#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore>
#include <QString>

class MyThread : public QThread
{
public:
    MyThread();
    void run();
    QString name;
    bool Stop;
};

#endif // MYTHREAD_H
