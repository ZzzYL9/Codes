#ifndef COGNATEWIDGET_H
#define COGNATEWIDGET_H

#include <QWidget>
#include "ui_CognateWidget.h"

class CognateWidget : public QWidget
{
	Q_OBJECT

public:
	CognateWidget(QWidget *parent = 0);

	void setDictName   (const QString& dict);
	void setCentralWord(const QString& word, bool showChinese);

private slots:
	void slotDoubleClicked(QTableWidgetItem*);

signals:
	void doubleClicked(int id, bool);

private:
	Ui::CognateWidgetClass ui;
	QString dictName;
};

#endif // COGNATEWIDGET_H
