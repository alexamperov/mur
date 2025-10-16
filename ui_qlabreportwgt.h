/********************************************************************************
** Form generated from reading UI file 'qlabreportwgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLABREPORTWGT_H
#define UI_QLABREPORTWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QLabReportWgt
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxTeacher;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditTeacherFIO;
    QGroupBox *groupBoxStudent;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelStudentFIO;
    QLineEdit *lineEditStudentFIO;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelStudentGroup;
    QLineEdit *lineEditStudentGroup;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelStudentNum;
    QLineEdit *lineEditStudentNum;
    QPushButton *pushButtonExport;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QLabReportWgt)
    {
        if (QLabReportWgt->objectName().isEmpty())
            QLabReportWgt->setObjectName(QString::fromUtf8("QLabReportWgt"));
        QLabReportWgt->resize(494, 358);
        verticalLayout = new QVBoxLayout(QLabReportWgt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBoxTeacher = new QGroupBox(QLabReportWgt);
        groupBoxTeacher->setObjectName(QString::fromUtf8("groupBoxTeacher"));
        horizontalLayout = new QHBoxLayout(groupBoxTeacher);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBoxTeacher);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditTeacherFIO = new QLineEdit(groupBoxTeacher);
        lineEditTeacherFIO->setObjectName(QString::fromUtf8("lineEditTeacherFIO"));

        horizontalLayout->addWidget(lineEditTeacherFIO);


        verticalLayout->addWidget(groupBoxTeacher);

        groupBoxStudent = new QGroupBox(QLabReportWgt);
        groupBoxStudent->setObjectName(QString::fromUtf8("groupBoxStudent"));
        verticalLayout_2 = new QVBoxLayout(groupBoxStudent);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelStudentFIO = new QLabel(groupBoxStudent);
        labelStudentFIO->setObjectName(QString::fromUtf8("labelStudentFIO"));

        horizontalLayout_2->addWidget(labelStudentFIO);

        lineEditStudentFIO = new QLineEdit(groupBoxStudent);
        lineEditStudentFIO->setObjectName(QString::fromUtf8("lineEditStudentFIO"));

        horizontalLayout_2->addWidget(lineEditStudentFIO);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelStudentGroup = new QLabel(groupBoxStudent);
        labelStudentGroup->setObjectName(QString::fromUtf8("labelStudentGroup"));

        horizontalLayout_4->addWidget(labelStudentGroup);

        lineEditStudentGroup = new QLineEdit(groupBoxStudent);
        lineEditStudentGroup->setObjectName(QString::fromUtf8("lineEditStudentGroup"));

        horizontalLayout_4->addWidget(lineEditStudentGroup);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelStudentNum = new QLabel(groupBoxStudent);
        labelStudentNum->setObjectName(QString::fromUtf8("labelStudentNum"));

        horizontalLayout_3->addWidget(labelStudentNum);

        lineEditStudentNum = new QLineEdit(groupBoxStudent);
        lineEditStudentNum->setObjectName(QString::fromUtf8("lineEditStudentNum"));

        horizontalLayout_3->addWidget(lineEditStudentNum);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBoxStudent);

        pushButtonExport = new QPushButton(QLabReportWgt);
        pushButtonExport->setObjectName(QString::fromUtf8("pushButtonExport"));

        verticalLayout->addWidget(pushButtonExport);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(QLabReportWgt);

        QMetaObject::connectSlotsByName(QLabReportWgt);
    } // setupUi

    void retranslateUi(QWidget *QLabReportWgt)
    {
        QLabReportWgt->setWindowTitle(QApplication::translate("QLabReportWgt", "Form", nullptr));
        groupBoxTeacher->setTitle(QApplication::translate("QLabReportWgt", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        label->setText(QApplication::translate("QLabReportWgt", "\320\244\320\230\320\236:", nullptr));
        groupBoxStudent->setTitle(QApplication::translate("QLabReportWgt", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202", nullptr));
        labelStudentFIO->setText(QApplication::translate("QLabReportWgt", "\320\244\320\230\320\236:", nullptr));
        labelStudentGroup->setText(QApplication::translate("QLabReportWgt", "\320\223\321\200\321\203\320\277\320\277\320\260:", nullptr));
        labelStudentNum->setText(QApplication::translate("QLabReportWgt", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\321\207\321\221\321\202\320\275\320\276\320\271 \320\272\320\275\320\270\320\266\320\272\320\270:", nullptr));
        pushButtonExport->setText("Создать отчет");
    } // retranslateUi

};

namespace Ui {
    class QLabReportWgt: public Ui_QLabReportWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLABREPORTWGT_H
