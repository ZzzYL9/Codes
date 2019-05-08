#ifndef PIEVIEW_H
#define PIEVIEW_H

#include <QAbstractItemView>

class PieView : public QAbstractItemView
{
    Q_OBJECT

public:
    PieView(QWidget *parent = 0);

    virtual QRect       visualRect(const QModelIndex &) const;
    virtual void        scrollTo  (const QModelIndex &, ScrollHint hint = EnsureVisible);
    virtual QModelIndex indexAt   (const QPoint &) const;
	virtual void        setModel  (QAbstractItemModel* model);

public slots:
    void dataChanged(const QModelIndex &, const QModelIndex &);

protected:
    virtual int     horizontalOffset() const;
    virtual int     verticalOffset() const;
    virtual bool    isIndexHidden(const QModelIndex &) const;
    virtual void    setSelection(const QRect&, QItemSelectionModel::SelectionFlags);
	virtual QRegion visualRegionForSelection(const QItemSelection &) const;
	virtual QModelIndex moveCursor(QAbstractItemView::CursorAction, Qt::KeyboardModifiers);

    void paintEvent (QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);

private:
	double  getValue(int row) const;
	double  getTotalAmount() const;
	int     getValidItems();
	QString getText      (int row);
	double  getDeltaAngle(int row);
	QColor  getColor     (int row);
	void    drawText(QPainter&, double start, double delta, const QString&);
	void    drawPie (QPainter&, double start, double delta, const QColor&);
	void    drawPies (QPainter& painter);
	void    drawTexts(QPainter& painter);

private:
	enum {NAME, AMOUNT, PERCENTAGE};

    const static int margin = 20;
    int    pieSize;
    int    validItems;
};

#endif
