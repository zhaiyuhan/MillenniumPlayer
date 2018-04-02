#pragma once

#include <QWidget>
#include "ui_SettingView.h"
class SettingView : public QWidget
{
	Q_OBJECT

public:
	SettingView(QWidget *parent = Q_NULLPTR);
	~SettingView();

private:
	void initLayouts()
	{
		ui.widget_lyric_setting->setLayout(ui.layout_for_widget_lyric_setting);
		ui.widget_shortcut_key_setting->setLayout(ui.layout_for_widget_shortcut_key_setting);
		ui.widget_device_setting->setLayout(ui.layout_for_widget_device_setting);
	}
	void initEvents()
	{
		connect(ui.btn_interface_setting, &QPushButton::clicked, this, [=]()
		{ ui.stackedWidget->setCurrentWidget(ui.widget_interface_setting); });
		connect(ui.btn_lyric_setting, &QPushButton::clicked, this, [=]()
		{ ui.stackedWidget->setCurrentWidget(ui.widget_lyric_setting); });
		connect(ui.btn_shortcut_key_setting, &QPushButton::clicked, this, [=]()
		{ ui.stackedWidget->setCurrentWidget(ui.widget_shortcut_key_setting); });
		connect(ui.btn_device_setting, &QPushButton::clicked, this, [=]()
		{ ui.stackedWidget->setCurrentWidget(ui.widget_device_setting); });
		
	}
	Ui::SettingView ui;
};
