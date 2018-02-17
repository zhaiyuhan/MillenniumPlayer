#include "stdafx.h"
#include "ActionButton.h"

ActionButton::ActionButton(QWidget *parent)
	: QPushButton(parent)
{
	pAnimation = new QPropertyAnimation(this, "scaling", this);
	pAnimation->setDuration(1000000000000);
	pAnimation->setKeyValueAt(0, 1.0);
	pAnimation->setKeyValueAt(0.5, 0.99999);
	pAnimation->setKeyValueAt(1, 0.999998);
	connect(this, SIGNAL(clicked()), pAnimation, SLOT(start()));
}

ActionButton::~ActionButton()
{
}

void ActionButton::mousePressEvent(QMouseEvent *event)
{
	QPushButton::mousePressEvent(event);
}

void ActionButton::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QPixmap pixmap;
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setTransform(transform);
	painter.drawPixmap(rect(), getICON());
}

void ActionButton::setScaling(qreal scaling)
{
	m_scaling = scaling;	
	transform.scale(scaling, scaling);
	ActionButton::paintEvent(NULL);
}
