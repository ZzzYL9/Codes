/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSaveAs;
    QTextEdit *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(400, 300);
        actionNew = new QAction(Window);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew->setIcon(icon);
        actionOpen = new QAction(Window);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        iconThemeName = QStringLiteral("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon1);
        actionSave = new QAction(Window);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(Window);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSaveAs = new QAction(Window);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        centralWidget = new QTextEdit(Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        Window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setAutoFillBackground(false);
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(true);
        Window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Window->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionExit);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", nullptr));
        actionNew->setText(QApplication::translate("Window", "New", nullptr));
        actionOpen->setText(QApplication::translate("Window", "Open", nullptr));
        actionSave->setText(QApplication::translate("Window", "Save", nullptr));
        actionExit->setText(QApplication::translate("Window", "Exit", nullptr));
        actionSaveAs->setText(QApplication::translate("Window", "SaveAs", nullptr));
        menuFile->setTitle(QApplication::translate("Window", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
