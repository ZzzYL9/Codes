#include "GroupDlg.h"
#include "Library.h"
#include "BatchImportDlg.h"
#include "WordList.h"
#include "UserSetting.h"
#include <QInputDialog>
#include <QtSql/QSqlTableModel>
#include <QHeaderView>
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QProgressDialog>

GroupDlg::GroupDlg(QWidget *parent, const QString& dict, const QString& table, const QString& w)
	: QDialog(parent), dictName(dict), tableName(table), word(w)
{
	currentRow = 0;
	initModel();
	initView();
	initConnection();
}

GroupDlg::~GroupDlg() {
	model->submitAll();
}

void GroupDlg::initModel()
{
	model = new QSqlTableModel(this);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setTable(tableName);
	model->select();
	model->setHeaderData(0, Qt::Horizontal, tr("组名"));
	model->setHeaderData(1, Qt::Horizontal, tr("成员"));
}

void GroupDlg::initView()
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint);
	setWindowState(windowState() ^ Qt::WindowMaximized);
	setWindowTitle(tableName);

	ui.tableView->setModel(model);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);
	ui.tableView->resizeColumnsToContents();
	ui.tableView->sortByColumn(0, Qt::AscendingOrder);

	rawChinese      = Library::getChinese(dictName, word);
	filteredChinese = ChineseList(rawChinese).getFiltered();
	ui.lineEditCurrentWord->setText(word.isEmpty() ? tr("无") 
												   : word + " : " + rawChinese);
	ui.lineEditSearch->setText(filteredChinese);
	ui.lineEditSearch->selectAll();
	ui.lineEditSearch->setFocus();
}

void GroupDlg::initConnection()
{
	connect(ui.buttonNew,    SIGNAL(clicked()), this, SLOT(slotNew()));
	connect(ui.buttonDel,    SIGNAL(clicked()), this, SLOT(slotDel()));
	connect(ui.buttonJoin,   SIGNAL(clicked()), this, SLOT(slotJoin()));
	connect(ui.buttonNext,   SIGNAL(clicked()), this, SLOT(slotNext()));
	connect(ui.buttonEdit,   SIGNAL(clicked()), this, SLOT(slotEdit()));
	connect(ui.buttonUnite,  SIGNAL(clicked()), this, SLOT(slotUnite()));
	connect(ui.buttonExport, SIGNAL(clicked()), this, SLOT(slotExport()));
	connect(ui.tableView,   SIGNAL(doubleClicked(const QModelIndex&)),
			this,           SLOT(slotEdit()));
	connect(ui.tableView,   SIGNAL(clicked(const QModelIndex&)),
			this,           SLOT(slotSetCurrentRow(const QModelIndex&)));
	connect(ui.tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
			this,                           SLOT(slotSetCurrentRow(const QModelIndex&)));
	connect(ui.lineEditSearch, SIGNAL(textChanged(const QString&)), 
			this,			   SLOT(slotSearch(const QString&)));
}

void GroupDlg::slotJoin()
{
	QString englishLine = getEnglishLine(currentRow);
	if(EnglishList(englishLine).contains(word))
	{
		QMessageBox::warning(this, tr("错误"), tr("该词已经存在于该组中"));
		return;
	}

	model->setData(model->index(currentRow, 1), EnglishList(englishLine).add(word));
	model->submitAll();
	accept();
}

void GroupDlg::slotSetCurrentRow(const QModelIndex& idx)
{
	currentRow = idx.isValid() ? idx.row() : -1;
	ui.buttonDel  ->setEnabled(idx.isValid());
	ui.buttonJoin ->setEnabled(idx.isValid());
	ui.buttonEdit ->setEnabled(idx.isValid());
	ui.buttonUnite->setEnabled(getSelectedIndexes().size() > 1);
}

QModelIndexList GroupDlg::getSelectedIndexes() const {
	return ui.tableView->selectionModel()->selectedRows();
}

void GroupDlg::slotDel()
{
	if(QMessageBox::warning(this, tr("确认"), tr("确认删除该组么？"), 
							QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
	{
		model->removeRow(currentRow);
		model->submitAll();
	}
}

void GroupDlg::selectRow(int row, bool select)
{
	select ? ui.tableView->selectRow(row)
	       : ui.tableView->selectionModel()->select(model->index(row, 0), 
				QItemSelectionModel::Rows | QItemSelectionModel::Deselect);
	ui.buttonDel  ->setEnabled(select);
	ui.buttonJoin ->setEnabled(select);
	ui.buttonEdit ->setEnabled(select);
	ui.buttonUnite->setEnabled(select);
}

void GroupDlg::slotNext()
{
	if(!searchResults.isEmpty())
		selectRow(searchResults.next());
}

bool GroupDlg::slotSearch(const QString& target, bool fuzzy)
{
	if(search(target, 0, 1, fuzzy))
	{
		selectRow(searchResults.next());
		ui.buttonNext->setEnabled(true);
		return true;
	}
	else
	{
		selectRow(currentRow, false);
		ui.buttonNext->setEnabled(false);
		return false;
	}
}

bool GroupDlg::search(const QString& target, int start, int end, bool fuzzy)
{
	if(target.isEmpty())
		return false;

	fetchAll();
	searchResults.clear();	

	if(ChineseList::isChinese(target))
		searchChinese(target);
	else
		for(int i=start; i<=end; ++i)
			searchEnglish(target, i, fuzzy);

	return !searchResults.isEmpty();
}

void GroupDlg::searchChinese(const QString& target)
{
	QStringList wordList = ChineseList(target).getSplitted();
	foreach(QString word, wordList)
		searchResults.add(model->match(model->index(0, 0), Qt::DisplayRole, 
			word, model->rowCount(), Qt::MatchContains));
}

void GroupDlg::searchEnglish(const QString& target, int column, bool fuzzy)
{
	QModelIndexList fuzzyResults = model->match(model->index(0, column), Qt::DisplayRole, 
											    target, model->rowCount(), Qt::MatchContains);
	if(fuzzy)
		searchResults.add(fuzzyResults);
	else
		foreach(QModelIndex idx, fuzzyResults)
			if(EnglishList(model->data(idx).toString()).contains(target))
				searchResults.add(idx);
}

void GroupDlg::slotNew()
{
	BatchImportDlg dlg(this, dictName, ui.lineEditSearch->text(), word);
	if(dlg.exec() == QDialog::Accepted)
	{
		addRecord(dlg.getGroupName(), dlg.getEnglishList());
		finishEditGroup(dlg.getGroupName());
	}
}

void GroupDlg::slotEdit()
{
	BatchImportDlg dlg(this, dictName, getGroupName(currentRow), getEnglishLine(currentRow));
	if(dlg.exec() == QDialog::Accepted)
	{
		setRecord(currentRow, dlg.getGroupName(), dlg.getEnglishList());
		finishEditGroup(dlg.getGroupName());
	}
}

int GroupDlg::exec()
{
	if(!slotSearch(word, false))  // search english with no fuzzy
		slotSearch(rawChinese);   // then chinese

	return QDialog::exec();
}

void GroupDlg::slotUnite()
{
	bool ok;
	QString groupName = QInputDialog::getText(this, tr("新组名"),
                                          tr("新组名"), QLineEdit::Normal,
                                          QString(), &ok);
	if(ok && !groupName.isEmpty())
	{
		QModelIndexList selectedIndexes = getSelectedIndexes();
		QStringList wordList;
		foreach(QModelIndex idx, selectedIndexes)
			wordList << EnglishList(getEnglishLine(idx.row())).getSplitted();
		wordList = wordList.fromSet(wordList.toSet());   // remove duplicated
		wordList.sort();
		addRecord(groupName, wordList.join(", "));

		foreach(QModelIndex idx, selectedIndexes)   // delete old
			model->removeRow(idx.row());

		finishEditGroup(groupName);
	}
}

void GroupDlg::setRecord(int row, const QString& groupName, const QString& line)
{
	if(row < 0 || row >= model->rowCount())
		return;
	
	QString englishLine = line;
	if(search(groupName, 0, 0, false))  // join, if already exists
	{
		int oldRow = searchResults.next();
		if(oldRow != row)
		{
			QStringList oldList = EnglishList(getEnglishLine(oldRow)).getSplitted();
			QStringList newList = EnglishList(englishLine)           .getSplitted();
			oldList << newList;
			oldList = oldList.fromSet(oldList.toSet());   // remove duplicated
			oldList.sort();
			englishLine = oldList.join(", ");
			model->removeRow(oldRow);
			model->submitAll();
		}
	}
	model->setData(model->index(row, 0), groupName);
	model->setData(model->index(row, 1), englishLine);
}

void GroupDlg::addRecord(const QString& groupName, const QString& englishLine)
{
	int lastRow = model->rowCount();
	model->insertRow(lastRow);
	setRecord(lastRow, groupName, englishLine);
}

void GroupDlg::finishEditGroup(const QString& groupName)
{
	model->submitAll();
	slotSearch(groupName);    // highlight current group
}

void GroupDlg::slotExport()
{
	QString destDir = tableName;
	QFile file(destDir + ".txt");
	if(!file.open(QFile::WriteOnly | QFile::Truncate))
	{
		QMessageBox::critical(this, tr("打开文件错误"), tr("无法创建文件"));
		return;
	}

	QTextStream ofs(&file);
	ofs << destDir << "\r\n\r\n";

	QDir(".").mkdir(destDir);
	fetchAll();

	int count = model->rowCount();
	QProgressDialog progress(tr("一共%1个分组，正在导出...").arg(count), 0, 0, count);
	progress.setWindowTitle(tr("单词导出中"));
	progress.setWindowModality(Qt::WindowModal);

	for(int row=0; row<count; ++row)
	{
		const QString groupName = tr("%1 %2").arg(row+1).arg(getGroupName(row));
		QDir(destDir).mkdir(groupName);
		ofs << "\r\n" << groupName << "\r\n";

		QStringList list = EnglishList(getEnglishLine(row)).getSplitted();
		foreach(QString word, list)
		{
			Library::exportMp3(destDir + "/" + groupName, word);
			ofs << word << "\r\n";
		}

		progress.setValue(row);
		qApp->processEvents();
	}
}

QString GroupDlg::getEnglishLine(int row) const {
	return model->data(model->index(row, 1)).toString();
}

QString GroupDlg::getGroupName(int row) const {
	return model->data(model->index(row, 0)).toString();
}

void GroupDlg::fetchAll()
{
	while(model->canFetchMore())
		model->fetchMore();
}


//////////////////////////////////////////////////////////////////////////
// SearchResult
void SearchResult::add(const QModelIndex& index) {
	results << index;
}

void SearchResult::add(const QModelIndexList& indexList) {
	results << indexList;
}

void SearchResult::clear()
{
	results.clear();
	current = -1;
}

int SearchResult::next()
{
	current = (current+1) % results.size();
	return results.at(current).row();
}

void SearchResult::sort() {
	qSort(results);
}

bool SearchResult::isEmpty() const {
	return results.isEmpty();
}