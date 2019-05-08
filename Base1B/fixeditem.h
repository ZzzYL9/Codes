#ifndef FIXEDITEM_H
#define FIXEDITEM_H
#include <coordinate.h>
#include <QPixmap>
#include <QPainter>
#include <QLabel>


//using factory designed pattern
//FixedFactory is the factory interface
//FixedItem is the product interface

class FixedItem
{
public:
    virtual ~FixedItem() {}
    virtual Coordinate getCoordinate() = 0;
    virtual QPixmap getPixmap()=0;
    virtual QPixmap getRpixmap()=0;
};

#endif // FIXEDITEM_H
