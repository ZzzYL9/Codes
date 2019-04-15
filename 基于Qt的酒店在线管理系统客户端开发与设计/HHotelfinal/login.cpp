/********************************************************************************
* File Name:	login.cpp
* Description:	第6章实例训练
* Reference book:《Linux环境下Qt4图形界面与MySQL编程》，机械工业出版社.2012.1
* E_mail: openlinux2011@gmail.com
*
********************************************************************************/
#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "chgpwd.h"
#include "zhu_ce.h"

#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtGui>
#include <QPalette>
#include<QSettings>
#include <QCompleter>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    setAttribute(Qt::WA_DeleteOnClose);

    this->setObjectName("myWindow");//窗口背景不影响子控件，另外在样式表中还需要加东西
    ui->setupUi(this);
    ui->leUid->setPlaceholderText(QStringLiteral("帐号"));
    ui->lePwd->setPlaceholderText(QStringLiteral("密码"));
    ui->leUid->setFocus();
    ui->label->close();

    //QPushButton设置自体颜色
    QPalette   pal;
     pal.setColor(QPalette::ButtonText, QColor(0,0,255));
     ui->pbChgpwd->setPalette(pal);
     ui->pbQuit->setPalette(pal);

     //QPushButton设置控件无边框
    ui->pbChgpwd->setStyleSheet("border:none;");
    ui->pbQuit->setStyleSheet("border:none;");
    //ui->pushButton->setStyleSheet("border:none;");

    //ui->pbLogin->setStyleSheet("{background-color:transparent}");//透明色，原色

    //ui->label_4->setPixmap(":/new/prefix1/head.jpg");
    QObject::connect(ui->lePwd, SIGNAL(returnPressed()), this, SLOT(on_pbLogin_clicked()));
    if (ui->checkBox->isChecked())
    {
        ui->leUid->setText("select sid from staff");
        ui->lePwd->setText("select pwd from staff");
    }

}

login::~login()
{
    delete ui;
}

void login::on_pbLogin_clicked()
{
    if(ui->leUid->text().isEmpty()||
       ui->lePwd->text().isEmpty())
    {
        QMessageBox::information(this,tr("提示"),tr("请输入完整信息"),QMessageBox::Ok);
        return;
    }
    QString sid=ui->leUid->text();
    QString pwd=ui->lePwd->text();
    QSqlQuery query;
    query.prepare("select * from staff where sid=:sid and pwd=:pwd");
    query.bindValue(":sid", sid);
    query.bindValue(":pwd", pwd);
    query.exec();
    if(query.next())
    {
        MainWindow *w=new MainWindow();
        w->show();
        this->hide();
    }
    else
    {
        ui->label->show();
        ui->leUid->clear();
        ui->lePwd->clear();
        ui->leUid->setFocus();
    }
}

void login::on_pbChgpwd_clicked()
{
    this->close();
    chgpwd *c=new chgpwd();
    c->show(); 
}

void login::on_pbQuit_clicked()//注册账号
{
    this->close();
    zhu_ce *zhuce = new zhu_ce;
    zhuce->show();
}


void login::on_leUid_editingFinished()
{
    ui->label->close();
}

void login::on_pushButton_clicked()//密码小眼睛
{
    static int i = 0;
    i++;
    if (i % 2)
    {
        ui->lePwd->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lePwd->setEchoMode(QLineEdit::Password);
    }
}
