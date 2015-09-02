#include "test.h"

Test::Test(QObject *parent) :
    QObject(parent)
{
}

void Test::doTest(QString Command)
{

    QMetaObject MetaObject = this->staticMetaObject;
    QMetaEnum MetaEnum = MetaObject.enumerator(MetaObject.indexOfEnumerator("Tests"));

    switch(MetaEnum.keysToValue(Command.toUpper().toLatin1()))
    {
        case TEST1:
        qDebug() << "Do something for test 1";
        break;

        case TEST2:
        qDebug() << "Do something for test 2";
        break;

        case TEST3:
        qDebug() << "Do something for test 3";
        break;

        default:
        qDebug() << "Unknown command!";
        break;
    }
}
