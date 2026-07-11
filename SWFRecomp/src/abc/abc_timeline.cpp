// AVM2 static timeline tables (see abc_timeline.hpp). Byte-level tag
// reader over the decompressed stream; emission contract in
// SWFModernRuntime/include/avm2/avm2_abc.h ("Static timeline tables").

#include <abc/abc_timeline.hpp>

#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

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
	TAG_DEFINE_TEXT = 11,
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
};

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
		if (is_po3 && (has_class_name || (has_image && has_char)))
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
				defineChar(body, 4 /* EDITTEXT */, true);
				break;
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
				body.u8();    // format
				int32_t w = body.u16();
				int32_t h = body.u16();
				ci.bounds[0] = 0;
				ci.bounds[1] = w * 20;
				ci.bounds[2] = 0;
				ci.bounds[3] = h * 20;
				chars.push_back(ci);
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
	// Root frame labels: when DefineSceneAndFrameLabelData provides labels,
	// plain FrameLabel tags are IGNORED (Ruffle movie_clip.rs:4064).
	if (!sc.scene_labels.empty())
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
			    << ", " << ci.bounds[3] << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2CharInfo avm2_generated_chars[1];\n";
	}
	out << "const uint32_t avm2_generated_char_count = " << sc.chars.size()
	    << ";\n\n";

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
