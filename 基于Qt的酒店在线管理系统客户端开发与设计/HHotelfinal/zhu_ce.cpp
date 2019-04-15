#include "zhu_ce.h"
#include "ui_zhu_ce.h"


#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "chgpwd.h"


#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtGui>
#include <QPalette>
#include<QSettings>

#include <QDesktopWidget>
#include <QRegExp>
#include <QRegExpValidator>

zhu_ce::zhu_ce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zhu_ce)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    //CheckBox的单项选择,多项是默认的，不用我们管哦！
    QButtonGroup* pButtonGroup = new QButtonGroup(this);
    pButtonGroup->addButton(ui->checkBox,1);
    pButtonGroup->addButton(ui->checkBox_2,2);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);

    QRegExp re("[A-Za-z0-9]+$");//不能输汉字
    QRegExpValidator* rev = new QRegExpValidator(re,this);
    ui->lineEdit->setValidator(rev);
    ui->lineEdit_2->setValidator(rev);
    ui->lineEdit_3->setValidator(rev);
    ui->lineEdit_5->setValidator(rev);
}

zhu_ce::~zhu_ce()
{
    delete ui;
}

void zhu_ce::on_pushButton_clicked()
{
    if (ui->checkBox->isChecked() == false && ui->checkBox_2->isChecked() == false)
    {
        QMessageBox::warning(this, tr("提示"), tr("请选择性别"));
        return;
    }
    if (ui->checkBox->isChecked())
    {
        sex = QString("男");
    }
    if (ui->checkBox_2->isChecked())
    {
        sex = QString("女");
    }
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "" || ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "")
    {
        QMessageBox::warning(this, tr("提示"),tr("信息填写不完整！"));
        return;
    }
    if (ui->lineEdit_2->text() != ui->lineEdit_3->text())
    {
        QMessageBox::warning(this, tr("提示"), tr("两次密码输入不一致！"));
        return;
    }

    QString sid = ui->lineEdit->text();
    QString pwd = ui->lineEdit_2->text();
    QString sname = QString("root");
    QString name = ui->lineEdit_4->text();
    QString age = ui->lineEdit_5->text();


    QSqlQuery query;
    QString str = QString("insert into staff value('%1', '%2', '%3', '%4', '%5', '%6')").arg(sid).arg(sname).arg(pwd).arg(name).arg(sex).arg(age);
    bool ret = query.exec(str);
    if (!ret)
    {
        QMessageBox::warning(this, tr("警告"), tr("该账号已注册！"));
        return;
    }
    else
    {
        QMessageBox::information(this, tr("恭喜"), tr("恭喜您注册成功！"));
        this->close();
        login *log = new login;
        log->show();
        log->move ((QApplication::desktop()->width() - log->width())/2,(QApplication::desktop()->height() - log->height())/2);//登陆窗口居中显示
    }
}

void zhu_ce::on_pushButton_2_clicked()
{
    this->close();
    login *log = new login;
    log->show();
    log->move ((QApplication::desktop()->width() - log->width())/2,(QApplication::desktop()->height() - log->height())/2);//登陆窗口居中显示

}
