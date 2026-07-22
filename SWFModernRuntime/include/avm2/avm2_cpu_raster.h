#ifndef AVM2_CPU_RASTER_H
#define AVM2_CPU_RASTER_H

#include <stdint.h>

// AVM2 CPU shape rasterizer (T5). Dawn-free triangle rasterizer for the
// headless AVM2 render path (AVM2_CPU_DUMP) and BitmapData.draw() of a shape
// source. Composites a resident, pre-tessellated timeline-shape vertex range
// (shape_data[vert_offset .. vert_offset+vert_count)) into a premultiplied-ARGB
// target, mirroring the WGSL fragment shader (render_webgpu.c) so the CPU output
// is identical to the GPU/Dawn sink — hence to Ruffle (which the GPU path is
// already pixel-matched against).
//
// `w*` are the node's world matrix (shape-local twips -> target twips); the
// raster divides by 20 to reach device pixels, the same convention
// avm2_cpu_composite_bitmap uses (1 px = 20 twips, pixel centres at +0.5).
// `node_alpha` (0..1) is the concatenated display-tree alpha. `transparent` is
// the target BitmapData's transparency flag (kept for the store representation;
// blending itself always uses the true source alpha).
//
// Fill classes this tranche: solid (0x00), strokes (packed 0x80000000 -> low
// byte 0x00 -> solid via colour index), and gradients (0x10 linear / 0x12
// radial / 0x13 focal, pad/reflect/repeat). Bitmap fills (0x40-0x43) and masks
// (clip_depth, T7) are skipped.
void avm2_cpu_raster_shape(uint32_t* buf, int W, int H, int transparent,
                           uint32_t vert_offset, uint32_t vert_count,
                           double wa, double wb, double wc, double wd,
                           double wtx, double wty, double node_alpha);

// T4 Part B — fill descriptor for runtime (flash.display.Graphics) triangles.
// kind: 1 solid, 2 gradient. Solid uses r/g/b/a (straight 0..1). Gradient uses
// grad_type (0x10/0x12/0x13), spread (0/1/2), interp (0 rgb / 1 linearRGB),
// focal, a 256*4 RGBA8 `ramp`, and `inv2d` (the normalized inverse 2D affine
// mapping shape-local twips -> UV[0,1], as render_webgpu.c's dynamic path does).
typedef struct
{
	int kind;
	float r, g, b, a;
	unsigned char grad_type, spread, interp;
	float focal;
	const unsigned char* ramp;   // 256*4
	float inv2d[6];              // a,b,c,d,tx,ty
} Avm2GfxFill;

// Rasterize an explicit runtime triangle list (`xy_twips`, shape-local twips,
// vert_count % 3 == 0) into a premultiplied-ARGB target under the node world
// matrix (shape-local twips -> target twips; /20 -> device px) + concatenated
// alpha, shaded per `fill`. Mirrors avm2_cpu_raster_shape but for script-built
// geometry (no static shape_data range).
void avm2_cpu_raster_tris(uint32_t* buf, int W, int H, int transparent,
                          const float* xy_twips, uint32_t vert_count,
                          const Avm2GfxFill* fill,
                          double wa, double wb, double wc, double wd,
                          double wtx, double wty, double node_alpha);

#endif // AVM2_CPU_RASTER_H
