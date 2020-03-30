#pragma once

#include <QSlider>

#include "3rdparty/QMW/Includes/qtmaterialslider.h"

class Slider : public QtMaterialSlider
{
	Q_OBJECT

public:
    explicit Slider(QWidget *parent = nullptr);
	~Slider();

    void setRange(double Min, double Max);
    void setMinimum(double Min);
    double minimum() const;
    void setMaximum(double Max);
    double maximum() const;
    double value() const;
    
public slots:
    void setValue(int value);
    void setValue(double Value, bool BlockSignals = false);

private slots:

signals:
    void click_event(double Value);
    void valueChanged(double Value);
    void rangeChanged(double Min, double Max);
protected:
    void mousePressEvent(QMouseEvent* ev)
    {

        //注意应先调用父类的鼠标点击处理事件，这样可以不影响拖动的情况
        QtMaterialSlider::mousePressEvent(ev);
        qDebug() << "clicked";
        double cxctl = 0;  // 滑块宽度
        double cxwnd = 0;  // 滑槽长度
        double mxpos = 0;  // 鼠标按下的位置
        cxctl = this->minimumSizeHint().width();
        cxwnd = this->width();
        if (this->invertedAppearance())
            mxpos = cxwnd - ev->x();
        else
            mxpos = ev->x();
        if (cxwnd <= cxctl)
        {
            //
        }
        double scpos = this->minimum() +
            (double)((this->maximum() - this->minimum()) *
                ((mxpos - cxctl / 2.0) / (cxwnd - cxctl)));

        if (this->sliderPosition() == scpos)
        {
            //
        }
        emit click_event(scpos);
        ////向父窗口发送自定义事件event type，这样就可以在父窗口中捕获这个事件进行处理
        //QEvent evEvent(static_cast<QEvent::Type>(QEvent::User + 1));
        //QCoreApplication::sendEvent(parentWidget(), &evEvent);

    }
private:
    double	m_Multiplier;
};
