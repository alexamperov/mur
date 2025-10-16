#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <QObject>
#include <QMap>
#include <QVector>
#include <QSet>
#include <QString>

class StateManager : public QObject
{
    Q_OBJECT

public:
    explicit StateManager(QObject *parent = nullptr);
    static StateManager& instance();

    void setStateCode(int stateIndex, const QVector<int>& code);
    QVector<int> getStateCode(int stateIndex) const;
    QMap<int, QVector<int>> getAllStateCodes() const;
    bool hasDuplicateCodes() const;
    bool isValidCode(const QVector<int>& code) const;
    void clear();
    QString getCodeString(int stateIndex) const;

    // Новые методы для безопасной работы
    bool hasStateCode(int stateIndex) const;
    int getStateCodeSize() const;
    bool isInitialized() const { return !m_stateCodes.isEmpty(); }

private:
    QMap<int, QVector<int>> m_stateCodes;
};

#define stateManager StateManager::instance()

#endif // STATEMANAGER_H
