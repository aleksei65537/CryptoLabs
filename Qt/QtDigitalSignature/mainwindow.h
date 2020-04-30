#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "generate.h"
#include "signature.h"
#include "verify.h"
#include "decrypt.h"
#include "encrypt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonChooseGenerate_clicked();

    void on_pushButtonChooseSign_clicked();

    void on_pushButtonChooseVerify_clicked();

    void on_pushButton_clicked();

    void on_pushButtonDecrypt_clicked();

private:
    Ui::MainWindow *ui;
    Generate generate;
    Signature signature;
    Verify verify;
    Decrypt decrypt;
    Encrypt encrypt;
};
#endif // MAINWINDOW_H
