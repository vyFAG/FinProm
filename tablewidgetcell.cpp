#include "tablewidgetcell.h"

TableWidgetCell::TableWidgetCell(int setX, int setY)
{
    x = setX;
    y = setY;
    salaryNewValue = new QLineEdit;
    //salaryNewValue->setEnabled(0);
    salaryNewValue->hide();

    presenceChange = new QCheckBox;
    connect(presenceChange, SIGNAL(clicked(bool)), this, SLOT(presenceChanged(bool)));

    salaryChangeButton = new QPushButton;
    salaryChangeButton->setObjectName("salary-change");
    salaryChangeButton->setFixedSize(QSize(18, 18));
    salaryChangeButton->setIcon(QIcon("dollar_sign.png"));
    salaryChangeButton->setIconSize(QSize(16, 16));
    salaryChangeButton->hide();
    connect(salaryChangeButton, SIGNAL(clicked()), this, SLOT(salaryChangeButtonClicked()));

    //salaryChangeLabel = new QLabel;

    salaryInformation = new QLabel("Введите новую зарплату");
    salaryInformation->hide();

    cellLayout = new QGridLayout;
    cellLayout->addWidget(salaryInformation, 0, 0, 1, 3);
    cellLayout->addWidget(salaryNewValue, 1, 0, 1, 3);
    cellLayout->addWidget(presenceChange, 1, 3, 1, 1);
    cellLayout->addWidget(salaryChangeButton, 1, 4, 1, 1);
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(cellLayout);
    this->setLayout(mainLayout);
}

int TableWidgetCell::getX() const {
    return x;
}
int TableWidgetCell::getY() const {
    return y;
}

void TableWidgetCell::setPresence() {
    presenceChange->setChecked(1);
}
void TableWidgetCell::setChangedSalary(double salary) {
    presenceChange->setChecked(1);
    emit(salaryChangeButton->clicked());
    salaryNewValue->setText(QString::number(salary));
}

void TableWidgetCell::presenceChanged(bool isChecked) {
    if(isChecked == 1) {
        salaryChangeButton->show();
    }
    else if(isChecked == 0) {
        salaryChangeButton->hide();
    }

    emit makeStretch();
    emit setSalary(x, y, -1);
}

void TableWidgetCell::salaryChangeButtonClicked() {
    salaryNewValue->show();
    salaryInformation->show();

    emit makeStretch();
}

void TableWidgetCell::salaryChanged(int setSalaryInt) {
    emit setSalary(x, y, setSalaryInt);
}
