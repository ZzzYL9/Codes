#ifndef MODIFYPAW_H
#define MODIFYPAW_H

#include <QDialog>

namespace Ui {
class ModifyPaw;
}

class ModifyPaw : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPaw(QWidget *parent = 0);
    ~ModifyPaw();

private:
    Ui::ModifyPaw *ui;
};

#endif // MODIFYPAW_H
