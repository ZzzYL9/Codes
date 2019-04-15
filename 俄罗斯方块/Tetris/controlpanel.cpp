#include "controlpanel.h"
#include "qlabel.h"
#include "qpainter.h"
#include <QPushButton>


ControlPanel::ControlPanel(QWidget *parent)
	: QWidget(parent)
{
	QFont font;
	font.setPointSize(20);
	font.setFamily(("msyh"));

	QFont font2 = font;
	font2.setPointSize(40);
	font2.setBold(true);

	QLabel* text2 = new QLabel(QStringLiteral("操作方法：左右下箭头移动，上箭头变形。"),this);
	font.setPointSize(20);
	text2->setGeometry(50,50,360,100);
	text2->setFont(font);
	text2->setWordWrap(true);
	//text2->setAlignment(Qt::AlignTop);

	QLabel* text1 = new QLabel(QStringLiteral("下一个："),this);
	text1->setGeometry(50,140,200,40);
	text1->setFont(font);

	QLabel* text3 = new QLabel(QStringLiteral("得分："),this);
	text3->setGeometry(50,280,100,40);
	text3->setFont(font);

	m_pScore = new QLabel(QStringLiteral("0"),this);
	m_pScore->setGeometry(200,280,200,40); 
	m_pScore->setFont(font2);

	QLabel* text4 = new QLabel(QStringLiteral("关数："),this);
	text4->setGeometry(50,350,100,40);
	text4->setFont(font);

	m_pSpeed = new QLabel(QStringLiteral("1"),this);
	m_pSpeed->setGeometry(200,350,100,40);
	m_pSpeed->setFont(font);

	//QPushButton* pBtn1 = new QPushButton(QStringLiteral("加速"),this);
	//pBtn1->setGeometry(50,420,100,25); 
	//pBtn1->releaseKeyboard();

	//QPushButton* pBtn2 = new QPushButton(QStringLiteral("减速"),this);
	//pBtn2->setGeometry(180,420,100,25); 
	//connect(pBtn1, SIGNAL(clicked()), parent, SLOT(Btn1Clicked()));
	//connect(pBtn2, SIGNAL(clicked()), parent, SLOT(Btn2Clicked()));

}

ControlPanel::~ControlPanel()
{

}

void ControlPanel::SetNext(ITEM_TYPE t,int nShape)
{
	m_NextItem.InitItem(t,nShape);
}

void ControlPanel::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setBrush(Qt::red);
	painter.setPen(QPen(QColor(Qt::red),1));

	m_NextItem.Draw(painter,180,180,20,20);

	update();
}

void ControlPanel::SetScore( int n )
{
	m_pScore->setText(QString("%1").arg(n));
}

void ControlPanel::SetSpeed( int n )
{
	m_pSpeed->setText(QString("%1").arg(n));
}

