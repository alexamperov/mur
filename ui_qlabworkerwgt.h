/********************************************************************************
** Form generated from reading UI file 'qlabworkerwgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABWORKERWGT_H
#define UI_QLABWORKERWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qlabcarnocardwgt.h"
#include "qlabreportwgt.h"
#include "qlabstatustablewgt.h"
#include "qlabstructuretablewgt.h"
#include "qlabtransitiontablewgt.h"
#include "qlabvarchosewgt.h"
#include "qlabworkerwgt.h"

QT_BEGIN_NAMESPACE

class Ui_QLabWorkerWgt
{
public:
    QVBoxLayout *verticalLayout;
    QLabTabWgt *tabWidget;
    QWidget *tabLabChose;
    QVBoxLayout *verticalLayout_2;
    QLabVarChoseWgt *wgtLabChose;
    QWidget *tabStatusTable;
    QGridLayout *gridLayout;
    QLabStatusTableWgt *wgtStatusTable;
    QWidget *tabTransitionTable;
    QVBoxLayout *verticalLayout_4;
    QLabTransitionTableWgt *wgtTransitionTable;
    QWidget *tabStructureTable;
    QHBoxLayout *horizontalLayout_2;
    QLabStructureTableWgt *wgtStructureTable;
    QWidget *tabCarnoCard3;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget_2;
    QLabCarnoCardWgt *tab;
    QLabCarnoCardWgt *tab_2;
    QLabCarnoCardWgt *tab_9;
    QLabCarnoCardWgt *tab_8;
    QLabCarnoCardWgt *tab_7;
    QLabCarnoCardWgt *tab_3;
    QWidget *tabReport;
    QVBoxLayout *verticalLayout_6;
    QLabReportWgt *wgtReport;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonNext;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *QLabWorkerWgt)
    {
        if (QLabWorkerWgt->objectName().isEmpty())
            QLabWorkerWgt->setObjectName(QString::fromUtf8("QLabWorkerWgt"));
        QLabWorkerWgt->resize(700, 550);
        QLabWorkerWgt->setMinimumSize(QSize(700, 550));
        verticalLayout = new QVBoxLayout(QLabWorkerWgt);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QLabTabWgt(QLabWorkerWgt);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabLabChose = new QWidget();
        tabLabChose->setObjectName(QString::fromUtf8("tabLabChose"));
        verticalLayout_2 = new QVBoxLayout(tabLabChose);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        wgtLabChose = new QLabVarChoseWgt(tabLabChose);
        wgtLabChose->setObjectName(QString::fromUtf8("wgtLabChose"));

        verticalLayout_2->addWidget(wgtLabChose);

        tabWidget->addTab(tabLabChose, QString());
        tabStatusTable = new QWidget();
        tabStatusTable->setObjectName(QString::fromUtf8("tabStatusTable"));
        gridLayout = new QGridLayout(tabStatusTable);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        wgtStatusTable = new QLabStatusTableWgt(tabStatusTable);
        wgtStatusTable->setObjectName(QString::fromUtf8("wgtStatusTable"));

        gridLayout->addWidget(wgtStatusTable, 0, 0, 1, 1);

        tabWidget->addTab(tabStatusTable, QString());
        tabTransitionTable = new QWidget();
        tabTransitionTable->setObjectName(QString::fromUtf8("tabTransitionTable"));
        verticalLayout_4 = new QVBoxLayout(tabTransitionTable);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        wgtTransitionTable = new QLabTransitionTableWgt(tabTransitionTable);
        wgtTransitionTable->setObjectName(QString::fromUtf8("wgtTransitionTable"));

        verticalLayout_4->addWidget(wgtTransitionTable);

        tabWidget->addTab(tabTransitionTable, QString());
        tabStructureTable = new QWidget();
        tabStructureTable->setObjectName(QString::fromUtf8("tabStructureTable"));
        horizontalLayout_2 = new QHBoxLayout(tabStructureTable);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wgtStructureTable = new QLabStructureTableWgt(tabStructureTable);
        wgtStructureTable->setObjectName(QString::fromUtf8("wgtStructureTable"));

        horizontalLayout_2->addWidget(wgtStructureTable);

        tabWidget->addTab(tabStructureTable, QString());
        tabCarnoCard3 = new QWidget();
        tabCarnoCard3->setObjectName(QString::fromUtf8("tabCarnoCard3"));
        horizontalLayout_3 = new QHBoxLayout(tabCarnoCard3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tabWidget_2 = new QTabWidget(tabCarnoCard3);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        tab = new QLabCarnoCardWgt();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setEnabled(true);
        tabWidget_2->addTab(tab, QString());
        tab_2 = new QLabCarnoCardWgt();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(false);
        tabWidget_2->addTab(tab_2, QString());
        tab_9 = new QLabCarnoCardWgt();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        tab_9->setEnabled(false);
        tabWidget_2->addTab(tab_9, QString());
        tab_8 = new QLabCarnoCardWgt();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tab_8->setEnabled(false);
        tabWidget_2->addTab(tab_8, QString());
        tab_7 = new QLabCarnoCardWgt();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tab_7->setEnabled(false);
        tabWidget_2->addTab(tab_7, QString());
        tab_3 = new QLabCarnoCardWgt();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setEnabled(false);
        tabWidget_2->addTab(tab_3, QString());

        horizontalLayout_3->addWidget(tabWidget_2);

        tabWidget->addTab(tabCarnoCard3, QString());
        tabReport = new QWidget();
        tabReport->setObjectName(QString::fromUtf8("tabReport"));
        verticalLayout_6 = new QVBoxLayout(tabReport);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        wgtReport = new QLabReportWgt(tabReport);
        wgtReport->setObjectName(QString::fromUtf8("wgtReport"));

        verticalLayout_6->addWidget(wgtReport);

        tabWidget->addTab(tabReport, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonBack = new QPushButton(QLabWorkerWgt);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));

        horizontalLayout->addWidget(pushButtonBack);

        pushButtonSave = new QPushButton(QLabWorkerWgt);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout->addWidget(pushButtonSave);

        pushButtonNext = new QPushButton(QLabWorkerWgt);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));

        horizontalLayout->addWidget(pushButtonNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QLabWorkerWgt);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(QLabWorkerWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabWorkerWgt)
    {
        QLabWorkerWgt->setWindowTitle(QApplication::translate("QLabWorkerWgt", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabLabChose), QApplication::translate("QLabWorkerWgt", "\320\222\321\213\320\261\320\276\321\200 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatusTable), QApplication::translate("QLabWorkerWgt", "\320\232\320\276\320\264\320\270\321\200\320\276\320\262\320\272\320\260 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTransitionTable), QApplication::translate("QLabWorkerWgt", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\276\320\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStructureTable), QApplication::translate("QLabWorkerWgt", "\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\275\320\260\321\217 \321\202\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("QLabWorkerWgt", "J3", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("QLabWorkerWgt", "K3", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("QLabWorkerWgt", "J2", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("QLabWorkerWgt", "K2", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("QLabWorkerWgt", "J1", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("QLabWorkerWgt", "K1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCarnoCard3), QApplication::translate("QLabWorkerWgt", "\320\234\320\270\320\275\320\270\320\274\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabReport), QApplication::translate("QLabWorkerWgt", "\320\236\321\202\321\207\320\265\321\202", nullptr));
        pushButtonBack->setText(QApplication::translate("QLabWorkerWgt", "<- &\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButtonSave->setText(QApplication::translate("QLabWorkerWgt", "&\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButtonNext->setText(QApplication::translate("QLabWorkerWgt", "&\320\224\320\260\320\273\320\265\320\265 ->", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLabWorkerWgt: public Ui_QLabWorkerWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABWORKERWGT_H
