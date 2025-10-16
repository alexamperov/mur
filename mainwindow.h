#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QLayout>
#include <QScreen>

#include "qwelcomewgt.h"
#include "qlabworkerwgt.h"

#include "qlabdatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
	void showLabChoseWgt();
	void showLabOpenWgt();
	void showWelcomeWgt();

protected:
	void destroyWelcome();
	void destroyLabWorker();

private:
    Ui::MainWindow *ui;
    QLabDataBase currentDB;
	QWelcomeWgt* welcomeScr;
	QLabWorkerWgt* labWorkerScr;
	QSize welcomeSize;
	QSize workerSize;
};

#endif // MAINWINDOW_H
