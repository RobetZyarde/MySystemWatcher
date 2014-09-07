#ifndef MYTABBAR_H
#define MYTABBAR_H

#include <QTabBar>

class myTabBar:public QTabBar
{
    Q_OBJECT
public:
    myTabBar(QWidget *parent = 0);
    ~myTabBar();
};
#endif // MYTABBAR_H
