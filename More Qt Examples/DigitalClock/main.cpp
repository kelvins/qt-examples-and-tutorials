#include <QApplication>
#include "clock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Clock c; // Creates a new instance of the clock class
    c.show(); // Calls the show function (from QWidgets classes)

    return a.exec();
}
