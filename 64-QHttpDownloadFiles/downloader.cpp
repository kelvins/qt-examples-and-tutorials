#include "downloader.h"

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
}

void Downloader::Do_Download()
{

}

void Downloader::stateChanged(int state)
{
    switch (state)
    {
        case 0:
            qDebug() << "Unconnected";
            break;
        case 1:
            qDebug() << "Host Lookup";
            break;
        case 2:
            qDebug() << "Connecting";
            break;
        case 3:
            qDebug() << "Sending";
            break;
        case 4:
            qDebug() << "Reading";
            break;
        case 5:
            qDebug() << "Connect";
            break;
        case 6:
            qDebug() << "Closing";
            break;
    }
}

void Downloader::responseHeaderReceived(const QNetworkRequest &resp)
{
    qDebug() << "Size" << resp.
}

void Downloader::requestFinished(int id, bool error)
{

}
