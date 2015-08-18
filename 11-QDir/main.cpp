#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // True if mDir1 exists and False if not
    //QDir mDir1("/home/kelvin/Github");
    //qDebug() << mDir1.exists();

    /*QDir mDir;
    foreach(QFileInfo mItm, mDir.drives())
    {
        qDebug() << mItm.absoluteFilePath();
    }*/

    // Create a directory
    /*QDir mDir;
    QString mPath = "/home/kelvin/ZZZZZZ";
    if(!mDir.exists(mPath))
    {
        mDir.mkpath(mPath);
        qDebug() << "Created";
    }
    else
    {
        qDebug() << "Already exists";
    }*/

    QDir mDir("/home/kelvin");

    foreach (QFileInfo mItm, mDir.entryInfoList())
    {
        if(mItm.isDir())
            qDebug() << "Dir:" << mItm.absoluteFilePath();;
        if(mItm.isFile())
            qDebug() << "File:" << mItm.absoluteFilePath();;
    }

    return a.exec();
}
