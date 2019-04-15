#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chessboard.h"
#include "steplist.h"
#include "chesshandler.h"
#include "settingsdialog.h"
#include "gamesettings.h"
#include "steptimerthread.h"
#include <QMainWindow>
#include <QMutex>
#include <QWaitCondition>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initActions();
    void processNewGameEvent();
    void processUpdateMoveEvent();
    void processIllegalMoveEvent();
    void processFallbackEvent();
    void processGameResultEvent();
    void processTipEvent(int event);
    void processTipReplyEvent(int event);
    void playTipSound(const MoveInfo &info, int gameResult);
    void playGameResultSound(int gameResult);
    void addToStepList(const MoveInfo &info);
    void updateGeneralDisplay(int gameResult);
    void showResult(int gameResult);
    void showTip(int type);
    void showTipReply(int type, int result);

    void displayStepTime(int interval);
    bool isGameOver();
    void setGameOver(bool gameOver);
    void stepTimeOver();
    void setStepInterval(int interval);
    int getStepInterval();

    ~MainWindow();

    QMutex stepTimeMutex;
    QWaitCondition gameStartCond;
    QWaitCondition stepOverCond;

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void startGame();
    void newGame();
    void settings();
    void flipChessBoard();
    void save();
    void open();
    void fallback();
    void loseGame();
    void drawnGame();
    void about();
    void doMove(int index);

    void processEvent(int event);

private:
    Ui::MainWindow *ui;
    ChessBoard *chessBoard;
    StepList *leftStepList;
    StepList *rightStepList;
    ChessHandler *chessHandler;
    SettingsDialog *settingsDialog;
    bool gameStarted;
    bool gameOver;
    MoveInfo lastMoveInfo;
    int stepInterval;
    StepTimerThread timerThread;
};

#endif // MAINWINDOW_H
