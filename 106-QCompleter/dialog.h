#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCompleter>
#include <QDirModel>

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
    QCompleter *StringCompleter;
    QCompleter *ModelCompleter;
};

#endif // DIALOG_H
