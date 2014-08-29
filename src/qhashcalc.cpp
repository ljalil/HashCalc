#include "qhashcalc.h"



QHashCalc::QHashCalc():chunckSize(1024*1024*4)
{

}

QHashCalc::QHashCalc(QString fileName):chunckSize(1024*1024*4)
{
    this->fileName = fileName;
}

void QHashCalc::setFileName(const QString &value)
{
    fileName = value;
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



QString QHashCalc::getFileName() const
{
    return fileName;
}



QString QHashCalc::calcMD4ForFile()
{
    QCryptographicHash hash(QCryptographicHash::Md4);
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);
    while(!inputFile.atEnd())
    {
        hash.addData(inputFile.read(chunckSize));
    }
    inputFile.close();
    return QString(hash.result().toHex());
}

QString QHashCalc::calcMD5ForFile()
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);
    while(!inputFile.atEnd())
    {
        hash.addData(inputFile.read(chunckSize));
    }
    inputFile.close();
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA1ForFile()
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);
    while(!inputFile.atEnd())
    {
        hash.addData(inputFile.read(chunckSize));
    }
    inputFile.close();
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA224ForFile()
{
    QCryptographicHash hash(QCryptographicHash::Sha224);
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);
    while(!inputFile.atEnd())
    {
        hash.addData(inputFile.read(chunckSize));
    }
    inputFile.close();
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA256ForFile()
{
    QCryptographicHash hash(QCryptographicHash::Sha256);
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);
    while(!inputFile.atEnd())
    {
        hash.addData(inputFile.read(chunckSize));
    }
    inputFile.close();
    return QString(hash.result().toHex());
}


QString QHashCalc::calcSHA384ForFile()
{
    QCryptographicHash hash(QCryptographicHash::Sha384);
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);
    while(!inputFile.atEnd())
    {
        hash.addData(inputFile.read(chunckSize));
    }
    inputFile.close();
    return QString(hash.result().toHex());
}


QString QHashCalc::calcSHA512ForFile()
{
    QCryptographicHash hash(QCryptographicHash::Sha512);
    QFile inputFile(this->fileName);
    inputFile.open(QIODevice::ReadOnly);
    while(!inputFile.atEnd())
    {
        hash.addData(inputFile.read(chunckSize));
    }
    inputFile.close();
    return QString(hash.result().toHex());
}

QString QHashCalc::calcMD4ForText(const QByteArray &textToHash)
{
    QCryptographicHash hash(QCryptographicHash::Md4);
    hash.addData(textToHash);
    return QString(hash.result().toHex());
}

QString QHashCalc::calcMD5ForText(const QByteArray &textToHash)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(textToHash);
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA1ForText(const QByteArray &textToHash)
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(textToHash);
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA224ForText(const QByteArray &textToHash)
{
    QCryptographicHash hash(QCryptographicHash::Sha224);
    hash.addData(textToHash);
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA256ForText(const QByteArray &textToHash)
{
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(textToHash);
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA384ForText(const QByteArray &textToHash)
{
    QCryptographicHash hash(QCryptographicHash::Sha384);
    hash.addData(textToHash);
    return QString(hash.result().toHex());
}

QString QHashCalc::calcSHA512ForText(const QByteArray &textToHash)
{
    QCryptographicHash hash(QCryptographicHash::Sha512);
    hash.addData(textToHash);
    return QString(hash.result().toHex());
}
