#include "dialog.h"
#include "ui_dialog.h"
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for (int var = 1; var <= 9; ++var) {
        ui->listWidget->addItem(QString::number(var) + " Item");
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QListWidgetItem *itm = ui->listWidget->currentItem();
    itm->setText("Fuzzy Bunny of doom");
    itm->setTextColor(Qt::red);
    itm->setBackgroundColor(Qt::yellow);
}
