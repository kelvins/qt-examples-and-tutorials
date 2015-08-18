#include <QCoreApplication>
#include <QHash>
#include <QDebug>
#include <QHashIterator>

/*
 * Like a QMap, but, QMap is orderly by the key and QHash is orderly by a hash.
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<int, QString> Employees;

    Employees.insert(1, "Bob");
    Employees.insert(2, "Amy");
    Employees.insert(3, "Chad");

    qDebug() << "3 = " << Employees.value(3);

    foreach(int i, Employees.keys())
    {
        qDebug() << Employees[i];
    }

    QHashIterator<int, QString> Iter(Employees);
    while(Iter.hasNext())
    {
        Iter.next();
        qDebug() << Iter.key() << " = " << Iter.value();
    }

    return a.exec();
}
