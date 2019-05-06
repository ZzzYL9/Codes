#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Paint_init();
    void Paint(int flag);
    void randinit();
    void saveinitfile();
    void savefile();
    void readfile();//读取坐标文件
    void computedegree();
    void computetension();
    void computerepulsion();
    void start_1();
    //读取时刻一的point
    void read_p1();
    //读取时刻一的edge
    void read_d1();
    //读取时刻二的point
    void read_p2();
    //读取边dege1(时刻二)
    void read_d2();
    //读取时刻三的point
    void read_p3();
    //读取边dege2（时刻三）
    void read_d3();

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

private slots:
    void on_one_Btn_clicked();

    void on_two_Btn_clicked();

    void on_three_Btn_clicked();


private:
    Ui::MainWindow *ui;
    QImage image;
};

#endif // MAINWINDOW_H
