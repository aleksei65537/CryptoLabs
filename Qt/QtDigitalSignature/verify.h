#ifndef VERIFY_H
#define VERIFY_H

#include <QDialog>

namespace Ui {
class Verify;
}

class Verify : public QDialog
{
    Q_OBJECT

public:
    explicit Verify(QWidget *parent = nullptr);
    ~Verify();

private slots:
    void on_pushButtonVerify_clicked();

private:
    Ui::Verify *ui;
};

#endif // VERIFY_H
