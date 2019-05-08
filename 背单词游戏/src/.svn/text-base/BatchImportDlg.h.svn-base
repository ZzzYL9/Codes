/*
 *	Group editing dialog
 */

#ifndef BATCHIMPORTDLG_H
#define BATCHIMPORTDLG_H

#include <QDialog>
#include "ui_BatchImportDlg.h"

class SearchWidget;

class BatchImportDlg : public QDialog
{
	Q_OBJECT

public:
	BatchImportDlg(QWidget *parent, const QString& dict, const QString& ch, 
														 const QString& en);
	QString getGroupName()   const { return ui.lineEditGroupName->text(); }
	QString getEnglishList() const;
	int     exec();

public slots:
	void slotSearch(const QString& target);
	void slotReSearch();
	void slotAppendName();
	void slotCopyName();
	void slotImport();
	void slotDel();
	void slotAll();
	void slotGroupWidgetActivated ();
	void slotSearchWidgetActivated();
	void accept();

private:
	void initView(const QString& chineseLine);
	void initConnection();
	void loadOldWords(const QString& englishLine);
	void enableOption(bool enable);
	SearchWidget::SearchOption getOption() const;

private:
	Ui::BatchImportDlgClass ui;
	QString       dictName;
	SearchWidget* activeTable;
};


#endif // BATCHIMPORTDLG_H
