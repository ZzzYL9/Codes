#include "Item.h"
#include "qpainter.h"

Item::Item(ITEM_TYPE t,int nShape)
{
	m_CurPos = QPoint(0,0);

	InitItem(t,nShape);
}

Item::~Item(void)
{
}

void Item::InitItem(ITEM_TYPE t,int nShape)
{
	m_points.clear();

	m_type = t;
	m_CurShape = nShape;
	switch (t)
	{
	case ITEM_1:
		{
			if (nShape%2 == 0)
			{
				for (int i = 0; i < 4; i++)
				{
					m_points.append(m_CurPos + QPoint( i,2));
				}
			}
			else if (nShape%2 == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					m_points.append(m_CurPos + QPoint( 2,i));
				}
			}
			break;
		}
	case ITEM_2:
		{
			if (nShape == 0)
			{
				m_points.append(m_CurPos + QPoint( 1,0));
				m_points.append(m_CurPos + QPoint( 0,1));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
			}
			else if (nShape == 1)
			{
				m_points.append(m_CurPos + QPoint( 1,0));
				m_points.append(m_CurPos + QPoint( 1,2));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
			}
			else if (nShape == 2)
			{
				m_points.append(m_CurPos + QPoint( 0,1));
				m_points.append(m_CurPos + QPoint( 1,2));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
			}
			else if (nShape == 3)
			{
				m_points.append(m_CurPos + QPoint( 1,0));
				m_points.append(m_CurPos + QPoint( 0,1));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 1,2));
			}
			
			break;
		}
	case ITEM_3:
		{
			if (nShape == 0)
			{
				m_points.append(m_CurPos + QPoint( 1,0));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 1,2));
				m_points.append(m_CurPos + QPoint( 2,2));
			}
			else if (nShape == 1)
			{
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 3,1));
				m_points.append(m_CurPos + QPoint( 1,2));
			}
			else if (nShape == 2)
			{
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 2,2));
				m_points.append(m_CurPos + QPoint( 2,3));
			}
			else if (nShape == 3)
			{
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 2,2));
				m_points.append(m_CurPos + QPoint( 1,2));
				m_points.append(m_CurPos + QPoint( 0,2));
			}
			break;
		}
	case ITEM_4:
		{
			if (nShape == 0)
			{
				m_points.append(m_CurPos + QPoint( 2,0));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 2,2));
				m_points.append(m_CurPos + QPoint( 1,2));
			}
			else if (nShape == 1)
			{
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 1,2));
				m_points.append(m_CurPos + QPoint( 2,2));
				m_points.append(m_CurPos + QPoint( 3,2));
			}
			else if (nShape == 2)
			{
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 1,2));
				m_points.append(m_CurPos + QPoint( 1,3));
			}
			else if (nShape == 3)
			{
				m_points.append(m_CurPos + QPoint( 0,1));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 2,2));
			}
			break;
		}
	case ITEM_5:
		{
			m_points.append(m_CurPos + QPoint( 0,0));
			m_points.append(m_CurPos + QPoint( 0,1));
			m_points.append(m_CurPos + QPoint( 1,0));
			m_points.append(m_CurPos + QPoint( 1,1));
			break;
		}
	case ITEM_6:
		{
			if (nShape == 0)
			{
				m_points.append(m_CurPos + QPoint( 1,0));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 2,2));
			}
			else if (nShape == 1)
			{
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 0,2));
				m_points.append(m_CurPos + QPoint( 1,2));
			}
			else if (nShape == 2)
			{
				m_points.append(m_CurPos + QPoint( 2,0));
				m_points.append(m_CurPos + QPoint( 2,1));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 1,2));
			}
			else if (nShape == 3)
			{
				m_points.append(m_CurPos + QPoint( 0,1));
				m_points.append(m_CurPos + QPoint( 1,1));
				m_points.append(m_CurPos + QPoint( 1,2));
				m_points.append(m_CurPos + QPoint( 2,2));
			}
			break;
		}
	default:
		break;
	}
}

void Item::ChangeShape(int nAdd)
{
	m_CurShape = (m_CurShape + nAdd)%4;
	InitItem(m_type,m_CurShape);
}

void Item::Draw(QPainter& painter,int nStartX,int nStartY,int nW,int nH)
{
	for (int i = 0; i< m_points.size(); i++)
	{
		QPoint pt = m_points[i];
		painter.drawRect(QRect(nStartX + pt.x() * nW,nStartY + pt.y() * nH,nW,nH));
	}
}

void Item::AddPoints(QVector<QPoint>& points)
{
	for (int i = 0; i<points.size(); i++)
	{
		if (!m_points.contains(points[i]))
		{
			m_points.append(points[i]);
		}
	}
}

void Item::Move(int x,int y)
{
	for (int i = 0; i<m_points.size(); i++)
	{
		int x1 = m_points[i].x() + x;
		int y1 = m_points[i].y() + y;
		m_points[i].setX(x1);
		m_points[i].setY(y1);
	}
	m_CurPos += QPoint(x,y);
}

void Item::Move(QPoint pos)
{
	Move(pos.x(),pos.y());
}

void Item::MoveTo(int x,int y)
{
	for (int i = 0; i<m_points.size(); i++)
	{
		int x1 = m_points[i].x() - m_CurPos.x() + x;
		int y1 = m_points[i].y() - m_CurPos.y() + y;
		m_points[i].setX(x1);
		m_points[i].setY(y1);
	}
	m_CurPos = QPoint(x,y);
}

void Item::MoveTo(QPoint pos)
{
	MoveTo(pos.x(),pos.y());
}

void Item::DeleteRow( int y )
{
	QVector<QPoint> newPoints;
	for (int i=0; i<m_points.size(); i++)
	{
		if (m_points[i].y() != y)
		{
			newPoints.append(m_points[i]);
		}
	}
	m_points = newPoints;
}

void Item::MoveDown( int nRow,int y )
{
	for (int i = 0; i<m_points.size(); i++)
	{
		if(m_points[i].y() < nRow)
		{
			m_points[i].setY(m_points[i].y()+ y);
		}
	}
}
