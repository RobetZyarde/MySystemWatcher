﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tab.h"
#include <QProgressBar>
#include "cputhread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setThread(CpuThread *workthread);
private:
    Ui::MainWindow *ui;
     QAction *openAction;
     void open();
};

#endif // MAINWINDOW_H
