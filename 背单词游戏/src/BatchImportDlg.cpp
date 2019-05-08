#include "BatchImportDlg.h"
#include "WordList.h"
#include "Library.h"
#include "MainWindow.h"
#include "SettingDlg.h"
#include <QHeaderView>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

BatchImportDlg::BatchImportDlg(QWidget *parent, const QString& dict, 
							   const QString& chineseLine, const QString& englishLine)
	: QDialog(parent), dictName(dict)
{
	activeTable = 0;
	initView(chineseLine);
	initConnection();
	loadOldWords(englishLine);
}

void BatchImportDlg::initView(const QString& chineseLine)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint);
	ui.lineEditGroupName->setText(chineseLine);
	ui.lineEditSearch->setText(chineseLine);
	ui.lineEditSearch->selectAll();
	ui.lineEditSearch->setFocus();

	ui.searchWidgetSearch->setDictName(dictName);
}

void BatchImportDlg::initConnection()
{
	connect(ui.buttonImport, SIGNAL(clicked()), this, SLOT(slotImport()));
	connect(ui.buttonDel,    SIGNAL(clicked()), this, SLOT(slotDel()));
	connect(ui.buttonAll,    SIGNAL(clicked()), this, SLOT(slotAll()));
	connect(ui.buttonAppend, SIGNAL(clicked()), this, SLOT(slotAppendName()));
	connect(ui.buttonCopy,   SIGNAL(clicked()), this, SLOT(slotCopyName()));
	connect(ui.lineEditSearch, SIGNAL(textChanged(const QString&)), 
			this,			   SLOT(slotSearch(const QString&)));
	connect(ui.searchWidgetGroup,  SIGNAL(clicked()), this, SLOT(slotGroupWidgetActivated()));
	connect(ui.searchWidgetSearch, SIGNAL(clicked()), this, SLOT(slotSearchWidgetActivated()));
	connect(ui.searchWidgetGroup,  SIGNAL(doubleClicked(int)), this, SLOT(slotDel()));
	connect(ui.searchWidgetSearch, SIGNAL(doubleClicked(int)), this, SLOT(slotImport()));
	connect(ui.radioBegin, SIGNAL(clicked()), this, SLOT(slotReSearch()));
	connect(ui.radioEnd,   SIGNAL(clicked()), this, SLOT(slotReSearch()));
	connect(ui.radioAny,   SIGNAL(clicked()), this, SLOT(slotReSearch()));
}

int BatchImportDlg::exec()
{
	slotReSearch();
	return QDialog::exec();
}

void BatchImportDlg::loadOldWords(const QString& englishLine)
{
	QStringList englishList = EnglishList(englishLine).getSplitted();
	foreach(QString english, englishList)
		ui.searchWidgetGroup->appendRecord(english, Library::getChinese(dictName, english));
	ui.searchWidgetGroup->sort();
}

void BatchImportDlg::slotAppendName()
{
	ui.lineEditGroupName->setText(
		ui.lineEditGroupName->text().append(
			tr("¡¢") + ui.lineEditSearch->text()));
}

void BatchImportDlg::slotCopyName() {
	ui.lineEditGroupName->setText(ui.lineEditSearch->text());
}

void BatchImportDlg::enableOption(bool enable)
{
	ui.radioBegin->setEnabled(enable);
	ui.radioEnd  ->setEnabled(enable);
	ui.radioAny  ->setEnabled(enable);
}

void BatchImportDlg::slotSearch(const QString& target)
{
	enableOption(!ChineseList::isChinese(target));
	ui.searchWidgetSearch->search(target, getOption());
	ui.searchWidgetSearch->removeDuplicate(*ui.searchWidgetGroup);
}

SearchWidget::SearchOption BatchImportDlg::getOption() const
{
	if(ui.radioBegin->isChecked())
		return SearchWidget::BEGIN;
	if(ui.radioEnd->isChecked())
		return SearchWidget::END;
	return SearchWidget::ANY;
}

void BatchImportDlg::slotImport() {
	ui.searchWidgetSearch->moveRecordsTo(*ui.searchWidgetGroup);
}

void BatchImportDlg::slotDel() {
	ui.searchWidgetGroup->moveRecordsTo(*ui.searchWidgetSearch);
}

void BatchImportDlg::slotGroupWidgetActivated()
{
	activeTable = ui.searchWidgetGroup;
	ui.searchWidgetSearch->selectAll(false);
	ui.buttonImport->setEnabled(false);
	ui.buttonDel   ->setEnabled(true);
	ui.buttonAll   ->setEnabled(true);
}

void BatchImportDlg::slotSearchWidgetActivated()
{
	activeTable = ui.searchWidgetSearch;
	ui.searchWidgetGroup->selectAll(false);
	ui.buttonDel   ->setEnabled(false);
	ui.buttonImport->setEnabled(true);
	ui.buttonAll   ->setEnabled(true);
}

void BatchImportDlg::slotAll()
{
	if(activeTable != 0)
		activeTable->selectAll(true);
}

QString BatchImportDlg::getEnglishList() const
{
	QStringList result;
	for(int i=0; i<ui.searchWidgetGroup->rowCount(); ++i)
		result << ui.searchWidgetGroup->getEnglish(i);
	return result.join(", ");
}

void BatchImportDlg::accept()
{
	if(ui.searchWidgetGroup->rowCount() > 0)
		QDialog::accept();
	else
		reject();
}

void BatchImportDlg::slotReSearch() {
	slotSearch(ui.lineEditSearch->text());
}