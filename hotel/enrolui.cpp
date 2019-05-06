#include "enrolui.h"
#include "ui_enrolui.h"

enrolUi::enrolUi(DataBase *db,QWidget *parent) :
    m_db(db),
    QDialog(parent),
    ui(new Ui::enrolUi)
{
    ui->setupUi(this);
}

enrolUi::~enrolUi()
{
    delete ui;
}


void enrolUi::on_okBtn_clicked()
{
    if(ui->nameEdit->text()==""||ui->phoneNumEdit->text()==""||ui->idEdit->text()==""||ui->pawEdit->text()==""||ui->btnpwdEdit->text()==""||ui->idcardEdit->text()=="")
    {
        QMessageBox::warning(this,"警告","所填入注册信息不能为空 请重新填写!");
    }
    else
    {
        if(ui->pawEdit->text()!=ui->btnpwdEdit->text())
        {
             QMessageBox::warning(this,"警告","所填入密码不一致 请重新填写!");
        }
        else
        {
            m_db->DB_add(ui->idEdit->text(),ui->nameEdit->text(),ui->pawEdit->text(),ui->idcardEdit->text(),ui->phoneNumEdit->text());
            this->close();
        }
    }

}

void enrolUi::on_cancleBtn_clicked()
{
    this->close();
}
