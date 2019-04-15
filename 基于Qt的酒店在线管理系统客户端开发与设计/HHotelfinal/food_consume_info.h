#ifndef FOOD_CONSUME_INFO_H
#define FOOD_CONSUME_INFO_H

#include <QDialog>

namespace Ui {
class food_consume_info;
}

class food_consume_info : public QDialog
{
    Q_OBJECT

public:
    explicit food_consume_info(QWidget *parent = 0);
    ~food_consume_info();

private:
    Ui::food_consume_info *ui;
};

#endif // FOOD_CONSUME_INFO_H
