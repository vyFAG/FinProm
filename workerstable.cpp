#include "workerstable.h"

WorkersTable::WorkersTable(ProjectClass* setProject) {
    mainProject = setProject;
    this->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setColumnCount(1);
}

void WorkersTable::setWidgetAll() {
    for(int y = 0; y < this->rowCount(); y++) {
        for(int x = 1; x < this->columnCount(); x++) {
            setCellWidget(y, x, new TableWidgetCell(x, y));
            if(mainProject->getWorkerSalary(x - 1, y) == mainProject->getWorkersVector()[y].getWorkerSalary()) {
                TableWidgetCell* widgetTmp = qobject_cast<TableWidgetCell*>(this->cellWidget(y, x));
                widgetTmp->setPresence();
            }
            else if(mainProject->getWorkerSalary(x - 1, y) != mainProject->getWorkersVector()[y].getWorkerSalary() &&
                    mainProject->getWorkerSalary(x - 1, y) != 0){
                TableWidgetCell* widgetTmp = qobject_cast<TableWidgetCell*>(this->cellWidget(y, x));
                widgetTmp->setChangedSalary(mainProject->getWorkerSalary(x - 1, y));
            }
            connect(this->cellWidget(y, x), SIGNAL(setSalary(int,int,double)), this, SLOT(salaryChanged(int,int,double)));
            connect(this->cellWidget(y, x), SIGNAL(makeStretch()), this, SLOT(makeCellStretch()));
        }
    }
    setHeaders();
}

void WorkersTable::initializeCells(ProjectClass setProject) {
    for(int y = 0; y < setProject.getWorkersShedule().size(); y++) {
        if(this->rowCount() <= y) {
            this->setRowCount(this->rowCount() + 1);
        }
        this->setItem(y, 0, new QTableWidgetItem(setProject.getWorkersVector().at(y).getWorkerName()));
        for(int x = 1; x < setProject.getWorkersShedule().at(y).size(); x++) {
            setCellWidget(y, x, new TableWidgetCell(x, y));
            if(mainProject->getWorkerSalary(x - 1, y) == mainProject->getWorkersVector().at(y).getWorkerSalary()) {
                TableWidgetCell* widgetTmp = qobject_cast<TableWidgetCell*>(this->cellWidget(y, x));
                widgetTmp->setPresence();
            }
            else if(mainProject->getWorkerSalary(x - 1, y) != mainProject->getWorkersVector().at(y).getWorkerSalary() &&
                    mainProject->getWorkerSalary(x - 1, y) != 0){
                TableWidgetCell* widgetTmp = qobject_cast<TableWidgetCell*>(this->cellWidget(y, x));
                widgetTmp->setChangedSalary(mainProject->getWorkerSalary(x - 1, y));
            }
            connect(this->cellWidget(y, x), SIGNAL(setSalary(int,int,double)), this, SLOT(salaryChanged(int,int,double)));
            connect(this->cellWidget(y, x), SIGNAL(makeStretch()), this, SLOT(makeCellStretch()));
        }
    }
}

void WorkersTable::setHeaders() {
    QStringList headersTmp;
    headersTmp.append("Работник");

    for(int i = 0; i < this->columnCount(); i++) {
        headersTmp.append(mainProject->getStartDate().addDays(i).toString());
    }

    this->setHorizontalHeaderLabels(headersTmp);
}

void WorkersTable::makeCellStretch() {
    this->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void WorkersTable::workerAddedSlot(WorkerClass& worker) {
    this->setRowCount(this->rowCount() + 1);
    this->setItem(this->rowCount() - 1, 0, new QTableWidgetItem(worker.getWorkerName()));
}
void WorkersTable::sheduleChangedSlot(int columns) {
    this->setColumnCount(columns + 1);
    setWidgetAll();
    makeCellStretch();
}

void WorkersTable::prepareColumns() {
    this->setColumnCount(mainProject->getStartDate().daysTo(mainProject->getFinishDate()));
    setWidgetAll();
    makeCellStretch();
}

void WorkersTable::salaryChanged(int x, int y, double setSalary) {
    emit setSalaryToProject(x - 1, y, setSalary);
}
