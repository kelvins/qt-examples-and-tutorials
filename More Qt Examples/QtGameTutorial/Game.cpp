#include "Game.h"
#include "Enemy.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
//#include <QMediaPlayer>
#include <QDebug>

Game::Game(QWidget *parent)
{
    // Create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0 ,0, 800, 600);
    setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    // Add a view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // Create an item to put into the scene
    player = new Player();
    player->setPos(350,500);

    // make the item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Add the item to the scene
    scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);

    // create the health
    health = new Health();
    health->setPos(health->x(), health->y()+30);
    scene->addItem(health);

    // spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // play background sound
    /*QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/background.mp3"));
    music->play();*/

    show();
}

void Game::GameOver()
{
    delete this;
}

