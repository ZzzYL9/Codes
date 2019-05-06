#include "mainwindow.h"
#include <QApplication>
#include "log_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    log_dialog L;
//    L.show();
    MainWindow M;
    M.show();

    return a.exec();
}
