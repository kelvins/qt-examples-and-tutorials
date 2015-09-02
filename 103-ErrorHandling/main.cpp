#include <QCoreApplication>
#include <QDebug>
#include <QString>

#include "myerror.h"

void test()
{
    qDebug() << "Starting...";

    try
    {
        MyError *cErr = new MyError();
        cErr->setMessage("lol");
        throw cErr;

        throw QString("The cat ate my homework!");
    }
    catch(char* cerr)
    {
        qDebug() << cerr;
    }
    catch(QString sErr)
    {
        qDebug() << "QSTRING = " << sErr;
    }
    catch(MyError *cErrMsg)
    {
        qDebug() << "MyError = " << cErrMsg->getMessage();
    }
    catch(...)
    {
        qDebug() << "Unknown Error has occured.";
    }

    qDebug() << "Glad that's over with";

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();

    return a.exec();
}
