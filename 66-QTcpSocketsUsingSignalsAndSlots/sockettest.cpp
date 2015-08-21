#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{

}

void SocketTest::Test()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting...";

    socket->connectToHost("voidrealms.com", 80);

    if( !socket->waitForConnected(1000) )
    {
        qDebug() << "Error:" << socket->errorString();
    }
}


void SocketTest::connected()
{
    qDebug() << "Connected!";

    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void SocketTest::disconnected()
{
    qDebug() << "Disconnected!";
}

void SocketTest::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote:" << bytes;
}

void SocketTest::readyRead()
{
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
}
