#include <QPainter>
#include <QRect>

#include "fearGreedChart.h"

FearGreedChart::FearGreedChart(QQuickItem* parent)
    : QQuickPaintedItem(parent)
{

}

void FearGreedChart::paint(QPainter *painter)
{
    // https://doc.qt.io/qt-5/qtqml-tutorials-extending-qml-example.html
    QPen pen = painter->pen();
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
}
