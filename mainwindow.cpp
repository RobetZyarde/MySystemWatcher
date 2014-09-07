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

    openAction = new QAction(QIcon(":/images/doc-open"),tr("新建任务(运行...)(N)"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("运行新程序"));
    //openAction = new QAction(QIcon(":/images/doc-open"),tr("退出任务管理器(X)"),this);
    //openAction->setShortcuts(QKeySequence::Open);
    //openAction->setStatusTip(tr("退出任务管理器"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    QMenu *file = menuBar()->addMenu(tr("文件(F)"));
    file->addAction(openAction);

    openAction = new QAction(QIcon(":/images/doc-open"),tr("前端显示(A)"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("除非被最小化，任务管理器始终在其他窗口前显示"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    QMenu *choice = menuBar()->addMenu(tr("选项(O)"));
    choice->addAction(openAction);

    openAction = new QAction(QIcon(":/images/doc-open"),tr("立即刷新"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("强迫任务管理器立即刷新，忽略更新速度设置"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    QMenu *view = menuBar()->addMenu(tr("查看(V)"));
    view->addAction(openAction);

    openAction = new QAction(QIcon(":/images/doc-open"),tr("帮助信息(H)"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("小组成员：陈姝琳 吴琳琳 何明杰"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    QMenu *help = menuBar()->addMenu(tr("帮助(H)"));
    help->addAction(openAction);
    statusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("Open"));
}

