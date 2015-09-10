#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);

    openAction = new QAction(tr("&Open"), this); // Creates a new action - Open
    saveAction = new QAction(tr("&Save"), this); // Creates a new action - Save
    exitAction = new QAction(tr("E&xit"), this); // Creates a new action - Exit

    // Connects all actions with its functions
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));

    // Adds a menu on the menuBar
    fileMenu = menuBar()->addMenu(tr("&File"));
    // Adds all actions on the menu
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    textEdit = new QTextEdit; // New TextEdit
    setCentralWidget(textEdit); // TextEdit Fullscreen

    setWindowTitle(tr("Notepad")); // Window Title
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::quit()
{
    // Creates a message box when user press the exit button
    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("Notepad"));
    messageBox.setText(tr("Do you really want to quit?"));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);

    // If user press yes then closes the application
    if (messageBox.exec() == QMessageBox::Yes)
        qApp->quit();
}

void Notepad::save()
{
    // Creates a file dialog with the options txt, cpp and h to save a file
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}

void Notepad::open()
{
    // Creates a file dialog with the options txt, cpp and h to open a file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
}
