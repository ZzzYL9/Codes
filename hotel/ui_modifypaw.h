/********************************************************************************
** Form generated from reading UI file 'modifypaw.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPAW_H
#define UI_MODIFYPAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ModifyPaw
{
public:

    void setupUi(QDialog *ModifyPaw)
    {
        if (ModifyPaw->objectName().isEmpty())
            ModifyPaw->setObjectName(QStringLiteral("ModifyPaw"));
        ModifyPaw->resize(415, 470);

        retranslateUi(ModifyPaw);

        QMetaObject::connectSlotsByName(ModifyPaw);
    } // setupUi

    void retranslateUi(QDialog *ModifyPaw)
    {
        ModifyPaw->setWindowTitle(QApplication::translate("ModifyPaw", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModifyPaw: public Ui_ModifyPaw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPAW_H
