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
	Ui::SettingView ui;
};
