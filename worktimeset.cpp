#include "worktimeset.h"

WorkTimeSet::WorkTimeSet(ProjectClass* project)
{
    QFile* styleSheetFile = new QFile("style_sheet.css");
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    this->setStyleSheet(style);

    tmpProject = project;
    startTime = new QDateEdit();
    startTime->setDate(tmpProject->getStartDate());
    startTime->setEnabled(0);

    finishTime = new  QDateEdit();
    finishTime->setDate(tmpProject->getFinishDate());
    connect(finishTime, SIGNAL(dateChanged(QDate)), this, SLOT(finishDateChanged(QDate)));

    previousDate = new QDateTime();
    previousDate->setDate(finishTime->date());

    startTimeInformation = new QLabel("Дата начала работ");
    finishTimeInformation = new QLabel("Дата конца работ");

    cancelButton = new QPushButton("Cancel");
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
    okButton = new QPushButton("OK");
    connect(okButton, SIGNAL(clicked()), this, SLOT(okButtonClicked()));

    mainLayout = new QGridLayout();
    mainLayout->addWidget(startTimeInformation, 0, 0, 1, 2);
    mainLayout->addWidget(startTime, 0, 2, 1, 4);
    mainLayout->addWidget(finishTimeInformation, 1, 0, 1, 2);
    mainLayout->addWidget(finishTime, 1, 2, 1, 4);
    mainLayout->addWidget(okButton, 2, 2, 1, 2);
    mainLayout->addWidget(cancelButton, 2, 4, 1, 2);

    this->setLayout(mainLayout);
}

void WorkTimeSet::finishDateChanged(QDate) {
    if(startTime->date() < finishTime->date()) {
        previousDate->setDate(finishTime->date());
    }
    else {
        finishTime->setDate(previousDate->date());
    }
}

void WorkTimeSet::okButtonClicked() {
    tmpProject->setFinishDate(finishTime->date());
    emit dateChanged();
    this->close();
}
void WorkTimeSet::cancelButtonClicked() {
    this->close();
}
