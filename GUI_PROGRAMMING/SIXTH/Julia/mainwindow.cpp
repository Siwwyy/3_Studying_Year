#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Run()
{
    const size_t threads_size = 100;
    QThread * Threads = new QThread[threads_size];
    for(size_t i = 0; i < threads_size; ++i)
    {
        //Threads[i] = QThread::create(paintEvent());
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);


//    QPolygon poly;

//    poly << QPoint(10,10);
//    poly << QPoint(10,100);
//    poly << QPoint(100,10);
//    poly << QPoint(100,100);



    //Draw Something

    for(size_t i = 0; i < QWidget::width(); ++i)
    {
        for(size_t j = 0; j < QWidget::height(); ++j)
        {
//            int juliaValue = Julia( i,j );
//            int offset = i + j * QWidget::height();
//            QColor color(255*juliaValue,0,0,255);

            int mangelbotvalue = MangelBot( i,j );
//            int offset = i + j * QWidget::height();
            QColor color(255*mangelbotvalue,0,0,255);

            QPen linepen;
            linepen.setWidth(8);
            linepen.setColor(color);
            painter.setPen(linepen);
            painter.drawPoint(QPoint(i,j));
        }
    }

}


int MainWindow::Julia(int x, int y)
{
    const float scale = 1.5;
    float jx = scale * (float)(QWidget::width()/2 - x)/(QWidget::width()/2);
    float jy = scale * (float)(QWidget::width()/2 - y)/(QWidget::width()/2);

    Complex c(-0.8, 0.156);
    Complex a(jx, jy);

    for (size_t i=0; i<200; i++)
    {
        a = a * a + c;
        if (a.magnitude2() > 1000)
         {
            return 0;
        }
    }

    return 1;
}

int MainWindow::MangelBot(int x, int y)
{
    Complex point((float)x/QWidget::width()-1.5, (float)y/QWidget::height()-0.5);

    Complex z(0, 0);
    unsigned int nb_iter = 0;
    while (qFabs(z.r) < 2 && nb_iter <= 34)
    {
       z = z * z + point;
       nb_iter++;
    }
    if (nb_iter < 34)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
