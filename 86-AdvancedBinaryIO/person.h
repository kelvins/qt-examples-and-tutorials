#ifndef PERSON_H
#define PERSON_H

#include <QtCore>

class Person
{
public:
    Person();

    QString getName() const;
    void setName(const QString &value);

    int getAge() const;
    void setAge(int value);

    int Age;
    QString Name;
};

#endif // PERSON_H
