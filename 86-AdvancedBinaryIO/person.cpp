#include "person.h"

Person::Person()
{
}
QString Person::getName() const
{
    return Name;
}

void Person::setName(const QString &value)
{
    Name = value;
}
int Person::getAge() const
{
    return Age;
}

void Person::setAge(int value)
{
    Age = value;
}


