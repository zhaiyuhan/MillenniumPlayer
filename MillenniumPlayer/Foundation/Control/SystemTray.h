#pragma once

#include <QSystemTrayIcon>

class SystemTray : public QSystemTrayIcon
{
	Q_OBJECT

public:
	SystemTray(QWidget *parent);
	~SystemTray();
private:
	void createActions()
	{
		m_settingAction = new QAction("Setting", this);
		m_settingAction->setIcon(QIcon(":/Icons/setting.svg"));
		m_showAction = new QAction("Show View", this);
		m_exitAction = new QAction("Exit", this);
		m_exitAction->setIcon(QIcon(":/Icons/exit.svg"));
	}

	void createWidgetAction()
	{
		m_playWidget = new QWidget();

		PlayButton = new QPushButton();
		PreviousButton = new QPushButton();
		NextButton = new QPushButton();
		TitleLabel = new QLabel();
		volumeSlider = new QSlider();
		volumeSlider->setOrientation(Qt::Horizontal);

		TitleLabel->setFixedWidth(60);
		TitleLabel->setAlignment(Qt::AlignCenter);
		QPixmap play_pixmap(":/Icons/play.svg");
		PlayButton->setIcon(play_pixmap);
		PlayButton->setIconSize(QSize(32, 32));
		PlayButton->setObjectName("transparentButton");
		PlayButton->setFlat(true);

		QPixmap  backward_pixmap(":/Icons/previous.svg");
		PreviousButton->setIcon(backward_pixmap);
		PreviousButton->setIconSize(QSize(16, 16));
		PreviousButton->setObjectName("transparentButton");
		PreviousButton->setFlat(true);

		QPixmap forward_pixmap(":/Icons/next.svg");
		NextButton->setIcon(forward_pixmap);
		NextButton->setIconSize(QSize(16,16));
		NextButton->setObjectName("transparentButton");
		NextButton->setFlat(true);

		QHBoxLayout *layout = new QHBoxLayout();
		layout->addWidget(PreviousButton);
		layout->addWidget(PlayButton);
		layout->addWidget(NextButton);
		layout->setSpacing(0);
		layout->setContentsMargins(20, 20, 20, 40);

		QVBoxLayout *layout2 = new QVBoxLayout();
		layout2->addLayout(layout);
		layout2->addWidget(TitleLabel, 0, Qt::AlignCenter);
		layout2->addWidget(volumeSlider, 0, Qt::AlignCenter);
		layout2->setSpacing(5);
		layout2->setContentsMargins(0, 0, 0, 5);
		TitleLabel->setText("player");
		TitleLabel->setEnabled(false);
		m_playWidget->setLayout(layout2);

		m_playWidgetAction = new QWidgetAction(m_menu);
		m_playWidgetAction->setDefaultWidget(m_playWidget);
	}

	void createMenu()
	{
		createActions();		
		m_menu = new Menu();
		createWidgetAction();
		m_menu->addAction(m_playWidgetAction);
		m_menu->addSeparator();
		m_menu->addAction(m_settingAction);
		m_menu->addSeparator();
		m_menu->addAction(m_showAction);
		m_menu->addAction(m_exitAction);		
	}
private:
	QPushButton *PlayButton;
	QPushButton *PreviousButton;
	QPushButton *NextButton;
	QSlider * volumeSlider;
	QLabel *TitleLabel;
	QWidget * m_playWidget;
	QWidgetAction * m_playWidgetAction;
	QAction * m_settingAction;
	QAction * m_showAction;
	QAction * m_exitAction;
	Menu * m_menu;
};
