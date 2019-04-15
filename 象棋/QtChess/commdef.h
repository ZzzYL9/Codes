#ifndef COMMDEF_H
#define COMMDEF_H
#include <QString>
#include <QObject>

struct MoveInfo
{
    char killedChessman;
    char movingChessman;
    bool attackGeneral;
    int move;
    QString moveStepAlpha;
    unsigned long zobristKey;

    void reset()
    {
        killedChessman = 0;
        movingChessman = 0;
        attackGeneral = 0;
        move = 0;
        moveStepAlpha = "";
        zobristKey = 0;
    }

    MoveInfo()
    {
        reset();
    }

};

struct ChineseMoveStep
{
    int orderNumber;
    QString moveStepInfo;
    QString moveStepTime;

    ChineseMoveStep()
    {
        orderNumber = 0;
    }
};

static const QString INDICATOR = QObject::tr(":/images/WOOD/OOS.GIF");
static const QString AUDIO_NEW_GAME = QObject::tr(":/audios/NewGame.wav");
static const QString AUDIO_ATTACK_KING = QObject::tr(":/audios/AttackKing.wav");
static const QString AUDIO_CHOOSE = QObject::tr(":/audios/Choose.wav");
static const QString AUDIO_EAT = QObject::tr(":/audios/Eat.wav");
static const QString AUDIO_LOSS = QObject::tr(":/audios/Loss.wav");
static const QString AUDIO_MOVE = QObject::tr(":/audios/Move.wav");
static const QString AUDIO_WIN = QObject::tr(":/audios/Win.wav");
static const QString AUDIO_TIE = QObject::tr(":/audios/Draw.wav");
static const QString AUDIO_ILLEGAL = QObject::tr(":/audios/Forbid.wav");

static const QString SETTINGS_FILE = QObject::tr("Config.ini");
static const QString CHESSMAN_CODE = QObject::tr("krncabpKRNCABP"); //将车马炮士象卒帅车马炮仕相兵

static const int TIE = 0;
static const int BLACK = 1;
static const int RED = 2;
static const int COMPITITOR_MACHINE = 1;
static const int COMPITITOR_HUMAN = 2;
static const int COMPITITOR_NETWORK = 3;
static const int CLIENT_SIDE = 1;
static const int SERVER_SIDE = 2;
static const int MAX_SEARCH_DEPTH = 3;

static const int CHESSMAN_TYPE_COUNT = 14;
static const int CHESSBOARD_ROW = 10;
static const int CHESSBOARD_COLUMN = 9;
static const int WINDOW_STARTX = 0;
static const int WINDOW_STARTY = 0;
static const int CHESSBOARD_WIDTH = 521;
static const int CHESSBOARD_HEIGHT = 577;
static const int CHESSBOARD_STARTX = 250;
static const int CHESSBOARD_STARTY = 100;
static const int LEFTSTEPLIST_STARTX = 20;
static const int LEFTSTEPLIST_STARTY = 100;
static const int STEPLIST_WIDTH = 200;
static const int STEPLIST_HEIGHT = 640;
static const int RIGHTSTEPLIST_STARTX = 800;
static const int RIGHTSTEPLIST_STARTY = 100;
static const int MOVE_STEP_PER_PAGE = 15;
static const int COLUMN_PER_STEP = 3;

static const int SQUARE_SIZE = 57;
static const int BOARD_EDGE = 4;

// 棋盘范围
static const int RANK_TOP = 3;
static const int RANK_BOTTOM = 12;
static const int FILE_LEFT = 3;
static const int FILE_RIGHT = 11;

//棋子编号
static const char BLACK_GENERAL = 1;     //黑将
static const char BLACK_CHARIOT = 2;     //黑车
static const char BLACK_HORSE = 3;       //黑马
static const char BLACK_CANNON = 4;      //黑炮
static const char BLACK_ADVISOR = 5;     //黑士
static const char BLACK_MINISTER = 6;    //黑象
static const char BLACK_SOLDIER = 7;     //黑卒

static const char RED_GENERAL = 8;       //红帅
static const char RED_CHARIOT = 9;       //红车
static const char RED_HORSE = 10;        //红马
static const char RED_CANNON = 11;       //红炮
static const char RED_ADVISOR = 12;      //红仕
static const char RED_MINISTER = 13;     //红相
static const char RED_SOLDIER = 14;      //红兵

static const int EVENT_NEW_GAME = 1;
static const int EVENT_UPDATE_MOVE = 2;
static const int EVENT_ILLEGAL_MOVE = 3;
static const int EVENT_FALLBACK = 4;
static const int EVENT_GAME_RESULT = 5;
static const int EVENT_REQ_FALLBACK = 8;
static const int EVENT_REQ_FALLBACK_REPLY = 9;
static const int EVENT_REQ_TIE = 10;
static const int EVENT_REQ_TIE_REPLY = 11;
static const int EVENT_REQ_LOSE = 12;
static const int EVENT_REQ_LOSE_REPLY = 13;

static const int TIP_REQ_FALLBACK = 1;
static const int TIP_REQ_TIE = 2;
static const int TIP_REQ_LOSE = 3;

// 判断棋子是否在棋盘中的数组
static const char ccInBoard[256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// 判断棋子是否在九宫的数组
static const char ccInFort[256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// 判断步长是否符合特定走法的数组，1=帅(将)，2=仕(士)，3=相(象)
static const char ccLegalSpan[512] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0
};

// 根据步长判断马是否蹩腿的数组
static const char ccKnightPin[512] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,-16,  0,-16,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0, 16,  0, 16,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0
};

// 帅(将)的步长
static const char KING_DELTA[4] = {-16, -1, 1, 16};
// 仕(士)的步长
static const char ADVISOR_DELTA[4] = {-17, -15, 15, 17};
// 马的步长，以帅(将)的步长作为马腿
static const char knightDelta[4][2] = {{-33, -31}, {-18, 14}, {-14, 18}, {31, 33}};
// 马被将军的步长，以仕(士)的步长作为马腿
static const char KNIGHT_CHECK_DELTA[4][2] = {{-33, -18}, {-31, -14}, {14, 31}, {18, 33}};

// 棋盘初始设置
static const char STARTUP_LAYOUT[256] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  2,  3,  6,  5,  1,  5,  6,  3,  2,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,
    0,  0,  0,  7,  0,  7,  0,  7,  0,  7,  0,  7,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0, 14,  0, 14,  0, 14,  0, 14,  0, 14,  0,  0,  0,  0,
    0,  0,  0,  0, 11,  0,  0,  0,  0,  0, 11,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0, 9, 10, 13,  12,  8,  12, 13, 10, 9,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

const int MATE_VALUE = 10000;               //最高分值，即将死的分值
const int BAN_VALUE = MATE_VALUE - 100;     //长将判负的分值，低于该值将不写入置换表
const int WIN_VALUE = MATE_VALUE - 200;     //搜索出胜负的分值界限，超出此值就说明已经搜索出杀棋了
const int DRAW_VALUE = 20;                  //和棋时返回的分数（取负值）
const int ADVANCED_VALUE = 3;               //先行权分值
const int RANDOM_MASK = 7;                  //随机性分值

// 子力位置价值表
static const int CHESSMAN_VALUE[7][256] = {
    { // 帅(将)
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0, 11, 15, 11,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    }, { // 车
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,194,206,204,212,200,212,204,206,194,  0,  0,  0,  0,
         0,  0,  0,200,208,206,212,200,212,206,208,200,  0,  0,  0,  0,
         0,  0,  0,198,208,204,212,212,212,204,208,198,  0,  0,  0,  0,
         0,  0,  0,204,209,204,212,214,212,204,209,204,  0,  0,  0,  0,
         0,  0,  0,208,212,212,214,215,214,212,212,208,  0,  0,  0,  0,
         0,  0,  0,208,211,211,214,215,214,211,211,208,  0,  0,  0,  0,
         0,  0,  0,206,213,213,216,216,216,213,213,206,  0,  0,  0,  0,
         0,  0,  0,206,208,207,214,216,214,207,208,206,  0,  0,  0,  0,
         0,  0,  0,206,212,209,216,233,216,209,212,206,  0,  0,  0,  0,
         0,  0,  0,206,208,207,213,214,213,207,208,206,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    }, { // 马
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0, 88, 85, 90, 88, 90, 88, 90, 85, 88,  0,  0,  0,  0,
         0,  0,  0, 85, 90, 92, 93, 78, 93, 92, 90, 85,  0,  0,  0,  0,
         0,  0,  0, 93, 92, 94, 95, 92, 95, 94, 92, 93,  0,  0,  0,  0,
         0,  0,  0, 92, 94, 98, 95, 98, 95, 98, 94, 92,  0,  0,  0,  0,
         0,  0,  0, 90, 98,101,102,103,102,101, 98, 90,  0,  0,  0,  0,
         0,  0,  0, 90,100, 99,103,104,103, 99,100, 90,  0,  0,  0,  0,
         0,  0,  0, 93,108,100,107,100,107,100,108, 93,  0,  0,  0,  0,
         0,  0,  0, 92, 98, 99,103, 99,103, 99, 98, 92,  0,  0,  0,  0,
         0,  0,  0, 90, 96,103, 97, 94, 97,103, 96, 90,  0,  0,  0,  0,
         0,  0,  0, 90, 90, 90, 96, 90, 96, 90, 90, 90,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    }, { // 炮
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0, 96, 96, 97, 99, 99, 99, 97, 96, 96,  0,  0,  0,  0,
         0,  0,  0, 96, 97, 98, 98, 98, 98, 98, 97, 96,  0,  0,  0,  0,
         0,  0,  0, 97, 96,100, 99,101, 99,100, 96, 97,  0,  0,  0,  0,
         0,  0,  0, 96, 96, 96, 96, 96, 96, 96, 96, 96,  0,  0,  0,  0,
         0,  0,  0, 95, 96, 99, 96,100, 96, 99, 96, 95,  0,  0,  0,  0,
         0,  0,  0, 96, 96, 96, 96,100, 96, 96, 96, 96,  0,  0,  0,  0,
         0,  0,  0, 96, 99, 99, 98,100, 98, 99, 99, 96,  0,  0,  0,  0,
         0,  0,  0, 97, 97, 96, 91, 92, 91, 96, 97, 97,  0,  0,  0,  0,
         0,  0,  0, 98, 98, 96, 92, 89, 92, 96, 98, 98,  0,  0,  0,  0,
         0,  0,  0,100,100, 96, 91, 90, 91, 96,100,100,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    }, { // 仕(士)
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0, 20,  0, 20,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0, 23,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0, 20, 20, 20,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    }, { // 相(象)
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0, 20,  0,  0,  0, 20,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0, 18,  0,  0,  0, 23,  0,  0,  0, 18,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0, 20,  0,  0,  0, 20,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    }, { // 兵(卒)
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  7,  0,  7,  0, 15,  0,  7,  0,  7,  0,  0,  0,  0,
         0,  0,  0,  7,  0, 13,  0, 16,  0, 13,  0,  7,  0,  0,  0,  0,
         0,  0,  0, 14, 18, 20, 27, 29, 27, 20, 18, 14,  0,  0,  0,  0,
         0,  0,  0, 19, 23, 27, 29, 30, 29, 27, 23, 19,  0,  0,  0,  0,
         0,  0,  0, 19, 24, 32, 37, 37, 37, 32, 24, 19,  0,  0,  0,  0,
         0,  0,  0, 19, 24, 34, 42, 44, 42, 34, 24, 19,  0,  0,  0,  0,
         0,  0,  0,  9,  9,  9, 11, 13, 11,  9,  9,  9,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    }
};

// 根据纵坐标和横坐标获得格子
inline int COORD_XY(int x, int y) {
    return x + (y << 4);
}

// 纵坐标水平镜像
inline int FILE_FLIP(int x) {
    return 14 - x;
}

// 横坐标垂直镜像
inline int RANK_FLIP(int y) {
    return 15 - y;
}

inline int getChessboardCoord(int x, int y, bool fliped)
{
    x = fliped ? FILE_FLIP(x) : x;
    y = fliped ? RANK_FLIP(y) : y;

    return (x - FILE_LEFT) + (y - RANK_TOP) * CHESSBOARD_COLUMN;
}

//获取棋子位置
inline void getPixmapPos(int row, int column, int &xx, int &yy)
{
    xx = BOARD_EDGE + column * SQUARE_SIZE;
    yy = BOARD_EDGE + row * SQUARE_SIZE;
}

//根据棋盘上的行和列获取在数组中的索引
inline int getChessmanIndex(int row, int column, bool fliped)
{
    int x = column + FILE_LEFT;
    int y = row + RANK_TOP;
    if (fliped)
    {
        x = FILE_FLIP(x);
        y = RANK_FLIP(y);
    }
    return COORD_XY(x, y);
}

inline void getPixmapIndex(int xx, int yy, int &row, int &column)
{
    row = (yy - BOARD_EDGE) / SQUARE_SIZE;
    column = (xx - BOARD_EDGE) / SQUARE_SIZE;
}

// 判断棋子是否在棋盘中
inline bool IN_BOARD(int sq) {
    return ccInBoard[sq] != 0;
}

// 判断棋子是否在九宫中
inline bool IN_FORT(int sq) {
    return ccInFort[sq] != 0;
}

// 获得格子的纵坐标
inline int RANK_Y(int sq) {
    return sq >> 4;
}

// 获得格子的横坐标
inline int FILE_X(int sq) {
    return sq & 15;
}

// 翻转格子
inline int SQUARE_FLIP(int sq) {
    return 254 - sq;
}

// 格子水平镜像
inline int MIRROR_SQUARE(int sq) {
    return COORD_XY(FILE_FLIP(FILE_X(sq)), RANK_Y(sq));
}

// 格子水平镜像
inline int SQUARE_FORWARD(int sq, int sd) {
    return sq - 16 + (sd << 5);
}

// 走法是否符合帅(将)的步长
inline bool KING_SPAN(int sqSrc, int sqDst) {
    return ccLegalSpan[sqDst - sqSrc + 256] == 1;
}

// 走法是否符合仕(士)的步长
inline bool ADVISOR_SPAN(int sqSrc, int sqDst) {
    return ccLegalSpan[sqDst - sqSrc + 256] == 2;
}

// 走法是否符合相(象)的步长
inline bool BISHOP_SPAN(int sqSrc, int sqDst) {
    return ccLegalSpan[sqDst - sqSrc + 256] == 3;
}

// 相(象)眼的位置
inline int BISHOP_PIN(int sqSrc, int sqDst) {
    return (sqSrc + sqDst) >> 1;
}

// 马腿的位置
inline int KNIGHT_PIN(int sqSrc, int sqDst) {
    return sqSrc + ccKnightPin[sqDst - sqSrc + 256];
}

// 是否未过河
inline bool HOME_HALF(int sq, int sd) {
    return (sq & 0x80) != (sd << 7);
}

// 是否已过河
inline bool AWAY_HALF(int sq, int sd) {
    return (sq & 0x80) == (sd << 7);
}

// 是否在河的同一边
inline bool SAME_HALF(int sqSrc, int sqDst) {
    return ((sqSrc ^ sqDst) & 0x80) == 0;
}

// 是否在同一行
inline bool SAME_RANK(int sqSrc, int sqDst) {
    return ((sqSrc ^ sqDst) & 0xf0) == 0;
}

// 是否在同一列
inline bool SAME_FILE(int sqSrc, int sqDst) {
    return ((sqSrc ^ sqDst) & 0x0f) == 0;
}

// 获得走法的起点
inline int SRC(int mv) {
  return mv & 255;
}

// 获得走法的终点
inline int DST(int mv) {
  return mv >> 8;
}

// 根据起点和终点获得走法
inline int MOVE(int sqSrc, int sqDst) {
  return sqSrc + (sqDst << 8);
}

inline bool isBlackSide(char chessmanType)
{
    return (chessmanType >= BLACK_GENERAL) && (chessmanType <= BLACK_SOLDIER);
}

inline bool isRedSide(int chessmanType)
{
    return (chessmanType >= RED_GENERAL) && (chessmanType <= RED_SOLDIER);
}

inline bool isSameSide(int srcChessmanType, int dstChessmanType)
{
    return ((isBlackSide(srcChessmanType) && isBlackSide(dstChessmanType))
            || (isRedSide(srcChessmanType) && isRedSide(dstChessmanType)));
}

inline QString getChessmanPic(char chessman, bool selected, bool dead)
{
    QString chessmanPic;
    switch(chessman)
    {
    case 0:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/OOS.GIF"): QObject::tr(":/images/WOOD/OO.GIF");
        }
        break;
    case 1:
        {
            chessmanPic = dead ? QObject::tr(":/images/WOOD/BKM.GIF") : (selected ? QObject::tr(":/images/WOOD/BKS.GIF"): QObject::tr(":/images/WOOD/BK.GIF"));
        }
        break;
    case 2:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/BRS.GIF"): QObject::tr(":/images/WOOD/BR.GIF");
        }
        break;
    case 3:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/BNS.GIF"): QObject::tr(":/images/WOOD/BN.GIF");
        }
        break;
    case 4:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/BCS.GIF"): QObject::tr(":/images/WOOD/BC.GIF");
        }
        break;
    case 5:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/BAS.GIF"): QObject::tr(":/images/WOOD/BA.GIF");
        }
        break;
    case 6:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/BBS.GIF"): QObject::tr(":/images/WOOD/BB.GIF");
        }
        break;
    case 7:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/BPS.GIF"): QObject::tr(":/images/WOOD/BP.GIF");
        }
        break;
    case 8:
        {
            chessmanPic = dead ? QObject::tr(":/images/WOOD/RKM.GIF") : (selected ? QObject::tr(":/images/WOOD/RKS.GIF"): QObject::tr(":/images/WOOD/RK.GIF"));
        }
        break;
    case 9:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/RRS.GIF"): QObject::tr(":/images/WOOD/RR.GIF");
        }
        break;
    case 10:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/RNS.GIF"): QObject::tr(":/images/WOOD/RN.GIF");
        }
        break;
    case 11:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/RCS.GIF"): QObject::tr(":/images/WOOD/RC.GIF");
        }
        break;
    case 12:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/RAS.GIF"): QObject::tr(":/images/WOOD/RA.GIF");
        }
        break;
    case 13:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/RBS.GIF"): QObject::tr(":/images/WOOD/RB.GIF");
        }
        break;
    case 14:
        {
            chessmanPic = selected ? QObject::tr(":/images/WOOD/RPS.GIF"): QObject::tr(":/images/WOOD/RP.GIF");
        }
        break;
    default:
        break;
    }
    return chessmanPic;
}

inline int getChessmanTypeByCode(QChar code)
{
    int chessmanType = 0;
    for (int i = 0; i < 14; ++i)
    {
        if (CHESSMAN_CODE.at(i) == code)
        {
            chessmanType = i + 1;
            break;
        }
    }

    return chessmanType;
}

inline QString convertToTimeStr(int seconds)
{
    QString time;

    int hour = seconds / 3600;
    int minute = (seconds - hour * 3600) / 60;
    int second = seconds - hour * 3600 - minute * 60;
    time.sprintf("%.2d:%.2d:%.2d", hour, minute, second);

    return time;
}

#endif // COMMDEF

