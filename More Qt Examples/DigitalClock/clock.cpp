#include "clock.h"

Clock::Clock(QWidget *parent) :
    QLCDNumber(parent)
{
    setSegmentStyle(Filled); // Change the look of the LCD numbers

    QTimer *timer = new QTimer(this); // Calls showTime function every second
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime())); // Connect timer (timeout) to function showTime
    timer->start(1000); // Starts timer

    showTime(); // Calls showTime function for the first time

    setWindowTitle("Digital Clock"); // Set the title of the window
    resize(150, 60); // Resizes the window
}

/**
 * @brief Clock::showTime
 * Gets the current Time and puts it on a QString
 */
void Clock::showTime()
{
    QTime time = QTime::currentTime(); // Gets the current time
    QString text = time.toString("hh:mm"); // Puts the time on a QString variable

    if( (time.second() % 2) == 0 ) // Blinks the colon
        text[2] = ' ';

    display(text); // Shows the current time
}
