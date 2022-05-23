#ifndef NEWPROJECTWINDOW_H
#define NEWPROJECTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>

class NewProjectWindow : public QWidget
{
    Q_OBJECT
public:
    NewProjectWindow();

private:
    QLineEdit* setNameOfProject;
    QLabel* setNameOfProjectInformation;
    QPushButton* createProject;
    QPushButton* cancelButton;
    QGridLayout* mainLayout;

public slots:
    void cancelButtonClicked();
    void applyButtonClicked();

signals:
    void projectCreated(QString);
};

#endif // NEWPROJECTWINDOW_H
