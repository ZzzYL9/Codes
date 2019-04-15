#include "food_consume_info.h"
#include "ui_food_consume_info.h"

food_consume_info::food_consume_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::food_consume_info)
{
    ui->setupUi(this);
}

food_consume_info::~food_consume_info()
{
    delete ui;
}
