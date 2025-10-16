/********************************************************************************
** Form generated from reading UI file 'qlabvarchosewgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABVARCHOSEWGT_H
#define UI_QLABVARCHOSEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qlabvarchosewgt.h"

QT_BEGIN_NAMESPACE

class Ui_QLabVarChoseWgt
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayoutVarTxt;
    QLabel *labelVarTxt;
    QLabel *labelVarCnt;
    QHBoxLayout *horizontalLayoutVarChose;
    QLabel *label;
    QLineEdit *lineEditChosenVar;
    QPushButton *pushButtonChoseVar;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QVarPreviewWgt *textBrowserVarPreviewOne;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QVarPreviewWgt *textBrowserVarPreviewZero;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QVarPreviewWgt *textBrowserVarPreviewTrigger;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QVarPreviewWgt *textBrowserVarPreviewBasis;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *QLabVarChoseWgt)
    {
        if (QLabVarChoseWgt->objectName().isEmpty())
            QLabVarChoseWgt->setObjectName(QString::fromUtf8("QLabVarChoseWgt"));
        QLabVarChoseWgt->resize(640, 232);
        gridLayout_2 = new QGridLayout(QLabVarChoseWgt);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayoutVarTxt = new QHBoxLayout();
        horizontalLayoutVarTxt->setObjectName(QString::fromUtf8("horizontalLayoutVarTxt"));
        labelVarTxt = new QLabel(QLabVarChoseWgt);
        labelVarTxt->setObjectName(QString::fromUtf8("labelVarTxt"));

        horizontalLayoutVarTxt->addWidget(labelVarTxt);

        labelVarCnt = new QLabel(QLabVarChoseWgt);
        labelVarCnt->setObjectName(QString::fromUtf8("labelVarCnt"));

        horizontalLayoutVarTxt->addWidget(labelVarCnt);

        horizontalLayoutVarTxt->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayoutVarTxt, 0, 0, 1, 1);

        horizontalLayoutVarChose = new QHBoxLayout();
        horizontalLayoutVarChose->setObjectName(QString::fromUtf8("horizontalLayoutVarChose"));
        label = new QLabel(QLabVarChoseWgt);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayoutVarChose->addWidget(label);

        lineEditChosenVar = new QLineEdit(QLabVarChoseWgt);
        lineEditChosenVar->setObjectName(QString::fromUtf8("lineEditChosenVar"));
        lineEditChosenVar->setMaxLength(3);
        lineEditChosenVar->setFrame(true);
        lineEditChosenVar->setCursorPosition(0);

        horizontalLayoutVarChose->addWidget(lineEditChosenVar);

        pushButtonChoseVar = new QPushButton(QLabVarChoseWgt);
        pushButtonChoseVar->setObjectName(QString::fromUtf8("pushButtonChoseVar"));

        horizontalLayoutVarChose->addWidget(pushButtonChoseVar);


        gridLayout_2->addLayout(horizontalLayoutVarChose, 1, 0, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(QLabVarChoseWgt);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        textBrowserVarPreviewOne = new QVarPreviewWgt(QLabVarChoseWgt);
        textBrowserVarPreviewOne->setObjectName(QString::fromUtf8("textBrowserVarPreviewOne"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        textBrowserVarPreviewOne->setFont(font);
        textBrowserVarPreviewOne->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        textBrowserVarPreviewOne->setFrameShape(QFrame::Panel);
        textBrowserVarPreviewOne->setFrameShadow(QFrame::Plain);
        textBrowserVarPreviewOne->setOpenLinks(false);

        verticalLayout_2->addWidget(textBrowserVarPreviewOne);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(QLabVarChoseWgt);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        textBrowserVarPreviewZero = new QVarPreviewWgt(QLabVarChoseWgt);
        textBrowserVarPreviewZero->setObjectName(QString::fromUtf8("textBrowserVarPreviewZero"));
        textBrowserVarPreviewZero->setFont(font);
        textBrowserVarPreviewZero->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        textBrowserVarPreviewZero->setFrameShape(QFrame::Panel);
        textBrowserVarPreviewZero->setFrameShadow(QFrame::Plain);
        textBrowserVarPreviewZero->setOpenLinks(false);

        verticalLayout->addWidget(textBrowserVarPreviewZero);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(QLabVarChoseWgt);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        textBrowserVarPreviewTrigger = new QVarPreviewWgt(QLabVarChoseWgt);
        textBrowserVarPreviewTrigger->setObjectName(QString::fromUtf8("textBrowserVarPreviewTrigger"));
        textBrowserVarPreviewTrigger->setFont(font);
        textBrowserVarPreviewTrigger->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        textBrowserVarPreviewTrigger->setFrameShape(QFrame::Panel);
        textBrowserVarPreviewTrigger->setFrameShadow(QFrame::Plain);
        textBrowserVarPreviewTrigger->setOpenLinks(false);

        verticalLayout_3->addWidget(textBrowserVarPreviewTrigger);


        gridLayout->addLayout(verticalLayout_3, 0, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(QLabVarChoseWgt);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        textBrowserVarPreviewBasis = new QVarPreviewWgt(QLabVarChoseWgt);
        textBrowserVarPreviewBasis->setObjectName(QString::fromUtf8("textBrowserVarPreviewBasis"));
        textBrowserVarPreviewBasis->setFont(font);
        textBrowserVarPreviewBasis->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        textBrowserVarPreviewBasis->setFrameShape(QFrame::Panel);
        textBrowserVarPreviewBasis->setFrameShadow(QFrame::Plain);
        textBrowserVarPreviewBasis->setOpenLinks(false);

        verticalLayout_4->addWidget(textBrowserVarPreviewBasis);


        gridLayout->addLayout(verticalLayout_4, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(QLabVarChoseWgt);

        QMetaObject::connectSlotsByName(QLabVarChoseWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabVarChoseWgt)
    {
        QLabVarChoseWgt->setWindowTitle(QApplication::translate("QLabVarChoseWgt", "Form", nullptr));
        labelVarTxt->setText(QApplication::translate("QLabVarChoseWgt", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\276\320\262 \320\262 \320\261\320\260\320\267\320\265 \320\264\320\260\320\275\320\275\321\213\321\205:", nullptr));
        labelVarCnt->setText(QApplication::translate("QLabVarChoseWgt", "0", nullptr));
        label->setText(QApplication::translate("QLabVarChoseWgt", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\260:", nullptr));
        pushButtonChoseVar->setText(QApplication::translate("QLabVarChoseWgt", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("QLabVarChoseWgt", "X = 1", nullptr));
        label_2->setText(QApplication::translate("QLabVarChoseWgt", "X = 0", nullptr));
        label_4->setText(QApplication::translate("QLabVarChoseWgt", "\320\242\321\200\320\270\320\263\320\263\320\265\321\200", nullptr));
        label_5->setText(QApplication::translate("QLabVarChoseWgt", "\320\221\320\260\320\267\320\270\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLabVarChoseWgt: public Ui_QLabVarChoseWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABVARCHOSEWGT_H
