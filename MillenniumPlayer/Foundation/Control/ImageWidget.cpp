#include "stdafx.h"
#include "ImageWidget.h"

ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
{
	setAutoFillBackground(true);
	

}

ImageWidget::~ImageWidget()
{
}

void ImageWidget::setCoverImage(QImage & coverimage)
{
	QPalette palette;
	palette.setBrush(QPalette::Background,
		QBrush(QPixmap::fromImage(coverimage).scaled
		(
			size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));
	setPalette(palette);
}
