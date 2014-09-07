#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QWidget>
#include <QTabWidget>

class tablemodel : public QWidget
{
    Q_OBJECT

public:
    explicit tablemodel(QWidget *parent = 0);
    ~tablemodel();

};

#endif // TABLEMODEL_H
