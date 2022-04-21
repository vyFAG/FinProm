#ifndef WORKERSTABLE_H
#define WORKERSTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>

#include "tablewidgetcell.h"

class WorkersTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit WorkersTable(QWidget *parent = nullptr);
    void addRow();
    void addColumn();
    void expandCell(int rowBegin, int columnBegin, int rowFinish = 0, int columnFinish = 0);
    void setWidgetAll();


signals:

private slots:
    void makeCellStretch();
};

#endif // WORKERSTABLE_H
