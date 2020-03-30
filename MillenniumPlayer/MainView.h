#pragma once

#include <QtWidgets/QMainWindow>
#include <QPropertyAnimation>
#include "3rdparty/QMW/Includes/qtmaterialiconbutton.h"
#include "3rdparty/QMW/Includes/qtmaterialslider.h"
#include "Foundation/View/BaseView.h"
#include "Foundation/Control/ActionButton.h"
#include "Foundation/Control/PlayList.h"
#include "Foundation/Control/StackedWidget.h"
#include "Foundation/Core/MUSIC_TAG_INFO.h"
#include "Foundation/Core/MUSIC_PLAYER.h"

class MainView : public BaseView
{
	Q_OBJECT

public:
	MainView(QWidget *parent = Q_NULLPTR);

	void addMusic(QAbstractItemModel* model, 
		QString title, QString album, QString artist)
	{
		model->insertRow(0);
		model->setData(model->index(0, 0), title);
		model->setData(model->index(0, 1), album);
		model->setData(model->index(0, 2), artist);
	}
	QAbstractItemModel* createMailModel(QObject* parent)
	{
		QStandardItemModel* model = new QStandardItemModel(0, 3, parent);

		model->setHeaderData(0, Qt::Horizontal, QObject::tr("歌曲"));
		model->setHeaderData(1, Qt::Horizontal, QObject::tr("Sender"));
		model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));

		addMusic(model, "Lover", "Artsit", "Swift");
		addMusic(model, "Lover", "Artsit", "Swift");
		addMusic(model, "Lover", "Artsit", "Swift");
		return model;
	}
protected:
	void dragMoveEvent(QDragMoveEvent* event)
	{
		qDebug() << "drag move";
	}
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* event);
	bool eventFilter(QObject* watched, QEvent* event)
	{
		if (watched == ProgressSlider)
		{
			if (event->type() == QEvent::MouseButtonPress)
			{
				on_slider_mouseLButtonPress(watched, event);
				return true;
			}
			else {
				return false;
			}		
		}
		else if (watched == this) {
			if (event->type() == QEvent::MouseButtonDblClick)
			{
				if (Qt::WindowFullScreen == windowState())
					this->showNormal();
				if (Qt::WindowFullScreen != windowState())
					this->isMaximized() ? this->showNormal() : this->showMaximized();
			}
		}
		return QWidget::eventFilter(watched, event);
	}
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
		m_stackedwidget = new StackedWidget(this);
		
		w1 = new QWidget();
		w2 = new PlayList();

		w1->setLayout(m_hboxlayout);
		m_stackedwidget->insertWidget(0, w1);
		m_stackedwidget->insertWidget(1, w2);
		w2->setSourceModel(createMailModel(w2));
		m_stackedwidget->resize(600, 300);
		m_stackedwidget->setSpeed(500);
		m_stackedwidget->setVerticalMode(true);
		connect(ListButton, &QPushButton::clicked, this, [=]()
		{ 
				switch (m_stackedwidget->currentIndex())
				{
				case 0:
					m_stackedwidget->slideInNext();
					break;
				case 1:
					m_stackedwidget->slideInPrev();
					break;
				}
				
			});
		
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
			//qDebug() << "changed";
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
	void on_slider_mouseLButtonPress(QObject* slider, QEvent* event)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		double cxctl = 0;  // 滑块宽度
		double cxwnd = 0;  // 滑槽长度
		double mxpos = 0;  // 鼠标按下的位置
		cxctl = ProgressSlider->minimumSizeHint().width();
		cxwnd = ProgressSlider->width();
		if (ProgressSlider->invertedAppearance())
			mxpos = cxwnd - mouseEvent->x();
		else
			mxpos = mouseEvent->x();
		if (cxwnd <= cxctl)
		{
			//
		}
		double scpos = ProgressSlider->minimum() +
			(double)((ProgressSlider->maximum() - ProgressSlider->minimum()) *
				((mxpos - cxctl / 2.0) / (cxwnd - cxctl)));

		if (ProgressSlider->sliderPosition() == scpos)
		{
			//
		}
		qDebug() << scpos;
		m_MUSIC_PLAYER->pause();
		ProgressSlider->setValue(scpos);
		m_MUSIC_PLAYER->setPosition(scpos);
		m_MUSIC_PLAYER->play();
		CurrentTime->setText(m_MUSIC_PLAYER->updateTime());
	}
	MUSIC_TAG_INFO * m_MUSIC_TAG_INFO;
	MUSIC_PLAYER * m_MUSIC_PLAYER;
	QMap<QString, QString> tag;
	QImage coverPicture;
private:
	QWidget* w1;
	PlayList* w2;
	QHBoxLayout * m_hboxlayout;
	StackedWidget* m_stackedwidget;
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
