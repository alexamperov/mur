#ifndef QLABSTRUCTURETABLEWGT_H
#define QLABSTRUCTURETABLEWGT_H

#include <QWidget>
#include <QTableWidget>
#include <QTextBrowser>
#include <QResizeEvent>
#include <QScrollBar>
#include <QMessageBox>

#include "qlabdatabase.h"
#include "qfileworker.h"
#include "statemanager.h"

#include "qindwgt.h"

namespace Ui {
class QLabStructureTableWgt;
class QStructureTableWgt;
}

class QStructureTableHeaderWgt : public QTextBrowser
{
    Q_OBJECT

public:
    explicit QStructureTableHeaderWgt(QWidget *parent = 0) : QTextBrowser(parent) {
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    }

     QString getHeaderText() const;
    QString headerText;
public slots:
    void setHeaderText(QString text);

protected:
    void keyPressEvent(QKeyEvent *e) {e->accept();}
    void mouseDoubleClickEvent(QMouseEvent *e) {e->accept();}
    void mouseMoveEvent(QMouseEvent *e) {e->accept();}
    void mousePressEvent(QMouseEvent *e) {e->accept();}
};

class QStructureTableWgt : public QTableWidget
{
    Q_OBJECT

private:
    QString currentVar;
    QVector<QString> currentSymbols;
    bool isTested = false;
    bool testResult = false;
    int lastRow = 0;

signals:
    void setVar(QObject*);
    void funcChanged(int, QString);
    void funcsIsValid();
    void dataEdited();
    void triggerIndexChanged(int);

public:
    void updateTableForTriggerType(const QString& triggerType);
    QStructureTableWgt(QObject* obj,QWidget *parent = nullptr);
    void buildTable();
    void connectModules1(QLabDataBase* db);
    bool isOK();
    void saveData(QFileWorker* stream);
    void openData(QFileWorker* stream);
    //void updateHeaders();
    bool checkTable(QTableWidget* table, const std::vector<int>& expectedTransitions, const std::vector<int>& stdVectorOne);
    //bool checkTable1(QTableWidget* table, const std::vector<int>& expectedTransitions,std::vector<std::pair<int,int>> result1);
    bool checkCells(const QVector<QVector<int>> &cells, const QVector<QString> &expectedValues);
    bool checkOutput(QTableWidget* table);
    void clearTable();
    QVector<QString> vecTrigger = {"RS", "D", "T", "JK"};
    QVector<QString> vecBasis = {"Буля", "Шеффера", "Пирса"};
    QString triggerType;
    QString basisType;

    // Проверка функций возбуждения
    bool checkExcitationFunctions(QTableWidget* table);
    bool checkRSExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next);
    bool checkDExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next);
    bool checkTExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next);
    bool checkJKExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next);
    int parseExcitationValue(QTableWidgetItem* item);

    // Вспомогательные методы
    bool checkStructureRow(QTableWidget* table, int row, const std::vector<int>& expectedSequence, const QString& modeName);
    int getNextStateCodeFromTransition(int currentStateIndex, const std::vector<int>& expectedSequence, const QString& modeName);
    bool checkCodeInColumns(QTableWidget* table, int row, int startCol, int endCol, const QVector<int>& expectedCode, const QString& codeType);
    bool checkInputSignal(QTableWidget* table, int row, int col, int expectedInput);
    int binaryVectorToInt(const QVector<int>& binaryVector);
    QVector<int> intToBinaryVector(int value, int bits);
    bool checkNextStateColumn(QTableWidget* table, int row, int col, int expectedStateIndex);
    int getStateIndexByCode(int codeValue);

protected:
    QString getDBSymbol(QString sym);
    QString getTableSymbol(int row);
    void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void toggleTableItem(int row, int column);

private:
    QIndWgt *currentIndicator;
    bool adoptOptionState = 0;
    void adoptColumnsWidth();
    QLabDataBase* currentDB;
    int trigger_index;

protected slots:
    void itemKeyPressed(QKeyEvent* event);
    void clickedTableItem(QTableWidgetItem* item);
};

class QLabStructureTableWgt : public QWidget
{
    Q_OBJECT

signals:
    //void setVar(QString);
    void setVar(QObject*);
    void funcChanged(int, QString);
    void funcsIsValid();
    void dataEdited();

public:
    QLabStructureTableWgt(QWidget *parent = 0);
    void connectModules(QLabDataBase* db);
    void saveData(QFileWorker* stream);
    void openData(QFileWorker* stream);
    bool isOK();
    void Convertation(QObject* obj);
    std::vector<std::pair<int,int>> getCellsNotInCheckRangeZero(QTableWidget* table,
                                                                 const std::vector<int>& expectedTransitions);
    std::vector<std::pair<int,int>> getCellsNotInCheckRangeOne(QTableWidget* table,
                                                                const std::vector<int>& expectedTransitions);
    bool checkTriggers (QTableWidget* table);

    int getStructureColumnIndex(const QString& triggerType, int tabIndex);
    void updateCarnoCardData();
    QStructureTableWgt* structureTable() const { return m_structureTable; }
    QStructureTableWgt* m_structureTable; // Добавляем член для хранения указателя

private slots:
    void on_pushButtonCheck_clicked();

protected slots:
    void showErrMsgSignal(int errCode);

public slots:
    //void showErrMsg();
    void setLabels1(QObject* obj);
    void showErrMsgSignal();


private:

    QLabDataBase* currentDB;

    Ui::QLabStructureTableWgt *ui;
    std::vector<int> stdVectorOne;
    std::vector<int> stdVectorZero;
    QStructureTableWgt* structureTableWgt;
    QString triggerType;
    QVector<QString> vecTrigger = {"RS", "D", "T", "JK"};
    QVector<QString> vecBasis = {"Буля", "Шеффера", "Пирса"};
    QString basisType;


};

#endif // QLABSTRUCTURETABLEWGT_H
