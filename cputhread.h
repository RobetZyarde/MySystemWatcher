#ifndef CPUTHREAD_H
#define CPUTHREAD_H

#include <QThread>
#include <QTimer>
#include <QProgressBar>
#include "qdebug.h"
#include "windows.h"
#include <tlhelp32.h>
//#include <winternl.h>
#include "psapi.h"

//#pragma comment (lib,"ntdll.lib")
//#pragma comment (lib,"psapi.lib")


class CpuThread : public QThread
{
    Q_OBJECT
public:
    explicit CpuThread(QObject *parent = 0);
    int get_cpu_usage();
    void send();
    static CpuThread *app;
    void get_memory_usage();
    void get_progress_information();
    void get_system_information();
protected:
    void run();
signals:
    void cpuget(int cpu);
    void memoryget(int percent);
    void phymemoryget(int total);
    void available(int total);
    void cache(int total);
    void free(int total);
    void process(int total);
    void thread(int total);
    void handler(int total);
    void handon(int total1,int total2);
    void paged(int total);
    void nonpaged(int total);
    void memory_Q(QString b);
    void cpu_Q(QString a);
    void process_Q(QString c);
private:
   FILETIME preidleTime;
   FILETIME prekernelTime;
   FILETIME preuserTime;
   FILETIME idleTime;
   FILETIME kernelTime;
   FILETIME userTime;
   MEMORYSTATUSEX statex;
   int threadnumber;
   int progressnumber;
   int handlernumber;
   PROCESSENTRY32 pe32;
   HANDLE hProcessSnap;
   DWORD handle;
   PERFORMANCE_INFORMATION mysystem1;
};

__int64 CompareFileTime ( FILETIME time1, FILETIME time2 );


#endif // CPUTHREAD_H
