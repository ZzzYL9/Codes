#ifndef HOTEL_H
#define HOTEL_H

#include <QWidget>
#include"database.h"
#include"mainwindow.h"
namespace Ui {
class Hotel;
}

class Hotel : public QWidget
{
    Q_OBJECT

public:
    explicit Hotel(QWidget *parent = nullptr);
    ~Hotel();
protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_Hotel_customContextMenuRequested(const QPoint &pos);
    void onOutLogin();
    void on_LoginButton_clicked();

    void on_NumberButton_clicked();

private:
    Ui::Hotel *ui;
    DataBase *m_db;
     mainwindow *Main;
};

#endif // HOTEL_H
