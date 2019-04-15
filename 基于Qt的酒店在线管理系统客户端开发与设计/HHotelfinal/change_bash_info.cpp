#include "change_bash_info.h"
#include "ui_change_bash_info.h"


#include <QtGui>
#include <QTableWidget>
#include <QMessageBox>
//#include <QDateTime>
//#include <QDate>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractItemView>

change_bash_info::change_bash_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_bash_info)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

change_bash_info::~change_bash_info()
{
    delete ui;
}

void change_bash_info::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "")
    {
        QMessageBox::warning(this, tr("警告"), tr("信息输入不能为空！"));
        return;
    }
    QString bashName = ui->lineEdit->text();
    QString str = ui->lineEdit_2->text();
    int price = str.toInt();
    QSqlQuery query;
    query.prepare("update bash_type set  bashPrice = :price where bashName=:bashName");
    query.bindValue(":bashName", bashName);
    query.bindValue(":bashPrice", price);
    if (query.exec())
        QMessageBox::information(this, tr("恭喜"), tr("修改洗浴价格成功!"));
    this->close();

    main_window = new MainWindow;
    main_window->show();
}

void change_bash_info::on_pushButton_2_clicked()
{
    this->close();
    main_window = new MainWindow;
    main_window->show();
}
