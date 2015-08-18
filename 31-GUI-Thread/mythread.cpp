#include "mythread.h"
#include <QMutex>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::run()
{
    for (int var = 0; var < 10000; ++var)
    {
        QMutex mutex;
        mutex.lock();
        if( this->Stop )
        {
            mutex.unlock();
            break;
        }
        mutex.unlock();
        this->msleep(100);
        emit NumberChanged(var);
    }
}
