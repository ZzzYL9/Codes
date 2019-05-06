/********************************************************************************
** Form generated from reading UI file 'hotel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTEL_H
#define UI_HOTEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hotel
{
public:
    QLabel *label_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *UserIdLabel;
    QLineEdit *UserIdEdit;
    QLabel *PasswordLabel;
    QLineEdit *PasswordEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *LoginButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *NumberButton;

    void setupUi(QWidget *Hotel)
    {
        if (Hotel->objectName().isEmpty())
            Hotel->setObjectName(QStringLiteral("Hotel"));
        Hotel->resize(499, 282);
        Hotel->setMinimumSize(QSize(499, 282));
        Hotel->setMaximumSize(QSize(499, 282));
        Hotel->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(Hotel);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 40, 223, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\255\211\347\272\277"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(Hotel);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 95, 270, 86));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        UserIdLabel = new QLabel(layoutWidget);
        UserIdLabel->setObjectName(QStringLiteral("UserIdLabel"));

        gridLayout->addWidget(UserIdLabel, 0, 0, 1, 1);

        UserIdEdit = new QLineEdit(layoutWidget);
        UserIdEdit->setObjectName(QStringLiteral("UserIdEdit"));

        gridLayout->addWidget(UserIdEdit, 0, 1, 1, 3);

        PasswordLabel = new QLabel(layoutWidget);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        gridLayout->addWidget(PasswordLabel, 1, 0, 1, 1);

        PasswordEdit = new QLineEdit(layoutWidget);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(PasswordEdit, 1, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        LoginButton = new QPushButton(layoutWidget);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(LoginButton, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        NumberButton = new QPushButton(layoutWidget);
        NumberButton->setObjectName(QStringLiteral("NumberButton"));
        NumberButton->setEnabled(true);
        NumberButton->setCursor(QCursor(Qt::ArrowCursor));

        gridLayout->addWidget(NumberButton, 2, 3, 1, 1);


        retranslateUi(Hotel);

        QMetaObject::connectSlotsByName(Hotel);
    } // setupUi

    void retranslateUi(QWidget *Hotel)
    {
        Hotel->setWindowTitle(QApplication::translate("Hotel", "Hotel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Hotel", "\350\215\243\345\215\216\345\215\260\350\261\241\345\256\276\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        UserIdLabel->setText(QApplication::translate("Hotel", "\350\201\214\345\267\245\345\217\267\357\274\232", Q_NULLPTR));
        PasswordLabel->setText(QApplication::translate("Hotel", "\345\257\206  \347\240\201\357\274\232", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("Hotel", "\347\231\273\345\275\225", Q_NULLPTR));
        NumberButton->setText(QApplication::translate("Hotel", "\346\263\250\345\206\214\345\267\245\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Hotel: public Ui_Hotel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTEL_H
