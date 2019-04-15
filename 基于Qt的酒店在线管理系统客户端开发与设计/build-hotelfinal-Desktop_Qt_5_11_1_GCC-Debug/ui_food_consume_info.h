/********************************************************************************
** Form generated from reading UI file 'food_consume_info.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOOD_CONSUME_INFO_H
#define UI_FOOD_CONSUME_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_food_consume_info
{
public:

    void setupUi(QDialog *food_consume_info)
    {
        if (food_consume_info->objectName().isEmpty())
            food_consume_info->setObjectName(QStringLiteral("food_consume_info"));
        food_consume_info->resize(533, 388);

        retranslateUi(food_consume_info);

        QMetaObject::connectSlotsByName(food_consume_info);
    } // setupUi

    void retranslateUi(QDialog *food_consume_info)
    {
        food_consume_info->setWindowTitle(QApplication::translate("food_consume_info", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class food_consume_info: public Ui_food_consume_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOOD_CONSUME_INFO_H
