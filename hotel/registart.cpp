#include "registart.h"
#include "ui_registart.h"
#include "rebook.h"
#include<QMessageBox>
#include<QPainter>

registart::registart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registart)
{
    ui->setupUi(this);
    ui->roomIdEdit->hide();
    ui->roomIdLabel->hide();
    ui->reserInBtn->hide();
}

registart::registart(DataBase *db,QString bookNo, QString roomPrice, QString roomType, QWidget *parent):m_bookNo(bookNo),m_roomPrice(roomPrice),
    m_db(db),m_roomType(roomType),QDialog(parent),ui(new Ui::registart)
{
    ui->setupUi(this);
    ui->roomIdEdit->hide();
    ui->roomIdLabel->hide();
    ui->reserInBtn->hide();
}

registart::~registart()
{
    delete ui;
}

void registart::on_querryBtn_clicked()
{
   if(!ui->cardIdEdit->text().isEmpty())
   {
       int isreBook=m_db->DB_is_order(ui->cardIdEdit->text(),25);
       if(isreBook!=-1)
       {
           ui->roomIdEdit->setText(QString::number(isreBook));
           ui->roomIdLabel->setText(tr("当前住宿房间为:"));
           ui->roomIdEdit->show();
       ui->roomIdEdit->setEnabled(0);
       ui->roomIdLabel->show();
       ui->reserInBtn->show();
        connect(ui->reserInBtn,&QPushButton::clicked,this,[&](){

            sendRegist(1);
            this->close();
        });
       }
       else
       {
          this->hide();
          ReBook *one=new ReBook(m_db,QString::number(isreBook),m_roomPrice,m_roomType,parent());
        /*
          connect(one,&ReBook::rebook,this,[]()
          {


          });
          */
          if(one->exec()==QDialog::Accepted&&one->yesOrNo==1)
          {

                m_db->DB_is_order(ui->cardIdEdit->text(),25);
                sendRegist(1);
                this->close();
          };
       }

   }
}



void registart::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("://images/registart.jpg"));
    p.end();
}

