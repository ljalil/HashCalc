#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QFile>
#include <QtCore/QCryptographicHash>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_openFileDialog_ToolButton_clicked();

    void on_Md4_pushButton_clicked();

    void on_Md5_pushButton_clicked();

    void on_Sha1_pushButton_clicked();

    void on_Sha224_pushButton_clicked();

    void on_Sha256_pushButton_clicked();

    void on_Sha384_pushButton_clicked();

    void on_Sha512_pushButton_clicked();

    void on_calculate_pushButton_clicked();

    void on_textToHash_plainTextEdit_textChanged();

    void on_textCalculate_pushButton_clicked();


    void on_pushButton_clicked();

private:
    void clearAllResults();
    Ui::Widget *ui;
    const quint32 chunckSize; //size to be read from file at once ~ 4 Mo
    QString fileName;
    QString textToHash;
    QFile inputFile;

};

#endif // WIDGET_H
