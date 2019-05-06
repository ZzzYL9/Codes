/********************************************************************************
** Form generated from reading UI file 'enrol.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENROL_H
#define UI_ENROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *enrolButton;
    QPushButton *centerButton;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(576, 434);
        Form->setStyleSheet(QLatin1String("QWidget{background-color: rgb(111, 168, 130);}\n"
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
        label_7 = new QLabel(Form);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 10, 441, 71));
        label_7->setStyleSheet(QStringLiteral("font: 32pt \"Bahnschrift SemiLight SemiConde\";"));
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(380, 370, 141, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        enrolButton = new QPushButton(widget);
        enrolButton->setObjectName(QStringLiteral("enrolButton"));
        enrolButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(enrolButton);

        centerButton = new QPushButton(widget);
        centerButton->setObjectName(QStringLiteral("centerButton"));
        centerButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(centerButton);

        widget1 = new QWidget(Form);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(150, 110, 251, 231));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        lineEdit_5 = new QLineEdit(widget1);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        lineEdit_6 = new QLineEdit(widget1);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 1);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        enrolButton->raise();
        centerButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_5->raise();
        label_6->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        lineEdit_5->raise();
        lineEdit_6->raise();
        label_7->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label_7->setText(QApplication::translate("Form", " \350\215\243\345\215\216\345\215\260\350\261\241\345\221\230\345\267\245\346\263\250\345\206\214\347\225\214\351\235\242", Q_NULLPTR));
        enrolButton->setText(QApplication::translate("Form", "\347\241\256\350\256\244\346\263\250\345\206\214", Q_NULLPTR));
        centerButton->setText(QApplication::translate("Form", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "\347\224\265\350\257\235", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "\350\264\246\345\217\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "\345\257\206\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("Form", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("Form", "\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENROL_H
