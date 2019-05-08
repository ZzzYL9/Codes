#include "SettingDlg.h"
#include "Library.h"
#include "UserSetting.h"
#include <QFontDialog>
#include <QColorDialog>
#include <QPixmap>
#include <QImage>
#include <QtSql/QSqlQuery>
#include <QFileDialog>
#include <QMessageBox>

SettingDlg::SettingDlg(const QString& user, QWidget *parent)
	: QDialog(parent), userName(user)
{
	ui.setupUi(this);

	connect(ui.buttonTableFont,       SIGNAL(clicked()), this, SLOT(slotSetTableFont()));
	connect(ui.buttonWordFont,        SIGNAL(clicked()), this, SLOT(slotSetWordFont()));
	connect(ui.buttonPhoneticFont,    SIGNAL(clicked()), this, SLOT(slotSetPhoneticFont()));
	connect(ui.buttonChineseFont,     SIGNAL(clicked()), this, SLOT(slotSetChineseFont()));
	connect(ui.buttonNoteFont,        SIGNAL(clicked()), this, SLOT(slotSetNoteFont()));
	connect(ui.buttonGUIFont,         SIGNAL(clicked()), this, SLOT(slotSetGUIFont()));
	connect(ui.buttonNewColor,        SIGNAL(clicked()), this, SLOT(slotSetNewColor()));
	connect(ui.buttonUnfamiliarColor, SIGNAL(clicked()), this, SLOT(slotSetUnfamiliarColor()));
	connect(ui.buttonFamiliarColor,   SIGNAL(clicked()), this, SLOT(slotSetFamiliarColor()));
	connect(ui.buttonPhoneticColor,   SIGNAL(clicked()), this, SLOT(slotSetPhoneticColor()));
	connect(ui.buttonWav,             SIGNAL(clicked()), this, SLOT(slotSetWavDir()));
	connect(ui.buttonMp3,             SIGNAL(clicked()), this, SLOT(slotSetMp3Dir()));
	connect(ui.buttonDBFile,          SIGNAL(clicked()), this, SLOT(slotSetDBFileName()));
	connect(ui.checkBoxAutoHide,   SIGNAL(toggled(bool)), this, SLOT(slotSetAutoHide  (bool)));
	connect(ui.checkBoxAutoBackup, SIGNAL(toggled(bool)), this, SLOT(slotSetAutoBackup(bool)));
}

QString SettingDlg::getRightShortcut() const { 
	return ui.lineEditRightShortcut->text(); 
}
QString SettingDlg::getWrongShortcut() const {
	return ui.lineEditWrongShortcut->text(); 
}
QString SettingDlg::getChineseShortcut() const {
	return ui.lineEditChineseShortcut->text(); 
}
QString SettingDlg::getSetFamiliarShortcut() const { 
	return ui.lineEditSetFamiliarShortcut->text(); 
}

void SettingDlg::setRightShortcut(const QString& shortcut) {
	ui.lineEditRightShortcut->setText(shortcut);
}
void SettingDlg::setWrongShortcut(const QString& shortcut) {
	ui.lineEditWrongShortcut->setText(shortcut);
}
void SettingDlg::setChineseShortcut(const QString& shortcut) {
	ui.lineEditChineseShortcut->setText(shortcut);
}
void SettingDlg::setSetFamiliarShortcut(const QString& shortcut) {
	ui.lineEditSetFamiliarShortcut->setText(shortcut);
}

void SettingDlg::slotSetTableFont() {
	setTableFont(QFontDialog::getFont(0, getTableFont(), this));
}
void SettingDlg::slotSetWordFont() {
	setWordFont(QFontDialog::getFont(0, getWordFont(), this));
}
void SettingDlg::slotSetChineseFont() {
	setChineseFont(QFontDialog::getFont(0, getChineseFont(), this));
}
void SettingDlg::slotSetPhoneticFont() {
	setPhoneticFont(QFontDialog::getFont(0, getPhoneticFont(), this));
}
void SettingDlg::slotSetNoteFont() {
	setNoteFont(QFontDialog::getFont(0, getNoteFont(), this));
}
void SettingDlg::slotSetGUIFont() {
	setGUIFont(QFontDialog::getFont(0, getGUIFont(), this));
}

QColor SettingDlg::getNewWordColor() const {
	return ui.labelNewColor->pixmap()->toImage().pixel(0, 0);
}
QColor SettingDlg::getUnfamiliarColor() const {
	return ui.labelUnfamiliarColor->pixmap()->toImage().pixel(0, 0);
}
QColor SettingDlg::getFamiliarColor() const {
	return ui.labelFamiliarColor->pixmap()->toImage().pixel(0, 0);
}
QColor SettingDlg::getPhoneticColor() const {
	return ui.labelPhoneticColor->pixmap()->toImage().pixel(0, 0);
}
QString SettingDlg::getWavDir() const {
	return ui.lineEditWav->text();
}
QString SettingDlg::getMp3Dir() const {
	return ui.lineEditMp3->text();
}
bool SettingDlg::getAutoBackup() const {
	return ui.checkBoxAutoBackup->isChecked();
}
int SettingDlg::getBackupDays() const {
	return ui.spinBoxBackupDays->value();
}
QString SettingDlg::getDBFileName() const {
	return ui.lineEditDBFile->text();
}
QString SettingDlg::getFilteredChar() const {
	return ui.lineEditFilteredChar->text();
}
bool SettingDlg::getAutoHide() const {
	return ui.checkBoxAutoHide->isChecked();
}
int SettingDlg::getHideDelay() const {
	return ui.spinBoxHideDelay->value();
}
int SettingDlg::getShowDelay() const {
	return ui.spinBoxShowDelay->value();
}
void SettingDlg::setAutoHide(bool hide) {
	ui.checkBoxAutoHide->setChecked(hide);
}
void SettingDlg::setHideDelay(int delay) {
	ui.spinBoxHideDelay->setValue(delay);
}
void SettingDlg::setShowDelay(int delay) {
	ui.spinBoxShowDelay->setValue(delay);
}
void SettingDlg::setDBFileName(const QString& name) {
	ui.lineEditDBFile->setText(name);
}
void SettingDlg::setAutoBackup(bool backup) {
	ui.checkBoxAutoBackup->setChecked(backup);
}
void SettingDlg::setWavDir(const QString& dir) {
	ui.lineEditWav->setText(dir);
}
void SettingDlg::setMp3Dir(const QString& dir) {
	ui.lineEditMp3->setText(dir);
}
void SettingDlg::setFilteredChar(const QString& chars) {
	ui.lineEditFilteredChar->setText(chars);
}
void SettingDlg::setBackupDays(int days) {
	ui.spinBoxBackupDays->setValue(days);
}
void SettingDlg::setNewWordColor(const QColor& color)
{
	QPixmap pixmap(ui.labelNewColor->width(), ui.labelNewColor->height());
	pixmap.fill(color);
	ui.labelNewColor->setPixmap(pixmap);
}
void SettingDlg::setUnfamiliarColor(const QColor& color)
{
	QPixmap pixmap(ui.labelUnfamiliarColor->width(), ui.labelUnfamiliarColor->height());
	pixmap.fill(color);
	ui.labelUnfamiliarColor->setPixmap(pixmap);
}

void SettingDlg::setFamiliarColor(const QColor& color)
{
	QPixmap pixmap(ui.labelFamiliarColor->width(), ui.labelFamiliarColor->height());
	pixmap.fill(color);
	ui.labelFamiliarColor->setPixmap(pixmap);
}

void SettingDlg::setPhoneticColor(const QColor& color)
{
	QPixmap pixmap(ui.labelPhoneticColor->width(), ui.labelPhoneticColor->height());
	pixmap.fill(color);
	ui.labelPhoneticColor->setPixmap(pixmap);
}

void SettingDlg::slotSetNewColor()
{
	QColor color = QColorDialog::getColor(getNewWordColor(), this);
	if(color.isValid())
		setNewWordColor(color);
}

void SettingDlg::slotSetUnfamiliarColor()
{
	QColor color = QColorDialog::getColor(getUnfamiliarColor(), this);
	if(color.isValid())
		setUnfamiliarColor(color);
}

void SettingDlg::slotSetFamiliarColor()
{
	QColor color = QColorDialog::getColor(getFamiliarColor(), this);
	if(color.isValid())
		setFamiliarColor(color);
}

void SettingDlg::slotSetPhoneticColor()
{
	QColor color = QColorDialog::getColor(getPhoneticColor(), this);
	if(color.isValid())
		setPhoneticColor(color);
}

void SettingDlg::importSetting(const UserSetting &setting)
{
	UserSetting* globalSetting = UserSetting::getInstance("Global");
	setWavDir    (globalSetting->value("WavDir").toString());
	setMp3Dir    (globalSetting->value("Mp3Dir").toString());
	setDBFileName(globalSetting->value("dbFileName").toString());

	setTableFont   (setting.getFont("tableFont"));
	setWordFont    (setting.getFont("wordFont"));
	setChineseFont (setting.getFont("chineseFont"));
	setPhoneticFont(setting.getFont("phoneticFont"));
	setNoteFont    (setting.getFont("noteFont"));
	setGUIFont     (setting.getFont("guiFont"));
	setNewWordColor   (setting.getColor("newWordColor"));
	setUnfamiliarColor(setting.getColor("unFamiliarColor"));
	setFamiliarColor  (setting.getColor("familiarColor"));
	setPhoneticColor  (setting.getColor("phoneticColor"));
	setRightShortcut      (setting.getShortcut("rightShortcut"));
	setWrongShortcut      (setting.getShortcut("wrongShortcut"));
	setChineseShortcut    (setting.getShortcut("chineseShortcut"));
	setSetFamiliarShortcut(setting.getShortcut("setFamiliarShortcut"));
	setAutoBackup(setting.value("Other/autoBackup").toBool());
	slotSetAutoBackup(setting.value("Other/autoBackup").toBool());  // can't trigger slot, why??
	setBackupDays(setting.value("Other/backupDays").toInt());

	setFilteredChar(setting.value("Other/filteredChar").toString());
	setAutoHide (setting.value("LeftPanel/autoHide") .toBool());
	setHideDelay(setting.value("LeftPanel/hideDelay").toInt());
	setShowDelay(setting.value("LeftPanel/showDelay").toInt());
}

UserSetting& SettingDlg::exportSetting() const
{
	UserSetting* globalSetting = UserSetting::getInstance("Global");
	globalSetting->setValue("WavDir",     getWavDir());
	globalSetting->setValue("Mp3Dir",     getMp3Dir());
	globalSetting->setValue("dbFileName", getDBFileName());

	UserSetting* result = UserSetting::getInstance(userName);
	result->setFont("tableFont",    getTableFont());
	result->setFont("wordFont",     getWordFont());
	result->setFont("chineseFont",  getChineseFont());
	result->setFont("phoneticFont", getPhoneticFont());
	result->setFont("noteFont",     getNoteFont());
	result->setFont("guiFont",      getGUIFont());
	result->setColor("newWordColor",    getNewWordColor());
	result->setColor("unFamiliarColor", getUnfamiliarColor());
	result->setColor("familiarColor",   getFamiliarColor());
	result->setColor("phoneticColor",   getPhoneticColor());
	result->setShortcut("rightShortcut",       getRightShortcut());
	result->setShortcut("wrongShortcut",       getWrongShortcut());
	result->setShortcut("chineseShortcut",     getChineseShortcut());
	result->setShortcut("setFamiliarShortcut", getSetFamiliarShortcut());
	result->setValue("Other/autoBackup",   getAutoBackup());
	result->setValue("Other/backupDays",   getBackupDays());
	result->setValue("Other/filteredChar", getFilteredChar());
	result->setValue("LeftPanel/autoHide",  getAutoHide());
	result->setValue("LeftPanel/hideDelay", getHideDelay());
	result->setValue("LeftPanel/showDelay", getShowDelay());
	return *result;
}

void SettingDlg::accept() 
{
	exportSetting();
	QDialog::accept();
}

void SettingDlg::slotSetWavDir()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("选择文件夹"), getWavDir());
	if(!dir.isEmpty())
		setWavDir(dir);
}

void SettingDlg::slotSetMp3Dir()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("选择文件夹"), getMp3Dir());
	if(!dir.isEmpty())
		setMp3Dir(dir);
}

void SettingDlg::slotSetDBFileName()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("选择数据库文件"),
                                                 ".", tr("数据库文件(*.db);;所有文件(*.*)"));
	if(!fileName.isEmpty())
	{
		setDBFileName(fileName);
		QMessageBox::information(this, tr("确定"), tr("重启程序后生效"));
	}
}

void SettingDlg::slotSetAutoHide(bool hide)
{
	ui.spinBoxHideDelay->setEnabled(hide);
	ui.spinBoxShowDelay->setEnabled(hide);
}

void SettingDlg::slotSetAutoBackup(bool hide) {
	ui.spinBoxBackupDays->setEnabled(hide);
}