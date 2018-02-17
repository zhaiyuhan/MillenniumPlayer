#include "stdafx.h"
#include "SystemTray.h"

SystemTray::SystemTray(QWidget *parent)
	: QSystemTrayIcon(parent)
{
	setIcon(QIcon(":/logo.ico"));
	createMenu();
	setContextMenu(m_menu);
}

SystemTray::~SystemTray()
{
}
