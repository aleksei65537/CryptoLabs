#include "decrypt.h"
#include "ui_decrypt.h"
#include "DigitalSignature/digital_signature.hpp"

Decrypt::Decrypt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decrypt)
{
    ui->setupUi(this);
}

Decrypt::~Decrypt()
{
    delete ui;
}

void Decrypt::on_pushButton_clicked()
{
    std::string cipher = ui->textEditCipher->toPlainText().toStdString();
    std::string key     = ui->textEditKey->toPlainText().toStdString();

    ds::RSA<1024> rsa;
    rsa.import_privkey_from_pem(key);

    ui->textBrowser->setText(rsa.decrypt(cipher).c_str());
}
