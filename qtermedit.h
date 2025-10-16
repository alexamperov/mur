#ifndef QTERMEDIT_H
#define QTERMEDIT_H

#include <QWidget>
#include <QTextBrowser>
#include <QMouseEvent>

namespace Ui {
class QTermEdit;
}

class QTermItmWgt : public QTextBrowser
{
	Q_OBJECT

public:
	explicit QTermItmWgt(QWidget *parent = 0);
	bool state();
	bool isBlocked();

private:
	bool triggerState = false;
	bool blocked = false;
	QString txtOn;
	QString txtOff;
	QString txtBlk;

public slots:
    void setTermItm(QString var, int num, bool sign);
	void setTermFrm(int form);
	void setOn();
	void setOff();
	void setBlk();
	void clearBlk();
	void blkState(bool state);
	void setHtml(QString text);

signals:
	void toggledOn();

protected:
	void toggleState();

	void mouseDoubleClickEvent(QMouseEvent *e) {e->accept();}
	void mouseMoveEvent(QMouseEvent *e) {e->accept();}
	void mousePressEvent(QMouseEvent *e);

};

class QTermEdit : public QWidget
{
	Q_OBJECT

private:
	QString nTerm;
	QString sTerm;
	int termForm = 0;

public:
	explicit QTermEdit(QWidget *parent = 0);
	QString getNTerm();
	QString getSTerm();
	int getTermForm();
	void setTermForm(int form);
	bool isTermOK();
	~QTermEdit();

public slots:
	void unblock();
	void block();
	void block(int form);
	void clear();

protected slots:
	void setKF();
	void setDF();

private:
	Ui::QTermEdit *ui;
};

#endif // QTERMEDIT_H
