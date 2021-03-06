QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editworkerwindow.cpp \
    existingprojectbutton.cpp \
    main.cpp \
    mainwindow.cpp \
    newprojectwindow.cpp \
    projectclass.cpp \
    startwindow.cpp \
    tablewidgetcell.cpp \
    workerclass.cpp \
    workerstable.cpp \
    worktimeset.cpp

HEADERS += \
    editworkerwindow.h \
    existingprojectbutton.h \
    mainwindow.h \
    newprojectwindow.h \
    projectclass.h \
    startwindow.h \
    tablewidgetcell.h \
    workerclass.h \
    workerstable.h \
    worktimeset.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
