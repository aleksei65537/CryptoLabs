#include "encrypt.h"
#include "ui_encrypt.h"
#include "DigitalSignature/digital_signature.hpp"

Encrypt::Encrypt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Encrypt)
{
    ui->setupUi(this);
}

Encrypt::~Encrypt()
{
    delete ui;
}

void Encrypt::on_pushButton_clicked()
{
    std::string message = ui->textEditMessage->toPlainText().toStdString();
    std::string key     = ui->textEditKey->toPlainText().toStdString();

    ds::RSA<1024> rsa;
    rsa.import_pubkey_from_pem(key);

    ui->textBrowser->setText(rsa.encrypt(message).c_str());
}
