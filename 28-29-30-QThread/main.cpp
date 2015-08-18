#include <QCoreApplication>
#include "mythread.h"

/*
 * Example of Threads and QMutex Class (used to protect an object) to prevent deadlock
 * Ex.: mutex.lock(); and mutex.unlock();
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mThread1;
    MyThread mThread2;
    MyThread mThread3;

    mThread1.name = "mThread1";
    mThread2.name = "mThread2";
    mThread3.name = "mThread3";

    mThread1.start(QThread::HighestPriority);
    mThread2.start();
    mThread3.start(QThread::LowestPriority);

    mThread1.Stop = false;
    mThread1.wait();
    mThread1.Stop = true;

    return a.exec();
}
