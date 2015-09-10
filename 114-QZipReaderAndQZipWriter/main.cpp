#include <QCoreApplication>
#include <QDebug>
#include "zipreader.h"
#include "zipwriter.h"

/**
 * @brief Compression Test
 * @param ZipFile the zip file
 */
void CompressTest(QString ZipFile)
{
    //ZipWriter cZip(ZipFile);
    //cZip.addDirectory("/home/kelvin/QtProjects/Youtube\ Tutorials/114-QZipReaderAndQZipWriter/images");
    //cZip.close();

    ZipWriter cZip(ZipFile);
    QString SingleFile = "/home/kelvin/QtProjects/Youtube\ Tutorials/114-QZipReaderAndQZipWriter/images/galaxy.jpg";
    QFile file(SingleFile);
    file.open(QIODevice::ReadOnly);

    cZip.addFile("image1.jpg", file.readAll());

    file.close();
    cZip.close();
}

/**
 * @brief Decompress Test
 * @param ZipFile the zip file
 */
void DecompressTest(QString ZipFile)
{
    ZipReader cZip(ZipFile);
    foreach(ZipReader::FileInfo item, cZip.fileInfoList())
    {
        qDebug() << item.filePath;
    }

    //cZip.extractAll("DEST");

    ZipReader::FileInfo fInfo = cZip.entryInfoAt(0);
    QFile file("/home/kelvin/QtProjects/Youtube\ Tutorials/114-QZipReaderAndQZipWriter/images/galaxy2.jpg");
    file.open(QIODevice::WriteOnly);

    file.write(cZip.fileData(fInfo.filePath));

    file.close();
    cZip.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString ZipFile = "/home/kelvin/QtProjects/Youtube\ Tutorials/114-QZipReaderAndQZipWriter/test.zip";
    CompressTest(ZipFile);
    DecompressTest(ZipFile);

    return a.exec();
}
