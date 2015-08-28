#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtCore>

class myClass
{
public:
    myClass();
    int Number;
};

Q_DECLARE_METATYPE(myClass);

#endif // MYCLASS_H
