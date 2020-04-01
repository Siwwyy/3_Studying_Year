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

    void start(const QString &name);

    void Fill();
    void Erase();

signals:

    void on_number(const QString &name);
    void erase(const QString &name);

public slots:
   void stop();

private:
    bool mStop;
    QString temp;
};

#endif // MYJOB_H
