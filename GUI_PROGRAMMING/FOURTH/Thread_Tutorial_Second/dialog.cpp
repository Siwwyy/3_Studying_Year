#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    emit on_Stop();
    delete ui;
}


void Dialog::on_Start_Button_clicked()
{
    //QT 4+ connect(obj,SIGNAL(), obj2, SLOT());

    //QT 5
    connect(&mJob,&MyJob::on_number,this,&Dialog::new_number);
    //connect(&mJob,&MyJob::erase,this,&Dialog::delete_number);
    connect(this,&Dialog::on_Stop, &mJob,&MyJob::stop);
    QFuture<void> test = QtConcurrent::run(&this->mJob,&MyJob::start,QString(""));

}

void Dialog::on_Stop_Button_clicked()
{
    emit on_Stop();
}

void Dialog::new_number(const QString &name)
{
    qDebug() << "From dialog: " << name;
    ui->Text_Area->setText(name);
}

void Dialog::delete_number(const QString &name)
{
        qDebug() << "From Del: " << name;
    ui->Text_Area->setText(name);
}
