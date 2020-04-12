#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      czytelnicy_id(-1),
      ksiazki_id(-1)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 500));
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("E:/!!PROJECTS_VS/!!3_Studying_Year/GUI_PROGRAMMING/FIFTH/Data_Base/DB.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::Connection_Open()
{
    if(this->db.open() == false)
    {
        //qDebug() << "Failed to open the database\n";
        return false;
    }
    else
    {
        //qDebug() << "Connected to the database\n";
        return true;
    }
}

void MainWindow::Connection_Close()
{
    this->db.close();
}

void MainWindow::on_Wyswietl_Czytelnicy_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(Connection_Open() == true)
    {
        QSqlQuery * query = new QSqlQuery(this->db);

        query->prepare("SELECT * FROM Czytelnicy WHERE Czytelnicy.Imie != '""' AND Czytelnicy.Nazwisko != '""' ");

        query->exec();
        model->setQuery(*query);

        ui->Lista_Czytelnikow->setModel(model);
        //ui->

        //qDebug() << (model->rowCount());

        Connection_Close();
    }
}

void MainWindow::on_Dodaj_Czytelnicy_clicked()
{
    //INSERT INTO Czytelnicy (Imie,Nazwisko,id_Ksiazki) VALUES ("Damian", "Andrysiak",NULL)
    QString name = ui->Imie_Czytelnicy->text();
    QString surname = ui->Nazwisko_Czytelnicy->text();

    if(name != "" && surname != "")
    {
        if(Connection_Open() == true)
        {
            QSqlQuery * query = new QSqlQuery(this->db);

            query->prepare("INSERT INTO Czytelnicy (Imie,Nazwisko,id_Ksiazki) VALUES ('"+name+"', '"+surname+"',NULL)");

            if(query->exec() == true)
            {
                //qDebug() << ("Inserted to DB");
                QMessageBox::information(this,tr("Information"), tr("Successed insertion to DB"),QMessageBox::Ok);
            }
            else
            {
                //qDebug() << ("Error");
                QMessageBox::information(this,tr("Information"), tr("Failed insertion to DB"),QMessageBox::Ok);
            }

            Connection_Close();
            on_Wyswietl_Czytelnicy_clicked();
        }
    }
}

void MainWindow::on_Usun_Czytelnicy_clicked()
{
    //DELETE FROM Czytelnicy WHERE Czytelnicy.Imie = "" AND Czytelnicy.Nazwisko = ""
    QString name = ui->Imie_Czytelnicy->text();
    QString surname = ui->Nazwisko_Czytelnicy->text();

    if(name != "" && surname != "")
    {
        if(Connection_Open() == true)
        {
            QSqlQuery * query = new QSqlQuery(this->db);

            query->prepare("DELETE FROM Czytelnicy WHERE Imie ='"+name+"' AND Nazwisko = '"+surname+"'");

            if(query->exec() == true)
            {
                //qDebug() << ("Inserted to DB");
                QMessageBox::information(this,tr("Information"), tr("User: "+ name.toLatin1() +" "+ surname.toLatin1() +" has been deleted"),QMessageBox::Ok);
            }
            else
            {
                //qDebug() << ("Error");
                QMessageBox::information(this,tr("Information"), tr("User: "+ name.toLatin1() +" "+ surname.toLatin1() +" has been deleted"),QMessageBox::Ok);
            }

            Connection_Close();
            on_Wyswietl_Czytelnicy_clicked();
        }
    }
}

void MainWindow::on_MainWindow_destroyed()
{
    Connection_Close();
}

void MainWindow::on_Wyswietl_Ksiazki_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(Connection_Open() == true)
    {
        QSqlQuery * query = new QSqlQuery(this->db);

        query->prepare("SELECT * FROM Ksiazki");

        query->exec();
        model->setQuery(*query);

        ui->Lista_Ksiazek->setModel(model);

       //qDebug() << (model->rowCount());

        Connection_Close();
    }
}

void MainWindow::on_Dodaj_Ksiazki_clicked()
{
    //INSERT INTO Ksiazki (Tytul,Autor_Imie,Autor_Nazwisko) VALUES ("Test","Test","Test")
    QString title = ui->Tytul_Ksiazki->text();
    QString name = ui->Imie_Ksiazki->text();
    QString surname = ui->Nazwisko_Ksiazki->text();

    if(title != "" && name != ""  && surname != "")
    {
        if(Connection_Open() == true)
        {
            QSqlQuery * query = new QSqlQuery(this->db);

            query->prepare("INSERT INTO Ksiazki (Tytul,Autor_Imie,Autor_Nazwisko) VALUES ('"+title+"','"+name+"','"+surname+"')");

            if(query->exec() == true)
            {
                //qDebug() << ("Inserted to DB");
                QMessageBox::information(this,tr("Information"), tr("Successed insertion to DB"),QMessageBox::Ok);
            }
            else
            {
                //qDebug() << ("Error");
                QMessageBox::information(this,tr("Information"), tr("Failed insertion to DB"),QMessageBox::Ok);
            }

            Connection_Close();
            on_Wyswietl_Ksiazki_clicked();
        }
    }
}

void MainWindow::on_Usun_Ksiazki_clicked()
{
    QString title = ui->Tytul_Ksiazki->text();

    if(title != "")
    {
        if(Connection_Open() == true)
        {
            QSqlQuery * query = new QSqlQuery(this->db);

            query->prepare("DELETE FROM Ksiazki WHERE Tytul = '"+title+"' ");

            if(query->exec() == true)
            {
                //qDebug() << ("Inserted to DB");
                QMessageBox::information(this,tr("Information"), tr("Book: "+ title.toLatin1() +" has been deleted"),QMessageBox::Ok);
            }
            else
            {
                //qDebug() << ("Error");
                QMessageBox::information(this,tr("Information"), tr("Book: "+ title.toLatin1() +" has been deleted"),QMessageBox::Ok);
            }

            Connection_Close();
            on_Wyswietl_Ksiazki_clicked();
        }
    }
}

void MainWindow::on_Wyswietl_Czytelnicy_Wypozycz_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(Connection_Open() == true)
    {
        QSqlQuery * query = new QSqlQuery(this->db);

        query->prepare("SELECT * FROM Czytelnicy WHERE Czytelnicy.Imie != '""' AND Czytelnicy.Nazwisko != '""' ");

        query->exec();
        model->setQuery(*query);

        ui->Lista_Wypozycz_Czytelnicy->setModel(model);

        //qDebug() << (model->rowCount());

        Connection_Close();
    }
}

void MainWindow::on_Wyswietl_Ksiazki_Wypozycz_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(Connection_Open() == true)
    {
        QSqlQuery * query = new QSqlQuery(this->db);

        query->prepare("SELECT * FROM Ksiazki");

        query->exec();
        model->setQuery(*query);

        ui->Lista_Wypozycz_Ksiazki->setModel(model);

        //qDebug() << (model->rowCount());

        Connection_Close();
    }
}

void MainWindow::on_Wypozycz_Ksiazke_clicked()
{
    //UPDATE Czytelnicy SET id_Ksiazki = 1 WHERE id_Czytelnicy = 13

    if(this->czytelnicy_id != -1 && this->ksiazki_id != -1)
    {
        if(Connection_Open() == true)
        {
            QSqlQueryModel * model = new QSqlQueryModel();
            //UPDATE Czytelnicy SET id_Ksiazki = 1 WHERE id_Czytelnicy = 14 and id_Ksiazki != (SELECT id_Ksiazki FROM Czytelnicy)
            QSqlQuery * query = new QSqlQuery(this->db);
//= (SELECT id_Ksiazki FROM Czytelnicy)
            //split this update to select first and then update if id_ksiazka isnt exist in table
            //UPDATE Czytelnicy SET id_Ksiazki = 1 WHERE id_Czytelnicy = 3 and id_Ksiazki != (SELECT id_Ksiazki FROM Czytelnicy)
            query->prepare("SELECT id_Ksiazki FROM Czytelnicy WHERE id_Ksiazki = '"+QString::number(ksiazki_id).toLatin1()+"' ");
            query->exec();
            model->setQuery(*query);
            qDebug() << (model->rowCount());
            if(model->rowCount() == 0)
            {
                query->prepare("UPDATE Czytelnicy SET id_Ksiazki = '"+QString::number(ksiazki_id).toLatin1()+"' WHERE id_Czytelnicy = '"+QString::number(czytelnicy_id).toLatin1()+"' ");
                QMessageBox::information(this,tr("Information"), tr("Book has been borrowed"), QMessageBox::Ok);
                Connection_Close();
                on_Wyswietl_Czytelnicy_Wypozycz_clicked();
                on_Wyswietl_Ksiazki_Wypozycz_clicked();
            }
            else
            {
                QMessageBox::information(this,tr("Information"), tr("Book isnt available to borrow"), QMessageBox::Ok);
            }
        }
    }
    else
    {
        QMessageBox::information(this,tr("Information"), tr("Click on both tables"),QMessageBox::Ok);
    }
    this->czytelnicy_id = -1;
    this->ksiazki_id = -1;
}

void MainWindow::on_Lista_Wypozycz_Czytelnicy_clicked(const QModelIndex &index)
{
    //ui->temp1->setText(QString::number(index.row()));
    //ui->Lista_Wypozycz_Ksiazki->selectRow(index.row());
    //ui->temp1->setText(QString::number();
    //ui->temp1->setText(ui->Lista_Wypozycz_Czytelnicy->model()->index(index.row(),0).data().toString());
    this->czytelnicy_id = ui->Lista_Wypozycz_Czytelnicy->model()->index(index.row(),0).data().toInt();
}

void MainWindow::on_Lista_Wypozycz_Ksiazki_clicked(const QModelIndex &index)
{
    //ui->temp2->setText(ui->Lista_Wypozycz_Ksiazki->model()->index(index.row(),0).data().toString());
    this->ksiazki_id = ui->Lista_Wypozycz_Ksiazki->model()->index(index.row(),0).data().toInt();
}

void MainWindow::on_Oddaj_Ksiazke_clicked()
{
    if(this->czytelnicy_id != -1)
    {
        if(Connection_Open() == true)
        {
            QSqlQuery * query = new QSqlQuery(this->db);

            query->prepare("UPDATE Czytelnicy SET id_Ksiazki = NULL WHERE id_Czytelnicy = '"+QString::number(czytelnicy_id).toLatin1()+"' and id_Ksiazki IS NOT NULL ");

            if(query->exec() == false)
            {
                   QMessageBox::information(this,tr("Information"), tr("Book hasn't be returned"),QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,tr("Information"), tr("Book has been returned"),QMessageBox::Ok);
            }
            Connection_Close();
            on_Wyswietl_Czytelnicy_Wypozycz_clicked();
            on_Wyswietl_Ksiazki_Wypozycz_clicked();
        }
    }
    else
    {
        QMessageBox::information(this,tr("Information"), tr("Click on both tables"),QMessageBox::Ok);
    }
    this->czytelnicy_id = -1;
    this->ksiazki_id = -1;
}
