#include "myjob.h"

MyJob::MyJob(QObject *parent) : QObject(parent)
{

}

void MyJob::start()
{
    this->mStop = false;

    while(mStop == false)
    {
        emit on_number();
        QThread::currentThread()->msleep(200);
    }
}

void MyJob::eraser(const int & delay)
{
    while(mStop == false)
    {
        emit erase(this->delay);
        qDebug() << "Eraser " <<this->delay;
        QThread::currentThread()->msleep(this->delay);
    }
}

void MyJob::stop()
{
    this->mStop = true;
}
