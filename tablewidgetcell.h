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
    explicit TableWidgetCell(QWidget *parent = nullptr);

private:
    QLineEdit* salaryNewValue;
    QCheckBox* presenceChange;
    QPushButton* salaryChangeButton;
    //QLabel* salaryChangeLabel;
    QLabel* salaryInformation;
    QGridLayout* cellLayout;
    QVBoxLayout* mainLayout;

signals:
    void makeStretch();

private slots:
    void presenceChanged(bool);
    void salaryChangeButtonClicked();
};

#endif // TABLEWIDGETCELL_H
