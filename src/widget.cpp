#include <QCryptographicHash>
#include <QDir>
#include <QMessageBox> //QMessageBox::warning()
#include <QFileDialog> //QFileDialog::getOpenFileName()
#include "widget.h"
#include "ui_widget.h"
#include <QTest>
Widget::Widget(QWidget *parent) :QWidget(parent),
                                ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    hashCalcer = new QHashCalc;

}

Widget::~Widget()
{
    delete hashCalcer; // preventing memory leaks
    delete hashCracker;
    delete ui;
}

void Widget::clearAllResults()
{
    //this function will be called when calculate button is
    //clicked to clear all the results before calculating the new hashes
    ui->Md4_lineEdit->clear();
    ui->Md5_lineEdit->clear();
    ui->Sha1_lineEdit->clear();
    ui->Sha224_lineEdit->clear();
    ui->Sha256_lineEdit->clear();
    ui->Sha384_lineEdit->clear();
    ui->Sha512_lineEdit->clear();
}

void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void Widget::dropEvent(QDropEvent *event)
{
    QList<QUrl> Urls = event->mimeData()->urls();
    this->hashCalcer->setFileName(Urls.first().toLocalFile());
    this->ui->fileName_LineEdit->setText(Urls.first().toLocalFile());
}

void Widget::on_openFileDialog_ToolButton_clicked()
{
    //assign the name of the file that user select
    //to the variable fileName 'QString'
    this->hashCalcer->setFileName(QFileDialog::getOpenFileName(
                                            this,
                                            "Choose a local file",
                                            QDir::homePath()
                                            ));
    if(!this->hashCalcer->getFileName().isEmpty())
        ui->fileName_LineEdit->setText(this->hashCalcer->getFileName());
}

//********************-> slots for copy buttons [start] <-********************

void Widget::on_Md4_pushButton_clicked()
{
    ui->Md4_lineEdit->selectAll();
    ui->Md4_lineEdit->copy();
}

void Widget::on_Md5_pushButton_clicked()
{
    ui->Md5_lineEdit->selectAll();
    ui->Md5_lineEdit->copy();
}

void Widget::on_Sha1_pushButton_clicked()
{
    ui->Sha1_lineEdit->selectAll();
    ui->Sha1_lineEdit->copy();
}

void Widget::on_Sha224_pushButton_clicked()
{
    ui->Sha224_lineEdit->selectAll();
    ui->Sha224_lineEdit->copy();
}

void Widget::on_Sha256_pushButton_clicked()
{
    ui->Sha256_lineEdit->selectAll();
    ui->Sha256_lineEdit->copy();
}

void Widget::on_Sha384_pushButton_clicked()
{
    ui->Sha384_lineEdit->selectAll();
    ui->Sha384_lineEdit->copy();
}

void Widget::on_Sha512_pushButton_clicked()
{
    ui->Sha512_lineEdit->selectAll();
    ui->Sha512_lineEdit->copy();
}

//*********************-> slots for copy buttons [end] <-*********************

//******************-> slot for calculate buttons [start] <-******************

void Widget::on_calculate_pushButton_clicked()
{
    //clear all the results from previous operation
    clearAllResults();

    this->hashCalcer->setFileName(ui->fileName_LineEdit->text());

    //check if there is no path in the fileName
    if(this->hashCalcer->getFileName().isEmpty())
    {
        QMessageBox::warning(
                            this,
                            "Error",
                            "There is no input file, please select one then continue"
                            );
        return;
    }

    //set the file name with the path given from user


    //check if the file is accessible,
    //show error and exit if not, continue if yes

    if(!this->hashCalcer->isOpenbale())
    {
        QMessageBox::warning(
                             this,
                             "Error",
                             "Sorry, cannot open the file, please check if it's still exists then try again"
                             );
        return;
    }


    if(ui->Md4_checkBox->isChecked())
        ui->Md4_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Md4));

    if(ui->Md5_checkBox->isChecked())
        ui->Md5_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Md5));

    if(ui->Sha1_checkBox->isChecked())
        ui->Sha1_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha1));

    if(ui->Sha224_checkBox->isChecked())
        ui->Sha224_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha224));

    if(ui->Sha256_checkBox->isChecked())
        ui->Sha256_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha256));

    if(ui->Sha384_checkBox->isChecked())
        ui->Sha384_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha384));

    if(ui->Sha512_checkBox->isChecked())
        ui->Sha512_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha512));

}

//*******************-> slot for calculate buttons [end] <-*******************


void Widget::on_textToHash_plainTextEdit_textChanged()
{
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
}

void Widget::on_textCalculate_pushButton_clicked()
{
    if(ui->textToHash_plainTextEdit->toPlainText().isEmpty())
    {
        QMessageBox::warning(this,"Error","There is no text to process");
    }

    else if(ui->Md4_radioButton->isChecked())
    {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Md4));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if(ui->Md5_radioButton->isChecked())
    {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Md5));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if(ui->Sha1_radioButton->isChecked())
    {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha1));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if(ui->Sha224_radioButton->isChecked())
    {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha1));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if(ui->Sha256_radioButton->isChecked())
    {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha224));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if(ui->Sha384_radioButton->isChecked())
    {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha384));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if(ui->Sha512_radioButton->isChecked())
    {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha512));
        ui->textHash_groupBox->setTitle("The result:");
    }

}

void Widget::on_pushButton_clicked()
{
    QMessageBox::aboutQt(this);
}


void Widget::on_Md4_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}

void Widget::on_Md5_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}

void Widget::on_Sha1_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}

void Widget::on_Sha224_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}

void Widget::on_Sha256_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}

void Widget::on_Sha384_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}

void Widget::on_Sha512_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}

void Widget::on_crack_pushButton_clicked()
{
    hashCracker = new QHashCracker(ui->md5crack_lineEdit->text());
    hashCracker->downloadData();
    qDebug("pause");
    QTest::qSleep(3000);
    qDebug("resume");

    ui->md5cracked_lineEdit->setText(hashCracker->getReply());

}
