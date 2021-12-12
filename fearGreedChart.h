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

    // Greed
    Q_PROPERTY(qreal greedStartAngle READ getGreedStartAngle WRITE setGreedStartAngle NOTIFY greedStartAngleChanged)
    Q_PROPERTY(qreal greedSpanAngle READ getGreedSpanAngle WRITE setGreedSpanAngle NOTIFY greedSpanAngleChanged)
    Q_PROPERTY(Qt::PenCapStyle greedPenStyle READ getGreedPenStyle WRITE setGreedPenStyle NOTIFY greedPenStyleChanged)
    Q_PROPERTY(int greedDialWidth READ getGreedDialWidth WRITE setGreedDialWidth NOTIFY greedDialWidthChanged)

    // Common
    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)

public:
    FearGreedChart(QQuickItem *parent = 0);
    void paint(QPainter *painter);

    // Common
    void setBackgroundColor(QColor color);
    QColor getBackgroundColor() {return m_BackgroundColor;}

    // Feer Setter/Getter
    void setFeerStartAngle(qreal angle);
    void setFeerSpanAngle(qreal angle);
    void setFeerPenStyle(Qt::PenCapStyle style);
    void setFeerDialWidth(qreal width);
    qreal getFeerStartAngle() {return m_FeerStartAngle;}
    qreal getFeerSpanAngle() {return m_FeerSpanAngle;}
    Qt::PenCapStyle getFeerPenStyle() {return m_FeerPenStyle;}
    int getFeerDialWidth() {return m_FeerDialWidth;}

    // Greed Setter/Getter
    void setGreedStartAngle(qreal angle);
    void setGreedSpanAngle(qreal angle);
    void setGreedPenStyle(Qt::PenCapStyle style);
    void setGreedDialWidth(qreal width);
    qreal getGreedStartAngle() {return m_GreedStartAngle;}
    qreal getGreedSpanAngle() {return m_GreedSpanAngle;}
    Qt::PenCapStyle getGreedPenStyle() {return m_GreedPenStyle;}
    int getGreedDialWidth() {return m_GreedDialWidth;}

signals:
    // Feer Signal
    void feerStartAngleChanged();
    void feerSpanAngleChanged();
    void feerPenStyleChanged();
    void feerDialWidthChanged();

    // Greed Signal
    void greedStartAngleChanged();
    void greedSpanAngleChanged();
    void greedPenStyleChanged();
    void greedDialWidthChanged();

    // Common Signal
    void backgroundColorChanged();

private:
    // Feer member
    qreal m_FeerStartAngle;
    qreal m_FeerSpanAngle;
    Qt::PenCapStyle m_FeerPenStyle;
    int m_FeerDialWidth;

    // Greed member
    qreal m_GreedStartAngle;
    qreal m_GreedSpanAngle;
    Qt::PenCapStyle m_GreedPenStyle;
    int m_GreedDialWidth;

    // Common member
    QColor m_BackgroundColor;
};

#endif // FEADGREEDCHART_H
