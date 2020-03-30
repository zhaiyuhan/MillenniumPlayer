#include "stdafx.h"
#include "MainView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	::SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication a(argc, argv);
	MainView w;
	w.show();
	return a.exec();
}
