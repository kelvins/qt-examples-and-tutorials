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
    QPen pen(Qt::black);
    pen.setWidth(15);

    QPoint startPoint(20, 30);
    QPoint endPoint(200, 30);

    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    painter.drawLine(startPoint, endPoint);

    startPoint.setY(50);
    endPoint.setY(50);

    pen.setCapStyle(Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(startPoint, endPoint);

    startPoint.setY(70);
    endPoint.setY(70);

    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.drawLine(startPoint, endPoint);
}
