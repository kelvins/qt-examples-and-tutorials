#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::startServer()
{
    if( !listen(QHostAddress::Any, 1234) )
    {
        qDebug() << "Not started!";
    }
    else
    {
        qDebug() << "Started!";
    }
}

void MyServer::incomingConnection(int handle)
{
    MyClient *client = new MyClient(this);
    client->setSocket(handle);
}
