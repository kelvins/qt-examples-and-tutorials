#include "myobject.h"
#include <QThread>
#include <QDebug>

MyObject::MyObject(QObject *parent) :
    QObject(parent)
{
}

void MyObject::doSetup(QThread &cThread)
{
    connect(&cThread, SIGNAL(started()), this, SLOT(doWork()));
}

void MyObject::doWork()
{
    for (int var = 0; var < 100; ++var)
    {
        qDebug() << var;
    }
}
