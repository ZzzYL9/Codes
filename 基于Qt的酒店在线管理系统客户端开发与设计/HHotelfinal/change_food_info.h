#ifndef CHANGE_FOOD_INFO_H
#define CHANGE_FOOD_INFO_H

#include <QDialog>

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "mainwindow.h"

namespace Ui {
class change_food_info;
}

class change_food_info : public QDialog
{
    Q_OBJECT

public:
    explicit change_food_info(QWidget *parent = 0);
    ~change_food_info();

    MainWindow *main_window;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_food_info *ui;
};

#endif // CHANGE_FOOD_INFO_H
