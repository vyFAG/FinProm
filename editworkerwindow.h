#ifndef EDITWORKERWINDOW_H
#define EDITWORKERWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "workerclass.h"

class EditWorkerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit EditWorkerWindow(WorkerClass& worker);
    ~EditWorkerWindow();
    void numberNormalize();

private:
    QPushButton* okButton;
    QPushButton* cancelButton;
    QLabel* nameInformationLabel;
    QLabel* salaryInformationLabel;
    QLabel* specializationInformationLabel;
    QLineEdit* nameLineEdit;
    QLineEdit* salaryLineEdit;
    QLineEdit* specializationLineEdit;
    QGridLayout* mainLayout;
    WorkerClass* workerTmp;

private slots:
    void cancelEditing();
    void acceptEditing();

signals:
    void finishEdit();
    void cancelEdit();
};

#endif // EDITWORKERWINDOW_H
