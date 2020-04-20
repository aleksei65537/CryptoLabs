#include "generate.h"
#include "ui_generate.h"
#include "DigitalSignature/digital_signature.hpp"
#include <QTextStream>
#include <QString>
#include <string>
#include <sstream>
#include "mainwindow.h"

Generate::Generate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generate)
{
    ui->setupUi(this);
}

Generate::~Generate()
{
    delete ui;
}

void Generate::on_pushButtonGenerateKeys_clicked()
{
    ds::RSA<1024> rsa;
    rsa.generate();
    std::stringstream ss;
    rsa.export_privkey_to_pem(ss);

    ui->textBrowserPrivateKey->setText(ss.str().c_str());

    ss.str("");
    rsa.export_pubkey_to_pem(ss);

    ui->textBrowserPublicKey->setText(ss.str().c_str());
}
