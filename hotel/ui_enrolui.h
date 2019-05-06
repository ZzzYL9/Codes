/********************************************************************************
** Form generated from reading UI file 'enrolui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENROLUI_H
#define UI_ENROLUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enrolUi
{
public:
    QLabel *labelNameEdit;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *phoneNumEdit;
    QLabel *label_3;
    QLineEdit *idEdit;
    QLineEdit *pawEdit;
    QLineEdit *btnpwdEdit;
    QLineEdit *idcardEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *IdcardLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okBtn;
    QPushButton *cancleBtn;

    void setupUi(QDialog *enrolUi)
    {
        if (enrolUi->objectName().isEmpty())
            enrolUi->setObjectName(QStringLiteral("enrolUi"));
        enrolUi->resize(485, 545);
        enrolUi->setStyleSheet(QLatin1String("QWidget{background-color: rgb(111, 168, 130);}\n"
"\n"
"QPushButton{\n"
"	border:2px groove gray;\n"
"	border-radius:10px;\n"
"	padding:4px;\n"
"	border-style:inset;}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(199, 199, 186);\n"
"}\n"
"\n"
"QLineEdit{background-color: rgb(251, 255, 248);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:gray;\n"
"padding:3px;}\n"
"\n"
"\n"
""));
        labelNameEdit = new QLabel(enrolUi);
        labelNameEdit->setObjectName(QStringLiteral("labelNameEdit"));
        labelNameEdit->setGeometry(QRect(30, 30, 441, 71));
        labelNameEdit->setStyleSheet(QStringLiteral("font: 32pt \"Bahnschrift SemiLight SemiConde\";"));
        layoutWidget_2 = new QWidget(enrolUi);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(100, 130, 251, 231));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameEdit = new QLineEdit(layoutWidget_2);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        phoneNumEdit = new QLineEdit(layoutWidget_2);
        phoneNumEdit->setObjectName(QStringLiteral("phoneNumEdit"));
        phoneNumEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(phoneNumEdit, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        idEdit = new QLineEdit(layoutWidget_2);
        idEdit->setObjectName(QStringLiteral("idEdit"));
        idEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(idEdit, 2, 1, 1, 1);

        pawEdit = new QLineEdit(layoutWidget_2);
        pawEdit->setObjectName(QStringLiteral("pawEdit"));
        pawEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pawEdit, 3, 1, 1, 1);

        btnpwdEdit = new QLineEdit(layoutWidget_2);
        btnpwdEdit->setObjectName(QStringLiteral("btnpwdEdit"));
        btnpwdEdit->setStyleSheet(QStringLiteral(""));
        btnpwdEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(btnpwdEdit, 4, 1, 1, 1);

        idcardEdit = new QLineEdit(layoutWidget_2);
        idcardEdit->setObjectName(QStringLiteral("idcardEdit"));
        idcardEdit->setStyleSheet(QStringLiteral(""));
        idcardEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(idcardEdit, 5, 1, 1, 1);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        IdcardLabel = new QLabel(layoutWidget_2);
        IdcardLabel->setObjectName(QStringLiteral("IdcardLabel"));

        gridLayout->addWidget(IdcardLabel, 5, 0, 1, 1);

        widget = new QWidget(enrolUi);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(110, 390, 241, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        okBtn = new QPushButton(widget);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(okBtn);

        cancleBtn = new QPushButton(widget);
        cancleBtn->setObjectName(QStringLiteral("cancleBtn"));
        cancleBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(cancleBtn);


        retranslateUi(enrolUi);

        QMetaObject::connectSlotsByName(enrolUi);
    } // setupUi

    void retranslateUi(QDialog *enrolUi)
    {
        enrolUi->setWindowTitle(QApplication::translate("enrolUi", "Dialog", Q_NULLPTR));
        labelNameEdit->setText(QApplication::translate("enrolUi", " \350\215\243\345\215\216\345\215\260\350\261\241\345\221\230\345\267\245\346\263\250\345\206\214\347\225\214\351\235\242", Q_NULLPTR));
        label->setText(QApplication::translate("enrolUi", "\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("enrolUi", "\347\224\265\350\257\235", Q_NULLPTR));
        label_3->setText(QApplication::translate("enrolUi", "\350\264\246\345\217\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("enrolUi", "\345\257\206\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("enrolUi", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        IdcardLabel->setText(QApplication::translate("enrolUi", "\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201", Q_NULLPTR));
        okBtn->setText(QApplication::translate("enrolUi", "\347\241\256\350\256\244\346\263\250\345\206\214", Q_NULLPTR));
        cancleBtn->setText(QApplication::translate("enrolUi", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enrolUi: public Ui_enrolUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENROLUI_H
