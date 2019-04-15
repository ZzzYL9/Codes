#ifndef CHANGE_BASH_INFO_H
#define CHANGE_BASH_INFO_H

#include <QDialog>

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "mainwindow.h"

namespace Ui {
class change_bash_info;
}

class change_bash_info : public QDialog
{
    Q_OBJECT

public:
    explicit change_bash_info(QWidget *parent = 0);
    ~change_bash_info();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_bash_info *ui;

    MainWindow *main_window;
};

#endif // CHANGE_BASH_INFO_H
