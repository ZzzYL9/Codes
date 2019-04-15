/********************************************************************************
** Form generated from reading UI file 'delete_food_info.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_FOOD_INFO_H
#define UI_DELETE_FOOD_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_delete_food_info
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QTableView *tableView;

    void setupUi(QDialog *delete_food_info)
    {
        if (delete_food_info->objectName().isEmpty())
            delete_food_info->setObjectName(QStringLiteral("delete_food_info"));
        delete_food_info->resize(362, 451);
        delete_food_info->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        label = new QLabel(delete_food_info);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 315, 101, 41));
        label->setStyleSheet(QLatin1String("font: 75 11pt \"Agency FB\";\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        lineEdit = new QLineEdit(delete_food_info);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 320, 211, 31));
        lineEdit->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        pushButton = new QPushButton(delete_food_info);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 370, 99, 41));
        pushButton->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(delete_food_info);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 370, 99, 41));
        pushButton_2->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(delete_food_info);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 10, 191, 61));
        label_3->setStyleSheet(QLatin1String("font: 75 14pt \"Agency FB\";\n"
"color: rgb(0, 0, 255);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        tableView = new QTableView(delete_food_info);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 80, 321, 221));
        tableView->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));

        retranslateUi(delete_food_info);

        QMetaObject::connectSlotsByName(delete_food_info);
    } // setupUi

    void retranslateUi(QDialog *delete_food_info)
    {
        delete_food_info->setWindowTitle(QApplication::translate("delete_food_info", "Dialog", nullptr));
        label->setText(QApplication::translate("delete_food_info", "    \350\217\234 \345\220\215", nullptr));
        pushButton->setText(QApplication::translate("delete_food_info", "\347\241\256  \350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("delete_food_info", "\350\277\224  \345\233\236", nullptr));
        label_3->setText(QApplication::translate("delete_food_info", "      \345\210\240   \351\231\244   \350\217\234   \345\223\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_food_info: public Ui_delete_food_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_FOOD_INFO_H
