#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include"database.h"
class QMenu;
class QAction;
namespace Ui {
class mainwindow;
}

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    enum {REBOOK=0,CURROOM=1,QUITROOM=2};
    explicit mainwindow(DataBase *db,QWidget *parent = nullptr);
    ~mainwindow();
    void Init();
    void reflushContro();
    void reflushDebtContro();
    void reflushStaContro(int index);
    void reflushDayCheckContro();
    void reflushSystemContro();
    void RoomManagementMenu(const QPoint pos);
    void doStyle();
signals:
    void sendOutLogin();

private slots:
    void on_pushButton_5_clicked();

    void onTransRoom(bool yesOrNo,int current);
    void Reservation();//预定操作

    void onrebook(bool yesOrNo);//点击确定操作之后
    void onCheckout(bool yesOrNo);
    void Registration();//登记操作
    void Onregister(bool yesOrno);
    void TransferRooms();//调房操作
    void Chekout();//结账退房操作操作

    void on_findBtn_clicked();

    void on_findEdit_textChanged(const QString &arg1);

    void on_outBtn_clicked();


    void on_findRoomDebtEdit_textChanged(const QString &arg1);

    void on_CheckoutButton_clicked();

    void on_debtTableWidgt_clicked(const QModelIndex &index);

    void on_BookButton_clicked();

    void on_AccommodationButton_clicked();

    void on_RetreatButton_clicked();

    void on_findRoomIdEdit_textChanged(const QString &arg1);

    void on_InitializationButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_ChangePasswordButton_clicked();

private:
    Ui::mainwindow *ui;
    DataBase *m_db;
};

#endif // MAINWINDOW_H
