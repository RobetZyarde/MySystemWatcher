#include "mainwindow.h"
#include <QApplication>
#include "cputhread.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CpuThread * workthread = new CpuThread();
    MainWindow* w = new MainWindow;
    w->show();
    workthread->start();
    return a.exec();
}
