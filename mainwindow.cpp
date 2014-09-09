#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mytab *tab = new mytab;
    this->setCentralWidget(tab);
    setWindowTitle(tr("Windows任务管理器"));
        myStatus_1 = new QLabel;
        myStatus_1->setMinimumSize(100,20);
        myStatus_1->setFrameShape(QFrame::NoFrame);
        ui->statusBar->addPermanentWidget(myStatus_1);
        myStatus_1->setText("进程数:");
        connect(CpuThread::app,&CpuThread::process_Q,myStatus_1,&QLabel::setText,Qt::QueuedConnection);
        myStatus_2 = new QLabel;
        myStatus_2->setMinimumSize(125,20);
        myStatus_2->setFrameShape(QFrame::NoFrame);
        ui->statusBar->addPermanentWidget(myStatus_2);
        connect(CpuThread::app,&CpuThread::cpu_Q,myStatus_2,&QLabel::setText,Qt::QueuedConnection);
        myStatus_3 = new QLabel;
        myStatus_3->setMinimumSize(125,20); //不会= =
        myStatus_3->setFrameShape(QFrame::NoFrame);
        ui->statusBar->addPermanentWidget(myStatus_3);
        ui->statusBar->setSizeGripEnabled(false);
        connect(CpuThread::app,&CpuThread::memory_Q,myStatus_3,&QLabel::setText,Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("Open"));
}

