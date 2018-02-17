#pragma once

#include <QSlider>

class Slider : public QSlider
{
	Q_OBJECT

public:
	Slider(QWidget *parent);
	~Slider();
};
