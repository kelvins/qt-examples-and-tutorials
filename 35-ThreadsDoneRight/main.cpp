#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "myobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread cThread;
    MyObject cObject;

    cObject.doSetup(cThread);
    cObject.moveToThread(&cThread);

    cThread.start();

    return a.exec();
}
