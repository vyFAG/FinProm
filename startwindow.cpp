#include "startwindow.h"

StartWindow::StartWindow(QWidget *parent) : QWidget(parent) {
    //this->setStyleSheet("background-color: #ffffff");

    QFile* styleSheetFile = new QFile("style_sheet.css");
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    //qDebug() << style;

    this->setStyleSheet(style);

    this->setFixedSize(640, 480);

    mainProject = new ProjectClass();

    newProjectButton = new QPushButton("Создать новый проект" ,this);
    newProjectButton->setMaximumSize(240, 80);
    newProjectButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    newProjectButton->setObjectName("projectButton");
    connect(newProjectButton, SIGNAL(clicked()), this, SLOT(createNewProject()));

    loadProjectButton = new QPushButton("Загрузить проект", this);
    loadProjectButton->setMaximumSize(240, 80);
    loadProjectButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    loadProjectButton->setObjectName("projectButton");
    //connect(loadProjectButton, SIGNAL(clicked()), this, SLOT(doNothing()));

    projectButtonsLayout = new QVBoxLayout();
    projectButtonsLayout->setContentsMargins(0, 40, 0, 40);
    projectButtonsLayout->setAlignment(Qt::AlignTop);
    projectButtonsLayout->setSpacing(24);
    projectButtonsLayout->addWidget(newProjectButton);
    projectButtonsLayout->addWidget(loadProjectButton);

    //projectsBeginning = new QLabel("Начало работы", this);
    //projectsBeginning->setAlignment(Qt::AlignLeft);

    functionsLayout = new QVBoxLayout();

    //functionsLayout->addWidget(projectsBeginning);
    functionsLayout->addLayout(projectButtonsLayout);

    existingProjectsScrollArea = new QScrollArea;
    existingProjectsScrollArea->setMaximumSize(240, 400);
    existingProjectsLayout = new QVBoxLayout;

    makeProjectList();

    QWidget* widget = new QWidget;
    widget->setLayout(existingProjectsLayout);
    existingProjectsScrollArea->setWidget(widget);
    existingProjectsScrollArea->show();

    listOfProjects = new QLabel("Недавние проекты", this);
    listOfProjects->setAlignment(Qt::AlignLeft);

    projectsLayout = new QVBoxLayout();

    projectsLayout->addWidget(listOfProjects);
    projectsLayout->addWidget(existingProjectsScrollArea);

    mainLayout = new QHBoxLayout(this);

    mainLayout->addLayout(projectsLayout);
    mainLayout->addLayout(functionsLayout);

    this->setStyleSheet(style);
}

QString StartWindow::changeSlash(QString path) {
    for(int i = 0; i < path.size(); i++) {
        if(path[i] == '/') {
            path.insert(i, '/');
            i++;
        }
    }
    return path;
}

void StartWindow::makeProjectList() {
    QDir projectsDir(changeSlash(QCoreApplication::applicationDirPath()) + "//projects");
    projectsDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    projectsDir.setSorting(QDir::Size | QDir::Reversed);
    QFileInfoList list = projectsDir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.completeSuffix() == "fpproject") {
            existingProjectsFiles.push_back(QPair<QString, ExistingProjectButton*>(fileInfo.absoluteFilePath(),
                                                                                   new ExistingProjectButton(fileInfo.baseName(), existingProjectsFiles.size())));
            existingProjectsFiles[existingProjectsFiles.size() - 1].second->setMinimumHeight(20);
            existingProjectsFiles[existingProjectsFiles.size() - 1].second->setObjectName("existingProjectButton");
            existingProjectsLayout->addWidget(existingProjectsFiles[existingProjectsFiles.size() - 1].second);
            connect(existingProjectsFiles[existingProjectsFiles.size() - 1].second, SIGNAL(clicked()),
                    existingProjectsFiles[existingProjectsFiles.size() - 1].second, SLOT(buttonClicked()));
            connect(existingProjectsFiles[existingProjectsFiles.size() - 1].second,
                    SIGNAL(returnId(int)), this, SLOT(projectLoadedFromList(int)));
        }
    }
}

void StartWindow::createNewProject() {
    newProjectWindow = new NewProjectWindow();
    newProjectWindow->show();
    connect(newProjectWindow, SIGNAL(projectCreated(QString)), this, SLOT(openNewProject(QString)));
}

void StartWindow::openNewProject(QString setName) {
    QString setNameTmp = setName;
    mainProject->setProjectName(setNameTmp);
    MainWindow* mainWindow = new MainWindow(mainProject);
    newProjectWindow->close();
    mainWindow->show();
    this->hide();
}

void StartWindow::projectLoadedFromList(int index) {
    QString path = existingProjectsFiles[index].first;
    QFile* savedProject = new QFile(path);
    if(!savedProject->open(QIODevice::ReadOnly)) {
        QErrorMessage* cannotReadError = new QErrorMessage();
        cannotReadError->showMessage("Невозможно прочитать из файла");
        return;
    }

    QDataStream read(savedProject);

    read.setVersion(QDataStream::Qt_5_13);

    QString tmpString;
    read >> tmpString;
    mainProject->setProjectName(tmpString);

    read >> tmpString;
    mainProject->setProjectPath(tmpString);

    int workersSize;
    read >> workersSize;
    for(int i = 0; i < workersSize; i++) {
        QString workerName;
        double workerSalary;
        QString workerSpecialization;

        read >> workerName;
        read >> workerSalary;
        read >> workerSpecialization;

        mainProject->addWorker(workerName, workerSalary, workerSpecialization);
    }

    int workerSheduleSize;
    read >> workerSheduleSize;
    for(int i = 0; i < workerSheduleSize; i++) {
        QVector<double> tmpRow;
        int tmpRowSize;
        read >> tmpRowSize;
        read >> tmpRow;
        mainProject->addUploaded(tmpRow);
    }

    QDate startDate;
    QDate finishDate;

    read >> startDate;
    read >> finishDate;
    mainProject->setStartDate(startDate);
    mainProject->setFinishDate(finishDate);

    MainWindow* mainWindow = new MainWindow(mainProject);
    mainWindow->show();
    this->hide();
}

//void StartWindow::projectSaved() {
//    QString path = changeSlash(QCoreApplication::applicationDirPath()) + "//projects";
//    //qDebug() << path;
//
//    QDir* projectsDir = new QDir();
//    projectsDir->mkpath(path);
//
//    path += "//govno.fpproject";
//    QFile* savedProject = new QFile(path);
//
//    if(!savedProject->open(QIODevice::WriteOnly)) {
//        QErrorMessage* cannotReadError = new QErrorMessage();
//        cannotReadError->showMessage("Невозможно осуществить запись в файл");
//        return;
//    }
//
//
//    savedProject->close();
//}
