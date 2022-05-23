#ifndef WORKERCLASS_H
#define WORKERCLASS_H

#include <QString>

class WorkerClass
{
public:
    WorkerClass(QString name, double salary, QString specialization);
    WorkerClass();

    QString getWorkerName() const;
    double getWorkerSalary() const;
    QString getWorkerSpecialization() const;

    void setWorkerName(QString);
    void setWorkerSalary(double);
    void setWorkerSpecialization(QString);

private:
    QString workerName = "";
    double workerSalary = 0;
    QString workerSpecialization = "";
};

#endif // WORKERCLASS_H
