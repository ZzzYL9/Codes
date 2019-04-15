#include "change_food_info.h"
#include "ui_change_food_info.h"

#include <QtGui>
#include <QTableWidget>
#include <QMessageBox>
//#include <QDateTime>
//#include <QDate>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractItemView>
#include <QRegExp>
#include <QRegExpValidator>

change_food_info::change_food_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_food_info)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();

    setAttribute(Qt::WA_DeleteOnClose);

    QRegExp regx("[0-9]+$");
    QRegExpValidator* validator = new QRegExpValidator(regx, this);
    ui->lineEdit_2->setValidator(validator);
}

change_food_info::~change_food_info()
{
    delete ui;
}

void change_food_info::on_pushButton_clicked()
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
       query.prepare("update food_info set  foodPrice = :foodPrice where foodName=:foodName");
        query.bindValue(":foodName",foodName);
        query.bindValue(":foodPrice",food_price);

        if (query.exec())
            QMessageBox::information(this, tr("恭喜"), tr("菜品价格修改成功!"));
        this->close();

        main_window = new MainWindow;
        main_window->show();
    }
}

void change_food_info::on_pushButton_2_clicked()
{
    this->close();
    main_window = new MainWindow;
    main_window->show();

}
