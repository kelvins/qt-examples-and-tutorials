#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView
{

public:
    Game(QWidget *parent=0);
    void GameOver();

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;

};

#endif // GAME_H
