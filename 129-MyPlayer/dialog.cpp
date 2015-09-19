#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChange);
    connect(player, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChange);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_slideProgress_sliderMoved(int position)
{
    // progress
    player->setPosition(position);
}

void Dialog::on_sliderVolume_sliderMoved(int position)
{
    // volume
    player->setVolume(position);
}

void Dialog::on_pushButton_clicked()
{
    // start
    // Load the file
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\Kelvin\\Downloads\\I_Wanna_Be_Sedated_-_The_Ramones.mp3"));
    player->play();
    qDebug() << player->errorString();
}

void Dialog::on_pushButton_2_clicked()
{
    // stop
    player->stop();
}

void Dialog::on_positionChange(qint64 position)
{
    ui->slideProgress->setValue(position);
}

void Dialog::on_durationChange(qint64 position)
{
    ui->slideProgress->setMaximum(position);
}
