#ifndef MYJOB_H
#define MYJOB_H

#include <QObject>
#include <QDebug>
#include <QThread>

class MyJob : public QObject
{
    Q_OBJECT
public:
    explicit MyJob(QObject *parent = nullptr);
    QString str;
    int delay = 500;
    void start();
    void eraser(const int & delay);

signals:

    void on_number();
    void erase(const int & delay);

public slots:
   void stop();

private:
    bool mStop;

};

#endif // MYJOB_H
