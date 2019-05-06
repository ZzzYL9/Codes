#ifndef LOG_DIALOG_H
#define LOG_DIALOG_H

#include <QDialog>

namespace Ui {
class log_dialog;
}

class log_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit log_dialog(QWidget *parent = nullptr);
    ~log_dialog();

private slots:
    void on_log_Btn_clicked();

    void on_quit_Btn_clicked();

private:
    Ui::log_dialog *ui;
};

#endif // LOG_DIALOG_H
