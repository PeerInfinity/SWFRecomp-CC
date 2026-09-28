// Device fonts declared in a Ruffle test.toml -> generated Avm2FontData rows.
// See include/abc/abc_devicefont.hpp for why this lives in the recompiler.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <strings.h>
#include <string>
#include <vector>

#include <toml++/toml.hpp>
#include <stb_truetype.h>

#include <abc/abc_devicefont.hpp>
#include <abc/abc_glyph_flatten.hpp>

namespace SWFRecomp
{
namespace abc
{

namespace
{

struct KernPair
{
	uint16_t left, right;
	int16_t value;
};

struct DeviceFaceDef
{
	std::string key;      // the `[fonts.KEY]` table name (font_sorts refers to it)
	std::string family;
	bool bold = false, italic = false;
	uint16_t em_square = 1000;
	int32_t ascent = 0, descent = 0, leading = 0;  // font units, descent positive
	std::vector<uint16_t> codes;
	std::vector<int32_t> advances;
	std::vector<KernPair> kerns;
	std::vector<uint32_t> fallback;  // indices into the emitted device table
	// Flattened glyph outlines in the face's own font units, y NEGATED
	// (Ruffle font_face.rs GlyphToDrawing emits `-y`), indexed exactly like
	// `codes`/`advances` (see appendGlyphOutline).
	std::vector<int32_t> glyph_pts;             // x,y pairs
	std::vector<uint32_t> glyph_pt_start;       // nglyphs+1
	std::vector<uint32_t> glyph_contour_ends;   // absolute pair indices
	std::vector<uint32_t> glyph_contour_start;  // nglyphs+1
};

// --- glyph outlines ---------------------------------------------------------
// Ruffle builds a device glyph as a flash Drawing straight from the TTF
// outline (core/src/font/font_face.rs `GlyphToDrawing`): every move/line
// point and every quadratic control/anchor is TRUNCATED to an integer
// (`x as i32`, `-y as i32` — y negated), read as twips, and the Drawing is
// then tessellated like any glyph shape: lyon's Levien flattening at
// FillOptions::DEFAULT_TOLERANCE (0.1 px = 2.0 units, since a glyph
// coordinate is one twip at scale 1), NonZero fill. The embedded-font
// pipeline (abc_timeline.cpp parseGlyphShape) does the same flattening on
// DefineFont2/3 shapes, so both share abc_glyph_flatten.hpp and the runtime
// consumes the result through the same Avm2FontData outline arrays.

// Accumulates one glyph's contours into fd in the runtime's layout.
struct OutlineSink
{
	DeviceFaceDef& fd;
	std::vector<int32_t> cur;  // x,y pairs of the open contour
	int32_t px = 0, py = 0;    // pen, already truncated + y-negated

	explicit OutlineSink(DeviceFaceDef& f) : fd(f) {}

	// Ruffle's truncation of a ttf_parser coordinate (y already negated).
	static int32_t tw(double v) { return (int32_t) v; }

	void flush()
	{
		if (cur.size() >= 6)  // a fillable contour needs >= 3 points
		{
			fd.glyph_pts.insert(fd.glyph_pts.end(), cur.begin(), cur.end());
			fd.glyph_contour_ends.push_back((uint32_t) (fd.glyph_pts.size() / 2));
		}
		cur.clear();
	}
	void start()
	{
		if (cur.empty()) { cur.push_back(px); cur.push_back(py); }
	}
	void moveTo(double x, double y)
	{
		flush();
		px = tw(x);
		py = tw(-y);
	}
	void lineTo(double x, double y)
	{
		start();
		px = tw(x);
		py = tw(-y);
		cur.push_back(px);
		cur.push_back(py);
	}
	void quadTo(double cxf, double cyf, double axf, double ayf)
	{
		start();
		// Flatten the TRUNCATED curve (Ruffle truncates before lyon sees it),
		// rounding each flattened point back to a font unit exactly as the
		// embedded-glyph path does.
		double x0 = px, y0 = py;
		double cx = tw(cxf), cy = tw(-cyf);
		double ax = tw(axf), ay = tw(-ayf);
		GlyphLevienParams lp = glyphLevienInit((float) x0, (float) y0,
		                                       (float) cx, (float) cy,
		                                       (float) ax, (float) ay,
		                                       GLYPH_LEVIEN_TOL);
		uint32_t nseg = (lp.count < 1) ? 1 : lp.count;
		for (uint32_t k = 1; k <= nseg; k++)
		{
			double t = (k < lp.count) ? (double) glyphLevienT(lp, k) : 1.0;
			double u = 1.0 - t;
			cur.push_back((int32_t) lround(u*u*x0 + 2.0*u*t*cx + t*t*ax));
			cur.push_back((int32_t) lround(u*u*y0 + 2.0*u*t*cy + t*t*ay));
		}
		px = (int32_t) ax;
		py = (int32_t) ay;
	}
	void cubicTo(double c1xf, double c1yf, double c2xf, double c2yf,
	             double axf, double ayf)
	{
		// CFF faces only (TrueType outlines are quadratic). Split the
		// truncated cubic into quadratics at the midpoint-of-thirds and reuse
		// the Levien flattener; exact lyon cubic parity is not attempted
		// (no corpus test declares a CFF device face).
		start();
		double x0 = px, y0 = py;
		double c1x = tw(c1xf), c1y = tw(-c1yf);
		double c2x = tw(c2xf), c2y = tw(-c2yf);
		double ax = tw(axf), ay = tw(-ayf);
		const int N = 8;
		double lx = x0, ly = y0;
		for (int k = 1; k <= N; k++)
		{
			double t0 = (double) (k - 1) / N, t1 = (double) k / N;
			auto bez = [&](double t, double* ox, double* oy) {
				double u = 1.0 - t;
				*ox = u*u*u*x0 + 3.0*u*u*t*c1x + 3.0*u*t*t*c2x + t*t*t*ax;
				*oy = u*u*u*y0 + 3.0*u*u*t*c1y + 3.0*u*t*t*c2y + t*t*t*ay;
			};
			double ex, ey, mx, my;
			bez(t1, &ex, &ey);
			bez(0.5 * (t0 + t1), &mx, &my);
			// Quadratic through (lx,ly), (mx,my) at t=.5, (ex,ey).
			double qcx = 2.0 * mx - 0.5 * (lx + ex);
			double qcy = 2.0 * my - 0.5 * (ly + ey);
			GlyphLevienParams lp = glyphLevienInit((float) lx, (float) ly,
			                                       (float) qcx, (float) qcy,
			                                       (float) ex, (float) ey,
			                                       GLYPH_LEVIEN_TOL);
			uint32_t nseg = (lp.count < 1) ? 1 : lp.count;
			for (uint32_t j = 1; j <= nseg; j++)
			{
				double t = (j < lp.count) ? (double) glyphLevienT(lp, j) : 1.0;
				double u = 1.0 - t;
				cur.push_back((int32_t) lround(u*u*lx + 2.0*u*t*qcx + t*t*ex));
				cur.push_back((int32_t) lround(u*u*ly + 2.0*u*t*qcy + t*t*ey));
			}
			lx = ex;
			ly = ey;
		}
		px = (int32_t) ax;
		py = (int32_t) ay;
	}
};

// Flatten one TTF glyph outline into fd's contour arrays (font units).
void appendGlyphOutline(const stbtt_fontinfo* info, int g, DeviceFaceDef& fd)
{
	stbtt_vertex* verts = NULL;
	int nv = stbtt_GetGlyphShape(info, g, &verts);
	if (nv <= 0)
	{
		if (verts != NULL) stbtt_FreeShape(info, verts);
		return;
	}
	OutlineSink sink(fd);
	for (int i = 0; i < nv; i++)
	{
		const stbtt_vertex& v = verts[i];
		switch (v.type)
		{
		case STBTT_vmove:  sink.moveTo(v.x, v.y); break;
		case STBTT_vline:  sink.lineTo(v.x, v.y); break;
		case STBTT_vcurve: sink.quadTo(v.cx, v.cy, v.x, v.y); break;
		case STBTT_vcubic: sink.cubicTo(v.cx, v.cy, v.cx1, v.cy1, v.x, v.y); break;
		default: break;
		}
	}
	sink.flush();
	stbtt_FreeShape(info, verts);
}

// Outline size control. A full-BMP face (thousands of glyphs at ~0.4 KB of
// generated C each) would bloat every test that declares one, so outlines
// are emitted for Latin + Latin-1 + Latin Extended-A/B + IPA only; any
// higher codepoint keeps its metrics but an empty contour range and so
// renders blank (the pre-outline behaviour for every glyph).
const int DEVFONT_OUTLINE_MAX_CP = 0x2FF;

// --- minimal big-endian TrueType table directory reader -------------------
// stb_truetype exposes hhea + OS/2 typo metrics but not unitsPerEm,
// OS/2.version, fsSelection or the usWin* pair, and its table finder is
// static. ttf_parser's vertical-metrics ladder (lib.rs:1499-1585) needs all
// of them, so read the directory directly.

uint16_t beU16(const uint8_t* p) { return (uint16_t) ((p[0] << 8) | p[1]); }
int16_t beS16(const uint8_t* p) { return (int16_t) beU16(p); }
uint32_t beU32(const uint8_t* p)
{
	return ((uint32_t) p[0] << 24) | ((uint32_t) p[1] << 16)
	       | ((uint32_t) p[2] << 8) | (uint32_t) p[3];
}

// Returns the offset of `tag` within `data`, or 0 when absent.
uint32_t findTable(const std::vector<uint8_t>& data, uint32_t font_start,
                   const char* tag)
{
	if (data.size() < font_start + 12) return 0;
	const uint8_t* base = data.data() + font_start;
	uint32_t num = beU16(base + 4);
	for (uint32_t i = 0; i < num; i++)
	{
		size_t rec = font_start + 12 + (size_t) i * 16;
		if (rec + 16 > data.size()) return 0;
		const uint8_t* r = data.data() + rec;
		if (memcmp(r, tag, 4) == 0)
		{
			uint32_t off = beU32(r + 8);
			return off < data.size() ? off : 0;
		}
	}
	return 0;
}

// ttf_parser Face::ascender/descender/line_gap (lib.rs:1499-1585): OS/2 typo
// metrics win outright when OS/2 >= v4 sets fsSelection bit 7
// (USE_TYPO_METRICS); otherwise hhea wins UNLESS its value is 0, in which case
// it falls back to OS/2 typo and then to the usWin pair. The zero-fallback arm
// is not academic: several corpus TestFonts ship `hhea.descender = 0` with
// `OS/2.sTypoDescender = -200`.
void readVMetrics(const std::vector<uint8_t>& data, uint32_t font_start,
                  int32_t* ascent, int32_t* descent, int32_t* leading,
                  uint16_t* upem)
{
	*ascent = *descent = *leading = 0;
	*upem = 1000;

	uint32_t head = findTable(data, font_start, "head");
	if (head != 0 && head + 20 <= data.size())
	{
		uint16_t u = beU16(data.data() + head + 18);
		if (u != 0) *upem = u;
	}

	int32_t hhea_asc = 0, hhea_desc = 0, hhea_gap = 0;
	uint32_t hhea = findTable(data, font_start, "hhea");
	if (hhea != 0 && hhea + 12 <= data.size())
	{
		hhea_asc = beS16(data.data() + hhea + 4);
		hhea_desc = beS16(data.data() + hhea + 6);
		hhea_gap = beS16(data.data() + hhea + 8);
	}

	bool has_os2 = false, use_typo = false;
	int32_t typo_asc = 0, typo_desc = 0, typo_gap = 0;
	int32_t win_asc = 0, win_desc = 0;
	uint32_t os2 = findTable(data, font_start, "OS/2");
	if (os2 != 0 && os2 + 78 <= data.size())
	{
		has_os2 = true;
		const uint8_t* t = data.data() + os2;
		uint16_t version = beU16(t + 0);
		uint16_t fs_selection = beU16(t + 62);
		typo_asc = beS16(t + 68);
		typo_desc = beS16(t + 70);
		typo_gap = beS16(t + 72);
		win_asc = (int32_t) beU16(t + 74);
		win_desc = (int32_t) beU16(t + 76);
		use_typo = version >= 4 && (fs_selection & 0x80) != 0;
	}

	if (has_os2 && use_typo)
	{
		*ascent = typo_asc;
		*descent = -typo_desc;
		*leading = typo_gap;
		return;
	}

	int32_t asc = hhea_asc;
	if (asc == 0 && has_os2)
	{
		asc = typo_asc;
		if (asc == 0) asc = win_asc;
	}
	int32_t desc = hhea_desc;
	if (desc == 0 && has_os2)
	{
		desc = typo_desc;
		if (desc == 0) desc = -win_desc;
	}
	int32_t gap = hhea_gap;
	if ((hhea_asc == 0 || hhea_desc == 0) && has_os2)
	{
		gap = (typo_asc != 0 || typo_desc != 0) ? typo_gap : 0;
	}

	*ascent = asc;
	// Ruffle FontFace::new stores `descender: -face.descender()`, i.e. the
	// positive-down convention Avm2FontData uses.
	*descent = -desc;
	*leading = gap;
}

bool readFile(const std::string& path, std::vector<uint8_t>& out)
{
	FILE* f = fopen(path.c_str(), "rb");
	if (f == NULL) return false;
	fseek(f, 0, SEEK_END);
	long sz = ftell(f);
	fseek(f, 0, SEEK_SET);
	if (sz <= 0) { fclose(f); return false; }
	out.resize((size_t) sz);
	bool ok = fread(out.data(), 1, (size_t) sz, f) == (size_t) sz;
	fclose(f);
	return ok;
}

std::string cEsc(const std::string& s)
{
	std::string r;
	for (char c : s)
	{
		if (c == '"' || c == '\\') { r += '\\'; r += c; }
		else if ((unsigned char) c < 0x20) { char b[8]; snprintf(b, sizeof(b), "\\%03o", c); r += b; }
		else r += c;
	}
	return r;
}

// Loads one declared face. Returns false when the TTF is missing/unparsable.
bool loadFace(const std::string& path, DeviceFaceDef& fd)
{
	std::vector<uint8_t> data;
	if (!readFile(path, data)) return false;

	int font_start = stbtt_GetFontOffsetForIndex(data.data(), 0);
	if (font_start < 0) return false;
	stbtt_fontinfo info;
	if (stbtt_InitFont(&info, data.data(), font_start) == 0) return false;

	int32_t asc = 0, desc = 0, gap = 0;
	uint16_t upem = 1000;
	readVMetrics(data, (uint32_t) font_start, &asc, &desc, &gap, &upem);
	fd.em_square = upem;
	fd.ascent = asc;
	fd.descent = desc;
	fd.leading = gap;

	// Ruffle resolves glyphs on demand through the cmap, so every mapped
	// codepoint is available. The generated tables are flat, so materialise
	// the BMP range once. Glyph 0 (.notdef) is never a cmap hit for a sane
	// font; codepoints below 0x20 are not laid out.
	std::vector<std::pair<int, uint16_t>> glyph_to_code;
	std::vector<int> glyph_ids;  // parallel to fd.codes (outline emission order)
	for (int cp = 0x20; cp <= 0xFFFF; cp++)
	{
		int g = stbtt_FindGlyphIndex(&info, cp);
		if (g <= 0) continue;
		int adv = 0, lsb = 0;
		stbtt_GetGlyphHMetrics(&info, g, &adv, &lsb);
		fd.codes.push_back((uint16_t) cp);
		fd.advances.push_back((int32_t) adv);
		glyph_ids.push_back(g);
		glyph_to_code.push_back({ g, (uint16_t) cp });
	}
	if (fd.codes.empty()) return false;

	// Glyph outlines, in the same index space as codes/advances. Emitted
	// only when at least one glyph has ink; otherwise the outline pointers
	// stay NULL and the runtime treats the face as metrics-only.
	{
		for (size_t i = 0; i < glyph_ids.size(); i++)
		{
			fd.glyph_pt_start.push_back((uint32_t) (fd.glyph_pts.size() / 2));
			fd.glyph_contour_start.push_back(
				(uint32_t) fd.glyph_contour_ends.size());
			if (fd.codes[i] > DEVFONT_OUTLINE_MAX_CP) continue;
			appendGlyphOutline(&info, glyph_ids[i], fd);
		}
		fd.glyph_pt_start.push_back((uint32_t) (fd.glyph_pts.size() / 2));
		fd.glyph_contour_start.push_back((uint32_t) fd.glyph_contour_ends.size());
		if (fd.glyph_pts.empty())
		{
			fd.glyph_pt_start.clear();
			fd.glyph_contour_ends.clear();
			fd.glyph_contour_start.clear();
		}
	}

	// Kerning. Ruffle reads the `kern` table ONLY (font.rs:261-269, 327-340) —
	// never GPOS — so use stbtt_GetKerningTable (kern, horizontal, format 0)
	// rather than stbtt_GetGlyphKernAdvance, which prefers GPOS when present.
	int nkern = stbtt_GetKerningTableLength(&info);
	if (nkern > 0)
	{
		std::vector<stbtt_kerningentry> tbl((size_t) nkern);
		nkern = stbtt_GetKerningTable(&info, tbl.data(), nkern);
		std::sort(glyph_to_code.begin(), glyph_to_code.end());
		for (int i = 0; i < nkern; i++)
		{
			if (tbl[i].advance == 0) continue;
			auto findCode = [&](int g, uint16_t* out) {
				auto it = std::lower_bound(
					glyph_to_code.begin(), glyph_to_code.end(),
					std::make_pair(g, (uint16_t) 0));
				if (it == glyph_to_code.end() || it->first != g) return false;
				*out = it->second;
				return true;
			};
			uint16_t lc = 0, rc = 0;
			if (!findCode(tbl[i].glyph1, &lc)) continue;
			if (!findCode(tbl[i].glyph2, &rc)) continue;
			KernPair kp;
			kp.left = lc;
			kp.right = rc;
			kp.value = (int16_t) tbl[i].advance;
			fd.kerns.push_back(kp);
		}
	}
	return true;
}

}  // namespace

void emitDeviceFonts(std::ostream& out)
{
	std::vector<DeviceFaceDef> faces;

	toml::table tbl;
	bool have_toml = false;
	try
	{
		tbl = toml::parse_file("test.toml");
		have_toml = true;
	}
	catch (...)
	{
		have_toml = false;
	}

	if (have_toml)
	{
		if (const toml::table* fonts = tbl["fonts"].as_table())
		{
			for (const auto& kv : *fonts)
			{
				const toml::table* ft = kv.second.as_table();
				if (ft == NULL) continue;
				DeviceFaceDef fd;
				fd.key = std::string(kv.first.str());
				fd.family = std::string((*ft)["family"].value_or(""));
				std::string path = std::string((*ft)["path"].value_or(""));
				fd.bold = (*ft)["bold"].value_or(false);
				fd.italic = (*ft)["italic"].value_or(false);
				if (fd.family.empty() || path.empty()) continue;
				if (!loadFace(path, fd))
				{
					fprintf(stderr, "SWFRecomp: device font '%s' (%s) could not "
					        "be loaded; ignoring\n", fd.family.c_str(),
					        path.c_str());
					continue;
				}
				faces.push_back(std::move(fd));
			}
		}

		// [font_sorts.KEY] { family, bold, italic, sort = [font keys] } is the
		// per-family glyph fallback chain (Ruffle test.rs::font_sorts +
		// FontSet: sort[0] is the MAIN face, the rest are fallbacks).
		if (const toml::table* sorts = tbl["font_sorts"].as_table())
		{
			for (const auto& kv : *sorts)
			{
				const toml::table* st = kv.second.as_table();
				if (st == NULL) continue;
				std::string family = std::string((*st)["family"].value_or(""));
				bool bold = (*st)["bold"].value_or(false);
				bool italic = (*st)["italic"].value_or(false);
				const toml::array* arr = (*st)["sort"].as_array();
				if (family.empty() || arr == NULL) continue;
				std::vector<uint32_t> chain;
				for (const auto& e : *arr)
				{
					std::string key = std::string(e.value_or(""));
					for (size_t i = 0; i < faces.size(); i++)
					{
						if (faces[i].key == key) { chain.push_back((uint32_t) i); break; }
					}
				}
				if (chain.empty()) continue;
				// The chain is attached to the face the query resolves to.
				for (auto& f : faces)
				{
					if (f.bold == bold && f.italic == italic
					    && strcasecmp(f.family.c_str(), family.c_str()) == 0)
						f.fallback = chain;
				}
			}
		}
	}

	out << "\n// Device fonts declared by the test harness (test.toml [fonts.*]).\n";
	for (size_t i = 0; i < faces.size(); i++)
	{
		const DeviceFaceDef& fd = faces[i];
		out << "static const uint16_t devfont_" << i << "_codes[] = { ";
		for (auto c : fd.codes) out << c << ", ";
		out << "};\n";
		out << "static const int32_t devfont_" << i << "_advances[] = { ";
		for (auto a : fd.advances) out << a << ", ";
		out << "};\n";
		if (!fd.kerns.empty())
		{
			out << "static const uint16_t devfont_" << i << "_kern_left[] = { ";
			for (auto& k : fd.kerns) out << k.left << ", ";
			out << "};\n";
			out << "static const uint16_t devfont_" << i << "_kern_right[] = { ";
			for (auto& k : fd.kerns) out << k.right << ", ";
			out << "};\n";
			out << "static const int16_t devfont_" << i << "_kern_value[] = { ";
			for (auto& k : fd.kerns) out << k.value << ", ";
			out << "};\n";
		}
		if (!fd.glyph_pts.empty())
		{
			out << "static const int32_t devfont_" << i << "_pts[] = { ";
			for (auto v : fd.glyph_pts) out << v << ", ";
			out << "};\n";
			out << "static const uint32_t devfont_" << i << "_pt_start[] = { ";
			for (auto v : fd.glyph_pt_start) out << v << ", ";
			out << "};\n";
			out << "static const uint32_t devfont_" << i << "_contour_ends[] = { ";
			for (auto v : fd.glyph_contour_ends) out << v << ", ";
			out << "};\n";
			out << "static const uint32_t devfont_" << i << "_contour_start[] = { ";
			for (auto v : fd.glyph_contour_start) out << v << ", ";
			out << "};\n";
		}
		if (!fd.fallback.empty())
		{
			out << "static const uint32_t devfont_" << i << "_fallback[] = { ";
			for (auto v : fd.fallback) out << v << ", ";
			out << "};\n";
		}
	}
	if (!faces.empty())
	{
		out << "const Avm2FontData avm2_generated_device_fonts[] = {\n";
		for (size_t i = 0; i < faces.size(); i++)
		{
			const DeviceFaceDef& fd = faces[i];
			std::string n = std::to_string(i);
			out << "\t{ 0, \"" << cEsc(fd.family) << "\", "
			    << (fd.bold ? 1 : 0) << ", " << (fd.italic ? 1 : 0)
			    << ", 1, " << fd.em_square << ", "
			    << fd.ascent << ", " << fd.descent << ", " << fd.leading << ", "
			    << fd.codes.size()
			    << ", devfont_" << n << "_codes, devfont_" << n << "_advances,";
			if (fd.glyph_pts.empty())
				out << " NULL, NULL, NULL, NULL, ";
			else
				out << " devfont_" << n << "_pts, devfont_" << n << "_pt_start,"
				    << " devfont_" << n << "_contour_ends, devfont_" << n
				    << "_contour_start, ";
			if (fd.kerns.empty())
				out << "NULL, NULL, NULL, 0, ";
			else
				out << "devfont_" << n << "_kern_left, devfont_" << n
				    << "_kern_right, devfont_" << n << "_kern_value, "
				    << fd.kerns.size() << ", ";
			if (fd.fallback.empty())
				out << "NULL, 0 },\n";
			else
				out << "devfont_" << n << "_fallback, " << fd.fallback.size()
				    << " },\n";
		}
		out << "};\n";
	}
	else
	{
		out << "const Avm2FontData avm2_generated_device_fonts[1];\n";
	}
	out << "const uint32_t avm2_generated_device_font_count = " << faces.size()
	    << ";\n\n";
}

}  // namespace abc
}  // namespace SWFRecomp
