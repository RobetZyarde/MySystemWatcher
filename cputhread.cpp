#include "cputhread.h"

CpuThread *CpuThread::app = NULL;

CpuThread::CpuThread(QObject *parent): QThread(parent)
{
GetSystemTimes( &idleTime, &kernelTime, &userTime );
preidleTime = idleTime;
prekernelTime = kernelTime;
preuserTime = userTime;
if(!app)
   {
    app=this;
}
statex.dwLength = sizeof (statex);
GlobalMemoryStatusEx (&statex);
}

__int64 CompareFileTime ( FILETIME time1, FILETIME time2 )//转换为整数时间
{
       __int64 a = time1.dwHighDateTime << 32 | time1.dwLowDateTime ;
       __int64 b = time2.dwHighDateTime << 32 | time2.dwLowDateTime ;

       return   (b - a);
}

int CpuThread::get_cpu_usage()
{
    GetSystemTimes( &idleTime, &kernelTime, &userTime );
    __int64 idle = CompareFileTime( preidleTime,idleTime);
    __int64 kernel = CompareFileTime( prekernelTime, kernelTime);
    __int64 user = CompareFileTime(preuserTime, userTime);
    int cpu = (kernel +user - idle) *100/(kernel+user);
    int cpuidle = (idle) *100/(kernel+user);
     qDebug()<<"CPU利用率:" << cpu << "%" << "      CPU空闲率:"<<cpuidle << "%" <<endl;
     preidleTime = idleTime;
     prekernelTime = kernelTime;
     preuserTime = userTime ;
    return cpu;
}

void CpuThread::get_memory_usage()
{
    GlobalMemoryStatusEx (&statex);
}

void CpuThread::send(){
    emit cpuget(this->get_cpu_usage());
    qDebug()<<this->get_cpu_usage()<<endl;
}

void CpuThread::run() {
 //   QTimer *timer = new QTimer(this);
   // connect(timer, &QTimer::timeout,this,&CpuThread::send);
   // timer->start(500);
        while(true){
            emit cpuget(get_cpu_usage());
            get_memory_usage();
            emit memoryget(statex.dwMemoryLoad);
           QThread::msleep(500);
        }
}
