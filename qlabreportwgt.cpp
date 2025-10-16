#include "qlabreportwgt.h"
#include "ui_qlabreportwgt.h"

QLabReportWgt::QLabReportWgt(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::QLabReportWgt)
{
	ui->setupUi(this);

	connect(ui->lineEditStudentFIO, SIGNAL(textChanged(QString)), this, SIGNAL(dataEdited()));
	connect(ui->lineEditStudentGroup, SIGNAL(textChanged(QString)), this, SIGNAL(dataEdited()));
	connect(ui->lineEditStudentNum, SIGNAL(textChanged(QString)), this, SIGNAL(dataEdited()));
	connect(ui->lineEditTeacherFIO, SIGNAL(textChanged(QString)), this, SIGNAL(dataEdited()));
}

void QLabReportWgt::saveData(QFileWorker* stream)
{
	stream->setStr(ui->lineEditStudentFIO->text());
	stream->setStr(ui->lineEditStudentGroup->text());
	stream->setStr(ui->lineEditStudentNum->text());
	stream->setStr(ui->lineEditTeacherFIO->text());
}

void QLabReportWgt::openData(QFileWorker* stream)
{
	ui->lineEditStudentFIO->setText(stream->getStr());
	ui->lineEditStudentGroup->setText(stream->getStr());
	ui->lineEditStudentNum->setText(stream->getStr());
	ui->lineEditTeacherFIO->setText(stream->getStr());
}

QLabReportWgt::~QLabReportWgt()
{
	delete ui;
}

void QLabReportWgt::setReportData()
{

}

void QLabReportWgt::getReportData()
{

}
