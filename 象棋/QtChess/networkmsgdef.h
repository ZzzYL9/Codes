#ifndef NETWORK_MSG_DEF_H
#define NETWORK_MSG_DEF_H
#include "commdef.h"

const int MAX_MSG_SIZE = 1024;
const int MSG_REQ_GAME_INFO = 1;
const int MSG_GAME_INFO = 2;
const int MSG_NEW_GAME = 3;
const int MSG_CHESSBOARD_SYNC = 4;
const int MSG_MOVE_INFO = 5;
const int MSG_TIP = 6;
const int MSG_TIP_REPLY = 7;

struct BaseNetworkMsg
{
    int msgID;

    BaseNetworkMsg()
    {
        msgID = 0;
    }
};

struct MsgReqGameInfo : public BaseNetworkMsg
{
    MsgReqGameInfo()
    {
        msgID = MSG_REQ_GAME_INFO;
    }
};

struct MsgGameInfo : public BaseNetworkMsg
{
    int mySide;
    int ahead;
    int stepTime;
    char arrChessman[256];

    MsgGameInfo()
    {
        msgID = MSG_GAME_INFO;
        mySide = 0;
        ahead = 0;
        stepTime = 0;
        memset(arrChessman, 0, sizeof(arrChessman));
    }
};

struct MsgNewGame : public BaseNetworkMsg
{
    char arrChessman[256];

    MsgNewGame()
    {
        msgID = MSG_NEW_GAME;
        memset(arrChessman, 0, sizeof(arrChessman));
    }

};

struct MsgChessboardSync : public BaseNetworkMsg
{
    int currentTurn; 
    int gameResult; 
    int whoIsDead;
    char arrChessman[256];

    MsgChessboardSync()
    {
        msgID = MSG_CHESSBOARD_SYNC;
        currentTurn = 0;
        gameResult = -1;
        whoIsDead = 0;
        memset(arrChessman, 0, sizeof(arrChessman));
    }
};

struct MsgTip : public BaseNetworkMsg
{
    int reqSide;
    int tipType;

    MsgTip()
    {
        msgID = MSG_TIP;
        reqSide = 0;
        tipType = 0;
    }
};

struct MsgTipReply : public BaseNetworkMsg
{
    int reqSide;
    int result;
    int tipType;

    MsgTipReply()
    {
        msgID = MSG_TIP_REPLY;
        reqSide = 0;
        result = 0;
        tipType = 0;
    }
};

struct MsgMoveInfo : public BaseNetworkMsg
{
    int currentTurn; 
    int gameResult; 
    int whoIsDead;
    char arrChessman[256];
    char killedChessman;
    char movingChessman;
    bool attackGeneral;
    int move;
    char moveStepAlpha[10];
    unsigned long zobristKey;

    MsgMoveInfo()
    {
        msgID = MSG_MOVE_INFO;
        currentTurn = 0;
        gameResult = -1;
        whoIsDead = 0;
        memset(arrChessman, 0, sizeof(arrChessman));
        killedChessman = 0;
        movingChessman = 0;
        attackGeneral = false;
        move = 0;
        memset(moveStepAlpha, 0, sizeof(moveStepAlpha));
        zobristKey = 0;
    }
};

#endif
