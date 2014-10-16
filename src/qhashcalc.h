/*****************************************************************************************
*                                                                                        *
*                                                                                        *
*         ██╗  ██╗ █████╗ ███████╗██╗  ██╗ ██████╗ █████╗ ██╗      ██████╗               *
*         ██║  ██║██╔══██╗██╔════╝██║  ██║██╔════╝██╔══██╗██║     ██╔════╝               *
*         ███████║███████║███████╗███████║██║     ███████║██║     ██║                    *
*         ██╔══██║██╔══██║╚════██║██╔══██║██║     ██╔══██║██║     ██║                    *
*         ██║  ██║██║  ██║███████║██║  ██║╚██████╗██║  ██║███████╗╚██████╗               *
*         ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝               *
*                                                                                        *
* Project : HashCalc                                                                     *
* Purpose : Calculate hashes for files and texte with different algorithms               *
* Author  : Abdeljalil Letrache                                                          *
* License : LGPL v3.0                                                                    *
* Version : 1.1                                                                          *
*                                                                                        *
*****************************************************************************************/

#ifndef QHASHCALC_H
#define QHASHCALC_H
#include <QCryptographicHash>
#include <QFile>
#include <QString>


class QHashCalc
{
private:
    QString fileName;
    QCryptographicHash* Hash;
    const quint32 CHUNK_SIZE;
    const QString API_KEY;
public:
    QHashCalc();
    QHashCalc(QString fileName);
    ~QHashCalc();
    QString getFileName() const;
    void setFileName(const QString &value);
    bool isOpenbale();
    QString CalcHashForFile(QCryptographicHash::Algorithm Algorithm);
    QString CalcHashForText(const QByteArray &textToHash,QCryptographicHash::Algorithm Algorithm);


};

#endif // QHASHCALC_H
