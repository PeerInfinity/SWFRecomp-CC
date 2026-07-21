// AVM2 static timeline tables (see abc_timeline.hpp). Byte-level tag
// reader over the decompressed stream; emission contract in
// SWFModernRuntime/include/avm2/avm2_abc.h ("Static timeline tables").

#include <abc/abc_timeline.hpp>

#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

#include <zlib.h>

namespace SWFRecomp
{
namespace abc
{

namespace
{

// SWF tag codes handled here.
enum
{
	TAG_END = 0,
	TAG_SHOW_FRAME = 1,
	TAG_DEFINE_SHAPE = 2,
	TAG_PLACE_OBJECT = 4,
	TAG_REMOVE_OBJECT = 5,
	TAG_DEFINE_BITS = 6,
	TAG_DEFINE_BUTTON = 7,
	TAG_SET_BACKGROUND_COLOR = 9,
	TAG_DEFINE_SOUND = 14,
	TAG_DEFINE_TEXT = 11,
	TAG_DEFINE_BINARY_DATA = 87,
	TAG_DEFINE_BITS_JPEG2 = 21,
	TAG_DEFINE_SHAPE2 = 22,
	TAG_PLACE_OBJECT2 = 26,
	TAG_REMOVE_OBJECT2 = 28,
	TAG_DEFINE_SHAPE3 = 32,
	TAG_DEFINE_TEXT2 = 33,
	TAG_DEFINE_BUTTON2 = 34,
	TAG_DEFINE_BITS_JPEG3 = 35,
	TAG_DEFINE_BITS_LOSSLESS = 20,
	TAG_DEFINE_BITS_LOSSLESS2 = 36,
	TAG_DEFINE_EDIT_TEXT = 37,
	TAG_DEFINE_SPRITE = 39,
	TAG_DEFINE_FONT2 = 48,
	TAG_CSM_TEXT_SETTINGS = 74,
	TAG_DEFINE_FONT3 = 75,
	TAG_FRAME_LABEL = 43,
	TAG_DEFINE_MORPH_SHAPE = 46,
	TAG_DEFINE_VIDEO_STREAM = 60,
	TAG_PLACE_OBJECT3 = 70,
	TAG_DEFINE_SHAPE4 = 83,
	TAG_DEFINE_MORPH_SHAPE2 = 84,
	TAG_DEFINE_SCENE_AND_FRAME_LABEL_DATA = 86,
	TAG_DEFINE_BITS_JPEG4 = 90,
};

struct ByteReader
{
	const uint8_t* p;
	const uint8_t* end;

	bool ok(size_t n) const { return p + n <= end; }
	uint8_t u8() { return ok(1) ? *p++ : (p = end, 0); }
	uint16_t u16()
	{
		if (!ok(2)) { p = end; return 0; }
		uint16_t v = (uint16_t) (p[0] | (p[1] << 8));
		p += 2;
		return v;
	}
	uint32_t u32()
	{
		if (!ok(4)) { p = end; return 0; }
		uint32_t v = (uint32_t) p[0] | ((uint32_t) p[1] << 8)
		           | ((uint32_t) p[2] << 16) | ((uint32_t) p[3] << 24);
		p += 4;
		return v;
	}
	uint32_t encodedU32()
	{
		uint32_t v = 0;
		for (int shift = 0; shift < 35 && ok(1); shift += 7)
		{
			uint8_t b = *p++;
			v |= (uint32_t) (b & 0x7F) << shift;
			if ((b & 0x80) == 0) break;
		}
		return v;
	}
	std::string cstr()
	{
		std::string s;
		while (ok(1) && *p != 0) s.push_back((char) *p++);
		if (ok(1)) p++;  // NUL
		return s;
	}
	void skip(size_t n) { p = (p + n <= end) ? p + n : end; }
};

struct BitReader
{
	ByteReader& r;
	uint32_t bit;  // 0..7 within *r.p

	explicit BitReader(ByteReader& br) : r(br), bit(0) {}

	uint32_t ub(uint32_t n)
	{
		uint32_t v = 0;
		for (uint32_t i = 0; i < n; i++)
		{
			if (!r.ok(1)) return v << (n - i);
			uint32_t b = (*r.p >> (7 - bit)) & 1;
			v = (v << 1) | b;
			if (++bit == 8)
			{
				bit = 0;
				r.p++;
			}
		}
		return v;
	}
	int32_t sb(uint32_t n)
	{
		uint32_t v = ub(n);
		if (n > 0 && (v & (1u << (n - 1))))
		{
			v |= ~((1u << n) - 1);
		}
		return (int32_t) v;
	}
	void align()
	{
		if (bit != 0)
		{
			bit = 0;
			r.p++;
		}
	}
};

struct Matrix
{
	float a = 1, b = 0, c = 0, d = 1;
	int32_t tx = 0, ty = 0;
};

Matrix parseMatrix(ByteReader& r)
{
	Matrix m;
	BitReader br(r);
	if (br.ub(1))
	{
		uint32_t nbits = br.ub(5);
		m.a = (float) (br.sb(nbits) / 65536.0);
		m.d = (float) (br.sb(nbits) / 65536.0);
	}
	if (br.ub(1))
	{
		uint32_t nbits = br.ub(5);
		m.b = (float) (br.sb(nbits) / 65536.0);
		m.c = (float) (br.sb(nbits) / 65536.0);
	}
	uint32_t tbits = br.ub(5);
	m.tx = br.sb(tbits);
	m.ty = br.sb(tbits);
	br.align();
	return m;
}

void skipRect(ByteReader& r, int32_t* out /* xmin xmax ymin ymax or NULL */)
{
	BitReader br(r);
	uint32_t nbits = br.ub(5);
	int32_t v[4];
	for (int i = 0; i < 4; i++) v[i] = br.sb(nbits);
	br.align();
	if (out != nullptr)
	{
		out[0] = v[0];
		out[1] = v[1];
		out[2] = v[2];
		out[3] = v[3];
	}
}

void skipCxform(ByteReader& r, bool with_alpha)
{
	BitReader br(r);
	uint32_t has_add = br.ub(1);
	uint32_t has_mult = br.ub(1);
	uint32_t nbits = br.ub(4);
	uint32_t terms = with_alpha ? 4 : 3;
	if (has_mult) br.ub(nbits * terms);
	if (has_add) br.ub(nbits * terms);
	br.align();
}

// SurfaceFilterList skip (PlaceObject3 / ButtonRecord2). Filter payload
// sizes per SWF spec.
void skipFilterList(ByteReader& r)
{
	uint32_t n = r.u8();
	for (uint32_t i = 0; i < n && r.ok(1); i++)
	{
		uint8_t id = r.u8();
		switch (id)
		{
			case 0: r.skip(23); break;             // DropShadow
			case 1: r.skip(9); break;              // Blur
			case 2: r.skip(15); break;             // Glow
			case 3: r.skip(27); break;             // Bevel
			case 4:                                 // GradientGlow
			case 7:                                 // GradientBevel
			{
				uint32_t nc = r.u8();
				r.skip(nc * 5 + 19);
				break;
			}
			case 5:                                 // Convolution
			{
				uint32_t mx = r.u8();
				uint32_t my = r.u8();
				r.skip(4 + 4 + 4 * mx * my + 4 + 1);
				break;
			}
			case 6: r.skip(80); break;             // ColorMatrix
			default: r.p = r.end; break;           // unknown: bail on this list
		}
	}
}

// Decode a DefineBitsLossless/2 payload to STRAIGHT RGBA (R,G,B,A per pixel,
// row-major). Ported from Ruffle render/src/utils.rs decode_define_bits_lossless.
// `version` is 1 or 2; `format` is the SWF BitmapFormat byte (3 ColorMap8,
// 4 Rgb15, 5 Rgb32). `num_colors` is BitmapColorTableSize (colors - 1), only
// meaningful for format 3. `z`/`zlen` is the zlib-compressed pixel data.
// Returns false (out untouched) on any decode error.
bool decodeLossless(int version, int format, uint32_t w, uint32_t h,
                    uint32_t num_colors, const uint8_t* z, size_t zlen,
                    std::vector<uint8_t>& out)
{
	if (w == 0 || h == 0) return false;
	bool has_alpha = (version == 2);
	// Compute the expected decompressed size per format.
	size_t decomp_size = 0;
	uint32_t padded_width = w;
	uint32_t palette_bytes = 0;
	if (format == 3)
	{
		palette_bytes = (num_colors + 1) * (has_alpha ? 4u : 3u);
		padded_width = (w + 3u) & ~3u;
		decomp_size = palette_bytes + (size_t) padded_width * h;
	}
	else if (format == 4)
	{
		if (version != 1) return false;  // Rgb15 is v1 only
		padded_width = (w + 1u) & ~1u;
		decomp_size = (size_t) padded_width * h * 2;
	}
	else if (format == 5)
	{
		decomp_size = (size_t) w * h * 4;
	}
	else
	{
		return false;
	}

	std::vector<uint8_t> d(decomp_size);
	uLongf dlen = (uLongf) decomp_size;
	if (uncompress(d.data(), &dlen, z, (uLong) zlen) != Z_OK
	    || (size_t) dlen != decomp_size)
	{
		return false;
	}

	out.assign((size_t) w * h * 4, 0);
	size_t o = 0;
	if (format == 5)
	{
		// Stored ARGB (v2 premultiplied per spec; kept as-is, matching
		// Ruffle) — rotate_left(1): [a,r,g,b] -> [r,g,b,a].
		for (uint32_t p = 0; p < w * h; p++)
		{
			uint8_t a = d[p * 4 + 0], r = d[p * 4 + 1];
			uint8_t g = d[p * 4 + 2], b = d[p * 4 + 3];
			out[o++] = r;
			out[o++] = g;
			out[o++] = b;
			out[o++] = has_alpha ? a : 255;
		}
	}
	else if (format == 4)
	{
		size_t i = 0;
		for (uint32_t y = 0; y < h; y++)
		{
			for (uint32_t x = 0; x < w; x++)
			{
				uint16_t c = (uint16_t) ((d[i] << 8) | d[i + 1]);
				auto comp = [c](int shift) -> uint8_t {
					uint32_t v = (c >> shift) & 0x1F;
					return (uint8_t) ((v * 255 + 15) / 31);
				};
				out[o++] = comp(10);
				out[o++] = comp(5);
				out[o++] = comp(0);
				out[o++] = 255;
				i += 2;
			}
			i += (size_t) (padded_width - w) * 2;
		}
	}
	else  // format 3, ColorMap8
	{
		size_t i = 0;
		struct Col { uint8_t r, g, b, a; };
		std::vector<Col> pal(num_colors + 1);
		for (uint32_t p = 0; p <= num_colors; p++)
		{
			Col c;
			c.r = d[i]; c.g = d[i + 1]; c.b = d[i + 2];
			c.a = has_alpha ? d[i + 3] : 255;
			pal[p] = c;
			i += has_alpha ? 4 : 3;
		}
		for (uint32_t y = 0; y < h; y++)
		{
			for (uint32_t x = 0; x < w; x++)
			{
				uint32_t e = d[i];
				Col c;
				if (e < pal.size()) c = pal[e];
				else { c.r = c.g = c.b = 0; c.a = has_alpha ? 0 : 255; }
				out[o++] = c.r;
				out[o++] = c.g;
				out[o++] = c.b;
				out[o++] = c.a;
				i += 1;
			}
			i += (size_t) (padded_width - w);
		}
	}
	return true;
}

struct BitmapAsset
{
	uint16_t char_id;
	uint16_t width, height;
	uint8_t transparency;
	std::vector<uint8_t> rgba;  // empty if decode failed
};

struct BinaryAsset
{
	uint16_t char_id;
	std::vector<uint8_t> bytes;
};

struct SoundAsset
{
	uint16_t char_id;
	uint8_t format, rate, sample_size, stereo;
	uint32_t sample_count;
	uint32_t data_size;
	// Full payload (all remaining tag bytes, incl. the 2-byte MP3 seek
	// prefix) — emitted so the runtime mixer can decode and play it.
	std::vector<uint8_t> payload;
};

struct TOp
{
	uint8_t kind = 0;
	uint8_t flags = 0;
	uint8_t visible = 1;
	uint16_t char_id = 0;
	uint16_t depth = 0;
	uint16_t clip_depth = 0;
	uint16_t ratio = 0;
	bool has_name = false;
	std::string name;
	Matrix mtx;
};

// Flag bits mirror AVM2_TLF_* in avm2_abc.h.
enum
{
	TLF_HAS_CHAR = 1 << 0,
	TLF_MOVE = 1 << 1,
	TLF_HAS_MATRIX = 1 << 2,
	TLF_HAS_NAME = 1 << 3,
	TLF_HAS_CLIP_DEPTH = 1 << 4,
	TLF_HAS_RATIO = 1 << 5,
	TLF_HAS_VISIBLE = 1 << 6,
};

struct Timeline
{
	uint16_t char_id = 0;
	uint32_t declared_frames = 0;
	std::vector<std::vector<TOp>> frames;   // closed frames (ShowFrame)
	std::vector<TOp> current;               // ops since the last ShowFrame
	std::vector<std::pair<uint32_t, std::string>> labels;

	void showFrame()
	{
		frames.push_back(current);
		current.clear();
	}
	void finish()
	{
		// Trailing ops without a ShowFrame still form a (partial) frame —
		// zero-frame sprites keep frame_count 0 when there are no ops.
		if (!current.empty())
		{
			frames.push_back(current);
			current.clear();
		}
	}
};

struct CharInfo
{
	uint16_t char_id;
	uint8_t kind;  // AVM2_CHAR_*
	int32_t bounds[4] = { 0, 0, 0, 0 };
	bool has_text = false;
	std::string init_text;
};

// Full DefineEditText data (flag bits mirror AVM2_ETF_* in avm2_abc.h).
struct EditTextDef
{
	uint16_t char_id = 0;
	uint16_t flags = 0;
	uint16_t font_id = 0;
	bool has_font_class = false;
	std::string font_class;
	uint16_t font_height = 0;
	uint32_t color_rgba = 0;
	uint16_t max_length = 0;
	uint8_t align = 0;
	uint16_t left_margin = 0, right_margin = 0, indent = 0;
	int16_t leading = 0;
	std::string variable_name;
	bool has_text = false;
	std::string raw_text;
	// CSMTextSettings (tag 74).
	bool has_render_settings = false;
	uint8_t aa_advanced = 0;
	uint8_t grid_fit = 0;
	float cs_thickness = 0, cs_sharpness = 0;
};

// DefineFont2/3 measurement data + glyph outlines (RWK-2: the outlines feed
// the runtime CPU rasterizer behind BitmapData.draw(TextField)).
struct FontDef
{
	uint16_t font_id = 0;
	std::string name;
	bool bold = false, italic = false, has_layout = false;
	uint16_t em_square = 1024;
	int32_t ascent = 0, descent = 0, leading = 0;
	std::vector<uint16_t> codes;
	std::vector<int16_t> advances;
	// Flattened contour polylines in font units (quadratic curves subdivided
	// at parse time). Contours of glyph g are contour indices
	// [glyph_contour_start[g], glyph_contour_start[g+1]); contour k's points
	// are pair indices [k == glyph_contour_start[g] ? glyph_pt_start[g]
	// : contour_ends[k-1], contour_ends[k]) into glyph_pts.
	std::vector<int32_t> glyph_pts;             // x,y pairs
	std::vector<uint32_t> glyph_pt_start;       // nglyphs+1
	std::vector<uint32_t> glyph_contour_ends;   // absolute pair indices
	std::vector<uint32_t> glyph_contour_start;  // nglyphs+1
};

// LSB-first SWF bit reader for glyph SHAPE records.
struct GlyphBitReader
{
	const uint8_t* p;
	const uint8_t* end;
	uint32_t bit = 0;  // bits consumed in *p

	uint32_t ub(uint32_t n)
	{
		uint32_t v = 0;
		for (uint32_t i = 0; i < n; i++)
		{
			if (p >= end) return v << (n - i);
			v = (v << 1) | ((*p >> (7 - bit)) & 1);
			if (++bit == 8) { bit = 0; p++; }
		}
		return v;
	}
	int32_t sb(uint32_t n)
	{
		uint32_t v = ub(n);
		if (n > 0 && (v & (1u << (n - 1)))) v |= ~((1u << n) - 1);
		return (int32_t) v;
	}
};

// Parse one glyph SHAPE (no styles): flatten contours into fd. Quadratic
// curves are subdivided into 8 segments — glyphs render at text sizes, where
// that is well under half a pixel of error.
static void parseGlyphShape(const uint8_t* p, const uint8_t* end, FontDef& fd)
{
	GlyphBitReader r{p, end};
	uint32_t fill_bits = r.ub(4);
	uint32_t line_bits = r.ub(4);
	int32_t px = 0, py = 0;
	std::vector<int32_t> cur;  // x,y pairs of the open contour

	auto flush = [&]() {
		if (cur.size() >= 6)  // a fillable contour needs >= 3 points
		{
			fd.glyph_pts.insert(fd.glyph_pts.end(), cur.begin(), cur.end());
			fd.glyph_contour_ends.push_back((uint32_t) (fd.glyph_pts.size() / 2));
		}
		cur.clear();
	};

	for (;;)
	{
		if (r.p >= r.end) break;
		if (r.ub(1) == 0)  // non-edge record
		{
			uint32_t flags = r.ub(5);
			if (flags == 0) break;  // EndShapeRecord
			if (flags & 0x10) break;  // StateNewStyles: invalid in a glyph
			if (flags & 0x01)  // MoveTo (absolute)
			{
				uint32_t nb = r.ub(5);
				px = r.sb(nb);
				py = r.sb(nb);
				flush();
			}
			if (flags & 0x02) r.ub(fill_bits);  // FillStyle0
			if (flags & 0x04) r.ub(fill_bits);  // FillStyle1
			if (flags & 0x08) r.ub(line_bits);  // LineStyle
		}
		else if (r.ub(1))  // straight edge
		{
			uint32_t nb = r.ub(4) + 2;
			int32_t dx = 0, dy = 0;
			if (r.ub(1)) { dx = r.sb(nb); dy = r.sb(nb); }
			else if (r.ub(1)) dy = r.sb(nb);
			else dx = r.sb(nb);
			if (cur.empty()) { cur.push_back(px); cur.push_back(py); }
			px += dx;
			py += dy;
			cur.push_back(px);
			cur.push_back(py);
		}
		else  // curved edge (quadratic)
		{
			uint32_t nb = r.ub(4) + 2;
			int32_t cdx = r.sb(nb), cdy = r.sb(nb);
			int32_t adx = r.sb(nb), ady = r.sb(nb);
			double x0 = px, y0 = py;
			double cx = px + cdx, cy = py + cdy;
			double ax = cx + adx, ay = cy + ady;
			if (cur.empty()) { cur.push_back(px); cur.push_back(py); }
			for (int k = 1; k <= 8; k++)
			{
				double t = k / 8.0, u = 1.0 - t;
				double qx = u * u * x0 + 2.0 * u * t * cx + t * t * ax;
				double qy = u * u * y0 + 2.0 * u * t * cy + t * t * ay;
				cur.push_back((int32_t) lround(qx));
				cur.push_back((int32_t) lround(qy));
			}
			px = (int32_t) lround(ax);
			py = (int32_t) lround(ay);
		}
	}
	flush();
}

struct ButtonRec
{
	uint16_t char_id;
	uint16_t depth;
	uint8_t state_flags;
	Matrix mtx;
};

struct ButtonDef
{
	uint16_t char_id;
	std::vector<ButtonRec> records;
};

struct Scanner
{
	std::vector<Timeline> timelines;
	std::vector<CharInfo> chars;
	std::vector<ButtonDef> buttons;
	std::vector<EditTextDef> edittexts;
	std::vector<FontDef> fonts;
	std::vector<BitmapAsset> bitmaps;
	std::vector<BinaryAsset> binaries;
	std::vector<SoundAsset> sounds;
	struct CsmSettings
	{
		uint16_t char_id;
		uint8_t aa_advanced, grid_fit;
		float thickness, sharpness;
	};
	std::vector<CsmSettings> csm;
	std::vector<std::pair<uint32_t, std::string>> scenes;  // (offset, name)
	std::vector<std::pair<uint32_t, std::string>> scene_labels;
	uint32_t bg_color = 0xFFFFFF;
	bool bg_seen = false;

	void parsePlace(ByteReader r, int tag_code, Timeline& tl)
	{
		TOp op;
		op.kind = 0;
		if (tag_code == TAG_PLACE_OBJECT)
		{
			op.char_id = r.u16();
			op.depth = r.u16();
			op.mtx = parseMatrix(r);
			op.flags = TLF_HAS_CHAR | TLF_HAS_MATRIX;
			tl.current.push_back(op);
			return;
		}
		bool is_po3 = (tag_code == TAG_PLACE_OBJECT3);
		uint8_t flags = r.u8();
		uint8_t flags2 = is_po3 ? r.u8() : 0;
		bool has_clip_actions = (flags & 0x80) != 0;
		bool has_clip_depth = (flags & 0x40) != 0;
		bool has_name = (flags & 0x20) != 0;
		bool has_ratio = (flags & 0x10) != 0;
		bool has_color = (flags & 0x08) != 0;
		bool has_matrix = (flags & 0x04) != 0;
		bool has_char = (flags & 0x02) != 0;
		bool move = (flags & 0x01) != 0;
		bool has_filters = (flags2 & 0x01) != 0;
		bool has_blend = (flags2 & 0x02) != 0;
		bool has_cache = (flags2 & 0x04) != 0;
		bool has_class_name = (flags2 & 0x08) != 0;
		bool has_image = (flags2 & 0x10) != 0;
		bool has_visible = (flags2 & 0x20) != 0;
		bool has_bg = (flags2 & 0x40) != 0;
		(void) has_clip_actions;

		op.depth = r.u16();
		// ClassName present iff HAS_CLASS_NAME, or an image with NO character
		// id (Ruffle read.rs:1911 — the SWF19 spec's "HasImage && HasChar"
		// wording is wrong; a bitmap placed by id has no className).
		if (is_po3 && (has_class_name || (has_image && !has_char)))
		{
			r.cstr();
		}
		if (has_char)
		{
			op.char_id = r.u16();
			op.flags |= TLF_HAS_CHAR;
		}
		if (move) op.flags |= TLF_MOVE;
		if (has_matrix)
		{
			op.mtx = parseMatrix(r);
			op.flags |= TLF_HAS_MATRIX;
		}
		if (has_color) skipCxform(r, true);
		if (has_ratio)
		{
			op.ratio = r.u16();
			op.flags |= TLF_HAS_RATIO;
		}
		if (has_name)
		{
			op.name = r.cstr();
			op.has_name = true;
			op.flags |= TLF_HAS_NAME;
		}
		if (has_clip_depth)
		{
			op.clip_depth = r.u16();
			op.flags |= TLF_HAS_CLIP_DEPTH;
		}
		if (is_po3)
		{
			if (has_filters) skipFilterList(r);
			if (has_blend) r.u8();
			if (has_cache) r.u8();
			if (has_visible)
			{
				op.visible = r.u8();
				op.flags |= TLF_HAS_VISIBLE;
			}
			if (has_bg) r.u32();
		}
		tl.current.push_back(op);
	}

	void parseButton(ByteReader r, int tag_code)
	{
		ButtonDef bd;
		bd.char_id = r.u16();
		if (tag_code == TAG_DEFINE_BUTTON2)
		{
			r.u8();   // flags (track as menu)
			r.u16();  // action offset
		}
		while (r.ok(1))
		{
			uint8_t rec_flags = r.u8();
			if (rec_flags == 0) break;
			ButtonRec rec;
			rec.state_flags = rec_flags & 0x0F;
			rec.char_id = r.u16();
			rec.depth = r.u16();
			rec.mtx = parseMatrix(r);
			if (tag_code == TAG_DEFINE_BUTTON2)
			{
				skipCxform(r, true);
				if (rec_flags & 0x10) skipFilterList(r);
				if (rec_flags & 0x20) r.u8();  // blend mode
			}
			bd.records.push_back(rec);
		}
		buttons.push_back(bd);
	}

	void defineChar(ByteReader r, uint8_t kind, bool has_rect_bounds)
	{
		CharInfo ci;
		ci.char_id = r.u16();
		ci.kind = kind;
		if (has_rect_bounds)
		{
			skipRect(r, ci.bounds);
		}
		chars.push_back(ci);
	}

	// Scan one tag stream (main or sprite body) into `tl`. Returns after
	// TAG_END or when the reader is exhausted.
	void scanStream(ByteReader& r, Timeline& tl, bool is_root)
	{
		while (r.ok(2))
		{
			uint16_t cl = r.u16();
			uint16_t code = cl >> 6;
			uint32_t len = cl & 0x3F;
			if (len == 0x3F) len = r.u32();
			if (!r.ok(len)) break;
			ByteReader body = { r.p, r.p + len };
			r.skip(len);

			switch (code)
			{
				case TAG_END:
					return;
				case TAG_SHOW_FRAME:
					tl.showFrame();
					break;
				case TAG_PLACE_OBJECT:
				case TAG_PLACE_OBJECT2:
				case TAG_PLACE_OBJECT3:
					parsePlace(body, code, tl);
					break;
				case TAG_REMOVE_OBJECT:
				case TAG_REMOVE_OBJECT2:
				{
					TOp op;
					op.kind = 1;
					if (code == TAG_REMOVE_OBJECT) body.u16();  // char id
					op.depth = body.u16();
					tl.current.push_back(op);
					break;
				}
				case TAG_FRAME_LABEL:
				{
					std::string label = body.cstr();
					tl.labels.push_back({ (uint32_t) tl.frames.size(), label });
					break;
				}
				default:
					if (is_root) defineTag(body, code);
					break;
			}
		}
	}

	void defineTag(ByteReader body, uint16_t code)
	{
		switch (code)
		{
			case TAG_SET_BACKGROUND_COLOR:
			{
				uint32_t rr = body.u8(), gg = body.u8(), bb = body.u8();
				// FP keeps only the FIRST SetBackgroundColor.
				if (!bg_seen)
				{
					bg_color = (rr << 16) | (gg << 8) | bb;
					bg_seen = true;
				}
				break;
			}
			case TAG_DEFINE_SHAPE:
			case TAG_DEFINE_SHAPE2:
			case TAG_DEFINE_SHAPE3:
			case TAG_DEFINE_SHAPE4:
				defineChar(body, 0 /* SHAPE */, true);
				break;
			case TAG_DEFINE_MORPH_SHAPE:
			case TAG_DEFINE_MORPH_SHAPE2:
				defineChar(body, 6 /* MORPHSHAPE */, true);
				break;
			case TAG_DEFINE_TEXT:
			case TAG_DEFINE_TEXT2:
				defineChar(body, 3 /* TEXT */, true);
				break;
			case TAG_DEFINE_EDIT_TEXT:
			{
				CharInfo ci;
				EditTextDef et;
				ci.char_id = body.u16();
				et.char_id = ci.char_id;
				ci.kind = 4;  // EDITTEXT
				skipRect(body, ci.bounds);
				uint8_t f1 = body.u8();
				uint8_t f2 = body.u8();
				bool has_text = (f1 & 0x80) != 0;
				bool has_text_color = (f1 & 0x04) != 0;
				bool has_max_length = (f1 & 0x02) != 0;
				bool has_font = (f1 & 0x01) != 0;
				bool has_font_class = (f2 & 0x80) != 0;
				bool has_layout = (f2 & 0x20) != 0;
				// Flag bits mirror AVM2_ETF_* (avm2_abc.h).
				if (f1 & 0x40) et.flags |= 1 << 0;   // word wrap
				if (f1 & 0x20) et.flags |= 1 << 1;   // multiline
				if (f1 & 0x10) et.flags |= 1 << 2;   // password
				if (f1 & 0x08) et.flags |= 1 << 3;   // read only
				if (f2 & 0x40) et.flags |= 1 << 4;   // auto size
				if (f2 & 0x10) et.flags |= 1 << 5;   // no select
				if (f2 & 0x08) et.flags |= 1 << 6;   // border
				if (f2 & 0x04) et.flags |= 1 << 7;   // was static
				if (f2 & 0x02) et.flags |= 1 << 8;   // html
				if (f2 & 0x01) et.flags |= 1 << 9;   // use outlines
				if (has_font) et.flags |= 1 << 10;
				if (has_font_class) et.flags |= 1 << 11;
				if (has_text_color) et.flags |= 1 << 12;
				if (has_max_length) et.flags |= 1 << 13;
				if (has_layout) et.flags |= 1 << 14;
				if (has_text) et.flags |= 1 << 15;
				if (has_font) et.font_id = body.u16();
				if (has_font_class)
				{
					et.has_font_class = true;
					et.font_class = body.cstr();
				}
				if (has_font) et.font_height = body.u16();
				if (has_text_color)
				{
					uint32_t rr = body.u8(), gg = body.u8(), bb = body.u8(),
					         aa = body.u8();
					et.color_rgba = (rr << 24) | (gg << 16) | (bb << 8) | aa;
				}
				if (has_max_length) et.max_length = body.u16();
				if (has_layout)
				{
					et.align = body.u8();
					et.left_margin = body.u16();
					et.right_margin = body.u16();
					et.indent = body.u16();
					et.leading = (int16_t) body.u16();
				}
				et.variable_name = body.cstr();
				if (has_text)
				{
					et.has_text = true;
					et.raw_text = std::string();  // filled below alongside ci
				}
				if (has_text)
				{
					ci.has_text = true;
					std::string raw = body.cstr();
					et.raw_text = raw;
					bool is_html = (f2 & 0x02) != 0;
					if (!is_html)
					{
						ci.init_text = raw;
					}
					else
					{
						// TextField.text returns the PLAIN text: tags
						// stripped, </p> becomes a newline, basic
						// entities decoded.
						std::string out;
						for (size_t i = 0; i < raw.size(); )
						{
							if (raw[i] == '<')
							{
								size_t close = raw.find('>', i);
								std::string tag = raw.substr(i + 1,
									close == std::string::npos ? std::string::npos
									                           : close - i - 1);
								if (tag == "/p" || tag == "/P") out += '\n';
								i = (close == std::string::npos) ? raw.size()
								                                 : close + 1;
							}
							else if (raw.compare(i, 5, "&amp;") == 0)
							{
								out += '&';
								i += 5;
							}
							else if (raw.compare(i, 4, "&lt;") == 0)
							{
								out += '<';
								i += 4;
							}
							else if (raw.compare(i, 4, "&gt;") == 0)
							{
								out += '>';
								i += 4;
							}
							else if (raw.compare(i, 6, "&quot;") == 0)
							{
								out += '"';
								i += 6;
							}
							else if (raw.compare(i, 6, "&apos;") == 0)
							{
								out += '\'';
								i += 6;
							}
							else
							{
								out += raw[i++];
							}
						}
						ci.init_text = out;
					}
				}
				chars.push_back(ci);
				edittexts.push_back(et);
				break;
			}
			case TAG_CSM_TEXT_SETTINGS:
			{
				uint16_t text_id = body.u16();
				uint8_t bits = body.u8();
				uint8_t use_flash_type = (bits >> 6) & 0x3;
				uint8_t grid = (bits >> 3) & 0x7;
				uint32_t th = body.u32();
				uint32_t sh = body.u32();
				CsmSettings cs;
				cs.char_id = text_id;
				cs.aa_advanced = use_flash_type != 0;
				cs.grid_fit = grid > 2 ? 0 : (uint8_t) grid;
				memcpy(&cs.thickness, &th, 4);
				memcpy(&cs.sharpness, &sh, 4);
				csm.push_back(cs);
				break;
			}
			case TAG_DEFINE_FONT2:
			case TAG_DEFINE_FONT3:
			{
				FontDef fd;
				fd.font_id = body.u16();
				uint8_t fflags = body.u8();
				bool font_has_layout = (fflags & 0x80) != 0;
				bool wide_offsets = (fflags & 0x08) != 0;
				bool wide_codes = (fflags & 0x04) != 0;
				fd.italic = (fflags & 0x02) != 0;
				fd.bold = (fflags & 0x01) != 0;
				fd.has_layout = font_has_layout;
				fd.em_square = (code == TAG_DEFINE_FONT3) ? 20480 : 1024;
				body.u8();  // language code
				uint8_t name_len = body.u8();
				for (uint8_t i = 0; i < name_len; i++)
				{
					char c = (char) body.u8();
					if (c != '\0') fd.name += c;
				}
				uint16_t nglyphs = body.u16();
				// Offset table start is the reference point for the glyph
				// offsets and the code-table offset. A 0-glyph device font
				// omits the remaining tables (Ruffle read.rs).
				const uint8_t* offtab = body.p;
				uint32_t code_table_off = 0;
				std::vector<uint32_t> glyph_offsets;
				if (nglyphs > 0)
				{
					glyph_offsets.reserve(nglyphs);
					for (uint16_t i = 0; i < nglyphs; i++)
					{
						glyph_offsets.push_back(wide_offsets ? body.u32()
						                                     : body.u16());
					}
					code_table_off = wide_offsets ? body.u32() : body.u16();
				}
				// Parse each glyph SHAPE into flattened contour outlines
				// (the CPU rasterizer behind BitmapData.draw(TextField)).
				for (uint16_t i = 0; i < nglyphs; i++)
				{
					fd.glyph_pt_start.push_back(
						(uint32_t) (fd.glyph_pts.size() / 2));
					fd.glyph_contour_start.push_back(
						(uint32_t) (fd.glyph_contour_ends.size()));
					uint32_t g0 = glyph_offsets[i];
					uint32_t g1 = i + 1 < nglyphs ? glyph_offsets[i + 1]
					                              : code_table_off;
					if (g1 <= g0 || offtab + g1 > body.end) continue;
					parseGlyphShape(offtab + g0, offtab + g1, fd);
				}
				fd.glyph_pt_start.push_back((uint32_t) (fd.glyph_pts.size() / 2));
				fd.glyph_contour_start.push_back(
					(uint32_t) (fd.glyph_contour_ends.size()));
				// Jump to the code table.
				if (nglyphs > 0 && offtab + code_table_off <= body.end)
				{
					body.p = offtab + code_table_off;
					for (uint16_t i = 0; i < nglyphs; i++)
					{
						fd.codes.push_back(wide_codes || code == TAG_DEFINE_FONT3
						                   ? body.u16() : body.u8());
					}
					if (font_has_layout)
					{
						fd.ascent = body.u16();
						fd.descent = body.u16();
						fd.leading = (int16_t) body.u16();
						for (uint16_t i = 0; i < nglyphs; i++)
						{
							fd.advances.push_back((int16_t) body.u16());
						}
						// Glyph bounds + kerning follow; not needed.
					}
				}
				fonts.push_back(fd);
				// Fonts are not placeable characters: no CharInfo entry.
				break;
			}
			case TAG_DEFINE_BITS:
			case TAG_DEFINE_BITS_JPEG2:
			case TAG_DEFINE_BITS_JPEG3:
			case TAG_DEFINE_BITS_JPEG4:
				defineChar(body, 5 /* BITMAP */, false);
				break;
			case TAG_DEFINE_BITS_LOSSLESS:
			case TAG_DEFINE_BITS_LOSSLESS2:
			{
				CharInfo ci;
				ci.char_id = body.u16();
				ci.kind = 5;  // BITMAP
				uint8_t format = body.u8();
				int32_t w = body.u16();
				int32_t h = body.u16();
				ci.bounds[0] = 0;
				ci.bounds[1] = w * 20;
				ci.bounds[2] = 0;
				ci.bounds[3] = h * 20;
				chars.push_back(ci);
				int version = (code == TAG_DEFINE_BITS_LOSSLESS2) ? 2 : 1;
				uint32_t num_colors = 0;
				if (format == 3) num_colors = body.u8();  // BitmapColorTableSize
				BitmapAsset ba;
				ba.char_id = ci.char_id;
				ba.width = (uint16_t) w;
				ba.height = (uint16_t) h;
				ba.transparency = (version == 2) ? 1 : 0;
				// Remaining body bytes are the zlib-compressed pixel data.
				if (body.p < body.end)
				{
					decodeLossless(version, format, (uint32_t) w, (uint32_t) h,
					               num_colors, body.p,
					               (size_t) (body.end - body.p), ba.rgba);
				}
				bitmaps.push_back(ba);
				break;
			}
			case TAG_DEFINE_BINARY_DATA:
			{
				BinaryAsset ba;
				ba.char_id = body.u16();
				body.u32();  // reserved (always 0)
				if (body.p < body.end)
				{
					ba.bytes.assign(body.p, body.end);
				}
				binaries.push_back(ba);
				// Not a placeable character, but record a CharInfo so
				// SymbolClass binding resolution can classify it.
				CharInfo ci;
				ci.char_id = ba.char_id;
				ci.kind = 8;  // OTHER
				chars.push_back(ci);
				break;
			}
			case TAG_DEFINE_SOUND:
			{
				SoundAsset sa;
				sa.char_id = body.u16();
				uint8_t bits = body.u8();
				sa.format = (bits >> 4) & 0x0F;
				sa.rate = (bits >> 2) & 0x03;
				sa.sample_size = (bits >> 1) & 0x01;
				sa.stereo = bits & 0x01;
				sa.sample_count = body.u32();
				// Payload = the remaining tag bytes; Ruffle's SoundInstance
				// size excludes the 2-byte MP3 seek-samples prefix.
				{
					size_t payload = (size_t) (body.end - body.p);
					if (sa.format == 2 && payload >= 2) payload -= 2;
					sa.data_size = (uint32_t) payload;
				}
				if (body.p < body.end)
				{
					sa.payload.assign(body.p, body.end);
				}
				sounds.push_back(sa);
				break;
			}
			case TAG_DEFINE_VIDEO_STREAM:
				defineChar(body, 7 /* VIDEO */, false);
				break;
			case TAG_DEFINE_BUTTON:
			case TAG_DEFINE_BUTTON2:
			{
				CharInfo ci;
				ci.char_id = (uint16_t) (body.p[0] | (body.p[1] << 8));
				ci.kind = 2;  // BUTTON
				chars.push_back(ci);
				parseButton(body, code);
				break;
			}
			case TAG_DEFINE_SPRITE:
			{
				Timeline sub;
				sub.char_id = body.u16();
				sub.declared_frames = body.u16();
				scanStream(body, sub, false);
				sub.finish();
				CharInfo ci;
				ci.char_id = sub.char_id;
				ci.kind = 1;  // SPRITE
				chars.push_back(ci);
				timelines.push_back(sub);
				break;
			}
			case TAG_DEFINE_SCENE_AND_FRAME_LABEL_DATA:
			{
				uint32_t nscenes = body.encodedU32();
				for (uint32_t i = 0; i < nscenes; i++)
				{
					uint32_t off = body.encodedU32();
					std::string name = body.cstr();
					scenes.push_back({ off, name });
				}
				uint32_t nlabels = body.encodedU32();
				for (uint32_t i = 0; i < nlabels; i++)
				{
					uint32_t frame = body.encodedU32();
					std::string label = body.cstr();
					scene_labels.push_back({ frame, label });
				}
				break;
			}
			default:
				break;
		}
	}
};

std::string cEscape(const std::string& s)
{
	std::string out;
	for (char ch : s)
	{
		unsigned char u = (unsigned char) ch;
		if (ch == '"' || ch == '\\')
		{
			out.push_back('\\');
			out.push_back(ch);
		}
		else if (u < 0x20 || u == 0x7F)
		{
			char buf[8];
			snprintf(buf, sizeof(buf), "\\%03o", u);
			out += buf;
		}
		else
		{
			out.push_back(ch);
		}
	}
	return out;
}

std::string fmtFloat(float f)
{
	// %.9g alone can produce "1", which is not a float literal with an f
	// suffix appended; ensure a decimal point or exponent first.
	char buf[64];
	snprintf(buf, sizeof(buf), "%.9g", (double) f);
	if (strchr(buf, '.') == nullptr && strchr(buf, 'e') == nullptr
	    && strchr(buf, 'n') == nullptr /* nan/inf */)
	{
		strcat(buf, ".0");
	}
	strcat(buf, "f");
	return buf;
}

}  // namespace

void emitAvm2Timeline(const uint8_t* tags_start, const uint8_t* end,
                      const TimelineEmitInfo& info,
                      const std::string& output_folder)
{
	Scanner sc;
	Timeline root;
	root.char_id = 0;
	root.declared_frames = info.header_frame_count;
	ByteReader r = { tags_start, end };
	sc.scanStream(r, root, true);
	root.finish();
	// Root goes first; sprites follow in definition order.
	sc.timelines.insert(sc.timelines.begin(), root);
	// Root frame labels: when DefineSceneAndFrameLabelData exists (any
	// scenes), plain FrameLabel tags are IGNORED — even if the scene data
	// carries zero labels (Ruffle movie_clip.rs frame_label gate;
	// movieclip_currentlabels_dupes2).
	if (!sc.scenes.empty())
	{
		sc.timelines[0].labels = sc.scene_labels;
	}

	std::ostringstream out;
	out << "// Generated by SWFRecomp (abc_timeline.cpp). Do not edit.\n";
	out << "#include \"abc_gen.h\"\n\n";

	for (size_t t = 0; t < sc.timelines.size(); t++)
	{
		const Timeline& tl = sc.timelines[t];
		size_t total_ops = 0;
		for (auto& f : tl.frames) total_ops += f.size();
		if (total_ops > 0)
		{
			out << "static const Avm2TimelineOp tl_" << t << "_ops[] = {\n";
			for (auto& f : tl.frames)
			{
				for (auto& op : f)
				{
					out << "\t{ " << (int) op.kind << ", " << (int) op.flags
					    << ", " << (int) op.visible << ", " << op.char_id
					    << ", " << op.depth << ", " << op.clip_depth << ", "
					    << op.ratio << ", "
					    << (op.has_name ? ("\"" + cEscape(op.name) + "\"")
					                    : std::string("NULL"))
					    << ", " << fmtFloat(op.mtx.a) << ", " << fmtFloat(op.mtx.b)
					    << ", " << fmtFloat(op.mtx.c) << ", " << fmtFloat(op.mtx.d)
					    << ", " << op.mtx.tx << ", " << op.mtx.ty << " },\n";
				}
			}
			out << "};\n";
		}
		out << "static const uint32_t tl_" << t << "_starts[] = { ";
		uint32_t acc = 0;
		out << acc;
		for (auto& f : tl.frames)
		{
			acc += (uint32_t) f.size();
			out << ", " << acc;
		}
		out << " };\n";
		if (!tl.labels.empty())
		{
			out << "static const Avm2FrameLabelData tl_" << t << "_labels[] = {\n";
			for (auto& l : tl.labels)
			{
				out << "\t{ " << l.first << ", \"" << cEscape(l.second) << "\" },\n";
			}
			out << "};\n";
		}
	}

	out << "\nconst Avm2TimelineData avm2_generated_timelines[] = {\n";
	for (size_t t = 0; t < sc.timelines.size(); t++)
	{
		const Timeline& tl = sc.timelines[t];
		size_t total_ops = 0;
		for (auto& f : tl.frames) total_ops += f.size();
		out << "\t{ " << tl.char_id << ", " << tl.frames.size() << ", "
		    << tl.declared_frames << ", "
		    << (total_ops > 0 ? ("tl_" + std::to_string(t) + "_ops")
		                      : std::string("NULL"))
		    << ", tl_" << t << "_starts, " << tl.labels.size() << ", "
		    << (!tl.labels.empty() ? ("tl_" + std::to_string(t) + "_labels")
		                           : std::string("NULL"))
		    << " },\n";
	}
	out << "};\n";
	out << "const uint32_t avm2_generated_timeline_count = "
	    << sc.timelines.size() << ";\n\n";

	if (!sc.chars.empty())
	{
		out << "const Avm2CharInfo avm2_generated_chars[] = {\n";
		for (auto& ci : sc.chars)
		{
			out << "\t{ " << ci.char_id << ", " << (int) ci.kind << ", "
			    << ci.bounds[0] << ", " << ci.bounds[1] << ", " << ci.bounds[2]
			    << ", " << ci.bounds[3] << ", "
			    << (ci.has_text ? ("\"" + cEscape(ci.init_text) + "\"")
			                    : std::string("NULL"))
			    << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2CharInfo avm2_generated_chars[1];\n";
	}
	out << "const uint32_t avm2_generated_char_count = " << sc.chars.size()
	    << ";\n\n";

	// Shape geometry table (char_id -> shape_data vertex range), from the
	// recompiler's tessellation pass. Drives the AVM2 solid-fill render walk
	// (renderer_draw_shape). Present only when the caller recorded shapes.
	{
		const std::vector<Avm2ShapeGeomRec> empty_geom;
		const std::vector<Avm2ShapeGeomRec>& geom =
			info.shape_geom != nullptr ? *info.shape_geom : empty_geom;
		if (!geom.empty())
		{
			out << "const Avm2ShapeGeom avm2_generated_shape_geom[] = {\n";
			for (auto& g : geom)
			{
				out << "\t{ " << g.char_id << ", " << (int) g.solid_only << ", "
				    << g.vert_offset << ", " << g.vert_count << ", "
				    << g.morph_end_offset << " },\n";
			}
			out << "};\n";
		}
		else
		{
			out << "const Avm2ShapeGeom avm2_generated_shape_geom[1];\n";
		}
		out << "const uint32_t avm2_generated_shape_geom_count = "
		    << geom.size() << ";\n\n";
	}

	if (!sc.scenes.empty())
	{
		out << "const Avm2SceneData avm2_generated_scenes[] = {\n";
		for (auto& s : sc.scenes)
		{
			out << "\t{ \"" << cEscape(s.second) << "\", " << s.first << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2SceneData avm2_generated_scenes[1];\n";
	}
	out << "const uint32_t avm2_generated_scene_count = " << sc.scenes.size()
	    << ";\n\n";

	for (size_t i = 0; i < sc.buttons.size(); i++)
	{
		const ButtonDef& bd = sc.buttons[i];
		if (bd.records.empty()) continue;
		out << "static const Avm2ButtonRecordData btn_" << i << "_recs[] = {\n";
		for (auto& rec : bd.records)
		{
			out << "\t{ " << rec.char_id << ", " << rec.depth << ", "
			    << (int) rec.state_flags << ", 1, " << fmtFloat(rec.mtx.a)
			    << ", " << fmtFloat(rec.mtx.b) << ", " << fmtFloat(rec.mtx.c)
			    << ", " << fmtFloat(rec.mtx.d) << ", " << rec.mtx.tx << ", "
			    << rec.mtx.ty << " },\n";
		}
		out << "};\n";
	}
	if (!sc.buttons.empty())
	{
		out << "const Avm2ButtonData avm2_generated_buttons[] = {\n";
		for (size_t i = 0; i < sc.buttons.size(); i++)
		{
			const ButtonDef& bd = sc.buttons[i];
			out << "\t{ " << bd.char_id << ", " << bd.records.size() << ", "
			    << (bd.records.empty() ? std::string("NULL")
			                           : ("btn_" + std::to_string(i) + "_recs"))
			    << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2ButtonData avm2_generated_buttons[1];\n";
	}
	out << "const uint32_t avm2_generated_button_count = " << sc.buttons.size()
	    << ";\n\n";

	for (auto& cs : sc.csm)
	{
		for (auto& et : sc.edittexts)
		{
			if (et.char_id == cs.char_id)
			{
				et.has_render_settings = true;
				et.aa_advanced = cs.aa_advanced;
				et.grid_fit = cs.grid_fit;
				et.cs_thickness = cs.thickness;
				et.cs_sharpness = cs.sharpness;
			}
		}
	}
	if (!sc.edittexts.empty())
	{
		out << "const Avm2EditTextData avm2_generated_edittexts[] = {\n";
		for (auto& et : sc.edittexts)
		{
			out << "\t{ " << et.char_id << ", " << et.flags << ", "
			    << et.font_id << ", "
			    << (et.has_font_class ? ("\"" + cEscape(et.font_class) + "\"")
			                          : std::string("NULL"))
			    << ", " << et.font_height << ", 0x" << std::hex
			    << et.color_rgba << std::dec << "u, " << et.max_length << ", "
			    << (int) et.align << ", " << et.left_margin << ", "
			    << et.right_margin << ", " << et.indent << ", " << et.leading
			    << ", "
			    << (!et.variable_name.empty()
			        ? ("\"" + cEscape(et.variable_name) + "\"")
			        : std::string("NULL"))
			    << ", "
			    << (et.has_text ? ("\"" + cEscape(et.raw_text) + "\"")
			                    : std::string("NULL"))
			    << ", " << (et.has_render_settings ? 1 : 0) << ", "
			    << (int) et.aa_advanced << ", " << (int) et.grid_fit << ", "
			    << fmtFloat(et.cs_thickness) << ", " << fmtFloat(et.cs_sharpness)
			    << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2EditTextData avm2_generated_edittexts[1];\n";
	}
	out << "const uint32_t avm2_generated_edittext_count = "
	    << sc.edittexts.size() << ";\n\n";

	for (size_t i = 0; i < sc.fonts.size(); i++)
	{
		const FontDef& fd = sc.fonts[i];
		if (!fd.codes.empty())
		{
			out << "static const uint16_t font_" << i << "_codes[] = { ";
			for (auto c : fd.codes) out << c << ", ";
			out << "};\n";
		}
		if (!fd.advances.empty())
		{
			out << "static const int16_t font_" << i << "_advances[] = { ";
			for (auto a : fd.advances) out << a << ", ";
			out << "};\n";
		}
		if (!fd.glyph_pts.empty())
		{
			out << "static const int32_t font_" << i << "_pts[] = { ";
			for (auto v : fd.glyph_pts) out << v << ", ";
			out << "};\n";
			out << "static const uint32_t font_" << i << "_pt_start[] = { ";
			for (auto v : fd.glyph_pt_start) out << v << ", ";
			out << "};\n";
			out << "static const uint32_t font_" << i << "_contour_ends[] = { ";
			for (auto v : fd.glyph_contour_ends) out << v << ", ";
			out << "};\n";
			out << "static const uint32_t font_" << i << "_contour_start[] = { ";
			for (auto v : fd.glyph_contour_start) out << v << ", ";
			out << "};\n";
		}
	}
	if (!sc.fonts.empty())
	{
		out << "const Avm2FontData avm2_generated_fonts[] = {\n";
		for (size_t i = 0; i < sc.fonts.size(); i++)
		{
			const FontDef& fd = sc.fonts[i];
			out << "\t{ " << fd.font_id << ", \"" << cEscape(fd.name) << "\", "
			    << (fd.bold ? 1 : 0) << ", " << (fd.italic ? 1 : 0) << ", "
			    << (fd.has_layout ? 1 : 0) << ", " << fd.em_square << ", "
			    << fd.ascent << ", " << fd.descent << ", " << fd.leading << ", "
			    << fd.codes.size() << ", "
			    << (fd.codes.empty() ? std::string("NULL")
			                         : ("font_" + std::to_string(i) + "_codes"))
			    << ", "
			    << (fd.advances.empty()
			        ? std::string("NULL")
			        : ("font_" + std::to_string(i) + "_advances"));
			if (fd.glyph_pts.empty())
			{
				out << ", NULL, NULL, NULL, NULL },\n";
			}
			else
			{
				out << ", font_" << i << "_pts, font_" << i << "_pt_start"
				    << ", font_" << i << "_contour_ends"
				    << ", font_" << i << "_contour_start },\n";
			}
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2FontData avm2_generated_fonts[1];\n";
	}
	out << "const uint32_t avm2_generated_font_count = " << sc.fonts.size()
	    << ";\n\n";

	// Embedded bitmaps: straight RGBA, zlib-DEFLATE-compressed at recompile
	// time (raw RGBA is ~46 MB for a real game). The runtime inflates on
	// BitmapData construction (avm2_bitmap.c bd_seed_embedded). A blob that
	// fails to compress or does not shrink is emitted raw (z_len 0).
	std::vector<uint32_t> bmp_zlen(sc.bitmaps.size(), 0);
	for (size_t i = 0; i < sc.bitmaps.size(); i++)
	{
		const BitmapAsset& ba = sc.bitmaps[i];
		if (ba.rgba.empty()) continue;
		uLongf bound = compressBound((uLong) ba.rgba.size());
		std::vector<uint8_t> z(bound);
		uLongf zlen = bound;
		bool ok = compress2(z.data(), &zlen, ba.rgba.data(),
		                    (uLong) ba.rgba.size(), 9) == Z_OK
		          && (size_t) zlen < ba.rgba.size();
		const uint8_t* emit = ok ? z.data() : ba.rgba.data();
		size_t emit_len = ok ? (size_t) zlen : ba.rgba.size();
		bmp_zlen[i] = ok ? (uint32_t) zlen : 0;
		out << "static const uint8_t bmp_" << i << "_rgba[] = {";
		for (size_t k = 0; k < emit_len; k++)
		{
			if ((k & 31) == 0) out << "\n\t";
			out << (int) emit[k] << ",";
		}
		out << "\n};\n";
	}
	if (!sc.bitmaps.empty())
	{
		out << "const Avm2BitmapData avm2_generated_bitmaps[] = {\n";
		for (size_t i = 0; i < sc.bitmaps.size(); i++)
		{
			const BitmapAsset& ba = sc.bitmaps[i];
			out << "\t{ " << ba.char_id << ", " << ba.width << ", " << ba.height
			    << ", " << (int) ba.transparency << ", "
			    << (ba.rgba.empty() ? std::string("NULL")
			                        : ("bmp_" + std::to_string(i) + "_rgba"))
			    << ", " << bmp_zlen[i] << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2BitmapData avm2_generated_bitmaps[1];\n";
	}
	out << "const uint32_t avm2_generated_bitmap_count = " << sc.bitmaps.size()
	    << ";\n\n";

	// Embedded binary data (DefineBinaryData).
	for (size_t i = 0; i < sc.binaries.size(); i++)
	{
		const BinaryAsset& ba = sc.binaries[i];
		if (ba.bytes.empty()) continue;
		out << "static const uint8_t bin_" << i << "_bytes[] = {";
		for (size_t k = 0; k < ba.bytes.size(); k++)
		{
			if ((k & 31) == 0) out << "\n\t";
			out << (int) ba.bytes[k] << ",";
		}
		out << "\n};\n";
	}
	if (!sc.binaries.empty())
	{
		out << "const Avm2BinaryData avm2_generated_binaries[] = {\n";
		for (size_t i = 0; i < sc.binaries.size(); i++)
		{
			const BinaryAsset& ba = sc.binaries[i];
			out << "\t{ " << ba.char_id << ", " << ba.bytes.size() << ", "
			    << (ba.bytes.empty() ? std::string("NULL")
			                         : ("bin_" + std::to_string(i) + "_bytes"))
			    << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2BinaryData avm2_generated_binaries[1];\n";
	}
	out << "const uint32_t avm2_generated_binary_count = " << sc.binaries.size()
	    << ";\n\n";

	// Embedded sounds: metadata + full payload bytes (MP3 stays compressed;
	// the runtime mixer decodes on play, so no recompile-time zlib needed).
	for (size_t i = 0; i < sc.sounds.size(); i++)
	{
		const SoundAsset& sa = sc.sounds[i];
		if (sa.payload.empty()) continue;
		out << "static const uint8_t snd_" << i << "_bytes[] = {";
		for (size_t k = 0; k < sa.payload.size(); k++)
		{
			if ((k & 31) == 0) out << "\n\t";
			out << (int) sa.payload[k] << ",";
		}
		out << "\n};\n";
	}
	if (!sc.sounds.empty())
	{
		out << "const Avm2SoundData avm2_generated_sounds[] = {\n";
		for (size_t i = 0; i < sc.sounds.size(); i++)
		{
			const SoundAsset& sa = sc.sounds[i];
			out << "\t{ " << sa.char_id << ", " << (int) sa.format << ", "
			    << (int) sa.rate << ", " << (int) sa.sample_size << ", "
			    << (int) sa.stereo << ", " << sa.sample_count << ", "
			    << sa.data_size << ", "
			    << (sa.payload.empty() ? std::string("NULL")
			                           : ("snd_" + std::to_string(i) + "_bytes"))
			    << ", " << sa.payload.size() << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2SoundData avm2_generated_sounds[1];\n";
	}
	out << "const uint32_t avm2_generated_sound_count = " << sc.sounds.size()
	    << ";\n\n";

	out << "const int32_t avm2_generated_stage_rect[4] = { "
	    << info.stage_xmin << ", " << info.stage_xmax << ", " << info.stage_ymin
	    << ", " << info.stage_ymax << " };\n";
	out << "const uint16_t avm2_generated_frame_rate = " << info.frame_rate
	    << ";\n";
	out << "const uint16_t avm2_generated_header_frames = "
	    << info.header_frame_count << ";\n";
	out << "const uint32_t avm2_generated_bg_color = 0x";
	char hexbuf[16];
	snprintf(hexbuf, sizeof(hexbuf), "%06X", sc.bg_color);
	out << hexbuf << ";\n";

	std::ofstream f(output_folder + "/abc_timeline.c");
	f << out.str();
}

}  // namespace abc
}  // namespace SWFRecomp
