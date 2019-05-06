#include "modifypaw.h"
#include "ui_modifypaw.h"

ModifyPaw::ModifyPaw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyPaw)
{
    ui->setupUi(this);
}

ModifyPaw::~ModifyPaw()
{
    delete ui;
}
