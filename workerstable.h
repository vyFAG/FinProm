#ifndef WORKERSTABLE_H
#define WORKERSTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QStringList>

#include "tablewidgetcell.h"
#include "workerclass.h"
#include "projectclass.h"

class WorkersTable : public QTableWidget
{
    Q_OBJECT
public:
    WorkersTable(ProjectClass* setProject);
    void addRow();
    void addColumn();
    void setWidgetAll();
    void initializeCells(ProjectClass* setProject);
    void setHeaders();
    void prepareColumns();

private:
    ProjectClass* mainProject;

signals:
    //void cellChecked(int, int);
    //void cellChanged(int, int);
    void setSalaryToProject(int, int, double);

private slots:
    void makeCellStretch();
    void workerAddedSlot(WorkerClass&);
    void sheduleChangedSlot(int);
    void salaryChanged(int, int, double);
};

#endif // WORKERSTABLE_H
