#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include "myrunnable.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

    void StartServer();

protected:
    void incomingConnection(int handle);

signals:

public slots:

private:
    QThreadPool *pool;

};

#endif // MYSERVER_H
