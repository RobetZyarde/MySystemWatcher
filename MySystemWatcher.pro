#-------------------------------------------------
#
# Project created by QtCreator 2014-08-30T17:26:02
#
#-------------------------------------------------

QT       += core gui

QT += widgets

TARGET = MySystemWatcher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tab.cpp \
    mytabbar.cpp \
    cpustate.cpp \
    cputhread.cpp \
    cpuscene.cpp \
    label1.cpp \
    label2.cpp \
    label3.cpp \
    memoryscene.cpp

HEADERS  += mainwindow.h \
    tab.h \
    mytabbar.h \
    cpustate.h \
    cputhread.h \
    cpuscene.h \
    label1.h \
    label2.h \
    label3.h \
    memoryscene.h

FORMS    += mainwindow.ui \
    cpustate.ui \
    label1.ui \
    label2.ui \
    label3.ui

RESOURCES += \
    resource.qrc

LIBS += -lpsapi


