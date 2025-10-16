#include "qlabstructuretablewgt.h"
#include "ui_qlabstructuretablewgt.h"
#include <QDebug>
#include <QtMath>
#include <QVector>
#include <math.h>

QLabStructureTableWgt::QLabStructureTableWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLabStructureTableWgt)
{
    ui->setupUi(this);
    m_structureTable = ui->tableWidgetStructureTable;
    // int trigger_index = obj->property("trigger").toInt();
    // QString triggerType = vecTrigger.at(trigger_index);
    // qDebug() << "Type of trigger in structure table: " << triggerType << trigger_index;
    connect(this, SIGNAL(setVar(QObject*)), this, SLOT(setLabels1(QObject*)));
    //qDebug() << "Таблица построена: " ;
}



void QLabStructureTableWgt::connectModules(QLabDataBase* db)
{
    currentDB = db;
}

void QStructureTableWgt::connectModules1(QLabDataBase* db)
{
    currentDB = db;
}

void QLabStructureTableWgt::setLabels1(QObject* obj)
{
    ui->labelZero->setText(obj->property("zero").toString());
    ui->labelOne->setText(obj->property("one").toString());
    Convertation(obj);

    // Получаем тип триггера и обновляем таблицу
    int trigger_index = obj->property("trigger").toInt();
    QString triggerType = ui->tableWidgetStructureTable->vecTrigger.at(trigger_index);
    ui->tableWidgetStructureTable->updateTableForTriggerType(triggerType);

}

bool QLabStructureTableWgt::isOK()
{
    if (ui->tableWidgetStructureTable->isOK())
        return true;
    else
        return false;
}

bool QStructureTableWgt::isOK()
{

    return true;
}

void QStructureTableWgt::updateTableForTriggerType(const QString& triggerTypeInput)
{

    triggerType = triggerTypeInput;
    qDebug() << "Updating table for trigger type:" << triggerType;

    // Очищаем таблицу полностью
    clear();
    setRowCount(0);
    setColumnCount(0);

    // Устанавливаем правильное количество столбцов в зависимости от типа триггера
    int excitationColumnsCount;
    if (triggerType == "D" || triggerType == "T") {
        excitationColumnsCount = 3; // D3,D2,D1 или T3,T2,T1
    } else { // RS или JK
        excitationColumnsCount = 6; // R3,S3,R2,S2,R1,S1 или J3,K3,J2,K2,J1,K1
    }

    // ОБЩЕЕ КОЛИЧЕСТВО КОЛОНОК: базовые колонки + колонки функций возбуждения
    setColumnCount(9 + excitationColumnsCount);
    setRowCount(18);

    // Заполняем ячейки
    for (int i = 0; i < rowCount(); i++) {
        for (int j = 0; j < columnCount(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem("");
            item->setTextAlignment(Qt::AlignCenter);
            if (j != 4) item->setFlags(item->flags() & ~Qt::ItemIsEditable);

            if (i > 1 && j != 0 && j != 4 && j != 8){
                item->setText("0");
            } else {
                item->setText("");
            }
            setItem(i, j, item);
        }
    }

    // Пересоздаем всю структуру таблицы
    QTableWidgetItem *headerItemText;
    QStructureTableHeaderWgt *headerItem;

    setSpan(0, 0, 2, 1);
    headerItemText = new QTableWidgetItem("Исх. сост.");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    headerItemText->setFlags(headerItemText->flags() & ~Qt::ItemIsEditable);
    setItem(0, 0, headerItemText);

    // Заполнение первого столбца под "Исходящее состояние"
    int init_state = 0;
    for (int i = 2; i < rowCount(); i++) {
        if (i == 10){
            init_state = 0;
        }
        headerItem = new QStructureTableHeaderWgt(this);
        headerItem->setHeaderText(QString("a%1").arg(init_state));
        setCellWidget(i, 0, headerItem);
        init_state++;
    }

    setSpan(0, 1, 1, 3);
    headerItemText = new QTableWidgetItem("Код исх. сост.");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    headerItemText->setFlags(headerItemText->flags() & ~Qt::ItemIsEditable);
    setItem(0, 1, headerItemText);

    // Заполнение под стройкой "Код исходного состояния"
    for (int i = 1; i < 4; i++) {
        headerItem = new QStructureTableHeaderWgt(this);
        headerItem->setHeaderText(QString("Q<span style=\" vertical-align:sub;\">%1</span>").arg(4 - i));
        setCellWidget(1, i, headerItem);
    }

    setSpan(0, 4, 2, 1);
    headerItemText = new QTableWidgetItem("След. сост");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    headerItemText->setFlags(headerItemText->flags() & ~Qt::ItemIsEditable);
    setItem(0, 4, headerItemText);

    setSpan(0, 5, 1, 3);
    headerItemText = new QTableWidgetItem("Код след. сост.");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    headerItemText->setFlags(headerItemText->flags() & ~Qt::ItemIsEditable);
    setItem(0, 5, headerItemText);

    // Заполнение под стройкой "Код следующего состояния"
    for (int i = 5; i < 8; i++) {
        headerItem = new QStructureTableHeaderWgt(this);
        headerItem->setHeaderText(QString("Q<span style=\" vertical-align:sub;\">%1</span>").arg(8 - i));
        setCellWidget(1, i, headerItem);
    }

    setSpan(0, 8, 2, 1);
    headerItemText = new QTableWidgetItem("Вх. сигн., X");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    setItem(0, 8, headerItemText);

    // ЗАГОЛОВОК ДЛЯ ФУНКЦИЙ ВОЗБУЖДЕНИЯ
    setSpan(0, 9, 1, excitationColumnsCount);
    headerItemText = new QTableWidgetItem("Функции возбуждения");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    setItem(0, 9, headerItemText);

    // УСТАНАВЛИВАЕМ ЗАГОЛОВКИ В ЗАВИСИМОСТИ ОТ ТИПА ТРИГГЕРА
    if (triggerType == "RS"){
        qDebug() << "We in RS Trigger";
        for (int i = 0; i < 3; i++) {
            int colR = 9 + i * 2;
            int colS = 10 + i * 2;

            auto headerR = new QStructureTableHeaderWgt(this);
            headerR->setHeaderText(QString("R<span style=\" vertical-align:sub;\">%1</span>").arg(3 - i));
            setCellWidget(1, colR, headerR);

            auto headerS = new QStructureTableHeaderWgt(this);
            headerS->setHeaderText(QString("S<span style=\" vertical-align:sub;\">%1</span>").arg(3 - i));
            setCellWidget(1, colS, headerS);
        }
    } else if (triggerType == "D"){
        qDebug() << "We in D Trigger";
        for (int i = 0; i < 3; i++) {
            auto headerD = new QStructureTableHeaderWgt(this);
            headerD->setHeaderText(QString("D<span style=\" vertical-align:sub;\">%1</span>").arg(3 - i));
            setCellWidget(1, 9 + i, headerD);
        }
    } else if (triggerType == "T"){
        qDebug() << "We in T Trigger";
        for (int i = 0; i < 3; i++) {
            auto headerT = new QStructureTableHeaderWgt(this);
            headerT->setHeaderText(QString("T<span style=\" vertical-align:sub;\">%1</span>").arg(3 - i));
            setCellWidget(1, 9 + i, headerT);
        }
    } else if (triggerType == "JK"){
        qDebug() << "We in JK Trigger - Setting JK headers";
        for (int i = 0; i < 3; i++) {
            int colJ = 9 + i * 2;
            int colK = 10 + i * 2;

            auto headerJ = new QStructureTableHeaderWgt(this);
            headerJ->setHeaderText(QString("J<span style=\" vertical-align:sub;\">%1</span>").arg(3 - i));
            setCellWidget(1, colJ, headerJ);

            auto headerK = new QStructureTableHeaderWgt(this);
            headerK->setHeaderText(QString("K<span style=\" vertical-align:sub;\">%1</span>").arg(3 - i));
            setCellWidget(1, colK, headerK);
        }
    }

    // Заполнение третьей строки под "Входной сигнал"
    int input_sig = 0;
    for (int i = 2; i < rowCount(); i++) {
        if (i == 10){
            input_sig = 1;
        }
        headerItem = new QStructureTableHeaderWgt(this);
        headerItem->setHeaderText(QString("%1").arg(input_sig));
        setCellWidget(i, 8, headerItem);
    }

    update();
    adoptColumnsWidth();
}

QString QStructureTableWgt::getTableSymbol(int row)
{
    return item(row, 6)->text() +
            item(row, 7)->text() +
            item(row, 8)->text() +
            item(row, 9)->text() +
            item(row, 10)->text() +
            item(row, 11)->text() +
            item(row, 12)->text();
}

QString QStructureTableWgt::getDBSymbol(QString sym)
{
    if (sym != "*") {
        for (int i = 0; i < currentSymbols.size(); i++)
            if (sym[0] == currentSymbols[i][0])
                return currentSymbols[i].right(7);
        return "";
    } else
        return "*******";
}

void QStructureTableWgt::resizeEvent(QResizeEvent *event)
{
    if (event->size() != event->oldSize())
        adoptColumnsWidth();
    QTableWidget::resizeEvent(event);
}

void QStructureTableWgt::keyPressEvent(QKeyEvent *event)
{
    int row = currentRow();
    int column = currentColumn();
        switch (event->key()) {

            case Qt::Key_Space:
                if (row > 0 && column > 0)
                    toggleTableItem(row, column);
                break;
        }
}

void QStructureTableWgt::toggleTableItem(int row, int column)
{
    if (row > 1 && column != 0 && column != 4 && column != 8){
        if (column > 8){
            if (item(row, column)->text() == "0")
                item(row, column)->setText("1");
            else if (item(row, column)->text() == "1")
                item(row, column)->setText("*");
            else
                item(row, column)->setText("0");
        }else {
            if (item(row, column)->text() == "0")
                item(row, column)->setText("1");
            else
                item(row, column)->setText("0");
        }
    }

    isTested = false;
//    sendFunc(column);
    dataEdited();
}

void QStructureTableWgt::adoptColumnsWidth()
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

void QStructureTableWgt::clickedTableItem(QTableWidgetItem *item)
{
    if (item != 0)
        toggleTableItem(item->row(), item->column());
}

void QStructureTableWgt::itemKeyPressed(QKeyEvent *event)
{
    keyPressEvent(event);
}

QString QStructureTableHeaderWgt::getHeaderText() const
{
    return headerText ;
}

void QStructureTableHeaderWgt::setHeaderText(QString text)
{
    qDebug() << "Setting header text to:" << text;
    headerText = text;
    setHtml(text);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::NoFrame);
    viewport()->setAutoFillBackground(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void QLabStructureTableWgt::on_pushButtonCheck_clicked()
{
    showErrMsgSignal();
}

void QLabStructureTableWgt::showErrMsgSignal(int errCode)
{

    QString title;
    if (errCode == 0)
        title = "Таблица состояний заполнена верно!";
    else
        title = "Таблица состояний заполнена неверно!";

    QMessageBox msg(errCode == 0 ? QMessageBox::Information : QMessageBox::Warning,
                    "Внимание!",
                    title,
                    QMessageBox::Cancel);
    msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
    msg.exec();
}

void QLabStructureTableWgt::Convertation(QObject* obj)
{
    QString one = obj->property("one").toString();
    QString zero = obj->property("zero").toString();
    int trigger_index = obj->property("trigger").toInt();
    int basis_index = obj->property("basis").toInt();

    qDebug() << trigger_index << "TRIGGER INDEX!!!";
    // Разбиваем строку на список строк
    QStringList list = one.split(' ', Qt::SkipEmptyParts);
    QStringList list1 = zero.split(' ', Qt::SkipEmptyParts);
    QVector<QString> vecTrigger = {"RS", "D", "T", "JK"};
    triggerType = vecTrigger.at(trigger_index);
    // Создаём QVector<int> и заполняем его
    QVector<int> qVector;
    for (const QString &s : list) {
        bool ok;
        int num = s.toInt(&ok);
        if (ok) {
            qVector.append(num);
        }
    }
    QVector<int> qVector1;
    for (const QString &s1 : list1) {
        bool ok1;
        int num1 = s1.toInt(&ok1);
        if (ok1) {
            qVector1.append(num1);
        }
    }

    // Теперь конвертируем QVector<int> в std::vector<int>
    stdVectorOne= std::vector<int> (qVector.begin(), qVector.end());
    stdVectorZero= std::vector<int> (qVector1.begin(), qVector1.end());


    qDebug() << "Значение свойства1 'Zero':" << stdVectorZero;
    qDebug() << "Значение свойства1 'One':" << stdVectorOne;
    qDebug() << "Значение свойства1 'zero':" << obj->property("zero").toString();
    qDebug() << "TRIGGER TYPE!!!!" << triggerType;
    //qDebug() << "Значение свойства1 'trigger':" << vecTrigger.at(obj->property(t));
}

void QLabStructureTableWgt::showErrMsgSignal()
{
    qDebug() << "Checking structure table with vectors:";
    qDebug() << "stdVectorZero:" << QVector<int>(stdVectorZero.begin(), stdVectorZero.end());
    qDebug() << "stdVectorOne:" << QVector<int>(stdVectorOne.begin(), stdVectorOne.end());

    if (ui->tableWidgetStructureTable->checkTable(ui->tableWidgetStructureTable, stdVectorZero, stdVectorOne)) {
        showErrMsgSignal(0); // всё верно
    } else {
        showErrMsgSignal(1); // есть ошибки
    }
}

QStructureTableWgt::QStructureTableWgt(QObject* obj,QWidget *parent) : QTableWidget(parent)
{
    trigger_index = obj->property("trigger").toInt();
    triggerType = vecTrigger.at(trigger_index); // Используем currentTriggerType
    qDebug() << "Type of trigger in structure table: " << triggerType;

    // Используем новый метод для построения таблицы
    updateTableForTriggerType(triggerType);

    connect(this, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clickedTableItem(QTableWidgetItem*)));

    update();
}

bool QStructureTableWgt::checkTable(QTableWidget* table, const std::vector<int>& stdVectorZero, const std::vector<int>& stdVectorOne)
{
    qDebug() << "=== Starting structure table check with StateManager ===";

    // ДОБАВЬТЕ ЭТИ СТРОКИ ДЛЯ ОТЛАДКИ
    qDebug() << "Expected sequence for X=0:" << QVector<int>(stdVectorZero.begin(), stdVectorZero.end());
    qDebug() << "Expected sequence for X=1:" << QVector<int>(stdVectorOne.begin(), stdVectorOne.end());

    qDebug() << "=== StateManager State Codes ===";
    for (int i = 0; i < 8; i++) {
        if (stateManager.hasStateCode(i)) {
            QVector<int> code = stateManager.getStateCode(i);
            int value = binaryVectorToInt(code);
            qDebug() << "State a" << i << "-> code:" << code << "-> value:" << value;
        } else {
            qDebug() << "State a" << i << "-> NO CODE";
        }
    }

    // Проверяем, инициализирован ли StateManager
    if (!stateManager.isInitialized()) {
        qWarning() << "StateManager is not initialized!";
        return false;
    }

    bool allCorrect = true;

    // Проверяем строки для X=0 (строки 2-9)
    for (int row = 2; row <= 9; row++) {
        if (!checkStructureRow(table, row, stdVectorZero, "X=0")) {
            allCorrect = false;
        }
    }

    // Проверяем строки для X=1 (строки 10-17)
    for (int row = 10; row <= 17; row++) {
        if (!checkStructureRow(table, row, stdVectorOne, "X=1")) {
            allCorrect = false;
        }
    }

    qDebug() << "Structure table check:" << (allCorrect ? "PASSED" : "FAILED");

    if (!checkExcitationFunctions(table)){
        allCorrect = false;
    }
    return allCorrect;
}

bool QStructureTableWgt::checkStructureRow(QTableWidget* table, int row, const std::vector<int>& expectedSequence, const QString& modeName)
{
    qDebug() << "=== Checking" << modeName << "row:" << row << "===";

    // Получаем исходное состояние из заголовка
    QWidget* headerWidget = table->cellWidget(row, 0);
    if (!headerWidget) {
        qWarning() << modeName << "row" << row << "- No state header in column 0";
        return false;
    }

    QStructureTableHeaderWgt* header = qobject_cast<QStructureTableHeaderWgt*>(headerWidget);
    if (!header) {
        qWarning() << modeName << "row" << row << "- Invalid state header in column 0";
        return false;
    }

    QString stateName = header->getHeaderText();
    qDebug() << modeName << "row" << row << "- Header state:" << stateName;

    if (!stateName.startsWith('a')) {
        qWarning() << modeName << "row" << row << "- Invalid state name:" << stateName;
        return false;
    }

    // Получаем индекс состояния
    bool ok;
    int stateIndex = stateName.mid(1).toInt(&ok);
    if (!ok || stateIndex < 0 || stateIndex > 7) {
        qWarning() << modeName << "row" << row << "- Invalid state index:" << stateName;
        return false;
    }

    // Получаем код состояния из StateManager
    if (!stateManager.hasStateCode(stateIndex)) {
        qWarning() << modeName << "row" << row << "- No state code for" << stateName;
        return false;
    }

    QVector<int> stateCode = stateManager.getStateCode(stateIndex);
    int stateCodeValue = binaryVectorToInt(stateCode);

    qDebug() << modeName << "row" << row << "- State" << stateName << "code:" << stateCode << "value:" << stateCodeValue;

    // Проверяем код исходного состояния (столбцы 1-3)
    if (!checkCodeInColumns(table, row, 1, 3, stateCode, "source")) {
        qWarning() << modeName << "row" << row << "- Source code mismatch";
        return false;
    }
    qDebug() << modeName << "row" << row << "- Source code OK";

    // Получаем следующий код состояния из таблицы переходов
    int nextStateCodeValue = getNextStateCodeFromTransition(stateIndex, expectedSequence, modeName);
    if (nextStateCodeValue == -1) {
        qWarning() << modeName << "row" << row << "- Could not determine next state code";
        return false;
    }

    qDebug() << modeName << "row" << row << "- Expected next state code:" << nextStateCodeValue;

    // Получаем бинарный код следующего состояния
    QVector<int> nextStateCode = intToBinaryVector(nextStateCodeValue, 3);

    // Получаем индекс следующего состояния по коду
    int nextStateIndex = getStateIndexByCode(nextStateCodeValue);
    if (nextStateIndex == -1) {
        qWarning() << modeName << "row" << row << "- Could not find state for code:" << nextStateCodeValue;
        return false;
    }

    qDebug() << modeName << "row" << row << "- Expected next state: a" << nextStateIndex;

    // Проверяем столбец "След. сост" (столбец 4)
    if (!checkNextStateColumn(table, row, 4, nextStateIndex)) {
        qWarning() << modeName << "row" << row << "- Next state column mismatch";
        return false;
    }
    qDebug() << modeName << "row" << row << "- Next state column OK";

    // Проверяем код следующего состояния (столбцы 5-7)
    if (!checkCodeInColumns(table, row, 5, 7, nextStateCode, "next")) {
        qWarning() << modeName << "row" << row << "- Next code mismatch";
        return false;
    }
    qDebug() << modeName << "row" << row << "- Next code OK";

    // Проверяем входной сигнал (столбец 8)
    int expectedInput = (modeName == "X=0") ? 0 : 1;
    if (!checkInputSignal(table, row, 8, expectedInput)) {
        qWarning() << modeName << "row" << row << "- Input signal mismatch";
        return false;
    }
    qDebug() << modeName << "row" << row << "- Input signal OK";

    qDebug() << modeName << "row" << row << "- ALL CHECKS PASSED";
    return true;
}

int QStructureTableWgt::getNextStateCodeFromTransition(int currentStateIndex, const std::vector<int>& expectedSequence, const QString& modeName)
{
    // Получаем код текущего состояния
    if (!stateManager.hasStateCode(currentStateIndex)) {
        qWarning() << "No state code for current state index:" << currentStateIndex;
        return -1;
    }

    QVector<int> currentStateCode = stateManager.getStateCode(currentStateIndex);
    int currentCodeValue = binaryVectorToInt(currentStateCode);

    qDebug() << "Finding next state for current code:" << currentCodeValue << "in sequence:" << QVector<int>(expectedSequence.begin(), expectedSequence.end());

    // Ищем текущий код в expectedSequence
    auto it = std::find(expectedSequence.begin(), expectedSequence.end(), currentCodeValue);
    if (it != expectedSequence.end()) {
        // Нашли в цикле - берем следующий элемент
        int index = std::distance(expectedSequence.begin(), it);
        int nextIndex = (index + 1) % expectedSequence.size();
        int nextCode = expectedSequence[nextIndex];
        qDebug() << "Found in sequence at index" << index << ", next index:" << nextIndex << ", next code:" << nextCode;
        return nextCode;
    } else {
        // Не нашли - переход в начало цикла
        int startCode = expectedSequence[0];
        qDebug() << "Not found in sequence, transitioning to start of cycle:" << startCode;
        return startCode;
    }
}

bool QStructureTableWgt::checkCodeInColumns(QTableWidget* table, int row, int startCol, int endCol, const QVector<int>& expectedCode, const QString& codeType)
{
    if (endCol - startCol + 1 != expectedCode.size()) {
        qWarning() << "Column range doesn't match code size";
        return false;
    }

    for (int i = 0; i < expectedCode.size(); i++) {
        int col = startCol + i;
        QTableWidgetItem* item = table->item(row, col);
        if (!item) {
            qWarning() << "No item at row" << row << "col" << col;
            return false;
        }

        QString cellText = item->text().trimmed();
        if (cellText.isEmpty()) {
            qWarning() << "Empty cell at row" << row << "col" << col;
            return false;
        }

        bool ok;
        int cellValue = cellText.toInt(&ok);
        if (!ok || (cellValue != 0 && cellValue != 1)) {
            qWarning() << "Invalid value at row" << row << "col" << col << ":" << cellText;
            return false;
        }

        if (cellValue != expectedCode[i]) {
            qWarning() << codeType << "code mismatch at row" << row << "col" << col;
            qWarning() << "Expected:" << expectedCode[i] << "Got:" << cellValue;
            return false;
        }
    }

    return true;
}

bool QStructureTableWgt::checkInputSignal(QTableWidget* table, int row, int col, int expectedInput)
{
    QWidget* headerWidget = table->cellWidget(row, col);
    if (!headerWidget) {
        qWarning() << "No input header at row" << row << "col" << col;
        return false;
    }

    QStructureTableHeaderWgt* header = qobject_cast<QStructureTableHeaderWgt*>(headerWidget);
    if (!header) {
        qWarning() << "Invalid input header at row" << row << "col" << col;
        return false;
    }

    QString inputText = header->getHeaderText().trimmed();
    bool ok;
    int inputValue = inputText.toInt(&ok);

    if (!ok || inputValue != expectedInput) {
        qWarning() << "Input signal mismatch at row" << row;
        qWarning() << "Expected:" << expectedInput << "Got:" << inputValue;
        return false;
    }

    return true;
}

int QStructureTableWgt::binaryVectorToInt(const QVector<int>& binaryVector)
{
    int value = 0;
    for (int i = 0; i < binaryVector.size(); i++) {
        value = (value << 1) | binaryVector[i];
    }
    return value;
}

QVector<int> QStructureTableWgt::intToBinaryVector(int value, int bits)
{
    QVector<int> binaryVector(bits, 0);
    for (int i = bits - 1; i >= 0; i--) {
        binaryVector[i] = value & 1;
        value >>= 1;
    }
    return binaryVector;
}

bool QStructureTableWgt::checkNextStateColumn(QTableWidget* table, int row, int col, int expectedStateIndex)
{
    QTableWidgetItem* item = table->item(row, col);
    if (!item) {
        qWarning() << "ERROR: No item in next state column at row" << row << "col" << col;
        return false;
    }

    QString cellText = item->text().trimmed();
    QString expectedText = QString("a%1").arg(expectedStateIndex);

    qDebug() << "Checking next state column - Row:" << row << "Expected:" << expectedText << "Actual:" << cellText;

    if (cellText != expectedText) {
        qWarning() << "ERROR: Next state column mismatch at row" << row;
        qWarning() << "Expected:" << expectedText << "Got:" << cellText;
        return false;
    }

    return true;
}

int QStructureTableWgt::getStateIndexByCode(int codeValue)
{
    // Ищем состояние по коду в StateManager
    for (int i = 0; i < 8; i++) {
        if (!stateManager.hasStateCode(i)) {
            continue;
        }

        QVector<int> stateCode = stateManager.getStateCode(i);
        int currentCodeValue = binaryVectorToInt(stateCode);

        if (currentCodeValue == codeValue) {
            return i;
        }
    }

    qWarning() << "Could not find state index for code:" << codeValue;
    return -1;
}

// CHECKING TRIGGERS FIRING FUNCS

bool QStructureTableWgt::checkExcitationFunctions(QTableWidget* table)
{
    qDebug() << "=== Checking excitation functions for trigger type:" << triggerType << "===";


    bool allCorrect = true;

    for (int row = 2; row <= 17; row++) {
        // Получаем исходное и следующее состояние для каждого триггера (бита)
        for (int bit = 0; bit < 3; bit++) {
            // Столбцы для исходного состояния: 1(Q3), 2(Q2), 3(Q1)
            int initialCol = 1 + bit;
            // Столбцы для следующего состояния: 5(Q3), 6(Q2), 7(Q1)
            int nextCol = 5 + bit;

            QTableWidgetItem* initialItem = table->item(row, initialCol);
            QTableWidgetItem* nextItem = table->item(row, nextCol);

            if (!initialItem || !nextItem) {
                qWarning() << "Missing Q values at row" << row << "for bit" << bit;
                continue;
            }

            int Q_initial = initialItem->text().toInt();
            int Q_next = nextItem->text().toInt();

            // Проверяем функции возбуждения в зависимости от типа триггера
            if (triggerType == "RS") {
                if (!checkRSExcitation(table, row, bit, Q_initial, Q_next)) {
                    allCorrect = false;
                }
            } else if (triggerType == "D") {
                if (!checkDExcitation(table, row, bit, Q_initial, Q_next)) {
                    allCorrect = false;
                }
            } else if (triggerType == "T") {
                if (!checkTExcitation(table, row, bit, Q_initial, Q_next)) {
                    allCorrect = false;
                }
            } else if (triggerType == "JK") {
                if (!checkJKExcitation(table, row, bit, Q_initial, Q_next)) {
                    allCorrect = false;
                }
            }
        }
    }

    return allCorrect;
}

int QStructureTableWgt::parseExcitationValue(QTableWidgetItem* item)
{
    if (!item) return -1; // Ошибка - нет ячейки

    QString text = item->text().trimmed();

    if (text == "*") return 2; // Специальный код для звездочки
    if (text == "0") return 0;
    if (text == "1") return 1;

    return -1; // Неизвестное значение
}

// НЕ ТЕСТИРОВАНО
bool QStructureTableWgt::checkRSExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next)
{
    // Для RS триггера: столбцы 9(R3,S3), 11(R2,S2), 13(R1,S1)
    int baseCol = 9 + bit * 2;

    QTableWidgetItem* R_item = table->item(row, baseCol);
    QTableWidgetItem* S_item = table->item(row, baseCol + 1);

    if (!R_item || !S_item) {
        qWarning() << "Missing RS values at row" << row << "for bit" << bit;
        return false;
    }

    int R = parseExcitationValue(R_item);
    int S = parseExcitationValue(S_item);

    if (R == -1 || S == -1) {
        qWarning() << "Invalid RS values at row" << row << "for bit" << bit;
        return false;
    }

    // Таблица истинности RS-триггера с учетом звездочки
    bool correct = false;

    if (Q_initial == 0 && Q_next == 0) {
        // Для 0->0: R=*, S=0 (R может быть 0 или 1, S должен быть 0)
        correct = ((R == 1 || R == 0 || R == 2) && S == 0) ;
    } else if (Q_initial == 0 && Q_next == 1) {
        // Для 0->1: R=0, S=1
        correct = (R == 0 && S == 1);
    } else if (Q_initial == 1 && Q_next == 0) {
        // Для 1->0: R=1, S=0
        correct = (R == 1 || S == 0);
    } else if (Q_initial == 1 && Q_next == 1) {
        // Для 1->1: R=0, S=* (R должен быть 0, S может быть 0 или 1)
        correct = ((S == 0 || S == 2 || S == 1) && S == 1); // R=0 или *

    }

    if (!correct) {
        qWarning() << "RS error at row" << row << "bit" << bit << "transition" << Q_initial << "->" << Q_next;
        qWarning() << "Expected:";
        if (Q_initial == 0 && Q_next == 0) qWarning() << "R=*, S=0 (but not R=1,S=1)";
        if (Q_initial == 0 && Q_next == 1) qWarning() << "R=0, S=1";
        if (Q_initial == 1 && Q_next == 0) qWarning() << "R=1, S=0";
        if (Q_initial == 1 && Q_next == 1) qWarning() << "R=0, S=* (but not R=1,S=1)";
        qWarning() << "Got: R=" << (R == 2 ? "*" : QString::number(R)) << "S=" << (S == 2 ? "*" : QString::number(S));
    }

    return correct;
}

bool QStructureTableWgt::checkDExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next)
{
    // Для D триггера: столбцы 9(D3), 10(D2), 11(D1)
    int D_col = 9 + bit;

    QTableWidgetItem* D_item = table->item(row, D_col);
    if (!D_item) {
        qWarning() << "Missing D value at row" << row << "for bit" << bit;
        return false;
    }

    int D = parseExcitationValue(D_item);
    if (D == -1) {
        qWarning() << "Invalid D value at row" << row << "for bit" << bit;
        return false;
    }

    // Для D-триггера: D = Q_next (звездочка не допускается)
    bool correct = (D == Q_next);

    if (!correct) {
        qWarning() << "D error at row" << row << "bit" << bit;
        qWarning() << "D should equal Q_next:" << Q_next << "but got:" << (D == 2 ? "*" : QString::number(D));
    }

    return correct;
}

bool QStructureTableWgt::checkTExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next)
{
    // Для T триггера: столбцы 9(T3), 10(T2), 11(T1)
    int T_col = 9 + bit;

    QTableWidgetItem* T_item = table->item(row, T_col);
    if (!T_item) {
        qWarning() << "Missing T value at row" << row << "for bit" << bit;
        return false;
    }

    int T = parseExcitationValue(T_item);
    if (T == -1) {
        qWarning() << "Invalid T value at row" << row << "for bit" << bit;
        return false;
    }

    // Таблица истинности T-триггера (звездочка не допускается)
    bool correct = false;

    if (Q_initial == 0 && Q_next == 0) {
        // Для 0->0: T=0
        correct = (T == 0);
    } else if (Q_initial == 0 && Q_next == 1) {
        // Для 0->1: T=1
        correct = (T == 1);
    } else if (Q_initial == 1 && Q_next == 0) {
        // Для 1->0: T=1
        correct = (T == 1);
    } else if (Q_initial == 1 && Q_next == 1) {
        // Для 1->1: T=0
        correct = (T == 0);
    }

    if (!correct) {
        qWarning() << "T error at row" << row << "bit" << bit << "transition" << Q_initial << "->" << Q_next;
        qWarning() << "Expected T =" << (Q_initial == Q_next ? 0 : 1) << "but got:" << (T == 2 ? "*" : QString::number(T));
    }

    return correct;
}

bool QStructureTableWgt::checkJKExcitation(QTableWidget* table, int row, int bit, int Q_initial, int Q_next)
{
    // Для JK триггера: столбцы 9(J3,K3), 11(J2,K2), 13(J1,K1)
    int baseCol = 9 + bit * 2;

    QTableWidgetItem* J_item = table->item(row, baseCol);
    QTableWidgetItem* K_item = table->item(row, baseCol + 1);

    if (!J_item || !K_item) {
        qWarning() << "Missing JK values at row" << row << "for bit" << bit;
        return false;
    }

    int J = parseExcitationValue(J_item);
    int K = parseExcitationValue(K_item);

    if (J == -1 || K == -1) {
        qWarning() << "Invalid JK values at row" << row << "for bit" << bit;
        return false;
    }

    // Таблица истинности JK-триггера (с учетом звездочки)
    bool correct = false;

    if (Q_initial == 0 && Q_next == 0) {
        // Для 0->0: J=0, K=* (0 или 1)
        correct = ((K == 0 || K == 2 || K == 1) && J == 0);
    } else if (Q_initial == 0 && Q_next == 1) {
        // Для 0->1: J=1, K=* (0 или 1)
        correct = ((K == 1 || K == 2 || K == 0) && J == 1);
    } else if (Q_initial == 1 && Q_next == 0) {
        // Для 1->0: J=*, K=1
        correct = ((J == 1 || J == 2 || J == 0) && K == 1);
    } else if (Q_initial == 1 && Q_next == 1) {
        // Для 1->1: J=*, K=0
        correct = ((J == 0 || J == 2 || J == 1) && K == 0);
    }

    if (!correct) {
        qWarning() << "JK error at row" << row << "bit" << bit << "transition" << Q_initial << "->" << Q_next;
        qWarning() << "Expected:";
        if (Q_initial == 0 && Q_next == 0) qWarning() << "J=0, K=*";
        if (Q_initial == 0 && Q_next == 1) qWarning() << "J=1, K=*";
        if (Q_initial == 1 && Q_next == 0) qWarning() << "J=*, K=1";
        if (Q_initial == 1 && Q_next == 1) qWarning() << "J=*, K=0";
        qWarning() << "Got: J=" << (J == 2 ? "*" : QString::number(J)) << "K=" << (K == 2 ? "*" : QString::number(K));
    }

    return correct;
}


void QLabStructureTableWgt::saveData(QFileWorker* stream)
{
    QTableWidget* table = ui->tableWidgetStructureTable; // Исправьте на правильное имя

    stream->setInt(table->rowCount());
    stream->setInt(table->columnCount());

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
}

void QLabStructureTableWgt::openData(QFileWorker* stream)
{
    QTableWidget* table = ui->tableWidgetStructureTable;

    int rowCount = stream->getInt();
    int colCount = stream->getInt();

    table->setRowCount(rowCount);
    table->setColumnCount(colCount);

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            QString text = stream->getStr();
            QTableWidgetItem* item = new QTableWidgetItem(text);
            item->setTextAlignment(Qt::AlignCenter);

            // Определяем, какие столбцы должны быть нередактируемыми
            // Предположим, что:
            // - Столбцы 1-3: коды текущего состояния (нередактируемые)
            // - Столбец 4: следующее состояние (редактируемый)
            // - Столбцы 5-7: коды следующего состояния (нередактируемые)
            // - Столбцы 8+: триггеры (нередактируемые)

            if (col >= 1 && col <= 3) { // Коды текущего состояния
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
            else if (col >= 5 && col <= 7) { // Коды следующего состояния
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
            else if (col >= 8) { // Триггеры
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
            // Столбец 4 (следующее состояние) оставляем редактируемым
            // Столбец 0 (название состояния) тоже оставляем редактируемым, если нужно

            table->setItem(row, col, item);
        }
    }

    table->setEnabled(true);
}
