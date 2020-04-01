#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      _str(""),
      Filler_Threads_size(4)
{
    ui->setupUi(this);

    //Start();
    // Connect signals and slots for math buttons
    connect(ui->Change_Delay, SIGNAL(released()), this, SLOT(Change_Delay()));
   // Filler_Threads = new std::thread(&MainWindow::Fill_TextBox);
//    Filler_Threads = new std::thread[this->Filler_Threads_size];
//    for(size_t i = 0; i < this->Filler_Threads_size; ++i)
//    {
//        Filler_Threads[i] = new std::thread(&MainWindow::Fill_TextBox);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Start()
{
    while(true)
    {

    }
}

void MainWindow::Print_TextBox()
{

}

void MainWindow::Fill_TextBox()
{

}

void MainWindow::Eat_TextBox()
{

}

void MainWindow::Change_Delay()
{

}
