#pragma once

#include "stdafx.h"
#include <QMainWindow>
#include "Foundation/Control/CaptionButton.h"

#pragma comment (lib,"Dwmapi.lib")

class BaseView : public QWidget
{
	Q_OBJECT

public:
	explicit BaseView(QWidget* parent = nullptr);
	~BaseView();

protected:
	bool nativeEvent(const QByteArray & eventType, void * message, long * result);

	virtual void resizeEvent();

	void mousePressEvent(QMouseEvent *event)
	{
#ifdef Q_OS_WIN
		if (ReleaseCapture())
		{
				SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
		event->ignore();
#else
#endif
	}

	auto EnableAnimation(bool _enable) -> void {
		if (_enable)
		{
			HWND hWnd = (HWND)this->winId();
			DWORD style = ::GetWindowLong(hWnd, GWL_STYLE);
			SetWindowLong(hWnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION | CS_DBLCLKS);
		}
	}
	void EnableGaussianBlur(bool ifEnable)
	{
		if (ifEnable)
		{
			HWND hWnd = HWND(winId());
			HMODULE hUser = GetModuleHandle(L"user32.dll");
			if (hUser)
			{
				pfnSetWindowCompositionAttribute setWindowCompositionAttribute =
					(pfnSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
				if (setWindowCompositionAttribute)
				{
					ACCENT_POLICY accent = { ACCENT_ENABLE_BLURBEHIND, 0, 0, 0 };
					WINDOWCOMPOSITIONATTRIBDATA data;
					data.Attrib = WCA_ACCENT_POLICY;
					data.pvData = &accent;
					data.cbData = sizeof(accent);
					setWindowCompositionAttribute(hWnd, &data);
				}
			}
		}
	}
	void EnableBackgroundColor(QColor bgcolor)
	{
		QPalette p = palette();
		//p.setColor(QPalette::Background, QColor(0x00, 0xff, 0x00, 0x00));
		p.setColor(QPalette::Background, bgcolor);
		this->setPalette(p);
	}
	void EnableWindowShadow(bool ifEnable)
	{
		if (ifEnable)
		{
			BOOL bEnable = false;
			::DwmIsCompositionEnabled(&bEnable);
			if (bEnable)
			{
				DWMNCRENDERINGPOLICY ncrp = DWMNCRP_ENABLED;
				::DwmSetWindowAttribute((HWND)winId(), DWMWA_NCRENDERING_POLICY, &ncrp, sizeof(ncrp));
				MARGINS margins = { -1 };
				::DwmExtendFrameIntoClientArea((HWND)winId(), &margins);
			}
		}
	}

signals:
	void isHadFocuse(bool had);

private:
	auto composition_enabled() -> bool {
		auto composition_enabled = FALSE;
		auto success = ::DwmIsCompositionEnabled(&composition_enabled) == S_OK;
		return composition_enabled && success;
	}
	auto ifMaximized(HWND hwnd) -> bool
	{
		WINDOWPLACEMENT placement{};
		if (!::GetWindowPlacement(hwnd, &placement)) { return false; }
		return placement.showCmd == SW_MAXIMIZE;
	}
	auto adjust_maximized_client_rect(HWND window, RECT& rect) -> void
	{
		if (!ifMaximized(window)) { return; }
		HMONITOR monitor = ::MonitorFromWindow(window, MONITOR_DEFAULTTONULL);
		if (!monitor) { return; }
		MONITORINFO monitor_info{};
		monitor_info.cbSize = sizeof(monitor_info);
		if (!::GetMonitorInfoW(monitor, &monitor_info)) { return; }
		rect = monitor_info.rcWork;
	}
private:
	void setupUI()
	{
		CloseButton = new CaptionButton(CLOSE, this);
		MinButton = new CaptionButton(MIN, this);
		MaxButton = new CaptionButton(MAX, this);
	}

	CaptionButton * CloseButton;
	CaptionButton * MinButton;
	CaptionButton * MaxButton;

};
