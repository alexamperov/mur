/********************************************************************************
** Form generated from reading UI file 'qwelcomewgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWELCOMEWGT_H
#define UI_QWELCOMEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWelcomeWgt
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelAppVersion;
    QLabel *labelDBVersion;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonOpen;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *QWelcomeWgt)
    {
        if (QWelcomeWgt->objectName().isEmpty())
            QWelcomeWgt->setObjectName(QString::fromUtf8("QWelcomeWgt"));
        QWelcomeWgt->resize(640, 232);
        QWelcomeWgt->setMinimumSize(QSize(640, 232));
        horizontalLayout = new QHBoxLayout(QWelcomeWgt);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(QWelcomeWgt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        label_4 = new QLabel(QWelcomeWgt);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(QWelcomeWgt);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(QWelcomeWgt);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelAppVersion = new QLabel(QWelcomeWgt);
        labelAppVersion->setObjectName(QString::fromUtf8("labelAppVersion"));
        labelAppVersion->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelAppVersion);

        labelDBVersion = new QLabel(QWelcomeWgt);
        labelDBVersion->setObjectName(QString::fromUtf8("labelDBVersion"));
        labelDBVersion->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelDBVersion);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonNew = new QPushButton(QWelcomeWgt);
        pushButtonNew->setObjectName(QString::fromUtf8("pushButtonNew"));

        horizontalLayout_3->addWidget(pushButtonNew);

        pushButtonOpen = new QPushButton(QWelcomeWgt);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));

        horizontalLayout_3->addWidget(pushButtonOpen);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(QWelcomeWgt);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(150, 150));
        graphicsView->setMaximumSize(QSize(150, 150));
        graphicsView->setSizeIncrement(QSize(0, 0));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/images/logo_ikit.png);"));

        horizontalLayout_2->addWidget(graphicsView);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(QWelcomeWgt);

        QMetaObject::connectSlotsByName(QWelcomeWgt);
    } // setupUi

    void retranslateUi(QWidget *QWelcomeWgt)
    {
        QWelcomeWgt->setWindowTitle(QApplication::translate("QWelcomeWgt", "Form", nullptr));
        label->setText("Проектирование автомата Мура (Двоичный синхронный реверсивный счётчик)");
        label_2->setText(QApplication::translate("QWelcomeWgt", "\320\222\320\265\321\200\321\201\320\270\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213:", nullptr));
        label_3->setText(QApplication::translate("QWelcomeWgt", "\320\222\320\265\321\200\321\201\320\270\321\217 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205: ", nullptr));
        labelAppVersion->setText(QApplication::translate("QWelcomeWgt", "2025", nullptr));
        labelDBVersion->setText(QApplication::translate("QWelcomeWgt", "DB_VERSION", nullptr));
        pushButtonNew->setText(QApplication::translate("QWelcomeWgt", "&\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButtonOpen->setText(QApplication::translate("QWelcomeWgt", "&\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWelcomeWgt: public Ui_QWelcomeWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWELCOMEWGT_H
