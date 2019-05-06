#ifndef DATABASE_H
#define DATABASE_H

#include<QtSql>
#include<QTextCodec>
#include<QDebug>
#include<QMessageBox>

#define MAX_ROOM 20

class DataBase{
public:
    DataBase(QString name);
    bool DB_conn(QString QString);
    void DB_create();
    //添加管理员
    bool DB_add(QString man_id, QString man_name, QString man_passwd, QString man_IDcard, QString man_tel);

//    //默认超级管理员
//    bool super_man();
    //普通管理员信息查询
       bool DB_info_man(QVector<int> &man_ids, QVector<QString> &man_names, QVector<QString> &passwds, QVector<QString> &IDcards, QVector<QString> &tels);
         bool inf_change(QString id, QString name, QString pwd, QString IDcard, QString tel);
       //超级管理员信息查询
       bool DB_init_status();
         bool DB_info_sup(QVector<int> &man_ids, QVector<QString> &man_names, QVector<QString> &passwds, QVector<QString> &IDcards, QVector<QString> &tels);
    //登录
    bool DB_log(QString id, QString pwd, QString &name, int &zs, int &tf, int &yj, int &tsjiezhang, int &yd_find, int &dj_find, int &ts_find, int &baobiao);

    //房态显示
    bool DB_room_status(QVector<int> &no_s, QVector<QString> &status_s);

    //房间管理(房态查询)
    bool DB_room_manger(int no, QString &status);

    //预定房间
    bool DB_order(int no,QString cus_name, QString cus_IDcard, int fangfei, QString cus_tel, QString type, int price, QString status, QString orderdate, QString indate, QString outdate, int days, QString today);

    //住宿登记时,在预定表中查询是否存在身份证号,如果存在就将预定表中的客户信息转移到登记入住表
    int DB_is_order(QString IDcard, int yajin);

    //住宿登记
    bool DB_zhusu(int id, QString name, QString IDcard, int yajin, int fangfei, QString tel, QString type, int price, QString status, QString in_date, QString out_date, int days, QString today);

    //调房登记
    bool DB_tiaofang(int from_room, int to_room);

    //追加押金
    bool DB_addyajin(int room_id, QString name, int zhuijia);

    //退宿结账

   bool DB_quit_log(QString &name, int &roomid, QString &type, int &price, QString &indate, QString &outdate, int &days, QString &today, int &total);
   //挂账入住
   bool DB_quit(QString &name, int &roomid, QString &type, int &price, QString &indate, QString &outdate, int &days, int &total, int &is_guan);

    bool DB_guazhang(int room_no, QString room_name, QString IDcard, int room_yajin, QString room_tel, QString type, int price, QString room_status, QString orderdate, QString indate, QString out_date, int days);

    //挂账查询(所有数据)
    bool DB_guazhang_find(QVector<QString> &no_s, QVector<QString> &cus_name_s, QVector<QString> &cus_IDcard_s, QVector<int> &yajin_s, QVector<int> &total_s, QVector<QString> &cus_tel_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &status_s, QVector<QString> &ordertime_s, QVector<QString> &intime_s, QVector<QString> &outtime_s, QVector<int> &days_s);

    //预订房查询(输出所有数据)
    bool DB_ordered_find(QVector<int> &no_s, QVector<QString> &cus_name_s, QVector<QString> &cus_IDcard_s, QVector<int> &fangfei_s, QVector<QString> &cus_tel_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &status_s, QVector<QString> &ordertime_s, QVector<QString> &intime_s, QVector<QString> &outtime_s, QVector<int> &days_s);

    //按照房间号查询(预订房)
    bool DB_ordered_search(int &no, QString &cus_name, QString &cus_IDcard, int &fangfei, QString &cus_tel, QString &type, int &price, QString &status, QString &ordertime, QString &intime, QString &outtime, int &days);

    //住宿查询(查询所有数据)
    bool DB_zhusu_find(QVector<int> &roomid_s, QVector<QString> &name_s, QVector<QString> &IDcard_s, QVector<int> &yajin_s, QVector<int> fangfei_s, QVector<QString> &tel_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &status_s, QVector<QString> &indate_s, QVector<QString> &outdate_s, QVector<int> &days_s);

    //按照房间号查询(住宿)
    bool DB_zhusu_search(int &room_id, QString &cus_name, QString &IDcard, int &yajin, int &fangfei, QString &tel, QString &type, int &price, QString &status, QString &indate, QString &outdate, int &days);

    //退宿查询(输出所有数据)
    bool DB_quit_find(QVector<QString> &name_s, QVector<int> &roomid_s, QVector<QString> &type_s, QVector<int> &price_s, QVector<QString> &indate_s, QVector<QString> &outdate_s, QVector<int> &days_s, QVector<int> &total_pay_s);

    //按照房间号查询(退宿)
    bool DB_quit_search(QString &name, int &roomid, QString &type, int &price, QString &indate, QString &outdate, int &days, int &total_pays);

    //销售报表
    bool DB_baobiao(QVector<int> &room_ids, QVector<QString> &room_types, QVector<int> &room_prices, QVector<int> &room_totals, QVector<QString> &date_s, QString dates, int &rijie);

    //账单查询
    bool DB_bill(QVector<int> &ids, QVector<int> &room_ids, QVector<QString> &room_types, QVector<QString> &start_dates, QVector<QString> &end_dates, QVector<int> &moneys, QVector<QString> &todays);

    //权限分配
    bool DB_quanxian(QString name, int zs, int tf, int yj, int tsjiezhang, int yd_find, int dj_find, int ts_find, int baobiao);

    //初始化
    void DB_init(int flag);

private:
    QSqlQuery *query;
    QSqlDatabase *db;
};

#endif // DATABASE_H
