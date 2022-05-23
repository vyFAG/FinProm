#include "workerclass.h"

WorkerClass::WorkerClass(QString name, double salary, QString specialization) : workerName(name),
    workerSalary(salary),
    workerSpecialization(specialization)
{
}

WorkerClass::WorkerClass()
{
    workerName = "";
    workerSalary = 0;
    workerSpecialization = "";
}

QString WorkerClass::getWorkerName() const {
    return workerName;
}
double WorkerClass::getWorkerSalary() const {
    return workerSalary;
}
QString WorkerClass::getWorkerSpecialization() const {
    return workerSpecialization;
}

void WorkerClass::setWorkerSalary(double setSalary) {
    workerSalary = setSalary;
}
void WorkerClass::setWorkerSpecialization(QString setSpecialization) {
    workerSpecialization = setSpecialization;
}
void WorkerClass::setWorkerName(QString setName) {
    workerName = setName;
}
