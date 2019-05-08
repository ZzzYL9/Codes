#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "fixedfactory.h"

//using factory design pattern
//playerFactory is the concrete factory

class playerFactory :public FixedFactory
{

public:
    playerFactory();
    Player *createFixedItem(QSize size,
                               Coordinate where,
                               QPixmap image);
};

#endif // PLAYERFACTORY_H

