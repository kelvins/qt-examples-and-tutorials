#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTextStream>

class CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(QObject *parent = 0);

signals:
    void OnReadLine(QString Line);

public slots:
    void ReadSTDIN();
    void HandleSTDIN(QString Line);
    void WriteSTDOUT(QString Line);

private:
    QThread mThread;

};

#endif // COMMANDLINE_H
