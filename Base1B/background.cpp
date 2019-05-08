#include "background.h"
#include <iostream>
using namespace std;

Background::Background():
    m_coordinate(Coordinate(0,0,1000,600)){}
Background::Background(Coordinate coordinate, int velocity,QPixmap image):
    m_coordinate(coordinate),m_velocity(velocity),m_pixmap(image){}
Background::~Background(){}


bool Background::isCollision()
{
    //check if the image is end or not
    return (-m_coordinate.getQtRenderingXCoordinate()+m_pixmap.width()
            <= (signed int) m_coordinate.getFrameWidth());
}

void Background::render(QPainter &painter, int& m_count)
{
    if (isCollision())
    {
        // go back to the head of image if it is end
        m_coordinate.setXCoordinateToZero();

    }

    painter.drawPixmap(-m_coordinate.getQtRenderingXCoordinate(),0,m_pixmap);
    //change the x cooridate
    m_coordinate.changeInXCoordinate(m_velocity);
    painter.drawPixmap(-m_coordinate.getQtRenderingXCoordinate(),0,m_pixmap);
    //determine how many times changes and helpt to do stickman animation
    m_count += 1;
}
