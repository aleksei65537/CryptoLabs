#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <QDialog>

namespace Ui {
class Signature;
}

class Signature : public QDialog
{
    Q_OBJECT

public:
    explicit Signature(QWidget *parent = nullptr);
    ~Signature();

private slots:
    void on_pushButtonSign_clicked();

private:
    Ui::Signature *ui;
};

#endif // SIGNATURE_H
