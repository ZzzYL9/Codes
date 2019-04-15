#ifndef ADD_FOOD_INFO_H
#define ADD_FOOD_INFO_H

#include <QDialog>

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "mainwindow.h"


namespace Ui {
class add_food_info;
}

class add_food_info : public QDialog
{
    Q_OBJECT

public:
    explicit add_food_info(QWidget *parent = 0);
    ~add_food_info();

    MainWindow *main_window;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::add_food_info *ui;
};

#endif // ADD_FOOD_INFO_H
