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

void Dialog::doTask(int &number)
{
    qDebug() << "Starting" << number;

    int max = 10;
    for (int var = 0; var < max; ++var)
    {
        QThread::currentThread()->msleep(50);
        qDebug() << "Processing" << number << " - " << var << " of " << max;
    }

    qDebug() << "Stopped" << number;
}

void Dialog::on_pushButton_clicked()
{
    QVector<int> vector;
    for (int var = 0; var < ui->spinBox->value(); ++var)
    {
        vector.append(var);
    }

    QProgressDialog pdialog;
    pdialog.setLabelText("Processing");

    QFutureWatcher<void> watcher;

    connect(&pdialog, SIGNAL(canceled()), &watcher, SLOT(cancel()));
    connect(&watcher, SIGNAL(finished()), &pdialog, SLOT(reset()));
    connect(&watcher, SIGNAL(progressRangeChanged(int, int)), &pdialog, SLOT(setRange(int,int)));
    connect(&watcher, SIGNAL(progressValueChanged(int)), &pdialog, SLOT(setValue(int)));

    watcher.setFuture(QtConcurrent::map(vector, &Dialog::doTask));

    pdialog.exec();
    watcher.waitForFinished();

    if( watcher.isCanceled() )
    {
        qDebug() << "canceled!!!";
        QMessageBox::critical(this, "Canceled", "You clicked cancel!");
    }
    else
    {
        qDebug() << "finished!!!";
        QMessageBox::information(this, "Finished", "All done!");
    }
}
