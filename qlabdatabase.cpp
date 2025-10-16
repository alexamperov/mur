#include "qlabdatabase.h"
#include <QVariant>
#include <QDebug>

QLabDataBase::QLabDataBase(QObject *parent) : QObject(parent)
{
    for (auto& innerVector : fVars) {
        innerVector.clear();
    }
    fVars.clear();
}

QLabDataBase::~QLabDataBase()
{
    for (auto& innerVector : fVars) {
        innerVector.clear();
    }
    fVars.clear();
}

void QLabDataBase::addVar(int row, int col, QString item)
{
    if (row >= 0 && col >= 0)  {
        if (fVars.count() == row) {
            QVector<QString> otherRow = {};
            fVars.append(otherRow);
        }

        if (fVars[row].count() == col) {
            fVars[row].append(item);
        }else{
            fVars[row][col] = item;
        }

        editedFlag = 1;
        savedFlag = 0;
    }
}

QObject* QLabDataBase::getVar(int num)
{
    if ((fVars.count() > num) && (num >= 0)) {
        QObject *obj = new QObject();
        obj->setProperty("zero", fVars[num][0]);
        obj->setProperty("one", fVars[num][1]);
        qDebug() << "QLABDATABASE TRIGGER: " << fVars[num][2];
        obj->setProperty("trigger", fVars[num][2]);
        obj->setProperty("basis", fVars[num][3]);
        return obj;
    } else {
        return nullptr; // Возвращаем nullptr вместо пустого объекта
    }
}

int QLabDataBase::countVars()
{
    return fVars.count();
}

bool QLabDataBase::checkDB()
{
    if (editedFlag) {
        fErrs.clear();

        if (0 < fVars.count()) {
            for (int i = 0; i < fVars.count(); i++) {

                for (int j = 0; j < fVars[i].count(); j++) {
                    if (!checkSymbolsInString(fVars[i][j]))
                        fErrs.append("Вариант " + QString::number(i + 1) + ": В столбце " + QString::number(j + 1) + " найден неподходящий символ");

                    if (!findConsecutiveSpaces(fVars[i][j])) {
                        fErrs.append("Вариант " + QString::number(i + 1) + ": В столбце " + QString::number(j + 1) + " найдено несколько пробелов подряд");
                    }
                }

                if (!checkVarTwins(i, fVars[i]))
                    fErrs.append("Вариант " + QString::number(i + 1) + ": Дубликат!");
            }
        }
    }

    editedFlag = 0;
    if (fErrs.empty()) {
        checkState = true;
        return true;
    } else {
        checkState = false;
        return false;
    }
}

QStringList QLabDataBase::errReport()
{
    return fErrs;
}

bool QLabDataBase::saveDB(QString fn)
{
    if (stream.openFile(fn, QIODevice::WriteOnly)) {
        stream.setStr("pam-db");
        stream.setStr(QDateTime::currentDateTime().toString("yyyyMMddhhmm"));
        stream.setInt(checkState);

        stream.setInt(fVars.count()); // Записываем количество векторов в fVars
        stream.setInt(fVars[0].count()); // Записываем количество элементов в каждом векторе
        for (int i = 0; i < fVars.count(); i++) {
//            stream.setInt(fVars[i].count());
            for (int j = 0; j < fVars[i].count(); j++) {
                stream.setStr(fVars[i][j]); // Записываем каждый элемент текущего вектора
            }
        }

        stream.closeFile();

        editedFlag = 0;
        savedFlag = 1;
        return true;
    } else {
        return false;
    }
}

bool QLabDataBase::openDB(QString fn)
{
    if (stream.openFile(fn, QIODevice::ReadOnly))  {
        if (stream.getStr() == "pam-db") {
            fVersion = stream.getStr();
            checkState = stream.getInt();

            fVars.clear();

            int fVarsRows = stream.getInt();
            int fVarsCols = stream.getInt();

            fVars.resize(fVarsRows);

            for (int i = 0; i < fVars.size(); i++) {
                if (fVars[i].size() == 0){
                    fVars[i].resize(fVarsCols);
                }

                for (int j = 0; j < fVars[i].size(); j++) {
                    addVar(i, j, stream.getStr());
                }
                varLoaded(i);
                continue;
            }

            editedFlag = 1;
            savedFlag = 1;
            stream.closeFile();
            return true;
        }

        stream.closeFile();
        return false;
    } else {
        return false;
    }
}

QString QLabDataBase::getVersion()
{
    return fVersion;
}

bool QLabDataBase::isSaved()
{
    return savedFlag;
}

bool QLabDataBase::getDBState()
{
    return checkState;
}

bool QLabDataBase::checkSymbolsInString(QString str) {
    for (QChar ch : str) {
        //Проверка символы, не являющиеся цифрой или пробелом
        if (!ch.isDigit() && !ch.isSpace()) {
            return false;
        }

        //Проверка цифры на вхождение в диапазон от 0 до 7
        if (ch.isDigit()){
            if (ch < '0' || ch > '7') {
                return false; // Найдена цифра, не входящая в диапазон от 0 до 7
            }
        }

    }
    return true; // Строка состоит только из цифр и пробелов
}

bool QLabDataBase::checkVarTwins(int num, QVector<QString> item)
{
    for (int i = 0; i < fVars.count(); i++)
        if ((i != num) && this->compareVectors(fVars[i], item))
            return false;
    return true;
}

bool QLabDataBase::compareVectors(QVector<QString> vec1, QVector<QString> vec2) {
    if (vec1.size() != vec2.size()) {
        return false; // Размеры векторов разные, сразу возвращаем false
    }

    for (int i = 0; i < vec1.size(); ++i) {
        if (vec1[i] != vec2[i]) {
            return false; // Найдено несовпадение элементов
        }
    }

    return true; // Все элементы совпадают
}

bool QLabDataBase::findConsecutiveSpaces(QString str) {
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str.at(i) == ' ') {
            count++;
        } else {
            if (count > 1) {
                return false;
            }
            count = 0;
        }
    }
    if (count > 1) {
        return false;
    }
    return true;
}

