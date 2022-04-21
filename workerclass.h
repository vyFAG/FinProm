#ifndef WORKERCLASS_H
#define WORKERCLASS_H

#include <QString>

class WorkerClass
{
public:
    WorkerClass(QString name, double salary, QString specialization);

private:
    QString workerName;
    double workerSalary;
    QString workerSpecialization;
};

#endif // WORKERCLASS_H
