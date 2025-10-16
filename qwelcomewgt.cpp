#include "qwelcomewgt.h"
#include "ui_qwelcomewgt.h"
#include <QDebug>

QWelcomeWgt::QWelcomeWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWelcomeWgt)
{
    ui->setupUi(this);

    setAppVersion();

    ui->pushButtonNew->setEnabled(false);
    connect(this, SIGNAL(dbState(bool)), this, SLOT(setEnabled(bool)));
}

void QWelcomeWgt::connectModules(QLabDataBase *db)
{
    currentDB = db;
    connect(ui->pushButtonNew, SIGNAL(clicked(bool)), this, SIGNAL(newBtnClicked()));
	connect(ui->pushButtonOpen, SIGNAL(clicked(bool)), this, SIGNAL(openBtnClicked()));
    setDBVersion();
}

void QWelcomeWgt::setEnabled(bool state)
{
    ui->pushButtonNew->setEnabled(state);
}

void QWelcomeWgt::setDBVersion()
{
    if (currentDB->openDB(QApplication::applicationDirPath() + "/VariantList.pam-db")) {
		if (currentDB->getDBState()) {
            //ui->labelDBVersion->setText(currentDB->getVersion());
            ui->labelDBVersion->setText("2025");
			dbState(true);
		} else {
			ui->labelDBVersion->setText("БАЗА ДАННЫХ СОДЕРЖИТ ОШИБКИ!");
            dbState(false);
		}
    } else {
        ui->labelDBVersion->setText("БАЗА ДАННЫХ ОТСУТСТВУЕТ!");
        dbState(false);
    }
}

void QWelcomeWgt::setAppVersion()
{
    ui->labelAppVersion->setText("2025");
}

QWelcomeWgt::~QWelcomeWgt()
{
    delete ui;
}
