#include "hotel.h"
#include <QApplication>
#include "mainwindow.h"
#include<hotel.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // mainwindow w;
    Hotel w;
    w.show();

    return a.exec();
}
