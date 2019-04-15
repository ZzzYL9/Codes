#ifndef DELETE_FOOD_INFO_H
#define DELETE_FOOD_INFO_H

#include <QDialog>

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "mainwindow.h"

namespace Ui {
class delete_food_info;
}

class delete_food_info : public QDialog
{
    Q_OBJECT

public:
    explicit delete_food_info(QWidget *parent = 0);
    ~delete_food_info();

    MainWindow *main_window;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::delete_food_info *ui;

    QSqlTableModel *model_foodinfo;
};

#endif // DELETE_FOOD_INFO_H
