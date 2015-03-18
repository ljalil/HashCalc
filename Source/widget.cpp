#include <QCryptographicHash>
#include <QDir>
#include <QMessageBox> //QMessageBox::warning()
#include <QFileDialog> //QFileDialog::getOpenFileName()
#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent) :QWidget(parent),
                                ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QObject::connect(this,SIGNAL(readyCompareResult(bool)),this,SLOT(showCompareResult(bool)));
    hashCalcer = new QHashCalc;
    hashCracker = new QHashCracker;
}

Widget::~Widget()
{
    delete hashCalcer;
    delete hashCracker;
    delete ui;
}

void Widget::showCompareResult(bool equal)
{
    if (equal == false ) {
        ui->compareFileResult_Label->setStyleSheet("color : red;");
        ui->compareFileResult_Label->setText("Files are different");
    } else if (equal) {
        ui->compareFileResult_Label->setStyleSheet("color : green;");
        ui->compareFileResult_Label->setText("Files are identical");
    }
}

void Widget::clearAllResults()
{
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
    if (!this->hashCalcer->getFileName().isEmpty())
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
    if (this->hashCalcer->getFileName().isEmpty()) {
        QMessageBox::warning(
                            this,
                            "Error",
                            "There is no input file, please select one then continue"
                            );
        return;
    }

    if (!this->hashCalcer->isOpenbale()) {
        QMessageBox::warning(
                             this,
                             "Error",
                             "Sorry, cannot open the file, please check if it's still exists then try again"
                             );
        return;
    }

    if (ui->Md4_checkBox->isChecked())
        ui->Md4_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Md4));

    if (ui->Md5_checkBox->isChecked())
        ui->Md5_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Md5));

    if (ui->Sha1_checkBox->isChecked())
        ui->Sha1_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha1));

    if (ui->Sha224_checkBox->isChecked())
        ui->Sha224_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha224));

    if(ui->Sha256_checkBox->isChecked())
        ui->Sha256_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha256));

    if (ui->Sha384_checkBox->isChecked())
        ui->Sha384_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha384));

    if (ui->Sha512_checkBox->isChecked())
        ui->Sha512_lineEdit->setText(hashCalcer->CalcHashForFile(QCryptographicHash::Sha512));

    if (ui->compareFile_GroupBox->isChecked()) {
        compareHashCalcer = new QHashCalc;
        compareHashCalcer->setFileName(ui->compareFileName_LineEdit->text());
        if (!this->compareHashCalcer->isOpenbale()) {
            QMessageBox::warning(
                                 this,
                                 "Error",
                                 "Sorry, cannot open the file, please check if it's still exists then try again"
                                 );
            return;
        }

        if (ui->Md4_checkBox->isChecked()) {
            QString secFileHash = this->compareHashCalcer->CalcHashForFile(QCryptographicHash::Md4);
            ui->compareFileHashResult_LineEdit->setText(secFileHash);
            if (secFileHash == ui->Md4_lineEdit->text())
                emit this->readyCompareResult(true);
            else
                emit this->readyCompareResult(false);
        }
    }

}

//*******************-> slot for calculate buttons [end] <-*******************


void Widget::on_textToHash_plainTextEdit_textChanged()
{
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
}

void Widget::on_textCalculate_pushButton_clicked()
{
    if (ui->textToHash_plainTextEdit->toPlainText().isEmpty()) {
        QMessageBox::warning(this,"Error","There is no text to process");
    }

    else if (ui->hashTextAlgorithm_ComboBox->currentText() == "MD4") {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Md4));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if (ui->hashTextAlgorithm_ComboBox->currentText() == "MD5") {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Md5));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if (ui->hashTextAlgorithm_ComboBox->currentText() == "SHA-1") {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha1));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if (ui->hashTextAlgorithm_ComboBox->currentText() == "SHA-224") {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha1));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if (ui->hashTextAlgorithm_ComboBox->currentText() == "SHA-256") {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha224));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if (ui->hashTextAlgorithm_ComboBox->currentText() == "SHA-384") {
        QByteArray text = ui->textToHash_plainTextEdit->toPlainText().toUtf8();
        ui->textHash_plainTextEdit->clear();
        ui->textHash_plainTextEdit->insertPlainText(hashCalcer->CalcHashForText(text,QCryptographicHash::Sha384));
        ui->textHash_groupBox->setTitle("The result:");
    }

    else if (ui->hashTextAlgorithm_ComboBox->currentText() == "SHA-512") {
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

void Widget::on_crack_pushButton_clicked()
{
    hashCracker->setHash(ui->md5crack_lineEdit->text());
    hashCracker->downloadData();
    QObject::connect(hashCracker,SIGNAL(resultAvailable(QString)),
                     this,SLOT(resultReturned(QString)));

}

void Widget::resultReturned(QString result)
{
    if (result == QString::null) {
        ui->md5cracked_lineEdit->setStyleSheet("color: red;");
        ui->md5cracked_lineEdit->setText("The MD5 hash could not be cracked");

    } else {
        ui->md5cracked_lineEdit->setStyleSheet("");
        ui->md5cracked_lineEdit->setText(result);
    }
}

void Widget::on_pasteFromClipboard_Button_clicked()
{
    QClipboard *filePathText = qApp->clipboard();
    ui->fileName_LineEdit->setText(filePathText->text());
}

void Widget::on_compareFile_GroupBox_toggled(bool arg1)
{
    ui->compareFileResult_Label->setStyleSheet(""); //reset stylesheet
    ui->compareFileResult_Label->setText("No result!");
    if (arg1) {
    ui->calculate_pushButton->setText("Calculate/Compare checksum");
    ui->comparePasteFromClipboard_Button->setEnabled(true);
    ui->compareFileResult_Label->setEnabled(true);
    ui->compareFileName_LineEdit->setEnabled(true);
    ui->chooseCompareFile_ToolBox->setEnabled(true);
    ui->secondFile_Label->setEnabled(true);
    ui->compareFileResultLabel_Label->setEnabled(true);
    } else {
        ui->calculate_pushButton->setText("Calculate checksum");
        ui->compareFileHashResult_LineEdit->clear();
        ui->compareFileName_LineEdit->clear();
        ui->compareFileResult_Label->setStyleSheet("");
        ui->compareFileResult_Label->setText("No result!");
    }
}

void Widget::on_comparePasteFromClipboard_Button_clicked()
{
    QClipboard *compareFilePathText = qApp->clipboard();
    ui->compareFileName_LineEdit->setText(compareFilePathText->text());
}

void Widget::on_chooseCompareFile_ToolBox_clicked()
{
    QString compareFileName = QFileDialog::getOpenFileName(this,
                                                            "Choose a local file",
                                                            QDir::homePath()
                                                            );
    ui->compareFileName_LineEdit->setText(compareFileName);
}


void Widget::on_hashTextAlgorithm_ComboBox_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    ui->textHash_groupBox->setTitle("Click \"Hash the text\" and see the result here");
    ui->textHash_plainTextEdit->clear();
}
