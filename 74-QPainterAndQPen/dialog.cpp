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

    QPen paintPen(Qt::black);
    paintPen.setWidth(6);

    QPen linePen(Qt::red);
    linePen.setWidth(2);

    QPoint p1;
    p1.setX(10);
    p1.setY(10);

    QPoint p2;
    p2.setX(100);
    p2.setY(200);

    painter.setPen(linePen);
    painter.drawLine(p1, p2);

    painter.setPen(paintPen);
    painter.drawPoint(p1);
    painter.drawPoint(p2);

    //painter.drawLine(10, 10, 100, 100);
}
