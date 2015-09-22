#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProgressDialog>
#include <QtConcurrent>
#include <QDebug>
#include <QThread>
#include <QFutureWatcher>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    static void doTask(int &number);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
