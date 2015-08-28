#include <QCoreApplication>
#include <QtCore>
#include <QFile>
#include <QString>
#include <QMap>
#include <QDebug>

void Save()
{
    int MyNum = 22;
    QMap<qint64, QString> map;
    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    // save to disk
    QFile file("/home/kelvin/myfile.txt");

    if( !file.open(QIODevice::WriteOnly) )
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_7);

    out << MyNum << map;

    file.flush();
    file.close();
}

void Load()
{
    int MyNum = 22;
    QMap<qint64, QString> map;

    // load it from disk
    QFile file("/home/kelvin/myfile.txt");

    if( !file.open(QIODevice::ReadOnly) )
    {
        qDebug() << "Could not open file.";
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_7);

    //out << MyNum << map;
    in >> MyNum >> map;

    file.close();

    qDebug() << "MyNum = " << MyNum;

    foreach (QString item, map.values())
    {
        qDebug() << item;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Save();
    Load();

    return a.exec();
}
