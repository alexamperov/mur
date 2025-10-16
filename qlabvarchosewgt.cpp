#include "qlabvarchosewgt.h"
#include "ui_qlabvarchosewgt.h"
#include "qlabstructuretablewgt.h"
#include "ui_qlabstructuretablewgt.h"

#include <QVector>
#include <QDebug>

QLabVarChoseWgt::QLabVarChoseWgt(QWidget *parent) : QWidget(parent), ui(new Ui::QLabVarChoseWgt)
{
    ui->setupUi(this);
    connect(ui->lineEditChosenVar, SIGNAL(returnPressed()), ui->pushButtonChoseVar, SLOT(click()));

    // Инициализируем векторы
    vecTrigger = {"RS", "D", "T", "JK"};
    vecBasis = {"Буля", "Шеффера", "Пирса"};
}



void QLabVarChoseWgt::connectModules(QLabDataBase *db)
{
    currentDB = db;

	if (currentDB->getDBState())
		ui->labelVarCnt->setText(QString::number(currentDB->countVars()));
	else
		ui->labelVarCnt->setText("0");
}

void QLabVarChoseWgt::saveData(QFileWorker* stream)
{
    qDebug() << "Сохранение данных варианта..." << currentVarNum;

    stream->setInt(currentVarNum);

    // Сохраняем текущие данные из preview
    QString zeroText = ui->textBrowserVarPreviewZero->toPlainText();
    QString oneText = ui->textBrowserVarPreviewOne->toPlainText();

    // Определяем индексы триггера и базиса из текущих preview
    int triggerIndex = 0;
    int basisIndex = 0;

    QString currentTrigger = ui->textBrowserVarPreviewTrigger->toPlainText();
    QString currentBasis = ui->textBrowserVarPreviewBasis->toPlainText();

    // Находим индексы
    for (int i = 0; i < vecTrigger.size(); ++i) {
        if (vecTrigger[i] == currentTrigger) {
            triggerIndex = i;
            break;
        }
    }

    for (int i = 0; i < vecBasis.size(); ++i) {
        if (vecBasis[i] == currentBasis) {
            basisIndex = i;
            break;
        }
    }

    stream->setStr(zeroText);
    stream->setStr(oneText);
    stream->setInt(triggerIndex);
    stream->setInt(basisIndex);

    qDebug() << "Сохранены данные:" << zeroText << oneText << triggerIndex << basisIndex;
}

void QLabVarChoseWgt::openData(QFileWorker* stream)
{
    qDebug() << "Начало загрузки данных варианта...";

    // Получаем сохраненные данные
    currentVarNum = stream->getInt();
    QString zero = stream->getStr();
    QString one = stream->getStr();
    int trigger = stream->getInt();
    int basis = stream->getInt();

    qDebug() << "Загружены данные варианта:" << currentVarNum << zero << one << trigger << basis;

    // Обновляем UI с загруженными данными
    ui->lineEditChosenVar->setText(QString::number(currentVarNum));
    ui->textBrowserVarPreviewZero->setVarPreview(zero, true);
    ui->textBrowserVarPreviewOne->setVarPreview(one, true);

    // Инициализируем векторы, если они еще не инициализированы
    if (vecTrigger.isEmpty()) {
        vecTrigger = {"RS", "D", "T", "JK"};
    }
    if (vecBasis.isEmpty()) {
        vecBasis = {"Буля", "Шеффера", "Пирса"};
    }

    // Проверяем границы массивов
    if (trigger >= 0 && trigger < vecTrigger.size()) {
        ui->textBrowserVarPreviewTrigger->setVarPreview(vecTrigger[trigger], false);
    } else {
        qWarning() << "Некорректный индекс триггера:" << trigger;
        ui->textBrowserVarPreviewTrigger->setVarPreview("RS", false); // значение по умолчанию
    }

    if (basis >= 0 && basis < vecBasis.size()) {
        ui->textBrowserVarPreviewBasis->setVarPreview(vecBasis[basis], false);
    } else {
        qWarning() << "Некорректный индекс базиса:" << basis;
        ui->textBrowserVarPreviewBasis->setVarPreview("Буля", false); // значение по умолчанию
    }

    // Пытаемся получить вариант из базы данных, если она доступна
    if (currentDB && currentDB->getDBState() && currentVarNum > 0 && currentVarNum <= currentDB->countVars()) {
        qDebug() << "Получение варианта из базы данных...";
        QObject* obj = currentDB->getVar(currentVarNum - 1);
        if (obj) {
            qDebug() << "Вариант успешно получен из базы данных";
            emit varChanged(obj);
        } else {
            qWarning() << "Не удалось получить вариант из базы данных";
        }
    } else {
        qWarning() << "База данных не доступна или некорректный номер варианта";
        qDebug() << "currentDB:" << currentDB;
        if (currentDB) {
            qDebug() << "DB state:" << currentDB->getDBState();
            qDebug() << "Vars count:" << currentDB->countVars();
        }
    }

    // Блокируем редактирование после загрузки
    ui->lineEditChosenVar->setEnabled(false);
    ui->pushButtonChoseVar->setEnabled(false);

    emit dataEdited();
    qDebug() << "Загрузка данных варианта завершена";
}

bool QLabVarChoseWgt::isOK()
{
	if (currentVarNum > 0) {
		return true;
	} else
		return false;
}

QLabVarChoseWgt::~QLabVarChoseWgt()
{
	delete ui;
}

void QLabVarChoseWgt::showErrMsg()
{
	QMessageBox msg(QMessageBox::Warning,
					"Внимание!",
                    "Вариант работы должен быть от 1 до " +
					QString::number(currentDB->countVars()) + "!",
					QMessageBox::Cancel);
	msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
	msg.exec();
}

QVarPreviewWgt::QVarPreviewWgt(QWidget *parent) : QTextBrowser(parent)
{
	setText("Вариант не выбран!");
	setAlignment(Qt::AlignCenter);
	setMaximumHeight(QFontMetrics(font()).height() + 18);
    setMinimumHeight(maximumHeight());
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void QVarPreviewWgt::setVarPreview(QString text, bool edit)
{
    QString niceText = text;

    if (edit){
        for (int i = 0; i < niceText.count(); ++i) {
            if (niceText.at(i) == ' ') {
                niceText.replace(i, 1, ",");
            }
        }
    }

    setHtml(niceText);
    setAlignment(Qt::AlignCenter);
}

void QLabVarChoseWgt::on_pushButtonChoseVar_clicked()
{
	if (ui->lineEditChosenVar->text().toInt() > 0 && ui->lineEditChosenVar->text().toInt() <= currentDB->countVars()) {
		currentVarNum = ui->lineEditChosenVar->text().toInt();
        QObject* obj = currentDB->getVar(currentVarNum - 1);

//        currentVar = currentDB->getVar(currentVarNum - 1);
        ui->textBrowserVarPreviewZero->setVarPreview(obj->property("zero").toString(), true);
        ui->textBrowserVarPreviewOne->setVarPreview(obj->property("one").toString(), true);
        vecTrigger = {"RS", "D", "T", "JK"};
        vecBasis = {"Буля", "Шеффера", "Пирса"};
        int trigger_index = obj->property("trigger").toInt();
        int basis_index = obj->property("basis").toInt();
        ui->textBrowserVarPreviewTrigger->setVarPreview(vecTrigger[trigger_index], false);
        ui->textBrowserVarPreviewBasis->setVarPreview(vecBasis[basis_index], false);
        qDebug() << "Chosen Trigger:" <<vecTrigger.at(trigger_index);


        dataEdited();
        varChanged(obj);
	} else
		showErrMsg();

}

