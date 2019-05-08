#include "player.h"
#include "playerfactory.h"

playerFactory::playerFactory(){}

Player *playerFactory::createFixedItem(QSize size,
                               Coordinate where,
                               QPixmap image)
{
        return new Player(size,where,image);
}
