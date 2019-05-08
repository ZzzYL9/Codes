#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QProgressDialog>
#include <QApplication>
#include "DictLoader.h"

DictLoader::DictLoader(const QString& file, const QString& dict, QObject *parent)
	: QObject(parent), fileName(file), dictName(dict) {}

bool DictLoader::createDictTable(const QString& dict)
{
	QSqlQuery query;
	return query.exec(tr("CREATE TABLE %1 (编号 int primary key,  \
									单词 varchar,          \
									解释 varchar,          \
									得分 int,              \
									音标 varchar,          \
									备注 varchar,          \
									排序 int)").arg(dict));
}

void DictLoader::delDict(const QString& dict)
{
	QSqlQuery query;
	query.exec(tr("DROP TABLE %1").arg(dict));
	query.exec(tr("DELETE FROM Library WHERE dict = \"%1\"").arg(dict));
	query.exec(tr("DELETE FROM History WHERE dict = \"%1\"").arg(dict));
}

void DictLoader::addDictToLibrary(const QString& dict)
{
	QSqlQuery query;
	query.exec(tr("INSERT INTO Library VALUES(\'%1\')").arg(dict));
}

void DictLoader::load()
{
	if(!createDictTable(dictName))
	{
		QMessageBox::critical(0, tr("错误"), tr("无法创建词典"));
		return;
	}
	if(doLoad())
		addDictToLibrary(dictName);
	else
		delDict(dictName);
}

int DictLoader::check()
{
	file.setFileName(fileName);
	if(!file.open(QFile::ReadOnly))
	{
		QMessageBox::critical(0, tr("错误"), tr("打开文件错误"));
		return -1;
	}

	currentRow = 0;
	int wordCount = 0;
	is.setDevice(&file);           // beginning
	QString line;
	do {
		line = getLine();
	} while(isBeginLine(line));

	while(!is.atEnd())
	{
		if(!isEnglishLine(line))   // english
		{
			showError();
			return -1;
		}

		if(getLine().isEmpty())    // chinese
		{
			showError();
			return -1;
		}

		do
		{
			line = getLine();
		} while (!line.isEmpty());

		while(!is.atEnd() && line.isEmpty())   // empty
			line = getLine();

		wordCount ++;
	}

	return wordCount;
}

bool DictLoader::doLoad()
{
	int wordCount = check();
	if(wordCount == -1)
		return false;

	is.seek(0);
	QString line;
	do {
		line = getLine();
	} while(isBeginLine(line));

	id = 0;
	QProgressDialog progress(tr("一共%1个单词，正在导入...").arg(wordCount), 
							 0, 0, wordCount);
	progress.setWindowTitle(tr("词典导入中"));
	progress.setWindowModality(Qt::WindowModal);

	QSqlDatabase::database().transaction();
	QString english, chinese;
	while(!is.atEnd())
	{
		english = line;
		chinese = getLine();

		line = getLine();
		while (!line.isEmpty())
		{
			chinese += line;
			line = getLine();
		}

		addRecord(english, chinese);
		progress.setValue(id);
		qApp->processEvents();

		while(!is.atEnd() && line.isEmpty())
			line = getLine();
	}

	QSqlDatabase::database().commit();
	return true;
}

void DictLoader::showError() {
	QMessageBox::critical(0, tr("文件格式有误"), tr("请检查第%1行").arg(currentRow));
}

bool DictLoader::isEnglishLine(const QString& line)
{
	return ( line.contains("[") &&  line.contains("]")) ||
		   (!line.contains("[") && !line.contains("]"));
}

QString DictLoader::getLine() 
{
	currentRow ++;
	return is.readLine();
}

bool DictLoader::isBeginLine(const QString& line) {
	return !line.contains("[") && !line.contains("]");   // no []
}

void DictLoader::addRecord(const QString& englishLine, const QString& chinese)
{
	QString english  = englishLine.section(' ', 0, 0);
	QString phonetic = englishLine.section(' ', 1, -1, QString::SectionSkipEmpty);
	QSqlQuery query;
	query.exec(tr("INSERT INTO %1 VALUES (\"%2\", \"%3\", \"%4\", 0, \"%5\", \"\", 0)")
				.arg(dictName).arg(++id).arg(english).arg(chinese).arg(phonetic));
}