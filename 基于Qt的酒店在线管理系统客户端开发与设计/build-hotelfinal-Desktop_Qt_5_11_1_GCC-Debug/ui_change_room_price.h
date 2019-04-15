/********************************************************************************
** Form generated from reading UI file 'change_room_price.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_ROOM_PRICE_H
#define UI_CHANGE_ROOM_PRICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_change_room_price
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_6;

    void setupUi(QDialog *change_room_price)
    {
        if (change_room_price->objectName().isEmpty())
            change_room_price->setObjectName(QStringLiteral("change_room_price"));
        change_room_price->resize(388, 345);
        change_room_price->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        label = new QLabel(change_room_price);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 281, 31));
        label->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"font: 75 14pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        lineEdit = new QLineEdit(change_room_price);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 218, 171, 27));
        lineEdit->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        label_2 = new QLabel(change_room_price);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 220, 101, 20));
        label_2->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/shuijing.jpg);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Agency FB\";"));
        pushButton = new QPushButton(change_room_price);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 280, 99, 27));
        pushButton->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(change_room_price);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 280, 99, 27));
        pushButton_2->setStyleSheet(QLatin1String("font: 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/Purple.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        radioButton_2 = new QRadioButton(change_room_price);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(51, 76, 121, 19));
        radioButton_2->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        radioButton = new QRadioButton(change_room_price);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(51, 123, 131, 19));
        radioButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        radioButton_3 = new QRadioButton(change_room_price);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(51, 170, 131, 19));
        radioButton_3->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        radioButton_5 = new QRadioButton(change_room_price);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(210, 76, 131, 19));
        radioButton_5->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        radioButton_4 = new QRadioButton(change_room_price);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(210, 123, 131, 19));
        radioButton_4->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        radioButton_6 = new QRadioButton(change_room_price);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(210, 170, 111, 19));
        radioButton_6->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));

        retranslateUi(change_room_price);

        QMetaObject::connectSlotsByName(change_room_price);
    } // setupUi

    void retranslateUi(QDialog *change_room_price)
    {
        change_room_price->setWindowTitle(QApplication::translate("change_room_price", "Dialog", nullptr));
        label->setText(QApplication::translate("change_room_price", "\350\257\267\351\200\211\346\213\251\344\275\240\350\246\201\344\277\256\346\224\271\347\232\204\346\210\277\351\227\264\347\261\273\345\236\213", nullptr));
        label_2->setText(QApplication::translate("change_room_price", "\350\257\267\350\276\223\345\205\245\344\273\267\346\240\274", nullptr));
        pushButton->setText(QApplication::translate("change_room_price", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QApplication::translate("change_room_price", "\350\277\224\345\233\236", nullptr));
        radioButton_2->setText(QApplication::translate("change_room_price", "\345\225\206\345\212\241\345\245\227\346\210\277", nullptr));
        radioButton->setText(QApplication::translate("change_room_price", "\350\261\252\345\215\216\345\215\225\344\272\272\351\227\264", nullptr));
        radioButton_3->setText(QApplication::translate("change_room_price", "\346\240\207\345\207\206\345\215\225\344\272\272\351\227\264", nullptr));
        radioButton_5->setText(QApplication::translate("change_room_price", "\346\240\207\345\207\206\345\217\214\344\272\272\351\227\264", nullptr));
        radioButton_4->setText(QApplication::translate("change_room_price", "\350\261\252\345\215\216\345\217\214\344\272\272\351\227\264", nullptr));
        radioButton_6->setText(QApplication::translate("change_room_price", "\346\200\273\347\273\237\345\245\227\346\210\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change_room_price: public Ui_change_room_price {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_ROOM_PRICE_H
