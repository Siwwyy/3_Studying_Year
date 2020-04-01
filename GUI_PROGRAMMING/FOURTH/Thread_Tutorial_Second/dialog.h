#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtConcurrent>
#include "myjob.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class Dialog;
}

QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void on_Stop();

private slots:
    void on_Start_Button_clicked();
    void on_Stop_Button_clicked();

    void on_Ustaw_Ms_clicked();

public slots:
    void new_number();
    void delete_number();

private:
    Ui::Dialog *ui;
    MyJob mJob;
};
#endif // DIALOG_H
