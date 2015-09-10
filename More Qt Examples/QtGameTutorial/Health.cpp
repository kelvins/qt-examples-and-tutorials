
#include "Health.h"
#include "Game.h"
#include <QFont>

extern Game *game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the Health to 3
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 22));
}

void Health::decrease()
{
    health--;
    checkHealth();
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}

void Health::checkHealth()
{
    if( getHealth() <= 0 )
    {
        game->GameOver();
    }
}
