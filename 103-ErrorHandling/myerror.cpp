#include "myerror.h"

MyError::MyError(QObject *parent) :
    QObject(parent)
{
}

QString MyError::getMessage()
{
    return mMessage;
}

void MyError::setMessage(QString msg)
{
    mMessage = msg;
}
