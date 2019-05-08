#include <QtSql/QSqlQuery>
#include <QtGui>
#include "MyTableView.h"

MyTableView::MyTableView(QWidget *parent) : QTableView(parent) {}

MyTableView::~MyTableView() {
	saveSectionSizes();
}

void MyTableView::loadSectionSizes()
{
	QSqlQuery query;
	query.exec(tr("SELECT section, size FROM SectionSizes WHERE tableName = \'%1\'")
															.arg(tableName));
	while(query.next())
		sizes[query.value(0).toInt()] = query.value(1).toDouble();
}

void MyTableView::saveSectionSizes()
{
	QSqlQuery query;
	query.exec(tr("DELETE FROM SectionSizes WHERE tableName = \'%1\'").arg(tableName));
	for(int i=0; i<horizontalHeader()->count(); ++i)
		query.exec(tr("INSERT INTO SectionSizes VALUES(\'%1\', %2, %3)")
							.arg(tableName)
							.arg(i)
							.arg((float)horizontalHeader()->sectionSize(i) / width()));
}

void MyTableView::slotSetSectionSizes(int section, int /*oldSize*/, int newSize) {
	sizes[section] = (float)newSize / width();
}

void MyTableView::setTableName(const QString& table)
{
	if(!tableName.isEmpty() && table != tableName)
		saveSectionSizes();   // save last table
	tableName = table;
	loadSectionSizes();
	slotResizeSections();
}

void MyTableView::slotResizeSections()
{
	disconnect(horizontalHeader(), SIGNAL(sectionResized(int, int, int)), 
			this, SLOT(slotSetSectionSizes(int, int, int)));
	resizeSections(sizes);
	connect(horizontalHeader(), SIGNAL(sectionResized(int, int, int)), 
			this, SLOT(slotSetSectionSizes(int, int, int)));
}

void MyTableView::resizeSections(Map& map)
{
	int lastNoneZero;
	for(lastNoneZero=map.size()-1; lastNoneZero>=0 && map[lastNoneZero]==0; --lastNoneZero)
		;
	for(size_t section=0; section<map.size(); ++section)
	{
		if(map[section] == 0)
			hideColumn(section);
		else
		{
			showColumn(section);
			if(section != lastNoneZero)  // ignore last non-0 section
				setColumnWidth(section, map[section] * width());
		}
	}
}

void MyTableView::resizeEvent(QResizeEvent* event) 
{
	slotResizeSections();
	QTableView::resizeEvent(event);
}

void MyTableView::mousePressEvent(QMouseEvent* event)
{
	QTableView::mousePressEvent(event);
	if(event->button() == Qt::MidButton)
		emit midClicked();
}