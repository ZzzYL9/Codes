#include "chessboard.h"
#include "commdef.h"
#include <QPainter>
#include <QDebug>

ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent)
{
    resize(CHESSBOARD_WIDTH, CHESSBOARD_HEIGHT);
    move(CHESSBOARD_STARTX, CHESSBOARD_STARTY);
    fliped = false;
    loadPixmap(STARTUP_LAYOUT);
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    int xx = 0;
    int yy = 0;
    int index = 0;

    QPainter painter(this);
    painter.drawPixmap(0, 0, background);

    for (int row = 0; row < CHESSBOARD_ROW; ++row)
    {
        for (int column = 0; column < CHESSBOARD_COLUMN; ++column)
        {
            index = row * CHESSBOARD_COLUMN + column;
            getPixmapPos(row, column, xx, yy);
            painter.drawPixmap(xx, yy ,arrChessman[index]);
        }
    }
}

void ChessBoard::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        int row = 0;
        int column = 0;
        getPixmapIndex(event->pos().x(), event->pos().y(), row, column);

        int sq = getChessmanIndex(row, column, fliped);
        emit doMove(sq);
    }
}

void ChessBoard::loadPixmap(const char *chessman)
{
    int sq = 0;
    char pc = 0;
    int index = 0;

    background.load(":/images/WOOD.GIF");
    for(int row = 0; row < CHESSBOARD_ROW; ++row)
    {
        for (int column = 0; column < CHESSBOARD_COLUMN; ++column)
        {
            index = row * CHESSBOARD_COLUMN + column;
            sq = getChessmanIndex(row, column, fliped);
            pc = chessman[sq];
            arrChessman[index].load(getChessmanPic(pc, false, false));

        }
    }

}

void ChessBoard::showMoveRoute(char movingChessman, int move, bool show)
{
    int srcPos = SRC(move);
    int dstPos = DST(move);
    int srcIndex = 0;
    int dstIndex = 0;

    if (srcPos > 0)
    {
        srcIndex = getChessboardCoord(FILE_X(srcPos), RANK_Y(srcPos), fliped);
        arrChessman[srcIndex].load(getChessmanPic(dstPos > 0 ? 0 : movingChessman, show, false));
    }

    if (dstPos > 0)
    {
        dstIndex = getChessboardCoord(FILE_X(dstPos), RANK_Y(dstPos), fliped);
        arrChessman[dstIndex].load(getChessmanPic(movingChessman, show, false));
    }
}

void ChessBoard::updateGeneralDisplay(char chessman, int pos, bool dead)
{
    int index = getChessboardCoord(FILE_X(pos), RANK_Y(pos), fliped);
    arrChessman[index].load(getChessmanPic(chessman, true, dead));
}

void ChessBoard::changeFlip()
{
    fliped = !fliped;
}
