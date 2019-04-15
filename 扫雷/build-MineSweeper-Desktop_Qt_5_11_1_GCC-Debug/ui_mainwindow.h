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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
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
    QAction *action9_9_10;
    QAction *action16_16_40;
    QAction *action_16_30_99;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(497, 372);
        action9_9_10 = new QAction(MainWindow);
        action9_9_10->setObjectName(QStringLiteral("action9_9_10"));
        action16_16_40 = new QAction(MainWindow);
        action16_16_40->setObjectName(QStringLiteral("action16_16_40"));
        action_16_30_99 = new QAction(MainWindow);
        action_16_30_99->setObjectName(QStringLiteral("action_16_30_99"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 497, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(action9_9_10);
        menu_2->addAction(action16_16_40);
        menu_2->addAction(action_16_30_99);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QT\346\211\253\351\233\267\346\270\270\346\210\217\357\274\210by\351\200\206\351\243\216\345\276\256\345\205\211\357\274\211", nullptr));
        action9_9_10->setText(QApplication::translate("MainWindow", "\345\210\235\347\272\247 9*9 10\344\270\252\351\233\267", nullptr));
        action16_16_40->setText(QApplication::translate("MainWindow", "\344\270\255\347\272\247 16*16 40\344\270\252\351\233\267", nullptr));
        action_16_30_99->setText(QApplication::translate("MainWindow", "\351\253\230\347\272\247 16*30 99\344\270\252\351\233\267", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\260\346\270\270\346\210\217", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
