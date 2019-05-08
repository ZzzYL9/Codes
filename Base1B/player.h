#ifndef PLAYER_H
#define PLAYER_H
#include "fixeditem.h"

//using factory design pattern
//player is the concrete product

class Player:public FixedItem
{
public:
    Player(QSize size,
           Coordinate coordinate,
           QPixmap image);
    Coordinate getCoordinate() override;
    QPixmap getPixmap() override;
    QPixmap getRpixmap() override;
    void setPixmap();

private:
    QSize m_size;
    Coordinate m_coordinate;
    QPixmap m_pixmap;
    QPixmap r_pixmap;
};

#endif // PLAYER_H

