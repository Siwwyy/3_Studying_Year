#include "myjob.h"

MyJob::MyJob(QObject *parent) : QObject(parent)
{

}

void MyJob::start(const QString & name)
{
    this->mStop = false;

    for(int i =0; i < 999999; ++i)
    {
        if(mStop == true)
        {
            return;
        }
        //temp += "d";
        qDebug() << "From thread: " << i;
        Fill();
        Erase();
        emit on_number(temp);
        //emit erase(temp);
        QThread::currentThread()->msleep(100);
    }
}

void MyJob::Fill()
{
    temp += "d";
    QThread::currentThread()->msleep(100);
}

void MyJob::Erase()
{
    temp.remove(temp.size() - 1,1);
    QThread::currentThread()->msleep(400);
}

void MyJob::stop()
{
    this->mStop = true;
}
