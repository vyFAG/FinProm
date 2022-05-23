#include "mainwindow.h"

MainWindow::MainWindow(ProjectClass* startProject) {
    addWorker = new QPushButton("Добавить работника", this);
    connect(addWorker, SIGNAL(clicked()), this, SLOT(workerAdded()));

    dateOfWorkChange = new QPushButton("Изменить дату");
    connect(dateOfWorkChange, SIGNAL(clicked()), this, SLOT(dateOfWorkChanged()));

    saveProject = new QPushButton("Сохранить проект");
    connect(saveProject, SIGNAL(clicked()), this, SLOT(projectSaved()));

    mainProject = startProject;
    mainTable = new WorkersTable(mainProject);
    mainTable->prepareColumns();
    connect(mainProject, SIGNAL(workerAdded(WorkerClass&)), mainTable, SLOT(workerAddedSlot(WorkerClass&)));
    connect(mainProject, SIGNAL(dateChanged(int)), mainTable, SLOT(sheduleChangedSlot(int)));
    connect(mainTable, SIGNAL(setSalaryToProject(int,int,double)), mainProject, SLOT(changeSalary(int,int,double)));

    QFile* styleSheetFile = new QFile("style_sheet.css");
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    setStyleSheet(style);

    mainLayout = new QGridLayout;
    mainLayout->addWidget(mainTable, 0, 0, 1, 3);
    mainLayout->addWidget(addWorker, 1, 0);
    mainLayout->addWidget(dateOfWorkChange, 1, 1);
    mainLayout->addWidget(saveProject, 1, 2);
    //mainLayout->addWidget(new TableWidgetCell);
    //mainLayout->addWidget(new TableWidgetCell);
    this->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}

void MainWindow::workerAdded() {
    tmpWorker = new WorkerClass("", 0, "");
    EditWorkerWindow* tmpWindow = new EditWorkerWindow(*tmpWorker);
    connect(tmpWindow, SIGNAL(finishEdit()), this, SLOT(addWorkerToProject()));
    tmpWindow->show();
}

void MainWindow::addWorkerToProject() {
    mainProject->addWorker(*tmpWorker);
}

void MainWindow::dateOfWorkChanged() {
    WorkTimeSet* tmpWindow = new WorkTimeSet(mainProject);
    connect(tmpWindow, SIGNAL(dateChanged()), this, SLOT(changeProjectDate()));
    tmpWindow->show();
}

void MainWindow::changeProjectDate() {
    mainProject->changeTableColumn();
}

QString MainWindow::changeSlash(QString path) {
    for(int i = 0; i < path.size(); i++) {
        if(path[i] == '/') {
            path.insert(i, '/');
            i++;
        }
    }
    return path;
}

void MainWindow::projectSaved() {
    QString path = changeSlash(QCoreApplication::applicationDirPath()) + "//projects";
    //qDebug() << path;

    QDir* projectsDir = new QDir();
    projectsDir->mkpath(path);

    path = path + "//" + mainProject->getProjectName() + ".fpproject";
    QFile* savedProject = new QFile(path);

    if(!savedProject->open(QIODevice::WriteOnly)) {
        QErrorMessage* cannotReadError = new QErrorMessage();
        cannotReadError->showMessage("Невозможно осуществить запись в файл");
        return;
    }

    QDataStream write(savedProject);

    write.setVersion(QDataStream::Qt_5_13);

    write << mainProject->getProjectName() << "\n";
    write << mainProject->getProjectPath() << "\n";
    write << mainProject->getWorkersVector().size() << "\n";
    for(int i = 0; i < mainProject->getWorkersVector().size(); i++) {
        write << mainProject->getWorkersVector().at(i).getWorkerName() << "\n";
        write << mainProject->getWorkersVector().at(i).getWorkerSalary() << "\n";
        write << mainProject->getWorkersVector().at(i).getWorkerSpecialization() << "\n";
    }
    write << mainProject->getWorkersShedule().size()  << "\n";
    for(int i = 0; i < mainProject->getWorkersShedule().size(); i++) {
        write << mainProject->getWorkersShedule().at(i).size() << "\n";
        for(int x = 0; x < mainProject->getWorkersShedule().at(i).size(); x++) {
            write << mainProject->getWorkersShedule().at(i).at(x) << "\n";
        }
    }

    write << mainProject->getStartDate() << "\n";
    write << mainProject->getFinishDate() << "\n";

    savedProject->close();
    savedProject->open(QIODevice::ReadOnly);

    ProjectClass* projectTmp = new ProjectClass();

    QDataStream read(savedProject);

    read.setVersion(QDataStream::Qt_5_13);

    QString tmpString;
    read >> tmpString;
    projectTmp->setProjectName(tmpString);

    read >> tmpString;
    projectTmp->setProjectPath(tmpString);

    int workersSize;
    read >> workersSize;
    for(int i = 0; i < workersSize; i++) {
        QString workerName;
        double workerSalary;
        QString workerSpecialization;

        read >> workerName;
        read >> workerSalary;
        read >> workerSpecialization;

        projectTmp->addWorker(workerName, workerSalary, workerSpecialization);
    }

    int workerSheduleSize;
    read >> workerSheduleSize;
    qDebug() << workerSheduleSize;
    for(int i = 0; i < workerSheduleSize; i++) {
        int workerSalarySize;
        QVector<double> workerSalary;
        read >> workerSalarySize;
        qDebug() << workerSalarySize;
        for(int x = 0; x < workerSalarySize; x++) {
            double workerSalaryDay;
            read >> workerSalaryDay;

            workerSalary.push_back(workerSalaryDay);
        }
        projectTmp->addUploaded(workerSalary);
    }

    QDate startDate;
    QDate finishDate;

    read >> startDate;
    read >> finishDate;
    projectTmp->setStartDate(startDate);
    projectTmp->setFinishDate(finishDate);

    projectTmp->outProject();

    savedProject->close();
}
