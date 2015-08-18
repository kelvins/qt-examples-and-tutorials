#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <QMutex>

MyThread::MyThread()
{

}

void MyThread::run()
{
    qDebug() << this->name << "running!";

    for (int var = 0; var < 1000; ++var)
    {
        QMutex mutex;
        mutex.lock();
        if( this->Stop )
        {
            mutex.unlock();
            break;
        }
        mutex.unlock();
        qDebug() << this->name << var;
    }
}
