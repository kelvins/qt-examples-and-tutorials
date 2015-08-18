#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> List;

    for (int var = 0; var < 10; ++var) {
        List.append(var);
    }

    List.removeOne(5);
    List.removeLast();

    foreach (int nNumber, List) {
        qDebug() << nNumber;
    }

    return a.exec();
}
