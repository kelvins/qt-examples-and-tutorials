
#include "Enemy.h"
#include "Game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_number = rand() % 700;//(scene()->width()-100);
    setPos(random_number, 0);

    // draw
    setPixmap(QPixmap(":/images/enemy.png"));

    // connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y()+5);

    if( pos().y() > scene()->height() )
    {
        // decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
