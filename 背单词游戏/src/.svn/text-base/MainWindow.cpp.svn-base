#include "MainWindow.h"
#include "NewDictDlg.h"
#include "DictionaryModel.h"
#include "MyDelegate.h"
#include "SettingDlg.h"
#include "Library.h"
#include "GroupDlg.h"
#include "Entrance.h"
#include "DictLoader.h"
#include "MiniPlayer.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QSound>
#include <QFile>
#include <QStandardItemModel>
#include <QDataWidgetMapper>
#include <QTextStream>
#include <QDir>
#include <QDate>
#include <QDesktopWidget>
#include <QProgressDialog>
#include <QFileDialog>
#include <QCloseEvent>
#include <cmath>

QString MainWindow::userName;

MainWindow::MainWindow(const QString& user, QWidget *parent)
	: QMainWindow(parent), miniPlayer(0)
{
	userName = user;
	currentRow = currentID = -1;
	ui.setupUi(this);
	initModel();
	initView();
	initConnection();
}

void MainWindow::closeEvent(QCloseEvent*)
{
	ui.tableView->saveSectionSizes();
	saveSettings();
	if(setting->value("Other/autoBackup").toBool())
	{
		delOldBackups();
		backup();
	}
	if(miniPlayer != 0)
		delete miniPlayer;
	deleteLater();
}

void MainWindow::initModel()
{
	model = new DictionaryModel(this, userName);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	progressModel = new QStandardItemModel(3, 3, this);
	progressModel->setData(progressModel->index(0, 0), tr("新词"));
	progressModel->setData(progressModel->index(1, 0), tr("模糊词"));
	progressModel->setData(progressModel->index(2, 0), tr("熟词"));
}

void MainWindow::initView()
{
	ui.tableView->setModel(model);
	ui.tableView->setItemDelegate(new MyDelegate(ui.tableView));
	ui.tableView->setSortingEnabled(true);
	ui.tableView->sortByColumn(DictionaryModel::ENGLISH, Qt::AscendingOrder);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);
	ui.pieView->setModel(progressModel);
	ui.detailWidget->setModel(model);
	
	updateDictList();
	updateView();
}

void MainWindow::updateView()
{
	ui.tableView->setTableName(userName);
	loadSetting();
	updateCurrentDict();
}

void MainWindow::initConnection()
{
	connect(ui.buttonRight,          SIGNAL(clicked()), this, SLOT(slotRight()));
	connect(ui.buttonWrong,          SIGNAL(clicked()), this, SLOT(slotWrong()));
	connect(ui.buttonPrevUnit,       SIGNAL(clicked()), this, SLOT(slotPrevUnit()));
	connect(ui.buttonNextUnit,       SIGNAL(clicked()), this, SLOT(slotNextUnit()));
	connect(ui.buttonShuffle,        SIGNAL(clicked()), this, SLOT(slotShuffle()));
	connect(ui.buttonBack,           SIGNAL(clicked()), this, SLOT(slotBack()));
	connect(ui.buttonChinese,        SIGNAL(clicked()), this, SLOT(slotForceShowChinese()));
	connect(ui.buttonSetFamiliar,    SIGNAL(clicked()), this, SLOT(slotSetFamiliar()));
	connect(ui.buttonExitFullScreen, SIGNAL(clicked()), this, SLOT(slotExitFullScreen()));
	connect(ui.buttonAutoPlay,       SIGNAL(toggled(bool)), this, SLOT(slotPlay(bool)));
	connect(ui.buttonRecite,         SIGNAL(toggled(bool)), this, SLOT(slotRecite(bool)));
	connect(ui.buttonUpper,          SIGNAL(toggled(bool)), this, SLOT(slotUpper(bool)));

	connect(ui.actionLoadDict,   SIGNAL(triggered()), this, SLOT(slotNewDict()));
	connect(ui.actionDelDict,    SIGNAL(triggered()), this, SLOT(slotDelDict()));
	connect(ui.actionAbout,      SIGNAL(triggered()), this, SLOT(slotAbout()));
	connect(ui.actionSetting,    SIGNAL(triggered()), this, SLOT(slotSetting()));
	connect(ui.actionDelWord,    SIGNAL(triggered()), this, SLOT(slotDelWord()));
	connect(ui.actionChangeUser, SIGNAL(triggered()), this, SLOT(slotChangeUser()));
	connect(ui.actionExport,     SIGNAL(triggered()), this, SLOT(slotExport()));
	connect(ui.actionFullScreen, SIGNAL(triggered()), this, SLOT(slotFullScreen()));
	connect(ui.actionBackup,     SIGNAL(triggered()), this, SLOT(slotBackup()));
	connect(ui.actionMiniPlayer, SIGNAL(triggered()), this, SLOT(slotMiniPlayer()));
	connect(ui.actionHideControlBar, SIGNAL(triggered(bool)), this, SLOT(slotHideControlBar(bool)));
	connect(ui.buttonHideControlBar, SIGNAL(toggled  (bool)), this, SLOT(slotHideControlBar(bool)));

	connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex&)), 
			this,         SLOT(slotForceShowChinese()));
	connect(ui.tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
			ui.detailWidget,			    SLOT  (slotSetCurrentRow(QModelIndex)));
	connect(ui.tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
			this,							SLOT  (slotSetCurrentRow(QModelIndex)));
	connect(ui.tableView, SIGNAL(customContextMenuRequested(const QPoint&)), 
			this,         SLOT(slotRight()));
	connect(ui.tableView, SIGNAL(midClicked()), this, SLOT(slotWrong()));
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionClicked(int)),
			this,                             SLOT(slotGotoCurrentID()));
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionPressed(int)),
			this,                             SLOT(slotSectionPressed()));

	connect(ui.spinBoxUnitSize,   SIGNAL(valueChanged(int)), this, SLOT(slotResizeUnit(int)));
	connect(ui.spinBoxThreshold2, SIGNAL(valueChanged(int)), this, SLOT(slotSetMaxThreshold1(int)));
	connect(ui.spinBoxUnitSize,   SIGNAL(valueChanged(int)), this, SLOT(slotUpdateFilter()));
	connect(ui.spinBoxUnit,       SIGNAL(valueChanged(int)), this, SLOT(slotUpdateFilter()));
	connect(ui.spinBoxUnit,       SIGNAL(valueChanged(int)), this, SLOT(slotUpdateTitle()));
	connect(ui.spinBoxThreshold1, SIGNAL(valueChanged(int)), this, SLOT(slotUpdateFilter()));
	connect(ui.spinBoxThreshold2, SIGNAL(valueChanged(int)), this, SLOT(slotUpdateFilter()));
	connect(ui.checkBoxNew,        SIGNAL(stateChanged(int)), this, SLOT(slotUpdateFilter()));
	connect(ui.checkBoxUnfamiliar, SIGNAL(stateChanged(int)), this, SLOT(slotUpdateFilter()));
	connect(ui.checkBoxFamiliar,   SIGNAL(stateChanged(int)), this, SLOT(slotUpdateFilter()));
	connect(&timer,         SIGNAL(timeout()),     this, SLOT(slotTimeout()));
	connect(ui.groupWidget, SIGNAL(jobFinished()), this, SLOT(slotGotoCurrentID()));
	connect(ui.groupWidget,   SIGNAL(itemDbClicked(int, bool)), this, SLOT(slotJump(int, bool)));
	connect(ui.searchTab,     SIGNAL(doubleClicked(int, bool)), this, SLOT(slotJump(int, bool)));
	connect(ui.cognateWidget, SIGNAL(doubleClicked(int, bool)), this, SLOT(slotJump(int, bool)));
}

void MainWindow::loadSizes()
{
	ui.splitterVertical->setSizes(QList<int>() << setting->getSize("VerticalSplitterUp") 
											   << setting->getSize("VerticalSplitterDown"));
	ui.splitterLeft    ->setSizes(QList<int>() << setting->getSize("LeftSplitterLeft")
											   << setting->getSize("LeftSplitterRight"));
	ui.detailWidget->setSplitterSizes(QList<int>() << setting->getSize("DetailSplitterEnglish") 
											       << setting->getSize("DetailSplitterChinese")
											       << setting->getSize("DetailSplitterNote"));
	ui.dockWidgetGroup  ->setMinimumWidth (QApplication::desktop()->width()  * 0.25);
	ui.dockWidgetCognate->setMaximumHeight(QApplication::desktop()->height() * 0.27);
}

void MainWindow::saveSizes()
{
	setting->setSize("VerticalSplitterUp",    ui.splitterVertical->sizes().at(0));
	setting->setSize("VerticalSplitterDown",  ui.splitterVertical->sizes().at(1));
	setting->setSize("LeftSplitterLeft",      ui.splitterLeft    ->sizes().at(0));
	setting->setSize("LeftSplitterRight",     ui.splitterLeft    ->sizes().at(1));
	setting->setSize("DetailSplitterEnglish", ui.detailWidget->getSplitterSizes().at(0));
	setting->setSize("DetailSplitterChinese", ui.detailWidget->getSplitterSizes().at(1));
	setting->setSize("DetailSplitterNote",    ui.detailWidget->getSplitterSizes().at(2));
}

void MainWindow::loadButtonStatus()
{
	bool recite         = setting->value("ButtonStatus/Recite")        .toBool();
	bool upper          = setting->value("ButtonStatus/Upper")         .toBool();
	bool hideControlBar = setting->value("ButtonStatus/HideControlBar").toBool();
	ui.buttonRecite->setChecked(recite);
	ui.buttonUpper ->setChecked(upper);
	slotRecite(recite);
	slotUpper (upper);
	slotHideControlBar(hideControlBar);
}

void MainWindow::saveButtonStatus()
{
	setting->setValue("ButtonStatus/Recite",         ui.buttonRecite->isChecked());
	setting->setValue("ButtonStatus/Upper",          ui.buttonUpper ->isChecked());
	setting->setValue("ButtonStatus/HideControlBar", ui.frameControl->height() == 0);
}

void MainWindow::loadSetting()
{
	setting = UserSetting::getInstance(userName);
	importSetting(*setting);
	loadSizes();
	loadButtonStatus();
}

void MainWindow::saveSettings()
{
	submitAll();
	saveDictSetting(userName);
	setting->setValue("Other/currentDict", getCurrentDictName());
	saveSizes();
	saveButtonStatus();
}

void MainWindow::updateCurrentDict()
{
	const QString currentDict = setting->value("Other/currentDict").toString();
	currentDict.isEmpty() ? ui.comboBox->setCurrentIndex(0)
						  : ui.comboBox->setCurrentIndex(ui.comboBox->findText(currentDict));

	slotSetCurrentDict(getCurrentDictName());
}

void MainWindow::updateDictList()
{
	disconnect(ui.comboBox, SIGNAL(currentIndexChanged(const QString&)),
			   this,        SLOT(slotSetCurrentDict(const QString&)));
	ui.comboBox->clear();
	ui.comboBox->addItems(Library::getDictList());
	connect(ui.comboBox, SIGNAL(currentIndexChanged(const QString&)),
			this,        SLOT(slotSetCurrentDict(const QString&)));
}

void MainWindow::updateProgress()
{
	int newCount        = model->getNewWordCount();
	int unfamiliarCount = model->getUnfamiliarCount();
	int familiarCount   = model->getFamiliarCount();
	int total = qMax(newCount + unfamiliarCount + familiarCount, 1);
	progressModel->setData(progressModel->index(0, 0), model->getNewWordColor(), Qt::DecorationRole);
	progressModel->setData(progressModel->index(0, 1), newCount);
	progressModel->setData(progressModel->index(0, 2), tr("%1%").arg(newCount*100/total));
	progressModel->setData(progressModel->index(1, 0), model->getUnfamilarColor(), Qt::DecorationRole);
	progressModel->setData(progressModel->index(1, 1), unfamiliarCount);
	progressModel->setData(progressModel->index(1, 2), tr("%1%").arg(unfamiliarCount*100/total));
	progressModel->setData(progressModel->index(2, 0), model->getFamiliarColor(), Qt::DecorationRole);
	progressModel->setData(progressModel->index(2, 1), familiarCount);
	progressModel->setData(progressModel->index(2, 2), tr("%1%").arg(familiarCount*100/total));
}

void MainWindow::updateGroups(bool show) {
	ui.groupWidget->setCentralWord(getCurrentEnglish(), show);
}
void MainWindow::updateCognate(bool show) {
	ui.cognateWidget->setCentralWord(getCurrentEnglish(), show);
}

QString MainWindow::getCurrentDictName() const {
	return ui.comboBox->currentText();
}

QString MainWindow::getCurrentEnglish() const {
	return model->getEnglish(currentRow);
}

void MainWindow::selectRow(int row)
{
	if(0 <= row && row < model->rowCount())
	{
		currentRow = row;
		ui.tableView->selectRow(row);
		ui.tableView->setFocus();
	}
}

void MainWindow::setCredit(int credit)
{
	model->setData(model->index(currentRow, DictionaryModel::CREDIT), qMax(credit, 0));
	updateProgress();
}

void MainWindow::slotSetCurrentRow(const QModelIndex& current)
{
	bool valid = current.isValid();
	if(valid)
	{	
		currentRow = current.row();
		currentID = model->getID(currentRow);
		showDetail(!model->isReciting());
		speak();
	}

	ui.buttonChinese->setEnabled(valid);
	ui.buttonRight  ->setEnabled(valid);
	ui.buttonWrong  ->setEnabled(valid);
}

void MainWindow::slotForceShowChinese()
{
	showDetail(true);
	selectRow(currentRow);   // reselect current row
}

void MainWindow::showDetail(bool show)
{
	updateGroups (show);
	updateCognate(show);
	model->setShowChinese(show, currentRow);
	ui.detailWidget->showRow(show);
}

void MainWindow::slotRecite(bool recite)
{
	showDetail(!recite);
	model->setRecite(recite);
	selectRow(currentRow);
}

void MainWindow::slotNewDict()
{
	NewDictDlg dlg(this);
	if(dlg.exec() == QDialog::Accepted)
	{
		DictLoader loader(dlg.getFileName(), dlg.getDictName());
		loader.load();
		updateDictList();
		updateCurrentDict();
	}
}

void MainWindow::slotDelDict()
{
	if(ui.comboBox->currentIndex() >= 0 && 
	   QMessageBox::warning(this, "Warning", tr("真的要删除么？"),
						    QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
	{
		DictLoader::delDict(getCurrentDictName());
		updateDictList();
		ui.comboBox->setCurrentIndex(0);
		slotSetCurrentDict(getCurrentDictName());
	}
}

void MainWindow::slotSetCurrentDict(const QString& dict)
{
	if(dict.isEmpty())	return;

	if(!lastDict.isEmpty())         // save lastUser, lastDict's setting
		if(!lastUser.isEmpty() && lastUser != userName)
		{
			saveDictSetting(lastUser);
			lastUser = userName;
		}
		else
			saveDictSetting(userName);

	submitAll();                    // before shift, save current dict's changes
	model->setDictionary(dict);     // update view
	loadDictSetting();
	int dictSize = Library::getDictSize(dict);
	ui.lineEditWordCount->setText(tr("%1").arg(dictSize));
	ui.spinBoxUnitSize->setMaximum(dictSize);
	ui.searchTab    ->setDictName(dict);
	ui.groupWidget  ->setDictName(dict);
	ui.cognateWidget->setDictName(dict);
	slotUpdateTitle();

	lastDict = dict;
}

void MainWindow::slotResizeUnit(int size)
{
	if(size > 0)
	{
		const int wordCount = Library::getDictSize(getCurrentDictName());
		const int unitCount = ceil((float)wordCount/size);
		ui.lineEditUnitCount->setText(tr("%1").arg(unitCount));
		ui.spinBoxUnit->setMaximum(unitCount);
		setUnit(1);
	}
}

void MainWindow::gotoNext() {
	selectRow(currentRow+1);
}
void MainWindow::gotoPrev() {
	selectRow(currentRow-1);
}

void MainWindow::slotRight()
{
	setCredit(model->getCredit(currentRow) + 1);
	if(!ui.buttonAutoPlay->isChecked())
		gotoNext();
}
void MainWindow::slotWrong()
{
	setCredit(model->getCredit(currentRow) - 1);
	if(!ui.buttonAutoPlay->isChecked())
		gotoNext();
}

void MainWindow::slotShuffle()
{
	submitAll();    // submit appending changes
	model->shuffle();
}

void MainWindow::slotUpdateFilter()
{
	submitAll();
	model->updateFilter(exportDictSetting());
	model->select();
	updateProgress();
	slotGotoCurrentID();
}

void MainWindow::slotSetMaxThreshold1(int value) {
	ui.spinBoxThreshold1->setMaximum(value-1);
}

void MainWindow::slotUpdateTitle() {
	setWindowTitle(tr("MyWords - %1 - %2 - Unit %3").arg(userName)
													.arg(getCurrentDictName())
													.arg(getUnit()));
}

void MainWindow::slotPrevUnit() {
	setUnit(getUnit() - 1);
}
void MainWindow::slotNextUnit() {
	setUnit(getUnit() + 1);
}

void MainWindow::slotAbout() {
	QMessageBox::about(this, tr("About"), tr("<h3><b>MyWords - 我的红宝解决方案</b></h3>"
											 "<p>Build 2008.6.4</p>"
											 "<p>本软件基于GPL协议</p>"
											 "<p>chencongsytu@163.com</p>"));
}

void MainWindow::slotSetting()
{
	SettingDlg dlg(userName, this);
	dlg.importSetting(*setting);
	if(dlg.exec() == QDialog::Accepted)
	{
		importSetting(dlg.exportSetting());
		updateProgress();   // may change color
	}
}

void MainWindow::slotPlay(bool play) {
	play ? timer.start(getPlayDelay()) : timer.stop();
}

void MainWindow::slotTimeout()
{
	static bool showChinese = true;
	if(showChinese)
		slotForceShowChinese();
	else
	{
		if(currentRow == model->rowCount() - 1)  // stop at last row
			ui.buttonAutoPlay->toggle();
		else
			gotoNext();
	}
	showChinese = !showChinese;
}

void MainWindow::speak()
{
	const QString word = getCurrentEnglish();
	const QString fileName = wavDir + "/" + word.left(1) + "/" + word + ".wma";
	if(QFile::exists(fileName))
		QSound::play(fileName);	
}

void MainWindow::slotJump(int id, bool back)
{
	if(id < 1)	return;
	if(back)
	{
		enableJumpBack(true);
		jumpHistroy.push(currentID);
	}
	setUnit((id-1)/getUnitSize() + 1); // jump to page
	QModelIndexList indexes = model->match(
		model->index(0, 0), Qt::DisplayRole, id, 1,	Qt::MatchExactly | Qt::MatchWrap);
	if(indexes.isEmpty())
	{
		ui.checkBoxNew       ->setChecked(true);  // show all words
		ui.checkBoxUnfamiliar->setChecked(true);
		ui.checkBoxFamiliar  ->setChecked(true);
	}
	jumpInPage(id);
}

void MainWindow::slotBack()
{
	if(!jumpHistroy.empty())
	{
		slotJump(jumpHistroy.top(), false);
		jumpHistroy.pop();
	}
	else
		enableJumpBack(false);
}

void MainWindow::jumpInPage(int id)
{
	QModelIndexList indexes = model->match(
		model->index(0, 0), Qt::DisplayRole, id, 1,	Qt::MatchExactly | Qt::MatchWrap);
	if(!indexes.isEmpty())
	{
		currentRow = indexes.at(0).row();
		selectRow(currentRow);
	}
}

void MainWindow::slotGotoCurrentID() {
	jumpInPage(currentID);   // keep highlighting, can't use currentRow
}

void MainWindow::slotSectionPressed() {
	submitAll();
}

void MainWindow::slotDelWord()
{
	if(QMessageBox::warning(this, "Warning", tr("真的要删除么？"),
							QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
	{
		model->removeRow(currentRow);
		submitAll();
		selectRow(currentRow);
	}
}

void MainWindow::slotChangeUser()
{
	setting->setValue("Other/isDefault", false);
	Entrance* entrance = new Entrance;
	entrance->show();
	close();
}

int MainWindow::getUnit() const {
	return ui.spinBoxUnit->value();
}
int MainWindow::getUnitSize() const {
	return ui.spinBoxUnitSize->value();
}
void MainWindow::setUnit(int unit) 
{
	ui.spinBoxUnit->setValue(unit);
	slotUpdateTitle();
}
void MainWindow::setUnitSize(int size) {
	ui.spinBoxUnitSize->setValue(size);
}

void MainWindow::slotExport()
{
	QDir::current().mkdir("Export");
	QString destDir = tr("Export/%1-%2-Unit%3").arg(userName).arg(getCurrentDictName()).arg(getUnit());
	QDir::current().mkdir(destDir);
	QFile file(destDir + ".txt");
	if(!file.open(QFile::WriteOnly | QFile::Truncate))
	{
		QMessageBox::critical(this, tr("打开文件错误"), tr("无法创建文件"));
		return;
	}
	QTextStream ofs(&file);
	ofs << destDir << "\r\n\r\n";

	ui.buttonRecite->setChecked(false);  // learning mode
	while(model->canFetchMore())
		model->fetchMore();

	int count = model->rowCount();
	QProgressDialog progress(tr("一共%1个单词，正在导出...").arg(count), 
							 0, 0, count);
	progress.setWindowTitle(tr("单词导出中"));
	progress.setWindowModality(Qt::WindowModal);

	for(int row=0; row<count; ++row)
	{
		const QString word    = model->getEnglish(row);
		const QString chinese = model->getChinese(row);
		Library::exportMp3(destDir, word);
		ofs << row + 1 << " " << word << "  " << chinese << "\r\n";
	
		progress.setValue(row);
		qApp->processEvents();
	}
}

void MainWindow::importSetting(const UserSetting& setting)
{
	UserSetting* globalSetting = UserSetting::getInstance("Global");
	wavDir = globalSetting->value("WavDir").toString();
	mp3Dir = globalSetting->value("Mp3Dir").toString();

	QApplication::setFont            (setting.getFont("guiFont"));
	ui.tableView   ->setFont         (setting.getFont("tableFont"));
	ui.detailWidget->setEnglishFont  (setting.getFont("wordFont"));
	ui.detailWidget->setPhoneticFont (setting.getFont("phoneticFont"));
	ui.detailWidget->setChineseFont  (setting.getFont("chineseFont"));
	ui.detailWidget->setNoteFont     (setting.getFont("noteFont"));
	model->setNewWordColor           (setting.getColor("newWordColor"));
	model->setUnfamiliarColor        (setting.getColor("unFamiliarColor"));
	model->setFamiliarColor          (setting.getColor("familiarColor"));
	ui.detailWidget->setPhoneticColor(setting.getColor("phoneticColor"));
	ui.buttonRight      ->setShortcut(setting.getShortcut("rightShortcut"));
	ui.buttonWrong      ->setShortcut(setting.getShortcut("wrongShortcut"));
	ui.buttonChinese    ->setShortcut(setting.getShortcut("chineseShortcut"));
	ui.buttonSetFamiliar->setShortcut(setting.getShortcut("setFamiliarShortcut"));
}

void MainWindow::delOldBackups()
{
	const QDate today = QDate::currentDate();
	const int   days  = setting->value("Other/backupDays").toInt();
	const QFileInfoList fileInfos = 
		QDir("Backup").entryInfoList(QStringList() << "*.db", QDir::Files);
	foreach(QFileInfo fileInfo, fileInfos)
		if(QDate::fromString(fileInfo.baseName(), Qt::ISODate).daysTo(today) > days)
			QFile::remove(fileInfo.filePath());
}

void MainWindow::backup(const QString& fileName)
{
	QDir::current().mkdir("Backup");
	QString backupFileName = fileName.isEmpty() 
		? "./Backup/" + QDate::currentDate().toString(Qt::ISODate) + ".db"
		: fileName;

	if(QFile::exists(backupFileName))
		QFile::remove(backupFileName);

	QFile file(Library::getDBFileName());
	file.copy(backupFileName);
	file.close();
}

int MainWindow::getThreshold1() const {
	return ui.spinBoxThreshold1->value();
}
int MainWindow::getThreshold2() const {
	return ui.spinBoxThreshold2->value();
}
int MainWindow::getPlayDelay() const{
	return ui.spinBoxDelay->value() * 1000;
}

void MainWindow::submitAll() {
	model->submitAll();
}

void MainWindow::slotFullScreen()
{
	showFullScreen();
	ui.menuBar->hide();
}

void MainWindow::slotExitFullScreen()
{
	showMaximized();
	ui.menuBar->show();
}

void MainWindow::slotHideControlBar(bool hide)
{
	ui.frameControl->setMaximumSize(QSize(1024, hide ? 0 : 1024));
	ui.actionHideControlBar->setChecked(hide);
}

void MainWindow::slotBackup()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("备份数据库"),
		"./Backup/word.db", tr("Database file (*.db);;All file (*.*)"));
	if(!fileName.isEmpty())
		backup(fileName);
}

void MainWindow::slotUpper(bool upper) {
	model->setUpper(upper);
}

void MainWindow::enableJumpBack(bool enable) {
	ui.buttonBack->setEnabled(enable);
}

void MainWindow::loadDictSetting()
{
	if(setting->containsDictSetting(getCurrentDictName()))
	{
		DictSetting dictSetting = setting->getDictSetting(getCurrentDictName());
		slotResizeUnit(dictSetting.unitSize);
		setUnitSize   (dictSetting.unitSize);
		setUnit       (dictSetting.currentUnit);
		ui.spinBoxThreshold1->setValue(dictSetting.threshold1);
		ui.spinBoxThreshold2->setValue(dictSetting.threshold2);
		ui.checkBoxNew       ->setChecked(dictSetting.showNew);
		ui.checkBoxUnfamiliar->setChecked(dictSetting.showUnFamiliar);
		ui.checkBoxFamiliar  ->setChecked(dictSetting.showFamiliar);

		slotSetMaxThreshold1(getThreshold2());
	}
	slotUpdateFilter();
}

void MainWindow::saveDictSetting(const QString& user) {
	UserSetting::getInstance(user)->setDictSetting(lastDict, exportDictSetting());
}

DictSetting MainWindow::exportDictSetting() const
{
	DictSetting result;
	result.unitSize       = getUnitSize();
	result.currentUnit    = getUnit();
	result.threshold1     = getThreshold1();
	result.threshold2     = getThreshold2();
	result.showNew        = ui.checkBoxNew->isChecked();
	result.showUnFamiliar = ui.checkBoxUnfamiliar->isChecked();
	result.showFamiliar   = ui.checkBoxFamiliar->isChecked();
	return result;
}

void MainWindow::slotSetFamiliar() 
{
	setCredit(getThreshold2());
	if(!ui.buttonAutoPlay->isChecked())
		gotoNext();
}

void MainWindow::slotMiniPlayer()
{
	if(miniPlayer == 0)
	{
		miniPlayer = new MiniPlayer(model, this);
		connect(miniPlayer, SIGNAL(accepted()), this, SLOT(showMaximized()));
	}
	miniPlayer->show();
	hide();
}