#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include "qhashcalc.h"
#include "qhashcracker.h"
namespace Ui
{
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
    void on_Md4_radioButton_toggled(bool checked);
    void on_Md5_radioButton_toggled(bool checked);
    void on_Sha1_radioButton_toggled(bool checked);
    void on_Sha224_radioButton_toggled(bool checked);
    void on_Sha256_radioButton_toggled(bool checked);
    void on_Sha384_radioButton_toggled(bool checked);
    void on_Sha512_radioButton_toggled(bool checked);
    void on_crack_pushButton_clicked();
    void resultReturned(QString result);

private:
    void clearAllResults();
    Ui::Widget *ui;
    QHashCalc *hashCalcer;
    QHashCracker* hashCracker;

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
};

#endif // WIDGET_H
