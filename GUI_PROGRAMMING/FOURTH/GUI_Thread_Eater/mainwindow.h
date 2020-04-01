#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
//#include <QThread>
#include <string>
#include <thread>
#include <algorithm>
#include <functional>
#include <chrono>
#include <mutex>

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //VARIABLES
    Ui::MainWindow *ui;
    std::string _str;

//    std::thread * Print_Thread;
//    std::thread * Filler_Threads;
   size_t Filler_Threads_size;
//    std::thread * Eater_Thread;
    //////////////////////////

    //FUNCTIONS
    void Start();
    void Stop();
    void Print_TextBox();
    void Fill_TextBox();
    void Eat_TextBox();
    //////////////////////////
private slots:
    void Change_Delay();
};
#endif // MAINWINDOW_H
