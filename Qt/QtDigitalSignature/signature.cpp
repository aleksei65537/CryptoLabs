#include "signature.h"
#include "ui_signature.h"
#include <QString>
#include <string>
#include "DigitalSignature/digital_signature.hpp"

Signature::Signature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signature)
{
    ui->setupUi(this);
}

Signature::~Signature()
{
    delete ui;
}

void Signature::on_pushButtonSign_clicked()
{
    // Read message
    std::string message = ui->plainTextEditSignature->toPlainText().toStdString();

    // Read key
    std::string key = ui->plainTextEditKey->toPlainText().toStdString();
    ds::RSA<1024> rsa;
    rsa.import_privkey_from_pem(key);

    // Sign
    std::string sign = ds::sign(message, rsa);
    ui->textBrowserSignature->setText(sign.c_str());
}
