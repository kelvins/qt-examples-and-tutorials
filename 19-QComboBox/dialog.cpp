#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //ui->comboBox->addItem("Hello");
    //ui->comboBox->addItem("World");

    for (int var = 1; var <= 9; ++var) {
        ui->comboBox->addItem( QString::number(var) + " item" );
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QMessageBox::information(this, "Title", ui->comboBox->currentText());
}
