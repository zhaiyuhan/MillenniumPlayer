#pragma once

#include <QThread>
#include "3dParty/taglib/tag.h"
#include "3dParty/taglib/fileref.h"
#include "3dParty/taglib/toolkit/tstringlist.h"
#include "3dParty/taglib/audioproperties.h"
#include "3dParty/taglib/toolkit/tbytevector.h"
#include "3dParty/taglib/toolkit/tfile.h"
#include "3dParty/taglib/toolkit/tpropertymap.h"
#include "3dParty/taglib/mpeg/mpegfile.h"
#include "3dParty/taglib/mpeg/id3v2/id3v2framefactory.h"
#include "3dParty/taglib/mpeg/id3v2/id3v2tag.h"
#include "3dParty/taglib/mpeg/id3v2/id3v2frame.h"
#include "3dParty/taglib/mpeg/mpegfile.h"
#include "3dParty/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
#include "3dParty/taglib/ape/apefile.h"
#include "3dParty/taglib/ape/apeitem.h"
#include "3dParty/taglib/ape/apetag.h"
#include "3dParty/taglib/asf/asffile.h"
#include "3dParty/taglib/flac/flacfile.h"
#include "3dParty/taglib/mod/modfile.h"
#include "3dParty/taglib/mp4/mp4file.h"
#include "3dParty/taglib/mpc/mpcfile.h"
#include "3dParty/taglib/ogg/oggfile.h"
#include "3dParty/taglib/ogg/vorbis/vorbisfile.h"
#include "3dParty/taglib/ogg/vorbis/vorbisproperties.h"
#include "3dParty/taglib/ogg/xiphcomment.h"
#include "3dParty/taglib/wavpack/wavpackfile.h"
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
