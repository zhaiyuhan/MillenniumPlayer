#include "stdafx.h"
#include "MainView.h"
#include <QPalette>
#include"3rdparty/TagLib/Includes/fileref.h"
#include "3rdparty/TagLib/Includes/tstringlist.h"
using namespace TagLib;
MainView::MainView(QWidget *parent)
	: BaseView(parent)
{
	setMinimumSize(810, 500);
	EnableBackgroundColor(QColor(0x00, 0xff, 0x00, 0x00));
	EnableAnimation(true);
	EnableGaussianBlur(true);
	EnableWindowShadow(true);
	initView();
	setWindowIcon(QIcon(":/logo.ico"));
}

void MainView::initView()
{
	setupUI();
	CustomShadowEffect *bodyShadow = new CustomShadowEffect();
	bodyShadow->setBlurRadius(15.0);
	bodyShadow->setDistance(4.0);
	bodyShadow->setColor(QColor(21, 25, 30, 60));
	AlbumImageWidget->setGraphicsEffect(bodyShadow);
	AlbumImageWidget->show();	
	initLayout();
	initEvents();
}

void MainView::resizeEvent(QResizeEvent * event)
{
	ListButton->move((event->size().width() - 50), 20);	
	m_stackedwidget->move(((event->size().width()-600) / 2), ((event->size().height()-300) / 2));
	BaseView::resizeEvent();
}

void MainView::contextMenuEvent(QContextMenuEvent *)
{
	QCursor cur = this->cursor();
	menu = new Menu(this);
	QAction *OpenAction = new QAction(tr("Open"), this);
	connect(OpenAction, &QAction::triggered, this, [=]()
	{
		QFileDialog dialog(this);
		dialog.setFileMode(QFileDialog::AnyFile);
		QStringList fileName;
		if (dialog.exec() == QDialog::Accepted) 
		{
			fileName = dialog.selectedFiles();
			//检查文件信息
			m_MUSIC_TAG_INFO = new MUSIC_TAG_INFO(this);
			m_MUSIC_TAG_INFO->loadSong(fileName[0]);
			tag["Title"] = m_MUSIC_TAG_INFO->getTitle();
			tag["Artist"] = m_MUSIC_TAG_INFO->getArtist();
			tag["Album"] = m_MUSIC_TAG_INFO->getAlbum();
			tag["Duration"] = m_MUSIC_TAG_INFO->getDuration();	
			coverPicture = m_MUSIC_TAG_INFO->getCoverPicture();
			m_MUSIC_TAG_INFO->unloadSong();
			//检查文件信息结束	
			TitleLabel->setText(tag["Title"]);
			ArtistLabel->setText(tag["Artist"]);
			AlbumImageWidget->setCoverImage(coverPicture);
			LeftTime->setText(tag["Duration"]);		
			m_MUSIC_PLAYER->loadFile(fileName[0]);
			ProgressSlider->setRange(0, (int)m_MUSIC_PLAYER->getTotalLength());
			qDebug() << m_MUSIC_PLAYER->getTotalLength();
			fileName.clear();
		}
			
		
	});
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
		[=]() { 
		SettingView *settingview = new SettingView(this);  
		settingview->show(); });

	menu->addAction(HiddenAction);
	connect(HiddenAction, &QAction::triggered, this,
		[=]() {
		hide(); 
		systemTray->show(); });

	menu->addAction(AboutAction);
	connect(AboutAction, &QAction::triggered, this,
		[=]() { 
		AboutView *aboutview = new AboutView(this); 
		aboutview->exec(); });
	menu->addSeparator();
	menu->addAction(deleteAction);
	connect(deleteAction, &QAction::triggered, this,
		[=]() { qApp->exit(); });
	menu->exec(cur.pos());
}
