#include "projectclass.h"

ProjectClass::ProjectClass()
{

}

void ProjectClass::addWorker(QString name, double salary, QString specialization) {
    workersVector.push_back(WorkerClass(name, salary, specialization));
}

QVector<WorkerClass> ProjectClass::getWorkersVector() const {
    return workersVector;
}
