#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QListWidgetItem>
#include <QFile>
#include <QDebug>
#include "point.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showFileInfoList(QFileInfoList list);



private slots:
    void on_Btn_del_clicked();

    void on_Btn_OK_clicked();

private:
    Ui::MainWindow *ui;

};

extern Zuobiao Z;

#endif // MAINWINDOW_H
