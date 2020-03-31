#ifndef WORKER1_H
#define WORKER1_H

#include <QThread>

class Worker1 : public QThread
{
    Q_OBJECT
public:
    explicit Worker1(QString _id, int _time, QObject *parent = 0);

protected:
    void run() Q_DECL_OVERRIDE;

    QString id_;    //ID of thread
    int time_;      //sleep time for the thread

signals:

public slots:

};

#endif // WORKER1_H
