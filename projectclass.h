#ifndef PROJECTCLASS_H
#define PROJECTCLASS_H

#include <QVector>
#include <QObject>
#include <QDate>

#include <workerclass.h>

class ProjectClass : public QObject
{
    Q_OBJECT
public:
    ProjectClass();
    void addWorker(QString, double, QString);
    void addWorker(WorkerClass&);
    void addToShedule();
    void addUploaded(QVector<double>);

    QVector<WorkerClass> getWorkersVector() const;
    QVector<QVector<double>> getWorkersShedule() const;
    QDate getStartDate() const;
    QDate getFinishDate() const;
    double getWorkerSalary(int, int);

    void setProjectName(QString setName);
    void setProjectPath(QString setPath);
    QString getProjectName() const;
    QString getProjectPath() const;

    void setWorkersVectorSize(int setSize);
    void setWorkersSheduleSizeX(int setSize);
    void setWorkersSheduleSizeY(int setSize);

    void setStartDate(QDate);
    void setFinishDate(QDate);

    void changeTableColumn();

    void outProject();
    void outArray(QVector<double>& vectorTmp, int index);
    void outWorkerArray(QVector<WorkerClass>& vectorTmp);

private:
    QString projectName = "";
    QString projectPath = "";
    int workersVectorSize = 0;
    QVector<WorkerClass> workersVector;
    int workersSheduleSizeX = 0;
    int workersSheduleSizeY = 0;
    QVector<QVector<double>> workersShedule;
    QDate* startDate;
    QDate* finishDate;

signals:
    void workerAdded(WorkerClass&);
    void sheduleChanged();
    void dateChanged(int);

public slots:
    void changeSalary(int, int, double);
};

#endif // PROJECTCLASS_H
