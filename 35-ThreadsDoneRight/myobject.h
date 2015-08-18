#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyObject : public QObject
{
    Q_OBJECT

public:
    explicit MyObject(QObject *parent = 0);
    void doSetup(QThread &cThread);

signals:

public slots:
    void doWork();

};

#endif // MYOBJECT_H
