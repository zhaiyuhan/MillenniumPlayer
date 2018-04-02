#pragma once

#include <QWidget>

class ImageWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ImageWidget(QWidget *parent);
	~ImageWidget();

	void setCoverImage(QImage& coverimage);
signals:
	void clicked();
	void hover(bool enter);

protected:
	void mousePressEvent(QMouseEvent *event)
	{
		if (event->button() == Qt::LeftButton)
		{
			_ifPress = true;
		}
	}

	void mouseReleaseEvent(QMouseEvent * event)
	{
		if (_ifPress  && rect().contains(event->pos()))
		{
			_ifPress = false;
			emit clicked();
		}
	}

	void enterEvent(QEvent *)
	{
		emit hover(true);
	}

	void leaveEvent(QEvent *)
	{
		emit hover(false);
	}

	/*void paintEvent(QPaintEvent *event)
   	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);
		painter.setBrush(QBrush(Qt::transparent));
		painter.setPen(Qt::transparent);
		QRect rect = this->rect();
		rect.setWidth(rect.width() - 1);
		rect.setHeight(rect.height() - 1);
		painter.drawRoundedRect(rect, 15, 15);
		QWidget::paintEvent(event);
	}*/
private:
	bool _ifPress = false;
};
