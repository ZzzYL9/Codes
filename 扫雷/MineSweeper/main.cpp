#include "mainwindow.h"
#include <QApplication>

/*
 * QT扫雷游戏
 * 编译:QT5.8.0+MinGW
 * 作者:逆风微光
 * 博客:http://blog.csdn.net/dpsying/article/details/53791562
 * QQ:787701109
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
