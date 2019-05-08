/*
 *	TabBar working with auto-hide TabWidget
 */

#ifndef POPPINGTABBAR_H
#define POPPINGTABBAR_H

#include <QTabBar>
#include <QTimer>

class QMouseEvent;
class QEvent;

class PoppingTabBar : public QTabBar
{
	Q_OBJECT

public:
	PoppingTabBar(QWidget *parent);

protected:
	virtual void enterEvent(QEvent* event);
	virtual void leaveEvent(QEvent* event);
	virtual void mousePressEvent      (QMouseEvent* event);
	virtual void mouseDoubleClickEvent(QMouseEvent* event);

private:
	bool autoHide()  const;
	int  showDelay() const;

signals:
	void extend();
	void shrink();

private:
	QTimer timer;
};

#endif // POPPINGTABBAR_H
