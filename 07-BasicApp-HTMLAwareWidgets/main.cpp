#include <QtWidgets/QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("<h2>Hello <font color=red><i>World</i></font></h2>");

    label->show();

    return app.exec();
}
