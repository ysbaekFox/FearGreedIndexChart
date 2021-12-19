#ifndef FEADGREEDCHART_H
#define FEADGREEDCHART_H

#include <QQuickPaintedItem>

class FearGreedChart : public QQuickPaintedItem
{
    Q_OBJECT

    // Feer
    Q_PROPERTY(Qt::PenCapStyle feerPenStyle READ getFeerPenStyle WRITE setFeerPenStyle NOTIFY feerPenStyleChanged)
    Q_PROPERTY(int feerDialWidth READ getFeerDialWidth WRITE setFeerDialWidth NOTIFY feerDialWidthChanged)
    Q_PROPERTY(QColor feerBarColor READ getFeerBarColor WRITE setFeerBarColor NOTIFY feerBarColorChanged)

    // Greed
    Q_PROPERTY(Qt::PenCapStyle greedPenStyle READ getGreedPenStyle WRITE setGreedPenStyle NOTIFY greedPenStyleChanged)
    Q_PROPERTY(int greedDialWidth READ getGreedDialWidth WRITE setGreedDialWidth NOTIFY greedDialWidthChanged)
    Q_PROPERTY(QColor greedBarColor READ getGreedBarColor WRITE setGreedBarColor NOTIFY greedBarColorChanged)

    // Common
    Q_PROPERTY(qreal startAngle READ getStartAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal spanAngle READ getSpanAngle WRITE setSpanAngle NOTIFY spanAngleChanged)
    Q_PROPERTY(QColor centerPinColor READ getCenterPinColor WRITE setCenterPinColor NOTIFY centerPinColorChanged)
    Q_PROPERTY(QColor centerInnerColor READ getCenterInnerColor WRITE setCenterInnerColor NOTIFY centerInnerColorChanged)

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

    // Feer Setter/Getter
    void setFeerPenStyle(Qt::PenCapStyle style);
    void setFeerDialWidth(qreal width);
    void setFeerBarColor(QColor color);
    Qt::PenCapStyle getFeerPenStyle() {return m_FeerPenStyle;}
    int getFeerDialWidth() {return m_FeerDialWidth;}
    QColor getFeerBarColor() {return m_FeerBarColor;}

    // Greed Setter/Getter
    void setGreedPenStyle(Qt::PenCapStyle style);
    void setGreedDialWidth(qreal width);
    void setGreedBarColor(QColor color);
    Qt::PenCapStyle getGreedPenStyle() {return m_GreedPenStyle;}
    int getGreedDialWidth() {return m_GreedDialWidth;}
    QColor getGreedBarColor() {return m_GreedBarColor;}

signals:
    // Feer Signal
    void startAngleChanged();
    void spanAngleChanged();
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
    void centerInnerColorChanged();

private:
    // Feer member
    Qt::PenCapStyle m_FeerPenStyle;
    int m_FeerDialWidth;
    QColor m_FeerBarColor;

    // Greed member
    Qt::PenCapStyle m_GreedPenStyle;
    int m_GreedDialWidth;
    QColor m_GreedBarColor;

    // Common member
    qreal m_StartAngle;
    qreal m_SpanAngle;
    QColor m_CenterPinColor;
    QColor m_CenterInnerColor;
};

#endif // FEADGREEDCHART_H
