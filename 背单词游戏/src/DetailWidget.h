/*
 *	Displays word, phonetic, Chinese and note
 */

#ifndef DETAILWIDGET_H
#define DETAILWIDGET_H

#include <QWidget>
#include <QList>
#include <QModelIndex>
#include "ui_DetailWidget.h"

class DictionaryModel;

class DetailWidget : public QWidget
{
	Q_OBJECT

public:
	DetailWidget(QWidget *parent = 0);
	void setModel(DictionaryModel* m) { model = m; }
	void setEnglishFont  (const QFont& font);
	void setPhoneticFont (const QFont& font);
	void setChineseFont  (const QFont& font);
	void setNoteFont     (const QFont& font);
	void setPhoneticColor(const QColor& color);
	void showRow(bool show);

	QList<int> getSplitterSizes() const;
	void       setSplitterSizes(const QList<int> sizes);

private slots:
	void slotSave();
	void slotSetCurrentRow(const QModelIndex& current);

private:
	void showEnglish();
	void showChinese(bool show);
	void showNote   (bool show);

private:
	Ui::DetailWidgetClass ui;
	DictionaryModel* model;
	int  currentRow;
};

#endif // DETAILWIDGET_H
