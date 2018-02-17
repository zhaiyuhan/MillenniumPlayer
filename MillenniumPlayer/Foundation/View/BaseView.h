#pragma once

#include "stdafx.h"
#include <QMainWindow>
#include "Foundation/Control/CaptionButton.h"

#pragma comment (lib,"Dwmapi.lib")

class BaseView : public QMainWindow
{
	Q_OBJECT

public:
	BaseView(QWidget *parent);
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
