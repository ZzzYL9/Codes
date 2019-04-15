/********************************************************************************
* File Name:	main.cpp
* Description:	第6章实例训练
* Reference book:《Linux环境下Qt4图形界面与MySQL编程》，机械工业出版社.2012.1
* E_mail: openlinux2011@gmail.com
*
********************************************************************************/
#include <QApplication>
#include <QtGui>

#include <QDesktopWidget>

#include <QTextCodec>
#include "mainwindow.h"
#include "databaseconnection.h"
#include "login.h"
#include "chgpwd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    initsql();

//    if(!connectiondatabase())
//    {
//        printf("数据库连接失败");
//        return false;
//    }
//    else {
//        printf("数据库连接成功");
//    }
    login log;
    log.show();
    log.move ((QApplication::desktop()->width() - log.width())/2,(QApplication::desktop()->height() - log.height())/2);//登陆窗口居中显示
    return a.exec();
}
