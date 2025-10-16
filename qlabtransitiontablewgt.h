#ifndef QLABTRANSITIONTABLEWGT_H
#define QLABTRANSITIONTABLEWGT_H

#include <QWidget>
#include <QTableWidget>
#include <QTextBrowser>
#include <QResizeEvent>
#include <QScrollBar>
#include <QMessageBox>
#include <QLineEdit>
#include <QValidator>


#include "qlabdatabase.h"
#include "qfileworker.h"

#include "qindwgt.h"

namespace Ui {
    class QLabTransitionTableWgt;
}

class QTransitionTableHeaderWgt : public QTextBrowser
{
    Q_OBJECT

    public:
        explicit QTransitionTableHeaderWgt(QWidget *parent = 0) : QTextBrowser(parent) {}
         QString getHeaderText() const;

    public slots:
         void setHeaderText(const QString &text);

    private:
        QString headerText;
};

class QTransitionTableWgt : public QTableWidget
{
    Q_OBJECT

    private:
        QString currentVar;
        QVector<QString> currentSymbols;
        bool isTested = false;
        bool testResult = false;
        int lastRow = 0;
        //bool compareOutputSignals(const QString& cellText, const QStringList& expectedSignals);

    signals:
        //void symbolChanged(QString);
        void funcChanged(int, QString);
        void funcsIsValid();
        void dataEdited();

    public:
        int getStateCodeFromHeader(const QString& headerText);
        int findStateColumnByCode(const QVector<QString>& stateCodes, int targetCode);
        bool checkTransitionsForMode(int row, const QVector<QString>& stateCodes, const std::vector<int>& expectedSequence, const QString& modeName);

        QTransitionTableWgt(QWidget *parent = nullptr);
        bool isOK();
        // void saveData(QFileWorker* stream);
        // //bool checkCellsTransition(const QVector<QVector<int>> &cells, const QVector<QString> &expectedValues);
        // void openData(QFileWorker* stream);
        bool checkTable(QTableWidget* table,const std::vector<int>& stdVectorZero,const std::vector<int>& stdVectorOne);
        bool compareOutputSignals(const QString& cellText, const QStringList& expectedSignals);
        bool checkOutputSignals();
        //bool checkTable1(QTableWidget* table,const std::vector<int>& expectedTransitions1);





    protected:
        QString getDBSymbol(QString sym);
        QString getTableSymbol(int row);
        void resizeEvent(QResizeEvent *event);
//        void keyPressEvent(QKeyEvent *event);
//        void toggleTableItem(int row, int column);

    private:
        QIndWgt *currentIndicator;
        bool adoptOptionState = 0;
        void adoptColumnsWidth();

    protected slots:
//        void sendCurrentSymbol();
//        void sendFunc(int num);
//        void itemKeyPressed(QKeyEvent* event);
//        void clickedTableItem(QTableWidgetItem* item);

    public slots:

//        void adoptOptionToggled(bool state);
//        void setVar(QString var);
//        void setSymbols(QVector<QString> symbols);
          //void setVar(QObject* obj);
};

class QLabTransitionTableWgt : public QWidget
{
    Q_OBJECT

    signals:
        //void setVar(QString);
        void setVar(QObject*);
        void funcChanged(int, QString);
        void funcsIsValid();
        void dataEdited();

    public:
        explicit QLabTransitionTableWgt(QWidget *parent = 0);
        void connectModules(QLabDataBase* db);
        void saveData(QFileWorker* stream);
        void openData(QFileWorker* stream);
        void Convertation(QObject* obj);
        //std::vector<std::pair<int,int>> getCellsNotInCheckRange(QTableWidget* table,
        //                                                         const std::vector<int>& expectedTransitions);

        std::vector<int> stdVectorOne;
        std::vector<int> stdVectorZero;
        bool isOK();

    private slots:
        void on_pushButtonCheck_clicked();

        // LEGACY
        //void on_pushButtonCheck_clicked2();

    protected slots:
        // LEGACY
        //void showErrMsg(int errCode);
        void showErrMsgSignal(int errCode);

    public slots:
        // LEGACY
        //void showErrMsg();
        void showErrMsgSignal();
        void setLabels(QObject* obj);

    private:
        Ui::QLabTransitionTableWgt *ui;
        QLabDataBase* currentDB;
        QTransitionTableWgt *TransitionTable;

};



#endif // QLABTRANSITIONTABLEWGT_H
