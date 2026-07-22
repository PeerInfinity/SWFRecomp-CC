// AVM2 CPU shape rasterizer (T5) — see avm2_cpu_raster.h.
//
// Ported by COPY (never call) from action.c's rasterizeMovieClipToBitmap:
//   - INVERT_2D_AFFINE  (action.c:13314) — verbatim
//   - RASTER_TRI edge-coverage math (action.c:13354) — verbatim (pixel centres
//     at +0.5, sign-normalised barycentric, inside test w0,w1,w2 >= 0)
// The SOLID path reuses that coverage directly. The GRADIENT path reuses the
// coverage + barycentric-weight structure but replaces action.c's Drawing-API
// gradient math (raw +/-16384 twips space) with the shape_data convention the
// WGSL shader uses: the forward gradient matrix (uninv_mat_data) already bakes
// the [0,1] UV normalisation, so inverting its 2D affine and applying it to the
// shape-local vertex gives inv_pos.xy in [0,1] — exactly render_webgpu.c's
// vs_main. Ramp sampling, spread, and the focal formula mirror fs_main /
// sample_gradient (t*256-0.5 sampler phase). Timeline-shape ramps are stored
// sRGB-encoded (swf.cpp linearRgbLerp bakes linear->sRGB back), and the
// per-shape style never sets the is_linear_rgb bit, so NO linear->sRGB pass is
// applied here — matching the shader for timeline shapes.
//
// STORE PARITY (the tranche's central risk): final pixels are premultiplied via
// the SAME forward premul avm2_bitmap.c::premul() uses ((ch*a+127)/255), then
// source-over-blended, so BitmapData.getPixel (which un-premultiplies with
// Flash's brute-forced table) round-trips exactly. We do NOT use action.c's
// premultiplyAlpha.

#include <stdint.h>
#include <stddef.h>
#include <math.h>

#include "avm2/avm2_cpu_raster.h"

// Resident recompiler geometry tables, defined in the generated draws.c and
// linked into every build (both graphics and no-graphics — see verify_output.py
// DRAWS_ARRAY_NAMES). Read directly: NO_GRAPHICS builds have no render
// `context`, and the GPU dispatch reads the very same rows.
extern uint32_t shape_data[][4];    // {x_bits(float), y_bits(float), style_packed, style_index}
extern float    color_data[][4];    // {r,g,b,a} straight, 0..1
extern float    uninv_mat_data[];   // 16 floats/gradient: forward UV[0,1]->twips (2D affine in 4x4)
extern uint8_t  gradient_data[][4]; // 256 rows/gradient: {r,g,b,a} u8, sRGB-encoded

// ---------------------------------------------------------------------------
// Store helpers — must match avm2_bitmap.c premul()/blend_over() exactly.
// ---------------------------------------------------------------------------

// Flash forward premultiply with the TRUE source alpha (avm2_bitmap.c premul()
// with transparency=1). Its inverse is the FLASH_PREMUL_FACTOR table getPixel
// uses, so an opaque pixel round-trips identically.
static inline uint32_t cpu_premul(uint32_t c)
{
	uint32_t a = (c >> 24) & 0xFF;
	uint32_t r = (((c >> 16) & 0xFF) * a + 127) / 255;
	uint32_t g = (((c >>  8) & 0xFF) * a + 127) / 255;
	uint32_t b = (( c        & 0xFF) * a + 127) / 255;
	return (a << 24) | (r << 16) | (g << 8) | b;
}

// Premultiplied source-over (avm2_bitmap.c blend_over): src on top of dest.
static inline uint32_t cpu_blend_over(uint32_t dest, uint32_t src)
{
	uint32_t sa = (src >> 24) & 0xFF, inv = 255 - sa;
	uint32_t r = ((src >> 16) & 0xFF) + (((dest >> 16) & 0xFF) * inv) / 255;
	uint32_t g = ((src >>  8) & 0xFF) + (((dest >>  8) & 0xFF) * inv) / 255;
	uint32_t b = (( src        & 0xFF)) + ((( dest        & 0xFF)) * inv) / 255;
	uint32_t a = sa + (((dest >> 24) & 0xFF) * inv) / 255;
	if (r > 255) r = 255;
	if (g > 255) g = 255;
	if (b > 255) b = 255;
	if (a > 255) a = 255;
	return (a << 24) | (r << 16) | (g << 8) | b;
}

static inline uint32_t f2b(double x)
{
	if (x <= 0.0) return 0;
	if (x >= 1.0) return 255;
	return (uint32_t) (x * 255.0 + 0.5);
}

static inline float bits_to_f(uint32_t u)
{
	float f;
	__builtin_memcpy(&f, &u, sizeof(f));
	return f;
}

// ---------------------------------------------------------------------------
// Gradient shading — mirrors render_webgpu.c fs_main / sample_gradient exactly.
// ---------------------------------------------------------------------------

// apply_spread: 0 = pad (clamp), 1 = reflect (triangle wave), 2 = repeat (fract).
static inline double grad_spread(double t, uint32_t mode)
{
	if (mode == 1)
	{
		double p = t - 2.0 * floor(t / 2.0);
		return p <= 1.0 ? p : 2.0 - p;
	}
	if (mode == 2) return t - floor(t);
	if (t < 0.0) return 0.0;
	if (t > 1.0) return 1.0;
	return t;
}

// Sample ramp `row` at t in [0,1], matching the shader's hardware-sampler phase
// (u = t*256 - 0.5, clamp-to-edge, manual lerp along U). Returns straight ARGB.
static uint32_t grad_sample(uint32_t row, double t)
{
	if (t < 0.0) t = 0.0; else if (t > 1.0) t = 1.0;
	double u = t * 256.0 - 0.5;
	if (u < 0.0) u = 0.0; else if (u > 255.0) u = 255.0;
	int u0 = (int) floor(u);
	int u1 = u0 + 1; if (u1 > 255) u1 = 255;
	double f = u - (double) u0;
	const uint8_t* c0 = gradient_data[row * 256 + u0];
	const uint8_t* c1 = gradient_data[row * 256 + u1];
	uint32_t r = (uint32_t) ((c0[0] * (1.0 - f) + c1[0] * f) + 0.5);
	uint32_t g = (uint32_t) ((c0[1] * (1.0 - f) + c1[1] * f) + 0.5);
	uint32_t b = (uint32_t) ((c0[2] * (1.0 - f) + c1[2] * f) + 0.5);
	uint32_t a = (uint32_t) ((c0[3] * (1.0 - f) + c1[3] * f) + 0.5);
	return (a << 24) | (r << 16) | (g << 8) | b;
}

// gradient parameter t from normalised UV (gu,gv in [0,1]) per fill type.
static double grad_t(uint32_t style_type, double gu, double gv,
                     double focal_z, uint32_t spread)
{
	if (style_type == 0x10)          // linear
		return grad_spread(gu, spread);
	if (style_type == 0x12)          // radial
	{
		double x = gu * 2.0 - 1.0, y = gv * 2.0 - 1.0;
		return grad_spread(sqrt(x * x + y * y), spread);
	}
	// focal (0x13) — Ruffle's focal formula (render_webgpu.c focal_radial_t).
	double fx = focal_z;
	double ux = gu * 2.0 - 1.0, uy = gv * 2.0 - 1.0;
	double dx = fx - ux, dy = 0.0 - uy;
	double l = sqrt(dx * dx + dy * dy);
	if (l < 0.00001) return 0.0;
	dx /= l; dy /= l;
	double denom = sqrt(fmax(1.0 - fx * fx * dy * dy, 0.0)) + fx * dx;
	if (fabs(denom) < 0.00001) return 0.0;
	return grad_spread(l / denom, spread);
}

// ---------------------------------------------------------------------------
// Triangle coverage (ported verbatim from action.c RASTER_TRI). Calls back into
// a shader lambda per covered pixel. `solid_argb` non-zero-flag path avoids the
// per-pixel barycentric for the common solid/stroke case.
// ---------------------------------------------------------------------------

typedef struct {
	uint32_t* buf;
	int W, H;
	// gradient params (unused for solid)
	uint32_t style_type, style_id, spread;
	double focal_z, node_alpha;
	// inverted 2D affine (shape twips -> UV[0,1])
	double ia, ib, ic, id, itx, ity;
	// shape-local vertices (for gradient barycentric interp)
	double sx0, sy0, sx1, sy1, sx2, sy2;
	// solid colour (straight ARGB, node-alpha already applied)
	uint32_t solid_argb;
	int is_gradient;
} RasterCtx;

static void raster_tri(RasterCtx* R,
                       double ax, double ay, double bx, double by,
                       double cx, double cy)
{
	uint32_t* buf = R->buf;
	int W = R->W, H = R->H;
	double tx_min = ax < bx ? ax : bx; if (cx < tx_min) tx_min = cx;
	double tx_max = ax > bx ? ax : bx; if (cx > tx_max) tx_max = cx;
	double ty_min = ay < by ? ay : by; if (cy < ty_min) ty_min = cy;
	double ty_max = ay > by ? ay : by; if (cy > ty_max) ty_max = cy;
	int xlo = (int) floor(tx_min - 0.5); if (xlo < 0) xlo = 0;
	int xhi = (int) ceil (tx_max - 0.5); if (xhi > W - 1) xhi = W - 1;
	int ylo = (int) floor(ty_min - 0.5); if (ylo < 0) ylo = 0;
	int yhi = (int) ceil (ty_max - 0.5); if (yhi > H - 1) yhi = H - 1;
	if (xhi < xlo || yhi < ylo) return;
	double sgnd = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
	if (sgnd == 0.0) return;
	double abs_area = sgnd > 0 ? sgnd : -sgnd;
	double sgn = sgnd > 0 ? 1.0 : -1.0;
	double inv_area = 1.0 / abs_area;

	for (int py = ylo; py <= yhi; py++)
	{
		double qy = (double) py + 0.5;
		uint32_t* row = buf + (size_t) py * W;
		for (int px = xlo; px <= xhi; px++)
		{
			double qx = (double) px + 0.5;
			double w0 = ((bx - ax) * (qy - ay) - (by - ay) * (qx - ax)) * sgn;
			double w1 = ((cx - bx) * (qy - by) - (cy - by) * (qx - bx)) * sgn;
			double w2 = ((ax - cx) * (qy - cy) - (ay - cy) * (qx - cx)) * sgn;
			if (w0 < 0 || w1 < 0 || w2 < 0) continue;

			uint32_t straight;
			if (!R->is_gradient)
			{
				straight = R->solid_argb;
			}
			else
			{
				// Barycentric: alphaA = w1, alphaB = w2, alphaC = w0 (action.c
				// RASTER_TRI_GRADIENT ordering). Interpolate shape-local coords,
				// map through the inverted gradient matrix to UV[0,1].
				double aA = w1 * inv_area, aB = w2 * inv_area, aC = w0 * inv_area;
				double sx = aA * R->sx0 + aB * R->sx1 + aC * R->sx2;
				double sy = aA * R->sy0 + aB * R->sy1 + aC * R->sy2;
				double gu = R->ia * sx + R->ic * sy + R->itx;
				double gv = R->ib * sx + R->id * sy + R->ity;
				double t = grad_t(R->style_type, gu, gv, R->focal_z, R->spread);
				uint32_t sampled = grad_sample(R->style_id, t);
				if (R->node_alpha < 0.999)
				{
					uint32_t sa = (uint32_t) (((sampled >> 24) & 0xFF)
					                          * R->node_alpha + 0.5);
					sampled = (sampled & 0x00FFFFFFu) | (sa << 24);
				}
				straight = sampled;
			}
			row[px] = cpu_blend_over(row[px], cpu_premul(straight));
		}
	}
}

// ---------------------------------------------------------------------------
// Entry point.
// ---------------------------------------------------------------------------
void avm2_cpu_raster_shape(uint32_t* buf, int W, int H, int transparent,
                           uint32_t vert_offset, uint32_t vert_count,
                           double wa, double wb, double wc, double wd,
                           double wtx, double wty, double node_alpha)
{
	(void) transparent;  // blending uses true source alpha; see header note.
	if (buf == NULL || W <= 0 || H <= 0 || vert_count < 3) return;
	if (node_alpha <= 0.0) return;

	for (uint32_t t = 0; t + 3 <= vert_count; t += 3)
	{
		uint32_t i0 = vert_offset + t;
		uint32_t style_packed = shape_data[i0][2];
		uint32_t style_index  = shape_data[i0][3];
		uint32_t style_type   = style_packed & 0xFFu;

		// Only solid (0x00, incl. strokes) and gradients (0x10/0x12/0x13) this
		// tranche. Bitmap fills (0x40-0x43) and anything else are skipped.
		int is_grad = ((style_type & 0xF0u) == 0x10u);
		if (style_type != 0x00u && !is_grad) continue;

		// Shape-local twips vertices.
		double sx[3], sy[3], dX[3], dY[3];
		for (int k = 0; k < 3; k++)
		{
			uint32_t j = i0 + (uint32_t) k;
			sx[k] = (double) bits_to_f(shape_data[j][0]);
			sy[k] = (double) bits_to_f(shape_data[j][1]);
			// world (local twips -> target twips), then /20 -> device pixels.
			dX[k] = (wa * sx[k] + wc * sy[k] + wtx) / 20.0;
			dY[k] = (wb * sx[k] + wd * sy[k] + wty) / 20.0;
		}

		RasterCtx R;
		R.buf = buf; R.W = W; R.H = H;
		R.node_alpha = node_alpha;

		if (!is_grad)
		{
			uint32_t id = style_index & 0xFFFFu;
			double r = color_data[id][0], g = color_data[id][1];
			double b = color_data[id][2], a = color_data[id][3] * node_alpha;
			R.is_gradient = 0;
			R.solid_argb = (f2b(a) << 24) | (f2b(r) << 16) | (f2b(g) << 8) | f2b(b);
			raster_tri(&R, dX[0], dY[0], dX[1], dY[1], dX[2], dY[2]);
			continue;
		}

		// Gradient.
		uint32_t id = style_index & 0xFFFFu;
		uint32_t style_upper = (style_index >> 16) & 0xFFFFu;
		R.is_gradient = 1;
		R.style_type = style_type;
		R.style_id = id;
		R.spread = (style_packed >> 8) & 0x3u;
		R.focal_z = (style_type == 0x13u)
		            ? ((double) style_upper - 32768.0) / 16384.0 : 0.0;
		R.sx0 = sx[0]; R.sy0 = sy[0];
		R.sx1 = sx[1]; R.sy1 = sy[1];
		R.sx2 = sx[2]; R.sy2 = sy[2];

		// INVERT_2D_AFFINE(uninv_mat_data + id*16) — verbatim from action.c.
		const float* m = uninv_mat_data + (size_t) id * 16;
		double _ia = m[0],  _ib = m[1];
		double _ic = m[4],  _id = m[5];
		double _itx = m[12], _ity = m[13];
		double _det = _ia * _id - _ib * _ic;
		if (_det == 0.0)
		{
			R.ia = R.ib = R.ic = R.id = R.itx = R.ity = 0.0;
		}
		else
		{
			double _inv = 1.0 / _det;
			R.ia =  _id * _inv;  R.ib = -_ib * _inv;
			R.ic = -_ic * _inv;  R.id =  _ia * _inv;
			R.itx = (_ic * _ity - _id * _itx) * _inv;
			R.ity = (_ib * _itx - _ia * _ity) * _inv;
		}
		raster_tri(&R, dX[0], dY[0], dX[1], dY[1], dX[2], dY[2]);
	}
}
