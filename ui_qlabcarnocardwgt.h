/********************************************************************************
** Form generated from reading UI file 'qlabcarnocardwgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABCARNOCARDWGT_H
#define UI_QLABCARNOCARDWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qbasisedit.h"
#include "qlabcarnocardwgt.h"
#include "qtermedit.h"

QT_BEGIN_NAMESPACE

class Ui_QLabCarnoCardWgt
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBoxFuncPreview;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidgetFuncPreview;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QCarnoCardWgt *tableWidgetCardCarno;
    QLabel *label;
    QPushButton *pushButtonCardCheck;
    QGroupBox *groupBoxTermsLst;
    QVBoxLayout *verticalLayout_4;
    QTermsListWgt *tableWidgetTermsLst;
    QHBoxLayout *horizontalLayout_4;
    QTermEdit *widgetTermEdit;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButtonAddTerm;
    QPushButton *pushButtonDelTerm;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBoxResult;
    QHBoxLayout *horizontalLayout_3;
    QCarnoTextWgt *textBrowserResult;
    QPushButton *pushButtonCheckResult;
    QGroupBox *groupBoxBasisEdit;
    QHBoxLayout *horizontalLayout_5;
    QBasisEdit *widgetBasisEdit;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButtonCheckBasis;

    void setupUi(QWidget *QLabCarnoCardWgt)
    {
        if (QLabCarnoCardWgt->objectName().isEmpty())
            QLabCarnoCardWgt->setObjectName(QString::fromUtf8("QLabCarnoCardWgt"));
        QLabCarnoCardWgt->resize(710, 467);
        verticalLayout = new QVBoxLayout(QLabCarnoCardWgt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBoxFuncPreview = new QGroupBox(QLabCarnoCardWgt);
        groupBoxFuncPreview->setObjectName(QString::fromUtf8("groupBoxFuncPreview"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBoxFuncPreview->sizePolicy().hasHeightForWidth());
        groupBoxFuncPreview->setSizePolicy(sizePolicy);
        groupBoxFuncPreview->setSizeIncrement(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(groupBoxFuncPreview);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        tableWidgetFuncPreview = new QTableWidget(groupBoxFuncPreview);
        tableWidgetFuncPreview->setObjectName(QString::fromUtf8("tableWidgetFuncPreview"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        tableWidgetFuncPreview->setFont(font);
        tableWidgetFuncPreview->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);"));
        tableWidgetFuncPreview->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetFuncPreview->setAlternatingRowColors(true);
        tableWidgetFuncPreview->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetFuncPreview->horizontalHeader()->setVisible(false);
        tableWidgetFuncPreview->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableWidgetFuncPreview);


        horizontalLayout->addWidget(groupBoxFuncPreview);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox_3 = new QGroupBox(QLabCarnoCardWgt);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        tableWidgetCardCarno = new QCarnoCardWgt(groupBox_3);
        tableWidgetCardCarno->setObjectName(QString::fromUtf8("tableWidgetCardCarno"));
        tableWidgetCardCarno->setFont(font);
        tableWidgetCardCarno->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(0, 255, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);"));
        tableWidgetCardCarno->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetCardCarno->horizontalHeader()->setVisible(false);
        tableWidgetCardCarno->verticalHeader()->setVisible(false);

        horizontalLayout_7->addWidget(tableWidgetCardCarno);


        verticalLayout_6->addLayout(horizontalLayout_7);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        pushButtonCardCheck = new QPushButton(groupBox_3);
        pushButtonCardCheck->setObjectName(QString::fromUtf8("pushButtonCardCheck"));

        verticalLayout_6->addWidget(pushButtonCardCheck);


        horizontalLayout_2->addWidget(groupBox_3);

        groupBoxTermsLst = new QGroupBox(QLabCarnoCardWgt);
        groupBoxTermsLst->setObjectName(QString::fromUtf8("groupBoxTermsLst"));
        verticalLayout_4 = new QVBoxLayout(groupBoxTermsLst);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        tableWidgetTermsLst = new QTermsListWgt(groupBoxTermsLst);
        tableWidgetTermsLst->setObjectName(QString::fromUtf8("tableWidgetTermsLst"));
        tableWidgetTermsLst->setFont(font);
        tableWidgetTermsLst->setStyleSheet(QString::fromUtf8("selection-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 255, 0);"));
        tableWidgetTermsLst->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetTermsLst->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetTermsLst->horizontalHeader()->setVisible(false);
        tableWidgetTermsLst->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(tableWidgetTermsLst);


        horizontalLayout_2->addWidget(groupBoxTermsLst);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widgetTermEdit = new QTermEdit(QLabCarnoCardWgt);
        widgetTermEdit->setObjectName(QString::fromUtf8("widgetTermEdit"));

        horizontalLayout_4->addWidget(widgetTermEdit);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        pushButtonAddTerm = new QPushButton(QLabCarnoCardWgt);
        pushButtonAddTerm->setObjectName(QString::fromUtf8("pushButtonAddTerm"));

        verticalLayout_9->addWidget(pushButtonAddTerm);

        pushButtonDelTerm = new QPushButton(QLabCarnoCardWgt);
        pushButtonDelTerm->setObjectName(QString::fromUtf8("pushButtonDelTerm"));

        verticalLayout_9->addWidget(pushButtonDelTerm);


        horizontalLayout_4->addLayout(verticalLayout_9);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 0, -1, 0);
        groupBoxResult = new QGroupBox(QLabCarnoCardWgt);
        groupBoxResult->setObjectName(QString::fromUtf8("groupBoxResult"));
        horizontalLayout_3 = new QHBoxLayout(groupBoxResult);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 6, 6, 6);
        textBrowserResult = new QCarnoTextWgt(groupBoxResult);
        textBrowserResult->setObjectName(QString::fromUtf8("textBrowserResult"));
        textBrowserResult->setFont(font);
        textBrowserResult->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        textBrowserResult->setFrameShape(QFrame::Panel);
        textBrowserResult->setFrameShadow(QFrame::Plain);

        horizontalLayout_3->addWidget(textBrowserResult);

        pushButtonCheckResult = new QPushButton(groupBoxResult);
        pushButtonCheckResult->setObjectName(QString::fromUtf8("pushButtonCheckResult"));

        horizontalLayout_3->addWidget(pushButtonCheckResult);


        verticalLayout_7->addWidget(groupBoxResult);


        verticalLayout_3->addLayout(verticalLayout_7);

        groupBoxBasisEdit = new QGroupBox(QLabCarnoCardWgt);
        groupBoxBasisEdit->setObjectName(QString::fromUtf8("groupBoxBasisEdit"));
        horizontalLayout_5 = new QHBoxLayout(groupBoxBasisEdit);
        horizontalLayout_5->setSpacing(9);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(9, 6, 9, 6);
        widgetBasisEdit = new QBasisEdit(groupBoxBasisEdit);
        widgetBasisEdit->setObjectName(QString::fromUtf8("widgetBasisEdit"));
        verticalLayout_5 = new QVBoxLayout(widgetBasisEdit);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        horizontalLayout_5->addWidget(widgetBasisEdit);

        pushButtonCheckBasis = new QPushButton(groupBoxBasisEdit);
        pushButtonCheckBasis->setObjectName(QString::fromUtf8("pushButtonCheckBasis"));

        horizontalLayout_5->addWidget(pushButtonCheckBasis);


        verticalLayout_3->addWidget(groupBoxBasisEdit);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QLabCarnoCardWgt);

        QMetaObject::connectSlotsByName(QLabCarnoCardWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabCarnoCardWgt)
    {
        QLabCarnoCardWgt->setWindowTitle(QApplication::translate("QLabCarnoCardWgt", "Form", nullptr));
        groupBoxFuncPreview->setTitle(QApplication::translate("QLabCarnoCardWgt", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        groupBox_3->setTitle(QApplication::translate("QLabCarnoCardWgt", "\320\232\320\260\321\200\321\202\320\260", nullptr));
        label->setText(QApplication::translate("QLabCarnoCardWgt", "\320\224\320\273\321\217 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \321\201\320\272\320\273\320\265\320\270\320\262\320\260\320\275\320\270\321\217 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265: \"Ctrl+\320\233\320\232\320\234\"", nullptr));
        pushButtonCardCheck->setText(QApplication::translate("QLabCarnoCardWgt", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
        groupBoxTermsLst->setTitle(QApplication::translate("QLabCarnoCardWgt", "\320\242\320\265\321\200\320\274\321\213", nullptr));
        pushButtonAddTerm->setText(QApplication::translate("QLabCarnoCardWgt", "&\320\222\320\262\320\265\321\201\321\202\320\270 \321\202\320\265\321\200\320\274", nullptr));
        pushButtonDelTerm->setText(QApplication::translate("QLabCarnoCardWgt", "&\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\265\321\200\320\274", nullptr));
        groupBoxResult->setTitle(QApplication::translate("QLabCarnoCardWgt", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\262 \320\261\320\260\320\267\320\270\321\201\320\265 \"\320\221\321\203\320\273\321\217\"", nullptr));
        pushButtonCheckResult->setText(QApplication::translate("QLabCarnoCardWgt", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
        groupBoxBasisEdit->setTitle(QApplication::translate("QLabCarnoCardWgt", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \320\262 \320\261\320\260\320\267\320\270\321\201 \"\320\237\320\270\321\200\321\201\320\260\" \320\270\320\273\320\270 \"\320\250\320\265\321\204\321\204\320\265\321\200\320\260\"", nullptr));
        pushButtonCheckBasis->setText(QApplication::translate("QLabCarnoCardWgt", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLabCarnoCardWgt: public Ui_QLabCarnoCardWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABCARNOCARDWGT_H
