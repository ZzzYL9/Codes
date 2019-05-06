#include "database.h"


//连接数据库
DataBase::DataBase(QString name)
{
       db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
       DB_conn(name);
       DB_create();
}
bool DataBase::DB_conn(QString name)
{

    db->setHostName("localhost");
    db->setDatabaseName(name);
    db->setUserName("root");
    db->setPassword("root");

    if(!db->open()){
        qDebug() << "数据库打开失败";
        return false;
    }
    else{
        qDebug() << "数据库打开成功";
    }
    return true;
}


//创建基本表(验证)
void DataBase::DB_create()
{
    query = new QSqlQuery;

    //超级管理员登录表
    QString create_super = "create table Super_log (man_id char(11) primary key NOT NULL, man_name char(50) NOT NULL, man_passwd char(30) NULL , man_IDcard char(18) NULL , man_tel char(11) NULL );";
    query->prepare(create_super);
    if(!query->exec(create_super)){
        qDebug() << "query error(Super_log_tb):" << query->lastError();
    }else{
        qDebug() << "create Super_log_tb successfully";
        QString str = "insert into Super_log values ('1', '老板', 'root', '1234567890', '13370723641')";
//        query->clear();
        query->prepare(str);
        query->exec(str);
    }

    //普通管理员登录表
    QString create_manger = "create table Mangers_log (man_id char(11) primary key NOT NULL, man_name char(50) NOT NULL, man_passwd char(30) NULL , man_IDcard char(18) NULL , man_tel char(11) NULL );";
    query->prepare(create_manger);
    bool success = query->exec(create_manger);
    if(!success){
        qDebug() << "query error(Mangers_tb):" << query->lastError();
    }else{
        qDebug() << "create Mangers_log_tb successfully";
    }

    //管理员权限表
    //管理员名字/住宿登记/调房登记/追加押金/退宿结账/预定查询/登记查询/退宿查询/报表查询
    //show full columns from Quanxian 语句查询数据库中的注释
    QString create_quanxian = "create table Quanxian (man_name char(50) NULL comment '管理员名字', zs int(1) comment '住宿登记', tf int(1) comment '调房登记', yj int(1) comment '追加押金', tsjiezhang int(1) comment '退宿结账', yd_find int(1) comment '预定查询', dj_find int(1) comment '登记查询', ts_find int(1) comment '退宿查询', baobiao int(1) comment '报表查询')";
    if(!query->exec(create_quanxian)){
        qDebug() << "query error(Quanxian_tb): " << query->lastError();
    }else{
        qDebug() << "create Quanxian_tb successfully";
        DB_quanxian("老板",1,1,1,1,1,1,1,1);
    }


    //客户表
//    QString create_customers = "create table Customers (cus_roomid int(4) NOT NULL, cus_name char(50) NOT NULL, cus_IDcard char(18) primary key NULL , cus_yajin char(20) NULL , cus_total char(20) NULL , cus_in_date char(30) NULL , cus_pay_date char(30) NULL ,cus_tel char(11) NULL );";
//    if(!query->exec(create_customers)){
//        qDebug() << "query error(Customers_tb): " << query->lastError();
//    }else{
//        qDebug() << "create Customers_tb successfully";
//    }

    //房间状态表(总房间信息表)
    QString create_status = "create table Room_status (room_id int(4) NULL , status char(15) NULL );";
    if(!query->exec(create_status)){
        qDebug() << "query error(Customers_tb): " << query->lastError();
    }else{
        QString s = "空闲";
        for(int i = 0; i < 10; i++){
            query->clear();
            query->prepare("insert into Room_status values (?,?)");
            query->bindValue(0, i);
            query->bindValue(0, s);
            query->exec();
        }
        qDebug() << "create Room_status_tb successfully";
    }

    //预定房间表
    QString create_rooms = "create table Rooms (room_no int(4) primary key NOT NULL, room_name char(20) NOT NULL, room_IDcard char(18) NULL , room_fangfei int(11) NULL , room_tel char(11) NULL , room_type char(10) NOT NULL, room_price int(11) NULL , room_status char(15) NULL , room_orderdate char(30) NULL , room_in_time char (30) NULL, room_out_time char(30) NULL , days int(11) NULL );";
    if(!query->exec(create_rooms)){
        qDebug() << "query error(Rooms_tb): " << query->lastError();
    }else{
        qDebug() << "create Rooms_tb successfully";
    }

    //住宿登记表
    QString create_zhusudengji = "create table Zhusudengji (z_roomid int(4) NULL , z_name char(20) NULL , z_IDcard char(18) primary key NULL , z_yajin int(11) NULL , z_fangfei int(11) NULL , z_tel char(11) NULL , z_room_type char(10) NULL , z_price int(11) NULL , z_status char(15) NULL , z_in_date char(30) NULL , z_out_date char(30) NULL , z_days int(11) NULL );";
    if(!query->exec(create_zhusudengji)){
        qDebug() << "query error(Customers_tb): " << query->lastError();
    }else{
        qDebug() << "create Zhusudengji_tb successfully";
    }

    //退宿表
    QString create_quit = "create table Quit (q_name char(20) NULL , q_roomid int(4) NULL , q_type char(10) NULL , q_price int(11) NULL , q_in_date char(30) NULL , q_out_date char(30) NULL , q_days int(11) NULL , q_total_pay int(11) NULL );";
    if(!query->exec(create_quit)){
        qDebug() << "query error(Customers_tb): " << query->lastError();
    }else{
        qDebug() << "create Quit_tb successfully";
    }

    //挂账表
    QString create_guazhang = "create table Guazhang (room_no int(4) primary key NOT NULL, room_name char(20) NOT NULL, room_IDcard char(18) NULL , room_yajin int(11) NULL , room_total int(11) NULL , room_tel char(11) NULL , room_type char(10) NOT NULL, room_price int(11) NULL , room_status char(15) NULL , room_orderdate char(30) NULL , room_in_time char(30) NULL , room_out_time char(30) NULL , room_days int(11) NULL );";
    if(!query->exec(create_guazhang)){
        qDebug() << "query error(Guazhang_tb): " << query->lastError();
    }else{
        qDebug() << "create Guazhang_tb successfully";
    }

    //登记预收报表
    QString create_baobiao = "create table Baobiao (room_id int(4) NULL , room_type char(10) NULL , room_price int(4) NULL ,room_totalpay int(11) NULL , date char(30) NULL );";
    if(!query->exec(create_baobiao)){
        qDebug() << "query error(Baobiao_tb): " << query->lastError();
    }else{
        qDebug() << "create Baobiao_tb successfully";
    }

    //账单表
    QString create_payment = "create table Payment (pay_ID int(4) NULL , pay_room_no int(5) NULL , pay_room_type char(10) NULL , pay_in_date char(30) NULL , pay_end_date char(30) NULL , pay_money int(11) NULL , today char(20) NULL );";
    if(!query->exec(create_payment)){
        qDebug() << "query error(Payment_tb): " << query->lastError();
    }else{
        query->exec("insert into Payment values (0, NULL, NULL, NULL, NULL, NULL)");
        qDebug() << "create Payment_tb successfully";
    }
}



//登录(已验证)
bool DataBase::DB_log(QString id, QString pwd, QString &name, int &zs, int &tf, int &yj, int &tsjiezhang, int &yd_find, int &dj_find, int &ts_find, int &baobiao)
{
    query = new QSqlQuery;
    query->prepare("select man_name from Super_log where man_id = ? and man_passwd = ?");
    query->bindValue(0, id);
    query->bindValue(1, pwd);
    if(!query->exec())
    {
        qDebug()<<QObject::tr("查询超级管理者语句失败")<<query->lastError();
        return 0;
    }
    if(!query->next()){
//        qDebug() << "登录失败, 账户或密码错误";
        query->clear();
        query->prepare("select man_name from Mangers_log where man_id = ? and man_passwd = ?");
        query->bindValue(0, id);
        query->bindValue(1, pwd);
        if(!query->exec())
        {
            qDebug()<<QObject::tr("查询普通管理者语句失败")<<query->lastError();
            return 0;
        }
        if(!query->next()){
            qDebug() << "登录失败, 账户或密码错误";
            return 0;
        }else {
            qDebug() << "登录普通管理员成功";
            name = query->value(0).toString();
            query->prepare("select *from Quanxian where man_name = ?");
            query->bindValue(0, name);
            query->exec();
            if(query->next()){
                zs = query->value(1).toInt();
                tf = query->value(2).toInt();
                yj = query->value(3).toInt();
                tsjiezhang = query->value(4).toInt();
                yd_find = query->value(5).toInt();
                dj_find = query->value(6).toInt();
                ts_find = query->value(7).toInt();
                baobiao = query->value(8).toInt();
            }
        }
    }
    else{
        qDebug() << "登录超级管理员成功";
        name = query->value(0).toString();
        query->prepare("select *from Quanxian where man_name = ?");
        query->bindValue(0, name);
        query->exec();
        if(query->next()){
            zs = query->value(1).toInt();
            tf = query->value(2).toInt();
            yj = query->value(3).toInt();
            tsjiezhang = query->value(4).toInt();
            yd_find = query->value(5).toInt();
            dj_find = query->value(6).toInt();
            ts_find = query->value(7).toInt();
            baobiao = query->value(8).toInt();
        }
    }
    return 1;
}

//添加管理员(已验证)
bool DataBase::DB_add(QString man_id, QString man_name, QString man_passwd, QString man_IDcard, QString man_tel)
{
    query = new QSqlQuery;
    query->prepare("select *from Super_log where man_id = ?");
    query->exec();
    if(!query->next()){
        query->clear();
        query->prepare("insert into Mangers_log values(?,?,?,?,?)");
        query->bindValue(0, man_id);
        query->bindValue(1, man_name);
        query->bindValue(2, man_passwd);
        query->bindValue(3, man_IDcard);
        query->bindValue(4, man_tel);
        if(!query->exec())
        {
            qDebug()<<QObject::tr("用户添加失败")<<query->lastError();
            return -1;
        }
         qDebug()<<QObject::tr("用户添加成功");
         DB_quanxian(man_name, 0, 0, 0, 0, 0, 0, 0, 0);
    }else {
        qDebug() << "此工号已被注册";
        return 0;
    }

    return 1;
}

//房态显示(已验证)
bool DataBase::DB_room_status(QVector<int> &no_s, QVector<QString> &status_s)
{
    int no;
    QString status;
    query = new QSqlQuery;
    query->prepare("select *from Room_status");
    if(!query->exec()){
        qDebug()<<QObject::tr("客房显示语句出错");
        return -1;
    }
    while(query->next()){
        no = query->value(0).toInt();
        status = query->value(1).toString();

        no_s.push_back(no);
        status_s.push_back(status);
    }

    return 1;
}

//客房管理查询(房态查询)(已验证)
bool DataBase::DB_room_manger(int no, QString &status)
{
    query = new QSqlQuery;
    query->prepare("select *from Room_status where room_id = ?");
    query->bindValue(0, no);
    if(!query->exec()){
        qDebug()<<QObject::tr("查询客房语句错误");
        return -1;
    }
    if(query->next()){
        status = query->value(1).toString();
    }else{
        qDebug() << "没有此房间状态信息";
        return -1;
    }
    return 1;
}

//房间预定(已验证)
bool DataBase::DB_order(int no,QString cus_name, QString cus_IDcard, int fangfei, QString cus_tel, QString type, int price, QString status, QString orderdate, QString indate, QString outdate, int days, QString today)
{
    query = new QSqlQuery;

    query->prepare("select *from Room_status where room_id = ?");
    query->bindValue(0, no);
    if(!query->exec()){
        qDebug() << QObject::tr("查询房间状态表失败") << query->lastError();
        return 0;
    }
    if(query->next()){
        if(query->value(1).toString() != "空闲"){
            qDebug()<<QObject::tr("房间有人了");
            return 0;
        }else{
            query->prepare("update Room_status set status = '已预订' where room_id = ?");
            query->bindValue(0, no);
//            query->clear();
//            query->prepare("update Rooms set room_status = '已预订' where room_no = ?");
//            query->bindValue(0, no);
            if(!query->exec()){
                qDebug() << QObject::tr("预定失败");
                return -1;
            }else{
                query->clear();
                query->prepare("insert into Rooms values(?,?,?,?,?,?,?,?,?,?,?,?)");
                query->bindValue(0, no);
                query->bindValue(1, cus_name);
                query->bindValue(2, cus_IDcard);
                query->bindValue(3, fangfei);
                query->bindValue(4, cus_tel);
                query->bindValue(5, type);
                query->bindValue(6, price);
                query->bindValue(7, status);
                query->bindValue(8, orderdate);
                query->bindValue(9, indate);
                query->bindValue(10, outdate);
                query->bindValue(11, days);
                if(!query->exec()){
                    qDebug() << "预定语句出错" << query->lastError();
                }

                //将预订房出租情况插入到报表表中
                query->clear();
                query->prepare("insert into Baobiao values (?,?,?,?,?)");
                query->bindValue(0, no);
                query->bindValue(1, type);
                query->bindValue(2, price);
                query->bindValue(3, fangfei);
                query->bindValue(4, today);
                query->exec();

                qDebug() << QObject::tr("预定成功");
            }
        }
    }
    return 1;
}

//二改!!!
//住宿登记时,在预定表中查询是否存在身份证号
//如果存在就将客户信息从预定表改到住宿登记表
int DataBase::DB_is_order(QString IDcard, int yajin)
{
    int room_id;
    QString name;
    int fangfei;
    QString tel;
    QString type;
    int price;
    QString status;
    QString orderdate;
    QString indate;
    QString outdate;
    int days;

    query = new QSqlQuery;
    query->prepare("select *from Rooms where room_IDcard = ?");
    query->bindValue(0, IDcard);
    if(!query->exec()){
        qDebug() << "查询身份证号语句错误" << query->lastError();
        return -1;
    }else {
        if(query->next()){
            qDebug() << "该客户已经预定了房间";
            room_id = query->value(0).toInt();
            name = query->value(1).toString();
            IDcard = query->value(2).toString();
            fangfei = query->value(3).toInt();
            tel = query->value(4).toString();
            type = query->value(5).toString();
            price = query->value(6).toInt();
            status = query->value(7).toString();
            orderdate = query->value(8).toString();
            indate = query->value(9).toString();
            outdate = query->value(10).toString();
            days = query->value(11).toInt();

            query->clear();
            query->prepare("insert into Zhusudengji values (?,?,?,?,?,?,?,?,?,?,?,?)");
            query->bindValue(0, room_id);
            query->bindValue(1, name);
            query->bindValue(2, IDcard);
            query->bindValue(3, yajin);
            query->bindValue(4, fangfei);
            query->bindValue(5, tel);
            query->bindValue(6, type);
            query->bindValue(7, price);
            query->bindValue(8, status);
            query->bindValue(9, indate);
            query->bindValue(10, outdate);
            query->bindValue(11, days);
            if(!query->exec()){
                qDebug() << "插入住宿语句错误" << query->lastError();
                return -1;
            }
            query->clear();
            query->prepare("update Room_status set status = '已入住' where room_id = ?");
            query->bindValue(0, room_id);
            if(!query->exec())
            {

                qDebug() << "更新错误" << query->lastError();
                return -1;

            }
            query->clear();
            query->prepare("delete from Rooms where room_no = ?");
            query->bindValue(0, room_id);
            query->exec();
            return room_id;
        }else
            return -1;
    }
}

//住宿登记(已验证) 注意!身份证号不能两次输入相同的(一改)
bool DataBase::DB_zhusu(int id, QString name, QString IDcard, int yajin, int fangfei, QString tel, QString type, int price, QString status, QString in_date, QString out_date, int days, QString today)
{
    int total;
    total = (price * days) + yajin;
    query = new QSqlQuery;
    query->prepare("select *from Room_status where room_id = ?");
    query->bindValue(0, id);
    if(!query->exec()){
        qDebug() << QObject::tr("查询房间状态表失败") << query->lastError();
        return -1;
    }
    if(query->next()){
        if(query->value(1).toString() != "空闲"){
            qDebug()<<QObject::tr("房间有人了");
            return -1;
        }else{
            query->clear();
            query->prepare("insert into Zhusudengji values (?,?,?,?,?,?,?,?,?,?,?)");
            query->bindValue(0, id);
            query->bindValue(1, name);
            query->bindValue(2, IDcard);
            query->bindValue(3, yajin);
            query->bindValue(4, fangfei);
            query->bindValue(5, tel);
            query->bindValue(6, type);
            query->bindValue(7, price);
            query->bindValue(8, status);
            query->bindValue(9, in_date);
            query->bindValue(10, out_date);
            query->bindValue(11, days);

            if(!query->exec()){
                qDebug() << QObject::tr("入住插入语句错误") << query->lastError();
                return -1;
            }else{
                query->clear();
                query->prepare("insert into Baobiao values (?,?,?,?,?)");
                query->bindValue(0, id);
                query->bindValue(1, type);
                query->bindValue(2, price);
                query->bindValue(3, total);
                query->bindValue(4, today);
                query->exec();

                query->clear();
                query->prepare("update Room_status set status = '已入住' where room_id = ?");
                query->bindValue(0, id);
                if(!query->exec()){
                    qDebug() << QObject::tr("入住失败");
                    return -1;
                }

                qDebug() << QObject::tr("入住成功");
            }
        }
    }
    else {
        qDebug() << QObject::tr("房间不存在");
        return -1;
    }
    return 1;
//        else if(query->value(1).toString() == "已预订"){
//            query->clear();
//            query->prepare("select *from Rooms where room_IDcard = ?");
//            query->bindValue(0, IDcard);
//            if(!query->exec()){
//                qDebug() << QObject::tr("入住插入语句错误");
//                return -1;
//            }
//            if(query->next()){
//                if(query->value(2).toString() == IDcard){

//                }
//            }
//        }

}
bool DataBase::inf_change(QString id, QString name, QString pwd, QString IDcard, QString tel)
{
    query = new QSqlQuery;
    query->prepare("select *from Super_log where man_id = ?");
    query->bindValue(0, id);
    if(!query->exec()){
        qDebug() << QObject::tr("查询管理员语句错误（超管修改）") << query->lastError();
        return 0;
    }
    if(query->next()){
        query->clear();
        query->prepare("update Super_log set man_name = ?, man_passwd = ?, man_IDcard = ?, man_tel = ? where man_id = ?");
        query->bindValue(0, name);
        query->bindValue(1, pwd);
        query->bindValue(2, IDcard);
        query->bindValue(3, tel);
        query->bindValue(4, id);
        if(!query->exec()){
            qDebug() << QObject::tr("更新管理员语句错误（修改）") << query->lastError();
            return 0;
        }
    }else{
        query->clear();
        query->prepare("select *from Mangers_log where man_id = ?");
        query->bindValue(0, id);
        if(!query->exec()){
            qDebug() << QObject::tr("查询管理员语句错误（普管修改）") << query->lastError();
            return 0;
        }
        if(query->next()){
            query->clear();
            query->prepare("update Mangers_log set man_name = ?, man_passwd = ?, man_IDcard = ?, man_tel = ? where man_id = ?");
            query->bindValue(0, name);
            query->bindValue(1, pwd);
            query->bindValue(2, IDcard);
            query->bindValue(3, tel);
            query->bindValue(4, id);
            if(!query->exec()){
                qDebug() << QObject::tr("更新管理员语句错误（修改）") << query->lastError();
                return 0;
            }
        }
    }
    return 1;
}
//初始化房间状态表
bool DataBase::DB_init_status()
{
    query = new QSqlQuery;
    query->prepare("update Room_status set status = '空闲'");
    if(!query->exec()){
        qDebug() << QObject::tr("初始化房间状态失败");
        return 0;
    }
    return 1;
}

//初始化
void DataBase::DB_init(int flag)
{

    switch (flag) {
    //初始化预定房间表
    case 1:
        query->exec("delete from Rooms");

    //初始化登记表
    case 2:
        query->exec("delete from Zhusudengji");

    //初始化退宿表
    case 3:
        query->exec("delete from Quit");

    //初始化管理员权限表
    case 4:
        query->exec("delete from Quanxian");

    //初始化挂账表
    case 5:
        query->exec("delete from Guazhang");

    //初始化报表
    case 6:
        query->exec("delete from Baobiao");

    //初始化账单表
    case 7:
        query->exec("delete from Payment");

    //初始化房间状态表
    case 8:
        DB_init_status();
    case 9:
            query->exec("delete from Mangers_log");

    default:
        break;
    }
}

//调房登记(已验证)(一改)
//调房登记(已验证)(一改)
bool DataBase::DB_tiaofang(int from_room, int to_room)
{
    QString name;
    QString IDcard;
    int yajin;
    QString tel;
    QString type;
    int price;
    QString status;
    QString indate;
    QString outdate;
    int days;
    int chajia;
    QString orderdate;

    query = new QSqlQuery;
    query->prepare("select status from Room_status where room_id = ?");
    query->bindValue(0, from_room);
    query->exec();
    if(query->next()){
        if(query->value(0).toString() == "已入住"){
            query->clear();
            query->prepare("select z_fangfei from Zhusudengji where z_roomid = ?");
            query->bindValue(0, from_room);
            if(!query->exec()){
                qDebug() << "房费查询错误(调房)" << query->lastError();
                return 0;
            }
            if(query->next()){
                chajia += query->value(0).toInt();
            }

            QString str1 = "空闲";

            query->clear();
            query->prepare("select *from Room_status where room_id = ?");
            query->bindValue(0, to_room);
            if(!query->exec()){
                qDebug() << QObject::tr("调房失败") << query->lastError();
                return -1;
            }
            if(query->next()){
                QString str2 = query->value(1).toString();
                if(str2.compare(str1) != 0){
                    qDebug() << QObject::tr("调房失败(房间有人了)") << query->lastError();
                    return -1;
                }else{
                    query->clear();
                    query->prepare("select *from Zhusudengji where z_roomid = ?");
                    query->bindValue(0, from_room);
                    query->exec();
                    if(query->next()){
                        name = query->value(1).toString();
                        IDcard = query->value(2).toString();
                        yajin = query->value(3).toInt();
                        tel = query->value(5).toString();
                        type = query->value(6).toString();
                        price = query->value(7).toInt();
                        status = query->value(8).toString();
                        indate = query->value(9).toString();
                        outdate = query->value(10).toString();
                        days = query->value(11).toInt();
                    }

                    query->clear();
                    //更新房间状态表
                    query->prepare("update Room_status set status = '空闲' where room_id = ?");
                    query->bindValue(0, from_room);
                    query->exec();
                    query->clear();
                    //更新住宿登记表信息
                    query->prepare("update Zhusudengji set z_roomid = ?, z_name = ?, z_IDcard = ?, z_yajin = ?, z_fangfei = ?, z_tel = ?, z_room_type = ?, z_price = ?, z_status = ?, z_in_date = ?, z_out_date = ?, z_days = ? where z_roomid = ? and z_name = ?");
                    query->bindValue(0, to_room);
                    query->bindValue(1, name);
                    query->bindValue(2, IDcard);
                    query->bindValue(3, yajin);
                    query->bindValue(4, chajia);
                    query->bindValue(5, tel);
                    query->bindValue(6, type);
                    query->bindValue(7, price);
                    query->bindValue(8, status);
                    query->bindValue(9, indate);
                    query->bindValue(10, outdate);
                    query->bindValue(11, days);
                    query->bindValue(12, from_room);
                    query->bindValue(13, name);
                    if(!query->exec()){
                        qDebug() << "更新住宿表出错(调房)" << query->lastError();
                        return 0;
                    }
                    query->clear();
                    query->prepare("delete from Zhusudengji where z_roomid = ?");
                    query->bindValue(0, from_room);
                    query->exec();
                    query->clear();
                    query->prepare("update Room_status set status = '已入住' where room_id = ?");
                    query->bindValue(0, to_room);
                    query->exec();

                    //更新挂帐表
                    query->clear();
                    query->prepare("select *from Guazhang where room_no = ?");
                    query->bindValue(0, from_room);
                    if(!query->exec()){
                        qDebug() << QObject::tr("查询挂帐表失败（调房）") << query->lastError();
                        return 0;
                    }
                    if(query->next()){
                        orderdate = query->value(9).toString();
                        query->clear();
                        query->prepare("update Guazhang set room_no = ?, room_name = ? , room_IDcard = ?, room_yajin = ?, room_total = ?, room_tel = ?, room_type = ?, room_price = ?, room_status = ?, room_orderdate = ?, room_in_time = ?, room_out_time = ?, room_days = ? where room_no = ?");
                        query->bindValue(0, to_room);
                        query->bindValue(1, name);
                        query->bindValue(2, IDcard);
                        query->bindValue(3, yajin);
                        query->bindValue(4, chajia);
                        query->bindValue(5, tel);
                        query->bindValue(6, type);
                        query->bindValue(7, price);
                        query->bindValue(8, status);
                        query->bindValue(9, orderdate);
                        query->bindValue(10, indate);
                        query->bindValue(11, outdate);
                        query->bindValue(12, days);
                        query->bindValue(13, from_room);
                        if(!query->exec()){
                            qDebug() << "更新挂帐表失败（调房）" << query->lastError();
                            return 0;
                        }
                        query->clear();
                        query->prepare("delete from Guazhang where room_no = ?");
                        query->bindValue(0, from_room);
                        query->exec();
                    }
                }
            }
        }else
            return 0;
    }
    qDebug() << QObject::tr("调房成功");
    return 1;
}

//普通管理员查询
bool DataBase::DB_info_man(QVector<int> &man_ids, QVector<QString> &man_names, QVector<QString> &passwds, QVector<QString> &IDcards, QVector<QString> &tels)
{
    query = new QSqlQuery;
    int id;
    QString name;
    QString passwd;
    QString IDcard;
    QString tel;
    query->prepare("select *from Mangers_log");
    if(!query->exec()){
        qDebug()<<QObject::tr("查询普通管理员语句失败")<<query->lastError();
        return 0;
    }
    while(query->next()){
        id = query->value(0).toInt();
        name = query->value(1).toString();
        passwd = query->value(2).toString();
        IDcard = query->value(3).toString();
        tel = query->value(4).toString();

        man_ids.push_back(id);
        man_names.push_back(name);
        passwds.push_back(passwd);
        IDcards.push_back(IDcard);
        tels.push_back(tel);
    }
    return 1;
}

//超级管理员查询
bool DataBase::DB_info_sup(QVector<int> &man_ids, QVector<QString> &man_names, QVector<QString> &passwds, QVector<QString> &IDcards, QVector<QString> &tels)
{
    query = new QSqlQuery;
    int id;
    QString name;
    QString passwd;
    QString IDcard;
    QString tel;
    query->prepare("select *from Super_log");
    if(!query->exec()){
        qDebug()<<QObject::tr("查询普通管理员语句失败")<<query->lastError();
        return 0;
    }
    while(query->next()){
        id = query->value(0).toInt();
        name = query->value(1).toString();
        passwd = query->value(2).toString();
        IDcard = query->value(3).toString();
        tel = query->value(4).toString();

        man_ids.push_back(id);
        man_names.push_back(name);
        passwds.push_back(passwd);
        IDcards.push_back(IDcard);
        tels.push_back(tel);
    }
    return 1;
}
//追加押金(已验证)(一改)
bool DataBase::DB_addyajin(int room_id, QString name, int zhuijia)
{
    int yajin;
    query = new QSqlQuery;
    query->prepare("select z_yajin from Rooms where z_roomid = ? and z_name = ?");
    query->bindValue(0, room_id);
    query->bindValue(1, name);
    if(!query->exec()){
        qDebug() << QObject::tr("查询语句错误(预定押金)");
        return -1;
    }
    if(query->next()){
        yajin = query->value(0).toInt();
        yajin += zhuijia;
        query->clear();
        query->prepare("update Zhusudengji set z_yajin = ? where room_id = ?");
        query->bindValue(0, yajin);
        query->bindValue(1, room_id);
        if(query->exec()){
            qDebug() << QObject::tr("追加押金失败");
            return -1;
        }
    }else{
            qDebug() << "房间不存在";
            return -1;
        }
    return 1;
}

//退宿结账(已验证)  ???

bool DataBase::DB_quit(QString &name, int &roomid, QString &type, int &price, QString &indate, QString &outdate, int &days, int &total, int &is_guan)
{
    query = new QSqlQuery;
//    int total;
    total = price*days;
    query->prepare("select *from Guazhang where room_no = ?");
    query->bindValue(0, roomid);
    if(!query->exec()){
        qDebug() << QObject::tr("查询挂账表错误(结账)失败") << query->lastError();
        return -1;
    }
    if(query->next())
        is_guan = 1; //如果挂账表有这个客户则返回0
    else
        is_guan = 0; //如果没有则返回0

    query->clear();
    query->prepare("select *from Quit where q_roomid=?");
    query->bindValue(0,roomid);
    if(!query->exec()){
        qDebug() << QObject::tr("查询住宿表错误(结账)失败") << query->lastError();
        return -1;
    }
    if(query->next()){
        name = query->value(0).toString();
        type = query->value(2).toString();
        price = query->value(3).toInt();
        indate = query->value(4).toString();
        outdate = query->value(5).toString();
        days = query->value(6).toInt();
    }

    query->clear();

    return 1;
}

bool DataBase::DB_quit_log(QString &name, int &roomid, QString &type, int &price, QString &indate, QString &outdate, int &days, QString &today, int &total)
{
    query = new QSqlQuery;
//    int total;
    total = price*days;

    query->prepare("select *from Quit where q_roomid=?");
    query->bindValue(0,roomid);
    if(!query->exec()){
        qDebug() << QObject::tr("查询住宿表错误(结账)失败") << query->lastError();
        return -1;
    }
    if(query->next()){
        name = query->value(0).toString();
        type = query->value(2).toString();
        price = query->value(3).toInt();
        indate = query->value(4).toString();
        outdate = query->value(5).toString();
        days = query->value(6).toInt();
    }

    query->clear();


    query->prepare("insert into Quit values(?,?,?,?,?,?,?,?)");
    query->bindValue(0, name);
    query->bindValue(1, roomid);
    query->bindValue(2, type);
    query->bindValue(3, price);
    query->bindValue(4, indate);
    query->bindValue(5, outdate);
    query->bindValue(6, days);
    query->bindValue(7, total);
    if(!query->exec()){
        qDebug() << QObject::tr("结账失败");
        return -1;
    }else{
        qDebug() << "支付" << total << "元";
    }

    query->clear();
    query->prepare("select *from Guazhang where room_no = ?");
    query->bindValue(0, roomid);
    if(!query->exec()){
        qDebug() << "查询挂账表错误" << query->lastError();
        return -1;
    }else{
        if(query->next()){
            query->clear();
            query->prepare("delete from Guazhang where room_no = ?");
            query->bindValue(0, roomid);
            query->exec();
        }
    }

    int payid = 0; //账单单号
    query->clear();
    //查询账单表中的最后一条数据的账单单号
    query->prepare("select *from Payment order by pay_ID desc limit 1");
    query->exec();
    if(query->next()){
        payid = query->value(0).toInt();
        payid++;
    }
    //将销售情况插入账单中
    query->clear();
    query->prepare("insert into Payment values (?,?,?,?,?,?,?)");
    query->bindValue(0, payid);
    query->bindValue(1, roomid);
    query->bindValue(2, type);
    query->bindValue(3, indate);
    query->bindValue(4, outdate);
    query->bindValue(5, total);
    query->bindValue(6, today);
    if(!query->exec()){
        qDebug() << "插入账单语句错误" << query->lastError();
    }

    query->clear();
    query->prepare("update Room_status set status = '空闲' where room_id = ?");
    query->bindValue(0, roomid);
    query->exec();

    query->clear();
    query->prepare("delete from Zhusudengji where z_roomid = ?");
    query->bindValue(0, roomid);
    query->exec();
    return 1;
}

//挂账入住(已验证)
bool DataBase::DB_guazhang(int room_no, QString room_name, QString IDcard, int room_yajin, QString room_tel, QString type, int price, QString room_status, QString orderdate, QString indate, QString out_date, int days)
{
    int room_total;
    room_total = price * days;
    query = new QSqlQuery;
    query->prepare("insert into Guazhang values(?,?,?,?,?,?,?,?,?,?,?,?,?)");
    query->bindValue(0, room_no);
    query->bindValue(1, room_name);
    query->bindValue(2, IDcard);
    query->bindValue(3, room_yajin);
    query->bindValue(4, room_total);
    query->bindValue(5, room_tel);
    query->bindValue(6, type);
    query->bindValue(7, price);
    query->bindValue(8, room_status);
    query->bindValue(9, orderdate);
    query->bindValue(10, indate);
    query->bindValue(11, out_date);
    query->bindValue(12, days);
    if(!query->exec()){
        qDebug() << QObject::tr("挂账失败")<<query->lastError();
        return -1;
    }
    query->clear();


    return 1;
}

//挂账查询(已验证)
bool DataBase::DB_guazhang_find(QVector<QString> &no_s, QVector<QString> &cus_name_s, QVector<QString> &cus_IDcard_s, QVector<int> &yajin_s, QVector<int> &total_s, QVector<QString> &cus_tel_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &status_s, QVector<QString> &ordertime_s, QVector<QString> &intime_s, QVector<QString> &outtime_s, QVector<int> &days_s)
{
    QString no;
    QString cus_name;
    QString cus_IDcard;
    int yajin;
    int total;
    QString cus_tel;
    QString type;
    int price;
    QString status;
    QString ordertime;
    QString intime;
    QString outtime;
    int days;

    query = new QSqlQuery;
    query->prepare("select *from Guazhang");
    if(!query->exec()){
        qDebug() << QObject::tr("查询语句错误");
        return -1;
    }
    while(query->next()){
        no = query->value(0).toString();
        cus_name = query->value(1).toString();
        cus_IDcard = query->value(2).toString();
        yajin = query->value(3).toInt();
        total = query->value(4).toInt();
        cus_tel = query->value(5).toString();
        type = query->value(6).toString();
        price = query->value(7).toInt();
        status = query->value(8).toString();
        ordertime = query->value(9).toString();
        intime = query->value(10).toString();
        outtime = query->value(11).toString();
        days = query->value(12).toInt();

        no_s.push_back(no);
        cus_name_s.push_back(cus_name);
        cus_IDcard_s.push_back(cus_IDcard);
        yajin_s.push_back(yajin);
        total_s.push_back(total);
        cus_tel_s.push_back(cus_tel);
        type_s.push_back(type);
        price_s.push_back(price);
        status_s.push_back(status);
        ordertime_s.push_back(ordertime);
        intime_s.push_back(intime);
        outtime_s.push_back(outtime);
        days_s.push_back(days);
    }
    return 1;
}

//预订房查询(输出所有数据)(已验证)
bool DataBase::DB_ordered_find(QVector<int> &no_s, QVector<QString> &cus_name_s, QVector<QString> &cus_IDcard_s, QVector<int> &fangfei_s, QVector<QString> &cus_tel_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &status_s, QVector<QString> &ordertime_s, QVector<QString> &intime_s, QVector<QString> &outtime_s, QVector<int> &days_s)
{
    int no;
    QString cus_name;
    QString cus_IDcard;
    int fangfei;
    QString cus_tel;
    QString type;
    int price;
    QString status;
    QString ordertime;
    QString intime;
    QString outtime;
    int days;

    query = new QSqlQuery;
    query->prepare("select *from Rooms");
    if(!query->exec()){
        qDebug() << QObject::tr("查询语句错误");
        return -1;
    }
    while(query->next()){
        no = query->value(0).toInt();
        cus_name = query->value(1).toString();
        cus_IDcard = query->value(2).toString();
        fangfei = query->value(3).toInt();
        cus_tel = query->value(4).toString();
        type = query->value(5).toString();
        price = query->value(6).toInt();
        status = query->value(7).toString();
        ordertime = query->value(8).toString();
        intime = query->value(9).toString();
        outtime = query->value(10).toString();
        days = query->value(11).toInt();

        no_s.push_back(no);
        cus_name_s.push_back(cus_name);
        cus_IDcard_s.push_back(cus_IDcard);
        fangfei_s.push_back(fangfei);
        cus_tel_s.push_back(cus_tel);
        type_s.push_back(type);
        price_s.push_back(price);
        status_s.push_back(status);
        ordertime_s.push_back(ordertime);
        intime_s.push_back(intime);
        outtime_s.push_back(outtime);
        days_s.push_back(days);
    }
    return 1;
}

//按照房间号查询(预订房)(已验证)
bool DataBase::DB_ordered_search(int &no, QString &cus_name, QString &cus_IDcard, int &fangfei, QString &cus_tel, QString &type, int &price, QString &status, QString &ordertime, QString &intime, QString &outtime, int &days)
{
    query = new QSqlQuery;
    query->prepare("select *from Rooms where room_no = ?");
    query->bindValue(0, no);
    if(!query->exec()){
        qDebug() << "预定表查询语句错误 " << query->lastError();
        return -1;
    }
    if(query->next()){
        no = query->value(0).toInt();
        cus_name = query->value(1).toString();
        cus_IDcard = query->value(2).toString();
        fangfei = query->value(3).toInt();
        cus_tel = query->value(4).toString();
        type = query->value(5).toString();
        price = query->value(6).toInt();
        status = query->value(7).toString();
        ordertime = query->value(8).toString();
        intime = query->value(9).toString();
        outtime = query->value(10).toString();
        days = query->value(11).toInt();
    }
    return 1;
}

//住宿查询(查询所有数据)(已验证)
bool DataBase::DB_zhusu_find(QVector<int> &roomid_s, QVector<QString> &name_s, QVector<QString> &IDcard_s, QVector<int> &yajin_s, QVector<int> fangfei_s, QVector<QString> &tel_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &status_s, QVector<QString> &indate_s, QVector<QString> &outdate_s, QVector<int> &days_s)
{
    int roomid;
    QString name;
    QString IDcard;
    int yajin;
    int fangfei;
    QString tel;
    QString type;
    int price;
    QString status;
    QString indate;
    QString outdate;
    int days;

    query = new QSqlQuery;
    query->prepare("select *from Zhusudengji");
    if(!query->exec()){
        qDebug() << QObject::tr("查询住宿语句出错");
        return -1;
    }
    while(query->next()){
        roomid = query->value(0).toInt();
        name = query->value(1).toString();
        IDcard = query->value(2).toString();
        yajin = query->value(3).toInt();
        fangfei = query->value(4).toInt();
        tel = query->value(5).toString();
        type = query->value(6).toString();
        price= query->value(7).toInt();
        status = query->value(8).toString();
        indate = query->value(9).toString();
        outdate = query->value(10).toString();
        days = query->value(11).toInt();

        roomid_s.push_back(roomid);
        name_s.push_back(name);
        IDcard_s.push_back(IDcard);
        yajin_s.push_back(yajin);
        fangfei_s.push_back(fangfei);
        tel_s.push_back(tel);
        type_s.push_back(type);
        price_s.push_back(price);
        status_s.push_back(status);
        indate_s.push_back(indate);
        outdate_s.push_back(outdate);
        days_s.push_back(days);

    }
    return 1;
}

//按照房间号查询(住宿)(已验证)
bool DataBase::DB_zhusu_search(int &room_id, QString &cus_name, QString &IDcard, int &yajin, int &fangfei, QString &tel, QString &type, int &price, QString &status, QString &indate, QString &outdate, int &days)
{
    query = new QSqlQuery;
    query->prepare("select *from Zhusudengji where z_roomid = ?");
    query->bindValue(0, room_id);
    if(!query->exec()){
        qDebug() << "登记表查询语句错误 " << query->lastError();
        return -1;
    }
    if(query->next()){
        room_id = query->value(0).toInt();
        cus_name = query->value(1).toString();
        IDcard = query->value(2).toString();
        yajin = query->value(3).toInt();
        fangfei = query->value(4).toInt();
        tel = query->value(5).toString();
        type = query->value(6).toString();
        price= query->value(7).toInt();
        status = query->value(8).toString();
        indate = query->value(9).toString();
        outdate = query->value(10).toString();
        days = query->value(11).toInt();

    }
    return 1;
}

//退宿查询(输出所有数据)(已验证)
bool DataBase::DB_quit_find(QVector<QString> &name_s, QVector<int> &roomid_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &indate_s, QVector<QString> &outdate_s, QVector<int> &days_s, QVector<int> &total_pay_s)
{
    QString name;
    int roomid;
    QString type;
    int price;
    QString indate;
    QString outdate;
    int days;
    int total_pay;

    query->prepare("select *from Quit");
    if(!query->exec()){
        qDebug() << QObject::tr("查询退宿语句出错");
        return -1;
    }
    while(query->next()){
        name = query->value(0).toString();
        roomid = query->value(1).toInt();
        type = query->value(2).toString();
        price = query->value(3).toInt();
        indate = query->value(4).toString();
        outdate = query->value(5).toString();
        days = query->value(6).toInt();
        total_pay = query->value(7).toInt();

        name_s.push_back(name);
        roomid_s.push_back(roomid);
        type_s.push_back(type);
        price_s.push_back(price);
        indate_s.push_back(indate);
        outdate_s.push_back(outdate);
        days_s.push_back(days);
        total_pay_s.push_back(total_pay);
    }
    return 1;
}

//按照房间号查询(退宿)(已验证)
bool DataBase::DB_quit_search(QString &name, int &roomid, QString &type, int &price, QString &indate, QString &outdate, int &days, int &total_pays)
{

    query->prepare("select *from Quit where q_roomid = ?");
    query->bindValue(0, roomid);
    if(!query->exec()){
        qDebug() << "退宿表查询语句错误 " << query->lastError();
        return -1;
    }
    if(query->next()){
        name = query->value(0).toString();
        roomid = query->value(1).toInt();
        type = query->value(2).toString();
        price = query->value(3).toInt();
        indate = query->value(4).toString();
        outdate = query->value(5).toString();
        days = query->value(6).toInt();
        total_pays = query->value(7).toInt();
    }
    return 1;
}

//销售报表查询(已验证)
bool DataBase::DB_baobiao(QVector<int> &room_ids, QVector<QString> &room_types, QVector<int> &room_prices, QVector<int> &room_totals, QVector<QString> &date_s, QString dates, int &rijie)
{
    int room_id;
    QString room_type;
    int price;
    int totalpay;
    QString date;
    rijie = 0;


    query->prepare("select *from Baobiao where date = ?");
    query->bindValue(0, dates);
    if(!query->exec()){
        qDebug() << "查询销售报表语句错误";
    }
    while(query->next()){
        room_id = query->value(0).toInt();
        room_type = query->value(1).toString();
        price = query->value(2).toInt();
        totalpay = query->value(3).toInt();
        date = query->value(4).toString();

        room_ids.push_back(room_id);
        room_types.push_back(room_type);
        room_prices.push_back(price);
        room_totals.push_back(totalpay);
        date_s.push_back(date);
    }
    for(auto it = room_totals.begin(); it != room_totals.end(); it++){
        rijie += *it;
    }
    return 1;
}

//查询历史账单(输出所有的数据)(已验证)
bool DataBase::DB_bill(QVector<int> &ids, QVector<int> &room_ids, QVector<QString> &room_types, QVector<QString> &start_dates, QVector<QString> &end_dates, QVector<int> &moneys, QVector<QString> &todays)
{

    int id;
    int room_id;
    QString room_type;
    QString start_date;
    QString end_date;
    int money;
    QString today;//结账当天日期

    query->prepare("select *from Payment");
    if(!query->exec()){
      qDebug() << QObject::tr("查询账单失败");
      return -1;
    }
    while (query->next()) {
      id = query->value(0).toInt();
      room_id = query->value(1).toInt();
      room_type = query->value(2).toString();
      start_date = query->value(3).toString();
      end_date = query->value(4).toString();
      money = query->value(5).toInt();
      today = query->value(6).toString();

      ids.push_back(id);
      room_ids.push_back(room_id);
      room_types.push_back(room_type);
      start_dates.push_back(start_date);
      end_dates.push_back(end_date);
      moneys.push_back(money);
      todays.push_back(today);
    }

//    qDebug()<<QObject::tr("无历史账单");
    return 1;
}
//权限分配(已验证)

//管理员名字/住宿登记/调房登记/追加押金/退宿结账/预定查询/登记查询/退宿查询/报表查询
bool DataBase::DB_quanxian(QString name, int zs, int tf, int yj, int tsjiezhang, int yd_find, int dj_find, int ts_find, int baobiao)
{

    query->prepare("insert into Quanxian values (?,?,?,?,?,?,?,?,?)");
    query->bindValue(0, name);
    query->bindValue(1, zs);
    query->bindValue(2, tf);
    query->bindValue(3, yj);
    query->bindValue(4, tsjiezhang);
    query->bindValue(5, yd_find);
    query->bindValue(6, dj_find);
    query->bindValue(7, ts_find);
    query->bindValue(8, baobiao);
    if(!query->exec()){
      qDebug() << QObject::tr("权限插入失败");
      return -1;
    }
    return 1;
}
