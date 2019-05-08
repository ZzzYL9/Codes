#include "WordDisplayer.h"

void MyHighlighter::highlightBlock(const QString& text)
{
	QTextCharFormat wordFormat;
	wordFormat.setForeground(wordColor);
	QRegExp wordExpression("\\b[\\S]+\\b");	
	
	QTextCharFormat phoneticFormat;
	phoneticFormat.setFont(phoneticFont);
	phoneticFormat.setForeground(phoneticColor);
	QRegExp phoneticExpression("\\[.*\\]|\\s");

	int index = text.indexOf(wordExpression);
	while (index >= 0)
	{
		int length = wordExpression.matchedLength();
		setFormat(index, length, wordFormat);
		index = text.indexOf(wordExpression, index + length);
	}	
	
	index = text.indexOf(phoneticExpression);
	while (index >= 0)
	{
		int length = phoneticExpression.matchedLength();
		setFormat(index, length, phoneticFormat);
		index = text.indexOf(phoneticExpression, index + length);
	}
}

WordDisplayer::WordDisplayer(QWidget *parent)
 	: QTextEdit(parent), highlighter(document())
{
	setFont(QFont("Arial", 36, QFont::Bold));  // defaults
	highlighter.setPhoneticFont (QFont("TOPhonetic", 18, QFont::Light));
	highlighter.setPhoneticColor(Qt::black);
	highlighter.setWordColor    (Qt::red);
}