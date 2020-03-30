#pragma once

#include <QStackedWidget>
#include <QPropertyAnimation>



enum Direction {
    LeftToRight,
    RightToLeft,
    TopToBottom,
    BottomToTop,
    AUTOMATIC
};

enum DirectionMode
{
    Vertical,
    Wrap
};

class StackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit StackedWidget(QWidget* parent = nullptr);
    ~StackedWidget();

    void setSpeed(int speed)
    {
        m_speed = speed;
    }
    void setAnimation(enum QEasingCurve::Type animationtype)
    {
        m_animationtype = animationtype;
    }
    void setDirectonMode(DirectionMode directonmode)
    {
        switch (directonmode)
        {
        case Vertical:
            m_vertical = true;
            break;
        case Wrap:
            m_wrap = true;
            break;
        default:
            m_vertical = true;
            break;
        }
    }

    void slideInNext();
    void slideInPrev();
    void slideInIdx(int idx, enum Direction direction = AUTOMATIC);


signals:
    void animationFinished();

protected:
    void animationDone();
    void slideInWgt(QWidget* widget, enum Direction direction = AUTOMATIC);
 
private:
    int m_speed;
    enum QEasingCurve::Type m_animationtype;

    bool m_vertical;
    int m_now;
    int m_next;
    bool m_wrap;
    QPoint m_pnow;
    bool m_active;
};
