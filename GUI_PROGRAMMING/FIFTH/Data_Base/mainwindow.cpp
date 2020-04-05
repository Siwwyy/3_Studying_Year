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

bool MainWindow::Connection_Open()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("E:/!!PROJECTS_VS/!!3_Studying_Year/GUI_PROGRAMMING/FIFTH/Data_Base/DB.db");

    if(this->db.open() == false)
    {
        qDebug() << "Failed to open the database\n";
        return false;
    }
    else
    {
        qDebug() << "Connected to the database\n";
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

        ui->tableView->setModel(model);

        qDebug() << (model->rowCount());

        Connection_Close();
    }
}

void MainWindow::on_Dodaj_Czytelnicy_clicked()
{
    //INSERT INTO Czytelnicy (Imie,Nazwisko,id_Ksiazki) VALUES ("Damian", "Andrysiak",NULL)
    QString name = ui->Imie_Czytelnicy->text();
    QString surname = ui->Nazwisko_Czytelnicy->text();

    if(Connection_Open() == true)
    {
        QSqlQuery * query = new QSqlQuery(this->db);

        query->prepare("INSERT INTO Czytelnicy (Imie,Nazwisko,id_Ksiazki) VALUES ('"+name+"', '"+surname+"',NULL)");

        if(query->exec() == true)
        {
            qDebug() << ("Inserted to DB");
        }
        else
        {
            qDebug() << ("Error");
        }

        Connection_Close();
        on_Wyswietl_Czytelnicy_clicked();
    }
}
