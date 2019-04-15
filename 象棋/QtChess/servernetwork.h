#ifndef SERVERNETWORK_H
#define SERVERNETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>

class ServerNetwork : public QObject
{
    Q_OBJECT
public:
    explicit ServerNetwork(QObject *parent = 0);
    ~ServerNetwork();
    void initServer(int port);
    int sendMsg(char *msg, int len);

signals:
    void processMessage(char *msg, int len);
    void connStateChanged(bool);

public slots:
    void newConnection();
    void disconnected();
    void readData();

private:
    QTcpServer *server;
    QTcpSocket *serverSocket;
};

#endif // SERVERNETWORK_H
