#pragma once

#include <QThread>
#include "3rdparty/BASS/Includes/bass.h"
class MUSIC_PLAYER : public QThread
{
	Q_OBJECT

public:
	explicit MUSIC_PLAYER(QObject *parent);
	~MUSIC_PLAYER();

Q_SIGNALS:
	void loadFileFinished();
	void songFinished();
	void positionUpdated();
	void positionChanged(int Position);
	void PlayState(bool _isplaying);

public Q_SLOTS:
    void loadFile(QString& _filepath);
    void play();
	void pause();
	void resume();
	void stop();
	void setVolume(int vol);
	void setPosition(int position);
	QString updateTime();
	void update();

private:
	unsigned long m_chan;
	QTimer * m_timer;

};
