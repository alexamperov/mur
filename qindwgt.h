#ifndef QINDWGT_H
#define QINDWGT_H

#include <QString>
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>

class QIndSeg : public QGraphicsView
{
    Q_OBJECT

private:
    int fSeg = 0;
	int fCurrentState = 0;
	QString fState0;
	QString fState1;
	QString fState2;

public:
    explicit QIndSeg(int seg, QWidget *parent = 0);

	QChar getCurrentState() {
        if (fCurrentState)
            return '1';
        else
            return '0';
    }

	void setCurrentState(const QChar state) {
		if ('0' == state) {
			fCurrentState = 0;
			setStyleSheet(fState0);
		} else if ('1' == state) {
			fCurrentState = 1;
			setStyleSheet(fState1);
		} else {
			fCurrentState = 2;
			setStyleSheet(fState2);
		}
    }

protected:
    void mousePressEvent(QMouseEvent *event);    

signals:
    void stateChanged(int seg);
};

class QIndWgt : public QWidget
{
    Q_OBJECT

public:
    QIndSeg *fSegA;
    QIndSeg *fSegB;
    QIndSeg *fSegC;
    QIndSeg *fSegD;
    QIndSeg *fSegE;
    QIndSeg *fSegF;
    QIndSeg *fSegG;

public:
    explicit QIndWgt(QWidget *parent = 0);
    ~QIndWgt();

	QChar getSegState(int seg);

public slots:
	void setSegState(int seg, QChar state);
	void setSegsState(QString state);
    void resetSegState();

signals:
    void stateChanged(int seg);

};

#endif // QINDWGT_H
