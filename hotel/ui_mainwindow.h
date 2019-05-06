/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QTabWidget *Tab;
    QWidget *tab_2;
    QTableWidget *controTableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *findEdit;
    QPushButton *findBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *outBtn;
    QWidget *tab_3;
    QTableWidget *debtTableWidgt;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *findRoomDebtEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *CheckoutButton;
    QWidget *tab_4;
    QTableWidget *statisticsTableWidget;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QPushButton *BookButton;
    QSpacerItem *verticalSpacer;
    QPushButton *AccommodationButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *RetreatButton;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_5;
    QTableWidget *dayCheckoutTableWidget;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *findRoomIdEdit;
    QPushButton *findRoomIdEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_6;
    QPushButton *InitializationButton;
    QTableWidget *systemTableWidet;
    QPushButton *ChangePasswordButton;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *workIdEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *phoneNum;
    QLabel *label_4;
    QLineEdit *pawEdit;
    QLabel *label_5;
    QLineEdit *btnEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QStringLiteral("mainwindow"));
        mainwindow->resize(986, 620);
        mainwindow->setStyleSheet(QStringLiteral(""));
        Tab = new QTabWidget(mainwindow);
        Tab->setObjectName(QStringLiteral("Tab"));
        Tab->setEnabled(true);
        Tab->setGeometry(QRect(10, 20, 991, 621));
        Tab->setMinimumSize(QSize(400, 400));
        Tab->setMaximumSize(QSize(1000, 1000));
        Tab->setStyleSheet(QLatin1String("background-color: rgb(104, 115, 166);\n"
""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(33,184,150),stop: 1 rgb(29,170,140));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/\n"
"    color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(37,189,252),stop: 1 rgb(32,170,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;}\n"
"QPushButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/\n"
"    color:rgb(233"
                        ", 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(38,190,255),stop: 1 rgb(33,184,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px; };"));
        controTableWidget = new QTableWidget(tab_2);
        if (controTableWidget->columnCount() < 5)
            controTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        controTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        controTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        controTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        controTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        controTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        controTableWidget->setObjectName(QStringLiteral("controTableWidget"));
        controTableWidget->setEnabled(true);
        controTableWidget->setGeometry(QRect(10, 60, 921, 451));
        controTableWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        controTableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        controTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        controTableWidget->setTextElideMode(Qt::ElideRight);
        controTableWidget->setShowGrid(true);
        controTableWidget->setGridStyle(Qt::CustomDashLine);
        controTableWidget->setSortingEnabled(false);
        controTableWidget->horizontalHeader()->setDefaultSectionSize(180);
        controTableWidget->horizontalHeader()->setMinimumSectionSize(30);
        controTableWidget->verticalHeader()->setDefaultSectionSize(100);
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 10, 461, 36));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        findEdit = new QLineEdit(layoutWidget);
        findEdit->setObjectName(QStringLiteral("findEdit"));
        findEdit->setStyleSheet(QLatin1String("background-color: rgb(251, 255, 248);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:gray;\n"
"padding:3px;"));

        horizontalLayout->addWidget(findEdit);

        findBtn = new QPushButton(layoutWidget);
        findBtn->setObjectName(QStringLiteral("findBtn"));

        horizontalLayout->addWidget(findBtn);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        outBtn = new QPushButton(layoutWidget);
        outBtn->setObjectName(QStringLiteral("outBtn"));

        horizontalLayout->addWidget(outBtn);

        Tab->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(33,184,150),stop: 1 rgb(29,170,140));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/\n"
"    color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(37,189,252),stop: 1 rgb(32,170,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;}\n"
"QPushButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/\n"
"    color:rgb(233"
                        ", 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(38,190,255),stop: 1 rgb(33,184,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px; };"));
        debtTableWidgt = new QTableWidget(tab_3);
        if (debtTableWidgt->columnCount() < 7)
            debtTableWidgt->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        debtTableWidgt->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        debtTableWidgt->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        debtTableWidgt->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        debtTableWidgt->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        debtTableWidgt->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        debtTableWidgt->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        debtTableWidgt->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        debtTableWidgt->setObjectName(QStringLiteral("debtTableWidgt"));
        debtTableWidgt->setEnabled(true);
        debtTableWidgt->setGeometry(QRect(50, 60, 771, 451));
        debtTableWidgt->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        debtTableWidgt->setAutoScroll(true);
        debtTableWidgt->setSelectionMode(QAbstractItemView::SingleSelection);
        debtTableWidgt->setSelectionBehavior(QAbstractItemView::SelectRows);
        debtTableWidgt->setSortingEnabled(false);
        debtTableWidgt->horizontalHeader()->setCascadingSectionResizes(false);
        debtTableWidgt->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 20, 421, 36));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        findRoomDebtEdit = new QLineEdit(layoutWidget1);
        findRoomDebtEdit->setObjectName(QStringLiteral("findRoomDebtEdit"));
        findRoomDebtEdit->setStyleSheet(QLatin1String("background-color: rgb(251, 255, 248);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:gray;\n"
"padding:3px;"));

        horizontalLayout_2->addWidget(findRoomDebtEdit);

        horizontalSpacer_3 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        CheckoutButton = new QPushButton(layoutWidget1);
        CheckoutButton->setObjectName(QStringLiteral("CheckoutButton"));

        horizontalLayout_2->addWidget(CheckoutButton);

        Tab->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tab_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(33,184,150),stop: 1 rgb(29,170,140));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/\n"
"    color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(37,189,252),stop: 1 rgb(32,170,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;}\n"
"QPushButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/\n"
"    color:rgb(233"
                        ", 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(38,190,255),stop: 1 rgb(33,184,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px; };"));
        statisticsTableWidget = new QTableWidget(tab_4);
        if (statisticsTableWidget->columnCount() < 6)
            statisticsTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        statisticsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        statisticsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        statisticsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        statisticsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        statisticsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        statisticsTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        statisticsTableWidget->setObjectName(QStringLiteral("statisticsTableWidget"));
        statisticsTableWidget->setGeometry(QRect(150, 80, 731, 411));
        statisticsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        statisticsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        layoutWidget2 = new QWidget(tab_4);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 120, 95, 318));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        BookButton = new QPushButton(layoutWidget2);
        BookButton->setObjectName(QStringLiteral("BookButton"));

        verticalLayout->addWidget(BookButton);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        AccommodationButton = new QPushButton(layoutWidget2);
        AccommodationButton->setObjectName(QStringLiteral("AccommodationButton"));

        verticalLayout->addWidget(AccommodationButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        RetreatButton = new QPushButton(layoutWidget2);
        RetreatButton->setObjectName(QStringLiteral("RetreatButton"));

        verticalLayout->addWidget(RetreatButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        Tab->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tab_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(33,184,150),stop: 1 rgb(29,170,140));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/\n"
"    color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(37,189,252),stop: 1 rgb(32,170,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;}\n"
"QPushButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/\n"
"    color:rgb(233"
                        ", 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(38,190,255),stop: 1 rgb(33,184,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px; };"));
        dayCheckoutTableWidget = new QTableWidget(tab_5);
        if (dayCheckoutTableWidget->columnCount() < 6)
            dayCheckoutTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        dayCheckoutTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        dayCheckoutTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        dayCheckoutTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        dayCheckoutTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        dayCheckoutTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        dayCheckoutTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem23);
        dayCheckoutTableWidget->setObjectName(QStringLiteral("dayCheckoutTableWidget"));
        dayCheckoutTableWidget->setGeometry(QRect(100, 70, 761, 421));
        dayCheckoutTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        dayCheckoutTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        layoutWidget3 = new QWidget(tab_5);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(320, 20, 461, 36));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        findRoomIdEdit = new QLineEdit(layoutWidget3);
        findRoomIdEdit->setObjectName(QStringLiteral("findRoomIdEdit"));
        findRoomIdEdit->setStyleSheet(QLatin1String("background-color: rgb(251, 255, 248);\n"
"border-style:outset;\n"
"border-width:2px;\n"
"border-radius:10px;\n"
"border-color:gray;\n"
"padding:3px;"));

        horizontalLayout_3->addWidget(findRoomIdEdit);

        findRoomIdEdit_2 = new QPushButton(layoutWidget3);
        findRoomIdEdit_2->setObjectName(QStringLiteral("findRoomIdEdit_2"));

        horizontalLayout_3->addWidget(findRoomIdEdit_2);

        horizontalSpacer_2 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        Tab->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tab_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(33,184,150),stop: 1 rgb(29,170,140));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/\n"
"    color:rgb(233, 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(37,189,252),stop: 1 rgb(32,170,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px;}\n"
"QPushButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/\n"
"    color:rgb(233"
                        ", 236, 243);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),stop: 0.3 rgb(38,190,255),stop: 1 rgb(33,184,240));\n"
"    border:1px;\n"
"    border-radius:10px;padding:2px 4px; };"));
        InitializationButton = new QPushButton(tab_6);
        InitializationButton->setObjectName(QStringLiteral("InitializationButton"));
        InitializationButton->setGeometry(QRect(110, 430, 88, 34));
        systemTableWidet = new QTableWidget(tab_6);
        if (systemTableWidet->columnCount() < 4)
            systemTableWidet->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        systemTableWidet->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        systemTableWidet->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        systemTableWidet->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        systemTableWidet->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        systemTableWidet->setObjectName(QStringLiteral("systemTableWidet"));
        systemTableWidet->setGeometry(QRect(110, 40, 511, 361));
        systemTableWidet->setSelectionMode(QAbstractItemView::SingleSelection);
        systemTableWidet->setSelectionBehavior(QAbstractItemView::SelectRows);
        ChangePasswordButton = new QPushButton(tab_6);
        ChangePasswordButton->setObjectName(QStringLiteral("ChangePasswordButton"));
        ChangePasswordButton->setGeometry(QRect(490, 430, 88, 34));
        layoutWidget4 = new QWidget(tab_6);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(661, 71, 241, 361));
        gridLayout = new QGridLayout(layoutWidget4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget4);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        workIdEdit = new QLineEdit(layoutWidget4);
        workIdEdit->setObjectName(QStringLiteral("workIdEdit"));

        gridLayout->addWidget(workIdEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        nameEdit = new QLineEdit(layoutWidget4);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        phoneNum = new QLineEdit(layoutWidget4);
        phoneNum->setObjectName(QStringLiteral("phoneNum"));

        gridLayout->addWidget(phoneNum, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        pawEdit = new QLineEdit(layoutWidget4);
        pawEdit->setObjectName(QStringLiteral("pawEdit"));
        pawEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pawEdit, 3, 1, 1, 1);

        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        btnEdit = new QLineEdit(layoutWidget4);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));
        btnEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(btnEdit, 4, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        Tab->addTab(tab_6, QString());

        retranslateUi(mainwindow);

        Tab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QApplication::translate("mainwindow", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = controTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\345\233\276\347\211\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = controTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = controTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("mainwindow", "\344\273\267\346\240\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = controTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("mainwindow", "\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = controTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\347\212\266\346\200\201", Q_NULLPTR));
        findEdit->setPlaceholderText(QApplication::translate("mainwindow", "\350\257\267\350\276\223\345\205\245\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        findBtn->setText(QApplication::translate("mainwindow", "\346\237\245\350\257\242", Q_NULLPTR));
        outBtn->setText(QApplication::translate("mainwindow", "\346\263\250\351\224\200", Q_NULLPTR));
        Tab->setTabText(Tab->indexOf(tab_2), QApplication::translate("mainwindow", "\345\256\242\346\210\277\347\256\241\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = debtTableWidgt->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = debtTableWidgt->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("mainwindow", "\346\214\202\345\270\220\345\215\225\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = debtTableWidgt->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("mainwindow", "\347\224\265\350\257\235\345\217\267\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = debtTableWidgt->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("mainwindow", "\345\205\245\344\275\217\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = debtTableWidgt->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("mainwindow", "\351\200\200\346\210\277\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = debtTableWidgt->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("mainwindow", "\344\275\217\345\256\277\345\244\251\346\225\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = debtTableWidgt->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("mainwindow", "\346\266\210\350\264\271\351\207\221\351\242\235", Q_NULLPTR));
        findRoomDebtEdit->setPlaceholderText(QApplication::translate("mainwindow", "\350\257\267\350\276\223\345\205\245\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        CheckoutButton->setText(QApplication::translate("mainwindow", "\347\273\223\345\270\220", Q_NULLPTR));
        Tab->setTabText(Tab->indexOf(tab_3), QApplication::translate("mainwindow", "\346\214\202\345\270\220\347\256\241\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = statisticsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = statisticsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = statisticsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("mainwindow", "\347\224\250\346\210\267\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = statisticsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("mainwindow", "\346\266\210\350\264\271\351\207\221\351\242\235", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = statisticsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("mainwindow", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = statisticsTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QApplication::translate("mainwindow", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        BookButton->setText(QApplication::translate("mainwindow", "\351\242\204\350\256\242\346\210\277\346\237\245\350\257\242", Q_NULLPTR));
        AccommodationButton->setText(QApplication::translate("mainwindow", "\344\275\217\345\256\277\346\237\245\350\257\242", Q_NULLPTR));
        RetreatButton->setText(QApplication::translate("mainwindow", "\351\200\200\345\256\277\346\237\245\350\257\242 ", Q_NULLPTR));
        Tab->setTabText(Tab->indexOf(tab_4), QApplication::translate("mainwindow", "\346\237\245\350\257\242\347\273\237\350\256\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = dayCheckoutTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = dayCheckoutTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("mainwindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = dayCheckoutTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("mainwindow", "\345\205\245\344\275\217\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = dayCheckoutTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("mainwindow", "\351\200\200\346\210\277\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = dayCheckoutTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem22->setText(QApplication::translate("mainwindow", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = dayCheckoutTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem23->setText(QApplication::translate("mainwindow", "\346\266\210\350\264\271\351\207\221\351\242\235", Q_NULLPTR));
        findRoomIdEdit->setPlaceholderText(QApplication::translate("mainwindow", "\350\257\267\350\276\223\345\205\245\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        findRoomIdEdit_2->setText(QApplication::translate("mainwindow", "\346\237\245\350\257\242", Q_NULLPTR));
        Tab->setTabText(Tab->indexOf(tab_5), QApplication::translate("mainwindow", "\346\227\245\347\273\223", Q_NULLPTR));
        InitializationButton->setText(QApplication::translate("mainwindow", "\345\210\235\345\247\213\345\214\226\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = systemTableWidet->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("mainwindow", "\345\267\245\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = systemTableWidet->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("mainwindow", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = systemTableWidet->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("mainwindow", "\350\201\214\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = systemTableWidet->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QApplication::translate("mainwindow", "\347\224\265\350\257\235\345\217\267\347\240\201", Q_NULLPTR));
        ChangePasswordButton->setText(QApplication::translate("mainwindow", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("mainwindow", "    \345\267\245\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("mainwindow", "    \345\247\223\345\220\215:", Q_NULLPTR));
        label_3->setText(QApplication::translate("mainwindow", "\347\224\265\350\257\235\345\217\267\347\240\201:", Q_NULLPTR));
        label_4->setText(QApplication::translate("mainwindow", "   \345\257\206\347\240\201:", Q_NULLPTR));
        label_5->setText(QApplication::translate("mainwindow", "\347\241\256\350\256\244\345\257\206\347\240\201:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mainwindow", "\347\241\256\345\256\232\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mainwindow", "\345\217\226\346\266\210", Q_NULLPTR));
        Tab->setTabText(Tab->indexOf(tab_6), QApplication::translate("mainwindow", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
