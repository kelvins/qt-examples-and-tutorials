#include <QCoreApplication>
#include <QPointer>

#include "test.h"
#include "child.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test cTest;

    QPointer<Child> cChild = new Child;
    cChild->doSomething();

    return a.exec();
}
