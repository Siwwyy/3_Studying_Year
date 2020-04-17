#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QtMath>
#include <complex>

QT_BEGIN_NAMESPACE

namespace Ui
{

class MainWindow;

}

QT_END_NAMESPACE

struct Complex
{
    float   r;
    float   i;

    Complex( float a, float b )
        : r(a), i(b)
    {

    }

    float magnitude2( void )
    {
        return r * r + i * i;
    }

    Complex operator*(const Complex& a)
    {
        return Complex(r*a.r - i*a.i, i*a.r + r*a.i);
    }

    Complex operator+(const Complex& a)
    {
        return Complex(r+a.r, i+a.i);
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    void paintEvent(QPaintEvent * e);
    int Julia(int x, int y);
    int MangelBot(int x, int y);
};
#endif // MAINWINDOW_H
