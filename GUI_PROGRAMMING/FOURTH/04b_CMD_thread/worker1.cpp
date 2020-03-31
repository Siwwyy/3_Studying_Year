#include "worker1.h"
#include <iostream>
using namespace std;

QMutex Worker1::mutex_;

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
//        QMutex m;
//        m.lock();
//        cout << "thread: " << id_.toStdString().c_str() << " is working" << endl;
//        m.unlock();

        //{
//            QMutexLocker locker(&mutex_);
//            cout << "thread: " << id_.toStdString().c_str() << " is working" << endl;
        //}

        mutex_.lock();
        cout << "thread: " << id_.toStdString().c_str() << " is working" << endl;
        mutex_.unlock();

        //deadlock
//        mutex_.lock();
//        mutex_.lock();
//        cout << "thread: " << id_.toStdString().c_str() << " is working" << endl;
//        mutex_.unlock();
//        mutex_.unlock();


        msleep(time_);
    }
}
