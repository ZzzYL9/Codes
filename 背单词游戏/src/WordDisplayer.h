/*
 *	Displays word and phonetic in corresponding color
 */

#ifndef WORDDISPLAYER_H
#define WORDDISPLAYER_H

#include <QTextEdit>
#include <QSyntaxHighlighter>
#include <QFont>
#include <QColor>

class MyHighlighter : public QSyntaxHighlighter
{
	Q_OBJECT

public:
	MyHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent){}
	void setPhoneticFont (const QFont& font)   { phoneticFont  = font;  }
	void setPhoneticColor(const QColor& color) { phoneticColor = color; }
	void setWordColor    (const QColor& color) { wordColor     = color; }
	QFont  getPhoneticFont()  const { return phoneticFont;  }
	QColor getPhoneticColor() const { return phoneticColor; }
	QColor getWordColor()     const { return wordColor;     }

protected:
	virtual void highlightBlock(const QString& text);

private:
	QFont  phoneticFont;
	QColor phoneticColor;
	QColor wordColor;
};

class WordDisplayer : public QTextEdit
{
	Q_OBJECT

public:
	WordDisplayer(QWidget *parent = 0);

	void setEnglishColor (const QColor& c) { highlighter.setWordColor    (c); }
	void setPhoneticColor(const QColor& c) { highlighter.setPhoneticColor(c); }
	void setEnglishFont  (const QFont& f)  { setFont(f); }
	void setPhoneticFont (const QFont& f)  { highlighter.setPhoneticFont (f); }

private:
	MyHighlighter highlighter;
};

#endif // WORDDISPLAYER_H
