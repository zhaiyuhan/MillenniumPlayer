#include "stdafx.h"
#include "StackedWidget.h"

#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QPixmap>

StackedWidget::StackedWidget(QWidget* parent)
    : QStackedWidget(parent)
{
    m_vertical = false;
    //setVerticalMode(true);
    m_speed = 500;
    m_now = 0;
    m_next = 0;
    m_wrap = false;
    m_pnow = QPoint(0, 0);
    m_active = false;
    m_animationtype = QEasingCurve::OutBack;  
}


StackedWidget::~StackedWidget() {
}

void StackedWidget::setVerticalMode(bool vertical) {
    m_vertical = vertical;
}

void StackedWidget::setSpeed(int speed) {
    m_speed = speed;
}

void StackedWidget::setAnimation(enum QEasingCurve::Type animationtype) {
    m_animationtype = animationtype;
}

void StackedWidget::setWrap(bool wrap) {
    m_wrap = wrap;
}

void StackedWidget::slideInNext() {
    int now = currentIndex();
    if (m_wrap || (now < count() - 1))
        /* Count is inherit from QStackedWidget */
        slideInIdx(now + 1);
}


void StackedWidget::slideInPrev() {
    int now = currentIndex();
    if (m_wrap || (now > 0))
        slideInIdx(now - 1);
}

void StackedWidget::slideInIdx(int idx, enum Direction direction) {
    //int idx, t_direction direction = AUTOMATIC;
    if (idx > count() - 1) {
        /* Here is an '=', indeed. */
        direction = m_vertical ? TOP2BOTTOM : RIGHT2LEFT;
        idx = idx % count();
    }
    else if (idx < 0) {
        direction = m_vertical ? BOTTOM2TOP : LEFT2RIGHT;
        idx = (idx + count()) % count();
    }
    slideInWgt(widget(idx), direction);
    /* widget() is a function inherited from QStackedWidget */
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
        /* Here is a '=', indeed. */
        directionhint = m_vertical ? TOP2BOTTOM : RIGHT2LEFT;
    }
    else {
        directionhint = m_vertical ? BOTTOM2TOP : LEFT2RIGHT;
    }
    if (direction == AUTOMATIC) {
        direction = directionhint;
    }
    /* NOW....calculate the shifts */
    int offsetx = frameRect().width();  /* Inherited from mother */
    int offsety = frameRect().height(); /* Inherited from mother */

    /* The following is important, to ensure that the new widget
       has correct geometry information when sliding in first time */
    widget(next)->setGeometry(0, 0, offsetx, offsety);

    if (direction == BOTTOM2TOP) {
        offsetx = 0;
        offsety = -offsety;
    }
    else if (direction == TOP2BOTTOM) {
        offsetx = 0;
        //offsety = offsety;
    }
    else if (direction == RIGHT2LEFT) {
        offsetx = -offsetx;
        offsety = 0;
    }
    else if (direction == LEFT2RIGHT) {
        //offsetx = offsetx;
        offsety = 0;
    }
    /* Re-position the next widget outside/aside of the display area */
    QPoint pnext = widget(next)->pos();
    QPoint pnow = widget(now)->pos();
    m_pnow = pnow;

    widget(next)->move(pnext.x() - offsetx, pnext.y() - offsety);
    /* Make it visible/show */
    widget(next)->show();
    widget(next)->raise();

    /* Animate both, the now and next widget to the side, using animation framework */
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

    QObject::connect(animgroup, SIGNAL(finished()), this, SLOT(animationDoneSlot()));
    m_next = next;
    m_now = now;
    m_active = true;
    animgroup->start();
}


void StackedWidget::animationDoneSlot(void) {
    /* When ready, call the QStackedWidget slot setCurrentIndex(int) */
    setCurrentIndex(m_next);  /* This function is inherit from QStackedWidget */
    /* Then hide the outshifted widget now, and  (may be done already implicitely by QStackedWidget) */
    widget(m_now)->hide();
    /* Then set the position of the outshifted widget now back to its original */
    widget(m_now)->move(m_pnow);
    /* So that the application could also still call the QStackedWidget original functions/slots for changings */
    //widget(m_now)->update();
    //setCurrentIndex(m_next);  /* This function is inherit from QStackedWidget */
    m_active = false;
    emit animationFinished();
}



