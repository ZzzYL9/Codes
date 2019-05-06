#include "transroom.h"
#include "ui_transroom.h"

#include <QPainter>
transRoom::transRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transRoom)
{
    ui->setupUi(this);

}

transRoom::transRoom(DataBase *db,QString currentRoomId, QMap<QString, int> room, QWidget *parent)
    : QDialog(parent),
       m_db(db),
       ui(new Ui::transRoom),
       m_currentRoomId(currentRoomId),
       m_room(room)
{
        ui->setupUi(this);
        ui->curRoomIdEdit->setText(currentRoomId);
        for(auto i=room.begin();i!=room.end();i++)
        {
            ui->TransRoomBox->addItem(i.key());
        }
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&transRoom::onClick);
}
transRoom::~transRoom()
{
    delete ui;
}
void transRoom::on_TransRoomBox_currentIndexChanged(const QString &arg1)
{
    ui->diffEdit->setText(QString::number(m_room[arg1]));
}

void transRoom::onClick()
{
    if(ui->curRoomIdEdit->text()!="")
    {
        sendTransRoom(1,ui->TransRoomBox->currentText().toInt());
        m_db->DB_tiaofang(ui->curRoomIdEdit->text().toInt(),ui->TransRoomBox->currentText().toInt());
    }
}


void transRoom::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("://images/transroom.jpg"));
    p.end();
}
