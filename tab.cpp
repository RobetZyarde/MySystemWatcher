#include "tab.h"


mytab::mytab(QWidget *parent) :
    QTabWidget(parent)
{
    this->setTabBar(&m_pTabBar);
    QFile  qss(":/qss/mytab.qss");
    qss.open(QFile::ReadOnly);
    this->setStyleSheet(qss.readAll());
    this->addTab(new QLabel, QString::fromLocal8Bit("进程"));
    this->addTab(new CpuState, QString::fromLocal8Bit("性能"));

}

mytab::~mytab()
{

}

