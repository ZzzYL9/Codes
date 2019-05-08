#include "DetailWidget.h"
#include "DictionaryModel.h"
#include <QModelIndex>

DetailWidget::DetailWidget(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.lineEditChinese, SIGNAL(textEdited(const QString&)), this, SLOT(slotSave()));
	connect(ui.textEditNote,    SIGNAL(textChanged()),              this, SLOT(slotSave()));
}

void DetailWidget::slotSetCurrentRow(const QModelIndex& current) {
	currentRow = current.row();
}

void DetailWidget::showRow(bool show)
{
	showEnglish();
	showChinese(show);
	showNote   (show);
}

void DetailWidget::slotSave()
{
	model->setData(model->index(currentRow, DictionaryModel::CHINESE), ui.lineEditChinese->text());
	model->setData(model->index(currentRow, DictionaryModel::NOTE),    ui.textEditNote->toPlainText());
}

void DetailWidget::showEnglish()
{
	ui.wordDisplayer->setEnglishColor(model->getEnglishColor(currentRow));
	ui.wordDisplayer->setHtml("<center>" + model->getEnglish (currentRow, false) + " " 
										 + model->getPhonetic(currentRow) + "</center>");
}

void DetailWidget::showChinese(bool show)
{
	show ? ui.lineEditChinese->setText(model->getChinese(currentRow))
		 : ui.lineEditChinese->setText("");
	ui.lineEditChinese->setReadOnly(!show);
}

void DetailWidget::showNote(bool show)
{
	disconnect(ui.textEditNote, SIGNAL(textChanged()), this, SLOT(slotSave()));
	show ? ui.textEditNote->setPlainText(model->getNote(currentRow))
		 : ui.textEditNote->clear();
	connect(ui.textEditNote, SIGNAL(textChanged()), this, SLOT(slotSave()));
	ui.textEditNote->setReadOnly(!show);
}

void DetailWidget::setEnglishFont(const QFont& font) {
	ui.wordDisplayer->setEnglishFont(font);
}
void DetailWidget::setPhoneticFont(const QFont& font) {
	ui.wordDisplayer->setPhoneticFont(font);
}
void DetailWidget::setChineseFont(const QFont& font) {
	ui.lineEditChinese->setFont(font);
}
void DetailWidget::setNoteFont(const QFont& font) {
	ui.textEditNote->setFont(font);
}
void DetailWidget::setPhoneticColor(const QColor& color) {
	ui.wordDisplayer->setPhoneticColor(color);
}

QList<int> DetailWidget::getSplitterSizes() const {
	return ui.splitter->sizes();
}
void DetailWidget::setSplitterSizes(const QList<int> sizes) {
	ui.splitter->setSizes(sizes);
}