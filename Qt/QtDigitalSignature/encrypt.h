#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <QDialog>

namespace Ui {
class Encrypt;
}

class Encrypt : public QDialog
{
    Q_OBJECT

public:
    explicit Encrypt(QWidget *parent = nullptr);
    ~Encrypt();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Encrypt *ui;
};

#endif // ENCRYPT_H
