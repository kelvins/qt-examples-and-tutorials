#ifndef MYERROR_H
#define MYERROR_H

#include <QObject>
#include <QString>

class MyError : public QObject
{
    Q_OBJECT
public:
    explicit MyError(QObject *parent = 0);
    QString getMessage();
    void setMessage(QString msg);

signals:

public slots:

protected:
    QString mMessage;

};

#endif // MYERROR_H
