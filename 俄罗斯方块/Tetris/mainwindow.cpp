#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "qwindowdefs.h"
#include <QTime>

#define RECT_COLUMES	15 //纵向方块数量
#define RECT_ROWS		15 //横向方块数量
#define RECT_WIDTH		40
#define RECT_HEIGHT		40

#define CONTRL_WIDTH	300		//控制区域宽度

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->mainToolBar->hide();
	ui->mainToolBar->hide();

	resize(RECT_COLUMES*RECT_WIDTH + CONTRL_WIDTH,RECT_ROWS*RECT_HEIGHT);

	m_ControlPanel = new ControlPanel(this);
	m_ControlPanel->setGeometry(RECT_COLUMES*RECT_WIDTH,0,CONTRL_WIDTH,height());
	
	m_nSpeed = 1;
	m_nLevel = 1;

	NewGame();
	
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::NewGame()
{
	m_FixedItems.m_points.clear();

	qsrand(QTime::currentTime().msec());

	ITEM_TYPE t1 = (ITEM_TYPE)(qrand()%ITEM_MAX);
	ITEM_TYPE t2 = (ITEM_TYPE)(qrand()%ITEM_MAX);
	int s1 = qrand()%4;
	int s2 = qrand()%4;
	m_CurItem.MoveTo(0,0);
	m_NextItem.MoveTo(0,0);
	m_CurItem.InitItem(t1,s1);
	m_NextItem.InitItem(t2,s2);
	m_CurItem.Move(RECT_COLUMES / 2 - 2,0);
	m_NextItem.Move(RECT_COLUMES / 2 - 2,0);

	m_ControlPanel->SetNext(t2,s2);

	//m_nSpeed = 1;		// 1~10档
	//m_ControlPanel->SetSpeed(m_nSpeed);
	m_nScore = 0;

	m_nTimerId = startTimer( (11-m_nSpeed)*100 );
}


void MainWindow::paintEvent(QPaintEvent *)
{
	DrawBKRects();
	DrawFixedRects();
	DrawCurItem();

	update();
}

//画边框
void MainWindow::DrawBKRects()
{
	QPainter painter(this);
    painter.setBrush(Qt::darkYellow);
	painter.setPen(QPen(QColor(Qt::black),2));

    for(int i = 0;i<RECT_ROWS; i++)
	{
        for (int j = 0; j<RECT_COLUMES; j++)
		{
            if (i == 0 || i == RECT_ROWS - 1 || j==0 || j==RECT_COLUMES-1)
			{
                painter.drawRect( i*RECT_WIDTH,j*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
			}
		}
	}
}

void MainWindow::DrawFixedRects()
{
	QPainter painter(this);
	painter.setBrush(Qt::darkGray);
	painter.setPen(QPen(QColor(Qt::darkGray),1));

	m_FixedItems.Draw(painter,0,0,RECT_WIDTH,RECT_HEIGHT);
}

//下一个显示的方块
void MainWindow::DrawCurItem()
{
	QPainter painter(this);
	painter.setBrush(Qt::red);
	painter.setPen(QPen(QColor(Qt::red),1));

	m_CurItem.Draw(painter,0,0,RECT_WIDTH,RECT_HEIGHT);
}


void MainWindow::timerEvent(QTimerEvent* e)
{
	if (e->timerId() == m_nTimerId)
	{
		m_CurItem.Move(0,1);
		if (HitBottom())
		{
			m_CurItem.Move(0,-1);

			AddToFixedRects();

			DeleteFullRows();

			if (HitTop())
			{
				killTimer(m_nTimerId);
				QMessageBox::information(NULL, "GAME OVER", "GAME OVER", QMessageBox::Yes , QMessageBox::Yes);
				NewGame();
				return;
			}

			m_CurItem = m_NextItem;


			ITEM_TYPE t = (ITEM_TYPE)(qrand()%ITEM_MAX);
			int nShape = qrand()%4;
			m_NextItem.InitItem(t,nShape);
			m_NextItem.MoveTo(RECT_COLUMES / 2 - 2,0);

			m_ControlPanel->SetNext(t,nShape);
		}
	}
}

void MainWindow::SetSpeed(int n)
{
	if (m_nSpeed == n)
	{
		return;
	}
	killTimer(m_nTimerId);
	m_nTimerId = startTimer((11 - m_nSpeed) * 100);
}

bool MainWindow::HitSide()
{
	for (int i = 0; i<m_CurItem.m_points.size(); i++)
	{
		QPoint pt = m_CurItem.m_points[i];
		if (pt.x() <= 0 || pt.x() >= RECT_COLUMES - 1)
		{
			return true;
		}
	}
	return false;
}

bool MainWindow::HitBottom()
{
	for (int i = 0; i<m_CurItem.m_points.size(); i++)
	{
		QPoint pt = m_CurItem.m_points[i];
		if (pt.y() >= RECT_ROWS - 1)
		{
			return true;
		}
		if (m_FixedItems.m_points.contains(pt))
		{
			return true;
		}
		//for (int j = 0; j<m_FixedItems.m_points.size(); j++)
		//{
		//	QPoint pt2 = m_FixedItems.m_points[j];
		//	if (pt.x() == pt2.x())
		//	{
		//		if (pt.y() >= pt2.y())
		//		{
		//			return true;
		//		}
		//	}
		//}
	}
	return false;
}

bool MainWindow::HitTop()
{
	for (int i = 0; i<m_FixedItems.m_points.size(); i++)
	{
		QPoint pt = m_FixedItems.m_points[i];
		if (pt.y() <= 1)
		{
			return true;
		}
	}
	return false;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
	if (m_ControlPanel)
	{
		m_ControlPanel->setGeometry(RECT_COLUMES*RECT_WIDTH,0,CONTRL_WIDTH,height());
	}
}

void MainWindow::AddToFixedRects()
{
	m_FixedItems.AddPoints(m_CurItem.m_points);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	int x = 0;
	int y = 0;
	switch(e->key())
	{
	case Qt::Key_Left:
		{
			x = -1;
			break;
		}
	case Qt::Key_Up:
		{
			m_CurItem.ChangeShape();
			if(HitSide() || HitBottom())
			{
				m_CurItem.ChangeShape(-1);
			}
			return;
		}
	case Qt::Key_Right:
		{
			x = 1;
			break;
		}
	case Qt::Key_Down:
		{
			y = 1;
			break;
		}
	}
	m_CurItem.Move(x,y);

	if (HitSide() || HitBottom())
	{
		m_CurItem.Move(-x,-y);
	}
}

void MainWindow::DeleteFullRows()
{
	int nRowsDeleted = 0;
	for (int i = 1; i<RECT_ROWS-1; i++)
	{
		int nCount = 0;
		for (int j = 1; j<RECT_COLUMES-1; j++)
		{
			if (m_FixedItems.m_points.contains(QPoint(j,i)))
			{
				nCount++;
			}
		}
		if (nCount >= RECT_COLUMES-2)
		{
			m_FixedItems.DeleteRow(i);
			m_FixedItems.MoveDown(i,1);	//消除行之上的内容下移一个单位
			nRowsDeleted++;
		}
	}
	//m_FixedItems.Move(0,nRowsDeleted);

	if (nRowsDeleted == 1)
	{
		m_nScore += 100;
	}
	else if (nRowsDeleted == 2)
	{
		m_nScore += 200;
	}
	else if (nRowsDeleted == 3)
	{
		m_nScore += 500;
	}
	else if (nRowsDeleted == 4)
	{
		m_nScore += 1000;
	}
	m_ControlPanel->SetScore(m_nScore);


	if(m_nScore >= 1000 * m_nLevel)
	{
		if (m_nSpeed<10)
		{
			m_nSpeed++;
			killTimer(m_nTimerId);
			m_nTimerId = startTimer( (10-m_nSpeed)*100 );
		}
		m_nLevel++;
		m_ControlPanel->SetSpeed(m_nLevel);
	}

}

void MainWindow::Btn1Clicked()
{
	//if (m_nSpeed<10)
	//{
	//	m_nSpeed++;

	//	killTimer(m_nTimerId);
	//	m_nTimerId = startTimer( (10-m_nSpeed)*100 );

	//	m_ControlPanel->SetSpeed(m_nSpeed);
	//}
}

void MainWindow::Btn2Clicked()
{
	//if (m_nSpeed > 1)
	//{
	//	m_nSpeed --;

	//	killTimer(m_nTimerId);
	//	m_nTimerId = startTimer( (10-m_nSpeed)*100 );

	//	m_ControlPanel->SetSpeed(m_nSpeed);
	//}
}


