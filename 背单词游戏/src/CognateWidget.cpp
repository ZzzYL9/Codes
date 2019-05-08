#include "CognateWidget.h"
#include "Library.h"
#include <QtSql/QSqlQuery>
#include <QHeaderView>

CognateWidget::CognateWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);
	ui.tableWidget->setRowCount(7);

	connect(ui.tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
			this,           SLOT(slotDoubleClicked(QTableWidgetItem*)));
}

void CognateWidget::slotDoubleClicked(QTableWidgetItem* item)
{
	const int row = ui.tableWidget->row(item);
	QTableWidgetItem* wordItem = ui.tableWidget->item(row, 0);
	emit doubleClicked(Library::searchEnglish(dictName, wordItem->text()), true);
}

void CognateWidget::setDictName(const QString& dict) {
	dictName = dict;
}

void CognateWidget::setCentralWord(const QString& word, bool showChinese)
{
	int id = Library::searchEnglish(dictName, word);
	if(id != -1)
	{
		QSqlQuery query;
		query.exec(tr("SELECT µ¥´Ê, ½âÊÍ FROM %1 WHERE ±àºÅ BETWEEN %2 AND %3")
						.arg(dictName).arg(id-3).arg(id+3));
		ui.tableWidget->clearContents();
		int i = 0;
		while(query.next())
		{
			QString english = query.value(0).toString();
			QString chinese = showChinese ? query.value(1).toString() : QString();
			ui.tableWidget->setItem(i, 0, new QTableWidgetItem(english));
			ui.tableWidget->setItem(i, 1, new QTableWidgetItem(chinese));
			i ++;
		}
		ui.tableWidget->sortItems(0);
		ui.tableWidget->resizeColumnToContents(0);
	}
}
