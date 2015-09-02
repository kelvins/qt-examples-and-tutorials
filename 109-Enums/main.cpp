#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test cTest;
    cTest.doTest(QString("test1"));

    return a.exec();
}
