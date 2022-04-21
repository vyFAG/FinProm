#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
    mainTable = new WorkersTable;
    //mainTable = new QTableWidget;
    //mainTable->setRowCount(1); mainTable->setColumnCount(1);
    //mainTable->setCellWidget(0, 0, new TableWidgetCell);

    QFile* styleSheetFile = new QFile("style_sheet.css");
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    mainTable->addColumn();
    mainTable->addRow();
    mainTable->addColumn();
    mainTable->addRow();
    mainTable->addColumn();
    mainTable->addRow();
    mainTable->addColumn();
    mainTable->addRow();
    mainTable->addColumn();
    mainTable->addRow();
    mainTable->addColumn();
    mainTable->addRow();

    mainLayout = new QGridLayout;
    mainLayout->addWidget(mainTable);
    //mainLayout->addWidget(new TableWidgetCell);
    //mainLayout->addWidget(new TableWidgetCell);
    this->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}

