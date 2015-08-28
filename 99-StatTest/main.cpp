#include <QCoreApplication>
#include <QDebug>
#include "staticlib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StaticLib cLib;
    cLib.Test();

    return a.exec();
}
