#include <QCoreApplication>
#include <QVariant>
#include <QDebug>

#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant v = 123.02;

    qDebug() << v.toInt();
    qDebug() << v.toDouble();

    if( v.canConvert<QString>() )
    {
        qDebug() << v.toString();
    }

    myClass cClass;
    cClass.Number = 23;

    QVariant z = QVariant::fromValue(cClass);

    myClass zClass = z.value<myClass>();

    qDebug() << zClass.Number;

    return a.exec();
}
