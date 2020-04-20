#include "verify.h"
#include "ui_verify.h"
#include <string>
#include <DigitalSignature/digital_signature.hpp>

Verify::Verify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Verify)
{
    ui->setupUi(this);
}

Verify::~Verify()
{
    delete ui;
}

void Verify::on_pushButtonVerify_clicked()
{
    std::string sig = ui->plainTextEditSignatura->toPlainText().toStdString();
    std::string message = ui->plainTextEditFile->toPlainText().toStdString();
    std::string key = ui->plainTextEditKey->toPlainText().toStdString();

    ds::RSA<1024> rsa;
    rsa.import_pubkey_from_pem(key);
    std::stringstream ss;

    if (ds::verify(message, sig, rsa)){
        ui->textBrowser->setPlainText("Подпись верна");
    } else {
        ui->textBrowser->setPlainText("Подпись неверна");
    }
}
