#include "stdafx.h"
#include "MainView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication a(argc, argv);
	const float DEFAULT_DPI = 96.0;
	HDC screen = GetDC(NULL);
	FLOAT dpiX = static_cast<FLOAT>(GetDeviceCaps(screen, LOGPIXELSX));
	ReleaseDC(0, screen);
	float fontSize = dpiX / DEFAULT_DPI;

	QFont font = a.font();
	font.setPointSize(font.pointSize() * fontSize);
	a.setFont(font);
	MainView w;
	w.show();
	return a.exec();
}
