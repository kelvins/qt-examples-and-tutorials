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

    // Make our polygon
    QPolygon poly;
    poly << QPoint(10,10);
    poly << QPoint(10,100);
    poly << QPoint(100,10);
    poly << QPoint(100,100);

    // Make a pen
    QPen linePen;
    linePen.setWidth(8);
    linePen.setColor(Qt::red);
    //linePen.setJoinStyle(Qt::RoundJoin);
    linePen.setJoinStyle(Qt::MiterJoin);
    //linePen.setStyle(Qt::DotLine);

    painter.setPen(linePen);

    // Make a brush
    QBrush fillbrush;
    fillbrush.setColor(Qt::green);
    fillbrush.setStyle(Qt::SolidPattern);

    // Fill the polygon
    QPainterPath path;
    path.addPolygon(poly);

    painter.fillPath(path, fillbrush);

    // Draw the polygon
    painter.drawPolygon(poly);

}
