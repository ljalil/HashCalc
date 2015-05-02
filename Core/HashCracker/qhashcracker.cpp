#include "qhashcracker.h"

QHashCracker::QHashCracker(QObject *parent) :
    QObject(parent),
    KEY("a7acdf6b902912da77d7fd35")
{
}

QHashCracker::QHashCracker(QString hash):
    KEY("a7acdf6b902912da77d7fd35")
{
    this->request = "http://api.md5crack.com/crack/" + KEY + "/" + hash;
}

void QHashCracker::setHash(QString hash)
{
    this->request = "http://api.md5crack.com/crack/" + KEY + "/" + hash;
}

void QHashCracker::downloadData()
{
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),
                     this,SLOT(replyFinished(QNetworkReply*)));
        manager->get(QNetworkRequest(QUrl(this->request)));
}

QString QHashCracker::getReply()
{
    return this->reply;
}

void QHashCracker::replyFinished(QNetworkReply *reply)
{
       //qDebug() << reply->readAll();
       QJsonDocument replyDocument = QJsonDocument::fromJson(reply->readAll());
       QJsonObject DocumentObj = replyDocument.object();
       QJsonValue ParsingValue = DocumentObj.value("phrase");
       this->reply = ParsingValue.toString();
       qDebug() << this->reply << endl;
       if(ParsingValue.isNull())
           this->reply = QString::null;
       emit resultAvailable(this->reply);
}
