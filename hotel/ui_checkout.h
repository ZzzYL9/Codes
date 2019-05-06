/********************************************************************************
** Form generated from reading UI file 'checkout.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUT_H
#define UI_CHECKOUT_H

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

class Ui_checkout
{
public:
    QPushButton *checkOutBtn;
    QPushButton *cancleBtn;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *IdcardLabel;
    QLineEdit *idCardEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *roomIdLabel;
    QLineEdit *roomIdEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *startTime;
    QLineEdit *startTimeEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *endTimeLabel;
    QLineEdit *endTimeEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *quitPriceLabel;
    QLineEdit *quitPriceEdit_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *debetLabel;
    QLineEdit *debtEdit;

    void setupUi(QDialog *checkout)
    {
        if (checkout->objectName().isEmpty())
            checkout->setObjectName(QStringLiteral("checkout"));
        checkout->resize(553, 349);
        checkout->setStyleSheet(QLatin1String("QPushButton{border-width:2px;\n"
"border-color:gray;\n"
"border-radius:10px;\n"
"padding:2px;\n"
"border-style:outset;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(91, 85, 255);\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:gray;\n"
"padding:3px;\n"
"}"));
        checkOutBtn = new QPushButton(checkout);
        checkOutBtn->setObjectName(QStringLiteral("checkOutBtn"));
        checkOutBtn->setGeometry(QRect(270, 300, 93, 28));
        cancleBtn = new QPushButton(checkout);
        cancleBtn->setObjectName(QStringLiteral("cancleBtn"));
        cancleBtn->setGeometry(QRect(370, 300, 93, 28));
        layoutWidget = new QWidget(checkout);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(62, 24, 231, 247));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        horizontalLayout_7->addWidget(nameLabel);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        horizontalLayout_7->addWidget(nameEdit);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        IdcardLabel = new QLabel(layoutWidget);
        IdcardLabel->setObjectName(QStringLiteral("IdcardLabel"));

        horizontalLayout_2->addWidget(IdcardLabel);

        idCardEdit = new QLineEdit(layoutWidget);
        idCardEdit->setObjectName(QStringLiteral("idCardEdit"));

        horizontalLayout_2->addWidget(idCardEdit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        roomIdLabel = new QLabel(layoutWidget);
        roomIdLabel->setObjectName(QStringLiteral("roomIdLabel"));

        horizontalLayout_3->addWidget(roomIdLabel);

        roomIdEdit = new QLineEdit(layoutWidget);
        roomIdEdit->setObjectName(QStringLiteral("roomIdEdit"));

        horizontalLayout_3->addWidget(roomIdEdit);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        startTime = new QLabel(layoutWidget);
        startTime->setObjectName(QStringLiteral("startTime"));

        horizontalLayout_4->addWidget(startTime);

        startTimeEdit = new QLineEdit(layoutWidget);
        startTimeEdit->setObjectName(QStringLiteral("startTimeEdit"));

        horizontalLayout_4->addWidget(startTimeEdit);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        endTimeLabel = new QLabel(layoutWidget);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));

        horizontalLayout_5->addWidget(endTimeLabel);

        endTimeEdit = new QLineEdit(layoutWidget);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));

        horizontalLayout_5->addWidget(endTimeEdit);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        quitPriceLabel = new QLabel(layoutWidget);
        quitPriceLabel->setObjectName(QStringLiteral("quitPriceLabel"));

        horizontalLayout->addWidget(quitPriceLabel);

        quitPriceEdit_2 = new QLineEdit(layoutWidget);
        quitPriceEdit_2->setObjectName(QStringLiteral("quitPriceEdit_2"));

        horizontalLayout->addWidget(quitPriceEdit_2);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        debetLabel = new QLabel(layoutWidget);
        debetLabel->setObjectName(QStringLiteral("debetLabel"));

        horizontalLayout_8->addWidget(debetLabel);

        debtEdit = new QLineEdit(layoutWidget);
        debtEdit->setObjectName(QStringLiteral("debtEdit"));

        horizontalLayout_8->addWidget(debtEdit);


        gridLayout->addLayout(horizontalLayout_8, 6, 0, 1, 1);


        retranslateUi(checkout);

        QMetaObject::connectSlotsByName(checkout);
    } // setupUi

    void retranslateUi(QDialog *checkout)
    {
        checkout->setWindowTitle(QApplication::translate("checkout", "Dialog", Q_NULLPTR));
        checkOutBtn->setText(QApplication::translate("checkout", "\347\273\223\350\264\246", Q_NULLPTR));
        cancleBtn->setText(QApplication::translate("checkout", "\345\217\226\346\266\210", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("checkout", "   \345\247\223 \345\220\215:", Q_NULLPTR));
        IdcardLabel->setText(QApplication::translate("checkout", "  \350\272\253\344\273\275\350\257\201:", Q_NULLPTR));
        roomIdLabel->setText(QApplication::translate("checkout", "  \346\210\277\351\227\264\345\217\267:", Q_NULLPTR));
        startTime->setText(QApplication::translate("checkout", "\345\274\200\345\247\213\346\227\266\351\227\264:", Q_NULLPTR));
        endTimeLabel->setText(QApplication::translate("checkout", "\347\273\223\346\235\237\346\227\266\351\227\264:", Q_NULLPTR));
        quitPriceLabel->setText(QApplication::translate("checkout", "\351\200\200\345\233\236\346\212\274\351\207\221:", Q_NULLPTR));
        debetLabel->setText(QApplication::translate("checkout", "\346\214\202\350\264\246\347\273\223\344\275\231:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class checkout: public Ui_checkout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUT_H
