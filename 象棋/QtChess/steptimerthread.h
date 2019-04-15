#ifndef STEPTIMERTHREAD_H
#define STEPTIMERTHREAD_H

#include <QObject>
#include <QThread>

class StepTimerThread : public QThread
{
    Q_OBJECT
public:
    StepTimerThread(QObject *parent = NULL);
    ~StepTimerThread();

private:
    void *threadData;

protected:
    void run();
};

#endif // STEPTIMERTHREAD_H
