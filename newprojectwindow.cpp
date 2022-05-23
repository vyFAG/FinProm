#include "newprojectwindow.h"

NewProjectWindow::NewProjectWindow() {
    setNameOfProject = new QLineEdit();
    setNameOfProjectInformation = new QLabel("Введите имя");
    createProject = new QPushButton("Подтвердить");
    connect(createProject, SIGNAL(clicked()), this, SLOT(applyButtonClicked()));
    cancelButton = new QPushButton("Отмена");
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));

    mainLayout = new QGridLayout();
    mainLayout->addWidget(setNameOfProject, 0, 0, 1, 2);
    mainLayout->addWidget(setNameOfProjectInformation, 0, 2, 1, 1);
    mainLayout->addWidget(createProject, 1, 1, 1, 1);
    mainLayout->addWidget(cancelButton, 1, 2, 1, 1);

    this->setLayout(mainLayout);
}

void NewProjectWindow::cancelButtonClicked() {
    this->close();
}
void NewProjectWindow::applyButtonClicked() {
    emit projectCreated(QString(setNameOfProject->text()));
    //this->close();
}
