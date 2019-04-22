#ifndef MYSQL_H
#define MYSQL_H

#include<iostream>
#include"/usr/include/mysql/mysql.h"
#include<string>
#include<stdio.h>
using namespace std;

class sql_api
{
public:
    sql_api();
    ~sql_api();
    //void substring( char *s, char ch1, char ch2, char *substr );
    bool sql_connect(string host,string user,string password,string dbname);
    bool Create(string str);
    bool Drop(string str);
    bool Insert(string str);
    bool Delete(string str);
    bool Select_easy(string str);
    bool Select();
    

private:
    MYSQL * conn;//mysql连接
};



#endif // MYSQL_H
