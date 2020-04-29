#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CRC/crc.hpp"
#include <iostream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonEncode_clicked()
{
    std::string message = ui->lineEditEncode->text().toStdString();
    std::cout << message;
    ui->textBrowser->setText(QString::number(crc(message)));
}

void MainWindow::on_pushButtonDecode_clicked()
{
    std::string message = ui->lineEditDecode->text().toStdString();
    std::stringstream ss(ui->lineEditCRC->text().toStdString());
    long long check_sum;
    ss >> check_sum;
    if (crc(message) == check_sum) {
        ui->textBrowser->setText("Правильно");
    } else {
        ui->textBrowser->setText("Неправильно");
    }
}
