#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define inf 0x3f3f3f3f

#define N 10//点的个数
#define m 16
#define M0 16 //边数  第一组连接关系
#define M1 18 //第二组连接关系
#define M2 17 //第三组连接关系数量
#define max 200//区间范围 最大值
#define min 0// 区间范围 最小值
#define Gmax 50//最大迭代次数
#define K 1 //弹性系数
#define Defaultlength 50 //
#define g Defaultlength*Defaultlength //斥力系数
#define f 10 //斥力常量

#define Alpha 0.5    //求节点动态半径的阿尔法，属于[0,1]

int m1;
float stability[N];//节点稳定度
float dynamicr[N];//每一个点对应的动态半径

struct node{//二维坐标点
    int num;//节点的序号
    float x;
    float y;
};
struct edge{
    int v1;
    int v2;
    float naturelen;
};

struct edge *e;
struct edge e1[m];//边一
struct edge e2[m];//边二
struct edge e3[m];//边三
struct node point[N];//N个点的坐标
struct node point1[N];//时刻一
struct node point2[N];//时刻二
struct node point3[N];//时刻三
struct node point_init[N];//点的初始坐标

int degree[N];//顶点的度
float mass[N];//顶点的质量
float force[N];//顶点i所受的合力
float repulsion[N][N];// 顶点所受的斥力
float tension[N][N];// 顶点所受的张力
float sumforce;//系统合力

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("动态网络拓扑显示系统"));
    image = QImage(1320,682,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(170, 170, 255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充

    QFont font("Microsoft YaHei");
    ui->label->setFont(font);

    read_d1();
    Paint_init();
//    readfile();
}

//可复用
void MainWindow::randinit()
{
    int i;
    for(i=0;i<N;i++){
        point[i].num=i+1;
        point_init[i].num=i+1;
        point[i].x=(float)rand()/RAND_MAX*(max-min)+min;
        point_init[i].x=point[i].x;
        point[i].y=(float)rand()/RAND_MAX*(max-min)+min;
        point_init[i].y=point[i].y;
        force[i]=0;
    }
    for(i=0;i<N;i++){
        printf("%d %.2f %.2f\n",point[i].num,point[i].x,point[i].y);
    }
}

//可复用
void MainWindow::saveinitfile()
{//把点的坐标写入文件
    int i;
    FILE *fp;
    fp=fopen("../wuxiang/txt/point0.txt","w");
    if(fp==NULL){
        return ;
    }
    for(i=0;i<N;i++){
        fprintf(fp,"%d %f %f\n",point[i].num,point[i].x,point[i].y);
    }
    fclose(fp);
}
void MainWindow::savefile()
{//把点的坐标写入文件
    int i;
        FILE *fp;
        fp=fopen("../wuxiang/txt/point1.txt","w");
        if(fp==NULL){
            return ;
        }
        for(i=0;i<N;i++){
            fprintf(fp,"%d %f %f\n",point[i].num,point[i].x,point[i].y);
        }
        fclose(fp);
}

void MainWindow::readfile()
{
    FILE *fp;
    m1=M0;
    e=(struct edge *)malloc(sizeof(struct edge)*m1);
    fp=fopen("../wuxiang/txt/edge.txt","r");
    if(fp==NULL){
        return ;
    }
    int i;
    int w,r;

    i=0;
    while(fscanf(fp,"%d%d",&w,&r)!=EOF){
        e[i].v1=w;
        e[i].v2=r;
    //	printf("w:%d,r:%d,",w,r);
        e[i].naturelen=Defaultlength;
        i++;
        if(i>=m1)break;
    }
    fclose(fp);
}

//读取时刻一的point
void MainWindow::read_p1()
{
    FILE *fp;
    fp=fopen("../wuxiang/txt/point1.txt","r");
    if(fp==NULL){
        return ;
    }
    int i;
    int w;
    float f1, f2;

    i=0;
    while(fscanf(fp,"%d%f%f",&w,&f1,&f2)!=EOF){
        point1[i].num=w;
        point1[i].x=f1;
    //	printf("w:%d,r:%d,",w,r);
        point1[i].y=f2;
        i++;
        if(i>=m)break;
    }
    fclose(fp);
}

//读取时刻一的edge
void MainWindow::read_d1()
{
    FILE *fp;
    fp=fopen("../wuxiang/txt/edge.txt","r");
    if(fp==NULL){
        return ;
    }
    int i;
    int w,r;

    i=0;
    while(fscanf(fp,"%d%d",&w,&r)!=EOF){
        e1[i].v1=w;
        e1[i].v2=r;
    //	printf("w:%d,r:%d,",w,r);
        e1[i].naturelen=Defaultlength;
        i++;
        if(i>=m)break;
    }
    fclose(fp);
}

//读取时刻二的point
void MainWindow::read_p2()
{
    FILE *fp;
    fp=fopen("../wuxiang/txt/point2.txt","r");
    if(fp==NULL){
        return ;
    }
    int i;
    int w;
    float f1, f2;

    i=0;
    while(fscanf(fp,"%d%f%f",&w,&f1,&f2)!=EOF){
        point2[i].num=w;
        point2[i].x=f1;
    //	printf("w:%d,r:%d,",w,r);
        point2[i].y=f2;
        i++;
        if(i>=m)break;
    }
    fclose(fp);
}

//读取边dege1
void MainWindow::read_d2()
{
    FILE *fp;
    fp=fopen("../wuxiang/txt/edge1.txt","r");
    if(fp==NULL){
        return ;
    }
    int i;
    int w,r;

    i=0;
    while(fscanf(fp,"%d%d",&w,&r)!=EOF){
        e2[i].v1=w;
        e2[i].v2=r;
    //	printf("w:%d,r:%d,",w,r);
        e2[i].naturelen=Defaultlength;
        i++;
        if(i>=m)break;
    }
    fclose(fp);
}

//读取时刻三的point
void MainWindow::read_p3()
{
    FILE *fp;
    fp=fopen("../wuxiang/txt/point3.txt","r");
    if(fp==NULL){
        return ;
    }
    int i;
    int w;
    float f1, f2;

    i=0;
    while(fscanf(fp,"%d%f%f",&w,&f1,&f2)!=EOF){
        point3[i].num=w;
        point3[i].x=f1;
    //	printf("w:%d,r:%d,",w,r);
        point3[i].y=f2;
        i++;
        if(i>=m)break;
    }
    fclose(fp);
}

//读取边dege2(时刻三)
void MainWindow::read_d3()
{
    FILE *fp;
    fp=fopen("../wuxiang/txt/edge2.txt","r");
    if(fp==NULL){
        return ;
    }
    int i;
    int w,r;

    i=0;
    while(fscanf(fp,"%d%d",&w,&r)!=EOF){
        e3[i].v1=w;
        e3[i].v2=r;
    //	printf("w:%d,r:%d,",w,r);
        e3[i].naturelen=Defaultlength;
        i++;
        if(i>=m)break;
    }
    fclose(fp);
}


void MainWindow::computedegree()
{//根据连接关系计算各个顶点的度
    int i;
    for(i=0;i<N;i++){
        degree[i]=0;
    }
    for(i=0;i<m1;i++){
    //	printf("e:%d,",e[i].v1-1);
        degree[e[i].v1-1]+=1;
        degree[e[i].v2-1]+=1;
    }

    for(i=0;i<N;i++){
        mass[i]=degree[i];
    //	printf("%d ,",degree[i]);
    }

    return ;
}

void MainWindow::computetension()
{//计算张力
    int i,j;
    float d;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            tension[i][j]=0;
        }
    }
    for(i=0;i<m;i++){
        d=(point[e[i].v1-1].x-point[e[i].v2-1].x)*(point[e[i].v1-1].x-point[e[i].v2-1].x)+(point[e[i].v1-1].y-point[e[i].v2-1].y)*(point[e[i].v1-1].y-point[e[i].v2-1].y);
        d=sqrt(d);
        if(d<=e[i].naturelen){
            tension[e[i].v1-1][e[i].v2-1]=0;
            tension[e[i].v2-1][e[i].v1-1]=0;
        }
        else{
            tension[e[i].v2-1][e[i].v1-1]=K*(d-e[i].naturelen);
            tension[e[i].v1-1][e[i].v2-1]=K*(d-e[i].naturelen);
        }
    }
}

//可复用
void MainWindow::computerepulsion()
{//计算斥力
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            repulsion[i][j]=0;
        }
    }
    float d;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j)continue;
            d=(point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y);
            if(d==0){
                repulsion[i][j]=f;
            }
            else {
                repulsion[i][j]=g*mass[i]*mass[j]/(d);
            }
        }
    }
}


void MainWindow::start_1()
{
    m1=M0;
    srand(time(NULL));
    randinit();

    readfile();//读取连接关系
    saveinitfile();//保存随机初始化的点坐标
    computedegree();//计算点的度和质量

    int k=0;
    int i,j;
    while(k++<Gmax){

        computetension();//计算张力
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                force[i]+=tension[i][j];
                    point[i].x+=(point[j].x-point[i].x)*0.001*(tension[i][j]/mass[i]);
                    point[i].y+=(point[j].y-point[i].y)*0.001*(tension[i][j]/mass[i]);
            }
        }
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(i!=j){
                    force[i]+=repulsion[i][j];
                    point[i].x+=(point[i].x-point[j].x)*0.001*(repulsion[i][j]/mass[i]);
                    point[i].y+=(point[i].y-point[j].y)*0.001*(repulsion[i][j]/mass[i]);
                }
            }
        }
        for(i=0;i<N;i++){
            force[i]=0;
        }
        printf("%d代：\n",k);
        for(i=0;i<N;i++){
            printf("%d %f %f\n",point[i].num,point[i].x,point[i].y);
        }
    }
    savefile();
    //FR完成
    //新的连接关系第二组
    printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("新的连接关系读入\n");
        FILE *fp;
        fp=fopen("../wuxiang/txt/edge1.txt","r");
        if(fp==NULL){
            printf("文件打开失败\n");
            return ;
        }
    //	int i;
        int w,r;
        struct edge * temp;//新的连接关系
        int t;

        t=M1;
        temp=(struct edge*)malloc(sizeof(struct edge)*t);
        i=0;
        while(fscanf(fp,"%d%d",&w,&r)!=EOF){
            temp[i].v1=w;
            temp[i].v2=r;
        //	printf("w:%d,r:%d,",w,r);
            temp[i].naturelen=Defaultlength;
            i++;
            if(i>=t)break;
        }
        fclose(fp);
        //计算节点稳定度 1  0.5   0
        int d1[N][N]={0};
        int d2[N][N]={0};
        for(i=0;i<m1;i++){
            d1[e[i].v1-1][e[i].v2-1]=d1[e[i].v2-1][e[i].v1-1]=1;
        }
        for(i=0;i<t;i++){
            d2[temp[i].v1-1][temp[i].v2-1]=d2[temp[i].v2-1][temp[i].v1-1]=1;
        }
        int aaa;//计数
        for(i=0;i<N;i++){
            aaa=0;
            for(j=0;j<N;j++){
                if(d1[i][j]!=d2[i][j])aaa++;
            }
            if(aaa==0)stability[i]=0;
            else if(aaa==1)stability[i]=0.5;
            else if(aaa>=2)stability[i]=1.0;
        }

        //计算节点动态半径
        for(i=0;i<N;i++)
        {
            dynamicr[i]=Alpha*stability[i];
            degree[i]=0;
            float ss=0;
            for(j=0;j<N;j++){
                if(d2[i][j]!=0){
                    degree[i]++;
                    ss+=stability[j];
                }
            }
            dynamicr[i]+=(1-Alpha)*ss/degree[i];
        }
        //进行迭代
        for(i=0;i<N;i++){
            mass[i]=degree[i];
        }
        free(e);
        e=temp;
        m1=t;
        k=0;
        printf("新读入的连接关系：\n");
        for(i=0;i<m1;i++){
            printf("%d %d %.2f\n",e[i].v1,e[i].v2,e[i].naturelen);
        }
        printf("-------------------\n");
        struct node tmppoint[N];//临时节点存放
        while(k++<Gmax){
            for(i=0;i<N;i++){//未移动前的节点位置先在tmppoint中
                tmppoint[i].num=point[i].num;
                tmppoint[i].x=point[i].x;
                tmppoint[i].y=point[i].y;
            }
            computetension();//计算张力
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    force[i]+=tension[i][j];
                        point[i].x+=(point[j].x-point[i].x)*0.001*(tension[i][j]/mass[i]);
                        point[i].y+=(point[j].y-point[i].y)*0.001*(tension[i][j]/mass[i]);
                }
            }
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    if(i!=j){
                        force[i]+=repulsion[i][j];
                        point[i].x+=(point[i].x-point[j].x)*0.001*(repulsion[i][j]/mass[i]);
                        point[i].y+=(point[i].y-point[j].y)*0.001*(repulsion[i][j]/mass[i]);
                    }
                }
            }
            for(i=0;i<N;i++){
                force[i]=0;
            }
            float dd;
            for(i=0;i<N;i++){
                dd=(tmppoint[i].x-point[i].x)*(tmppoint[i].x-point[i].x)+(tmppoint[i].y-point[i].y)*(tmppoint[i].y-point[i].y);
                dd=sqrt(dd);
                if(dd>dynamicr[i]){//如果移动距离大于动态半径
                    point[i].x=tmppoint[i].x+(point[i].x-tmppoint[i].x)*dynamicr[i]/dd;
                    point[i].y=tmppoint[i].y+(point[i].y-tmppoint[i].y)*dynamicr[i]/dd;
                }
            }
            printf("%d代：\n",k);
            for(i=0;i<N;i++){
                printf("%d %f %f\n",point[i].num,point[i].x,point[i].y);
            }

        }
        //迭代之后，保存新的坐标

            fp=fopen("../wuxiang/txt/point2.txt","w");
            if(fp==NULL){
                return ;
            }
            for(i=0;i<N;i++){
                fprintf(fp,"%d %f %f\n",point[i].num,point[i].x,point[i].y);
            }
            fclose(fp);

        printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("--------------------------------\n");
        printf("新的连接关系读入\n");
        fp=fopen("../wuxiang/txt/edge2.txt","r");
        if(fp==NULL){
            printf("文件打开失败\n");
            return;
        }

        t=M2;
        temp=(struct edge*)malloc(sizeof(struct edge)*t);
        i=0;
        while(fscanf(fp,"%d%d",&w,&r)!=EOF){
            temp[i].v1=w;
            temp[i].v2=r;
        //	printf("w:%d,r:%d,",w,r);
            temp[i].naturelen=Defaultlength;
            i++;
            if(i>=t)break;
        }
        fclose(fp);
        //计算节点稳定度 1  0.5   0
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                d1[i][j]=0;
                d2[i][j]=0;
            }
        }
        for(i=0;i<m1;i++){
            d1[e[i].v1-1][e[i].v2-1]=d1[e[i].v2-1][e[i].v1-1]=1;
        }
        for(i=0;i<t;i++){
            d2[temp[i].v1-1][temp[i].v2-1]=d2[temp[i].v2-1][temp[i].v1-1]=1;
        }
        //aaa;//计数
        for(i=0;i<N;i++){
            aaa=0;
            for(j=0;j<N;j++){
                if(d1[i][j]!=d2[i][j])aaa++;
            }
            if(aaa==0)stability[i]=0;
            else if(aaa==1)stability[i]=0.5;
            else if(aaa>=2)stability[i]=1.0;
        }

        //计算节点动态半径
        for(i=0;i<N;i++)
        {
            dynamicr[i]=Alpha*stability[i];
            degree[i]=0;
            float ss=0;
            for(j=0;j<N;j++){
                if(d2[i][j]!=0){
                    degree[i]++;
                    ss+=stability[j];
                }
            }
            dynamicr[i]+=(1-Alpha)*ss/degree[i];
        }
        //进行迭代
        for(i=0;i<N;i++){
            mass[i]=degree[i];
        }
        free(e);
        e=temp;
        m1=t;
        k=0;
        printf("新读入的连接关系：\n");
        for(i=0;i<m1;i++){
            printf("%d %d %.2f\n",e[i].v1,e[i].v2,e[i].naturelen);
        }
        printf("-------------------\n");
        while(k++<Gmax){
            for(i=0;i<N;i++){//未移动前的节点位置先在tmppoint中
                tmppoint[i].num=point[i].num;
                tmppoint[i].x=point[i].x;
                tmppoint[i].y=point[i].y;
            }
            computetension();//计算张力
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    force[i]+=tension[i][j];
                        point[i].x+=(point[j].x-point[i].x)*0.001*(tension[i][j]/mass[i]);
                        point[i].y+=(point[j].y-point[i].y)*0.001*(tension[i][j]/mass[i]);
                }
            }
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    if(i!=j){
                        force[i]+=repulsion[i][j];
                        point[i].x+=(point[i].x-point[j].x)*0.001*(repulsion[i][j]/mass[i]);
                        point[i].y+=(point[i].y-point[j].y)*0.001*(repulsion[i][j]/mass[i]);
                    }
                }
            }
            for(i=0;i<N;i++){
                force[i]=0;
            }
            float dd;
            for(i=0;i<N;i++){
                dd=(tmppoint[i].x-point[i].x)*(tmppoint[i].x-point[i].x)+(tmppoint[i].y-point[i].y)*(tmppoint[i].y-point[i].y);
                dd=sqrt(dd);
                if(dd>dynamicr[i]){//如果移动距离大于动态半径
                    point[i].x=tmppoint[i].x+(point[i].x-tmppoint[i].x)*dynamicr[i]/dd;
                    point[i].y=tmppoint[i].y+(point[i].y-tmppoint[i].y)*dynamicr[i]/dd;
                }
            }
            printf("%d代：\n",k);
            for(i=0;i<N;i++){
                printf("%d %f %f\n",point[i].num,point[i].x,point[i].y);
            }

        }
        //迭代之后，保存新的坐标

            fp=fopen("../wuxiang/txt/point3.txt","w");
            if(fp==NULL){
                return ;
            }
            for(i=0;i<N;i++){
                fprintf(fp,"%d %f %f\n",point[i].num,point[i].x,point[i].y);
            }
            fclose(fp);
}

void MainWindow::Paint_init()
{
    start_1();
    ui->stackedWidget->setCurrentIndex(0);
    QPainter painter(&image);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int pointx_left=35,pointy_left=660;//确定坐标轴起点坐标，这里定义(35,380)
    int width=580-pointx_left,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

//    painter.drawLine(pointx_left,pointy_left,width+pointx_left,pointy_left);//坐标轴x宽度为width
//    painter.drawLine(pointx_left,pointy_left-height,pointx_left,pointy_left);//坐标轴y高度为height

    float kx=(float)width; //x轴的系数
    float ky=(float)height;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(1);

    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);
    for(int i=0;i<m;i++)
    {
        //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
        painter.setPen(pen);//黑色笔用于连线
        painter.drawLine(pointx_left+kx*(point_init[e1[i].v1-1].x/100),pointy_left-(point_init[e1[i].v1-1].y/100)*ky,pointx_left+kx*(point_init[e1[i].v2-1].x/100),pointy_left-(point_init[e1[i].v2-1].y/100)*ky);
        painter.setPen(penPoint);//蓝色的笔，用于标记各个点
        painter.drawPoint(pointx_left+kx*(point_init[e1[i].v1-1].x/100),pointy_left-(point_init[e1[i].v1-1].y/100)*ky);
        painter.drawPoint(pointx_left+kx*(point_init[e1[i].v2-1].x/100),pointy_left-(point_init[e1[i].v2-1].y/100)*ky);
        painter.drawText(pointx_left+kx*(point_init[e1[i].v1-1].x/100),pointy_left-(point_init[e1[i].v1-1].y/100)*ky-5,
                QString::number(point_init[e1[i].v1-1].num));
        painter.drawText(pointx_left+kx*(point_init[e1[i].v2-1].x/100),pointy_left-(point_init[e1[i].v2-1].y/100)*ky-5,
                QString::number(point_init[e1[i].v2-1].num));
    }
//    painter.drawPoint(pointx_left+kx*(point_init[e[m-1].v2-1].x/100),pointy_left-(point_init[e[m-1].v2-1].y/100)*ky);//绘制最后一个点


    //绘制刻度线
    QPen penDegree;
    penDegree.setColor(Qt::black);
    penDegree.setWidth(2);
    painter.setPen(penDegree);

    //画上x轴刻度线
//    float _maStep=(float)_ma_1/10;//y轴刻度间隔需根据最大值来表示
//    for(int i=0;i<20;i++)//分成10份
//    {
//        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
//        painter.drawLine(pointx_left+(i+1)*width/10,pointy_left,pointx_left+(i+1)*width/10,pointy_left+4);
//        painter.drawText(pointx_left+(i+1)*width/10,
//                         pointy_left+10,QString::number((int)((i+1)*10)));
//    }


    //左边y轴刻度线
//    float _maStep_1=(float)_ma/10;//y轴刻度间隔需根据最大值来表示
//    for(int i=0;i<20;i++)
//    {
//        //代码较长，但是掌握基本原理即可。
//        //主要就是确定一个位置，然后画一条短短的直线表示刻度。
//        painter.drawLine(pointx_left,pointy_left-(i+1)*height/10,
//                         pointx_left-4,pointy_left-(i+1)*height/10);
//        painter.drawText(pointx_left,pointy_left-(i+0.85)*height/10,
//                         QString::number((int)(10*(i+1))));
//    }
}

void MainWindow::Paint(int flag)
{
//    start();
    QPainter painter(&image);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int pointx_left=35,pointy_left=660;//确定坐标轴起点坐标，这里定义(35,380)
    int width=580-pointx_left,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。

//    painter.drawLine(pointx_left,pointy_left,width+pointx_left,pointy_left);//坐标轴x宽度为width
//    painter.drawLine(pointx_left,pointy_left-height,pointx_left,pointy_left);//坐标轴y高度为height

    float kx=(float)width; //x轴的系数
    float ky=(float)height;//y方向的比例系数
    QPen pen,penPoint;
    pen.setColor(Qt::black);
    pen.setWidth(1);

    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);
    if(flag == 1){//时刻一
        for(int i=0;i<m;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx_left+(kx*point1[e1[i].v1-1].x/100),pointy_left-(point1[e1[i].v1-1].y/100)*ky,pointx_left+kx*(point1[e1[i].v2-1].x/100),pointy_left-(point1[e1[i].v2-1].y/100)*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx_left+kx*(point1[e1[i].v1-1].x/100),pointy_left-(point1[e1[i].v1-1].y/100)*ky);
            painter.drawPoint(pointx_left+kx*(point1[e1[i].v2-1].x/100),pointy_left-(point1[e1[i].v2-1].y/100)*ky);
            painter.drawText(pointx_left+kx*(point1[e1[i].v1-1].x/100),pointy_left-(point1[e1[i].v1-1].y/100)*ky-5,
                    QString::number(point1[e1[i].v1-1].num));
            painter.drawText(pointx_left+kx*(point1[e1[i].v2-1].x/100),pointy_left-(point1[e1[i].v2-1].y/100)*ky-5,
                    QString::number(point1[e1[i].v2-1].num));
        }
//        painter.drawPoint(pointx_left+kx*(point1[e1[m-1].v2-1].x/100),pointy_left-(point1[e1[m-1].v2-1].y/100)*ky);//绘制最后一个点
    }
    if(flag == 2){//时刻二
        for(int i=0;i<m;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx_left+(kx*point2[e2[i].v1-1].x/100),pointy_left-(point2[e2[i].v1-1].y/100)*ky,pointx_left+kx*(point2[e2[i].v2-1].x/100),pointy_left-(point2[e2[i].v2-1].y/100)*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx_left+kx*(point2[e2[i].v1-1].x/100),pointy_left-(point2[e2[i].v1-1].y/100)*ky);
            painter.drawPoint(pointx_left+kx*(point2[e2[i].v2-1].x/100),pointy_left-(point2[e2[i].v2-1].y/100)*ky);
            painter.drawText(pointx_left+kx*(point2[e2[i].v1-1].x/100),pointy_left-(point2[e2[i].v1-1].y/100)*ky-5,
                    QString::number(point2[e2[i].v1-1].num));
            painter.drawText(pointx_left+kx*(point2[e2[i].v2-1].x/100),pointy_left-(point2[e2[i].v2-1].y/100)*ky-5,
                    QString::number(point2[e2[i].v2-1].num));
        }
//        painter.drawPoint(pointx_left+kx*(point2[e2[m-1].v2-1].x/100),pointy_left-(point2[e2[m-1].v2-1].y/100)*ky);//绘制最后一个点
    }
    if(flag == 3){//时刻三
        for(int i=0;i<m;i++)
        {
            //由于y轴是倒着的，所以y轴坐标要pointy-a[i]*ky 其中ky为比例系数
            painter.setPen(pen);//黑色笔用于连线
            painter.drawLine(pointx_left+(kx*point3[e3[i].v1-1].x/100),pointy_left-(point3[e3[i].v1-1].y/100)*ky,pointx_left+kx*(point3[e3[i].v2-1].x/100),pointy_left-(point3[e3[i].v2-1].y/100)*ky);
            painter.setPen(penPoint);//蓝色的笔，用于标记各个点
            painter.drawPoint(pointx_left+kx*(point3[e3[i].v1-1].x/100),pointy_left-(point3[e3[i].v1-1].y/100)*ky);
            painter.drawPoint(pointx_left+kx*(point3[e3[i].v2-1].x/100),pointy_left-(point3[e3[i].v2-1].y/100)*ky);
            painter.drawText(pointx_left+kx*(point3[e3[i].v1-1].x/100),pointy_left-(point3[e3[i].v1-1].y/100)*ky-5,
                    QString::number(point3[e3[i].v1-1].num));
            painter.drawText(pointx_left+kx*(point[e[i].v2-1].x/100),pointy_left-(point3[e3[i].v2-1].y/100)*ky-5,
                    QString::number(point3[e3[i].v2-1].num));
        }
//        painter.drawPoint(pointx_left+kx*(point3[e3[m-1].v2-1].x/100),pointy_left-(point3[e3[m-1].v2-1].y/100)*ky);//绘制最后一个点
    }


    //绘制刻度线
    QPen penDegree;
    penDegree.setColor(Qt::black);
    penDegree.setWidth(2);
    painter.setPen(penDegree);

//    画上x轴刻度线
//    for(int i=0;i<20;i++)//分成10份
//    {
//        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
//        painter.drawLine(pointx_left+(i+1)*width/10,pointy_left,pointx_left+(i+1)*width/10,pointy_left+4);
//        painter.drawText(pointx_left+(i+1)*width/10,
//                         pointy_left+10,QString::number((int)((i+1)*10)));
//    }


    //左边y轴刻度线
//    for(int i=0;i<20;i++)
//    {
//        //代码较长，但是掌握基本原理即可。
//        //主要就是确定一个位置，然后画一条短短的直线表示刻度。
//        painter.drawLine(pointx_left,pointy_left-(i+1)*height/10,
//                         pointx_left-4,pointy_left-(i+1)*height/10);
//        painter.drawText(pointx_left,pointy_left-(i+0.85)*height/10,
//                         QString::number((int)(10*(i+1))));
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_one_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    update();
    image = QImage(1320,682,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(219, 187, 255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充
    read_p1();
    read_d1();
    Paint(1);
}

void MainWindow::on_two_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    update();
    image = QImage(1320,682,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(192, 216, 255);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充
    read_p2();
    read_d2();
    Paint(2);
}

void MainWindow::on_three_Btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    update();
    image = QImage(1320,682,QImage::Format_RGB32);  //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255, 235, 225);    //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充
    read_p3();
    read_d3();
    Paint(3);
}
