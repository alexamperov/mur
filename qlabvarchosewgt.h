#ifndef QLABVARCHOSEWGT_H
#define QLABVARCHOSEWGT_H

#include <QWidget>
#include <QTextBrowser>
#include <QFontMetrics>
#include <QMessageBox>
#include <QMouseEvent>

#include "qlabdatabase.h"
#include "qfileworker.h"
#include "qlabstructuretablewgt.h"

namespace Ui {
class QLabVarChoseWgt;
}

class QVarPreviewWgt : public QTextBrowser
{
	Q_OBJECT

    public:
        explicit QVarPreviewWgt(QWidget *parent = 0);

    public slots:
        void setVarPreview(QString text, bool edit);
};

class QLabVarChoseWgt : public QWidget
{
    Q_OBJECT

    public:
        explicit QLabVarChoseWgt(QWidget *parent = 0);
        void connectModules(QLabDataBase *db);
        void saveData(QFileWorker* stream);
        void openData(QFileWorker* stream);
        bool isOK();
        ~QLabVarChoseWgt();
        QVector<QString> vecTrigger;
        QVector<QString> vecBasis;

    signals:
        void varChanged(QObject*);
        void dataEdited();

    public slots:
        void showErrMsg();

    private slots:
        void on_pushButtonChoseVar_clicked();

    private:
        Ui::QLabVarChoseWgt *ui;
        Ui::QLabStructureTableWgt *ui1;
        QLabDataBase *currentDB;
        QObject *currentVar;
        int currentVarNum = 0;
    };

#endif // QLABVARCHOSEWGT_H
