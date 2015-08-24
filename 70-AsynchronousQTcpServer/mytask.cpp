#include "mytask.h"

MyTask::MyTask()
{
}

void MyTask::run()
{
    // Time consumer

    qDebug() << "Task Start";

    int iNumber = 0;
    for (int var = 0; var < 100; ++var)
    {
        iNumber += var;
    }

    qDebug() << "Task done";

    emit Result(iNumber);
}
