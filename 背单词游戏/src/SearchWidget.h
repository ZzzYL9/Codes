/*
 *	Used in SearchTab and BatchImportDlg
 */

#ifndef SEARCHTABLE_H
#define SEARCHTABLE_H

#include <QWidget>
#include "ui_SearchWidget.h"

class QSqlTableModel;
class QStandardItemModel;

class SearchWidget : public QWidget
{
	Q_OBJECT

public:
	typedef enum{BEGIN, ANY, END} SearchOption;

public:
	SearchWidget(QWidget *parent = 0);
	void setDictName (const QString& dict);
	void search      (const QString& target, SearchOption option);
	void appendRecord(const QString& english, const QString& chinese);
	void delRecord   (const QString& english);
	void selectAll(bool select);
	void moveRecordsTo  (SearchWidget& dest);
	void removeDuplicate(const SearchWidget& other);
	int     rowCount() const;
	QString getEnglish(int row) const;
	QString getChinese(int row) const;
	void sort();

private slots:
	void slotDoubleClicked(const QModelIndex&);

private:
	void setRecord(int row, const QString& english, const QString& chinese);
	bool validRow (int row) const;

signals:
	void doubleClicked(int);
	void clicked();

private:
	void initModel();
	void initView();
	void initConnection();
	QString getFilter(QString target, SearchOption option) const;
	int findEnglish(const QString& english) const;
	QModelIndexList getSelected() const;

private:
	Ui::SearchWidgetClass ui;
	QSqlTableModel*     modelSql;
	QStandardItemModel* model;
	QString             dictName;
};

#endif // SEARCHTABLE_H
