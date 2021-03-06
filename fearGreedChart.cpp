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
      m_DialWidth(20),
      m_PenStyle(Qt::PenCapStyle::SquareCap),
      m_FeerBarColor(Qt::transparent),
      m_GreedBarColor(Qt::transparent),
      m_CenterPinColor(Qt::transparent),
      m_BackGroundColor(Qt::transparent),
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

    qreal xCenterPoint = x() + ( width() * 0.5);
    qreal yCenterPoint = y() + ( height() * 0.5 );

    qDebug() << "xCenterPoint : " << xCenterPoint;
    qDebug() << "yCenterPoint : " << yCenterPoint;

    QPen pen = painter->pen();
    pen.setCapStyle(m_PenStyle);
    pen.setWidth(m_DialWidth);
    painter->setPen(pen);

    QRect drawingRect;
    drawingRect.setX(0);
    drawingRect.setY(0);
    drawingRect.setWidth(width());
    drawingRect.setHeight(height());

    painter->setBrush(m_BackGroundColor);
    painter->setPen(m_BackGroundColor);
    painter->drawChord( xCenterPoint + (width() * 0.08), yCenterPoint + (height() * 0.08),
                      width() - (width() * 0.16), height() - (height() * 0.16), -20 * 16, 220 * 16);

    QConicalGradient gradient;
    gradient.setAngle(m_StartAngle);
    gradient.setCenter(drawingRect.center());
    gradient.setColorAt(0, m_GreedBarColor);
    gradient.setColorAt(0.25, "grey");
    gradient.setColorAt(0.5, m_FeerBarColor);
    gradient.setColorAt(1, m_GreedBarColor);

    qreal reduceRate = 70;
    xCenterPoint += reduceRate;
    yCenterPoint += reduceRate;

    qreal radius = size * 0.5 - reduceRate;
    qDebug() << "radius : " << radius;

    qreal reducedWidth = width() - (reduceRate * 2);
    qreal reducedHeight = height() - (reduceRate * 2);

    painter->setBrush(gradient);
    painter->drawPie( xCenterPoint, yCenterPoint,
                      reducedWidth, reducedHeight , getStartAngle() * 16, getSpanAngle() * 16);

    int rectCenterX = width() / 2;
    int rectCenterY = height() / 2;

    for(int i = 0; i < 5; i++)
    {
        painter->save();
        painter->translate(rectCenterX, rectCenterY);
        painter->rotate(10 - (i * 50));
        pen.setColor(m_CenterInnerColor);
        pen.setWidth(1);
        painter->drawLine(0, 0, 0 + radius + 10, 0);
        painter->restore();
    }

    painter->setBrush(m_BackGroundColor);
    painter->setPen(m_BackGroundColor);
    painter->drawPie( xCenterPoint + m_DialWidth, yCenterPoint + m_DialWidth,
                      reducedWidth - (m_DialWidth * 2), reducedHeight - (m_DialWidth * 2), getStartAngle() * 16, getSpanAngle() * 16);

    painter->setBrush(m_CenterPinColor);
    painter->setPen(m_CenterPinColor);
    painter->drawPie( xCenterPoint + reducedWidth * 0.46, yCenterPoint + reducedHeight * 0.46,
                      reducedWidth - (reducedWidth * 0.92), reducedHeight - (reducedHeight * 0.92), 0 * 16, 360 * 16);

    painter->setBrush(m_CenterInnerColor);
    painter->setPen(m_CenterInnerColor);
    painter->drawPie( xCenterPoint + reducedWidth * 0.48, yCenterPoint + reducedHeight * 0.48,
                      reducedWidth - (reducedWidth * 0.96), reducedHeight - (reducedHeight * 0.96), 0 * 16, 360 * 16);
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

void FearGreedChart::setPenStyle(Qt::PenCapStyle style)
{
    if(m_PenStyle == style)
        return;
    m_PenStyle = style;
    emit penStyleChanged();
}

void FearGreedChart::setDialWidth(qreal width)
{
    if(m_DialWidth == width)
        return;
    m_DialWidth = width;
    emit dialWidthChanged();
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

void FearGreedChart::setBackGroundColor(QColor color)
{
    if(m_BackGroundColor == color)
        return;
    m_BackGroundColor = color;
    emit backgroundColorChanged();
}
