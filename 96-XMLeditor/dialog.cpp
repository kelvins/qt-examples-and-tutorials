#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // create the model
    FileName = "/home/kelvin/MyXML.xml";
    model = new QStandardItemModel(0, 1, this); // 0 rows 1 column

    ReadFile();

    ui->treeView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ReadFile()
{
    QStandardItem *root = new QStandardItem("Books");
    model->appendRow(root);

    QDomDocument document;

    // load the xml file
    QFile file(FileName);
    if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        document.setContent(&file);
        file.close();
    }

    // get the xml root element
    QDomElement xmlRoot = document.firstChildElement();

    // read the books
    QDomNodeList books = xmlRoot.elementsByTagName("Book");

    for (int var = 0; var < books.count(); ++var)
    {
        QDomElement book = books.at(var).toElement();
        QStandardItem *bookItem = new QStandardItem(book.attribute("Name"));

        // read the chapters of the book
        QDomNodeList chapters = book.elementsByTagName("Chapter");
        for (int i = 0; i < chapters.count(); ++i)
        {
            QDomElement chapter = chapters.at(i).toElement();
            QStandardItem *chapterItem = new QStandardItem(chapter.attribute("Name"));

            bookItem->appendRow(chapterItem);
        }
        root->appendRow(bookItem);
    }
}

void Dialog::WriteFile()
{
    // write the xml file
    QDomDocument document;

    // Make a root node
    QDomElement xmlRoot = document.createElement("Books");
    document.appendChild(xmlRoot);

    QStandardItem *root = model->item(0, 0);
    for (int var = 0; var < root->rowCount(); ++var)
    {
        QStandardItem *book = root->child(var, 0);

        QDomElement xmlBook = document.createElement("Book");
        xmlBook.setAttribute("Name", book->text());
        xmlBook.setAttribute("ID", var);
        xmlRoot.appendChild(xmlBook);

        for (int h = 0; h < book->rowCount(); ++h)
        {
            QStandardItem *chapter = book->child(h, 0);
            QDomElement xmlChapter = document.createElement("Chapter");
            xmlChapter.setAttribute("Name", chapter->text());
            xmlChapter.setAttribute("ID", h);
            xmlBook.appendChild(xmlChapter);
        }
    }

    // save to disk
    QFile file(FileName);
    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Failed to write file";
    }

    QTextStream stream(&file);
    stream << document.toString();
    file.close();

    qDebug() << "Finished";
}

void Dialog::on_pushButton_clicked()
{
    // save the document
    WriteFile();
}
