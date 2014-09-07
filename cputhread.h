#ifndef CPUTHREAD_H
#define CPUTHREAD_H

#include <QThread>
#include <QTimer>
#include <QProgressBar>
#include "qdebug.h"
#include "windows.h"


class CpuThread : public QThread
{
    Q_OBJECT
public:
    explicit CpuThread(QObject *parent = 0);
    int get_cpu_usage();
    void send();
    static CpuThread *app;
    void get_memory_usage();
protected:
    void run();
signals:
    void cpuget(int cpu);
    void memoryget(int percent);
private:
   FILETIME preidleTime;
   FILETIME prekernelTime;
   FILETIME preuserTime;
   FILETIME idleTime;
   FILETIME kernelTime;
   FILETIME userTime;
   MEMORYSTATUSEX statex;
};

__int64 CompareFileTime ( FILETIME time1, FILETIME time2 );


#endif // CPUTHREAD_H
