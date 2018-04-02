#include "stdafx.h"
#include "InformationView.h"

InformationView::InformationView(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(QSize(300, 400));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Tool);
	setWindowModality(Qt::WindowModal);
	BOOL bEnable = false;
	::DwmIsCompositionEnabled(&bEnable);
	if (bEnable)
	{
		DWMNCRENDERINGPOLICY ncrp = DWMNCRP_ENABLED;
		::DwmSetWindowAttribute((HWND)winId(), DWMWA_NCRENDERING_POLICY, &ncrp, sizeof(ncrp));
		MARGINS margins = { -1 };
		::DwmExtendFrameIntoClientArea((HWND)winId(), &margins);
	}
	
	initView();
}

InformationView::~InformationView()
{
	setAttribute(Qt::WA_DeleteOnClose);
}

void InformationView::updateInformation(QMap<QString, QString>& _tag, QImage & _coverimage)
{
	if (_tag.contains("Title"))
		TitleLabel->setText(QString(_tag["Title"]));
	if (_tag.contains("Artist") && _tag.contains("Album"))
	{
		QString Artist_Album = _tag["Artist"];
		Artist_Album += " - ";
		Artist_Album += _tag["Album"];
		Artist_AlbumLabel->setText(QString(Artist_Album));
	}
	if (!_coverimage.isNull())
		AlbumImageWidget->setCoverImage(_coverimage);
	update();

}

void InformationView::initView()
{
	setAutoFillBackground(true);
	setupUI();
	initLayouts();
}
