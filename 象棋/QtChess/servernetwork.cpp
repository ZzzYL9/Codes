#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QDataStream>
#include <QMessageBox>
#include "servernetwork.h"

ServerNetwork::ServerNetwork(QObject *parent) : QObject(parent)
{
    serverSocket = NULL;
}

ServerNetwork::~ServerNetwork()
{
    if (server != NULL)
    {
        delete server;
        server = NULL;
    }

}

void ServerNetwork::initServer(int port)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any, port))
    {
        QMessageBox::critical(NULL, tr("错误信息"), tr("监听端口失败！"));
    }
}

int ServerNetwork::sendMsg(char *msg, int len)
{
    return serverSocket->write(msg, len);
}

void ServerNetwork::newConnection()
{
    serverSocket = server->nextPendingConnection();
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(serverSocket, SIGNAL(disconnected()), serverSocket, SLOT(deleteLater()));
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(readData()));

    emit connStateChanged(true);
}

void ServerNetwork::disconnected()
{
    emit connStateChanged(false);
}

void ServerNetwork::readData()
{
     char msg[1024];
     memset(msg, 0, 1024);

     int len = serverSocket->read(msg, 1024);

    emit processMessage(msg, len);
}

