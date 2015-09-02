#include "commandline.h"

CommandLine::CommandLine(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&mThread); // Move the object of this class to a thread

    connect(&mThread, SIGNAL(started()), this, SLOT(ReadSTDIN()));
    connect(this, SIGNAL(OnReadLine(QString)), this, SLOT(HandleSTDIN(QString)));

    mThread.start();
}

// This is like a loop (thread)
void CommandLine::ReadSTDIN()
{
    QTextStream stream(stdin);
    QString line = stream.readLine();
    emit OnReadLine(line);
    ReadSTDIN();
}

void CommandLine::HandleSTDIN(QString Line)
{
    //qDebug() << Line;
    WriteSTDOUT("You enterede: " + Line);
}

void CommandLine::WriteSTDOUT(QString Line)
{
    QTextStream stream(stdout);
    stream << Line;
}
