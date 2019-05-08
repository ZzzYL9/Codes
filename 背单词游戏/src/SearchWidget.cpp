#include "SearchWidget.h"
#include "WordList.h"
#include "Library.h"
#include <QtGui>
#include <QtSql\QSqlTableModel>

SearchWidget::SearchWidget(QWidget *parent)	: QWidget(parent)
{
	initModel();
	initView();
	initConnection();
}

void SearchWidget::initModel()
{
	model = new QStandardItemModel(this);
	model->setColumnCount(2);
	model->setHorizontalHeaderLabels(QStringList() << tr("单词") << tr("解释"));

	modelSql = new QSqlTableModel(this);
	modelSql->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

void SearchWidget::initView()
{
	ui.setupUi(this);
	ui.tableView->setModel(model);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);
	ui.tableView->sortByColumn(0, Qt::AscendingOrder);
}

void SearchWidget::initConnection()
{
	connect(ui.tableView, SIGNAL(doubleClicked  (const QModelIndex&)),
			this,         SLOT(slotDoubleClicked(const QModelIndex&)));
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex&)), this, SIGNAL(clicked()));
}

void SearchWidget::search(const QString& target, SearchOption option)
{
	// search
	modelSql->setFilter(getFilter(target, option));
	modelSql->select();
	while(modelSql->canFetchMore())
		modelSql->fetchMore();

	// copy to model
	model->setRowCount(0);
	model->insertRows(0, modelSql->rowCount());
	for(int i=0; i<modelSql->rowCount(); ++i)
		for(int j=0; j<2; ++j)
			model->setData(model->index(i, j), modelSql->data(modelSql->index(i, j)));

	sort();
}

QString SearchWidget::getFilter(QString target, SearchOption option) const
{
	if(target.isEmpty())
		return "0";

	if(ChineseList::isChinese(target))    // chinese
	{
		QString result;
		QStringList chineseList = ChineseList(target).getSplitted();
		foreach(QString chinese, chineseList)
			result.append(tr("(解释 LIKE \"%%1%\") OR ").arg(chinese));
		return result.left(result.length() - 4);    // truncate last " OR "
	}

	// english
	switch(option)
	{
	case BEGIN:
		return tr("单词 LIKE \"%1%\"").arg(target);
	case END:
		return tr("单词 LIKE \"%%1\"").arg(target);
	default:
		return tr("单词 LIKE \"%%1%\"").arg(target);
	}
}

void SearchWidget::slotDoubleClicked(const QModelIndex& idx) {
	emit doubleClicked(
			Library::searchEnglish(
				dictName, model->data(model->index(idx.row(), 0)).toString()));
}

void SearchWidget::setDictName(const QString& dict)
{
	dictName = dict;
	modelSql->setTable(dict);
	modelSql->removeColumns(3, 4);
	modelSql->removeColumn(0);
}

void SearchWidget::appendRecord(const QString& english, const QString& chinese)
{
	if(findEnglish(english) == -1)
	{
		int lastRow = model->rowCount();
		model->insertRow(lastRow);
		setRecord(lastRow, english, chinese);
	}
}

void SearchWidget::delRecord(const QString& english)
{
	int row = findEnglish(english);
	if(row >= 0)
		model->removeRow(row);
}

void SearchWidget::moveRecordsTo(SearchWidget& dest)
{
	QStringList englishsToBeDeleted;
	QModelIndexList idxs = ui.tableView->selectionModel()->selectedRows();
	int lastRow = dest.rowCount();
	dest.model->insertRows(lastRow, idxs.size());
	foreach(QModelIndex idx, idxs)
	{
		QString english = getEnglish(idx.row());
		dest.setRecord(lastRow++, english, getChinese(idx.row()));
		englishsToBeDeleted << english;
	}
	dest.sort();

	foreach(QString english, englishsToBeDeleted)
		delRecord(english);   // don't delete by rows, because they change while deleting
}

int SearchWidget::findEnglish(const QString& english) const
{
	QModelIndexList idxs = model->match(model->index(0, 0), Qt::DisplayRole, 
										english, 1, Qt::MatchExactly);
	return idxs.isEmpty() ? -1 : idxs.front().row();
}

void SearchWidget::selectAll(bool select)
{
	if(select)
	{
		ui.tableView->selectAll();
		ui.tableView->setFocus();
	}
	else
		ui.tableView->clearSelection();
}

void SearchWidget::removeDuplicate(const SearchWidget& other)
{
	for(int i=0; i<other.rowCount(); ++i)
		delRecord(other.getEnglish(i));
}

int SearchWidget::rowCount() const {
	return model->rowCount();
}

void SearchWidget::sort() 
{
	ui.tableView->sortByColumn(0, ui.tableView->horizontalHeader()->sortIndicatorOrder());
	ui.tableView->resizeColumnToContents(0);
}

QString SearchWidget::getEnglish(int row) const {
	return validRow(row) ? model->data(model->index(row, 0)).toString() : QString();
}

QString SearchWidget::getChinese(int row) const {
	return validRow(row) ? model->data(model->index(row, 1)).toString() : QString();
}

void SearchWidget::setRecord(int row, const QString& english, const QString& chinese)
{
	if(validRow(row))
	{
		model->setData(model->index(row, 0), english);
		model->setData(model->index(row, 1), chinese);
	}
}

bool SearchWidget::validRow(int row) const {
	return 0 <= row && row < model->rowCount();
}