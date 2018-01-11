#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainView.h"

class MainView : public QMainWindow
{
	Q_OBJECT

public:
	MainView(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainViewClass ui;
};
