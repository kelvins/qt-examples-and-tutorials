#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>
#include "myclient.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

    void startServer();

protected:
    void incomingConnection(int handle);

signals:

public slots:

};

#endif // MYSERVER_H
