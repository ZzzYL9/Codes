#ifndef GROUPDLG_H
#define GROUPDLG_H

#include <QDialog>
#include <QString>
#include "ui_GroupDlg.h"

class QSqlTableModel;
class QModelIndex;

class SearchResult
{
public:
	void add(const QModelIndexList& indexList);
	void add(const QModelIndex&     index);
	void clear();
	int  next();
	void sort();
	bool isEmpty() const;
private:
	QModelIndexList results;
	int             current;
};

class GroupDlg : public QDialog
{
	Q_OBJECT

public:
	GroupDlg(QWidget *parent, const QString& dict, const QString& table, const QString& w);
	~GroupDlg();
	int exec();

private slots:
	void slotNew();
	void slotDel();
	void slotJoin();
	void slotNext();
	void slotEdit();
	void slotUnite();
	void slotSetCurrentRow(const QModelIndex&);
	bool slotSearch(const QString& target, bool fuzzy = true);
	void slotExport();

private:
	void initModel();
	void initView();
	void initConnection();
	void selectRow(int row, bool select = true);
	bool search(const QString& target, int start, int end, bool fuzzy = true);
	void searchChinese(const QString& target);
	void searchEnglish(const QString& target, int column, bool fuzzy);
	void addRecord(const QString& groupName, const QString& englishLine);
	void setRecord(int row, const QString& groupName, const QString& englishLine);
	void finishEditGroup(const QString& groupName);
	QString getGroupName  (int row) const;
	QString getEnglishLine(int row) const;
	void fetchAll();
	QModelIndexList getSelectedIndexes() const;

private:
	Ui::GroupDlgClass ui;
	QSqlTableModel* model;
	QString         dictName;
	QString         tableName;
	QString         word;
	QString         rawChinese;
	QString         filteredChinese;
	int             currentRow;
	SearchResult    searchResults;
};


#endif // GROUPDLG_H
