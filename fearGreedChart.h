#ifndef FEADGREEDCHART_H
#define FEADGREEDCHART_H

#include <QQuickPaintedItem>

class FearGreedChart : public QQuickPaintedItem
{
    Q_OBJECT

    // Feer
    Q_PROPERTY(QColor feerBarColor READ getFeerBarColor WRITE setFeerBarColor NOTIFY feerBarColorChanged)

    // Greed
    Q_PROPERTY(QColor greedBarColor READ getGreedBarColor WRITE setGreedBarColor NOTIFY greedBarColorChanged)

    // Common
    Q_PROPERTY(int dialWidth READ getDialWidth WRITE setDialWidth NOTIFY dialWidthChanged)
    Q_PROPERTY(Qt::PenCapStyle penStyle READ getPenStyle WRITE setPenStyle NOTIFY penStyleChanged)
    Q_PROPERTY(qreal startAngle READ getStartAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal spanAngle READ getSpanAngle WRITE setSpanAngle NOTIFY spanAngleChanged)
    Q_PROPERTY(QColor centerPinColor READ getCenterPinColor WRITE setCenterPinColor NOTIFY centerPinColorChanged)
    Q_PROPERTY(QColor centerInnerColor READ getCenterInnerColor WRITE setCenterInnerColor NOTIFY centerInnerColorChanged)
    Q_PROPERTY(QColor backgroundColor READ getBackGroundColor WRITE setBackGroundColor NOTIFY backgroundColorChanged)

public:
    FearGreedChart(QQuickItem *parent = 0);
    void paint(QPainter *painter);

    // Common
    void setCenterPinColor(QColor color);
    QColor getCenterPinColor() {return m_CenterPinColor;}
    void setCenterInnerColor(QColor color);
    QColor getCenterInnerColor() {return m_CenterInnerColor;}
    void setStartAngle(qreal angle);
    void setSpanAngle(qreal angle);
    qreal getStartAngle() {return m_StartAngle;}
    qreal getSpanAngle() {return m_SpanAngle;}
    void setPenStyle(Qt::PenCapStyle style);
    Qt::PenCapStyle getPenStyle() {return m_PenStyle;}
    void setDialWidth(qreal width);
    int getDialWidth() {return m_DialWidth;}
    void setBackGroundColor(QColor color);
    QColor getBackGroundColor() {return m_BackGroundColor;}

    // Feer Setter/Getter
    void setFeerBarColor(QColor color);
    QColor getFeerBarColor() {return m_FeerBarColor;}

    // Greed Setter/Getter
    void setGreedBarColor(QColor color);
    QColor getGreedBarColor() {return m_GreedBarColor;}

signals:
    // Feer Signal
    void startAngleChanged();
    void spanAngleChanged();
    void feerBarColorChanged();

    // Greed Signal
    void greedStartAngleChanged();
    void greedSpanAngleChanged();
    void greedBarColorChanged();

    // Common Signal
    void centerPinColorChanged();
    void centerInnerColorChanged();
    void penStyleChanged();
    void dialWidthChanged();
    void backgroundColorChanged();

private:
    // Feer member
    QColor m_FeerBarColor;

    // Greed member
    QColor m_GreedBarColor;

    // Common member
    qreal m_StartAngle;
    qreal m_SpanAngle;
    QColor m_CenterPinColor;
    QColor m_CenterInnerColor;
    QColor m_BackGroundColor;
    Qt::PenCapStyle m_PenStyle;
    int m_DialWidth;
};

#endif // FEADGREEDCHART_H
