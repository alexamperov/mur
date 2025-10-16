/********************************************************************************
** Form generated from reading UI file 'qlabstructuretablewgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABSTRUCTURETABLEWGT_H
#define UI_QLABSTRUCTURETABLEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qlabstructuretablewgt.h"

QT_BEGIN_NAMESPACE

class Ui_QLabStructureTableWgt
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *labelZero;
    QLabel *label_7;
    QLabel *labelOne;
    QStructureTableWgt *tableWidgetStructureTable;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButtonCheck;

    void setupUi(QWidget *QLabStructureTableWgt)
    {
        if (QLabStructureTableWgt->objectName().isEmpty())
            QLabStructureTableWgt->setObjectName(QString::fromUtf8("QLabStructureTableWgt"));
        QLabStructureTableWgt->resize(669, 385);
        verticalLayout_2 = new QVBoxLayout(QLabStructureTableWgt);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(QLabStructureTableWgt);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        labelZero = new QLabel(QLabStructureTableWgt);
        labelZero->setObjectName(QString::fromUtf8("labelZero"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelZero);

        label_7 = new QLabel(QLabStructureTableWgt);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        labelOne = new QLabel(QLabStructureTableWgt);
        labelOne->setObjectName(QString::fromUtf8("labelOne"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelOne);


        horizontalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidgetStructureTable = new QStructureTableWgt(QLabStructureTableWgt);
        tableWidgetStructureTable->setObjectName(QString::fromUtf8("tableWidgetStructureTable"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        tableWidgetStructureTable->setFont(font);
        tableWidgetStructureTable->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 255, 0);"));
        tableWidgetStructureTable->setFrameShadow(QFrame::Plain);
        tableWidgetStructureTable->setAlternatingRowColors(true);
        tableWidgetStructureTable->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetStructureTable->horizontalHeader()->setVisible(false);
        tableWidgetStructureTable->verticalHeader()->setVisible(false);
        tableWidgetStructureTable->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tableWidgetStructureTable);

        label = new QLabel(QLabStructureTableWgt);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(QLabStructureTableWgt);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        pushButtonCheck = new QPushButton(QLabStructureTableWgt);
        pushButtonCheck->setObjectName(QString::fromUtf8("pushButtonCheck"));

        verticalLayout_2->addWidget(pushButtonCheck);


        retranslateUi(QLabStructureTableWgt);

        QMetaObject::connectSlotsByName(QLabStructureTableWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabStructureTableWgt)
    {
        QLabStructureTableWgt->setWindowTitle(QApplication::translate("QLabStructureTableWgt", "Form", nullptr));
        label_5->setText(QApplication::translate("QLabStructureTableWgt", "X = 0          ", nullptr));
        labelZero->setText(QApplication::translate("QLabStructureTableWgt", " ", nullptr));
        label_7->setText(QApplication::translate("QLabStructureTableWgt", "X = 1", nullptr));
        labelOne->setText(QApplication::translate("QLabStructureTableWgt", " ", nullptr));
        label->setText(QApplication::translate("QLabStructureTableWgt", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\265 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\262 \320\262\320\270\320\264\320\265  0;  1;  2;  3;  4;  5;  6;  7", nullptr));
        label_2->setText(QApplication::translate("QLabStructureTableWgt", "\320\224\320\273\321\217 \320\277\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\271 \321\217\321\207\320\265\320\265\320\272 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265: \"\320\233\320\232\320\234\" (\320\264\320\262\320\260\320\266\320\264\321\213), \"\320\237\321\200\320\276\320\261\320\265\320\273\" \320\270\320\273\320\270 \"\320\222\320\262\320\276\320\264\"", nullptr));
        pushButtonCheck->setText(QApplication::translate("QLabStructureTableWgt", "&\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLabStructureTableWgt: public Ui_QLabStructureTableWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABSTRUCTURETABLEWGT_H
