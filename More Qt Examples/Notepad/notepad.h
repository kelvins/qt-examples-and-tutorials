#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QAction>
#include <QMenu>
#include <QString>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:
    void quit();
    void save();
    void open();

private:
    QTextEdit *textEdit;
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;

    QMenu *fileMenu;

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
