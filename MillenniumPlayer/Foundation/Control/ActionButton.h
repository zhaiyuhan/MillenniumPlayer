#pragma once

#include <QPushButton>

class ActionButton : public QPushButton
{
	Q_OBJECT
	Q_PROPERTY(qreal scaling READ scaling WRITE setScaling)
public:
	ActionButton(QWidget *parent);
	~ActionButton();

	void setICON(QPixmap icon) { _icon = icon; }
	QPixmap getICON() { return _icon; }

protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent *);
private:
	qreal scaling()
	{
		return m_scaling;
	}
	void setScaling(qreal scaling);
private:
	qreal m_scaling;
	QTransform transform;
	QPropertyAnimation * pAnimation;
	QPixmap _icon;
};
