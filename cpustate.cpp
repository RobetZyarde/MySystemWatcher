﻿#include "cpustate.h"
#include "ui_cpustate.h"
#include "qdebug.h"
#include "label1.h"
#include "label2.h"
#include "label3.h"

CpuState::CpuState(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CpuState)
{
    ui->setupUi(this);
    label1 *m_label1=new label1;
    label2 *m_label2=new label2;
    label3 *m_label3=new label3;
    connect(CpuThread::app,&CpuThread::cpuget,ui->progressBar_2,&QProgressBar::setValue,Qt::QueuedConnection);
    connect(CpuThread::app,&CpuThread::memoryget,ui->progressBar_3,&QProgressBar::setValue,Qt::QueuedConnection);
    connect(CpuThread::app,&CpuThread::phymemoryget,m_label1,&label1::setALL);
    connect(CpuThread::app,&CpuThread::available,m_label1,&label1::setavailable);
    connect(CpuThread::app,&CpuThread::cache,m_label1,&label1::setcache);
    connect(CpuThread::app,&CpuThread::free,m_label1,&label1::setfree);
    connect(CpuThread::app,&CpuThread::thread,m_label2,&label2::setline2);
    connect(CpuThread::app,&CpuThread::process,m_label2,&label2::setprogress);
    connect(CpuThread::app,&CpuThread::handler,m_label2,&label2::sethandle);
    connect(CpuThread::app,&CpuThread::handon,m_label2,&label2::sethandon);
    connect(CpuThread::app,&CpuThread::paged,m_label3,&label3::setnumber);
    connect(CpuThread::app,&CpuThread::nonpaged,m_label3,&label3::setopnumber);
    CpuScene *myscene = new CpuScene;
    MemoryScene *myscene_1 = new MemoryScene;
    ui->graphicsView->setScene(myscene);
    ui->graphicsView_2->setScene(myscene_1);
    QPixmap bg(10,10);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::black));
    p.setPen(Qt::darkGreen);
    p.drawRect(0,0,10,10);
    ui->graphicsView->setBackgroundBrush(bg);
    ui->graphicsView_2->setBackgroundBrush(bg);
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
    gridLayout->addWidget(ui->label,0,0);
    gridLayout->addWidget(ui->label_2,2,0);
    gridLayout->addWidget(ui->progressBar_2,1,0);
    gridLayout->addWidget(ui->progressBar_3,3,0);
    gridLayout->addWidget(ui->graphicsView,0,1,2,3);
    gridLayout->addWidget(ui->graphicsView_2,2,1,2,3);
    gridLayout->addWidget(m_label1,6,0,1,2);
    gridLayout->addWidget(m_label2,6,2,1,2);
    gridLayout->addWidget(m_label3,7,0,1,2);
    ui->progressBar_2->setAlignment(Qt::AlignHCenter);
    ui->progressBar_2->setAlignment(Qt::AlignVCenter);
    ui->progressBar_3->setAlignment(Qt::AlignHCenter);
    ui->progressBar_3->setAlignment(Qt::AlignVCenter);
    this->setLayout(gridLayout);
    gridLayout->setAlignment(ui->progressBar_2,Qt::AlignHCenter);
    gridLayout->setAlignment(ui->progressBar_3,Qt::AlignHCenter);
    gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    ui->graphicsView->resize(100,60);
     ui->graphicsView_2->resize(100,60);
     ui->progressBar_2->setTextVisible(false);
     ui->progressBar_3->setTextVisible(false);
}

CpuState::~CpuState()
{
    delete ui;
}


