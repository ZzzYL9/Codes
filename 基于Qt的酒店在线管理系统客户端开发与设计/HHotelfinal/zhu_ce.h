#ifndef ZHU_CE_H
#define ZHU_CE_H

#include <QDialog>
#include <QButtonGroup>

#include "mainwindow.h"


namespace Ui {
class zhu_ce;
}

class zhu_ce : public QDialog
{
    Q_OBJECT

public:
    explicit zhu_ce(QWidget *parent = 0);
    ~zhu_ce();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::zhu_ce *ui;
    QString sex;
};






#endif // ZHU_CE_H
