#include "checkout.h"
#include "ui_checkout.h"
#include <QPainter>

checkout::checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkout)
{
    ui->setupUi(this);
}

checkout::checkout(DataBase *db, int room_id,QWidget *parent): QDialog(parent),
    m_db(db),
    m_id(room_id)
    ,ui(new Ui::checkout)
{
    ui->setupUi(this);
        QString cus_name;
        QString IDcard;
        int yajin;
        int fangfei;
        QString tel;
        QString type;
        int price;
        QString status;
        QString indate;
        QString outdate;
        int days;
        int yesOrNo=0;
    m_db->DB_zhusu_search(room_id, cus_name,IDcard, yajin,fangfei,tel,type,price, status, indate,outdate, days);

    m_db->DB_quit(cus_name,room_id,type,price,indate,outdate,days,fangfei,yesOrNo);

    ui->nameEdit->setText(cus_name);
    ui->idCardEdit->setText(IDcard);
    ui->roomIdEdit->setText(QString::number(room_id));
    ui->startTimeEdit->setText(indate);
    ui->endTimeEdit->setText(outdate);
    ui->quitPriceEdit_2->setText(QString::number(yajin));


    if(yesOrNo==0)
    {
        ui->debtEdit->setText("");
        ui->debtEdit->hide();
        ui->debetLabel->hide();
    }
    else if(yesOrNo==1)
    {
        ui->debtEdit->setText(QString::number(fangfei));
    }

}



checkout::~checkout()
{
    delete ui;
}

void checkout::clicked()
{

    //m_db->DB_quit(ui->nameEdit->text(),ui->roomIdEdit->text().toInt(),ui->roomIdEdit->text(),ui->quitPriceEdit_2->text().toInt(),ui->startTimeEdit->text(),ui->endTimeLabel_2->text(),1,"");
    emit sendCheckInfo(1);
   /*
    this->close();
    QString name;
    int roomid;
    QString type;
    int price;
    QString indate;
    QString outdate;
    int days;
    QString today;
    int total;
    m_db->DB_quit(ui->roomIdEdit->text(),roomid,); */
}

void checkout::cancleclicked()
{
     this->close();
}

void checkout::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("://images/checkout.jpg"));
    p.end();
}


void checkout::on_checkOutBtn_clicked()
{
    QString cus_name;
    QString IDcard;
    int yajin;
    int fangfei;
    QString tel;
    QString type;
    int price;
    QString status;
    QString indate;
    QString outdate;
    int days;
    m_db->DB_zhusu_search(m_id, cus_name,IDcard, yajin,fangfei,tel,type,price, status, indate,outdate, days);
    m_db->DB_quit_log(cus_name,m_id,type,price,indate,outdate,days,outdate,fangfei);
     emit sendCheckInfo(1);
      this->close();
}

void checkout::on_cancleBtn_clicked()
{
    this->close();
}
