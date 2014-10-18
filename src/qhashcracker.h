#ifndef QHASHCRACKER_H
#define QHASHCRACKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class QHashCracker : public QObject
{
    Q_OBJECT
private:
    QString request;
    const QString KEY;
    QString reply;
    QNetworkAccessManager* manager;
public:
    explicit QHashCracker(QObject *parent = 0);
    QHashCracker(QString hash);
    void downloadData();
    QString getReply();
    void setHash(QString hash);
signals:
    void resultAvailable(QString);
public slots:
    void replyFinished(QNetworkReply* reply);
};

#endif // QHASHCRACKER_H
