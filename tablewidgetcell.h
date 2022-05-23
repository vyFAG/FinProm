#ifndef TABLEWIDGETCELL_H
#define TABLEWIDGETCELL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QCheckBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>

class TableWidgetCell : public QWidget
{
    Q_OBJECT
public:
    TableWidgetCell(int, int);
    int getX() const;
    int getY() const;
    void setPresence();
    void setChangedSalary(double);

private:
    QLineEdit* salaryNewValue;
    QCheckBox* presenceChange;
    QPushButton* salaryChangeButton;
    //QLabel* salaryChangeLabel;
    QLabel* salaryInformation;
    QGridLayout* cellLayout;
    QVBoxLayout* mainLayout;

    int x; int y;

signals:
    void makeStretch();
    void setSalary(int x, int y, double setSalary);

private slots:
    void presenceChanged(bool);
    void salaryChangeButtonClicked();
    void salaryChanged(int);
};

#endif // TABLEWIDGETCELL_H
