/********************************************************************************
** Form generated from reading UI file 'compression.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPRESSION_H
#define UI_COMPRESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CompressionClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openButton;
    QLineEdit *inputLine;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *comButton;
    QPushButton *uncomButton;

    void setupUi(QDialog *CompressionClass)
    {
        if (CompressionClass->objectName().isEmpty())
            CompressionClass->setObjectName(QStringLiteral("CompressionClass"));
        CompressionClass->resize(426, 392);
        gridLayout = new QGridLayout(CompressionClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        openButton = new QPushButton(CompressionClass);
        openButton->setObjectName(QStringLiteral("openButton"));

        horizontalLayout_2->addWidget(openButton);

        inputLine = new QLineEdit(CompressionClass);
        inputLine->setObjectName(QStringLiteral("inputLine"));

        horizontalLayout_2->addWidget(inputLine);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        progressBar = new QProgressBar(CompressionClass);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comButton = new QPushButton(CompressionClass);
        comButton->setObjectName(QStringLiteral("comButton"));
        comButton->setMinimumSize(QSize(150, 50));

        horizontalLayout->addWidget(comButton);

        uncomButton = new QPushButton(CompressionClass);
        uncomButton->setObjectName(QStringLiteral("uncomButton"));
        uncomButton->setMinimumSize(QSize(150, 50));

        horizontalLayout->addWidget(uncomButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CompressionClass);

        QMetaObject::connectSlotsByName(CompressionClass);
    } // setupUi

    void retranslateUi(QDialog *CompressionClass)
    {
        CompressionClass->setWindowTitle(QApplication::translate("CompressionClass", "Compression", 0));
        openButton->setText(QApplication::translate("CompressionClass", "\346\211\223\345\274\200", 0));
        comButton->setText(QApplication::translate("CompressionClass", "\345\216\213\347\274\251", 0));
        uncomButton->setText(QApplication::translate("CompressionClass", "\350\247\243\345\216\213", 0));
    } // retranslateUi

};

namespace Ui {
    class CompressionClass: public Ui_CompressionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPRESSION_H
