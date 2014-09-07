#include "cpuscene.h"
#include "cputhread.h"
#include "qdebug.h"

CpuScene::CpuScene(QObject *parent):QGraphicsScene(parent)
{
     this->setSceneRect(0, 0, 80, 80);
    setDefaultWaveDataPen();
    for(int i=0;i<100;i++)
   {
            m_scaleLinesList.append(this->addLine(2*i,100,2*(i+1),100,m_waveDataPen));
           y.append(100);
   }
    for(int i=0;i<100;i++)
   {
            y[i]=100;
   }

   connect(CpuThread::app,&CpuThread::cpuget,this,&CpuScene::refresh,Qt::QueuedConnection);
}

void CpuScene::setDefaultWaveDataPen()
{
           m_waveDataPen.setColor(Qt::green);
           m_waveDataPen.setStyle(Qt::SolidLine);
           m_waveDataPen.setWidthF(1);
}

void CpuScene::refresh(int cpu)
{
    for(int i=99;i>0;i--)
   {
        y[i]=y[i-1];
   }
    for(int i=0;i<99;i++)
   {
        m_scaleLinesList[i]->setLine(2*i,y[i],2*(i+1),y[i+1]);
   }
    y[0]=100-cpu;


}
