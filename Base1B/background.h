#ifndef BACKGROUND_H
#define BACKGROUND_H

#include"coordinate.h"
#include <QPainter>
#include <QPixmap>

//header file of background
class Background
{
public:
    Background();
    Background(Coordinate coordinate,int velocity,QPixmap image);
    ~Background();

    void render(QPainter &painter, int &m_count);
    void setPixmap(QPixmap map);
    bool isCollision();

private:
    //current image coordinator
    Coordinate m_coordinate;
    //velocity read from file
    int m_velocity;
    //image stored as pixmap
    QPixmap m_pixmap;
};

#endif // BACKGROUND_Hs
