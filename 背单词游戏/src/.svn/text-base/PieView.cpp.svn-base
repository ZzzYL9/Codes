#define _USE_MATH_DEFINES
#include <cmath>
#include <QScrollBar>
#include <QFontMetrics>
#include <QPainter>
#include <QPaintEvent>
#include "PieView.h"

PieView::PieView(QWidget *parent) : QAbstractItemView(parent) {}

double PieView::getValue(int row) const {
	return model()->data(model()->index(row, AMOUNT)).toDouble();
}

int PieView::getValidItems()
{
	int result = 0;
	for(int row = 0; row < model()->rowCount(); ++row)
		if(getValue(row) > 0.0)
			result++;
	return result;
}

double PieView::getTotalAmount() const
{
	double result= 0.0;
	for(int row=0; row<model()->rowCount(); ++row)
		result += getValue(row);
	return result;
}

void PieView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
	validItems = getValidItems();
	QAbstractItemView::dataChanged(topLeft, bottomRight);
}

QString PieView::getText(int row)
{
	return tr("%1 %2(%3)").arg(model()->data(model()->index(row, NAME)).toString())
						  .arg(getValue(row))
						  .arg(model()->data(model()->index(row, PERCENTAGE)).toString());
}

double PieView::getDeltaAngle(int row) {
	return 360 * getValue(row) / getTotalAmount();
}

QColor PieView::getColor(int row) {
	return QColor(
		model()->data(model()->index(row, NAME), Qt::DecorationRole).toString());
}

void PieView::drawText(QPainter& painter, double startAngle, 
					   double deltaAngle, const QString& text)
{
	if(deltaAngle > 0)
	{
		int width = QFontMetrics(painter.font()).width(text);
		int r = pieSize / 3;
		int x = r*cos((startAngle+deltaAngle/2)*M_PI/180);
		int y = r*sin((startAngle+deltaAngle/2)*M_PI/180);
		painter.drawText(pieSize/2 + x - width/2, pieSize/2 - y, text);
	}
}

void PieView::drawPie(QPainter& painter, double startAngle, 
					  double deltaAngle, const QColor& color)
{
	if(deltaAngle > 0)
	{
		painter.setBrush(color);
		painter.drawPie(0, 0, pieSize, pieSize, startAngle*16, deltaAngle*16);
	}
}

void PieView::drawPies(QPainter& painter)
{
	double startAngle = 0.0;
	for(int row = 0; row < model()->rowCount(); ++row)
	{
		drawPie(painter, startAngle, getDeltaAngle(row), getColor(row));
		startAngle += getDeltaAngle(row);
	}
}

void PieView::drawTexts(QPainter& painter)
{
	double startAngle = 0.0;
	for(int row = 0; row < model()->rowCount(); ++row)
	{
		drawText(painter, startAngle, getDeltaAngle(row), getText(row));
		startAngle += getDeltaAngle(row);
	}
}

void PieView::paintEvent(QPaintEvent *event)
{
	QPainter painter(viewport());
	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillRect(event->rect(), viewOptions().palette.base());
	painter.setPen(viewOptions().palette.color(QPalette::Foreground));

	if (validItems > 0)
	{
		if(viewport()->width() > viewport()->height())
			painter.translate((viewport()->width() - pieSize)/2, margin);
		else
			painter.translate(margin, (viewport()->height() - pieSize)/2);
		painter.drawEllipse(0, 0, pieSize, pieSize);
		drawPies (painter);
		drawTexts(painter);
	}
}

void PieView::resizeEvent(QResizeEvent*)
{
	int totalSize = qMin(viewport()->width(), viewport()->height());
	pieSize = totalSize - 2*margin;
}


// inherited
QModelIndex PieView::indexAt(const QPoint&) const {
    return QModelIndex();
}

bool PieView::isIndexHidden(const QModelIndex&) const {
    return false;
}

int PieView::horizontalOffset() const {
    return horizontalScrollBar()->value();
}

QModelIndex PieView::moveCursor(QAbstractItemView::CursorAction, Qt::KeyboardModifiers)
{
    viewport()->update();
    return currentIndex();
}

void PieView::scrollTo(const QModelIndex&, ScrollHint) {
    update();
}

void PieView::setSelection(const QRect&, QItemSelectionModel::SelectionFlags) {
    update();
}

int PieView::verticalOffset() const {
    return verticalScrollBar()->value();
}

QRegion PieView::visualRegionForSelection(const QItemSelection&) const {
	return QRegion();
}

QRect PieView::visualRect(const QModelIndex&) const {
	return QRect(0, 0, pieSize, pieSize);
}

void PieView::setModel(QAbstractItemModel *m) {
	if (model()) {
		disconnect(model(), SIGNAL(rowsRemoved(const QModelIndex&,int,int)), viewport(), SLOT(update()));
		disconnect(model(), SIGNAL(rowsInserted(const QModelIndex&,int,int)), viewport(), SLOT(update()));
		disconnect(model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex &)), viewport(), SLOT(update()));
	}
	QAbstractItemView::setModel(m);
	if (model()) {
		connect(model(), SIGNAL(rowsRemoved(const QModelIndex&,int,int)), viewport(), SLOT(update()));
		connect(model(), SIGNAL(rowsInserted(const QModelIndex&,int,int)), viewport(), SLOT(update()));
		connect(model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), viewport(), SLOT(update()));
	}
	dataChanged(QModelIndex(), QModelIndex()); // generate the pie for the first time
}