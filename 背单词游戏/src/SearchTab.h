#ifndef SEARCHTAB_H
#define SEARCHTAB_H

#include <QWidget>
#include "ui_SearchTab.h"

class SearchTab : public QWidget
{
	Q_OBJECT

public:
	SearchTab(QWidget *parent = 0);
	void setDictName(const QString& dict);

protected:
	virtual void enterEvent(QEvent*);

private slots:
	void slotSearch(const QString& target);
	void slotReSearch();
	void slotDoubleClicked(int);

private:
	SearchWidget::SearchOption getOption() const;
	void enableOption(bool enable);
	void focusInput();

signals:
	void doubleClicked(int, bool);

private:
	Ui::SearchTabClass ui;
};

#endif // SEARCHTAB_H
