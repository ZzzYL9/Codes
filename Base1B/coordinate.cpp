#include "coordinate.h"

//Coordinate class
//to help determining the position of objects
Coordinate::Coordinate(unsigned int xCoordinate,
                       unsigned int yCoordinate,
                       unsigned int frameWidth,
                       unsigned int frameHeight):
    m_xCoordinate(xCoordinate),m_yCoordinate(yCoordinate),m_frameWidth(frameWidth),m_frameHeight(frameHeight){}

int Coordinate::getQtRenderingXCoordinate()
{
    return int (m_xCoordinate);
}

int Coordinate::getQtRenderingYCoordinate()
{
    return int (m_frameHeight - m_yCoordinate);
}

unsigned int Coordinate::getFrameHeight()
{
    return m_frameHeight;
}

unsigned int Coordinate::getFrameWidth()
{
    return m_frameWidth;
}

void Coordinate::changeInXCoordinate(int change)
{
    m_xCoordinate += change;
}

void Coordinate::changeInYCoordinate(int change)
{
    m_yCoordinate += change;
}

void Coordinate::setXCoordinateToZero()
{
    m_xCoordinate = 0;
}
