#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("biblioteca_kindle");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("12345");

    db.open();

    model = new QSqlRelationalTableModel(this);

    model->setTable("livros");
    model->setRelation(0, QSqlRelation("valores", "id_livro", "valor"));
    model->select();

    ui->tableView->setModel(model);
}

Dialog::~Dialog()
{
    db.close();
    delete ui;
}
