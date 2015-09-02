#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "child.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0);

signals:

public slots:

private:
    Child *mChild;

};

#endif // TEST_H
