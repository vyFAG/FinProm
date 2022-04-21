#include "workerstable.h"

WorkersTable::WorkersTable(QWidget *parent) : QTableWidget(parent) {
    this->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void WorkersTable::addRow() {
    this->setRowCount(this->rowCount() + 1);
    setWidgetAll();
}
void WorkersTable::addColumn() {
    this->setColumnCount(this->columnCount() + 1);
    setWidgetAll();
}

void WorkersTable::expandCell(int rowBegin, int columnBegin, int rowFinish, int columnFinish) {
    if(rowBegin > rowFinish) {
        rowFinish = rowBegin;
    }
    if(columnBegin > columnFinish) {
        columnFinish = columnBegin;
    }

    for(int y = rowBegin; y <= rowFinish; y++) {
        for(int x = columnBegin; x <= columnFinish; x++) {
            setCellWidget(y, x, new TableWidgetCell); //new TableWidgetCell
        }
    }
}

void WorkersTable::setWidgetAll() {
    for(int y = 0; y < this->rowCount(); y++) {
        for(int x = 0; x < this->columnCount(); x++) {
            setCellWidget(y, x, new TableWidgetCell); //new TableWidgetCell
            connect(this->cellWidget(y, x), SIGNAL(makeStretch()), this, SLOT(makeCellStretch()));
        }
    }
}

void WorkersTable::makeCellStretch() {
    this->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
