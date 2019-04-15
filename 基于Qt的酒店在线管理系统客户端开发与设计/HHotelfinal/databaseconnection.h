#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSql>

void initsql()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Hotel");
    db.setUserName("root");
    db.setPassword("root");

    if(db.open())
        {
            qDebug()<<"Database connected successfully!";
            return;
        }
    else
        {
            qDebug()<<"Database connected failed!";
            return;
        }
}

//static bool connectiondatabase()
//{
//    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setPort(3306);  //设置端口
//    db.setDatabaseName("hotel");
//    db.setUserName("root");
//    db.setPassword("root");

//    // 设置编码格式
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForLocale(codec);

//    //Set Character-Set
//    db.exec("set NAMES UTF8");

//    if(!db.open())
//    {
//        return false;
//    }
//    return true;
//}


#endif // DATABASECONNECTION_H
