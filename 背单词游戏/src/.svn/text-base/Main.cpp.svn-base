#include <QtGui/QApplication>
#include <QTextCodec>
#include <QFontDatabase>
#include "Entrance.h"
#include "Library.h"
#include "UserSetting.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QFontDatabase::addApplicationFont("TOPhonetic.ttf");
	
	if(!Library::openDB(Library::getDBFileName()))
	{
		app.quit();
		return 0;
	}

	Library::createTables();
	Entrance entrance;
	entrance.show();
	app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
	int ret = app.exec();
	UserSetting::destroySettingManager();
	return ret;
}