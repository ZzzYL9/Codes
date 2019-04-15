#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
    void updateDialog();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void apply();
    void confirm();
    void serverOrClientChange(int index);

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
