#pragma once

#include <QWidget>

class InformationView : public QWidget
{
	Q_OBJECT

public:
	explicit InformationView(QWidget *parent = Q_NULLPTR);
	~InformationView();

	void updateInformation(QMap<QString, QString>& _tag, QImage& _coverimage);
protected:
	void setupUI()
	{
		AlbumImageWidget = new ImageWidget(this);
		AlbumImageWidget->setFixedSize(QSize(300, 300));
		TitleLabel = new Label(this, QString("Title"));
		TitleLabel->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
		Artist_AlbumLabel = new Label(this, QString("Artist - Album"));
		Artist_AlbumLabel->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
		QFont f;// ("Microsoft YaHei", 10, QFont::Light);
		f.setFamily("Microsoft YaHei UI Light");
		f.setPointSize(20);
		TitleLabel->setFont(f);
		f.setPointSize(16);
		Artist_AlbumLabel->setFont(f);
	}
	void initLayouts()
	{
		QVBoxLayout *m_mainlayout = new QVBoxLayout(this);
		m_mainlayout->setMargin(0);
		m_mainlayout->addWidget(AlbumImageWidget);
		m_mainlayout->addWidget(TitleLabel);
		m_mainlayout->addWidget(Artist_AlbumLabel);
	}
	void initView();

private:
	QVBoxLayout * m_mainlayout;
	ImageWidget * AlbumImageWidget;
	Label * TitleLabel;
	Label * Artist_AlbumLabel;
	
};
