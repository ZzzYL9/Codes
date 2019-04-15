#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include "Item.h"
#include "qlabel.h"


class ControlPanel : public QWidget
{
	Q_OBJECT

public:
	ControlPanel(QWidget *parent);
	~ControlPanel();

	void SetNext(ITEM_TYPE t,int nShape);
	void SetScore(int n);
	void SetSpeed(int n);
protected:
	void paintEvent(QPaintEvent *);


private:
	Item m_NextItem;

	QLabel* m_pScore;

	QLabel* m_pSpeed;
	int m_nSpeed;
};

#endif // CONTROLPANEL_H
