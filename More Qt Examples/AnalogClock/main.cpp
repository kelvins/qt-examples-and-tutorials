#include <QApplication>
#include "analogclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AnalogClock clock;
    clock.show();

    return a.exec();
}
