#pragma once

// JPEG / image-data helpers shared by the AVM1 tag recompiler (swf.cpp) and
// the AVM2/ABC character scanner (abc/abc_timeline.cpp). Both have to turn a
// DefineBits{,JPEG2,JPEG3,JPEG4} payload into pixels at recompile time, and
// both hit the same two SWF quirks: the spurious EOI+SOI sequence Flash's
// exporter leaves in the stream, and the missing trailing EOI that optimizers
// strip.

#include <cstddef>
#include <cstring>

namespace SWFRecomp
{

enum class JpegTagFormat { Jpeg, Png, Gif, Unknown };

inline JpegTagFormat detectImageFormat(const unsigned char* data, size_t len)
{
	if (len >= 2 && data[0] == 0xFF && data[1] == 0xD8) return JpegTagFormat::Jpeg;
	if (len >= 4 && data[0] == 0xFF && data[1] == 0xD9
		&& data[2] == 0xFF && data[3] == 0xD8) return JpegTagFormat::Jpeg;
	static const unsigned char PNG_MAGIC[8] = {0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A};
	if (len >= 8 && memcmp(data, PNG_MAGIC, 8) == 0) return JpegTagFormat::Png;
	if (len >= 6 && data[0] == 0x47 && data[1] == 0x49 && data[2] == 0x46
		&& data[3] == 0x38 && (data[4] == 0x37 || data[4] == 0x39)
		&& data[5] == 0x61) return JpegTagFormat::Gif;
	return JpegTagFormat::Unknown;
}

// Splice a spurious FF D9 FF D8 (EOI+SOI) sequence out of JPEG data wherever
// it appears before the SOF0 marker. Per Ruffle's remove_invalid_jpeg_data
// (render/src/utils.rs:84 — see ruffle-rs/ruffle#8775). Mutates `len` and
// the buffer in place via memmove. Safe no-op if no such sequence found
// before SOF0, or if marker parsing gets confused — bails defensively.
inline bool stripInvalidJpegMarkers(unsigned char* data, size_t& len)
{
	const unsigned char SOI = 0xD8;
	const unsigned char EOI = 0xD9;
	const unsigned char SOF0 = 0xC0;

	// Fast path: strip a single leading FF D9 FF D8 by memmoving down 4.
	// (We may still need the walker below if a *second* spurious sequence
	// sits mid-stream — rare but cheap to check.)
	bool stripped_leading = false;
	if (len >= 4 && data[0] == 0xFF && data[1] == EOI
		&& data[2] == 0xFF && data[3] == SOI)
	{
		memmove(data, data + 4, len - 4);
		len -= 4;
		stripped_leading = true;
	}

	// Walk markers looking for an interior EOI+SOI before SOF0.
	size_t pos = 0;
	while (pos + 4 <= len)
	{
		if (data[pos] != 0xFF) return stripped_leading; // not a JPEG / lost the thread
		unsigned char m = data[pos + 1];

		if (m == EOI && data[pos + 2] == 0xFF && data[pos + 3] == SOI)
		{
			// Splice out these 4 bytes.
			memmove(data + pos, data + pos + 4, len - pos - 4);
			len -= 4;
			return true;
		}

		if (m == SOF0) return stripped_leading; // reached real frame header
		if (m == SOI || m == EOI || (m >= 0xD0 && m <= 0xD7))
		{
			// Standalone marker, no payload length.
			pos += 2;
			continue;
		}

		// Segment with length: [FF mm len_hi len_lo ...] — length includes its own 2 bytes.
		size_t seg_len = ((size_t) data[pos + 2] << 8) | (size_t) data[pos + 3];
		if (seg_len < 2 || pos + 2 + seg_len > len) return stripped_leading; // malformed; bail
		pos += 2 + seg_len;
	}

	return stripped_leading;
}

// Some JPEGs are missing the trailing FF D9 (optimizers strip it). stb_image
// can refuse those, so glue one on if absent. Caller passes a buffer that
// has room for +2 bytes; if it doesn't, returns false without writing.
inline bool appendTrailingEoiIfMissing(unsigned char* data, size_t& len, size_t cap)
{
	if (len >= 2 && data[len - 2] == 0xFF && data[len - 1] == 0xD9) return false;
	if (len + 2 > cap) return false;
	data[len++] = 0xFF;
	data[len++] = 0xD9;
	return true;
}

}  // namespace SWFRecomp
