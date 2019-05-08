#include "player.h"
#include <QMatrix>


Player::Player(QSize size, Coordinate where, QPixmap image):
    m_size(size),m_coordinate(where),m_pixmap(image){
    setPixmap();
}

Coordinate Player::getCoordinate()
{
    return m_coordinate;
}

QPixmap Player::getPixmap()
{
    return m_pixmap;
}

QPixmap Player::getRpixmap()
{
    return r_pixmap;
}

void Player::setPixmap()
{
    m_pixmap = m_pixmap.scaled(m_size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QMatrix matrix1;
    matrix1.rotate(-10);
    m_pixmap = m_pixmap.transformed(matrix1);

    QMatrix matrix;
    matrix.rotate(10);
    r_pixmap = m_pixmap.transformed(matrix);
}




