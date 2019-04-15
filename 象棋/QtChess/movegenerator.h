#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H
#include <QString>
#include <stdio.h>
#include <QList>
#include "commdef.h"

class MoveGenerator
{
public:
    MoveGenerator();
    ~MoveGenerator();
    bool validateMove(const char *arrChessman, int srcPos, int dstPos);
    bool validateGeneralMove(const char *arrChessman, int srcPos, int dstPos);
    bool validateAdvisorMove(const char *arrChessman, int srcPos, int dstPos);
    bool validateMinisterMove(const char *arrChessman, int srcPos, int dstPos);
    bool validateHorseMove(const char *arrChessman, int srcPos, int dstPos);
    bool validateChariotMove(const char *arrChessman, int srcPos, int dstPos);
    bool validateCannonMove(const char *arrChessman, int srcPos, int dstPos);
    bool validateSoldierMove(const char *arrChessman, int srcPos, int dstPos);

    void generateAllMove(char *arrChessman, int side, QList<MoveInfo> &lstInfo);
    void generateGeneralMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo);
    void generateAdvisorMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo);
    void generateMinisterMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo);
    void generateHorseMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo);
    void generateChariotMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo);
    void generateCannonMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo);
    void generateSoldierMove(char *arrChessman, int srcPos, MoveInfo &info, QList<MoveInfo> &lstInfo);

    void addMoveRoute(char *arrChessman, int srcPos, int dstPos, MoveInfo &info, QList<MoveInfo> &lstInfo);

    bool isAttackGeneral(const char *arrChessman, char attackedGeneral);
    bool attackGeneral(const char *arrChessman, int attackedPos, char chessman);
    bool attackedByGeneral(const char *arrChessman, int attackedPos, char attackingGeneral);
    int getChessmanPos(const char *arrChessman, char chessman, int pos[]);

    bool isGeneralDead(char *arrChessman, int side);
    bool canSaveGeneral(char *arrChessman, int index, char attackedGeneral);

    //获取着法的数字坐标格式，如k5+1
    void getMoveStepAlpha(const char *arrChessman, int mv, QString &stepAlpha);
    void getGeneralMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha);
    void getAdvisorMinisterMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha);
    void getChariotCannonMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha);
    void getHorseMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha);
    void getSoldierMoveStepAlpha(const char *arrChessman, char movingChessman, int fromX, int fromY, int toX, int toY, QString &stepAlpha);

    //将数字坐标格式转换成中文格式如将5进1
    static QString digitToChinese(const QChar &digit, bool black);
    static QString chessManCodeToChinese(const QChar &code);
    static QString actionToChinese(const QChar &action);
    static void alphaFmtToChiness(const QString &alphaFmt, QString &chineseFmt, bool black);

    //保存棋局结果为FEN串
    static QString chessmanToFEN(const char *arrChessman, int currentTurn);
    //从FEE串加载棋局
    static void FENTochessman(QString strFEN, char *arrChessman, int &currentTurn);

};

#endif // MOVEGENERATOR_H
