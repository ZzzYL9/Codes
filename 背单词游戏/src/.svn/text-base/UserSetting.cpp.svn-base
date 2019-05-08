#include "UserSetting.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QFile>

UserSetting::UserSetting(const QString& name) : MySetting(name) 
{
	if(QFile(name + ".ini").size() == 0)   // no setting
		loadDefaults();
}

void UserSetting::loadDefaults()
{
	if(getUserName() == "Global")
	{
		setValue("dbFileName", "word.db");
		setValue("WavDir",     "Sound");
		setValue("Mp3Dir",     "Mp3");
	}
	else
	{
		setFont("tableFont",    QFont(tr("Arial"),      11));
		setFont("wordFont",     QFont(tr("Arial"),      72, QFont::Bold));
		setFont("phoneticFont", QFont(tr("TOPhonetic"), 18, QFont::Normal));
		setFont("chineseFont",  QFont(tr("ËÎÌå"),       20, QFont::Bold));
		setFont("noteFont",     QFont(tr("Arial"),      16));
		setFont("guiFont",      QFont(tr("ËÎÌå"),       10));

		setColor("newWordColor",    QColor(Qt::red));
		setColor("unFamiliarColor", QColor(Qt::gray));
		setColor("familiarColor",   QColor(Qt::darkGreen));
		setColor("phoneticColor",   QColor(Qt::darkBlue));

		setShortcut("rightShortcut",       QString("Right"));
		setShortcut("wrongShortcut",       QString("Left"));
		setShortcut("chineseShortcut",     QString("Ctrl+H"));
		setShortcut("setNewShortcut",      QString("Ctrl+N"));
		setShortcut("setFamiliarShortcut", QString("Ctrl+F"));

		beginGroup("Other");
		setValue("filteredChar", tr("£¬¡££»¡¢µÄ"));
		setValue("isDefault",    false);
		setValue("currentDict",  QString());
		setValue("autoBackup",   true);
		setValue("backupDays",   7);
		endGroup();

		beginGroup("LeftPanel");
		setValue("autoHide",  true);
		setValue("hideDelay", 5);
		setValue("showDelay", 1);
		endGroup();

		setSize("LeftSplitterLeft",      300);
		setSize("LeftSplitterRight",     700);
		setSize("VerticalSplitterUp",    350);
		setSize("VerticalSplitterDown",  450);
		setSize("DetailSplitterEnglish", 200);
		setSize("DetailSplitterChinese", 100);
		setSize("DetailSplitterNote",    150);

		beginGroup("ButtonStatus");
		setValue("Recite",         false);
		setValue("Upper",          false);
		setValue("HideControlBar", false);
		endGroup();
	}
}

QFont UserSetting::getFont(const QString& section) const
{
	QFont font;
	font.fromString(value("Font/" + section).toString());
	return font;
}
QColor UserSetting::getColor(const QString& section) const {
	return value("Color/" + section).toInt();
}
QKeySequence UserSetting::getShortcut(const QString& section) const {
	return QKeySequence(value("Shortcut/" + section).toString());
}
int UserSetting::getSize(const QString& section) const {
	return value("Sizes/" + section).toInt();
}
void UserSetting::setFont(const QString& section, const QFont& font) {
	setValue("Font/" + section, font.toString());
}
void UserSetting::setColor(const QString& section, const QColor& color) {
	setValue("Color/" + section, color.rgb());
}
void UserSetting::setShortcut(const QString& section, const QKeySequence& keySequence){
	setValue("Shortcut/" + section, keySequence.toString());
}
void UserSetting::setSize(const QString& section, int size) {
	setValue("Sizes/" + section, size);
}

DictSetting UserSetting::getDictSetting(const QString& dictName)
{
	DictSetting result;
	beginGroup(dictName);
	result.unitSize       = value("unitSize")      .toInt();
	result.currentUnit    = value("currentUnit")   .toInt();
	result.threshold1     = value("threshold1")    .toInt();
	result.threshold2     = value("threshold2")    .toInt();
	result.showNew        = value("showNew")       .toBool();
	result.showUnFamiliar = value("showUnFamiliar").toBool();
	result.showFamiliar   = value("showFamiliar")  .toBool();
	endGroup();
	return result;
}

void UserSetting::setDictSetting(const QString& dictName, const DictSetting& setting)
{
	beginGroup(dictName);
	setValue("unitSize",       setting.unitSize);
	setValue("currentUnit",    setting.currentUnit);
	setValue("threshold1",     setting.threshold1);
	setValue("threshold2",     setting.threshold2);
	setValue("showNew",        setting.showNew);
	setValue("showUnFamiliar", setting.showUnFamiliar);
	setValue("showFamiliar",   setting.showFamiliar);
	endGroup();
}

bool UserSetting::containsDictSetting(const QString& dictName) const {
	return childGroups().contains(dictName);
}