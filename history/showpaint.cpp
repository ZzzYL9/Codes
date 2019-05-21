#include "showpaint.h"
#include "ui_showpaint.h"
#include "mainwindow.h"
#include "point.h"
#include<cstdlib>
#include<ctime>

int count = 0;
int tem = 0;
QVector<double> vec;//保存温度一的值

ShowPaint::ShowPaint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowPaint)
{
    ui->setupUi(this);
    image = QImage(650,400,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(0,0,0);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

    for(auto it = Z.point_tem1_group.begin(); it != Z.point_tem1_group.end(); it++)
    {
        vec.push_back((*it).tem_1);
    }

    Paint(true);
}

void ShowPaint::Paint(bool flag)
{
    image = QImage(650,400,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(0,0,0);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

    QPainter painter(&image);
    painter.setPen(Qt::white);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int pointx_left=35,pointy_left=360;//确定坐标轴起点坐标，这里定义(35,360)
    int pointx_right = 580, pointy_right = 360;
    int width=580-pointx_left,height=280;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。
    //如果flag==false则将温度一全换为温度二的数据
    if(flag == false){
        for(int i = 0; i < Z.point_tem1_group.size(); i++){
            Z.point_tem1_group[i].tem_1 = Z.point_tem2_group[i].tem_2;
        }
        painter.drawText(pointx_left,
                         pointy_left-height-20,QString("温度二"));
    }
    if(flag == true){
        painter.drawText(pointx_left,
                         pointy_left-height-20,QString("温度一"));
    }
    painter.drawText(pointx_right,
                     pointy_right-height-20,QString("压强"));

    painter.drawLine(pointx_left,pointy_left,width+pointx_left,pointy_left);//坐标轴x宽度为width
    painter.drawLine(pointx_left,pointy_left-height,pointx_left,pointy_left);//坐标轴y高度为height

    //右边Y坐标轴
    painter.drawLine(pointx_right,pointy_right-height,pointx_right,pointy_right);//坐标轴y高度为height

    //获得数据中最大值和最小值、平均数
    int n=10;//n为数据个数
    int _ma=0;//数组里的最大值

    for(int i=0;i<Z.point_pa_group.size();i++)
    {
        if(Z.point_pa_group[i].pa>_ma){
            _ma=Z.point_pa_group[i].pa;
        }
    }

    double kx=(double)width/(n-1); //x轴的系数
    double ky=(double)height/_ma;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::blue);
    pen.setWidth(1);

    painter.drawText(pointx_right-80, 50, QString("压强"));
    painter.setPen(pen);
    painter.drawLine(pointx_right-50, 50, pointx_right, 50);

    penPoint.setColor(Qt::white);
    penPoint.setWidth(5);
    for(int i=0;i<n-1;i++)
    {
        //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        painter.setPen(pen);//黑色笔用于连线
        painter.drawLine(pointx_left+kx*i,pointy_left-Z.point_pa_group[i].pa*ky,pointx_left+kx*(i+1),pointy_left-Z.point_pa_group[i+1].pa*ky);
        painter.setPen(penPoint);//蓝色的笔，用于标记各个点
        painter.drawPoint(pointx_left+kx*i,pointy_left-Z.point_pa_group[i].pa*ky);
    }
    painter.drawPoint(pointx_left+kx*(n-1),pointy_left-Z.point_pa_group[n-1].pa*ky);//绘制最后一个点

    //绘制刻度线
    QPen penDegree;
    penDegree.setColor(Qt::white);
    penDegree.setWidth(2);
    painter.setPen(penDegree);
    //画上x轴刻度线
    for(int i=0;i<n-1;i++)//分成10份
    {
        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
        painter.drawLine(pointx_left+(i+1)*width/9,pointy_left,pointx_left+(i+1)*width/9,pointy_left+4);
        painter.drawText(pointx_left+i*width/9,
                         pointy_left+10,QString::number((int)((i+1)*((double)n/10))));
    }
    painter.drawText(pointx_left+(n-1)*width/9,
                     pointy_left+10,QString::number((int)(n*((double)n/10))));

    //右边y轴刻度线
    double _maStep_1=(double)_ma/10;//y轴刻度间隔需根据最大值来表示
    for(int i=0;i<10;i++)
    {
        //代码较长，但是掌握基本原理即可。
        //主要就是确定一个位置，然后画一条短短的直线表示刻度。
        painter.drawLine(pointx_right,pointy_left-(i+1)*height/10,
                         pointx_right-4,pointy_left-(i+1)*height/10);
        painter.drawText(pointx_right,pointy_left-(i+0.85)*height/10,
                         QString::number((int)(_maStep_1*(i+1))));
    }

    int _ma1=0;//数组里的最大值

    for(int i=0;i<Z.point_tem1_group.size();i++)
    {
        if(Z.point_tem1_group[i].tem_1>_ma1){
            _ma1=Z.point_tem1_group[i].tem_1;
        }
    }

    double kx1=(double)width/(n-1); //x轴的系数
    double ky1=(double)height/_ma1;//y方向的比例系数
    QPen pen1,penPoint1;
    pen1.setColor(Qt::green);
    pen1.setWidth(1);

    painter.drawText(pointx_right-80, 25, QString("温度"));
    painter.setPen(pen1);
    painter.drawLine(pointx_right-50, 25, pointx_right, 25);

    penPoint1.setColor(Qt::red);
    penPoint1.setWidth(5);
    for(int i=0;i<n-1;i++)
    {
        //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        painter.setPen(pen1);//白色笔用于连线
        painter.drawLine(pointx_left+kx1*i,pointy_left-Z.point_tem1_group[i].tem_1*ky1,pointx_left+kx1*(i+1),pointy_left-Z.point_tem1_group[i+1].tem_1*ky1);
        painter.setPen(penPoint1);//蓝色的笔，用于标记各个点
        painter.drawPoint(pointx_left+kx1*i,pointy_left-Z.point_tem1_group[i].tem_1*ky1);
    }
    painter.drawPoint(pointx_left+kx1*(n-1),pointy_left-Z.point_tem1_group[n-1].tem_1*ky1);//绘制最后一个点

    //绘制刻度线
    QPen penDegree1;
    penDegree1.setColor(Qt::white);
    penDegree1.setWidth(2);
    painter.setPen(penDegree1);
    //左边Y轴刻度线
    double _maStep_2=(double)_ma1/10;//y轴刻度间隔需根据最大值来表示
    for(int i=0;i<10;i++)
    {
        //代码较长，但是掌握基本原理即可。
        //主要就是确定一个位置，然后画一条短短的直线表示刻度。
        painter.drawLine(pointx_left,pointy_left-(i+1)*height/10,
                         pointx_left-4,pointy_left-(i+1)*height/10);
        painter.drawText(pointx_left-20,pointy_left-(i+0.85)*height/10,
                         QString::number((int)(_maStep_2*(i+1))));
    }
}

void ShowPaint::Paint_switch(bool flag)
{
    int num = Z.point_pa_group.size()/10; //
    int leave = Z.point_pa_group.size()%10;

    image = QImage(650,400,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(0,0,0);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

    QPainter painter(&image);
    painter.setPen(Qt::white);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int pointx_left=35,pointy_left=360;//确定坐标轴起点坐标，这里定义(35,360)
    int pointx_right = 580, pointy_right = 360;
    int width=580-pointx_left,height=280;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。
    if(flag == false){
        for(int i = 0; i < Z.point_tem1_group.size(); i++){
            Z.point_tem1_group[i].tem_1 = Z.point_tem2_group[i].tem_2;
        }
        painter.drawText(pointx_left,
                         pointy_left-height-20,QString("温度二"));
    }
    if(flag == true){
        for(int i = 0; i < Z.point_tem1_group.size(); i++){
            Z.point_tem1_group[i].tem_1 = vec[i];
        }
        painter.drawText(pointx_left,
                         pointy_left-height-20,QString("温度一"));
    }
    painter.drawText(pointx_right,
                     pointy_right-height-20,QString("压强"));

    painter.drawLine(pointx_left,pointy_left,width+pointx_left,pointy_left);//坐标轴x宽度为width
    painter.drawLine(pointx_left,pointy_left-height,pointx_left,pointy_left);//坐标轴y高度为height

    //右边Y坐标轴
    painter.drawLine(pointx_right,pointy_right-height,pointx_right,pointy_right);//坐标轴y高度为height

    //获得数据中最大值和最小值、平均数
    int n=10;//n为数据个数
    int _ma=0;//数组里的最大值

    if(count > 0&&count < num){
        for(int i=0;i<Z.point_pa_group.size();i++)
        {
            if(Z.point_pa_group[i].pa>_ma){
                _ma=Z.point_pa_group[i].pa;
            }
        }

        double kx=(double)width/(n-1); //x轴的系数
        double ky=(double)height/_ma;//y方向的比例系数
        QPen pen,penPoint;
        pen.setColor(Qt::blue);
        pen.setWidth(1);

        painter.drawText(pointx_right-80, 50, QString("压强"));
        painter.setPen(pen);
        painter.drawLine(pointx_right-50, 50, pointx_right, 50);

        penPoint.setColor(Qt::white);
        penPoint.setWidth(5);
        int j = 0;
        for(int i=count*10;i<(count+1)*10-1;i++)
        {
            if(j < n-1){
                painter.setPen(pen);//黑色笔用于连线
                painter.drawLine(pointx_left+kx*j,pointy_left-Z.point_pa_group[i].pa*ky,pointx_left+kx*(j+1),pointy_left-Z.point_pa_group[i+1].pa*ky);
                painter.setPen(penPoint);//蓝色的笔，用于标记各个点
                painter.drawPoint(pointx_left+kx*j,pointy_left-Z.point_pa_group[i].pa*ky);
                painter.drawText(pointx_left+j*width/9,
                                 pointy_left+10,QString::number((int)(i+1)));
                j++;
            }
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数

        }
        painter.drawPoint(pointx_left+kx*(n-1),pointy_left-Z.point_pa_group[(count+1)*10-1].pa*ky);//绘制最后一个点
        painter.drawText(pointx_left+(n-1)*width/9,
                         pointy_left+10,QString::number((int)(((count+1)*10))));

        //绘制刻度线
        QPen penDegree;
        penDegree.setColor(Qt::white);
        penDegree.setWidth(2);
        painter.setPen(penDegree);

        //画上x轴刻度线
        for(int i=0;i<9;i++)//分成9份
        {
            //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
            painter.drawLine(pointx_left+(i+1)*width/9,pointy_left,pointx_left+(i+1)*width/9,pointy_left+4);
        }

        //右边y轴刻度线
        double _maStep_1=(double)_ma/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            //代码较长，但是掌握基本原理即可。
            //主要就是确定一个位置，然后画一条短短的直线表示刻度。
            painter.drawLine(pointx_right,pointy_left-(i+1)*height/10,
                             pointx_right-4,pointy_left-(i+1)*height/10);
            painter.drawText(pointx_right,pointy_left-(i+0.85)*height/10,
                             QString::number((int)(_maStep_1*(i+1))));
        }

        int n1=10;//n为数据个数
        int _ma1=0;//数组里的最大值

        for(int i=0;i<Z.point_tem1_group.size();i++)
        {
            if(Z.point_tem1_group[i].tem_1>_ma1){
                _ma1=Z.point_tem1_group[i].tem_1;
            }
        }

        double kx1=(double)width/(n1-1); //x轴的系数
        double ky1=(double)height/_ma1;//y方向的比例系数
        QPen pen1,penPoint1;
        pen1.setColor(Qt::green);
        pen1.setWidth(1);

        painter.drawText(pointx_right-80, 25, QString("温度"));
        painter.setPen(pen1);
        painter.drawLine(pointx_right-50, 25, pointx_right, 25);

        penPoint1.setColor(Qt::red);
        penPoint1.setWidth(5);

        int k = 0;
        for(int i=count*10;i<(count+1)*10-1;i++)
        {
            if(k < n1-1){
                //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
                painter.setPen(pen1);//黑色笔用于连线
                painter.drawLine(pointx_left+kx1*k,pointy_left-Z.point_tem1_group[i].tem_1*ky1,pointx_left+kx1*(k+1),pointy_left-Z.point_tem1_group[i+1].tem_1*ky1);
                painter.setPen(penPoint1);//蓝色的笔，用于标记各个点
                painter.drawPoint(pointx_left+kx1*k,pointy_left-Z.point_tem1_group[i].tem_1*ky1);
                k++;
            }
        }
        painter.drawPoint(pointx_left+kx1*(n1-1),pointy_left-Z.point_tem1_group[(count+1)*10-1].tem_1*ky1);//绘制最后一个点

        //绘制刻度线
        QPen penDegree1;
        penDegree1.setColor(Qt::white);
        penDegree1.setWidth(2);
        painter.setPen(penDegree1);

        //左边Y轴刻度线
        double _maStep_2=(double)_ma1/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            //代码较长，但是掌握基本原理即可。
            //主要就是确定一个位置，然后画一条短短的直线表示刻度。
            painter.drawLine(pointx_left,pointy_left-(i+1)*height/10,
                             pointx_left-4,pointy_left-(i+1)*height/10);
            painter.drawText(pointx_left-20,pointy_left-(i+0.85)*height/10,
                             QString::number((int)(_maStep_2*(i+1))));
        }
/**************************************************/

    }else if(count == num){
        int _ma1 = 0;
        for(int i=0;i<Z.point_pa_group.size();i++)
        {
            if(Z.point_pa_group[i].pa>_ma1){
                _ma1=Z.point_pa_group[i].pa;
            }
        }

        double kx1=(double)width/(n-1); //x轴的系数
        double ky1=(double)height/_ma1;//y方向的比例系数
        QPen pen,penPoint;
        pen.setColor(Qt::blue);
        pen.setWidth(1);

        painter.drawText(pointx_right-80, 50, QString("压强"));
        painter.setPen(pen);
        painter.drawLine(pointx_right-50, 50, pointx_right, 50);

        penPoint.setColor(Qt::white);
        penPoint.setWidth(5);
        int j = 0;
        for(int i=count*10;i<count*10+leave-1;i++)
        {
            if(j < leave-1){
                painter.setPen(pen);//黑色笔用于连线
                painter.drawLine(pointx_left+kx1*j,pointy_left-Z.point_pa_group[i].pa*ky1,pointx_left+kx1*(j+1),pointy_left-Z.point_pa_group[i+1].pa*ky1);
                painter.setPen(penPoint);//蓝色的笔，用于标记各个点
                painter.drawPoint(pointx_left+kx1*j,pointy_left-Z.point_pa_group[i].pa*ky1);
                painter.drawText(pointx_left+j*width/9,
                                 pointy_left+10,QString::number((int)((i+1))));
                j++;
            }
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        }
        painter.drawPoint(pointx_left+kx1*(leave-1),pointy_left-Z.point_pa_group[count*10+leave-1].pa*ky1);//绘制最后一个点
        painter.drawText(pointx_left+(leave-1)*width/9,
                         pointy_left+10,QString::number((int)((count*10+leave))));

        //绘制刻度线
        QPen penDegree1;
        penDegree1.setColor(Qt::white);
        penDegree1.setWidth(2);
        painter.setPen(penDegree1);

        //画上x轴刻度线
        for(int i=0;i<9;i++)//分成10份
        {
            //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
            painter.drawLine(pointx_left+(i+1)*width/9,pointy_left,pointx_left+(i+1)*width/9,pointy_left+4);
        }

        //右边y轴刻度线
        double _maStep_1=(double)_ma1/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            painter.drawLine(pointx_right,pointy_left-(i+1)*height/10,
                             pointx_right-4,pointy_left-(i+1)*height/10);
            painter.drawText(pointx_right,pointy_left-(i+0.85)*height/10,
                             QString::number((int)(_maStep_1*(i+1))));
        }

        for(int i=0;i<Z.point_tem1_group.size();i++)
        {
            if(Z.point_tem1_group[i].tem_1>_ma){
                _ma=Z.point_tem1_group[i].tem_1;
            }
        }

        double kx=(double)width/(n-1); //x轴的系数
        double ky=(double)height/_ma;//y方向的比例系数
        pen.setColor(Qt::green);
        pen.setWidth(1);

        painter.drawText(pointx_right-80, 25, QString("温度"));
        painter.setPen(pen);
        painter.drawLine(pointx_right-50, 25, pointx_right, 25);

        penPoint.setColor(Qt::red);
        penPoint.setWidth(5);
        int m = 0;
        for(int i=count*10;i<count*10+leave-1;i++)
        {
            if(m < leave-1){
                //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
                painter.setPen(pen);//黑色笔用于连线
                painter.drawLine(pointx_left+kx*m,pointy_left-Z.point_tem1_group[i].tem_1*ky,pointx_left+kx*(m+1),pointy_left-Z.point_tem1_group[i+1].tem_1*ky);
                painter.setPen(penPoint);//蓝色的笔，用于标记各个点
                painter.drawPoint(pointx_left+kx*m,pointy_left-Z.point_tem1_group[i].tem_1*ky);
                m++;
            }

        }
        painter.drawPoint(pointx_left+kx*(leave-1),pointy_left-Z.point_tem1_group[count*10+leave-1].tem_1*ky);//绘制最后一个点

        //绘制刻度线
        QPen penDegree;
        penDegree.setColor(Qt::white);
        penDegree.setWidth(2);
        painter.setPen(penDegree);
        //左边Y轴刻度线
        double _maStep_2=(double)_ma/10;//y轴刻度间隔需根据最大值来表示
        for(int i=0;i<10;i++)
        {
            painter.drawLine(pointx_left,pointy_left-(i+1)*height/10,
                             pointx_left-4,pointy_left-(i+1)*height/10);
            painter.drawText(pointx_left-20,pointy_left-(i+0.85)*height/10,
                             QString::number((int)(_maStep_2*(i+1))));
        }
    }
}


ShowPaint::~ShowPaint()
{
    delete ui;
}

void ShowPaint::on_Btn_back_clicked()
{
    count = 0;
    Z.point_pa_group.clear();
    Z.point_tem1_group.clear();
    Z.point_tem2_group.clear();

    MainWindow *M = new MainWindow;
    this->hide();
    M->show();
}

void ShowPaint::on_Btn_tem1_clicked()
{

    tem = 0;//如果温度一按钮被按下则将标志置为0
    Paint_switch(true);
}

void ShowPaint::on_Btn_last_clicked()
{
    ui->Btn_next->setEnabled(true);
    update();
    count--;
    int num = Z.point_pa_group.size()/10; //
    if(tem == 0){//温度一
        if(count > 0&&count < num)
            Paint_switch(true);
        if(count == 0){
            update();
            image = QImage(650,300,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
            QColor backColor = qRgb(0,0,0);    //画布初始化背景色使用白色
            image.fill(backColor);//对画布进行填充

            Paint(true);
            ui->Btn_last->setEnabled(false);
        }
    }
    if(tem == 1){
        if(count > 0&&count < num)
            Paint_switch(false);
        if(count == 0){
            update();
            image = QImage(650,300,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
            QColor backColor = qRgb(0,0,0);    //画布初始化背景色使用白色
            image.fill(backColor);//对画布进行填充

            Paint(false);
            ui->Btn_last->setEnabled(false);
        }
    }
}

void ShowPaint::on_Btn_next_clicked()
{
    ui->Btn_last->setEnabled(true);
    update();
    int num = Z.point_pa_group.size()/10; //
    count++;
    if(tem == 0)
        Paint_switch(true);
    if(tem == 1)
        Paint_switch(false);
    if(count == num)
        ui->Btn_next->setEnabled(false);
}

void ShowPaint::on_Btn_tem2_clicked()
{
    tem = 1;//温度二
    Paint_switch(false);
}
