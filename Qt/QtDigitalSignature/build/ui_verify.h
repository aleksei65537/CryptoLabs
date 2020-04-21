/********************************************************************************
** Form generated from reading UI file 'verify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFY_H
#define UI_VERIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Verify
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QPlainTextEdit *plainTextEditFile;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QPlainTextEdit *plainTextEditKey;
    QLabel *label_4;
    QPlainTextEdit *plainTextEditSignatura;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonVerify;

    void setupUi(QDialog *Verify)
    {
        if (Verify->objectName().isEmpty())
            Verify->setObjectName(QString::fromUtf8("Verify"));
        Verify->resize(800, 600);
        verticalLayout_5 = new QVBoxLayout(Verify);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(Verify);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        plainTextEditFile = new QPlainTextEdit(Verify);
        plainTextEditFile->setObjectName(QString::fromUtf8("plainTextEditFile"));

        verticalLayout_3->addWidget(plainTextEditFile);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(Verify);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        plainTextEditKey = new QPlainTextEdit(Verify);
        plainTextEditKey->setObjectName(QString::fromUtf8("plainTextEditKey"));

        verticalLayout_4->addWidget(plainTextEditKey);

        label_4 = new QLabel(Verify);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        plainTextEditSignatura = new QPlainTextEdit(Verify);
        plainTextEditSignatura->setObjectName(QString::fromUtf8("plainTextEditSignatura"));

        verticalLayout_4->addWidget(plainTextEditSignatura);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(Verify);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        textBrowser = new QTextBrowser(Verify);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonVerify = new QPushButton(Verify);
        pushButtonVerify->setObjectName(QString::fromUtf8("pushButtonVerify"));

        verticalLayout->addWidget(pushButtonVerify);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(Verify);

        QMetaObject::connectSlotsByName(Verify);
    } // setupUi

    void retranslateUi(QDialog *Verify)
    {
        Verify->setWindowTitle(QCoreApplication::translate("Verify", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Verify", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("Verify", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\272\321\200\321\213\321\202\321\213\320\271 \320\272\320\273\321\216\321\207", nullptr));
        label_4->setText(QCoreApplication::translate("Verify", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\320\264\320\277\320\270\321\201\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("Verify", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        pushButtonVerify->setText(QCoreApplication::translate("Verify", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Verify: public Ui_Verify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFY_H
