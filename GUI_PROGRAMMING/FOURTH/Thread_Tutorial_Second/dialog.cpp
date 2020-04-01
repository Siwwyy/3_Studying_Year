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
    connect(&mJob,&MyJob::erase,this,&Dialog::delete_number);
    //connect(&mJob,&MyJob::erase,this,&Dialog::delete_number);
    connect(this,&Dialog::on_Stop, &mJob,&MyJob::stop);
    QFuture<void> test = QtConcurrent::run(&this->mJob,&MyJob::start);
    QFuture<void> test1 = QtConcurrent::run(&this->mJob,&MyJob::eraser, mJob.delay);
}

void Dialog::on_Stop_Button_clicked()
{
    emit on_Stop();
}

void Dialog::new_number()
{
    //qDebug() << "From dialog: " << name;

    mJob.str.push_back("d");
    ui->Text_Area->setText(mJob.str);
    //QThread::currentThread()->msleep(300);
}

void Dialog::delete_number()
{
      //  qDebug() << "From Del: " << name;

//    mJob.str.remove((mJob.str.size() - 1),1);
    //QString temp  = mJob.str.left(mJob.str.size() - 1);
    mJob.str.remove(mJob.str.size() - 1,2);
   // mJob.str = temp;
    ui->Text_Area->setText(mJob.str);
    //QThread::currentThread()->msleep(ui->Ms->text().toUInt());
}

void Dialog::on_Ustaw_Ms_clicked()
{
    on_Stop_Button_clicked();
    mJob.delay = ui->Ms->text().toUInt();
    qDebug() << "From Dialog: " << mJob.delay;
    on_Start_Button_clicked();
}
