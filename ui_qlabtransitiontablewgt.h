/********************************************************************************
** Form generated from reading UI file 'qlabtransitiontablewgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABTRANSITIONTABLEWGT_H
#define UI_QLABTRANSITIONTABLEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qlabtransitiontablewgt.h"

QT_BEGIN_NAMESPACE

class Ui_QLabTransitionTableWgt
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *labelZero;
    QLabel *label_7;
    QLabel *labelOne;
    QTransitionTableWgt *tableWidgetTransitionTable;
    QLabel *label;
    QLabel *label_6;
    QPushButton *pushButtonCheck;

    void setupUi(QWidget *QLabTransitionTableWgt)
    {
        if (QLabTransitionTableWgt->objectName().isEmpty())
            QLabTransitionTableWgt->setObjectName(QString::fromUtf8("QLabTransitionTableWgt"));
        QLabTransitionTableWgt->resize(669, 385);
        verticalLayout_2 = new QVBoxLayout(QLabTransitionTableWgt);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(QLabTransitionTableWgt);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(QLabTransitionTableWgt);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(QLabTransitionTableWgt);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(QLabTransitionTableWgt);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        labelZero = new QLabel(QLabTransitionTableWgt);
        labelZero->setObjectName(QString::fromUtf8("labelZero"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelZero);

        label_7 = new QLabel(QLabTransitionTableWgt);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        labelOne = new QLabel(QLabTransitionTableWgt);
        labelOne->setObjectName(QString::fromUtf8("labelOne"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelOne);


        horizontalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidgetTransitionTable = new QTransitionTableWgt(QLabTransitionTableWgt);
        tableWidgetTransitionTable->setObjectName(QString::fromUtf8("tableWidgetTransitionTable"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        tableWidgetTransitionTable->setFont(font);
        tableWidgetTransitionTable->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 255, 0);"));
        tableWidgetTransitionTable->setFrameShadow(QFrame::Plain);
        tableWidgetTransitionTable->setAlternatingRowColors(true);
        tableWidgetTransitionTable->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetTransitionTable->horizontalHeader()->setVisible(false);
        tableWidgetTransitionTable->verticalHeader()->setVisible(false);
        tableWidgetTransitionTable->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tableWidgetTransitionTable);

        label = new QLabel(QLabTransitionTableWgt);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_6 = new QLabel(QLabTransitionTableWgt);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        pushButtonCheck = new QPushButton(QLabTransitionTableWgt);
        pushButtonCheck->setObjectName(QString::fromUtf8("pushButtonCheck"));

        verticalLayout_2->addWidget(pushButtonCheck);


        retranslateUi(QLabTransitionTableWgt);

        QMetaObject::connectSlotsByName(QLabTransitionTableWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabTransitionTableWgt)
    {
        QLabTransitionTableWgt->setWindowTitle(QApplication::translate("QLabTransitionTableWgt", "Form", nullptr));
        label_2->setText(QApplication::translate("QLabTransitionTableWgt", "y1 = Q1", nullptr));
        label_3->setText(QApplication::translate("QLabTransitionTableWgt", "y2 = Q2", nullptr));
        label_4->setText(QApplication::translate("QLabTransitionTableWgt", "y3 = Q3", nullptr));
        label_5->setText(QApplication::translate("QLabTransitionTableWgt", "X = 0     ", nullptr));
        labelZero->setText(QApplication::translate("QLabTransitionTableWgt", "", nullptr));
        label_7->setText(QApplication::translate("QLabTransitionTableWgt", "X = 1     ", nullptr));
        labelOne->setText(QApplication::translate("QLabTransitionTableWgt", "", nullptr));
        label->setText(QApplication::translate("QLabTransitionTableWgt", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\321\213\321\205\320\276\320\264\320\275\321\213\320\265 \321\201\320\270\320\263\320\275\320\260\320\273\321\213 \320\262 \320\262\320\270\320\264\320\265:   -   y1    y2   y1,y2  y3,  y3,y1    y2, y3    y1,y2,y3 (Любой порядок, с пробелами или без)", nullptr));
        label_6->setText(QApplication::translate("QLabTransitionTableWgt", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\265\320\265 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\262 \320\262\320\270\320\264\320\265:    a0   a1   a2   a3   a4   a5   a6   a7", nullptr));
        pushButtonCheck->setText(QApplication::translate("QLabTransitionTableWgt", "&\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLabTransitionTableWgt: public Ui_QLabTransitionTableWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABTRANSITIONTABLEWGT_H
