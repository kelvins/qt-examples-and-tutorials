#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QDebug>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = 0);

    QString Name;

    void Gossip(QString Words);

signals:
    void Speak(QString Words);

public slots:
    void Listen(QString Words);

};

#endif // PERSON_H
