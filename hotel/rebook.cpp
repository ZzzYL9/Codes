#include "rebook.h"
#include "ui_rebook.h"
#include<QDebug>
#include<QMessageBox>
ReBook::ReBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReBook)
{
    ui->setupUi(this);
}

ReBook::ReBook(DataBase *db,QString bookNo, QString roomPrice, QString roomType, bool isDebet, QWidget *parent):
m_db(db),
QDialog(parent),
ui(new Ui::ReBook)
{
ui->setupUi(this);
ui->rooIdEdit->setText(bookNo);
ui->RoomTypeEdit->setText(roomType);
ui->RoomTypeEdit->setEnabled(0);
ui->roomPriceEdit->setText(roomPrice);
ui->RoomTypeEdit->setEnabled(0);
ui->IsDebtBtn->setChecked(isDebet);
if(roomType=="标准单间")
ui->roomImageLabel->setPixmap(QPixmap("://images/bigBed.jpg").scaled(180,100));
else
   ui->roomImageLabel->setPixmap(QPixmap("://images/beautiful.jpg").scaled(180,100));


}
ReBook::~ReBook()
{
    delete ui;
}

void ReBook::on_calendarWidget_clicked(const QDate &date)
{
    ui->startTimeEdit->setText(date.toString("yyyy-MM-dd"));
}

void ReBook::on_dayNumsBox_currentIndexChanged(int index)
{
        QDate endTime;
        QDate Temo=endTime.fromString(ui->startTimeEdit->text(),"yyyy-MM-dd").addDays(index+1);
        ui->endTimeEdit->setText(Temo.toString("yyyy-MM-dd"));

}


void ReBook::on_buttonBox_accepted()
{
    if(ui->userNameEdit->text().isEmpty()||ui->carIdEdit->text().isEmpty()||ui->phoneIdEdit->text().isEmpty()||ui->RoomTypeEdit->text().isEmpty()||ui->roomPriceEdit->text().isEmpty()||ui->startTimeEdit->text().isEmpty(),ui->dayNumsBox->currentText().isEmpty(),ui->endTimeEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"预定登录","信息不能为空",QMessageBox::Ok);
        yesOrNo=0;
    }
    else {
        int days=ui->dayNumsBox->currentText().toInt();
        int yajin=25;
        QString curTime=QDateTime::currentDateTime().toString("yyyy-MM-dd");
        QString status="空闲";
        int isDebt=ui->IsDebtBtn->isChecked();
        if(isDebt==1)
        {
             m_db->DB_guazhang(ui->rooIdEdit->text().toInt(),ui->userNameEdit->text(),ui->carIdEdit->text(),yajin,ui->phoneIdEdit->text(),ui->RoomTypeEdit->text(),ui->roomPriceEdit->text().toInt(),status,curTime,ui->startTimeEdit->text(),ui->endTimeEdit->text(),days);
        }

         m_db->DB_order(ui->rooIdEdit->text().toInt(),ui->userNameEdit->text(),ui->carIdEdit->text(),ui->roomPriceEdit->text().toInt(),ui->phoneIdEdit->text(),ui->RoomTypeEdit->text(),ui->roomPriceEdit->text().toInt(),status,curTime,ui->startTimeEdit->text(),ui->endTimeEdit->text(),days,curTime);
         yesOrNo=1;
         emit rebook(1);

    }
}
