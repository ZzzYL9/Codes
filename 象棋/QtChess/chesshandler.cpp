#include "chesshandler.h"
#include "gamesettings.h"
#include "networkmsgdef.h"
#include <assert.h>
#include <QMessageBox>

ChessHandler::ChessHandler(QObject *parent) : QObject(parent)
{
    server = new ServerNetwork(this);
    client = new ClientNetwork(this);

    connect(server, SIGNAL(processMessage(char *,int)), this, SLOT(processMessage(char *,int)));
    connect(client, SIGNAL(processMessage(char *,int)), this, SLOT(processMessage(char *,int)));
    connect(server, SIGNAL(connStateChanged(bool)), this, SLOT(connStateChanged(bool)));
    connect(client, SIGNAL(connStateChanged(bool)), this, SLOT(connStateChanged(bool)));
}

ChessHandler::~ChessHandler()
{
    if (server != NULL)
    {
        delete server;
        server = NULL;
    }

    if (client != NULL)
    {
        delete client;
        client = NULL;
    }
}

void ChessHandler::startGame()
{
    if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
    {
        if (g_gameSettings.getServerOrClient() == SERVER_SIDE)
        {
            server->initServer(g_gameSettings.getPort());
        }
        else
        {
            client->initClient(g_gameSettings.getIpAddr(), g_gameSettings.getPort());
        }
    }
}

void ChessHandler::newGame()
{
    reset(g_gameSettings.getAhead());
    resetZobrist();
    currentMoveInfo.reset();
    setChessmanLayout(STARTUP_LAYOUT);
    emit refreshGame(EVENT_NEW_GAME);
}

void ChessHandler::messGame(const char *chessman, int turn)
{
    reset(turn);
    currentMoveInfo.reset();
    resetZobrist();
    setChessmanLayout(chessman);
    emit refreshGame(EVENT_NEW_GAME);
}

void ChessHandler::fallback()
{
    if (lstMoveInfo.size() > 0)
    {
        if (lstMoveInfo.size() == 1)
        {
            undoMakeMove();
        }
        else
        {
            undoMakeMove();
            undoMakeMove();
        }
        emit refreshGame(EVENT_FALLBACK);
        currentMoveInfo.reset();
    }
}

void ChessHandler::loseGame(int reqSide)
{
    if (gameResult == -1)
    {
        gameResult = reqSide == RED ? BLACK : RED ;
        emit refreshGame(EVENT_GAME_RESULT);
    }
}

void ChessHandler::drawnGame()
{
    if (gameResult == -1)
    {
        gameResult = TIE;
        emit refreshGame(EVENT_GAME_RESULT);
    }
}

void ChessHandler::reset(int turn)
{
    currentTurn = turn;
    currentSearchMoveTurn = currentTurn;
    gameResult = -1;
    whoIsDead = 0;
    lstMoveInfo.clear();
    blackValue = 0;
    redValue = 0;
    memset(arrChessman, 0, sizeof(arrChessman));
    tipReplyResult = 0;
    tipType = 0;
    tipReqSide = 0;
    exitGame = false;
}

void ChessHandler::resetZobrist()
{
    rc4.init();
    initZobrist.init(rc4);
    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            zobristTable[i][j].init(rc4);
        }
    }

    currentZobrist.reset();
}

void ChessHandler::setChessmanLayout(const char *chessman)
{
    for (int i = 0; i < 256; ++i)
    {
        if(chessman[i] != 0)
        {
            addChessman(i, chessman[i]);
        }
    }
}

void ChessHandler::addChessman(int index, char chessmanType)
{
    arrChessman[index] = chessmanType;
    currentZobrist.Xor(zobristTable[chessmanType - 1][index]);
    if (isBlackSide(chessmanType))
    {
        blackValue += CHESSMAN_VALUE[chessmanType - 1][index];
    }
    else
    {
        redValue += CHESSMAN_VALUE[chessmanType - 8][SQUARE_FLIP(index)];
    }
}

void ChessHandler::delChessman(int index, char chessmanType)
{
    arrChessman[index] = 0;
    currentZobrist.Xor(zobristTable[chessmanType - 1][index]);
    if (isBlackSide(chessmanType))
    {
        blackValue -= CHESSMAN_VALUE[chessmanType - 1][index];
    }
    else
    {
        redValue -= CHESSMAN_VALUE[chessmanType - 8][SQUARE_FLIP(index)];
    }
}

void ChessHandler::doMove(int index)
{
    assert(index >= 0x33 && index <= 0xcb);
    int fromPos = SRC(currentMoveInfo.move);
    int toPos = DST(currentMoveInfo.move);

    if (fromPos == index || toPos == index)
    {
        return;
    }

    bool legal = false;
    if (currentTurn == RED)
    {
        legal = redDoMove(index);
    }
    else
    {
        legal = blackDoMove(index);
    }

    if (legal)
    {
        if (SRC(currentMoveInfo.move) > 0 && DST(currentMoveInfo.move) > 0)
        {
            applyMove();

            if (g_gameSettings.getGameType() == COMPITITOR_MACHINE)
            {
                //电脑走棋
                computerMove();
            }
        }
        else
        {
            //发送网络消息
            if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
            {
                sendMoveInfoMsg();
            }

            emit refreshGame(EVENT_UPDATE_MOVE);
        }
    }
    else
    {
        if (currentMoveInfo.movingChessman > 0)
        {
            emit refreshGame(EVENT_ILLEGAL_MOVE);
        }
    }
}

bool ChessHandler::redDoMove(int index)
{
    int killedChessman = arrChessman[index];
    int movingChessman = currentMoveInfo.movingChessman;
    bool legal = false;
    if (movingChessman == 0)
    {
        if (isRedSide(killedChessman))
        {
            currentMoveInfo.movingChessman = killedChessman;
            currentMoveInfo.move = index;
            legal = true;
        }
    }
    else
    {
        if (isRedSide(killedChessman))
        {
            currentMoveInfo.movingChessman = killedChessman;
            currentMoveInfo.move = index;
            legal = true;
        }
        else
        {
            //判断走法是否合理
            if(moveGenerator.validateMove(arrChessman, SRC(currentMoveInfo.move), index))
            {
                //再判断走棋后，自己是否被对方将军，如果自己被对方将军，则走法不合理
                arrChessman[SRC(currentMoveInfo.move)] = 0;
                arrChessman[index] = movingChessman;
                if (moveGenerator.isAttackGeneral(arrChessman, RED_GENERAL))
                {
                    legal = false;
                }
                else
                {
                    //再判断自己是否将对方的军
                    currentMoveInfo.attackGeneral = moveGenerator.isAttackGeneral(arrChessman, BLACK_GENERAL);
                    legal = true;
                }

                arrChessman[SRC(currentMoveInfo.move)] = movingChessman;
                arrChessman[index] = killedChessman;

                if (legal)
                {
                    currentMoveInfo.killedChessman = killedChessman;
                    currentMoveInfo.move = MOVE(SRC(currentMoveInfo.move), index);
                    moveGenerator.getMoveStepAlpha(arrChessman, currentMoveInfo.move, currentMoveInfo.moveStepAlpha);
                }
            }
            else
            {
                legal = false;
            }
        }
    }

    return legal;
}

bool ChessHandler::blackDoMove(int index)
{
    int killedChessman = arrChessman[index];
    int movingChessman = currentMoveInfo.movingChessman;
    bool legal = false;
    if (movingChessman == 0)
    {
        if (isBlackSide(killedChessman))
        {
            currentMoveInfo.movingChessman = killedChessman;
            currentMoveInfo.move = index;
            legal = true;
        }
    }
    else
    {
        if (isBlackSide(killedChessman))
        {
            currentMoveInfo.movingChessman = killedChessman;
            currentMoveInfo.move = index;
            legal = true;
        }
        else
        {
            //判断走法是否合理
            if(moveGenerator.validateMove(arrChessman, SRC(currentMoveInfo.move), index))
            {
                //再判断走棋后，自己是否被对方将军，如果自己被对方将军，则走法不合理
                arrChessman[SRC(currentMoveInfo.move)] = 0;
                arrChessman[index] = movingChessman;
                if (moveGenerator.isAttackGeneral(arrChessman, BLACK_GENERAL))
                {
                    legal = false;
                }
                else
                {
                    //再判断自己是否将对方的军
                    currentMoveInfo.attackGeneral = moveGenerator.isAttackGeneral(arrChessman, RED_GENERAL);
                    legal = true;
                }

                arrChessman[SRC(currentMoveInfo.move)] = movingChessman;
                arrChessman[index] = killedChessman;

                if (legal)
                {
                    currentMoveInfo.killedChessman = killedChessman;
                    currentMoveInfo.move = MOVE(SRC(currentMoveInfo.move), index);
                    moveGenerator.getMoveStepAlpha(arrChessman, currentMoveInfo.move, currentMoveInfo.moveStepAlpha);
                }
            }
            else
            {
                legal = false;
            }
        }
    }

    return legal;
}

void ChessHandler::applyMove()
{
    doMakeMove(currentMoveInfo);

    //判断是否将对方置于死地
    if (currentMoveInfo.attackGeneral)
    {
        if (moveGenerator.isGeneralDead(arrChessman, currentTurn))
        {
            whoIsDead = currentTurn;
            gameResult = currentTurn == BLACK ? RED : BLACK;
        }
    }

    int rep = repStatus(3);
    if (rep > 0)
    {
        int repVal = repValue(rep);
        if (repVal > WIN_VALUE)
        {
            gameResult = currentTurn == BLACK ? RED : BLACK;
        }

        if (repVal < -WIN_VALUE)
        {
            gameResult = currentTurn;
        }
    }

    //发送网络消息
    if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
    {
        sendMoveInfoMsg();
    }

    emit refreshGame(EVENT_UPDATE_MOVE);
    currentMoveInfo.reset();
}

void ChessHandler::computerMove()
{
    minMaxSearch(MAX_SEARCH_DEPTH, currentMoveInfo);
    moveGenerator.getMoveStepAlpha(arrChessman, currentMoveInfo.move, currentMoveInfo.moveStepAlpha);
    applyMove();
}

void ChessHandler::doMakeMove(MoveInfo &info, bool record)
{
    int fromPos = SRC(info.move);
    int toPos = DST(info.move);
    char movingChessman = arrChessman[fromPos];
    char killedChessman = arrChessman[toPos];

    if (killedChessman > 0)
    {
        delChessman(toPos, killedChessman);
    }

    delChessman(fromPos, movingChessman);
    addChessman(toPos, movingChessman);
    info.zobristKey = currentZobrist.key;

    if (record)
    {
        lstMoveInfo.push_back(info);
        currentTurn = currentTurn == BLACK ? RED : BLACK;
    }
    currentSearchMoveTurn = currentSearchMoveTurn == BLACK ? RED : BLACK;

    currentZobrist.Xor(initZobrist);
}

void ChessHandler::undoMakeMove()
{
    MoveInfo info = lstMoveInfo.back();

    delChessman(DST(info.move), info.movingChessman);
    addChessman(SRC(info.move), info.movingChessman);
    if (info.killedChessman > 0)
    {
        addChessman(DST(info.move), info.killedChessman);
    }

    lstMoveInfo.pop_back();
    currentTurn = (currentTurn == BLACK ? RED : BLACK);
    currentSearchMoveTurn = currentTurn;
    currentZobrist.Xor(initZobrist);

    if (lstMoveInfo.size() > 0)
    {
        currentMoveInfo = lstMoveInfo.back();
    }
}

void ChessHandler::undoMakeMove(MoveInfo &info)
{
    delChessman(DST(info.move), info.movingChessman);
    addChessman(SRC(info.move), info.movingChessman);
    if (info.killedChessman > 0)
    {
        addChessman(DST(info.move), info.killedChessman);
    }

    currentSearchMoveTurn = (currentSearchMoveTurn == BLACK ? RED : BLACK);
    currentZobrist.Xor(initZobrist);
}

int ChessHandler::repStatus(int recur)
{
    bool selfSide = true;
    bool perpCheck = true;
    bool oppPerpCheck = true;

    int i = lstMoveInfo.size() - 1;

    while(i >= 0 && lstMoveInfo.at(i).killedChessman == 0)
    {
        if (selfSide)
        {
            perpCheck = perpCheck && lstMoveInfo.at(i).attackGeneral;
            if (lstMoveInfo.at(i).zobristKey == currentMoveInfo.zobristKey)
            {
                recur--;
                if (recur == 0)
                {
                    return 1 + (perpCheck ? 2 : 0) + (oppPerpCheck ? 4 : 0);
                }
            }
        }
        else
        {
            oppPerpCheck = oppPerpCheck && lstMoveInfo.at(i).attackGeneral;
        }
        selfSide = !selfSide;
        --i;
    }

    return 0;
}

int ChessHandler::repValue(int repStatus)
{

    int retVal = 0;
    retVal = ((repStatus & 2) == 0 ? 0 :  - BAN_VALUE) +
        ((repStatus & 4) == 0 ? 0 : BAN_VALUE);

    return retVal == 0 ? ((lstMoveInfo.size() & 1) == 0 ? -DRAW_VALUE : DRAW_VALUE) : retVal;
}

void ChessHandler::stepTimeOver()
{
    if (gameResult == -1)
    {
        gameResult = currentTurn == BLACK ? RED : BLACK;

        emit refreshGame(EVENT_GAME_RESULT);
    }
}

int ChessHandler::minMaxSearch(int depth, MoveInfo &info)
{
    int bestValue = isMySide() ? MATE_VALUE : -MATE_VALUE;
    int value = 0;

    if (depth == 0)
    {
        return evaluate();
    }

     QList<MoveInfo> lstInfo;
     moveGenerator.generateAllMove(arrChessman, currentSearchMoveTurn, lstInfo);
     for (QList<MoveInfo>::iterator it = lstInfo.begin(); it != lstInfo.end(); ++it)
     {
         doMakeMove(*it, false);
         value = minMaxSearch(depth - 1, info);
         undoMakeMove(*it);

         if (isMySide())
         {
             if (value < bestValue)
             {
                 bestValue = value;
                 if (depth == MAX_SEARCH_DEPTH)
                 {
                     info = *it;
                 }
             }
         }
         else
         {
             if (value > bestValue)
             {
                 bestValue = value;
                 if (depth == MAX_SEARCH_DEPTH)
                 {
                     info = *it;
                 }
             }
         }
     }

     return bestValue;
}

int ChessHandler::evaluate()
{
    return g_gameSettings.getCompetitorSide() == RED ? redValue - blackValue : blackValue - redValue;
}

bool ChessHandler::isMySide()
{
    return !(g_gameSettings.getCompetitorSide() == currentSearchMoveTurn);
}

const MoveInfo &ChessHandler::getCurrentMoveInfo()
{
    return currentMoveInfo;
}

const QList<MoveInfo> &ChessHandler::getLstMoveInfo()
{
    return lstMoveInfo;
}

int ChessHandler::getGameResult()
{
    return gameResult;
}

const char *ChessHandler::getChessman()
{
    return arrChessman;
}

char ChessHandler::getDeadOne()
{
    return whoIsDead;
}

int ChessHandler::getGeneralPos(char general)
{
    int pos = 0;
    for (int i = 0; i < 256; ++i)
    {
        if (arrChessman[i] == general)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

int ChessHandler::getCurrentTurn()
{
    return currentTurn;
}

void ChessHandler::setCurrentTurn(int turn)
{
    currentTurn = turn;
}

void ChessHandler::setChessman(const char *chessman)
{
    memcpy(arrChessman, chessman, sizeof(arrChessman));
}

int ChessHandler::getTipReplyResult()
{
    return tipReplyResult;
}

void ChessHandler::setTipReplyResult(int result)
{
    tipReplyResult = result;
}

int ChessHandler::getTipType()
{
    return tipType;
}

void ChessHandler::setTipType(int type)
{
    tipType = type;
}

void ChessHandler::processReqGameInfoMsg(char *msg, int len)
{
    Q_UNUSED(msg);
    assert(len == sizeof(MsgReqGameInfo));

    MsgGameInfo networkMsg;
    networkMsg.mySide = g_gameSettings.getCompetitorSide();
    networkMsg.stepTime = g_gameSettings.getStepTime();
    networkMsg.ahead = g_gameSettings.getAhead();
    memcpy(networkMsg.arrChessman, arrChessman, sizeof(arrChessman));
    sendMsg((char *)&networkMsg, sizeof(networkMsg));
}

void ChessHandler::processGameInfoMsg(char *msg, int len)
{
    assert(len == sizeof(MsgGameInfo));
    MsgGameInfo *netMsg = (MsgGameInfo *)msg;
    g_gameSettings.setCompetitorSide(netMsg->mySide == BLACK ? RED : BLACK);
    g_gameSettings.setAhead(netMsg->ahead);
    g_gameSettings.setStepTime(netMsg->stepTime);

    memcpy(arrChessman, netMsg->arrChessman, sizeof(arrChessman));
}

void ChessHandler::processNewGameMsg(char *msg, int len)
{
    Q_UNUSED(msg);
    assert(len == sizeof(MsgNewGame));
    newGame();
}

void ChessHandler::processChessboardSyncMsg(char *msg, int len)
{
    assert(len == sizeof(MsgChessboardSync));
    MsgChessboardSync *netMsg = (MsgChessboardSync *)msg;
    messGame(netMsg->arrChessman, netMsg->currentTurn);
}

void ChessHandler::processMoveInfoMsg(char *msg, int len)
{
    assert(len == sizeof(MsgMoveInfo));
    MsgMoveInfo *netMsg = (MsgMoveInfo *)msg;
    currentTurn = netMsg->currentTurn;
    gameResult = netMsg->gameResult;
    whoIsDead = netMsg->whoIsDead;
    currentMoveInfo.killedChessman = netMsg->killedChessman;
    currentMoveInfo.movingChessman = netMsg->movingChessman;
    currentMoveInfo.attackGeneral = netMsg->attackGeneral;
    currentMoveInfo.move = netMsg->move;
    if (strlen(netMsg->moveStepAlpha) > 0)
    {
        currentMoveInfo.moveStepAlpha = netMsg->moveStepAlpha;
    }
    currentMoveInfo.zobristKey = netMsg->zobristKey;

    memcpy(arrChessman, netMsg->arrChessman, sizeof(arrChessman));
    if (SRC(currentMoveInfo.move) > 0 && DST(currentMoveInfo.move) > 0)
    {
        lstMoveInfo.push_back(currentMoveInfo);
    }
    emit refreshGame(EVENT_UPDATE_MOVE);
    currentMoveInfo.reset();
}

void ChessHandler::processTipMsg(char *msg, int len)
{
    assert(len == sizeof(MsgTip));
    MsgTip *netMsg = (MsgTip *)msg;
    tipType = netMsg->tipType;
    tipReqSide = netMsg->reqSide;
    switch (netMsg->tipType)
    {
    case TIP_REQ_FALLBACK:
        emit refreshGame(EVENT_REQ_FALLBACK);
        break;
    case TIP_REQ_LOSE:
        emit refreshGame(EVENT_REQ_LOSE);
        break;
    case TIP_REQ_TIE:
        emit refreshGame(EVENT_REQ_TIE);
        break;
    default:
        break;
    }
}

void ChessHandler::processTipReplyMsg(char *msg, int len)
{
    assert(len == sizeof(MsgTipReply));
    MsgTipReply *netMsg = (MsgTipReply *)msg;
    tipReplyResult = netMsg->result;
    switch (netMsg->tipType)
    {
    case TIP_REQ_FALLBACK:
        emit refreshGame(EVENT_REQ_FALLBACK_REPLY);
        break;
    case TIP_REQ_LOSE:
        emit refreshGame(EVENT_REQ_LOSE_REPLY);
        break;
    case TIP_REQ_TIE:
        emit refreshGame(EVENT_REQ_TIE_REPLY);
        break;
    default:
        break;
    }

    doAsTipResult(netMsg->tipType, netMsg->result, netMsg->reqSide);
}

void ChessHandler::doAsTipResult(int type, int result, int reqSide)
{
    if (result == 1)
    {
        switch (type)
        {
        case TIP_REQ_FALLBACK:
            fallback();
            break;
        case TIP_REQ_LOSE:
            loseGame(reqSide);
            break;
        case TIP_REQ_TIE:
            drawnGame();
            break;
        default:
            break;
        }
    }
}

void ChessHandler::setTipReqSide(int side)
{
    tipReqSide = side;
}

void ChessHandler::setExitGame(bool exit)
{
    exitGame = exit;
}

void ChessHandler::sendMsg(char *msg, int len)
{
    if (g_gameSettings.getServerOrClient() == SERVER_SIDE)
    {
        server->sendMsg(msg, len);
    }
    else
    {
        client->sendMsg(msg, len);
    }
}

void ChessHandler::sendTipMsg(int type)
{
    MsgTip msg;
    msg.tipType = type;
    msg.reqSide = g_gameSettings.getCompetitorSide() == BLACK ? RED : BLACK;
    sendMsg((char *)&msg, sizeof(msg));
    tipType = type;
}

void ChessHandler::sendTipReplyMsg(int tipType, int result)
{
    tipReplyResult = result;
    MsgTipReply replyMsg;
    replyMsg.reqSide = g_gameSettings.getCompetitorSide();
    replyMsg.tipType = tipType;
    replyMsg.result = result;
    sendMsg((char *)&replyMsg, sizeof(replyMsg));
}

void ChessHandler::sendMoveInfoMsg()
{
    MsgMoveInfo msg;
    msg.currentTurn = currentTurn;
    msg.gameResult = gameResult;
    msg.whoIsDead = whoIsDead;
    memcpy(msg.arrChessman, arrChessman, sizeof(arrChessman));
    msg.killedChessman = currentMoveInfo.killedChessman;
    msg.movingChessman = currentMoveInfo.movingChessman;
    msg.attackGeneral = currentMoveInfo.attackGeneral;
    msg.move = currentMoveInfo.move;
    if (currentMoveInfo.moveStepAlpha.size() > 0)
    {
        strcpy(msg.moveStepAlpha, currentMoveInfo.moveStepAlpha.toStdString().c_str());
    }
    msg.zobristKey = currentMoveInfo.zobristKey;
    sendMsg((char *)&msg, sizeof(msg));
}

void ChessHandler::sendNewGameMsg()
{
    MsgNewGame msg;
    memcpy(msg.arrChessman, arrChessman, sizeof(msg.arrChessman));
    sendMsg((char *)&msg, sizeof(msg));
}

void ChessHandler::sendChessBoardSyncMsg()
{
    MsgChessboardSync msg;
    msg.currentTurn = currentTurn;
    memcpy(msg.arrChessman, arrChessman, sizeof(msg.arrChessman));
    msg.gameResult = gameResult;
    msg.whoIsDead = whoIsDead;
    sendMsg((char *)&msg, sizeof(msg));
}

void ChessHandler::processMessage(char *msg, int len)
{
    BaseNetworkMsg *networkMsg = (BaseNetworkMsg *)msg;

    switch (networkMsg->msgID)
    {
    case MSG_REQ_GAME_INFO:
        processReqGameInfoMsg(msg, len);
        break;
    case MSG_GAME_INFO:
        processGameInfoMsg(msg, len);
        break;
    case MSG_NEW_GAME:
        processNewGameMsg(msg, len);
        break;
    case MSG_CHESSBOARD_SYNC:
        processChessboardSyncMsg(msg, len);
        break;
    case MSG_MOVE_INFO:
        processMoveInfoMsg(msg, len);
        break;
    case MSG_TIP:
        processTipMsg(msg, len);
        break;
    case MSG_TIP_REPLY:
        processTipReplyMsg(msg, len);
        break;
    default:
        break;
    }

}

void ChessHandler::connStateChanged(bool status)
{
    if(exitGame)
    {
        return;
    }

    QString tipMsg;
    if (status == true)
    {
        tipMsg = g_gameSettings.getServerOrClient() == SERVER_SIDE ? tr("客户端已连接。") : tr("服务器已连接。");
        QMessageBox::about(NULL, tr("提示信息"), tipMsg);
    }
    else
    {
        tipMsg = g_gameSettings.getServerOrClient() == SERVER_SIDE ? tr("客户端已断开。") : tr("服务器已断开。");
        tipMsg.append(tr("游戏将进入自由模式"));
        QMessageBox::about(NULL, tr("提示信息"), tipMsg);

        g_gameSettings.setGameType(COMPITITOR_HUMAN);
        newGame();
    }

}
