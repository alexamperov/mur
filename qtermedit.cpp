#include "qtermedit.h"
#include "ui_qtermedit.h"

// QTermEdit::QTermEdit(QWidget *parent) :
// 	QWidget(parent),
// 	ui(new Ui::QTermEdit)
// {
// 	ui->setupUi(this);

//     ui->textBrowser0X1->setTermItm("Q", 1, 0);
//     ui->textBrowser0X2->setTermItm("Q", 2, 0);
//     ui->textBrowser0X3->setTermItm("Q", 3, 0);
//     ui->textBrowser0X4->setTermItm("X", 0, 0);

//     ui->textBrowser1X1->setTermItm("Q", 1, 1);
//     ui->textBrowser1X2->setTermItm("Q", 2, 1);
//     ui->textBrowser1X3->setTermItm("Q", 3, 1);
//     ui->textBrowser1X4->setTermItm("X", 0, 1);

// 	ui->textBrowserDF->setTermFrm(-1);
//     ui->textBrowserKF->setTermFrm(1);

// 	connect(ui->textBrowser0X1, SIGNAL(toggledOn()), ui->textBrowser1X1, SLOT(setOff()));
// 	connect(ui->textBrowser1X1, SIGNAL(toggledOn()), ui->textBrowser0X1, SLOT(setOff()));

// 	connect(ui->textBrowser0X2, SIGNAL(toggledOn()), ui->textBrowser1X2, SLOT(setOff()));
// 	connect(ui->textBrowser1X2, SIGNAL(toggledOn()), ui->textBrowser0X2, SLOT(setOff()));

// 	connect(ui->textBrowser0X3, SIGNAL(toggledOn()), ui->textBrowser1X3, SLOT(setOff()));
// 	connect(ui->textBrowser1X3, SIGNAL(toggledOn()), ui->textBrowser0X3, SLOT(setOff()));

// 	connect(ui->textBrowser0X4, SIGNAL(toggledOn()), ui->textBrowser1X4, SLOT(setOff()));
// 	connect(ui->textBrowser1X4, SIGNAL(toggledOn()), ui->textBrowser0X4, SLOT(setOff()));

// 	connect(ui->textBrowserDF, SIGNAL(toggledOn()), ui->textBrowserKF, SLOT(setOff()));
// 	connect(ui->textBrowserDF, SIGNAL(toggledOn()), this, SLOT(setKF()));

// 	connect(ui->textBrowserKF, SIGNAL(toggledOn()), ui->textBrowserDF, SLOT(setOff()));
// 	connect(ui->textBrowserKF, SIGNAL(toggledOn()), this, SLOT(setDF()));

// 	setMaximumHeight(ui->textBrowser0X1->height() * 2 + 12);
// }

QTermEdit::QTermEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTermEdit)
{
    ui->setupUi(this);

    ui->textBrowser0X1->setTermItm("Q", 1, 0);
    ui->textBrowser0X2->setTermItm("Q", 2, 0);
    ui->textBrowser0X3->setTermItm("Q", 3, 0);
    ui->textBrowser0X4->setTermItm("X", 0, 0);

    ui->textBrowser1X1->setTermItm("Q", 1, 1);
    ui->textBrowser1X2->setTermItm("Q", 2, 1);
    ui->textBrowser1X3->setTermItm("Q", 3, 1);
    ui->textBrowser1X4->setTermItm("X", 0, 1);

    // ИСПРАВЛЕНО: правильные формы для кнопок
    ui->textBrowserDF->setTermFrm(-1);  // НДФ
    ui->textBrowserKF->setTermFrm(1);   // НКФ

    connect(ui->textBrowser0X1, SIGNAL(toggledOn()), ui->textBrowser1X1, SLOT(setOff()));
    connect(ui->textBrowser1X1, SIGNAL(toggledOn()), ui->textBrowser0X1, SLOT(setOff()));

    connect(ui->textBrowser0X2, SIGNAL(toggledOn()), ui->textBrowser1X2, SLOT(setOff()));
    connect(ui->textBrowser1X2, SIGNAL(toggledOn()), ui->textBrowser0X2, SLOT(setOff()));

    connect(ui->textBrowser0X3, SIGNAL(toggledOn()), ui->textBrowser1X3, SLOT(setOff()));
    connect(ui->textBrowser1X3, SIGNAL(toggledOn()), ui->textBrowser0X3, SLOT(setOff()));

    connect(ui->textBrowser0X4, SIGNAL(toggledOn()), ui->textBrowser1X4, SLOT(setOff()));
    connect(ui->textBrowser1X4, SIGNAL(toggledOn()), ui->textBrowser0X4, SLOT(setOff()));

    // ИСПРАВЛЕНО: правильные соединения
    connect(ui->textBrowserDF, SIGNAL(toggledOn()), ui->textBrowserKF, SLOT(setOff()));
    connect(ui->textBrowserDF, SIGNAL(toggledOn()), this, SLOT(setDF()));  // НДФ

    connect(ui->textBrowserKF, SIGNAL(toggledOn()), ui->textBrowserDF, SLOT(setOff()));
    connect(ui->textBrowserKF, SIGNAL(toggledOn()), this, SLOT(setKF()));  // НКФ

    setMaximumHeight(ui->textBrowser0X1->height() * 2 + 12);
}

QString QTermEdit::getSTerm()
{
	return sTerm;
}

int QTermEdit::getTermForm()
{
	return termForm;
}

void QTermEdit::setTermForm(int form)
{
	termForm = form;
	block();
}

QString QTermEdit::getNTerm()
{
	return nTerm;
}

bool QTermEdit::isTermOK()
{
    QString nSign;
    QString sSign;

    nTerm = "";
    sTerm = "";

    // ИСПРАВЛЕНО: правильное соответствие форм и разделителей
    if (ui->textBrowserDF->state()) {
        // НДФ - форма И (конъюнкция)
        nSign = "&#183;";  // И для отображения
        sSign = "*";       // И для внутреннего представления
        termForm = -1;     // НДФ
    } else if (ui->textBrowserKF->state()) {
        // НКФ - форма ИЛИ (дизъюнкция)
        nSign = "+";       // ИЛИ для отображения
        sSign = "+";       // ИЛИ для внутреннего представления
        termForm = 1;      // НКФ
    } else {
        return false;
    }

    // Остальная часть метода остается без изменений
    if (ui->textBrowser0X1->state()) {
        sTerm += "!x1";
        nTerm += "<span style=\"text-decoration: overline;\">x</span><span style=\" vertical-align:sub;\">1</span>";
    } else if (ui->textBrowser1X1->state()) {
        sTerm += "x1";
        nTerm += "x<span style=\" vertical-align:sub;\">1</span>";
    }

    if (ui->textBrowser0X2->state()) {
        sTerm += sSign + "!x2";
        nTerm += nSign + "<span style=\"text-decoration: overline;\">x</span><span style=\" vertical-align:sub;\">2</span>";
    } else if (ui->textBrowser1X2->state()) {
        sTerm += sSign + "x2";
        nTerm += nSign + "x<span style=\" vertical-align:sub;\">2</span>";
    }

    if (ui->textBrowser0X3->state()) {
        sTerm += sSign + "!x3";
        nTerm += nSign + "<span style=\"text-decoration: overline;\">x</span><span style=\" vertical-align:sub;\">3</span>";
    } else if (ui->textBrowser1X3->state()) {
        sTerm += sSign + "x3";
        nTerm += nSign + "x<span style=\" vertical-align:sub;\">3</span>";
    }

    if (ui->textBrowser0X4->state()) {
        sTerm += sSign + "!x4";
        nTerm += nSign + "<span style=\"text-decoration: overline;\">x</span><span style=\" vertical-align:sub;\">4</span>";
    } else if (ui->textBrowser1X4->state()) {
        sTerm += sSign + "x4";
        nTerm += nSign + "x<span style=\" vertical-align:sub;\">4</span>";
    }

    if (nTerm.size() > 0 && nTerm[0] == nSign[0]) {
        nTerm.remove(0, nSign.size());
    }

    if (sTerm.size() > 0 && sTerm[0] == sSign[0]) {
        sTerm.remove(0, sSign.size());
    }

    return (nTerm.size() > 0 && sTerm.size() > 0);
}

QTermEdit::~QTermEdit()
{
	delete ui;
}

void QTermEdit::unblock()
{
    if (ui->textBrowserDF->isBlocked())
        ui->textBrowserDF->clearBlk();
    if (ui->textBrowserKF->isBlocked())
        ui->textBrowserKF->clearBlk();
}

void QTermEdit::block()
{
    if (termForm == -1) { // НДФ
        ui->textBrowserKF->setBlk();   // Блокируем НКФ
        ui->textBrowserDF->setOn();    // Включаем НДФ
        ui->textBrowserDF->blkState(true);
    } else if (termForm == 1) { // НКФ
        ui->textBrowserDF->setBlk();   // Блокируем НДФ
        ui->textBrowserKF->setOn();    // Включаем НКФ
        ui->textBrowserKF->blkState(true);
    }
}

void QTermEdit::block(int form)
{
    termForm = form;
    if (termForm == -1) { // НДФ
        ui->textBrowserKF->setBlk();   // Блокируем НКФ
        ui->textBrowserDF->setOn();    // Включаем НДФ
        ui->textBrowserDF->blkState(true);
    } else if (termForm == 1) { // НКФ
        ui->textBrowserDF->setBlk();   // Блокируем НДФ
        ui->textBrowserKF->setOn();    // Включаем НКФ
        ui->textBrowserKF->blkState(true);
    }
}


void QTermEdit::clear()
{
	ui->textBrowser0X1->setOff();
	ui->textBrowser0X2->setOff();
	ui->textBrowser0X3->setOff();
	ui->textBrowser0X4->setOff();

	ui->textBrowser1X1->setOff();
	ui->textBrowser1X2->setOff();
	ui->textBrowser1X3->setOff();
	ui->textBrowser1X4->setOff();

	ui->textBrowserDF->setOff();
	ui->textBrowserKF->setOff();
}


void QTermEdit::setKF()
{
    termForm = 1;  // НКФ
}

void QTermEdit::setDF()
{
    termForm = -1; // НДФ
}

QTermItmWgt::QTermItmWgt(QWidget *parent) : QTextBrowser(parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	triggerState = false;
}

bool QTermItmWgt::state()
{
	return triggerState;
}

bool QTermItmWgt::isBlocked()
{
	if (blocked)
		return true;
	else
		return false;
}

void QTermItmWgt::setTermItm(QString var, int num, bool sign)
{
	if (sign) {
        txtOn = "<style>body{background-color:lime;}</style><body>" + QString(var);
        if (num > 0){
            txtOn += "<span style=\" vertical-align:sub;\">" + QString::number(num) + "</span>";
        }
        txtOn += "</body>";


        txtOff = "<style>body{background-color:white;}</style><body>" + QString(var);
        if (num > 0){
            txtOff += "<span style=\" vertical-align:sub;\">" + QString::number(num) + "</span>";
        }
        txtOff += "</body>";

	} else {        
        txtOn = "<style>body{background-color:lime;}</style><body><div style=\"text-decoration: overline;\">" + QString(var);
        if (num > 0){
            txtOn += "<span style=\" vertical-align:sub;\">" + QString::number(num) + "</span>";
        }
        txtOn += "</div></body>";


        txtOff = "<style>body{background-color:white;}</style><body><div style=\"text-decoration: overline;\">" + QString(var);
        if (num > 0){
            txtOff += "<span style=\" vertical-align:sub;\">" + QString::number(num) + "</span>";
        }
        txtOff += "</div></body>";

	}

	setHtml(txtOff);

	setMaximumHeight(QFontMetrics(font()).height() + 12);
	setMinimumHeight(maximumHeight());

	setMaximumWidth(maximumHeight());
	setMinimumWidth(maximumWidth());
}


void QTermItmWgt::setTermFrm(int form)
{
    QString txt;
    if (form == -1) { // НДФ
        txtOn = "<style>body{background-color:lime;}</style><body>НДФ</body>";
        txtOff = "<style>body{background-color:white;}</style><body>НДФ</body>";
        txtBlk = "<style>body{background-color:red;}</style><body>НДФ</body>";
        txt = "НДФ";
    } else if (form == 1) { // НКФ
        txtOn = "<style>body{background-color:lime;}</style><body>НКФ</body>";
        txtOff = "<style>body{background-color:white;}</style><body>НКФ</body>";
        txtBlk = "<style>body{background-color:red;}</style><body>НКФ</body>";
        txt = "НКФ";
    }

    setHtml(txtOff);
    setMaximumHeight(QFontMetrics(font()).height() + 12);
    setMaximumWidth(QFontMetrics(font()).horizontalAdvance(txt) + 12);
}

void QTermItmWgt::setOn()
{
	if (!blocked) {
		blocked = false;
		triggerState = true;
		setHtml(txtOn);
		toggledOn();
	}
}

void QTermItmWgt::setOff()
{
	if (!blocked) {
		triggerState  = false;
		setHtml(txtOff);
	}
}

void QTermItmWgt::setBlk()
{
	blocked = true;
	triggerState = false;
	setHtml(txtBlk);
}

void QTermItmWgt::clearBlk()
{
	blocked = false;
	triggerState  = false;
	setHtml(txtOff);
}

void QTermItmWgt::blkState(bool state)
{
	blocked = state;
}

void QTermItmWgt::setHtml(QString text)
{
	QTextBrowser::setHtml(text);
	setAlignment(Qt::AlignCenter);
}

void QTermItmWgt::toggleState()
{
	if (!blocked) {
		triggerState = !triggerState;
		if (triggerState) {
			setHtml(txtOn);
			toggledOn();
		} else
			setHtml(txtOff);
	}
}

void QTermItmWgt::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton) {
		toggleState();
	}
}
