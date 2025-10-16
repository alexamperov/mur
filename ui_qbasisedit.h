/********************************************************************************
** Form generated from reading UI file 'qbasisedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QBASISEDIT_H
#define UI_QBASISEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qbasisedit.h"

QT_BEGIN_NAMESPACE

class Ui_QBasisEdit
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidgetFunc;
    QVBoxLayout *verticalLayout_4;
    QBasisTextWgt *textBrowserN;
    QHBoxLayout *horizontalLayout_7;
    QBasisTextWgt *textBrowserD;
    QBasisTextWgt *textBrowserK;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QBasisEdit)
    {
        if (QBasisEdit->objectName().isEmpty())
            QBasisEdit->setObjectName(QString::fromUtf8("QBasisEdit"));
        QBasisEdit->resize(584, 177);
        verticalLayout_2 = new QVBoxLayout(QBasisEdit);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidgetFunc = new QTableWidget(QBasisEdit);
        tableWidgetFunc->setObjectName(QString::fromUtf8("tableWidgetFunc"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        tableWidgetFunc->setFont(font);
        tableWidgetFunc->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 255, 0);"));
        tableWidgetFunc->setFrameShadow(QFrame::Plain);
        tableWidgetFunc->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetFunc->setTabKeyNavigation(false);
        tableWidgetFunc->setProperty("showDropIndicator", QVariant(false));
        tableWidgetFunc->setDragDropOverwriteMode(false);
        tableWidgetFunc->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetFunc->setShowGrid(false);
        tableWidgetFunc->setWordWrap(false);
        tableWidgetFunc->setCornerButtonEnabled(false);
        tableWidgetFunc->horizontalHeader()->setVisible(false);
        tableWidgetFunc->horizontalHeader()->setMinimumSectionSize(0);
        tableWidgetFunc->horizontalHeader()->setHighlightSections(false);
        tableWidgetFunc->verticalHeader()->setVisible(false);
        tableWidgetFunc->verticalHeader()->setMinimumSectionSize(0);
        tableWidgetFunc->verticalHeader()->setDefaultSectionSize(30);
        tableWidgetFunc->verticalHeader()->setHighlightSections(false);

        horizontalLayout_2->addWidget(tableWidgetFunc);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textBrowserN = new QBasisTextWgt(QBasisEdit);
        textBrowserN->setObjectName(QString::fromUtf8("textBrowserN"));
        textBrowserN->setFont(font);
        textBrowserN->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        textBrowserN->setFrameShape(QFrame::Panel);
        textBrowserN->setFrameShadow(QFrame::Plain);

        verticalLayout_4->addWidget(textBrowserN);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        textBrowserD = new QBasisTextWgt(QBasisEdit);
        textBrowserD->setObjectName(QString::fromUtf8("textBrowserD"));
        textBrowserD->setFont(font);
        textBrowserD->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        textBrowserD->setFrameShape(QFrame::Panel);
        textBrowserD->setFrameShadow(QFrame::Plain);

        horizontalLayout_7->addWidget(textBrowserD);

        textBrowserK = new QBasisTextWgt(QBasisEdit);
        textBrowserK->setObjectName(QString::fromUtf8("textBrowserK"));
        textBrowserK->setFont(font);
        textBrowserK->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        textBrowserK->setFrameShape(QFrame::Panel);
        textBrowserK->setFrameShadow(QFrame::Plain);

        horizontalLayout_7->addWidget(textBrowserK);


        verticalLayout_4->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_3 = new QLabel(QBasisEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3->setWordWrap(true);

        verticalLayout_2->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(QBasisEdit);

        QMetaObject::connectSlotsByName(QBasisEdit);
    } // setupUi

    void retranslateUi(QWidget *QBasisEdit)
    {
        QBasisEdit->setWindowTitle(QApplication::translate("QBasisEdit", "Form", nullptr));
        label_3->setText(QApplication::translate("QBasisEdit", "\320\224\320\273\321\217 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\276\320\264\320\275\320\276\320\271 \321\217\321\207\320\265\320\271\320\272\320\270 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265: \"\320\233\320\232\320\234\", \320\275\320\265\321\201\320\272\320\276\320\273\321\214\320\272\320\270\321\205: \"Ctrl+\320\233\320\232\320\234\", \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\260: \"Shift+\320\233\320\232\320\234\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QBasisEdit: public Ui_QBasisEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QBASISEDIT_H
