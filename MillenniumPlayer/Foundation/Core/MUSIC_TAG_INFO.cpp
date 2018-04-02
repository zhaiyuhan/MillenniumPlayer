#include "stdafx.h"
#include "MUSIC_TAG_INFO.h"
#pragma execution_character_set("utf-8")
using namespace TagLib;

MUSIC_TAG_INFO::MUSIC_TAG_INFO(QObject *parent)
	: QThread(parent)
{
	m_file = nullptr;
}

MUSIC_TAG_INFO::~MUSIC_TAG_INFO()
{
	unloadSong();
}

void MUSIC_TAG_INFO::loadSong(QString& _filepath)
{
	m_name = _filepath;
	if (_filepath.startsWith("http"))
	{
		m_isLocalFile = false;
	}
	m_isLocalFile = true;
	m_file = 
		new TagLib::FileRef(reinterpret_cast<const wchar_t *>(m_name.constData()));
}

void MUSIC_TAG_INFO::unloadSong()
{
	if (m_file)
	{
		delete m_file;
		m_file = nullptr;
	}
}

QString MUSIC_TAG_INFO::getTitle()
{
	HandleUnknowFile();
	TagLib::String songTitle = m_file->tag()->title();
	QString title = QString::fromStdWString(songTitle.toCWString());
	return title;
}

QString MUSIC_TAG_INFO::getArtist()
{
	HandleUnknowFile();
	TagLib::String songArtist = m_file->tag()->artist();
	QString artist = QString::fromStdWString(songArtist.toCWString());
	return artist;
}

QString MUSIC_TAG_INFO::getAlbum()
{
	HandleUnknowFile();
	TagLib::String songAlbum = m_file->tag()->album();
	QString album = QString::fromStdWString(songAlbum.toCWString());
	return album;
}

QString MUSIC_TAG_INFO::getDuration()
{
	if (!m_file->audioProperties()) {
		return QString::fromUtf8("Unknow֪");
	}
	TagLib::AudioProperties *properties = m_file->audioProperties();
	QTime songDuration(0, 0, 0, 0);
	songDuration = songDuration.addSecs(properties->length());
	return songDuration.toString("mm:ss");
}

QImage MUSIC_TAG_INFO::getCoverPicture()
{
	QImage image;

	if (!isCoverImageValid())
		return image;

	if (auto *file = dynamic_cast<TagLib::APE::File *>(m_file->file()))
	{
		if (file->APETag())
			image = fromApe(file->APETag());
	}
	else if (auto *file = dynamic_cast<TagLib::ASF::File *>(m_file->file()))
	{
		if (file->tag())
			image = fromAsf(file->tag());
	}
	else if (auto *file = dynamic_cast<TagLib::FLAC::File *>(m_file->file()))
	{
		image = fromFlac(file);

		if (image.isNull() && file->ID3v2Tag())
			image = fromId3(file->ID3v2Tag());
	}
	else if (auto *file = dynamic_cast<TagLib::MP4::File *>(m_file->file()))
	{
		if (file->tag())
			image = fromMp4(file->tag());
	}
	else if (auto *file = dynamic_cast<TagLib::MPC::File *>(m_file->file()))
	{
		if (file->APETag())
			image = fromApe(file->APETag());
	}
	else if (auto *file = dynamic_cast<TagLib::MPEG::File *>(m_file->file()))
	{
		if (file->ID3v2Tag())
			image = fromId3(file->ID3v2Tag());

		if (image.isNull() && file->APETag())
			image = fromApe(file->APETag());
	}
	else if (auto *file = dynamic_cast<TagLib::Ogg::Vorbis::File *>(m_file->file()))
	{
		if (file->tag())
			image = fromVorbis(file->tag());
	}
	else if (auto *file = dynamic_cast<TagLib::WavPack::File *>(m_file->file())) {

		if (file->APETag())
			image = fromApe(file->APETag());
	}
	return image;
}

bool MUSIC_TAG_INFO::isCoverImageValid() const
{
	return (m_file && m_file->file() && m_file->file()->isValid());
}

QImage MUSIC_TAG_INFO::fromTagBytes(const TagLib::ByteVector & data) const
{
	QImage image;
	image.loadFromData((const uchar *)data.data(), data.size());
	return image;
}

QImage MUSIC_TAG_INFO::fromApe(TagLib::APE::Tag * tag) const
{
	const TagLib::APE::ItemListMap &map = tag->itemListMap();

	TagLib::String str = "COVER ART (FRONT)";
	if (!map.contains(str))
		return QImage();

	TagLib::String fileName = map[str].toString();
	TagLib::ByteVector item = map[str].value();
	return fromTagBytes(item.mid(fileName.size() + 1));
}

QImage MUSIC_TAG_INFO::fromAsf(TagLib::ASF::Tag * tag) const
{
	const TagLib::ASF::AttributeListMap &map = tag->attributeListMap();

	TagLib::String str = "WM/Picture";
	if (!map.contains(str))
		return QImage();

	const TagLib::ASF::AttributeList &list = map[str];
	if (list.isEmpty())
		return QImage();

	TagLib::ASF::Picture pic = list[0].toPicture();
	if (pic.isValid())
		return fromTagBytes(pic.picture());
	return QImage();
}

QImage MUSIC_TAG_INFO::fromFlac(TagLib::FLAC::File * file) const
{
	const TagLib::List<TagLib::FLAC::Picture *> &list = file->pictureList();
	if (list.isEmpty())
		return QImage();

	TagLib::FLAC::Picture *pic = list[0];
	return fromTagBytes(pic->data());
}

QImage MUSIC_TAG_INFO::fromId3(TagLib::ID3v2::Tag * tag) const
{
	const TagLib::ID3v2::FrameList &list = tag->frameList("APIC");
	if (list.isEmpty())
		return QImage();

	auto *frame = static_cast<TagLib::ID3v2::AttachedPictureFrame *>(list.front());
	return fromTagBytes(frame->picture());
}

QImage MUSIC_TAG_INFO::fromMp4(TagLib::MP4::Tag * tag) const
{
	TagLib::String str = "covr";
	if (!tag->itemListMap().contains(str))
		return QImage();

	TagLib::MP4::CoverArtList coverList = tag->itemListMap()[str].toCoverArtList();
	if (coverList[0].data().size() > 0)
		return fromTagBytes(coverList[0].data());

	return QImage();
}

QImage MUSIC_TAG_INFO::fromVorbis(TagLib::Tag * tag) const
{
	if (auto *comment = dynamic_cast<TagLib::Ogg::XiphComment *>(tag)) {
		TagLib::String str = "COVERART";

		if (!comment->contains(str))
			str = "METADATA_BLOCK_PICTURE";

		if (!comment->contains(str))
			return QImage();

		TagLib::ByteVector tagBytes = comment->fieldListMap()[str].front().data(TagLib::String::Latin1);
		QByteArray base64;
		base64.setRawData(tagBytes.data(), tagBytes.size());
		QImage image;
		image.loadFromData(QByteArray::fromBase64(base64));
		return image;
	}

	return QImage();
}
