/********************************************************************************
** Form generated from reading UI file 'chgpwd.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHGPWD_H
#define UI_CHGPWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chgpwd
{
public:
    QWidget *centralwidget;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *leUid;
    QLineEdit *lePwd;
    QLabel *label_3;
    QLineEdit *leNewPwd;
    QLabel *label_4;
    QLineEdit *leNewPwdcopy;
    QPushButton *pbSubmit;
    QPushButton *pbQuit;

    void setupUi(QMainWindow *chgpwd)
    {
        if (chgpwd->objectName().isEmpty())
            chgpwd->setObjectName(QStringLiteral("chgpwd"));
        chgpwd->resize(490, 365);
        chgpwd->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/about1.jpg);"));
        centralwidget = new QWidget(chgpwd);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 20, 171, 51));
        label_5->setStyleSheet(QLatin1String("font: 75 9pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 90, 111, 31));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 140, 121, 31));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        leUid = new QLineEdit(centralwidget);
        leUid->setObjectName(QStringLiteral("leUid"));
        leUid->setGeometry(QRect(200, 92, 231, 21));
        leUid->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        lePwd = new QLineEdit(centralwidget);
        lePwd->setObjectName(QStringLiteral("lePwd"));
        lePwd->setGeometry(QRect(200, 140, 231, 21));
        lePwd->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        lePwd->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 192, 121, 21));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        leNewPwd = new QLineEdit(centralwidget);
        leNewPwd->setObjectName(QStringLiteral("leNewPwd"));
        leNewPwd->setGeometry(QRect(200, 190, 231, 21));
        leNewPwd->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        leNewPwd->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 238, 121, 31));
        label_4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        leNewPwdcopy = new QLineEdit(centralwidget);
        leNewPwdcopy->setObjectName(QStringLiteral("leNewPwdcopy"));
        leNewPwdcopy->setGeometry(QRect(200, 240, 231, 21));
        leNewPwdcopy->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        leNewPwdcopy->setEchoMode(QLineEdit::Password);
        pbSubmit = new QPushButton(centralwidget);
        pbSubmit->setObjectName(QStringLiteral("pbSubmit"));
        pbSubmit->setGeometry(QRect(160, 297, 121, 41));
        pbSubmit->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        pbQuit = new QPushButton(centralwidget);
        pbQuit->setObjectName(QStringLiteral("pbQuit"));
        pbQuit->setGeometry(QRect(310, 297, 121, 41));
        pbQuit->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        chgpwd->setCentralWidget(centralwidget);

        retranslateUi(chgpwd);

        QMetaObject::connectSlotsByName(chgpwd);
    } // setupUi

    void retranslateUi(QMainWindow *chgpwd)
    {
        chgpwd->setWindowTitle(QApplication::translate("chgpwd", "MainWindow", nullptr));
        label_5->setText(QApplication::translate("chgpwd", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; color:#ca0000;\">\345\257\206\347\240\201\345\217\230\346\233\264\357\274\232</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("chgpwd", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000c7;\">\347\256\241\347\220\206\345\221\230\347\274\226\345\217\267\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("chgpwd", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000c7;\">\350\276\223\345\205\245\346\227\247\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("chgpwd", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000c7;\">\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("chgpwd", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000c7;\">\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        pbSubmit->setText(QApplication::translate("chgpwd", "\347\241\256\350\256\244", nullptr));
        pbQuit->setText(QApplication::translate("chgpwd", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chgpwd: public Ui_chgpwd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHGPWD_H
