#include "editworkerwindow.h"

EditWorkerWindow::EditWorkerWindow(WorkerClass& worker) : workerTmp(&worker){
    QFile* styleSheetFile = new QFile("style_sheet.css");
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    this->setStyleSheet(style);

    okButton = new QPushButton("OK", this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(acceptEditing()));
    cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelEditing()));

    nameInformationLabel = new QLabel("Имя", this);
    salaryInformationLabel = new QLabel("Зарплата", this);
    specializationInformationLabel = new QLabel("Специализация", this);

    nameLineEdit = new QLineEdit(workerTmp->getWorkerName(), this);
    salaryLineEdit = new QLineEdit(QString::number(workerTmp->getWorkerSalary()), this);
    specializationLineEdit = new QLineEdit(workerTmp->getWorkerSpecialization(), this);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameInformationLabel, 0, 0, 1, 2);
    mainLayout->addWidget(nameLineEdit, 0, 2, 1, 4);
    mainLayout->addWidget(salaryInformationLabel, 1, 0, 1, 2);
    mainLayout->addWidget(salaryLineEdit, 1, 2, 1, 4);
    mainLayout->addWidget(specializationInformationLabel, 2, 0, 1, 2);
    mainLayout->addWidget(specializationLineEdit, 2, 2, 1, 4);
    mainLayout->addWidget(okButton, 3, 2, 1, 2);
    mainLayout->addWidget(cancelButton, 3, 4, 1, 2);

    this->setLayout(mainLayout);
}

void EditWorkerWindow::numberNormalize() {
    QString numberTmp = salaryLineEdit->text();
    for(int i = 0; i < numberTmp.size(); i++) {
        if(QString("qwertyuiopasdfghjklzxcvbnm/;'\[]=-+)(&?><!@%$#").contains(numberTmp[i], Qt::CaseInsensitive)) {
            numberTmp.remove(numberTmp[i]);
            i--;
        }
        else if(numberTmp[i] == '"') {
            numberTmp.remove(numberTmp[i]);
            i--;
        }
        else if(numberTmp[i] == ',') {
            numberTmp[i] = '.';
        }
    }
    qDebug() << numberTmp;
    salaryLineEdit->setText(numberTmp);
}

EditWorkerWindow::~EditWorkerWindow() {

}

void EditWorkerWindow::cancelEditing() {
    //emit cancelEdit();
    this->close();
}
void EditWorkerWindow::acceptEditing() {
    workerTmp->setWorkerName(nameLineEdit->text());

    numberNormalize();
    if(salaryLineEdit->text() == "0" || salaryLineEdit->text() == "\0") {
        salaryLineEdit->setStyleSheet("color: #ff0000");
        return;
    }

    workerTmp->setWorkerSalary(salaryLineEdit->text().toDouble());
    workerTmp->setWorkerSpecialization(specializationLineEdit->text());
    emit finishEdit();
    this->close();
}
