#pragma once

#include <QPushButton>

enum ButtonType { CLOSE, MIN, MAX, FULLSCREEN, CLOSESAVE };
enum ButtonStatus { NORMAL, ENTER, PRESS, NOSTATUS };

class CaptionButton : public QPushButton
{
	Q_OBJECT

public:
	CaptionButton(QWidget *parent);
	CaptionButton(ButtonType buttontype, QWidget * parent);
	~CaptionButton();
	void setStatus(ButtonStatus buttonstatus)
	{
		e_status = buttonstatus;
	}
	

protected:
	void mousePressEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void paintEvent(QPaintEvent *);

private:
	
	ButtonStatus e_status;
	ButtonType e_type;
	bool _ifPress = false;
	QString m_loadpath;
};
