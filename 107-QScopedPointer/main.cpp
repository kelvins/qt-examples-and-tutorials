#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>

int *test()
{
    //int *i = new int(22);

    //qDebug() << "Value:" << *i;
    //qDebug() << "Pointer:" << i;

    QScopedPointer<int> i(new int(23));

    qDebug() << *i;
    qDebug() << i.data();

    return i.take();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //int *z = test();
    //qDebug() << *z;
    //delete z;

    //int *z = test();
    //qDebug() << *z;

    QScopedPointer<int> z(test());
    qDebug() << *z;
    qDebug() << z.data();

    return a.exec();
}
