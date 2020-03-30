#pragma once

#include <QStackedWidget>
#include <QPaintEvent> 
#include <QPropertyAnimation>

#include <QStackedWidget>
#include <QPropertyAnimation>

enum Direction {
    LEFT2RIGHT,
    RIGHT2LEFT,
    TOP2BOTTOM,
    BOTTOM2TOP,
    AUTOMATIC
};

class StackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit StackedWidget(QWidget* parent = nullptr);
    ~StackedWidget();

    void setSpeed(int speed);  
    void setAnimation(enum QEasingCurve::Type animationtype); 
    void setVerticalMode(bool vertical = true);
    void setWrap(bool wrap); 


    void slideInNext();
    void slideInPrev();
    void slideInIdx(int idx, enum Direction direction = AUTOMATIC);


signals:
    /* this is used for internal purposes in the class engine */
    void animationFinished(void);

protected slots:
    /* this is used for internal purposes in the class engine */
    void animationDoneSlot(void);

protected:
    /* this is used for internal purposes in the class engine */
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

    QList<QWidget*> blockedPageList;
};
