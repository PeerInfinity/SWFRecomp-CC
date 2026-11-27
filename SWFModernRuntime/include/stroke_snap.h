#pragma once

// Drawing-API stroke snapping (s28 n-drawapi-stroke-snap).
//
// Flash Player 32 rasterises EVERY stroke, timeline or runtime, by one device-
// space rule (pinned with the Flash oracle, SWFRecompDocs/plans/
// n-stroke-snap-report.md §1):
//   u = round(4 * device width)              width in quarter pixels
//   pixelHinting: SNAP, W = max(1, u / 4)
//   else:         SNAP when u <= 4 (W = 1), u == 8 (W = 2), u == 12 (W = 3);
//                 otherwise AA at width 2*floor(u/2)/4 (min 1 px)
// Snapped, exactly axis-aligned segments cover whole pixels; positions are
// quantised to the quarter-pixel grid.
//
// Timeline strokes get it from render_webgpu.c hairline_restage, fed by the
// recompiler's centre tables. Drawing-API strokes (AVM1 action.c, AVM2
// avm2_display.c) are tessellated at run time, so their stroke builders record
// the same inputs themselves: a triangle "soup" of segment quads + join/cap
// fans whose every vertex is centre + offset, the centre being a polyline
// vertex, and per vertex the axis flags of that polyline vertex. The renderer
// (render_webgpu_stroke_snap) rebuilds the soup in device space.
//
// The two drawing APIs differ only in the declared width (measured):
//   AVM1 lineStyle(t): t truncated to whole pixels   (1.5 -> 1, 2.25 -> 2)
//   AVM2 lineStyle(t): t rounded to whole pixels     (1.2 -> 1, 1.5 -> 2)

// Per-vertex axis flags (same bits as the recompiler's stroke_snap_data).
#define STROKE_SNAP_VERT 1u   // centre ends an exactly vertical segment (x snaps)
#define STROKE_SNAP_HORZ 2u   // centre ends an exactly horizontal one (y snaps)
// s28 n-join-disc: where the centre sits on its contour (Flash caps a closed
// contour's seam instead of joining it; render_webgpu.c stroke_snap_place).
#define STROKE_SNAP_END   4u   // an open end of the polyline (cap)
#define STROKE_SNAP_CLOSE 8u   // the seam vertex of a closed contour
// s29 n-seam-caps: the builders emit a closed contour's seam as TWO CAPS (one
// per adjacent segment) instead of a join, as Flash draws it. Every vertex of
// a seam cap, and of a seam-side segment-quad end, carries SEAM plus the axis
// of the segment it belongs to (OWN_V / OWN_H; neither = a diagonal). The low
// bits keep the seam's corner flags (both segments' axes | CLOSE), so the
// runtime can place it either as that segment's cap (HIGH, W = 1..3:
// stroke_seam_flags) or as the old snapped corner (LOW, W >= 4, kill switch
// SWF_STROKE_SEAM_CAPS=0). For round caps + round joins the unsnapped geometry
// is identical.
#define STROKE_SNAP_OWN_V 16u
#define STROKE_SNAP_OWN_H 32u
#define STROKE_SNAP_SEAM  64u

// Line flags (same bits as the recompiler's stroke_run_flags).
#define STROKE_FLAG_PIXEL_HINTING 1u
#define STROKE_FLAG_NO_HSCALE     2u
#define STROKE_FLAG_NO_VSCALE     4u

typedef struct StrokeSnapSrc {
	const float* xy;            // soup, local twips, n vertices
	const float* cen;           // per-vertex centre, local twips
	const unsigned char* sf;    // per-vertex STROKE_SNAP_* flags
	unsigned n;
	double decl_twips;          // declared width in local twips (0 = hairline)
	double emitted_twips;       // full width the soup was built at, local twips
	unsigned flags;             // STROKE_FLAG_*
	unsigned long long gen;     // unique id of this soup (cache key); 0 = uncached
	// Optional post-pass on the restaged copy (the translucent-stroke union).
	// Receives a malloc'd array it may replace (free the old one).
	void (*post)(float** xy, unsigned* n);
} StrokeSnapSrc;

// Soup generation ids (cache keys must never repeat). The counter is per
// translation unit, so each caller passes its own tag (AVM1 1, AVM2 2) into
// the top byte.
static inline unsigned long long stroke_snap_next_gen(unsigned tag)
{
	static unsigned long long g = 0;
	return (++g & 0x00FFFFFFFFFFFFFFull) | ((unsigned long long) tag << 56);
}

// AS3 LineScaleMode string -> STROKE_FLAG_NO_* bits ("none" = both,
// "vertical" = scale vertically only = no H scale, "horizontal" = no V
// scale). AVM1 lineStyle's noScale names mean the opposite and are swapped
// by the caller (action.c drawingParseLineFlags).
static inline unsigned stroke_scale_mode_flags(const char* s, int n)
{
	if (s == NULL) return 0;
	if (n == 4 && s[0] == 'n' && s[1] == 'o' && s[2] == 'n' && s[3] == 'e')
		return STROKE_FLAG_NO_HSCALE | STROKE_FLAG_NO_VSCALE;
	if (n == 8 && s[0] == 'v') return STROKE_FLAG_NO_HSCALE;
	if (n == 10 && s[0] == 'h') return STROKE_FLAG_NO_VSCALE;
	return 0;
}
