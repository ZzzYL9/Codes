#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>
#include"database.h"
namespace Ui {
class checkout;
}

class checkout : public QDialog
{
    Q_OBJECT

public:
    explicit checkout(QWidget *parent = 0);
    explicit checkout(DataBase *db,int roomId,QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
   // checkout();
    ~checkout();
signals:
    void sendCheckInfo(bool yesOrNoz);
private slots:

    void clicked();
    void cancleclicked();


    void on_checkOutBtn_clicked();

    void on_cancleBtn_clicked();

private:
    Ui::checkout *ui;
    DataBase *m_db;
    int m_id;
};


#endif // CHECKOUT_H
