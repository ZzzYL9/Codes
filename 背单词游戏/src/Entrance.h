#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <QtGui/QDialog>
#include "ui_Entrance.h"

class Entrance : public QDialog
{
	Q_OBJECT

public:
	Entrance(QWidget *parent = 0, Qt::WFlags flags = 0);

public slots:
	void show();

private slots:
	void slotEnter();
	void slotAddUser();
	void slotDelUser();

private:
	void go(const QString& userName);

private:
	Ui::EntranceClass ui;	
};

#endif // ENTRANCE_H
