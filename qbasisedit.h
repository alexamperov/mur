#ifndef QBASISEDIT_H
#define QBASISEDIT_H

#include <QWidget>
#include <QTableWidget>
#include <QTextBrowser>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QHeaderView>
#include <QLabel>

#include "qfileworker.h"

namespace Ui {
class QBasisEdit;
}

struct expTree {
	QChar op;
	expTree* lf;
	expTree* rt;
};

class QBasisTextWgt : public QTextBrowser
{
	Q_OBJECT

private:
	bool iAmButton = false;
	QString txtOn;
	QString txtOff;
	int termIndex = -1;

public:
	explicit QBasisTextWgt(QWidget *parent = 0);

public slots:
	void setTermText(QString text);
	void setBttnText(QString text);
	void setTermIndex(int index);
	void setBttnWdth(int wdth);

protected slots:
	void toggleOn();
	void toggleOff();
	void setTermText(int index, QString text);

signals:
	void iAmPressed(QBasisTextWgt*);
	void iAmPressedWithCtrl(QBasisTextWgt*);
	void iAmPressedWithShift(QBasisTextWgt*);
	void setTermTextSignal(int, QString);
    void clicked();

protected:
	void mouseDoubleClickEvent(QMouseEvent *e) {e->accept();}
	void mouseMoveEvent(QMouseEvent *e) {e->accept();}
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);

};

class QBasisEdit : public QWidget
{
	Q_OBJECT

private:
	int lastItem = -1;
	QString currentFunc;
	QString currentSign = "?";
	expTree* currentExpTree = 0;
	bool medited = false;
	int checkErrCode = -1;
	QString initExp;

public:
	explicit QBasisEdit(QWidget *parent = 0);
	~QBasisEdit();
	int checkExp();
	int calcExp(int x1, int x2, int x3, int x4);
	QString getBasis();
	QString getInitExp();
    bool hasNot(int index);
    void updateNotDisplay(int begin, int end);

    void updateAllDisplay();
    void updateDisplay(int index);
    void ensureNotRowExists();
    int findAvailableNotRow(int column);
    int findAvailableNotRowForRange(int begin, int end);

    void debugState();
    void clickedAdd();
    bool rangeContainsOperators(int begin, int end);

    void convertToShefferBasis();
    void convertToPierceBasis();
    QString getExpressionWithNotations();
    void setExpressionWithNegations(const QString& expression);

public slots:
	void setExp(QString func);
	void saveData(QFileWorker* stream);
	void openData(QFileWorker* stream);

signals:
	void readyForInitData();
	void setTermTextSignal(int, QString);
	void showErrMsg(int);
	void edited();

protected slots:
	void setSelection(QBasisTextWgt* wgt);
	void setSelectionWithCtrl(QBasisTextWgt* wgt);
	void setSelectionWithShift(QBasisTextWgt* wgt);
	void clickedNot();
	void clickedMul();
    //void clickedAdd();

protected:
    bool recvCaclExp(expTree* exp, int x1, int x2, int x3, int x4);
	void destroyExpTree(expTree *ptr);
	expTree *genExpTree(int begin, int end, int mNots = 0);
	void getExpOp(int begin, int end, int mNots, QChar &op, int &index);
	int cntOfNots(int index);
	bool NOT(int begin, int end);
	void MUL(int index);
	void ADD(int index);
	void addClearItemsToColumn(int column);
	bool isMayAddNotInRow(int row, int begin, int end);
	void setNotInRow(int row, int begin, int end);
	void setUnNotInRow(int row, int begin, int end);
	void insertClearNotRow(int row);
	int lenOfNotInRow(int row, int begin, int end);
	int leftOfNotInRow(int row, int begin);
	int rightOfNotInRow(int row, int end);
	int upNotInRow(int row, int begin, int end);
	int cntOfNotInRowBtwnBE(int row, int begin, int end);
	bool isNotIsEqual(int row, int begin, int end);
	void removeClearRows();
	void clearSelection();
	void downNotInRows();
	int cntOfBrackets(int begin, int end);
	bool checkForNot(int x1, int x2);

private:
	Ui::QBasisEdit *ui;
};

#endif // QBASISEDIT_H
