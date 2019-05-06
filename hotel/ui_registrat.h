/********************************************************************************
** Form generated from reading UI file 'registrat.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRAT_H
#define UI_REGISTRAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Registrat
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *roomIdLabel;
    QLabel *roomIdLabel_2;
    QLineEdit *roomIdEdit_3;
    QLabel *roomIdLabel_3;
    QLineEdit *roomIdEdit_4;
    QLabel *roomIdLabel_4;
    QLineEdit *roomIdEdit_5;
    QLabel *roomIdLabel_5;
    QRadioButton *radioButton;
    QLabel *label;
    QLineEdit *roomIdEdit_2;
    QLineEdit *roomIdEdit;
    QCalendarWidget *calendarWidget;
    QLabel *label_2;

    void setupUi(QDialog *Registrat)
    {
        if (Registrat->objectName().isEmpty())
            Registrat->setObjectName(QStringLiteral("Registrat"));
        Registrat->resize(749, 522);
        buttonBox = new QDialogButtonBox(Registrat);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(610, 430, 111, 81));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        roomIdLabel = new QLabel(Registrat);
        roomIdLabel->setObjectName(QStringLiteral("roomIdLabel"));
        roomIdLabel->setGeometry(QRect(100, 140, 53, 21));
        roomIdLabel_2 = new QLabel(Registrat);
        roomIdLabel_2->setObjectName(QStringLiteral("roomIdLabel_2"));
        roomIdLabel_2->setGeometry(QRect(70, 180, 75, 21));
        roomIdEdit_3 = new QLineEdit(Registrat);
        roomIdEdit_3->setObjectName(QStringLiteral("roomIdEdit_3"));
        roomIdEdit_3->setGeometry(QRect(160, 250, 171, 21));
        roomIdLabel_3 = new QLabel(Registrat);
        roomIdLabel_3->setObjectName(QStringLiteral("roomIdLabel_3"));
        roomIdLabel_3->setGeometry(QRect(60, 250, 75, 21));
        roomIdEdit_4 = new QLineEdit(Registrat);
        roomIdEdit_4->setObjectName(QStringLiteral("roomIdEdit_4"));
        roomIdEdit_4->setGeometry(QRect(160, 220, 171, 21));
        roomIdLabel_4 = new QLabel(Registrat);
        roomIdLabel_4->setObjectName(QStringLiteral("roomIdLabel_4"));
        roomIdLabel_4->setGeometry(QRect(70, 220, 75, 21));
        roomIdEdit_5 = new QLineEdit(Registrat);
        roomIdEdit_5->setObjectName(QStringLiteral("roomIdEdit_5"));
        roomIdEdit_5->setGeometry(QRect(160, 290, 171, 21));
        roomIdLabel_5 = new QLabel(Registrat);
        roomIdLabel_5->setObjectName(QStringLiteral("roomIdLabel_5"));
        roomIdLabel_5->setGeometry(QRect(70, 290, 75, 21));
        radioButton = new QRadioButton(Registrat);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(130, 30, 115, 19));
        label = new QLabel(Registrat);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 72, 15));
        roomIdEdit_2 = new QLineEdit(Registrat);
        roomIdEdit_2->setObjectName(QStringLiteral("roomIdEdit_2"));
        roomIdEdit_2->setGeometry(QRect(160, 180, 171, 21));
        roomIdEdit = new QLineEdit(Registrat);
        roomIdEdit->setObjectName(QStringLiteral("roomIdEdit"));
        roomIdEdit->setGeometry(QRect(160, 140, 171, 21));
        calendarWidget = new QCalendarWidget(Registrat);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(390, 20, 341, 291));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setNavigationBarVisible(false);
        calendarWidget->setDateEditEnabled(true);
        label_2 = new QLabel(Registrat);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 330, 241, 121));

        retranslateUi(Registrat);
        QObject::connect(buttonBox, SIGNAL(accepted()), Registrat, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Registrat, SLOT(reject()));

        QMetaObject::connectSlotsByName(Registrat);
    } // setupUi

    void retranslateUi(QDialog *Registrat)
    {
        Registrat->setWindowTitle(QApplication::translate("Registrat", "Dialog", Q_NULLPTR));
        roomIdLabel->setText(QApplication::translate("Registrat", "\346\210\277\351\227\264\345\217\267:", Q_NULLPTR));
        roomIdLabel_2->setText(QApplication::translate("Registrat", "\346\210\277\351\227\264\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        roomIdLabel_3->setText(QApplication::translate("Registrat", "  \347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        roomIdLabel_4->setText(QApplication::translate("Registrat", " \350\272\253\344\273\275\350\257\201\357\274\232", Q_NULLPTR));
        roomIdLabel_5->setText(QApplication::translate("Registrat", " \347\224\265\350\257\235\345\217\267: ", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Registrat", "RadioButton", Q_NULLPTR));
        label->setText(QApplication::translate("Registrat", "\346\230\257\345\220\246\351\242\204\345\256\232\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Registrat", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Registrat: public Ui_Registrat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRAT_H
