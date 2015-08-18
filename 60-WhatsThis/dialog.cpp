#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    LinkFilter *filter = new LinkFilter(this);
    this->installEventFilter(filter);

    connect(filter, SIGNAL(linkClicked(QString)), this, SLOT(showLink(QString)));

    ui->pushButton->setWhatsThis("For more information <a href='www.google.com'>Click here</a>");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showLink(const QString &Link)
{
    QMessageBox::information(this, "Link Clicked", Link);
}
