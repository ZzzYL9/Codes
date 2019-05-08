#ifndef GROUPWIDGET_H
#define GROUPWIDGET_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include "ui_GroupWidget.h"

class GroupWidget : public QWidget
{
	Q_OBJECT

public:
	GroupWidget(QWidget *parent = 0);
	void setDictName(const QString& dict) { dictName = dict; }
	void setCentralWord(const QString& word, bool show = true);

public slots:
	void slotAddSynonym();
	void slotAddAntonym();
	void slotAddSimilar();
	void slotDel();
	void slotItemDbClicked(QTreeWidgetItem* item, int column);

signals:
	void itemDbClicked(int id, bool);
	void jobFinished();

private:
	void initConnections();
	bool leaveGroup  (const QString& table, const QString& groupName, const QString& word);
	void delGroup    (const QString& table, const QString& groupName);
	void openGroupDlg(const QString& table);
	QString getCurrentGroupName() const;
	QString getItemEnglish(const QString& itemLine) const;
	QTreeWidgetItem* createGroupItem(const QString& categoryName) const;
	void highlightCurrent();

private:
	Ui::GroupWidgetClass ui;
	QString dictName;
	QString centralWord;
};

#endif // GROUPWIDGET_H
