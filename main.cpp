#include "mainwindow.h"
#include "startwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //StartWindow w;
    w.show();
    return a.exec();
}
