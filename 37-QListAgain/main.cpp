#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> List;

    for (int var = 1; var <= 20; ++var)
    {
        List.append(var);
    }

    /*QListIterator<int> Iter(List);

    while(Iter.hasNext())
    {
        qDebug() << Iter.next();
    }

    Iter.toBack();
    while(Iter.hasPrevious())
    {
        qDebug() << Iter.previous();
        if( Iter.hasPrevious() )
        {
            qDebug() << "next..." << Iter.peekPrevious();
        }
    }*/

    QMutableListIterator<int> Iter(List);

    while (Iter.hasNext())
    {
        int i = Iter.next();
        if( i == 5 )
        {
            Iter.remove();
        }
    }

    Iter.toFront();

    while (Iter.hasNext()) {
        qDebug() << Iter.next();
    }

    return a.exec();
}
