#include "qhashcalc.h"

QHashCalc::QHashCalc():CHUNK_SIZE(1024*1024*4),
    API_KEY("134c7045e839655a8b032f94")
{

}

QHashCalc::QHashCalc(QString fileName):CHUNK_SIZE(1024*1024*4),
    API_KEY("134c7045e839655a8b032f94")
{
    this->fileName = fileName;
}

QHashCalc::~QHashCalc()
{
    delete this->Hash; //preventing memory leaks
}

void QHashCalc::setFileName(const QString &value)
{
    this->fileName = value;
}


QString QHashCalc::getFileName() const
{
    return fileName;
}

bool QHashCalc::isOpenbale()
{
    QFile inputFile(this->getFileName());
    if(inputFile.open(QIODevice::ReadOnly))
    {
        inputFile.close();
        return true;
    }
    else {
        return false;
    }
}

QString QHashCalc::CalcHashForFile(QCryptographicHash::Algorithm Algorithm)
{
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);

    //using "switch" statement to compare the "Algorithm" parameter with integers from QCryptographicHash
    //to assign the choosen algorithm to "Hash"

    switch (Algorithm)
    {
    case QCryptographicHash::Md4:
         Hash = new QCryptographicHash(QCryptographicHash::Md4);
        break;
    case QCryptographicHash::Md5:
        Hash = new QCryptographicHash(QCryptographicHash::Md5);
        break;
    case QCryptographicHash::Sha1:
        Hash = new QCryptographicHash(QCryptographicHash::Sha1);
        break;
    case QCryptographicHash::Sha224:
        Hash = new QCryptographicHash(QCryptographicHash::Sha224);
        break;
    case QCryptographicHash::Sha256:
        Hash = new QCryptographicHash(QCryptographicHash::Sha256);
        break;
    case QCryptographicHash::Sha384:
        Hash = new QCryptographicHash(QCryptographicHash::Sha384);
        break;
    case QCryptographicHash::Sha512:
        Hash = new QCryptographicHash(QCryptographicHash::Sha512);
        break;
    }

    while(!inputFile.atEnd())
    {
        Hash->addData(inputFile.read(CHUNK_SIZE));
    }
    inputFile.close();
    QString Result = QString(Hash->result().toHex());
    Hash->reset();
    return Result;
}

QString QHashCalc::CalcHashForText(const QByteArray &textToHash,QCryptographicHash::Algorithm Algorithm)
{
    switch (Algorithm)
    {
    case QCryptographicHash::Md4:
         Hash = new QCryptographicHash(QCryptographicHash::Md4);
        break;
    case QCryptographicHash::Md5:
        Hash = new QCryptographicHash(QCryptographicHash::Md5);
        break;
    case QCryptographicHash::Sha1:
        Hash = new QCryptographicHash(QCryptographicHash::Sha1);
        break;
    case QCryptographicHash::Sha224:
        Hash = new QCryptographicHash(QCryptographicHash::Sha224);
        break;
    case QCryptographicHash::Sha256:
        Hash = new QCryptographicHash(QCryptographicHash::Sha256);
        break;
    case QCryptographicHash::Sha384:
        Hash = new QCryptographicHash(QCryptographicHash::Sha384);
        break;
    case QCryptographicHash::Sha512:
        Hash = new QCryptographicHash(QCryptographicHash::Sha512);
        break;
    }

    Hash->addData(textToHash);
    QString Result = QString(Hash->result().toHex());

    //Using a variable to store the result HEX value, because reseting
    //"Hash" to the initial state before doing other calculations, must be done before returning

    Hash->reset();
    return Result;
}
