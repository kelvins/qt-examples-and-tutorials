
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

extern Game *game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw graphics
    setPixmap(QPixmap(":/images/bullet.png"));

    // connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int var = 0, n = colliding_items.size(); var < n; ++var)
    {
        if( typeid(*(colliding_items[var])) == typeid(Enemy) )
        {
            // increase the score
            game->score->increase();

            // remove them from the scene
            scene()->removeItem(colliding_items[var]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[var];
            delete this;

            return;
        }
    }

    // move bullet up
    setPos(x(), y()-10);

    if( pos().y() + 40 < 0 )
    {
        scene()->removeItem(this);
        delete this;
    }
}
