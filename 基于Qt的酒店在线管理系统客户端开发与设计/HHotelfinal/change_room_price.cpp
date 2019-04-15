#include "change_room_price.h"
#include "ui_change_room_price.h"

#include <QtGui>
#include <QTableWidget>
#include <QMessageBox>
//#include <QDateTime>
//#include <QDate>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractItemView>


change_room_price::change_room_price(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_room_price)
{
    ui->setupUi(this);
    tid = 0;
    ui->lineEdit->setFocus();

    setAttribute(Qt::WA_DeleteOnClose);
}

change_room_price::~change_room_price()
{
    delete ui;
}

void change_room_price::on_pushButton_clicked()
{
    if (tid != 1 && tid != 2 && tid != 3 && tid != 4 && tid != 5 && tid != 6)
        QMessageBox::warning(this, tr("警告"), tr("请选择修改的房间类型!"));
    else
    {
        QString str = ui->lineEdit->text();
        int price = str.toInt();
        QSqlQuery query;
        query.prepare("update roomtype set  roomtype.price = :price where tid=:tid");
        query.bindValue(":tid", tid);
        query.bindValue(":price", price);
        if (query.exec())
            QMessageBox::information(this, tr("恭喜"), tr("房间价格修改成功!"));
        this->close();

        main_window = new MainWindow;
        main_window->show();

    }
}

void change_room_price::on_radioButton_clicked()
{
    tid = 1;
}

void change_room_price::on_radioButton_2_clicked()
{
    tid = 2;
}

void change_room_price::on_radioButton_3_clicked()
{
    tid = 3;
}

void change_room_price::on_radioButton_4_clicked()
{
    tid = 4;
}

void change_room_price::on_radioButton_5_clicked()
{
    tid = 5;
}

void change_room_price::on_radioButton_6_clicked()
{
    tid = 6;
}

void change_room_price::on_pushButton_2_clicked()
{
    this->close();
    main_window = new MainWindow;
    main_window->show();

}
