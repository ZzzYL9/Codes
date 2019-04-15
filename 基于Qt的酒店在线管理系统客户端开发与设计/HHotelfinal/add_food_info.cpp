#include "add_food_info.h"
#include "ui_add_food_info.h"

#include <QtGui>
#include <QTableWidget>
#include <QMessageBox>
//#include <QDateTime>
//#include <QDate>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractItemView>


add_food_info::add_food_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_food_info)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();

    setAttribute(Qt::WA_DeleteOnClose);
}

add_food_info::~add_food_info()
{
    delete ui;
}

void add_food_info::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "")
    {
        QMessageBox::warning(this, tr("警告"), tr("输入信息不能为空!"));
    }
    else
    {
        QString foodName = ui->lineEdit->text();
        QString foodPrice = ui->lineEdit_2->text();
        int food_price = foodPrice.toInt();

        QSqlQuery query;
        query.prepare("insert into food_info(foodName,foodPrice) values(:foodName,:foodPrice)");
        query.bindValue(":foodName",foodName);
        query.bindValue(":foodPrice",food_price);

        if (query.exec())
            QMessageBox::information(this, tr("恭喜"), tr("添加菜品成功!"));
        this->close();

        main_window = new MainWindow;
        main_window->show();

    }
}

void add_food_info::on_pushButton_2_clicked()
{
    this->close();
    main_window = new MainWindow;
    main_window->show();

}
