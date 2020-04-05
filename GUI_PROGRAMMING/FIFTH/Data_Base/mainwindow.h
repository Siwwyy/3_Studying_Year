#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

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

    bool Connection_Open();

    void Connection_Close();

private slots:
    void on_Wyswietl_Czytelnicy_clicked();

    void on_Dodaj_Czytelnicy_clicked();

    void on_Usun_Czytelnicy_clicked();

    void on_MainWindow_destroyed();

    void on_Wyswietl_Ksiazki_clicked();

    void on_Dodaj_Ksiazki_clicked();

    void on_Usun_Ksiazki_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
