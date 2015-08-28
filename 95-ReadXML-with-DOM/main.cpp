
#include <QtCore>
#include <QtXml>
#include <QDebug>

// DOM Method of reading XML

void ListElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);

    qDebug() << "Total items = " << items.count();

    for (int var = 0; var < items.count(); ++var)
    {
        QDomNode itemNode = items.at(var);

        // convert to element
        if( itemNode.isElement() )
        {
            QDomElement itemEle = itemNode.toElement();
            qDebug() << itemEle.attribute(attribute);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;

    // Load the file
    QFile file("/home/kelvin/MyXML.xml");
    if( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Could not open the file";
        return -1;
    }
    else
    {
        if( !document.setContent(&file) )
        {
            qDebug() << "Failed to load document";
            file.close();
            return -1;

        }
    }

    // Get the root element
    QDomElement root = document.firstChildElement();

    // List the books
    ListElements(root, "Book", "Name");

    qDebug() << "\r\nMore Advanced\r\n";

    // Get the chapters
    QDomNodeList books = root.elementsByTagName("Book");
    for (int var = 0; var < books.count(); ++var)
    {
        QDomNode bookNode = books.at(var);
        // convert to element
        if( bookNode.isElement() )
        {
            QDomElement book = bookNode.toElement();
            qDebug() << "Chapters in " << book.attribute("Name");
            ListElements(book, "Chapter", "Name");
        }
    }

    qDebug() << "Finished";

    return a.exec();
}
