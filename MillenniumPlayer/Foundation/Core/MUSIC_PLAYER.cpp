#include "stdafx.h"
#include "MUSIC_PLAYER.h"

void CALLBACK syncFunc(HSYNC handle, DWORD channel, DWORD data, void *user);

MUSIC_PLAYER::MUSIC_PLAYER(QObject *parent)
	: QThread(parent)
{
	BASS_SetConfig(BASS_CONFIG_FLOATDSP, TRUE);
	if (!BASS_Init(-1, 44100, 0, NULL, NULL))
		return;
	BASS_SetVolume(0.06); // default

	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this,
		[=]() { emit positionUpdated(); });
	connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	connect(this, SIGNAL(songFinished()), this, SLOT(pause()));
}

MUSIC_PLAYER::~MUSIC_PLAYER()
{
	BASS_ChannelStop(m_stream);
	BASS_MusicFree(m_stream);
	BASS_StreamFree(m_stream);
	BASS_Stop();
	BASS_Free();
}

double MUSIC_PLAYER::getTotalLength()
{
	return BASS_ChannelBytes2Seconds(m_stream, BASS_ChannelGetLength(m_stream, BASS_POS_BYTE));
}

void MUSIC_PLAYER::loadFile(QString& _filepath)
{
	//释放先前资源
	BASS_ChannelStop(m_stream);
	BASS_MusicFree(m_stream);
	BASS_StreamFree(m_stream);
	m_timer->stop();
	//转码
	const wchar_t * encoded_filepath = reinterpret_cast<const wchar_t *>(_filepath.utf16());
	if (!(m_stream = BASS_StreamCreateFile(false, encoded_filepath, 0, 0, BASS_SAMPLE_LOOP | BASS_SAMPLE_FX))
		&& !(m_stream = BASS_MusicLoad(false, encoded_filepath, 0, 0, BASS_MUSIC_RAMP | BASS_SAMPLE_LOOP | BASS_SAMPLE_FX, 1))
		&& !(m_stream = BASS_StreamCreateURL(_filepath.toUtf8().constData(), 0, BASS_SAMPLE_LOOP | BASS_SAMPLE_FX, 0, 0)))
		return;
	else {
		BASS_ChannelPlay(m_stream, true);
		m_timer->start(100);
		BASS_ChannelSetSync(m_stream, BASS_SYNC_POS, 0, &syncFunc, 0);
		emit(PlayState(false));
	}

}

void MUSIC_PLAYER::play()
{
	switch (BASS_ChannelIsActive(m_stream))
	{
	case BASS_ACTIVE_STOPPED:
		BASS_ChannelPlay(m_stream, true);
		m_timer->start(100);
		BASS_ChannelSetSync(m_stream, BASS_SYNC_POS, 0, &syncFunc, 0);
		emit(PlayState(false));
	case BASS_ACTIVE_PLAYING:
		emit(PlayState(true));
		pause();
		break;
	case BASS_ACTIVE_PAUSED:
		emit(PlayState(false));
		m_timer->start(100);
		BASS_ChannelPlay(m_stream, false);
		break;
	default:
		BASS_ChannelPlay(m_stream, true);
		m_timer->start(100);
		BASS_ChannelSetSync(m_stream, BASS_SYNC_POS, 0, &syncFunc, 0);
		break;
	}
}

void MUSIC_PLAYER::pause()
{
	BASS_ChannelPause(m_stream);
	m_timer->stop();
}

void MUSIC_PLAYER::resume()
{
	if (!BASS_ChannelPlay(m_stream, false))
		return;
	else {
		m_timer->start(98);
	}
}

void MUSIC_PLAYER::stop()
{
	BASS_ChannelStop(m_stream);
	m_timer->stop();

}

void MUSIC_PLAYER::setVolume(int vol)
{
	float bassvol = (float)vol / 400.0f;
	BASS_SetVolume(bassvol);
}

void MUSIC_PLAYER::setPosition(double position)
{
	BASS_ChannelSetPosition(m_stream, BASS_ChannelSeconds2Bytes(m_stream, position), BASS_POS_BYTE);
}

QString MUSIC_PLAYER::updateTime()
{
	if (BASS_ChannelIsActive(m_stream) != BASS_ACTIVE_STOPPED)
	{
		QTime elapsedtime(0, 0, 0, 0);
		elapsedtime = elapsedtime.addSecs(BASS_ChannelBytes2Seconds(m_stream, BASS_ChannelGetPosition(m_stream, BASS_POS_BYTE)));
		return elapsedtime.toString("mm:ss");
	
	}
	return QString();
}

void MUSIC_PLAYER::update()
{
	if (BASS_ChannelIsActive(m_stream) != BASS_ACTIVE_STOPPED) {
		emit positionChanged(BASS_ChannelBytes2Seconds(m_stream, BASS_ChannelGetPosition(m_stream, BASS_POS_BYTE)));	
	}
	else {
		emit songFinished();
	}
}

void syncFunc(HSYNC handle, DWORD channel, DWORD data, void * user)
{
	BASS_ChannelRemoveSync(channel, handle);
	BASS_ChannelStop(channel);
}
