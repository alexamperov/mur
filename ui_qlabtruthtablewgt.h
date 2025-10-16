/********************************************************************************
** Form generated from reading UI file 'qlabtruthtablewgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABTRUTHTABLEWGT_H
#define UI_QLABTRUTHTABLEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qindwgt.h"
#include "qlabstatustablewgt.h"

QT_BEGIN_NAMESPACE

class Ui_QLabTruthTableWgt
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QTruthTableWgt *tableWidgetTruthTable;
    QIndWgt *wgtIndicator;
    QCheckBox *checkBoxAdoptWidth;
    QPushButton *pushButtonCheck;

    void setupUi(QWidget *QLabTruthTableWgt)
    {
        if (QLabTruthTableWgt->objectName().isEmpty())
            QLabTruthTableWgt->setObjectName(QString::fromUtf8("QLabTruthTableWgt"));
        QLabTruthTableWgt->resize(454, 300);
        verticalLayout = new QVBoxLayout(QLabTruthTableWgt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(QLabTruthTableWgt);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidgetTruthTable = new QTruthTableWgt(QLabTruthTableWgt);
        tableWidgetTruthTable->setObjectName(QString::fromUtf8("tableWidgetTruthTable"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        tableWidgetTruthTable->setFont(font);
        tableWidgetTruthTable->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 255, 0);"));
        tableWidgetTruthTable->setFrameShadow(QFrame::Plain);
        tableWidgetTruthTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetTruthTable->setAlternatingRowColors(true);
        tableWidgetTruthTable->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetTruthTable->horizontalHeader()->setVisible(false);
        tableWidgetTruthTable->verticalHeader()->setVisible(false);
        tableWidgetTruthTable->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(tableWidgetTruthTable);

        wgtIndicator = new QIndWgt(QLabTruthTableWgt);
        wgtIndicator->setObjectName(QString::fromUtf8("wgtIndicator"));

        horizontalLayout->addWidget(wgtIndicator);


        verticalLayout_2->addLayout(horizontalLayout);

        checkBoxAdoptWidth = new QCheckBox(QLabTruthTableWgt);
        checkBoxAdoptWidth->setObjectName(QString::fromUtf8("checkBoxAdoptWidth"));

        verticalLayout_2->addWidget(checkBoxAdoptWidth);

        pushButtonCheck = new QPushButton(QLabTruthTableWgt);
        pushButtonCheck->setObjectName(QString::fromUtf8("pushButtonCheck"));

        verticalLayout_2->addWidget(pushButtonCheck);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(QLabTruthTableWgt);

        QMetaObject::connectSlotsByName(QLabTruthTableWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabTruthTableWgt)
    {
        QLabTruthTableWgt->setWindowTitle(QApplication::translate("QLabTruthTableWgt", "Form", nullptr));
        label->setText(QApplication::translate("QLabTruthTableWgt", "\320\224\320\273\321\217 \320\277\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\271 \321\217\321\207\320\265\320\265\320\272 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265: \"\320\233\320\232\320\234\" (\320\264\320\262\320\260\320\266\320\264\321\213), \"\320\237\321\200\320\276\320\261\320\265\320\273\" \320\270\320\273\320\270 \"\320\222\320\262\320\276\320\264\"", nullptr));
        checkBoxAdoptWidth->setText(QApplication::translate("QLabTruthTableWgt", "\320\220\320\264\320\260\320\277\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\210\320\270\321\200\320\270\320\275\321\203 \320\272\320\276\320\273\320\276\320\275\320\276\320\272 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 \320\277\320\276\320\264 \321\200\320\260\320\267\320\274\320\265\321\200 \320\276\320\272\320\275\320\260", nullptr));
        pushButtonCheck->setText(QApplication::translate("QLabTruthTableWgt", "&\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLabTruthTableWgt: public Ui_QLabTruthTableWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABTRUTHTABLEWGT_H
