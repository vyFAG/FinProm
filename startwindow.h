#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QVector>
#include <QPair>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QString>

#include "mainwindow.h"
#include "projectclass.h"
#include "existingprojectbutton.h"
#include "projectclass.h"
#include "newprojectwindow.h"

class StartWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = nullptr);
    void makeProjectList();
    QString changeSlash(QString path);


private:
    QPushButton* newProjectButton;
    QPushButton* loadProjectButton;

    QLabel* projectsBeginning;
    QLabel* listOfProjects;

    QVBoxLayout* projectButtonsLayout;
    QVBoxLayout* existingProjectsLayout;
    QVBoxLayout* functionsLayout;
    QVBoxLayout* projectsLayout;

    QScrollArea* existingProjectsScrollArea;

    QHBoxLayout* mainLayout;

    QVector<QPair<QString, ExistingProjectButton*>> existingProjectsFiles;
    ProjectClass* mainProject;

    NewProjectWindow* newProjectWindow;

signals:

private slots:
    void projectLoadedFromList(int);
    void createNewProject();
    void openNewProject(QString);

};

#endif // STARTWINDOW_H
