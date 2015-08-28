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

    painter.drawText(100, 100, "Hello World");

    QRect rec(100, 120, 250, 25);
    painter.drawRect(rec);
    painter.drawText(rec, Qt::AlignLeft, "Left");
    painter.drawText(rec, Qt::AlignCenter, "Center");
    painter.drawText(rec, Qt::AlignRight | Qt::AlignVCenter, "Right");

    QRect rec2(100, 150, 25, 25);
    painter.drawRect(rec2);
    painter.drawText(rec2, "This will be clipped");

    QTextDocument doc;
    QRect rec3(0, 0, 250, 250);
    painter.translate(20, 20);
    doc.setTextWidth(rec3.width());
    doc.setHtml("<b><u>Hello</u></b> <br><br> <font face='Arial' color='red' size='6'><i>World</i></font>");
    doc.drawContents(&painter, rec3);
}
