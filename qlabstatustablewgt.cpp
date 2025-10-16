#include "qlabstatustablewgt.h"
#include "ui_qlabstatustablewgt.h"
#include <QDebug>
#include <QtMath>

#include <math.h>
#include "statemanager.h"
QLabStatusTableWgt::QLabStatusTableWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLabStatusTableWgt)
{
    ui->setupUi(this);

    connect(ui->tableWidgetStatusTable, SIGNAL(funcChanged(int, QString)), this, SIGNAL(funcChanged(int, QString)));
    connect(ui->tableWidgetStatusTable, SIGNAL(funcsIsValid()), this, SIGNAL(funcsIsValid()));
    connect(ui->tableWidgetStatusTable, SIGNAL(dataEdited()), this, SIGNAL(dataEdited()));
    connect(this, SIGNAL(setVar(QObject*)), this, SLOT(setLabels(QObject*)));

    //connect(this, SIGNAL(on_pushButtonCheck_3_clicked), ui->tableWidgetStatusTable, SIGNAL(fillTable()));

}

void QLabStatusTableWgt::connectModules(QLabDataBase* db)
{
    currentDB = db;
    //connect(ui->tableWidgetStatusTable, SIGNAL(funcChanged(QString)), this, SIGNAL(funcChanged(QString)));
}

bool QLabStatusTableWgt::isOK()
{
    if (ui->tableWidgetStatusTable->isOK())
        return true;
    else
        return false;
}
void QLabStatusTableWgt::openData(QFileWorker* stream)
{
    qDebug() << "Начало загрузки таблицы состояний...";

    // Используем правильный тип - QStatusTableWgt вместо QTableWidget
    QStatusTableWgt* table = ui->tableWidgetStatusTable;

    // Восстанавливаем размеры таблицы
    int rowCount = stream->getInt();
    int colCount = stream->getInt();

    qDebug() << "Размеры таблицы:" << rowCount << "x" << colCount;

    // Проверяем валидность размеров
    if (rowCount <= 0 || colCount <= 0 || rowCount > 100 || colCount > 100) {
        qWarning() << "Некорректные размеры таблицы:" << rowCount << "x" << colCount;
        return;
    }

    // Устанавливаем размеры таблицы
    table->setRowCount(rowCount);
    table->setColumnCount(colCount);

    // Восстанавливаем данные ячеек
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            QString text = stream->getStr();
            // Создаем ячейку, если ее нет
            if (!table->item(row, col)) {
                QTableWidgetItem* newItem = new QTableWidgetItem(text);
                newItem->setTextAlignment(Qt::AlignCenter);
                table->setItem(row, col, newItem);
            } else {
                table->item(row, col)->setText(text);
            }
        }
    }

    // Восстанавливаем данные из lineEdit
    ui->lineEditStatus->setText(stream->getStr());
    ui->lineEditTrigger->setText(stream->getStr());

    // Восстанавливаем структуру таблицы (заголовки)
    qDebug() << "Восстановление структуры таблицы...";
    table->fillTable();

    // Обновляем StateManager данными из загруженной таблицы
    qDebug() << "Обновление StateManager...";
    QVector<QVector<int>> cells = table->getAllCodeCells();
    bool updateSuccess = table->updateStateCodesFromTable(cells);
    qDebug() << "StateManager update result:" << updateSuccess;

    // Активируем таблицу
    table->setEnabled(true);

    qDebug() << "Таблица состояний успешно загружена";
}
void QLabStatusTableWgt::saveData(QFileWorker* stream)
{
    qDebug() << "Сохранение таблицы состояний...";

    // Используем правильный тип
    QStatusTableWgt* table = ui->tableWidgetStatusTable;

    // Сохраняем размеры таблицы
    stream->setInt(table->rowCount());
    stream->setInt(table->columnCount());

    qDebug() << "Сохранение размеров:" << table->rowCount() << "x" << table->columnCount();

    // Сохраняем данные ячеек
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            QTableWidgetItem* item = table->item(row, col);
            if (item) {
                stream->setStr(item->text());
            } else {
                stream->setStr("");
            }
        }
    }

    // Сохраняем данные из lineEdit
    stream->setStr(ui->lineEditStatus->text());
    stream->setStr(ui->lineEditTrigger->text());

    qDebug() << "Таблица состояний успешно сохранена";
}




QLabStatusTableWgt::~QLabStatusTableWgt()
{
    delete ui;
}

void QLabStatusTableWgt::setLabels(QObject* obj)
{
    ui->labelZero->setText(obj->property("zero").toString());
    ui->labelOne->setText(obj->property("one").toString());

}

QStatusTableWgt::QStatusTableWgt(QWidget *parent) : QTableWidget(parent)
{

    setColumnCount(4);
    setRowCount(10);

    setEnabled(false);

    // Подключение сигналов и слотов
    connect(this, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clickedTableItem(QTableWidgetItem*)));
    connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(sendCurrentSymbol()));
}

void QStatusTableWgt::fillTable()
{
    setEnabled(true);

    // Установка заголовков для "Состояния"
    setSpan(0, 0, 2, 1);
    if (!item(0, 0)) {
        QTableWidgetItem *headerItem1 = new QTableWidgetItem("Состояние");
        headerItem1->setTextAlignment(Qt::AlignCenter);
        headerItem1->setBackground(Qt::gray);
        setItem(0, 0, headerItem1);
    }

    setSpan(0, 1, 1, 3);
    if (!item(0, 1)) {
        QTableWidgetItem *headerItem2 = new QTableWidgetItem("Код");
        headerItem2->setTextAlignment(Qt::AlignCenter);
        headerItem2->setBackground(Qt::gray);
        setItem(0, 1, headerItem2);
    }

    QStatusTableHeaderWgt *headerItem;

    for (int i = 1; i < columnCount(); i++) {
        if (!item(1, i)) {
            setItem(1, i, new QTableWidgetItem(""));
            item(1, i)->setBackground(Qt::gray);
        }

        if (!cellWidget(1, i)) {
            headerItem = new QStatusTableHeaderWgt(this);
            headerItem->setHeaderText(QString("Q<span style=\" vertical-align:sub;\">%1</span>").arg(4-i));
            setCellWidget(1, i, headerItem);
        }
    }

    // Заполнение первого столбца "Состояние"
    for (int i = 2; i < rowCount(); i++) {
        if (!item(i, 0)) {
            setItem(i, 0, new QTableWidgetItem(""));
            item(i, 0)->setBackground(Qt::gray);
            item(i, 0)->setTextAlignment(Qt::AlignCenter);
        }

        if (!cellWidget(i, 0)) {
            headerItem = new QStatusTableHeaderWgt(this);
            headerItem->setHeaderText(QString("a<span style=\" vertical-align:sub;\">%1</span>").arg(i-2));
            setCellWidget(i, 0, headerItem);
        }
    }

    // Заполнение таблицы ячейками "0" только если ячейки пустые
    for (int i = 2; i < rowCount(); i++) {
        for (int j = 1; j < columnCount(); j++) {
            if (!item(i, j)) {
                setItem(i, j, new QTableWidgetItem("0"));
                item(i, j)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}

void QStatusTableWgt::setSymbols(QVector<QString> symbols)
{
    currentSymbols = symbols;
}

bool QStatusTableWgt::isOK()
{
    return true;
}

QString QStatusTableWgt::getTableSymbol(int row)
{
    return item(row, 6)->text() +
            item(row, 7)->text() +
            item(row, 8)->text() +
            item(row, 9)->text() +
            item(row, 10)->text() +
            item(row, 11)->text() +
            item(row, 12)->text();
}

QString QStatusTableWgt::getDBSymbol(QString sym)
{
    if (sym != "*") {
        for (int i = 0; i < currentSymbols.size(); i++)
            if (sym[0] == currentSymbols[i][0])
                return currentSymbols[i].right(7);
        return "";
    } else
        return "*******";
}

void QStatusTableWgt::resizeEvent(QResizeEvent *event)
{
    if (event->size() != event->oldSize())
        adoptColumnsWidth();
    QTableWidget::resizeEvent(event);
}

void QStatusTableWgt::keyPressEvent(QKeyEvent *event)
{
    int row = currentRow();
    int column = currentColumn();
        switch (event->key()) {
            case Qt::Key_Up:
                if (1 < row) {
                    row--;
                } else {
                    row = rowCount() - 1;
                    if (column > 6)
                        column--;
                    else
                        column = 12;
                }
                if (column < 6)
                    column = 6;
                setCurrentCell(row, column);
                break;
            case Qt::Key_Left:
                if (5 != (column - 1)) {
                    column--;
                } else if (1 != row) {
                    row--;
                    column = 12;
                } else {
                    row = rowCount() - 1;
                    column = 12;
                }
                if (column < 6)
                    column = 12;
                setCurrentCell(row, column);
                break;
            case Qt::Key_Right:
                if (columnCount() != (column + 1)) {
                    column++;
                } else if (rowCount() != (row + 1)) {
                    row++;
                    column = 1;
                } else {
                    row = 1;
                    column = 1;
                }
                if (row < 1)
                    row = 1;
                if (column < 6)
                    column = 6;
                setCurrentCell(row, column);
                break;
            case Qt::Key_Down:
                if (rowCount() > (row + 1)) {
                    row++;
                } else {
                    row = 1;
                    if (column < 12)
                        column++;
                    else
                        column = 6;
                }
                if (column < 6)
                    column = 6;
                setCurrentCell(row, column);
                break;
            case Qt::Key_Return:
                if (row > 0 && column > 0)
                    toggleTableItem(row, column);
                break;
            case Qt::Key_Space:
                if (row > 0 && column > 0)
                    toggleTableItem(row, column);
                break;
            case Qt::Key_Delete:
                if (row > 0 && column > 0)
                    deleteTableItem(row, column);
                break;
        }
}

void QStatusTableWgt::toggleTableItem(int row, int column)
{
    if (row > 1 && column > 0){
        if (item(row, column)->text() == "0")
            item(row, column)->setText("1");
        else
            item(row, column)->setText("0");
    }

    isTested = false;
//    sendFunc(column);
    dataEdited();
}

void QStatusTableWgt::deleteTableItem(int row, int column)
{
    if (row > 1 && column > 0) {
        item(row, column)->setText("0");
        isTested = false;
        sendFunc(column);
        dataEdited();
    }
}

void QStatusTableWgt::adoptColumnsWidth()
{
    int newColWidth = 0;

    if (verticalScrollBar()->isVisible())
        newColWidth = (width() - verticalScrollBar()->width()) / columnCount();
    else
        newColWidth = width() / columnCount();

    for (int i = 0; i < columnCount(); i++) {
        setColumnWidth(i, newColWidth - 1);
    }
}

void QStatusTableWgt::sendCurrentSymbol()
{

    if (selectedItems()[0]->row() != lastRow && selectedItems()[0]->row() > 0) {
        lastRow = selectedItems()[0]->row();
//        symbolChanged(getDBSymbol(item(lastRow, 5)->text()));
    }
}

void QStatusTableWgt::sendFunc(int num)
{
    QString func = "";
    for (int i = 1; i < rowCount(); i++)
        func.append(item(i, num)->text());
    funcChanged(num - 6, func);
}

void QStatusTableWgt::clickedTableItem(QTableWidgetItem *item)
{
    if (item != 0)
        toggleTableItem(item->row(), item->column());
}

void QStatusTableWgt::itemKeyPressed(QKeyEvent *event)
{
    keyPressEvent(event);
}

void QStatusTableWgt::setVar(QObject* obj)
{
//    QLabStatusTableWgt->labelZero->setText(currentDB->getVersion());

    //qDebug() << "zero" << obj->property("zero").toString();
    //qDebug() << "one" << obj->property("one").toString();
//    for (int i = 0; i < rowCount() - 1; i++) {
//        item(i + 1, 5)->setText(QString(var[i]));
//        item(i + 1, 5)->setTextAlignment(Qt::AlignCenter);
//        item(i + 1, 5)->setBackground(Qt::gray);
//    }

    setCurrentCell(1, 6);
}

void QStatusTableHeaderWgt::setHeaderText(QString text)
{
    setHtml(text);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::NoFrame);
    viewport()->setAutoFillBackground(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void QLabStatusTableWgt::on_pushButtonCheck_clicked()
{


    qDebug() << "Button Pushed";
    showErrMsg();
}

void QLabStatusTableWgt::showErrMsg(int errCode)
{
    QString title;
    if (errCode == 0)
        title = "Таблица заполнена верно!";
    else
        title = "Таблица заполнена неверно!";

    QMessageBox msg(errCode == 0 ? QMessageBox::Information : QMessageBox::Warning,
                    "Внимание!",
                    title,
                    QMessageBox::Cancel);
    msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
    msg.exec();
}

void QLabStatusTableWgt::showErrMsgStatusAndTrigger(int errCode)
{
    QString title;
    if (errCode == 0)
        title = "Количество состояний и количество триггеров соответствует варианту";
    else
        title = "Количество состояний либо  количество триггеров не соответствуют варианту!";

    QMessageBox msg(errCode == 0 ? QMessageBox::Information : QMessageBox::Warning,
                    "Внимание!",
                    title,
                    QMessageBox::Cancel);
    msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
    msg.exec();
}

void QLabStatusTableWgt::showErrMsg()
{
    qDebug() << "=== Starting state table validation ===";

    QVector<QVector<int>> cells = {{2,1},{2,2},{2,3},{3,1},{3,2},{4,1},{4,3},{5,1},{6,2},{6,3},{7,2},{8,3},
                                   {3,3},{4,2},{5,2},{5,3},{6,1},{7,1},{7,3},{8,1},{8,2},{9,1},{9,2},{9,3}};

    // Проверяем, заполнена ли таблица
    if (!ui->tableWidgetStatusTable->isEnabled()) {
        qCritical() << "Table is not filled! Please fill the table first.";
        QMessageBox::warning(this, "Ошибка", "Таблица не заполнена! Сначала заполните таблицу.");
        return;
    }

    // ИСПРАВЛЕНИЕ: Убрана проверка stateManager.isInitialized()
    // потому что StateManager очищается в updateStateCodesFromTable()

    // Проверяем, что StateManager доступен
    qDebug() << "StateManager instance:" << &stateManager;

    // Сначала обновляем коды в StateManager
    qDebug() << "Updating state codes from table...";
    bool updateSuccess = ui->tableWidgetStatusTable->updateStateCodesFromTable(cells);
    qDebug() << "Update result:" << updateSuccess;

    if (updateSuccess) {
        // Затем проверяем на дубликаты
        qDebug() << "Checking for duplicate codes...";
        bool hasDuplicates = stateManager.hasDuplicateCodes();
        qDebug() << "Duplicate check result:" << hasDuplicates;

        if (!hasDuplicates) {
            qDebug() << "Validation PASSED - no duplicate codes";
            showErrMsg(0); // Нет ошибок - уникальные коды
        } else {
            qDebug() << "Validation FAILED - duplicate codes found";
            showErrMsg(1); // Есть дубликаты
        }
    } else {
        qDebug() << "Validation FAILED - error updating codes";
        showErrMsg(1); // Ошибка при обновлении кодов
    }

    qDebug() << "=== State table validation completed ===";
}

QVector<QVector<int>> QStatusTableWgt::getAllCodeCells()
{
    QVector<QVector<int>> cells;

    // Предполагаем, что состояния начинаются с строки 2, а коды - с столбца 1
    int startRow = 2;
    int startCol = 1;

    for (int row = startRow; row < rowCount(); ++row) {
        for (int col = startCol; col < columnCount(); ++col) {
            cells.append({row, col});
        }
    }

    qDebug() << "Generated cells for StateManager:" << cells.size() << "cells";
    return cells;
}

bool QStatusTableWgt::updateStateCodesFromTable(const QVector<QVector<int>> &cells)
{
    qDebug() << "Starting updateStateCodesFromTable...";

    // Очищаем предыдущие коды
    stateManager.clear();

    // Группируем ячейки по строкам (состояниям)
    QMap<int, QMap<int, int>> stateData; // row -> (col -> value)

    // Собираем данные из таблицы
    for (const auto& cell : cells) {
        if (cell.size() < 2) continue;

        int row = cell[0];
        int col = cell[1];

        // Используем this, поскольку этот метод вызывается из QStatusTableWgt
        QTableWidgetItem* tableItem = item(row, col);
        if (!tableItem) {
            qWarning() << "Item not found at row" << row << "col" << col;
            continue;
        }

        QString valueStr = tableItem->text();
        qDebug() << "Cell [" << row << "," << col << "] =" << valueStr;

        // Преобразуем строку в число (0 или 1)
        bool ok;
        int value = valueStr.toInt(&ok);
        if (!ok || (value != 0 && value != 1)) {
            qWarning() << "Invalid cell value at row" << row << "col" << col << ":" << valueStr;
            return false;
        }

        stateData[row][col] = value;
    }

    // Формируем коды для каждого состояния
    for (auto it = stateData.begin(); it != stateData.end(); ++it) {
        int tableRow = it.key(); // Строка в таблице (2, 3, 4, ...)

        // ИСПРАВЛЕНИЕ: Преобразуем номер строки в индекс состояния
        // Строка 2 -> состояние a0, строка 3 -> состояние a1, и т.д.
        int stateIndex = tableRow - 2;

        if (stateIndex < 0) {
            qWarning() << "Invalid state index for table row" << tableRow;
            continue;
        }

        QVector<int> code;

        // Сортируем столбцы для правильного порядка битов
        QList<int> columns = it->keys();
        std::sort(columns.begin(), columns.end());

        for (int col : columns) {
            code.append((*it)[col]);
        }

        // Сохраняем код в StateManager
        stateManager.setStateCode(stateIndex, code);

        qDebug() << "State a" << stateIndex << "(table row" << tableRow << ") code:" << code;
    }

    qDebug() << "updateStateCodesFromTable completed successfully";
    qDebug() << "Total states in StateManager:" << stateManager.getAllStateCodes().size();
    return true;
}

void QLabStatusTableWgt::on_pushButtonCheck_3_clicked()
{
    int quantityStatus = ui->lineEditStatus->text().toInt();
    int quantityTrigger = ui->lineEditTrigger->text().toInt();

    // Разделение строки на массив по пробелам
    QStringList elementZero = ui->labelZero->text().split(' ', Qt::SkipEmptyParts);
    QStringList elementOne = ui->labelOne->text().split(' ', Qt::SkipEmptyParts);




    // Подсчет количества элементов в массиве
    int maxElements = elementZero.count() > elementOne.count() ? elementZero.count() : elementOne.count();

    qDebug() << qRound(qLn(maxElements) / qLn(2));
    int exponent = qRound(qLn(maxElements) / qLn(2));

    if (quantityStatus == maxElements && exponent == quantityTrigger){
        showErrMsgStatusAndTrigger(0);
        ui->tableWidgetStatusTable->fillTable();
    }else{
        showErrMsgStatusAndTrigger(1);
    }

}


// void QLabStatusTableWgt::openData(QFileWorker* stream)
// {
//     // Восстанавливаем данные таблицы состояний
//     QTableWidget* table = ui->tableWidgetStatusTable;

//     // Восстанавливаем размеры таблицы
//     int rowCount = stream->getInt();
//     int colCount = stream->getInt();

//     // Устанавливаем размеры таблицы
//     table->setRowCount(rowCount);
//     table->setColumnCount(colCount);

//     // Восстанавливаем данные ячеек
//     for (int row = 0; row < rowCount; ++row) {
//         for (int col = 0; col < colCount; ++col) {
//             QString text = stream->getStr();
//             QTableWidgetItem* item = new QTableWidgetItem(text);
//             item->setTextAlignment(Qt::AlignCenter);
//             table->setItem(row, col, item);
//         }
//     }

//     // Восстанавливаем данные из lineEdit
//     ui->lineEditStatus->setText(stream->getStr());
//     ui->lineEditTrigger->setText(stream->getStr());

//     // Активируем таблицу
//     table->setEnabled(true);
// }

// void QStatusTableWgt::fillTable()
// {

//     setEnabled(true);

//     // Установка заголовков для "Состояния"
//     setSpan(0, 0, 2, 1);
//     QTableWidgetItem *headerItem1 = new QTableWidgetItem("Состояние");
//     headerItem1->setTextAlignment(Qt::AlignCenter);
//     headerItem1->setBackground(Qt::gray);
//     setItem(0, 0, headerItem1);


//     setSpan(0, 1, 1, 3); // объединяем ячейки для заголовка "Код"
//     QTableWidgetItem *headerItem2 = new QTableWidgetItem("Код");
//     headerItem2->setTextAlignment(Qt::AlignCenter);
//     headerItem2->setBackground(Qt::gray);
//     setItem(0, 1, headerItem2);

//     QStatusTableHeaderWgt *headerItem;

//     for (int i = 1; i < columnCount(); i++) {
//         setItem(1, i, new QTableWidgetItem(""));
//         item(1, i)->setBackground(Qt::gray);

//         headerItem = new QStatusTableHeaderWgt(this);
//         headerItem->setHeaderText(QString("Q<span style=\" vertical-align:sub;\">%1</span>").arg(4-i));
//         setCellWidget(1, i, headerItem);
//     }

//     // Заполнение первого столбца "Состояние"
//     for (int i = 2; i < rowCount(); i++) {
//         setItem(i, 0, new QTableWidgetItem(""));
//         item(i, 0)->setBackground(Qt::gray);
//         item(i, 0)->setTextAlignment(Qt::AlignCenter);

//         headerItem = new QStatusTableHeaderWgt(this);
//         headerItem->setHeaderText(QString("a<span style=\" vertical-align:sub;\">%1</span>").arg(i-2));
//         setCellWidget(i, 0, headerItem);
//     }

//    // Заполнение таблицы ячейками "0" для подстолбцов в "Код"
//    for (int i = 2; i < rowCount(); i++) {
//        for (int j = 1; j < columnCount(); j++) {
//            setItem(i, j, new QTableWidgetItem("0"));
//            item(i, j)->setTextAlignment(Qt::AlignCenter);
//        }
//    }
// }


// LEGACY
// bool QStatusTableWgt::checkCells(const QVector<QVector<int>> &cells, const QVector<QString> &expectedValues)
// {
//     bool allMatch = true;
//     for (int i = 0; i < cells.size(); ++i)
//     {
//         int row = cells[i][0];
//         int col = cells[i][1];
//         QString currentVal = item(row, col)->text();

//         if (currentVal != expectedValues[i])
//         {

//             allMatch = false;
//             // Можно вывести предупреждение, если нужно.
//         }

//     }
//     return allMatch;
// }
