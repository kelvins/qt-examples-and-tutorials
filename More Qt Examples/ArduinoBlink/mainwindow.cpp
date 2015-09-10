#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>

QT_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lightOn = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_turnON_OFF_clicked()
{
    if( lightOn == false )
    {
        sendData('1');
        lightOn = true;
        ui->turnON_OFF->setIcon(QIcon(":/imgs/lamp-on.png"));
    }
    else
    {
        sendData('1');
        lightOn = false;
        ui->turnON_OFF->setIcon(QIcon(":/imgs/lamp-off.png"));
    }
}

void MainWindow::sendData(char data)
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {

        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            serial.write(&data);
            serial.flush();
            serial.close();
        }

    }
}

/*
// Arduino code
int led = 13;

void setup(){
    Serial.begin(9600);
    pinMode(led, OUTPUT);
}

void loop(){

    if(Serial.available()){

        int entrada = Serial.parseInt();
        Serial.println(entrada);

        if( entrada == 2 ){
            digitalWrite(led, HIGH);
            delay(500);
        }else if( entrada == 1 ){
            digitalWrite(led, LOW);
            delay(500);
        }

    }
}

*/
