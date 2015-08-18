#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    // Info
    QMessageBox::information(this, "Title Here",
                             "Some information");
}

void Dialog::on_pushButton_2_clicked()
{
    // Question
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Title Here",
                                    "Do you like cats?",
                                    QMessageBox::Yes | QMessageBox::No);

    if( reply == QMessageBox::Yes ){
        QMessageBox::information(this, "Title Here",
                                 "You love cats!");
    }else{
        QMessageBox::information(this, "Title Here",
                                 "You don't like cats!");
    }
}

void Dialog::on_pushButton_3_clicked()
{
    // Warning
    QMessageBox::warning(this, "Title Here",
                         "Warning information");
}

void Dialog::on_pushButton_4_clicked()
{
    // Custom
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Title Here",
                                  "My text here",
                                  QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoToAll);
    if( reply == QMessageBox::YesToAll ){
        QMessageBox::warning(this, "Title Here",
                             "Be careful");
    }
}
