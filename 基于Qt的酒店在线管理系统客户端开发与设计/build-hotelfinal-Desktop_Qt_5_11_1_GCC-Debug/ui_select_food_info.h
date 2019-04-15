/********************************************************************************
** Form generated from reading UI file 'select_food_info.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_FOOD_INFO_H
#define UI_SELECT_FOOD_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_select_food_info
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *select_food_info)
    {
        if (select_food_info->objectName().isEmpty())
            select_food_info->setObjectName(QStringLiteral("select_food_info"));
        select_food_info->resize(392, 323);
        select_food_info->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        label = new QLabel(select_food_info);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(35, 10, 351, 51));
        label->setStyleSheet(QLatin1String("font: 75 14pt \"Agency FB\";\n"
"color: rgb(0, 0, 255);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        label_2 = new QLabel(select_food_info);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 84, 121, 41));
        label_2->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Ubuntu\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        lineEdit = new QLineEdit(select_food_info);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 90, 201, 31));
        lineEdit->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        tableView = new QTableView(select_food_info);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 150, 311, 71));
        tableView->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        pushButton = new QPushButton(select_food_info);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 250, 121, 41));
        pushButton->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(select_food_info);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 250, 121, 41));
        pushButton_2->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(select_food_info);

        QMetaObject::connectSlotsByName(select_food_info);
    } // setupUi

    void retranslateUi(QDialog *select_food_info)
    {
        select_food_info->setWindowTitle(QApplication::translate("select_food_info", "Dialog", nullptr));
        label->setText(QApplication::translate("select_food_info", "                   \346\237\245   \350\257\242   \350\217\234   \345\223\201", nullptr));
        label_2->setText(QApplication::translate("select_food_info", "  \350\257\267\350\276\223\345\205\245\350\217\234\345\220\215", nullptr));
        pushButton->setText(QApplication::translate("select_food_info", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("select_food_info", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_food_info: public Ui_select_food_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_FOOD_INFO_H
