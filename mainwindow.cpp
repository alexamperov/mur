#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    workerSize.setWidth(200);
    workerSize.setHeight(100);

	welcomeScr = 0;
	labWorkerScr = 0;
	showWelcomeWgt();

    setGeometry(QStyle::alignedRect(Qt::RightToLeft, Qt::AlignCenter, workerSize, QRect(100, 100, 150, 40)));
    repaint();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
	delete welcomeScr;
	delete labWorkerScr;
    close();
}

void MainWindow::showLabChoseWgt()
{
	destroyWelcome();

	labWorkerScr = new QLabWorkerWgt();
	labWorkerScr->connectModules(&currentDB);
	labWorkerScr->newLab();

	ui->mainLayout->addWidget(labWorkerScr);
	connect(labWorkerScr, SIGNAL(showWelcomeWgt()), this, SLOT(showWelcomeWgt()));
}

void MainWindow::showLabOpenWgt()
{
	labWorkerScr = new QLabWorkerWgt();
	labWorkerScr->connectModules(&currentDB);
	if (labWorkerScr->openLab()) {
		destroyWelcome();
		ui->mainLayout->addWidget(labWorkerScr);
		connect(labWorkerScr, SIGNAL(showWelcomeWgt()), this, SLOT(showWelcomeWgt()));
	} else
		destroyLabWorker();
}

void MainWindow::showWelcomeWgt()
{
	destroyLabWorker();

	welcomeScr = new QWelcomeWgt();
	ui->mainLayout->addWidget(welcomeScr);
    welcomeScr->connectModules(&currentDB);
	connect(welcomeScr, SIGNAL(newBtnClicked()), this, SLOT(showLabChoseWgt()));
	connect(welcomeScr, SIGNAL(openBtnClicked()), this, SLOT(showLabOpenWgt()));
}

void MainWindow::destroyWelcome()
{
	if (welcomeScr != 0) {
		disconnect(welcomeScr, SIGNAL(newBtnClicked()), this, SLOT(showLabChoseWgt()));
		disconnect(welcomeScr, SIGNAL(openBtnClicked()), this, SLOT(showLabOpenWgt()));
		delete welcomeScr;
		welcomeScr = 0;
	}
}

void MainWindow::destroyLabWorker()
{
	if (labWorkerScr != 0 ) {
		disconnect(labWorkerScr, SIGNAL(showWelcomeWgt()), this, SLOT(showWelcomeWgt()));
		delete labWorkerScr;
		labWorkerScr = 0;
	}
}
