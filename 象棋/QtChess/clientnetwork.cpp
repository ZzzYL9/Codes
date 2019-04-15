#include "clientnetwork.h"
#include "networkmsgdef.h"
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QHostAddress>
#include <QMessageBox>

ClientNetwork::ClientNetwork(QObject *parent) : QObject(parent)
{
}

ClientNetwork::~ClientNetwork()
{

}

void ClientNetwork::initClient(QString serverIP, int port)
{
    clientSocket = new QTcpSocket();
    connect(clientSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(clientSocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    QHostAddress addr(serverIP);
    clientSocket->connectToHost(addr, port);
}

int ClientNetwork::sendMsg(char *msg, int len)
{
    return clientSocket->write(msg, len);
}

void ClientNetwork::connected()
{
    emit connStateChanged(true);
    MsgReqGameInfo msg;
    clientSocket->write((char *)&msg, sizeof(msg));
}

void ClientNetwork::disconnected()
{
    emit connStateChanged(false);
}

void ClientNetwork::readData()
{
    char msg[1024];
    memset(msg, 0, 1024);
    int len = clientSocket->read(msg, 1024);
    emit processMessage(msg, len);
}

void ClientNetwork::displayError(QAbstractSocket::SocketError err)
{
    qDebug() << err;
}

