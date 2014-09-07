#include "cpustate.h"
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
    connect(CpuThread::app,&CpuThread::cpuget,ui->progressBar_2,&QProgressBar::setValue,Qt::QueuedConnection);
    connect(CpuThread::app,&CpuThread::cpuget,[](int a){qDebug()<<a<<endl;});
    connect(CpuThread::app,&CpuThread::memoryget,ui->progressBar_3,&QProgressBar::setValue,Qt::QueuedConnection);
    CpuScene *myscene = new CpuScene;
    MemoryScene *myscene_1 = new MemoryScene;
    ui->graphicsView->setScene(myscene);
    ui->graphicsView_2->setScene(myscene_1);
    ui->graphicsView->resize(100,60);
    ui->graphicsView_2->resize(100,60);
    QPixmap bg(10,10);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::black));
    p.setPen(Qt::darkGreen);
    p.drawRect(0,0,10,10);
    ui->graphicsView->setBackgroundBrush(bg);
    ui->graphicsView_2->setBackgroundBrush(bg);
    label1 *m_label1=new label1;
    label2 *m_label2=new label2;
    label3 *m_label3=new label3;
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(ui->progressBar_2,0,0);
    gridLayout->addWidget(ui->progressBar_3,2,0);
    gridLayout->addWidget(ui->label,1,0);
    gridLayout->addWidget(ui->label_2,3,0);
    gridLayout->addWidget(ui->graphicsView,0,1,1,3);
    gridLayout->addWidget(ui->graphicsView_2,2,1,1,3);
    gridLayout->addWidget(m_label1,6,0,1,2);
    gridLayout->addWidget(m_label2,6,2,1,2);
    gridLayout->addWidget(m_label3,7,0,1,2);
    this->setLayout(gridLayout);
}

CpuState::~CpuState()
{
    delete ui;
}


