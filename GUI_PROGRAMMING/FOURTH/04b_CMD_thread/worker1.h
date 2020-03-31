////////////////////////////////////////////////////////////////////////////////////
///
/// In this example Mutex is used to synchronize two threads
/// now, text dsplayed on the console is ok because writting to cmd
/// is protected by QMutex
///
///

#ifndef WORKER1_H
#define WORKER1_H

#include <QThread>
#include <QMutex>

class Worker1 : public QThread
{
    Q_OBJECT
public:
    explicit Worker1(QString _id, int _time, QObject *parent = 0);

protected:
    void run() Q_DECL_OVERRIDE;

    QString id_;    //ID of thread
    int time_;      //sleep time for the thread

    static QMutex mutex_;   //we will synchronize threads using mutex
signals:

public slots:

};

#endif // WORKER1_H
