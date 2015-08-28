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

    QPen pen1(Qt::black);
    pen1.setWidth(6);

    QPen pen2(Qt::red);
    pen2.setWidth(6);

    QPen pen3(Qt::green);
    pen3.setWidth(6);

    QPen pen4(Qt::blue);
    pen4.setWidth(6);

    QRect rec(100, 100, 100, 100);

    painter.setPen(pen1);
    painter.drawRect(rec);

    painter.translate(150, -60);
    painter.rotate(45);
    painter.setPen(pen2);
    painter.drawRect(rec);

    painter.setPen(pen3);
    painter.scale(0.5, 0.5);
    painter.drawRect(rec);

    painter.resetTransform();
    painter.shear(0.2, 0.2);
    painter.setPen(pen4);
    painter.drawRect(rec);

}
