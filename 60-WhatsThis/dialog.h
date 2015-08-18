#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "linkfilter.h"
#include <QtCore>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

public slots:
    void showLink(const QString &Link);

};

#endif // DIALOG_H
