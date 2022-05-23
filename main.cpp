#include "mainwindow.h"
#include "startwindow.h"

#include <QApplication>

#include "projectclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w(new ProjectClass());
    StartWindow w;
    w.show();
    return a.exec();
}
