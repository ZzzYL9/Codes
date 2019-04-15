#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "gamesettings.h"
#include "commdef.h"
#include <QStringList>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->btnApply, SIGNAL(clicked()), this, SLOT(apply()));
    connect(ui->btnConfirm, SIGNAL(clicked()), this, SLOT(confirm()));
    connect(ui->cmbServerOrClient, SIGNAL(currentIndexChanged(int)), this, SLOT(serverOrClientChange(int)));
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::updateDialog()
{
    QStringList stringList;

    stringList << "人机对战" << "自由下棋" << "网络对战";
    ui->cmbGameType->addItems(stringList);
    ui->cmbGameType->setCurrentIndex(g_gameSettings.getGameType() - 1);

    stringList.clear();
    stringList << "黑" << "红";
    ui->cmbCompetitorSide->addItems(stringList);
    ui->cmbCompetitorSide->setCurrentIndex(g_gameSettings.getCompetitorSide() - 1);

    stringList.clear();
    stringList << "黑方" << "红方";
    ui->cmbAhead->addItems(stringList);
    ui->cmbAhead->setCurrentIndex(g_gameSettings.getAhead() - 1);

    ui->ledStepTime->setText(QString::number(g_gameSettings.getStepTime(), 10));

    stringList.clear();
    stringList << "客户端" << "服务器端";
    ui->cmbServerOrClient->addItems(stringList);
    ui->cmbServerOrClient->setCurrentIndex(g_gameSettings.getServerOrClient() - 1);

    ui->ledIpAddr->setText(g_gameSettings.getIpAddr());

    ui->ledPort->setText(QString::number(g_gameSettings.getPort(), 10));
}

void SettingsDialog::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void SettingsDialog::apply()
{
    g_gameSettings.setGameType(ui->cmbGameType->currentIndex() + 1);
    g_gameSettings.setCompetitorSide(ui->cmbCompetitorSide->currentIndex() + 1);
    g_gameSettings.setAhead(ui->cmbAhead->currentIndex() + 1);
    g_gameSettings.setStepTime(ui->ledStepTime->text().toInt());
    g_gameSettings.setServerOrClient(ui->cmbServerOrClient->currentIndex() + 1);
    g_gameSettings.setIpAddr(ui->ledIpAddr->text());
    g_gameSettings.setPort(ui->ledPort->text().toInt());
}

void SettingsDialog::confirm()
{
    apply();
    QDialog::accept();
}

void SettingsDialog::serverOrClientChange(int index)
{
    if (index + 1 == SERVER_SIDE)
    {
        ui->ledIpAddr->setText(tr("localhost"));
        ui->ledIpAddr->setEnabled(false);
    }
    else
    {
        ui->ledIpAddr->setEnabled(true);
    }
}
