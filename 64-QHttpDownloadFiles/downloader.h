#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QDebug>
#include <QHttp>
#include <QFile>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);

    void Do_Download();

signals:

public slots:
    void stateChanged(int state);
    void responseHeaderReceived(const QNetworkReply &resp);
    void requestFinished(int id, bool error);

private:
    QNetworkAccessManager *http;

};

#endif // DOWNLOADER_H
