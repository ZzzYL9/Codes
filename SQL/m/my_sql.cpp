#include"my_sql.h"
#include <vector>
#include <fstream>



sql_api::sql_api()
{
    conn = mysql_init(NULL);
}
sql_api::~sql_api()
{
    mysql_close(conn);
}
bool sql_api::sql_connect(string host,string user,string password,string dbname)
{
    conn = mysql_real_connect(conn,host.c_str(),user.c_str(),password.c_str(), dbname.c_str(),0,NULL,0);
    if(conn ==NULL)
    {
        cout<<"mysql_real_connect is failed"<<endl;
        return false;
    }
        return true;
}

//创建表
bool sql_api::Create(string str)
{
    vector<string> strs; //保存所有切割下来的字符串
    string str1 = ""; //需要创建的表的信息
    string last_inf = ""; //表信息最后一个数据
    string txt_name = ""; //txt文件名称
    string tb_name = ""; //表名称
    int t1 = str.find("(");//括号中所有数据
    int t2 = str.find_last_of(")");
    str1 = str.substr(t1+1,t2-t1-1);
//     cout << str1 << endl;
    t1 = str.find_last_of(","); //查找最后一个表信息
    t2 = str.find_last_of(")");
    last_inf = str.substr(t1+1,t2-t1-1);
    
    t1 = str.find_last_of(" "); //查找生成的txt文件
    t2 = str.find_last_of("t");
    txt_name = str.substr(t1+1,t2-t1);
    
    t1 = str.find_first_of("L"); //查找表名字
    t2 = str.find("(");
    tb_name = str.substr(t1+3, t2-t1-4);
//     cout << str4;

    int bj=0;
    int ej=0;
    while(ej = str1.find(",",bj))
    {
        if (ej<1)
        {
            break;
        }
        string tempCCre = str1.substr(bj,ej-bj);

        //这里添加处理的代码，tempCCre就是获得的子串；
        strs.push_back(tempCCre);
//             cout << tempCCre << endl;

        bj = ej+1;
        ej = 0;
    }
        
    string sql = "CREATE TABLE ";
    sql += tb_name;
    sql += " (";
    for(int i = 0; i < strs.size(); i++){
        sql += strs[i];
        sql += " char(100),";
    }
    sql += last_inf;
    sql += " char(100)";
    sql += ");";
    cout << sql << endl;
    int ret =mysql_query(conn,sql.c_str());
    if(ret != 0)
    {
        return false;
    }
    
    string my_path = "../m/";
    my_path += txt_name;
    //创建TXT文件
    ofstream fout(my_path);
    if (fout) { // 如果创建成功
        fout << "ID " ; // 使用与cout同样的方式进行写入
        for(auto it = strs.begin(); it !=strs.end(); it++){
            fout << *it << " ";
         }
         fout << last_inf << endl;
        fout.close(); // 执行完操作后关闭文件句柄
    }
    return true;
}

//删除表
bool sql_api::Drop(string str)
{
    int ret =mysql_query(conn,str.c_str());
    if(ret != 0)
    {
        return false;
    }
    return true;
}

//插入数据
bool sql_api::Insert(string str)
{
    //首先判断是哪种插入语句
    int a = str.find_first_of("(");
    int b = str.find_last_of("(");
    
    if(a == b){
        vector<string> strs;
        string str1;
        string tb_name;
        string last_inf;
        string first_inf;
        
        int t1 = str.find(",");//括号中所有数据字符串
        int t2 = str.find_last_of(",");
        str1 = str.substr(t1+1,t2-t1);
//         cout << str1;
        
        t1 = str.find_first_of("O"); //查找表名字
        t2 = str.find_first_of("V");
        tb_name = str.substr(t1+2, t2-t1-3);
        
        t1 = str.find_last_of(","); //查找最后一个表信息
        t2 = str.find_last_of(")");
        last_inf = str.substr(t1+2,t2-t1-2);
        
        t1 = str.find_first_of("("); //查找第一个信息
        t2 = str.find_first_of(",");
        first_inf = str.substr(t1+1, t2-t1-2);
//         cout << first_inf;
        
        
        int bj=0;
        int ej=0;
        while(ej = str1.find(",",bj))
        {
            if (ej<1)
            {
                break;
            }
            string tempCCre = str1.substr(bj+1,ej-bj-1);

            strs.push_back(tempCCre);//这里添加处理的代码，tempCCre就是获得的子串；

            bj = ej+1;
            ej = 0;
        }
//         for(auto it = strs.begin(); it != strs.end(); it++){
//             cout << "a" << *it << "v";
//         }
        
        string sql = "INSERT INTO ";
        sql += tb_name;
        sql += " VALUES";
        sql += " ('";
        sql += first_inf;
        sql += "',";
        for(int i = 0; i < strs.size(); i++){
            sql += "'";
            sql += strs[i];
            sql += "', ";
        }
        sql += "'";
        sql += last_inf;
        sql += "')";
        cout << sql;
        
        int ret =mysql_query(conn,sql.c_str());
        if(ret != 0)
        {
            return false;
        }
        
        string my_path = "../m/";
        my_path += tb_name;
        my_path += ".txt";
        cout << my_path;
        //创建TXT文件
        ofstream fout(my_path, ios::app);
        if (fout) { // 如果创建成功
            fout << first_inf << " ";
            for(auto it = strs.begin(); it !=strs.end(); it++){
                fout << *it << " ";
            }
            fout << last_inf;
            fout << endl;
            fout.close(); // 执行完操作后关闭文件句柄
        }else{
            cout << "文件写入失败";
        }
        
        return true;
        
    }else{
        int t1 = str.find_first_of("(");//第一个括号
        int t2 = str.find_first_of(")");
        string s = str.substr(t1, t2-t1+1);
        
        int t3 = str.find_last_of("(");//第二个括号
        int t4 = str.find_last_of(")");
        string s1 = str.substr(t3,t4-t3+1);
//         cout << s1;
        
        t1 = str.find_first_of("O"); //查找表名字
        t2 = str.find_first_of("(");
        string tb_name = str.substr(t1+2, t2-t1-3);
        
        t3 = s1.find_first_of(",");//第二个括号中两个逗号间数据
        t4 = s1.find_last_of(",");
        string s2 = s1.substr(t3+1,t4-t3+1);
//         cout << s2;
        
        t1 = s1.find_last_of(","); //查找最后一个表信息
        t2 = s1.find_last_of(")");
        string last_inf = s1.substr(t1+2,t2-t1-2);
//         cout << "a" << last_inf;
        
        t1 = s1.find_last_of("("); //查找第一个信息
        t2 = s1.find_first_of(",");
        string first_inf = s1.substr(t1+1, t2-t1-1);
//         cout << "a" << first_inf;
        
        vector<string> strs1;//保存第二个括号内的所有数据
        
        int bj=0;
        int ej=0;
        while(ej = s2.find(",",bj))
        {
            if (ej<1)
            {
                break;
            }
            string tempCCre = s2.substr(bj+1,ej-bj-1);

            strs1.push_back(tempCCre);//这里添加处理的代码，tempCCre就是获得的子串；

            bj = ej+1;
            ej = 0;
        }
        
//         for(auto it = strs1.begin(); it != strs1.end(); it++){
//             cout << "a" << *it << "v";
//         }
        string sql = "INSERT INTO ";
        sql += tb_name;
        sql += s;
        sql += " VALUES";
        sql += " ('";
        sql += first_inf;
        sql += "',";
        for(int i = 0; i < strs1.size(); i++){
            sql += "'";
            sql += strs1[i];
//             cout << strs1[i];
            sql += "', ";
        }
        sql += "'";
        sql += last_inf;
        sql += "')";
        cout << sql;
        
        int ret =mysql_query(conn,sql.c_str());
        if(ret != 0)
        {
            return false;
        }
        
        string my_path = "../m/";
        my_path += tb_name;
        my_path += ".txt";
        cout << my_path;
        //创建TXT文件
        ofstream fout(my_path, ios::app);
        if (fout) { // 如果创建成功
            fout << first_inf << " ";
            for(auto it = strs1.begin(); it !=strs1.end(); it++){
                fout << *it << " ";
            }
            fout << last_inf;
            fout << endl;
            fout.close(); // 执行完操作后关闭文件句柄
        }else{
            cout << "文件写入失败";
        }
        return true;
    }
}


//删除数据
bool sql_api::Delete(string str)
{
    int flag = 0;
    flag = str.find("*");
//     cout << flag;
    if(flag == -1){
        int len = str.length();
        int t1 = str.find("=");
        string str1 = str.substr(t1+2, len-t1-2);
    //     cout << str1;
        int t2 = str.find("D");//截取前面的语句
        int t3 = str.find_last_of("E");
        string str2 = str.substr(t2, t3-t2+2);
    //     cout << str2;
        int t4 = str.find_first_of("M"); //获取表名相邻数据
        int t5 = str.find_first_of("=");
        string tempCCre = str.substr(t4+2, t5-t4-1);
//         cout << tempCCre;
        
        int bj=0;
        int ej=0;
        string tb_name;
        while(ej = tempCCre.find(" ",bj))
        {
            if (ej<1)
            {
                break;
            }
            tb_name = tempCCre.substr(bj,ej-bj);

//             strs.push_back(tb_name);//这里添加处理的代码，tempCCre就是获得的子串；
            break;
//             bj = ej+1;
//             ej = 0;
        }
        cout << tb_name;
        
        
        string str3 = str.substr(t3+2, t1-t3-3);//WHERE后面的到=前面的内容
    //     cout << str3;
        str2 += str3;
        str2 += " = '";
        str2 += str1;
        str2 += "'";
        
        int ret =mysql_query(conn,str2.c_str());
        if (ret != 0)
        {
            return false;
        }
/*************************************/
//更新文本文件
        string select = "SELECT *FROM Student";

        int ret1 =mysql_query(conn,select.c_str());
        if (ret1 != 0)
        {
            return false;
        }

        MYSQL_RES *res =mysql_store_result(conn);
        //"id" "name" "age" "sex" "school"
        if (res == NULL){
            return false;
        }
        
        int num_fields =mysql_num_fields(res);//行数
        MYSQL_FIELD *field ;//
        MYSQL_ROW rows;//结果集的下一行


        string my_path = "../m/";
        my_path += tb_name;
        my_path += ".txt";
        ofstream fout(my_path, ios::trunc);
        if (fout) { // 如果创建成功
            while(field = mysql_fetch_field(res))
            {
                fout<<field->name<<' ';
            }
            fout << endl;
            while(rows = mysql_fetch_row(res))
            {
                int i=0;
                for(i=0;i<num_fields;i++)
                {
                    fout<<rows[i]<<' ';
                }
                fout<<endl;
            }
            fout.close(); // 执行完操作后关闭文件句柄
        }else{
            cout << "文件写入失败";
        }
        
        mysql_free_result(res);
        return true;
    }else{
        int t2 = str.find("D");//截取前面的语句
        int t3 = str.find_first_of("*");
        string str2 = str.substr(t2, t3-t2);
//         cout << str2 << endl;
        
        int len = str.length();
        int t1 = str.find("*");
        string str1 = str.substr(t1+2, len-t1-2);
//         cout << str1;
        str2 += str1;
//         cout << str2;
        
        int t4 = str.find_first_of("M");
        string tb_name = str.substr(t4+2, len-t4+1);
        cout << tb_name;
        
        int ret =mysql_query(conn,str2.c_str());
        if (ret != 0)
        {
            return false;
        }

/*************************************/
//更新文本文件
        string select = "SELECT *FROM Student";

        int ret1 =mysql_query(conn,select.c_str());
        if (ret1 != 0)
        {
            return false;
        }

        MYSQL_RES *res =mysql_store_result(conn);
        //"id" "name" "age" "sex" "school"
        if (res == NULL){
            return false;
        }
        
        int num_fields =mysql_num_fields(res);//行数
        MYSQL_FIELD *field ;//
        MYSQL_ROW rows;//结果集的下一行


        string my_path = "../m/";
        my_path += tb_name;
        my_path += ".txt";
        ofstream fout(my_path, ios::trunc);
        if (fout) { // 如果创建成功
            while(field = mysql_fetch_field(res))
            {
                fout<<field->name<<' ';
            }
            fout << endl;
            while(rows = mysql_fetch_row(res))
            {
                int i=0;
                for(i=0;i<num_fields;i++)
                {
                    fout<<rows[i]<<' ';
                }
                fout<<endl;
            }
            fout.close(); // 执行完操作后关闭文件句柄
        }else{
            cout << "文件写入失败";
        }
        
        mysql_free_result(res);
        return true;
    }

}

//查询
bool sql_api::Select_easy(string str)
{
    int flag = str.find("=");
//     cout <<!flag;
    if(flag == -1){
        int ret =mysql_query(conn,str.c_str());
        if (ret != 0)
        {
            return false;
        }

        MYSQL_RES *res =mysql_store_result(conn);
        //"id" "name" "age" "sex" "school"
        if (res == NULL){
            return false;
        }
        int num_fields =mysql_num_fields(res);//行数
        MYSQL_FIELD *field ;//
        MYSQL_ROW rows;//结果集的下一行
        while(field = mysql_fetch_field(res))
        {
            cout<<field->name<<' ';
        }
        cout<<endl;
        while(rows = mysql_fetch_row(res))
        {
            int i=0;
            for(i=0;i<num_fields;i++)
            {
                cout<<rows[i]<<' ';
            }
            cout<<endl;
        }
    mysql_free_result(res);
    return true;
    }else{
        int a = str.find_last_of(".");
//         cout << a;
        if(a == -1){ //如果后面不是带有添加进TXT文件的语句
            int t1 = str.find("S");//截取前面的语句
            int t2 = str.find_last_of("=");
            string str1 = str.substr(t1, t2-t1+2);
//             cout << str1; 
            
            int len = str.length();
            int t3 = str.find("=");
            string str2 = str.substr(t3+2, len-t3-2);
//             cout << str2; //查询的value
            
            str1 += "'";
            str1 += str2;
            str1 += "'";
//             cout << str1;
            
            int ret =mysql_query(conn,str1.c_str());
            if (ret != 0)
            {
                return false;
            }
            
            MYSQL_RES *res =mysql_store_result(conn);
            //"id" "name" "age" "sex" "school"
            if (res == NULL){
                return false;
            }
            int num_fields =mysql_num_fields(res);//行数
            MYSQL_FIELD *field ;//
            MYSQL_ROW rows;//结果集的下一行
            while(field = mysql_fetch_field(res))
            {
                cout<<field->name<<' ';
            }
            cout<<endl;
            while(rows = mysql_fetch_row(res))
            {
                int i=0;
                for(i=0;i<num_fields;i++)
                {
                    cout<<rows[i]<<' ';
                }
                cout<<endl;
            }
            mysql_free_result(res);
            return true;
        }else{  //如果后面是带有添加进TXT文件的语句
            int t1 = str.find("S");//截取前面的语句
            int t2 = str.find_last_of("=");
            string str1 = str.substr(t1, t2-t1+2);
//             cout << str1; 
            
            int t6 = str.find_last_of(" ");;
            int t3 = str.find("=");
            string str2 = str.substr(t3+2, t6-t3-5);
//             cout << str2; //查询的value
            
            str1 += "'";
            str1 += str2;
            str1 += "'";
            
            
            int t4 = str.find_last_of(" "); //查找生成的txt文件的名字
            int t5 = str.find_last_of("t");
            string txt_name = str.substr(t4+1,t5-t4);      
//             cout << txt_name;
            
            int ret =mysql_query(conn,str1.c_str()); //执行sql语句
            if (ret != 0)
            {
                return false;
            }
            
            MYSQL_RES *res =mysql_store_result(conn);
            //"id" "name" "age" "sex" "school"
            if (res == NULL){
                return false;
            }
            
            int num_fields =mysql_num_fields(res);//行数
            MYSQL_FIELD *field ;//
            MYSQL_ROW rows;//结果集的下一行
            
            string my_path = "../m/";
            my_path += txt_name;

            cout << my_path;
            //创建TXT文件
            ofstream fout(my_path, ios::app);
            if (fout) { // 如果创建成功
                while(field = mysql_fetch_field(res))
                {
                    fout<<field->name<<' ';
                }
                fout << endl;
                while(rows = mysql_fetch_row(res))
                {
                    int i=0;
                    for(i=0;i<num_fields;i++)
                    {
                        fout<<rows[i]<<' ';
                    }
                    fout<<endl;
                }
                fout.close(); // 执行完操作后关闭文件句柄
            }else{
                cout << "文件写入失败";
            }
            
            mysql_free_result(res);
            return true;
            
        }

    }
}

//查找数据
bool sql_api::Select()
{
    string sql="SELECT * FROM myhttp_info;";
    int ret = mysql_query(conn,sql.c_str());
    if (ret != 0)
    {
        return false;
    }
        MYSQL_RES *res =mysql_store_result(conn);
        //"id" "name" "age" "sex" "school"
        if (res == NULL)
        {
            return false;
        }
        int num_fields =mysql_num_fields(res);//行数
        MYSQL_FIELD *field ;//
        MYSQL_ROW rows;//结果集的下一行
        while(field = mysql_fetch_field(res))
        {
            cout<<field->name<<' ';
        }
        cout<<endl;
        while(rows = mysql_fetch_row(res))
        {
            int i=0;
            for(i=0;i<num_fields;i++)
            {
                cout<<rows[i]<<' ';
            }
            cout<<endl;
        }
    mysql_free_result(res);
    return true;
}


 
