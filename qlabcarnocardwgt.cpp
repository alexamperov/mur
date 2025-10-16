#include "qlabcarnocardwgt.h"
#include "ui_qlabcarnocardwgt.h"

// ==================== CustomHeaderItem ====================
class CustomHeaderItem : public QWidget
{
public:
    CustomHeaderItem(const QString &text, QWidget *parent = nullptr) : QWidget(parent)
    {
        QLabel *label = new QLabel(this);
        label->setText(text);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("QLabel { font-size: 16px; background-color: #a0a0a4; }");
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(label);
    }
};

// ==================== QCarnoTextWgt ====================
QCarnoTextWgt::QCarnoTextWgt(QWidget *parent) : QTextBrowser(parent)
{
    setText("");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setFrameStyle(QFrame::NoFrame);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void QCarnoTextWgt::setTermText(QString text)
{
    setHtml(text);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::NoFrame);
    viewport()->setAutoFillBackground(false);
    iamATerm = true;
}

void QCarnoTextWgt::setResultText(QString text)
{
    setHtml(text);
    setAlignment(Qt::AlignCenter);
}

void QCarnoTextWgt::setHeaderText(QString text)
{
    QString html = QString("<div style='text-align: center; margin: 0px; padding: 0px;'>%1</div>").arg(text);
    setHtml(html);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::NoFrame);
    viewport()->setAutoFillBackground(false);
}

void QCarnoTextWgt::setRow(int row)
{
    iamInRow = row;
}

void QCarnoTextWgt::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        if (iamATerm && iamInRow != -1)
            iamSelectedInRow(iamInRow);
}

// ==================== QTermsListWgt ====================
QTermsListWgt::QTermsListWgt(QWidget *parent) :  QTableWidget(parent)
{
    setColumnCount(0);
    setRowCount(0);
}

void QTermsListWgt::addTerm(QString text)
{
    QCarnoTextWgt *term = new QCarnoTextWgt(this);
    term->setTermText(text);
    term->setRow(rowCount());
    term->setFont(font());

    setColumnCount(1);
    setRowCount(rowCount() + 1);
    setCellWidget(rowCount() - 1, 0, term);
    verticalHeader()->setVisible(true);

    connect(term, SIGNAL(iamSelectedInRow(int)), this, SLOT(selectTerm(int)));
}

void QTermsListWgt::delSelectedTerm()
{
    if (currentRow() >= 0) {
        removeRow(currentRow());
        termSelected(currentRow());
    }

    if (rowCount() == 0)
        termsListIsEmpty();
}

void QTermsListWgt::selectTerm(int row)
{
    setCurrentCell(row, 0);
    termSelected(row);
}

void QTermsListWgt::resizeEvent(QResizeEvent *event)
{
    if (event->size() != event->oldSize())
        if (rowCount() > 0)
            setColumnWidth(0, event->size().width() - 20);
    QTableWidget::resizeEvent(event);
}

// ==================== QCarnoCardWgt ====================
QCarnoCardWgt::QCarnoCardWgt(QWidget *parent) : QTableWidget(parent)
{
    setColumnCount(6);
    setRowCount(6);

    setHeaderItem(1, 0, "Q<span style=\" vertical-align:sub;\">1</span>");
    setHeaderItem(2, 0, "Q<span style=\" vertical-align:sub;\">1</span>");
    setHeaderItem(3, 0, "<div style=\"text-decoration: overline;\">Q</div><span style=\" vertical-align:sub;\">1</span></div>");
    setHeaderItem(4, 0, "<div style=\"text-decoration: overline;\">Q</div><span style=\" vertical-align:sub;\">1</span></div>");

    setHeaderItem(0, 1, "Q<span style=\" vertical-align:sub;\">2</span>");
    setHeaderItem(0, 2, "Q<span style=\" vertical-align:sub;\">2</span>");
    setHeaderItem(0, 3, "<div style=\"text-decoration: overline;\">Q</div><span style=\" vertical-align:sub;\">2</span></div>");
    setHeaderItem(0, 4, "<div style=\"text-decoration: overline;\">Q</div><span style=\" vertical-align:sub;\">2</span></div>");

    setHeaderItem(5, 1, "<div style=\"text-decoration: overline;\">x</div>");
    setHeaderItem(5, 2, "x");
    setHeaderItem(5, 3, "x");
    setHeaderItem(5, 4, "<div style=\"text-decoration: overline;\">x</div>");

    setHeaderItem(1, 5, "<div style=\"text-decoration: overline;\">Q</div><span style=\" vertical-align:sub;\">3</span>");
    setHeaderItem(2, 5, "Q<span style=\" vertical-align:sub;\">3</span>");
    setHeaderItem(3, 5, "Q<span style=\" vertical-align:sub;\">3</span>");
    setHeaderItem(4, 5, "<div style=\"text-decoration: overline;\">Q</div><span style=\" vertical-align:sub;\">3</span>");

    for (int i = 0; i < columnCount(); i++)
        setColumnWidth(i, 30);

    QTableWidgetItem *nItem;
    for (int i = 1; i < rowCount() - 1; i++){
        for (int j = 1; j < columnCount() - 1; j++) {
            nItem = new QTableWidgetItem("0");
            nItem->setTextAlignment(Qt::AlignCenter);
            setItem(i, j, nItem);
        }
    }

    connect(this, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(clickedTableItem(QTableWidgetItem*)));
}

bool QCarnoCardWgt::isCoverOK(int form)
{
    cover = "";

    QString digit;
    if (form == -1)
        digit = "1";
    else if (form == 1)
        digit = "0";

    QList<QTableWidgetItem*> items = selectedItems();
    for (int i = 0; i < items.size(); i++)
        if (items[i]->row() > 0 && items[i]->row() < 5 &&
            items[i]->column() > 0 && items[i]->column() < 5) {
            if (items[i]->text() != digit)
                if (items[i]->text() != "*")
                    return false;
            cover += QString::number(items[i]->row() - 1) + QString::number(items[i]->column() - 1);
        } else
            return false;

    QString left;
    QString right;
    for (int i = 0; i < cover.size() - 2; i += 2)
        for (int j = i + 2; j < cover.size(); j += 2) {
            left[0] = cover[i];
            left[1] = cover[i + 1];
            right[0] = cover[j];
            right[1] = cover[j + 1];
            if (left.toInt() > right.toInt()) {
                cover[i] = right[0];
                cover[i + 1] = right[1];
                cover[j] = left[0];
                cover[j + 1] = left[1];
            }
        }

    if (cover.size() > 0) {
        QVector<int> c;
        c.resize(cover.size());
        for (int i = 0; i < cover.size(); i++)
            c[i] = cover[i].digitValue();
        if (c.size() == 2) {
            return true;
        }
        if (c.size() == 4) {
            if ((c[0] == c[2] && c[1] == c[3] - 1) ||
                (c[0] == c[2] - 1 && c[1] == c[3]) ||
                (c[0] == c[2] && c[1] == c[3] - 3) ||
                (c[0] == c[2] - 3 && c[1] == c[3])) {
                return true;
            } else
                return false;
        }
        if (c.size() == 8) {
            if ((c[0] == c[2] && c[0] == c[4] && c[0] == c[6] && c[1] == c[3] - 1 && c[1] == c[5] - 2 && c[1] == c[7] - 3) ||
                (c[0] == c[2] - 1 && c[0] == c[4] - 2 && c[0] == c[6] - 3 && c[1] == c[3] && c[1] == c[5] && c[1] == c[7]) ||
                (c[0] == c[2] && c[0] == c[4] - 1 && c[0] == c[6] - 1 && c[1] == c[3] - 1 && c[1] == c[5] && c[1] == c[7] - 1) ||
                (c[0] == c[2] && c[0] == c[4] - 1 && c[0] == c[6] - 1 && c[1] == c[3] - 3 && c[1] == c[5] && c[1] == c[7] - 3) ||
                (c[0] == c[2] && c[0] == c[4] - 3 && c[0] == c[6] - 3 && c[1] == c[3] - 1 && c[1] == c[5] && c[1] == c[7] - 1) ||
                (c[0] == c[2] && c[0] == c[4] - 3 && c[0] == c[6] - 3 && c[1] == c[3] - 3 && c[1] == c[5] && c[1] == c[7] - 3)) {
                return true;
            } else
                return false;
        }
        if (c.size() == 16) {
            if ((c[0] == c[2] && c[0] == c[4] && c[0] == c[6] && c[1] == c[3] - 1 && c[1] == c[5] - 2 && c[1] == c[7] - 3 &&
                 c[0] == c[8] - 3 && c[0] == c[10] - 3 && c[0] == c[12] - 3 && c[0] == c[14] - 3 &&
                 c[1] == c[9] && c[1] == c[11] - 1 && c[1] == c[13] - 2 && c[1] == c[15] - 3) ||
                (c[0] == c[2] && c[0] == c[4] && c[0] == c[6] && c[1] == c[3] - 1 && c[1] == c[5] - 2 && c[1] == c[7] - 3 &&
                 c[0] == c[8] - 1 && c[0] == c[10] - 1 && c[0] == c[12] - 1 && c[0] == c[14] - 1 &&
                 c[1] == c[9] && c[1] == c[11] - 1 && c[1] == c[13] - 2 && c[1] == c[15] - 3) ||
                (c[0] == c[2] && c[0] == c[4] - 1 && c[0] == c[6] - 1 && c[1] == c[3] - 3 && c[1] == c[5] && c[1] == c[7] - 3 &&
                 c[0] == c[8] - 2 && c[0] == c[10] - 2 && c[0] == c[12] - 3 && c[0] == c[14] - 3 &&
                 c[1] == c[9] && c[1] == c[11] - 3 && c[1] == c[13] && c[1] == c[15] - 3) ||
                (c[0] == c[2] && c[0] == c[4] - 1 && c[0] == c[6] - 1 && c[1] == c[3] - 1 && c[1] == c[5] && c[1] == c[7] - 1 &&
                 c[0] == c[8] - 2 && c[0] == c[10] - 2 && c[0] == c[12] - 3 && c[0] == c[14] - 3 &&
                 c[1] == c[9] && c[1] == c[11] - 1 && c[1] == c[13] && c[1] == c[15] - 1)) {
                return true;
            } else
                return false;
        }
        return false;
    } else
        return false;
}

bool QCarnoCardWgt::isOK()
{
    return true;
}

void QCarnoCardWgt::saveData(QFileWorker* stream)
{
    stream->setStr(currentFunc);
    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 5; j++)
            stream->setStr(item(i, j)->text());
}

void QCarnoCardWgt::openData(QFileWorker* stream)
{
    currentFunc = stream->getStr();
    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 5; j++) {
            item(i, j)->setText(stream->getStr());
            item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
}

void QCarnoCardWgt::setFunc(QString func)
{
    currentFunc = func;
}

void QCarnoCardWgt::setExample(bool state)
{
    isExample = state;
    if (isExample) {
        for (int i = 1; i < rowCount() - 1; i++)
            for (int j = 1; j < columnCount() - 1; j++) {
                item(i, j)->setText(QString::number(initCellNums[i - 1][j - 1]));
                item(i, j)->setTextAlignment(Qt::AlignCenter);
            }
    } else {
        for (int i = 1; i < rowCount() - 1; i++)
            for (int j = 1; j < columnCount() - 1; j++) {
                item(i, j)->setText("0");
                item(i, j)->setTextAlignment(Qt::AlignCenter);
            }
    }
}

void QCarnoCardWgt::showCover(QString cover)
{
    clearSelection();

    for (int i = 0; i < cover.size() - 1; i += 2)
        item(cover[i].digitValue() + 1, cover[i + 1].digitValue() + 1)->setSelected(true);
}

void QCarnoCardWgt::setHeaderItem(int row, int column, QString text)
{
    CustomHeaderItem *hItem = new CustomHeaderItem(QString(text));
    setCellWidget(row, column, hItem);
}

void QCarnoCardWgt::keyPressEvent(QKeyEvent *event)
{
    int row = currentRow();
    int column = currentColumn();
    switch (event->key()) {
    case Qt::Key_Up:
        if (1 < row) {
            row--;
        } else {
            row = rowCount() - 2;
        }
        if (column == 0)
            column = 1;
        else if (column == 5)
            column = 4;
        setCurrentCell(row, column);
        break;
    case Qt::Key_Left:
        if (row > 1) {
            if (column > 1) {
                column--;
            } else {
                row--;
                column = columnCount() - 2;
            }
        } else if (row == 1) {
            if (column > 1) {
                column--;
            } else {
                row = rowCount() - 2;
                column = columnCount() - 2;
            }
        } else if (column > 1) {
            column--;
            row = 1;
        } else {
            row = rowCount() - 2;
            column = columnCount() - 2;
        }
        if (row == 5)
            row = 4;
        setCurrentCell(row, column);
        break;
    case Qt::Key_Right:
        if (columnCount() - 1 > (column + 1)) {
            column++;
        } else if (rowCount() - 1 > (row + 1)) {
            row++;
            column = 1;
        } else {
            row = 1;
            column = 1;
        }
        if (row == 0)
            row = 1;
        else if (row == 5)
            row = 4;
        setCurrentCell(row, column);
        break;
    case Qt::Key_Down:
        if (rowCount() - 1 > (row + 1)) {
            row++;
        } else {
            row = 1;
        }
        if (column == 0)
            column = 1;
        else if (column == 5)
            column = 4;
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

void QCarnoCardWgt::toggleTableItem(int row, int column)
{
    if (!isExample){
        if ((row > 0 && column > 0) && (row < rowCount() - 1 && column < columnCount() - 1)) {
            if (item(row, column)->text() == "0")
                item(row, column)->setText("1");
            else if (item(row, column)->text() == "1") {
                item(row, column)->setText("*");
            } else
                item(row, column)->setText("0");
            isTested = false;
            dataEdited();
        }
    }
}

void QCarnoCardWgt::deleteTableItem(int row, int column)
{
    if (!isExample) {
        item(row, column)->setText("0");
        isTested = false;
        dataEdited();
    }
}

void QCarnoCardWgt::clickedTableItem(QTableWidgetItem *item)
{
    toggleTableItem(item->row(), item->column());
}

// ==================== QLabCarnoCardWgt ====================
QLabCarnoCardWgt::QLabCarnoCardWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLabCarnoCardWgt)
{
    ui->setupUi(this);

    connect(ui->tableWidgetTermsLst, SIGNAL(termsListIsEmpty()), ui->widgetTermEdit, SLOT(unblock()));
    connect(ui->tableWidgetTermsLst, SIGNAL(termSelected(int)), this, SLOT(showCover(int)));

    ui->pushButtonAddTerm->setMinimumHeight(ui->widgetTermEdit->maximumHeight() / 2 - 6);
    ui->pushButtonDelTerm->setMinimumHeight(ui->widgetTermEdit->maximumHeight() / 2 - 6);

    ui->textBrowserResult->setMaximumHeight(QFontMetrics(ui->textBrowserResult->font()).height() + 12);
    ui->textBrowserResult->setMinimumHeight(ui->textBrowserResult->maximumHeight());

    ui->groupBoxResult->setMaximumHeight(ui->textBrowserResult->maximumHeight() + 35);
    ui->groupBoxResult->setMinimumHeight(ui->groupBoxResult->maximumHeight());
    ui->pushButtonCheckResult->setMinimumHeight(ui->textBrowserResult->maximumHeight());

    ui->tableWidgetFuncPreview->setRowCount(18);
    ui->tableWidgetFuncPreview->setColumnCount(5);

    ui->tableWidgetFuncPreview->setSpan(0, 0, 1, 3);
    ui->tableWidgetFuncPreview->setItem(0, 0, new QTableWidgetItem("Исх. сост."));
    ui->tableWidgetFuncPreview->item(0, 0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetFuncPreview->item(0, 0)->setBackground(Qt::gray);

    for (int i = 0; i < 4; i++) {
        ui->tableWidgetFuncPreview->setItem(1, i, new QTableWidgetItem(QString("Q%1").arg(3-i)));
        ui->tableWidgetFuncPreview->item(1, i)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetFuncPreview->item(1, i)->setBackground(Qt::gray);
    }

    ui->tableWidgetFuncPreview->setSpan(0, 3, 2, 1);
    ui->tableWidgetFuncPreview->setItem(0, 3, new QTableWidgetItem("Вх. сигн. Х."));
    ui->tableWidgetFuncPreview->item(0, 3)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetFuncPreview->item(0, 3)->setBackground(Qt::gray);

    ui->tableWidgetFuncPreview->setSpan(0, 4, 2, 1);
    ui->tableWidgetFuncPreview->setItem(0, 4, new QTableWidgetItem("J3"));
    ui->tableWidgetFuncPreview->item(0, 4)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetFuncPreview->item(0, 4)->setBackground(Qt::gray);

    for (int row = 0; row < ui->tableWidgetFuncPreview->rowCount(); row++) {
        for (int col = 0; col < ui->tableWidgetFuncPreview->columnCount(); col++) {
            if (!ui->tableWidgetFuncPreview->item(row, col)) {
                QTableWidgetItem* item = new QTableWidgetItem("");
                item->setTextAlignment(Qt::AlignCenter);

                if (row >= 2) {
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                } else {
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                    item->setBackground(Qt::lightGray);
                }

                ui->tableWidgetFuncPreview->setItem(row, col, item);
            }
        }
    }

    for (int i = 0; i < ui->tableWidgetFuncPreview->columnCount(); i++) {
        ui->tableWidgetFuncPreview->setColumnWidth(i, ui->tableWidgetFuncPreview->rowHeight(0));
    }

    ui->groupBoxBasisEdit->setMaximumHeight(ui->widgetBasisEdit->maximumHeight() + 35);
    ui->groupBoxBasisEdit->setMinimumHeight(ui->groupBoxBasisEdit->maximumHeight());

    connect(ui->widgetBasisEdit, SIGNAL(edited()), this, SLOT(basisEdited()));
    connect(ui->tableWidgetCardCarno, SIGNAL(dataEdited()), this, SIGNAL(dataEdited()));
    connect(ui->widgetBasisEdit, SIGNAL(showErrMsg(int)), this, SLOT(showErrMsg(int)));

    ui->pushButtonCheckBasis->setMinimumHeight(ui->widgetBasisEdit->minimumHeight());
}

QLabCarnoCardWgt::~QLabCarnoCardWgt()
{
    delete ui;
}

void QLabCarnoCardWgt::setFuncNum(int funcNum)
{
    currentFuncNum = funcNum;

    QString funcChar;
    switch (currentFuncNum) {
    case 0: funcChar = "a"; break;
    case 1: funcChar = "b"; break;
    case 2: funcChar = "c"; break;
    case 3: funcChar = "d"; break;
    case 4: funcChar = "e"; break;
    case 5: funcChar = "f"; break;
    case 6: funcChar = "g"; break;
    }

    QCarnoTextWgt* hItem = new QCarnoTextWgt;
    hItem->setHeaderText("f<span style=\" vertical-align:sub;\">" + funcChar + "</span>");
    ui->tableWidgetFuncPreview->setCellWidget(0, 1, hItem);
}

bool QLabCarnoCardWgt::isOK()
{
    return true;
}

void QLabCarnoCardWgt::clearTableData()
{
    qDebug() << "Clearing table data for rows 2-17";

    for (int row = 2; row < ui->tableWidgetFuncPreview->rowCount(); row++) {
        for (int col = 0; col < ui->tableWidgetFuncPreview->columnCount(); col++) {
            QTableWidgetItem* item = ui->tableWidgetFuncPreview->item(row, col);
            if (item) {
                item->setText("");
            }
        }
    }
}

void QLabCarnoCardWgt::setupTableHeaders()
{
    ui->tableWidgetFuncPreview->setSpan(0, 0, 1, 3);
    QTableWidgetItem* header1 = new QTableWidgetItem("Входное состояние");
    header1->setTextAlignment(Qt::AlignCenter);
    header1->setBackground(Qt::gray);
    header1->setFlags(header1->flags() & ~Qt::ItemIsEditable);
    ui->tableWidgetFuncPreview->setItem(0, 0, header1);

    QTableWidgetItem* header2 = new QTableWidgetItem("X");
    header2->setTextAlignment(Qt::AlignCenter);
    header2->setBackground(Qt::gray);
    header2->setFlags(header2->flags() & ~Qt::ItemIsEditable);
    ui->tableWidgetFuncPreview->setItem(0, 3, header2);

    QTableWidgetItem* header3 = new QTableWidgetItem("Вход триггера");
    header3->setTextAlignment(Qt::AlignCenter);
    header3->setBackground(Qt::gray);
    header3->setFlags(header3->flags() & ~Qt::ItemIsEditable);
    ui->tableWidgetFuncPreview->setItem(0, 4, header3);

    QStringList bitHeaders;
    bitHeaders << "Q3" << "Q2" << "Q1";
    for (int i = 0; i < 3; i++) {
        QTableWidgetItem* bitHeader = new QTableWidgetItem(bitHeaders[i]);
        bitHeader->setTextAlignment(Qt::AlignCenter);
        bitHeader->setBackground(Qt::lightGray);
        bitHeader->setFlags(bitHeader->flags() & ~Qt::ItemIsEditable);
        ui->tableWidgetFuncPreview->setItem(1, i, bitHeader);
    }

    QTableWidgetItem* empty1 = new QTableWidgetItem("");
    empty1->setBackground(Qt::lightGray);
    empty1->setFlags(empty1->flags() & ~Qt::ItemIsEditable);
    ui->tableWidgetFuncPreview->setItem(1, 3, empty1);

    QTableWidgetItem* empty2 = new QTableWidgetItem("");
    empty2->setBackground(Qt::lightGray);
    empty2->setFlags(empty2->flags() & ~Qt::ItemIsEditable);
    ui->tableWidgetFuncPreview->setItem(1, 4, empty2);
}

QPoint QLabCarnoCardWgt::getCarnoCoordinates(int Q3, int Q2, int Q1, int X)
{
    int row = -1;
    int col = -1;

    if (Q1 == 1 && Q3 == 0) row = 1;
    else if (Q1 == 1 && Q3 == 1) row = 2;
    else if (Q1 == 0 && Q3 == 1) row = 3;
    else if (Q1 == 0 && Q3 == 0) row = 4;

    if (Q2 == 1 && X == 0) col = 1;
    else if (Q2 == 1 && X == 1) col = 2;
    else if (Q2 == 0 && X == 1) col = 3;
    else if (Q2 == 0 && X == 0) col = 4;

    return QPoint(col, row);
}

void CardCarno::genExpressions(bool& form, vector<string>& flatExps, vector<vector<string>>& combExps,
                               vector<vector<vector<unsigned int>>>& coversCombs)
{
    vector<vector<unsigned int>> coversSigns = {
        /* НДФ для дополненной карты Карно */
        /*  Q1  */ {0, 0, 0, 1, 0, 2, 0, 3, 0, 4, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4},
        /* !Q1  */ {2, 0, 2, 1, 2, 2, 2, 3, 2, 4, 3, 0, 3, 1, 3, 2, 3, 3, 3, 4},
        /*  Q2  */ {0, 0, 0, 1, 0, 4, 1, 0, 1, 1, 1, 4, 2, 0, 2, 1, 2, 4, 3, 0, 3, 1, 3, 4, 4, 0, 4, 1, 4, 4},
        /* !Q2  */ {0, 2, 0, 3, 1, 2, 1, 3, 2, 2, 2, 3, 3, 2, 3, 3, 4, 2, 4, 3},
        /*  X   */ {0, 1, 0, 2, 1, 1, 1, 2, 2, 1, 2, 2, 3, 1, 3, 2, 4, 1, 4, 2},  // X вместо Q3
        /* !X   */ {0, 0, 0, 3, 0, 4, 1, 0, 1, 3, 1, 4, 2, 0, 2, 3, 2, 4, 3, 0, 3, 3, 3, 4, 4, 0, 4, 3, 4, 4},  // !X вместо !Q3
        /*  Q3  */ {1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 2, 0, 2, 1, 2, 2, 2, 3, 2, 4},  // Q3 вместо X
        /* !Q3  */ {0, 0, 0, 1, 0, 2, 0, 3, 0, 4, 3, 0, 3, 1, 3, 2, 3, 3, 3, 4, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4}   // !Q3 вместо !X
    };

    flatExps.clear();
    combExps.clear();

    string fullExp, partExp;
    bool isSignIn, isAddSign;

    // Соответствие термов выбранной форме и coversSigns
    vector<string> signsInNDF = {"Q1", "!Q1", "Q2", "!Q2", "X", "!X", "Q3", "!Q3"};  // X и Q3 поменяны местами
    vector<string> signsInNKF = {"!Q1", "Q1", "!Q2", "Q2", "!X", "X", "!Q3", "Q3"};  // X и Q3 поменяны местами

    // проходим по всему списку комбинаций областей
    for (unsigned int combNum = 0; combNum < coversCombs.size(); combNum++) {

        fullExp.clear();
        combExps.push_back({});
        // проходим по списку областей в комбинациях
        for (unsigned int combNumCover = 0; combNumCover < coversCombs[combNum].size(); combNumCover++) {

            partExp.clear();
            // проходим по списку термов (терм <-> область покрытия)
            for (unsigned int signNum = 0; signNum < coversSigns.size();  signNum++) {

                isAddSign = true;
                // проверка, что область склеивания целиком входит в облать покрытия терма, рангом 1
                for (unsigned int cA = 0; cA < coversCombs[combNum][combNumCover].size(); cA += 2) {

                    isSignIn = false;
                    for (unsigned int sA = 0; sA < coversSigns[signNum].size(); sA += 2)

                        if (coversCombs[combNum][combNumCover][cA] == coversSigns[signNum][sA] &&
                            coversCombs[combNum][combNumCover][cA + 1] == coversSigns[signNum][sA + 1]) {
                            isSignIn = true;
                            break;
                        }

                    // если не входит - пропускаем
                    if (!isSignIn) {
                        isAddSign = false;
                        break;
                    }
                }

                // если входит - добавляем в формируемый терм
                if (isAddSign) {
                    partExp += form ? signsInNDF[signNum] + "*" : signsInNKF[signNum] + "+";
                }
            }

            partExp.erase(partExp.size() - 1, 1);
            fullExp += form ? "(" + partExp + ")+" : "(" + partExp + ")*";
            combExps.back().push_back(partExp);
        }

        fullExp.erase(fullExp.size() - 1, 1);
        flatExps.push_back(fullExp);
    }
}

void QLabCarnoCardWgt::debugCarnoStructure()
{
    qDebug() << "=== Carno Map Structure ===";

    for (int row = 1; row <= 4; row++) {
        QWidget* rowHeader = ui->tableWidgetCardCarno->cellWidget(row, 0);
        if (rowHeader) {
            qDebug() << "Row" << row << "header:" << rowHeader->metaObject()->className();
        }
    }

    for (int col = 1; col <= 4; col++) {
        QWidget* colHeader = ui->tableWidgetCardCarno->cellWidget(0, col);
        if (colHeader) {
            qDebug() << "Col" << col << "header:" << colHeader->metaObject()->className();
        }
    }

    qDebug() << "Key cells:";
    qDebug() << "Cell [2,4] (Q1,Q2,Q3,NotX):" << (ui->tableWidgetCardCarno->item(2, 4) ? ui->tableWidgetCardCarno->item(2, 4)->text() : "NULL");
    qDebug() << "Cell [3,3] (NotQ1,NotQ2,Q3,NotX):" << (ui->tableWidgetCardCarno->item(3, 3) ? ui->tableWidgetCardCarno->item(3, 3)->text() : "NULL");
}

void QLabCarnoCardWgt::testCarnoCoordinates()
{
    qDebug() << "=== Testing Carno Coordinates ===";

    QVector<QVector<int>> testCases = {
        {1, 1, 1, 0}, // Q1 Q2 Q3 NotX
        {1, 1, 0, 0}, // NotQ1 Q2 Q3 NotX
        {0, 1, 1, 0}, // Q1 Q2 NotQ3 NotX
        {1, 0, 1, 0}, // Q1 NotQ2 Q3 NotX
    };

    for (const QVector<int>& testCase : testCases) {
        QPoint coords = getCarnoCoordinates(testCase[0], testCase[1], testCase[2], testCase[3]);
        qDebug() << "Q3=" << testCase[0] << "Q2=" << testCase[1] << "Q1=" << testCase[2]
                 << "X=" << testCase[3] << "-> row=" << coords.y() << "col=" << coords.x();

        QTableWidgetItem* carnoItem = ui->tableWidgetCardCarno->item(coords.y(), coords.x());
        if (carnoItem) {
            qDebug() << "  Current value in cell:" << carnoItem->text();
        }
    }
}

bool QLabCarnoCardWgt::checkCarnoMap()
{
    if (!ui->tableWidgetFuncPreview) {
        qWarning() << "Minimization table is null!";
        return false;
    }

    bool isValid = true;

    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= 4; col++) {
            QTableWidgetItem* item = ui->tableWidgetCardCarno->item(row, col);
            if (item) {
                item->setBackground(Qt::white);
            }
        }
    }

    qDebug() << "=== Starting Carno map check ===";

    for (int tableRow = 2; tableRow < ui->tableWidgetFuncPreview->rowCount(); tableRow++) {
        QTableWidgetItem* itemQ3 = ui->tableWidgetFuncPreview->item(tableRow, 0);
        QTableWidgetItem* itemQ2 = ui->tableWidgetFuncPreview->item(tableRow, 1);
        QTableWidgetItem* itemQ1 = ui->tableWidgetFuncPreview->item(tableRow, 2);
        QTableWidgetItem* itemX = ui->tableWidgetFuncPreview->item(tableRow, 3);
        QTableWidgetItem* itemTrigger = ui->tableWidgetFuncPreview->item(tableRow, 4);

        if (itemQ3 && itemQ2 && itemQ1 && itemX && itemTrigger) {
            bool okQ3, okQ2, okQ1, okX;
            int Q3 = itemQ3->text().toInt(&okQ3);
            int Q2 = itemQ2->text().toInt(&okQ2);
            int Q1 = itemQ1->text().toInt(&okQ1);
            int X = itemX->text().toInt(&okX);
            QString expectedValue = itemTrigger->text();

            if (!okQ3 || !okQ2 || !okQ1 || !okX) {
                qWarning() << "Invalid number format in row" << tableRow;
                continue;
            }

            qDebug() << "Row" << tableRow << ": Q3=" << Q3 << "Q2=" << Q2 << "Q1=" << Q1 << "X=" << X << "Expected:" << expectedValue;

            QPoint coords = getCarnoCoordinates(Q3, Q2, Q1, X);

            if (coords.x() != -1 && coords.y() != -1) {
                QTableWidgetItem* carnoItem = ui->tableWidgetCardCarno->item(coords.y(), coords.x());
                QString actualValue = carnoItem ? carnoItem->text() : "";

                qDebug() << "  Carno coordinates: row=" << coords.y() << "col=" << coords.x()
                         << "Actual:" << actualValue;

                if (actualValue != expectedValue) {
                    isValid = false;
                    if (carnoItem) {
                        carnoItem->setBackground(Qt::red);
                    }
                    qDebug() << "  ERROR: expected '" << expectedValue << "', got '" << actualValue << "'";
                }
            } else {
                qWarning() << "  Invalid coordinates for row" << tableRow;
            }
        }
    }

    qDebug() << "=== Carno map check complete: " << (isValid ? "VALID" : "INVALID") << "===";
    return isValid;
}

void QLabCarnoCardWgt::updateResult()
{
    if (userSTerms.isEmpty()) {
        resultS = "";
        resultN = "";
        ui->textBrowserResult->setResultText("");
        return;
    }

    QString opS, opN;
    if (currentForm == -1) {
        opS = "+";
        opN = " + ";
    } else {
        opS = "*";
        opN = " · ";
    }

    resultS = "";
    resultN = "";
    for (int i = 0; i < userSTerms.count(); i++) {
        if (i > 0) {
            resultS += opS;
            resultN += opN;
        }
        resultS += "(" + userSTerms[i] + ")";
        resultN += "(" + convertToNiceTerm(userSTerms[i], currentForm) + ")";
    }

    qDebug() << "Generated expression:" << resultS;
    ui->textBrowserResult->setResultText(resultN);

    // Уничтожаем старое дерево выражений
    destroyExpTree(resultExp);
    resultExp = nullptr;

    isResultTested = false;
    isBasisTested = false;
}

void QLabCarnoCardWgt::basisEdited()
{
    isBasisTested = false;
    dataEdited();
}

void QLabCarnoCardWgt::saveData(QFileWorker* stream)
{
    for (int i = 1; i < ui->tableWidgetFuncPreview->rowCount(); i++)
        stream->setStr(ui->tableWidgetFuncPreview->item(i, 1)->text());

    ui->tableWidgetCardCarno->saveData(stream);
    ui->widgetBasisEdit->saveData(stream);

    stream->setStr(currentFunc);
    stream->setInt(currentFuncNum);
    stream->setInt(currentForm);
    stream->setInt(currentTerm);

    stream->setInt(userCovers.count());
    for (int i = 0; i < userCovers.count(); i++)
        stream->setStr(userCovers[i]);

    stream->setInt(userSTerms.count());
    for (int i = 0; i < userSTerms.count(); i++)
        stream->setStr(userSTerms[i]);

    stream->setInt(userNTerms.count());
    for (int i = 0; i < userNTerms.count(); i++)
        stream->setStr(userNTerms[i]);

    stream->setInt(algmTermsD.size());
    for (int i = 0; i < int(algmTermsD.size()); i++) {
        stream->setInt(algmTermsD[i].size());
        for (int j = 0; j < int(algmTermsD[i].size()); j++)
            stream->setStr(QString::fromStdString(algmTermsD[i][j]));
    }

    stream->setInt(algmTermsK.size());
    for (int i = 0; i < int(algmTermsK.size()); i++) {
        stream->setInt(algmTermsK[i].size());
        for (int j = 0; j < int(algmTermsK[i].size()); j++)
            stream->setStr(QString::fromStdString(algmTermsK[i][j]));
    }

    stream->setStr(resultS);
    stream->setStr(resultN);

    stream->setInt(isResultTested);
    stream->setInt(resultTestCode);

    stream->setInt(isBasisTested);
    stream->setInt(basisTestCode);
}

void QLabCarnoCardWgt::openData(QFileWorker* stream)
{
    for (int i = 1; i < ui->tableWidgetFuncPreview->rowCount(); i++) {
        ui->tableWidgetFuncPreview->item(i, 1)->setText(stream->getStr());
        ui->tableWidgetFuncPreview->item(i, 1)->setTextAlignment(Qt::AlignCenter);
    }

    ui->tableWidgetCardCarno->openData(stream);
    ui->widgetBasisEdit->openData(stream);

    currentFunc = stream->getStr();
    currentFuncNum = stream->getInt();
    currentForm = stream->getInt();
    currentTerm = stream->getInt();

    userCovers.resize(stream->getInt());
    for (int i = 0; i < userCovers.count(); i++)
        userCovers[i] = stream->getStr();

    userSTerms.resize(stream->getInt());
    for (int i = 0; i < userSTerms.count(); i++)
        userSTerms[i] = stream->getStr();

    userNTerms.resize(stream->getInt());
    for (int i = 0; i < userNTerms.count(); i++) {
        userNTerms[i] = stream->getStr();
        ui->tableWidgetTermsLst->addTerm(userNTerms[i]);
    }

    algmTermsD.resize(stream->getInt());
    for (int i = 0; i < algmTermsD.size(); i++) {
        algmTermsD[i].resize(stream->getInt());
        for (int j = 0; j < algmTermsD[i].size(); j++)
            algmTermsD[i][j] = stream->getStr().toStdString();
    }

    algmTermsK.resize(stream->getInt());
    for (int i = 0; i < algmTermsK.size(); i++) {
        algmTermsK[i].resize(stream->getInt());
        for (int j = 0; j < algmTermsK[i].size(); j++)
            algmTermsK[i][j] = stream->getStr().toStdString();
    }

    ui->tableWidgetTermsLst->selectTerm(currentTerm);
    if (currentForm != 0)
        ui->widgetTermEdit->block(currentForm);

    resultS = stream->getStr();
    resultN = stream->getStr();

    ui->textBrowserResult->setResultText(resultN);

    isResultTested = stream->getInt();
    resultTestCode = stream->getInt();

    isBasisTested = stream->getInt();
    basisTestCode = stream->getInt();
}

bool QLabCarnoCardWgt::isValidCarnoCover(const QString& cover)
{
    if (cover.isEmpty()) {
        qDebug() << "Empty cover provided";
        return false;
    }

    qDebug() << "Validating cover:" << cover;

    QSet<int> rows, cols;
    for (int i = 0; i < cover.size(); i += 2) {
        if (i + 1 < cover.size()) {
            int row = QString(cover[i]).toInt();
            int col = QString(cover[i + 1]).toInt();

            // Проверяем, что координаты в допустимом диапазоне
            if (row < 0 || row > 3 || col < 0 || col > 3) {
                qDebug() << "Invalid coordinates - row:" << row << "col:" << col;
                return false;
            }

            rows.insert(row);
            cols.insert(col);
        }
    }

    // Преобразуем в списки и сортируем для анализа
    QList<int> rowList = rows.values();
    QList<int> colList = cols.values();
    std::sort(rowList.begin(), rowList.end());
    std::sort(colList.begin(), colList.end());

    // Проверяем размер области (должен быть степенью двойки)
    int areaSize = rows.size() * cols.size();
    if (areaSize != 1 && areaSize != 2 && areaSize != 4 && areaSize != 8) {
        qDebug() << "Invalid area size:" << areaSize;
        return false;
    }

    // Проверяем, что область прямоугольная
    // Для строк: должны идти подряд или быть циклически связанными (0 и 3)
    bool rowsValid = false;
    if (rows.size() == 1) {
        rowsValid = true;
    } else if (rows.size() == 2) {
        // Проверяем, что строки идут подряд или это 0 и 3 (циклическая связь)
        if ((rowList[1] - rowList[0] == 1) || (rowList[0] == 0 && rowList[1] == 3)) {
            rowsValid = true;
        }
    } else if (rows.size() == 4) {
        // Все строки - всегда валидно
        rowsValid = true;
    }

    // Для столбцов: аналогичная проверка
    bool colsValid = false;
    if (cols.size() == 1) {
        colsValid = true;
    } else if (cols.size() == 2) {
        // Проверяем, что столбцы идут подряд или это 0 и 3 (циклическая связь)
        if ((colList[1] - colList[0] == 1) || (colList[0] == 0 && colList[1] == 3)) {
            colsValid = true;
        }
    } else if (cols.size() == 4) {
        // Все столбцы - всегда валидно
        colsValid = true;
    }

    if (!rowsValid || !colsValid) {
        qDebug() << "Invalid rectangular area - rows:" << rowList << "cols:" << colList;
        return false;
    }

    qDebug() << "Valid cover - rows:" << rows.size() << "cols:" << cols.size()
             << "area:" << areaSize << "rowList:" << rowList << "colList:" << colList;
    return true;
}

QString QLabCarnoCardWgt::generateCorrectTermFromCover(const QString& cover, int form)
{
    if (cover.isEmpty()) {
        qDebug() << "Empty cover provided";
        return "";
    }

    qDebug() << "Generating correct term from cover:" << cover << "form:" << form;

    QSet<int> rows, cols;
    for (int i = 0; i < cover.size(); i += 2) {
        if (i + 1 < cover.size()) {
            int row = QString(cover[i]).toInt();
            int col = QString(cover[i + 1]).toInt();
            rows.insert(row);
            cols.insert(col);
        }
    }

    // Анализируем, какие переменные постоянны в выделенной области
    bool q1Constant = allSameQ1(rows);
    bool q2Constant = allSameQ2(cols);
    bool q3Constant = allSameQ3(rows);
    bool xConstant = allSameX(cols);

    qDebug() << "Constants - Q1:" << q1Constant << "Q2:" << q2Constant
             << "Q3:" << q3Constant << "X:" << xConstant;

    // Строим терм только из постоянных переменных с именами Q1, Q2, Q3, X
    QString term;
    QString separator = (form == -1) ? "*" : "+";

    if (form == -1) { // НДФ
        if (q1Constant) {
            int q1Value = getQ1FromRow(*rows.begin());
            term += (q1Value == 1) ? "Q1" : "!Q1";
            term += separator;
        }
        if (q2Constant) {
            int q2Value = getQ2FromCol(*cols.begin());
            term += (q2Value == 1) ? "Q2" : "!Q2";
            term += separator;
        }
        if (q3Constant) {
            int q3Value = getQ3FromRow(*rows.begin());
            term += (q3Value == 1) ? "Q3" : "!Q3";
            term += separator;
        }
        if (xConstant) {
            int xValue = getXFromCol(*cols.begin());
            term += (xValue == 1) ? "X" : "!X";
            term += separator;
        }
    } else { // НКФ
        if (q1Constant) {
            int q1Value = getQ1FromRow(*rows.begin());
            term += (q1Value == 1) ? "!Q1" : "Q1";
            term += separator;
        }
        if (q2Constant) {
            int q2Value = getQ2FromCol(*cols.begin());
            term += (q2Value == 1) ? "!Q2" : "Q2";
            term += separator;
        }
        if (q3Constant) {
            int q3Value = getQ3FromRow(*rows.begin());
            term += (q3Value == 1) ? "!Q3" : "Q3";
            term += separator;
        }
        if (xConstant) {
            int xValue = getXFromCol(*cols.begin());
            term += (xValue == 1) ? "!X" : "X";
            term += separator;
        }
    }

    // Убираем последний разделитель
    if (term.endsWith(separator)) {
        term.chop(1);
    }

    // Если ни одна переменная не постоянна, это ошибка
    if (term.isEmpty()) {
        qDebug() << "No constant variables in cover - invalid selection";
        return "";
    }

    qDebug() << "Generated correct term:" << term;
    return term;
}

QString QLabCarnoCardWgt::convertToNiceTerm(const QString& term, int form)
{
    QString niceTerm = term;

    // Форматируем для красивого отображения
    niceTerm.replace("!Q1", "<span style=\"text-decoration: overline;\">Q</span><span style=\" vertical-align:sub;\">1</span>");
    niceTerm.replace("!Q2", "<span style=\"text-decoration: overline;\">Q</span><span style=\" vertical-align:sub;\">2</span>");
    niceTerm.replace("!Q3", "<span style=\"text-decoration: overline;\">Q</span><span style=\" vertical-align:sub;\">3</span>");
    niceTerm.replace("!X", "<span style=\"text-decoration: overline;\">X</span>");

    niceTerm.replace("Q1", "Q<span style=\" vertical-align:sub;\">1</span>");
    niceTerm.replace("Q2", "Q<span style=\" vertical-align:sub;\">2</span>");
    niceTerm.replace("Q3", "Q<span style=\" vertical-align:sub;\">3</span>");
    niceTerm.replace("X", "X");

    if (form == -1) {
        niceTerm.replace("*", "&#183;");
    } else {
        niceTerm.replace("+", "+");
    }

    return niceTerm;
}

bool QLabCarnoCardWgt::allSameQ1(const QSet<int>& rows)
{
    if (rows.isEmpty()) return false;

    // Получаем значение Q1 из первой строки
    int firstQ1 = getQ1FromRow(*rows.begin());

    // Проверяем, что во всех строках Q1 одинаково
    for (int row : rows) {
        if (getQ1FromRow(row) != firstQ1) {
            return false;
        }
    }
    return true;
}

bool QLabCarnoCardWgt::allSameQ2(const QSet<int>& cols)
{
    if (cols.isEmpty()) return false;

    // Получаем значение Q2 из первого столбца
    int firstQ2 = getQ2FromCol(*cols.begin());

    // Проверяем, что во всех столбцах Q2 одинаково
    for (int col : cols) {
        if (getQ2FromCol(col) != firstQ2) {
            return false;
        }
    }
    return true;
}

bool QLabCarnoCardWgt::allSameQ3(const QSet<int>& rows)
{
    if (rows.isEmpty()) return false;

    // Получаем значение Q3 из первой строки
    int firstQ3 = getQ3FromRow(*rows.begin());

    // Проверяем, что во всех строках Q3 одинаково
    for (int row : rows) {
        if (getQ3FromRow(row) != firstQ3) {
            return false;
        }
    }
    return true;
}

bool QLabCarnoCardWgt::allSameX(const QSet<int>& cols)
{
    if (cols.isEmpty()) return false;

    // Получаем значение X из первого столбца
    int firstX = getXFromCol(*cols.begin());

    // Проверяем, что во всех столбцах X одинаково
    for (int col : cols) {
        if (getXFromCol(col) != firstX) {
            return false;
        }
    }
    return true;
}

int QLabCarnoCardWgt::getQ1FromRow(int row)
{
    // Строки в карте Карно:
    // row=0 (строка 1 в таблице): Q1=1, Q3=0
    // row=1 (строка 2 в таблице): Q1=1, Q3=1
    // row=2 (строка 3 в таблице): Q1=0, Q3=1
    // row=3 (строка 4 в таблице): Q1=0, Q3=0

    return (row == 0 || row == 1) ? 1 : 0;
}

int QLabCarnoCardWgt::getQ3FromRow(int row)
{
    // Строки в карте Карно:
    // row=0 (строка 1 в таблице): Q1=1, Q3=0
    // row=1 (строка 2 в таблице): Q1=1, Q3=1
    // row=2 (строка 3 в таблице): Q1=0, Q3=1
    // row=3 (строка 4 в таблице): Q1=0, Q3=0

    return (row == 1 || row == 2) ? 1 : 0;
}

int QLabCarnoCardWgt::getQ2FromCol(int col)
{
    // Столбцы в карте Карно:
    // col=0 (столбец 1 в таблице): Q2=1, X=0
    // col=1 (столбец 2 в таблице): Q2=1, X=1
    // col=2 (столбец 3 в таблице): Q2=0, X=1
    // col=3 (столбец 4 в таблице): Q2=0, X=0

    return (col == 0 || col == 1) ? 1 : 0;
}

int QLabCarnoCardWgt::getXFromCol(int col)
{
    // Столбцы в карте Карно:
    // col=0 (столбец 1 в таблице): Q2=1, X=0
    // col=1 (столбец 2 в таблице): Q2=1, X=1
    // col=2 (столбец 3 в таблице): Q2=0, X=1
    // col=3 (столбец 4 в таблице): Q2=0, X=0

    return (col == 1 || col == 2) ? 1 : 0;
}

// Функции для формирования термов
QString QLabCarnoCardWgt::getQ1Term(const QSet<int>& rows, bool forNKF)
{
    int q1Value = getQ1FromRow(*rows.begin());
    if (forNKF) {
        return (q1Value == 1) ? "!Q1" : "Q1";
    } else {
        return (q1Value == 1) ? "Q1" : "!Q1";
    }
}

QString QLabCarnoCardWgt::getQ2Term(const QSet<int>& cols, bool forNKF)
{
    int q2Value = getQ2FromCol(*cols.begin());
    if (forNKF) {
        return (q2Value == 1) ? "!Q2" : "Q2";
    } else {
        return (q2Value == 1) ? "Q2" : "!Q2";
    }
}

QString QLabCarnoCardWgt::getQ3Term(const QSet<int>& rows, bool forNKF)
{
    int q3Value = getQ3FromRow(*rows.begin());
    if (forNKF) {
        return (q3Value == 1) ? "!Q3" : "Q3";
    } else {
        return (q3Value == 1) ? "Q3" : "!Q3";
    }
}

QString QLabCarnoCardWgt::getXTerm(const QSet<int>& cols, bool forNKF)
{
    int xValue = getXFromCol(*cols.begin());
    if (forNKF) {
        return (xValue == 1) ? "!X" : "X";
    } else {
        return (xValue == 1) ? "X" : "!X";
    }
}

void QLabCarnoCardWgt::on_pushButtonAddTerm_clicked()
{
    QString cover = ui->tableWidgetCardCarno->getCover();
    QString sTerm = ui->widgetTermEdit->getSTerm();
    QString nTerm = ui->widgetTermEdit->getNTerm();
    int form = ui->widgetTermEdit->getTermForm();

    qDebug() << "=== Adding Term ===";
    qDebug() << "Cover:" << cover;
    qDebug() << "STerm from widget:" << sTerm;
    qDebug() << "NTerm from widget:" << nTerm;
    qDebug() << "Form:" << form;
    qDebug() << "Current form:" << currentForm;

    // Проверяем, что форма терма выбрана
    if (form == 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите форму терма (НДФ или НКФ)!");
        return;
    }

    // Если уже есть термы, проверяем совпадение формы
    if (!userSTerms.isEmpty() && form != currentForm) {
        QMessageBox::warning(this, "Ошибка",
                             QString("Все термы должны быть в одной форме!\n"
                                     "Текущая форма: %1\n"
                                     "Удалите существующие термы чтобы сменить форму.")
                                 .arg(currentForm == -1 ? "НДФ" : "НКФ"));
        return;
    }

    // Определяем источник терма
    bool fromCover = !cover.isEmpty();
    bool fromWidget = !sTerm.isEmpty();

    if (!fromCover && !fromWidget) {
        QMessageBox::warning(this, "Ошибка",
                             "Не выбран терм!\n"
                             "Либо выделите область на карте Карно, "
                             "либо введите терм через кнопки переменных.");
        return;
    }

    if (fromCover) {
        // Проверяем, что выделенная область корректна для карты Карно
        if (!isValidCarnoCover(cover)) {
            QMessageBox::warning(this, "Ошибка",
                                 "Некорректная область выделения!\n"
                                 "Выделите прямоугольную область размером 1, 2, 4 или 8 ячеек.");
            return;
        }

        // Генерируем терм из выделения на карте
        QString generatedTerm = generateCorrectTermFromCover(cover, form);
        if (!generatedTerm.isEmpty()) {
            sTerm = generatedTerm;
            nTerm = convertToNiceTerm(sTerm, form);
            qDebug() << "Generated from cover - STerm:" << sTerm << "NTerm:" << nTerm;
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сгенерировать терм из выделенной области.");
            return;
        }
    }

    // Проверяем уникальность
    if (!isUserTermUnique(sTerm)) {
        QMessageBox::warning(this, "Ошибка", "Такой терм уже добавлен!");
        return;
    }

    // Если это первый терм, устанавливаем текущую форму и блокируем выбор формы
    if (userSTerms.isEmpty()) {
        currentForm = form;
        qDebug() << "Setting current form to:" << currentForm;
        // Блокируем виджет выбора формы
        ui->widgetTermEdit->block(currentForm);
    }

    // Добавляем терм
    userSTerms.append(sTerm);
    userNTerms.append(nTerm);
    userCovers.append(cover);

    // Обновляем интерфейс
    ui->tableWidgetTermsLst->addTerm(userNTerms.back());

    // Выбираем и показываем добавленный терм
    int newRow = ui->tableWidgetTermsLst->rowCount() - 1;
    ui->tableWidgetTermsLst->selectTerm(newRow);
    showCover(newRow);

    // Очищаем ТОЛЬКО выбор переменных, НЕ форму
    clearVariableSelectionOnly();

    updateResult();
    dataEdited();

    qDebug() << "Term added successfully. Total terms:" << userSTerms.count();
}

void QLabCarnoCardWgt::clearVariableSelectionOnly()
{
    // Временно сохраняем текущую форму
    int savedForm = currentForm;

    // Очищаем все выборы (включая форму)
    ui->widgetTermEdit->clear();

    // Восстанавливаем форму
    if (savedForm != 0) {
        ui->widgetTermEdit->block(savedForm);
    }
}

void QLabCarnoCardWgt::on_pushButtonDelTerm_clicked()
{
    if (ui->tableWidgetTermsLst->currentRow() >= 0) {
        userSTerms.remove(currentTerm);
        userNTerms.remove(currentTerm);
        userCovers.remove(currentTerm);
        ui->tableWidgetTermsLst->delSelectedTerm();

        // Если термов не осталось, разблокируем выбор формы
        if (userSTerms.isEmpty()) {
            currentForm = 0;
            ui->widgetTermEdit->unblock();
            // Очищаем все выборы, включая форму
            ui->widgetTermEdit->clear();
            qDebug() << "All terms deleted, unlocking form selection";
        } else {
            // Если термы остались, очищаем только переменные
            clearVariableSelectionOnly();
        }

        updateResult();
        dataEdited();
    }
}

void QLabCarnoCardWgt::on_pushButtonCardCheck_clicked()
{
    if (checkCarnoMap()) {
        showErrMsg(1);
    } else {
        showErrMsg(2);
    }
}

QString QLabCarnoCardWgt::normalizeTerm(const QString& term) {
    if (term.isEmpty()) return term;

    qDebug() << "Normalizing term:" << term;

    // Разбиваем терм на множители
    QStringList factors = term.split('*', Qt::SkipEmptyParts);

    // Удаляем пустые строки и пробелы
    for (int i = 0; i < factors.size(); i++) {
        factors[i] = factors[i].trimmed();
        if (factors[i].isEmpty()) {
            factors.removeAt(i);
            i--;
        }
    }

    // Сортируем множители в алфавитном порядке
    std::sort(factors.begin(), factors.end());

    // Собираем обратно в строку
    QString result = factors.join('*');
    qDebug() << "Normalized result:" << result;

    return result;
}

void QLabCarnoCardWgt::on_pushButtonCheckResult_clicked()
{
    minimizeFunc();
    qDebug() << "=== BASIC CHECK INFO ===";
    qDebug() << "Current form:" << currentForm << (currentForm == -1 ? "(НДФ)" : "(НКФ)");
    qDebug() << "User terms count:" << userSTerms.count();
    qDebug() << "User terms:" << userSTerms;
    qDebug() << "RRRRR Result expression:" << resultS;

    if (!isResultTested) {
        isResultTested = true;
        resultTestCode = 100;

        if (userSTerms.count() > 0) {
            int num, pow;

            if (resultExp == 0) {
                QString expressionForParser = resultS;
                expressionForParser.replace("Q1", "1");
                expressionForParser.replace("Q2", "2");
                expressionForParser.replace("Q3", "3");
                expressionForParser.replace("X", "4");
                qDebug() << "Original expression:" << resultS;
                qDebug() << "Expression for parser:" << expressionForParser;
                resultExp = genExpTree(expressionForParser);

                if (resultExp == 0) {
                    qDebug() << "ERROR: Failed to generate expression tree";
                    resultTestCode = 9;
                    showErrMsg(9);
                    return;
                }
            }

            qDebug() << "=== CHECKING FUNCTION VALUES ===";

            bool allMatch = true;
            for(int cnt = power(2, 4) - 1; cnt >= 0; cnt--) {
                num = cnt;
                int arg[4];
                for (int i = 3; i >= 0; i--) {
                    pow = power(2, i);
                    if (num >= pow) {
                        arg[i] = 1;
                        num -= pow;
                    } else
                        arg[i] = 0;
                }

                // Получаем значение из currentFunc
                int index = arg[0] * 8 + arg[3] * 4 + arg[2] * 2 + arg[1] * 1;

                if (index >= 0 && index < currentFunc.length()) {
                    QChar expectedChar = currentFunc[index];

                    // Пропускаем don't-care состояния
                    if (expectedChar == '*') {
                        qDebug() << "Skipping combination" << cnt << "(don't care)";
                        continue;
                    }

                    int expected = expectedChar.digitValue();

                    qDebug() << "Testing combination" << cnt << ":"
                             << "Q3=" << arg[3] << "Q2=" << arg[2] << "Q1=" << arg[1] << "X=" << arg[0]
                             << "-> index" << index << "Expected:" << expected;

                    int actual = recvCaclExp(resultExp, arg[3], arg[2], arg[1], arg[0]);

                    if (expected != actual) {
                        resultTestCode = 9;
                        allMatch = false;
                        qDebug() << "ERROR: Function value mismatch at combination" << cnt;
                        qDebug() << "  Arguments: Q3=" << arg[3] << "Q2=" << arg[2] << "Q1=" << arg[1] << "X=" << arg[0];
                        qDebug() << "  Expected:" << expected << "Got:" << actual;

                        showErrMsg(9);
                        break;
                    } else {
                        qDebug() << "  ✓ Match: expected" << expected << "got" << actual;
                    }
                } else {
                    qDebug() << "Invalid index" << index << "for combination" << cnt;
                }
            }

            if (allMatch) {
                qDebug() << "✓ Function values check PASSED - all combinations match";

                // Проверка минимальности с нормализацией термов
                bool isOK;
                if (currentForm == -1) {
                    qDebug() << "=== CHECKING MINIMAL NDF TERMS ===";
                    qDebug() << "Algorithm NDF terms count:" << algmTermsD.size();

                    // ДОБАВЛЕНО: Логирование нормализованных термов
                    qDebug() << "User NDF terms (normalized):";
                    QVector<QString> normalizedUserTerms;
                    for (int k = 0; k < userSTerms.count(); k++) {
                        QString normalized = normalizeTerm(userSTerms[k]);
                        normalizedUserTerms.append(normalized);
                        qDebug() << "  " << normalized;
                    }

                    for (int i = 0; i < int(algmTermsD.size()); i++) {
                        qDebug() << "  Checking algorithm set" << i << "with" << algmTermsD[i].size() << "terms:";

                        // ДОБАВЛЕНО: Логирование алгоритмических термов
                        qDebug() << "  Algorithm terms (normalized):";
                        QVector<QString> normalizedAlgTerms;
                        for (int j = 0; j < int(algmTermsD[i].size()); j++) {
                            QString algTerm = QString::fromStdString(algmTermsD[i][j]);
                            QString normalized = normalizeTerm(algTerm);
                            normalizedAlgTerms.append(normalized);
                            qDebug() << "    " << normalized;
                        }

                        if (int(algmTermsD[i].size()) == int(userSTerms.size())) {
                            qDebug() << "  ✓ Size matches user terms, checking content...";
                            isOK = true;

                            // Проверяем каждый алгоритмический терм
                            for (int j = 0; j < int(algmTermsD[i].size()); j++) {
                                QString algTerm = QString::fromStdString(algmTermsD[i][j]);
                                QString normalizedAlgTerm = normalizeTerm(algTerm);
                                bool found = false;

                                for (int k = 0; k < userSTerms.count(); k++) {
                                    QString normalizedUserTerm = normalizeTerm(userSTerms[k]);
                                    if (normalizedAlgTerm == normalizedUserTerm) {
                                        found = true;
                                        qDebug() << "    ✓ Found matching term:" << normalizedAlgTerm;
                                        break;
                                    }
                                }

                                if (!found) {
                                    isOK = false;
                                    qDebug() << "    ✗ Missing term:" << normalizedAlgTerm;
                                    break;
                                }
                            }

                            if (isOK) {
                                resultTestCode = 10;
                                qDebug() << "✓ MINIMAL NDF SOLUTION FOUND!";
                                showErrMsg(10);
                                ui->widgetBasisEdit->setExp(resultS);
                                return;
                            }
                        }
                    }

                    resultTestCode = 11;
                    qDebug() << "✗ NDF solution is NOT minimal";
                    showErrMsg(11);

                } else if (currentForm == 1) {
                    qDebug() << "=== CHECKING MINIMAL NKF TERMS ===";
                    qDebug() << "Algorithm NKF terms count:" << algmTermsK.size();
                    qDebug() << "User NKF terms:" << userSTerms;

                    for (int i = 0; i < int(algmTermsK.size()); i++) {
                        qDebug() << "  Checking algorithm set" << i << "with" << algmTermsK[i].size() << "terms:";

                        if (int(algmTermsK[i].size()) == int(userSTerms.size())) {
                            qDebug() << "  ✓ Size matches user terms, checking content...";
                            isOK = true;

                            // Проверяем каждый алгоритмический терм с нормализацией
                            for (int j = 0; j < int(algmTermsK[i].size()); j++) {
                                QString algTerm = QString::fromStdString(algmTermsK[i][j]);
                                QString normalizedAlgTerm = normalizeTerm(algTerm);
                                bool found = false;

                                for (int k = 0; k < userSTerms.count(); k++) {
                                    QString normalizedUserTerm = normalizeTerm(userSTerms[k]);
                                    if (normalizedAlgTerm == normalizedUserTerm) {
                                        found = true;
                                        qDebug() << "    ✓ Found matching term:" << normalizedAlgTerm;
                                        break;
                                    }
                                }

                                if (!found) {
                                    isOK = false;
                                    qDebug() << "    ✗ Missing term:" << normalizedAlgTerm;
                                    break;
                                }
                            }

                            if (isOK) {
                                resultTestCode = 10;
                                qDebug() << "✓ MINIMAL NKF SOLUTION FOUND!";
                                showErrMsg(10);
                                ui->widgetBasisEdit->setExp(resultS);
                                return;
                            }
                        }
                    }

                    resultTestCode = 11;
                    qDebug() << "✗ NKF solution is NOT minimal";
                    showErrMsg(11);
                }
            }

        } else {
            resultTestCode = 8;
            qDebug() << "✗ No terms to check";
            showErrMsg(8);
        }
    } else {
        qDebug() << "Using cached result:" << resultTestCode;
        showErrMsg(resultTestCode);
    }
}


void QLabCarnoCardWgt::on_pushButtonCheckBasis_clicked()
{
    qDebug() << "\n=== BASIS CHECK STARTED ===";
    qDebug() << "Result test code:" << resultTestCode;
    qDebug() << "Initial expression:" << ui->widgetBasisEdit->getInitExp();
    qDebug() << "Result expression:" << resultS;

    if (!isBasisTested) {
        isBasisTested = true;

        if (resultTestCode == 10) {
            qDebug() << "✓ Result test passed (code 10)";

            QString initExp = ui->widgetBasisEdit->getInitExp();

            if (initExp == resultS) {
                qDebug() << "✓ Expressions match";

                int checkResult = ui->widgetBasisEdit->checkExp();
                qDebug() << "Expression check result:" << checkResult;

                if (checkResult == 0) {
                    qDebug() << "✓ Expression syntax is valid";

                    QString basis = ui->widgetBasisEdit->getBasis();
                    qDebug() << "Detected basis:" << basis;

                    bool allMatch = true;
                    int failedCombination = -1;

                    // Детальное тестирование всех комбинаций
                    for (int cnt = 0; cnt < 16; cnt++) {
                        int Q3 = (cnt & 0x08) ? 1 : 0;
                        int Q2 = (cnt & 0x04) ? 1 : 0;
                        int Q1 = (cnt & 0x02) ? 1 : 0;
                        int X  = (cnt & 0x01) ? 1 : 0;

                        QString tableValue = ui->tableWidgetFuncPreview->item(cnt + 2, 4)->text();

                        if (tableValue != "*") {
                            int expected = tableValue.toInt();
                            int actual = ui->widgetBasisEdit->calcExp(Q3, Q2, Q1, X);

                            qDebug() << QString("Test %1: Q3=%2 Q2=%3 Q1=%4 X=%5 -> Expected: %6 Got: %7")
                                            .arg(cnt).arg(Q3).arg(Q2).arg(Q1).arg(X).arg(expected).arg(actual);

                            if (expected != actual) {
                                qDebug() << "✗ MISMATCH!";
                                allMatch = false;
                                failedCombination = cnt;
                                break;
                            }
                        }
                    }

                    if (allMatch) {
                        qDebug() << "✓ All combinations match!";

                        if (basis == "Шеффера") {
                            basisTestCode = 14;
                            showErrMsg(14);
                        } else if (basis == "Пирса") {
                            basisTestCode = 15;
                            showErrMsg(15);
                        } else {
                            basisTestCode = 13;
                            showErrMsg(13);
                        }
                    } else {
                        qDebug() << "✗ Function values don't match at combination" << failedCombination;

                        if (basis == "Шеффера") {
                            basisTestCode = 16;
                            showErrMsg(16);
                        } else {
                            basisTestCode = 17;
                            showErrMsg(17);
                        }
                    }
                } else {
                    qDebug() << "✗ Expression syntax error";
                    basisTestCode = 13;
                    showErrMsg(13);
                }
            } else {
                qDebug() << "✗ Expressions don't match!";
                basisTestCode = 12;
                showErrMsg(12);
            }
        } else {
            qDebug() << "✗ Result test not passed, code:" << resultTestCode;
            basisTestCode = 12;
            showErrMsg(12);
        }
    } else {
        qDebug() << "Using cached basis test result:" << basisTestCode;
        showErrMsg(basisTestCode);
    }
}

// void QLabCarnoCardWgt::on_pushButtonCheckBasis_clicked()
// {
//     qDebug() << "\n=== BASIS CHECK STARTED ===";
//     qDebug() << "Result test code:" << resultTestCode;
//     qDebug() << "Initial expression:" << ui->widgetBasisEdit->getInitExp();
//     qDebug() << "Result expression:" << resultS;

//     if (!isBasisTested) {
//         isBasisTested = true;

//         if (resultTestCode == 10) {
//             qDebug() << "✓ Result test passed (code 10)";

//             QString initExp = ui->widgetBasisEdit->getInitExp();

//             if (initExp == resultS) {
//                 qDebug() << "✓ Expressions match";

//                 int checkResult = ui->widgetBasisEdit->checkExp();
//                 qDebug() << "Expression check result:" << checkResult;

//                 if (checkResult == 0) {
//                     qDebug() << "✓ Expression syntax is valid";

//                     QString basis = ui->widgetBasisEdit->getBasis();
//                     qDebug() << "Detected basis:" << basis;

//                     bool allMatch = true;
//                     int failedCombination = -1;

//                     for (int cnt = 0; cnt < 16; cnt++) {
//                         int Q3 = (cnt & 0x08) ? 1 : 0;
//                         int Q2 = (cnt & 0x04) ? 1 : 0;
//                         int Q1 = (cnt & 0x02) ? 1 : 0;
//                         int X  = (cnt & 0x01) ? 1 : 0;

//                         QString tableValue = ui->tableWidgetFuncPreview->item(cnt + 2, 4)->text();

//                         if (tableValue != "*") {
//                             int expected = tableValue.toInt();
//                             int actual = ui->widgetBasisEdit->calcExp(Q3, Q2, Q1, X);

//                             if (expected != actual) {
//                                 qDebug() << "✗ MISMATCH at combination" << cnt;
//                                 qDebug() << "  Q3=" << Q3 << "Q2=" << Q2 << "Q1=" << Q1 << "X=" << X;
//                                 qDebug() << "  Expected:" << expected << "Got:" << actual;
//                                 qDebug() << "  Current basis:" << basis;
//                                 qDebug() << "  Current expression:" << ui->widgetBasisEdit->getInitExp();
//                                 allMatch = false;
//                                 failedCombination = cnt;
//                                 break;
//                             }
//                         }
//                     }

//                     if (allMatch) {
//                         qDebug() << "✓ All combinations match!";

//                         if (basis == "Шеффера") {
//                             basisTestCode = 14;
//                             showErrMsg(14);
//                         } else if (basis == "Пирса") {
//                             basisTestCode = 15;
//                             showErrMsg(15);
//                         } else {
//                             basisTestCode = 13;
//                             showErrMsg(13);
//                         }
//                     } else {
//                         qDebug() << "✗ Function values don't match at combination" << failedCombination;

//                         if (basis == "Шеффера") {
//                             basisTestCode = 16;
//                             showErrMsg(16);
//                         } else {
//                             basisTestCode = 17;
//                             showErrMsg(17);
//                         }
//                     }
//                 } else {
//                     qDebug() << "✗ Expression syntax error";
//                     basisTestCode = 13;
//                     showErrMsg(13);
//                 }
//             } else {
//                 qDebug() << "✗ Expressions don't match!";
//                 basisTestCode = 12;
//                 showErrMsg(12);
//             }
//         } else {
//             qDebug() << "✗ Result test not passed, code:" << resultTestCode;
//             basisTestCode = 12;
//             showErrMsg(12);
//         }
//     } else {
//         qDebug() << "Using cached basis test result:" << basisTestCode;
//         showErrMsg(basisTestCode);
//     }
// }

void QLabCarnoCardWgt::showCarnoHint()
{
    qDebug() << "=== Showing Carno hint ===";

    for (int tableRow = 2; tableRow < ui->tableWidgetFuncPreview->rowCount(); tableRow++) {
        QTableWidgetItem* itemQ3 = ui->tableWidgetFuncPreview->item(tableRow, 0);
        QTableWidgetItem* itemQ2 = ui->tableWidgetFuncPreview->item(tableRow, 1);
        QTableWidgetItem* itemQ1 = ui->tableWidgetFuncPreview->item(tableRow, 2);
        QTableWidgetItem* itemX = ui->tableWidgetFuncPreview->item(tableRow, 3);
        QTableWidgetItem* itemTrigger = ui->tableWidgetFuncPreview->item(tableRow, 4);

        if (itemQ3 && itemQ2 && itemQ1 && itemX && itemTrigger) {
            bool okQ3, okQ2, okQ1, okX;
            int Q3 = itemQ3->text().toInt(&okQ3);
            int Q2 = itemQ2->text().toInt(&okQ2);
            int Q1 = itemQ1->text().toInt(&okQ1);
            int X = itemX->text().toInt(&okX);
            QString expectedValue = itemTrigger->text();

            if (okQ3 && okQ2 && okQ1 && okX) {
                QPoint coords = getCarnoCoordinates(Q3, Q2, Q1, X);

                if (coords.x() != -1 && coords.y() != -1) {
                    QTableWidgetItem* carnoItem = ui->tableWidgetCardCarno->item(coords.y(), coords.x());
                    if (carnoItem) {
                        QString userValue = carnoItem->text();

                        carnoItem->setData(Qt::UserRole, userValue);
                        carnoItem->setText(expectedValue);
                        carnoItem->setForeground(Qt::blue);

                        qDebug() << "Hint: [" << coords.y() << "," << coords.x()
                                 << "] set to:" << expectedValue << "(was:" << userValue << ")";
                    }
                }
            }
        }
    }

    QMessageBox::information(this, "Подсказка",
                             "Правильные значения показаны синим цветом на 3 секунды.\n"
                             "Сравните с вашими значениями и исправьте расхождения.");
}

// Вспомогательные функции QLabCarnoCardWgt
bool QLabCarnoCardWgt::isCoverAndTermOK(QString cover, QString term, int form)
{
    QString genTerm = "";

    if (form == 0)
        return false;

    bool isAdd;
    bool isIn;

    for (int k = 0; k < signsTemplate.size(); k++) {
        isAdd = true;
        for (int n = 0; n < cover.size() - 1; n += 2) {
            isIn = false;
            for (int m = 0; m < signsTemplate[k].size() - 1; m += 2)
                if (cover[n] == signsTemplate[k][m] &&
                    cover[n + 1] == signsTemplate[k][m + 1]) {
                    isIn = true;
                    break;
                }
            if (!isIn) {
                isAdd = false;
                break;
            }
        }
        if (isAdd) {
            if (form == -1) {
                genTerm.append(signsNDF[k] + "*");
            } else if (form == +1) {
                genTerm.append(signsNKF[k] + "+");
            }
        }
    }
    genTerm.remove(genTerm.size() - 1, 1);

    if (genTerm == term)
        return true;
    else
        return false;
}

QString QCarnoCardWgt::getCover()
{
    cover = "";
    QList<QTableWidgetItem*> items = selectedItems();

    qDebug() << "Selected items count:" << items.size();

    for (int i = 0; i < items.size(); i++) {
        if (items[i]->row() > 0 && items[i]->row() < 5 &&
            items[i]->column() > 0 && items[i]->column() < 5) {
            cover += QString::number(items[i]->row() - 1) + QString::number(items[i]->column() - 1);
            qDebug() << "Added to cover - row:" << items[i]->row() - 1 << "col:" << items[i]->column() - 1;
        }
    }

    // Сортируем cover для consistent представления
    QString sortedCover = "";
    for (int i = 0; i < cover.size() - 1; i += 2) {
        sortedCover += cover.mid(i, 2);
    }

    qDebug() << "Final cover:" << sortedCover;
    return sortedCover;
}

bool QLabCarnoCardWgt::isUserTermUnique(const QString term)
{
    if (term.isEmpty()) return true;

    // Нормализуем терм для сравнения (убираем лишние пробелы, приводим к одному формату)
    QString normalizedTerm = term;
    normalizedTerm = normalizedTerm.simplified();
    normalizedTerm.replace(" ", "");

    for (int i = 0; i < userSTerms.count(); i++) {
        QString existingTerm = userSTerms[i];
        existingTerm = existingTerm.simplified();
        existingTerm.replace(" ", "");

        if (existingTerm == normalizedTerm) {
            return false;
        }
    }
    return true;
}

void QLabCarnoCardWgt::highlightTermOnCarnoMap(const QString& cover)
{
    if (cover.isEmpty()) {
        qDebug() << "Empty cover, nothing to highlight";
        return;
    }

    qDebug() << "Highlighting cover on carno map:" << cover;

    // Сначала сбрасываем все выделения
    clearCarnoHighlights();

    // Выделяем ячейки согласно cover
    for (int i = 0; i < cover.size(); i += 2) {
        if (i + 1 < cover.size()) {
            int row = QString(cover[i]).toInt() + 1; // +1 потому что в карте строки 1-4
            int col = QString(cover[i + 1]).toInt() + 1; // +1 потому что в карте столбцы 1-4

            //qDebug() << "Highlighting cell - row:" << row << "col:" << col;

            QTableWidgetItem* item = ui->tableWidgetCardCarno->item(row, col);
            if (item) {
                // Устанавливаем выделение и цвет фона
                item->setSelected(true);
                item->setBackground(QColor(173, 216, 230)); // Light blue

                // Принудительно обновляем ячейку
                ui->tableWidgetCardCarno->update(ui->tableWidgetCardCarno->visualItemRect(item));
            } else {
                //qDebug() << "Item not found at row:" << row << "col:" << col;
            }
        }
    }

    // Принудительно обновляем всю таблицу
    ui->tableWidgetCardCarno->viewport()->update();
    qDebug() << "Carno map highlighting completed";
}

void QLabCarnoCardWgt::clearCarnoHighlights()
{
    qDebug() << "Clearing carno highlights";

    // Сбрасываем все выделения
    ui->tableWidgetCardCarno->clearSelection();

    // Сбрасываем цвета всех ячеек
    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= 4; col++) {
            QTableWidgetItem* item = ui->tableWidgetCardCarno->item(row, col);
            if (item) {
                item->setBackground(Qt::white);
            }
        }
    }

    // Принудительно обновляем таблицу
    ui->tableWidgetCardCarno->viewport()->update();
    qDebug() << "Carno highlights cleared";
}

void QLabCarnoCardWgt::showCover(int row)
{
    // Временно отключаем сигнал чтобы избежать рекурсии
    disconnect(ui->tableWidgetCardCarno, SIGNAL(itemSelectionChanged()),
               ui->tableWidgetTermsLst, SLOT(clearSelection()));

    // Сбрасываем предыдущие выделения
    clearCarnoHighlights();

    if (row >= 0 && row < userCovers.size()) {
        // Выделяем покрытие текущего терма
        QString cover = userCovers[row];
        qDebug() << "Showing cover for term" << row << ":" << cover;
        highlightTermOnCarnoMap(cover);
        currentTerm = row;
    } else {
        currentTerm = -1;
        qDebug() << "No cover to show for row:" << row;
    }

    // Восстанавливаем соединение
    connect(ui->tableWidgetCardCarno, SIGNAL(itemSelectionChanged()),
            ui->tableWidgetTermsLst, SLOT(clearSelection()));
}

void QLabCarnoCardWgt::setFunc(int num, QString func)
{
    qDebug() << "=== SETFUNC CALLED ===";
    qDebug() << "num:" << num << "currentFuncNum:" << currentFuncNum;
    qDebug() << "func:" << func;
    qDebug() << "func length:" << func.length();

    if (num == currentFuncNum) {
        currentFunc = func;
        ui->tableWidgetCardCarno->setFunc(func);

        // Детальное логирование
        QString debugStr;
        for (int i = 0; i < func.length(); i++) {
            debugStr += QString("%1").arg(func[i]);
        }
        qDebug() << "func content:" << debugStr;

        for (int i = 0; i < func.size(); i++) {
            ui->tableWidgetFuncPreview->item(i + 1, 1)->setText(QString(func[i]));
            ui->tableWidgetFuncPreview->item(i + 1, 1)->setTextAlignment(Qt::AlignCenter);
        }
    } else {
        qDebug() << "num != currentFuncNum, skipping...";
    }
}

void QLabCarnoCardWgt::showErrMsg(int errCode)
{
    QString title;
    if (errCode == 1)
        title = "Карта соответствует варианту!";
    else if (errCode == 2)
        title = "Карта не соответствует варианту!";
    else if (errCode == 3)
        title = "Такой терм уже введен!";
    else if (errCode == 4)
        title = "Область склеивания не соответствует терму!";
    else if (errCode == 5)
        title = "Ошибка в области склеивания!";
    else if (errCode == 6)
        title = "Выберите терм и форму (НДФ или НКФ)!";
    else if (errCode == 7)
        title = "Введите карту в соответствии с вариантом!";
    else if (errCode == 8)
        title = "Введите термы!";
    else if (errCode == 9)
        title = "Результат вычисления не соответствует значениям функции!";
    else if (errCode == 10)
        title = "Результат вычисления соответствует значениям функции!\nРешение минимально!";
    else if (errCode == 11)
        title = "Результат вычисления соответствует значениям функции, но решение не минимально!";
    else if (errCode == 12)
        title = "Проверьте результат в базисе \"Буля\"!";
    else if (errCode == 13)
        title = "Определите базис!";
    else if (errCode == 14)
        title = "Базис: Шеффера!\nРезультат вычисления соответствует значениям функции!";
    else if (errCode == 15)
        title = "Базис: Пирса!\nРезультат вычисления соответствует значениям функции!";
    else if (errCode == 16)
        title = "Базис: Шеффера!\nРезультат вычисления не соответствует значениям функции!";
    else if (errCode == 17)
        title = "Базис: Пирса!\nРезультат вычисления не соответствует значениям функции!";
    else if (errCode == 18)
        title = "Ошибка применения операции \"отрицание\" над некоторыми ячейками!";
    else if (errCode == 19)
        title = "Ошибка применения операции \"конъюнкция\" над некоторыми ячейками!";
    else if (errCode == 20)
        title = "Ошибка применения операции \"дизъюнкция\" над некоторыми ячейками!";

    QMessageBox msg(errCode == 1 || errCode == 10 || errCode == 14 || errCode == 15 ? QMessageBox::Information :
                        QMessageBox::Warning,
                    "Внимание!",
                    title,
                    QMessageBox::Cancel);
    msg.setButtonText(QMessageBox::Cancel, "&Закрыть");
    msg.exec();
}

void QLabCarnoCardWgt::destroyExpTree(expTree* ptr)
{
    if (ptr != 0) {
        destroyExpTree(ptr->lf);
        destroyExpTree(ptr->rt);
        delete ptr;
    }
}

expTree* QLabCarnoCardWgt::genExpTree(QString func)
{
    //qDebug() << "    genExpTree parsing:" << func;

    if (func.isEmpty()) {
        qDebug() << "    genExpTree: empty function";
        return nullptr;
    }

    expTree *treeItem = new expTree;
    QChar op;
    int index;

    getExpOp(func, op, index);

    if (index != -1) {
        treeItem->op = op;
        //qDebug() << "    genExpTree: found op '" << op << "' at index" << index;

        if (op == '!') {
            // Унарное отрицание - берем только следующий символ или выражение в скобках
            QString operand;
            if (func.length() > 1 && func[1] == '(') {
                // Ищем закрывающую скобку
                int bktBalance = 1;
                int endPos = 2;
                for (; endPos < func.length() && bktBalance > 0; endPos++) {
                    if (func[endPos] == '(') bktBalance++;
                    else if (func[endPos] == ')') bktBalance--;
                }
                if (bktBalance == 0) {
                    operand = func.mid(2, endPos - 3);
                } else {
                    operand = func.mid(1);
                }
            } else {
                // Берем только следующий символ
                operand = func.mid(1, 1);
            }
            //qDebug() << "    genExpTree: unary !, operand:" << operand;
            treeItem->lf = genExpTree(operand);
            treeItem->rt = nullptr;
        }
        else if (op == '*' || op == '+') {
            QString left = func.left(index).simplified();
            QString right = func.mid(index + 1).simplified();
            //qDebug() << "    genExpTree: binary" << op << ", left:" << left << "right:" << right;
            treeItem->lf = genExpTree(left);
            treeItem->rt = genExpTree(right);
        }
        else {
            treeItem->op = op;
            treeItem->lf = nullptr;
            treeItem->rt = nullptr;
            //qDebug() << "    genExpTree: variable node '" << op << "'";
        }
    } else {
        treeItem->op = func[0];
        treeItem->lf = nullptr;
        treeItem->rt = nullptr;
        //qDebug() << "    genExpTree: single character node '" << func[0] << "'";
    }

    return treeItem;
}

void QLabCarnoCardWgt::getExpOp(QString& func, QChar &op, int &index)
{
    index = -1;
    op = '\0';

    func = func.simplified();
    if (func.isEmpty()) {
        return;
    }

    // Сначала убираем внешние скобки
    while (func.startsWith('(') && func.endsWith(')')) {
        int balance = 1;
        bool isOuter = true;
        for (int i = 1; i < func.length() - 1; i++) {
            if (func[i] == '(') balance++;
            else if (func[i] == ')') balance--;
            if (balance == 0) {
                isOuter = false;
                break;
            }
        }
        if (isOuter) {
            func = func.mid(1, func.length() - 2).simplified();
        } else {
            break;
        }
    }

    // Ищем бинарные операторы с наименьшим приоритетом
    int balance = 0;
    int plusIndex = -1;
    int multIndex = -1;

    // Ищем справа налево
    for (int i = func.length() - 1; i >= 0; i--) {
        if (func[i] == ')') balance++;
        else if (func[i] == '(') balance--;
        else if (balance == 0) {
            if (func[i] == '+') {
                plusIndex = i;
                break; // Нашли самый правый + вне скобок
            } else if (func[i] == '*' && multIndex == -1) {
                multIndex = i; // Запомним самый правый *
            }
        }
    }

    if (plusIndex != -1) {
        op = '+';
        index = plusIndex;
    } else if (multIndex != -1) {
        op = '*';
        index = multIndex;
    } else if (func.startsWith('!')) {
        // Если операторов нет, но есть унарное отрицание
        op = '!';
        index = 0;
    } else {
        // Одиночная переменная
        op = func[0];
        index = 0;
    }
}

int QLabCarnoCardWgt::power(int num, unsigned int power)
{
    int result;
    result = power == 0 ? 1 : num;

    if (power > 1)
        for (; power > 1; power--)
            result *= num;

    return result;
}

void QLabCarnoCardWgt::resizeEvent(QResizeEvent* event)
{
    if (event->oldSize() != event->size()) {
        ui->pushButtonAddTerm->setMinimumWidth(ui->groupBoxTermsLst->width());
        ui->pushButtonDelTerm->setMinimumWidth(ui->groupBoxTermsLst->width());
    }
    QWidget::resizeEvent(event);
}

void QLabCarnoCardWgt::minimizeFunc()
{
    debugTableToFuncMapping();

    qDebug() << "=== STARTING FUNCTION MINIMIZATION ===";
    qDebug() << "Current function:" << currentFunc;
    qDebug() << "Function length:" << currentFunc.length();

    algmTermsD.clear();
    algmTermsK.clear();

    // Проверка корректности функции
    if (currentFunc.length() != 16) {
        qDebug() << "ERROR: Function length is not 16!";
        return;
    }

    // Проверяем, есть ли в функции хотя бы одна единица или ноль
    bool hasOnesOrZeros = currentFunc.contains('0') || currentFunc.contains('1');
    if (!hasOnesOrZeros) {
        qDebug() << "WARNING: Function contains only don't-cares, using test function";
        QString testFunc = "0001000100010001";
        currentFunc = testFunc;
    }

    qDebug() << "Using function for minimization:" << currentFunc;

    try {
        // Вычисляем минимальные покрытия для НДФ
        qDebug() << "Calculating NDF...";
        bool ndfResult = minimizer.calculate(1, currentFunc.toStdString());
        qDebug() << "NDF calculation result:" << ndfResult;

        if (ndfResult) {
            algmTermsD = minimizer.getCombExps();
            qDebug() << "Algorithm NDF solutions:" << algmTermsD.size();

            // Безопасное логирование алгоритмических решений
            for (size_t i = 0; i < algmTermsD.size(); i++) {
                qDebug() << "  Solution" << i << ":";
                for (size_t j = 0; j < algmTermsD[i].size(); j++) {
                    if (j < algmTermsD[i].size()) {
                        QString algTerm = QString::fromStdString(algmTermsD[i][j]);
                        QString normalized = normalizeTerm(algTerm);
                        qDebug() << "    Original:" << algTerm << "-> Normalized:" << normalized;
                    }
                }
            }
        } else {
            qDebug() << "NDF calculation failed!";
        }

        // Вычисляем минимальные покрытия для НКФ
        qDebug() << "Calculating NKF...";
        bool nkfResult = minimizer.calculate(0, currentFunc.toStdString());
        qDebug() << "NKF calculation result:" << nkfResult;

        if (nkfResult) {
            algmTermsK = minimizer.getCombExps();
            qDebug() << "Algorithm NKF solutions:" << algmTermsK.size();

            // Безопасное логирование для НКФ
            for (size_t i = 0; i < algmTermsK.size(); i++) {
                qDebug() << "  NKF Solution" << i << ":";
                for (size_t j = 0; j < algmTermsK[i].size(); j++) {
                    if (j < algmTermsK[i].size()) {
                        QString algTerm = QString::fromStdString(algmTermsK[i][j]);
                        QString normalized = normalizeTerm(algTerm);
                        qDebug() << "    Original:" << algTerm << "-> Normalized:" << normalized;
                    }
                }
            }
        } else {
            qDebug() << "NKF calculation failed!";
        }

        qDebug() << "Minimization complete - NDF solutions:" << algmTermsD.size()
                 << "NKF solutions:" << algmTermsK.size();

    } catch (const std::exception& e) {
        qDebug() << "Exception during minimization:" << e.what();
    } catch (...) {
        qDebug() << "Unknown exception during minimization!";
    }
}

void QLabCarnoCardWgt::setStructureData(QStructureTableWgt* structureTableWidget, int triggerColumnIndex, const QString& triggerInputName)
{
    if (!structureTableWidget) {
        qWarning() << "Structure table widget is null!";
        return;
    }

    // Очищаем таблицу
    clearTableData();

    QTableWidgetItem* triggerHeader = ui->tableWidgetFuncPreview->item(0, 4);
    if (triggerHeader) {
        triggerHeader->setText(triggerInputName);
    }

    qDebug() << "Filling table with data from structure table, trigger column:" << triggerColumnIndex;

    // ЗАПОЛНЯЕМ ТАБЛИЦУ ДАННЫМИ ИЗ structureTableWidget В ТОМ ЖЕ ПОРЯДКЕ
    for (int sourceRow = 2; sourceRow <= 17; sourceRow++) {
        int targetRow = sourceRow;

        // Заполняем Q3, Q2, Q1 из исходной таблицы
        for (int col = 1; col <= 3; col++) {
            QTableWidgetItem* sourceItem = structureTableWidget->item(sourceRow, col);
            if (sourceItem) {
                QTableWidgetItem* targetItem = ui->tableWidgetFuncPreview->item(targetRow, col-1);
                if (targetItem) {
                    targetItem->setText(sourceItem->text());
                }
            }
        }

        // Заполняем X из заголовка
        QWidget* xHeaderWidget = structureTableWidget->cellWidget(sourceRow, 8);
        if (xHeaderWidget) {
            QStructureTableHeaderWgt* xHeader = qobject_cast<QStructureTableHeaderWgt*>(xHeaderWidget);
            if (xHeader) {
                QString xValue = xHeader->getHeaderText();
                QTableWidgetItem* targetItem = ui->tableWidgetFuncPreview->item(targetRow, 3);
                if (targetItem) {
                    targetItem->setText(xValue);
                }
            }
        }

        // Заполняем значение триггера
        QTableWidgetItem* triggerItem = structureTableWidget->item(sourceRow, triggerColumnIndex);
        if (triggerItem) {
            QTableWidgetItem* targetItem = ui->tableWidgetFuncPreview->item(targetRow, 4);
            if (targetItem) {
                targetItem->setText(triggerItem->text());
            }
        }
    }

    // ОБНОВЛЯЕМ currentFunc В НУЖНОМ ПОРЯДКЕ (X*8 + Q3*4 + Q2*2 + Q1*1)
    updateCurrentFuncFromTable();

    qDebug() << "Table data updated from structure";
    qDebug() << "CurrentFunc:" << currentFunc;
}

void QLabCarnoCardWgt::updateCurrentFuncFromTable()
{
    //qDebug() << "=== UPDATING CURRENTFUNC FROM TABLE ===";

    // Создаем строку из 16 символов (по умолчанию нули)
    QString newFunc = "0000000000000000";

    // Проходим по всем строкам таблицы истинности (от 2 до 17)
    for (int tableRow = 2; tableRow < ui->tableWidgetFuncPreview->rowCount(); tableRow++) {
        QTableWidgetItem* itemQ3 = ui->tableWidgetFuncPreview->item(tableRow, 0);
        QTableWidgetItem* itemQ2 = ui->tableWidgetFuncPreview->item(tableRow, 1);
        QTableWidgetItem* itemQ1 = ui->tableWidgetFuncPreview->item(tableRow, 2);
        QTableWidgetItem* itemX = ui->tableWidgetFuncPreview->item(tableRow, 3);
        QTableWidgetItem* itemTrigger = ui->tableWidgetFuncPreview->item(tableRow, 4);

        if (itemQ3 && itemQ2 && itemQ1 && itemX && itemTrigger) {
            // Берем значения как есть из таблицы
            QString q3Str = itemQ3->text();
            QString q2Str = itemQ2->text();
            QString q1Str = itemQ1->text();
            QString xStr = itemX->text();
            QString triggerValue = itemTrigger->text();

            // Преобразуем в числа (если не число, используем 0)
            int Q3 = (q3Str == "1") ? 1 : 0;
            int Q2 = (q2Str == "1") ? 1 : 0;
            int Q1 = (q1Str == "1") ? 1 : 0;
            int X = (xStr == "1") ? 1 : 0;

            // Вычисляем индекс по формуле: X*8 + Q3*4 + Q2*2 + Q1*1
            int index = X * 8 + Q3 * 4 + Q2 * 2 + Q1 * 1;

            if (index >= 0 && index < 16) {
                // Сохраняем значение из таблицы (0, 1 или *) как есть
                newFunc[index] = triggerValue.isEmpty() ? '0' : triggerValue[0];
                //qDebug() << "Table row" << tableRow << ": Q3=" << Q3 << "Q2=" << Q2
                //         << "Q1=" << Q1 << "X=" << X << "-> index" << index
                //         << "set to:" << triggerValue;
            }
        }
    }

    currentFunc = newFunc;
    qDebug() << "Updated currentFunc:" << currentFunc;
}

void QLabCarnoCardWgt::debugTableToFuncMapping()
{
    //qDebug() << "=== DEBUG TABLE TO FUNCTION MAPPING ===";
    //qDebug() << "Current function:" << currentFunc;

    // Проверяем все возможные комбинации
    for (int X = 0; X <= 1; X++) {
        for (int Q3 = 0; Q3 <= 1; Q3++) {
            for (int Q2 = 0; Q2 <= 1; Q2++) {
                for (int Q1 = 0; Q1 <= 1; Q1++) {
                    int index = X * 8 + Q3 * 4 + Q2 * 2 + Q1 * 1;

                    // Находим соответствующую строку в таблице
                    QString expected = "?";
                    for (int tableRow = 2; tableRow < ui->tableWidgetFuncPreview->rowCount(); tableRow++) {
                        QTableWidgetItem* itemQ3 = ui->tableWidgetFuncPreview->item(tableRow, 0);
                        QTableWidgetItem* itemQ2 = ui->tableWidgetFuncPreview->item(tableRow, 1);
                        QTableWidgetItem* itemQ1 = ui->tableWidgetFuncPreview->item(tableRow, 2);
                        QTableWidgetItem* itemX = ui->tableWidgetFuncPreview->item(tableRow, 3);
                        QTableWidgetItem* itemTrigger = ui->tableWidgetFuncPreview->item(tableRow, 4);

                        if (itemQ3 && itemQ2 && itemQ1 && itemX && itemTrigger) {
                            bool okQ3, okQ2, okQ1, okX;
                            int tQ3 = itemQ3->text().toInt(&okQ3);
                            int tQ2 = itemQ2->text().toInt(&okQ2);
                            int tQ1 = itemQ1->text().toInt(&okQ1);
                            int tX = itemX->text().toInt(&okX);

                            if (okQ3 && okQ2 && okQ1 && okX &&
                                tQ3 == Q3 && tQ2 == Q2 && tQ1 == Q1 && tX == X) {
                                expected = itemTrigger->text();
                                break;
                            }
                        }
                    }

                    //qDebug() << "Index" << index << ": X=" << X << "Q3=" << Q3 << "Q2=" << Q2 << "Q1=" << Q1
                    //         << "-> func[" << index << "] =" << (index < currentFunc.length() ? currentFunc[index] : '?')
                    //         << "Expected:" << expected;
                }
            }
        }
    }
}

bool QLabCarnoCardWgt::recvCaclExp(expTree* exp, int Q3, int Q2, int Q1, int X)
{
    if (!exp) {
        //qDebug() << "    recvCaclExp: null expression";
        return false;
    }

    //qDebug() << "    recvCaclExp: op='" << exp->op << "'";

    if (exp->op == '!') {
        bool result = !recvCaclExp(exp->lf, Q3, Q2, Q1, X);
        //qDebug() << "    recvCaclExp: ! operation = " << result;
        return result;
    }
    else if (exp->op == '*') {
        bool left = recvCaclExp(exp->lf, Q3, Q2, Q1, X);
        bool right = recvCaclExp(exp->rt, Q3, Q2, Q1, X);
        bool result = left & right;
        //qDebug() << "    recvCaclExp: * operation: " << left << " & " << right << " = " << result;
        return result;
    }
    else if (exp->op == '+') {
        bool left = recvCaclExp(exp->lf, Q3, Q2, Q1, X);
        bool right = recvCaclExp(exp->rt, Q3, Q2, Q1, X);
        bool result = left | right;
        //qDebug() << "    recvCaclExp: + operation: " << left << " | " << right << " = " << result;
        return result;
    }
    else if (exp->op == '1') {
        //qDebug() << "    recvCaclExp: variable Q1 = " << Q1;
        return Q1;
    }
    else if (exp->op == '2') {
        //qDebug() << "    recvCaclExp: variable Q2 = " << Q2;
        return Q2;
    }
    else if (exp->op == '3') {
        //qDebug() << "    recvCaclExp: variable Q3 = " << Q3;
        return Q3;
    }
    else if (exp->op == '4') {
        //qDebug() << "    recvCaclExp: variable X = " << X;
        return X;
    }

    //() << "    recvCaclExp: unknown op '" << exp->op << "'";
    return false;
}
