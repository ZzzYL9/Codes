#include "PoppingTabWidget.h"
#include "PoppingTabBar.h"
#include "UserSetting.h"
#include "MainWindow.h"
#include <QTabBar>
#include <QDesktopWidget>
#include <QApplication>

PoppingTabWidget::PoppingTabWidget(QWidget *parent) : QTabWidget(parent)
{
	PoppingTabBar* tb = new PoppingTabBar(this);
	setTabBar(tb);

	connect(&timerHide, SIGNAL(timeout()), this, SLOT(slotShrink()));
	connect(&timerShow, SIGNAL(timeout()), this, SLOT(slotExtend()));
	connect(tb,         SIGNAL(extend()),  this, SLOT(slotExtend()));
	connect(tb,         SIGNAL(shrink()),  this, SLOT(slotShrink()));
}

void PoppingTabWidget::leaveEvent(QEvent* event) 
{
	if(autoHide())
	{
		timerHide.start(hideDelay() * 1000);
		timerShow.stop();
	}
	QWidget::leaveEvent(event);
}

void PoppingTabWidget::enterEvent(QEvent* event)
{
	if(autoHide())
	{
		timerHide.stop();
		timerShow.start(showDelay() * 1000);
	}
	QWidget::enterEvent(event);
}

void PoppingTabWidget::slotExtend()
{
	timerShow.stop();
	setMaximumWidth(1000);
	setMinimumWidth(getMinShowWidth());
}

void PoppingTabWidget::slotShrink()
{
	timerHide.stop();
	setMinimumWidth(tabBar()->width());
	setMaximumWidth(tabBar()->width());
}

void PoppingTabWidget::showEvent(QShowEvent*) {
	autoHide() ? slotShrink() : slotExtend();
}

bool PoppingTabWidget::autoHide() const {
	return UserSetting::getInstance(MainWindow::userName)->value("LeftPanel/autoHide").toBool();
}

int PoppingTabWidget::showDelay() const {
	return UserSetting::getInstance(MainWindow::userName)->value("LeftPanel/showDelay").toInt();
}

int PoppingTabWidget::hideDelay() const {
	return UserSetting::getInstance(MainWindow::userName)->value("LeftPanel/hideDelay").toInt();
}

int PoppingTabWidget::getMinShowWidth() const {
	return QApplication::desktop()->width() * 0.26;
}
