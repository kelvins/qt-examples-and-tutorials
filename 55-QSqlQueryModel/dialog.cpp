#include "dialog.h"
#include "ui_dialog.h"

// Tutorials 55

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");// Driver
    db.setHostName("127.0.0.1");             // Host name
    db.setDatabaseName("biblioteca_kindle"); // Database name
    db.setPort(3306);                        // Port to connect
    db.setUserName("root");                  // User name
    db.setPassword("12345");                 // Password

    db.open();

    this->model = new QSqlQueryModel();
    model->setQuery("select * from livros");

    ui->tableView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}
