#include <QCoreApplication>
#include <QtCore>

#include "person.h"
#include "Overloads.h"

void Save()
{
    Person person1;
    person1.setName("Bryan");
    person1.setAge(36);

    Person person2;
    person2.setName("Heather");
    person2.setAge(18);

    QFile file("/home/kelvin/people.txt");
    if( !file.open(QIODevice::WriteOnly) )
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_7);

    out << person1;
    out << person2;

    file.flush();
    file.close();
}

void Load()
{
    Person person1;
    Person person2;

    QFile file("/home/kelvin/people.txt");
    if( !file.open(QIODevice::ReadOnly) )
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_7);

    in >> person1;
    in >> person2;

    file.close();

    qDebug() << "Name:" << person1.getName() << "Age:" << person1.getAge();
    qDebug() << "Name:" << person2.getName() << "Age:" << person2.getAge();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Save();
    Load();

    return a.exec();
}
