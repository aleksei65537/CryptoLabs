/********************************************************************************
** Form generated from reading UI file 'generate.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATE_H
#define UI_GENERATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Generate
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowserPrivateKey;
    QTextBrowser *textBrowserPublicKey;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonGenerateKeys;

    void setupUi(QDialog *Generate)
    {
        if (Generate->objectName().isEmpty())
            Generate->setObjectName(QString::fromUtf8("Generate"));
        Generate->resize(800, 600);
        verticalLayout = new QVBoxLayout(Generate);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textBrowserPrivateKey = new QTextBrowser(Generate);
        textBrowserPrivateKey->setObjectName(QString::fromUtf8("textBrowserPrivateKey"));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        textBrowserPrivateKey->setFont(font);

        horizontalLayout->addWidget(textBrowserPrivateKey);

        textBrowserPublicKey = new QTextBrowser(Generate);
        textBrowserPublicKey->setObjectName(QString::fromUtf8("textBrowserPublicKey"));
        textBrowserPublicKey->setFont(font);

        horizontalLayout->addWidget(textBrowserPublicKey);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonGenerateKeys = new QPushButton(Generate);
        pushButtonGenerateKeys->setObjectName(QString::fromUtf8("pushButtonGenerateKeys"));

        horizontalLayout_2->addWidget(pushButtonGenerateKeys);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Generate);

        QMetaObject::connectSlotsByName(Generate);
    } // setupUi

    void retranslateUi(QDialog *Generate)
    {
        Generate->setWindowTitle(QCoreApplication::translate("Generate", "Dialog", nullptr));
        pushButtonGenerateKeys->setText(QCoreApplication::translate("Generate", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Generate: public Ui_Generate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATE_H
