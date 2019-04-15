/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_2;
    QLineEdit *leUid;
    QLabel *label_3;
    QLineEdit *lePwd;
    QPushButton *pbLogin;
    QPushButton *pbQuit;
    QPushButton *pbChgpwd;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(427, 272);
        login->setStyleSheet(QStringLiteral("QMainWindow#myWindow{border-image: url(:/new/prefix1/login.jpg);}"));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 73, 104, 104));
        label_4->setMinimumSize(QSize(104, 104));
        label_4->setMaximumSize(QSize(104, 104));
        label_4->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/head.jpg);"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(130, 160, 97, 22));
        checkBox->setStyleSheet(QStringLiteral(""));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(250, 160, 97, 22));
        checkBox_2->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 74, 60, 20));
        label_2->setStyleSheet(QStringLiteral(""));
        leUid = new QLineEdit(centralwidget);
        leUid->setObjectName(QStringLiteral("leUid"));
        leUid->setGeometry(QRect(200, 70, 146, 27));
        leUid->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 114, 45, 20));
        label_3->setStyleSheet(QStringLiteral(""));
        lePwd = new QLineEdit(centralwidget);
        lePwd->setObjectName(QStringLiteral("lePwd"));
        lePwd->setGeometry(QRect(200, 110, 146, 27));
        lePwd->setStyleSheet(QStringLiteral(""));
        lePwd->setEchoMode(QLineEdit::Password);
        pbLogin = new QPushButton(centralwidget);
        pbLogin->setObjectName(QStringLiteral("pbLogin"));
        pbLogin->setGeometry(QRect(130, 200, 217, 30));
        pbLogin->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/denglu.jpg);"));
        pbQuit = new QPushButton(centralwidget);
        pbQuit->setObjectName(QStringLiteral("pbQuit"));
        pbQuit->setGeometry(QRect(350, 110, 66, 27));
        pbQuit->setMinimumSize(QSize(66, 27));
        pbQuit->setMaximumSize(QSize(66, 27));
        pbQuit->setStyleSheet(QStringLiteral(""));
        pbChgpwd = new QPushButton(centralwidget);
        pbChgpwd->setObjectName(QStringLiteral("pbChgpwd"));
        pbChgpwd->setGeometry(QRect(350, 70, 66, 27));
        pbChgpwd->setMinimumSize(QSize(66, 27));
        pbChgpwd->setMaximumSize(QSize(66, 27));
        pbChgpwd->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(246, 140, 111, 17));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(322, 113, 21, 21));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/eye88.png);"));
        login->setCentralWidget(centralwidget);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "MainWindow", nullptr));
        label_4->setText(QString());
        checkBox->setText(QApplication::translate("login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QApplication::translate("login", "\350\207\252\345\212\250\347\231\273\351\231\206", nullptr));
        label_2->setText(QApplication::translate("login", "\350\201\214\345\267\245\345\217\267", nullptr));
        label_3->setText(QApplication::translate("login", "\345\257\206  \347\240\201", nullptr));
        pbLogin->setText(QString());
        pbQuit->setText(QApplication::translate("login", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        pbChgpwd->setText(QApplication::translate("login", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        label->setText(QApplication::translate("login", "\345\270\220\345\217\267\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
