#ifndef POINT_H
#define POINT_H

#include <QVector>
#include <iostream>
#include <fstream>

using std::istream;

struct Point_tem1{
    int x; //序号
    double tem_1; //温度1
};

struct Point_tem2{
    int x; //序号
    double tem_2; //温度2
};

struct Point_pa{
    int x; //序号
    int pa; //压强
};

struct Zuobiao{
    int no; //x轴点集
    double tem_1; //温度点集
    double tem_2; //
    int pa; //压强点集
    char ch;
    QVector<Point_tem1> point_tem1_group; //所有温度1集合
    QVector<Point_tem2> point_tem2_group; //所有温度2集合
    QVector<Point_pa> point_pa_group; //所有压强点集合
};

istream &read(istream& is, Zuobiao& Z);

#endif // POINT_H
