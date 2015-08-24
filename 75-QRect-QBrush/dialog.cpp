#include "dialog.h"
#include "ui_dialog.h"

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

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rec(10, 10, 100, 100);

    QPen framePen(Qt::red);
    framePen.setWidth(6);

    //QBrush brush(Qt::blue, Qt::DiagCrossPattern);
    QBrush brush(Qt::blue, Qt::SolidPattern);

    painter.fillRect(rec, brush);
    painter.setPen(framePen);
    painter.drawRect(rec);
    painter.drawEllipse(rec);



}
