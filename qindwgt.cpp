#include "qindwgt.h"

QIndWgt::QIndWgt(QWidget *parent) :
    QWidget(parent)
{
    setBaseSize(QSize(101, 161));
    setMinimumSize(QSize(101, 161));
    setMaximumSize(QSize(101, 161));

    fSegA = new QIndSeg(1,this);
    fSegA->setGeometry(QRect(20, 10, 63, 22));

    fSegB = new QIndSeg(2,this);
    fSegB->setGeometry(QRect(71, 20, 22, 63));

    fSegC = new QIndSeg(3,this);
    fSegC->setGeometry(QRect(71, 80, 22, 63));

    fSegD = new QIndSeg(4,this);
    fSegD->setGeometry(QRect(20, 131, 63, 22));

    fSegE = new QIndSeg(5,this);
    fSegE->setGeometry(QRect(10, 80, 22, 63));

    fSegF = new QIndSeg(6,this);
    fSegF->setGeometry(QRect(10, 20, 22, 63));

    fSegG = new QIndSeg(7,this);
    fSegG->setGeometry(QRect(20, 71, 63, 22));

    connect(fSegA, SIGNAL(stateChanged(int)), this, SIGNAL(stateChanged(int)));
    connect(fSegB, SIGNAL(stateChanged(int)), this, SIGNAL(stateChanged(int)));
    connect(fSegC, SIGNAL(stateChanged(int)), this, SIGNAL(stateChanged(int)));
    connect(fSegD, SIGNAL(stateChanged(int)), this, SIGNAL(stateChanged(int)));
    connect(fSegE, SIGNAL(stateChanged(int)), this, SIGNAL(stateChanged(int)));
    connect(fSegF, SIGNAL(stateChanged(int)), this, SIGNAL(stateChanged(int)));
    connect(fSegG, SIGNAL(stateChanged(int)), this, SIGNAL(stateChanged(int)));
}

QIndWgt::~QIndWgt()
{
    delete fSegA;
    delete fSegB;
    delete fSegC;
    delete fSegD;
    delete fSegE;
    delete fSegF;
    delete fSegG;
}

QChar QIndWgt::getSegState(int seg)
{
	QChar state = '0';
    switch (seg) {
        case 1:
            state = fSegA->getCurrentState();
            break;
        case 2:
            state = fSegB->getCurrentState();
            break;
        case 3:
            state = fSegC->getCurrentState();
            break;
        case 4:
            state = fSegD->getCurrentState();
            break;
        case 5:
            state = fSegE->getCurrentState();
            break;
        case 6:
            state = fSegF->getCurrentState();
            break;
        case 7:
            state = fSegG->getCurrentState();
            break;
    }

    return state;
}

void QIndWgt::setSegState(int seg, QChar state)
{
    switch (seg) {
        case 1:
            fSegA->setCurrentState(state);
            break;
        case 2:
            fSegB->setCurrentState(state);
            break;
        case 3:
            fSegC->setCurrentState(state);
            break;
        case 4:
            fSegD->setCurrentState(state);
            break;
        case 5:
            fSegE->setCurrentState(state);
            break;
        case 6:
            fSegF->setCurrentState(state);
            break;
        case 7:
            fSegG->setCurrentState(state);
            break;
	}
}

void QIndWgt::setSegsState(QString state)
{
	for (int i = 0; i < state.size(); i++)
		setSegState(i + 1, state[i]);
}

void QIndWgt::resetSegState()
{
    fSegA->setCurrentState('0');
    fSegB->setCurrentState('0');
    fSegC->setCurrentState('0');
    fSegD->setCurrentState('0');
    fSegE->setCurrentState('0');
    fSegF->setCurrentState('0');
    fSegG->setCurrentState('0');
}

QIndSeg::QIndSeg(int seg, QWidget *parent) :
    QGraphicsView(parent)
{
    fSeg = seg;
    switch (seg) {
        case 1:
			fState2 = "border-image: url(:/qindwgt/a_2.png);";
			fState1 = "border-image: url(:/qindwgt/a_1.png);";
			fState0 = "border-image: url(:/qindwgt/a_0.png);";
            break;
        case 2:
			fState2 = "border-image: url(:/qindwgt/b_2.png);";
			fState1 = "border-image: url(:/qindwgt/b_1.png);";
			fState0 = "border-image: url(:/qindwgt/b_0.png);";
            break;
        case 3:
			fState2 = "border-image: url(:/qindwgt/c_2.png);";
			fState1 = "border-image: url(:/qindwgt/c_1.png);";
			fState0 = "border-image: url(:/qindwgt/c_0.png);";
            break;
        case 4:
			fState2 = "border-image: url(:/qindwgt/d_2.png);";
			fState1 = "border-image: url(:/qindwgt/d_1.png);";
			fState0 = "border-image: url(:/qindwgt/d_0.png);";
            break;
        case 5:
			fState2 = "border-image: url(:/qindwgt/e_2.png);";
			fState1 = "border-image: url(:/qindwgt/e_1.png);";
			fState0 = "border-image: url(:/qindwgt/e_0.png);";
            break;
        case 6:
			fState2 = "border-image: url(:/qindwgt/f_2.png);";
			fState1 = "border-image: url(:/qindwgt/f_1.png);";
			fState0 = "border-image: url(:/qindwgt/f_0.png);";
            break;
        case 7:
			fState2 = "border-image: url(:/qindwgt/g_2.png);";
			fState1 = "border-image: url(:/qindwgt/g_1.png);";
			fState0 = "border-image: url(:/qindwgt/g_0.png);";
            break;
    }

	setStyleSheet(fState0);
}


void QIndSeg::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
		if (fCurrentState == 0)
			setCurrentState('1');
        else
			setCurrentState('0');
        stateChanged(fSeg);
    }
}
