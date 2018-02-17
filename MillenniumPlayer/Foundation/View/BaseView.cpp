#include "stdafx.h"
#include "BaseView.h"
#include "Foundation/Control/CaptionButton.h"

BaseView::BaseView(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);
	HWND hWnd = (HWND)this->winId();
	//DWORD style = ::GetWindowLong(hWnd, GWL_STYLE);
	//SetWindowLong(hWnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | CS_DBLCLKS);
	setupUI();
	connect(CloseButton, &QPushButton::clicked, [=]() { qApp->exit(); });
	connect(MinButton, &QPushButton::clicked, [=]() { showMinimized(); });
	connect(MaxButton, &QPushButton::clicked, [=]() { 
		isMaximized() ? showNormal() : showMaximized();
	});
	connect(this, &BaseView::isHadFocuse, [=](bool had) {
		if (had) {
			CloseButton->setStatus(NORMAL);
			MinButton->setStatus(NORMAL);
			MaxButton->setStatus(NORMAL);
			update();
		}
		else {
			CloseButton->setStatus(NOSTATUS);
			MinButton->setStatus(NOSTATUS);
			MaxButton->setStatus(NOSTATUS);
			update();
		}
	});
}

BaseView::~BaseView()
{
}

bool BaseView::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
	Q_UNUSED(eventType)
		MSG* msg = reinterpret_cast<MSG*>(message);
	switch (msg->message) {
	case WM_SETFOCUS:
		emit isHadFocuse(true);
		break;
	case WM_KILLFOCUS:
		emit isHadFocuse(false);
		break;

/*
	case WM_NCCALCSIZE:
	{
		*result = 0;
		return true;
	}

	case WM_NCHITTEST:
	{
		int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
		int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
		if (xPos > 0 && xPos < 5)
			*result = HTLEFT;
		if (xPos >(this->width() - 5) && xPos < (this->width() - 0))
			*result = HTRIGHT;
		if (yPos > 0 && yPos < 5)
			*result = HTTOP;
		if (yPos >(this->height() - 5) && yPos < (this->height() - 0))
			*result = HTBOTTOM;
		if (xPos > 0 && xPos < 5 && yPos > 0 && yPos < 5)
			*result = HTTOPLEFT;
		if (xPos >(this->width() - 5) && xPos < (this->width() - 0) && yPos > 0 && yPos < 5)
			*result = HTTOPRIGHT;
		if (xPos > 0 && xPos < 5 && yPos >(this->height() - 5) && yPos < (this->height() - 0))
			*result = HTBOTTOMLEFT;
		if (xPos >(this->width() - 5) && xPos < (this->width() - 0) && yPos >(this->height() - 5) && yPos < (this->height() - 0))
			*result = HTBOTTOMRIGHT;
		return true;
		break;
	}
	
	case WM_LBUTTONDBLCLK:
		if (Qt::WindowFullScreen == windowState())
			this->showNormal();
		if (Qt::WindowFullScreen != windowState())
			this->isMaximized() ? this->showNormal() : this->showMaximized();
		break;*/
	default:
		return QWidget::nativeEvent(eventType, message, result);
	}
	return QWidget::nativeEvent(eventType, message, result);
}

void BaseView::resizeEvent()
{
	CloseButton->move(20, 20);
	MinButton->move(45, 20);
	MaxButton->move(70, 20);
}
