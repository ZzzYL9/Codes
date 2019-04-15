#ifndef SELECT_FOOD_INFO_H
#define SELECT_FOOD_INFO_H

#include <QDialog>

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "mainwindow.h"

namespace Ui {
class select_food_info;
}

class select_food_info : public QDialog
{
    Q_OBJECT

public:
    explicit select_food_info(QWidget *parent = 0);
    ~select_food_info();

    MainWindow *main_window;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::select_food_info *ui;

    QSqlTableModel *model_foodinfo;    //获取food_price_info
};

#endif // SELECT_FOOD_INFO_H
