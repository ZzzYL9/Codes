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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionStart;
    QAction *actionNewGame;
    QAction *actionTie;
    QAction *actionUndo;
    QAction *actionLose;
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionSave;
    QAction *actionFlip;
    QWidget *centralWidget;
    QLCDNumber *timeLeft;
    QLabel *lblTurn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu_Help;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        MainWindow->setMinimumSize(QSize(1024, 768));
        MainWindow->setMaximumSize(QSize(1024, 768));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/chess.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/helpabout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon3);
        actionNewGame = new QAction(MainWindow);
        actionNewGame->setObjectName(QStringLiteral("actionNewGame"));
        actionNewGame->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/newgame.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewGame->setIcon(icon4);
        actionTie = new QAction(MainWindow);
        actionTie->setObjectName(QStringLiteral("actionTie"));
        actionTie->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/tie.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTie->setIcon(icon5);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionUndo->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/fallback.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon6);
        actionLose = new QAction(MainWindow);
        actionLose->setObjectName(QStringLiteral("actionLose"));
        actionLose->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/fail.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLose->setIcon(icon7);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/fileexit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon8);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionSettings->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon9);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon10);
        actionFlip = new QAction(MainWindow);
        actionFlip->setObjectName(QStringLiteral("actionFlip"));
        actionFlip->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/flip.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlip->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        timeLeft = new QLCDNumber(centralWidget);
        timeLeft->setObjectName(QStringLiteral("timeLeft"));
        timeLeft->setGeometry(QRect(510, 10, 75, 20));
        timeLeft->setMinimumSize(QSize(75, 20));
        timeLeft->setMaximumSize(QSize(75, 20));
        timeLeft->setDigitCount(8);
        timeLeft->setSegmentStyle(QLCDNumber::Flat);
        timeLeft->setProperty("value", QVariant(0));
        lblTurn = new QLabel(centralWidget);
        lblTurn->setObjectName(QStringLiteral("lblTurn"));
        lblTurn->setGeometry(QRect(440, 10, 61, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionStart);
        menuFile->addAction(actionNewGame);
        menuFile->addAction(actionFlip);
        menuFile->addAction(actionUndo);
        menuFile->addAction(actionLose);
        menuFile->addAction(actionTie);
        menuFile->addAction(actionSettings);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menu_Help->addAction(actionAbout);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionStart);
        toolBar->addAction(actionNewGame);
        toolBar->addAction(actionFlip);
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionTie);
        toolBar->addAction(actionLose);
        toolBar->addAction(actionSettings);
        toolBar->addAction(actionAbout);
        toolBar->addSeparator();
        toolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\255\345\233\275\350\261\241\346\243\213", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
        actionStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213(&S)", nullptr));
        actionNewGame->setText(QApplication::translate("MainWindow", "\346\226\260\345\261\200(&N)", nullptr));
        actionTie->setText(QApplication::translate("MainWindow", "\346\217\220\345\222\214(&T)", nullptr));
        actionUndo->setText(QApplication::translate("MainWindow", "\346\202\224\346\243\213(&U)", nullptr));
        actionLose->setText(QApplication::translate("MainWindow", "\350\256\244\350\276\223(&L)", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&E)", nullptr));
        actionSettings->setText(QApplication::translate("MainWindow", "\351\246\226\351\200\211\351\241\271(&P)", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
        actionFlip->setText(QApplication::translate("MainWindow", "\347\277\273\350\275\254\346\243\213\347\233\230(&R)", nullptr));
        lblTurn->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_Help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
