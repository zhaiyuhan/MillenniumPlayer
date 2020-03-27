#pragma once

#include <QSystemTrayIcon>
#include "3rdparty/QMW/Includes/qtmaterialiconbutton.h"
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

		PlayButton = new QtMaterialIconButton(QIcon(":/Icons/play.svg"));
		PreviousButton = new QtMaterialIconButton(QIcon(":/Icons/previous.svg"));
		NextButton = new QtMaterialIconButton(QIcon(":/Icons/next.svg"));
		TitleLabel = new QLabel();
		volumeSlider = new QSlider();
		volumeSlider->setOrientation(Qt::Horizontal);

		TitleLabel->setFixedWidth(60);
		TitleLabel->setAlignment(Qt::AlignCenter);
		PlayButton->setIconSize(QSize(32, 32));
		PlayButton->setColor(Qt::white);
		PreviousButton->setIconSize(QSize(16, 16));
		PreviousButton->setColor(Qt::white);
		NextButton->setIconSize(QSize(16,16));
		NextButton->setColor(Qt::white);

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
		TitleLabel->setText(QString::fromLocal8Bit("ÔÝÎÞ²¥·Å"));
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
	QtMaterialIconButton*PlayButton;
	QtMaterialIconButton*PreviousButton;
	QtMaterialIconButton*NextButton;
	QSlider * volumeSlider;
	QLabel *TitleLabel;
	QWidget * m_playWidget;
	QWidgetAction * m_playWidgetAction;
	QAction * m_settingAction;
	QAction * m_showAction;
	QAction * m_exitAction;
	Menu * m_menu;
};
