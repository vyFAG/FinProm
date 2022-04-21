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
#include <vector>

#include "mainwindow.h"

class StartWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = nullptr);

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

    std::vector<QPushButton*> existingProjectsButtonsArray;

signals:

private slots:
    void doNothing();
    void createNewProject();

};

#endif // STARTWINDOW_H
