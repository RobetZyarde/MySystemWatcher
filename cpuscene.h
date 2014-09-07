#ifndef CPUSCENE_H
#define CPUSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPixmap>
#include <QBrush>

class CpuScene:public QGraphicsScene
{
        Q_OBJECT
public:
    CpuScene(QObject *parent = 0);
    QList<QGraphicsLineItem*> m_scaleLinesList;
    QList<qreal> y;
    QPen  m_waveDataPen;
    QPainter *m_painter;
    void setDefaultWaveDataPen();
    void refresh(int Cpu);
};

#endif // CPUSCENE_H
