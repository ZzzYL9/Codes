/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QRadioButton *rb1;
    QRadioButton *rb2;
    QRadioButton *rb3;
    QRadioButton *rb4;
    QRadioButton *rb5;
    QRadioButton *rb6;
    QLabel *label_2;
    QTableView *tvRoomInfo;
    QPushButton *pushButton;
    QLabel *label_11;
    QLabel *label;
    QTableView *tvPriceInfo;
    QWidget *tab2;
    QGroupBox *groupBox_2;
    QPushButton *pbSubmit;
    QPushButton *pbCancle;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *leID;
    QLabel *label_4;
    QLineEdit *leUserName;
    QLineEdit *leRoomID;
    QLabel *label_6;
    QLineEdit *leNumOfNig;
    QLabel *label_13;
    QWidget *tab5;
    QTableView *food_tableView;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_2;
    QLabel *label_15;
    QPushButton *pushButton_13;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QWidget *tab;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_12;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QPushButton *pushButton_23;
    QWidget *tab3;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLineEdit *leOut_ID;
    QPushButton *pbOut_Search;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *leRealdate;
    QLabel *label_10;
    QLineEdit *lePay;
    QPushButton *pbCheckout;
    QTableView *tableView_2;
    QTableView *tvQuery;
    QWidget *tab4;
    QTableView *tvCheckin;
    QTableView *tvCheckout;
    QWidget *tab_2;
    QTableView *tableView_3;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_31;
    QTableView *tableView_7;
    QLabel *label_16;
    QWidget *tab_3;
    QLabel *label_31;
    QLabel *label_32;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(803, 646);
        MainWindow->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/blueButton.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 30, 721, 577));
        tabWidget->setMinimumSize(QSize(600, 0));
        tabWidget->setMaximumSize(QSize(801, 16777215));
        tabWidget->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        tab1->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        rb1 = new QRadioButton(tab1);
        rb1->setObjectName(QStringLiteral("rb1"));
        rb1->setGeometry(QRect(120, 250, 140, 26));
        rb1->setMinimumSize(QSize(140, 26));
        rb1->setMaximumSize(QSize(140, 26));
        rb1->setStyleSheet(QLatin1String("border :0px ;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        rb2 = new QRadioButton(tab1);
        rb2->setObjectName(QStringLiteral("rb2"));
        rb2->setGeometry(QRect(120, 290, 140, 26));
        rb2->setMinimumSize(QSize(140, 26));
        rb2->setStyleSheet(QLatin1String("border :0px ;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        rb3 = new QRadioButton(tab1);
        rb3->setObjectName(QStringLiteral("rb3"));
        rb3->setGeometry(QRect(120, 330, 140, 26));
        rb3->setMinimumSize(QSize(140, 26));
        rb3->setStyleSheet(QLatin1String("border :0px ;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        rb4 = new QRadioButton(tab1);
        rb4->setObjectName(QStringLiteral("rb4"));
        rb4->setGeometry(QRect(120, 370, 140, 26));
        rb4->setMinimumSize(QSize(140, 26));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        rb4->setFont(font);
        rb4->setFocusPolicy(Qt::NoFocus);
        rb4->setAutoFillBackground(false);
        rb4->setStyleSheet(QLatin1String("border :0px ;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        rb5 = new QRadioButton(tab1);
        rb5->setObjectName(QStringLiteral("rb5"));
        rb5->setGeometry(QRect(120, 410, 140, 26));
        rb5->setMinimumSize(QSize(140, 26));
        rb5->setStyleSheet(QLatin1String("border :0px ;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        rb6 = new QRadioButton(tab1);
        rb6->setObjectName(QStringLiteral("rb6"));
        rb6->setGeometry(QRect(120, 450, 140, 26));
        rb6->setMinimumSize(QSize(140, 26));
        rb6->setStyleSheet(QLatin1String("border :0px ;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        label_2 = new QLabel(tab1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 240, 31, 161));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(10000, 10000));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        tvRoomInfo = new QTableView(tab1);
        tvRoomInfo->setObjectName(QStringLiteral("tvRoomInfo"));
        tvRoomInfo->setGeometry(QRect(390, 249, 286, 231));
        tvRoomInfo->setMinimumSize(QSize(286, 0));
        tvRoomInfo->setMaximumSize(QSize(286, 250));
        tvRoomInfo->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(tab1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 500, 111, 41));
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(400, 400));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Purple.jpg);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 10pt \"Agency FB\";"));
        label_11 = new QLabel(tab1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(70, 240, 31, 161));
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(10000, 10000));
        label_11->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        label = new QLabel(tab1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 31, 151));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        tvPriceInfo = new QTableView(tab1);
        tvPriceInfo->setObjectName(QStringLiteral("tvPriceInfo"));
        tvPriceInfo->setEnabled(true);
        tvPriceInfo->setGeometry(QRect(120, 11, 555, 224));
        tvPriceInfo->setMinimumSize(QSize(555, 224));
        tvPriceInfo->setMaximumSize(QSize(555, 224));
        tvPriceInfo->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tab2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/beijing.jpg);"));
        groupBox_2 = new QGroupBox(tab2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 691, 501));
        groupBox_2->setStyleSheet(QStringLiteral("border: 2px solid gray;"));
        pbSubmit = new QPushButton(groupBox_2);
        pbSubmit->setObjectName(QStringLiteral("pbSubmit"));
        pbSubmit->setGeometry(QRect(190, 310, 101, 31));
        pbSubmit->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Blue.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        pbSubmit->setFlat(false);
        pbCancle = new QPushButton(groupBox_2);
        pbCancle->setObjectName(QStringLiteral("pbCancle"));
        pbCancle->setGeometry(QRect(330, 310, 101, 31));
        pbCancle->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Blue.jpg);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 200, 101, 31));
        label_5->setStyleSheet(QLatin1String("border :0px ;\n"
"border-image: url(:/new/prefix1/shuijing.jpg);\n"
"font: 75 11pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 100, 101, 31));
        label_3->setStyleSheet(QLatin1String("border :0px ;\n"
"border-image: url(:/new/prefix1/shuijing.jpg);\n"
"font: 75 11pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);\n"
""));
        leID = new QLineEdit(groupBox_2);
        leID->setObjectName(QStringLiteral("leID"));
        leID->setGeometry(QRect(180, 100, 261, 31));
        leID->setStyleSheet(QLatin1String("border :0px ;\n"
"border-image: url(:/new/prefix1/white.jpg);\n"
""));
        leID->setEchoMode(QLineEdit::Normal);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 150, 101, 31));
        label_4->setStyleSheet(QLatin1String("border :0px ;\n"
"font: 75 11pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);\n"
""));
        leUserName = new QLineEdit(groupBox_2);
        leUserName->setObjectName(QStringLiteral("leUserName"));
        leUserName->setGeometry(QRect(180, 150, 261, 31));
        leUserName->setStyleSheet(QLatin1String("border :0px ;\n"
"border-image: url(:/new/prefix1/white.jpg);\n"
"\n"
""));
        leRoomID = new QLineEdit(groupBox_2);
        leRoomID->setObjectName(QStringLiteral("leRoomID"));
        leRoomID->setGeometry(QRect(180, 200, 261, 31));
        leRoomID->setStyleSheet(QLatin1String("border :0px ;\n"
"border-image: url(:/new/prefix1/white.jpg);\n"
"\n"
""));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 250, 101, 31));
        label_6->setStyleSheet(QLatin1String("border :0px ;\n"
"border-image: url(:/new/prefix1/shuijing.jpg);\n"
"font: 75 11pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);\n"
""));
        leNumOfNig = new QLineEdit(groupBox_2);
        leNumOfNig->setObjectName(QStringLiteral("leNumOfNig"));
        leNumOfNig->setEnabled(true);
        leNumOfNig->setGeometry(QRect(180, 250, 261, 31));
        leNumOfNig->setStyleSheet(QLatin1String("border :0px ;\n"
"border-image: url(:/new/prefix1/white.jpg);\n"
"\n"
""));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(450, 100, 131, 31));
        label_13->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/new/prefix1/shuijing.jpg);\n"
"border :0px ;"));
        tabWidget->addTab(tab2, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QStringLiteral("tab5"));
        tab5->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/meishi.jpg);"));
        food_tableView = new QTableView(tab5);
        food_tableView->setObjectName(QStringLiteral("food_tableView"));
        food_tableView->setGeometry(QRect(460, 0, 261, 341));
        food_tableView->setStyleSheet(QLatin1String("font: 75 10pt \"Agency FB\";\n"
"color: rgb(0, 0, 255);"));
        pushButton_10 = new QPushButton(tab5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(610, 410, 101, 40));
        pushButton_10->setMinimumSize(QSize(0, 40));
        pushButton_10->setMaximumSize(QSize(16777215, 40));
        pushButton_10->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Purple.jpg);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Agency FB\";"));
        lineEdit_2 = new QLineEdit(tab5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(460, 360, 251, 31));
        lineEdit_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        label_15 = new QLabel(tab5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(380, 360, 71, 31));
        label_15->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";\n"
"border-image: url(:/new/prefix1/shuijing.jpg);"));
        pushButton_13 = new QPushButton(tab5);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(460, 410, 101, 40));
        pushButton_13->setMinimumSize(QSize(0, 40));
        pushButton_13->setMaximumSize(QSize(16777215, 40));
        pushButton_13->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Purple.jpg);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Agency FB\";"));
        pushButton_2 = new QPushButton(tab5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 0, 71, 40));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setMaximumSize(QSize(16777215, 40));
        pushButton_3 = new QPushButton(tab5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 60, 71, 40));
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setMaximumSize(QSize(16777215, 40));
        pushButton_4 = new QPushButton(tab5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(380, 120, 71, 40));
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setMaximumSize(QSize(16777215, 40));
        pushButton_5 = new QPushButton(tab5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(380, 180, 71, 40));
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setMaximumSize(QSize(16777215, 40));
        pushButton_8 = new QPushButton(tab5);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(380, 300, 71, 40));
        pushButton_8->setMinimumSize(QSize(0, 40));
        pushButton_8->setMaximumSize(QSize(16777215, 40));
        pushButton_6 = new QPushButton(tab5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(380, 240, 71, 40));
        pushButton_6->setMinimumSize(QSize(0, 40));
        pushButton_6->setMaximumSize(QSize(16777215, 40));
        tabWidget->addTab(tab5, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(360, 110, 271, 181));
        tableView->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanhua.jpg);"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(360, 300, 271, 31));
        lineEdit->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        pushButton_11 = new QPushButton(tab);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(330, 370, 121, 41));
        pushButton_11->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Blue.jpg);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Agency FB\";"));
        pushButton_12 = new QPushButton(tab);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(510, 370, 121, 41));
        pushButton_12->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Blue.jpg);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Agency FB\";"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(220, 10, 331, 71));
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(140, 110, 107, 21));
        radioButton->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/shuijing.jpg);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";"));
        radioButton_3 = new QRadioButton(tab);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(140, 230, 107, 20));
        radioButton_3->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/shuijing.jpg);\n"
"font: 75 10pt \"Agency FB\";\n"
"color: rgb(0, 0, 0);"));
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 170, 107, 20));
        radioButton_2->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/shuijing.jpg);\n"
"font: 75 10pt \"Agency FB\";\n"
"color: rgb(0, 0, 0);"));
        radioButton_4 = new QRadioButton(tab);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(140, 290, 107, 20));
        radioButton_4->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/shuijing.jpg);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Agency FB\";"));
        pushButton_23 = new QPushButton(tab);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(140, 370, 121, 41));
        pushButton_23->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Blue.jpg);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Agency FB\";"));
        tabWidget->addTab(tab, QString());
        radioButton->raise();
        radioButton_3->raise();
        radioButton_2->raise();
        radioButton_4->raise();
        tableView->raise();
        lineEdit->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        label_12->raise();
        pushButton_23->raise();
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        tab3->setStyleSheet(QStringLiteral(""));
        gridLayout_6 = new QGridLayout(tab3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_3 = new QGroupBox(tab3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setStyleSheet(QLatin1String("border :0px ;\n"
"border-color: rgb(173, 168, 166);"));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(15, 15, 295, 22));
        label_7->setMinimumSize(QSize(295, 22));
        label_7->setMaximumSize(QSize(295, 22));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/xia2.jpg);"));
        leOut_ID = new QLineEdit(groupBox_3);
        leOut_ID->setObjectName(QStringLiteral("leOut_ID"));
        leOut_ID->setGeometry(QRect(317, 15, 179, 22));
        leOut_ID->setMinimumSize(QSize(179, 22));
        leOut_ID->setMaximumSize(QSize(179, 22));
        leOut_ID->setStyleSheet(QStringLiteral("border :0px ;"));
        pbOut_Search = new QPushButton(groupBox_3);
        pbOut_Search->setObjectName(QStringLiteral("pbOut_Search"));
        pbOut_Search->setGeometry(QRect(503, 13, 179, 24));
        pbOut_Search->setMinimumSize(QSize(179, 24));
        pbOut_Search->setMaximumSize(QSize(179, 22));
        pbOut_Search->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/blueButton.jpg);\n"
"font: 75 11pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(16, 44, 671, 41));
        label_8->setMinimumSize(QSize(0, 0));
        label_8->setMaximumSize(QSize(1000, 1000));
        label_8->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/lanhua.jpg);\n"
"color: rgb(0, 0, 0);\n"
"font: 75 14pt \"Agency FB\";"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(15, 475, 135, 22));
        label_9->setMinimumSize(QSize(135, 22));
        label_9->setMaximumSize(QSize(135, 22));
        label_9->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/xia2.jpg);"));
        leRealdate = new QLineEdit(groupBox_3);
        leRealdate->setObjectName(QStringLiteral("leRealdate"));
        leRealdate->setGeometry(QRect(157, 475, 175, 22));
        leRealdate->setMinimumSize(QSize(175, 22));
        leRealdate->setMaximumSize(QSize(175, 22));
        leRealdate->setStyleSheet(QStringLiteral("border :0px ;"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(15, 504, 135, 19));
        label_10->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/xia2.jpg);"));
        lePay = new QLineEdit(groupBox_3);
        lePay->setObjectName(QStringLiteral("lePay"));
        lePay->setGeometry(QRect(157, 504, 175, 22));
        lePay->setMinimumSize(QSize(175, 22));
        lePay->setMaximumSize(QSize(175, 22));
        lePay->setStyleSheet(QStringLiteral("border :0px ;"));
        pbCheckout = new QPushButton(groupBox_3);
        pbCheckout->setObjectName(QStringLiteral("pbCheckout"));
        pbCheckout->setGeometry(QRect(339, 502, 179, 24));
        pbCheckout->setMinimumSize(QSize(179, 24));
        pbCheckout->setMaximumSize(QSize(179, 24));
        pbCheckout->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/blueButton.jpg);\n"
"font: 75 11pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        tableView_2 = new QTableView(groupBox_3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(3, 272, 691, 191));
        tableView_2->setMinimumSize(QSize(0, 0));
        tableView_2->setMaximumSize(QSize(10000, 10000));
        tableView_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/xia2.jpg);"));
        tvQuery = new QTableView(groupBox_3);
        tvQuery->setObjectName(QStringLiteral("tvQuery"));
        tvQuery->setGeometry(QRect(3, 81, 691, 191));
        tvQuery->setMinimumSize(QSize(0, 0));
        tvQuery->setMaximumSize(QSize(1000, 11000));
        tvQuery->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shang2.jpg);"));

        gridLayout_6->addWidget(groupBox_3, 0, 0, 1, 1);

        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QStringLiteral("tab4"));
        tvCheckin = new QTableView(tab4);
        tvCheckin->setObjectName(QStringLiteral("tvCheckin"));
        tvCheckin->setGeometry(QRect(0, 2, 721, 276));
        tvCheckin->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shang.jpg);"));
        tvCheckout = new QTableView(tab4);
        tvCheckout->setObjectName(QStringLiteral("tvCheckout"));
        tvCheckout->setGeometry(QRect(0, 276, 721, 276));
        tvCheckout->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/xia.jpg);"));
        tabWidget->addTab(tab4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanxin.jpg);"));
        tableView_3 = new QTableView(tab_2);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(0, 1, 721, 431));
        tableView_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/lanxin.jpg);"));
        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(540, 510, 93, 28));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 510, 191, 31));
        lineEdit_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        pushButton_31 = new QPushButton(tab_2);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        pushButton_31->setGeometry(QRect(380, 510, 111, 28));
        tableView_7 = new QTableView(tab_2);
        tableView_7->setObjectName(QStringLiteral("tableView_7"));
        tableView_7->setGeometry(QRect(0, 401, 721, 100));
        tableView_7->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/xia1.jpg);"));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 510, 121, 31));
        label_16->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/shuijing.jpg);"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/about1.jpg);"));
        tab_3->setInputMethodHints(Qt::ImhNone);
        label_31 = new QLabel(tab_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(210, 50, 621, 441));
        label_32 = new QLabel(tab_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(30, 140, 151, 141));
        label_32->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/hotel.jpg);"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        rb1->setText(QApplication::translate("MainWindow", "\345\225\206\345\212\241\345\245\227\346\210\277 ", nullptr));
        rb2->setText(QApplication::translate("MainWindow", "\350\261\252\345\215\216\345\215\225\344\272\272\351\227\264", nullptr));
        rb3->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206\345\215\225\344\272\272\351\227\264", nullptr));
        rb4->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206\345\217\214\344\272\272\351\227\264", nullptr));
        rb5->setText(QApplication::translate("MainWindow", "\350\261\252\345\215\216\345\217\214\344\272\272\351\227\264", nullptr));
        rb6->setText(QApplication::translate("MainWindow", "\346\200\273\347\273\237\345\245\227\346\210\277 ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\346\210\277</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\351\227\264</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\344\277\241</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\346\201\257</span></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\346\210\277\344\273\267", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\346\210\277</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\351\227\264</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\347\261\273</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\345\236\213</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\344\273\212</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\346\227\245</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\346\210\277</span></p><p><span style=\" font-size:12pt; font-weight:600; color:#0000ff;\">\344\273\267</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "\345\256\242\346\210\277\346\237\245\350\257\242", nullptr));
        groupBox_2->setTitle(QString());
        pbSubmit->setText(QApplication::translate("MainWindow", "\347\241\256  \345\256\232", nullptr));
        pbCancle->setText(QApplication::translate("MainWindow", "\345\217\226  \346\266\210", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "  \346\210\277\351\227\264\345\217\267\347\240\201", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "  \350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "  \345\247\223    \345\220\215", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "  \345\205\245\344\275\217\345\244\251\346\225\260", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\350\272\253\344\273\275\350\257\201\345\217\267\346\240\274\345\274\217\351\224\231\350\257\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "\347\231\273\350\256\260\345\205\245\344\275\217", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "\347\224\250\351\244\220\347\231\273\350\256\260", nullptr));
        label_15->setText(QApplication::translate("MainWindow", " \350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "\346\211\223\345\214\205\351\245\255\350\217\234", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\217\234\345\223\201", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\217\234\345\223\201", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\217\234\345\223\201", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\350\217\234\345\223\201", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "\344\273\267\346\240\274\351\231\215\345\272\217", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\344\273\267\346\240\274\345\215\207\345\272\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab5), QApplication::translate("MainWindow", "\351\244\220\351\245\256\347\256\241\347\220\206", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "\346\264\227\346\265\264\347\231\273\350\256\260", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "\345\217\226   \346\266\210", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#0055ff;\">\345\244\251 \346\261\240 \346\264\227 \346\265\264 \344\270\255 \345\277\203</span></p></body></html>", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\346\231\256  \351\200\232  \346\264\227  \346\265\264", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "\346\240\207  \345\207\206  \346\214\211  \346\221\251", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\346\240\207  \345\207\206  \350\266\263  \346\265\264", nullptr));
        radioButton_4->setText(QApplication::translate("MainWindow", "\346\240\207  \345\207\206  \346\241\221  \346\213\277", nullptr));
        pushButton_23->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\273\267\346\240\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\346\264\227\346\265\264\347\256\241\347\220\206", nullptr));
        groupBox_3->setTitle(QString());
        label_7->setText(QApplication::translate("MainWindow", "                   \350\272\253  \344\273\275  \350\257\201  \345\217\267\357\274\232 ", nullptr));
        pbOut_Search->setText(QApplication::translate("MainWindow", "\346\237\245     \350\257\242", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "                                            \345\205\245 \344\275\217 \344\277\241 \346\201\257", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\345\256\236\351\231\205\345\205\245\344\275\217\345\244\251\346\225\260:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\345\272\224  \347\274\264  \350\264\271  \347\224\250\357\274\232", nullptr));
        pbCheckout->setText(QApplication::translate("MainWindow", "\351\200\200    \346\210\277", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("MainWindow", "\351\200\200\346\210\277\347\273\223\347\256\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QApplication::translate("MainWindow", "\350\256\260\345\275\225\346\230\276\347\244\272", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        pushButton_31->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\345\221\230\345\267\245\345\247\223\345\220\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">\351\205\222\345\272\227\345\234\250\347\272\277\347\256\241\347\220\206\347\263\273\347\273\237</span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">\351\205\222\345\272\227\345\234\250\347\272\277\347\256\241\347\220\206\347\263\273\347\273\237 Hotel 1.0\357\274\210MSVC 2015,64 bit\357\274\211 </span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">Built on Apr 14 2018 16:21:39</span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">From revision 7071b61e02</span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">All rights reserved.</span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">The program is provied AS IS with NO WARRANTY OF </span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0"
                        "000ff;\">ANY KIND, INCLUDING THE WARRANTY OF DESIGN,</span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">MERCHANTABILITY AND FITNESS FOR A PARTICULAR </span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">PURPOSE.</span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#ff0000;\">Author:</span></p><p align=\"justify\"><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">Copyright 2017-2018 </span><span style=\" font-size:11pt; font-weight:600; color:#000000;\">WangHu</span><span style=\" font-size:11pt; font-weight:600; color:#0000ff;\">. </span></p></body></html>", nullptr));
        label_32->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\345\205\263\344\272\216\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
