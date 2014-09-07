#ifndef TAB_H
#define TAB_H

#include <QTabWidget>
#include <QLabel>
#include <QFile>
#include "mytabbar.h"
#include "cpustate.h"
#include "cputhread.h"
#include <QProgressBar>
class mytab: public QTabWidget
{
    Q_OBJECT

public:
    mytab(QWidget *parent = 0);
    ~mytab();
private:
    myTabBar      m_pTabBar;
};


#endif // TAB_H
