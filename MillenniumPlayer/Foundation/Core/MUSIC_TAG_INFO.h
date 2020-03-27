#pragma once

#include <QThread>
#include "3rdparty/TagLib/Includes/tag.h"
#include "3rdparty/TagLib/Includes//fileref.h"
#include "3rdparty/TagLib/Includes/tstringlist.h"
#include "3rdparty/TagLib/Includes/audioproperties.h"
#include "3rdparty/TagLib/Includes/tbytevector.h"
#include "3rdparty/TagLib/Includes/tfile.h"
#include "3rdparty/TagLib/Includes/tpropertymap.h"
#include "3rdparty/TagLib/Includes/mpegfile.h"
#include "3rdparty/TagLib/Includes/id3v2framefactory.h"
#include "3rdparty/TagLib/Includes/id3v2tag.h"
#include "3rdparty/TagLib/Includes/id3v2frame.h"
#include "3rdparty/TagLib/Includes/mpegfile.h"
#include "3rdparty/TagLib/Includes/attachedpictureframe.h"
#include "3rdparty/TagLib/Includes/apefile.h"
#include "3rdparty/TagLib/Includes/apeitem.h"
#include "3rdparty/TagLib/Includes/apetag.h"
#include "3rdparty/TagLib/Includes/asffile.h"
#include "3rdparty/TagLib/Includes/flacfile.h"
#include "3rdparty/TagLib/Includes/modfile.h"
#include "3rdparty/TagLib/Includes/mp4file.h"
#include "3rdparty/TagLib/Includes/mpcfile.h"
#include "3rdparty/TagLib/Includes/oggfile.h"
#include "3rdparty/TagLib/Includes/vorbisfile.h"
#include "3rdparty/TagLib/Includes/vorbisproperties.h"
#include "3rdparty/TagLib/Includes/xiphcomment.h"
#include "3rdparty/TagLib/Includes/wavpackfile.h"
class MUSIC_TAG_INFO : public QThread
{
	Q_OBJECT

public:
	explicit MUSIC_TAG_INFO(QObject *parent);
	~MUSIC_TAG_INFO();

	void loadSong(QString& _filepath);
	void unloadSong();
	
	QString getTitle();//标题
	QString getArtist();//艺术家
	QString getAlbum();//专家
	QString getDuration();//时长
	QImage getCoverPicture();
	bool isCoverImageValid() const;
protected:
	QImage fromTagBytes(const TagLib::ByteVector &data) const;
	QImage fromApe(TagLib::APE::Tag *tag) const;
	QImage fromAsf(TagLib::ASF::Tag *tag) const;
	QImage fromFlac(TagLib::FLAC::File *file) const;
	QImage fromId3(TagLib::ID3v2::Tag *tag) const;
	QImage fromMp4(TagLib::MP4::Tag *tag) const;
	QImage fromVorbis(TagLib::Tag *tag) const;
private:
	QString HandleUnknowFile()
	{
		if (!m_file->tag())
		{
			return QString::fromUtf8("未知");
		}
		return QString::fromUtf8("未知");
	}
	QString m_name;
	bool m_isLocalFile;
	TagLib::FileRef * m_file;
};
