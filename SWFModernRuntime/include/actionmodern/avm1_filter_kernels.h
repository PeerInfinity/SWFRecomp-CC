#ifndef AVM1_FILTER_KERNELS_H
#define AVM1_FILTER_KERNELS_H

// AVM1 BitmapData.applyFilter -> the AVM2 CPU filter kernels (s27
// w2-applyfilter-cm; src/actionmodern/avm1_filter_kernels.c). Kept free of
// AVM2 headers so action.c does not pull the AVM2 type tree in: the bridge
// converts this to an Avm2FilterVal.

#include <stdint.h>

typedef struct SWFAppContext SWFAppContext;

// The quantized native filter in swf::Filter's units, exactly as
// avm2_filters.c avm2_filter_from_object produces them (Ruffle
// bitmap_filter.rs avm1_to_filter quantizes the AVM1 fields the same way).
typedef struct Avm1FilterKernelParams
{
	uint8_t kind;                       // Avm2FilterKind: 1 blur, 2 drop shadow,
	                                    // 3 glow, 4 bevel, 5 convolution,
	                                    // 7 gradient glow, 8 gradient bevel
	int32_t blur_x, blur_y;             // Fixed16
	int32_t angle, distance;            // Fixed16 (radians / pixels)
	int16_t strength;                   // Fixed8
	uint8_t quality;                    // 0..15
	uint8_t inner, knockout, on_top, hide_object;
	uint32_t color;  uint8_t alpha;     // shadow / glow / convolution / bevel shadow
	uint32_t color2; uint8_t alpha2;    // bevel highlight
	uint8_t conv_cols, conv_rows;
	const float* conv_matrix; uint32_t conv_len;
	float divisor, bias;
	uint8_t preserve_alpha, clamp;
	uint8_t grad_count;                 // <= 16
	uint32_t grad_colors[16];
	uint8_t grad_alphas[16];
	uint8_t grad_ratios[16];
} Avm1FilterKernelParams;

// Pixels are premultiplied 0xAARRGGBB, row-major (BitmapDataNative storage).
// Returns 1 when the kind was handled (the target is written), 0 otherwise.
int avm1_filter_kernels_apply(SWFAppContext* app,
                              uint32_t* dst_px, uint32_t dst_w, uint32_t dst_h, int dst_transparent,
                              uint32_t* src_px, uint32_t src_w, uint32_t src_h, int src_transparent,
                              int32_t sx, int32_t sy, int32_t sw, int32_t sh,
                              int32_t dx, int32_t dy, const Avm1FilterKernelParams* p);

#endif
