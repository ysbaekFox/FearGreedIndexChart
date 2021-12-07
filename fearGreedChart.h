#ifndef FEADGREEDCHART_H
#define FEADGREEDCHART_H

#include <QQuickPaintedItem>

class FearGreedChart : public QQuickPaintedItem
{
    Q_OBJECT


public:
    FearGreedChart(QQuickItem *parent = 0);
    void paint(QPainter *painter);
};

#endif // FEADGREEDCHART_H
