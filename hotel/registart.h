#ifndef REGISTART_H
#define REGISTART_H

#include <QDialog>
#include"database.h"
namespace Ui {
class registart;
}

class registart : public QDialog
{
    Q_OBJECT

public:
    explicit registart(QWidget *parent = 0);
    registart(DataBase *db,QString bookNo, QString roomPrice, QString roomType,QWidget *parent=0);
    void paintEvent(QPaintEvent *);
    ~registart();
signals:
    void sendRegist(bool yesOrNo);
private slots:
    void on_querryBtn_clicked();

private:
    Ui::registart *ui;
    QString m_bookNo;
    QString m_roomPrice;
    QString m_roomType;
    DataBase *m_db;
};

#endif // REGISTART_H
