#include "startwindow.h"

StartWindow::StartWindow(QWidget *parent) : QWidget(parent) {
    //this->setStyleSheet("background-color: #ffffff");

    QFile* styleSheetFile = new QFile("style_sheet.css");
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    //qDebug() << style;

    //this->setStyleSheet(style);

    this->setFixedSize(640, 480);

    newProjectButton = new QPushButton("Создать новый проект" ,this);
    newProjectButton->setMaximumSize(240, 80);
    newProjectButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    newProjectButton->setObjectName("projectButton");
    connect(newProjectButton, SIGNAL(clicked()), this, SLOT(createNewProject()));

    loadProjectButton = new QPushButton("Загрузить проект", this);
    loadProjectButton->setMaximumSize(240, 80);
    loadProjectButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    loadProjectButton->setObjectName("projectButton");
    connect(loadProjectButton, SIGNAL(clicked()), this, SLOT(doNothing()));

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
    for(int i = 0; i < 2; ++i) {
        existingProjectsButtonsArray.push_back(new QPushButton(QString("text" + QString::number(i))));
        existingProjectsButtonsArray.back()->setMinimumHeight(20);
        existingProjectsButtonsArray.back()->setObjectName("existingProjectButton");
        connect(existingProjectsButtonsArray.back(), SIGNAL(clicked()), this, SLOT(doNothing()));
        existingProjectsLayout->addWidget(existingProjectsButtonsArray.back());
    }
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

void StartWindow::doNothing() {
    qDebug() << "do nothing";
}

void StartWindow::createNewProject() {
    //MainWindow* newProjectWindow = new MainWindow(currentProject);
    //newProjectWindow->show();
    //this->close();
}
