/********************************************************************************
** Form generated from reading UI file 'registart.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTART_H
#define UI_REGISTART_H

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

class Ui_registart
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cardIdLabel;
    QLineEdit *cardIdEdit;
    QPushButton *querryBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *roomIdLabel;
    QLineEdit *roomIdEdit;
    QPushButton *reserInBtn;

    void setupUi(QDialog *registart)
    {
        if (registart->objectName().isEmpty())
            registart->setObjectName(QStringLiteral("registart"));
        registart->resize(434, 172);
        registart->setStyleSheet(QLatin1String("QPushButton{border-width:2px;\n"
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
        layoutWidget = new QWidget(registart);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 30, 281, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cardIdLabel = new QLabel(layoutWidget);
        cardIdLabel->setObjectName(QStringLiteral("cardIdLabel"));

        horizontalLayout_2->addWidget(cardIdLabel);

        cardIdEdit = new QLineEdit(layoutWidget);
        cardIdEdit->setObjectName(QStringLiteral("cardIdEdit"));

        horizontalLayout_2->addWidget(cardIdEdit);

        querryBtn = new QPushButton(layoutWidget);
        querryBtn->setObjectName(QStringLiteral("querryBtn"));

        horizontalLayout_2->addWidget(querryBtn);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        roomIdLabel = new QLabel(layoutWidget);
        roomIdLabel->setObjectName(QStringLiteral("roomIdLabel"));

        horizontalLayout->addWidget(roomIdLabel);

        roomIdEdit = new QLineEdit(layoutWidget);
        roomIdEdit->setObjectName(QStringLiteral("roomIdEdit"));

        horizontalLayout->addWidget(roomIdEdit);

        reserInBtn = new QPushButton(layoutWidget);
        reserInBtn->setObjectName(QStringLiteral("reserInBtn"));

        horizontalLayout->addWidget(reserInBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(registart);

        QMetaObject::connectSlotsByName(registart);
    } // setupUi

    void retranslateUi(QDialog *registart)
    {
        registart->setWindowTitle(QApplication::translate("registart", "Dialog", Q_NULLPTR));
        cardIdLabel->setText(QApplication::translate("registart", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", Q_NULLPTR));
        querryBtn->setText(QApplication::translate("registart", "\346\237\245\350\257\242", Q_NULLPTR));
        roomIdLabel->setText(QApplication::translate("registart", " \346\210\277\351\227\264\345\217\267 \357\274\232 ", Q_NULLPTR));
        reserInBtn->setText(QApplication::translate("registart", "\347\231\273\350\256\260\345\205\245\344\275\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registart: public Ui_registart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTART_H
