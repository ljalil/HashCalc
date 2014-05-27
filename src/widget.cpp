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
* Version : 0.2                                                                          *
*                                                                                        *
*****************************************************************************************/


#include <QCryptographicHash>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :QWidget(parent),
                                ui(new Ui::Widget),
                                chunckSize(1024*1024*4)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
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

void Widget::on_openFileDialog_ToolButton_clicked()
{
    //assign the name of the file that user select
    //to the variable fileName 'QString'
    fileName = QFileDialog::getOpenFileName(
                                            this,
                                            "Choose a local file",
                                            QDir::homePath()
                                            );
    if(!fileName.isEmpty())
        ui->fileName_LineEdit->setText(fileName);
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

    //check if there is no path in the fileName
    if(fileName.isEmpty())
    {
        QMessageBox::warning(
                            this,
                            "Error",
                            "There is no input file, please select one then continue"
                            );
        return;
    }

    //set the file name with the path given from user

    inputFile.setFileName(fileName);

    //check if the file is accessible,
    //show error and exit if not, continue if yes

    if(!inputFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(
                             this,
                             "Error",
                             "Sorry, cannot open the file, please check if it's still exists then try again"
                             );
        return;
    }

    ui->progressBar->setMaximum(inputFile.size()/1000);

    //this section will executed if the file is accessible
    //and everytthing is okay

    if(ui->Md4_checkBox->isChecked())
    {
        QCryptographicHash hash(QCryptographicHash::Md4);
        inputFile.seek(0);
        ui->label->setText("[MD4]: Reading file...");
        ui->progressBar->setValue(0);
        while(!inputFile.atEnd())
        {
            hash.addData(inputFile.read(chunckSize));
            ui->progressBar->setValue(inputFile.pos() / 1000);
        }
        ui->label->setText("[MD4]: Hashing file...");
        ui->Md4_lineEdit->setText(hash.result().toHex());
        ui->label->setText("[MD4]: Done.");
    }

    if(ui->Md5_checkBox->isChecked())
    {
        QCryptographicHash hash(QCryptographicHash::Md5);
        inputFile.seek(0);
        ui->label->setText("[MD5]: Reading file...");
        ui->progressBar->setValue(0);
        while(!inputFile.atEnd())
        {
            hash.addData(inputFile.read(chunckSize));
            ui->progressBar->setValue(inputFile.pos() / 1000);
        }
        ui->label->setText("[MD5]: Hashing file...");
        ui->Md5_lineEdit->setText(hash.result().toHex());
        ui->label->setText("[MD5]: Done.");
    }

    if(ui->Sha1_checkBox->isChecked())
    {
        QCryptographicHash hash(QCryptographicHash::Sha1);
        inputFile.seek(0);
        ui->label->setText("[SHA1]: Reading file...");
        ui->progressBar->setValue(0);
        while(!inputFile.atEnd())
        {
            hash.addData(inputFile.read(chunckSize));
            ui->progressBar->setValue(inputFile.pos() / 1000);
        }
        ui->label->setText("[SHA1]: Hashing file...");
        ui->Sha1_lineEdit->setText(hash.result().toHex());
        ui->label->setText("[SHA1]: Done.");
    }

    if(ui->Sha224_checkBox->isChecked())
    {
        QCryptographicHash hash(QCryptographicHash::Sha224);
        inputFile.seek(0);
        ui->label->setText("[SHA224]: Reading file...");
        ui->progressBar->setValue(0);
        while(!inputFile.atEnd())
        {
            hash.addData(inputFile.read(chunckSize));
            ui->progressBar->setValue(inputFile.pos() / 1000);
        }
        ui->label->setText("[SHA224]: Hashing file...");
        ui->Sha224_lineEdit->setText(hash.result().toHex());
        ui->label->setText("[SHA224]: Done.");
    }

    if(ui->Sha256_checkBox->isChecked())
    {
        QCryptographicHash hash(QCryptographicHash::Sha256);
        inputFile.seek(0);
        ui->label->setText("[SHA256]: Reading file...");
        ui->progressBar->setValue(0);
        while(!inputFile.atEnd())
        {
            hash.addData(inputFile.read(chunckSize));
            ui->progressBar->setValue(inputFile.pos() / 1000);
        }
        ui->label->setText("[SHA256]: Hashing file...");
        ui->Sha256_lineEdit->setText(hash.result().toHex());
        ui->label->setText("[SHA256]: Done.");
    }

    if(ui->Sha384_checkBox->isChecked())
    {
        QCryptographicHash hash(QCryptographicHash::Sha384);
        inputFile.seek(0);
        ui->label->setText("[SHA384]: Reading file...");
        ui->progressBar->setValue(0);
        while(!inputFile.atEnd())
        {
            hash.addData(inputFile.read(chunckSize));
            ui->progressBar->setValue(inputFile.pos() / 1000);
        }
        ui->label->setText("[SHA384]: Hashing file...");
        ui->Sha384_lineEdit->setText(hash.result().toHex());
        ui->label->setText("[SHA384]: Done.");
    }

    if(ui->Sha512_checkBox->isChecked())
    {
        QCryptographicHash hash(QCryptographicHash::Sha512);
        inputFile.seek(0);
        ui->label->setText("[SHA512]: Reading file...");
        ui->progressBar->setValue(0);
        while(!inputFile.atEnd())
        {
            hash.addData(inputFile.read(chunckSize));
            ui->progressBar->setValue(inputFile.pos() / 1000);
        }
        ui->label->setText("[SHA512]: Hashing file...");
        ui->Sha512_lineEdit->setText(hash.result().toHex());
        ui->label->setText("[SHA512]: Done.");
    }
    ui->label->setText("Done :-)");
    inputFile.close();
}

//*******************-> slot for calculate buttons [end] <-*******************


void Widget::on_textToHash_plainTextEdit_textChanged()
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}

void Widget::on_textCalculate_pushButton_clicked()
{
    if(ui->textToHash_plainTextEdit->toPlainText().isEmpty())
    {
        QMessageBox::warning(this,"Error","There is no text to process");
    }

    else if(ui->Md4_radioButton->isChecked())
    {
        ui->textHash_groupBox->setTitle("The result:");
        ui->textHash_plainTextEdit->clear();
        QCryptographicHash hash(QCryptographicHash::Md4);
        hash.addData(ui->textToHash_plainTextEdit->toPlainText().toUtf8());
        ui->textHash_plainTextEdit->insertPlainText(hash.result().toHex());
    }

    else if(ui->Md5_radioButton->isChecked())
    {
        ui->textHash_groupBox->setTitle("The result:");
        ui->textHash_plainTextEdit->clear();
        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(ui->textToHash_plainTextEdit->toPlainText().toUtf8());
        ui->textHash_plainTextEdit->insertPlainText(hash.result().toHex());
    }

    else if(ui->Sha1_radioButton->isChecked())
    {
        ui->textHash_groupBox->setTitle("The result:");
        ui->textHash_plainTextEdit->clear();
        QCryptographicHash hash(QCryptographicHash::Sha1);
        hash.addData(ui->textToHash_plainTextEdit->toPlainText().toUtf8());
        ui->textHash_plainTextEdit->insertPlainText(hash.result().toHex());
    }

    else if(ui->Sha224_radioButton->isChecked())
    {
        ui->textHash_groupBox->setTitle("The result:");
        ui->textHash_plainTextEdit->clear();
        QCryptographicHash hash(QCryptographicHash::Sha224);
        hash.addData(ui->textToHash_plainTextEdit->toPlainText().toUtf8());
        ui->textHash_plainTextEdit->insertPlainText(hash.result().toHex());
    }

    else if(ui->Sha256_radioButton->isChecked())
    {
        ui->textHash_groupBox->setTitle("The result:");
        ui->textHash_plainTextEdit->clear();
        QCryptographicHash hash(QCryptographicHash::Sha256);
        hash.addData(ui->textToHash_plainTextEdit->toPlainText().toUtf8());
        ui->textHash_plainTextEdit->insertPlainText(hash.result().toHex());
    }

    else if(ui->Sha384_radioButton->isChecked())
    {
        ui->textHash_groupBox->setTitle("The result:");
        ui->textHash_plainTextEdit->clear();
        QCryptographicHash hash(QCryptographicHash::Sha384);
        hash.addData(ui->textToHash_plainTextEdit->toPlainText().toUtf8());
        ui->textHash_plainTextEdit->insertPlainText(hash.result().toHex());
    }

    else if(ui->Sha512_radioButton->isChecked())
    {
        ui->textHash_groupBox->setTitle("The result:");
        ui->textHash_plainTextEdit->clear();
        QCryptographicHash hash(QCryptographicHash::Sha512);
        hash.addData(ui->textToHash_plainTextEdit->toPlainText().toUtf8());
        ui->textHash_plainTextEdit->insertPlainText(hash.result().toHex());
    }

}

void Widget::on_pushButton_clicked()
{
    QMessageBox::aboutQt(this);
}



void Widget::on_Md4_radioButton_toggled(bool checked)
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}

void Widget::on_Md5_radioButton_toggled(bool checked)
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}

void Widget::on_Sha1_radioButton_toggled(bool checked)
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}

void Widget::on_Sha224_radioButton_toggled(bool checked)
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}

void Widget::on_Sha256_radioButton_toggled(bool checked)
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}

void Widget::on_Sha384_radioButton_toggled(bool checked)
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}

void Widget::on_Sha512_radioButton_toggled(bool checked)
{
    ui->textHash_groupBox->setTitle("Click 'Hash the text' and see the result here");
}
