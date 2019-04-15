/********************************************************************************
* File Name:	mainwindow.cpp
* Description:	第6章实例训练
* Reference book:《Linux环境下Qt4图形界面与MySQL编程》，机械工业出版社.2012.1
* E_mail: openlinux2011@gmail.com
*
********************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "change_room_price.h"
#include "add_food_info.h"
#include "delete_food_info.h"
#include "change_food_info.h"
#include "select_food_info.h"
#include "change_bash_info.h"
#include "zhu_ce.h"
#include "chgpwd.h"

#include <QtGui>
#include <QTableWidget>
#include <QMessageBox>
#include <QDateTime>
#include <QDate>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractItemView>
#include <QScrollBar>
#include <QToolTip>
#include <QRegExp>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    //ui->pushButton_7->setStyleSheet("border:none;");
    //QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForLocale(codec);

    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);

    ui->label_13->close();

    QRegExp regExp("[0-9]{17}[0-9Xx]{1}");
    QRegExpValidator *pRegExpValidator2 = new QRegExpValidator(regExp,this);
    ui->leID->setValidator(pRegExpValidator2);

    ui->leID->setMaxLength(18);//限制输入长度，最大为18位
    ui->leID->setFocus();

    this->setObjectName("myWindow");//窗口背景不影响子控件，另外在样式表中还需要加东西
    ui->tab->setObjectName("mytab");

    bash_index = 0;

    //QPushButton设置自体颜色
    QPalette   pal;
    pal.setColor(QPalette::ButtonText, QColor(255,255,255));
    ui->pushButton_10->setPalette(pal);
    ui->pushButton_13->setPalette(pal);
    ui->pushButton_2->setPalette(pal);
    ui->pushButton_3->setPalette(pal);
    ui->pushButton_4->setPalette(pal);
    ui->pushButton_5->setPalette(pal);
    ui->pushButton_6->setPalette(pal);
    //ui->pushButton_7->setPalette(pal);
    ui->pushButton_8->setPalette(pal);
    //ui->pushButton_9->setPalette(pal);
    ui->pushButton_11->setPalette(pal);
    ui->pushButton_12->setPalette(pal);

     //QPushButton设置控件无边框
    //ui->pushButton_10->setStyleSheet("border:none;");
    //ui->pushButton_13->setStyleSheet("border:none;");


    //ui->tableView->setStyleSheet("{background-color:transparent}");


    ui->lineEdit->setPlaceholderText(QStringLiteral("身份证号"));
    ui->lineEdit_3->setPlaceholderText(QStringLiteral("职工姓名"));

    //设置水平、垂直滚动条样式
    ui->food_tableView->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
      "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
      "QScrollBar::handle:hover{background:gray;}"
      "QScrollBar::sub-line{background:transparent;}"
      "QScrollBar::add-line{background:transparent;}");
     ui->food_tableView->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
      "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
      "QScrollBar::handle:hover{background:gray;}"
      "QScrollBar::sub-line{background:transparent;}"
      "QScrollBar::add-line{background:transparent;}");

    //表头两种颜色：为选中时为天空蓝，选中时为亮蓝色
    ui->food_tableView->setStyleSheet("selection-background-color:light pink;"); //设置选中背景色
    ui->food_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色

    //QPushButton设置背景图片
    //ui->pushButton_11->setStyleSheet("border-image:url(:/new/prefix1/purpleButton.jpg);");
    ui->pushButton_2->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    ui->pushButton_3->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    ui->pushButton_4->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    ui->pushButton_5->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    ui->pushButton_6->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    //ui->pushButton_7->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    ui->pushButton_8->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    //ui->pushButton_9->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");
    //ui->pushButton_10->setStyleSheet("border-image:url(:/new/prefix1/blueButton.jpg);");


    //ui->tab->setStyleSheet("border-image:url(:/new/prefix1/head.jpg);");

    //ui->dateTimeEdit->setCalendarPopup(true);

    ui->tabWidget->setCurrentIndex(0);
    //tab 1
    priceinfo_model=new QSqlTableModel(this);
    priceinfo_model->setTable("roomtype");//get table roomtype(MySQL)
    priceinfo_model->setEditStrategy(QSqlTableModel::OnManualSubmit); //修改提交过之后更新到数据库
    priceinfo_model->select();
    //获取当前列 的索引
    priceinfo_model->removeColumn(priceinfo_model->fieldIndex("tid"));
    priceinfo_model->removeColumn(priceinfo_model->fieldIndex("amount"));

    priceinfo_model->setHeaderData(0,Qt::Horizontal,tr("房间类型"));
    priceinfo_model->setHeaderData(1,Qt::Horizontal,tr("价格"));
    priceinfo_model->setHeaderData(2,Qt::Horizontal,tr("押金"));
    priceinfo_model->setHeaderData(3,Qt::Horizontal,tr("描述"));
    ui->tvPriceInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

    ui->tvPriceInfo->setModel(this->priceinfo_model);

    ui->tvPriceInfo->setStyleSheet("selection-background-color:light pink;"); //设置选中背景色
    ui->tvPriceInfo->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色


    //初始化   roominfo_model;

    this->roominfo_model=new QSqlTableModel(this);
    this->roominfo_model->setTable("room");
    this->roominfo_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    this->roominfo_model->select();
    this->roominfo_model->setHeaderData(0,Qt::Horizontal,tr("房间号"));
    this->roominfo_model->setHeaderData(2,Qt::Horizontal,tr("状态"));
    //注意hideColumn的位置
    ui->tvRoomInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

    ui->tvRoomInfo->setStyleSheet("selection-background-color:light pink;"); //设置选中背景色
    ui->tvRoomInfo->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色

    ui->tvRoomInfo->setModel(this->roominfo_model);
    ui->tvRoomInfo->hideColumn(1);
    //默认显示第一种类型的房间
    ui->rb1->setChecked(true);//设置radio_button为选中状态
    this->roominfo_model->setFilter("tid=1");
    this->roominfo_model->select();

    //tab2  登记入住初始化
    ui->leID->setText("");
     ui->leID->setPlaceholderText(QStringLiteral("18位身份证号"));
    ui->leUserName->setText("");
    ui->leRoomID->setText("");
    ui->leNumOfNig->setText("");

    //tab3  初始化 退房结算
    checkout_model=new QSqlTableModel(this);

    checkout_model->setTable("checkin");
    checkout_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    checkout_model->setHeaderData(0,Qt::Horizontal,tr("客户号"));
    checkout_model->setHeaderData(1,Qt::Horizontal,tr("房间号"));
    checkout_model->setHeaderData(2,Qt::Horizontal,tr("入住时间"));
    checkout_model->setHeaderData(3,Qt::Horizontal,tr("入住天数"));
    checkout_model->setHeaderData(4,Qt::Horizontal,tr("押金"));
    checkout_model->select();
    checkout_model->removeColumn(this->checkout_model->fieldIndex("engagedate"));
    checkout_model->removeColumn(this->checkout_model->fieldIndex("engagecash"));
    checkout_model->removeColumn(this->checkout_model->fieldIndex("sid"));
    //
    ui->tvQuery->setModel(checkout_model);
    ui->tvQuery->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

    //
    model_checkin_other=new QSqlTableModel(this);
    model_checkin_other->setTable("other_consume_bill");
    model_checkin_other->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_checkin_other->setHeaderData(0,Qt::Horizontal,tr("客户号"));
    model_checkin_other->setHeaderData(1,Qt::Horizontal,tr("餐饮消费"));
    model_checkin_other->setHeaderData(2,Qt::Horizontal,tr("洗浴消费"));
    model_checkin_other->select();
    ui->tableView_2->setModel(model_checkin_other);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑



    //tab4
    model_checkin=new QSqlTableModel(this);
    model_checkin->setTable("checkin");
    model_checkin->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_checkin->select();
    model_checkin->setHeaderData(0,Qt::Horizontal,tr("客户号"));
    model_checkin->setHeaderData(1,Qt::Horizontal,tr("房间号"));
    model_checkin->setHeaderData(2,Qt::Horizontal,tr("入住日期"));
    model_checkin->setHeaderData(3,Qt::Horizontal,tr("入住天数"));

    //注意hideColumn的位置
    ui->tvCheckin->setModel(this->model_checkin);
    ui->tvCheckin->hideColumn(4);
    ui->tvCheckin->hideColumn(5);
    ui->tvCheckin->hideColumn(6);
    ui->tvCheckin->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

//    ui->tvCheckin->setStyleSheet("selection-background-color:light pink;"); //设置选中背景色
//    ui->tvCheckin->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色

    model_checkout=new QSqlTableModel(this);
    model_checkout->setTable("checkout");
    model_checkout->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_checkout->select();
    model_checkout->setHeaderData(0,Qt::Horizontal,tr("客户号"));
    model_checkout->setHeaderData(2,Qt::Horizontal,tr("入住日期"));
    model_checkout->setHeaderData(1,Qt::Horizontal,tr("房间号"));
    model_checkout->setHeaderData(3,Qt::Horizontal,tr("退房日期"));
    model_checkout->setHeaderData(4,Qt::Horizontal,tr("付款金额"));
    ui->tvCheckout->setModel(this->model_checkout);
    ui->tvCheckout->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

//    ui->tvCheckout->setStyleSheet("selection-background-color:light pink;"); //设置选中背景色
//    ui->tvCheckout->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色

    //tab5  餐饮系统
    model_foodinfo = new QSqlTableModel(this);
    model_foodinfo->setTable("food_info");
    model_foodinfo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_foodinfo->select();
    model_foodinfo->setHeaderData(0,Qt::Horizontal,tr("菜名"));
    model_foodinfo->setHeaderData(1,Qt::Horizontal,tr("价格"));

    ui->food_tableView->setModel(this->model_foodinfo);
    ui->food_tableView->setSortingEnabled(true);//使其可排序
    ui->food_tableView->setSelectionBehavior ( QAbstractItemView::SelectRows);//整行选中模式
    ui->food_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

    //tab6  洗浴系统
    model_bashinfo = new QSqlTableModel(this);
    model_bashinfo->setTable("bash_type");
    model_bashinfo->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_bashinfo->select();

    model_bashinfo->removeColumn(this->model_bashinfo->fieldIndex("bash_index"));
    model_bashinfo->setHeaderData(0,Qt::Horizontal,tr("洗浴类型"));
    model_bashinfo->setHeaderData(1,Qt::Horizontal,tr("洗浴价格"));

    ui->tableView->setModel(this->model_bashinfo);
    //ui->tableView->setSortingEnabled(true);//使其可排序
    ui->tableView->setSelectionBehavior ( QAbstractItemView::SelectRows);//整行选中模式
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

    //ui->tableView->setStyleSheet("selection-background-color:light pink;"); //设置选中背景色
    //ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色


    //tab_2 员工信息表
    staff_info = new QSqlTableModel(this);
    staff_info->setTable("staff");
    staff_info->setEditStrategy(QSqlTableModel::OnManualSubmit);
    staff_info->select();

    staff_info->setHeaderData(0,Qt::Horizontal,tr("职工账号"));
    staff_info->setHeaderData(1,Qt::Horizontal,tr("主机名称"));
    staff_info->setHeaderData(2,Qt::Horizontal,tr("登录密码"));
    staff_info->setHeaderData(3,Qt::Horizontal,tr("职工姓名"));
    staff_info->setHeaderData(4,Qt::Horizontal,tr("职工性别"));
    staff_info->setHeaderData(5,Qt::Horizontal,tr("职工年龄"));

    ui->tableView_3->setModel(this->staff_info);
    //ui->tableView->setSortingEnabled(true);//使其可排序
    ui->tableView_3->setSelectionBehavior ( QAbstractItemView::SelectRows);//整行选中模式
    ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

    ui->tableView_3->setStyleSheet("selection-background-color:light pink;"); //设置选中背景色
    ui->tableView_3->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色

    QObject::connect(ui->leNumOfNig, SIGNAL(returnPressed()), this, SLOT(on_pbSubmit_clicked()));
    QObject::connect(ui->lineEdit_2, SIGNAL(returnPressed()), this, SLOT(on_pushButton_10_clicked()));
    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_11_clicked()));
    QObject::connect(ui->leOut_ID, SIGNAL(returnPressed()), this, SLOT(on_pbOut_Search_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rb1_clicked()
{
    this->roominfo_model->setFilter("tid=1");
    this->roominfo_model->select();
}

void MainWindow::on_rb2_clicked()
{
    this->roominfo_model->setFilter("tid=2");
    this->roominfo_model->select();
}

void MainWindow::on_rb3_clicked()
{
    this->roominfo_model->setFilter("tid=3");
    this->roominfo_model->select();
}

void MainWindow::on_rb4_clicked()
{
    this->roominfo_model->setFilter("tid=4");
    this->roominfo_model->select();
}

void MainWindow::on_rb5_clicked()
{
    this->roominfo_model->setFilter("tid=5");
    this->roominfo_model->select();
}

void MainWindow::on_rb6_clicked()
{
    this->roominfo_model->setFilter("tid=6");
    this->roominfo_model->select();
}

//登记入住
void MainWindow::on_pbSubmit_clicked()
{
    //QLineEdit设置错误提示，取值范
    ui->leNumOfNig->setValidator(new QDoubleValidator(0, 3000, 2));
    if(ui->leNumOfNig->text().toDouble() < 0 || ui->leNumOfNig->text().toDouble() > 365)
     {
            // 错误提示
            QToolTip::showText(ui->leNumOfNig->mapToGlobal(QPoint(100, 0)), "范围应该是0-3000");
            // 设置LineEdit变为红色
            ui->leNumOfNig->setStyleSheet("QLineEdit{border:1px solid red }");
            return;
     }
     else
     {
            // LineEdit恢复之前的状态
            ui->leNumOfNig->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
     }

    QString cnum=ui->leID->text();
    QString cname=ui->leUserName->text();
    QString rid=ui->leRoomID->text();
    QString day=ui->leNumOfNig->text();

    if (cnum == "" || cname == "" || rid == "" || day == "")
    {
        QMessageBox::warning(this, "注意", "输入不能为空！");
        return;
    }

    QString state;
    QDateTime time;
    int cash=0;
    QSqlQuery query;
    query.exec("select state from room where rid="+rid);
    if(query.next())
    {
        state=query.value(0).toString();
        if(state == tr("占用"))
        {QMessageBox::warning(this,tr("info"),tr("房间被占用！"));
            ui->leID->clear();
            ui->leUserName->clear();
            ui->leRoomID->clear();
            ui->leNumOfNig->clear();
            return;}
    }
    query.exec("SELECT * FROM client WHERE cnumber='"+cnum+"'");
    if(!query.next()) {
        query.prepare(tr("INSERT INTO client VALUES (:id, :name)"));
        query.bindValue(":id", cnum);
        query.bindValue(":name", cname);
        query.exec();
        QMessageBox::information(this,tr("info"),tr("欢迎首次光临!"));
    }else QMessageBox::information(this,tr("info"),tr("欢迎光临!"));
    query.exec("SELECT foregift FROM room,roomtype WHERE room.tid=roomtype.tid and room.rid="+rid);
    if(query.next()) {
        cash = query.value(0).toInt();
    }
    QString stime=time.currentDateTime().toString();

    //写入 checkin 数据库
    query.prepare("INSERT INTO checkin (cnumber,rid, opendate,engagedate,engagecash) VALUES (:cnum, :rid, :opendate,:engagedate,:engagecash)");
    query.bindValue(":cnum", cnum);
    query.bindValue(":rid", rid);
    query.bindValue(":opendate",time.currentDateTime() );
    query.bindValue(":engagedate",day);
    query.bindValue(":engagecash",cash);

    if(query.exec())
    {
        query.prepare(tr("UPDATE room SET state ='占用' WHERE rid = ? "));
        query.bindValue(0, rid);
        query.exec();
        QMessageBox::information(this,tr("恭喜"),tr("入住成功！"));
    }
    else  QMessageBox::warning(this,tr("警告"),tr("入住失败！"));
    ui->leID->clear();
    ui->leUserName->clear();
    ui->leRoomID->clear();
    ui->leNumOfNig->clear();
}

void MainWindow::on_pbCancle_clicked()
{
    //tab  登记入住初始化
    ui->leID->setText("");
    ui->leUserName->setText("");
    ui->leRoomID->setText("");
    ui->leNumOfNig->setText("");
}


//查询
void MainWindow::on_pbOut_Search_clicked()
{
    if(ui->leOut_ID->text().isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入身份信息！"),QMessageBox::Ok);
        return;
    }

    QString cnumber=ui->leOut_ID->text().trimmed();
    this->checkout_model->setFilter(QObject::tr("cnumber='%1'").arg(cnumber));
    this->checkout_model->select();
    ui->tvQuery->setModel(checkout_model);

    this->model_checkin_other->setFilter(QObject::tr("cnum='%1'").arg(cnumber));
    this->model_checkin_other->select();
    ui->tableView_2->setModel(model_checkin_other);


    QDateTime closedatetime=QDateTime::currentDateTime();
    QDateTime opendatetime;
    QDate   closedate=closedatetime.date();
    QDate   opendate;

    int realdate=1;
    opendatetime=this->checkout_model->record(0).value("opendate").toDateTime();
    opendate=opendatetime.date();
    if(closedate.year()==opendate.year())
    {
        realdate +=closedate.dayOfYear()-opendate.dayOfYear();
    }
    else
    {
        int tempyear=opendate.year();
        while(tempyear!=closedate.year())
        {
            if(QDate::isLeapYear(opendate.year()))
            {
                realdate +=366;
            }
            else
            {
                realdate +=365;
            }
            tempyear++;
        }
        realdate +=closedate.dayOfYear()-opendate.dayOfYear();
    }

    //将实际天数显示在  text 中
    ui->leRealdate->setText(QString::number(realdate));

    int room_price;
    int food_price;
    int bash_price;
    QString rid;
    rid=this->checkout_model->record(0).value("rid").toString();

    //执行 query 语句 查找price
    QSqlQuery query;
    query.prepare("select roomtype.price from roomtype where roomtype.tid=(select room.tid from room where room.rid=:rid)");
    query.bindValue(":rid",rid);
    query.exec();

    if(query.first())
    {
        room_price = query.value(0).toInt();
        room_price *=realdate;
    }

    query.prepare("select sum(foodPrice) from  other_consume_bill where cnum =:cnum");
    query.bindValue(":cnum",cnumber);
    query.exec();
    if (query.next())
    food_price = query.value(0).toInt();
     qDebug()<<food_price;

    query.prepare("select sum(bashPrice) from  other_consume_bill where cnum =:cnum");
    query.bindValue(":cnum",cnumber);
    query.exec();
    if (query.next())
    bash_price = query.value(0).toInt();
     qDebug()<<bash_price;
    //当前数据 显示到text中

     int Price = room_price + food_price + bash_price;
       qDebug()<<Price;
    ui->lePay->setText(QString::number(Price));
}

//退房
void MainWindow::on_pbCheckout_clicked()
{
    QDateTime closedatetime=QDateTime::currentDateTime();
    QDateTime opendatetime;
    QDate   closedate=closedatetime.date();
    QDate   opendate;

    int realdate=1;
    opendatetime=this->checkout_model->record(0).value("opendate").toDateTime();
    opendate=opendatetime.date();
    if(closedate.year()==opendate.year())
    {
        realdate +=closedate.dayOfYear()-opendate.dayOfYear();
    }
    else
    {
        int tempyear=opendate.year();
        while(tempyear!=closedate.year())
        {
            if(QDate::isLeapYear(opendate.year()))
            {
                realdate +=366;
            }
            else
            {
                realdate +=365;
            }
            tempyear++;
        }
        realdate +=closedate.dayOfYear()-opendate.dayOfYear();
    }

    //将实际天数显示在  text 中
    ui->leRealdate->setText(QString::number(realdate));

    int room_price;
    int food_price;
    int bash_price;
    QString rid;
    rid=this->checkout_model->record(0).value("rid").toString();

    //执行 query 语句 查找price
    QSqlQuery query;
    query.prepare("select roomtype.price from roomtype where roomtype.tid=(select room.tid from room where room.rid=:rid)");
    query.bindValue(":rid",rid);
    query.exec();

    if(query.first())
    {
        room_price = query.value(0).toInt();
        room_price *=realdate;
    }

    QString cnumber = ui->leOut_ID->text();
    query.prepare("select sum(foodPrice) from  other_consume_bill where cnum =:cnum");
    query.bindValue(":cnum",cnumber);
    query.exec();
    if (query.next())
    food_price = query.value(0).toInt();
     qDebug()<<food_price;

    query.prepare("select sum(bashPrice) from  other_consume_bill where cnum =:cnum");
    query.bindValue(":cnum",cnumber);
    query.exec();
    if (query.next())
    bash_price = query.value(0).toInt();
     qDebug()<<bash_price;
    //当前数据 显示到text中

     int Price = room_price + food_price + bash_price;
       qDebug()<<Price;

    //更新checkin及checkout表格。

    QString ID=this->checkout_model->record(0).value("cnumber").toString();
    query.prepare("delete from checkin where cnumber=:cnumber and opendate=:opendate");
    query.bindValue(":cnumber",ID);
    query.bindValue(":opendate",opendatetime);
    query.exec();

    //删除other_consume_bill表中所有相关内容
    query.prepare("delete from other_consume_bill where cnum=:cnum");
    query.bindValue(":cnumber",ID);
    query.exec();

    query.prepare("insert into checkout (cnumber,rid,opendate,closedate,cash) values(:cnumber,:rid,:opendate,:closedate,:cash)");
    query.bindValue(":cnumber",ID);
    query.bindValue(":rid",rid);
    query.bindValue(":opendate",opendatetime);
    query.bindValue(":closedate",closedatetime);
    query.bindValue(":cash",Price);
    query.exec();

    //更改 room 的状态
    query.prepare("update room set  room.state='空闲' where rid=:rid");
    query.bindValue(":rid", rid);
    query.exec();

    QMessageBox::information(this,tr("恭喜"),tr("退房成功！"),QMessageBox::Ok);

    ui->leOut_ID->clear();
    ui->leRealdate->clear();
    ui->lePay->clear();

}

//  tab4 查询记录信息

void MainWindow::on_tabWidget_currentChanged(int index)//根据索引变化而实现刷新功能
{
    if(index==5)
    {
        model_checkin->select();
        //注意hideColumn的位置
        ui->tvCheckin->setModel(this->model_checkin);
        model_checkout->select();
        ui->tvCheckout->setModel(this->model_checkout);
    }
    else if(index==4)
    {
        ui->tvQuery->clearFocus();
        this->checkout_model->select();
        ui->tvQuery->setModel(checkout_model);
    }
}

void MainWindow::on_pushButton_clicked()//修改房间价格
{
    this->close();
    change_room_price *room_price = new change_room_price;
    room_price->show();
}

void MainWindow::on_pushButton_2_clicked()//添加菜品
{
    this->close();
    add_food_info *food_info = new add_food_info;
    food_info->show();
}

void MainWindow::on_pushButton_3_clicked()//删除菜品
{
    this->close();
    delete_food_info *food_info = new delete_food_info;
    food_info->show();
}

void MainWindow::on_pushButton_4_clicked()//修改菜品
{
    this->close();
    change_food_info *food_info = new change_food_info;
    food_info->show();
}

void MainWindow::on_pushButton_5_clicked()//查询擦品
{
    this->close();
    select_food_info *food_info = new select_food_info;
    food_info->show();
}

void MainWindow::on_pushButton_6_clicked()//价格升序
{
    ui->food_tableView->sortByColumn(1,Qt::AscendingOrder);
}


void MainWindow::on_pushButton_8_clicked()//价格降序
{
    ui->food_tableView->sortByColumn(1,Qt::DescendingOrder);
}


void MainWindow::on_pushButton_10_clicked()//餐饮登记
{
    QString cnum = ui->lineEdit_2->text();
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox::warning(this, tr("FAILURE"), tr("Please Input Id!"));
        return;
    }


    QSqlQuery query;
    int foodPrice = 0;

    ui->food_tableView->setSelectionMode(QAbstractItemView::ExtendedSelection); //可多选（Ctrl、Shift、  Ctrl+A都可以）

    QModelIndexList indexList = ui->food_tableView->selectionModel()->selectedIndexes();//选中的所有索引（行）

    QModelIndex index;

    foreach(index, indexList )
    {
     //QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());

     QString text1 =index.model()->data(index, Qt::EditRole).toString();

     qDebug()<<text1.toInt();

     foodPrice += text1.toInt();
    }

    qDebug()<<foodPrice;

    query.prepare("insert into other_consume_bill(cnum, foodPrice ) values(:cnum,:foodPrice)");
    query.bindValue(":cnum", cnum);
    query.bindValue(":foodPrice", foodPrice);
    query.exec();
    QMessageBox::information(this,tr("恭喜"),tr("用餐登记成功!"));
}

void MainWindow::on_pushButton_11_clicked()//洗浴
{
    QString cnum = ui->lineEdit->text();
    QSqlQuery query;

    int bash_cash = 0;
    int bashPrice = 0;

    if (bash_index != 1 && bash_index != 2 && bash_index != 3 && bash_index != 4 )
        QMessageBox::warning(this, tr("Warning"), tr("Pleae select one roomtype!"));
    else
    {
       //query.exec("select * from bash_type where bash_index ="+bash_index);

        QString str=QString("select * from bash_type where bash_index= %1").arg(bash_index);
        query.exec(QObject::tr(str.toUtf8().data()));

       if (!query.isActive())
           QMessageBox::warning(this, tr("警告"), tr("洗浴类型标号错误!"));

       qDebug()<<bash_index;
      if(query.first()) //是否找到符合条件的记录
      {
           bash_cash = query.value(2).toInt();
           bashPrice = query.value(2).toInt();
           QString bashName = query.value(1).toString();

        // 插入信息到洗浴信息表格中
        query.prepare("insert into bash_info(cnum, bashName, bash_cash) values(:cnum,:bashName, :bash_cash)");
        query.bindValue(":cnum",cnum);
        query.bindValue(":bashName",bashName);
        query.bindValue(":bash_cash",bash_cash);
        if (query.exec())
            QMessageBox::information(this, tr("恭喜"), tr("洗浴登记成功!"));

        //同时插入信息到其他消费账单表格中
        query.prepare("insert into other_consume_bill(cnum,bashPrice) values(:cnum,:bashPrice)");
        query.bindValue(":cnum",cnum);
        query.bindValue(":bashPrice",bashPrice);

        if (!query.exec())
            QMessageBox::warning(this, tr("警告"), tr("INSERT INTO OTHER_CONSUME_BILL FAILURE!"));
      }
      else
      {
         QMessageBox::warning(this, tr("FAILURE"), tr("None Record(bash_index)!"));
      }
    }
}


void MainWindow::on_pushButton_12_clicked()//清空LineEdit
{
    ui->lineEdit->clear();
}

void MainWindow::on_radioButton_clicked()//标准洗浴
{
    bash_index = 1;
}

void MainWindow::on_radioButton_2_clicked()//标准足浴
{
    bash_index = 2;
}

void MainWindow::on_radioButton_3_clicked()//标准按摩
{
    bash_index = 3;
}

void MainWindow::on_radioButton_4_clicked()//标准桑拿
{
    bash_index = 4;
}



void MainWindow::on_pushButton_23_clicked()//修改洗浴价格
{
    this->close();
    change_bash_info *bash_info = new change_bash_info;
    bash_info->show();
}

void MainWindow::on_pushButton_9_clicked()//删除员工信息
{
    if (ui->lineEdit_3->text() == "")
    {
        QMessageBox::warning(this, tr("警告"), tr("输入信息不能为空！"));
        return;
    }
    QString name = ui->lineEdit_3->text();
    QSqlQuery query;
    query.exec("select name from staff where name="+name);
    if(query.size() != 0)
    {
        query.prepare("delete from staff where name=:name");
        query.bindValue(":name",name);
        query.exec();
        QMessageBox::information(this, tr("恭喜"), tr("恭喜您成功删除员工:%1").arg(name));

        staff_info->setTable("staff");
        staff_info->setEditStrategy(QSqlTableModel::OnManualSubmit);
        staff_info->select();

        staff_info->setHeaderData(0,Qt::Horizontal,tr("职工账号"));
        staff_info->setHeaderData(1,Qt::Horizontal,tr("主机名称"));
        staff_info->setHeaderData(2,Qt::Horizontal,tr("登录密码"));
        staff_info->setHeaderData(3,Qt::Horizontal,tr("职工姓名"));
        staff_info->setHeaderData(4,Qt::Horizontal,tr("职工性别"));
        staff_info->setHeaderData(5,Qt::Horizontal,tr("职工年龄"));

        ui->tableView_3->setModel(this->staff_info);
        //ui->tableView->setSortingEnabled(true);//使其可排序
        ui->tableView_3->setSelectionBehavior ( QAbstractItemView::SelectRows);//整行选中模式
        ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑

        return;
    }
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("信息匹配错误，请您仔细核实信息！"));
    }

}

void MainWindow::on_pushButton_31_clicked()//查询员工信息
{
    if (ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox::warning(this, tr("警告"), tr("输入信息不能为空！"));
        return;
    }
    QString name = ui->lineEdit_3->text().trimmed();
    QSqlQuery query;
    query.exec("select name from staff where name="+name);
    if(query.size() != 0)
    {
        //tab_2 员工信息表
        staff_info_1 = new QSqlTableModel(this);
        staff_info_1->setTable("staff");
        staff_info_1->setEditStrategy(QSqlTableModel::OnManualSubmit);
        staff_info_1->setFilter(QObject::tr("name='%1'").arg(name));
        staff_info_1->select();

        staff_info_1->setHeaderData(0,Qt::Horizontal,tr("职工账号"));
        staff_info_1->setHeaderData(1,Qt::Horizontal,tr("主机名称"));
        staff_info_1->setHeaderData(2,Qt::Horizontal,tr("登录密码"));
        staff_info_1->setHeaderData(3,Qt::Horizontal,tr("职工姓名"));
        staff_info_1->setHeaderData(4,Qt::Horizontal,tr("职工性别"));
        staff_info_1->setHeaderData(5,Qt::Horizontal,tr("职工年龄"));

        ui->tableView_7->setModel(this->staff_info_1);
        //ui->tableView->setSortingEnabled(true);//使其可排序
        ui->tableView_7->setSelectionBehavior ( QAbstractItemView::SelectRows);//整行选中模式
        ui->tableView_7->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑
    }
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("信息匹配错误，请您仔细核实信息！"));
    }
}


