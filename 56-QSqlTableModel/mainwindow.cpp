#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");// Driver
    db.setHostName("127.0.0.1");             // Host name
    db.setDatabaseName("biblioteca_kindle"); // Database name
    db.setPort(3306);                        // Port to connect
    db.setUserName("root");                  // User name
    db.setPassword("12345");                 // Password

    db.open();

    model = new QSqlTableModel();
    model->setTable("livros");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}
