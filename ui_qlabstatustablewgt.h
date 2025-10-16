/********************************************************************************
** Form generated from reading UI file 'qlabstatustablewgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABSTATUSTABLEWGT_H
#define UI_QLABSTATUSTABLEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qlabstatustablewgt.h"

QT_BEGIN_NAMESPACE

class Ui_QLabStatusTableWgt
{
public:
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLabel *labelZero;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLabel *labelOne;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditStatus;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditTrigger;
    QPushButton *pushButtonCheck_3;
    QStatusTableWgt *tableWidgetStatusTable;
    QLabel *label;
    QPushButton *pushButtonCheck;

    void setupUi(QWidget *QLabStatusTableWgt)
    {
        if (QLabStatusTableWgt->objectName().isEmpty())
            QLabStatusTableWgt->setObjectName(QString::fromUtf8("QLabStatusTableWgt"));
        QLabStatusTableWgt->resize(669, 385);
        verticalLayout_7 = new QVBoxLayout(QLabStatusTableWgt);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, 50, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(QLabStatusTableWgt);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_9);

        labelZero = new QLabel(QLabStatusTableWgt);
        labelZero->setObjectName(QString::fromUtf8("labelZero"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(120);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(labelZero->sizePolicy().hasHeightForWidth());
        labelZero->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(labelZero);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_11 = new QLabel(QLabStatusTableWgt);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_11);

        labelOne = new QLabel(QLabStatusTableWgt);
        labelOne->setObjectName(QString::fromUtf8("labelOne"));
        sizePolicy1.setHeightForWidth(labelOne->sizePolicy().hasHeightForWidth());
        labelOne->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(labelOne);


        verticalLayout_5->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(verticalLayout_5, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(QLabStatusTableWgt);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditStatus = new QLineEdit(QLabStatusTableWgt);
        lineEditStatus->setObjectName(QString::fromUtf8("lineEditStatus"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(150);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditStatus->sizePolicy().hasHeightForWidth());
        lineEditStatus->setSizePolicy(sizePolicy2);
        lineEditStatus->setMaxLength(3);
        lineEditStatus->setFrame(true);
        lineEditStatus->setCursorPosition(0);

        horizontalLayout->addWidget(lineEditStatus);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(QLabStatusTableWgt);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditTrigger = new QLineEdit(QLabStatusTableWgt);
        lineEditTrigger->setObjectName(QString::fromUtf8("lineEditTrigger"));
        sizePolicy2.setHeightForWidth(lineEditTrigger->sizePolicy().hasHeightForWidth());
        lineEditTrigger->setSizePolicy(sizePolicy2);
        lineEditTrigger->setMaxLength(3);
        lineEditTrigger->setFrame(true);
        lineEditTrigger->setCursorPosition(0);

        horizontalLayout_2->addWidget(lineEditTrigger);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        pushButtonCheck_3 = new QPushButton(QLabStatusTableWgt);
        pushButtonCheck_3->setObjectName(QString::fromUtf8("pushButtonCheck_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(150);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonCheck_3->sizePolicy().hasHeightForWidth());
        pushButtonCheck_3->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButtonCheck_3, 0, 1, 2, 1);


        gridLayout_2->addLayout(gridLayout, 0, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);

        tableWidgetStatusTable = new QStatusTableWgt(QLabStatusTableWgt);
        tableWidgetStatusTable->setObjectName(QString::fromUtf8("tableWidgetStatusTable"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        tableWidgetStatusTable->setFont(font);
        tableWidgetStatusTable->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 255, 0);"));
        tableWidgetStatusTable->setFrameShadow(QFrame::Plain);
        tableWidgetStatusTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetStatusTable->setAlternatingRowColors(true);
        tableWidgetStatusTable->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetStatusTable->horizontalHeader()->setVisible(false);
        tableWidgetStatusTable->verticalHeader()->setVisible(false);
        tableWidgetStatusTable->verticalHeader()->setHighlightSections(false);

        verticalLayout_7->addWidget(tableWidgetStatusTable);

        label = new QLabel(QLabStatusTableWgt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        verticalLayout_7->addWidget(label);

        pushButtonCheck = new QPushButton(QLabStatusTableWgt);
        pushButtonCheck->setObjectName(QString::fromUtf8("pushButtonCheck"));

        verticalLayout_7->addWidget(pushButtonCheck);


        retranslateUi(QLabStatusTableWgt);

        QMetaObject::connectSlotsByName(QLabStatusTableWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabStatusTableWgt)
    {
        QLabStatusTableWgt->setWindowTitle(QApplication::translate("QLabStatusTableWgt", "Form", nullptr));
        label_9->setText(QApplication::translate("QLabStatusTableWgt", "X = 0     ", nullptr));
        labelZero->setText(QApplication::translate("QLabStatusTableWgt", "0 1 2 3 4 5 6", nullptr));
        label_11->setText(QApplication::translate("QLabStatusTableWgt", "X = 1     ", nullptr));
        labelOne->setText(QApplication::translate("QLabStatusTableWgt", "7 6 5 4 3 2 1", nullptr));
        label_2->setText(QApplication::translate("QLabStatusTableWgt", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\271:", nullptr));
        label_3->setText(QApplication::translate("QLabStatusTableWgt", "\320\242\321\200\320\265\320\261\321\203\320\265\320\274\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\321\200\320\270\320\263\320\263\320\265\321\200\320\276\320\262 ( log 2 Nmax )", nullptr));
        pushButtonCheck_3->setText(QApplication::translate("QLabStatusTableWgt", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("QLabStatusTableWgt", "\320\224\320\273\321\217 \320\277\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\271 \321\217\321\207\320\265\320\265\320\272 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265: \"\320\233\320\232\320\234\" (\320\264\320\262\320\260\320\266\320\264\321\213), \"\320\237\321\200\320\276\320\261\320\265\320\273\" \320\270\320\273\320\270 \"\320\222\320\262\320\276\320\264\"", nullptr));
        pushButtonCheck->setText(QApplication::translate("QLabStatusTableWgt", "&\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLabStatusTableWgt: public Ui_QLabStatusTableWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABSTATUSTABLEWGT_H
