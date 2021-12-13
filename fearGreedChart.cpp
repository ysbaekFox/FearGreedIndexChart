#include <QPainter>
#include <QRect>

#include <Qt>
#include <QMessageLogger>

#include <QtMath>

#include "fearGreedChart.h"

FearGreedChart::FearGreedChart(QQuickItem* parent)
    : QQuickPaintedItem(parent),
      m_FeerStartAngle(0),
      m_FeerSpanAngle(0),
      m_GreedStartAngle(0),
      m_GreedSpanAngle(0),
      m_FeerDialWidth(1),
      m_GreedDialWidth(1),
      m_FeerPenStyle(Qt::PenCapStyle::SquareCap),
      m_GreedPenStyle(Qt::PenCapStyle::SquareCap),
      m_FeerBarColor(Qt::transparent),
      m_GreedBarColor(Qt::transparent),
      m_CenterPinColor(Qt::transparent)
{

}

void FearGreedChart::paint(QPainter *painter)
{
    qDebug() << "x : " << x();
    qDebug() << "y : " << y();
    qDebug() << "width : " << width();
    qDebug() << "height : " << height();

    qreal size = qMin(this->width(), this->height());
    setWidth(size), setHeight(size);
    painter->setRenderHints(QPainter::Antialiasing, true);

    // Common
    QPen pen = painter->pen();
    pen.setCapStyle(m_FeerPenStyle);
    pen.setWidth(m_FeerDialWidth);
    painter->setPen(pen);

    // Feer
    painter->setBrush(m_FeerBarColor);
    painter->setPen(m_FeerBarColor);
    painter->drawPie( x() + (size*0.5), y() + (size*0.5), width(), height() , getFeerStartAngle() * 16, getFeerSpanAngle() * 16);

    QColor innerColor;
    innerColor.setNamedColor("white");
    painter->setBrush(innerColor);
    painter->setPen(innerColor);
    painter->drawPie( x() + (size*0.5) + 30, y() + (size*0.5) + 30, width() - 60, height() - 60, getFeerStartAngle() * 16, getFeerSpanAngle() * 16);

    // Greed
    painter->setBrush(m_GreedBarColor);
    painter->setPen(m_GreedBarColor);
    painter->drawPie( x() + (size*0.5), y() + (size*0.5), width(), height() , getGreedStartAngle() * 16, getGreedSpanAngle() * 16);

    innerColor.setNamedColor("white");
    painter->setBrush(innerColor);
    painter->setPen(innerColor);
    painter->drawPie( x() + (size*0.5) + 30, y() + (size*0.5) + 30, width() - 60, height() - 60, getGreedStartAngle() * 16, getGreedSpanAngle() * 16);

    painter->setBrush(m_CenterPinColor);
    painter->setPen(m_CenterPinColor);
    painter->drawPie( x() + (size*0.5) + 230, y() + (size*0.5) + 230, width() - 460, height() - 460, 0 * 16, 360 * 16);

    painter->setBrush(innerColor);
    painter->setPen(innerColor);
    painter->drawPie( x() + (size*0.5) + 240, y() + (size*0.5) + 240, width() - 480, height() - 480, 0 * 16, 360 * 16);
}

void FearGreedChart::setFeerStartAngle(qreal angle)
{
    if(m_FeerStartAngle == angle)
        return;
    m_FeerStartAngle = angle;
    emit feerStartAngleChanged();
}

void FearGreedChart::setFeerSpanAngle(qreal angle)
{
    if(m_FeerSpanAngle == angle)
        return;
    m_FeerSpanAngle = angle;
    emit feerSpanAngleChanged();
}

void FearGreedChart::setFeerPenStyle(Qt::PenCapStyle style)
{
    if(m_FeerPenStyle == style)
        return;
    m_FeerPenStyle = style;
    emit feerPenStyleChanged();
}

void FearGreedChart::setFeerDialWidth(qreal width)
{
    if(m_FeerDialWidth == width)
        return;
    m_FeerDialWidth = width;
    emit feerDialWidthChanged();
}

void FearGreedChart::setGreedStartAngle(qreal angle)
{
    if(m_GreedStartAngle == angle)
        return;
    m_GreedStartAngle = angle;
    emit greedStartAngleChanged();
}

void FearGreedChart::setGreedSpanAngle(qreal angle)
{
    if(m_GreedSpanAngle == angle)
        return;
    m_GreedSpanAngle = angle;
    emit greedSpanAngleChanged();
}

void FearGreedChart::setGreedPenStyle(Qt::PenCapStyle style)
{
    if(m_GreedPenStyle == style)
        return;
    m_GreedPenStyle = style;
    emit greedPenStyleChanged();
}

void FearGreedChart::setGreedDialWidth(qreal width)
{
    if(m_GreedDialWidth == width)
        return;
    m_GreedDialWidth = width;
    emit greedDialWidthChanged();
}

void FearGreedChart::setCenterPinColor(QColor color)
{
    if(m_CenterPinColor == color)
        return;
    m_CenterPinColor = color;
    emit centerPinColorChanged();
}

void FearGreedChart::setFeerBarColor(QColor color)
{
    if(m_FeerBarColor == color)
        return;
    m_FeerBarColor = color;
    emit feerBarColorChanged();
}

void FearGreedChart::setGreedBarColor(QColor color)
{
    if(m_GreedBarColor == color)
        return;
    m_GreedBarColor = color;
    emit greedBarColorChanged();
}
