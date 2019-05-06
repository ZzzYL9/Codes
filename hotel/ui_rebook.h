/********************************************************************************
** Form generated from reading UI file 'rebook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REBOOK_H
#define UI_REBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReBook
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QCalendarWidget *calendarWidget;
    QLabel *dayNumsLabel;
    QLabel *roomImageLabel;
    QComboBox *dayNumsBox;
    QLabel *endTimeLabel;
    QLineEdit *endTimeEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *roomIdLabel;
    QLineEdit *rooIdEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *userNameLabel;
    QLineEdit *userNameEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *RoomTypeLabel;
    QLineEdit *carIdEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *roomPriceLabel;
    QLineEdit *phoneIdEdit;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *cardIdLabel;
    QLineEdit *RoomTypeEdit;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *phoneIdLabel;
    QLineEdit *roomPriceEdit;
    QLineEdit *startTimeEdit;
    QLabel *startTimeLabel;
    QRadioButton *IsDebtBtn;

    void setupUi(QDialog *ReBook)
    {
        if (ReBook->objectName().isEmpty())
            ReBook->setObjectName(QStringLiteral("ReBook"));
        ReBook->resize(794, 524);
        ReBook->setMinimumSize(QSize(0, 4));
        ReBook->setStyleSheet(QLatin1String("QPushButton{border-width:2px;\n"
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
"}\n"
"\n"
"QDialog{\n"
"background-color: rgb(111, 166, 255);\n"
"}"));
        buttonBox = new QDialogButtonBox(ReBook);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 410, 741, 81));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ReBook);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 0, 261, 61));
        label->setStyleSheet(QLatin1String("font: 32pt \"Bahnschrift SemiLight SemiConde\";\n"
"color: rgb(56, 61, 59);"));
        calendarWidget = new QCalendarWidget(ReBook);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(370, 80, 361, 241));
        calendarWidget->setGridVisible(true);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        dayNumsLabel = new QLabel(ReBook);
        dayNumsLabel->setObjectName(QStringLiteral("dayNumsLabel"));
        dayNumsLabel->setGeometry(QRect(510, 360, 60, 16));
        roomImageLabel = new QLabel(ReBook);
        roomImageLabel->setObjectName(QStringLiteral("roomImageLabel"));
        roomImageLabel->setGeometry(QRect(90, 410, 180, 100));
        dayNumsBox = new QComboBox(ReBook);
        dayNumsBox->setObjectName(QStringLiteral("dayNumsBox"));
        dayNumsBox->setGeometry(QRect(490, 330, 111, 21));
        dayNumsBox->setDuplicatesEnabled(false);
        endTimeLabel = new QLabel(ReBook);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));
        endTimeLabel->setGeometry(QRect(610, 360, 60, 16));
        endTimeEdit = new QLineEdit(ReBook);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));
        endTimeEdit->setGeometry(QRect(610, 330, 101, 21));
        layoutWidget = new QWidget(ReBook);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 90, 251, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        roomIdLabel = new QLabel(layoutWidget);
        roomIdLabel->setObjectName(QStringLiteral("roomIdLabel"));

        horizontalLayout->addWidget(roomIdLabel);

        rooIdEdit = new QLineEdit(layoutWidget);
        rooIdEdit->setObjectName(QStringLiteral("rooIdEdit"));
        rooIdEdit->setReadOnly(false);

        horizontalLayout->addWidget(rooIdEdit);

        layoutWidget1 = new QWidget(ReBook);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 130, 251, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        userNameLabel = new QLabel(layoutWidget1);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));

        horizontalLayout_2->addWidget(userNameLabel);

        userNameEdit = new QLineEdit(layoutWidget1);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));

        horizontalLayout_2->addWidget(userNameEdit);

        layoutWidget2 = new QWidget(ReBook);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(70, 170, 251, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        RoomTypeLabel = new QLabel(layoutWidget2);
        RoomTypeLabel->setObjectName(QStringLiteral("RoomTypeLabel"));

        horizontalLayout_3->addWidget(RoomTypeLabel);

        carIdEdit = new QLineEdit(layoutWidget2);
        carIdEdit->setObjectName(QStringLiteral("carIdEdit"));

        horizontalLayout_3->addWidget(carIdEdit);

        layoutWidget3 = new QWidget(ReBook);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(70, 210, 251, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        roomPriceLabel = new QLabel(layoutWidget3);
        roomPriceLabel->setObjectName(QStringLiteral("roomPriceLabel"));

        horizontalLayout_4->addWidget(roomPriceLabel);

        phoneIdEdit = new QLineEdit(layoutWidget3);
        phoneIdEdit->setObjectName(QStringLiteral("phoneIdEdit"));

        horizontalLayout_4->addWidget(phoneIdEdit);

        layoutWidget4 = new QWidget(ReBook);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(70, 250, 251, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        cardIdLabel = new QLabel(layoutWidget4);
        cardIdLabel->setObjectName(QStringLiteral("cardIdLabel"));

        horizontalLayout_5->addWidget(cardIdLabel);

        RoomTypeEdit = new QLineEdit(layoutWidget4);
        RoomTypeEdit->setObjectName(QStringLiteral("RoomTypeEdit"));

        horizontalLayout_5->addWidget(RoomTypeEdit);

        layoutWidget5 = new QWidget(ReBook);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(70, 290, 251, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        phoneIdLabel = new QLabel(layoutWidget5);
        phoneIdLabel->setObjectName(QStringLiteral("phoneIdLabel"));
        phoneIdLabel->setMinimumSize(QSize(0, 0));
        phoneIdLabel->setLineWidth(1);
        phoneIdLabel->setMidLineWidth(0);
        phoneIdLabel->setScaledContents(false);
        phoneIdLabel->setIndent(0);

        horizontalLayout_6->addWidget(phoneIdLabel);

        roomPriceEdit = new QLineEdit(layoutWidget5);
        roomPriceEdit->setObjectName(QStringLiteral("roomPriceEdit"));

        horizontalLayout_6->addWidget(roomPriceEdit);

        startTimeEdit = new QLineEdit(ReBook);
        startTimeEdit->setObjectName(QStringLiteral("startTimeEdit"));
        startTimeEdit->setGeometry(QRect(381, 331, 101, 21));
        startTimeLabel = new QLabel(ReBook);
        startTimeLabel->setObjectName(QStringLiteral("startTimeLabel"));
        startTimeLabel->setGeometry(QRect(381, 359, 60, 16));
        IsDebtBtn = new QRadioButton(ReBook);
        IsDebtBtn->setObjectName(QStringLiteral("IsDebtBtn"));
        IsDebtBtn->setGeometry(QRect(380, 390, 181, 81));

        retranslateUi(ReBook);
        QObject::connect(buttonBox, SIGNAL(accepted()), ReBook, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ReBook, SLOT(reject()));

        dayNumsBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReBook);
    } // setupUi

    void retranslateUi(QDialog *ReBook)
    {
        ReBook->setWindowTitle(QApplication::translate("ReBook", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ReBook", "\346\210\277\351\227\264\351\242\204\345\256\232\347\225\214\351\235\242", Q_NULLPTR));
        dayNumsLabel->setText(QApplication::translate("ReBook", "\345\205\245\344\275\217\345\244\251\346\225\260", Q_NULLPTR));
        roomImageLabel->setText(QString());
        dayNumsBox->clear();
        dayNumsBox->insertItems(0, QStringList()
         << QApplication::translate("ReBook", "1", Q_NULLPTR)
         << QApplication::translate("ReBook", "2", Q_NULLPTR)
         << QApplication::translate("ReBook", "3", Q_NULLPTR)
         << QApplication::translate("ReBook", "4", Q_NULLPTR)
         << QApplication::translate("ReBook", "5", Q_NULLPTR)
        );
        dayNumsBox->setCurrentText(QApplication::translate("ReBook", "1", Q_NULLPTR));
        endTimeLabel->setText(QApplication::translate("ReBook", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        roomIdLabel->setText(QApplication::translate("ReBook", "  \346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        rooIdEdit->setText(QString());
        rooIdEdit->setPlaceholderText(QString());
        userNameLabel->setText(QApplication::translate("ReBook", "  \347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        RoomTypeLabel->setText(QApplication::translate("ReBook", "  \350\272\253\344\273\275\350\257\201", Q_NULLPTR));
        roomPriceLabel->setText(QApplication::translate("ReBook", "\347\224\265\350\257\235\345\217\267\347\240\201", Q_NULLPTR));
        cardIdLabel->setText(QApplication::translate("ReBook", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        phoneIdLabel->setText(QApplication::translate("ReBook", "\346\210\277\351\227\264\344\273\267\346\240\274", Q_NULLPTR));
        startTimeLabel->setText(QApplication::translate("ReBook", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        IsDebtBtn->setText(QApplication::translate("ReBook", "\346\230\257\345\220\246\346\214\202\350\264\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReBook: public Ui_ReBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REBOOK_H
