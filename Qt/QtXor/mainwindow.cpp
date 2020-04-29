#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "XOR/xor.hpp"
#include <string>
#include <vector>
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


void MainWindow::on_pushButtonGen_clicked()
{
    std::string message = ui->textEditMessage->toPlainText().toStdString();
    std::vector<std::string> keys;
    QStringList lst = ui->textEditKeys->toPlainText().split(" ");

    for (size_t i = 0; i < lst.size(); i++)
    {
        keys.push_back(lst[i].toStdString());
    }

    std::string enc = crypt(message, keys);
    std::stringstream ss;
    for (size_t i = 0; i < enc.size(); i++)
    {
        ss.fill('0');
        ss.width(2);
        ss << std::hex << (size_t)enc[i];
    }
    ui->textBrowser->setText(ss.str().c_str());
}
