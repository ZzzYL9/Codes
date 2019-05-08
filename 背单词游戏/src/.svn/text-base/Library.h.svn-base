#ifndef LIBRARY_H
#define LIBRARY_H

/*
 *	Some library related sql queries, uglily encapsulated
 */
#include <QStringList>

class  QTextStream;
struct DictSetting;

namespace Library
{
	bool openDB(const QString& name);
	void createTables();
	void addUser(const QString& name);
	void delUser(const QString& name);
	QString     getDBFileName();
	QStringList getDictList();
	QStringList getUserList();
	int         getDictSize(const QString& dictName);
	QString     getChinese(const QString& dictName, const QString& english);
	int         getCredit (const QString& userName, const QString& english);
	void        setCredit(const QString& dictName, const QString& userName, 
				          const QString& word, int credit);
	int  searchEnglish(const QString& dictName, const QString& english);
	int  getNextID(const QString& tableName);
	void exportMp3(const QString& destDir, const QString& english);
};

#endif