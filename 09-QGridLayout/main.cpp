#include <QtWidgets/QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

/* Example of Grid Layout */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("My App");

    QGridLayout *layout = new QGridLayout;

    QLabel *label1 = new QLabel("Name");
    QLineEdit *textName1 = new QLineEdit;

    QLabel *label2 = new QLabel("Name");
    QLineEdit *textName2 = new QLineEdit;

    layout->addWidget(label1, 0, 0);
    layout->addWidget(textName1, 0, 1);

    layout->addWidget(label2, 1, 0);
    layout->addWidget(textName2, 1, 1);

    QPushButton *button = new QPushButton("Ok");

    layout->addWidget(button, 2, 0, 1, 2); // Parameters: WIDGET, row, column, n of rows, n of columns

    window->setLayout(layout);

    window->show();
    return app.exec();
}
