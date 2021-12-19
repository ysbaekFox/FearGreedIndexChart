#include <QPainter>
#include <QRect>

#include <Qt>
#include <QMessageLogger>

#include <QtMath>

#include "fearGreedChart.h"

FearGreedChart::FearGreedChart(QQuickItem* parent)
    : QQuickPaintedItem(parent),
      m_StartAngle(0),
      m_SpanAngle(0),
      m_FeerDialWidth(1),
      m_GreedDialWidth(1),
      m_FeerPenStyle(Qt::PenCapStyle::SquareCap),
      m_GreedPenStyle(Qt::PenCapStyle::SquareCap),
      m_FeerBarColor(Qt::transparent),
      m_GreedBarColor(Qt::transparent),
      m_CenterPinColor(Qt::transparent),
      m_CenterInnerColor(Qt::transparent)
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

    QPen pen = painter->pen();
    pen.setCapStyle(m_FeerPenStyle);
    pen.setWidth(m_FeerDialWidth);
    painter->setPen(pen);

    QRect drawingRect;
    drawingRect.setX(0);
    drawingRect.setY(0);
    drawingRect.setWidth(width());
    drawingRect.setHeight(height());

    QConicalGradient gradient;
    gradient.setAngle(-10);
    gradient.setCenter(drawingRect.center());
    gradient.setColorAt(0, m_GreedBarColor);
    gradient.setColorAt(0.25, "grey");
    gradient.setColorAt(0.5, m_FeerBarColor);
    gradient.setColorAt(1, m_GreedBarColor);

    painter->setBrush(gradient);
    painter->setPen(Qt::transparent);
    painter->drawPie( 0, 0, width(), height() , getStartAngle() * 16, getSpanAngle() * 16);

    QColor innerColor;
    innerColor.setNamedColor("white");
    painter->setBrush(innerColor);
    painter->setPen(innerColor);
    painter->drawPie( 30, 30, width() - 60, height() - 60, getStartAngle() * 16, getSpanAngle() * 16);

    painter->setBrush(m_CenterPinColor);
    painter->setPen(m_CenterPinColor);
    painter->drawPie( 230, 230, width() - 460, height() - 460, 0 * 16, 360 * 16);

    painter->setBrush(innerColor);
    painter->setPen(innerColor);
    painter->drawPie( 240, 240, width() - 480, height() - 480, 0 * 16, 360 * 16);
}

void FearGreedChart::setStartAngle(qreal angle)
{
    if(m_StartAngle == angle)
        return;
    m_StartAngle = angle;
    emit startAngleChanged();
}

void FearGreedChart::setSpanAngle(qreal angle)
{
    if(m_SpanAngle == angle)
        return;
    m_SpanAngle = angle;
    emit spanAngleChanged();
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

void FearGreedChart::setCenterInnerColor(QColor color)
{
    if(m_CenterInnerColor == color)
        return;
    m_CenterInnerColor = color;
    emit centerInnerColorChanged();
}
