#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QErrorMessage>
#include <QDataStream>
#include <QFile>
#include <QCoreApplication>
#include <QDir>

#include "workerstable.h"
#include "workerclass.h"
#include "tablewidgetcell.h"
#include "editworkerwindow.h"
#include "projectclass.h"
#include "worktimeset.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(ProjectClass* startProject);
    ~MainWindow();
    QString changeSlash(QString path);

private:
    WorkersTable* mainTable;
    QGridLayout* mainLayout;
    QPushButton* addWorker;
    QPushButton* dateOfWorkChange;
    QPushButton* saveProject;

    ProjectClass* mainProject;
    WorkerClass* tmpWorker;

public slots:
    void workerAdded();
    void dateOfWorkChanged();
    void addWorkerToProject();
    void changeProjectDate();
    void projectSaved();
};

#endif // MAINWINDOW_H

