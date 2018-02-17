#include "stdafx.h"
#include "MainView.h"
#include <QPalette>
MainView::MainView(QWidget *parent)
	: BaseView(parent)
{
	setMinimumSize(810, 500);
	EnableBackgroundColor(QColor(0x00, 0xff, 0x00, 0x00));
	EnableGaussianBlur(true);
	EnableWindowShadow(true);
	initView();
	setWindowIcon(QIcon(":/logo.ico"));
}

void MainView::initView()
{
	setupUI();
	QPalette pal(AlbumImageWidget->palette());
	pal.setColor(QPalette::Background, Qt::white);
	AlbumImageWidget->setPalette(pal);
	AlbumImageWidget->setAutoFillBackground(true);
	CustomShadowEffect *bodyShadow = new CustomShadowEffect();
	bodyShadow->setBlurRadius(10.0);
	bodyShadow->setDistance(2.0);
	bodyShadow->setColor(QColor(21, 25, 30, 60));
	AlbumImageWidget->setGraphicsEffect(bodyShadow);
	AlbumImageWidget->show();	
	//setCentralWidget(m_stackedwidget);
	initLayout();
}

void MainView::resizeEvent(QResizeEvent * event)
{
	ListButton->move((event->size().width() - 50), 20);	
	m_stackedwidget->move(((event->size().width()-600) / 2), ((event->size().height()-300) / 2));
	/*AlbumImageWidget->move(((event->size().width() - 250) / 2 - 200), ((event->size().height() - 200) / 2));	
		
	VolumeButton->move((event->size().width() - 120), AlbumImageWidget->y());	
	TitleLabel->resize(100, 40);
	TitleLabel->move(AlbumImageWidget->x() + AlbumImageWidget->width() + 20, AlbumImageWidget->y());
	ArtistLabel->move(TitleLabel->x(), AlbumImageWidget->y() + TitleLabel->height() + 3);		
	FavouriteButton->move(TitleLabel->x(), ArtistLabel->y() + 45);	
	CurrentTime->move(TitleLabel->x(), FavouriteButton->y() + TitleLabel->height() + 3);
	LeftTime->move(VolumeButton->x(), FavouriteButton->y() + TitleLabel->height() + 3);
	ProgressSlider->resize(VolumeButton->x() - TitleLabel->x() + 25, 25);
	ProgressSlider->move(TitleLabel->x(), FavouriteButton->y() + 70);*/
	BaseView::resizeEvent();
}

void MainView::contextMenuEvent(QContextMenuEvent *)
{
	QCursor cur = this->cursor();
	menu = new Menu(this);
	QAction *OpenAction = new QAction(tr("Open"), this);
	QAction *OpenAudioCDAction = new QAction(tr("Open audio CD"), this);
	QAction *AddFilesAction = new QAction(tr("Add Files"), this);
	QAction *AddFloderAction = new QAction(tr("Add Floder"), this);
	QAction *SettingAction = new QAction(tr("Setting"), this);
	QAction *HiddenAction = new QAction(tr("Hidden"), this);
	QAction *AboutAction = new QAction(tr("About"), this);	
	QAction *deleteAction = new QAction(tr("Exit"), this);
	deleteAction->setObjectName("done");
	menu->addAction(OpenAction);
	menu->addAction(OpenAudioCDAction);
	menu->addSeparator();
	menu->addAction(AddFilesAction);
	menu->addAction(AddFloderAction);
	menu->addSeparator();
	menu->addAction(SettingAction);	
	connect(SettingAction, &QAction::triggered, this,
		[=]() { SettingView *settingview = new SettingView(this);  settingview->show(); });
	menu->addAction(HiddenAction);
	connect(HiddenAction, &QAction::triggered, this,
		[=]() { hide(); systemTray->show();
	});
	menu->addAction(AboutAction);
	connect(AboutAction, &QAction::triggered, this,
		[=]() { AboutView *aboutview = new AboutView(this); aboutview->exec(); });
	menu->addSeparator();
	menu->addAction(deleteAction);
	connect(deleteAction, &QAction::triggered, this,
		[=]() { qApp->exit(); });
	menu->exec(cur.pos());
}
