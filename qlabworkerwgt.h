#ifndef QLABWORKERWGT_H
#define QLABWORKERWGT_H

#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTabWidget>
#include <QTabBar>
#include <QWheelEvent>
#include <QKeyEvent>

#include "qlabdatabase.h"
#include "qfileworker.h"
#include "qlabcarnocardwgt.h"

namespace Ui {
class QLabWorkerWgt;
}

class QTabBarWgt : public QTabBar
{
    Q_OBJECT

public:
    explicit QTabBarWgt(QWidget *parent = 0);

signals:
    void tabsChange(int, int);

protected:
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event) {event->accept();}
    void keyPressEvent(QKeyEvent *event) {event->accept();}

};

class QLabTabWgt : public QTabWidget
{
    Q_OBJECT

public:
    explicit QLabTabWgt(QWidget *parent = 0);

signals:
    void tabsChange(int, int);

};

class QLabWorkerWgt : public QWidget
{
    Q_OBJECT

signals:
    void showWelcomeWgt();

public:
    explicit QLabWorkerWgt(QWidget *parent = 0);
    void connectModules(QLabDataBase *db);
    bool openLab();
    bool saveLab();
    void newLab();


    int getStructureColumnIndex(const QString& triggerType, int tabIndex);
    void updateCarnoCardData();

    QVector<QString> vecTrigger = {"RS", "D", "T", "JK"};
    ~QLabWorkerWgt();

public slots:
    void saveData(QFileWorker* stream);
    void openData(QFileWorker* stream);
    void updateMinimizationTabs(QObject* obj);

protected slots:
    void checkTabs();
    void changeTab(int prev, int next);
    void showErrMsg(int errCode);
    void dataEdited();

private slots:
    void on_pushButtonBack_clicked();
    void on_pushButtonNext_clicked();
    void on_pushButtonSave_clicked();

protected:
    bool currentCardCheck();
    void createCarnoCardTabs(const QStringList& tabNames);

private:
    Ui::QLabWorkerWgt *ui;
    QLabDataBase *currentDB;
    bool isEdited = false;
    QList<QLabCarnoCardWgt*> carnocardWidgets; // Список для хранения созданных виджетов
};

#endif // QLABWORKERWGT_H
