#include <QCoreApplication>
#include <QThread>
#include "worker1.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    cout << "idealThreadCount: " << QThread::idealThreadCount() << endl;

    Worker1 a("A", 500), b("B", 410), c("C", 520);

    a.start();
    b.start();
    c.start();

    return app.exec();
}
