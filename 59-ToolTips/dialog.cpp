#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->pushButton1->setToolTip("Hello <font color='red'><b>World</b></font>"
                                "<ul>"
                                "<li>Item 1</li>"
                                "<li>Item 2</li>"
                                "<li>Item 3</li>"
                                "</ul>");
    ui->pushButton2->setToolTip("<img src=':/files/add.png' /> Add"
                                "<br>"
                                "<img src=':/files/warning.png' /> Warning"
                                "<br>"
                                "<img src=':/files/stop.png' /> Stop");
}

Dialog::~Dialog()
{
    delete ui;
}
