#pragma once

#include <QtWidgets/QMainWindow>
#include "Foundation/View/BaseView.h"

class MainView : public BaseView
{
	Q_OBJECT

public:
	MainView(QWidget *parent = Q_NULLPTR);

protected:
	void setupUI()
	{
		AlbumImageWidget = new ImageWidget(this);
		AlbumImageWidget->setFixedSize(250, 250);
		ListButton = new ActionButton(this);		
		ListButton->setFixedSize(25, 25);
		ListButton->setICON(QPixmap(":/MainView/Resources/List.svg"));
		VolumeButton = new ActionButton(this);
		VolumeButton->setFixedSize(25, 25);
		VolumeButton->setICON(QPixmap(":/MainView/Resources/Volume.svg"));
		FavouriteButton = new ActionButton(this);
		FavouriteButton->setFixedSize(20, 20);
		FavouriteButton->setICON(QPixmap(":/MainView/Resources/Favourite.svg"));
		ArtistLabel = new Label(this, QString("Artist"));
		QFont f;// ("Microsoft YaHei", 10, QFont::Light);
		f.setFamily("Microsoft YaHei UI Light");
		f.setPointSize(20);
		ArtistLabel->setFont(f);
		QPalette p;
		p.setColor(QPalette::WindowText, Qt::white);
		ArtistLabel->setPalette(p);
		TitleLabel = new Label(this, QString("Title"));
		f.setPointSize(28);
		TitleLabel->setFont(f);
		TitleLabel->setPalette(p);
		CurrentTime = new Label(this, QString("00:00"));
		CurrentTime->setPalette(p);
		LeftTime = new Label(this, QString("00:00"));
		LeftTime->setPalette(p);
		ProgressSlider = new Slider(this);
		ProgressSlider->setOrientation(Qt::Horizontal);
		systemTray = new SystemTray(this);
	}
	void initLayout()
	{
		m_hboxlayout = new QHBoxLayout();
		m_gridlayout = new QGridLayout();
		m_gridlayout->addWidget(TitleLabel, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(VolumeButton, 0, 1, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
		m_gridlayout->addWidget(ArtistLabel, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(FavouriteButton, 2, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(CurrentTime, 3, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(LeftTime, 3, 1, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
		m_gridlayout->addWidget(ProgressSlider, 4, 0, 1, 2, Qt::AlignVCenter);
		m_hboxlayout->addWidget(AlbumImageWidget);
		m_hboxlayout->addLayout(m_gridlayout);
		m_stackedwidget = new QStackedWidget(this);
		
		QWidget *w1 = new QWidget();
		w1->setLayout(m_hboxlayout);
		m_stackedwidget->addWidget(w1);
		m_stackedwidget->resize(600, 300);
		//setLayout(m_hboxlayout);
	}
	void initView();
	void resizeEvent(QResizeEvent *event);
	void contextMenuEvent(QContextMenuEvent *);
private:
	QHBoxLayout * m_hboxlayout;
	QStackedWidget * m_stackedwidget;
	QGridLayout * m_gridlayout;
	ImageWidget *AlbumImageWidget;
	ActionButton *ListButton;
	ActionButton *VolumeButton;
	ActionButton *FavouriteButton;
	Label *ArtistLabel;
	Label *TitleLabel;
	Label *CurrentTime;
	Label *LeftTime;
	Slider *ProgressSlider;
	Menu *menu;
	SystemTray *systemTray;
};
