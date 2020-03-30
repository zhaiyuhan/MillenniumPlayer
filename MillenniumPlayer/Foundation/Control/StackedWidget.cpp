#include "stdafx.h"
#include "StackedWidget.h"

StackedWidget::StackedWidget(QWidget* parent)
    : QStackedWidget(parent),
     m_vertical(false), m_wrap( false),
m_speed(500),
m_now(0), m_next(0),
m_pnow(QPoint(0, 0)),
m_active(false),
m_animationtype(QEasingCurve::OutBack)
{
}

StackedWidget::~StackedWidget() {
}


void StackedWidget::slideInNext() {
    int now = currentIndex();
    if (m_wrap || (now < count() - 1))
        slideInIdx(now + 1);
}


void StackedWidget::slideInPrev() {
    int now = currentIndex();
    if (m_wrap || (now > 0))
        slideInIdx(now - 1);
}

void StackedWidget::slideInIdx(int idx, enum Direction direction) {
    if (idx > count() - 1) {
        direction = m_vertical ? TopToBottom : RightToLeft;
        idx = idx % count();
    }
    else if (idx < 0) {
        direction = m_vertical ? BottomToTop : LeftToRight;
        idx = (idx + count()) % count();
    }
    slideInWgt(widget(idx), direction);
}


void StackedWidget::slideInWgt(QWidget* newwidget, enum Direction direction) {
    if (m_active) {
        return;
    } else {
        m_active = true;
    }
    enum Direction directionhint;
    int now = currentIndex(); 
    int next = indexOf(newwidget);
    if (now == next) {
        m_active = false;
        return;
    }
    else if (now < next) {
        directionhint = m_vertical ? TopToBottom : RightToLeft;
    }
    else {
        directionhint = m_vertical ? BottomToTop : LeftToRight;
    }
    if (direction == AUTOMATIC) {
        direction = directionhint;
    }

    int offsetx = frameRect().width();  
    int offsety = frameRect().height(); 

    widget(next)->setGeometry(0, 0, offsetx, offsety);

    if (direction == BottomToTop) {
        offsetx = 0;
        offsety = -offsety;
    }
    else if (direction == TopToBottom) {
        offsetx = 0;
    }
    else if (direction == RightToLeft) {
        offsetx = -offsetx;
        offsety = 0;
    }
    else if (direction == LeftToRight) {
        offsety = 0;
    }
   
    QPoint pnext = widget(next)->pos();
    QPoint pnow = widget(now)->pos();
    m_pnow = pnow;

    widget(next)->move(pnext.x() - offsetx, pnext.y() - offsety);
   
    widget(next)->show();
    widget(next)->raise();

  
    QPropertyAnimation* animnow = new QPropertyAnimation(widget(now), "pos");
    animnow->setDuration(m_speed);
    animnow->setEasingCurve(m_animationtype);
    animnow->setStartValue(QPoint(pnow.x(), pnow.y()));
    animnow->setEndValue(QPoint(offsetx + pnow.x(), offsety + pnow.y()));

    QPropertyAnimation* animnext = new QPropertyAnimation(widget(next), "pos");
    animnext->setDuration(m_speed);
    animnext->setEasingCurve(m_animationtype);
    animnext->setStartValue(QPoint(-offsetx + pnext.x(), offsety + pnext.y()));
    animnext->setEndValue(QPoint(pnext.x(), pnext.y()));

    QParallelAnimationGroup* animgroup = new QParallelAnimationGroup;
    animgroup->addAnimation(animnow);
    animgroup->addAnimation(animnext);

    connect(animgroup, &QAnimationGroup::finished, this, [=]() {
        animationDone();
    });
    m_next = next;
    m_now = now;
    m_active = true;
    animgroup->start();
}


void StackedWidget::animationDone(void) {
    
    setCurrentIndex(m_next); 
    widget(m_now)->hide();
    widget(m_now)->move(m_pnow);
    m_active = false;
    emit animationFinished();
}



