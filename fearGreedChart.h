#ifndef FEADGREEDCHART_H
#define FEADGREEDCHART_H

#include <QQuickPaintedItem>

class FearGreedChart : public QQuickPaintedItem
{
    Q_OBJECT

    // Feer
    Q_PROPERTY(qreal feerStartAngle READ getFeerStartAngle WRITE setFeerStartAngle NOTIFY feerStartAngleChanged)
    Q_PROPERTY(qreal feerSpanAngle READ getFeerSpanAngle WRITE setFeerSpanAngle NOTIFY feerSpanAngleChanged)
    Q_PROPERTY(Qt::PenCapStyle feerPenStyle READ getFeerPenStyle WRITE setFeerPenStyle NOTIFY feerPenStyleChanged)
    Q_PROPERTY(int feerDialWidth READ getFeerDialWidth WRITE setFeerDialWidth NOTIFY feerDialWidthChanged)
    Q_PROPERTY(QColor feerBarColor READ getFeerBarColor WRITE setFeerBarColor NOTIFY feerBarColorChanged)

    // Greed
    Q_PROPERTY(qreal greedStartAngle READ getGreedStartAngle WRITE setGreedStartAngle NOTIFY greedStartAngleChanged)
    Q_PROPERTY(qreal greedSpanAngle READ getGreedSpanAngle WRITE setGreedSpanAngle NOTIFY greedSpanAngleChanged)
    Q_PROPERTY(Qt::PenCapStyle greedPenStyle READ getGreedPenStyle WRITE setGreedPenStyle NOTIFY greedPenStyleChanged)
    Q_PROPERTY(int greedDialWidth READ getGreedDialWidth WRITE setGreedDialWidth NOTIFY greedDialWidthChanged)
    Q_PROPERTY(QColor greedBarColor READ getGreedBarColor WRITE setGreedBarColor NOTIFY greedBarColorChanged)

    // Common
    Q_PROPERTY(QColor centerPinColor READ getCenterPinColor WRITE setCenterPinColor NOTIFY centerPinColorChanged)

public:
    FearGreedChart(QQuickItem *parent = 0);
    void paint(QPainter *painter);

    // Common
    void setCenterPinColor(QColor color);
    QColor getCenterPinColor() {return m_CenterPinColor;}

    // Feer Setter/Getter
    void setFeerStartAngle(qreal angle);
    void setFeerSpanAngle(qreal angle);
    void setFeerPenStyle(Qt::PenCapStyle style);
    void setFeerDialWidth(qreal width);
    void setFeerBarColor(QColor color);
    qreal getFeerStartAngle() {return m_FeerStartAngle;}
    qreal getFeerSpanAngle() {return m_FeerSpanAngle;}
    Qt::PenCapStyle getFeerPenStyle() {return m_FeerPenStyle;}
    int getFeerDialWidth() {return m_FeerDialWidth;}
    QColor getFeerBarColor() {return m_FeerBarColor;}

    // Greed Setter/Getter
    void setGreedStartAngle(qreal angle);
    void setGreedSpanAngle(qreal angle);
    void setGreedPenStyle(Qt::PenCapStyle style);
    void setGreedDialWidth(qreal width);
    void setGreedBarColor(QColor color);
    qreal getGreedStartAngle() {return m_GreedStartAngle;}
    qreal getGreedSpanAngle() {return m_GreedSpanAngle;}
    Qt::PenCapStyle getGreedPenStyle() {return m_GreedPenStyle;}
    int getGreedDialWidth() {return m_GreedDialWidth;}
    QColor getGreedBarColor() {return m_GreedBarColor;}

signals:
    // Feer Signal
    void feerStartAngleChanged();
    void feerSpanAngleChanged();
    void feerPenStyleChanged();
    void feerDialWidthChanged();
    void feerBarColorChanged();

    // Greed Signal
    void greedStartAngleChanged();
    void greedSpanAngleChanged();
    void greedPenStyleChanged();
    void greedDialWidthChanged();
    void greedBarColorChanged();

    // Common Signal
    void centerPinColorChanged();

private:
    // Feer member
    qreal m_FeerStartAngle;
    qreal m_FeerSpanAngle;
    Qt::PenCapStyle m_FeerPenStyle;
    int m_FeerDialWidth;
    QColor m_FeerBarColor;

    // Greed member
    qreal m_GreedStartAngle;
    qreal m_GreedSpanAngle;
    Qt::PenCapStyle m_GreedPenStyle;
    int m_GreedDialWidth;
    QColor m_GreedBarColor;

    // Common member
    QColor m_CenterPinColor;
};

#endif // FEADGREEDCHART_H
