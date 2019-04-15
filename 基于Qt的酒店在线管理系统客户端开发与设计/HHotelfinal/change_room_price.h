#ifndef CHANGE_ROOM_PRICE_H
#define CHANGE_ROOM_PRICE_H

#include <QDialog>
//#include <QMainWindow>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "mainwindow.h"

namespace Ui {
class change_room_price;
}

class change_room_price : public QDialog
{
    Q_OBJECT

public:
    explicit change_room_price(QWidget *parent = 0);
    ~change_room_price();

    MainWindow *main_window;

private slots:
    void on_pushButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_room_price *ui;
    int tid;
};

#endif // CHANGE_ROOM_PRICE_H
