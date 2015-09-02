#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Use the string list
    QStringList CompletionList;
    CompletionList << "Bryan" << "Bart" << "Bread" << "Kelvin" << "Beth" << "Brad" << "Kelly";
    StringCompleter = new QCompleter(CompletionList, this);
    StringCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(StringCompleter);

    // Use a Model
    ModelCompleter = new QCompleter(this);
    ModelCompleter->setModel(new QDirModel(ModelCompleter));
    ui->lineEdit_2->setCompleter(ModelCompleter);
}

Dialog::~Dialog()
{
    delete ui;
}
