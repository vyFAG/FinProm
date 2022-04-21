#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QTableWidget>
#include <QFile>

#include "workerstable.h"
#include "tablewidgetcell.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    WorkersTable* mainTable;
    //QTableWidget* mainTable;
    QGridLayout* mainLayout;
};
#endif // MAINWINDOW_H
