#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    if( ui->checkBox->isChecked() )
        QMessageBox::information(this, "Title", "You like cats");
    else
        QMessageBox::information(this, "Title", "You don't like cats");
}
