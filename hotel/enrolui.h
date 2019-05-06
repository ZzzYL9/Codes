#ifndef ENROLUI_H
#define ENROLUI_H

#include <QDialog>
#include<database.h>
namespace Ui {
class enrolUi;
}

class enrolUi : public QDialog
{
    Q_OBJECT

public:
    explicit enrolUi(DataBase *db,QWidget *parent = 0);
    ~enrolUi();

private slots:


    void on_okBtn_clicked();

    void on_cancleBtn_clicked();

private:
    Ui::enrolUi *ui;
    DataBase *m_db;
};

#endif // ENROLUI_H
