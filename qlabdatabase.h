#ifndef QLABDATABASE_H
#define QLABDATABASE_H

#include "qfileworker.h"

#include <QObject>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QDateTime>

class QLabDataBase : public QObject
{
    Q_OBJECT

private:
    QVector<QVector<QString>> fVars;
    QVector<QString> fSyms;
    QStringList fErrs;
    QString fVersion = "";
    QFileWorker stream;


public:
    explicit QLabDataBase(QObject *parent = 0);
    ~QLabDataBase();
    void addVar(int row, int col, QString str);
    QObject* getVar(int num);
    int countVars();
    bool checkDB();
    QStringList errReport();
    bool saveDB(QString fn);
    bool openDB(QString fn);
    void fillSyms();
    QString getVersion();
    QString convertVar(int num);
    QString convertLabVar();
    bool isSaved();
    bool getDBState();

signals:
    void symLoaded(int num);
    void varLoaded(int num);
    void dbOpened();

private:
    bool checkSymbolsInString(QString str);
    bool compareVectors(QVector<QString> vec1, QVector<QString> vec2);
    bool findConsecutiveSpaces(QString str);

    bool checkVarTwins(int num, QVector<QString> item);
    QString checkSym(int num, QString item);
    bool editedFlag = 0;
    bool savedFlag = 1;
    bool checkState = true;
};

#endif // QLABDATABASE_H
