/*
 *	WordList means coma+space separated English words, such as abase, abandon, ...
 */

#ifndef WORD_LIST_H 
#define WORD_LIST_H

#include <QString>

class WordList
{
public:
	WordList(const QString& l) : line(l) {}
	virtual ~WordList() {}
	virtual QStringList getSplitted() const = 0;

protected:
	QString line;
};

class EnglishList : public WordList
{
public:
	EnglishList(const QString& l) : WordList(l) {}
	bool    contains(const QString& word) const;
	QString add     (const QString& word);
	QString remove  (const QString& word);
	QStringList getSplitted() const;
};

class ChineseList : public WordList
{
public:
	ChineseList(const QString& l) : WordList(l) {}
	QStringList getSplitted() const;
	QString     getFiltered();

	static bool isChinese(const QString& text);

private:
	static bool isChineseChar(const QChar& ch);
	static bool filtered(const QChar& ch);
};

#endif