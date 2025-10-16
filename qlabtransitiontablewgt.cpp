#include "qlabtransitiontablewgt.h"
#include "ui_qlabtransitiontablewgt.h"
#include <QDebug>
#include <QtMath>
#include <QVector>
#include <vector>
#include <math.h>
#include <statemanager.h>
using namespace std;

QLabTransitionTableWgt::QLabTransitionTableWgt(QWidget *parent) :QWidget(parent),ui(new Ui::QLabTransitionTableWgt)
{
    ui->setupUi(this);
    connect(this, SIGNAL(setVar(QObject*)), this, SLOT(setLabels(QObject*)));
}

void QLabTransitionTableWgt::connectModules(QLabDataBase* db){currentDB = db;}

void QLabTransitionTableWgt::setLabels(QObject* obj)
{
    ui->labelZero->setText(obj->property("zero").toString());
    ui->labelOne->setText(obj->property("one").toString());
    Convertation(obj);
}

bool QLabTransitionTableWgt::isOK(){return ui->tableWidgetTransitionTable->isOK();}

bool QTransitionTableWgt::isOK(){return true;}

QTransitionTableWgt::QTransitionTableWgt(QWidget *parent) : QTableWidget(parent)
{
    setColumnCount(9);
    setRowCount(6);

    qDebug() << "Creating transition table with" << rowCount() << "rows and" << columnCount() << "columns";

    for (int i = 0; i < rowCount(); i++) {
        for (int j = 0; j < columnCount(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem("");
            item->setTextAlignment(Qt::AlignCenter);
            setItem(i, j, item);
        }
    }

    QTableWidgetItem *headerItemText;

    setSpan(0, 0, 4, 1); // Установка заголовков для "Входной сигнал"
    headerItemText = new QTableWidgetItem("Входной сигнал");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    headerItemText->setFlags(headerItemText->flags() & ~Qt::ItemIsEditable);
    setItem(0, 0, headerItemText);

    setSpan(0, 1, 1, 8); // объединяем ячейки для заголовка "Выходной сигнал"
    headerItemText = new QTableWidgetItem("Выходной сигнал");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    headerItemText->setFlags(headerItemText->flags() & ~Qt::ItemIsEditable);
    setItem(0, 1, headerItemText);

    setSpan(2, 1, 1, 8); // объединяем ячейки для заголовка "Внутреннее состояние"
    headerItemText = new QTableWidgetItem("Внутреннее состояние");
    headerItemText->setTextAlignment(Qt::AlignCenter);
    headerItemText->setBackground(Qt::gray);
    headerItemText->setFlags(headerItemText->flags() & ~Qt::ItemIsEditable);
    setItem(2, 1, headerItemText);

    QTransitionTableHeaderWgt *headerItem;

    // Заполнение первого столбца под "Входной сигнал"
    for (int i = 4; i < rowCount(); i++) {
        headerItem = new QTransitionTableHeaderWgt(this);
        headerItem->setHeaderText(QString("X = %1").arg(i-4));
        setCellWidget(i, 0, headerItem);
        qDebug() << "Created input header at row" << i << ": X =" << (i-4);
    }

    // Заполнение третьей строки под "Внутреннее состояние"
    for (int i = 1; i < columnCount(); i++) {
        headerItem = new QTransitionTableHeaderWgt(this);
        QString stateName = QString("a%1").arg(i-1);
        headerItem->setHeaderText(stateName);
        setCellWidget(3, i, headerItem);
        qDebug() << "Created state header at column" << i << ":" << stateName;
    }

    qDebug() << "Transition table structure:";
    qDebug() << "- Columns: 0 (input), 1-8 (states a0-a7)";
    qDebug() << "- Rows: 0-1 (output signals), 2-3 (headers), 4-5 (transitions)";
}

// ADAPTIVE TABLE

void QTransitionTableWgt::resizeEvent(QResizeEvent *event)
{
    if (event->size() != event->oldSize())
        adoptColumnsWidth();
    QTableWidget::resizeEvent(event);
}

void QTransitionTableWgt::adoptColumnsWidth()
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

// HEADER METHODS

void QTransitionTableHeaderWgt::setHeaderText(const QString &text)
{
    headerText = text;
    setHtml(text);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::NoFrame);
    viewport()->setAutoFillBackground(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QString QTransitionTableHeaderWgt::getHeaderText() const
{
    return headerText;
}

// BUTTON EVENT

void QLabTransitionTableWgt::on_pushButtonCheck_clicked()
{
    showErrMsgSignal();
}

// CHECKING TABLE METHODS

void QLabTransitionTableWgt::showErrMsgSignal(int errCode)
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

void QLabTransitionTableWgt::showErrMsgSignal()
{
    qDebug() << "=== Starting transition table validation ===";

    // Проверяем, инициализирован ли StateManager
    if (!stateManager.isInitialized()) {
        qCritical() << "StateManager is not initialized! Please fill and check the state coding table first.";
        QMessageBox::warning(this, "Ошибка", "Сначала заполните и проверьте таблицу кодировки состояний!");
        return;
    }

    qDebug() << "StateManager contains" << stateManager.getAllStateCodes().size() << "state codes";

    if (ui->tableWidgetTransitionTable->checkTable(ui->tableWidgetTransitionTable, stdVectorZero, stdVectorOne)) {
        qDebug() << "Transition table validation PASSED";
        showErrMsgSignal(0); // всё верно
    } else {
        qDebug() << "Transition table validation FAILED";
        showErrMsgSignal(1); // есть ошибки
    }

    qDebug() << "=== Transition table validation completed ===";
}

struct Transition {
    int currentState;  // Текущее состояние
    int nextState;     // Следующее состояние

    // Конструктор для удобства
    Transition(int current, int next) : currentState(current), nextState(next) {}

    // Для отладки
    QString toString() const {
        return QString("a%1 → a%2").arg(currentState).arg(nextState);
    }
};

// Checking Output Signals in for cycle
bool QTransitionTableWgt::checkOutputSignals()
{
    qDebug() << "=== Starting output signals check ===";

    // Проверяем, инициализирован ли StateManager
    if (!stateManager.isInitialized()) {
        qWarning() << "StateManager is not initialized! Cannot check output signals.";
        return false;
    }

    bool allSignalsValid = true;
    bool hasAnyOutput = false; // Флаг, чтобы проверить, есть ли хотя бы один заполненный выходной сигнал

    // Проверяем строку с выходными сигналами (строка 1)
    // Колонки с состояниями начинаются с индекса 1 (a0), 2 (a1), 3 (a2) и т.д.
    for (int col = 1; col < columnCount(); ++col) {
        QTableWidgetItem* outputItem = item(1, col);
        if (!outputItem) {
            qWarning() << "No item at row 1, column" << col;
            allSignalsValid = false;
            continue;
        }

        QString cellText = outputItem->text().trimmed();

        // Проверяем, что ячейка не пустая
        if (cellText.isEmpty()) {
            qWarning() << "Empty cell at row 1, column" << col;
            allSignalsValid = false;
            continue;
        }

        // Получаем состояние из заголовка столбца (строка 3)
        QString stateName;
        QWidget* headerWidget = cellWidget(3, col);
        if (!headerWidget) {
            qWarning() << "No header widget at row 3, column" << col;
            allSignalsValid = false;
            continue;
        }

        QTransitionTableHeaderWgt* header = qobject_cast<QTransitionTableHeaderWgt*>(headerWidget);
        if (!header) {
            qWarning() << "Invalid header widget at row 3, column" << col;
            allSignalsValid = false;
            continue;
        }

        stateName = header->getHeaderText();
        qDebug() << "Processing state:" << stateName << "at column" << col << "with value:" << cellText;

        // Извлекаем индекс состояния (a0 -> 0, a1 -> 1, etc.)
        int stateIndex = -1;
        if (stateName.startsWith("a")) {
            bool ok;
            stateIndex = stateName.mid(1).toInt(&ok);
            if (!ok) {
                qWarning() << "Invalid state format:" << stateName;
                allSignalsValid = false;
                continue;
            }
        } else {
            qWarning() << "State name doesn't start with 'a':" << stateName;
            allSignalsValid = false;
            continue;
        }

        // Получаем код состояния из StateManager
        if (!stateManager.hasStateCode(stateIndex)) {
            qWarning() << "No state code found for" << stateName;
            allSignalsValid = false;
            continue;
        }

        QVector<int> stateCode = stateManager.getStateCode(stateIndex);
        qDebug() << "State" << stateName << "code:" << stateCode;

        // ИСПРАВЛЕНИЕ: Формируем ожидаемые выходные сигналы в обратном порядке {y3, y2, y1}
        QStringList expectedSignals;
        for (int i = 0; i < stateCode.size(); ++i) {
            if (stateCode[i] == 1) {
                // Бит 0 (младший) соответствует y1, бит 1 соответствует y2, бит 2 (старший) соответствует y3
                // Поэтому инвертируем порядок: stateCode.size() - i
                int signalNumber = stateCode.size() - i;
                expectedSignals.append(QString("y%1").arg(signalNumber));
            }
        }

        // Сравниваем с содержимым ячейки
        if (!compareOutputSignals(cellText, expectedSignals)) {
            qWarning() << "Output signals mismatch for state" << stateName;
            qWarning() << "Expected:" << expectedSignals.join(",");
            qWarning() << "Got:" << cellText;
            allSignalsValid = false;
        } else {
            qDebug() << "Output signals match for state" << stateName;
            hasAnyOutput = true;
        }
    }

    // Если ни один выходной сигнал не заполнен корректно, считаем это ошибкой
    if (!hasAnyOutput) {
        qWarning() << "No valid output signals found!";
        allSignalsValid = false;
    }

    qDebug() << "Output signals check result:" << (allSignalsValid ? "PASSED" : "FAILED");
    return allSignalsValid;
}

// Comparing output signals from stateManager with text in cell
bool QTransitionTableWgt::compareOutputSignals(const QString& cellText, const QStringList& expectedSignals)
{
    if (expectedSignals.isEmpty()) {
        return cellText.isEmpty() || cellText == "-" || cellText == "0";
    }

    // Нормализуем текст из ячейки: убираем пробелы, разбиваем по запятым
    QStringList cellSignals = cellText.split(',', Qt::SkipEmptyParts);
    QStringList normalizedCellSignals;

    for (QString signal : cellSignals) {
        QString normalized = signal.trimmed().toLower();
        if (!normalized.isEmpty()) {
            normalizedCellSignals.append(normalized);
        }
    }

    // Нормализуем ожидаемые сигналы
    QStringList normalizedExpectedSignals;
    for (QString signal : expectedSignals) {
        normalizedExpectedSignals.append(signal.trimmed().toLower());
    }

    // Сортируем оба списка для сравнения без учета порядка
    normalizedCellSignals.sort();
    normalizedExpectedSignals.sort();

    bool match = normalizedCellSignals == normalizedExpectedSignals;

    if (!match) {
        qDebug() << "Signal comparison failed:";
        qDebug() << "Cell signals:" << normalizedCellSignals;
        qDebug() << "Expected signals:" << normalizedExpectedSignals;
    }

    return match;
}

bool QTransitionTableWgt::checkTable(QTableWidget* table, const std::vector<int>& stdVectorZero, const std::vector<int>& stdVectorOne)
{
    qDebug() << "=== Starting table check with new logic ===";

    // Сначала проверяем выходные сигналы
    if (!checkOutputSignals()) {
        qWarning() << "Output signals check failed!";
        return false;
    }

    qDebug() << "Output signals check passed, checking transitions with new logic...";

    // Получаем строку с закодированными состояниями (строка 3)
    QVector<QString> stateCodes;
    for (int col = 1; col < columnCount(); ++col) {
        QWidget* headerWidget = cellWidget(3, col);
        if (headerWidget) {
            QTransitionTableHeaderWgt* header = qobject_cast<QTransitionTableHeaderWgt*>(headerWidget);
            if (header) {
                stateCodes.append(header->getHeaderText());
            } else {
                stateCodes.append("");
            }
        } else {
            stateCodes.append("");
        }
    }

    qDebug() << "State codes in headers:" << stateCodes;

    // Проверяем переходы для X=0
    if (!checkTransitionsForMode(4, stateCodes, stdVectorZero, "X=0")) {
        return false;
    }

    // Проверяем переходы для X=1
    if (!checkTransitionsForMode(5, stateCodes, stdVectorOne, "X=1")) {
        return false;
    }

    qDebug() << "Table check completed: PASSED";
    return true;
}

bool QTransitionTableWgt::checkTransitionsForMode(int row, const QVector<QString>& stateCodes, const std::vector<int>& expectedSequence, const QString& modeName)
{
    qDebug() << "=== Checking transitions for" << modeName << "===";
    qDebug() << "Expected sequence:" << QVector<int>(expectedSequence.begin(), expectedSequence.end());

    // Создаем множество используемых состояний из expectedSequence
    QSet<int> usedStates;
    for (int code : expectedSequence) {
        usedStates.insert(code);
    }

    // Проверяем основную цепочку
    for (size_t i = 0; i < expectedSequence.size(); i++) {
        int currentCode = expectedSequence[i];
        int nextCode = expectedSequence[(i + 1) % expectedSequence.size()]; // зацикливание

        // Находим индекс столбца для текущего состояния
        int currentCol = findStateColumnByCode(stateCodes, currentCode);
        if (currentCol == -1) {
            qWarning() << modeName << "- State with code" << currentCode << "not found in state codes";
            return false;
        }

        // Получаем переход, который ввел пользователь
        QTableWidgetItem* transitionItem = item(row, currentCol);
        if (!transitionItem || transitionItem->text().isEmpty()) {
            qWarning() << modeName << "- Empty transition for state with code" << currentCode << "at column" << currentCol;
            return false;
        }

        QString transitionText = transitionItem->text().trimmed();
        if (!transitionText.startsWith('a')) {
            qWarning() << modeName << "- Invalid transition format:" << transitionText;
            return false;
        }

        // Получаем индекс состояния перехода
        bool ok;
        int transitionStateIndex = transitionText.mid(1).toInt(&ok);
        if (!ok || transitionStateIndex < 0 || transitionStateIndex >= stateCodes.size()) {
            qWarning() << modeName << "- Invalid state index in transition:" << transitionText;
            return false;
        }

        // Получаем код состояния перехода
        int transitionCode = getStateCodeFromHeader(stateCodes[transitionStateIndex]);
        if (transitionCode == -1) {
            qWarning() << modeName << "- Could not get code for transition state:" << stateCodes[transitionStateIndex];
            return false;
        }

        // Проверяем соответствие
        if (transitionCode != nextCode) {
            qWarning() << modeName << "- Transition mismatch for state with code" << currentCode;
            qWarning() << "  Expected transition to code:" << nextCode;
            qWarning() << "  Got transition to code:" << transitionCode;
            return false;
        }

        qDebug() << modeName << "- State code" << currentCode << "->" << nextCode << ": OK";
    }

    // Проверяем неиспользуемые состояния (должны переходить в начало цикла)
    int startOfCycleCode = expectedSequence[0];
    for (int col = 1; col < columnCount(); ++col) {
        int stateCode = getStateCodeFromHeader(stateCodes[col - 1]);
        if (stateCode == -1) continue;

        // Если состояние не используется в цикле
        if (!usedStates.contains(stateCode)) {
            QTableWidgetItem* transitionItem = item(row, col);
            if (!transitionItem || transitionItem->text().isEmpty()) {
                qWarning() << modeName << "- Empty transition for unused state with code" << stateCode;
                return false;
            }

            QString transitionText = transitionItem->text().trimmed();
            if (!transitionText.startsWith('a')) {
                qWarning() << modeName << "- Invalid transition format for unused state:" << transitionText;
                return false;
            }

            // Получаем индекс состояния перехода
            bool ok;
            int transitionStateIndex = transitionText.mid(1).toInt(&ok);
            if (!ok || transitionStateIndex < 0 || transitionStateIndex >= stateCodes.size()) {
                qWarning() << modeName << "- Invalid state index in transition for unused state:" << transitionText;
                return false;
            }

            // Получаем код состояния перехода
            int transitionCode = getStateCodeFromHeader(stateCodes[transitionStateIndex]);
            if (transitionCode == -1) {
                qWarning() << modeName << "- Could not get code for transition state (unused):" << stateCodes[transitionStateIndex];
                return false;
            }

            // Проверяем, что переход ведет в начало цикла
            if (transitionCode != startOfCycleCode) {
                qWarning() << modeName << "- Unused state with code" << stateCode << "should transition to start of cycle (code" << startOfCycleCode << ")";
                qWarning() << "  But got transition to code:" << transitionCode;
                return false;
            }

            qDebug() << modeName << "- Unused state code" << stateCode << "-> start of cycle" << startOfCycleCode << ": OK";
        }
    }

    qDebug() << modeName << "transitions check: PASSED";
    return true;
}

int QTransitionTableWgt::findStateColumnByCode(const QVector<QString>& stateCodes, int targetCode)
{
    for (int i = 0; i < stateCodes.size(); i++) {
        int code = getStateCodeFromHeader(stateCodes[i]);
        if (code == targetCode) {
            return i + 1; // +1 потому что столбцы начинаются с 1
        }
    }
    return -1;
}

int QTransitionTableWgt::getStateCodeFromHeader(const QString& headerText)
{
    if (!headerText.startsWith('a')) {
        return -1;
    }

    // Извлекаем индекс состояния (a0 -> 0, a1 -> 1, etc.)
    bool ok;
    int stateIndex = headerText.mid(1).toInt(&ok);
    if (!ok || stateIndex < 0 || stateIndex > 7) {
        return -1;
    }

    // Получаем код состояния из StateManager
    if (!stateManager.hasStateCode(stateIndex)) {
        return -1;
    }

    QVector<int> stateCode = stateManager.getStateCode(stateIndex);

    // Преобразуем бинарный код в число
    int codeValue = 0;
    for (int i = 0; i < stateCode.size(); i++) {
        codeValue = (codeValue << 1) | stateCode[i];
    }

    return codeValue;
}

void QLabTransitionTableWgt::saveData(QFileWorker* stream)
{
    // Используем правильное имя таблицы переходов
    QTableWidget* table = ui->tableWidgetTransitionTable; // ЗАМЕНИТЕ на правильное имя

    // Сохраняем размеры таблицы
    stream->setInt(table->rowCount());
    stream->setInt(table->columnCount());

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

    // Сохраняем специфичные данные для таблицы переходов
    // stream->setStr(ui->lineEditSomeData->text()); // если есть дополнительные поля
}

void QLabTransitionTableWgt::openData(QFileWorker* stream)
{
    // Используем правильное имя таблицы переходов
    QTableWidget* table = ui->tableWidgetTransitionTable; // ЗАМЕНИТЕ на правильное имя

    // Проверяем, инициализирована ли таблица
    if (table->rowCount() == 0 || table->columnCount() == 0) {
        qDebug() << "Таблица переходов не инициализирована, выполняется заполнение...";
        // Вызовите здесь метод для базового заполнения таблицы, если он есть
        // table->fillBaseStructure();
    }

    // Восстанавливаем размеры таблицы
    int rowCount = stream->getInt();
    int colCount = stream->getInt();

    // Проверяем валидность размеров
    if (rowCount <= 0 || colCount <= 0 || rowCount > 1000 || colCount > 100) {
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

    // Восстанавливаем специфичные данные
    // ui->lineEditSomeData->setText(stream->getStr());

    qDebug() << "Таблица переходов успешно загружена:" << rowCount << "x" << colCount;
}

void QLabTransitionTableWgt::Convertation(QObject* obj)
{
    //qDebug() << "Значение свойства 'one':" << obj->property("one").toString();
    QString one = obj->property("one").toString();
    QString zero = obj->property("zero").toString();
    // Разбиваем строку на список строк
    QStringList list = one.split(' ', Qt::SkipEmptyParts);
    QStringList list1 = zero.split(' ', Qt::SkipEmptyParts);

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



}


