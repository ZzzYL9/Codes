#ifndef TRANSROOM_H
#define TRANSROOM_H

#include <QDialog>
#include<QList>
#include<QMap>
#include"database.h"
namespace Ui {
class transRoom;
}

class transRoom : public QDialog
{
    Q_OBJECT

public:
    explicit transRoom(QWidget *parent = 0);

    transRoom(DataBase *db,QString currentRoomId,QMap<QString,int>room,QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~transRoom();
signals:
    void sendTransRoom(bool yesOrNo,int current);
public slots:
    void onClick();
private slots:
    void on_TransRoomBox_currentIndexChanged(const QString &arg1);

private:
    Ui::transRoom *ui;
    DataBase *m_db;
    QString m_currentRoomId;
    QMap<QString, int>m_room;
};

#endif // TRANSROOM_H
