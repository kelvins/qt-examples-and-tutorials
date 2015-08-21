#ifndef WATERCOOLER_H
#define WATERCOOLER_H

#include <QObject>

class WaterCooler : public QObject
{
    Q_OBJECT
public:
    explicit WaterCooler(QObject *parent = 0);

signals:

public slots:

};

#endif // WATERCOOLER_H
