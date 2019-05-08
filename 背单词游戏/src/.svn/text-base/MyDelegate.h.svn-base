#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QItemDelegate>
#include <QPixmap>

class QPainter;
class QModelIndex;

class MyDelegate : public QItemDelegate
{
	Q_OBJECT

public:
	MyDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

private:
    QPixmap star;
};

#endif // MYDELEGATE_H
