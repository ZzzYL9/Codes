/*
*  TabWidget that auto-hides when mouse leaves or double-clicks on the tab
*  shows up when mouse enters or double-clicks on the tab
*/

#ifndef POPPINGTABWIDGET_H
#define POPPINGTABWIDGET_H

#include <QTabWidget>
#include <QTimer>

class PoppingTabWidget : public QTabWidget
{
	Q_OBJECT

public:
	PoppingTabWidget(QWidget *parent);

protected:
	virtual void  showEvent (QShowEvent*);
	virtual void  leaveEvent(QEvent* event);
	virtual void  enterEvent(QEvent* event);

private slots:
	void slotExtend();
	void slotShrink();

private:
	bool autoHide()  const;
	int  showDelay() const;
	int  hideDelay() const;
	int  getMinShowWidth() const;

private:
	QTimer timerHide;
	QTimer timerShow;
};

#endif // POPPINGTABWIDGET_H
