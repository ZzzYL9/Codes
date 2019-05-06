#ifndef REBOOK_H
#define REBOOK_H

#include <QDialog>
#include<database.h>
namespace Ui {
class ReBook;
}

class ReBook : public QDialog
{
    Q_OBJECT

public:
    explicit ReBook(QWidget *parent = 0);
    ReBook(DataBase *db,QString bookNo,QString roomPrice,QString roomType,bool isDebet,QWidget *parent=0);
    //void paintEvent(QPaintEvent *);
    bool   yesOrNo;
    ~ReBook();
signals:
    void rebook(bool yesOrNo);


private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_dayNumsBox_currentIndexChanged(int index);



    void on_buttonBox_accepted();
private:
    Ui::ReBook *ui;
    DataBase *m_db;

};

#endif // REBOOK_H
