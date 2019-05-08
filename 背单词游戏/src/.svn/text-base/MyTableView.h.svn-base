/*
 *	TableView that can remember section sizes
 *  This is a simplified version, no popup menu, can't hide section...
 */

#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>
#include <map>

class QCloseEvent;

class MyTableView : public QTableView
{
	Q_OBJECT

	typedef std::map<int, float> Map;

public:
	MyTableView(QWidget* parent = 0);
	~MyTableView();

	void setTableName(const QString& table);
	void setSectionSize(int section, int size);
	void saveSectionSizes();

protected:
	virtual void resizeEvent    (QResizeEvent* event);
	virtual void mousePressEvent(QMouseEvent*  event);
	void loadSectionSizes();
	void resizeSections(Map& map);

protected slots:
	void slotResizeSections();
	void slotSetSectionSizes(int section, int oldSize, int newSize);

signals:
	void midClicked();

protected:
	Map sizes;
	QString tableName;
};

#endif // MYTABLEVIEW_H
