#pragma once
#include "qvector.h"
#include "qpoint.h"
#include "qmap.h"
#include "qpainter.h"


enum ITEM_TYPE{
	ITEM_1 = 0,		//长条
	ITEM_2,			//山字形
	ITEM_3,			//手枪形1
	ITEM_4,			//手枪形2
	ITEM_5,			//田
	ITEM_6,			//Z字形1
	ITEM_MAX,
};


class Item
{
public:
	Item(){}
	Item(ITEM_TYPE t,int nShape = 0);
	~Item(void);

	void InitItem(ITEM_TYPE t,int nShape = 0);
	void ChangeShape(int nAdd = 1);
	
	void AddPoints(QVector<QPoint>& points);
	void Move(int x,int y);
	void Move(QPoint pos);
	void MoveDown(int nRow,int y);		//第nRow行以上的部分下移y个单位，用在消除之后
	void MoveTo(int x,int y);
	void MoveTo(QPoint pos);

	void Draw(QPainter& painter,int nStartX,int nStartY,int nW,int nH);

	void DeleteRow(int y);
public:
	QVector<QPoint> m_points;
	QPoint m_CurPos;
private:
	ITEM_TYPE m_type;
	
	int m_Shapes;
	int m_CurShape;
	
	//QMap<int,QVector<QPoint>> m_allShapePoints;
};

