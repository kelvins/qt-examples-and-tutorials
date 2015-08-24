#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>
#include "mytask.h"

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = 0);

    void setSocket(int descriptor);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void TaskResult(int number);

private:
    QTcpSocket *socket;

};

#endif // MYCLIENT_H
