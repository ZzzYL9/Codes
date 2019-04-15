#include "select_food_info.h"
#include "ui_select_food_info.h"

#include <QtGui>
#include <QTableWidget>
#include <QMessageBox>
//#include <QDateTime>
//#include <QDate>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractItemView>


select_food_info::select_food_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select_food_info)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

select_food_info::~select_food_info()
{
    delete ui;
}

void select_food_info::on_pushButton_clicked()
{
      QSqlQuery query;
      QString foodName = ui->lineEdit->text();

      if (ui->lineEdit->text() == "" )
      {
          QMessageBox::warning(this, tr("Warning"), tr("Please input correct information!"));
          return;
      }
      query.exec("select * from food_info where foodName="+foodName);
       if (query.size() != 0)
      {
           model_foodinfo = new QSqlTableModel(this);
           model_foodinfo->setTable("food_info");
           model_foodinfo->setEditStrategy(QSqlTableModel::OnManualSubmit);

           model_foodinfo->setFilter(QObject::tr("foodName = '%1'").arg(foodName));
           model_foodinfo->select();
           model_foodinfo->setHeaderData(0,Qt::Horizontal,tr("菜名"));
           model_foodinfo->setHeaderData(1,Qt::Horizontal,tr("价格"));

           ui->tableView->setModel(this->model_foodinfo);
           ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑
      }
      else
      {
            QMessageBox::warning(this, tr("警告"), tr("None Record!"));
      }
      ui->tableView->clearFocus();
}

void select_food_info::on_pushButton_2_clicked()
{
    this->close();
    main_window = new MainWindow;
    main_window->show();
}
