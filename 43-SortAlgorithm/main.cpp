#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> List;

    List << 2 << 3 << 1 << 9 << 0 << 6 << 8;

    qSort(List);
    //qSort(List.begin() + 1, List.end() - 1);

    foreach (int i, List)
    {
        qDebug() << i;
    }

    return a.exec();
}
