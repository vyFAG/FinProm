#include "projectclass.h"

ProjectClass::ProjectClass() {
    startDate = new QDate();
    startDate->setDate(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day());
    finishDate = new QDate();
    finishDate->setDate(startDate->addDays(30).year(), startDate->addDays(30).month(), startDate->addDays(30).day());
}

void ProjectClass::addWorker(QString name, double salary, QString specialization) {
    workersVector.push_back(WorkerClass(name, salary, specialization));
    workersVectorSize++;
    emit workerAdded(workersVector[workersVector.size() - 1]);
    addToShedule();
}

void ProjectClass::addWorker(WorkerClass& worker) {
    workersVector.push_back(worker);
    workersVectorSize++;
    emit workerAdded(worker);
    addToShedule();
}

void ProjectClass::addToShedule() {
    workersShedule.push_back(QVector<double>(startDate->daysTo(*finishDate)));
    workersSheduleSizeY++;
    emit dateChanged(startDate->daysTo(*finishDate));
}


QVector<WorkerClass> ProjectClass::getWorkersVector() const {
    return workersVector;
}

QDate ProjectClass::getStartDate() const {
    return *startDate;
}
QDate ProjectClass::getFinishDate() const {
    return *finishDate;
}

double ProjectClass::getWorkerSalary(int x, int y) {
    return workersShedule[y][x];
}

void ProjectClass::setProjectName(QString setName) {
    projectName = setName;
}
void ProjectClass::setProjectPath(QString setPath) {
    projectPath = setPath;
}
QString ProjectClass::getProjectName() const {
    return projectName;
}
QString ProjectClass::getProjectPath() const {
    return projectPath;
}

void ProjectClass::addUploaded(QVector<double> addToVector) {
    workersShedule.push_back(addToVector);
}

void ProjectClass::setWorkersVectorSize(int setSize) {
    workersVectorSize = setSize;
}
void ProjectClass::setWorkersSheduleSizeX(int setSize) {
    workersSheduleSizeX = setSize;
}
void ProjectClass::setWorkersSheduleSizeY(int setSize) {
    workersSheduleSizeY = setSize;
}

QVector<QVector<double>> ProjectClass::getWorkersShedule() const {
    return workersShedule;
}

void ProjectClass::setStartDate(QDate setDate) {
    startDate->setDate(setDate.year(), setDate.month(), setDate.day());
}

void ProjectClass::setFinishDate(QDate setDate) {
    finishDate->setDate(setDate.year(), setDate.month(), setDate.day());
}

void ProjectClass::changeTableColumn() {
    if(workersShedule.size() > 0) {
        if(startDate->daysTo(*finishDate) > workersShedule[0].size()) {
            for(int i = 0; i < workersVector.size(); i++) {
                for(int x = 0; workersShedule[i].size() < startDate->daysTo(*finishDate); x++) {
                    workersShedule[i].push_back(double(0));
                    workersSheduleSizeX++;
                }
            }
            emit dateChanged(startDate->daysTo(*finishDate));
        }
        else if(startDate->daysTo(*finishDate) < workersShedule[0].size()) {
            for(int i = 0; i < workersVector.size(); i++) {
                for(int x = workersShedule[i].size(); x > startDate->daysTo(*finishDate); x--) {
                    workersShedule[i].pop_back();
                    workersSheduleSizeX--;
                }
            }
            emit dateChanged(startDate->daysTo(*finishDate));
        }
    }
}

void ProjectClass::changeSalary(int x, int y, double setSalary) {
    if(setSalary == -1) {
        workersShedule[y][x] = workersVector[y].getWorkerSalary();
    }
    else {
        workersShedule[y][x] = setSalary;
    }
}

void ProjectClass::outProject() {
    qDebug() << "projectName " << projectName;
    qDebug() << "projectPath " << projectPath;
    outWorkerArray(workersVector);
    for(int i = 0; i < workersShedule.size(); i++) {
        outArray(workersShedule[i], i);
    }
    qDebug() << startDate;
    qDebug() << finishDate;
}

void ProjectClass::outArray(QVector<double>& vectorTmp, int index) {
    qDebug() << index << " workerSalary\n";
    for(int i = 0; i < vectorTmp.size(); i++) {
        qDebug() << vectorTmp[i] << " ";
    }
    qDebug() << "\n";
}

void  ProjectClass::outWorkerArray(QVector<WorkerClass>& vectorTmp) {
    qDebug() << "WorkerVector\n";
    for(int i = 0; i < vectorTmp.size(); i++) {
        qDebug() << vectorTmp[i].getWorkerName() << " ";
        qDebug() << vectorTmp[i].getWorkerSalary() << " ";
        qDebug() << vectorTmp[i].getWorkerSpecialization() << " ";
    }
    qDebug() << "\n";
}
