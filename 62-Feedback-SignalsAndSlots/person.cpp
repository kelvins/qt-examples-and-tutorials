#include "person.h"

Person::Person(QObject *parent) :
    QObject(parent)
{
}

void Person::Listen(QString Words)
{
    qDebug() << Name << " says someone told me..." << Words;
}

void Person::Gossip(QString Words)
{
    qDebug() << Name << " says " << Words;
    emit Speak(Words);
}
