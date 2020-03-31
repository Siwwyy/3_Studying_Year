#include "worker1.h"
#include <iostream>
using namespace std;

Worker1::Worker1(QString _id, int _time, QObject *parent) :
    QThread(parent)
  , id_(_id)
  , time_(_time)
{
}

void Worker1::run()
{
    while(!isInterruptionRequested())
    {
        cout << "thread: " << id_.toStdString().c_str() << " is working" << endl;
        msleep(time_);
    }
}
