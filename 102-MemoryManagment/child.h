#ifndef CHILD_H
#define CHILD_H

#include <QObject>
#include <QDebug>

class Child : public QObject
{
    Q_OBJECT
public:
    explicit Child(QObject *parent = 0);
    void doSomething();

signals:

public slots:

};

#endif // CHILD_H
