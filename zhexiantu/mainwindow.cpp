#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cstdlib>
#include<ctime>
#define inf 0x3f3f3f3f
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = QImage(600,300,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255,255,255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

    Paint();
}

void MainWindow::Paint()
{
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点


    int pointx_left=35,pointy_left=280;//确定坐标轴起点坐标，这里定义(35,280)
    int pointx_right = 580, pointy_right = 280;
    int width=580-pointx_left,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

    //绘制坐标轴 坐标轴原点(35，280)
    painter.drawRect(5,5,600-10,300-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。

    painter.drawLine(pointx_left,pointy_left,width+pointx_left,pointy_left);//坐标轴x宽度为width
    painter.drawLine(pointx_left,pointy_left-height,pointx_left,pointy_left);//坐标轴y高度为height

    //右边Y坐标轴
    painter.drawLine(pointx_right,pointy_right,width+pointx_right,pointy_right);//坐标轴x宽度为width
    painter.drawLine(pointx_right,pointy_right-height,pointx_right,pointy_right);//坐标轴y高度为height


    srand(time(NULL));

    //获得数据中最大值和最小值、平均数
    int n=30;//n为数据个数
    double sum=0;
    double ave=0;
    int _ma=0;//数组里的最大值
    int _mi=inf;

    int a[n];//数据储存在数组a中，大小为n

    for(int i=0;i<n;i++)
        a[i]=rand()%40+20;
    int maxpos=0,minpos=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(a[i]>_ma){
            _ma=a[i];
            maxpos=i;
        }
        if(a[i]<_mi){
            _mi=a[i];
            minpos=i;
        }
    }
    ave=sum/n;//平均数

    double kx=(double)width/(n-1); //x轴的系数
    double ky=(double)height/_ma;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(2);

    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);
    for(int i=0;i<n-1;i++)
    {
        //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        painter.setPen(pen);//黑色笔用于连线
        painter.drawLine(pointx_left+kx*i,pointy_left-a[i]*ky,pointx_left+kx*(i+1),pointy_left-a[i+1]*ky);
        painter.setPen(penPoint);//蓝色的笔，用于标记各个点
        painter.drawPoint(pointx_left+kx*i,pointy_left-a[i]*ky);
    }
    painter.drawPoint(pointx_left+kx*(n-1),pointy_left-a[n-1]*ky);//绘制最后一个点

    //绘制平均线
    QPen penAve;
    penAve.setColor(Qt::red);//选择红色
    penAve.setWidth(2);
    penAve.setStyle(Qt::DotLine);//线条类型为虚线
    painter.setPen(penAve);
    painter.drawLine(pointx_left,pointy_left-ave*ky,pointx_left+width,pointy_left-ave*ky);

    //绘制最大值和最小值
    QPen penMaxMin;
    penMaxMin.setColor(Qt::darkGreen);//暗绿色
    painter.setPen(penMaxMin);
    painter.drawText(pointx_left+kx*maxpos-kx,pointy_left-a[maxpos]*ky-5,
                     "最大值"+QString::number(_ma));
    painter.drawText(pointx_left+kx*minpos-kx,pointy_left-a[minpos]*ky+15,
                     "最小值"+QString::number(_mi));

    penMaxMin.setColor(Qt::red);
    penMaxMin.setWidth(7);
    painter.setPen(penMaxMin);
    painter.drawPoint(pointx_left+kx*maxpos,pointy_left-a[maxpos]*ky);//标记最大值点
    painter.drawPoint(pointx_left+kx*minpos,pointy_left-a[minpos]*ky);//标记最小值点


    //绘制刻度线
    QPen penDegree;
    penDegree.setColor(Qt::black);
    penDegree.setWidth(2);
    painter.setPen(penDegree);
    //画上x轴刻度线
    for(int i=0;i<10;i++)//分成10份
    {
        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
        painter.drawLine(pointx_left+(i+1)*width/10,pointy_left,pointx_left+(i+1)*width/10,pointy_left+4);
        painter.drawText(pointx_left+(i+0.65)*width/10,
                         pointy_left+10,QString::number((int)((i+1)*((double)n/10))));
    }
    //y轴刻度线
    double _maStep=(double)_ma/10;//y轴刻度间隔需根据最大值来表示
    for(int i=0;i<10;i++)
    {
        //代码较长，但是掌握基本原理即可。
        //主要就是确定一个位置，然后画一条短短的直线表示刻度。
        painter.drawLine(pointx_left,pointy_left-(i+1)*height/10,
                         pointx_left-4,pointy_left-(i+1)*height/10);
        painter.drawText(pointx_left-20,pointy_left-(i+0.85)*height/10,
                         QString::number((int)(_maStep*(i+1))));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
