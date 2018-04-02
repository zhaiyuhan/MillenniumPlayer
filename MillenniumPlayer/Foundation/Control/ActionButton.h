#pragma once

#include <QPushButton>

class ActionButton : public QPushButton
{
	Q_OBJECT
	Q_PROPERTY(qreal scaling READ scaling WRITE setScaling)
public:
	enum ButtonStatus { NORMAL, ENTER, PRESS, NOSTATUS };
	ActionButton(QWidget *parent);
	~ActionButton();

	void setICON(QPixmap icon) { _icon = icon; }
	QPixmap getICON() { return _icon; }

protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent * event);
	void paintEvent(QPaintEvent *);
private:
	ButtonStatus e_status;
	qreal scaling()
	{
		return m_scaling;
	}
	void setScaling(qreal scaling);
private:	
	bool _ifPress = false;
	qreal m_scaling;
	QTransform transform;
	QPropertyAnimation * pAnimation;
	QPixmap _icon;
};
