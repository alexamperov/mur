#include "qlabworkerwgt.h"
#include "ui_qlabworkerwgt.h"

#include "qlabworkerwgt.h"
#include "ui_qlabworkerwgt.h"

#include "qlabworkerwgt.h"
#include "ui_qlabworkerwgt.h"

QLabWorkerWgt::QLabWorkerWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLabWorkerWgt)
{
    ui->setupUi(this);

    connect(ui->wgtLabChose, SIGNAL(varChanged(QObject*)), ui->wgtStatusTable, SIGNAL(setVar(QObject*)));
    connect(ui->wgtLabChose, SIGNAL(varChanged(QObject*)), ui->wgtTransitionTable, SIGNAL(setVar(QObject*)));
    connect(ui->wgtLabChose, SIGNAL(varChanged(QObject*)), ui->wgtStructureTable, SIGNAL(setVar(QObject*)));
    connect(ui->wgtLabChose, SIGNAL(varChanged(QObject*)), this, SLOT(updateMinimizationTabs(QObject*)));

    connect(ui->wgtLabChose, SIGNAL(dataEdited()), this, SLOT(dataEdited()));
    connect(ui->wgtStatusTable, SIGNAL(dataEdited()), this, SLOT(dataEdited()));
    connect(ui->wgtStructureTable, SIGNAL(dataEdited()), this, SLOT(dataEdited()));
    connect(ui->wgtReport, SIGNAL(dataEdited()), this, SLOT(dataEdited()));

    connect(ui->tabWidget, SIGNAL(tabsChange(int,int)), this, SLOT(changeTab(int,int)));

    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(3, false);
    ui->tabWidget->setTabEnabled(4, false);
    ui->tabWidget->setTabEnabled(5, false);
}
void QLabWorkerWgt::updateCarnoCardData()
{
    // Получаем тип триггера
    int trigger_index = ui->wgtLabChose->property("trigger").toInt();
    QString triggerType = vecTrigger.at(trigger_index);

    qDebug() << "=== UPDATING CARNO CARD DATA ===";
    qDebug() << "Trigger type:" << triggerType;
    qDebug() << "Number of carno cards:" << carnocardWidgets.size();

    // Получаем таблицу из виджета структуры
    QStructureTableWgt* structureTableWidget = ui->wgtStructureTable->findChild<QStructureTableWgt*>();
    if (!structureTableWidget) {
        qWarning() << "Could not find structure table widget for update!";
        return;
    }

    // Находим tabWidget_2
    QTabWidget* minimizationTabWidget = ui->tabCarnoCard3->findChild<QTabWidget*>("tabWidget_2");
    if (!minimizationTabWidget) {
        qWarning() << "Could not find tabWidget_2 in minimization tab";
        return;
    }

    // Обновляем данные во всех картах Карно
    for (int i = 0; i < carnocardWidgets.size(); i++) {
        int structureColumnIndex = getStructureColumnIndex(triggerType, i);
        QString triggerInputName = minimizationTabWidget->tabText(i);

        qDebug() << "Updating card" << i << "with trigger input:" << triggerInputName << "column index:" << structureColumnIndex;

        // Сначала очищаем данные
        carnocardWidgets[i]->clearTableData();

        // Затем заполняем новыми данными
        carnocardWidgets[i]->setStructureData(structureTableWidget, structureColumnIndex, triggerInputName);
    }

    qDebug() << "=== CARNO CARD DATA UPDATE COMPLETE ===";
}
// qlabworkerwgt.cpp
void QLabWorkerWgt::createCarnoCardTabs(const QStringList& tabNames)
{



    // Находим tabWidget_2
    QTabWidget* minimizationTabWidget = ui->tabCarnoCard3->findChild<QTabWidget*>("tabWidget_2");
    if (!minimizationTabWidget) {
        qWarning() << "Could not find tabWidget_2 in minimization tab";
        return;
    }

    // Очищаем существующие вкладки
    minimizationTabWidget->clear();
    carnocardWidgets.clear();

    // Получаем тип триггера для определения индексов столбцов
    int trigger_index = ui->wgtLabChose->property("trigger").toInt();
    QString triggerType = vecTrigger.at(trigger_index);

    // Получаем таблицу из виджета структуры
    QStructureTableWgt* structureTableWidget = ui->wgtStructureTable->findChild<QStructureTableWgt*>();
    if (!structureTableWidget) {
        qWarning() << "Could not find structure table widget!";
        return;
    }
    // Создаем новые вкладки
    for (int i = 0; i < tabNames.size(); i++) {
        QLabCarnoCardWgt* card = new QLabCarnoCardWgt();
        carnocardWidgets.append(card);
        minimizationTabWidget->addTab(card, tabNames[i]);

        // Определяем индекс столбца в структурной таблице для этой вкладки
        int structureColumnIndex = getStructureColumnIndex(triggerType, i);

        // Передаем данные из структурной таблицы с именем входа
        card->setStructureData(structureTableWidget, structureColumnIndex, tabNames[i]);
    }

    qDebug() << "Created" << tabNames.size() << "minimization tabs:" << tabNames;
}

int QLabWorkerWgt::getStructureColumnIndex(const QString& triggerType, int tabIndex)
{
    // Базовый индекс для функций возбуждения в структурной таблице
    int baseColumn = 9;

    if (triggerType == "RS") {
        // Для RS: R3, S3, R2, S2, R1, S1 (колонки 9-14)
        return baseColumn + tabIndex;
    }
    else if (triggerType == "D") {
        // Для D: D3, D2, D1 (колонки 9-11)
        return baseColumn + tabIndex;
    }
    else if (triggerType == "T") {
        // Для T: T3, T2, T1 (колонки 9-11)
        return baseColumn + tabIndex;
    }
    else if (triggerType == "JK") {
        // Для JK: J3, K3, J2, K2, J1, K1 (колонки 9-14)
        return baseColumn + tabIndex;
    }

    return baseColumn + tabIndex; // fallback
}

void QLabWorkerWgt::updateMinimizationTabs(QObject* obj)
{
    qDebug() << "Updating minimization tabs for trigger type...";

    // Получаем тип триггера из варианта
    int trigger_index = obj->property("trigger").toInt();
    QVector<QString> vecTrigger = {"RS", "D", "T", "JK"};
    QString triggerType = vecTrigger.at(trigger_index);

    qDebug() << "Trigger type for minimization:" << triggerType;

    // Создаем вкладки в зависимости от типа триггера
    if (triggerType == "RS") {
        createCarnoCardTabs({"R3", "S3", "R2", "S2", "R1", "S1"});
    }
    else if (triggerType == "D") {
        createCarnoCardTabs({"D3", "D2", "D1"});
    }
    else if (triggerType == "T") {
        createCarnoCardTabs({"T3", "T2", "T1"});
    }
    else if (triggerType == "JK") {
        createCarnoCardTabs({"J3", "K3", "J2", "K2", "J1", "K1"});
    }

    qDebug() << "Updated minimization tabs for" << triggerType;
}

QLabWorkerWgt::~QLabWorkerWgt()
{
    if (isEdited) {
        QMessageBox msg(QMessageBox::Warning,
                        "Внимание!",
                        "Все несохранённые данные будут утеряны!\n"
                        "Сохранить перед закрытием?",
                        QMessageBox::Yes | QMessageBox::No);
        msg.setButtonText(QMessageBox::Yes, "&Да");
        msg.setButtonText(QMessageBox::No, "&Нет");
        msg.setDefaultButton(QMessageBox::Yes);

        if (msg.exec() == QMessageBox::Yes)
            on_pushButtonSave_clicked();
    }
    delete ui;
}

void QLabWorkerWgt::showErrMsg(int errCode)
{
    QString title;
    bool msgType = false;
    if (errCode == 1)
        title = "Ошибка открытия файла на чтение!";
    else if (errCode == 2)
        title = "Файл не соответствует формату!";
    else if (errCode == 3)
        title = "Ошибка открытия файла на запись!";
    else if (errCode == 4) {
        msgType = true;
        title = "Данные сохранены!";
    }

    QMessageBox msg(msgType ? QMessageBox::Information : QMessageBox::Warning,
                    "Внимание!",
                    title,
                    QMessageBox::Cancel);
    msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
    msg.exec();
}

void QLabWorkerWgt::dataEdited()
{
    isEdited = true;
}

void QLabWorkerWgt::saveData(QFileWorker* stream)
{
    // Состояние вкладок
    for (int i = 0; i < ui->tabWidget->count(); i++)
        stream->setInt(ui->tabWidget->isTabEnabled(i));
    stream->setInt(ui->tabWidget->currentIndex());

    // Данные в порядке вкладок
    ui->wgtLabChose->saveData(stream);

    if (ui->tabWidget->isTabEnabled(1)) {
        ui->wgtStatusTable->saveData(stream);
    }
    if (ui->tabWidget->isTabEnabled(2)) {
        ui->wgtTransitionTable->saveData(stream);
    }
    if (ui->tabWidget->isTabEnabled(3)) {
        ui->wgtStructureTable->saveData(stream);
    }

    ui->wgtReport->saveData(stream);
}

void QLabWorkerWgt::openData(QFileWorker* stream)
{
    qDebug() << "=== НАЧАЛО ЗАГРУЗКИ ДАННЫХ ===";

    // Восстанавливаем состояние вкладок
    for (int i = 0; i < ui->tabWidget->count(); i++) {
        bool enabled = stream->getInt();
        ui->tabWidget->setTabEnabled(i, enabled);
        qDebug() << "Вкладка" << i << (enabled ? "включена" : "выключена");
    }

    int currentTab = stream->getInt();
    ui->tabWidget->setCurrentIndex(currentTab);
    qDebug() << "Текущая вкладка:" << currentTab;

    // Восстанавливаем данные всех виджетов
    qDebug() << "--- Загрузка данных выбора варианта ---";
    ui->wgtLabChose->openData(stream);

    // Восстанавливаем таблицы, если они были активны
    if (ui->tabWidget->isTabEnabled(1)) {
        qDebug() << "--- Загрузка таблицы состояний ---";
        ui->wgtStatusTable->openData(stream);
    }
    if (ui->tabWidget->isTabEnabled(2)) {
        qDebug() << "--- Загрузка таблицы переходов ---";
        ui->wgtTransitionTable->openData(stream);
    }
    if (ui->tabWidget->isTabEnabled(3)) {
        qDebug() << "--- Загрузка структурной таблицы ---";
        ui->wgtStructureTable->openData(stream);
    }

    qDebug() << "--- Загрузка отчета ---";
    ui->wgtReport->openData(stream);

    isEdited = false;
    qDebug() << "=== ЗАГРУЗКА ДАННЫХ ЗАВЕРШЕНА УСПЕШНО ===";
}

void QLabWorkerWgt::checkTabs()
{

}

// qlabworkerwgt.cpp
void QLabWorkerWgt::changeTab(int prev, int next)
{
    if (next != -1) {
        bool isOk = true;
        if (next > prev) {
            switch (next) {
            case 1:
                if (ui->wgtLabChose->isOK())
                    isOk = true;
                break;
            case 2:
                if (ui->wgtLabChose->isOK() && ui->wgtStatusTable->isOK())
                    isOk = true;
                break;
            case 3:
                if (ui->wgtLabChose->isOK() &&
                    ui->wgtStatusTable->isOK() && ui->wgtTransitionTable->isOK())
                    isOk = true;
                break;
            case 4: // Вкладка минимизации
                if (ui->wgtLabChose->isOK() && ui->wgtStatusTable->isOK())
                {
                    // Обновляем данные в картах Карно при переходе на вкладку
                    updateCarnoCardData();
                    isOk = true;
                }
                break;
                // ... остальные case
            }
        } else {
            isOk = true;
        }

        if (isOk) {
            ui->tabWidget->setTabEnabled(next, true);
            ui->tabWidget->setCurrentIndex(next);
        } else {
            QMessageBox msg(QMessageBox::Warning,
                            "Внимание!",
                            "Для перехода на эту вкладку, заполните и проверьте данные в предыдущих!",
                            QMessageBox::Cancel);
            msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
            msg.exec();
        }
    }
}

void QLabWorkerWgt::connectModules(QLabDataBase *db)
{
    currentDB = db;
    ui->wgtLabChose->connectModules(currentDB);
    ui->wgtStatusTable->connectModules(currentDB);
    ui->wgtTransitionTable->connectModules(currentDB);
    ui->wgtStructureTable->connectModules(currentDB);
//	ui->wgtCarnoCard1->setFuncNum(0);
//	ui->wgtCarnoCard2->setFuncNum(1);
//	ui->wgtCarnoCard3->setFuncNum(2);
//	ui->wgtCarnoCard4->setFuncNum(3);
//	ui->wgtCarnoCard5->setFuncNum(4);
//	ui->wgtCarnoCard6->setFuncNum(5);
//	ui->wgtCarnoCard7->setFuncNum(6);

//	connect(ui->wgtLabChose, SIGNAL(isOK()), this, SLOT(enableSaveBtn()));
}

bool QLabWorkerWgt::openLab()
{
    QString fn = QFileDialog::getOpenFileName(this, "Выберите файл", "", "*.pam-calc");
    if (0 < fn.length()) {
        if (!fn.endsWith(".pam-calc", Qt::CaseInsensitive))
            fn += ".pam-calc";
        QFileWorker stream;
        if (stream.openFile(fn, QIODevice::ReadOnly)) {
            QString fileHeader = stream.getStr();
            if (fileHeader == "pam-calc") {
                qDebug() << "Файл открыт, заголовок верный";
                openData(&stream);
                stream.closeFile();
                return true;
            } else {
                qDebug() << "Неверный заголовок файла:" << fileHeader;
                showErrMsg(2);
            }
        } else {
            qDebug() << "Ошибка открытия файла:" << fn;
            showErrMsg(1);
        }
    }
    return false;
}

bool QLabWorkerWgt::saveLab()
{
    QString fn = QFileDialog::getSaveFileName(this, "Выберите файл", "", "*.pam-calc");
    if (0 < fn.length()) {
        if (!fn.endsWith(".pam-calc", Qt::CaseInsensitive))
            fn += ".pam-calc";
        QFileWorker stream;
        if (stream.openFile(fn, QIODevice::WriteOnly)) {
            stream.setStr("pam-calc");
            saveData(&stream);
            stream.closeFile();
            isEdited = false;
            showErrMsg(4);
            return true;
        } else
            showErrMsg(3);
    }
    return false;
}

void QLabWorkerWgt::newLab()
{

}

void QLabWorkerWgt::on_pushButtonBack_clicked()
{
    if (ui->tabWidget->currentWidget() == ui->tabLabChose) {
        if (1) {
            if (isEdited) {
                QMessageBox msg(QMessageBox::Warning,
                                "Внимание!",
                                "Вы действительно хотите закрыть текущую лабораторную работу?!",
                                QMessageBox::Yes | QMessageBox::No);
                msg.setButtonText(QMessageBox::Yes, "&Да");
                msg.setButtonText(QMessageBox::No, "&Нет");
                msg.setDefaultButton(QMessageBox::No);

                if (msg.exec() == QMessageBox::Yes)
                    showWelcomeWgt();
            } else
                showWelcomeWgt();
        } else {
            showWelcomeWgt();
        }
    } else {
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() - 1);
    }
}

void QLabWorkerWgt::on_pushButtonNext_clicked()
{
    if (ui->tabWidget->currentIndex() == 0) {
        if (ui->wgtLabChose->isOK()) {
            ui->tabWidget->setTabEnabled(1, true);
            ui->tabWidget->setCurrentIndex(1);
            return;
        }
    } else if (ui->tabWidget->currentIndex() == 1) {
        if (ui->wgtStatusTable->isOK()) {
            ui->tabWidget->setTabEnabled(2, true);
            ui->tabWidget->setCurrentIndex(2);
            return;
        }
    } /*else if (ui->tabWidget->currentIndex() == 2) {
        if (ui->wgtCarnoCard1->isOK()) {
            ui->tabWidget->setTabEnabled(3, true);
            ui->tabWidget->setCurrentIndex(3);
            return;
        }
    } else if (ui->tabWidget->currentIndex() == 3) {
        if (ui->wgtCarnoCard2->isOK()) {
            ui->tabWidget->setTabEnabled(4, true);
            ui->tabWidget->setCurrentIndex(4);
            return;
        }
    } else if (ui->tabWidget->currentIndex() == 4) {
        if (ui->wgtCarnoCard3->isOK()) {
            ui->tabWidget->setTabEnabled(5, true);
            ui->tabWidget->setCurrentIndex(5);
            return;
        }
    } else if (ui->tabWidget->currentIndex() == 5) {
        if (ui->wgtCarnoCard4->isOK()) {
            ui->tabWidget->setTabEnabled(6, true);
            ui->tabWidget->setCurrentIndex(6);
            return;
        }
    } else if (ui->tabWidget->currentIndex() == 6) {
        if (ui->wgtCarnoCard5->isOK()) {
            ui->tabWidget->setTabEnabled(7, true);
            ui->tabWidget->setCurrentIndex(7);
            return;
        }
    } else if (ui->tabWidget->currentIndex() == 7) {
        if (ui->wgtCarnoCard6->isOK()) {
            ui->tabWidget->setTabEnabled(8, true);
            ui->tabWidget->setCurrentIndex(8);
            return;
        }
    } else if (ui->tabWidget->currentIndex() == 8) {
        if (ui->wgtCarnoCard7->isOK()) {
            ui->tabWidget->setTabEnabled(9, true);
            ui->tabWidget->setCurrentIndex(9);
            return;
        }
    }*/

    if (ui->tabWidget->currentIndex() == 0) {
        QMessageBox msg(QMessageBox::Warning,
                        "Внимание!",
                        "Для прехода на следующую вкладку, введите вариант лабораторной работы и нажмите \"Применить\"!",
                        QMessageBox::Cancel);
        msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
        msg.exec();
    } else if (ui->tabWidget->currentIndex() != 9) {
        QMessageBox msg(QMessageBox::Warning,
                        "Внимание!",
                        "Для прехода на следующую вкладку, заполните и проверьте данные!",
                        QMessageBox::Cancel);
        msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
        msg.exec();
    }
}

QLabTabWgt::QLabTabWgt(QWidget *parent) : QTabWidget(parent)
{
    QTabBarWgt* newTabBar = new QTabBarWgt(this);
    connect(newTabBar, SIGNAL(tabsChange(int,int)), this, SIGNAL(tabsChange(int,int)));
    setTabBar(newTabBar);
}

QTabBarWgt::QTabBarWgt(QWidget *parent) : QTabBar(parent)
{

}

void QTabBarWgt::mousePressEvent(QMouseEvent *event)
{
    tabsChange(currentIndex(), tabAt(event->pos()));
}

void QLabWorkerWgt::on_pushButtonSave_clicked()
{
    saveLab();
}
