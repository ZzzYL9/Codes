#include "log_dialog.h"
#include "ui_log_dialog.h"
#include "mainwindow.h"
#include <QMessageBox>

log_dialog::log_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log_dialog)
{
    ui->setupUi(this);


}

log_dialog::~log_dialog()
{
    delete ui;
}

void log_dialog::on_log_Btn_clicked()
{
    MainWindow *M = new MainWindow;
    QString user = "root";
    QString pwd = "root";
    QString user_get;
    QString pwd_get;
    user_get = ui->user_edi->text();
    pwd_get = ui->pwd_edi->text();
    if(user == user_get&&pwd == pwd_get){
        QMessageBox::information(this,"",tr("登录成功"));
        M->show();
        this->close();
    }else {
        QMessageBox::information(this,"",tr("账号或密码错误"));
    }
}

void log_dialog::on_quit_Btn_clicked()
{
    this->close();
}
