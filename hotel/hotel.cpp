#include "hotel.h"
#include "ui_hotel.h"
#include <QPainter>
#include<registart.h>
#include<enrolui.h>
Hotel::Hotel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hotel)
{
    ui->setupUi(this);
    m_db=new DataBase("test.sql");
}

Hotel::~Hotel()
{
    delete ui;
}

void Hotel::on_Hotel_customContextMenuRequested(const QPoint &pos)
{

}

void Hotel::onOutLogin()
{
    Main->deleteLater();
    this->show();

}

void Hotel::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("://images/login3.jpg"));
    p.end();
}

void Hotel::on_LoginButton_clicked()
{
    QString id=ui->UserIdEdit->text();
    QString paw=ui->PasswordEdit->text();
    if(id.isEmpty()||paw.isEmpty())
        QMessageBox::warning(this,tr("警告"),"所填信息不能为空");
    QString name;
    int zs,  tf,  yj, tsjiezhang, yd_find,dj_find, ts_find, baobiao=0;
    bool ok=m_db->DB_log(id,paw,name,zs,tf,yj,tsjiezhang,yd_find,dj_find,ts_find,baobiao);
    if(ok)
    {
       Main=new mainwindow(m_db);
       this->hide();
       connect(Main,&mainwindow::sendOutLogin,this,&Hotel::onOutLogin);
       Main->show();
    }
    else
    {
          QMessageBox::warning(this,tr("警告"),"账户或密码错误",QMessageBox::Yes);
    }



}
void Hotel::on_NumberButton_clicked()
{
    enrolUi *enr=new enrolUi(m_db,this);
    enr->exec();
}
