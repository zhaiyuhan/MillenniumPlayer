#include "stdafx.h"
#include "CaptionButton.h"

CaptionButton::CaptionButton(ButtonType buttontype,QWidget *parent)
	: QPushButton(parent)
{
	_ifPress = false;
	e_type = buttontype;
	e_status = NORMAL;
	setFlat(true);
	setFixedSize(QSize(22, 22));
}

CaptionButton::~CaptionButton()
{
}

void CaptionButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		_ifPress = true;
		e_status = PRESS;
		update();
	}
}
void CaptionButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (_ifPress  && rect().contains(event->pos()))
	{
		_ifPress = false;
		e_status = ENTER;
		update();
		emit clicked();
	}
}
void CaptionButton::enterEvent(QEvent *)
{
	if (e_status != NOSTATUS)
		e_status = ENTER;
	update();
}
void CaptionButton::leaveEvent(QEvent *)
{
	if (e_status != NOSTATUS)
		e_status = NORMAL;
	update();

}

void CaptionButton::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QPixmap pixmap;
	painter.setRenderHint(QPainter::Antialiasing, true);
	switch (e_status)
	{
	case NORMAL:
		if (e_type == CLOSE) m_loadpath = ":/MainView/Resources/CaptionButton/Close.png";
		if (e_type == MIN) m_loadpath = ":/MainView/Resources/CaptionButton/Min.png";
		if (e_type == MAX) m_loadpath = ":/MainView/Resources/CaptionButton/Max.png";
		if (e_type == FULLSCREEN) m_loadpath = ":/MainView/Resources/CaptionButton/Max.png";
		if (e_type == CLOSESAVE) m_loadpath = ":/MainView/Resources/CaptionButton/Close.svg";
		pixmap.load(m_loadpath);
		break;
	case ENTER:
		if (e_type == CLOSE) m_loadpath = ":/MainView/Resources/CaptionButton/CloseHover.png";
		if (e_type == MIN) m_loadpath = ":/MainView/Resources/CaptionButton/MinHover.png";
		if (e_type == MAX) m_loadpath = ":/MainView/Resources/CaptionButton/MaxHover.png";
		if (e_type == FULLSCREEN) m_loadpath = ":/MainView/Resources/CaptionButton/FullScreenHover.png";
		if (e_type == CLOSESAVE) m_loadpath = ":/MainView/Resources/CaptionButton/Close.svg";
		pixmap.load(m_loadpath);
		break;
	case PRESS:
		if (e_type == CLOSE) m_loadpath = ":/MainView/Resources/CaptionButton/ClosePressed.png";
		if (e_type == MIN) m_loadpath = ":/MainView/Resources/CaptionButton/MinPressed.png";
		if (e_type == MAX) m_loadpath = ":/MainView/Resources/CaptionButton/MaxPressed.png";
		if (e_type == FULLSCREEN) m_loadpath = ":/MainView/Resources/CaptionButton/Close.svg";
		if (e_type == CLOSESAVE) m_loadpath = ":/MainView/Resources/CaptionButton/Close.svg";
		pixmap.load(m_loadpath);
		break;
	case NOSTATUS:
		m_loadpath = ":/MainView/Resources/CaptionButton/NoState.png";
		pixmap.load(m_loadpath);
		break;
	default:
		if (e_type == CLOSE) m_loadpath = "";
		pixmap.load(m_loadpath);
		break;
	}
	painter.drawPixmap(0, 0, 20, 20, pixmap);
}


