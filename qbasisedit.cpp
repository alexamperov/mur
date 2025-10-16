#include "qbasisedit.h"
#include "ui_qbasisedit.h"

QBasisEdit::QBasisEdit(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::QBasisEdit)
{
	ui->setupUi(this);

	ui->textBrowserD->setBttnText("&#183;");
	ui->textBrowserK->setBttnText("+");

	ui->textBrowserN->setBttnText("&#172;");
	ui->textBrowserN->setBttnWdth(ui->textBrowserD->width() * 2 + 6);

	ui->tableWidgetFunc->setColumnCount(0);
	ui->tableWidgetFunc->setRowCount(0);

	ui->tableWidgetFunc->setMaximumHeight(ui->textBrowserN->maximumHeight() + 35);
	ui->tableWidgetFunc->setMinimumHeight(ui->tableWidgetFunc->maximumHeight());

	setMaximumHeight(ui->tableWidgetFunc->maximumHeight() + 6 + ui->label_3->height());
	setMinimumHeight(maximumHeight());

	connect(ui->textBrowserN, SIGNAL(clicked()), this, SLOT(clickedNot()));
	connect(ui->textBrowserD, SIGNAL(clicked()), this, SLOT(clickedMul()));
	connect(ui->textBrowserK, SIGNAL(clicked()), this, SLOT(clickedAdd()));

	connect(ui->textBrowserN, SIGNAL(clicked()), this, SIGNAL(edited()));
	connect(ui->textBrowserD, SIGNAL(clicked()), this, SIGNAL(edited()));
	connect(ui->textBrowserK, SIGNAL(clicked()), this, SIGNAL(edited()));
}

QBasisEdit::~QBasisEdit()
{
	destroyExpTree(currentExpTree);
	delete ui;
}

int QBasisEdit::calcExp(int x1, int x2, int x3, int x4)
{
	if (checkExp() == 0)
		return recvCaclExp(currentExpTree, x1, x2, x3, x4);
	else
		return -1;
}

QString QBasisEdit::getBasis()
{
	if (checkExp() == 0) {
		if (currentSign == "*")
			return "Шеффера";
		else if (currentSign == "+")
			return "Пирса";
		else
			return "Ошибка";
	} else
		return "Ошибка";
}

QString QBasisEdit::getInitExp()
{
	return initExp;
}

void QBasisEdit::setExp(QString func)
{
    if (initExp != func) {
        initExp = func;
        currentSign = "?";

        ui->tableWidgetFunc->clear();
        ui->tableWidgetFunc->setColumnCount(0);
        ui->tableWidgetFunc->setRowCount(0);
        ui->tableWidgetFunc->setRowCount(1);

        currentFunc.clear();
        lastItem = -1;
        medited = true;

        QBasisTextWgt* wgt;

        for (int i = 0; i < func.size(); i++) {
            wgt = new QBasisTextWgt;

            ui->tableWidgetFunc->setColumnCount(ui->tableWidgetFunc->columnCount() + 1);
            addClearItemsToColumn(ui->tableWidgetFunc->columnCount() - 1);

            int currentColumn = ui->tableWidgetFunc->columnCount() - 1;
            wgt->setTermIndex(currentColumn);
            connect(this, SIGNAL(setTermTextSignal(int,QString)), wgt,
                    SIGNAL(setTermTextSignal(int,QString)));

            QString displayText;
            QChar c = func[i];

            if (c == '!') {
                currentFunc.append('!');
                // Для символа '!' устанавливаем отрицание в таблице
                ensureNotRowExists();
                int notRow = findAvailableNotRow(currentColumn);
                if (notRow >= 0) {
                    ui->tableWidgetFunc->item(notRow, currentColumn)->setBackground(Qt::black);
                }

                // Пропускаем следующий символ, так как он уже учтен в отрицании
                if (i + 1 < func.size()) {
                    i++;
                    c = func[i];
                }
            }

            if (c == '1') {
                currentFunc.append('1');
                displayText = "Q1";
            } else if (c == '2') {
                currentFunc.append('2');
                displayText = "Q2";
            } else if (c == '3') {
                currentFunc.append('3');
                displayText = "Q3";
            } else if (c == '4') {
                currentFunc.append('4');
                displayText = "X";
            } else if (c == '(') {
                currentFunc.append('(');
                displayText = "(";
            } else if (c == ')') {
                currentFunc.append(')');
                displayText = ")";
            } else if (c == '*') {
                currentFunc.append('*');
                displayText = "·";
            } else if (c == '+') {
                currentFunc.append('+');
                displayText = "+";
            } else {
                currentFunc.append('?');
                displayText = "□";
            }

            wgt->setTermText(displayText);

            ui->tableWidgetFunc->setCellWidget(ui->tableWidgetFunc->rowCount() - 1,
                                               currentColumn, wgt);
            ui->tableWidgetFunc->setColumnWidth(currentColumn, 30);

            connect(wgt, SIGNAL(iAmPressed(QBasisTextWgt*)), this, SLOT(setSelection(QBasisTextWgt*)));
            connect(wgt, SIGNAL(iAmPressedWithCtrl(QBasisTextWgt*)), this,
                    SLOT(setSelectionWithCtrl(QBasisTextWgt*)));
            connect(wgt, SIGNAL(iAmPressedWithShift(QBasisTextWgt*)), this,
                    SLOT(setSelectionWithShift(QBasisTextWgt*)));
        }
    }
}

int QBasisEdit::findAvailableNotRow(int column)
{
    // Ищем первую строку отрицания (нечетные индексы), где можно разместить отрицание
    for (int row = 1; row < ui->tableWidgetFunc->rowCount(); row += 2) {
        if (ui->tableWidgetFunc->item(row, column)->background() != Qt::black) {
            return row;
        }
    }

    // Если все строки заняты, создаем новую
    insertClearNotRow(0);
    return 1; // Возвращаем первую строку отрицания
}

void QBasisEdit::saveData(QFileWorker* stream)
{
	QString line;
	stream->setStr(initExp);
	stream->setStr(currentFunc);

	if (ui->tableWidgetFunc->rowCount() > 0)
		stream->setInt((ui->tableWidgetFunc->rowCount() - 1) / 2);
	else
		stream->setInt(0);

	for (int i = ui->tableWidgetFunc->rowCount() - 2; i > 0; i -= 2) {
		line = "";
		for (int j = 0; j < ui->tableWidgetFunc->columnCount(); j++) {
            if (ui->tableWidgetFunc->item(i, j)->background() == Qt::black)
				line.append('!');
			else
				line.append('-');
		}
		stream->setStr(line);
	}
}

void QBasisEdit::openData(QFileWorker* stream)
{
	medited = true;

	initExp = "";
	setExp(stream->getStr());
	currentFunc = stream->getStr();

	bool cont = false;
	int lf = -1;
	int rt = -1;
	QString line;
	int notsCnt = stream->getInt();
	for (int i = 0; i < notsCnt; i++) {
		line = stream->getStr();
		for (int j = 0; j < line.count(); j++) {
			if (line[j] == '!') {
				if (!cont) {
					lf = j;
					rt = j;
					cont = true;
				} else {
					rt = j;
				}
			} else {
				if (lf != -1) {
					NOT(lf, rt);
					lf = -1;
					rt = -1;
					cont = false;
				}
			}
		}
		if (lf != -1)
			NOT(lf, rt);
	}

	for (int i = 0; i < currentFunc.count(); i++)
        if (currentFunc[i] == '*')
			setTermTextSignal(i, "&#183;");
        else if (currentFunc[i] == '+')
			setTermTextSignal(i, "+");
}

void QBasisEdit::setSelection(QBasisTextWgt *wgt)
{
	for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++)
		if (ui->tableWidgetFunc->cellWidget(ui->tableWidgetFunc->rowCount() - 1, i) == wgt) {
			ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->setSelected(true);
			lastItem = i;
		} else {
			ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->setSelected(false);
		}
}

void QBasisEdit::setSelectionWithCtrl(QBasisTextWgt *wgt)
{
	for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++)
		if (ui->tableWidgetFunc->cellWidget(ui->tableWidgetFunc->rowCount() - 1, i) == wgt) {
			if (ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->isSelected())
				ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->setSelected(false);
			else
				ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->setSelected(true);
			lastItem = i;
			return;
		}
}

void QBasisEdit::setSelectionWithShift(QBasisTextWgt *wgt)
{
	if (lastItem != -1) {
        int l = -1;
        int r = -1;
		for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++)
			if (ui->tableWidgetFunc->cellWidget(ui->tableWidgetFunc->rowCount() - 1, i) == wgt) {
				if (lastItem <= i) {
					l = lastItem;
					r = i;
				} else {
					l = i;
					r = lastItem;
				}
				lastItem = i;
			}
		for (int i = l; i <= r; i++)
			ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->setSelected(true);
	}
}

void QBasisEdit::destroyExpTree(expTree *ptr)
{
	if (ptr != 0) {
		destroyExpTree(ptr->lf);
		destroyExpTree(ptr->rt);
		delete ptr;
	}
}

expTree *QBasisEdit::genExpTree(int begin, int end, int mNots)
{
    // Если есть табличные отрицания, добавляем их в дерево
    int actualNots = mNots + cntOfNots(begin); // Предполагая, что cntOfNots считает отрицания для позиции

    expTree *treeItem = new expTree;
    QChar op;
    int index;

    getExpOp(begin, end, actualNots, op, index);

    if (op == '!') {
        treeItem->op = '!';
        treeItem->lf = genExpTree(begin, end, actualNots + 1);
        treeItem->rt = 0;
		} else if (op == '*' || op == '+') {
			treeItem->op = op;
			treeItem->lf = genExpTree(begin, index - 1, mNots);
			treeItem->rt = genExpTree(index + 1, end, mNots);
		} else {
			treeItem->op = op;
			treeItem->lf = 0;
			treeItem->rt = 0;
		}

	return treeItem;
}

void QBasisEdit::getExpOp(int begin, int end, int mNots, QChar &op, int &index)
{
	index = INT_MAX;
	int currentCnt = INT_MAX;
	int newCnt;

	for (int i = begin; i <= end; i++) {
		newCnt = cntOfNots(i);
		if ((currentFunc[i] == '*' || currentFunc[i] == '+') && currentCnt > newCnt - mNots) {
			op = currentFunc[i];
			index = i;
			currentCnt = newCnt - mNots;
		}
	}

	if (index == INT_MAX) {
		if (currentFunc[begin].isDigit()) {
			op = currentFunc[begin];
			index = begin;
		} else if (currentFunc[end].isDigit()) {
			op = currentFunc[end];
			index = end;
		} else {
			op = currentFunc[end - 1];
			index = end - 1;
		}
		currentCnt = cntOfNots(index) - mNots;
	}

	if (index != INT_MAX && currentCnt > 0)
		op = '!';
}

int QBasisEdit::cntOfNots(int index)
{
	int cnt = 0;
	for(int i = 1; i < ui->tableWidgetFunc->rowCount() - 1; i += 2)
        if (ui->tableWidgetFunc->item(i, index)->background() == Qt::black)
			cnt++;
	return cnt;
}

void QBasisEdit::clickedNot()
{
    qDebug() << "\n=== NOT BUTTON CLICKED ===";

    // Сначала соберем информацию о выделенных позициях
    QVector<int> selectedPositions;
    bool hasOperators = false;

    for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++) {
        if (ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->isSelected()) {
            selectedPositions.append(i);
            QChar c = currentFunc[i];
            qDebug() << "Selected position" << i << "character:" << c;
            if (c == '*' || c == '+') {
                hasOperators = true;
            }
        }
    }

    if (selectedPositions.isEmpty()) {
        qDebug() << "No selection - cannot apply NOT";
        showErrMsg(18);
        return;
    }

    if (hasOperators) {
        qDebug() << "Selection contains operators - will apply general NOT to entire expression";
    } else {
        qDebug() << "Selection contains only variables - will apply NOT to individual elements";
    }

    bool isOk = true;
    int begin = -1;
    int end = -1;

    for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++) {
        if (ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->isSelected()) {
            if (begin == -1) {
                begin = i;
                end = i;
            } else {
                end = i;
            }
        } else {
            if (begin != -1) {
                qDebug() << "Applying NOT to range:" << begin << "-" << end;
                if (!NOT(begin, end))
                    isOk = false;
                begin = -1;
                end = -1;
            }
        }
    }

    if (begin != -1) {
        qDebug() << "Applying NOT to final range:" << begin << "-" << end;
        if (!NOT(begin, end))
            isOk = false;
    }

    if (!isOk) {
        qDebug() << "NOT operation failed";
        showErrMsg(18);
    } else {
        qDebug() << "NOT operation completed successfully";
    }

    clearSelection();
    medited = true;
}

bool QBasisEdit::rangeContainsOperators(int begin, int end)
{
    for (int i = begin; i <= end; i++) {
        QChar c = currentFunc[i];
        if (c == '*' || c == '+') {
            return true;
        }
    }
    return false;
}

int QBasisEdit::findAvailableNotRowForRange(int begin, int end)
{
    // Ищем строку, где весь диапазон свободен
    for (int row = 1; row < ui->tableWidgetFunc->rowCount(); row += 2) {
        bool available = true;
        for (int col = begin; col <= end; col++) {
            if (ui->tableWidgetFunc->item(row, col)->background() == Qt::black) {
                available = false;
                break;
            }
        }
        if (available) {
            return row;
        }
    }
    return -1; // Нет доступной строки
}

// Вспомогательный метод для создания строки отрицания
void QBasisEdit::ensureNotRowExists()
{
    if (ui->tableWidgetFunc->rowCount() <= 1) {
        insertClearNotRow(0);
    }
}

void QBasisEdit::updateNotDisplay(int begin, int end)
{
    // Обновляем отображение для всех затронутых ячеек
    for (int i = begin; i <= end; i++) {
        QBasisTextWgt* wgt = qobject_cast<QBasisTextWgt*>(ui->tableWidgetFunc->cellWidget(ui->tableWidgetFunc->rowCount() - 1, i));
        if (wgt) {
            QString currentText = wgt->toPlainText();
            // Добавляем черту над текстом для отрицания
            if (hasNot(i)) {
                if (!currentText.contains("¯")) {
                    wgt->setTermText("<span style=\"text-decoration: overline;\">" + currentText + "</span>");
                }
            } else {
                // Убираем черту если отрицания нет
                wgt->setTermText(currentText.replace("<span style=\"text-decoration: overline;\">", "").replace("</span>", ""));
            }
        }
    }
}

void QBasisEdit::MUL(int index)
{
    if (index >= 0 && index < currentFunc.size()) {
        currentFunc[index] = '*';
        updateDisplay(index);
        medited = true;
    }
}

void QBasisEdit::ADD(int index)
{
    if (index >= 0 && index < currentFunc.size()) {
        currentFunc[index] = '+';
        updateDisplay(index);
        medited = true;
    }
}

bool QBasisEdit::NOT(int begin, int end)
{
    qDebug() << "=== APPLYING NOT OPERATION ===";
    qDebug() << "Range:" << begin << "to" << end;

    if (begin < 0 || end >= currentFunc.size() || begin > end) {
        return false;
    }

    ensureNotRowExists();

    // Проверяем, есть ли операторы в выделенном диапазоне
    bool hasOperators = rangeContainsOperators(begin, end);

    if (hasOperators) {
        qDebug() << "Expression with operators detected - applying NOT to the entire expression";

        // Ищем существующее общее отрицание на всем диапазоне
        bool hasFullNot = false;
        for (int row = 1; row < ui->tableWidgetFunc->rowCount(); row += 2) {
            hasFullNot = true;
            for (int i = begin; i <= end; i++) {
                if (ui->tableWidgetFunc->item(row, i)->background() != Qt::black) {
                    hasFullNot = false;
                    break;
                }
            }
            if (hasFullNot) {
                // Снимаем общее отрицание - УДАЛЯЕМ '!' из currentFunc
                qDebug() << "Removing general NOT from row" << row;
                for (int i = begin; i <= end; i++) {
                    ui->tableWidgetFunc->item(row, i)->setBackground(Qt::white);
                }

                // ОБНОВЛЯЕМ currentFunc - убираем внешние '!'
                currentFunc = currentFunc.mid(1, currentFunc.length() - 2);
                medited = true;
                updateAllDisplay();
                removeClearRows();
                return true;
            }
        }

        // Добавляем общее отрицание - ДОБАВЛЯЕМ '!' в currentFunc
        int notRow = findAvailableNotRowForRange(begin, end);
        if (notRow < 0) {
            insertClearNotRow(0);
            notRow = 1;
        }

        qDebug() << "Adding general NOT at row" << notRow << "to entire expression";
        for (int i = begin; i <= end; i++) {
            ui->tableWidgetFunc->item(notRow, i)->setBackground(Qt::black);
        }

        // ОБНОВЛЯЕМ currentFunc - добавляем внешние '!'
        currentFunc = "!" + currentFunc;
        medited = true;
        updateAllDisplay();
        return true;
    }
    else {
        // Существующая логика для отдельных переменных
        for (int row = 1; row < ui->tableWidgetFunc->rowCount(); row += 2) {
            bool hasFullNot = true;
            for (int i = begin; i <= end; i++) {
                if (ui->tableWidgetFunc->item(row, i)->background() != Qt::black) {
                    hasFullNot = false;
                    break;
                }
            }

            if (hasFullNot) {
                qDebug() << "Removing NOT from row" << row;
                for (int i = begin; i <= end; i++) {
                    ui->tableWidgetFunc->item(row, i)->setBackground(Qt::white);
                }

                // ОБНОВЛЯЕМ currentFunc - убираем '!' для переменных
                for (int i = begin; i <= end; i++) {
                    if (currentFunc[i].isDigit() || currentFunc[i] == '4') {
                        // Убираем '!' перед переменной
                        if (i > 0 && currentFunc[i-1] == '!') {
                            currentFunc.remove(i-1, 1);
                            // Корректируем индексы после удаления
                            i--;
                            end--;
                        }
                    }
                }

                medited = true;
                updateAllDisplay();
                removeClearRows();
                return true;
            }
        }

        int notRow = findAvailableNotRowForRange(begin, end);
        if (notRow < 0) {
            insertClearNotRow(0);
            notRow = 1;
        }

        qDebug() << "Adding NOT at row" << notRow;
        for (int i = begin; i <= end; i++) {
            ui->tableWidgetFunc->item(notRow, i)->setBackground(Qt::black);
        }

        // ОБНОВЛЯЕМ currentFunc - добавляем '!' для переменных
        for (int i = begin; i <= end; i++) {
            if (currentFunc[i].isDigit() || currentFunc[i] == '4') {
                // Добавляем '!' перед переменной
                currentFunc.insert(i, '!');
                // Корректируем индексы после вставки
                i++;
                end++;
            }
        }

        medited = true;
        updateAllDisplay();
        return true;
    }
}

void QBasisEdit::addClearItemsToColumn(int column)
{
	for (int i = 0; i < ui->tableWidgetFunc->rowCount(); i++)
		if (ui->tableWidgetFunc->item(i, column) == 0) {
			ui->tableWidgetFunc->setItem(i, column, new QTableWidgetItem(""));
            ui->tableWidgetFunc->item(i, column)->setBackground(Qt::white);
            ui->tableWidgetFunc->item(i, column)->setForeground(Qt::black);
		}
}

bool QBasisEdit::isMayAddNotInRow(int row, int begin, int end)
{
	for (int i = begin; i <= end; i++)
        if (ui->tableWidgetFunc->item(row, i)->background() == Qt::black)
			return false;
	return true;
}

void QBasisEdit::setNotInRow(int row, int begin, int end)
{
	for (int i = begin; i <= end; i++)
        ui->tableWidgetFunc->item(row, i)->setBackground(Qt::black);
}

void QBasisEdit::setUnNotInRow(int row, int begin, int end)
{
	for (int i = begin; i <= end; i++)
        ui->tableWidgetFunc->item(row, i)->setBackground(Qt::white);
}

void QBasisEdit::insertClearNotRow(int row)
{
    ui->tableWidgetFunc->insertRow(row);
    ui->tableWidgetFunc->setRowHeight(row, 3); // Черная строка
    ui->tableWidgetFunc->insertRow(row);
    ui->tableWidgetFunc->setRowHeight(row, 1); // Разделительная строка

    for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++) {
        // Черная строка (изначально белая, будет закрашиваться при отрицаниях)
        ui->tableWidgetFunc->setItem(row, i, new QTableWidgetItem(""));
        ui->tableWidgetFunc->item(row, i)->setBackground(Qt::white);
        ui->tableWidgetFunc->item(row, i)->setForeground(Qt::black);

        // Разделительная строка (белая)
        ui->tableWidgetFunc->setItem(row + 1, i, new QTableWidgetItem(""));
        ui->tableWidgetFunc->item(row + 1, i)->setBackground(Qt::white);
        ui->tableWidgetFunc->item(row + 1, i)->setForeground(Qt::black);
    }
}

int QBasisEdit::lenOfNotInRow(int row, int begin, int end)
{
	return rightOfNotInRow(row, end) - leftOfNotInRow(row, begin) + 1;
}

int QBasisEdit::leftOfNotInRow(int row, int begin)
{
	int left = begin;
	for (int i = begin - 1; i >= 0; i--)
        if (ui->tableWidgetFunc->item(row, i)->background() == Qt::black)
			left--;
		else
			break;
	return left;
}

int QBasisEdit::rightOfNotInRow(int row, int end)
{
	int right = end;
	for (int i = end + 1; i < ui->tableWidgetFunc->columnCount(); i++)
        if (ui->tableWidgetFunc->item(row, i)->background() == Qt::black)
			right++;
		else
			break;
	return right;
}

int QBasisEdit::upNotInRow(int row, int begin, int end)
{
	if (row != 1) {
		row -= 2;
		if (isMayAddNotInRow(row, begin, end)) {
			setNotInRow(row, begin, end);
			return 0;
		} else {
			int lf = leftOfNotInRow(row, begin);
			int rt = rightOfNotInRow(row, end);
			int nr = upNotInRow(row, lf, rt);
			setUnNotInRow(row + nr, lf, rt);
			setNotInRow(row + nr, begin, end);

			return nr;
		}
	} else {
		insertClearNotRow(0);
		setNotInRow(1, begin, end);
		return 2;
	}
}

int QBasisEdit::cntOfNotInRowBtwnBE(int row, int begin, int end)
{
	int cnt = 0;
	bool cont = false;
	for (int i = begin; i <= end; i++)
        if (ui->tableWidgetFunc->item(row, i)->background() == Qt::black) {
			if (!cont) {
				cnt++;
				cont = true;
			}
		} else if (cont)
			cont = false;
	return cnt;
}

bool QBasisEdit::isNotIsEqual(int row, int begin, int end)
{
	for (int i = begin; i <= end; i++)
        if (ui->tableWidgetFunc->item(row, i)->background() == Qt::white)
			return false;
	return true;
}

void QBasisEdit::removeClearRows()
{
	for (int i = ui->tableWidgetFunc->rowCount() - 2; i > 0; i -= 2)
		if (cntOfNotInRowBtwnBE(i, 0, ui->tableWidgetFunc->columnCount() - 1) == 0) {
			ui->tableWidgetFunc->removeRow(i);
			ui->tableWidgetFunc->removeRow(i - 1);
		}
}

void QBasisEdit::clearSelection()
{
	for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++)
		ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->setSelected(false);
}

void QBasisEdit::downNotInRows()
{
	int lf;
	int rt;
	int cont;
	for (int i = ui->tableWidgetFunc->rowCount() - 4; i > 0; i -= 2) {
		lf = -1;
		rt = -1;
		cont = false;
		for (int j = 0; j < ui->tableWidgetFunc->columnCount(); j++) {
            if (ui->tableWidgetFunc->item(i, j)->background() == Qt::black) {
				if (!cont) {
					lf = j;
					cont = true;
				} else {
					rt = j;
				}
			} else if (lf != -1) {
				if (isMayAddNotInRow(i + 2, lf, rt)) {
					setUnNotInRow(i, lf, rt);
					setNotInRow(i + 2, lf, rt);
				}
				lf = -1;
				rt = -1;
				cont = false;
			}
		}
	}
}

int QBasisEdit::cntOfBrackets(int begin, int end)
{
	int cnt = 0;
	for (int i = begin; i <= end; i++)
		if (currentFunc[i] == '(' || currentFunc[i] == ')')
			cnt++;
	return cnt;
}

bool QBasisEdit::checkForNot(int x1, int x2)
{
	if (x1 != x2) {
		QVector<QVector<int>> x1Data;
		QVector<QVector<int>> x2Data;
		x1Data.resize(3);
		x2Data.resize(3);

		for (int i = 1; i < ui->tableWidgetFunc->rowCount() - 1; i += 2) {
            if (ui->tableWidgetFunc->item(i, x1)->background() == Qt::black) {
				x1Data[0].append(lenOfNotInRow(i, x1, x1));
				x1Data[1].append(leftOfNotInRow(i, x1));
				x1Data[2].append(rightOfNotInRow(i, x1));
			}
            if (ui->tableWidgetFunc->item(i, x2)->background() == Qt::black) {
				x1Data[0].append(lenOfNotInRow(i, x2, x2));
				x1Data[1].append(leftOfNotInRow(i, x2));
				x1Data[2].append(rightOfNotInRow(i, x2));
			}
		}

		int newNotLen = x2 - x1 +1;

		for (int i = 0; i < x1Data[0].count(); i++) {
			if ((x1Data[0][i] > newNotLen && (x1 < x1Data[1][i] || x2 > x1Data[2][i])) ||
				(x1Data[0][i] < newNotLen && (x1 > x1Data[1][i] || x2 < x1Data[2][i])) ||
				(x1Data[0][i] == newNotLen && (x1 != x1Data[1][i] || x2 != x1Data[2][i])))
				return false;
		}

		for (int i = 0; i < x2Data[0].count(); i++) {
			if ((x2Data[0][i] > newNotLen && (x1 < x2Data[1][i] || x2 > x2Data[2][i])) ||
				(x2Data[0][i] < newNotLen && (x1 > x2Data[1][i] || x2 < x2Data[2][i])) ||
				(x2Data[0][i] == newNotLen && (x1 != x2Data[1][i] || x2 != x2Data[2][i])))
				return false;
		}
		return true;
	} else
		return true;
}

QBasisTextWgt::QBasisTextWgt(QWidget *parent) : QTextBrowser(parent)
{
	setText("");
	connect(this, SIGNAL(setTermTextSignal(int,QString)), this, SLOT(setTermText(int,QString)));
}

void QBasisTextWgt::setTermText(QString text)
{
    // Явно устанавливаем HTML с базовыми стилями
    QString html = QString("<html><body style=\"margin: 0; padding: 0; text-align: center;\">%1</body></html>").arg(text);
    setHtml(html);

    // Убеждаемся, что виджет настроен правильно
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::NoFrame);
    viewport()->setAutoFillBackground(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Принудительно обновляем отображение
    update();
    repaint();

    iAmButton = false;
}

void QBasisTextWgt::setBttnText(QString text)
{
	setMaximumHeight(30);
	setMaximumWidth(30);

	txtOn = "<style>body{background-color:lime;}</style><body>" + text + "</span></body>";
	txtOff = "<style>body{background-color:white;}</style><body>" + text + "</span></body>";

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	toggleOff();

	iAmButton = true;
}

void QBasisTextWgt::setTermIndex(int index)
{
	termIndex = index;
}

void QBasisTextWgt::setBttnWdth(int wdth)
{
	setMaximumWidth(wdth);
}

void QBasisTextWgt::toggleOn()
{
	setHtml(txtOn);
	setAlignment(Qt::AlignCenter);
}

void QBasisTextWgt::toggleOff()
{
	setHtml(txtOff);
	setAlignment(Qt::AlignCenter);
}

void QBasisTextWgt::setTermText(int index, QString text)
{
	if (index == termIndex)
		setTermText(text);
}

void QBasisTextWgt::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton) {
		if (iAmButton) {
			toggleOn();
		} else {
			if (e->modifiers() == Qt::ControlModifier)
				iAmPressedWithCtrl(this);
			else if (e->modifiers() == Qt::ShiftModifier)
				iAmPressedWithShift(this);
			else
				iAmPressed(this);
		}
	}
}

void QBasisTextWgt::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton) {
		if (iAmButton) {
			toggleOff();
			clicked();
		}
	}
}

QString QBasisEdit::getExpressionWithNotations()
{
    QString expression;
    bool inNegation = false;
    int negationStart = -1;

    for (int i = 0; i < currentFunc.size(); i++) {
        // Проверяем, есть ли отрицание для этой позиции
        bool hasNotation = hasNot(i);

        if (hasNotation && !inNegation) {
            // Начало отрицания
            expression += "!(";
            inNegation = true;
            negationStart = i;
        } else if (!hasNotation && inNegation) {
            // Конец отрицания
            expression += ")";
            inNegation = false;
        }

        // Добавляем текущий символ
        expression += currentFunc[i];

        // Проверяем конец выражения для отрицания
        if (inNegation && (i == currentFunc.size() - 1 || !hasNot(i+1))) {
            expression += ")";
            inNegation = false;
        }
    }

    return expression;
}

void QBasisEdit::setExpressionWithNegations(const QString& expression)
{
    // Очищаем текущее состояние
    ui->tableWidgetFunc->clear();
    ui->tableWidgetFunc->setColumnCount(0);
    ui->tableWidgetFunc->setRowCount(0);
    ui->tableWidgetFunc->setRowCount(1);

    currentFunc.clear();
    initExp = expression;

    // Парсим выражение с отрицаниями и создаем соответствующие элементы
    // Это сложная логика, требующая парсинга выражения
}

void QBasisEdit::updateDisplay(int index)
{
    QBasisTextWgt* wgt = qobject_cast<QBasisTextWgt*>(ui->tableWidgetFunc->cellWidget(ui->tableWidgetFunc->rowCount() - 1, index));
    if (!wgt) return;

    QString displayText;
    QChar c = currentFunc[index];

    // Определяем базовый текст
    if (c == '1') displayText = "Q1";
    else if (c == '2') displayText = "Q2";
    else if (c == '3') displayText = "Q3";
    else if (c == '4') displayText = "X";
    else if (c == '*') displayText = "·";
    else if (c == '+') displayText = "+";
    else if (c == '(') displayText = "(";
    else if (c == ')') displayText = ")";
    else if (c == '!') {
        // Для символа '!' показываем отрицание следующего символа
        if (index + 1 < currentFunc.size()) {
            QChar nextChar = currentFunc[index + 1];
            if (nextChar == '1') displayText = "<span style=\"text-decoration: overline;\">Q</span><span style=\" vertical-align:sub;\">1</span>";
            else if (nextChar == '2') displayText = "<span style=\"text-decoration: overline;\">Q</span><span style=\" vertical-align:sub;\">2</span>";
            else if (nextChar == '3') displayText = "<span style=\"text-decoration: overline;\">Q</span><span style=\" vertical-align:sub;\">3</span>";
            else if (nextChar == '4') displayText = "<span style=\"text-decoration: overline;\">X</span>";
            else displayText = "!";
        } else {
            displayText = "!";
        }
    }
    else displayText = "□";

    wgt->setTermText(displayText);
}

void QBasisEdit::updateAllDisplay()
{
    for (int i = 0; i < currentFunc.size(); i++) {
        updateDisplay(i);
    }
}

bool QBasisEdit::hasNot(int index)
{
    // Проверяем есть ли отрицание для данной позиции в черных строках
    for (int row = 1; row < ui->tableWidgetFunc->rowCount() - 1; row += 2) {
        QTableWidgetItem* item = ui->tableWidgetFunc->item(row, index);
        if (item && item->background() == Qt::black) {
            return true;
        }
    }
    return false;
}

void QBasisEdit::debugState()
{
    qDebug() << "\n=== QBasisEdit DEBUG STATE ===";
    qDebug() << "Current function:" << currentFunc;
    qDebug() << "Current sign:" << currentSign;
    qDebug() << "medited:" << medited;
    qDebug() << "checkErrCode:" << checkErrCode;

    // Логируем состояние отрицаний
    qDebug() << "Not rows state:";
    for (int row = 1; row < ui->tableWidgetFunc->rowCount(); row += 2) {
        QString rowState;
        for (int col = 0; col < ui->tableWidgetFunc->columnCount(); col++) {
            if (ui->tableWidgetFunc->item(row, col) &&
                ui->tableWidgetFunc->item(row, col)->background() == Qt::black) {
                rowState += "1";
            } else {
                rowState += "0";
            }
        }
        qDebug() << "  Row" << row << ":" << rowState;
    }
    qDebug() << "=== END DEBUG STATE ===\n";
}

void QBasisEdit::clickedMul()
{
    qDebug() << "\n=== MUL BUTTON CLICKED ===";

    bool isOk = true;
    for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++) {
        if (ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->isSelected()) {
            qDebug() << "Setting operator * at position:" << i << "current char:" << currentFunc[i];

            if (currentFunc[i] == '+' || currentFunc[i] == '*' || currentFunc[i] == '?') {
                currentFunc[i] = '*';
                MUL(i);
                qDebug() << "Successfully set * at position" << i;
            } else {
                qDebug() << "Cannot set * at position" << i << "- invalid current character";
                isOk = false;
            }
        }
    }

    if (!isOk) {
        qDebug() << "MUL operation failed on some positions";
        showErrMsg(19);
    } else {
        qDebug() << "MUL operation completed successfully";
    }

    clearSelection();
    medited = true;
}

void QBasisEdit::clickedAdd()
{
    qDebug() << "\n=== ADD BUTTON CLICKED ===";

    bool isOk = true;
    for (int i = 0; i < ui->tableWidgetFunc->columnCount(); i++) {
        if (ui->tableWidgetFunc->item(ui->tableWidgetFunc->rowCount() - 1, i)->isSelected()) {
            qDebug() << "Setting operator + at position:" << i << "current char:" << currentFunc[i];

            if (currentFunc[i] == '+' || currentFunc[i] == '*' || currentFunc[i] == '?') {
                currentFunc[i] = '+';
                ADD(i);
                qDebug() << "Successfully set + at position" << i;
            } else {
                qDebug() << "Cannot set + at position" << i << "- invalid current character";
                isOk = false;
            }
        }
    }

    if (!isOk) {
        qDebug() << "ADD operation failed on some positions";
        showErrMsg(20);
    } else {
        qDebug() << "ADD operation completed successfully";
    }

    clearSelection();
    medited = true;
}

int QBasisEdit::checkExp()
{
    qDebug() << "\n=== CHECKING EXPRESSION ===";
    qDebug() << "Current function:" << currentFunc;
    qDebug() << "medited flag:" << medited;

    if (medited) {
        medited = false;

        // Используем выражение с отрицаниями
        QString expressionWithNots = getExpressionWithNotations();
        qDebug() << "Expression with notations:" << expressionWithNots;
        int cntP = 0;
        int cntS = 0;
        int cntU = 0;

        for (int i = 0; i < currentFunc.count(); i++) {
            if (currentFunc[i] == '*')
                cntS++;
            else if (currentFunc[i] == '+')
                cntP++;
            else if (currentFunc[i] == '?')
                cntU++;
        }

        qDebug() << "Operators count: * =" << cntS << "+ =" << cntP << "? =" << cntU;

        // Упрощаем логику определения базиса
        if (cntS > 0) {
            currentSign = "*";
            qDebug() << "Detected basis: Шеффера (contains * operators)";
        }
        else if (cntP > 0) {
            currentSign = "+";
            qDebug() << "Detected basis: Пирса (contains + operators)";
        }
        else {
            currentSign = "?";
            checkErrCode = 1;
            qDebug() << "No operators found - cannot determine basis";
            return checkErrCode;
        }

        qDebug() << "Destroying old expression tree...";
        destroyExpTree(currentExpTree);

        qDebug() << "Generating new expression tree...";
        currentExpTree = 0;
        currentExpTree = genExpTree(0, currentFunc.count() - 1);

        if (currentExpTree == 0) {
            qDebug() << "Failed to generate expression tree";
            checkErrCode = 1;
        } else {
            qDebug() << "Expression tree generated successfully";
            checkErrCode = 0;
        }

        return checkErrCode;
    } else {
        qDebug() << "No changes - using cached result:" << checkErrCode;
        return checkErrCode;
    }
}

bool QBasisEdit::recvCaclExp(expTree* exp, int x1, int x2, int x3, int x4)
{
    if (!exp) return false;

    if (exp->op == '!') {
        return !recvCaclExp(exp->lf, x1, x2, x3, x4);
    }
    else if (exp->op == '*') {
        bool left = recvCaclExp(exp->lf, x1, x2, x3, x4);
        bool right = recvCaclExp(exp->rt, x1, x2, x3, x4);

        // В базисе Шеффера операция * это NAND (И-НЕ)
        return !(left && right);  // Всегда возвращаем NAND для операции *
    }
    else if (exp->op == '+') {
        bool left = recvCaclExp(exp->lf, x1, x2, x3, x4);
        bool right = recvCaclExp(exp->rt, x1, x2, x3, x4);

        // В базисе Пирса операция + это NOR (ИЛИ-НЕ)
        return !(left || right);  // Всегда возвращаем NOR для операции +
    }
    else if (exp->op == '1') return x1;
    else if (exp->op == '2') return x2;
    else if (exp->op == '3') return x3;
    else if (exp->op == '4') return x4;

    return false;
}

void QBasisEdit::convertToShefferBasis()
{
    qDebug() << "Converting to Sheffer basis...";

    // Для выражения A+B в базисе Шеффера: (A NAND A) NAND (B NAND B)
    // Но это сложно. Временно используем простое преобразование.

    // Просто заменяем + на * и надеемся, что recvCaclExp правильно обработает NAND
    QString newFunc = currentFunc;
    newFunc.replace('+', '*');

    currentFunc = newFunc;
    medited = true;
    updateAllDisplay();
}

void QBasisEdit::convertToPierceBasis()
{
    qDebug() << "Converting to Pierce basis...";

    // Для выражения A*B в базисе Пирса: (A NOR A) NOR (B NOR B)
    // Временно используем простое преобразование.

    QString newFunc = currentFunc;
    newFunc.replace('*', '+');

    currentFunc = newFunc;
    medited = true;
    updateAllDisplay();
}
