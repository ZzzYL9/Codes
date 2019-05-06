#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QWidget>
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QLabel>
#include<rebook.h>
#include<registart.h>
#include<transroom.h>
#include<checkout.h>
#include<QTableWidget>
#include<QPainter>

mainwindow::mainwindow(DataBase *db, QWidget *parent):
    QWidget(parent),
    m_db(db),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    doStyle();
    Init();
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::Init(){
    ui->workIdEdit->setVisible(0);
    ui->nameEdit->setVisible(0);
    ui->phoneNum->setVisible(0);
    ui->pawEdit->setVisible(0);
    ui->btnEdit->setVisible(0);
    ui->label->setVisible(0);
    ui->label_2->setVisible(0);
    ui->label_3->setVisible(0);
    ui->label_4->setVisible(0);
    ui->label_5->setVisible(0);
    ui->pushButton->setVisible(0);
    ui->pushButton_2->setVisible(0);
    ui->controTableWidget->setContextMenuPolicy (Qt::CustomContextMenu);

    connect(ui->controTableWidget,&QTableWidget::customContextMenuRequested,this,&mainwindow::RoomManagementMenu);
    ui->controTableWidget->verticalHeader()->setVisible(0);
    reflushContro();
    reflushDebtContro();
    reflushStaContro(REBOOK);
    reflushDayCheckContro();
    reflushSystemContro();
}

void mainwindow::reflushContro()
{
    int acount=ui->controTableWidget->rowCount();
    ui->controTableWidget->model()->removeRows(0,acount);
    QVector<int>nos;
    QVector<QString>status;
    m_db->DB_room_status(nos,status);
    for(int i=0;i<nos.count();i++)
    {
        int RowCont;
        RowCont=ui->controTableWidget->rowCount();
        ui->controTableWidget->insertRow(RowCont);//增加一行
        ui->controTableWidget->setItem(RowCont,1,new QTableWidgetItem(QString::number(nos[i])));
        ui->controTableWidget->setItem(RowCont,2,new QTableWidgetItem ("98"));
        ui->controTableWidget->setItem(RowCont,3,new QTableWidgetItem(tr("房间类型")));
        ui->controTableWidget->setItem(RowCont,4,new QTableWidgetItem(status[i]));
        QLabel *label2 = new QLabel("",this);
        label2->setPixmap(QPixmap("://images/bigBed.jpg").scaled(180,100));
        ui->controTableWidget->setCellWidget(i  ,0,label2);
    }

}

void mainwindow::reflushDebtContro()
{
    int acount=ui->debtTableWidgt->rowCount();
    ui->debtTableWidgt->model()->removeRows(0,acount);
    QVector<QString> no_s;
    QVector<QString> cus_name_s;
    QVector<QString> cus_IDcard_s;
    QVector<int> yajin_s;
    QVector<int> total_s;
    QVector<QString> cus_tel_s;
    QVector<QString> type_s;
    QVector<int> price_s;
    QVector<QString> status_s;
    QVector<QString> ordertime_s;
    QVector<QString> intime_s;
    QVector<QString> outtime_s;
    QVector<int> days_s;
    m_db->DB_guazhang_find(no_s,cus_name_s,cus_IDcard_s,yajin_s,total_s,cus_tel_s,type_s,price_s,status_s,ordertime_s,intime_s,outtime_s,days_s);
    for(int i=0;i<no_s.count();i++)
    {
        int RowCont;
        RowCont=ui->debtTableWidgt->rowCount();
        ui->debtTableWidgt->insertRow(RowCont);//增加一行
         ui->debtTableWidgt->setItem(RowCont,0,new QTableWidgetItem (no_s[i]));
         ui->debtTableWidgt->setItem(RowCont,1,new QTableWidgetItem(cus_name_s[i]));
        ui->debtTableWidgt->setItem(RowCont,2,new QTableWidgetItem(cus_tel_s[i]));

        ui->debtTableWidgt->setItem(RowCont,3,new QTableWidgetItem(intime_s[i]));
        ui->debtTableWidgt->setItem(RowCont,4,new QTableWidgetItem(outtime_s[i]));
        ui->debtTableWidgt->setItem(RowCont,5,new QTableWidgetItem(QString::number(days_s[i])));
        ui->debtTableWidgt->setItem(RowCont,6,new QTableWidgetItem(QString::number(price_s[i])));

    }
}

void mainwindow::reflushStaContro(int index)
{
    int acount=ui->statisticsTableWidget->rowCount();
    ui->statisticsTableWidget->model()->removeRows(0,acount);
    QVector<int> no_s;
    QVector<QString> cus_name_s;
    QVector<QString> cus_IDcard_s;
    QVector<int> fangfei_s;
    QVector<QString> cus_tel_s;
    QVector<QString> type_s;
    QVector<int> price_s;
   QVector<QString> status_s;
   QVector<QString> ordertime_s;
   QVector<QString> intime_s;
   QVector<QString> outtime_s;
   QVector<int>yajin_s;
   QVector<int> days_s;
   QVector<int>Acounts;
    if(index==REBOOK)
    {
      m_db->DB_ordered_find(no_s,cus_name_s,cus_IDcard_s,fangfei_s,cus_tel_s,type_s,price_s,status_s,ordertime_s,intime_s,outtime_s,days_s);
       for(int i=0;i<cus_name_s.count();i++)
      {
      int RowCont;
      RowCont=ui->statisticsTableWidget->rowCount();
      ui->statisticsTableWidget->insertRow(RowCont);//增加一行
      ui->statisticsTableWidget->setItem(RowCont,0,new QTableWidgetItem(QString::number(no_s[i])));
      ui->statisticsTableWidget->setItem(RowCont,1,new QTableWidgetItem(type_s[i]));
      ui->statisticsTableWidget->setItem(RowCont,2,new QTableWidgetItem (cus_name_s[i]));
      ui->statisticsTableWidget->setItem(RowCont,5,new QTableWidgetItem(intime_s[i]));
      ui->statisticsTableWidget->setItem(RowCont,4,new QTableWidgetItem(outtime_s[i]));
      ui->statisticsTableWidget->setItem(RowCont,3,new QTableWidgetItem(QString::number(price_s[i])));
        }

    }
    else if(index==CURROOM)
    {
        QVector<int>nos;
      m_db->DB_zhusu_find(nos,cus_name_s,cus_IDcard_s,yajin_s,fangfei_s,cus_tel_s,type_s,price_s,status_s,intime_s,outtime_s,days_s);
      for(int i=0;i<cus_name_s.count();i++)
     {
     int RowCont;
     RowCont=ui->statisticsTableWidget->rowCount();
     ui->statisticsTableWidget->insertRow(RowCont);//增加一行
     ui->statisticsTableWidget->setItem(RowCont,0,new QTableWidgetItem(QString::number(nos[i])));
     ui->statisticsTableWidget->setItem(RowCont,1,new QTableWidgetItem(type_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,2,new QTableWidgetItem (cus_name_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,5,new QTableWidgetItem(intime_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,4,new QTableWidgetItem(outtime_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,3,new QTableWidgetItem(QString::number(price_s[i])));
      }

    }
    else
    {
       QVector<int>nos;
      m_db->DB_quit_find(cus_name_s,nos,type_s,price_s,intime_s,outtime_s,days_s,Acounts);
      for(int i=0;i<cus_name_s.count();i++)
     {
     int RowCont;
     RowCont=ui->statisticsTableWidget->rowCount();
     ui->statisticsTableWidget->insertRow(RowCont);//增加一行
     ui->statisticsTableWidget->setItem(RowCont,0,new QTableWidgetItem(QString::number(nos[i])));
     ui->statisticsTableWidget->setItem(RowCont,1,new QTableWidgetItem(type_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,2,new QTableWidgetItem (cus_name_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,5,new QTableWidgetItem(intime_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,4,new QTableWidgetItem(outtime_s[i]));
     ui->statisticsTableWidget->setItem(RowCont,3,new QTableWidgetItem(QString::number(price_s[i])));
       }
    }
}
void mainwindow::reflushDayCheckContro()
{
    int acount=ui->dayCheckoutTableWidget->rowCount();
    ui->dayCheckoutTableWidget->model()->removeRows(0,acount);
    QVector<int>nos;
    QVector<QString> no_s;
    QVector<QString> cus_name_s;
    QVector<QString> cus_IDcard_s;
    QVector<int> fangfei_s;
    QVector<QString> cus_tel_s;
    QVector<QString> type_s;
    QVector<int> price_s;
   QVector<QString> status_s;
   QVector<QString> ordertime_s;
   QVector<QString> intime_s;
   QVector<QString> outtime_s;
   QVector<int>Acounts;
   QVector<int>days_s;
  m_db->DB_quit_find(cus_name_s,nos,type_s,price_s,intime_s,outtime_s,days_s,Acounts);
  for(int i=0;i<cus_name_s.count();i++)
 {
 int RowCont;
 RowCont=ui->dayCheckoutTableWidget->rowCount();
 ui->dayCheckoutTableWidget->insertRow(RowCont);//增加一行
 ui->dayCheckoutTableWidget->setItem(RowCont,0,new QTableWidgetItem(QString::number(nos[i])));
 ui->dayCheckoutTableWidget->setItem(RowCont,1,new QTableWidgetItem (cus_name_s[i]));
 ui->dayCheckoutTableWidget->setItem(RowCont,2,new QTableWidgetItem(intime_s[i]));
 ui->dayCheckoutTableWidget->setItem(RowCont,3,new QTableWidgetItem(outtime_s[i]));
 ui->dayCheckoutTableWidget->setItem(RowCont,4,new QTableWidgetItem(type_s[i]));
 ui->dayCheckoutTableWidget->setItem(RowCont,5,new QTableWidgetItem(QString::number(Acounts[i])));
 }
}

void mainwindow::reflushSystemContro()
{
    int acount=ui->systemTableWidet->rowCount();
    ui->systemTableWidet->model()->removeRows(0,acount);
    QVector<int> man_ids;
    QVector<QString> man_names;
    QVector<QString> passwds;
    QVector<QString> IDcards;
    QVector<QString> tels;
    m_db->DB_info_man(man_ids, man_names,passwds, IDcards,tels);
    QVector<int> man_ids1;
    QVector<QString> man_names1;
    QVector<QString> passwds1;
    QVector<QString> IDcards1;
    QVector<QString> tels1;
    m_db->DB_info_sup(man_ids1, man_names1,passwds1, IDcards1,tels1);
    for(int i=0;i<man_ids.count();i++)
   {
   int RowCont;
   RowCont=ui->systemTableWidet->rowCount();
   ui->systemTableWidet->insertRow(RowCont);//增加一行
   ui->systemTableWidet->setItem(RowCont,0,new QTableWidgetItem(QString::number(man_ids[i])));
   ui->systemTableWidet->setItem(RowCont,1,new QTableWidgetItem(man_names[i]));
   ui->systemTableWidet->setItem(RowCont,2,new QTableWidgetItem (tr("管理员")));
   ui->systemTableWidet->setItem(RowCont,3,new QTableWidgetItem(tels[i]));
    }

   for(int i=0;i<man_ids1.count();i++)
   {
   int RowCont;
   RowCont=ui->systemTableWidet->rowCount();
   ui->systemTableWidet->insertRow(RowCont);//增加一行
   ui->systemTableWidet->setItem(RowCont,0,new QTableWidgetItem(QString::number(man_ids1[i])));
   ui->systemTableWidet->setItem(RowCont,1,new QTableWidgetItem(man_names1[i]));
   ui->systemTableWidet->setItem(RowCont,2,new QTableWidgetItem (tr("老板")));
   ui->systemTableWidet->setItem(RowCont,3,new QTableWidgetItem(tels1[i]));
    }

}



void mainwindow::RoomManagementMenu(const QPoint pos)
{
    if(ui->controTableWidget->selectedItems().size()!=0)    //当前选中数不为0时
    {
    QMenu *menu=new QMenu(ui->controTableWidget);
    QAction *ReservationAction=new QAction(tr("预定"),ui->controTableWidget);
    QAction  *RegistrationAction=new QAction(tr("登记"),ui->controTableWidget);
    QAction *TransferRoomsAction=new QAction(tr("调房"),ui->controTableWidget);//调房
    QAction *CheckoutAction=new QAction(tr("结账离开"),ui->controTableWidget);//退房
    connect(ReservationAction,&QAction::triggered,this,&mainwindow::Reservation);
    connect(RegistrationAction,&QAction::triggered,this,&mainwindow::Registration);
    connect(TransferRoomsAction,&QAction::triggered,this,&mainwindow::TransferRooms);
    connect(CheckoutAction,&QAction::triggered,this,&mainwindow::Chekout);
    menu->addAction(ReservationAction);
    menu->addAction(RegistrationAction);
    menu->addAction(TransferRoomsAction);
    menu->addAction(CheckoutAction);
    menu->move(cursor().pos());
    menu->show();
    }
}


void mainwindow::on_pushButton_5_clicked()
{
    QMessageBox::warning(this, "警告", "确定要初始化数据库?");
}

void mainwindow::onTransRoom(bool yesOrNo,int current)
{
    if(yesOrNo==1)
    {
        int in=ui->controTableWidget->currentRow();
        ui->controTableWidget->setItem(in,4,new QTableWidgetItem(tr("空闲")));
        ui->controTableWidget->setItem(current-1,4,new QTableWidgetItem(tr("已入住")));
    }
}

void mainwindow::Reservation()//预定
{


    int in=ui->controTableWidget->currentRow();
    if(ui->controTableWidget->item(in,3)->text()=="已入住")
    {
        QMessageBox::warning(this, "警告", "当前已登记");
    }
    else
    {
        ReBook *bookUi=new ReBook(m_db,ui->controTableWidget->item(in,1)->text(),ui->controTableWidget->item(in,2)->text(),ui->controTableWidget->item(in,3)->text(),0,this);
        connect(bookUi,&ReBook::rebook,this,&mainwindow::onrebook);
        bookUi->exec();
    }
}

void mainwindow::onrebook(bool yesOrNo)
{
       //int cur=ui->controTableWidget->currentRow();
       //ui->controTableWidget->setItem(cur,4,new QTableWidgetItem(tr("已预定")));
       if(yesOrNo)
           {

           Init();
                }
       }

void mainwindow::onCheckout(bool yesOrNo)
{
    if(yesOrNo)
    {
        Init();
     //   ui->controTableWidget->setItem(ui->controTableWidget->currentRow(),4,new QTableWidgetItem("空闲"));
       // ui->debtTableWidgt->removeRow(ui->debtTableWidgt->currentRow());

        QMessageBox::warning(this,"欢迎光临","欢迎下次再见");

    }
}


void mainwindow::Registration()//的登记
{

    int in=ui->controTableWidget->currentRow();
    if(ui->controTableWidget->item(in,3)->text()=="已入住")
    {
        QMessageBox::warning(this, "警告", "当前已登记");
    }
    else
    {
        registart *registartUi=new registart(m_db,ui->controTableWidget->item(in,1)->text(),ui->controTableWidget->item(in,2)->text(),ui->controTableWidget->item(in,3)->text(),this);
        connect(registartUi,&registart::sendRegist,this,&mainwindow::Onregister);
        registartUi->exec();
        Init();

    }

}

void mainwindow::Onregister(bool yesOrno)//登记
{
    if(yesOrno==1)
    {
      //int in=ui->controTableWidget->currentRow();
        //ui->controTableWidget->setItem(in,4,new QTableWidgetItem(tr("已入住")));
    QMessageBox::warning(this,"登记成功","登记成功，请缴纳押金25元");


    }
}
void mainwindow::TransferRooms()//调房
{
      int in=ui->controTableWidget->currentRow();
       QMap<QString,int>a;
        for(int i=0;i<ui->controTableWidget->rowCount();i++)
        {
               if(ui->controTableWidget->item(i,4)->text()=="空闲"&&ui->controTableWidget->item(i,1)->text().toInt()-1!=in)
                a[ui->controTableWidget->item(i,1)->text()]=ui->controTableWidget->item(i,2)->text().toInt();
        }
    transRoom *One=new transRoom(m_db,ui->controTableWidget->item(in,1)->text(),a,this);
    connect(One,&transRoom::sendTransRoom,this,&mainwindow::onTransRoom);
    One->exec();

}
void mainwindow::Chekout()//结账
{
    checkout *one=new checkout(m_db,ui->controTableWidget->currentRow()+1);
        connect(one,&checkout::sendCheckInfo,this,&mainwindow::onCheckout);
    one->exec();

}

void mainwindow::on_findBtn_clicked()
{
    int count=ui->controTableWidget->rowCount();

    for(int i=0;i<count;i++)
    {
        if(ui->controTableWidget->item(i,1)->text()==ui->findEdit->text())
        {

                ui->controTableWidget->setCurrentItem(ui->controTableWidget->item(i,1));
                return;
        }
    }

}

void mainwindow::on_findEdit_textChanged(const QString &arg1)
{

    int count=ui->controTableWidget->rowCount();
    for(int i=0;i<count;i++)
    {
        if(   ui->controTableWidget->item(i,1)->text().startsWith(ui->findEdit->text()))
        {
                ui->controTableWidget->setCurrentItem(ui->controTableWidget->item(i,1));

        }
    }
}

void mainwindow::on_outBtn_clicked()
{
    this->close();
    emit sendOutLogin();
}



void mainwindow::on_findRoomDebtEdit_textChanged(const QString &arg1)
{

    int count=ui->debtTableWidgt->rowCount();
    ui->debtTableWidgt->clearSelection();
    for(int i=0;i<count;i++)
    {
        if(ui->debtTableWidgt->item(i,0)->text()==arg1)
        {

                ui->debtTableWidgt->setCurrentItem(ui->debtTableWidgt->item(i,1));
                return;
        }
    }
}

void mainwindow::on_CheckoutButton_clicked()
{
    if(ui->findRoomDebtEdit->text()!="")
    {
        checkout *check=new checkout(m_db,ui->debtTableWidgt->item(ui->debtTableWidgt->currentRow(),0)->text().toInt(),this);
        check->exec();
    }
}

void mainwindow::on_debtTableWidgt_clicked(const QModelIndex &index)
{
   int i=index.row();
   ui->findRoomDebtEdit->setText(ui->debtTableWidgt->item(i,0)->text());
}

void mainwindow::on_BookButton_clicked()
{
    reflushStaContro(0);
    qDebug()<<"1";
}

void mainwindow::on_AccommodationButton_clicked()
{
    reflushStaContro(1);
    qDebug()<<"2";
}

void mainwindow::on_RetreatButton_clicked()
{
    qDebug()<<"3";
     reflushStaContro(2);
}

void mainwindow::on_findRoomIdEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty())
    {
        int acount=ui->dayCheckoutTableWidget->rowCount();
        for(int i=0;i<acount;i++)
        {

            if(ui->dayCheckoutTableWidget->item(i,0)->text().startsWith(arg1))
            {
                ui->dayCheckoutTableWidget->setCurrentItem(ui->dayCheckoutTableWidget->item(i,0));
                return ;
            }
        }
    }
}


void mainwindow::doStyle(){
    ui->Tab->setTabIcon(0,QIcon(":/images/kefang.jpg"));
    ui->Tab->setTabIcon(1,QIcon(":/images/guazhang.jpg"));
    ui->Tab->setTabIcon(2,QIcon(":/images/chaxun.jpg"));
    ui->Tab->setTabIcon(3,QIcon(":/images/rijie.jpg"));
    ui->Tab->setTabIcon(4,QIcon(":/images/shezhi.png"));
}

void mainwindow::on_InitializationButton_clicked()
{

    m_db->DB_init(1);
    Init();
    qDebug()<<"初始化";
}

void mainwindow::on_pushButton_clicked()
{
    if(ui->workIdEdit->text().isEmpty()||ui->nameEdit->text().isEmpty()||ui->phoneNum->text().isEmpty()||ui->pawEdit->text().isEmpty()||ui->btnEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","所填入信息不能为空!");
    }
    else if(ui->pawEdit->text()!=ui->btnEdit->text())
    {
         QMessageBox::warning(this,"警告","两次密码不一致!");
    }
    else
    {

          QMessageBox::warning(this,"警告","修改成功!");
          m_db->inf_change(ui->workIdEdit->text(),ui->nameEdit->text(),ui->pawEdit->text(),"",ui->phoneNum->text());
          ui->workIdEdit->setVisible(0);
          ui->nameEdit->setVisible(0);
          ui->phoneNum->setVisible(0);
          ui->pawEdit->setVisible(0);
          ui->btnEdit->setVisible(0);
          ui->label->setVisible(0);
          ui->label_2->setVisible(0);
          ui->label_3->setVisible(0);
          ui->label_4->setVisible(0);
          ui->label_5->setVisible(0);
          ui->pushButton->setVisible(0);
          ui->pushButton_2->setVisible(0);
    }
    reflushSystemContro();
}

void mainwindow::on_pushButton_2_clicked()
{
    ui->workIdEdit->setVisible(0);
    ui->nameEdit->setVisible(0);
    ui->phoneNum->setVisible(0);
    ui->pawEdit->setVisible(0);
    ui->btnEdit->setVisible(0);
    ui->label->setVisible(0);
    ui->label_2->setVisible(0);
    ui->label_3->setVisible(0);
    ui->label_4->setVisible(0);
    ui->label_5->setVisible(0);
    ui->pushButton->setVisible(0);
    ui->pushButton_2->setVisible(0);
}

void mainwindow::on_ChangePasswordButton_clicked()
{
    if(ui->systemTableWidet->currentRow()>=0)
    {
    ui->workIdEdit->setVisible(1);
    ui->nameEdit->setVisible(1);
    ui->phoneNum->setVisible(1);
    ui->pawEdit->setVisible(1);
    ui->btnEdit->setVisible(1);
    ui->label->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_4->setVisible(1);
    ui->label_5->setVisible(1);
    ui->pushButton->setVisible(1);
    ui->pushButton_2->setVisible(1);
}
}
