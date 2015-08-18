#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QString>

/*
 * Sample database use.
 *
 * Tutorials:
 * 51: Intro, connection
 * 52: Basic SQL Query
 * 53: SQL Query Prepare and BindValue
 *
 * Remember to add "QT += sql" on ".pro" file
 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1");             // Host name
    db.setDatabaseName("biblioteca_kindle"); // Database name
    db.setPort(3306);                        // Port to connect
    db.setUserName("root");                  // User name
    db.setPassword("12345");                 // Password

    if( db.open() ) // Open connection
    {
        qDebug() << "Opened!";

        QString sQuery = "insert into livros(nome, autor) values(:nome, :autor)";

        QSqlQuery qry;

        qry.prepare(sQuery);
        qry.bindValue(":nome", "Testando insercao de livro");
        qry.bindValue(":autor", "Eu mesmo");

        if( qry.exec() )
        {
            qDebug() << "Record inserted!";
        }
        else
        {
            qDebug() << "Error: " << db.lastError().text();
        }


        if( qry.exec("select * from livros") )
        {
            while( qry.next() )
            {
                qDebug() << qry.value(1).toString();
            }
        }
        else
        {
            qDebug() << "Error: " << db.lastError().text();
        }

        qDebug() << "Closing...";
        db.close(); // close connection
    }
    else
    {
        qDebug() << "Error: " << db.lastError().text();
    }



    return a.exec();
}
