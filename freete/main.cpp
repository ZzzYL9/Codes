#include "window.h"
#include <QApplication>

#include "freete.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Freete freete(argc, argv);

    return a.exec();
}
