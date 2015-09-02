#include "child.h"

Child::Child(QObject *parent) :
    QObject(parent)
{
}

void Child::doSomething()
{
    qDebug() << "Do Something";
}
