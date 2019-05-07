#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QMap>
#include <iostream>
#include <fstream>
#include "point.h"
#include "showpaint.h"

Zuobiao Z;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("历史记录选择"));

    QString root = "..//history//csv";//文件存在的目录
    QDir rootDir(root);
    QString name = "*.csv"; //选择要筛选的文件类型
    QStringList filters; //筛选器
    filters<<name;
    QFileInfoList list = rootDir.entryInfoList(filters);
    showFileInfoList(list);



}

void MainWindow::showFileInfoList(QFileInfoList list)
{
    for(unsigned int i=0; i<list.count() ;i++)
    {
        QFileInfo tmpFileInfo = list.at(i);
        if(tmpFileInfo.isDir())
        {
//            QIcon icon("dir.png"); //在显示的目录前加图片
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
//            QListWidgetItem *tmp = new QListWidgetItem(icon, fileName); //添加图片
            ui->listWidget->addItem(tmp);
        }
        else if(tmpFileInfo.isFile())
        {
//            QIcon icon("../history/jinmao_1.jpg");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
            ui->listWidget->addItem(tmp);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_del_clicked()
{
    QString dir_name;
    QString path_name = "..//history//csv/";
    if(ui->listWidget->currentItem()!=Q_NULLPTR)
    {
        dir_name = ui->listWidget->currentItem()->text();
        QString str = path_name + dir_name;
        QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete item;
        QFile file(str);
        if (file.exists())
        {
            file.remove();
        }
    }
}

void MainWindow::on_Btn_OK_clicked()
{
//    QMap<int, QPair<double, int>> dates;
    QVector<Zuobiao> test;
    QString str;
    QString dir_name;
    QString path_name = "..//history//csv/";
    if(ui->listWidget->currentItem()!=Q_NULLPTR){
        dir_name = ui->listWidget->currentItem()->text();
        str = path_name + dir_name;
    }
    std::string s = str.toStdString();
//    std::ifstream ifs{"../history/csv/2015.csv"};
    std::ifstream ifs(s);
    while(read(ifs, Z)){
        test.push_back(Z);
    }
    Point_tem1 pt1;
    Point_tem2 pt2;
    Point_pa pp;
    for(auto it = test.begin(); it != test.end(); it++){
//        qDebug() << (*it).no << " " << (*it).tem_1 << " " << (*it).tem_2 << " " << (*it).pa;
        pt1.x = (*it).no;
        pt1.tem_1 = (*it).tem_1;
        pt2.x = (*it).no;
        pt2.tem_2 = (*it).tem_2;
        pp.x = (*it).no;
        pp.pa = (*it).pa;
        Z.point_tem1_group.push_back(pt1);
        Z.point_tem2_group.push_back(pt2);
        Z.point_pa_group.push_back(pp);
    }
    ifs.close();
    ShowPaint *S = new ShowPaint;
    S->show();
    this->hide();

//    QFile file(str);
//    if(!file.open(QFile::ReadOnly | QFile::Text)){
//       qDebug() << "Could not open file for writing";
//       return;
//    }else {
//        qDebug() << "open successfully";
//    }
//    QTextStream in(&file);
//    while (!in.atEnd()) {
//        QString line = in.readLine();
//        QString str1 = line.mid(0,2);
//        QString str2 = line.mid(3,5);
//        QString str3 = line.mid(9,12);

//        QPair<double, int> flag;
//        int a = str1.toInt();
//        double b = str2.toDouble();
//        int c = str3.toInt();
//        flag.first = b;
//        flag.second = c;

//        dates.insert(a, flag);

//        qDebug() << a << " " << b << " " << c;
//    }
//    for(auto i = dates.constBegin(); i != dates.constEnd(); i++){
//        qDebug() << i.key() << " " << i.value().first << " " << i.value().second;
//    }

}
