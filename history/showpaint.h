#ifndef SHOWPAINT_H
#define SHOWPAINT_H

#include <QDialog>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QtGui>

namespace Ui {
class ShowPaint;
}

class ShowPaint : public QDialog
{
    Q_OBJECT

public:
    explicit ShowPaint(QWidget *parent = nullptr);
    ~ShowPaint();

    void Paint(bool flag);
    void Paint_switch(bool flag);


protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

private slots:
    void on_Btn_back_clicked();

    void on_Btn_tem1_clicked();

    void on_Btn_last_clicked();

    void on_Btn_tem2_clicked();

    void on_Btn_next_clicked();

private:
    Ui::ShowPaint *ui;
    QImage image;
};

#endif // SHOWPAINT_H
