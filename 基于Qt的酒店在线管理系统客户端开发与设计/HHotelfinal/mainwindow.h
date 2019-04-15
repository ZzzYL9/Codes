/********************************************************************************
* File Name:	mainwindow.cpp
* Description:	第6章实例训练
* Reference book:《Linux环境下Qt4图形界面与MySQL编程》，机械工业出版社.2012.1
* E_mail: openlinux2011@gmail.com
*
********************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>


namespace Ui {
    class MainWindow;
} //text 中 text 中 text 中

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    //房间类型选择 pushbutton
    void on_rb1_clicked();

    void on_rb2_clicked();

    void on_rb3_clicked();

    void on_rb4_clicked();

    void on_rb5_clicked();

    void on_rb6_clicked();

    void on_pbSubmit_clicked();

    void on_pbCancle_clicked();

    void on_pbOut_Search_clicked();

    void on_pbCheckout_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_31_clicked();

private:
    Ui::MainWindow *ui;

    QSqlTableModel *roominfo_model;     //获取roominfo
    QSqlTableModel *priceinfo_model;    //获取price_info
    QSqlTableModel *checkout_model;    //获取checkout
    QSqlTableModel *model_checkout;    //获取checkout
    QSqlTableModel *model_checkin;    //获取checkin
    QSqlTableModel *model_checkin_other;    //获取checkin_other
    QSqlTableModel *model_foodinfo;    //获取food_price_info
    QSqlTableModel *model_bashinfo;    //获取bash_typeinfo
    QSqlTableModel *staff_info;    //获取staff_info
    QSqlTableModel *staff_info_1;    //获取指定staff_info

    int bash_index;


};


#endif // MAINWINDOW_H
