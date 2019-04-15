#include "steptimerthread.h"
#include "mainwindow.h"

StepTimerThread::StepTimerThread(QObject *parent) : QThread(parent), threadData(parent)
{

}

StepTimerThread::~StepTimerThread()
{
    wait();
}

void StepTimerThread::run()
{
    MainWindow *mainWin = (MainWindow *)threadData;

    mainWin->stepTimeMutex.lock();
    while (mainWin->getStepInterval() == 0)
    {
        mainWin->gameStartCond.wait(&mainWin->stepTimeMutex, 500);
        mainWin->setStepInterval(g_gameSettings.getStepTime());
    }
    mainWin->stepTimeMutex.unlock();
    mainWin->displayStepTime(mainWin->getStepInterval());

    while (!mainWin->isGameOver())
    {
        mainWin->stepTimeMutex.lock();
        while (mainWin->getStepInterval() > 0 && !mainWin->isGameOver())
        {
            if(mainWin->stepOverCond.wait(&mainWin->stepTimeMutex, 1000) == false)
            {
                int interval = mainWin->getStepInterval() - 1;
                mainWin->setStepInterval(interval);
            }
            else
            {
                mainWin->setStepInterval(g_gameSettings.getStepTime());
            }

            mainWin->displayStepTime(mainWin->getStepInterval());
        }
        mainWin->setStepInterval(0);
        mainWin->setGameOver(true);
        mainWin->stepTimeOver();
        mainWin->stepTimeMutex.unlock();
    }
}

