#ifndef CLIENTNETWORK_H
#define CLIENTNETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class ClientNetwork : public QObject
{
    Q_OBJECT
public:
    explicit ClientNetwork(QObject *parent = 0);
    ~ClientNetwork();
    void initClient(QString serverIP, int port);
    int sendMsg(char *msg, int len);

signals:
    void processMessage(char *msg, int len);
    void connStateChanged(bool);

public slots:
    void connected();
    void disconnected();
    void readData();
    void displayError(QAbstractSocket::SocketError err);
private:
    QTcpSocket *clientSocket;
};

#endif // CLIENTNETWORK_H
