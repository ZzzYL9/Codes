#ifndef CHESSHANDLER_H
#define CHESSHANDLER_H

#include "commdef.h"
#include "rc4.h"
#include "zobrist.h"
#include "movegenerator.h"
#include "servernetwork.h"
#include "clientnetwork.h"
#include <QObject>
#include <QList>

class ChessHandler : public QObject
{
    Q_OBJECT
public:
    explicit ChessHandler(QObject *parent = 0);
    ~ChessHandler();
    void startGame();
    void newGame();
    void messGame(const char *chessman, int turn);
    void fallback();
    void loseGame(int reqSide);
    void drawnGame();
    void reset(int turn);
    void resetZobrist();
    void setChessmanLayout(const char *chessman);
    void addChessman(int index, char chessmanType);
    void delChessman(int index, char chessmanType);
    void doMove(int index);
    bool redDoMove(int index);
    bool blackDoMove(int index);
    void applyMove();
    void computerMove();
    void doMakeMove(MoveInfo &info, bool record = true);
    void undoMakeMove();
    void undoMakeMove(MoveInfo &info);
    int repStatus(int recur);
    int repValue(int repStatus);
    void stepTimeOver();
    int minMaxSearch(int depth, MoveInfo &info);
    int evaluate();
    bool isMySide();

    const MoveInfo &getCurrentMoveInfo();
    const QList<MoveInfo> &getLstMoveInfo();
    int getGameResult();

    const char *getChessman();
    char getDeadOne();
    int getGeneralPos(char general);
    int getCurrentTurn();
    void setCurrentTurn(int turn);
    void setChessman(const char *arrChessman);
    int getTipReplyResult();
    void setTipReplyResult(int result);
    int getTipType();
    void setTipType(int type);
    void doAsTipResult(int type, int result, int reqSide);
    void setTipReqSide(int side);
    void setExitGame(bool exit);

    void processReqGameInfoMsg(char *msg, int len);
    void processGameInfoMsg(char *msg, int len);
    void processNewGameMsg(char *msg, int len);
    void processChessboardSyncMsg(char *msg, int len);
    void processMoveInfoMsg(char *msg, int len);
    void processTipMsg(char *msg, int len);
    void processTipReplyMsg(char *msg, int len);
    void sendMsg(char *msg, int len);
    void sendTipMsg(int tipType);
    void sendTipReplyMsg(int tipType, int result);
    void sendMoveInfoMsg();
    void sendNewGameMsg();
    void sendChessBoardSyncMsg();

signals:
    void refreshGame(int refreshType);

public slots:
    void processMessage(char *msg, int len);
    void connStateChanged(bool status);

private:
    char arrChessman[256];
    int currentTurn;
    int currentSearchMoveTurn;
    int gameResult;
    char whoIsDead;
    bool exitGame;
    MoveGenerator moveGenerator;
    QList<MoveInfo> lstMoveInfo;
    MoveInfo currentMoveInfo;
    ServerNetwork *server;
    ClientNetwork *client;
    int tipReplyResult;
    int tipType;
    int tipReqSide;

    //子力值
    int blackValue;
    int redValue;

    //用于重复局面检测
    RC4    rc4;
    Zobrist currentZobrist;
    Zobrist initZobrist;
    Zobrist zobristTable[CHESSMAN_TYPE_COUNT][256];

};

#endif // CHESSHANDLER_H
