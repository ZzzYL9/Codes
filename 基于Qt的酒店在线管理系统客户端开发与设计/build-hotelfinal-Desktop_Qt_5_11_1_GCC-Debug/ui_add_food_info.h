/********************************************************************************
** Form generated from reading UI file 'add_food_info.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_FOOD_INFO_H
#define UI_ADD_FOOD_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add_food_info
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *add_food_info)
    {
        if (add_food_info->objectName().isEmpty())
            add_food_info->setObjectName(QStringLiteral("add_food_info"));
        add_food_info->resize(379, 274);
        add_food_info->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        label = new QLabel(add_food_info);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 331, 51));
        label->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 14pt \"Ubuntu\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        label_2 = new QLabel(add_food_info);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 71, 31));
        label_2->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Ubuntu\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        label_3 = new QLabel(add_food_info);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 140, 71, 31));
        label_3->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Ubuntu\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        lineEdit = new QLineEdit(add_food_info);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 80, 171, 31));
        lineEdit->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);\n"
""));
        lineEdit_2 = new QLineEdit(add_food_info);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 140, 171, 27));
        lineEdit_2->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        pushButton = new QPushButton(add_food_info);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 200, 111, 31));
        pushButton->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(add_food_info);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 200, 111, 31));
        pushButton_2->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(add_food_info);

        QMetaObject::connectSlotsByName(add_food_info);
    } // setupUi

    void retranslateUi(QDialog *add_food_info)
    {
        add_food_info->setWindowTitle(QApplication::translate("add_food_info", "Dialog", nullptr));
        label->setText(QApplication::translate("add_food_info", "    \346\267\273  \345\212\240  \350\217\234  \345\223\201", nullptr));
        label_2->setText(QApplication::translate("add_food_info", " \350\217\234 \345\220\215", nullptr));
        label_3->setText(QApplication::translate("add_food_info", " \344\273\267 \346\240\274", nullptr));
        pushButton->setText(QApplication::translate("add_food_info", "\347\241\256  \350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("add_food_info", "\350\277\224  \345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_food_info: public Ui_add_food_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_FOOD_INFO_H
