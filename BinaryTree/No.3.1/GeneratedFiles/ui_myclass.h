/********************************************************************************
** Form generated from reading UI file 'myclass.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLASS_H
#define UI_MYCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *firstBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *firstPreLine;
    QPushButton *findButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *levelLine;
    QPushButton *swapButton;
    QLineEdit *findLine;
    QLineEdit *parentLine;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *secondBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *secondPreLine;
    QLineEdit *inorderLine;
    QHBoxLayout *horizontalLayout;
    QLineEdit *graLine;
    QPushButton *getTreeButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QStringLiteral("MyClassClass"));
        MyClassClass->resize(696, 338);
        gridLayout = new QGridLayout(MyClassClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        firstBox = new QGroupBox(MyClassClass);
        firstBox->setObjectName(QStringLiteral("firstBox"));
        verticalLayout_2 = new QVBoxLayout(firstBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        firstPreLine = new QLineEdit(firstBox);
        firstPreLine->setObjectName(QStringLiteral("firstPreLine"));

        horizontalLayout_2->addWidget(firstPreLine);

        findButton = new QPushButton(firstBox);
        findButton->setObjectName(QStringLiteral("findButton"));

        horizontalLayout_2->addWidget(findButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        levelLine = new QLineEdit(firstBox);
        levelLine->setObjectName(QStringLiteral("levelLine"));

        horizontalLayout_3->addWidget(levelLine);

        swapButton = new QPushButton(firstBox);
        swapButton->setObjectName(QStringLiteral("swapButton"));

        horizontalLayout_3->addWidget(swapButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        findLine = new QLineEdit(firstBox);
        findLine->setObjectName(QStringLiteral("findLine"));

        verticalLayout_2->addWidget(findLine);

        parentLine = new QLineEdit(firstBox);
        parentLine->setObjectName(QStringLiteral("parentLine"));

        verticalLayout_2->addWidget(parentLine);


        verticalLayout_4->addWidget(firstBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        secondBox = new QGroupBox(MyClassClass);
        secondBox->setObjectName(QStringLiteral("secondBox"));
        verticalLayout = new QVBoxLayout(secondBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        secondPreLine = new QLineEdit(secondBox);
        secondPreLine->setObjectName(QStringLiteral("secondPreLine"));

        verticalLayout->addWidget(secondPreLine);

        inorderLine = new QLineEdit(secondBox);
        inorderLine->setObjectName(QStringLiteral("inorderLine"));

        verticalLayout->addWidget(inorderLine);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graLine = new QLineEdit(secondBox);
        graLine->setObjectName(QStringLiteral("graLine"));

        horizontalLayout->addWidget(graLine);

        getTreeButton = new QPushButton(secondBox);
        getTreeButton->setObjectName(QStringLiteral("getTreeButton"));

        horizontalLayout->addWidget(getTreeButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(secondBox);


        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        retranslateUi(MyClassClass);

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QDialog *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "BinaryTree", 0));
        firstBox->setTitle(QApplication::translate("MyClassClass", "FindOrSwap", 0));
        findButton->setText(QApplication::translate("MyClassClass", "Find", 0));
        swapButton->setText(QApplication::translate("MyClassClass", "Swap", 0));
        secondBox->setTitle(QApplication::translate("MyClassClass", "GetBinaryTree", 0));
        getTreeButton->setText(QApplication::translate("MyClassClass", "GetTree", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
