#ifndef QLABSTATUSTABLEWGT_H
#define QLABSTATUSTABLEWGT_H

#include <QWidget>
#include <QTableWidget>
#include <QTextBrowser>
#include <QResizeEvent>
#include <QScrollBar>
#include <QMessageBox>

#include "qlabdatabase.h"
#include "qfileworker.h"

#include "qindwgt.h"

namespace Ui {
class QLabStatusTableWgt;
}

class QStatusTableHeaderWgt : public QTextBrowser
{
    Q_OBJECT

    public:
        explicit QStatusTableHeaderWgt(QWidget *parent = 0) : QTextBrowser(parent) {}

    public slots:
        void setHeaderText(QString text);

    protected:
        void keyPressEvent(QKeyEvent *e) {e->accept();}
        void mouseDoubleClickEvent(QMouseEvent *e) {e->accept();}
        void mouseMoveEvent(QMouseEvent *e) {e->accept();}
        void mousePressEvent(QMouseEvent *e) {e->accept();}
};

class QStatusTableWgt : public QTableWidget
{
    Q_OBJECT

    private:
        QString currentVar;
        QVector<QString> currentSymbols;
        bool isTested = false;
        bool testResult = false;
        int lastRow = 0;

    signals:
        void symbolChanged(QString);
        void funcChanged(int, QString);
        void funcsIsValid();
        void dataEdited();


    public:
        explicit QStatusTableWgt(QWidget *parent = 0);
        bool isOK();
        // LEGACY
        //bool checkCells(const QVector<QVector<int>> &cells, const QVector<QString> &expectedValues);
        void saveData(QFileWorker* stream);
        void openData(QFileWorker* stream);
        void fillTable();
        bool updateStateCodesFromTable(const QVector<QVector<int>> &cells);
        QVector<QVector<int>> getAllCodeCells();
    protected:
        QString getDBSymbol(QString sym);
        QString getTableSymbol(int row);
        void resizeEvent(QResizeEvent *event);
        void keyPressEvent(QKeyEvent *event);
        void toggleTableItem(int row, int column);
        void deleteTableItem(int row, int column);

    private:
        QIndWgt *currentIndicator;
        bool adoptOptionState = 0;
        void adoptColumnsWidth();
        Ui::QLabStatusTableWgt *ui;

    protected slots:
        void sendCurrentSymbol();
        void sendFunc(int num);
        void itemKeyPressed(QKeyEvent* event);
        void clickedTableItem(QTableWidgetItem* item);

    public slots:
    //    void adoptOptionToggled(bool state);
        void setVar(QObject* obj);
        void setSymbols(QVector<QString> symbols);
};

class QLabStatusTableWgt : public QWidget
{
    Q_OBJECT

    signals:
        void setVar(QObject*);
        void funcChanged(int, QString);
        void funcsIsValid();
        void dataEdited();

    public:
        explicit QLabStatusTableWgt(QWidget *parent = 0);
        void connectModules(QLabDataBase* db);
        void saveData(QFileWorker* stream);
        void openData(QFileWorker* stream);
        bool isOK();
        ~QLabStatusTableWgt();

    private slots:
        void on_pushButtonCheck_clicked();

        void on_pushButtonCheck_3_clicked();

    protected slots:
        void showErrMsg(int errCode);
        void showErrMsgStatusAndTrigger(int errCode);

    public slots:
        void showErrMsg();
        void setLabels(QObject* obj);

    private:
        Ui::QLabStatusTableWgt *ui;
        QLabDataBase* currentDB;
        QStatusTableWgt *statusTable;
};

#endif // QLABSTATUSTABLEWGT_H
