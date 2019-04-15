#ifndef STEPLIST_H
#define STEPLIST_H

#include "commdef.h"

#include <QWidget>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPaintEvent>
#include <QVector>

class StepList : public QWidget
{
    Q_OBJECT
public:
    explicit StepList(QWidget *parent = 0, bool left = true);
    ~StepList();
    void initPushButtons();
    void initPageInfo();
    void initTableView();
    void addMoveHistory(const MoveInfo &info);
    void clearHistoryDisplay();
    void updateHistoryDisplay();
    int getPageNumber(int orderNumber);
    int getRecordIndex(int orderNumber);
    void fallbackMoveHistory();

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void prevRecord();
    void prevPage();
    void nextRecord();
    void nextPage();

private:
    QPixmap pixSide;
    QTableView  *tableView;
    QStandardItemModel *model;
    QPushButton *btnPrevRecord;
    QPushButton *btnPrevPage;
    QPushButton *btnNextRecord;
    QPushButton *btnNextPage;
    QLabel *lblPageInfo;
    QVector<ChineseMoveStep> vecMoveHistory;
    int currentOrderNumber;
};

#endif // STEPLIST_H
