#ifndef NEWDICTDLG_H
#define NEWDICTDLG_H

#include <QDialog>
#include <QString>
#include "ui_NewDictDlg.h"

class NewDictDlg : public QDialog
{
	Q_OBJECT

public:
	NewDictDlg(QWidget *parent = 0);

	QString getDictName() const { return dictName; }
	QString getFileName() const { return fileName; }

private slots:
	void slotLoadFile();
	void slotDictNameModified(const QString& name);

private:
	Ui::NewDictDlgClass ui;
	QString fileName;
	QString dictName;
};

#endif // NEWDICTDLG_H
