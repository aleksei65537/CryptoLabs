#ifndef GENERATE_H
#define GENERATE_H

#include <QDialog>

namespace Ui {
class Generate;
}

class Generate : public QDialog
{
    Q_OBJECT

public:
    explicit Generate(QWidget *parent = nullptr);
    ~Generate();

private slots:
    void on_pushButtonGenerateKeys_clicked();

private:
    Ui::Generate *ui;
};

#endif // GENERATE_H
