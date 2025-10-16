/********************************************************************************
** Form generated from reading UI file 'qtermedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTERMEDIT_H
#define UI_QTERMEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtermedit.h"

QT_BEGIN_NAMESPACE

class Ui_QTermEdit
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QTermItmWgt *textBrowser1X1;
    QTermItmWgt *textBrowser1X2;
    QTermItmWgt *textBrowser1X3;
    QTermItmWgt *textBrowser1X4;
    QHBoxLayout *horizontalLayout_3;
    QTermItmWgt *textBrowser0X1;
    QTermItmWgt *textBrowser0X2;
    QTermItmWgt *textBrowser0X3;
    QTermItmWgt *textBrowser0X4;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QTermItmWgt *textBrowserDF;
    QTermItmWgt *textBrowserKF;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *QTermEdit)
    {
        if (QTermEdit->objectName().isEmpty())
            QTermEdit->setObjectName(QString::fromUtf8("QTermEdit"));
        QTermEdit->resize(532, 198);
        horizontalLayout = new QHBoxLayout(QTermEdit);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        textBrowser1X1 = new QTermItmWgt(QTermEdit);
        textBrowser1X1->setObjectName(QString::fromUtf8("textBrowser1X1"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        textBrowser1X1->setFont(font);
        textBrowser1X1->setFrameShape(QFrame::Panel);
        textBrowser1X1->setFrameShadow(QFrame::Plain);

        horizontalLayout_4->addWidget(textBrowser1X1);

        textBrowser1X2 = new QTermItmWgt(QTermEdit);
        textBrowser1X2->setObjectName(QString::fromUtf8("textBrowser1X2"));
        textBrowser1X2->setFont(font);
        textBrowser1X2->setFrameShape(QFrame::Panel);
        textBrowser1X2->setFrameShadow(QFrame::Plain);

        horizontalLayout_4->addWidget(textBrowser1X2);

        textBrowser1X3 = new QTermItmWgt(QTermEdit);
        textBrowser1X3->setObjectName(QString::fromUtf8("textBrowser1X3"));
        textBrowser1X3->setFont(font);
        textBrowser1X3->setFrameShape(QFrame::Panel);
        textBrowser1X3->setFrameShadow(QFrame::Plain);

        horizontalLayout_4->addWidget(textBrowser1X3);

        textBrowser1X4 = new QTermItmWgt(QTermEdit);
        textBrowser1X4->setObjectName(QString::fromUtf8("textBrowser1X4"));
        textBrowser1X4->setFont(font);
        textBrowser1X4->setFrameShape(QFrame::Panel);
        textBrowser1X4->setFrameShadow(QFrame::Plain);

        horizontalLayout_4->addWidget(textBrowser1X4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textBrowser0X1 = new QTermItmWgt(QTermEdit);
        textBrowser0X1->setObjectName(QString::fromUtf8("textBrowser0X1"));
        textBrowser0X1->setFont(font);
        textBrowser0X1->setFrameShape(QFrame::Panel);
        textBrowser0X1->setFrameShadow(QFrame::Plain);

        horizontalLayout_3->addWidget(textBrowser0X1);

        textBrowser0X2 = new QTermItmWgt(QTermEdit);
        textBrowser0X2->setObjectName(QString::fromUtf8("textBrowser0X2"));
        textBrowser0X2->setFont(font);
        textBrowser0X2->setFrameShape(QFrame::Panel);
        textBrowser0X2->setFrameShadow(QFrame::Plain);

        horizontalLayout_3->addWidget(textBrowser0X2);

        textBrowser0X3 = new QTermItmWgt(QTermEdit);
        textBrowser0X3->setObjectName(QString::fromUtf8("textBrowser0X3"));
        textBrowser0X3->setFont(font);
        textBrowser0X3->setFrameShape(QFrame::Panel);
        textBrowser0X3->setFrameShadow(QFrame::Plain);

        horizontalLayout_3->addWidget(textBrowser0X3);

        textBrowser0X4 = new QTermItmWgt(QTermEdit);
        textBrowser0X4->setObjectName(QString::fromUtf8("textBrowser0X4"));
        textBrowser0X4->setFont(font);
        textBrowser0X4->setFrameShape(QFrame::Panel);
        textBrowser0X4->setFrameShadow(QFrame::Plain);

        horizontalLayout_3->addWidget(textBrowser0X4);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        label = new QLabel(QTermEdit);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textBrowserDF = new QTermItmWgt(QTermEdit);
        textBrowserDF->setObjectName(QString::fromUtf8("textBrowserDF"));
        textBrowserDF->setFont(font);
        textBrowserDF->setFrameShape(QFrame::Panel);
        textBrowserDF->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(textBrowserDF);

        textBrowserKF = new QTermItmWgt(QTermEdit);
        textBrowserKF->setObjectName(QString::fromUtf8("textBrowserKF"));
        textBrowserKF->setFont(font);
        textBrowserKF->setFrameShape(QFrame::Panel);
        textBrowserKF->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(textBrowserKF);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(QTermEdit);

        QMetaObject::connectSlotsByName(QTermEdit);
    } // setupUi

    void retranslateUi(QWidget *QTermEdit)
    {
        QTermEdit->setWindowTitle(QApplication::translate("QTermEdit", "Form", nullptr));
        textBrowser1X1->setHtml(QApplication::translate("QTermEdit", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Terminus (TTF)'; font-weight:456;\"><br /></p></body></html>", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QTermEdit: public Ui_QTermEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTERMEDIT_H
