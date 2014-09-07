#include "memoryscene.h"
#include "cputhread.h"
#include "qdebug.h"

MemoryScene::MemoryScene(QObject *parent):QGraphicsScene(parent)
{
     this->setSceneRect(0, 0, 125, 100);
    setDefaultWaveDataPen();
    for(int i=0;i<200;i++)
   {
            m_scaleLinesList.append(this->addLine(i,100,(i+1),100,m_waveDataPen));
           y.append(100);
   }
    for(int i=0;i<200;i++)
   {
            y[i]=100;
   }

   connect(CpuThread::app,&CpuThread::memoryget,this,&MemoryScene::refresh,Qt::QueuedConnection);
}

void MemoryScene::setDefaultWaveDataPen()
{
           m_waveDataPen.setColor(Qt::blue);
           m_waveDataPen.setStyle(Qt::SolidLine);
           m_waveDataPen.setWidthF(3);
}

void MemoryScene::refresh(int Memory)
{
    for(int i=199;i>0;i--)
   {
        y[i]=y[i-1];
   }
    for(int i=0;i<199;i++)
   {
        m_scaleLinesList[i]->setLine(i,y[i],(i+1),y[i+1]);
   }
    y[0]=100-Memory;


}
