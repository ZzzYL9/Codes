#include "movegenerator.h"
#include "commdef.h"
#include <math.h>
#include <QDebug>

MoveGenerator::MoveGenerator()
{

}

MoveGenerator::~MoveGenerator()
{

}

bool MoveGenerator::validateMove(const char *arrChessman, int srcPos, int dstPos)
{
    if (srcPos == dstPos)
    {
        return false;
    }

    int movingChessman = arrChessman[srcPos];
    int killedChessman = arrChessman[dstPos];

    if (isSameSide(movingChessman, killedChessman))
    {
        return false;
    }

    bool legal = false;

    switch (movingChessman)
    {
    case BLACK_GENERAL:
    case RED_GENERAL:
        legal = validateGeneralMove(arrChessman, srcPos, dstPos);
        break;
    case BLACK_ADVISOR:
    case RED_ADVISOR:
        legal = validateAdvisorMove(arrChessman, srcPos, dstPos);
        break;
    case BLACK_MINISTER:
    case RED_MINISTER:
        legal = validateMinisterMove(arrChessman, srcPos, dstPos);
        break;
    case BLACK_HORSE:
    case RED_HORSE:
        legal = validateHorseMove(arrChessman, srcPos, dstPos);
        break;
    case BLACK_CHARIOT:
    case RED_CHARIOT:
        legal = validateChariotMove(arrChessman, srcPos, dstPos);
        break;
    case BLACK_CANNON:
    case RED_CANNON:
        legal = validateCannonMove(arrChessman, srcPos, dstPos);
        break;
    case BLACK_SOLDIER:
    case RED_SOLDIER:
        legal = validateSoldierMove(arrChessman, srcPos, dstPos);
        break;
    default:
        break;
    }

    return legal;
}

bool MoveGenerator::validateGeneralMove(const char *arrChessman, int srcPos, int dstPos)
{
    Q_UNUSED(arrChessman);
    return IN_FORT(dstPos) && KING_SPAN(srcPos, dstPos);
}

bool MoveGenerator::validateAdvisorMove(const char *arrChessman, int srcPos, int dstPos)
{
    Q_UNUSED(arrChessman);
    return IN_FORT(dstPos) && ADVISOR_SPAN(srcPos, dstPos);
}

bool MoveGenerator::validateMinisterMove(const char *arrChessman, int srcPos, int dstPos)
{
    return SAME_HALF(srcPos, dstPos) && BISHOP_SPAN(srcPos, dstPos) &&
            arrChessman[BISHOP_PIN(srcPos, dstPos)] == 0;
}

bool MoveGenerator::validateHorseMove(const char *arrChessman, int srcPos, int dstPos)
{
    int sqPin = KNIGHT_PIN(srcPos, dstPos);
    return sqPin != srcPos && arrChessman[sqPin] == 0;
}

bool MoveGenerator::validateChariotMove(const char *arrChessman, int srcPos, int dstPos)
{
    int delta = 0;
    if (SAME_RANK(srcPos, dstPos))
    {
        delta = (dstPos < srcPos ? -1 : 1);
    }
    else if(SAME_FILE(srcPos, dstPos))
    {
        delta = (dstPos < srcPos ? -16 : 16);
    }
    else
    {
        return false;
    }

    int sqPin = srcPos + delta;
    while (sqPin != dstPos && arrChessman[sqPin] == 0)
    {
        sqPin += delta;
    }

    return sqPin == dstPos;
}

bool MoveGenerator::validateCannonMove(const char *arrChessman, int srcPos, int dstPos)
{
    int delta = 0;

    if (SAME_RANK(srcPos, dstPos))
    {
        delta = (dstPos < srcPos ? -1 : 1);
    }
    else if(SAME_FILE(srcPos, dstPos))
    {
        delta = (dstPos < srcPos ? -16 : 16);
    }
    else
    {
        return false;
    }

    int sqPin = srcPos + delta;
    while (sqPin != dstPos && arrChessman[sqPin] == 0)
    {
        sqPin += delta;
    }

    if (sqPin == dstPos)
    {
        return arrChessman[dstPos] == 0;
    }

    sqPin += delta;
    while (sqPin != dstPos && arrChessman[sqPin] == 0)
    {
        sqPin += delta;
    }

    return sqPin == dstPos && arrChessman[dstPos] != 0;
}

bool MoveGenerator::validateSoldierMove(const char *arrChessman, int srcPos, int dstPos)
{
    int side = isBlackSide(arrChessman[srcPos]) ? 1 : 0;
    if (AWAY_HALF(dstPos, side) && (dstPos == srcPos - 1 || dstPos == srcPos + 1))
    {
        return true;
    }
    return dstPos == SQUARE_FORWARD(srcPos, side);
}

void MoveGenerator::addMoveRoute(char *arrChessman, int srcPos, int dstPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int killedChessman = arrChessman[dstPos];

    //再判断走棋后，自己是否被对方将军，如果自己被对方将军，则走法不合理
    arrChessman[srcPos] = 0;
    arrChessman[dstPos] = info.movingChessman;

    if (!isAttackGeneral(arrChessman, isBlackSide(info.movingChessman) ? BLACK_GENERAL : RED_GENERAL))
    {
        info.move = MOVE(srcPos, dstPos);
        info.killedChessman = killedChessman;
        lstInfo.push_back(info);
    }

    arrChessman[srcPos] = info.movingChessman;
    arrChessman[dstPos] = killedChessman;
}

void MoveGenerator::generateAllMove(char *arrChessman, int side, QList<MoveInfo> &lstInfo)
{
    MoveInfo info;
    for (int i = FILE_LEFT; i <= FILE_RIGHT; ++i)
    {
        for (int j = RANK_TOP; j <= RANK_BOTTOM; ++j)
        {
            int index = COORD_XY(i, j);
            if ((side == BLACK && isBlackSide(arrChessman[index])) ||
                 (side == RED && isRedSide(arrChessman[index])))
            {
                info.move = index;
                info.movingChessman = arrChessman[index];

                switch (arrChessman[index])
                {
                case BLACK_GENERAL:
                case RED_GENERAL:
                    generateGeneralMove(arrChessman, index, info, lstInfo);
                    break;
                case BLACK_CHARIOT:
                case RED_CHARIOT:
                    generateChariotMove(arrChessman, index, info, lstInfo);
                    break;
                case BLACK_CANNON:
                case RED_CANNON:
                    generateCannonMove(arrChessman, index, info, lstInfo);
                    break;
                case BLACK_HORSE:
                case RED_HORSE:
                    generateHorseMove(arrChessman, index, info, lstInfo);
                    break;
                case BLACK_ADVISOR:
                case RED_ADVISOR:
                    generateAdvisorMove(arrChessman, index, info, lstInfo);
                    break;
                case BLACK_MINISTER:
                case RED_MINISTER:
                    generateMinisterMove(arrChessman, index, info, lstInfo);
                    break;
                case BLACK_SOLDIER:
                case RED_SOLDIER:
                    generateSoldierMove(arrChessman, index, info, lstInfo);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void MoveGenerator::generateGeneralMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int dstPos;
    for (int i = 0; i < 4; ++i)
    {
        dstPos = srcPos + KING_DELTA[i];
        if (validateGeneralMove(arrChessman, srcPos, dstPos))
        {
            addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
        }
    }
}

void MoveGenerator::generateAdvisorMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int dstPos;
    for (int i = 0; i < 4; ++i)
    {
        dstPos = srcPos + ADVISOR_DELTA[i];
        if (validateAdvisorMove(arrChessman, srcPos, dstPos))
        {
            addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
        }
    }
}

void MoveGenerator::generateMinisterMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int dstPos;
    for (int i = 0; i < 4; ++i)
    {
        dstPos = srcPos + 2 * ADVISOR_DELTA[i];
        if (validateMinisterMove(arrChessman, srcPos, dstPos))
        {
            addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
        }
    }
}

void MoveGenerator::generateHorseMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int dstPos;
    for (int i = 0; i < 4; ++i)
    {
        dstPos = srcPos + KING_DELTA[i];
        if (arrChessman[dstPos] != 0)
        {
            continue;
        }

        for (int j = 0; j < 2; ++j)
        {
            dstPos = srcPos + KNIGHT_CHECK_DELTA[i][j];
            if (validateHorseMove(arrChessman, srcPos, dstPos))
            {
                addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
            }
        }
    }
}

void MoveGenerator::generateChariotMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int dstPos;
    int column = FILE_X(srcPos);
    int row = RANK_Y(srcPos);

    for (int i = RANK_TOP; i <= RANK_BOTTOM; ++i)
    {
        if (i != row)
        {
            dstPos = COORD_XY(column, i);
            if (validateChariotMove(arrChessman, srcPos, dstPos))
            {
                addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
            }
        }
    }

    for (int i = FILE_LEFT; i <= FILE_RIGHT; ++i)
    {
        if (i != column)
        {
            dstPos = COORD_XY(i, row);
            if (validateChariotMove(arrChessman, srcPos, dstPos))
            {
                addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
            }
        }
    }
}

void MoveGenerator::generateCannonMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int dstPos;
    int column = FILE_X(srcPos);
    int row = RANK_Y(srcPos);

    for (int i = RANK_TOP; i <= RANK_BOTTOM; ++i)
    {
        if (i != row)
        {
            dstPos = COORD_XY(column, i);
            if (validateCannonMove(arrChessman, srcPos, dstPos))
            {
                addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
            }
        }
    }

    for (int i = FILE_LEFT; i <= FILE_RIGHT; ++i)
    {
        if (i != column)
        {
            dstPos = COORD_XY(i, row);
            if (validateCannonMove(arrChessman, srcPos, dstPos))
            {
                addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
            }
        }
    }
}

void MoveGenerator::generateSoldierMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo)
{
    int dstPos = 0;
    for (int i = 0; i < 4; ++i)
    {
        dstPos = srcPos + KING_DELTA[i];
        if (validateSoldierMove(arrChessman, srcPos, dstPos))
        {
            addMoveRoute(arrChessman, srcPos, dstPos, info, lstInfo);
        }
    }
}

void MoveGenerator::getMoveStepAlpha(const char *arrChessman, int mv, QString &stepAlpha)
{
    int fromPos = SRC(mv);
    char movingChessman = arrChessman[fromPos];
    stepAlpha.append(CHESSMAN_CODE[movingChessman - 1]);

    int fromX = FILE_X(fromPos);
    int fromY = RANK_Y(fromPos);

    int dstPos = DST(mv);
    int toX = FILE_X(dstPos);
    int toY = RANK_Y(dstPos);

    switch (movingChessman)
    {
    case BLACK_GENERAL:
    case RED_GENERAL:
        getGeneralMoveStepAlpha(arrChessman, movingChessman, fromX, fromY, toX, toY, stepAlpha);
        break;
    case BLACK_ADVISOR:
    case BLACK_MINISTER:
    case RED_ADVISOR:
    case RED_MINISTER:
        getAdvisorMinisterMoveStepAlpha(arrChessman, movingChessman, fromX, fromY, toX, toY, stepAlpha);
        break;
    case BLACK_CHARIOT:
    case BLACK_CANNON:
    case RED_CHARIOT:
    case RED_CANNON:
        getChariotCannonMoveStepAlpha(arrChessman, movingChessman, fromX, fromY, toX, toY, stepAlpha);
        break;
    case BLACK_HORSE:
    case RED_HORSE:
        getHorseMoveStepAlpha(arrChessman, movingChessman, fromX, fromY, toX, toY, stepAlpha);
        break;
    case BLACK_SOLDIER:
    case RED_SOLDIER:
        getSoldierMoveStepAlpha(arrChessman, movingChessman, fromX, fromY, toX, toY, stepAlpha);
        break;
    default:
        break;
    }
}

void MoveGenerator::getGeneralMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha)
{
    Q_UNUSED(arrChessman);
    bool black = isBlackSide(movingChessman);
    int edge = black ? FILE_LEFT : FILE_RIGHT;
    stepAlpha += (abs(edge - fromX) + 1 + '0');
    if (fromY == toY)
    {
        stepAlpha += '.';
        stepAlpha += (abs(edge - toX) + 1 + '0');
    }
    else
    {
        stepAlpha += toY > fromY ? (black ? '+' : '-') : (black ? '-' : '+');
        stepAlpha += (abs(fromY - toY) + '0');
    }
}

void MoveGenerator::getAdvisorMinisterMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha)
{
    Q_UNUSED(arrChessman);
    bool black = isBlackSide(movingChessman);
    int edge = black ? FILE_LEFT : FILE_RIGHT;
    stepAlpha += (abs(edge - fromX) + 1 + '0');
    stepAlpha += toY > fromY ? (black ? '+' : '-') : (black ? '-' : '+');
    stepAlpha += (abs(edge - toX) + 1 + '0');
}

void MoveGenerator::getChariotCannonMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha)
{
    //获取车/炮的位置，如果有两个车/炮在同一列上要分前后
    bool black = isBlackSide(movingChessman);
    int edge = black ? FILE_LEFT : FILE_RIGHT;

    int pos[5];
    int chessmanCount = getChessmanPos(arrChessman, movingChessman, pos);
    //如果两个车/炮在同一列上
    if (chessmanCount == 2 && FILE_X(pos[0]) == FILE_X(pos[1]))
    {
        if (RANK_Y(pos[0]) > RANK_Y(pos[1]))
        {
            if (fromY == RANK_Y(pos[0]))
            {
                stepAlpha +=  black ? 'a' : 'b';
            }
            else
            {
                stepAlpha +=  black ? 'b' : 'a';
            }
        }
        else
        {
            if (fromY == RANK_Y(pos[0]))
            {
                stepAlpha +=  black ? 'b' : 'a';
            }
            else
            {
                stepAlpha +=  black ? 'a' : 'b';
            }
        }
    }
    else
    {
        stepAlpha += (abs(edge - fromX) + 1 + '0');
    }

    if (fromY == toY)
    {
        stepAlpha += '.';
        stepAlpha += (abs(edge - toX) + 1 + '0');
    }
    else
    {
        stepAlpha += toY > fromY ? (black ? '+' : '-') : (black ? '-' : '+');
        stepAlpha += (abs(fromY - toY) + '0');
    }
}

void MoveGenerator::getHorseMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha)
{
    bool black = isBlackSide(movingChessman);
    int edge = black ? FILE_LEFT : FILE_RIGHT;

    int pos[5];
    int chessmanCount = getChessmanPos(arrChessman, movingChessman, pos);

    //获取马的位置，如果有两个马在同一列上要分前后
    //如果两个马在同一列上
    if (chessmanCount == 2 && FILE_X(pos[0]) == FILE_X(pos[1]))
    {
        if (RANK_Y(pos[0]) > RANK_Y(pos[1]))
        {
            if (fromY == RANK_Y(pos[0]))
            {
                stepAlpha +=  black ? 'a' : 'b';
            }
            else
            {
                stepAlpha +=  black ? 'b' : 'a';
            }
        }
        else
        {
            if (fromY == RANK_Y(pos[0]))
            {
                stepAlpha +=  black ? 'b' : 'a';
            }
            else
            {
                stepAlpha +=  black ? 'a' : 'b';
            }
        }
    }
    else
    {
        stepAlpha += (abs(edge - fromX) + 1 + '0');
    }

    stepAlpha += toY > fromY ? (black ? '+' : '-') : (black ? '-' : '+');
    stepAlpha += (abs(edge - toX) + 1 + '0');
}

void MoveGenerator::getSoldierMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha)
{
    bool black = isBlackSide(movingChessman);
    int edge = black ? FILE_LEFT : FILE_RIGHT;

    //获取兵的位置
    int pos[5];
    int chessmanCount = getChessmanPos(arrChessman, movingChessman, pos);

    stepAlpha += (abs(edge - fromX) + 1 + '0');

    int mark = 0;
    int sameCoulumnPos[5];
    int soldierCountOnEachColumn[16];
    memset(sameCoulumnPos, 0, 5 * sizeof(int));
    memset(soldierCountOnEachColumn, 0, 16 * sizeof(int));
    for (int i = 0; i < chessmanCount; i++)
    {
        if (FILE_X(pos[i]) == fromX)
        {
            sameCoulumnPos[mark] = pos[i];
            mark++;
        }
        soldierCountOnEachColumn[FILE_X(pos[i])]++;
    }

    if (mark > 1)
    {
        char order = 'c'; //前
        if(black)
        {
            for (int i = mark - 1; i >= 0; i--)
            {
                if (RANK_Y(sameCoulumnPos[i]) == (fromY < toY ? toY - 1 : toY))
                {
                    stepAlpha[1] = order;
                    break;
                }
                order++;
            }
        }
        else
        {
            for (int i = 0; i < mark; i++)
            {
                if (RANK_Y(sameCoulumnPos[i]) == (fromY > toY ? toY + 1 : toY))
                {
                    stepAlpha[1] = order;
                    break;
                }
                order++;
            }
        }

        //转换成前后或前中后
        int moreSoldierColumn[2];
        int soldierPerColumn[2];
        int j = 0;
        memset(moreSoldierColumn, 0, 2 * sizeof(int));
        memset(soldierPerColumn, 0, 2 * sizeof(int));

        for (int i = 0; i < 16; ++i)
        {
            if (soldierCountOnEachColumn[i] > 1)
            {
                moreSoldierColumn[j] = i;
                soldierPerColumn[j] = soldierCountOnEachColumn[i];
                j++;
            }
        }

        bool inMoreSoldierColumn = false;
        int index = -1;
        for (int i = 0; i < 2; ++i)
        {
            if (moreSoldierColumn[i] == fromX && j > 1)
            {
                index = i;
                inMoreSoldierColumn = true;
                break;
            }
        }

        if (!inMoreSoldierColumn)
        {
            if (mark == 2)
            {
                stepAlpha[1] = stepAlpha[1] == 'c' ? 'q' : 'h';
            }
            else if (mark == 3)
            {
                stepAlpha[1] = stepAlpha[1] == 'c' ? 'q' : (stepAlpha[1] == 'd' ? 'z' : 'h');
            }
        }
        else
        {
            if (black)
            {
                if (index == 1)
                {
                    stepAlpha[1] = stepAlpha[1].toLatin1() + soldierPerColumn[0];
                }
            }
            else
            {
                if (index == 0)
                {
                    stepAlpha[1] = stepAlpha[1].toLatin1() + soldierPerColumn[1] ;
                }
            }
        }
    }

    if (fromY == toY)
    {
        stepAlpha += '.';
        stepAlpha += abs(edge - toX) + 1 + '0';
    }
    else
    {
        stepAlpha += fromY > toY ? (black ? '-' : '+') : (black ? '+' : '-');
        stepAlpha += abs(fromY - toY) + '0';
    }
}

bool MoveGenerator::isAttackGeneral(const char *arrChessman, char attackedGeneral)
{
    int pos[5];
    memset(pos, 0, sizeof(int) * 5);
    getChessmanPos(arrChessman, attackedGeneral, pos);
    bool attacked = false;

    if (attackedGeneral == BLACK_GENERAL)
    {
        attacked = attackedByGeneral(arrChessman, pos[0], RED_GENERAL) ||
                attackGeneral(arrChessman, pos[0], RED_CHARIOT) ||
                attackGeneral(arrChessman, pos[0], RED_CANNON) ||
                attackGeneral(arrChessman, pos[0], RED_HORSE) ||
                attackGeneral(arrChessman, pos[0], RED_SOLDIER);
    }
    else
    {
        attacked = attackedByGeneral(arrChessman, pos[0], BLACK_GENERAL) ||
                attackGeneral(arrChessman, pos[0], BLACK_CHARIOT) ||
                attackGeneral(arrChessman, pos[0], BLACK_CANNON) ||
                attackGeneral(arrChessman, pos[0], BLACK_HORSE) ||
                attackGeneral(arrChessman, pos[0], BLACK_SOLDIER);
    }

    return attacked;
}

bool MoveGenerator::attackGeneral(const char *arrChessman, int attackedPos, char chessman)
{
    int chessmanCount = 0;
    int pos[5];

    chessmanCount = getChessmanPos(arrChessman, chessman, pos);
    for (int i = 0; i < chessmanCount; ++i)
    {
        if (validateMove(arrChessman, pos[i], attackedPos))
        {
            return true;
        }
    }

    return false;
}

bool MoveGenerator::attackedByGeneral(const char *arrChessman, int attackedPos, char attackingGeneral)
{
    int pos[5];
    getChessmanPos(arrChessman, attackingGeneral, pos);
    if (!IN_FORT(pos[0]))
    {
        return false;
    }

    if (!SAME_FILE(attackedPos, pos[0]))
    {
        return false;
    }

    int delta = attackedPos > pos[0] ? 16 : -16;
    int sqPin = pos[0] + delta;

    while (sqPin != attackedPos && arrChessman[sqPin] == 0)
    {
        sqPin += delta;
    }

    return sqPin == attackedPos;
}

int MoveGenerator::getChessmanPos(const char *arrChessman, char chessman, int pos[])
{
    int posCount = 0;
    for (int i = FILE_LEFT; i <= FILE_RIGHT; ++i)
    {
        for (int j = RANK_TOP; j <= RANK_BOTTOM; ++j)
        {
            int sq = COORD_XY(i, j);
            if (arrChessman[sq] == chessman)
            {
                pos[posCount] = sq;
                posCount++;
            }
        }
    }

    return posCount;
}

bool MoveGenerator::isGeneralDead(char *arrChessman, int side)
{
    bool dead = true;
    char general = side == BLACK ? BLACK_GENERAL : RED_GENERAL;

    //判断能否解除将军的局面
    for (int i = RANK_TOP; i <= RANK_BOTTOM; i++)
    {
        for (int j = FILE_LEFT; j <= FILE_RIGHT; j++)
        {
            int index = COORD_XY(j, i);
            if ((side == BLACK && isBlackSide(arrChessman[index]))
                || (side == RED && isRedSide(arrChessman[index])))
            {
                if(canSaveGeneral(arrChessman, index, general))
                {
                    dead = false;
                    break;
                }
            }
        }
    }

    return dead;
}

bool MoveGenerator::canSaveGeneral(char *arrChessman, int index, char attackedGeneral)
{
    bool saved = false;
    char killedChessman = 0;
    char movingChessman = arrChessman[index];

    for (int i = RANK_TOP; i <= RANK_BOTTOM; i++)
    {
        for (int j = FILE_LEFT; j <= FILE_RIGHT; j++)
        {
            int dstPos = COORD_XY(j, i);
            if (validateMove(arrChessman, index, dstPos))
            {
                killedChessman = arrChessman[dstPos];

                //再判断走棋后，自己是否被对方将军
                arrChessman[index] = 0;
                arrChessman[dstPos] = movingChessman;

                if (!isAttackGeneral(arrChessman, attackedGeneral))
                {
                    saved = true;
                }

                arrChessman[index] = movingChessman;
                arrChessman[dstPos] = killedChessman;

                if (saved)
                {
                    break;
                }
            }
        }
    }

    return saved;
}

QString MoveGenerator::digitToChinese(const QChar &digit, bool black)
{
    QString strDigit;
    if (black)
    {
        switch(digit.toLatin1())
        {
        case '1':
            strDigit = "1";
            break;
        case '2':
            strDigit = "2";
            break;
        case '3':
            strDigit = "3";
            break;
        case '4':
            strDigit = "4";
            break;
        case '5':
            strDigit = "5";
            break;
        case '6':
            strDigit = "6";
            break;
        case '7':
            strDigit = "7";
            break;
        case '8':
            strDigit = "8";
            break;
        case '9':
            strDigit = "9";
            break;
        case 'a':
            strDigit = "前";
            break;
        case 'b':
            strDigit = "后";
            break;
        case 'c':
            strDigit = "一";
            break;
        case 'd':
            strDigit = "二";
            break;
        case 'e':
            strDigit = "三";
            break;
        case 'f':
            strDigit = "四";
            break;
        case 'g':
            strDigit = "五";
            break;
        case 'q':
            strDigit = "前";
            break;
        case 'z':
            strDigit = "中";
            break;
        case 'h':
            strDigit = "后";
            break;
        default:
            break;
        }
    }
    else
    {
        switch(digit.toLatin1())
        {
        case '1':
            strDigit = "一";
            break;
        case '2':
            strDigit = "二";
            break;
        case '3':
            strDigit = "三";
            break;
        case '4':
            strDigit = "四";
            break;
        case '5':
            strDigit = "五";
            break;
        case '6':
            strDigit = "六";
            break;
        case '7':
            strDigit = "七";
            break;
        case '8':
            strDigit = "八";
            break;
        case '9':
            strDigit = "九";
            break;
        case 'a':
            strDigit = "前";
            break;
        case 'b':
            strDigit = "后";
            break;
        case 'c':
            strDigit = "一";
            break;
        case 'd':
            strDigit = "二";
            break;
        case 'e':
            strDigit = "三";
            break;
        case 'f':
            strDigit = "四";
            break;
        case 'g':
            strDigit = "五";
            break;
        case 'q':
            strDigit = "前";
            break;
        case 'z':
            strDigit = "中";
            break;
        case 'h':
            strDigit = "后";
            break;
        default:
            break;
        }
    }

    return strDigit;
}

QString MoveGenerator::chessManCodeToChinese(const QChar &code)
{
    QString strCode;
    switch(code.toLatin1())
    {
    case 'k':
        strCode = "将";
        break;
    case 'r':
        strCode = "车";
        break;
    case 'n':
        strCode = "马";
        break;
    case 'c':
        strCode = "炮";
        break;
    case 'a':
        strCode = "士";
        break;
    case 'b':
        strCode = "象";
        break;
    case 'p':
        strCode = "卒";
        break;
    case 'K':
        strCode = "帅";
        break;
    case 'R':
        strCode = "车";
        break;
    case 'N':
        strCode = "马";
        break;
    case 'C':
        strCode = "炮";
        break;
    case 'A':
        strCode = "仕";
        break;
    case 'B':
        strCode = "相";
        break;
    case 'P':
        strCode = "兵";
        break;
    default:
        break;
    }

    return strCode;
}

QString MoveGenerator::actionToChinese(const QChar &action)
{
    QString strAction;
    switch(action.toLatin1())
    {
    case '.':
        strAction = "平";
        break;
    case '+':
        strAction = "进";
        break;
    case '-':
        strAction = "退";
        break;
    default:
        break;
    }

    return strAction;
}

void MoveGenerator::alphaFmtToChiness(const QString &alphaFmt, QString &chineseFmt, bool black)
{
    if (alphaFmt[1] >= 'a')
    {
        chineseFmt = digitToChinese(alphaFmt[1], black) +
                chessManCodeToChinese(alphaFmt[0]) +
                actionToChinese(alphaFmt[2]) +
                digitToChinese(alphaFmt[3], black);
    }
    else
    {
        chineseFmt = chessManCodeToChinese(alphaFmt[0]) +
                digitToChinese(alphaFmt[1], black) +
                actionToChinese(alphaFmt[2]) +
                digitToChinese(alphaFmt[3], black);
    }
}

QString MoveGenerator::chessmanToFEN(const char *arrChessman, int currentTurn)
{
    int k = 0;
    QString strFEN;
    for (int i = RANK_TOP; i <= RANK_BOTTOM; ++i)
    {
        k = 0;
        for (int j = FILE_LEFT; j <= FILE_RIGHT; ++j)
        {
            int coord = COORD_XY(j, i);
            char chessman = arrChessman[coord];
            if (chessman == 0)
            {
                k++;

                if (j == FILE_RIGHT)
                {
                    strFEN.append(k + '0');
                    strFEN.append('/');
                }
            }
            else
            {
                if (k > 0)
                {
                    strFEN.append(k + '0');
                    k = 0;
                }
                strFEN.append(CHESSMAN_CODE.at(chessman - 1));
                if (j == FILE_RIGHT)
                {
                    strFEN.append('/');
                }
            }
        }
    }

    strFEN.replace(strFEN.size() - 1, 1, ' ');
    strFEN.append(currentTurn == BLACK ? 'b' : 'w');
    return strFEN;
}

void MoveGenerator::FENTochessman(QString strFEN, char *arrChessman, int &currentTurn)
{
    int slashCount = 0;
    int i = 0;
    int k = 0;
    while (strFEN[i] != ' ')
    {
        int coord = COORD_XY(FILE_LEFT + k, slashCount + RANK_TOP);
        if (strFEN[i] >= 'A' && strFEN[i] <= 'z')
        {
            char type = getChessmanTypeByCode(strFEN[i]);
            arrChessman[coord] = type;
            k++;
        }
        if (strFEN[i] >= '0' && strFEN[i] <= '9')
        {
            k += (strFEN[i].toLatin1() - '0');
        }

        if (strFEN[i] == '/')
        {
            slashCount++;
            k = 0;
        }

        i++;
    }

    i++;

    currentTurn = (strFEN[i] == 'w') ? RED : BLACK;
}

