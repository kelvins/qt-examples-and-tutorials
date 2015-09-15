#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class Clock : public QLCDNumber
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = 0);

private slots:
    void showTime();

};

#endif // CLOCK_H
