#include "PoppingTabBar.h"
#include "UserSetting.h"
#include "MainWindow.h"
#include <QMouseEvent>

PoppingTabBar::PoppingTabBar(QWidget *parent) : QTabBar(parent) {
	connect(&timer, SIGNAL(timeout()), this, SIGNAL(extend()));
}

void PoppingTabBar::enterEvent(QEvent* event)
{
	if(autoHide())
		timer.start(showDelay() * 1000);
	QTabBar::enterEvent(event);
}

void PoppingTabBar::leaveEvent(QEvent* event)
{
	if(autoHide())
		timer.stop();
	QTabBar::leaveEvent(event);
}

void PoppingTabBar::mouseDoubleClickEvent(QMouseEvent* event) 
{
	emit shrink();
	event->ignore();      // ignore this event
}

void PoppingTabBar::mousePressEvent(QMouseEvent* event)
{
	emit extend();
	QTabBar::mousePressEvent(event);
}

bool PoppingTabBar::autoHide() const {
	return UserSetting::getInstance(MainWindow::userName)->value("LeftPanel/autoHide").toBool();
}

int PoppingTabBar::showDelay() const {
	return UserSetting::getInstance(MainWindow::userName)->value("LeftPanel/showDelay").toInt();
}