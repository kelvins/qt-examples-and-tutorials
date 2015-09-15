#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QDebug>

class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;
};

#endif // ANALOGCLOCK_H
