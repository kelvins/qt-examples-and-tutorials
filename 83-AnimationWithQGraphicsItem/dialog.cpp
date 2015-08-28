#include "dialog.h"
#include "ui_dialog.h"
#include "myitem.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200, -200, 300, 300);

    QPen myPen = QPen(Qt::red);

    QLineF TopLine( scene->sceneRect().topLeft(), scene->sceneRect().topRight() );
    QLineF LeftLine( scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft() );
    QLineF RightLine( scene->sceneRect().topRight(), scene->sceneRect().bottomRight() );
    QLineF BottomLine( scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight() );

    scene->addLine(TopLine, myPen);
    scene->addLine(LeftLine, myPen);
    scene->addLine(RightLine, myPen);
    scene->addLine(BottomLine, myPen);

    int itemCount = 25;
    for (int var = 0; var < itemCount; ++var)
    {
        MyItem *item = new MyItem();
        scene->addItem(item);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(100);

}

Dialog::~Dialog()
{
    delete ui;
}
