#ifndef PROJECTCLASS_H
#define PROJECTCLASS_H

#include <QVector>

#include <workerclass.h>

class ProjectClass
{
public:
    ProjectClass();
    void addWorker(QString, double, QString);
    QVector<WorkerClass> getWorkersVector() const;

private:
    QVector<WorkerClass> workersVector;
};

#endif // PROJECTCLASS_H
