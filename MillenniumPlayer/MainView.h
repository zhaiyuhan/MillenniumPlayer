#pragma once

#include <QtWidgets/QMainWindow>
#include "3rdparty/QMW/Includes/qtmaterialiconbutton.h"
#include "3rdparty/QMW/Includes/qtmaterialslider.h"
#include "Foundation/View/BaseView.h"
#include "Foundation/Control/ActionButton.h"
#include "Foundation/Core/MUSIC_TAG_INFO.h"
#include "Foundation/Core/MUSIC_PLAYER.h"

class MainView : public BaseView
{
	Q_OBJECT

public:
	MainView(QWidget *parent = Q_NULLPTR);

protected:
	void dragMoveEvent(QDragMoveEvent* event)
	{
		qDebug() << "drag move";
	}
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* event);
	void setupUI()
	{
		PreivousButton = new QtMaterialIconButton(QIcon(":/Icons/previous.svg"), this);
		PreivousButton->setFixedSize(25, 25);
		PreivousButton->setColor(Qt::white);
		PlayButton = new QtMaterialIconButton(QIcon(":/Icons/play.svg"), this);
		PlayButton->setFixedSize(25, 25);
		PlayButton->setColor(Qt::white);
		NextButton = new QtMaterialIconButton(QIcon(":/Icons/next.svg"), this);
		NextButton->setFixedSize(25, 25);
		NextButton->setColor(Qt::white);
		AlbumImageWidget = new ImageWidget(this);
		AlbumImageWidget->setFixedSize(250, 250);
		ListButton = new QtMaterialIconButton(QIcon(":/MainView/Resources/List.svg"), this);
		ListButton->setFixedSize(25, 25);
		ListButton->setColor(Qt::white);
		VolumeButton = new QtMaterialIconButton(QIcon(":/MainView/Resources/Volume.svg"), this);
		VolumeButton->setFixedSize(25, 25);
		VolumeButton->setColor(Qt::white);
		FavouriteButton = new QtMaterialIconButton(QIcon(":/MainView/Resources/Favourite.svg"), this);
		FavouriteButton->setFixedSize(20, 20);
		FavouriteButton->setColor(Qt::white);
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
		m_MUSIC_PLAYER = new MUSIC_PLAYER(this);
	}
	void initLayout()
	{
		m_hboxlayout = new QHBoxLayout();
		m_gridlayout = new QGridLayout();
		m_gridlayout->addWidget(TitleLabel, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(VolumeButton, 0, 2, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
		m_gridlayout->addWidget(ArtistLabel, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(FavouriteButton, 2, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(CurrentTime, 3, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
		m_gridlayout->addWidget(LeftTime, 3, 2, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
		m_gridlayout->addWidget(ProgressSlider, 4, 0, 1, 3, Qt::AlignVCenter);
		m_gridlayout->addWidget(PreivousButton, 5, 0, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
		m_gridlayout->addWidget(PlayButton, 5, 1, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
		m_gridlayout->addWidget(NextButton, 5, 2, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
		m_hboxlayout->addWidget(AlbumImageWidget);
		m_hboxlayout->addLayout(m_gridlayout);
		m_stackedwidget = new QStackedWidget(this);
		
		QWidget *w1 = new QWidget();
		QWidget *w2 = new QWidget();
		w1->setLayout(m_hboxlayout);
		m_stackedwidget->addWidget(w1);
		m_stackedwidget->addWidget(w2);
		connect(ListButton, &QPushButton::clicked, this, [=]()
		{ m_stackedwidget->setCurrentWidget(w2); });
		m_stackedwidget->resize(600, 300);
		//setLayout(m_hboxlayout);
	}
	void initEvents()
	{		
		connect(AlbumImageWidget, &ImageWidget::clicked, this,
			[=]() { 
			InformationView *informationview = new InformationView(this);  
			informationview->updateInformation(tag, coverPicture);
			QPalette p(informationview->palette());
			p.setColor(QPalette::Background, Qt::white);
			informationview->setPalette(p);
			informationview->show(); });
		connect(AlbumImageWidget, &ImageWidget::hover, this,
			[=](bool enter) { if (enter) { setCursor(Qt::PointingHandCursor); } else { setCursor(Qt::ArrowCursor); } });
		connect(PlayButton, &QPushButton::clicked, this,
			[=]() { m_MUSIC_PLAYER->play(); });
		connect(m_MUSIC_PLAYER, &MUSIC_PLAYER::PlayState, this,
			[=](bool _isPlaying) { 
				_isPlaying ? PlayButton->setIcon(QIcon(":/Icons/play.svg")) : PlayButton->setIcon(QIcon(":/Icons/pause.svg"));
			});
		connect(m_MUSIC_PLAYER, &MUSIC_PLAYER::positionUpdated, this,
			[=]() { CurrentTime->setText(m_MUSIC_PLAYER->updateTime()); });

		connect(m_MUSIC_PLAYER, &MUSIC_PLAYER::positionChanged, this, [=](double _currentposition) {
			ProgressSlider->setValue(_currentposition);
			qDebug() << "changed";
			});

		connect(ProgressSlider, &QSlider::sliderMoved, this, [=](double _currentposition) {
			m_MUSIC_PLAYER->pause();
			CurrentTime->setText(m_MUSIC_PLAYER->updateTime());
			});
		connect(ProgressSlider, &QSlider::sliderReleased, this, [=]() {
			m_MUSIC_PLAYER->setPosition(ProgressSlider->value());
			m_MUSIC_PLAYER->play();
			CurrentTime->setText(m_MUSIC_PLAYER->updateTime());
			});
		
		
	}
	void initView();
	void resizeEvent(QResizeEvent *event);
	void contextMenuEvent(QContextMenuEvent *);
private:
	MUSIC_TAG_INFO * m_MUSIC_TAG_INFO;
	MUSIC_PLAYER * m_MUSIC_PLAYER;
	QMap<QString, QString> tag;
	QImage coverPicture;
private:
	QHBoxLayout * m_hboxlayout;
	QStackedWidget * m_stackedwidget;
	QGridLayout * m_gridlayout;
	ImageWidget * AlbumImageWidget;
	QtMaterialIconButton* PreivousButton;
	QtMaterialIconButton * PlayButton;
	QtMaterialIconButton* NextButton;
	QtMaterialIconButton* ListButton;
	QtMaterialIconButton* VolumeButton;
	QtMaterialIconButton* FavouriteButton;
	Label * ArtistLabel;
	Label * TitleLabel;
	Label * CurrentTime;
	Label * LeftTime;
	Slider* ProgressSlider;
	Menu * menu;
	SystemTray * systemTray;
};
