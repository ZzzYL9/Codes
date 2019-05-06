/********************************************************************************
** Form generated from reading UI file 'transroom.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSROOM_H
#define UI_TRANSROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transRoom
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *curRoomIdLabel;
    QLineEdit *curRoomIdEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TransRoomLabel;
    QComboBox *TransRoomBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *diffLabel;
    QLineEdit *diffEdit;

    void setupUi(QDialog *transRoom)
    {
        if (transRoom->objectName().isEmpty())
            transRoom->setObjectName(QStringLiteral("transRoom"));
        transRoom->resize(506, 278);
        transRoom->setStyleSheet(QLatin1String("QPushButton{border-width:2px;\n"
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
        buttonBox = new QDialogButtonBox(transRoom);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(transRoom);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 50, 271, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        curRoomIdLabel = new QLabel(layoutWidget);
        curRoomIdLabel->setObjectName(QStringLiteral("curRoomIdLabel"));

        horizontalLayout->addWidget(curRoomIdLabel);

        curRoomIdEdit = new QLineEdit(layoutWidget);
        curRoomIdEdit->setObjectName(QStringLiteral("curRoomIdEdit"));

        horizontalLayout->addWidget(curRoomIdEdit);

        layoutWidget1 = new QWidget(transRoom);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 100, 271, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        TransRoomLabel = new QLabel(layoutWidget1);
        TransRoomLabel->setObjectName(QStringLiteral("TransRoomLabel"));

        horizontalLayout_2->addWidget(TransRoomLabel);

        TransRoomBox = new QComboBox(layoutWidget1);
        TransRoomBox->setObjectName(QStringLiteral("TransRoomBox"));

        horizontalLayout_2->addWidget(TransRoomBox);

        layoutWidget2 = new QWidget(transRoom);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(60, 140, 271, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        diffLabel = new QLabel(layoutWidget2);
        diffLabel->setObjectName(QStringLiteral("diffLabel"));

        horizontalLayout_3->addWidget(diffLabel);

        diffEdit = new QLineEdit(layoutWidget2);
        diffEdit->setObjectName(QStringLiteral("diffEdit"));

        horizontalLayout_3->addWidget(diffEdit);


        retranslateUi(transRoom);
        QObject::connect(buttonBox, SIGNAL(accepted()), transRoom, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), transRoom, SLOT(reject()));

        QMetaObject::connectSlotsByName(transRoom);
    } // setupUi

    void retranslateUi(QDialog *transRoom)
    {
        transRoom->setWindowTitle(QApplication::translate("transRoom", "Dialog", Q_NULLPTR));
        curRoomIdLabel->setText(QApplication::translate("transRoom", "\345\275\223\345\211\215\346\210\277\351\227\264\345\217\267:", Q_NULLPTR));
        TransRoomLabel->setText(QApplication::translate("transRoom", "\346\233\264\346\215\242\350\207\263\346\210\277\351\227\264\345\217\267\357\274\232", Q_NULLPTR));
        diffLabel->setText(QApplication::translate("transRoom", "       \345\267\256\344\273\267:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class transRoom: public Ui_transRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSROOM_H
