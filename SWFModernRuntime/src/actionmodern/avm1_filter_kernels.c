// AVM1 BitmapData.applyFilter for the non-ColorMatrix kinds (s27
// w2-applyfilter-cm): a bridge onto the AVM2 CPU filter kernels.
//
// AVM1 builds never link the AVM2 tree (verify_output.py: "AVM1 tests never
// compile src/avm2", avm2_cpu_raster.c excepted), and avm2_bitmap.c's kernels
// are file-static. So this TU RE-COMPILES avm2_bitmap.c with
// AVM2_BITMAP_KERNELS_ONLY defined: only the colour helpers, bd_get_raw /
// bd_set_raw, the PixelRegion helpers and the "applyFilter /
// generateFilterRect" kernel block survive (every AVM2 API function is
// #ifndef'd out), each with static linkage, so it links next to the full
// avm2_bitmap.c in a hybrid build without a clash. Whatever the kernels do
// for AVM2 (Flash's blur / glow / drop-shadow / bevel model, Flash
// convolution semantics) AVM1 gets byte-for-byte, with no second copy to
// drift. Ruffle runs one apply_filter for both VMs too
// (core/src/bitmap/operations.rs, reached from avm1 bitmap_data.rs).
//
// Pixel form: AVM1 BitmapDataNative.pixels are premultiplied 0xAARRGGBB
// (setPixel32 stores premultiplyAlpha(colour), getPixel32 unpremultiplies),
// the same storage as Avm2BitmapDataExt, so the buffers are wrapped as-is.
//
// The kernels allocate through avm2_alloc(ctx, n) / heap_free(ctx->app, p);
// avm2_alloc is renamed for this TU (it lives in avm2_main.c, which an AVM1
// build lacks) and a private context carries only `app`.

#include <actionmodern/avm1_filter_kernels.h>

#define AVM2_BITMAP_KERNELS_ONLY 1
#define avm2_alloc avm1_fk_alloc

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

// Flat build directories (verify_output.py, build_test.sh) carry a copy of
// avm2_bitmap.c under a non-.c name so their *.c glob does not compile the
// whole AVM2 TU into an AVM1 build; the source tree (CMake, the wasm scripts)
// reaches it by its relative path.
#if defined(__has_include)
#  if __has_include("avm2_bitmap_kernels.inc")
#    include "avm2_bitmap_kernels.inc"
#  else
#    include "../avm2/avm2_bitmap.c"
#  endif
#else
#  include "../avm2/avm2_bitmap.c"
#endif

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif


void* avm1_fk_alloc(Avm2Context* ctx, uint32_t size)
{
	return heap_alloc(ctx->app, size > 0 ? size : 1);
}

int avm1_filter_kernels_apply(SWFAppContext* app,
                              uint32_t* dst_px, uint32_t dst_w, uint32_t dst_h, int dst_transparent,
                              uint32_t* src_px, uint32_t src_w, uint32_t src_h, int src_transparent,
                              int32_t sx, int32_t sy, int32_t sw, int32_t sh,
                              int32_t dx, int32_t dy, const Avm1FilterKernelParams* p)
{
	if (dst_px == NULL || src_px == NULL || p == NULL) return 0;
	Avm2FilterVal fv;
	memset(&fv, 0, sizeof(fv));
	fv.kind = p->kind;
	fv.blur_x = p->blur_x; fv.blur_y = p->blur_y;
	fv.angle = p->angle; fv.distance = p->distance;
	fv.strength = p->strength; fv.quality = p->quality;
	fv.inner = p->inner; fv.knockout = p->knockout;
	fv.on_top = p->on_top; fv.hide_object = p->hide_object;
	fv.color = p->color & 0xFFFFFF; fv.alpha = p->alpha;
	fv.color2 = p->color2 & 0xFFFFFF; fv.alpha2 = p->alpha2;
	fv.conv_cols = p->conv_cols; fv.conv_rows = p->conv_rows;
	fv.conv_matrix = (float*) p->conv_matrix; fv.conv_len = p->conv_len;
	fv.divisor = p->divisor; fv.bias = p->bias;
	fv.preserve_alpha = p->preserve_alpha; fv.clamp = p->clamp;
	fv.grad_count = p->grad_count > AVM2_FILTER_MAX_GRAD ? AVM2_FILTER_MAX_GRAD : p->grad_count;
	for (int i = 0; i < fv.grad_count; i++)
	{
		fv.grad_colors[i] = p->grad_colors[i];
		fv.grad_alphas[i] = p->grad_alphas[i];
		fv.grad_ratios[i] = p->grad_ratios[i];
	}
	const Avm2FilterVal* f = &fv;
	static Avm2Context kctx;   // the kernels read only ctx->app
	kctx.app = app;

	Avm2BitmapDataExt dst = { 0 }, src = { 0 };
	dst.width = dst_w; dst.height = dst_h; dst.transparency = dst_transparent ? 1 : 0;
	dst.pixels = dst_px;
	src.width = src_w; src.height = src_h; src.transparency = src_transparent ? 1 : 0;
	// applyFilter(bmp, ...) onto itself: every kernel reads the whole source
	// before writing, except the pass-through copy below; snapshot it so an
	// overlapping destPoint reads the ORIGINAL pixels (Ruffle copies too).
	uint32_t* snap = NULL;
	if (src_px == dst_px)
	{
		size_t n = (size_t) src_w * src_h;
		snap = (uint32_t*) malloc((n ? n : 1) * sizeof(uint32_t));
		if (snap == NULL) return 0;
		memcpy(snap, src_px, n * sizeof(uint32_t));
		src.pixels = snap;
	}
	else
		src.pixels = src_px;

	int handled = 1;
	int is_conv = (f->kind == AVM2_FILTER_CONVOLUTION
	               && f->conv_cols != 0 && f->conv_rows != 0 && f->conv_matrix != NULL);
	if (f->kind == AVM2_FILTER_BLUR || fk_is_glowlike(f->kind))
	{
		fb_apply_grown(&dst, &src, sx, sy, sw, sh, dx, dy, f);
	}
	else if (is_conv)
	{
		bd_apply_convolution(&kctx, &dst, &src, sx, sy, sw, sh, dx, dy, f);
	}
	else if (f->kind == AVM2_FILTER_GRADIENT_GLOW || f->kind == AVM2_FILTER_GRADIENT_BEVEL
	         || f->kind == AVM2_FILTER_CONVOLUTION)
	{
		// bd_apply_filter's pass-through (Ruffle is_filter_supported false:
		// "treat this like a copy"): the clipped source rect, unpremultiplied
		// and re-premultiplied for the target's transparency.
		PixelRegion src_region = pr_for_region_i32(sx, sy, sw, sh);
		pr_clamp(&src_region, src.width, src.height);
		PixelRegion dst_region = pr_whole(dst.width, dst.height);
		pr_clamp_intersection(&dst_region, dx, dy, (int32_t) src_region.x_min,
		                      (int32_t) src_region.y_min, (int32_t) pr_w(&src_region),
		                      (int32_t) pr_h(&src_region), &src_region);
		uint32_t rw = pr_w(&dst_region), rh = pr_h(&dst_region);
		for (uint32_t y = 0; y < rh; y++)
			for (uint32_t x = 0; x < rw; x++)
			{
				uint32_t raw = bd_get_raw(&src, src_region.x_min + x, src_region.y_min + y);
				uint32_t straight = src.transparency ? unmul(raw) : raw;
				bd_set_raw(&dst, dst_region.x_min + x, dst_region.y_min + y,
				           premul(straight, dst.transparency));
			}
	}
	else
		handled = 0;
	free(snap);
	return handled;
}
