#include "stdafx.h"
#include "BaseView.h"
#include "Foundation/Control/CaptionButton.h"

BaseView::BaseView(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);
	HWND hWnd = (HWND)this->winId();
	
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

	case WM_NCCREATE: {
		auto userdata = reinterpret_cast<CREATESTRUCTW*>(msg->lParam)->lpCreateParams;
		::SetWindowLongPtrW(msg->hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(userdata));
	}
	case WM_NCCALCSIZE:
	{
		if (msg->wParam == TRUE)
		{
			auto& params = *reinterpret_cast<NCCALCSIZE_PARAMS*>(msg->lParam);
			adjust_maximized_client_rect(msg->hwnd, params.rgrc[0]);
		}
		*result = 0;
		return true;
	}
	case WM_NCHITTEST:
	{
		*result = 0;
		const LONG border_width = 8; //in pixels
		RECT winrect;
		GetWindowRect(reinterpret_cast<HWND>(winId()), &winrect);

		long x = GET_X_LPARAM(msg->lParam);
		long y = GET_Y_LPARAM(msg->lParam);

		auto resizeWidth = minimumWidth() != maximumWidth();
		auto resizeHeight = minimumHeight() != maximumHeight();

		if (resizeWidth)
		{
			//left border
			if (x >= winrect.left && x < winrect.left + border_width)
			{
				*result = HTLEFT;
			}
			//right border
			if (x < winrect.right && x >= winrect.right - border_width)
			{
				*result = HTRIGHT;
			}
		}
		if (resizeHeight)
		{
			//bottom border
			if (y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOM;
			}
			//top border
			if (y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOP;
			}
		}
		if (resizeWidth && resizeHeight)
		{
			//bottom left corner
			if (x >= winrect.left && x < winrect.left + border_width &&
				y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOMLEFT;
			}
			//bottom right corner
			if (x < winrect.right && x >= winrect.right - border_width &&
				y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOMRIGHT;
			}
			//top left corner
			if (x >= winrect.left && x < winrect.left + border_width &&
				y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOPLEFT;
			}
			//top right corner
			if (x < winrect.right && x >= winrect.right - border_width &&
				y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOPRIGHT;
			}
		}
		if (*result != 0)
			return true;
		break;
	}
	case WM_GETMINMAXINFO: {
		MINMAXINFO* mmi = reinterpret_cast<MINMAXINFO*>(msg->lParam);

		if (ifMaximized(msg->hwnd)) {

			RECT window_rect{};

			if (!GetWindowRect(msg->hwnd, &window_rect)) {
				return false;

			}

			HMONITOR monitor = MonitorFromRect(&window_rect, MONITOR_DEFAULTTONULL);
			if (!monitor) {
				return false;
			}

			MONITORINFO monitor_info = { 0 };
			monitor_info.cbSize = sizeof(monitor_info);
			GetMonitorInfo(monitor, &monitor_info);

			RECT work_area = monitor_info.rcWork;
			RECT monitor_rect = monitor_info.rcMonitor;

			mmi->ptMaxPosition.x = abs(work_area.left - monitor_rect.left);
			mmi->ptMaxPosition.y = abs(work_area.top - monitor_rect.top);

			mmi->ptMaxSize.x = abs(work_area.right - work_area.left);
			mmi->ptMaxSize.y = abs(work_area.bottom - work_area.top);
			mmi->ptMaxTrackSize.x = mmi->ptMaxSize.x;
			mmi->ptMaxTrackSize.y = mmi->ptMaxSize.y;

			*result = 1;
			return true;
		}
	}

	case WM_NCACTIVATE: {
		if (!composition_enabled()) {
			*result = 1;
			return true;
		}
		break;
	}
	case WM_SIZE: {

		RECT winrect;
		GetClientRect(msg->hwnd, &winrect);

		WINDOWPLACEMENT wp;
		wp.length = sizeof(WINDOWPLACEMENT);
		GetWindowPlacement(msg->hwnd, &wp);
		if (this)
		{
			if (wp.showCmd == SW_MAXIMIZE)
			{
				::SetWindowPos(reinterpret_cast<HWND>(winId()), Q_NULLPTR, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
			}
		}
	}
	case WM_SETFOCUS:
		emit isHadFocuse(true);
		break;
	case WM_KILLFOCUS:
		emit isHadFocuse(false);
		break;
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
