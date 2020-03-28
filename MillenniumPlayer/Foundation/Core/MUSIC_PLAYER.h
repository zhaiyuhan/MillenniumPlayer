#pragma once

#include <QThread>

#include "3rdparty/BASS/Includes/bass.h"
class MUSIC_PLAYER : public QThread
{
	Q_OBJECT

public:
	explicit MUSIC_PLAYER(QObject *parent);
	~MUSIC_PLAYER();
	double getTotalLength();
Q_SIGNALS:
	void loadFileFinished();
	void songFinished();
	void positionUpdated();
	void positionChanged(double Position);
	void PlayState(bool _isplaying);

public Q_SLOTS:
    void loadFile(QString& _filepath);
    void play();
	void pause();
	void resume();
	void stop();
	void setVolume(int vol);
	void setPosition(double position);
	QString updateTime();
	void update();

private:
	unsigned long m_stream;
	QTimer * m_timer;

};
