void on_progressBar_2_valueChanged(int value);
#ifndef CPUSTATE_H
#define CPUSTATE_H

#include <QWidget>
#include "windows.h"
#include "cputhread.h"
#include "cpuscene.h"
#include "memoryscene.h"
#include <QLayout>

namespace Ui {
class CpuState;
}

class CpuState : public QWidget
{
    Q_OBJECT

public:
    explicit CpuState(QWidget *parent = 0);
    ~CpuState();
private:
    Ui::CpuState *ui; 
};


#endif // CPUSTATE_H
