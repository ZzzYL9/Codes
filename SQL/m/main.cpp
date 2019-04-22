#include <iostream>
#include <string.h>
#include "my_sql.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{

    sql_api my_api;
    
       if(!my_api.sql_connect("127.0.0.1","root","root","own_sql"))
   {
       cout << "用户名或密码错误" << endl;
       return -1;
   }
//    cout << "~$ ";
//    string str1;
//    string str2 = "mySQL";
//    do{
//     cin >> str1;
//    }while(str1.compare(str2) != 0);
//    string user, pwd;
//    cout << "(mysql)==>login:";
//    cin >> user;
//    cout << "(mysql)==>password:";
//    cin >> pwd;
//    if(!my_api.sql_connect("127.0.0.1",user,pwd,"own_sql"))
//    {
//        cout << "用户名或密码错误" << endl;
//        return -1;
//    }
//    my_api.Create("CREATE TABLE Student (学号, 姓名, 身份证, 专业) TO Student.txt");
//     my_api.Drop("DROP TABLE test");
//     my_api.Insert("INSERT INTO Student VALUES (177777, 王二小, 12345, 计算机科学与技术)");
//         my_api.Insert("INSERT INTO Student (学号, 姓名, 身份证, 专业) VALUES (227777, 重庆, 11111, 士大夫)");
//     my_api.Delete("DELETE FROM Student WHERE 姓名 = 王二小");
    my_api.Delete("DELETE * FROM Student");
//     my_api.Select_easy("SELECT * FROM Student");
//     my_api.Select_easy("SELECT * FROM Student ORDER BY 学号 DESC");
//     my_api.Select_easy("SELECT * FROM Student WHERE 姓名 = 王二小 TO Class1.txt");
//     my_api.Select_easy("SELECT * FROM Student WHERE 姓名 = 王二小");


//    my_api.Select();
//    my_api.Insert("1,'张三',20,'男','SUST'");
//    my_api.Insert("2,'李四',21,'男','XATU'");
//    my_api.Insert("3,'王五',20,'男','清华'");
//    my_api.Insert("4,'小红',20,'男','北大'");
//    my_api.Insert("5,'小明',19,'女','西工大'");
//    my_api.Insert("6,'小李',22,'男','交大'");
//    my_api.Select();
//    my_api.Update("age=30 where name ='王五'");
//    my_api.Select();
//    my_api.Update("school ='xatu' where id =2");
//    my_api.Select();
//    my_api.Update("sex ='女' where name ='小红'");
//    my_api.Select();
//    my_api.Delete("name ='张三'");
//    my_api.Select();
//    my_api.Delete("school ='西工大'");
//    my_api.Select();
    return 0;
}

