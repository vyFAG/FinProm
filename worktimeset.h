#ifndef WORKTIMESET_H
#define WORKTIMESET_H

#include <QWidget>
#include <QPushButton>
#include <QDateEdit>
#include <QLabel>
#include <QGridLayout>
#include <QDateTime>
#include <QFile>

#include "projectclass.h"

class WorkTimeSet : public QWidget
{
    Q_OBJECT
public:
    WorkTimeSet(ProjectClass*);

private:
    QDateEdit* startTime;
    QDateEdit* finishTime;
    QLabel* startTimeInformation;
    QLabel* finishTimeInformation;
    QPushButton* cancelButton;
    QPushButton* okButton;
    QDateTime* previousDate;

    QGridLayout* mainLayout;

    ProjectClass* tmpProject;

signals:
    void dateChanged();

private slots:
    void finishDateChanged(QDate);
    void okButtonClicked();
    void cancelButtonClicked();

};

#endif // WORKTIMESET_H
