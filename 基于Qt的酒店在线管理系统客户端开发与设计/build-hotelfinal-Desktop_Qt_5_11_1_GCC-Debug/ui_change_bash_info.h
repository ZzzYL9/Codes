/********************************************************************************
** Form generated from reading UI file 'change_bash_info.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_BASH_INFO_H
#define UI_CHANGE_BASH_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_change_bash_info
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;

    void setupUi(QDialog *change_bash_info)
    {
        if (change_bash_info->objectName().isEmpty())
            change_bash_info->setObjectName(QStringLiteral("change_bash_info"));
        change_bash_info->resize(379, 274);
        change_bash_info->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        label = new QLabel(change_bash_info);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 80, 71, 31));
        label->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/shuijing.jpg);\n"
"font: 75 11pt \"Agency FB\";\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(change_bash_info);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 140, 71, 31));
        label_2->setStyleSheet(QLatin1String("font: 75 11pt \"Agency FB\";\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        lineEdit = new QLineEdit(change_bash_info);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 80, 171, 31));
        lineEdit->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        lineEdit_2 = new QLineEdit(change_bash_info);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 140, 171, 31));
        lineEdit_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        pushButton = new QPushButton(change_bash_info);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 200, 111, 31));
        pushButton->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(change_bash_info);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 200, 111, 31));
        pushButton_2->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(change_bash_info);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 20, 181, 41));
        label_3->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"font: 75 14pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));

        retranslateUi(change_bash_info);

        QMetaObject::connectSlotsByName(change_bash_info);
    } // setupUi

    void retranslateUi(QDialog *change_bash_info)
    {
        change_bash_info->setWindowTitle(QApplication::translate("change_bash_info", "Dialog", nullptr));
        label->setText(QApplication::translate("change_bash_info", "\346\264\227\346\265\264\347\261\273\345\236\213", nullptr));
        label_2->setText(QApplication::translate("change_bash_info", "\346\264\227\346\265\264\344\273\267\346\240\274", nullptr));
        pushButton->setText(QApplication::translate("change_bash_info", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("change_bash_info", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QApplication::translate("change_bash_info", "\344\277\256 \346\224\271 \346\264\227 \346\265\264 \344\273\267 \346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change_bash_info: public Ui_change_bash_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_BASH_INFO_H
