#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QClipboard>
#include "../Core/HashCalcer/qhashcalc.h"
#include "../Core/HashCracker/qhashcracker.h"
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

signals:
    void readyCompareResult(bool);
private slots:
    void showCompareResult(bool equal);

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
    void on_crack_pushButton_clicked();
    void resultReturned(QString result);
    void on_pasteFromClipboard_Button_clicked();
    void on_compareFile_GroupBox_toggled(bool arg1);
    void on_comparePasteFromClipboard_Button_clicked();
    void on_chooseCompareFile_ToolBox_clicked();
    void on_hashTextAlgorithm_ComboBox_currentIndexChanged(const QString &arg1);

private:
    void clearAllResults();
    Ui::Widget *ui;
    QHashCalc *hashCalcer;
    QHashCalc *compareHashCalcer;
    QHashCracker* hashCracker;

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
};

#endif // WIDGET_H
