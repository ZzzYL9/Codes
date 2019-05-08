#include "NewDictDlg.h"
#include <QFileDialog>

NewDictDlg::NewDictDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.buttonLoad->setEnabled(false);

	connect(ui.buttonLoad, SIGNAL(clicked()), this, SLOT(slotLoadFile()));
	connect(ui.lineEditDictName, SIGNAL(textChanged(const QString&)), 
			this,				 SLOT(slotDictNameModified(const QString&)));
}

void NewDictDlg::slotLoadFile()
{
	dictName = ui.lineEditDictName->text();
	fileName = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Dict Files (*.* *.txt)"));
	accept();
}

void NewDictDlg::slotDictNameModified(const QString& name) {
	ui.buttonLoad->setEnabled(!name.isEmpty());
}