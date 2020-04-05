#include <QCoreApplication>
#include <QtSql>

#include <iostream>
using namespace std;

void TestSQLite();
void TestExcel();
void TestAccess();
void TestCSV();

void DBInfo(QSqlDatabase& _db);
void RecordInfo(QSqlDatabase& _db, QString _name);

void DisplayQuery(QSqlDatabase& _db, QString _q);

void displayStringList(const QStringList& _list);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(;;)
    {
        cout
        << endl << "|--------------------------------------|"
        << endl << "|    Test dostepu do baz danych        |"
        << endl << "|    Wytbierz opcje z listy ponizej:   |"
        << endl << "|--------------------------------------|"
        << endl << "|                                      |"
        << endl << "|  1. Wyjscie z programu               |"
        << endl << "|  2. Pokaz liste dostepnych driverow  |"
        << endl << "|  3. Testuj baze SQLITE               |"
        << endl << "|  4. Testuj dostep do excela (ODBC)   |"
        << endl << "|  5. Testuj dostep do Access (ODBC)   |"
        << endl << "|  6. Testuj dostep do CSV (ODBC) (???)|"
        << endl << "|--------------------------------------|"
        << endl << "|  ";

        int what;
        cin >> what;

        switch( what )
        {
            case 0:
            case 1:
                return 0;//a.exec();
            case 2:
                //wyswietlamy liste dostepnych driverow
                cout << "Nazwy dostepnych driverow:" << endl;
                displayStringList(QSqlDatabase::drivers());
                break;
            case 3:
                TestSQLite();
                break;
            case 4:
                TestExcel();
                break;
            case 5:
                TestAccess();
                break;
            case 6:
                TestCSV();
                break;
        }
    }

    return a.exec();
}

void TestSQLite()
{
    QString name;
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "bazatestowa");
        //db.setDatabaseName(":memory:");
        db.setDatabaseName("v:\\programs\\qt\\06_qtSQL\\test_baza.sqlite");
        if (!db.open())
        {
            cout << "blad";

             return ;
        }

        cout << "polaczenie zrobione!\n";

        QSqlQuery query(db);
        query.exec("create table osoba (id int primary key, "
                   "imie varchar(20), nazwisko varchar(20))");
        query.exec("insert into osoba values(101, 'Jan', 'Kowalski')");
        query.exec("insert into osoba values(102, 'Mariusz', 'Nowak')");
        query.exec("insert into osoba values(103, 'Krzysztof', 'Nowak')");
        query.exec("insert into osoba values(104, 'Robert', 'Kowalski')");
        query.exec("insert into osoba values(105, 'Marek', 'Cybulski')");
        query.exec("insert into osoba values(106, 'Wacek', 'Nowak')");


        DBInfo(db);
        RecordInfo(db, "osoba");
        //displayStringList(QSqlDatabase::connectionNames());

        name = db.connectionName();
        db.close();
        cout << "\n\n" << (const char*)name.toLatin1() << "\n\n";
    }

    QSqlDatabase::removeDatabase(name);
}

void TestExcel()
{
    QString name;
    {
        QSqlDatabase db = QSqlDatabase::addDatabase( "QODBC3" ); //podlaczamy sie do ODBC
        if ( db.isValid() )
        {
            //QTZAJECIA
            //otwieramy sterownik odbc
            db.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DBQ="
                               + QString("v:\\programs\\qt\\06_qtSQL\\Zeszyt1.xls"));

            bool op = db.open();
            cout << "dbOpen status = " << op << endl;

            if(op)
            {
                DBInfo(db);
                RecordInfo(db, "[Arkusz2$]");


            }


            db.close();
        }
        else
            cout << "Nie moge zainicjalizowac sterownika ODBC\n";
        name = db.connectionName();
    }
    //QSqlDatabase::removeDatabase("bazatestowa");
}

void TestAccess()
{
    QString name;
    {
        QSqlDatabase db = QSqlDatabase::addDatabase( "QODBC3" ); //podlaczamy sie do ODBC
        if ( db.isValid() )
        {
            //QTZAJECIA
            //otwieramy sterownik odbc
            db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ="
                               + QString("v:\\programs\\qt\\06_qtSQL\\Database.accdb"));
            bool op = db.open();
            cout << "dbOpen status = " << op << endl;

            if(op)
            {
                DBInfo(db);
                RecordInfo(db, "Tabela1");

            }
            //nie dziala - nie potrafie dodac recordow do bazu uzywajac odbc
            //QSqlQuery query;
            //query.exec("insert into [Arkusz2$] values('101', 'Jan', 'Kowalski', '123654')");
            db.close();
        }
        else
            cout << "Nie moge zainicjalizowac sterownika ODBC\n";
        name = db.connectionName();
    }
    //QSqlDatabase::removeDatabase("bazatestowa");
}


void TestCSV()
{
    QString name;
    {
        QSqlDatabase db = QSqlDatabase::addDatabase( "QODBC3" ); //podlaczamy sie do ODBC
        if ( db.isValid() )
        {
            //QTZAJECIA
            //otwieramy sterownik odbc
            db.setDatabaseName("DRIVER=Microsoft Access Text Driver (*.txt, *.csv);DBQ="
                               + QString("v:\\programs\\qt\\06_qtSQL\\;")
                               + QString("Extensions=csv;"));

            bool op = db.open();
            cout << "dbOpen status = " << op << endl;

            if(op)
            {
                DBInfo(db);
                RecordInfo(db, "test.csv");

            }
            db.close();
        }
        else
            cout << "Nie moge zainicjalizowac sterownika ODBC\n";
        name = db.connectionName();
    }
    //QSqlDatabase::removeDatabase("bazatestowa");
}


void DBInfo(QSqlDatabase& _db)
{
    cout << "databaseName = " << ((const char*)_db.databaseName().toLatin1())
            << ", driverName = " << ((const char*)_db.driverName().toLatin1()) << endl;



    if ( _db.isOpen() )
    {
        //wyswietlamy liste tabel
        displayStringList(_db.tables( QSql::Tables));
        // QStringList list = db.tables( QSql::Tables);

    }
    else
    {
        cout << "Baza danych: " << ((const char*)_db.databaseName().toLatin1()) << " jest zamknieta\n"
                << "Blad: " << ((const char*)_db.lastError().databaseText().toLatin1());

    }
}

void RecordInfo(QSqlDatabase& _db, QString _name)
{
    QSqlRecord rec = _db.record(_name);


    //
    //wyswietlamy podstawowe informacje o rekordzie
    //

    cout << "---------------------\n"
         << "  Info o rekordzie\n"
         << "---------------------\n"
         <<"Tabela " << ((const char*)_name.toLatin1()) << " zawiera " << rec.count() << " pola:\n";



    //
    // wyswietlamy liste pol w rekordzie
    //

    for (int i = 0; i < rec.count(); i++)
    {
        cout << "Pole " << i << ": " << ((const char*)rec.fieldName(i).toLatin1()) << endl;
    }


    cout << "---------------------\n";


    //
    //budujemy zapytanie SQL
    //
    DisplayQuery(_db, QString("select * from ") + _name);

    //
    //budujemy zapytanie SQL
    //
    DisplayQuery(_db, QString("select * from ") + _name + QString(" where nazwisko=\'Nowak\'"));

}

void DisplayQuery(QSqlDatabase& _db, QString _q)
{
    cout << "---------------------\n"
         << "  Zapytanie do bazy\n"
         << "---------------------\n";



    QSqlQuery query(_q, _db);

    cout << "isActive() = " << (query.isActive() ? "true" : "false") << endl
         << "isSelect() = " << (query.isSelect() ? "true" : "false") << endl
         << "size()= " << query.size() << endl
         << "numRowsAffected() = " << query.numRowsAffected() << endl
         << "executedQuery()= " << ((const char*)query.executedQuery().toLatin1()) << endl;



    cout << "---------------------\n";

    //
    // wyswietlamy zawartosc rekordu
    //


    while(query.next())
    {
        cout << "Wiersz " << query.at() << ": ";
        for(int i= 0; i < query.record().count(); i++)
        {
            cout << ((const char*)query.value(i).toString().toLatin1()) << "; ";
        }
        cout << endl;
    }

    query.finish();
}

void displayStringList(const QStringList& _list)
{
    int i =0;
    QStringList list = _list;
    cout << "Elementow na liscie: " << list.length() << endl;
    QStringList::Iterator it = list.begin();
    while( it != list.end() )
    {
        // we save the name of the first table for later
        //if (table.isEmpty()) table = *it;
        cout << "Item " << i << ":\t" << ((const char*)(*it).toLatin1()) << "\n";
        ++it;
        ++i;
    }
}
