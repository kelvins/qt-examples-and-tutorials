#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QMetaEnum>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
    Q_ENUMS(Tests)

public:
    explicit Test(QObject *parent = 0);

    enum Tests
    {
        TEST1,
        TEST2,
        TEST3
    };

signals:

public slots:
    void doTest(QString Command);

};

#endif // TEST_H
