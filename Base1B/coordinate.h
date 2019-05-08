#ifndef COORDINATE_H
#define COORDINATE_H

//coordinate header
class Coordinate
{
public:
    Coordinate(unsigned int xCoordinate,
        unsigned int yCoordinate,
        unsigned int frameWidth,
        unsigned int frameHeight);

    int getQtRenderingXCoordinate();
    int getQtRenderingYCoordinate();

    void changeInXCoordinate(int change);
    void changeInYCoordinate(int change);

    void setXCoordinateToZero();

    unsigned int getFrameHeight();
    unsigned int getFrameWidth();

private:
    int m_xCoordinate;
    int m_yCoordinate;
    int m_frameWidth;
    int m_frameHeight;
};

#endif // COORDINATE_H
