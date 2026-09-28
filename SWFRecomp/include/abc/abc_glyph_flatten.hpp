#pragma once

// Raph Levien parabola-integral quadratic flattening for AVM2 GLYPH outlines,
// ported from lyon_geom 1.0.6 `src/quadratic_bezier.rs` — the flattener
// Ruffle's tessellator runs on glyph shapes (`register_shape` -> scale 1.0 ->
// `FillOptions::DEFAULT_TOLERANCE` = 0.1 px, and a glyph coordinate is read as
// one twip, so 0.1 px = 2.0 glyph units).
//
// Shared by the two glyph pipelines that must flatten identically:
//   * abc_timeline.cpp — DefineFont2/3 glyph SHAPEs (embedded fonts);
//   * abc_devicefont.cpp — TrueType outlines of the test harness's device
//     faces. Ruffle feeds those through the SAME register_shape path
//     (font_face.rs GlyphToDrawing -> Glyph::from_drawing), with the TTF's
//     own font units read as twips, so the tolerance is 2.0 font units
//     whatever the face's unitsPerEm is.
// Deliberately separate from the plain-shape flattener in swf.cpp.

#include <cmath>
#include <cstdint>

namespace SWFRecomp
{
namespace abc
{

static const float GLYPH_LEVIEN_TOL = 2.0f;

struct GlyphLevienParams
{
	uint32_t count;
	float integral_from;
	float integral_step;
	float inv_integral_from;
	float div_inv_integral_diff;
};

inline float glyphParabolaIntegral(float x)
{
	const float d = 0.67f;
	return x / (1.0f - d + sqrtf(sqrtf(d*d*d*d + 0.25f*x*x)));
}

inline float glyphParabolaInvIntegral(float x)
{
	const float b = 0.39f;
	return x * (1.0f - b + sqrtf(b*b + 0.25f*x*x));
}

inline GlyphLevienParams glyphLevienInit(float x0, float y0, float cx, float cy,
                                         float x1, float y1, float tolerance)
{
	GlyphLevienParams p = { 0, 0.0f, 0.0f, 0.0f, 0.0f };
	if (x0 == x1 && y0 == y1) return p;
	{
		float bx = x1 - x0, by = y1 - y0;
		float len2 = bx*bx + by*by;
		float cross = (cx - x0) * by - (cy - y0) * bx;
		if (len2 > 0.0f && (cross*cross) / len2 <= tolerance * tolerance * 4.0f) return p;
	}
	float ddx = 2.0f*cx - x0 - x1;
	float ddy = 2.0f*cy - y0 - y1;
	float crs = (x1 - x0) * ddy - (y1 - y0) * ddx;
	if (crs == 0.0f) return p;

	float inv_crs = 1.0f / crs;
	float parabola_from = ((cx - x0) * ddx + (cy - y0) * ddy) * inv_crs;
	float parabola_to   = ((x1 - cx) * ddx + (y1 - cy) * ddy) * inv_crs;
	float scale = fabsf(crs) / (sqrtf(ddx*ddx + ddy*ddy) * fabsf(parabola_to - parabola_from));

	float integral_from = glyphParabolaIntegral(parabola_from);
	float integral_to   = glyphParabolaIntegral(parabola_to);
	float integral_diff = integral_to - integral_from;

	float inv_integral_from = glyphParabolaInvIntegral(integral_from);
	float inv_integral_to   = glyphParabolaInvIntegral(integral_to);

	float count = ceilf(0.5f * fabsf(integral_diff) * sqrtf(scale / tolerance));
	if (!std::isfinite(count) || count < 1.0f) return p;
	if (count > 64.0f) count = 64.0f;

	p.count = (uint32_t) count;
	p.integral_from = integral_from;
	p.integral_step = integral_diff / count;
	p.inv_integral_from = inv_integral_from;
	p.div_inv_integral_diff = 1.0f / (inv_integral_to - inv_integral_from);
	return p;
}

inline float glyphLevienT(const GlyphLevienParams& p, uint32_t i)
{
	float u = glyphParabolaInvIntegral(p.integral_from + p.integral_step * (float) i);
	return (u - p.inv_integral_from) * p.div_inv_integral_diff;
}

}  // namespace abc
}  // namespace SWFRecomp
