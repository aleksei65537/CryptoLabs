/********************************************************************************
** Form generated from reading UI file 'signature.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNATURE_H
#define UI_SIGNATURE_H

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

class Ui_Signature
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPlainTextEdit *plainTextEditSignature;
    QLabel *label_3;
    QPlainTextEdit *plainTextEditKey;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTextBrowser *textBrowserSignature;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonSign;

    void setupUi(QDialog *Signature)
    {
        if (Signature->objectName().isEmpty())
            Signature->setObjectName(QString::fromUtf8("Signature"));
        Signature->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Signature->sizePolicy().hasHeightForWidth());
        Signature->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(Signature);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Signature);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        plainTextEditSignature = new QPlainTextEdit(Signature);
        plainTextEditSignature->setObjectName(QString::fromUtf8("plainTextEditSignature"));

        verticalLayout_2->addWidget(plainTextEditSignature);

        label_3 = new QLabel(Signature);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        plainTextEditKey = new QPlainTextEdit(Signature);
        plainTextEditKey->setObjectName(QString::fromUtf8("plainTextEditKey"));

        verticalLayout_2->addWidget(plainTextEditKey);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(Signature);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        textBrowserSignature = new QTextBrowser(Signature);
        textBrowserSignature->setObjectName(QString::fromUtf8("textBrowserSignature"));

        verticalLayout_3->addWidget(textBrowserSignature);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        pushButtonSign = new QPushButton(Signature);
        pushButtonSign->setObjectName(QString::fromUtf8("pushButtonSign"));

        verticalLayout->addWidget(pushButtonSign);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(Signature);

        QMetaObject::connectSlotsByName(Signature);
    } // setupUi

    void retranslateUi(QDialog *Signature)
    {
        Signature->setWindowTitle(QCoreApplication::translate("Signature", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Signature", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("Signature", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\260\320\272\321\200\321\213\321\202\321\213\320\271 \320\272\320\273\321\216\321\207", nullptr));
        label_2->setText(QCoreApplication::translate("Signature", "\320\237\320\276\320\264\320\277\320\270\321\201\321\214", nullptr));
        pushButtonSign->setText(QCoreApplication::translate("Signature", "\320\237\320\276\320\264\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signature: public Ui_Signature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNATURE_H
