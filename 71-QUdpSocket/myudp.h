#ifndef MYUDP_H
#define MYUDP_H

#include <QUdpSocket>
#include <QObject>
#include <QDebug>

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = 0);

    void SayHello();

signals:

public slots:
    void readyRead();

private:
    QUdpSocket *socket;

};

#endif // MYUDP_H
