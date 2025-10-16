#include "statemanager.h"
#include <QDebug>

StateManager& StateManager::instance()
{
    static StateManager instance;
    return instance;
}

StateManager::StateManager(QObject *parent) : QObject(parent)
{
}

void StateManager::setStateCode(int stateIndex, const QVector<int>& code)
{
    if (isValidCode(code)) {
        m_stateCodes[stateIndex] = code;
        qDebug() << "StateManager: Set code for state a" << stateIndex << ":" << code;
    } else {
        qWarning() << "StateManager: Invalid code for state a" << stateIndex << "Code should contain only 0 and 1";
    }
}

QVector<int> StateManager::getStateCode(int stateIndex) const
{
    if (m_stateCodes.contains(stateIndex)) {
        return m_stateCodes.value(stateIndex);
    }
    qWarning() << "StateManager: No code found for state a" << stateIndex;
    return QVector<int>();
}

QMap<int, QVector<int>> StateManager::getAllStateCodes() const
{
    return m_stateCodes;
}

bool StateManager::hasDuplicateCodes() const
{
    if (m_stateCodes.isEmpty()) {
        qWarning() << "StateManager: No state codes to check for duplicates";
        return false;
    }

    QSet<QString> uniqueCodes;

    for (auto it = m_stateCodes.begin(); it != m_stateCodes.end(); ++it) {
        QString codeStr = getCodeString(it.key());

        if (uniqueCodes.contains(codeStr)) {
            qDebug() << "StateManager: Duplicate code found for state a" << it.key() << ":" << codeStr;
            return true;
        }
        uniqueCodes.insert(codeStr);
    }

    return false;
}

bool StateManager::isValidCode(const QVector<int>& code) const
{
    if (code.isEmpty()) {
        return false;
    }

    for (int bit : code) {
        if (bit != 0 && bit != 1) {
            return false;
        }
    }
    return true;
}

void StateManager::clear()
{
    m_stateCodes.clear();
    qDebug() << "StateManager: Cleared all state codes";
}

QString StateManager::getCodeString(int stateIndex) const
{
    QVector<int> code = getStateCode(stateIndex);
    if (code.isEmpty()) {
        return "";
    }

    QString result;
    for (int bit : code) {
        result += QString::number(bit);
    }
    return result;
}

bool StateManager::hasStateCode(int stateIndex) const
{
    return m_stateCodes.contains(stateIndex);
}

int StateManager::getStateCodeSize() const
{
    if (m_stateCodes.isEmpty()) {
        return 0;
    }
    // Предполагаем, что все коды имеют одинаковую длину
    return m_stateCodes.first().size();
}
