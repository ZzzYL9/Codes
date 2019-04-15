#include "delete_food_info.h"
#include "ui_delete_food_info.h"

#include <QtGui>
#include <QTableWidget>
#include <QMessageBox>
//#include <QDateTime>
//#include <QDate>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractItemView>


delete_food_info::delete_food_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_food_info)
{
    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);

    model_foodinfo = new QSqlTableModel(this);
    model_foodinfo->setTable("food_info");
    model_foodinfo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_foodinfo->select();
    model_foodinfo->setHeaderData(0,Qt::Horizontal,tr("菜名"));
    model_foodinfo->setHeaderData(1,Qt::Horizontal,tr("价格"));

    ui->tableView->setModel(this->model_foodinfo);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑
}

delete_food_info::~delete_food_info()
{
    delete ui;
}

void delete_food_info::on_pushButton_clicked()
{
    if (ui->lineEdit->text()  == "")
    {
        QMessageBox::warning(this, tr("Warning"), tr("Please input correct information!"));
    }
    else
    {
        QString foodName = ui->lineEdit->text();

        QSqlQuery query;
        query.prepare("delete from food_info where foodName=:foodName");
        query.bindValue(":foodName",foodName);

        if (query.exec())
            QMessageBox::information(this, tr("SUCCESS"), tr("congratulations success!"));
        this->close();

        main_window = new MainWindow;
        main_window->show();

    }
}

void delete_food_info::on_pushButton_2_clicked()
{
    this->close();
    main_window = new MainWindow;
    main_window->show();

}
