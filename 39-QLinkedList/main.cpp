#include <QCoreApplication>
#include <QDebug>
#include <QLinkedList>

/*
 * List is very fast reading the list, but slow to insert and delete
 * LinkedList is very fast to insert and delete objects because it uses pointers
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<int> List;

    List << 1 << 3 << 5 << 6;
    List.append(8);

    foreach (int i, List)
    {
        qDebug() << i;
    }

    return a.exec();
}
