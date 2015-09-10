#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QModelIndex>

// 1º Tutorial de Conexão com MySQL - Exemplo

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Biblioteca Kindle - Version 1.0");

    setCentralWidget(ui->tabMain);
    ui->tabMain->setTabText(0, "Livros");
    ui->tabMain->setTabText(1, "Cadastrar/Alterar");

    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setHostName("127.0.0.1");
    mDatabase.setDatabaseName("biblioteca_kindle");
    mDatabase.setPort(3306);
    mDatabase.setUserName("root");
    mDatabase.setPassword("12345");
    if (!mDatabase.open()) {
        QMessageBox::critical(this, "Erro", mDatabase.lastError().text());
        return;
    }

    mModel = new QSqlTableModel(this);
    mModel->setTable("livros");
    mModel->select();
    ui->tableView->setModel(mModel);
    ui->tableView->resizeColumnsToContents();

}

MainWindow::~MainWindow()
{
    mDatabase.close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit_2->text() != ""){
        QSqlQuery query(QString::null, mDatabase);

        if(ui->lineEdit->text() == ""){
            // Salvar
            query.prepare("insert into livros(nome, autor) values(:nome, :autor)");
            query.bindValue(":nome", ui->lineEdit_2->text());
            query.bindValue(":autor", ui->lineEdit_3->text());
        }else{
            // Alterar
            query.prepare("update livros set nome = :nome, autor = :autor where id = :id");
            query.bindValue(":id", ui->lineEdit->text());
            query.bindValue(":nome", ui->lineEdit_2->text());
            query.bindValue(":autor", ui->lineEdit_3->text());
        }

        if(query.exec()){
            QMessageBox::information(this, "Sucesso", "Salvo com sucesso!");

            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            mModel->select();
            ui->tableView->setModel(mModel);

            ui->tabMain->setCurrentIndex(0);
        }else{
            QMessageBox::warning(this, "Mensagem de erro", "Erro ao salvar registro");
        }
    }else{
        QMessageBox::information(this, "Atenção", "Por favor, preencha o campo nome!");
    }
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int rowidx = ui->tableView->selectionModel()->currentIndex().row();
    ui->lineEdit->setText(ui->tableView->model()->index(rowidx , 0).data().toString());
    ui->lineEdit_2->setText(ui->tableView->model()->index(rowidx , 1).data().toString());
    ui->lineEdit_3->setText(ui->tableView->model()->index(rowidx , 2).data().toString());
    ui->tabMain->setCurrentIndex(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() != ""){
        QSqlQuery query(QString::null, mDatabase);
        query.prepare("delete from livros where id = :id");
        query.bindValue(":id", ui->lineEdit->text());

        if(query.exec()){
            QMessageBox::information(this, "Sucesso", "Excluído com sucesso!");

            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            mModel->select();
            ui->tableView->setModel(mModel);

            ui->tabMain->setCurrentIndex(0);
        }else{
            QMessageBox::warning(this, "Mensagem de erro", "Erro ao excluir registro");
        }
    }else{
        QMessageBox::information(this, "Atenção", "Por favor, selecione um registro para excluir!");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    // Novo
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
}
