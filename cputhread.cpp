#include "cputhread.h"
#include "string.h"
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
pe32.dwSize = sizeof(pe32);
statex.dwLength = sizeof (statex);
GlobalMemoryStatusEx (&statex);
get_progress_information();
memset(&mysystem1, 0, sizeof(mysystem1));
GetPerformanceInfo(&mysystem1,sizeof(PERFORMANCE_INFORMATION));
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

void CpuThread::get_system_information()
{
     GetPerformanceInfo(&mysystem1,sizeof(PERFORMANCE_INFORMATION));
}
void CpuThread::get_progress_information()
{
    threadnumber = 0;
    progressnumber = 0;
    handlernumber = 0;
    handle = 0;
    HANDLE temp;
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if( !Process32First(hProcessSnap,&pe32) )
            return ;
    do
        {
           threadnumber += pe32.cntThreads;
           progressnumber++;
           temp = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
           GetProcessHandleCount(temp,&handle);
           CloseHandle(temp);
           handlernumber += handle;
           if( Process32Next(hProcessSnap,&pe32)==FALSE )
               break;
        } while(1);
    CloseHandle(hProcessSnap);
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
            get_system_information();
            emit memoryget(statex.dwMemoryLoad);
            emit phymemoryget(statex.ullTotalPhys/(1024*1024));
            emit available(statex.ullAvailPhys/(1024*1024));
            emit free((statex.ullTotalVirtual-statex.ullAvailVirtual)/(1024*1024));
            emit cache((mysystem1.SystemCache*(mysystem1.PageSize)+(statex.ullTotalVirtual-statex.ullAvailVirtual))/(1024*1024));
            get_progress_information();
            emit thread(mysystem1.ThreadCount);
            emit process(mysystem1.ProcessCount);
            emit handler(mysystem1.HandleCount);
            emit handon((statex.ullTotalPageFile-statex.ullAvailPageFile)/(1024*1024),statex.ullTotalPageFile/(1024*1024));
            emit paged(mysystem1.KernelPaged*(mysystem1.PageSize)/(1024*1024));
            emit nonpaged(mysystem1.KernelNonpaged*(mysystem1.PageSize)/(1024*1024));
           QThread::msleep(500);
        }
}
