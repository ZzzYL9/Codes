#include "WordList.h"
#include "MainWindow.h"
#include "UserSetting.h"
#include <QStringList>

bool EnglishList::contains(const QString& word) const {
	return getSplitted().contains(word);
}

QString EnglishList::add(const QString& word)
{
	QStringList list = getSplitted();
	list << word;
	list.sort();
	return line = list.join(", ");
}

QString EnglishList::remove(const QString& word)
{
	QStringList list = getSplitted();
	int index = list.indexOf(word);
	if(index < 0)
		return line;

	list.removeAt(index);
	return line = list.join(", ");
}

QStringList EnglishList::getSplitted() const {
	return line.split(", ", QString::SkipEmptyParts);
}

bool ChineseList::isChinese(const QString& text)
{
	foreach(QChar ch, text)
		if(isChineseChar(ch))
			return true;
	return false;
}

bool ChineseList::isChineseChar(const QChar& ch) {
	return ch.toAscii() == 0;   // urgly!! better way??
}

bool ChineseList::filtered(const QChar& ch)
{
	const QString filteredChar = UserSetting::getInstance(MainWindow::userName)
												->value("Other/filteredChar").toString();
	return filteredChar.contains(ch) || !isChineseChar(ch);
}

QStringList ChineseList::getSplitted() const
{
	QStringList result;
	QString word;
	for(int i=0; i<line.length(); ++i)
	{
		QChar ch = line.at(i);
		if(filtered(ch))
		{
			if(!word.isEmpty())   // 1 word finished
			{
				result << word;
				word.clear();
			}
		}
		else                      // continue constructing a word
			word += ch;		
	}
	if(!word.isEmpty())
		result << word;
	return result;
}

QString ChineseList::getFiltered() {
	return line = getSplitted().join(QObject::tr("¡¢"));
}