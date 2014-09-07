#ifndef MEMORYSCENE_H
#define MEMORYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPixmap>
#include <QBrush>

class MemoryScene:public QGraphicsScene
{
        Q_OBJECT
public:
    MemoryScene(QObject *parent = 0);
    QList<QGraphicsLineItem*> m_scaleLinesList;
    QList<qreal> y;
    QPen  m_waveDataPen;
    QPainter *m_painter;
    void setDefaultWaveDataPen();
    void refresh(int Memory);
};

#endif // CPUSCENE_H
