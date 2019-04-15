#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commdef.h"
#include <QSound>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timerThread(this)
{
    ui->setupUi(this);
    move(WINDOW_STARTX, WINDOW_STARTY);
    chessBoard = new ChessBoard(this);
    leftStepList = new StepList(this, true);
    rightStepList = new StepList(this, false);
    chessHandler = new ChessHandler(this);
    settingsDialog = new SettingsDialog(this);
    settingsDialog->setVisible(false);
    gameStarted = false;
    gameOver = false;
    stepInterval = 0;
    lastMoveInfo.reset();

    initActions();
}

void MainWindow::initActions()
{
    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(startGame()));
    connect(ui->actionNewGame, SIGNAL(triggered()), this, SLOT(newGame()));
    connect(ui->actionFlip, SIGNAL(triggered()), this, SLOT(flipChessBoard()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(fallback()));
    connect(ui->actionLose, SIGNAL(triggered()), this, SLOT(loseGame()));
    connect(ui->actionTie, SIGNAL(triggered()), this, SLOT(drawnGame()));
    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(settings()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(chessBoard, SIGNAL(doMove(int)), this, SLOT(doMove(int)));
    connect(chessHandler, SIGNAL(refreshGame(int)), this, SLOT(processEvent(int)));
}

MainWindow::~MainWindow()
{
    if (chessHandler != NULL)
    {
        delete chessHandler;
        chessHandler = NULL;
    }
    if (chessBoard != NULL)
    {
        delete chessBoard;
        chessBoard = NULL;
    }
    if (leftStepList != NULL)
    {
        delete leftStepList;
        leftStepList = NULL;
    }
    if (rightStepList != NULL)
    {
        delete rightStepList;
        rightStepList = NULL;
    }
    if (ui != NULL)
    {
        delete ui;
        ui = NULL;
    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    int ret = QMessageBox::question(this, tr("提示信息"), tr("是否退出游戏？"), QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes)
    {
        chessHandler->setExitGame(true);
        e->accept();
    }
    else
    {
        e->ignore();
    }
}

void MainWindow::startGame()
{
    settings();
    chessHandler->startGame();
    ui->actionStart->setEnabled(false);
    ui->actionNewGame->setEnabled(true);
    ui->actionOpen->setEnabled(true);
    ui->actionSave->setEnabled(true);
    ui->actionFlip->setEnabled(true);
    ui->actionLose->setEnabled(true);
    ui->actionTie->setEnabled(true);
}

void MainWindow::newGame()
{
    chessHandler->newGame();
    if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
    {
        chessHandler->sendNewGameMsg();
    }
}

void MainWindow::settings()
{
    settingsDialog->updateDialog();
    if(settingsDialog->isVisible())
    {
        settingsDialog->activateWindow();
    }
    else
    {
        settingsDialog->show();
    }

    settingsDialog->exec();
}

void MainWindow::flipChessBoard()
{
    chessBoard->changeFlip();
    chessBoard->loadPixmap(chessHandler->getChessman());
    chessBoard->update();
}

//保存棋局为FEN串
void MainWindow::save()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("保存棋局"), QString(), tr("Plain text Files(*.txt);;All Files (*)"));
    if (fn.isEmpty())
    {
        return;
    }
    if (! fn.endsWith(".txt",Qt::CaseInsensitive))
    {
        fn += ".txt";
    }

    QFile file(fn);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);
    out << MoveGenerator::chessmanToFEN(chessHandler->getChessman(), chessHandler->getCurrentTurn());
    file.close();
}

//从FEE串加载棋局
void MainWindow::open()
{
    QString fn = QFileDialog::getOpenFileName(this,tr("加载棋局"),QString(),tr("All Files(*);;Text Files(*.txt)"));
    QFile file(fn);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    if (line.isNull())
    {
        return;
    }

    char arrChessman[256];
    int currentTurn = 0;
    memset(arrChessman, 0, sizeof(arrChessman));
    MoveGenerator::FENTochessman(line, arrChessman, currentTurn);

    chessHandler->messGame(arrChessman, currentTurn);

    if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
    {
        chessHandler->sendChessBoardSyncMsg();
    }

}

void MainWindow::fallback()
{
    if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
    {
        chessHandler->sendTipMsg(TIP_REQ_FALLBACK);
    }
    else
    {
        chessHandler->fallback();
    }

}

void MainWindow::loseGame()
{
    if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
    {
        chessHandler->sendTipMsg(TIP_REQ_LOSE);
    }
    else
    {
        chessHandler->loseGame(g_gameSettings.getCompetitorSide() == BLACK ? RED : BLACK);
    }
}

void MainWindow::drawnGame()
{
    if (g_gameSettings.getGameType() == COMPITITOR_NETWORK)
    {
        chessHandler->sendTipMsg(TIP_REQ_TIE);
    }
    else
    {
        chessHandler->drawnGame();
    }
}

void MainWindow::about()
{
    QMessageBox::about(NULL, tr("关于本软件"), tr("Chinese Chess Version 1.0.0 by Richard Zou"));
}

void MainWindow::doMove(int index)
{
    if (chessHandler->getCurrentTurn() == g_gameSettings.getCompetitorSide() &&
        g_gameSettings.getGameType() != COMPITITOR_HUMAN)
    {
        return;
    }

    if (chessHandler->getGameResult() == -1)
    {
        chessHandler->doMove(index);
    }
}

void MainWindow::processEvent(int event)
{
    switch (event)
    {
    case EVENT_NEW_GAME:
        processNewGameEvent();
        break;
    case EVENT_UPDATE_MOVE:
        processUpdateMoveEvent();
        break;
    case EVENT_ILLEGAL_MOVE:
        processIllegalMoveEvent();
        break;
    case EVENT_FALLBACK:
        processFallbackEvent();
        break;
    case EVENT_GAME_RESULT:
        processGameResultEvent();
        break;
    case EVENT_REQ_FALLBACK:
    case EVENT_REQ_TIE:
    case EVENT_REQ_LOSE:
        processTipEvent(event);
        break;
    case EVENT_REQ_FALLBACK_REPLY:
    case EVENT_REQ_LOSE_REPLY:
    case EVENT_REQ_TIE_REPLY:
        processTipReplyEvent(event);
        break;
    default:
        break;
    }
}

void MainWindow::processNewGameEvent()
{
    chessBoard->loadPixmap(chessHandler->getChessman());
    chessBoard->update();
    leftStepList->clearHistoryDisplay();
    rightStepList->clearHistoryDisplay();
    gameOver = false;
    gameStarted = true;
    lastMoveInfo.reset();
    ui->actionSettings->setEnabled(false);
    QSound::play(AUDIO_NEW_GAME);

    if (g_gameSettings.getStepTime() > 0)
    {
        timerThread.start();
        usleep(500);
        gameStartCond.wakeAll();
    }
}

void MainWindow::processUpdateMoveEvent()
{
    MoveInfo info = chessHandler->getCurrentMoveInfo();
    int gameResult = chessHandler->getGameResult();

    //如果移动了完整的一步，则需要先更新整个棋盘
    if (SRC(info.move) > 0 && DST(info.move) > 0)
    {
        chessBoard->loadPixmap(chessHandler->getChessman());
        addToStepList(info);
        if (gameResult == -1 && g_gameSettings.getStepTime() > 0)
        {
            stepOverCond.wakeAll();
        }
    }

    if (isSameSide(lastMoveInfo.movingChessman, info.movingChessman))
    {
        chessBoard->showMoveRoute(lastMoveInfo.movingChessman, lastMoveInfo.move, false);
    }
    chessBoard->showMoveRoute(info.movingChessman, info.move, true);
    chessBoard->update();

    playTipSound(info, gameResult);

    if (gameResult != -1)
    {
        if (gameResult != 0)
        {
            updateGeneralDisplay(gameResult);
        }

        showResult(gameResult);
    }

    lastMoveInfo = info;
    gameOver = gameResult != -1;
    ui->actionUndo->setEnabled(chessHandler->getLstMoveInfo().size() > 0);
}

void MainWindow::processIllegalMoveEvent()
{
    QSound::play(AUDIO_ILLEGAL);
}

void MainWindow::processFallbackEvent()
{
    chessBoard->loadPixmap(chessHandler->getChessman());
    chessBoard->update();
    lastMoveInfo.reset();
    leftStepList->fallbackMoveHistory();
    rightStepList->fallbackMoveHistory();

    if (chessHandler->getGameResult() == -1 && g_gameSettings.getStepTime() > 0)
    {
        stepOverCond.wakeAll();
    }
}

void MainWindow::processGameResultEvent()
{
    int gameResult = chessHandler->getGameResult();
    gameOver = gameResult != -1;
    playGameResultSound(gameResult);
    showResult(gameResult);
}

void MainWindow::processTipEvent(int event)
{
    Q_UNUSED(event);

    showTip(chessHandler->getTipType());
}

void MainWindow::processTipReplyEvent(int event)
{
    Q_UNUSED(event);
    showTipReply(chessHandler->getTipType(), chessHandler->getTipReplyResult());
    chessHandler->setTipType(0);
    chessHandler->setTipReplyResult(0);
    chessHandler->setTipReqSide(0);
}

void MainWindow::playTipSound(const MoveInfo &info, int gameResult)
{
    if (gameResult != -1)
    {
        playGameResultSound(gameResult);
    }
    else
    {
        if (SRC(info.move) > 0 && DST(info.move) > 0)
        {
            if (info.attackGeneral)
            {
                QSound::play(AUDIO_ATTACK_KING);
            }
            else
            {
                QSound::play(info.killedChessman == 0 ? AUDIO_MOVE : AUDIO_EAT);
            }
        }
        else
        {
            QSound::play(AUDIO_CHOOSE);
        }
    }
}

void MainWindow::playGameResultSound(int gameResult)
{
    if (gameResult != TIE)
    {
        QSound::play(gameResult == g_gameSettings.getCompetitorSide() ? AUDIO_LOSS : AUDIO_WIN);
    }
    else
    {
        QSound::play(AUDIO_TIE);
    }
}

void MainWindow::addToStepList(const MoveInfo &info)
{
    bool blackSide = isBlackSide(info.movingChessman);
    if (blackSide)
    {
        rightStepList->addMoveHistory(info);
    }
    else
    {
        leftStepList->addMoveHistory(info);
    }
}

void MainWindow::updateGeneralDisplay(int gameResult)
{
    int pos = 0;
    switch(gameResult)
    {
    case BLACK:
        {
            if (chessHandler->getDeadOne() == RED &&
                (pos = chessHandler->getGeneralPos(RED_GENERAL)) > 0)
            {
                chessBoard->updateGeneralDisplay(RED_GENERAL, pos, true);
            }
        }
        break;
    case RED:
        {
            if (chessHandler->getDeadOne() == BLACK &&
                (pos = chessHandler->getGeneralPos(BLACK_GENERAL)) > 0)
            {
                chessBoard->updateGeneralDisplay(BLACK_GENERAL, pos, true);
            }
        }
        break;
    default:
        break;
    }

    chessBoard->update();
}

void MainWindow::showResult(int gameResult)
{
    switch (gameResult)
    {
    case TIE:
        QMessageBox::about(NULL, tr("比赛结果"), tr("和局"));
        break;
    case BLACK:
        QMessageBox::about(NULL, tr("比赛结果"), tr("黑方胜"));
        break;
    case RED:
        QMessageBox::about(NULL, tr("比赛结果"), tr("红方胜"));
        break;
    default:
        break;
    }

    if (gameResult != -1)
    {
        ui->actionSettings->setEnabled(true);
    }
}

void MainWindow::showTip(int type)
{
    QString tipMsg;
    switch(type)
    {
    case TIP_REQ_FALLBACK:
        tipMsg = tr("对方请求悔棋，是否同意？");
        break;
    case TIP_REQ_TIE:
        tipMsg = tr("对方请求和棋，是否同意？");
        break;
    case TIP_REQ_LOSE:
        tipMsg = tr("对方请求认输，是否同意？");
        break;
    default:
        break;
    }

    if (tipMsg.size())
    {
        QMessageBox msgBox;
        msgBox.setText(tipMsg);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Discard);
        msgBox.setButtonText(QMessageBox::Ok, tr("同意"));
        msgBox.setButtonText(QMessageBox::Discard, tr("不同意"));

        int result = (msgBox.exec() == QMessageBox::Ok ? 1 : 0);
        chessHandler->sendTipReplyMsg(type, result);
        chessHandler->doAsTipResult(type, result, g_gameSettings.getCompetitorSide());
    }
}

void MainWindow::showTipReply(int type, int result)
{
    QString tipReplyMsg;
    switch(type)
    {
    case TIP_REQ_FALLBACK:
        tipReplyMsg = result == 1 ? tr("对方同意悔棋。") : tr("对方不同意悔棋。");
        break;
    case TIP_REQ_TIE:
        tipReplyMsg = result == 1 ? tr("对方同意和棋。") : tr("对方不同意和棋。");
        break;
    case TIP_REQ_LOSE:
        tipReplyMsg = result == 1 ? tr("对方同意认输。") : tr("对方不同意认输。");
        break;
    default:
        break;
    }

    if (tipReplyMsg.size())
    {
        QMessageBox::about(NULL, tr("提示信息"), tipReplyMsg);
    }
}

void MainWindow::displayStepTime(int interval)
{
    if(ui && ui->timeLeft)
    {
        ui->timeLeft->display(convertToTimeStr(interval));
    }
    if (ui && ui->lblTurn)
    {
        ui->lblTurn->setText(chessHandler->getCurrentTurn() == BLACK ? tr("黑方走棋") : tr("红方走棋"));
    }
}

bool MainWindow::isGameOver()
{
    return gameOver;
}

void MainWindow::setGameOver(bool isGameOver)
{
    gameOver = isGameOver;
}

void MainWindow::stepTimeOver()
{
    chessHandler->stepTimeOver();
}

void MainWindow::setStepInterval(int interval)
{
    stepInterval = interval;
}

int MainWindow::getStepInterval()
{
    return stepInterval;
}

