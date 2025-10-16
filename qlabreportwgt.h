#ifndef QLABREPORTWGT_H
#define QLABREPORTWGT_H

#include <QWidget>

#include "qfileworker.h"

namespace Ui {
class QLabReportWgt;
}

class QLabReportWgt : public QWidget
{
	Q_OBJECT

public:
	explicit QLabReportWgt(QWidget *parent = 0);
	void saveData(QFileWorker* stream);
	void openData(QFileWorker* stream);
	~QLabReportWgt();

signals:
	void dataEdited();

public slots:
	void setReportData();
	void getReportData();

private:
	Ui::QLabReportWgt *ui;
};

#endif // QLABREPORTWGT_H
