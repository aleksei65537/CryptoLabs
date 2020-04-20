#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButtonChooseGenerate_clicked()
{
    generate.show();
}

void MainWindow::on_pushButtonChooseSign_clicked()
{
    signature.show();
}

void MainWindow::on_pushButtonChooseVerify_clicked()
{
    verify.show();
}
