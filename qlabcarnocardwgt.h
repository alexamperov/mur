#ifndef QLABCARNOCARDWGT_H
#define QLABCARNOCARDWGT_H

#include <QWidget>
#include <QTextBrowser>
#include <QTableWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QLabel>
#include <QGroupBox>
#include <QLabStructureTableWgt.h>

#include "qbasisedit.h"

#include "cardcarno.h"
#include "qfileworker.h"

namespace Ui {
class QLabCarnoCardWgt;
}

class QCarnoTextWgt : public QTextBrowser
{
	Q_OBJECT

    private:
        bool iamATerm = false;
        int iamInRow = -1;

    public:
        explicit QCarnoTextWgt(QWidget *parent = 0);

    public slots:
        void setHeaderText(QString text);
        void setTermText(QString text);
        void setResultText(QString text);
        void setRow(int row);

    signals:
        void iamSelectedInRow(int);

    protected:
        void mouseDoubleClickEvent(QMouseEvent *e) {e->accept();}
        void mouseMoveEvent(QMouseEvent *e) {e->accept();}
        void mousePressEvent(QMouseEvent *e);

};

class QTermsListWgt : public QTableWidget
{
	Q_OBJECT

public:
	explicit QTermsListWgt(QWidget *parent = 0);

public slots:
	void addTerm(QString text);
	void delSelectedTerm();
	void selectTerm(int row);

signals:
	void termSelected(int);
	void termsListIsEmpty();

protected:
	void resizeEvent(QResizeEvent *event);
};

class QCarnoCardWgt : public QTableWidget
{
	Q_OBJECT

private:
	QString cover;
	bool isExample = false;
	bool isTested = false;
	bool testResult = false;

signals:
	void dataEdited();

public:
	explicit QCarnoCardWgt(QWidget *parent = 0);
	QString getCover();
	bool isCoverOK(int form);
	bool isOK();
	void saveData(QFileWorker* stream);
	void openData(QFileWorker* stream);




public slots:
	void setFunc(QString func);
	void setExample(bool state);
	void showCover(QString cover);

protected:
	void setHeaderItem(int row, int column, QString text);
	void toggleTableItem(int row, int column);
	void deleteTableItem(int row, int column);
	void keyPressEvent(QKeyEvent *event);

protected slots:
	void clickedTableItem(QTableWidgetItem* item);

private:
	QString currentFunc;
    int initCellNums[4][4] = {
        {12, 14, 10,  8},
        {13, 15, 11,  9},
        { 5,  7,  3,  1},
        { 4,  6,  2,  0}
    };

};

class QLabCarnoCardWgt : public QWidget
{
	Q_OBJECT

public:
	explicit QLabCarnoCardWgt(QWidget *parent = 0);
	~QLabCarnoCardWgt();
	void setFuncNum(int funcNum);
	bool isOK();
	void saveData(QFileWorker* stream);
	void openData(QFileWorker* stream);
    void setupTableHeaders();

    void testCarnoCoordinates();
    bool checkCarnoMap();
    QPoint getCarnoCoordinates(int Q3, int Q2, int Q1, int X);
    void showCarnoHint();
    void debugCarnoStructure();

    QString getXTerm(const QSet<int>& cols, bool forNKF);
    QString getQ1Term(const QSet<int>& cols, bool forNKF);
    QString getQ2Term(const QSet<int>& cols, bool forNKF);
    QString getQ3Term(const QSet<int>& cols, bool forNKF);

    int getXFromCol(int col);
    int getQ1FromCol(int col);
    int getQ2FromCol(int col);
    int getQ3FromCol(int col);

    bool allSameX(const QSet<int>& cols);
    bool allSameQ1(const QSet<int>& cols);
    bool allSameQ2(const QSet<int>& cols);
    bool allSameQ3(const QSet<int>& cols);

    QString convertToNiceTerm(const QString& term, int form);
    QString generateCorrectTermFromCover(const QString& cover, int form);

    // Функции для получения значений переменных из координат
    int getQ1FromRow(int row);
    int getQ3FromRow(int row);

    QString generateSimpleTermFromSelection();
    void highlightTermOnCarnoMap(const QString& cover);
    void clearCarnoHighlights();

    bool isValidCarnoCover(const QString& cover);

    void clearVariableSelectionOnly();
    void debugTableToFuncMapping();
    void updateCurrentFuncFromTable();
    void setStructureData(QStructureTableWgt* structureTableWidget, int triggerColumnIndex, const QString& triggerInputName);
    QString normalizeTerm(const QString& term);


protected:
	bool isCoverAndTermOK(QString cover, QString term, int form);
    bool isUserTermUnique(const QString term);
	bool checkBasisExp();
    bool recvCaclExp(expTree* exp, int x1, int x2, int x3, int x4);
	void destroyExpTree(expTree *ptr);
	expTree* genExpTree(QString func);
	void getExpOp(QString& func, QChar &op, int &index);
	int power(int num, unsigned int power);
	void resizeEvent(QResizeEvent *event);

protected slots:
	void showCover(int row);
	void updateResult();
	void basisEdited();
	void showErrMsg(int errCode);

private slots:
	void on_pushButtonAddTerm_clicked();
	void on_pushButtonDelTerm_clicked();
	void on_pushButtonCardCheck_clicked();
	void on_pushButtonCheckResult_clicked();
	void on_pushButtonCheckBasis_clicked();

public slots:
	void minimizeFunc();
	void setFunc(int num, QString func);
    //void setStructureData(QStructureTableWgt* structureTableWidget, int triggerColumnIndex, const QString& triggerInputName);
     void clearTableData();
signals:
	void dataEdited();

private:
	CardCarno minimizer;
	QVector<QString> userCovers;
	QVector<QString> userSTerms;
	QVector<QString> userNTerms;
	vector<vector<string>> algmTermsD;
	vector<vector<string>> algmTermsK;
	expTree* resultExp = 0;
	QString resultS = "";
	QString resultN = "";
	QString currentFunc = "";
	Ui::QLabCarnoCardWgt *ui;
	int currentFuncNum = -1;
	int currentTerm = -1;
	int currentForm = 0;
	bool isResultTested = false;
	int resultTestCode = -1;
	bool isBasisTested = false;
	int basisTestCode = -1;
	QVector<QString> signsNDF = {"x1", "!x1", "x2", "!x2", "x3", "!x3", "x4", "!x4"};
	QVector<QString> signsNKF = {"!x1", "x1", "!x2", "x2", "!x3", "x3", "!x4", "x4"};
	QVector<QString> signsTemplate = {"0001020310111213",
									  "2021222330313233",
									  "0001101120213031",
									  "0203121322233233",
									  "0102111221223132",
									  "0003101320233033",
									  "1011121320212223",
									  "0001020330313233"};
};

#endif // QLABCARNOCARDWGT_H
