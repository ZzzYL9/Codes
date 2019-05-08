#include "GroupWidget.h"
#include "Library.h"
#include "GroupDlg.h"
#include "BatchImportDlg.h"
#include "WordList.h"
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QHeaderView>

GroupWidget::GroupWidget(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	initConnections();
}

void GroupWidget::initConnections()
{
	connect(ui.buttonAddSynonym, SIGNAL(clicked()), this, SLOT(slotAddSynonym()));
	connect(ui.buttonAddAntonym, SIGNAL(clicked()), this, SLOT(slotAddAntonym()));
	connect(ui.buttonAddSimilar, SIGNAL(clicked()), this, SLOT(slotAddSimilar()));
	connect(ui.buttonDel,        SIGNAL(clicked()), this, SLOT(slotDel()));
	connect(ui.treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
			this,          SLOT  (slotItemDbClicked(QTreeWidgetItem*, int)));
}

QTreeWidgetItem* GroupWidget::createGroupItem(const QString& categoryName) const
{
	QTreeWidgetItem* categoryItem = new QTreeWidgetItem(QStringList() << categoryName);
	QSqlQuery query;
	query.exec(tr("SELECT chinese, words FROM %1 WHERE words LIKE \"%%2%\"")
											.arg(categoryName).arg(centralWord));
	while(query.next())
	{
		EnglishList englishList(query.value(1).toString());
		if(englishList.contains(centralWord))
		{
			QTreeWidgetItem* groupItem = 
				new QTreeWidgetItem(categoryItem, QStringList() << query.value(0).toString());
			groupItem->setIcon(0, QIcon(QPixmap(":/Entrance/Images/star.png")));
			QStringList wordList = englishList.getSplitted();
			foreach(QString word, wordList)
			{
				groupItem->addChild(new QTreeWidgetItem(
					QStringList() << word << Library::getChinese(dictName, word)));
			}
			categoryItem->addChild(groupItem);
		}
	}
	if(categoryItem->childCount() == 0)
	{
		delete categoryItem;
		return 0;
	}
	return categoryItem;
}

void GroupWidget::setCentralWord(const QString& word, bool show)
{
	if(word.isEmpty())
		return;

	centralWord = word.toLower();
	ui.treeWidget->clear();

	if(!show)
		return;

	QTreeWidgetItem* synonymItem = createGroupItem(tr("近义词"));
	QTreeWidgetItem* antonymItem = createGroupItem(tr("反义词"));
	QTreeWidgetItem* similarItem = createGroupItem(tr("易混词"));
	if(synonymItem != 0)
	{
		synonymItem->setIcon(0, QIcon(QPixmap(":/Entrance/Images/Smile.png")));
		ui.treeWidget->addTopLevelItem(synonymItem);
	}
	if(antonymItem != 0)
	{
		antonymItem->setIcon(0, QIcon(QPixmap(":/Entrance/Images/Alert_04.png")));
		ui.treeWidget->addTopLevelItem(antonymItem);
	}
	if(similarItem != 0)
	{
		similarItem->setIcon(0, QIcon(QPixmap(":/Entrance/Images/Help.png")));
		ui.treeWidget->addTopLevelItem(similarItem);
	}
	ui.treeWidget->expandAll();
	ui.treeWidget->header()->resizeSections(QHeaderView::ResizeToContents);

	highlightCurrent();
}

QString GroupWidget::getCurrentGroupName() const
{
	QTreeWidgetItem* item = ui.treeWidget->currentItem();
	if(item == 0)
		return QString();

	while(item->parent() != 0)
		item = item->parent();
	return item->text(0);
}

void GroupWidget::openGroupDlg(const QString& table)
{
	if(!table.isEmpty())
	{
		GroupDlg dlg(this, dictName, table, centralWord);
		dlg.exec();
		setCentralWord(centralWord);   // refresh
		emit jobFinished();
	}
}

void GroupWidget::slotAddSynonym() {
	openGroupDlg(tr("近义词"));
}
void GroupWidget::slotAddAntonym() {
	openGroupDlg(tr("反义词"));
}
void GroupWidget::slotAddSimilar() {
	openGroupDlg(tr("易混词"));
}

void GroupWidget::slotDel()
{
	QString table = getCurrentGroupName();
	if(table.isEmpty())	return;

	QTreeWidgetItem* item = ui.treeWidget->currentItem();
	if(item->parent() == 0)            // topmost
		return;

	if(item->parent()->parent() != 0)  // grandchild
	{
		if(QMessageBox::warning(this, tr("确认"), tr("确认从该组中删除单词么？"), 
								QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
		{
			const QString groupName = item->parent()->text(0);
			const QString itemLine  = item->text(0);
			if(leaveGroup(table, groupName, getItemEnglish(itemLine)))  // empty
				delGroup(table, groupName);
		}
	}
	else if(QMessageBox::warning(this, tr("确认"), tr("确认删除该组么？"), 
						QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
		delGroup(table, item->text(0));

	setCentralWord(centralWord);   // refresh
}

QString GroupWidget::getItemEnglish(const QString& itemLine) const {
	return itemLine.split(':', QString::SkipEmptyParts).at(0);
}

// return true if empty
bool GroupWidget::leaveGroup(const QString& table, const QString& groupName, 
							 const QString& word)
{
	QSqlQuery query;
	query.exec(tr("SELECT words FROM %1 WHERE chinese = \"%2\"")
							.arg(table).arg(groupName));
	while(query.next())
	{
		EnglishList englishList(query.value(0).toString());
		if(englishList.contains(word))
		{
			QString newLine = englishList.remove(word);
			if(newLine.isEmpty())
				return true;     // empty
			else
				query.exec(tr("UPDATE %1 SET words=\"%2\" WHERE chinese=\"%3\"")
								.arg(table).arg(newLine).arg(groupName));
		}
	}
	return false;
}

void GroupWidget::delGroup(const QString& table, const QString& groupName)
{
	QSqlQuery query;
	query.exec(tr("DELETE FROM %1 WHERE chinese = \"%2\"").arg(table)
														  .arg(groupName));
}

void GroupWidget::slotItemDbClicked(QTreeWidgetItem* item, int)
{
	if(item->parent() != 0 && item->parent()->parent() != 0)
	{
		QString english = getItemEnglish(item->data(0, Qt::DisplayRole).toString());
		emit itemDbClicked(Library::searchEnglish(dictName, english), true);
	}
}

void GroupWidget::highlightCurrent()
{
	for(int i=0; i<ui.treeWidget->topLevelItemCount(); ++i)
	{
		QTreeWidgetItem* topItem = ui.treeWidget->topLevelItem(i);
		for(int j=0; j<topItem->childCount(); ++j)
		{
			QTreeWidgetItem* groupItem = topItem->child(j);
			for(int k=0; k<groupItem->childCount(); ++k)
			{
				QTreeWidgetItem* item = groupItem->child(k);
				if(item->text(0) == centralWord)
				{
					item->setSelected(true);
					ui.treeWidget->scrollToItem(item, QAbstractItemView::PositionAtCenter);
				}
			}
		}
	}
}