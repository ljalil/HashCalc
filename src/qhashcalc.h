#ifndef QHASHCALC_H
#define QHASHCALC_H
#include <QCryptographicHash>
#include <QFile>
#include <QString>


class QHashCalc
{
private:
    QString fileName;
    const quint32 chunckSize;
public:
    QHashCalc();
    QHashCalc(QString fileName);
    QString getFileName() const;
    void setFileName(const QString &value);

    bool isOpenbale();

    QString calcMD4ForFile();
    QString calcMD5ForFile();
    QString calcSHA1ForFile();
    QString calcSHA224ForFile();
    QString calcSHA256ForFile();
    QString calcSHA384ForFile();
    QString calcSHA512ForFile();

    QString calcMD4ForText(const QByteArray &textToHash);
    QString calcMD5ForText(const QByteArray &textToHash);
    QString calcSHA1ForText(const QByteArray &textToHash);
    QString calcSHA224ForText(const QByteArray &textToHash);
    QString calcSHA256ForText(const QByteArray &textToHash);
    QString calcSHA384ForText(const QByteArray &textToHash);
    QString calcSHA512ForText(const QByteArray &textToHash);


};

#endif // QHASHCALC_H
