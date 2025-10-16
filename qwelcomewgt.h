#ifndef QWELCOMEWGT_H
#define QWELCOMEWGT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "qlabdatabase.h"

namespace Ui {
    class QWelcomeWgt;
}

class QWelcomeWgt : public QWidget
{
    Q_OBJECT

    signals:
        void newBtnClicked();
        void openBtnClicked();
        void dbState(bool);

    public slots:
        void setEnabled(bool state);

    public:
        explicit QWelcomeWgt(QWidget *parent = 0);
        void connectModules(QLabDataBase *db);
        ~QWelcomeWgt();

    protected:
        void setDBVersion();
        void setAppVersion();

    private:
        Ui::QWelcomeWgt *ui;
        QLabDataBase *currentDB;
};

#endif // QWELCOMEWGT_H
