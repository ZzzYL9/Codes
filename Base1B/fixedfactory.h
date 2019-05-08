#ifndef FIXEDFACTORY_H
#define FIXEDFACTORY_H

#include "coordinate.h"
#include "fixeditem.h"
#include <QSize>
#include <QPixmap>

//using factory designed pattern
//FixedFactory is the factory interface
//FixedItem is the product interface

class FixedFactory
{
public:
    virtual ~FixedFactory() {}
    virtual FixedItem *createFixedItem(QSize size,
                                       Coordinate where,
                                       QPixmap image) = 0;
};
#endif // FIXEDFACTORY_H
