#include "stdafx.h"
#include "SettingView.h"

SettingView::SettingView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Tool);
	setWindowModality(Qt::WindowModal);
	BOOL bEnable = false;
	::DwmIsCompositionEnabled(&bEnable);
	if (bEnable)
	{
		DWMNCRENDERINGPOLICY ncrp = DWMNCRP_ENABLED;
		::DwmSetWindowAttribute((HWND)winId(), DWMWA_NCRENDERING_POLICY, &ncrp, sizeof(ncrp));
		MARGINS margins = { -1 };
		::DwmExtendFrameIntoClientArea((HWND)winId(), &margins);
	}
	CustomShadowEffect *bodyShadow = new CustomShadowEffect();
	bodyShadow->setBlurRadius(10.0);
	bodyShadow->setDistance(2.0);
	bodyShadow->setColor(QColor(21, 25, 30, 60));
	ui.stackedWidget->setAutoFillBackground(true);
	ui.stackedWidget->setGraphicsEffect(bodyShadow);
}

SettingView::~SettingView()
{
}
