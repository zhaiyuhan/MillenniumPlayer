#include "stdafx.h"
#include "Slider.h"

Slider::Slider(QWidget *parent)
	: QtMaterialSlider(parent),
	m_Multiplier(10000.0)
{
	connect(this, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
	setSingleStep(1);
}

Slider::~Slider()
{
}
void Slider::setValue(int Value)
{
    emit valueChanged((double)Value / m_Multiplier);
}

void Slider::setValue(double Value, bool BlockSignals)
{
    QtMaterialSlider::blockSignals(BlockSignals);

    QtMaterialSlider::setValue(Value * m_Multiplier);

    if (!BlockSignals)
        emit valueChanged(Value);

    QtMaterialSlider::blockSignals(false);
}

void Slider::setRange(double Min, double Max)
{
    QtMaterialSlider::setRange(Min * m_Multiplier, Max * m_Multiplier);

    emit rangeChanged(Min, Max);
}

void Slider::setMinimum(double Min)
{
    QtMaterialSlider::setMinimum(Min * m_Multiplier);

    emit rangeChanged(minimum(), maximum());
}

double Slider::minimum() const
{
    return QtMaterialSlider::minimum() / m_Multiplier;
}

void Slider::setMaximum(double Max)
{
    QtMaterialSlider::setMaximum(Max * m_Multiplier);

    emit rangeChanged(minimum(), maximum());
}

double Slider::maximum() const
{
    return QtMaterialSlider::maximum() / m_Multiplier;
}

double Slider::value() const
{
    int Value = QtMaterialSlider::value();
    return (double)Value / m_Multiplier;
}
