#ifndef REGISTRAT_H
#define REGISTRAT_H

#include <QDialog>

namespace Ui {
class Registrat;
}

class Registrat : public QDialog
{
    Q_OBJECT

public:
    explicit Registrat(QWidget *parent = 0);
    ~Registrat();

private:
    Ui::Registrat *ui;
};

#endif // REGISTRAT_H
