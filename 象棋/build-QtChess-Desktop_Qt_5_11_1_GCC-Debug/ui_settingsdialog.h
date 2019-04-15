/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QPushButton *btnApply;
    QPushButton *btnConfirm;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *ledStepTime;
    QLineEdit *ledIpAddr;
    QLineEdit *ledPort;
    QComboBox *cmbGameType;
    QComboBox *cmbCompetitorSide;
    QComboBox *cmbAhead;
    QComboBox *cmbServerOrClient;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(315, 424);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsDialog->setWindowIcon(icon);
        btnApply = new QPushButton(SettingsDialog);
        btnApply->setObjectName(QStringLiteral("btnApply"));
        btnApply->setGeometry(QRect(85, 380, 51, 27));
        btnConfirm = new QPushButton(SettingsDialog);
        btnConfirm->setObjectName(QStringLiteral("btnConfirm"));
        btnConfirm->setGeometry(QRect(150, 380, 51, 27));
        label = new QLabel(SettingsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 61, 21));
        label_2 = new QLabel(SettingsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 61, 21));
        label_3 = new QLabel(SettingsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 61, 21));
        label_4 = new QLabel(SettingsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 180, 61, 21));
        label_5 = new QLabel(SettingsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 180, 71, 21));
        label_6 = new QLabel(SettingsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 280, 61, 21));
        label_7 = new QLabel(SettingsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 230, 61, 21));
        label_8 = new QLabel(SettingsDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 330, 71, 21));
        ledStepTime = new QLineEdit(SettingsDialog);
        ledStepTime->setObjectName(QStringLiteral("ledStepTime"));
        ledStepTime->setGeometry(QRect(100, 180, 131, 27));
        ledIpAddr = new QLineEdit(SettingsDialog);
        ledIpAddr->setObjectName(QStringLiteral("ledIpAddr"));
        ledIpAddr->setGeometry(QRect(100, 280, 131, 27));
        ledPort = new QLineEdit(SettingsDialog);
        ledPort->setObjectName(QStringLiteral("ledPort"));
        ledPort->setGeometry(QRect(100, 330, 131, 27));
        cmbGameType = new QComboBox(SettingsDialog);
        cmbGameType->setObjectName(QStringLiteral("cmbGameType"));
        cmbGameType->setGeometry(QRect(100, 20, 121, 33));
        cmbCompetitorSide = new QComboBox(SettingsDialog);
        cmbCompetitorSide->setObjectName(QStringLiteral("cmbCompetitorSide"));
        cmbCompetitorSide->setGeometry(QRect(100, 70, 81, 33));
        cmbAhead = new QComboBox(SettingsDialog);
        cmbAhead->setObjectName(QStringLiteral("cmbAhead"));
        cmbAhead->setGeometry(QRect(100, 120, 131, 33));
        cmbServerOrClient = new QComboBox(SettingsDialog);
        cmbServerOrClient->setObjectName(QStringLiteral("cmbServerOrClient"));
        cmbServerOrClient->setGeometry(QRect(100, 230, 131, 33));

        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "\346\270\270\346\210\217\350\256\276\347\275\256", nullptr));
        btnApply->setText(QApplication::translate("SettingsDialog", "\345\272\224\347\224\250", nullptr));
        btnConfirm->setText(QApplication::translate("SettingsDialog", "\347\241\256\345\256\232", nullptr));
        label->setText(QApplication::translate("SettingsDialog", "\346\270\270\346\210\217\347\261\273\345\236\213\357\274\232", nullptr));
        label_2->setText(QApplication::translate("SettingsDialog", "\350\260\201\345\205\210\350\265\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("SettingsDialog", "\345\257\271\346\211\213\346\211\247\357\274\232", nullptr));
        label_4->setText(QApplication::translate("SettingsDialog", "\346\255\245\346\227\266\357\274\232", nullptr));
        label_5->setText(QApplication::translate("SettingsDialog", "0\350\241\250\347\244\272\344\270\215\351\231\220\346\227\266", nullptr));
        label_6->setText(QApplication::translate("SettingsDialog", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        label_7->setText(QApplication::translate("SettingsDialog", "\346\234\254\346\234\272\344\270\272\357\274\232", nullptr));
        label_8->setText(QApplication::translate("SettingsDialog", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        ledStepTime->setText(QApplication::translate("SettingsDialog", "3000", nullptr));
        ledIpAddr->setText(QApplication::translate("SettingsDialog", "3000", nullptr));
        ledPort->setText(QApplication::translate("SettingsDialog", "3000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
