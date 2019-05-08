#include "SearchTab.h"
#include "WordList.h"

SearchTab::SearchTab(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.searchWidget, SIGNAL(doubleClicked(int)), 
			this,            SLOT(slotDoubleClicked(int)));
	connect(ui.lineEditSearch, SIGNAL(textChanged(const QString&)), 
			this,              SLOT(slotSearch(const QString&)));
	connect(ui.radioBegin, SIGNAL(clicked()), this, SLOT(slotReSearch()));
	connect(ui.radioEnd,   SIGNAL(clicked()), this, SLOT(slotReSearch()));
	connect(ui.radioAny,   SIGNAL(clicked()), this, SLOT(slotReSearch()));
}

void SearchTab::slotSearch(const QString& target) 
{
	enableOption(!ChineseList::isChinese(target));
	ui.searchWidget->search(target, getOption());
}

void SearchTab::slotReSearch() 
{
	focusInput();
	slotSearch(ui.lineEditSearch->text());
}

void SearchTab::enableOption(bool enable)
{
	ui.radioBegin->setEnabled(enable);
	ui.radioEnd  ->setEnabled(enable);
	ui.radioAny  ->setEnabled(enable);
}

SearchWidget::SearchOption SearchTab::getOption() const
{
	if(ui.radioBegin->isChecked())
		return SearchWidget::BEGIN;
	if(ui.radioEnd->isChecked())
		return SearchWidget::END;
	return SearchWidget::ANY;
}

void SearchTab::slotDoubleClicked(int id) {
	emit doubleClicked(id, true);
}

void SearchTab::setDictName(const QString& dict) {
	ui.searchWidget->setDictName(dict);
}

void SearchTab::enterEvent(QEvent*) {
	focusInput();
}

void SearchTab::focusInput()
{
	ui.lineEditSearch->setFocus();
	ui.lineEditSearch->selectAll();
}