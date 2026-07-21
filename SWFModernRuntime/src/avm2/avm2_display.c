// flash.display — the AVM2 display tree (Stage 5 tranches 2-4).
//
// An AVM2-owned display model driven by the recompiler's static timeline
// tables (avm2_abc.h "Static timeline tables"); zero entanglement with the
// AVM1 tag.c runtime. Semantics ported from Ruffle:
//   - display_object.rs / globals/flash/display/display_object.rs
//     (property surface incl. matrix decomposition + invalid-float rules)
//   - container.rs / display_object_container.rs (render-list vs
//     depth-list duality, child ops, 2006/2024/2025/2150 error codes,
//     timeline lock/pull)
//   - movie_clip.rs + frame_lifecycle.rs (per-tick phase order, deferred
//     AS3 place/remove, queued gotos, catch-up construction)
//   - stage.rs (frameRate clamping, color alpha rules)
//
// One ext struct (Avm2DisplayObjectExt) serves the whole ladder.

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <memory/heap.h>

#include <avm2/avm2_gc.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>
#include <avm2/avm2_value.h>

enum
{
	PHASE_IDLE = 0,
	PHASE_ENTER = 1,
	PHASE_CONSTRUCT = 2,
	PHASE_FRAME_SCRIPTS = 3,
	PHASE_EXIT = 4,
};

// ---------------------------------------------------------------------------
// Ext access + class checks
// ---------------------------------------------------------------------------

static int class_is_a(const Avm2Class* cls, const Avm2Class* ancestor)
{
	for (const Avm2Class* c = cls; c != NULL; c = c->super_class)
	{
		if (c == ancestor) return 1;
	}
	return 0;
}

Avm2DisplayObjectExt* avm2_display_ext_of(Avm2Context* ctx, Avm2Object* obj)
{
	if (obj == NULL || obj->cls == NULL || obj->native_ext == NULL) return NULL;
	if (!class_is_a(obj->cls, ctx->builtins.display_object_class)) return NULL;
	return (Avm2DisplayObjectExt*) obj->native_ext;
}

static int is_container(Avm2Context* ctx, Avm2Object* obj)
{
	return obj != NULL && obj->cls != NULL
	       && class_is_a(obj->cls, ctx->builtins.doc_class);
}

static Avm2DisplayObjectExt* this_display(Avm2Activation* act)
{
	if (act->this_val.kind != AVM2_VALUE_OBJECT) return NULL;
	return avm2_display_ext_of(act->ctx, act->this_val.u.obj);
}

static Avm2Object* this_obj(Avm2Activation* act)
{
	return act->this_val.kind == AVM2_VALUE_OBJECT ? act->this_val.u.obj : NULL;
}

// ---------------------------------------------------------------------------
// Orphans (constructed display objects with no parent still get frame
// phases — Ruffle orphan_manager)
// ---------------------------------------------------------------------------

static Avm2Object** g_orphans;
static uint32_t g_orphan_count, g_orphan_cap;

static void orphan_add(Avm2Context* ctx, Avm2Object* obj)
{
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		if (g_orphans[i] == obj) return;
	}
	if (g_orphan_count == g_orphan_cap)
	{
		uint32_t nc = g_orphan_cap > 0 ? g_orphan_cap * 2 : 16;
		Avm2Object** grown = avm2_alloc(ctx, nc * sizeof(Avm2Object*));
		memcpy(grown, g_orphans, g_orphan_count * sizeof(Avm2Object*));
		g_orphans = grown;
		g_orphan_cap = nc;
	}
	g_orphans[g_orphan_count++] = obj;
}

static void orphan_cleanup(Avm2Context* ctx)
{
	uint32_t w = 0;
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, g_orphans[i]);
		if (ext != NULL && ext->parent == NULL)
		{
			g_orphans[w++] = g_orphans[i];
		}
	}
	g_orphan_count = w;
}

// Frame-script cleanup queue (Ruffle frame_script_cleanup_queue).
static Avm2Object** g_fs_cleanup;
static uint32_t g_fs_cleanup_count, g_fs_cleanup_cap;

static void fs_cleanup_push(Avm2Context* ctx, Avm2Object* obj)
{
	if (g_fs_cleanup_count == g_fs_cleanup_cap)
	{
		uint32_t nc = g_fs_cleanup_cap > 0 ? g_fs_cleanup_cap * 2 : 8;
		Avm2Object** grown = avm2_alloc(ctx, nc * sizeof(Avm2Object*));
		memcpy(grown, g_fs_cleanup, g_fs_cleanup_count * sizeof(Avm2Object*));
		g_fs_cleanup = grown;
		g_fs_cleanup_cap = nc;
	}
	g_fs_cleanup[g_fs_cleanup_count++] = obj;
}

// Class -> SymbolClass char binding (built at stage build).
typedef struct SymbolClassMap
{
	Avm2Class* cls;
	uint16_t char_id;
} SymbolClassMap;
static SymbolClassMap* g_symbol_map;
static uint32_t g_symbol_map_count;

static uint16_t char_for_class(Avm2Class* cls)
{
	// A class inherits its SymbolClass binding from any ancestor
	// (movieclip_super_is_symbol: `new ChildClass()` where SuperClass is
	// the bound class still instantiates the symbol's timeline).
	for (Avm2Class* c = cls; c != NULL; c = c->super_class)
	{
		for (uint32_t i = 0; i < g_symbol_map_count; i++)
		{
			if (g_symbol_map[i].cls == c) return g_symbol_map[i].char_id;
		}
	}
	return 0;
}

// Exported for avm2_text.c (Font symbol binding).
uint16_t avm2_display_char_for_class(Avm2Class* cls)
{
	return char_for_class(cls);
}

// While instantiating a timeline child the alloc hook must not apply the
// script-created extras (skip flag, orphan registration, symbol lookup).
static int g_timeline_instantiation;

// ---------------------------------------------------------------------------
// Static-table lookups
// ---------------------------------------------------------------------------

static Avm2Class* g_textfield_class;
static Avm2Class* g_statictext_class;
static uint8_t g_stage_invalidated_flag;

static const Avm2TimelineData* timeline_for_char(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_timeline_count; i++)
	{
		if (avm2_generated_timelines[i].char_id == char_id)
		{
			return &avm2_generated_timelines[i];
		}
	}
	return NULL;
}

static const Avm2CharInfo* char_info(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_char_count; i++)
	{
		if (avm2_generated_chars[i].char_id == char_id)
		{
			return &avm2_generated_chars[i];
		}
	}
	return NULL;
}

static const Avm2ShapeGeom* shape_geom_for(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_shape_geom_count; i++)
	{
		if (avm2_generated_shape_geom[i].char_id == char_id)
		{
			return &avm2_generated_shape_geom[i];
		}
	}
	return NULL;
}

// Resolve a placed character's solid-fill shape geometry onto its ext (T1).
// Called at place-time so the render walk needs no per-frame lookup. Clears
// the range for anything that isn't a renderable solid shape (sprite,
// gradient/stroke shape, script-created, or unresolved char).
static void resolve_shape_geom(Avm2DisplayObjectExt* ext, uint16_t char_id)
{
	const Avm2ShapeGeom* sg = shape_geom_for(char_id);
	if (sg != NULL && sg->solid_only && sg->vert_count > 0)
	{
		ext->shape_vert_offset = sg->vert_offset;
		ext->shape_vert_count = sg->vert_count;
	}
	else
	{
		ext->shape_vert_offset = 0;
		ext->shape_vert_count = 0;
	}
}

// ---------------------------------------------------------------------------
// Matrix / decomposition math (Ruffle DisplayObjectBase)
// ---------------------------------------------------------------------------

static int32_t twips_from_pixels(double px)
{
	double t = px * 20.0;
	if (isnan(t)) return 0;
	if (t >= 2147483647.0) return INT32_MAX;
	if (t <= -2147483648.0) return INT32_MIN;
	return (int32_t) t;  // C truncation toward zero
}

static double twips_to_pixels(int32_t t)
{
	return (double) t / 20.0;
}

static void cache_scale_rotation(Avm2DisplayObjectExt* ext)
{
	if (ext->scale_rot_cached) return;
	double a = ext->mtx_a, b = ext->mtx_b, c = ext->mtx_c, d = ext->mtx_d;
	double rotation_x = atan2(b, a);
	double rotation_y = atan2(-c, d);
	ext->scale_x = sqrt(a * a + b * b);
	ext->scale_y = sqrt(c * c + d * d);
	ext->rotation_deg = rotation_x * (180.0 / M_PI);
	ext->skew = rotation_y - rotation_x;
	ext->scale_rot_cached = 1;
}

static void set_rotation_internal(Avm2DisplayObjectExt* ext, double deg)
{
	cache_scale_rotation(ext);
	ext->rotation_deg = deg;
	double rad = deg * (M_PI / 180.0);
	if (isnan(rad)) return;  // NaN rotation leaves the matrix untouched
	double cos_x = cos(rad), sin_x = sin(rad);
	double cos_y = cos(rad + ext->skew), sin_y = sin(rad + ext->skew);
	ext->mtx_a = (float) (ext->scale_x * cos_x);
	ext->mtx_b = (float) (ext->scale_x * sin_x);
	ext->mtx_c = (float) (ext->scale_y * -sin_y);
	ext->mtx_d = (float) (ext->scale_y * cos_y);
}

static void set_scale_x_internal(Avm2DisplayObjectExt* ext, double unit)
{
	cache_scale_rotation(ext);
	ext->scale_x = unit;  // NaN stored verbatim (getter reports it)
	double calc = isnan(unit) ? 0.0 : unit;
	double rot = ext->rotation_deg * (M_PI / 180.0);
	if (isnan(rot)) rot = 0.0;
	ext->mtx_a = (float) (cos(rot) * calc);
	ext->mtx_b = (float) (sin(rot) * calc);
}

static void set_scale_y_internal(Avm2DisplayObjectExt* ext, double unit)
{
	cache_scale_rotation(ext);
	ext->scale_y = unit;
	double calc = isnan(unit) ? 0.0 : unit;
	double rot = ext->rotation_deg * (M_PI / 180.0);
	if (isnan(rot)) rot = 0.0;
	ext->mtx_c = (float) (-sin(rot + ext->skew) * calc);
	ext->mtx_d = (float) (cos(rot + ext->skew) * calc);
}

// ---------------------------------------------------------------------------
// Bounds (Ruffle bounds_with_transform)
// ---------------------------------------------------------------------------

typedef struct Rect
{
	int valid;
	double xmin, xmax, ymin, ymax;  // twips
} Rect;

typedef struct Mat
{
	double a, b, c, d;
	double tx, ty;  // twips
} Mat;

static Mat ext_matrix(const Avm2DisplayObjectExt* ext)
{
	Mat m = { ext->mtx_a, ext->mtx_b, ext->mtx_c, ext->mtx_d,
	          (double) ext->mtx_tx, (double) ext->mtx_ty };
	return m;
}

static Mat mat_identity(void)
{
	Mat m = { 1, 0, 0, 1, 0, 0 };
	return m;
}

static Mat mat_mul(const Mat* m, const Mat* n)  // m * n
{
	Mat r;
	r.a = m->a * n->a + m->c * n->b;
	r.b = m->b * n->a + m->d * n->b;
	r.c = m->a * n->c + m->c * n->d;
	r.d = m->b * n->c + m->d * n->d;
	r.tx = m->a * n->tx + m->c * n->ty + m->tx;
	r.ty = m->b * n->tx + m->d * n->ty + m->ty;
	return r;
}

static void rect_union_point(Rect* r, double x, double y)
{
	if (!r->valid)
	{
		r->valid = 1;
		r->xmin = r->xmax = x;
		r->ymin = r->ymax = y;
		return;
	}
	if (x < r->xmin) r->xmin = x;
	if (x > r->xmax) r->xmax = x;
	if (y < r->ymin) r->ymin = y;
	if (y > r->ymax) r->ymax = y;
}

static void rect_union_xform(Rect* acc, const Rect* src, const Mat* m)
{
	if (!src->valid) return;
	double xs[2] = { src->xmin, src->xmax };
	double ys[2] = { src->ymin, src->ymax };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			double x = m->a * xs[i] + m->c * ys[j] + m->tx;
			double y = m->b * xs[i] + m->d * ys[j] + m->ty;
			rect_union_point(acc, x, y);
		}
	}
}

static Rect char_self_bounds(uint16_t char_id)
{
	Rect r = { 0, 0, 0, 0, 0 };
	const Avm2CharInfo* ci = char_info(char_id);
	if (ci != NULL
	    && (ci->xmin != 0 || ci->xmax != 0 || ci->ymin != 0 || ci->ymax != 0))
	{
		r.valid = 1;
		r.xmin = ci->xmin;
		r.xmax = ci->xmax;
		r.ymin = ci->ymin;
		r.ymax = ci->ymax;
	}
	return r;
}

int avm2_text_self_bounds(struct Avm2EditTextExt* et, int32_t* out_xywh);

static Rect display_self_bounds(const Avm2DisplayObjectExt* ext)
{
	if (ext->edittext != NULL)
	{
		int32_t b[4];
		if (avm2_text_self_bounds(ext->edittext, b))
		{
			Rect r2 = { 1, (double) b[0], (double) (b[0] + b[2]),
			            (double) b[1], (double) (b[1] + b[3]) };
			return r2;
		}
	}
	Rect r = char_self_bounds(ext->char_id);
	if (ext->draw_valid)
	{
		Rect d = { 1, (double) ext->draw_xmin, (double) ext->draw_xmax,
		           (double) ext->draw_ymin, (double) ext->draw_ymax };
		if (!r.valid)
		{
			r = d;
		}
		else
		{
			if (d.xmin < r.xmin) r.xmin = d.xmin;
			if (d.xmax > r.xmax) r.xmax = d.xmax;
			if (d.ymin < r.ymin) r.ymin = d.ymin;
			if (d.ymax > r.ymax) r.ymax = d.ymax;
		}
	}
	return r;
}

// bounds_with_transform: self bounds + children, all through `m`.
static void bounds_with_transform(Avm2Context* ctx, Avm2Object* obj,
                                  const Mat* m, Rect* acc)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	{
		Rect self = display_self_bounds(ext);
		// flash.display.Bitmap self bounds come from its cached BitmapData
		// size (avm2_bitmap.c); always a valid rect (0x0 when no data).
		if (!self.valid && ext->is_bitmap)
		{
			uint32_t bw = 0, bh = 0;
			if (avm2_bitmap_self_dims(ctx, obj, &bw, &bh))
			{
				self.valid = 1;
				self.xmin = 0;
				self.xmax = (double) bw * 20.0;
				self.ymin = 0;
				self.ymax = (double) bh * 20.0;
			}
		}
		rect_union_xform(acc, &self, m);
	}
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, ext->render_list[i]);
		if (cext == NULL) continue;
		Mat cm = ext_matrix(cext);
		Mat combined = mat_mul(m, &cm);
		bounds_with_transform(ctx, ext->render_list[i], &combined, acc);
	}
}

static Rect display_bounds(Avm2Context* ctx, Avm2Object* obj, int with_own_matrix)
{
	Rect acc = { 0, 0, 0, 0, 0 };
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return acc;
	Mat m = with_own_matrix ? ext_matrix(ext) : mat_identity();
	if (with_own_matrix)
	{
		// Width/height measure the object in its parent-facing space but
		// without translation (translation cancels in width/height).
	}
	bounds_with_transform(ctx, obj, &m, &acc);
	return acc;
}

static double rect_width_px(const Rect* r)
{
	return r->valid ? (r->xmax - r->xmin) / 20.0 : 0.0;
}

static double rect_height_px(const Rect* r)
{
	return r->valid ? (r->ymax - r->ymin) / 20.0 : 0.0;
}

// ---------------------------------------------------------------------------
// Render / depth list primitives (Ruffle container.rs)
// ---------------------------------------------------------------------------

static int render_index_of(Avm2DisplayObjectExt* ext, Avm2Object* child)
{
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		if (ext->render_list[i] == child) return (int) i;
	}
	return -1;
}

static void render_list_grow(Avm2Context* ctx, Avm2DisplayObjectExt* ext)
{
	if (ext->render_len == ext->render_cap)
	{
		uint32_t nc = ext->render_cap > 0 ? ext->render_cap * 2 : 8;
		Avm2Object** grown = avm2_alloc(ctx, nc * sizeof(Avm2Object*));
		memcpy(grown, ext->render_list, ext->render_len * sizeof(Avm2Object*));
		ext->render_list = grown;
		ext->render_cap = nc;
	}
}

static void render_list_insert(Avm2Context* ctx, Avm2DisplayObjectExt* ext,
                               uint32_t id, Avm2Object* child)
{
	render_list_grow(ctx, ext);
	if (id > ext->render_len) id = ext->render_len;
	memmove(&ext->render_list[id + 1], &ext->render_list[id],
	        (ext->render_len - id) * sizeof(Avm2Object*));
	ext->render_list[id] = child;
	ext->render_len++;
}

static int render_list_remove(Avm2DisplayObjectExt* ext, Avm2Object* child)
{
	int pos = render_index_of(ext, child);
	if (pos < 0) return 0;
	memmove(&ext->render_list[pos], &ext->render_list[pos + 1],
	        (ext->render_len - pos - 1) * sizeof(Avm2Object*));
	ext->render_len--;
	return 1;
}

// insert_at_id (Ruffle): MOVE if already present (rotate), else insert.
static void render_insert_at_id(Avm2Context* ctx, Avm2DisplayObjectExt* ext,
                                Avm2Object* child, uint32_t id)
{
	int old = render_index_of(ext, child);
	if (old >= 0)
	{
		uint32_t old_id = (uint32_t) old;
		if (old_id < id)
		{
			uint32_t last = (id < ext->render_len) ? id : ext->render_len - 1;
			Avm2Object* tmp = ext->render_list[old_id];
			memmove(&ext->render_list[old_id], &ext->render_list[old_id + 1],
			        (last - old_id) * sizeof(Avm2Object*));
			ext->render_list[last] = tmp;
		}
		else if (old_id > id)
		{
			Avm2Object* tmp = ext->render_list[old_id];
			memmove(&ext->render_list[id + 1], &ext->render_list[id],
			        (old_id - id) * sizeof(Avm2Object*));
			ext->render_list[id] = tmp;
		}
		return;
	}
	render_list_insert(ctx, ext, id, child);
}

static Avm2Object* child_by_depth(Avm2DisplayObjectExt* ext, int32_t depth)
{
	for (uint32_t i = 0; i < ext->depth_len; i++)
	{
		if (ext->depth_list[i].depth == depth) return ext->depth_list[i].child;
	}
	return NULL;
}

static void depth_list_remove_at(Avm2DisplayObjectExt* ext, uint32_t i)
{
	memmove(&ext->depth_list[i], &ext->depth_list[i + 1],
	        (ext->depth_len - i - 1) * sizeof(Avm2DepthEntry));
	ext->depth_len--;
}

// Remove the depth entry iff it maps to exactly this child.
static void remove_child_from_depth_list(Avm2DisplayObjectExt* ext, Avm2Object* child)
{
	for (uint32_t i = 0; i < ext->depth_len; i++)
	{
		if (ext->depth_list[i].child == child)
		{
			depth_list_remove_at(ext, i);
			return;
		}
	}
}

// Insert into depth_list (sorted); returns the previous child at depth (or
// NULL). Also computes the render slot per Ruffle replace_at_depth.
static Avm2Object* replace_at_depth(Avm2Context* ctx, Avm2DisplayObjectExt* ext,
                                    Avm2Object* child, int32_t depth)
{
	Avm2Object* prev = NULL;
	uint32_t pos = ext->depth_len;
	for (uint32_t i = 0; i < ext->depth_len; i++)
	{
		if (ext->depth_list[i].depth == depth)
		{
			prev = ext->depth_list[i].child;
			ext->depth_list[i].child = child;
			pos = UINT32_MAX;
			break;
		}
		if (ext->depth_list[i].depth > depth)
		{
			pos = i;
			break;
		}
	}
	if (pos != UINT32_MAX)
	{
		if (ext->depth_len == ext->depth_cap)
		{
			uint32_t nc = ext->depth_cap > 0 ? ext->depth_cap * 2 : 8;
			Avm2DepthEntry* grown = avm2_alloc(ctx, nc * sizeof(Avm2DepthEntry));
			memcpy(grown, ext->depth_list, ext->depth_len * sizeof(Avm2DepthEntry));
			ext->depth_list = grown;
			ext->depth_cap = nc;
		}
		memmove(&ext->depth_list[pos + 1], &ext->depth_list[pos],
		        (ext->depth_len - pos) * sizeof(Avm2DepthEntry));
		ext->depth_list[pos].depth = depth;
		ext->depth_list[pos].child = child;
		ext->depth_len++;
	}

	// Render slot.
	if (prev != NULL)
	{
		int ppos = render_index_of(ext, prev);
		Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, prev);
		if (pext != NULL && !pext->placed_by_avm2_script && ppos >= 0)
		{
			ext->render_list[ppos] = child;
			return prev;
		}
		if (ppos >= 0)
		{
			render_list_insert(ctx, ext, (uint32_t) ppos + 1, child);
			return NULL;
		}
		render_list_insert(ctx, ext, ext->render_len, child);
		return NULL;
	}
	// No previous at depth: land just before the next-higher depth child.
	Avm2Object* above = NULL;
	for (uint32_t i = 0; i < ext->depth_len; i++)
	{
		if (ext->depth_list[i].depth > depth)
		{
			above = ext->depth_list[i].child;
			break;
		}
	}
	if (above != NULL)
	{
		int apos = render_index_of(ext, above);
		if (apos >= 0)
		{
			render_list_insert(ctx, ext, (uint32_t) apos, child);
			return NULL;
		}
	}
	render_list_insert(ctx, ext, ext->render_len, child);
	return NULL;
}

// ---------------------------------------------------------------------------
// Stage / root / naming helpers
// ---------------------------------------------------------------------------

static int is_on_stage(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2Object* p = obj;
	while (p != NULL)
	{
		Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, p);
		if (ext == NULL) return 0;
		if (ext->is_stage) return 1;
		p = ext->parent;
	}
	return 0;
}

static Avm2Object* avm2_root_of(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2Object* node = obj;
	while (node != NULL)
	{
		Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, node);
		if (ext == NULL) return NULL;
		if (ext->is_root) return node;
		node = ext->parent;
	}
	return NULL;
}

static Avm2Object* stage_of(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2Object* node = obj;
	while (node != NULL)
	{
		Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, node);
		if (ext == NULL) return NULL;
		if (ext->is_stage) return node;
		node = ext->parent;
	}
	return NULL;
}

static void set_default_instance_name(Avm2Context* ctx, Avm2DisplayObjectExt* ext)
{
	if (ext->name != NULL || ext->is_stage) return;
	char buf[32];
	ctx->instance_counter++;  // names are 1-based: instance1, instance2, ...
	snprintf(buf, sizeof(buf), "instance%u", ctx->instance_counter);
	ext->name = avm2_string_from_literal(ctx, buf);
}

// ---------------------------------------------------------------------------
// added/removed events (Ruffle container.rs dispatch_*_event)
// ---------------------------------------------------------------------------

static void dispatch_simple_event(Avm2Context* ctx, Avm2Object* target,
                                  const char* type, int bubbles)
{
	Avm2Object* evt = avm2_event_new(ctx, avm2_string_from_literal(ctx, type),
	                                 bubbles, 0);
	avm2_dispatch_event(ctx, target, evt);
}

static void dispatch_added_to_stage_recursive(Avm2Context* ctx, Avm2Object* child)
{
	dispatch_simple_event(ctx, child, "addedToStage", 0);
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, child);
	if (ext == NULL) return;
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		dispatch_added_to_stage_recursive(ctx, ext->render_list[i]);
	}
	// Buttons recurse into their CURRENT state child (Ruffle
	// dispatch_added_to_stage_event's as_avm2_button arm).
	if (ext->btn_up != NULL)
	{
		dispatch_added_to_stage_recursive(ctx, ext->btn_up);
	}
}

static void dispatch_removed_from_stage_recursive(Avm2Context* ctx, Avm2Object* child)
{
	dispatch_simple_event(ctx, child, "removedFromStage", 0);
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, child);
	if (ext == NULL) return;
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		dispatch_removed_from_stage_recursive(ctx, ext->render_list[i]);
	}
}

static void dispatch_added_event(Avm2Context* ctx, Avm2Object* parent,
                                 Avm2Object* child, int child_was_on_stage)
{
	dispatch_simple_event(ctx, child, "added", 1);
	if (is_on_stage(ctx, parent) && !child_was_on_stage)
	{
		dispatch_added_to_stage_recursive(ctx, child);
	}
}

static void dispatch_removed_event(Avm2Context* ctx, Avm2Object* child)
{
	// A never-constructed timeline child has no AVM2 object in Ruffle's
	// model (object2 None): no events (a goto that places-then-removes a
	// child within one tick is silent — movieclip_displayevents_*goto).
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext != NULL && !cext->constructed) return;
	dispatch_simple_event(ctx, child, "removed", 1);
	if (is_on_stage(ctx, child))
	{
		dispatch_removed_from_stage_recursive(ctx, child);
	}
}

// ---------------------------------------------------------------------------
// Core add / remove
// ---------------------------------------------------------------------------

static void full_remove_child(Avm2Context* ctx, Avm2DisplayObjectExt* pext,
                              Avm2Object* child);

// insert_at_index (Ruffle ChildContainer::insert_at_index).
static void insert_at_index(Avm2Context* ctx, Avm2Object* parent, Avm2Object* child,
                            uint32_t index)
{
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (pext == NULL || cext == NULL) return;

	int parent_changed;
	if (cext->parent != NULL)
	{
		if (cext->parent != parent)
		{
			Avm2DisplayObjectExt* old = avm2_display_ext_of(ctx, cext->parent);
			if (old != NULL) full_remove_child(ctx, old, child);
			parent_changed = 1;
		}
		else
		{
			parent_changed = 0;
		}
	}
	else
	{
		parent_changed = 1;
	}

	int child_was_on_stage = is_on_stage(ctx, child);
	cext->place_frame = 0;
	cext->parent = parent;
	render_insert_at_id(ctx, pext, child, index);
	if (parent_changed)
	{
		dispatch_added_event(ctx, parent, child, child_was_on_stage);
	}
}

// Full removal (Ruffle remove_child, AVM2 direct path).
static Avm2Object* g_stage_focus;
static void set_focus(Avm2Context* ctx, Avm2Object* new_focus);

static void full_remove_child(Avm2Context* ctx, Avm2DisplayObjectExt* pext,
                              Avm2Object* child)
{
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	// Removing the focused object clears stage.focus (textfield_unload).
	if (child == g_stage_focus) g_stage_focus = NULL;
	dispatch_removed_event(ctx, child);
	remove_child_from_depth_list(pext, child);
	int removed = render_list_remove(pext, child);
	if (removed && cext != NULL)
	{
		// Timeline removal nulls the parent's named field (Ruffle 10b);
		// script removals (placed_by_avm2_script) keep it.
		if (!cext->placed_by_avm2_script && cext->has_explicit_name
		    && cext->name != NULL && cext->parent != NULL)
		{
			// Read the current value first: null/undefined values are left
			// alone (the setter is observably NOT invoked), read errors are
			// swallowed entirely, and any other value is nulled — even one
			// that is not this child (remove_child_clear_field).
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				Avm2Value cur = avm2_get_public_property(
					ctx, avm2_object_value(cext->parent),
					cext->name->utf8, cext->name->len, NULL);
				if (cur.kind != AVM2_VALUE_NULL && cur.kind != AVM2_VALUE_UNDEFINED)
				{
					avm2_set_public_property(ctx, avm2_object_value(cext->parent),
					                         cext->name->utf8, cext->name->len,
					                         avm2_null());
				}
			}
			avm2_try_pop_frame(&top);
		}
		cext->parent = NULL;
		// Never-constructed children have no AVM2 life to continue
		// (object2 None in Ruffle): no orphan tracking, no frame scripts.
		if (cext->constructed)
		{
			orphan_add(ctx, child);
		}
	}
}

// ---------------------------------------------------------------------------
// Allocation split: alloc-without-ctor + run-ctor (timeline path)
// ---------------------------------------------------------------------------

static Avm2Object* display_alloc_instance(Avm2Context* ctx, Avm2Class* cls)
{
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT,
	                                    cls->ivtable.slot_count + 1);
	obj->cls = cls;
	obj->vtable = &cls->ivtable;
	obj->proto = cls->prototype_obj;
	avm2_slots_init_defaults(ctx, obj, &cls->ivtable);
	if (cls->native_ext_size > 0)
	{
		obj->native_ext = avm2_alloc(ctx, cls->native_ext_size);
		memset(obj->native_ext, 0, cls->native_ext_size);
		obj->native_ext_size = cls->native_ext_size;  // GC conservative-scan span
	}
	if (cls->native_init != NULL)
	{
		cls->native_init(ctx, obj);
	}
	return obj;
}

static void display_run_constructor(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2Class* cls = obj->cls;
	Avm2TryFrame top;
	avm2_try_push_catch_all(ctx, &top);
	if (setjmp(top.jb) == 0)
	{
		avm2_call_method_ref(ctx, &cls->instance_init, cls,
		                     cls->iscope != NULL ? cls->iscope : cls->scope,
		                     avm2_object_value(obj), NULL, 0);
	}
	avm2_try_pop_frame(&top);
}

static void enter_frame_obj(Avm2Context* ctx, Avm2Object* obj);
static void construct_frame_obj(Avm2Context* ctx, Avm2Object* obj);
static void button_construct_states(Avm2Context* ctx, Avm2Object* button);
static void run_frame_scripts_obj(Avm2Context* ctx, Avm2Object* obj);
static void run_goto(Avm2Context* ctx, Avm2Object* obj, uint16_t frame, int is_implicit);
static void on_construction_complete(Avm2Context* ctx, Avm2Object* obj);
static void set_on_parent_field(Avm2Context* ctx, Avm2Object* obj);

// ---------------------------------------------------------------------------
// Class resolution for characters
// ---------------------------------------------------------------------------

static Avm2Object* find_globals_for_dotted(Avm2Context* ctx, const char* dotted,
                                           Avm2PropKey* out_key)
{
	const char* last_dot = strrchr(dotted, '.');
	Avm2PropKey key;
	key.ns_kind = 0x16;
	if (last_dot != NULL)
	{
		key.ns_uri = dotted;
		key.ns_len = (uint32_t) (last_dot - dotted);
		key.name = last_dot + 1;
	}
	else
	{
		key.ns_uri = "";
		key.ns_len = 0;
		key.name = dotted;
	}
	key.name_len = (uint32_t) strlen(key.name);
	*out_key = key;
	return avm2_domain_find(ctx, &key);
}

static Avm2Class* class_for_dotted_name(Avm2Context* ctx, const char* dotted)
{
	Avm2PropKey key;
	Avm2Object* globals = find_globals_for_dotted(ctx, dotted, &key);
	if (globals == NULL) return NULL;
	const Avm2PropEntry* entry = avm2_vtable_find(globals->vtable, &key);
	Avm2Value cls_val = avm2_undefined();
	if (entry != NULL && entry->kind == AVM2_PROP_SLOT)
	{
		cls_val = globals->slots[entry->slot_index];
	}
	else
	{
		Avm2Value* dyn = avm2_object_find_dynamic(globals, key.name, key.name_len);
		if (dyn != NULL) cls_val = *dyn;
	}
	if (cls_val.kind == AVM2_VALUE_OBJECT && cls_val.u.obj != NULL
	    && cls_val.u.obj->kind == AVM2_OBJ_CLASS)
	{
		return cls_val.u.obj->class_ref;
	}
	return NULL;
}

static Avm2Class* class_for_char(Avm2Context* ctx, uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_symbol_class_count; i++)
	{
		if (avm2_generated_symbol_classes[i].char_id == char_id
		    && avm2_generated_symbol_classes[i].class_name != NULL)
		{
			Avm2Class* cls = class_for_dotted_name(
				ctx, avm2_generated_symbol_classes[i].class_name);
			// A DisplayObject subclass IS the placed object. A non-display
			// binding (e.g. a BitmapData subclass bound to a bitmap char) is
			// not placeable directly — the display object stays a plain
			// Bitmap whose bitmapData is that subclass (seeded at placement).
			if (cls != NULL && class_is_a(cls, ctx->builtins.display_object_class))
				return cls;
		}
	}
	const Avm2CharInfo* ci = char_info(char_id);
	uint8_t kind = ci != NULL ? ci->kind : AVM2_CHAR_SPRITE;
	switch (kind)
	{
		case AVM2_CHAR_SHAPE:
		case AVM2_CHAR_MORPHSHAPE:
			return ctx->builtins.shape_class;
		case AVM2_CHAR_BUTTON:
			return ctx->builtins.simple_button_class;
		case AVM2_CHAR_TEXT:
			return g_statictext_class;
		case AVM2_CHAR_EDITTEXT:
			return g_textfield_class;
		case AVM2_CHAR_BITMAP:
			return ctx->builtins.bitmap_class;
		default:
			return ctx->builtins.movieclip_class;
	}
}

// The (non-display) class bound to `char_id`, or NULL — used to build a
// timeline Bitmap's bitmapData (BitmapData subclass binding).
static Avm2Class* nondisplay_class_for_char(Avm2Context* ctx, uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_symbol_class_count; i++)
	{
		if (avm2_generated_symbol_classes[i].char_id == char_id
		    && avm2_generated_symbol_classes[i].class_name != NULL)
		{
			Avm2Class* cls = class_for_dotted_name(
				ctx, avm2_generated_symbol_classes[i].class_name);
			if (cls != NULL && !class_is_a(cls, ctx->builtins.display_object_class))
				return cls;
		}
	}
	return NULL;
}

// ---------------------------------------------------------------------------
// Timeline execution
// ---------------------------------------------------------------------------

static void apply_place_matrix(Avm2DisplayObjectExt* ext, const Avm2TimelineOp* op)
{
	if ((op->flags & AVM2_TLF_HAS_MATRIX) == 0) return;
	ext->mtx_a = op->mtx_a;
	ext->mtx_b = op->mtx_b;
	ext->mtx_c = op->mtx_c;
	ext->mtx_d = op->mtx_d;
	ext->mtx_tx = op->mtx_tx;
	ext->mtx_ty = op->mtx_ty;
	ext->scale_rot_cached = 0;
}

static void apply_place_object(Avm2Context* ctx, Avm2Object* child,
                               const Avm2TimelineOp* op)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, child);
	if (ext == NULL) return;
	apply_place_matrix(ext, op);
	if (op->flags & AVM2_TLF_HAS_VISIBLE)
	{
		ext->visible = op->visible ? 1 : 0;
	}
}

// instantiate_child (Ruffle movie_clip.rs:1488): allocate, place, no ctor.
static Avm2Object* instantiate_child(Avm2Context* ctx, Avm2Object* parent,
                                     const Avm2TimelineOp* op)
{
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	if (pext == NULL) return NULL;
	if (child_by_depth(pext, op->depth) != NULL)
	{
		fprintf(stderr, "AVM2 timeline: failed to place char %u at occupied depth %u\n",
		        op->char_id, op->depth);
		return NULL;
	}
	Avm2Class* cls = class_for_char(ctx, op->char_id);
	if (cls == NULL) return NULL;

	g_timeline_instantiation = 1;
	Avm2Object* child = display_alloc_instance(ctx, cls);
	g_timeline_instantiation = 0;

	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext == NULL) return NULL;
	cext->char_id = op->char_id;
	resolve_shape_geom(cext, op->char_id);
	cext->timeline = timeline_for_char(op->char_id);
	Avm2Object* prev = replace_at_depth(ctx, pext, child, op->depth);
	cext->instantiated_by_timeline = 1;
	cext->depth = op->depth;
	cext->parent = parent;
	cext->place_frame = pext->current_frame;
	// Placed while the parent is still unconstructed (Ruffle: parent
	// object2 not yet allocated): only Sprite.constructChildren during the
	// parent's super() may construct this child. If the parent's ctor
	// never chains to super, the child stays unconstructed forever.
	cext->manual_frame_construct = !pext->constructed;
	apply_place_object(ctx, child, op);
	if (op->flags & AVM2_TLF_HAS_NAME)
	{
		cext->name = avm2_string_from_literal(ctx, op->name);
		cext->has_explicit_name = 1;
	}
	if (op->flags & AVM2_TLF_HAS_CLIP_DEPTH)
	{
		cext->clip_depth = op->clip_depth;
	}
	{
		const Avm2CharInfo* ci = char_info(op->char_id);
		if (ci != NULL && ci->kind == AVM2_CHAR_EDITTEXT)
		{
			avm2_text_seed_from_tag(ctx, child, op->char_id);
		}
		else if (ci != NULL && ci->kind == AVM2_CHAR_BITMAP)
		{
			avm2_bitmap_seed_timeline(ctx, child, op->char_id,
			                          nondisplay_class_for_char(ctx, op->char_id));
		}
		else if (ci != NULL && ci->init_text != NULL)
		{
			cext->tf_text = avm2_string_from_literal(ctx, ci->init_text);
		}
	}
	set_default_instance_name(ctx, cext);
	enter_frame_obj(ctx, child);
	if (prev != NULL)
	{
		dispatch_removed_event(ctx, prev);
	}
	return child;
}

// Ruffle DisplayObject::replace_with: a Replace op keeps the SAME display
// object and swaps the underlying character data — but only static assets
// (graphics/text) actually swap; sprites/MovieClips no-op (the trait
// default). place_object_replace_2 observes both halves.
static void replace_child_character(Avm2Context* ctx, Avm2Object* child,
                                    uint16_t char_id)
{
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext == NULL) return;
	if (cext->timeline != NULL || timeline_for_char(char_id) != NULL)
	{
		return;  // either side is a sprite: no swap
	}
	cext->char_id = char_id;
	resolve_shape_geom(cext, char_id);
	const Avm2CharInfo* ci = char_info(char_id);
	if (ci != NULL && ci->kind == AVM2_CHAR_EDITTEXT)
	{
		avm2_text_seed_from_tag(ctx, child, char_id);
	}
	else
	{
		cext->tf_text = (ci != NULL && ci->init_text != NULL)
			? avm2_string_from_literal(ctx, ci->init_text) : NULL;
	}
}

// Timeline place op against a live display list (non-goto path).
static void run_place_op(Avm2Context* ctx, Avm2Object* parent, const Avm2TimelineOp* op)
{
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	if (pext == NULL) return;
	if (op->flags & AVM2_TLF_HAS_CHAR)
	{
		Avm2Object* existing = child_by_depth(pext, op->depth);
		if (existing != NULL && (op->flags & AVM2_TLF_MOVE))
		{
			// Replace: same object, per-type character swap — no
			// remove/add events.
			Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, existing);
			if (cext != NULL)
			{
				replace_child_character(ctx, existing, op->char_id);
				cext->place_frame = pext->current_frame;
				apply_place_object(ctx, existing, op);
			}
		}
		else
		{
			instantiate_child(ctx, parent, op);
		}
	}
	else
	{
		// Modify/move at depth.
		Avm2Object* child = child_by_depth(pext, op->depth);
		if (child != NULL)
		{
			apply_place_object(ctx, child, op);
		}
	}
}

static void run_remove_op(Avm2Context* ctx, Avm2Object* parent, const Avm2TimelineOp* op)
{
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	if (pext == NULL) return;
	Avm2Object* child = child_by_depth(pext, op->depth);
	if (child == NULL) return;
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext != NULL && cext->placed_by_avm2_script)
	{
		// Script-locked: only unhook from timeline depth control.
		remove_child_from_depth_list(pext, child);
	}
	else
	{
		full_remove_child(ctx, pext, child);
	}
}

// determine_next_frame (Ruffle MC:1340). Our static tables are fully
// "preloaded": frames_loaded = timeline frame_count.
enum
{
	NEXT_FRAME_NEXT = 0,
	NEXT_FRAME_FIRST = 1,
	NEXT_FRAME_SAME = 2,
};

static uint32_t frames_loaded(const Avm2DisplayObjectExt* ext)
{
	// A script-created clip reports frames_loaded 1 (Ruffle
	// MovieClipShared::empty pre-completes preload) — but is created
	// NOT PLAYING, so its playhead stays at 0 (movieclip_displayevents
	// traces "frame 0" forever while movieclip_constr sees framesLoaded 1).
	return ext->timeline != NULL ? ext->timeline->frame_count : 1;
}

static uint32_t total_frames(const Avm2DisplayObjectExt* ext)
{
	// totalFrames = the DECLARED header/DefineSprite count verbatim, even
	// 0 (zero_frame_clip) or fewer than the real ShowFrame count
	// (swf_wrong_frame_count reports 1 while the playhead runs to 5).
	return ext->timeline != NULL ? ext->timeline->declared_frames : 1;
}

static int determine_next_frame(const Avm2DisplayObjectExt* ext)
{
	if ((uint32_t) ext->current_frame < frames_loaded(ext)) return NEXT_FRAME_NEXT;
	if (frames_loaded(ext) <= 1) return NEXT_FRAME_SAME;
	return NEXT_FRAME_FIRST;
}

// run_frame_internal (AS3 arm): queue place ops, run removals, advance.
static void run_frame_internal(Avm2Context* ctx, Avm2Object* obj, int run_display)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->timeline == NULL) return;

	int next = determine_next_frame(ext);
	if (next == NEXT_FRAME_FIRST)
	{
		run_goto(ctx, obj, 1, 1);
		return;
	}
	if (next == NEXT_FRAME_SAME)
	{
		ext->playing = 0;
		return;
	}

	uint32_t frame_idx = ext->current_frame;  // 0-based index of the NEW frame
	const Avm2TimelineData* tl = ext->timeline;
	uint32_t op_start = tl->frame_op_starts[frame_idx];
	uint32_t op_end = tl->frame_op_starts[frame_idx + 1];

	if (run_display)
	{
		// Queue placements (executed after this returns, still Enter
		// phase); run removals NOW (before the frame number advances).
		ext->queued_place_count = 0;
		uint32_t nplaces = 0;
		for (uint32_t i = op_start; i < op_end; i++)
		{
			if (tl->ops[i].kind == AVM2_TLOP_PLACE) nplaces++;
		}
		if (nplaces > 0)
		{
			ext->queued_places = avm2_alloc(ctx, nplaces * sizeof(int32_t));
		}
		for (uint32_t i = op_start; i < op_end; i++)
		{
			const Avm2TimelineOp* op = &tl->ops[i];
			if (op->kind == AVM2_TLOP_PLACE)
			{
				// QueuedTagList: one queued Add per depth — the FIRST wins
				// (place_object_same_depth_frame).
				int dup = 0;
				for (uint32_t k = 0; k < ext->queued_place_count; k++)
				{
					const Avm2TimelineOp* q = &tl->ops[ext->queued_places[k]];
					if (q->depth == op->depth && (op->flags & AVM2_TLF_HAS_CHAR)
					    && (q->flags & AVM2_TLF_HAS_CHAR))
					{
						fprintf(stderr, "AVM2 timeline: failed to queue place at "
						        "depth %u (already queued)\n", op->depth);
						dup = 1;
						break;
					}
				}
				if (!dup)
				{
					ext->queued_places[ext->queued_place_count++] = (int32_t) i;
				}
			}
			else if (op->kind == AVM2_TLOP_REMOVE)
			{
				run_remove_op(ctx, obj, op);
			}
		}
	}

	ext->current_frame++;
	ext->queued_script_frame = ext->current_frame;
	if (ext->last_queued_script_frame != (int32_t) ext->current_frame)
	{
		ext->last_queued_script_frame = -1;
	}
}

static void flush_queued_places(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->queued_place_count == 0) return;
	const Avm2TimelineData* tl = ext->timeline;
	uint32_t n = ext->queued_place_count;
	ext->queued_place_count = 0;
	for (uint32_t i = 0; i < n; i++)
	{
		run_place_op(ctx, obj, &tl->ops[ext->queued_places[i]]);
	}
}

// ---------------------------------------------------------------------------
// Frame phases per object
// ---------------------------------------------------------------------------

static void enter_frame_obj(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	int skip = ext->skip_next_enter_frame;
	// Children first, REVERSED render order.
	for (uint32_t i = ext->render_len; i > 0; i--)
	{
		Avm2Object* child = ext->render_list[i - 1];
		if (skip)
		{
			Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
			if (cext != NULL) cext->skip_next_enter_frame = 1;
		}
		enter_frame_obj(ctx, child);
	}
	Avm2Object* states[4] = { ext->btn_up, ext->btn_over, ext->btn_down,
	                          ext->btn_hit };
	for (int s = 3; s >= 0; s--)
	{
		if (states[s] != NULL)
		{
			if (skip)
			{
				Avm2DisplayObjectExt* sx = avm2_display_ext_of(ctx, states[s]);
				if (sx != NULL) sx->skip_next_enter_frame = 1;
			}
			enter_frame_obj(ctx, states[s]);
		}
	}
	if (skip)
	{
		ext->skip_next_enter_frame = 0;
		return;
	}
	if (ext->timeline != NULL)
	{
		if (ext->playing)
		{
			run_frame_internal(ctx, obj, 1);
		}
		flush_queued_places(ctx, obj);
	}
}

static void check_has_pending_script(Avm2DisplayObjectExt* ext)
{
	uint32_t f = ext->current_frame;
	if (f < ext->frame_script_cap
	    && ext->frame_scripts[f].kind == AVM2_VALUE_OBJECT)
	{
		ext->has_pending_script = 1;
	}
}

static void construct_frame_obj(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	int is_load_frame = !ext->initialized;
	int needs_construction = !ext->constructed;
	ext->loop_queued = 0;
	if (needs_construction)
	{
		// SimpleButton states are created eagerly, before the ctor runs
		// (Ruffle avm2_button.rs construct_frame). `constructed` is set
		// FIRST (Ruffle clears needs_frame_construction before
		// create_state): the has-MovieClip nested stage pass inside
		// button_construct_states re-enters this function on the button,
		// and must not run the ctor — the ctor runs here, in the OUTER
		// invocation, after the nested framescripts (the frame-2 script
		// traces precede the ctor trace in simplebutton_symbolclass).
		ext->constructed = 1;
		if (class_is_a(obj->cls, ctx->builtins.simple_button_class))
		{
			// Buttons expose the named on-parent field BEFORE construction
			// (Ruffle avm2_button.rs: the un-constructed object is visible
			// via parent.<childName> from the nested framescript pass).
			if (!ext->placed_by_avm2_script)
			{
				set_on_parent_field(ctx, obj);
			}
			button_construct_states(ctx, obj);
		}
		display_run_constructor(ctx, obj);
		on_construction_complete(ctx, obj);
	}
	else if (is_load_frame && ext->placed_by_avm2_script)
	{
		// Load-frame script-created object: its children are constructed
		// by Sprite.constructChildren during super(), not by this catchup
		// pass (constructors_vs_timeline).
	}
	else
	{
		{
			Avm2Object* states[4] = { ext->btn_hit, ext->btn_up,
			                          ext->btn_down, ext->btn_over };
			for (int s = 0; s < 4; s++)
			{
				if (states[s] != NULL) construct_frame_obj(ctx, states[s]);
			}
		}
		for (uint32_t i = 0; i < ext->render_len; i++)
		{
			Avm2DisplayObjectExt* cext =
				avm2_display_ext_of(ctx, ext->render_list[i]);
			// While Sprite.constructChildren iterates this container, a
			// nested construct pass (e.g. a no-op goto inside a child's
			// ctor) must not construct the remaining children.
			if (cext != NULL && !cext->constructed && ext->running_construct_frame)
			{
				continue;
			}
			// A child reserved for Sprite.constructChildren (placed before
			// the parent's ctor) is never constructed by the catchup pass
			// (movieclip_frameconstruct_skipped: the root ctor never calls
			// super(), so its load-frame children stay unconstructed).
			if (cext != NULL && !cext->constructed && cext->manual_frame_construct)
			{
				continue;
			}
			construct_frame_obj(ctx, ext->render_list[i]);
		}
	}
	if (ctx->frame_phase == PHASE_CONSTRUCT)
	{
		check_has_pending_script(ext);
	}
}

// Ruffle DisplayObject::set_on_parent_field: expose an explicitly-named
// timeline child as a property on its parent. Runs once (buttons set the
// field before construction; the completion path must not re-run the
// setter).
static void set_on_parent_field(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->parent_field_done) return;
	if (!ext->has_explicit_name || ext->name == NULL || ext->parent == NULL)
	{
		return;
	}
	ext->parent_field_done = 1;
	Avm2TryFrame top;
	avm2_try_push_catch_all(ctx, &top);
	if (setjmp(top.jb) == 0)
	{
		avm2_set_public_property(ctx, avm2_object_value(ext->parent),
		                         ext->name->utf8, ext->name->len,
		                         avm2_object_value(obj));
	}
	avm2_try_pop_frame(&top);
}

static void on_construction_complete(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (!ext->placed_by_avm2_script && ext->parent != NULL
	    && !class_is_a(ext->parent->cls, ctx->builtins.simple_button_class))
	{
		// fire_added_events: added + addedToStage on SELF only — timeline
		// children each fire their own at their own construction (the
		// recursive form is the container script-add path). Children whose
		// display parent is a BUTTON at construction time fire nothing
		// (Ruffle fire_added_events; button states get their events from
		// fire_state_events instead).
		dispatch_simple_event(ctx, obj, "added", 1);
		if (is_on_stage(ctx, obj))
		{
			dispatch_simple_event(ctx, obj, "addedToStage", 0);
		}
	}
	// set_on_parent_field (Ruffle DO:2328): a timeline child with an
	// explicit name becomes a property on its parent.
	if (!ext->placed_by_avm2_script)
	{
		set_on_parent_field(ctx, obj);
	}
	// Timeline symbol whose class is Sprite-typed (no MovieClip in the
	// chain): plays frame 1 then stops.
	if (ext->timeline != NULL && !ext->is_root
	    && !class_is_a(obj->cls, ctx->builtins.movieclip_class))
	{
		ext->playing = 0;
	}
	ext->initialized = 1;
}

static void run_local_frame_scripts(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || !ext->constructed) return;
	if (ext->has_pending_script && !ext->executing_frame_script)
	{
		uint32_t frame_id = ext->queued_script_frame;
		int is_fresh = (ext->last_queued_script_frame != (int32_t) frame_id);
		if (is_fresh && frame_id < ext->frame_script_cap
		    && ext->frame_scripts[frame_id].kind == AVM2_VALUE_OBJECT)
		{
			ext->last_queued_script_frame = (int32_t) frame_id;
			ext->has_pending_script = 0;
			ext->executing_frame_script = 1;
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				avm2_call_function_obj(ctx, ext->frame_scripts[frame_id].u.obj,
				                       avm2_object_value(obj), NULL, 0);
			}
			avm2_try_pop_frame(&top);
			ext->executing_frame_script = 0;
		}
	}
	// Flush a queued goto.
	if (ext->queued_goto_frame >= 0)
	{
		uint16_t frame = (uint16_t) ext->queued_goto_frame;
		ext->queued_goto_frame = -1;
		if (frame != ext->current_frame)
		{
			run_goto(ctx, obj, frame, 0);
		}
		else
		{
			// no_op_goto: nested frame with no tag changes.
			extern void avm2_display_inner_goto_frame(Avm2Context* ctx);
			avm2_display_inner_goto_frame(ctx);
		}
		if (ctx->swf_version <= 9)
		{
			construct_frame_obj(ctx, obj);
		}
	}
}

static void run_frame_scripts_obj(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	run_local_frame_scripts(ctx, obj);
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		run_frame_scripts_obj(ctx, ext->render_list[i]);
	}
	{
		// Normal order: hit, up, down, over; the one-shot "weird" order
		// right after construction: up, over, down, hit (Ruffle
		// all_state_children).
		Avm2Object* normal[4] = { ext->btn_hit, ext->btn_up, ext->btn_down,
		                          ext->btn_over };
		Avm2Object* weird[4] = { ext->btn_up, ext->btn_over, ext->btn_down,
		                         ext->btn_hit };
		Avm2Object** order = ext->btn_weird_order ? weird : normal;
		ext->btn_weird_order = 0;
		for (int s = 0; s < 4; s++)
		{
			if (order[s] != NULL) run_frame_scripts_obj(ctx, order[s]);
		}
	}
}

// ---------------------------------------------------------------------------
// Broadcast helpers
// ---------------------------------------------------------------------------

static void broadcast_named(Avm2Context* ctx, const char* type)
{
	Avm2Object* evt = avm2_event_new(ctx, avm2_string_from_literal(ctx, type), 0, 0);
	avm2_broadcast_event(ctx, evt, ctx->builtins.display_object_class);
}

static void run_frame_script_cleanup(Avm2Context* ctx)
{
	uint32_t i = 0;
	while (i < g_fs_cleanup_count)
	{
		Avm2Object* obj = g_fs_cleanup[i++];
		Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
		if (ext == NULL) continue;
		ext->has_pending_script = 1;
		ext->last_queued_script_frame = -1;
		run_local_frame_scripts(ctx, obj);
	}
	g_fs_cleanup_count = 0;
}

// run_inner_goto_frame (Ruffle FL:124): Construct + FrameScripts + Exit
// for the whole stage — no enterFrame.
void avm2_display_inner_goto_frame(Avm2Context* ctx)
{
	if (ctx->swf_version <= 9)
	{
		return;  // caller sets skip_next_enter_frame instead
	}
	uint8_t old_phase = ctx->frame_phase;
	g_fs_cleanup_count = 0;

	ctx->frame_phase = PHASE_CONSTRUCT;
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, g_orphans[i]);
		if (e != NULL && e->parent == NULL) construct_frame_obj(ctx, g_orphans[i]);
	}
	if (ctx->stage != NULL) construct_frame_obj(ctx, ctx->stage);
	broadcast_named(ctx, "frameConstructed");

	ctx->frame_phase = PHASE_FRAME_SCRIPTS;
	if (ctx->stage != NULL) run_frame_scripts_obj(ctx, ctx->stage);
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, g_orphans[i]);
		if (e != NULL && e->parent == NULL) run_frame_scripts_obj(ctx, g_orphans[i]);
	}
	run_frame_script_cleanup(ctx);

	ctx->frame_phase = PHASE_EXIT;
	broadcast_named(ctx, "exitFrame");
	orphan_cleanup(ctx);
	ctx->frame_phase = old_phase;
}

// ---------------------------------------------------------------------------
// Goto machinery (Ruffle run_goto, static-table form)
// ---------------------------------------------------------------------------

typedef struct GotoCmd
{
	int32_t depth;
	uint16_t frame;         // 1-based frame the (latest) PLACE came from
	const Avm2TimelineOp* place;  // latest full-place op at this depth
	const Avm2TimelineOp* mods[8];  // subsequent modify ops (matrix updates)
	uint32_t mod_count;
	uint32_t index;         // op order for sorting
} GotoCmd;

static void run_goto(Avm2Context* ctx, Avm2Object* obj, uint16_t frame, int is_implicit)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->timeline == NULL) return;
	const Avm2TimelineData* tl = ext->timeline;

	uint16_t frame_before = ext->current_frame;
	ext->skip_next_enter_frame = 0;
	int is_rewind = (frame <= ext->current_frame);

	if (ext->loop_queued)
	{
		ext->queued_place_count = 0;
	}
	if (is_implicit) ext->loop_queued = 1;

	uint16_t clamped = frame;
	if ((uint32_t) clamped > tl->frame_count) clamped = (uint16_t) tl->frame_count;
	if (clamped < 1) clamped = 1;

	uint16_t from_frame = is_rewind ? 0 : ext->current_frame;

	// Aggregate place/remove deltas per depth across [from_frame+1, clamped].
	GotoCmd cmds[128];
	uint32_t cmd_count = 0;
	uint32_t op_index = 0;
	for (uint16_t f = from_frame + 1; f <= clamped; f++)
	{
		uint32_t s = tl->frame_op_starts[f - 1];
		uint32_t e = tl->frame_op_starts[f];
		for (uint32_t i = s; i < e; i++)
		{
			const Avm2TimelineOp* op = &tl->ops[i];
			op_index++;
			if (op->kind == AVM2_TLOP_REMOVE)
			{
				for (uint32_t k = 0; k < cmd_count; k++)
				{
					if (cmds[k].depth == op->depth)
					{
						memmove(&cmds[k], &cmds[k + 1],
						        (cmd_count - k - 1) * sizeof(GotoCmd));
						cmd_count--;
						break;
					}
				}
				// Also mark: a child at this depth from BEFORE the goto
				// range must be removed (non-rewind forward goto).
				if (!is_rewind)
				{
					Avm2Object* child = child_by_depth(ext, op->depth);
					if (child != NULL)
					{
						Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
						if (cext != NULL && cext->placed_by_avm2_script)
						{
							remove_child_from_depth_list(ext, child);
						}
						else
						{
							full_remove_child(ctx, ext, child);
						}
					}
				}
				continue;
			}
			// PLACE
			GotoCmd* cmd = NULL;
			for (uint32_t k = 0; k < cmd_count; k++)
			{
				if (cmds[k].depth == op->depth)
				{
					cmd = &cmds[k];
					break;
				}
			}
			if (op->flags & AVM2_TLF_HAS_CHAR)
			{
				if (cmd == NULL)
				{
					if (cmd_count >= 128) continue;
					cmd = &cmds[cmd_count++];
					memset(cmd, 0, sizeof(*cmd));
					cmd->depth = op->depth;
				}
				cmd->place = op;
				cmd->frame = f;
				cmd->mod_count = 0;
				cmd->index = op_index;
			}
			else if (cmd != NULL)
			{
				if (cmd->mod_count < 8) cmd->mods[cmd->mod_count++] = op;
			}
			else
			{
				// Modify op for a child that predates the goto range.
				if (!is_rewind)
				{
					Avm2Object* child = child_by_depth(ext, op->depth);
					if (child != NULL) apply_place_object(ctx, child, op);
				}
			}
		}
	}

	// The playhead lands on the target BEFORE the removal/materialize
	// steps (a removed handler during the goto reads the NEW currentFrame
	// — movieclip_displayevents_timeline).
	ext->current_frame = clamped;
	ext->queued_script_frame = clamped;
	if (ext->last_queued_script_frame != (int32_t) clamped)
	{
		ext->last_queued_script_frame = -1;
	}

	if (is_rewind)
	{
		// Remove children that don't survive the rewind (Ruffle
		// survives_rewind): a non-script child placed AT OR BEFORE the
		// target frame survives unconditionally; later children survive
		// only when the final placement at their depth re-places the same
		// character with equal matrix/ratio/clip-depth.
		for (uint32_t i = ext->render_len; i > 0; i--)
		{
			Avm2Object* child = ext->render_list[i - 1];
			Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
			if (cext == NULL) continue;
			int candidate = (cext->place_frame > (int32_t) clamped)
			                || cext->placed_by_avm2_script;
			int survives;
			if (!candidate)
			{
				survives = 1;
			}
			else
			{
				survives = 0;
				for (uint32_t k = 0; k < cmd_count; k++)
				{
					if (cmds[k].depth != cext->depth || cmds[k].place == NULL)
					{
						continue;
					}
					const Avm2TimelineOp* op = cmds[k].place;
					int id_eq = (op->char_id == cext->char_id);
					int ratio_eq = ((op->flags & AVM2_TLF_HAS_RATIO) == 0)
					               || op->ratio == 0;
					int clip_eq = ((op->flags & AVM2_TLF_HAS_CLIP_DEPTH) == 0)
					              || op->clip_depth == cext->clip_depth;
					int mtx_eq = ((op->flags & AVM2_TLF_HAS_MATRIX) == 0)
					             || (op->mtx_a == cext->mtx_a && op->mtx_b == cext->mtx_b
					                 && op->mtx_c == cext->mtx_c && op->mtx_d == cext->mtx_d
					                 && op->mtx_tx == cext->mtx_tx
					                 && op->mtx_ty == cext->mtx_ty);
					survives = id_eq && ratio_eq && clip_eq && mtx_eq;
					break;
				}
			}
			if (!survives)
			{
				if (cext->placed_by_avm2_script)
				{
					remove_child_from_depth_list(ext, child);
				}
				else
				{
					full_remove_child(ctx, ext, child);
				}
			}
		}
	}

	// Materialize commands in op order: reuse matching children, create
	// the rest.
	for (uint32_t k = 0; k < cmd_count; k++)
	{
		const GotoCmd* cmd = &cmds[k];
		Avm2Object* child = child_by_depth(ext, cmd->depth);
		Avm2DisplayObjectExt* cext = child != NULL
			? avm2_display_ext_of(ctx, child) : NULL;
		if (child != NULL && cext != NULL && is_rewind)
		{
			// Rewind always modifies the surviving child in place
			// (survives_rewind scrubbed the mismatches above).
			apply_place_object(ctx, child, cmd->place);
		}
		else if (child != NULL && cext != NULL
		         && (cmd->place->flags & AVM2_TLF_MOVE))
		{
			// Forward-goto Replace: SAME display object, per-type
			// character swap + place_frame update (Ruffle goto arm
			// Replace(id) + prev_child).
			replace_child_character(ctx, child, cmd->place->char_id);
			apply_place_object(ctx, child, cmd->place);
			cext->place_frame = cmd->frame;
		}
		else
		{
			if (child != NULL)
			{
				full_remove_child(ctx, ext, child);
			}
			Avm2Object* fresh;
			if (is_implicit)
			{
				// Looping goto defers creation to the Enter-phase add
				// queue... static tables make immediate creation
				// equivalent here; keep immediate for simplicity.
				fresh = instantiate_child(ctx, obj, cmd->place);
			}
			else
			{
				fresh = instantiate_child(ctx, obj, cmd->place);
			}
			if (fresh != NULL)
			{
				Avm2DisplayObjectExt* fext = avm2_display_ext_of(ctx, fresh);
				if (fext != NULL) fext->place_frame = cmd->frame;
			}
			child = fresh;
		}
		if (child != NULL)
		{
			for (uint32_t mi = 0; mi < cmd->mod_count; mi++)
			{
				apply_place_object(ctx, child, cmd->mods[mi]);
			}
		}
	}

	(void) frame_before;
	if (!is_implicit)
	{
		if (ctx->swf_version <= 9)
		{
			ext->skip_next_enter_frame = 1;
		}
		else
		{
			avm2_display_inner_goto_frame(ctx);
		}
	}
}

// goto_frame entry (Ruffle MC:881).
static void mc_goto_frame(Avm2Context* ctx, Avm2Object* obj, uint16_t frame, int stop)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (stop) ext->playing = 0;
	else ext->playing = 1;
	if (frame < 1) frame = 1;
	if (ext->executing_frame_script)
	{
		if (ctx->swf_version <= 9 && frame == ext->current_frame)
		{
			ext->queued_goto_frame = -1;
			ext->skip_next_enter_frame = 1;
			return;
		}
		ext->queued_goto_frame = frame;
		if (frame < ext->frame_script_cap
		    && ext->frame_scripts[frame].kind == AVM2_VALUE_OBJECT)
		{
			fs_cleanup_push(ctx, obj);
		}
	}
	else
	{
		if (frame != ext->current_frame)
		{
			run_goto(ctx, obj, frame, 0);
		}
		else
		{
			ext->queued_goto_frame = -1;
			avm2_display_inner_goto_frame(ctx);
			if (ctx->swf_version <= 9) ext->skip_next_enter_frame = 1;
		}
	}
}

// ---------------------------------------------------------------------------
// Tick (frame_lifecycle.rs run_all_phases_avm2)
// ---------------------------------------------------------------------------

// Recursive render-pass walk: visible TextFields apply lazy autosize
// bounds (invisible subtrees are skipped, like culled rendering).
static void render_apply_text_bounds(Avm2Context* ctx, Avm2Object* obj,
                                     int visible)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (!ext->is_stage && !ext->visible) visible = 0;
	if (visible && ext->edittext != NULL)
	{
		avm2_text_apply_pending_bounds(ctx, obj);
	}
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		render_apply_text_bounds(ctx, ext->render_list[i], visible);
	}
}

// ---------------------------------------------------------------------------
// Timers: flash.utils setTimeout/setInterval + the flash.utils.Timer class.
// Ported from Ruffle core/src/timer.rs: ONE priority-ordered list on a µs
// clock, fired at the TAIL of each tick (Ruffle runs update_timers AFTER
// run_frame). tick_time fires when strictly < cur_time; intervals clamp to
// MIN_INTERVAL; MAX_TICKS caps ticks per frame. AS3 Timer entries carry a
// timer_obj and fire through timer_on_update (currentCount++/dispatch/
// stop-on-complete); setTimeout/setInterval entries call a plain function
// whose boolean return cancels an interval (Ruffle Timer.as _onUpdateClosure).
// ---------------------------------------------------------------------------

#define AVM2_TIMER_MIN_INTERVAL 10       // ms (Ruffle Timers::MIN_INTERVAL)
#define AVM2_TIMER_MAX_TICKS    10       // per frame (Ruffle Timers::MAX_TICKS)
#define AVM2_TIMER_SCALE        1000ULL  // µs per ms (Ruffle Timers::TIMER_SCALE)

typedef struct Avm2TimerEntry
{
	int32_t id;
	uint64_t tick_time;   // µs, absolute next fire
	uint64_t interval;    // µs
	uint8_t is_timeout;   // one-shot (setTimeout)
	uint8_t active;
	Avm2Object* timer_obj;  // non-NULL: AS3 Timer instance (fire via timer_on_update)
	Avm2Value fn;           // setTimeout/setInterval callback (timer_obj == NULL)
	Avm2Value args[8];
	uint32_t argc;
} Avm2TimerEntry;

static Avm2TimerEntry g_avm2_timers[256];
static uint32_t g_avm2_timer_count;
static int32_t g_avm2_timer_next_id;    // pre-incremented; Ruffle never issues 0
static uint64_t g_avm2_timer_cur_time;  // µs

double avm2_timer_elapsed_ms(void)
{
	return (double) (g_avm2_timer_cur_time / AVM2_TIMER_SCALE);
}

// AS3 Timer instance state (native_ext; dispatcher MUST stay first so the
// inherited EventDispatcher natives read it correctly).
typedef struct Avm2TimerObjExt
{
	Avm2EventDispatcherExt dispatcher;
	double delay;
	int32_t repeat_count;
	int32_t current_count;
	int32_t timer_entry_id;  // 0 = not running (running getter)
} Avm2TimerObjExt;

static Avm2TimerObjExt* timer_obj_ext(Avm2Object* obj)
{
	return obj != NULL ? (Avm2TimerObjExt*) obj->native_ext : NULL;
}

// Register a new list entry; interval clamps to MIN_INTERVAL. Returns the id.
static int32_t timer_list_add(int32_t interval_ms, int is_timeout,
                              Avm2Object* timer_obj, Avm2Value fn,
                              const Avm2Value* args, uint32_t argc)
{
	if (g_avm2_timer_count >= 256) return 0;
	if (interval_ms < AVM2_TIMER_MIN_INTERVAL) interval_ms = AVM2_TIMER_MIN_INTERVAL;
	uint64_t interval = (uint64_t) interval_ms * AVM2_TIMER_SCALE;
	Avm2TimerEntry* t = &g_avm2_timers[g_avm2_timer_count++];
	memset(t, 0, sizeof(*t));
	g_avm2_timer_next_id += 1;
	t->id = g_avm2_timer_next_id;
	t->tick_time = g_avm2_timer_cur_time + interval;
	t->interval = interval;
	t->is_timeout = (uint8_t) is_timeout;
	t->active = 1;
	t->timer_obj = timer_obj;
	t->fn = fn;
	for (uint32_t i = 0; i < argc && t->argc < 8; i++) t->args[t->argc++] = args[i];
	return t->id;
}

static void timer_list_remove(int32_t id)
{
	for (uint32_t i = 0; i < g_avm2_timer_count; i++)
	{
		if (g_avm2_timers[i].active && g_avm2_timers[i].id == id)
			g_avm2_timers[i].active = 0;
	}
}

// Reschedule an existing entry from NOW (Ruffle Timers::set_delay).
static void timer_list_set_delay(int32_t id, int32_t interval_ms)
{
	if (interval_ms < AVM2_TIMER_MIN_INTERVAL) interval_ms = AVM2_TIMER_MIN_INTERVAL;
	uint64_t interval = (uint64_t) interval_ms * AVM2_TIMER_SCALE;
	for (uint32_t i = 0; i < g_avm2_timer_count; i++)
	{
		if (g_avm2_timers[i].active && g_avm2_timers[i].id == id)
		{
			g_avm2_timers[i].interval = interval;
			g_avm2_timers[i].tick_time = g_avm2_timer_cur_time + interval;
			return;
		}
	}
}

static Avm2Value timer_add(Avm2Activation* act, int repeating)
{
	if (act->argc < 1) return avm2_integer(0);
	double delay = act->argc > 1 ? avm2_coerce_to_number(act->ctx, act->args[1]) : 0;
	if (!(delay >= 0)) delay = 0;
	Avm2Value cbargs[8];
	uint32_t n = 0;
	for (uint32_t i = 2; i < act->argc && n < 8; i++) cbargs[n++] = act->args[i];
	int32_t id = timer_list_add((int32_t) delay, !repeating, NULL, act->args[0],
	                            cbargs, n);
	return avm2_integer(id);
}

static Avm2Value utils_set_timeout(Avm2Activation* act)
{
	return timer_add(act, 0);
}

static Avm2Value utils_set_interval(Avm2Activation* act)
{
	return timer_add(act, 1);
}

static Avm2Value utils_clear_timer(Avm2Activation* act)
{
	if (act->argc < 1) return avm2_undefined();
	int32_t id = avm2_coerce_to_i32(act->ctx, act->args[0]);
	timer_list_remove(id);
	return avm2_undefined();
}

static Avm2Value utils_get_timer(Avm2Activation* act)
{
	(void) act;
	return avm2_integer((int32_t) avm2_timer_elapsed_ms());
}

void avm2_builtin_add_flash_utils_fn(Avm2Context* ctx, const char* name,
                                     Avm2MethodFn fn);

void avm2_register_timer_fns(Avm2Context* ctx)
{
	avm2_builtin_add_flash_utils_fn(ctx, "setTimeout", utils_set_timeout);
	avm2_builtin_add_flash_utils_fn(ctx, "setInterval", utils_set_interval);
	avm2_builtin_add_flash_utils_fn(ctx, "clearTimeout", utils_clear_timer);
	avm2_builtin_add_flash_utils_fn(ctx, "clearInterval", utils_clear_timer);
	avm2_builtin_add_flash_utils_fn(ctx, "getTimer", utils_get_timer);
}

// --- flash.utils.Timer natives -------------------------------------------

static const Avm2String* g_str_timer;
static const Avm2String* g_str_timer_complete;
// Defined below (Mouse section); rooted in avm2_gc_mark_roots_display.
static const Avm2String* g_mouse_cursor;

// One Timer tick: currentCount++, dispatch TimerEvent.TIMER; on the final
// repeat clear running (so a TIMER_COMPLETE handler reads running==false) and
// dispatch TimerEvent.TIMER_COMPLETE. Returns 1 to cancel the list entry.
static int timer_on_update(Avm2Context* ctx, Avm2Object* timer)
{
	Avm2TimerObjExt* ext = timer_obj_ext(timer);
	if (ext == NULL) return 1;
	ext->current_count += 1;
	Avm2Object* ev = avm2_timer_event_new(ctx, g_str_timer, 0, 0);
	avm2_dispatch_event(ctx, timer, ev);
	if (ext->repeat_count != 0 && ext->current_count >= ext->repeat_count)
	{
		ext->timer_entry_id = 0;  // running == false during TIMER_COMPLETE
		Avm2Object* ev2 = avm2_timer_event_new(ctx, g_str_timer_complete, 0, 0);
		avm2_dispatch_event(ctx, timer, ev2);
		return 1;
	}
	return 0;
}

static void timer_check_delay(Avm2Context* ctx, double delay)
{
	if (!isfinite(delay) || delay < 0)
	{
		avm2_throw_error(ctx, ctx->builtins.range_error_class,
		                 "Error #2066: The Timer delay specified is out of range.");
	}
}

// Timer(delay:Number, repeatCount:int = 0)
static Avm2Value timer_ctor(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	if (ext == NULL) return avm2_undefined();
	double delay = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0;
	timer_check_delay(ctx, delay);
	ext->delay = delay;
	ext->repeat_count = act->argc > 1 ? avm2_coerce_to_i32(ctx, act->args[1]) : 0;
	ext->current_count = 0;
	ext->timer_entry_id = 0;
	return avm2_undefined();
}

static Avm2Value timer_start(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	if (ext == NULL) return avm2_undefined();
	if (ext->timer_entry_id == 0)
	{
		int32_t id = timer_list_add((int32_t) ext->delay, 0, act->this_val.u.obj,
		                            avm2_null(), NULL, 0);
		ext->timer_entry_id = id;
	}
	return avm2_undefined();
}

static Avm2Value timer_stop(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	if (ext == NULL) return avm2_undefined();
	if (ext->timer_entry_id != 0)
	{
		timer_list_remove(ext->timer_entry_id);
		ext->timer_entry_id = 0;
	}
	return avm2_undefined();
}

static Avm2Value timer_reset(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	if (ext == NULL) return avm2_undefined();
	ext->current_count = 0;
	return timer_stop(act);
}

static Avm2Value timer_get_current_count(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	return avm2_integer(ext != NULL ? ext->current_count : 0);
}

static Avm2Value timer_get_delay(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	return avm2_number(ext != NULL ? ext->delay : 0);
}

static Avm2Value timer_set_delay(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	if (ext == NULL) return avm2_undefined();
	// Ruffle Timer.as quirk: the setter validates the OLD delay (getter),
	// not the incoming value — so the new value is never range-checked.
	timer_check_delay(ctx, ext->delay);
	double v = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0;
	ext->delay = v;
	if (ext->timer_entry_id != 0)
	{
		timer_list_set_delay(ext->timer_entry_id, (int32_t) v);
	}
	return avm2_undefined();
}

static Avm2Value timer_get_repeat_count(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	return avm2_integer(ext != NULL ? ext->repeat_count : 0);
}

static Avm2Value timer_set_repeat_count(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	if (ext == NULL) return avm2_undefined();
	ext->repeat_count = act->argc > 0 ? avm2_coerce_to_i32(act->ctx, act->args[0]) : 0;
	if (ext->repeat_count != 0 && ext->repeat_count <= ext->current_count)
	{
		timer_stop(act);
	}
	return avm2_undefined();
}

static Avm2Value timer_get_running(Avm2Activation* act)
{
	Avm2TimerObjExt* ext = timer_obj_ext(act->this_val.u.obj);
	return avm2_bool(ext != NULL && ext->timer_entry_id != 0);
}

void avm2_register_timer_class(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;
	Avm2Class* timer = avm2_builtin_class(ctx, "flash.utils", "Timer",
	                                      b->event_dispatcher_class);
	timer->instance_init.fn = timer_ctor;
	timer->instance_init.debug_name = "Timer";
	timer->native_ext_size = sizeof(Avm2TimerObjExt);
	b->timer_class = timer;
	avm2_builtin_add_method(ctx, timer, "start", timer_start);
	avm2_builtin_add_method(ctx, timer, "stop", timer_stop);
	avm2_builtin_add_method(ctx, timer, "reset", timer_reset);
	avm2_builtin_add_getset(ctx, timer, "currentCount", timer_get_current_count, NULL);
	avm2_builtin_add_getset(ctx, timer, "delay", timer_get_delay, timer_set_delay);
	avm2_builtin_add_getset(ctx, timer, "repeatCount", timer_get_repeat_count,
	                        timer_set_repeat_count);
	avm2_builtin_add_getset(ctx, timer, "running", timer_get_running, NULL);

	g_str_timer = avm2_string_from_literal(ctx, "timer");
	g_str_timer_complete = avm2_string_from_literal(ctx, "timerComplete");
}

// Fire one list entry (returns cancel bool), routing to timer_on_update for
// AS3 Timer entries and a plain function call for setTimeout/setInterval.
static int timer_fire_entry(Avm2Context* ctx, Avm2TimerEntry* t)
{
	if (t->timer_obj != NULL) return timer_on_update(ctx, t->timer_obj);
	Avm2Value ret = avm2_undefined();
	Avm2TryFrame top;
	avm2_try_push_catch_all(ctx, &top);
	if (setjmp(top.jb) == 0)
	{
		ret = avm2_call_value(ctx, t->fn, avm2_null(), t->args, t->argc);
	}
	avm2_try_pop_frame(&top);
	return avm2_coerce_to_boolean(ret) ? 1 : 0;
}

static Avm2TimerEntry* timer_find_min(void)
{
	Avm2TimerEntry* best = NULL;
	for (uint32_t i = 0; i < g_avm2_timer_count; i++)
	{
		if (!g_avm2_timers[i].active) continue;
		if (best == NULL || g_avm2_timers[i].tick_time < best->tick_time)
			best = &g_avm2_timers[i];
	}
	return best;
}

static Avm2TimerEntry* timer_find_by_id(int32_t id)
{
	for (uint32_t i = 0; i < g_avm2_timer_count; i++)
		if (g_avm2_timers[i].active && g_avm2_timers[i].id == id)
			return &g_avm2_timers[i];
	return NULL;
}

// Ruffle Timers::update_timers: advance the µs clock by one frame, then fire
// every entry whose tick_time is strictly < cur_time (earliest first), each at
// most MAX_TICKS times per frame.
static void run_due_timers(Avm2Context* ctx)
{
	double fps = (double) (int16_t) avm2_generated_frame_rate / 256.0;
	if (fps <= 0) fps = 24.0;
	uint64_t dt_us = (uint64_t) (1000.0 / fps * 1000.0);
	g_avm2_timer_cur_time += dt_us;

	int ticks = 0;
	for (;;)
	{
		Avm2TimerEntry* t = timer_find_min();
		if (t == NULL || !(t->tick_time < g_avm2_timer_cur_time)) break;
		if (++ticks > AVM2_TIMER_MAX_TICKS)
		{
			// SANITY backstop: rewind to just before the nearest timer.
			g_avm2_timer_cur_time =
				t->tick_time > 100 ? t->tick_time - 100 : 0;
			break;
		}
		int32_t fired_id = t->id;
		uint8_t was_timeout = t->is_timeout;
		int cancel = timer_fire_entry(ctx, t);
		// The callback may have added/removed timers; re-find by id.
		Avm2TimerEntry* e = timer_find_by_id(fired_id);
		if (e != NULL)
		{
			if (was_timeout || cancel) e->active = 0;
			else e->tick_time += e->interval;
		}
	}
	// Compact dead entries.
	uint32_t w = 0;
	for (uint32_t i = 0; i < g_avm2_timer_count; i++)
	{
		if (g_avm2_timers[i].active) g_avm2_timers[w++] = g_avm2_timers[i];
	}
	g_avm2_timer_count = w;
}

void avm2_display_run_tick(Avm2Context* ctx)
{
	if (ctx->stage == NULL) return;

	ctx->frame_phase = PHASE_ENTER;
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, g_orphans[i]);
		if (e != NULL && e->parent == NULL) enter_frame_obj(ctx, g_orphans[i]);
	}
	// Stage: children forward order, then broadcast (ST:858).
	{
		Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, ctx->stage);
		for (uint32_t i = 0; i < sext->render_len; i++)
		{
			enter_frame_obj(ctx, sext->render_list[i]);
		}
		broadcast_named(ctx, "enterFrame");
	}

	ctx->frame_phase = PHASE_CONSTRUCT;
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, g_orphans[i]);
		if (e != NULL && e->parent == NULL) construct_frame_obj(ctx, g_orphans[i]);
	}
	{
		Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, ctx->stage);
		for (uint32_t i = 0; i < sext->render_len; i++)
		{
			construct_frame_obj(ctx, sext->render_list[i]);
		}
	}
	broadcast_named(ctx, "frameConstructed");

	ctx->frame_phase = PHASE_FRAME_SCRIPTS;
	{
		Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, ctx->stage);
		for (uint32_t i = 0; i < sext->render_len; i++)
		{
			run_frame_scripts_obj(ctx, sext->render_list[i]);
		}
	}
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, g_orphans[i]);
		if (e != NULL && e->parent == NULL) run_frame_scripts_obj(ctx, g_orphans[i]);
	}
	run_frame_script_cleanup(ctx);

	ctx->frame_phase = PHASE_EXIT;
	broadcast_named(ctx, "exitFrame");
	orphan_cleanup(ctx);

	ctx->frame_phase = PHASE_IDLE;
	// Render phase: stage.invalidate() requests one "render" broadcast.
	if (g_stage_invalidated_flag)
	{
		g_stage_invalidated_flag = 0;
		broadcast_named(ctx, "render");
	}
	// The render pass applies pending autosize bounds on every VISIBLE
	// on-stage TextField (Ruffle EditText::render_self ->
	// apply_autosize_bounds; edittext_autosize_lazy_bounds_events).
	render_apply_text_bounds(ctx, ctx->stage, 1);

	// Timers: Ruffle runs update_timers AFTER run_frame (player.rs::tick), so
	// fire at the tail — the µs clock advances one frame here.
	run_due_timers(ctx);

	// Stage 8: deliver this tick's injected input (Ruffle processes input at
	// frame boundaries — after the frame's scripts). One WAIT group per tick.
	avm2_input_pump_tick(ctx);
}

// ---------------------------------------------------------------------------
// Stage build (called from runSWF_avm2)
// ---------------------------------------------------------------------------

void avm2_display_build_stage(Avm2Context* ctx, const char* root_class_name)
{
	// Symbol map (class -> char) for `new SymbolClass()` instantiation.
	g_symbol_map = avm2_alloc(ctx, (avm2_generated_symbol_class_count + 1)
	                                   * sizeof(SymbolClassMap));
	g_symbol_map_count = 0;
	for (uint32_t i = 0; i < avm2_generated_symbol_class_count; i++)
	{
		if (avm2_generated_symbol_classes[i].char_id == 0) continue;
		if (avm2_generated_symbol_classes[i].class_name == NULL) continue;
		Avm2Class* cls =
			class_for_dotted_name(ctx, avm2_generated_symbol_classes[i].class_name);
		if (cls != NULL)
		{
			g_symbol_map[g_symbol_map_count].cls = cls;
			g_symbol_map[g_symbol_map_count].char_id =
				avm2_generated_symbol_classes[i].char_id;
			g_symbol_map_count++;
		}
	}

	// Stage singleton.
	g_timeline_instantiation = 1;
	Avm2Object* stage = display_alloc_instance(ctx, ctx->builtins.stage_class);
	g_timeline_instantiation = 0;
	Avm2DisplayObjectExt* sext = (Avm2DisplayObjectExt*) stage->native_ext;
	sext->is_stage = 1;
	sext->is_root = 1;  // stage.root === stage (stage_displayobject_properties)
	sext->constructed = 1;
	ctx->stage = stage;

	// Root class: SymbolClass char 0, defaulting to MovieClip. A char-0
	// class that is NOT a DisplayObject is constructed once with the
	// stage as its sole argument (Ruffle's non-DO root special case).
	Avm2Class* root_cls = ctx->builtins.movieclip_class;
	Avm2Class* bound = NULL;
	if (root_class_name != NULL)
	{
		bound = class_for_dotted_name(ctx, root_class_name);
	}
	Avm2Object* nondo_root_instance = NULL;
	if (bound != NULL)
	{
		if (class_is_a(bound, ctx->builtins.display_object_class))
		{
			root_cls = bound;
		}
		else
		{
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				Avm2Value args[1] = { avm2_object_value(stage) };
				Avm2Value v = avm2_class_construct(ctx, bound, args, 1);
				nondo_root_instance = v.u.obj;
			}
			avm2_try_pop_frame(&top);
		}
	}
	(void) nondo_root_instance;

	g_timeline_instantiation = 1;
	Avm2Object* root = display_alloc_instance(ctx, root_cls);
	g_timeline_instantiation = 0;
	Avm2DisplayObjectExt* rext = (Avm2DisplayObjectExt*) root->native_ext;
	rext->is_root = 1;
	rext->char_id = 0;
	rext->timeline = timeline_for_char(0);
	rext->instantiated_by_timeline = 1;
	rext->depth = 0;
	rext->parent = stage;
	rext->name = avm2_string_from_literal(ctx, "root1");
	ctx->root = root;
	// Stage depth/render lists.
	replace_at_depth(ctx, sext, root, 0);
}

// ===========================================================================
// Natives: DisplayObject property surface
// ===========================================================================

static Avm2Value do_get_x(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(0);
	int32_t off = 0;
	if (ext->edittext != NULL)
	{
		cache_scale_rotation(ext);
		off = avm2_text_bounds_x_offset(act->ctx, this_obj(act), ext->scale_x);
	}
	return avm2_number(twips_to_pixels(ext->mtx_tx + off));
}

static Avm2Value do_set_x(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		int32_t off = 0;
		if (ext->edittext != NULL)
		{
			cache_scale_rotation(ext);
			off = avm2_text_bounds_x_offset(act->ctx, this_obj(act), ext->scale_x);
		}
		ext->mtx_tx = twips_from_pixels(avm2_coerce_to_number(act->ctx, act->args[0])) - off;
	}
	return avm2_undefined();
}

static Avm2Value do_get_y(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(0);
	int32_t off = 0;
	if (ext->edittext != NULL)
	{
		cache_scale_rotation(ext);
		off = avm2_text_bounds_y_offset(act->ctx, this_obj(act), ext->scale_y);
	}
	return avm2_number(twips_to_pixels(ext->mtx_ty + off));
}

static Avm2Value do_set_y(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		int32_t off = 0;
		if (ext->edittext != NULL)
		{
			cache_scale_rotation(ext);
			off = avm2_text_bounds_y_offset(act->ctx, this_obj(act), ext->scale_y);
		}
		ext->mtx_ty = twips_from_pixels(avm2_coerce_to_number(act->ctx, act->args[0])) - off;
	}
	return avm2_undefined();
}

// World matrix: concat ancestors' matrices.
static Mat display_world_matrix(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	Mat m = ext != NULL ? ext_matrix(ext) : mat_identity();
	Avm2Object* p = ext != NULL ? ext->parent : NULL;
	while (p != NULL)
	{
		Avm2DisplayObjectExt* pe = avm2_display_ext_of(ctx, p);
		if (pe == NULL) break;
		Mat pm = ext_matrix(pe);
		m = mat_mul(&pm, &m);
		p = pe->parent;
	}
	return m;
}

// Invert an affine Mat (a b c d tx ty).
static Mat mat_invert(const Mat* m)
{
	Mat r = mat_identity();
	double det = (double) m->a * m->d - (double) m->b * m->c;
	if (det == 0.0) return r;
	double ia = m->d / det, ib = -m->b / det, ic = -m->c / det, id = m->a / det;
	r.a = (float) ia;
	r.b = (float) ib;
	r.c = (float) ic;
	r.d = (float) id;
	r.tx = (int32_t) nearbyint(-(ia * m->tx + ic * m->ty));
	r.ty = (int32_t) nearbyint(-(ib * m->tx + id * m->ty));
	return r;
}

static Mat display_world_matrix(Avm2Context* ctx, Avm2Object* obj);
#define display_world_matrix_fwd display_world_matrix

static Avm2Value do_get_bounds(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2Object* target = (act->argc > 0 && act->args[0].kind == AVM2_VALUE_OBJECT)
		? act->args[0].u.obj : NULL;
	if (self == NULL) return avm2_undefined();
	if (target == NULL || avm2_display_ext_of(ctx, target) == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter targetCoordinateSpace must be "
		                 "non-null.");
	}
	Mat mw = display_world_matrix_fwd(ctx, self);
	Mat tw = display_world_matrix_fwd(ctx, target);
	Mat ti = mat_invert(&tw);
	Mat m = mat_mul(&ti, &mw);
	Rect r = { 0, 0, 0, 0, 0 };
	bounds_with_transform(ctx, self, &m, &r);
	extern Avm2Value avm2_text_new_rectangle(Avm2Context* ctx, double x, double y,
	                                         double w, double h);
	if (!r.valid)
	{
		return avm2_text_new_rectangle(ctx, 0, 0, 0, 0);
	}
	return avm2_text_new_rectangle(ctx, r.xmin / 20.0, r.ymin / 20.0,
	                               (r.xmax - r.xmin) / 20.0,
	                               (r.ymax - r.ymin) / 20.0);
}

// globalToLocal / localToGlobal: Point through the (inverse) world matrix.
static Avm2Value point_transform_native(Avm2Activation* act, int to_local)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2Value pv = act->argc > 0 ? act->args[0] : avm2_undefined();
	if (self == NULL || pv.kind != AVM2_VALUE_OBJECT || pv.u.obj == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter point must be non-null.");
	}
	double x = 0, y = 0;
	{
		Avm2Object* pt = pv.u.obj;
		if (pt->slot_count > 2)
		{
			x = avm2_coerce_to_number(ctx, pt->slots[1]);
			y = avm2_coerce_to_number(ctx, pt->slots[2]);
		}
	}
	Mat m = display_world_matrix(ctx, self);
	if (to_local) m = mat_invert(&m);
	double tx = m.a * (x * 20.0) + m.c * (y * 20.0) + m.tx;
	double ty = m.b * (x * 20.0) + m.d * (y * 20.0) + m.ty;
	// flash.geom.Point lives in the builtin domain.
	Avm2PropKey key = avm2_public_key("Point", 5);
	key.ns_kind = 0x16;
	key.ns_uri = "flash.geom";
	key.ns_len = 10;
	(void) key;
	extern Avm2Class* avm2_display_point_class(Avm2Context* ctx);
	Avm2Value args[2] = { avm2_number(tx / 20.0), avm2_number(ty / 20.0) };
	return avm2_class_construct(ctx, avm2_display_point_class(ctx), args, 2);
}

static Avm2Value do_global_to_local(Avm2Activation* act)
{
	return point_transform_native(act, 1);
}

static Avm2Value do_local_to_global(Avm2Activation* act)
{
	return point_transform_native(act, 0);
}

// hitTestPoint(x, y, shapeFlag=false): AABB world-bounds test (applies
// pending autosize bounds like hit_test_object).
static Avm2Value do_hit_test_point(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_bool(false);
	double x = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0;
	double y = act->argc > 1 ? avm2_coerce_to_number(ctx, act->args[1]) : 0;
	avm2_text_apply_pending_bounds(ctx, self);
	Mat m = display_world_matrix(ctx, self);
	Rect r = { 0, 0, 0, 0, 0 };
	bounds_with_transform(ctx, self, &m, &r);
	double tx = x * 20.0, ty = y * 20.0;
	int hit = r.valid && tx >= r.xmin && tx <= r.xmax && ty >= r.ymin
	          && ty <= r.ymax;
	return avm2_bool(hit != 0);
}

// local3DToGlobal / globalToLocal3D: 2D fallbacks (no 3D transforms).
static Avm2Value do_local3d_to_global(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2Value pv = act->argc > 0 ? act->args[0] : avm2_undefined();
	if (self == NULL || pv.kind != AVM2_VALUE_OBJECT || pv.u.obj == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter point3d must be non-null.");
	}
	extern Avm2Class* avm2_display_point_class(Avm2Context* ctx);
	Avm2Value args[2] = { avm2_number(0), avm2_number(0) };
	return avm2_class_construct(ctx, avm2_display_point_class(ctx), args, 2);
}

static Avm2Value do_hit_test_object(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2Object* other = (act->argc > 0 && act->args[0].kind == AVM2_VALUE_OBJECT)
		? act->args[0].u.obj : NULL;
	if (self == NULL || other == NULL
	    || avm2_display_ext_of(ctx, other) == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter obj must be non-null.");
	}
	// world_bounds applies pending autosize bounds on TextFields.
	avm2_text_apply_pending_bounds(ctx, self);
	avm2_text_apply_pending_bounds(ctx, other);
	Mat ma = display_world_matrix(ctx, self);
	Mat mb = display_world_matrix(ctx, other);
	Rect ra = { 0, 0, 0, 0, 0 }, rb = { 0, 0, 0, 0, 0 };
	bounds_with_transform(ctx, self, &ma, &ra);
	bounds_with_transform(ctx, other, &mb, &rb);
	int hit = ra.valid && rb.valid
	          && ra.xmin <= rb.xmax && rb.xmin <= ra.xmax
	          && ra.ymin <= rb.ymax && rb.ymin <= ra.ymax;
	return avm2_bool(hit != 0);
}

static Avm2Value do_get_scale_x(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(1);
	cache_scale_rotation(ext);
	return avm2_number(ext->scale_x);
}

static Avm2Value do_set_scale_x(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		set_scale_x_internal(ext, avm2_coerce_to_number(act->ctx, act->args[0]));
	}
	return avm2_undefined();
}

static Avm2Value do_get_scale_y(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(1);
	cache_scale_rotation(ext);
	return avm2_number(ext->scale_y);
}

static Avm2Value do_set_scale_y(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		set_scale_y_internal(ext, avm2_coerce_to_number(act->ctx, act->args[0]));
	}
	return avm2_undefined();
}

static Avm2Value do_get_rotation(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(0);
	cache_scale_rotation(ext);
	// Normalize into [-180, 180]. Both wraps are strict so that a rotation set
	// to exactly +180 or -180 reads back with its original sign (Flash/Ruffle
	// keep them distinct; the sign survives matrix decomposition as ±0 in the
	// atan2 numerator).
	double rem = fmod(ext->rotation_deg, 360.0);
	if (rem > 180.0) rem -= 360.0;
	else if (rem < -180.0) rem += 360.0;
	return avm2_number(rem);
}

static Avm2Value do_set_rotation(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		set_rotation_internal(ext, avm2_coerce_to_number(act->ctx, act->args[0]));
	}
	return avm2_undefined();
}

static Avm2Value do_get_width(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(0);
	if (ext->edittext != NULL)
	{
		return avm2_number(avm2_text_get_width_px(act->ctx, this_obj(act)));
	}
	Rect r = display_bounds(act->ctx, this_obj(act), 1);
	return avm2_number(rect_width_px(&r));
}

static Avm2Value do_get_height(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(0);
	if (ext->edittext != NULL)
	{
		return avm2_number(avm2_text_get_height_px(act->ctx, this_obj(act)));
	}
	Rect r = display_bounds(act->ctx, this_obj(act), 1);
	return avm2_number(rect_height_px(&r));
}

// set_width/set_height (Ruffle TDisplayObject::set_width/set_height).
static void set_width_height(Avm2Activation* act, int is_width)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || act->argc < 1) return;
	double value = avm2_coerce_to_number(act->ctx, act->args[0]);
	if (ext->edittext != NULL)
	{
		// EditText bounds semantics (Ruffle EditText::set_width/set_height):
		// the bounds resize, not the scale.
		if (is_width) avm2_text_set_width_px(act->ctx, this_obj(act), value);
		else avm2_text_set_height_px(act->ctx, this_obj(act), value);
		return;
	}
	if (!(value >= 0.0)) return;  // rejects negatives AND NaN

	Rect ob = display_bounds(act->ctx, this_obj(act), 0);
	double object_width = rect_width_px(&ob);
	double object_height = rect_height_px(&ob);

	double target_scale_x = 0.0, target_scale_y = 0.0;
	double relevant = is_width ? object_width : object_height;
	if (relevant != 0.0)
	{
		target_scale_x = value / object_width;
		target_scale_y = value / object_height;
	}
	cache_scale_rotation(ext);
	double prev_scale_x = ext->scale_x;
	double prev_scale_y = ext->scale_y;
	double rot = ext->rotation_deg * (M_PI / 180.0);
	double c = fabs(cos(rot));
	double s = fabs(sin(rot));
	double new_scale_x, new_scale_y;
	if (is_width)
	{
		double aspect = object_height / object_width;
		new_scale_x = aspect * (c * target_scale_x + s * target_scale_y)
		              / ((c + aspect * s) * (aspect * c + s));
		new_scale_y = (s * prev_scale_x + aspect * c * prev_scale_y)
		              / (aspect * c + s);
	}
	else
	{
		double aspect = object_width / object_height;
		new_scale_x = (aspect * c * prev_scale_x + s * prev_scale_y)
		              / (aspect * c + s);
		new_scale_y = aspect * (s * target_scale_x + c * target_scale_y)
		              / ((c + aspect * s) * (aspect * c + s));
	}
	if (!isfinite(new_scale_x)) new_scale_x = 0.0;
	if (!isfinite(new_scale_y)) new_scale_y = 0.0;
	set_scale_x_internal(ext, new_scale_x);
	set_scale_y_internal(ext, new_scale_y);
}

static Avm2Value do_set_width(Avm2Activation* act)
{
	set_width_height(act, 1);
	return avm2_undefined();
}

static Avm2Value do_set_height(Avm2Activation* act)
{
	set_width_height(act, 0);
	return avm2_undefined();
}

static Avm2Value do_get_alpha(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_number(ext != NULL ? (double) ext->alpha_fixed8 / 256.0 : 1.0);
}

static Avm2Value do_set_alpha(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		double v = avm2_coerce_to_number(act->ctx, act->args[0]) * 256.0;
		int16_t f;
		if (isnan(v)) f = 0;
		else if (v >= 32767.0) f = 32767;
		else if (v <= -32768.0) f = -32768;
		else f = (int16_t) v;
		ext->alpha_fixed8 = f;
	}
	return avm2_undefined();
}

static Avm2Value do_get_sound_transform(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	static const int32_t def[5] = { 100, 0, 0, 100, 100 };  // l2l,l2r,r2l,r2r,vol
	const int32_t* core = (ext != NULL && ext->sound_transform_set)
		? ext->sound_transform : def;
	return avm2_sound_transform_from_core(act->ctx, core);
}

static Avm2Value do_set_sound_transform(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	int32_t core[5];
	if (act->argc > 0 && avm2_sound_transform_read(act->ctx, act->args[0], core))
	{
		memcpy(ext->sound_transform, core, sizeof(core));
		ext->sound_transform_set = 1;
	}
	return avm2_undefined();
}

static Avm2Value do_get_visible(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_bool(ext == NULL || ext->visible != 0);
}

static Avm2Value do_set_visible(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->visible = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	}
	return avm2_undefined();
}

static Avm2Value do_get_name(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || ext->name == NULL) return avm2_null();
	return avm2_string(ext->name);
}

static Avm2Value do_set_name(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	const Avm2String* name = act->argc > 0
		? avm2_coerce_to_string(ctx, act->args[0])
		: avm2_string_from_literal(ctx, "null");
	if (ext->instantiated_by_timeline)
	{
		// IllegalOperationError (flash.errors keeps name "Error").
		avm2_throw_error(ctx, ctx->builtins.illegal_operation_error_class,
			"Error #2078: The name property of a Timeline-placed object cannot be modified.");
	}
	ext->name = name;
	return avm2_undefined();
}

static Avm2Value do_get_parent(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || ext->parent == NULL) return avm2_null();
	if (!is_container(act->ctx, ext->parent)) return avm2_null();
	return avm2_object_value(ext->parent);
}

static Avm2Value do_get_root(Avm2Activation* act)
{
	Avm2Object* r = avm2_root_of(act->ctx, this_obj(act));
	return r != NULL ? avm2_object_value(r) : avm2_null();
}

static Avm2Value do_get_stage(Avm2Activation* act)
{
	Avm2Object* s = stage_of(act->ctx, this_obj(act));
	return s != NULL ? avm2_object_value(s) : avm2_null();
}

static Avm2Value do_get_mask(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || ext->mask == NULL) return avm2_null();
	return avm2_object_value(ext->mask);
}

static Avm2Value do_set_mask(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->mask = (act->args[0].kind == AVM2_VALUE_OBJECT)
			? act->args[0].u.obj : NULL;
	}
	return avm2_undefined();
}

static Avm2Value do_get_metadata(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || ext->meta_data.kind != AVM2_VALUE_OBJECT) return avm2_null();
	return ext->meta_data;
}

static Avm2Value do_set_metadata(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	Avm2Value v = act->argc > 0 ? act->args[0] : avm2_null();
	if (v.kind != AVM2_VALUE_OBJECT)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter metaData must be non-null.");
	}
	if (ext != NULL) ext->meta_data = v;
	return avm2_undefined();
}

static Avm2Value do_get_filters(Avm2Activation* act)
{
	// Filters are not implemented: always a fresh empty Array.
	return avm2_object_value(avm2_array_new(act->ctx, 0));
}

static Avm2Value do_set_filters(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static void local_mouse(Avm2Context* ctx, Avm2Object* obj, double* lx, double* ly);

static Avm2Value do_get_mouse_x(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_number(0);
	double lx = 0, ly = 0;
	local_mouse(act->ctx, self, &lx, &ly);
	// mouseX is twips-quantized (Ruffle round to nearest twip -> pixels).
	return avm2_number(round(lx * 20.0) / 20.0);
}

static Avm2Value do_get_mouse_y(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_number(0);
	double lx = 0, ly = 0;
	local_mouse(act->ctx, self, &lx, &ly);
	return avm2_number(round(ly * 20.0) / 20.0);
}

static void disp_sconst(Avm2Context* ctx, Avm2Class* cls, const char* n,
                        const char* v)
{
	avm2_builtin_add_static_const(ctx, cls, n,
		avm2_string(avm2_string_from_literal(ctx, v)));
}

// --- flash.display.LoaderInfo (root movie only) ---
//
// The root SWF's LoaderInfo is a single shared object: every on-stage display
// object's `loaderInfo` returns it, and it is `=== root.loaderInfo` (test
// loaderinfo_root). Off-stage objects (no is_root ancestor) return null.
// flash.display.Loader (loading a *second* SWF) is still deferred, so there is
// exactly one root and one LoaderInfo singleton.

typedef struct Avm2LoaderInfoExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Object* parameters;             // stable identity across reads
} Avm2LoaderInfoExt;

static Avm2Object* g_root_loader_info;   // GC-rooted in avm2_gc_mark_roots_display
static double g_stage_frame_rate;        // tentative decl; defined below (Stage)

static Avm2LoaderInfoExt* loaderinfo_ext_of(Avm2Context* ctx, Avm2Object* o)
{
	if (o == NULL || o->cls == NULL
	    || !class_is_a(o->cls, ctx->builtins.loader_info_class))
		return NULL;
	return (Avm2LoaderInfoExt*) o->native_ext;
}

static Avm2Object* avm2_get_root_loader_info(Avm2Context* ctx)
{
	if (g_root_loader_info != NULL) return g_root_loader_info;
	Avm2Class* cls = ctx->builtins.loader_info_class;
	if (cls == NULL) return NULL;
	Avm2Value v = avm2_class_construct(ctx, cls, NULL, 0);
	if (v.kind != AVM2_VALUE_OBJECT) return NULL;
	g_root_loader_info = v.u.obj;
	return g_root_loader_info;
}

static Avm2Value do_get_loader_info(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	// loaderInfo is non-null only for objects connected to the root SWF.
	if (avm2_root_of(ctx, this_obj(act)) == NULL) return avm2_null();
	Avm2Object* li = avm2_get_root_loader_info(ctx);
	return li != NULL ? avm2_object_value(li) : avm2_null();
}

static Avm2Value li_get_bytes_total(Avm2Activation* act)
{
	(void) act;
#ifdef SWF_ONDISK_SIZE
	return avm2_number((double) SWF_ONDISK_SIZE);
#else
	return avm2_number(0);
#endif
}

static Avm2Value li_get_content(Avm2Activation* act)
{
	Avm2Object* r = act->ctx->root;
	return r != NULL ? avm2_object_value(r) : avm2_null();
}

static Avm2Value li_get_content_type(Avm2Activation* act)
{
	return avm2_string(avm2_string_from_literal(act->ctx,
	                                             "application/x-shockwave-flash"));
}

static Avm2Value li_get_as_version(Avm2Activation* act)
{
	(void) act;
	return avm2_integer(3);
}

static Avm2Value li_get_frame_rate(Avm2Activation* act)
{
	(void) act;
	return avm2_number(g_stage_frame_rate);
}

static Avm2Value li_get_width(Avm2Activation* act)
{
	(void) act;
	return avm2_integer((avm2_generated_stage_rect[1]
	                     - avm2_generated_stage_rect[0]) / 20);
}

static Avm2Value li_get_height(Avm2Activation* act)
{
	(void) act;
	return avm2_integer((avm2_generated_stage_rect[3]
	                     - avm2_generated_stage_rect[2]) / 20);
}

static Avm2Value li_get_swf_version(Avm2Activation* act)
{
	(void) act;
	return avm2_integer(avm2_generated_swf_version);
}

static Avm2Value li_get_url(Avm2Activation* act)
{
#ifdef SWF_URL
	return avm2_string(avm2_string_from_literal(act->ctx, SWF_URL));
#else
	return avm2_string(avm2_string_from_literal(act->ctx, ""));
#endif
}

static Avm2Value li_get_true(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(1);
}

static Avm2Value li_get_parameters(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2LoaderInfoExt* ext = loaderinfo_ext_of(ctx, this_obj(act));
	if (ext == NULL) return avm2_null();
	if (ext->parameters == NULL)
	{
		// Empty dynamic Object (no flashvars in headless / native).
		Avm2Value o = avm2_class_construct(ctx, ctx->builtins.object_class,
		                                   NULL, 0);
		ext->parameters = o.kind == AVM2_VALUE_OBJECT ? o.u.obj : NULL;
	}
	return ext->parameters != NULL ? avm2_object_value(ext->parameters)
	                               : avm2_null();
}

static Avm2Value li_get_application_domain(Avm2Activation* act)
{
	return avm2_current_domain_value(act->ctx);
}

static Avm2Value li_get_loader(Avm2Activation* act)
{
	(void) act;
	return avm2_null();  // root movie has no parent Loader
}

// --- InteractiveObject ---

static Avm2Value io_get_mouse_enabled(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_bool(ext == NULL || ext->mouse_enabled != 0);
}

static Avm2Value io_set_mouse_enabled(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->mouse_enabled = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	}
	return avm2_undefined();
}

static Avm2Value io_get_double_click_enabled(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_bool(ext != NULL && ext->double_click_enabled != 0);
}

static Avm2Value io_set_double_click_enabled(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->double_click_enabled = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	}
	return avm2_undefined();
}

static Avm2Value io_get_tab_enabled(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_bool(false);
	return avm2_bool(ext->tab_enabled_set ? ext->tab_enabled_val != 0 : false);
}

static Avm2Value io_set_tab_enabled(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->tab_enabled_set = 1;
		ext->tab_enabled_val = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	}
	return avm2_undefined();
}

static Avm2Value io_get_tab_index(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_integer(ext != NULL ? ext->tab_index : -1);
}

static Avm2Value io_set_tab_index(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	int32_t v = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	if (v < -1)
	{
		avm2_throw_error(ctx, ctx->builtins.range_error_class,
			"Error #2027: Parameter tabIndex must be a non-negative number; got %d.",
			v);
	}
	if (ext != NULL) ext->tab_index = v;
	return avm2_undefined();
}

static Avm2Value io_get_focus_rect(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || !ext->focus_rect_set) return avm2_null();
	return avm2_bool(ext->focus_rect_val != 0);
}

static Avm2Value io_set_focus_rect(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_null();
	Avm2Value v = act->argc > 0 ? act->args[0] : avm2_null();
	if (v.kind == AVM2_VALUE_NULL)
	{
		ext->focus_rect_set = 0;
	}
	else
	{
		ext->focus_rect_set = 1;
		ext->focus_rect_val = (v.kind == AVM2_VALUE_BOOL && v.u.b) ? 1 : 0;
	}
	return avm2_null();
}

// ===========================================================================
// Natives: DisplayObjectContainer child API
// ===========================================================================

static Avm2Object* arg_display_object(Avm2Activation* act, uint32_t idx,
                                      const char* pname)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc <= idx || act->args[idx].kind != AVM2_VALUE_OBJECT
	    || act->args[idx].u.obj == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter %s must be non-null.", pname);
	}
	return act->args[idx].u.obj;
}

static void throw_2006(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.range_error_class,
	                 "Error #2006: The supplied index is out of bounds.");
}

static void throw_2025(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2025: The supplied DisplayObject must be a child of the caller.");
}

// validate_add_operation (Ruffle DOC natives).
static void validate_add(Avm2Context* ctx, Avm2Object* parent, Avm2Object* child,
                         uint32_t index)
{
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	if (cext != NULL && cext->is_stage)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
			"Error #3783: A Stage object cannot be added as the child of another object.");
	}
	if (child == parent)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2024: An object cannot be added as a child of itself.");
	}
	for (Avm2Object* p = parent; p != NULL; )
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, p);
		if (e == NULL) break;
		if (p == child)
		{
			avm2_throw_error(ctx, ctx->builtins.argument_error_class,
				"Error #2150: An object cannot be added as a child to one of it's "
				"children (or children's children, etc.).");
		}
		p = e->parent;
	}
	if (pext == NULL || index > pext->render_len)
	{
		throw_2006(ctx);
	}
}

static Avm2Value doc_add_child(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* parent = this_obj(act);
	Avm2DisplayObjectExt* pext = this_display(act);
	Avm2Object* child = arg_display_object(act, 0, "child");
	if (pext == NULL) return avm2_null();
	uint32_t index = pext->render_len;
	validate_add(ctx, parent, child, index);
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext != NULL) cext->placed_by_avm2_script = 1;
	insert_at_index(ctx, parent, child, index);
	return avm2_object_value(child);
}

static Avm2Value doc_add_child_at(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* parent = this_obj(act);
	Avm2Object* child = arg_display_object(act, 0, "child");
	uint32_t index = act->argc > 1 ? avm2_coerce_to_u32(ctx, act->args[1]) : 0;
	validate_add(ctx, parent, child, index);
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext != NULL) cext->placed_by_avm2_script = 1;
	insert_at_index(ctx, parent, child, index);
	return avm2_object_value(child);
}

static Avm2Value doc_remove_child(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	Avm2Object* child = arg_display_object(act, 0, "child");
	if (pext == NULL || render_index_of(pext, child) < 0)
	{
		throw_2025(ctx);
	}
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext != NULL) cext->placed_by_avm2_script = 1;
	full_remove_child(ctx, pext, child);
	return avm2_object_value(child);
}

static Avm2Value doc_remove_child_at(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	int32_t i = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	if (pext == NULL || i < 0 || (uint32_t) i >= pext->render_len)
	{
		throw_2006(ctx);
	}
	Avm2Object* child = pext->render_list[i];
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext != NULL) cext->placed_by_avm2_script = 1;
	full_remove_child(ctx, pext, child);
	return avm2_object_value(child);
}

static Avm2Value doc_remove_children(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	if (pext == NULL) return avm2_undefined();
	int32_t from = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	int32_t to = act->argc > 1 ? avm2_coerce_to_i32(ctx, act->args[1]) : INT32_MAX;
	int32_t n = (int32_t) pext->render_len;
	if ((from >= n || from < 0) && to != INT32_MAX) throw_2006(ctx);
	if ((to >= n || to < 0) && to != INT32_MAX) throw_2006(ctx);
	if (from > to) throw_2006(ctx);
	int64_t endi = (int64_t) to + 1;
	if (endi > n) endi = n;
	if (from >= endi) return avm2_undefined();
	uint32_t count = (uint32_t) (endi - from);
	Avm2Object** snapshot = avm2_alloc(ctx, count * sizeof(Avm2Object*));
	memcpy(snapshot, &pext->render_list[from], count * sizeof(Avm2Object*));
	for (uint32_t i = 0; i < count; i++)
	{
		dispatch_removed_event(ctx, snapshot[i]);
	}
	for (uint32_t i = 0; i < count; i++)
	{
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, snapshot[i]);
		if (cext != NULL) cext->placed_by_avm2_script = 1;
		remove_child_from_depth_list(pext, snapshot[i]);
		render_list_remove(pext, snapshot[i]);
		if (cext != NULL)
		{
			cext->parent = NULL;
			orphan_add(ctx, snapshot[i]);
		}
	}
	return avm2_undefined();
}

static Avm2Value doc_get_child_at(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	int32_t i = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	if (pext == NULL || i < 0 || (uint32_t) i >= pext->render_len)
	{
		throw_2006(ctx);
	}
	Avm2Object* child = pext->render_list[i];
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext != NULL && !cext->constructed) return avm2_null();
	return avm2_object_value(child);
}

static Avm2Value doc_get_child_by_name(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	if (pext == NULL || act->argc < 1) return avm2_null();
	const Avm2String* name = avm2_coerce_to_string(ctx, act->args[0]);
	for (uint32_t i = 0; i < pext->render_len; i++)
	{
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, pext->render_list[i]);
		if (cext != NULL && cext->name != NULL
		    && avm2_string_equals(cext->name, name))
		{
			if (!cext->constructed) return avm2_null();
			return avm2_object_value(pext->render_list[i]);
		}
	}
	return avm2_null();
}

static Avm2Value doc_get_child_index(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	if (pext != NULL && act->argc > 0 && act->args[0].kind == AVM2_VALUE_OBJECT)
	{
		int pos = render_index_of(pext, act->args[0].u.obj);
		if (pos >= 0) return avm2_integer(pos);
	}
	throw_2025(ctx);
}

static Avm2Value doc_set_child_index(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* parent = this_obj(act);
	Avm2Object* child = arg_display_object(act, 0, "child");
	uint32_t index = act->argc > 1 ? avm2_coerce_to_u32(ctx, act->args[1]) : 0;
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext == NULL || cext->parent != parent) throw_2025(ctx);
	validate_add(ctx, parent, child, index);
	cext->placed_by_avm2_script = 1;
	insert_at_index(ctx, parent, child, index);
	return avm2_undefined();
}

static Avm2Value doc_swap_children(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	Avm2Object* c0 = arg_display_object(act, 0, "child1");
	Avm2Object* c1 = arg_display_object(act, 1, "child2");
	if (pext == NULL) throw_2025(ctx);
	int i0 = render_index_of(pext, c0);
	int i1 = render_index_of(pext, c1);
	if (i0 < 0 || i1 < 0) throw_2025(ctx);
	Avm2DisplayObjectExt* e0 = avm2_display_ext_of(ctx, c0);
	Avm2DisplayObjectExt* e1 = avm2_display_ext_of(ctx, c1);
	if (e0 != NULL) e0->placed_by_avm2_script = 1;
	if (e1 != NULL) e1->placed_by_avm2_script = 1;
	pext->render_list[i0] = c1;
	pext->render_list[i1] = c0;
	return avm2_undefined();
}

static Avm2Value doc_swap_children_at(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* pext = this_display(act);
	int32_t i0 = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	int32_t i1 = act->argc > 1 ? avm2_coerce_to_i32(ctx, act->args[1]) : 0;
	if (pext == NULL) throw_2006(ctx);
	int32_t n = (int32_t) pext->render_len;
	if (i0 < 0 || i0 >= n || i1 < 0 || i1 >= n) throw_2006(ctx);
	Avm2Object* c0 = pext->render_list[i0];
	Avm2Object* c1 = pext->render_list[i1];
	Avm2DisplayObjectExt* e0 = avm2_display_ext_of(ctx, c0);
	Avm2DisplayObjectExt* e1 = avm2_display_ext_of(ctx, c1);
	if (e0 != NULL) e0->placed_by_avm2_script = 1;
	if (e1 != NULL) e1->placed_by_avm2_script = 1;
	pext->render_list[i0] = c1;
	pext->render_list[i1] = c0;
	return avm2_undefined();
}

static Avm2Value doc_contains(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* parent = this_obj(act);
	if (is_container(ctx, parent) && act->argc > 0
	    && act->args[0].kind == AVM2_VALUE_OBJECT)
	{
		Avm2Object* p = act->args[0].u.obj;
		while (p != NULL)
		{
			if (p == parent) return avm2_bool(true);
			Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, p);
			if (e == NULL) break;
			p = e->parent;
		}
	}
	return avm2_bool(false);
}

static Avm2Value doc_get_num_children(Avm2Activation* act)
{
	Avm2DisplayObjectExt* pext = this_display(act);
	return avm2_integer(pext != NULL ? (int32_t) pext->render_len : 0);
}

static void stop_all_movie_clips(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (class_is_a(obj->cls, ctx->builtins.movieclip_class))
	{
		ext->playing = 0;
	}
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		if (is_container(ctx, ext->render_list[i]))
		{
			stop_all_movie_clips(ctx, ext->render_list[i]);
		}
	}
}

static Avm2Value doc_stop_all_movie_clips(Avm2Activation* act)
{
	Avm2Object* obj = this_obj(act);
	if (obj != NULL) stop_all_movie_clips(act->ctx, obj);
	return avm2_undefined();
}

static Avm2Value doc_get_mouse_children(Avm2Activation* act)
{
	Avm2DisplayObjectExt* pext = this_display(act);
	return avm2_bool(pext == NULL || pext->mouse_children != 0);
}

static Avm2Value doc_set_mouse_children(Avm2Activation* act)
{
	Avm2DisplayObjectExt* pext = this_display(act);
	if (pext != NULL && act->argc > 0)
	{
		pext->mouse_children = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	}
	return avm2_undefined();
}

static Avm2Value doc_get_tab_children(Avm2Activation* act)
{
	Avm2DisplayObjectExt* pext = this_display(act);
	return avm2_bool(pext == NULL || pext->tab_children != 0);
}

static Avm2Value doc_set_tab_children(Avm2Activation* act)
{
	Avm2DisplayObjectExt* pext = this_display(act);
	if (pext != NULL && act->argc > 0)
	{
		pext->tab_children = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	}
	return avm2_undefined();
}

// ===========================================================================
// Natives: MovieClip
// ===========================================================================

static Avm2Value mc_get_current_frame(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_integer(1);
	// Scene-relative (Ruffle G:42): only the root has scenes.
	if (ext->is_root && avm2_generated_scene_count > 0)
	{
		uint32_t best = 0;
		int found = 0;
		for (uint32_t i = 0; i < avm2_generated_scene_count; i++)
		{
			uint32_t start = avm2_generated_scenes[i].offset + 1;
			if (start <= ext->current_frame && (!found || start > best))
			{
				best = start;
				found = 1;
			}
		}
		if (found)
		{
			return avm2_integer((int32_t) ext->current_frame + 1 - (int32_t) best);
		}
	}
	return avm2_integer(ext->current_frame);
}

static Avm2Value mc_get_total_frames(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_integer(ext != NULL ? (int32_t) total_frames(ext) : 1);
}

static Avm2Value mc_get_frames_loaded(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_integer(1);
	uint32_t fl = frames_loaded(ext);
	uint32_t tf = total_frames(ext);
	return avm2_integer((int32_t) (fl < tf ? fl : tf));
}

static Avm2Value mc_get_is_playing(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_bool(ext != NULL && ext->programmatically_played && ext->playing);
}

static void mc_set_programmatically_played(Avm2DisplayObjectExt* ext)
{
	if (total_frames(ext) > 1)
	{
		ext->programmatically_played = 1;
	}
}

static Avm2Value mc_play(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL)
	{
		mc_set_programmatically_played(ext);
		ext->playing = 1;
	}
	return avm2_undefined();
}

static Avm2Value mc_stop(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL) ext->playing = 0;
	return avm2_undefined();
}

static Avm2Value mc_next_frame(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && (uint32_t) ext->current_frame < total_frames(ext))
	{
		mc_goto_frame(act->ctx, this_obj(act), ext->current_frame + 1, 1);
	}
	return avm2_undefined();
}

static Avm2Value mc_prev_frame(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && ext->current_frame > 1)
	{
		mc_goto_frame(act->ctx, this_obj(act), ext->current_frame - 1, 1);
	}
	return avm2_undefined();
}

// Scene helpers over the generated tables (root only).
typedef struct SceneInfo
{
	const char* name;
	uint32_t start;   // 1-based
	uint32_t length;
} SceneInfo;

static uint32_t scene_list(Avm2DisplayObjectExt* ext, SceneInfo* out, uint32_t max)
{
	if (!ext->is_root || avm2_generated_scene_count == 0) return 0;
	uint32_t n = avm2_generated_scene_count;
	if (n > max) n = max;
	for (uint32_t i = 0; i < n; i++)
	{
		out[i].name = avm2_generated_scenes[i].name;
		out[i].start = avm2_generated_scenes[i].offset + 1;
		uint32_t end = (i + 1 < avm2_generated_scene_count)
			? avm2_generated_scenes[i + 1].offset + 1
			: total_frames(ext) + 1;
		out[i].length = end - out[i].start;
	}
	return n;
}

static int current_scene_of(Avm2DisplayObjectExt* ext, SceneInfo* out)
{
	SceneInfo scenes[64];
	uint32_t n = scene_list(ext, scenes, 64);
	int best = -1;
	for (uint32_t i = 0; i < n; i++)
	{
		uint32_t cf = ext->current_frame > 0 ? ext->current_frame : 1;
		if (scenes[i].start <= cf && (best < 0 || scenes[i].start >= scenes[best].start))
		{
			best = (int) i;
		}
	}
	if (best >= 0)
	{
		*out = scenes[best];
		return 1;
	}
	out->name = "";
	out->start = 1;
	out->length = total_frames(ext);
	return 0;
}

// Label lookup on this clip's timeline (labels are 0-based frames in the
// tables; expose 1-based).
static int label_to_frame(Avm2DisplayObjectExt* ext, const Avm2String* label)
{
	if (ext->timeline == NULL) return -1;
	for (uint32_t i = 0; i < ext->timeline->label_count; i++)
	{
		const char* l = ext->timeline->labels[i].label;
		if (strlen(l) == label->len && memcmp(l, label->utf8, label->len) == 0)
		{
			return (int) ext->timeline->labels[i].frame + 1;
		}
	}
	return -1;
}

static Avm2Class* g_frame_label_class;
static Avm2Class* g_scene_class;

static Avm2Object* make_frame_label(Avm2Context* ctx, const char* name, int32_t frame)
{
	Avm2Value args[2];
	args[0] = avm2_string(avm2_string_from_literal(ctx, name));
	args[1] = avm2_integer(frame);
	Avm2Value inst = avm2_class_construct(ctx, g_frame_label_class, args, 2);
	return inst.u.obj;
}

static Avm2Value mc_get_current_label(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || ext->timeline == NULL) return avm2_null();
	const char* best = NULL;
	uint32_t best_frame = 0;
	for (uint32_t i = 0; i < ext->timeline->label_count; i++)
	{
		uint32_t f = ext->timeline->labels[i].frame + 1;
		if (f <= ext->current_frame && (best == NULL || f >= best_frame))
		{
			best = ext->timeline->labels[i].label;
			best_frame = f;
		}
	}
	return best != NULL ? avm2_string(avm2_string_from_literal(act->ctx, best))
	                    : avm2_null();
}

static Avm2Value mc_get_current_frame_label(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || ext->timeline == NULL) return avm2_null();
	for (uint32_t i = 0; i < ext->timeline->label_count; i++)
	{
		if (ext->timeline->labels[i].frame + 1 == ext->current_frame)
		{
			return avm2_string(avm2_string_from_literal(
				act->ctx, ext->timeline->labels[i].label));
		}
	}
	return avm2_null();
}

static Avm2Value mc_get_current_labels(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	Avm2Object* arr = avm2_array_new(ctx, 0);
	if (ext == NULL || ext->timeline == NULL) return avm2_object_value(arr);
	SceneInfo scene;
	current_scene_of(ext, &scene);
	uint32_t n = 0;
	for (uint32_t i = 0; i < ext->timeline->label_count; i++)
	{
		uint32_t f = ext->timeline->labels[i].frame + 1;
		if (f >= scene.start && f < scene.start + scene.length)
		{
			Avm2Object* fl = make_frame_label(ctx, ext->timeline->labels[i].label,
			                                  (int32_t) (f - scene.start + 1));
			avm2_array_set(ctx, arr, n++, avm2_object_value(fl));
		}
	}
	return avm2_object_value(arr);
}

static Avm2Object* make_scene(Avm2Context* ctx, Avm2DisplayObjectExt* ext,
                              const SceneInfo* si)
{
	Avm2Class* cls = g_scene_class;
	// labels within the scene, scene-relative 1-based frames.
	Avm2Object* labels = avm2_array_new(ctx, 0);
	uint32_t n = 0;
	if (ext->timeline != NULL)
	{
		for (uint32_t i = 0; i < ext->timeline->label_count; i++)
		{
			uint32_t f = ext->timeline->labels[i].frame + 1;
			if (f >= si->start && f < si->start + si->length)
			{
				Avm2Object* fl = make_frame_label(ctx, ext->timeline->labels[i].label,
				                                  (int32_t) (f - si->start + 1));
				avm2_array_set(ctx, labels, n++, avm2_object_value(fl));
			}
		}
	}
	Avm2Value args[3];
	args[0] = avm2_string(avm2_string_from_literal(ctx, si->name));
	args[1] = avm2_object_value(labels);
	args[2] = avm2_integer((int32_t) si->length);
	Avm2Value inst = avm2_class_construct(ctx, cls, args, 3);
	return inst.u.obj;
}

static Avm2Value mc_get_current_scene(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_null();
	SceneInfo si;
	current_scene_of(ext, &si);
	return avm2_object_value(make_scene(act->ctx, ext, &si));
}

static Avm2Value mc_get_scenes(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	Avm2Object* arr = avm2_array_new(ctx, 0);
	if (ext == NULL) return avm2_object_value(arr);
	SceneInfo scenes[64];
	uint32_t n = scene_list(ext, scenes, 64);
	if (n == 0)
	{
		SceneInfo si = { "", 1, total_frames(ext) };
		avm2_array_set(ctx, arr, 0, avm2_object_value(make_scene(ctx, ext, &si)));
		return avm2_object_value(arr);
	}
	for (uint32_t i = 0; i < n; i++)
	{
		avm2_array_set(ctx, arr, i, avm2_object_value(make_scene(ctx, ext, &scenes[i])));
	}
	return avm2_object_value(arr);
}

// gotoAndPlay/gotoAndStop argument handling (Ruffle G:384).
static void mc_goto_with_args(Avm2Activation* act, int stop)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	Avm2Object* obj = this_obj(act);
	if (ext == NULL || act->argc < 1) return;

	// Scene offset.
	int32_t scene_offset = 0;
	const Avm2String* scene_arg = NULL;
	if (act->argc > 1 && act->args[1].kind != AVM2_VALUE_NULL
	    && act->args[1].kind != AVM2_VALUE_UNDEFINED)
	{
		scene_arg = avm2_coerce_to_string(ctx, act->args[1]);
		SceneInfo scenes[64];
		uint32_t n = scene_list(ext, scenes, 64);
		int found = 0;
		for (uint32_t i = 0; i < n; i++)
		{
			if (strlen(scenes[i].name) == scene_arg->len
			    && memcmp(scenes[i].name, scene_arg->utf8, scene_arg->len) == 0)
			{
				scene_offset = (int32_t) scenes[i].start - 1;
				found = 1;
				break;
			}
		}
		(void) found;
	}
	else
	{
		SceneInfo si;
		if (current_scene_of(ext, &si))
		{
			scene_offset = (int32_t) si.start - 1;
		}
	}

	// Ruffle goto_frame arithmetic (globals movie_clip.rs): Integer VALUES
	// add the scene offset directly; everything else takes the string path
	// with i32 SATURATING parse + WRAPPING -1/+scene + SATURATING +1, and
	// the final u16 cast TRUNCATES — goto_methods' -0x80000000 (a Number,
	// not an Integer) wraps to i32::MAX and clamps to the LAST frame.
	// normalize(): only atom-range ints (|i| < 2^28) stay Integer; larger
	// Integers demote to Number and take the string path.
	int32_t frame = 1;
	Avm2Value arg = act->args[0];
	int use_int_path = 0;
	int32_t int_val = 0;
	if (arg.kind == AVM2_VALUE_INTEGER)
	{
		int_val = arg.u.i;
		use_int_path = (int_val >= -(1 << 28) && int_val < (1 << 28));
	}
	else if (arg.kind == AVM2_VALUE_NUMBER)
	{
		int32_t i = (int32_t) arg.u.d;
		if ((double) i == arg.u.d && !(arg.u.d == 0.0 && signbit(arg.u.d))
		    && i >= -(1 << 28) && i < (1 << 28))
		{
			int_val = i;
			use_int_path = 1;
		}
	}
	if (use_int_path)
	{
		frame = (int32_t) ((uint32_t) int_val + (uint32_t) scene_offset);
	}
	else
	{
		const Avm2String* s = avm2_coerce_to_string(ctx, arg);
		double n = avm2_string_to_int(s->utf8, s->len, 10, true);
		if (!isnan(n))
		{
			int32_t f;
			if (n >= 2147483647.0) f = INT32_MAX;
			else if (n <= -2147483648.0) f = INT32_MIN;
			else f = (int32_t) n;
			f = (int32_t) ((uint32_t) f - 1u);                 // wrapping_sub(1)
			f = (int32_t) ((uint32_t) f + (uint32_t) scene_offset);
			frame = (f == INT32_MAX) ? INT32_MAX : f + 1;      // saturating_add(1)
		}
		else
		{
			// Frame label.
			if (scene_arg != NULL)
			{
				// Label must exist within the named scene.
				int f = label_to_frame(ext, s);
				SceneInfo scenes[64];
				uint32_t nsc = scene_list(ext, scenes, 64);
				int in_scene = 0;
				for (uint32_t i = 0; i < nsc; i++)
				{
					if (strlen(scenes[i].name) == scene_arg->len
					    && memcmp(scenes[i].name, scene_arg->utf8, scene_arg->len) == 0
					    && f >= (int) scenes[i].start
					    && f < (int) (scenes[i].start + scenes[i].length))
					{
						in_scene = 1;
					}
				}
				if (!in_scene)
				{
					avm2_throw_error(ctx, ctx->builtins.argument_error_class,
					                 "Error #2109: Frame label %.*s not found in scene %.*s.",
					                 (int) s->len, s->utf8,
					                 (int) scene_arg->len, scene_arg->utf8);
				}
				frame = f;
			}
			else
			{
				int f = label_to_frame(ext, s);
				if (f < 0)
				{
					if (ctx->swf_version >= 11)
					{
						avm2_throw_error(ctx, ctx->builtins.argument_error_class,
						                 "Error #2109: Frame label %.*s not found in scene %.*s.",
						                 (int) s->len, s->utf8, (int) s->len, s->utf8);
					}
					f = 0;
				}
				frame = f;
			}
		}
	}
	if (!stop) mc_set_programmatically_played(ext);
	if (frame < 1) frame = 1;
	// TRUNCATING u16 cast (Ruffle `frame.max(1) as u16`).
	mc_goto_frame(ctx, obj, (uint16_t) (uint32_t) frame, stop);
}

static Avm2Value mc_goto_and_play(Avm2Activation* act)
{
	mc_goto_with_args(act, 0);
	return avm2_undefined();
}

static Avm2Value mc_goto_and_stop(Avm2Activation* act)
{
	mc_goto_with_args(act, 1);
	return avm2_undefined();
}

static Avm2Value mc_next_scene(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	SceneInfo scenes[64];
	uint32_t n = scene_list(ext, scenes, 64);
	int best = -1;
	for (uint32_t i = 0; i < n; i++)
	{
		if (scenes[i].start > ext->current_frame
		    && (best < 0 || scenes[i].start < scenes[best].start))
		{
			best = (int) i;
		}
	}
	if (best >= 0)
	{
		mc_goto_frame(act->ctx, this_obj(act), (uint16_t) scenes[best].start, 0);
	}
	else
	{
		// No next scene: goto the CURRENT scene's start (Ruffle
		// next_scene's .or(current_scene) — movieclip_next_scene).
		SceneInfo cur;
		current_scene_of(ext, &cur);
		mc_goto_frame(act->ctx, this_obj(act), (uint16_t) cur.start, 0);
	}
	return avm2_undefined();
}

static Avm2Value mc_prev_scene(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	SceneInfo cur;
	current_scene_of(ext, &cur);
	SceneInfo scenes[64];
	uint32_t n = scene_list(ext, scenes, 64);
	int best = -1;
	for (uint32_t i = 0; i < n; i++)
	{
		if (scenes[i].start < cur.start
		    && (best < 0 || scenes[i].start > scenes[best].start))
		{
			best = (int) i;
		}
	}
	if (best >= 0)
	{
		mc_goto_frame(act->ctx, this_obj(act), (uint16_t) scenes[best].start, 0);
	}
	else
	{
		// No previous scene: goto the CURRENT scene's start (Ruffle
		// prev_scene's .or(current_scene) — movieclip_prev_scene).
		mc_goto_frame(act->ctx, this_obj(act), (uint16_t) cur.start, 0);
	}
	return avm2_undefined();
}

// addFrameScript: (0-based frame, closure) pairs; stored 1-based.
static Avm2Value mc_add_frame_script(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL)
	{
		avm2_fatal("addFrameScript on a non-MovieClip receiver");
	}
	for (uint32_t i = 0; i + 1 < act->argc; i += 2)
	{
		int64_t frame_id = (int64_t) avm2_coerce_to_u32(ctx, act->args[i]) + 1;
		Avm2Value fn = act->args[i + 1];
		if (frame_id >= ext->frame_script_cap)
		{
			uint32_t new_cap = (uint32_t) frame_id + 8;
			Avm2Value* grown = avm2_alloc(ctx, new_cap * sizeof(Avm2Value));
			for (uint32_t j = 0; j < new_cap; j++)
			{
				grown[j] = (j < ext->frame_script_cap) ? ext->frame_scripts[j]
				                                       : avm2_undefined();
			}
			ext->frame_scripts = grown;
			ext->frame_script_cap = new_cap;
		}
		ext->frame_scripts[frame_id] = fn;
		if (fn.kind == AVM2_VALUE_OBJECT && frame_id == ext->current_frame)
		{
			if (ctx->frame_phase == PHASE_FRAME_SCRIPTS)
			{
				fs_cleanup_push(ctx, this_obj(act));
			}
			else
			{
				ext->last_queued_script_frame = -1;
				ext->has_pending_script = 1;
			}
		}
	}
	return avm2_undefined();
}

// ===========================================================================
// Natives: flash.display.Graphics (no rendering; tracks the AABB of drawn
// geometry so width/height see drawing-API content)
// ===========================================================================

static Avm2Class* g_graphics_class;

typedef struct Avm2GraphicsExt
{
	Avm2Object* owner;
} Avm2GraphicsExt;

static Avm2DisplayObjectExt* graphics_owner_ext(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL) return NULL;
	Avm2GraphicsExt* g = self->native_ext;
	return avm2_display_ext_of(act->ctx, g->owner);
}

static void draw_union_point(Avm2DisplayObjectExt* ext, double x_px, double y_px)
{
	int32_t x = twips_from_pixels(x_px);
	int32_t y = twips_from_pixels(y_px);
	if (!ext->draw_valid)
	{
		ext->draw_valid = 1;
		ext->draw_xmin = ext->draw_xmax = x;
		ext->draw_ymin = ext->draw_ymax = y;
		return;
	}
	if (x < ext->draw_xmin) ext->draw_xmin = x;
	if (x > ext->draw_xmax) ext->draw_xmax = x;
	if (y < ext->draw_ymin) ext->draw_ymin = y;
	if (y > ext->draw_ymax) ext->draw_ymax = y;
}

static Avm2Value gfx_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Avm2Value gfx_clear(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	if (ext != NULL) ext->draw_valid = 0;
	return avm2_undefined();
}

// moveTo/lineTo(x, y)
static Avm2Value gfx_point_op(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	if (ext != NULL && act->argc >= 2)
	{
		draw_union_point(ext, avm2_coerce_to_number(act->ctx, act->args[0]),
		                 avm2_coerce_to_number(act->ctx, act->args[1]));
	}
	return avm2_undefined();
}

// curveTo(cx, cy, ax, ay)
static Avm2Value gfx_curve_to(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	if (ext != NULL && act->argc >= 4)
	{
		draw_union_point(ext, avm2_coerce_to_number(act->ctx, act->args[0]),
		                 avm2_coerce_to_number(act->ctx, act->args[1]));
		draw_union_point(ext, avm2_coerce_to_number(act->ctx, act->args[2]),
		                 avm2_coerce_to_number(act->ctx, act->args[3]));
	}
	return avm2_undefined();
}

// drawRect/drawEllipse(x, y, w, h)
static Avm2Value gfx_draw_rect(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	if (ext != NULL && act->argc >= 4)
	{
		double x = avm2_coerce_to_number(act->ctx, act->args[0]);
		double y = avm2_coerce_to_number(act->ctx, act->args[1]);
		double w = avm2_coerce_to_number(act->ctx, act->args[2]);
		double h = avm2_coerce_to_number(act->ctx, act->args[3]);
		draw_union_point(ext, x, y);
		draw_union_point(ext, x + w, y + h);
	}
	return avm2_undefined();
}

// drawCircle(x, y, r)
static Avm2Value gfx_draw_circle(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	if (ext != NULL && act->argc >= 3)
	{
		double x = avm2_coerce_to_number(act->ctx, act->args[0]);
		double y = avm2_coerce_to_number(act->ctx, act->args[1]);
		double r = avm2_coerce_to_number(act->ctx, act->args[2]);
		draw_union_point(ext, x - r, y - r);
		draw_union_point(ext, x + r, y + r);
	}
	return avm2_undefined();
}

static Avm2Value do_get_graphics(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* obj = this_obj(act);
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_null();
	if (ext->graphics_obj == NULL)
	{
		Avm2Value v = avm2_class_construct(ctx, g_graphics_class, NULL, 0);
		((Avm2GraphicsExt*) v.u.obj->native_ext)->owner = obj;
		ext->graphics_obj = v.u.obj;
	}
	return avm2_object_value(ext->graphics_obj);
}

// ===========================================================================
// Natives: flash.geom.Matrix + Transform (enough for the transform.matrix
// property surface — displayobject_invalid_floats / displayobject_transform)
// ===========================================================================

static Avm2Class* g_matrix_class;
static Avm2Class* g_transform_class;

typedef struct Avm2TransformExt
{
	Avm2Object* target;
} Avm2TransformExt;

static void matrix_set_prop(Avm2Context* ctx, Avm2Object* m, const char* name,
                            double v)
{
	avm2_object_set_dynamic(ctx, m, name, (uint32_t) strlen(name), avm2_number(v));
}

static double matrix_get_prop(Avm2Context* ctx, Avm2Object* m, const char* name)
{
	Avm2Value* v = avm2_object_find_dynamic(m, name, (uint32_t) strlen(name));
	return v != NULL ? avm2_coerce_to_number(ctx, *v) : 0.0;
}

static Avm2Value geom_matrix_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	static const char* const names[6] = { "a", "b", "c", "d", "tx", "ty" };
	static const double defaults[6] = { 1, 0, 0, 1, 0, 0 };
	for (int i = 0; i < 6; i++)
	{
		double v = (uint32_t) i < act->argc
			? avm2_coerce_to_number(ctx, act->args[i]) : defaults[i];
		matrix_set_prop(ctx, self, names[i], v);
	}
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// flash.geom.Matrix method surface (ported from Ruffle avm1/globals/matrix.rs +
// render/src/matrix.rs, in pure f64 pixel space to match Flash's own doubles —
// NOT Ruffle's twips-quantized f32 render Matrix). Point transform semantics:
//   x' = a*x + c*y + tx ,  y' = b*x + d*y + ty .
// a/b/c/d/tx/ty live as dynamic props (see matrix_get/set_prop).
// ---------------------------------------------------------------------------

typedef struct { double a, b, c, d, tx, ty; } MatF;

static Avm2Object* make_geom_matrix(Avm2Context* ctx, double a, double b, double c,
                                    double d, double tx, double ty);

static MatF matf_read(Avm2Context* ctx, Avm2Object* m)
{
	MatF r;
	r.a = matrix_get_prop(ctx, m, "a");  r.b = matrix_get_prop(ctx, m, "b");
	r.c = matrix_get_prop(ctx, m, "c");  r.d = matrix_get_prop(ctx, m, "d");
	r.tx = matrix_get_prop(ctx, m, "tx"); r.ty = matrix_get_prop(ctx, m, "ty");
	return r;
}

static void matf_write(Avm2Context* ctx, Avm2Object* m, MatF v)
{
	matrix_set_prop(ctx, m, "a", v.a);   matrix_set_prop(ctx, m, "b", v.b);
	matrix_set_prop(ctx, m, "c", v.c);   matrix_set_prop(ctx, m, "d", v.d);
	matrix_set_prop(ctx, m, "tx", v.tx); matrix_set_prop(ctx, m, "ty", v.ty);
}

// result = A * B (A applied AFTER B), matching Ruffle's Matrix Mul.
static MatF matf_mul(MatF A, MatF B)
{
	MatF r;
	r.a = A.a * B.a + A.c * B.b;
	r.b = A.b * B.a + A.d * B.b;
	r.c = A.a * B.c + A.c * B.d;
	r.d = A.b * B.c + A.d * B.d;
	r.tx = A.a * B.tx + A.c * B.ty + A.tx;
	r.ty = A.b * B.tx + A.d * B.ty + A.ty;
	return r;
}

// arg i coerced to Number; undefined/absent -> NaN (Ruffle's unwrap_or Undefined).
static double matf_arg(Avm2Activation* act, uint32_t i)
{
	return i < act->argc ? avm2_coerce_to_number(act->ctx, act->args[i]) : (double) NAN;
}
// arg i coerced to Number; absent -> `def` (Ruffle's `if let Some` pattern).
static double matf_arg_def(Avm2Activation* act, uint32_t i, double def)
{
	return i < act->argc ? avm2_coerce_to_number(act->ctx, act->args[i]) : def;
}

static Avm2Object* matf_obj_arg(Avm2Activation* act, uint32_t i)
{
	return (act->argc > i && act->args[i].kind == AVM2_VALUE_OBJECT)
		? act->args[i].u.obj : NULL;
}

static double matf_read_num_prop(Avm2Context* ctx, Avm2Object* o, const char* name)
{
	if (o == NULL) return 0.0;
	int found = 0;
	Avm2Value v = avm2_get_public_property(ctx, avm2_object_value(o), name,
	                                       (uint32_t) strlen(name), &found);
	return found ? avm2_coerce_to_number(ctx, v) : 0.0;
}

static Avm2Value geom_matrix_identity(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s != NULL) matf_write(act->ctx, s, (MatF){ 1, 0, 0, 1, 0, 0 });
	return avm2_undefined();
}

static Avm2Value geom_matrix_clone(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	MatF m = matf_read(act->ctx, s);
	return avm2_object_value(
		make_geom_matrix(act->ctx, m.a, m.b, m.c, m.d, m.tx, m.ty));
}

static Avm2Value geom_matrix_scale(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	double sx = matf_arg(act, 0), sy = matf_arg(act, 1);
	MatF cur = matf_read(act->ctx, s);
	matf_write(act->ctx, s, matf_mul((MatF){ sx, 0, 0, sy, 0, 0 }, cur));
	return avm2_undefined();
}

static Avm2Value geom_matrix_rotate(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	double q = matf_arg(act, 0);
	MatF R = { cos(q), sin(q), -sin(q), cos(q), 0, 0 };
	matf_write(act->ctx, s, matf_mul(R, matf_read(act->ctx, s)));
	return avm2_undefined();
}

static Avm2Value geom_matrix_translate(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	double dx = matf_arg(act, 0), dy = matf_arg(act, 1);
	MatF cur = matf_read(act->ctx, s);
	cur.tx += dx;
	cur.ty += dy;
	matf_write(act->ctx, s, cur);
	return avm2_undefined();
}

static Avm2Value geom_matrix_concat(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	Avm2Object* o = matf_obj_arg(act, 0);
	MatF other = o != NULL ? matf_read(act->ctx, o) : (MatF){ 1, 0, 0, 1, 0, 0 };
	// this = other * this
	matf_write(act->ctx, s, matf_mul(other, matf_read(act->ctx, s)));
	return avm2_undefined();
}

static Avm2Value geom_matrix_invert(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	MatF m = matf_read(act->ctx, s);
	double det = m.a * m.d - m.b * m.c;
	MatF r;
	if (det != 0.0 && isfinite(det))
	{
		r.a = m.d / det;   r.b = -m.b / det;
		r.c = -m.c / det;  r.d = m.a / det;
		r.tx = (m.c * m.ty - m.d * m.tx) / det;
		r.ty = (m.b * m.tx - m.a * m.ty) / det;
	}
	else
	{
		r = (MatF){ 1, 0, 0, 1, 0, 0 };  // Ruffle: unwrap_or_default (identity)
	}
	matf_write(act->ctx, s, r);
	return avm2_undefined();
}

static Avm2Value geom_matrix_create_box(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	double sx = matf_arg(act, 0), sy = matf_arg(act, 1), rot = matf_arg(act, 2);
	double tx = matf_arg_def(act, 3, 0.0), ty = matf_arg_def(act, 4, 0.0);
	MatF r = { cos(rot) * sx, sin(rot) * sy, -sin(rot) * sx, cos(rot) * sy, tx, ty };
	matf_write(act->ctx, s, r);
	return avm2_undefined();
}

static Avm2Value geom_matrix_create_gradient_box(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	double w = matf_arg(act, 0), h = matf_arg(act, 1);
	double rot = matf_arg_def(act, 2, 0.0);
	double tx = matf_arg_def(act, 3, 0.0), ty = matf_arg_def(act, 4, 0.0);
	double sx = w / 1638.4, sy = h / 1638.4;
	MatF r = { cos(rot) * sx, sin(rot) * sy, -sin(rot) * sx, cos(rot) * sy,
	           tx + w / 2.0, ty + h / 2.0 };
	matf_write(act->ctx, s, r);
	return avm2_undefined();
}

static Avm2Value geom_matrix_transform_point_impl(Avm2Activation* act, int delta)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	MatF m = matf_read(ctx, s);
	Avm2Object* pt = matf_obj_arg(act, 0);
	double px = matf_read_num_prop(ctx, pt, "x");
	double py = matf_read_num_prop(ctx, pt, "y");
	double x = px * m.a + py * m.c + (delta ? 0.0 : m.tx);
	double y = px * m.b + py * m.d + (delta ? 0.0 : m.ty);
	extern Avm2Class* avm2_display_point_class(Avm2Context* ctx);
	Avm2Value pa[2] = { avm2_number(x), avm2_number(y) };
	return avm2_class_construct(ctx, avm2_display_point_class(ctx), pa, 2);
}

static Avm2Value geom_matrix_transform_point(Avm2Activation* act)
{
	return geom_matrix_transform_point_impl(act, 0);
}

static Avm2Value geom_matrix_delta_transform_point(Avm2Activation* act)
{
	return geom_matrix_transform_point_impl(act, 1);
}

static Avm2Value geom_matrix_set_to(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	MatF r = { matf_arg_def(act, 0, 0), matf_arg_def(act, 1, 0),
	           matf_arg_def(act, 2, 0), matf_arg_def(act, 3, 0),
	           matf_arg_def(act, 4, 0), matf_arg_def(act, 5, 0) };
	matf_write(act->ctx, s, r);
	return avm2_undefined();
}

static Avm2Value geom_matrix_copy_from(Avm2Activation* act)
{
	Avm2Object* s = this_obj(act);
	Avm2Object* o = matf_obj_arg(act, 0);
	if (s != NULL && o != NULL) matf_write(act->ctx, s, matf_read(act->ctx, o));
	return avm2_undefined();
}

// copyRowFrom(index, Vector3D): row0 -> (a,c,tx), row1 -> (b,d,ty), row2 ignored.
static Avm2Value geom_matrix_copy_row_from(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	int idx = (int) matf_arg(act, 0);
	Avm2Object* v = matf_obj_arg(act, 1);
	double vx = matf_read_num_prop(ctx, v, "x");
	double vy = matf_read_num_prop(ctx, v, "y");
	double vz = matf_read_num_prop(ctx, v, "z");
	MatF m = matf_read(ctx, s);
	if (idx == 0) { m.a = vx; m.c = vy; m.tx = vz; }
	else if (idx == 1) { m.b = vx; m.d = vy; m.ty = vz; }
	matf_write(ctx, s, m);
	return avm2_undefined();
}

// copyColumnFrom(index, Vector3D): col0 -> (a,b), col1 -> (c,d), col2 -> (tx,ty).
static Avm2Value geom_matrix_copy_column_from(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = this_obj(act);
	if (s == NULL) return avm2_undefined();
	int idx = (int) matf_arg(act, 0);
	Avm2Object* v = matf_obj_arg(act, 1);
	double vx = matf_read_num_prop(ctx, v, "x");
	double vy = matf_read_num_prop(ctx, v, "y");
	MatF m = matf_read(ctx, s);
	if (idx == 0) { m.a = vx; m.b = vy; }
	else if (idx == 1) { m.c = vx; m.d = vy; }
	else if (idx == 2) { m.tx = vx; m.ty = vy; }
	matf_write(ctx, s, m);
	return avm2_undefined();
}

// flash.geom.Vector3D minimal init (x,y,z,w dynamic props) so Matrix
// copyRow/copyColumnFrom read real components.
static Avm2Value geom_vector3d_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	static const char* const n[4] = { "x", "y", "z", "w" };
	for (int i = 0; i < 4; i++)
	{
		double v = (uint32_t) i < act->argc
			? avm2_coerce_to_number(ctx, act->args[i]) : 0.0;
		avm2_object_set_dynamic(ctx, self, n[i], (uint32_t) strlen(n[i]),
		                        avm2_number(v));
	}
	return avm2_undefined();
}

static Avm2Value geom_matrix_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	char buf[256];
	char nums[6][40];
	static const char* const names[6] = { "a", "b", "c", "d", "tx", "ty" };
	for (int i = 0; i < 6; i++)
	{
		avm2_format_number(nums[i], sizeof(nums[i]),
		                   matrix_get_prop(ctx, self, names[i]));
	}
	snprintf(buf, sizeof(buf), "(a=%s, b=%s, c=%s, d=%s, tx=%s, ty=%s)",
	         nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

static Avm2Object* make_geom_matrix(Avm2Context* ctx, double a, double b, double c,
                                    double d, double tx, double ty)
{
	Avm2Value args[6];
	args[0] = avm2_number(a);
	args[1] = avm2_number(b);
	args[2] = avm2_number(c);
	args[3] = avm2_number(d);
	args[4] = avm2_number(tx);
	args[5] = avm2_number(ty);
	Avm2Value v = avm2_class_construct(ctx, g_matrix_class, args, 6);
	return v.u.obj;
}

static Avm2Value transform_get_matrix(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL) return avm2_null();
	Avm2TransformExt* text = self->native_ext;
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, text->target);
	if (ext == NULL) return avm2_null();
	return avm2_object_value(make_geom_matrix(
		ctx, ext->mtx_a, ext->mtx_b, ext->mtx_c, ext->mtx_d,
		twips_to_pixels(ext->mtx_tx), twips_to_pixels(ext->mtx_ty)));
}

static Avm2Value transform_set_matrix(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL || act->argc < 1
	    || act->args[0].kind != AVM2_VALUE_OBJECT)
	{
		return avm2_undefined();
	}
	Avm2TransformExt* text = self->native_ext;
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, text->target);
	if (ext == NULL) return avm2_undefined();
	Avm2Object* m = act->args[0].u.obj;
	ext->mtx_a = (float) matrix_get_prop(ctx, m, "a");
	ext->mtx_b = (float) matrix_get_prop(ctx, m, "b");
	ext->mtx_c = (float) matrix_get_prop(ctx, m, "c");
	ext->mtx_d = (float) matrix_get_prop(ctx, m, "d");
	ext->mtx_tx = twips_from_pixels(matrix_get_prop(ctx, m, "tx"));
	ext->mtx_ty = twips_from_pixels(matrix_get_prop(ctx, m, "ty"));
	ext->scale_rot_cached = 0;
	return avm2_undefined();
}

static Avm2Class* g_colortransform_class;

static Avm2Value colortransform_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->slot_count < 9) return avm2_undefined();
	static const double defaults[8] = { 1, 1, 1, 1, 0, 0, 0, 0 };
	for (uint32_t i = 0; i < 8; i++)
	{
		double v = i < act->argc
			? avm2_coerce_to_number(ctx, act->args[i]) : defaults[i];
		self->slots[i + 1] = avm2_number(v);
	}
	return avm2_undefined();
}

static Avm2Value colortransform_to_string(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->slot_count < 9) return avm2_undefined();
	static const char* const names[8] = {
		"redMultiplier", "greenMultiplier", "blueMultiplier",
		"alphaMultiplier", "redOffset", "greenOffset", "blueOffset",
		"alphaOffset",
	};
	char buf[256];
	int off = 0;
	buf[off++] = '(';
	for (int i = 0; i < 8; i++)
	{
		char num[40];
		avm2_format_number(num, sizeof(num),
		                   avm2_coerce_to_number(act->ctx, self->slots[i + 1]));
		off += snprintf(buf + off, sizeof(buf) - (size_t) off, "%s%s=%s",
		                i > 0 ? ", " : "", names[i], num);
	}
	if (off < (int) sizeof(buf) - 1) buf[off++] = ')';
	buf[off] = '\0';
	return avm2_string(avm2_string_new(act->ctx, buf, (uint32_t) off));
}

static Avm2Value transform_get_color_transform(Avm2Activation* act)
{
	// Identity color transform (per-object color transforms are not
	// tracked in NO_GRAPHICS mode).
	return avm2_class_construct(act->ctx, g_colortransform_class, NULL, 0);
}

static Avm2Value transform_set_color_transform(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Mat display_world_matrix(Avm2Context* ctx, Avm2Object* obj);

static Avm2Value transform_get_concatenated_matrix(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL) return avm2_null();
	Avm2TransformExt* text = self->native_ext;
	if (text->target == NULL) return avm2_null();
	// On-stage children report the true world matrix; the stage itself and
	// off-stage objects mimic FP's bizarre quality-scaled local matrix
	// (Ruffle transform.rs; default quality High -> x5).
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, text->target);
	int on_stage = 0;
	for (Avm2Object* n = text->target; n != NULL; )
	{
		Avm2DisplayObjectExt* ne = avm2_display_ext_of(ctx, n);
		if (ne == NULL) break;
		if (ne->is_stage) { on_stage = 1; break; }
		n = ne->parent;
	}
	if (on_stage && ext != NULL && !ext->is_stage)
	{
		Mat m = display_world_matrix(ctx, text->target);
		return avm2_object_value(make_geom_matrix(
			ctx, m.a, m.b, m.c, m.d,
			twips_to_pixels((int32_t) m.tx), twips_to_pixels((int32_t) m.ty)));
	}
	double scale = 5.0;  // StageQuality::High
	return avm2_object_value(make_geom_matrix(
		ctx, (ext != NULL ? ext->mtx_a : 1) * scale,
		ext != NULL ? ext->mtx_b : 0, ext != NULL ? ext->mtx_c : 0,
		(ext != NULL ? ext->mtx_d : 1) * scale,
		ext != NULL ? twips_to_pixels(ext->mtx_tx) : 0,
		ext != NULL ? twips_to_pixels(ext->mtx_ty) : 0));
}

static Avm2Value transform_get_matrix3d(Avm2Activation* act)
{
	(void) act;
	return avm2_null();
}

static Avm2Value transform_set_stub(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

Avm2Value avm2_text_new_rectangle(Avm2Context* ctx, double x, double y,
                                  double w, double h);

static Avm2Value transform_get_pixel_bounds(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL) return avm2_null();
	Avm2TransformExt* text = self->native_ext;
	if (text->target == NULL) return avm2_null();
	// pixelBounds reads the RAW bounds — pending autosize bounds stay
	// pending (edittext_autosize_lazy_bounds_props).
	extern int avm2_text_lazy_suspend(Avm2Context* ctx, Avm2Object* obj);
	extern void avm2_text_lazy_restore(Avm2Context* ctx, Avm2Object* obj, int saved);
	int saved = avm2_text_lazy_suspend(ctx, text->target);
	Mat m = display_world_matrix(ctx, text->target);
	Rect r = { 0, 0, 0, 0, 0 };
	bounds_with_transform(ctx, text->target, &m, &r);
	avm2_text_lazy_restore(ctx, text->target, saved);
	if (!r.valid) return avm2_text_new_rectangle(ctx, 0, 0, 0, 0);
	return avm2_text_new_rectangle(ctx, r.xmin / 20.0, r.ymin / 20.0,
	                               (r.xmax - r.xmin) / 20.0,
	                               (r.ymax - r.ymin) / 20.0);
}

static Avm2Value do_get_transform(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* obj = this_obj(act);
	if (avm2_display_ext_of(ctx, obj) == NULL) return avm2_null();
	Avm2Value v = avm2_class_construct(ctx, g_transform_class, NULL, 0);
	((Avm2TransformExt*) v.u.obj->native_ext)->target = obj;
	return v;
}

static Avm2Value do_set_transform(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* obj = this_obj(act);
	if (act->argc < 1 || act->args[0].kind != AVM2_VALUE_OBJECT)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter transform must be non-null.");
	}
	// Pull the matrix off the assigned Transform (a Transform bound to
	// another object, per the AS3 pattern `a.transform = b.transform`).
	Avm2Value mval = avm2_get_public_property(ctx, act->args[0], "matrix", 6, NULL);
	if (mval.kind == AVM2_VALUE_OBJECT)
	{
		Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
		if (ext != NULL)
		{
			Avm2Object* m = mval.u.obj;
			ext->mtx_a = (float) matrix_get_prop(ctx, m, "a");
			ext->mtx_b = (float) matrix_get_prop(ctx, m, "b");
			ext->mtx_c = (float) matrix_get_prop(ctx, m, "c");
			ext->mtx_d = (float) matrix_get_prop(ctx, m, "d");
			ext->mtx_tx = twips_from_pixels(matrix_get_prop(ctx, m, "tx"));
			ext->mtx_ty = twips_from_pixels(matrix_get_prop(ctx, m, "ty"));
			ext->scale_rot_cached = 0;
		}
	}
	return avm2_undefined();
}

// --- generic stub props stored as dont_enum dyn props ---

static Avm2Value dyn_prop_get(Avm2Activation* act, const char* key, Avm2Value dflt)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL) return dflt;
	Avm2Value* v = avm2_object_find_dynamic(self, key, (uint32_t) strlen(key));
	return v != NULL ? *v : dflt;
}

static void dyn_prop_set(Avm2Activation* act, const char* key)
{
	Avm2Object* self = this_obj(act);
	if (self != NULL && act->argc > 0)
	{
		avm2_object_set_dynamic(act->ctx, self, key, (uint32_t) strlen(key),
		                        act->args[0])->dont_enum = 1;
	}
}

#define STUB_GETSET(fn, key, dflt) \
	static Avm2Value fn##_get(Avm2Activation* act) \
	{ return dyn_prop_get(act, key, dflt); } \
	static Avm2Value fn##_set(Avm2Activation* act) \
	{ dyn_prop_set(act, key); return avm2_undefined(); }

STUB_GETSET(do_cab, "__cacheAsBitmap", avm2_bool(false))
STUB_GETSET(do_opaquebg, "__opaqueBackground", avm2_null())
STUB_GETSET(do_scrollrect, "__scrollRect", avm2_null())
STUB_GETSET(do_accessprops, "__accessibilityProperties", avm2_null())
STUB_GETSET(io_needssoftkbd, "__needsSoftKeyboard", avm2_bool(false))

static Avm2Value io_request_soft_keyboard(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(false);
}
STUB_GETSET(io_softkbdarea, "__softKeyboardInputAreaOfInterest", avm2_null())
STUB_GETSET(do_accessimpl, "__accessibilityImplementation", avm2_null())
STUB_GETSET(do_contextmenu, "__contextMenu", avm2_null())
STUB_GETSET(do_blendmode, "__blendMode",
            avm2_string(avm2_string_from_literal(act->ctx, "normal")))

static Avm2Value do_get_zero(Avm2Activation* act)
{
	(void) act;
	return avm2_number(0);
}

static Avm2Value do_get_one(Avm2Activation* act)
{
	(void) act;
	return avm2_number(1);
}

static Avm2Value do_set_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

// ===========================================================================
// Natives: SimpleButton (Ruffle avm2_button.rs — states created eagerly at
// construct time, single-record states ARE the symbol, multi-record states
// wrap in an auto Sprite-classed clip)
// ===========================================================================

static const Avm2ButtonData* button_data_for_char(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_button_count; i++)
	{
		if (avm2_generated_buttons[i].char_id == char_id)
		{
			return &avm2_generated_buttons[i];
		}
	}
	return NULL;
}

static Avm2Object* button_create_state(Avm2Context* ctx, Avm2Object* button,
                                       uint8_t state_bit, int* out_multi)
{
	Avm2DisplayObjectExt* bext = avm2_display_ext_of(ctx, button);
	const Avm2ButtonData* bd = button_data_for_char(bext->char_id);
	*out_multi = 0;
	if (bd == NULL) return NULL;

	Avm2Object* children[32];
	const Avm2ButtonRecordData* recs[32];
	uint32_t n = 0;
	for (uint32_t i = 0; i < bd->record_count && n < 32; i++)
	{
		const Avm2ButtonRecordData* rec = &bd->records[i];
		if ((rec->state_flags & state_bit) == 0) continue;
		Avm2Class* cls = class_for_char(ctx, rec->char_id);
		if (cls == NULL) continue;
		g_timeline_instantiation = 1;
		Avm2Object* child = display_alloc_instance(ctx, cls);
		g_timeline_instantiation = 0;
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
		cext->char_id = rec->char_id;
		cext->timeline = timeline_for_char(rec->char_id);
		cext->instantiated_by_timeline = 1;
		cext->depth = rec->depth;
		if (rec->has_matrix)
		{
			cext->mtx_a = rec->mtx_a;
			cext->mtx_b = rec->mtx_b;
			cext->mtx_c = rec->mtx_c;
			cext->mtx_d = rec->mtx_d;
			cext->mtx_tx = rec->mtx_tx;
			cext->mtx_ty = rec->mtx_ty;
			cext->scale_rot_cached = 0;
		}
		{
			const Avm2CharInfo* ci = char_info(rec->char_id);
			if (ci != NULL && ci->kind == AVM2_CHAR_EDITTEXT)
			{
				avm2_text_seed_from_tag(ctx, child, rec->char_id);
			}
			else if (ci != NULL && ci->init_text != NULL)
			{
				cext->tf_text = avm2_string_from_literal(ctx, ci->init_text);
			}
		}
		children[n] = child;
		recs[n] = rec;
		n++;
	}
	(void) recs;
	if (n == 0) return NULL;
	if (n == 1)
	{
		Avm2Object* child = children[0];
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
		cext->parent = button;
		set_default_instance_name(ctx, cext);
		enter_frame_obj(ctx, child);
		construct_frame_obj(ctx, child);
		return child;
	}
	*out_multi = 1;
	// Wrapper: a MovieClip with the Sprite class (traces [object Sprite]),
	// never auto-named.
	g_timeline_instantiation = 1;
	Avm2Object* wrapper = display_alloc_instance(ctx, ctx->builtins.sprite_class);
	g_timeline_instantiation = 0;
	Avm2DisplayObjectExt* wext = avm2_display_ext_of(ctx, wrapper);
	wext->parent = button;
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, children[i]);
		replace_at_depth(ctx, wext, children[i], cext->depth);
		// Construction happens while parent is the BUTTON (a
		// non-container), so `parent` reads null from the ctor
		// (simplebutton_childprops); the wrapper becomes parent after.
		cext->parent = button;
		set_default_instance_name(ctx, cext);
		enter_frame_obj(ctx, children[i]);
		construct_frame_obj(ctx, children[i]);
		cext->parent = wrapper;
	}
	construct_frame_obj(ctx, wrapper);
	return wrapper;
}

static void button_construct_states(Avm2Context* ctx, Avm2Object* button)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, button);
	if (ext == NULL || ext->btn_states_created) return;
	ext->btn_states_created = 1;
	int up_multi, over_multi, down_multi, hit_multi;
	ext->btn_up = button_create_state(ctx, button, 0x01, &up_multi);
	ext->btn_over = button_create_state(ctx, button, 0x02, &over_multi);
	ext->btn_down = button_create_state(ctx, button, 0x04, &down_multi);
	ext->btn_hit = button_create_state(ctx, button, 0x08, &hit_multi);

	// Event quirks (Ruffle construct_frame): wrapper-state children fire
	// `added` with a temporarily-null parent; the UP state then fires
	// `added` on the real parent; addedToStage fires on the BUTTON
	// (recursively) when it is on stage.
	Avm2Object* states[4] = { ext->btn_up, ext->btn_over, ext->btn_down,
	                          ext->btn_hit };
	int multis[4] = { up_multi, over_multi, down_multi, hit_multi };
	for (int s = 0; s < 4; s++)
	{
		if (states[s] == NULL || !multis[s]) continue;
		Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, states[s]);
		// Ruffle fire_state_events: state.post_instantiation names the
		// wrapper AFTER all four states exist — it consumes a counter
		// number here, not at creation (simplebutton_symbolclass).
		set_default_instance_name(ctx, sext);
		Avm2Object* old_parent = sext->parent;
		sext->parent = NULL;
		for (uint32_t i = 0; i < sext->render_len; i++)
		{
			dispatch_simple_event(ctx, sext->render_list[i], "added", 1);
		}
		sext->parent = old_parent;
	}
	if (ext->btn_up != NULL)
	{
		dispatch_simple_event(ctx, ext->btn_up, "added", 1);
	}
	if (is_on_stage(ctx, button))
	{
		dispatch_added_to_stage_recursive(ctx, button);
	}

	// set_state(Up) (Ruffle): detach every state child, then parent only
	// the current (up) state — over/down/hit read parent=null/stage=null
	// afterwards (simplebutton_childevents frameConstructed traces).
	for (int s = 0; s < 4; s++)
	{
		if (states[s] == NULL) continue;
		Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, states[s]);
		if (sext != NULL) sext->parent = NULL;
	}
	if (ext->btn_up != NULL)
	{
		Avm2DisplayObjectExt* uext = avm2_display_ext_of(ctx, ext->btn_up);
		if (uext != NULL) uext->parent = button;
	}

	// A MovieClip in the up state (SWF>9) makes avmplus run a NESTED
	// construct/framescript/exit frame before the button's own ctor —
	// with the one-shot up/over/down/hit framescript order.
	int has_mc = 0;
	if (ext->btn_up != NULL)
	{
		Avm2DisplayObjectExt* uext = avm2_display_ext_of(ctx, ext->btn_up);
		if (up_multi && uext != NULL)
		{
			for (uint32_t i = 0; i < uext->render_len; i++)
			{
				if (class_is_a(uext->render_list[i]->cls,
				               ctx->builtins.movieclip_class))
				{
					has_mc = 1;
				}
			}
		}
		else if (class_is_a(ext->btn_up->cls, ctx->builtins.movieclip_class))
		{
			has_mc = 1;
		}
	}
	if (has_mc && ctx->swf_version > 9 && ctx->stage != NULL)
	{
		ext->btn_weird_order = 1;
		uint8_t old_phase = ctx->frame_phase;
		Avm2DisplayObjectExt* stext = avm2_display_ext_of(ctx, ctx->stage);
		ctx->frame_phase = PHASE_CONSTRUCT;
		for (uint32_t i = 0; i < stext->render_len; i++)
		{
			construct_frame_obj(ctx, stext->render_list[i]);
		}
		broadcast_named(ctx, "frameConstructed");
		ctx->frame_phase = PHASE_FRAME_SCRIPTS;
		for (uint32_t i = 0; i < stext->render_len; i++)
		{
			run_frame_scripts_obj(ctx, stext->render_list[i]);
		}
		run_frame_script_cleanup(ctx);
		ctx->frame_phase = PHASE_EXIT;
		broadcast_named(ctx, "exitFrame");
		ctx->frame_phase = old_phase;
	}
}

static Avm2Value btn_state_get(Avm2Activation* act, size_t off)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_null();
	Avm2Object* s = *(Avm2Object**) ((char*) ext + off);
	return s != NULL ? avm2_object_value(s) : avm2_null();
}

static Avm2Value btn_state_set(Avm2Activation* act, size_t off)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* button = this_obj(act);
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	Avm2Object* v = (act->argc > 0 && act->args[0].kind == AVM2_VALUE_OBJECT)
		? act->args[0].u.obj : NULL;
	Avm2Object* old = *(Avm2Object**) ((char*) ext + off);
	int child_was_on_stage = (v != NULL) && is_on_stage(ctx, v);
	// The rendered state is always Up in trace tests (no mouse input).
	int is_cur_state = (off == offsetof(Avm2DisplayObjectExt, btn_up));
	*(Avm2Object**) ((char*) ext + off) = v;

	// Ruffle set_state_child: the new child is pulled out of its current
	// container (simplebutton_childshuffle: numChildren drops, parent
	// reads null through the non-container button).
	if (v != NULL)
	{
		Avm2DisplayObjectExt* vext = avm2_display_ext_of(ctx, v);
		if (vext != NULL && vext->parent != NULL)
		{
			Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, vext->parent);
			if (pext != NULL && render_index_of(pext, v) >= 0)
			{
				vext->placed_by_avm2_script = 1;
				full_remove_child(ctx, pext, v);
			}
			vext->parent = NULL;
		}
		if (is_cur_state && vext != NULL)
		{
			vext->parent = button;
		}
	}
	if (old != NULL && old != v)
	{
		Avm2DisplayObjectExt* oext = avm2_display_ext_of(ctx, old);
		if (oext != NULL) oext->parent = NULL;
	}
	if (is_cur_state)
	{
		if (v != NULL)
		{
			dispatch_added_event(ctx, button, v, child_was_on_stage);
		}
		if (old != NULL && old != v)
		{
			dispatch_removed_event(ctx, old);
		}
		if (v != NULL)
		{
			// Ruffle set_state_child's trailing broadcasts (the "FIXME"
			// block): frameConstructed, the child's frame scripts, then
			// exitFrame (simplebutton_constr_childevents).
			broadcast_named(ctx, "frameConstructed");
			run_frame_scripts_obj(ctx, v);
			broadcast_named(ctx, "exitFrame");
		}
	}
	return avm2_undefined();
}

#define BTN_STATE(name, field) \
	static Avm2Value btn_get_##name(Avm2Activation* act) \
	{ return btn_state_get(act, offsetof(Avm2DisplayObjectExt, field)); } \
	static Avm2Value btn_set_##name(Avm2Activation* act) \
	{ return btn_state_set(act, offsetof(Avm2DisplayObjectExt, field)); }

BTN_STATE(up, btn_up)
BTN_STATE(over, btn_over)
BTN_STATE(down, btn_down)
BTN_STATE(hit, btn_hit)

STUB_GETSET(btn_enabled, "__enabled", avm2_bool(true))
STUB_GETSET(btn_handcursor, "__useHandCursor", avm2_bool(true))
STUB_GETSET(btn_trackasmenu, "__trackAsMenu", avm2_bool(false))

// SimpleButton(upState, overState, downState, hitTestState) constructor.
static Avm2Value simplebutton_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	button_construct_states(ctx, this_obj(act));
	static const size_t offs[4] = {
		offsetof(Avm2DisplayObjectExt, btn_up),
		offsetof(Avm2DisplayObjectExt, btn_over),
		offsetof(Avm2DisplayObjectExt, btn_down),
		offsetof(Avm2DisplayObjectExt, btn_hit),
	};
	for (uint32_t i = 0; i < 4 && i < act->argc; i++)
	{
		if (act->args[i].kind == AVM2_VALUE_OBJECT)
		{
			*(Avm2Object**) ((char*) ext + offs[i]) = act->args[i].u.obj;
		}
	}
	return avm2_undefined();
}

// ===========================================================================
// Natives: FrameLabel / Scene (state = dont_enum dyn props)
// ===========================================================================

static Avm2Value framelabel_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	Avm2Value name = act->argc > 0 ? act->args[0] : avm2_null();
	Avm2Value frame = act->argc > 1 ? act->args[1] : avm2_integer(0);
	avm2_object_set_dynamic(ctx, self, "__name", 6, name)->dont_enum = 1;
	avm2_object_set_dynamic(ctx, self, "__frame", 7, frame)->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value framelabel_get_name(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2Value* v = self != NULL ? avm2_object_find_dynamic(self, "__name", 6) : NULL;
	return v != NULL ? *v : avm2_null();
}

static Avm2Value framelabel_get_frame(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2Value* v = self != NULL ? avm2_object_find_dynamic(self, "__frame", 7) : NULL;
	return v != NULL ? *v : avm2_integer(0);
}

static Avm2Value scene_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	Avm2Value name = act->argc > 0 ? act->args[0] : avm2_null();
	Avm2Value labels = act->argc > 1 ? act->args[1] : avm2_null();
	Avm2Value num = act->argc > 2 ? act->args[2] : avm2_integer(0);
	avm2_object_set_dynamic(ctx, self, "__name", 6, name)->dont_enum = 1;
	avm2_object_set_dynamic(ctx, self, "__labels", 8, labels)->dont_enum = 1;
	avm2_object_set_dynamic(ctx, self, "__numFrames", 11, num)->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value scene_get_name(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2Value* v = self != NULL ? avm2_object_find_dynamic(self, "__name", 6) : NULL;
	return v != NULL ? *v : avm2_null();
}

static Avm2Value scene_get_labels(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2Value* v = self != NULL ? avm2_object_find_dynamic(self, "__labels", 8) : NULL;
	return v != NULL ? *v : avm2_null();
}

static Avm2Value scene_get_num_frames(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2Value* v = self != NULL ? avm2_object_find_dynamic(self, "__numFrames", 11) : NULL;
	return v != NULL ? *v : avm2_integer(0);
}

// ===========================================================================
// Natives: Stage
// ===========================================================================

static double g_stage_frame_rate;
static uint32_t g_stage_color;
static uint8_t g_stage_focus_rect = 1;

static Avm2Value stage_get_frame_rate(Avm2Activation* act)
{
	(void) act;
	double fr = g_stage_frame_rate;
	if (fr < 0.0)
	{
		fr = fmod(fr, 256.0);
		if (fr < 0.0) fr += 256.0;
	}
	return avm2_number(fr);
}

static Avm2Value stage_set_frame_rate(Avm2Activation* act)
{
	if (act->argc > 0)
	{
		double v = avm2_coerce_to_number(act->ctx, act->args[0]);
		// clamp(0.01, 1000.0); NaN propagates (Rust f64::clamp).
		if (!isnan(v))
		{
			if (v < 0.01) v = 0.01;
			if (v > 1000.0) v = 1000.0;
		}
		g_stage_frame_rate = v;
	}
	return avm2_undefined();
}

static Avm2Value stage_get_color(Avm2Activation* act)
{
	(void) act;
	return avm2_number((double) (0xFF000000u | g_stage_color));
}

static Avm2Value stage_set_color(Avm2Activation* act)
{
	if (act->argc > 0)
	{
		g_stage_color = avm2_coerce_to_u32(act->ctx, act->args[0]) & 0xFFFFFF;
	}
	return avm2_undefined();
}

static Avm2Value stage_get_stage_width(Avm2Activation* act)
{
	(void) act;
	return avm2_integer((avm2_generated_stage_rect[1] - avm2_generated_stage_rect[0]) / 20);
}

static Avm2Value stage_get_stage_height(Avm2Activation* act)
{
	(void) act;
	return avm2_integer((avm2_generated_stage_rect[3] - avm2_generated_stage_rect[2]) / 20);
}

static Avm2Value stage_set_dimension_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Avm2Value stage_get_allows_fullscreen(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(true);
}

static Avm2Value stage_get_allows_fullscreen_interactive(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(false);
}

static Avm2Value stage_get_browser_zoom_factor(Avm2Activation* act)
{
	(void) act;
	return avm2_number(1);
}

static Avm2Value stage_get_contents_scale_factor(Avm2Activation* act)
{
	(void) act;
	return avm2_number(1);
}

static Avm2Value stage_get_display_state(Avm2Activation* act)
{
	return avm2_string(avm2_string_from_literal(act->ctx, "normal"));
}

static Avm2Value stage_get_quality(Avm2Activation* act)
{
	return avm2_string(avm2_string_from_literal(act->ctx, "HIGH"));
}

static Avm2Value stage_set_quality(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Avm2Value stage_get_stage_focus_rect(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(g_stage_focus_rect != 0);
}

static Avm2Value stage_set_stage_focus_rect(Avm2Activation* act)
{
	if (act->argc > 0)
	{
		g_stage_focus_rect = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	}
	return avm2_undefined();
}

static Avm2Value stage_get_align(Avm2Activation* act)
{
	return avm2_string(avm2_string_from_literal(act->ctx, ""));
}

static Avm2Value stage_set_align(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Avm2Value stage_get_scale_mode(Avm2Activation* act)
{
	return avm2_string(avm2_string_from_literal(act->ctx, "showAll"));
}

static Avm2Value stage_set_scale_mode(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Avm2Value stage_get_focus(Avm2Activation* act)
{
	(void) act;
	return g_stage_focus != NULL ? avm2_object_value(g_stage_focus)
	                             : avm2_null();
}

static Avm2Value stage_set_focus(Avm2Activation* act)
{
	if (act->argc > 0 && act->args[0].kind == AVM2_VALUE_OBJECT
	    && act->args[0].u.obj != NULL
	    && avm2_display_ext_of(act->ctx, act->args[0].u.obj) != NULL)
	{
		// Focusing a TextField applies its pending autosize bounds — even when
		// re-focusing the already-focused object (edittext_autosize_lazy_bounds_
		// interactions relies on this). set_focus then fires focusOut/focusIn
		// only if the focus actually changes.
		avm2_text_apply_pending_bounds(act->ctx, act->args[0].u.obj);
		set_focus(act->ctx, act->args[0].u.obj);
	}
	else
	{
		set_focus(act->ctx, NULL);
	}
	return avm2_undefined();
}


static Avm2Value stage_invalidate(Avm2Activation* act)
{
	(void) act;
	g_stage_invalidated_flag = 1;
	return avm2_undefined();
}

// Stage overrides most DisplayObject setters to throw (plain Error).
static Avm2Value stage_throw_2071(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	avm2_throw_error(ctx, ctx->builtins.error_class,
	                 "Error #2071: The Stage class does not implement this property or method.");
}


// ===========================================================================
// Constructors (instance_init natives)
// ===========================================================================

// Alloc-time defaults for every display object.
static void display_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = obj->native_ext;
	ext->visible = 1;
	ext->mtx_a = 1;
	ext->mtx_d = 1;
	ext->scale_rot_cached = 1;
	ext->scale_x = 1;
	ext->scale_y = 1;
	ext->alpha_fixed8 = 256;
	ext->mouse_enabled = 1;
	ext->mouse_children = 1;
	ext->tab_children = 1;
	ext->use_hand_cursor = 1;
	ext->playing = 1;
	ext->queued_goto_frame = -1;
	ext->last_queued_script_frame = -1;
	ext->tab_index = -1;

	// TextFields carry the EditText engine state (avm2_text.c). Timeline
	// instantiation re-seeds it from the DefineEditText tag afterwards.
	if (g_textfield_class != NULL && class_is_a(obj->cls, g_textfield_class))
	{
		avm2_text_edittext_init(ctx, obj);
	}

	if (!g_timeline_instantiation)
	{
		// Script-created (Ruffle initialize_for_allocator): mark
		// script-placed, attach the symbol timeline for SymbolClass-bound
		// classes, auto-name, run the enter/construct catchup (with the
		// load-frame child-recursion gate), skip the first enterFrame.
		ext->placed_by_avm2_script = 1;
		ext->constructed = 1;
		uint16_t char_id = char_for_class(obj->cls);
		if (char_id != 0)
		{
			ext->char_id = char_id;
			ext->timeline = timeline_for_char(char_id);
		}
		// Ruffle new_with_avm2 does NOT set PLAYING (new_with_data does):
		// a plain `new MovieClip()` never advances past frame 0.
		ext->playing = (ext->timeline != NULL) ? 1 : 0;
		set_default_instance_name(ctx, ext);
		orphan_add(ctx, obj);
		enter_frame_obj(ctx, obj);
		construct_frame_obj(ctx, obj);
		ext->skip_next_enter_frame = 1;
		// on_construction_complete's non-event half (the events are
		// skipped for script-placed objects): initialized + the
		// Sprite-typed-symbol auto-stop.
		if (ext->timeline != NULL && !ext->is_root
		    && !class_is_a(obj->cls, ctx->builtins.movieclip_class))
		{
			ext->playing = 0;
		}
		ext->initialized = 1;
	}
}

// Abstract display classes (DisplayObject/InteractiveObject/
// DisplayObjectContainer) throw at ALLOCATION time — before any
// constructor body runs (displayobject_subclass traces prove the subclass
// ctor is never reached). Concrete descendants override this hook back to
// display_native_init.
static void display_native_init_abstract(Avm2Context* ctx, Avm2Object* obj)
{
	const char* name = "?";
	uint32_t name_len = 1;
	if (obj->cls != NULL)
	{
		name = obj->cls->name.name;
		name_len = obj->cls->name.name_len;
	}
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2012: %.*s$ class cannot be instantiated.",
	                 (int) name_len, name);
}

// Sprite constructor body (runs at super() time): constructChildren
// (Ruffle sprite.rs construct_children) — construct_frame on each child,
// so timeline children placed before the ctor get their constructors
// (and their own children recurse) here.
static Avm2Value sprite_ctor_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	ext->running_construct_frame = 1;
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		construct_frame_obj(ctx, ext->render_list[i]);
	}
	ext->running_construct_frame = 0;
	return avm2_undefined();
}

// ===========================================================================
// Registration
// ===========================================================================

static void add_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                       Avm2MethodFn getter, Avm2MethodFn setter)
{
	// Replace an inherited accessor in place (lookup returns the FIRST
	// match, so appending never shadows) — the Stage overrides depend on
	// this.
	uint32_t name_len = (uint32_t) strlen(name);
	for (uint32_t i = 0; i < cls->ivtable.count; i++)
	{
		Avm2PropEntry* e = &cls->ivtable.entries[i];
		if (e->key.name_len == name_len && e->key.ns_len == 0
		    && memcmp(e->key.name, name, name_len) == 0
		    && (e->kind == AVM2_PROP_GETTER || e->kind == AVM2_PROP_SETTER
		        || e->kind == AVM2_PROP_GETSET))
		{
			e->kind = (setter != NULL) ? AVM2_PROP_GETSET : AVM2_PROP_GETTER;
			e->method.fn = getter;
			e->method.debug_name = name;
			e->setter.fn = setter;
			e->setter.debug_name = name;
			e->defining_class = cls;
			return;
		}
	}
	avm2_builtin_add_getset(ctx, cls, name, getter, setter);
}

// ===========================================================================
// Stage 8: input harness + input->event bridge
//
// Parses the line-based input_events.txt (verify_output.py::preprocess_input_json)
// and drives the AVM2 mouse/keyboard/focus dispatch, mirroring Ruffle's
// player.rs::update_mouse_state + interactive.rs::event_dispatch_to_avm2. Events
// are pumped once per tick (at the tail of avm2_display_run_tick), one WAIT
// group per tick — the same cadence swf_core.c uses for AVM1.
// ===========================================================================

typedef enum
{
	IN_WAIT, IN_MOUSE_MOVE, IN_MOUSE_DOWN, IN_MOUSE_UP, IN_MOUSE_WHEEL,
	IN_KEY_DOWN, IN_KEY_UP, IN_TEXT_INPUT, IN_TEXT_CONTROL,
	IN_FOCUS_GAINED, IN_FOCUS_LOST, IN_SET_CLIPBOARD, IN_IME_PREEDIT,
	IN_IME_COMMIT
} Avm2InputKind;

typedef struct
{
	Avm2InputKind kind;
	float x, y;       // mouse stage pixels
	int32_t code;     // key code / text codepoint / wheel delta
	int32_t code2;    // key charCode
	int32_t code3;    // key keyLocation
	int button;       // 0 left, 1 middle, 2 right
	char text[1024];
	char ctrl[32];
} Avm2InputEvent;

static Avm2InputEvent* g_in_events;
static size_t g_in_count, g_in_pos;

// Live browser key injection (Stage 13c). The g_in_events queue above is the
// harness feed (load-once from a file, WAIT-paced). Live browser key events
// arrive asynchronously via the emscripten keydown/keyup callbacks in
// render_webgpu.c (which fire while the main loop is parked in
// emscripten_sleep) — buffer them in a ring drained by avm2_input_pump_tick at
// the same per-tick cadence. Single-threaded: the callback (during sleep) and
// the pump (during the tick) never interleave, so plain indices are safe.
#define AVM2_LIVE_IN_CAP 512
static Avm2InputEvent g_live_in[AVM2_LIVE_IN_CAP];
static size_t g_live_in_head, g_live_in_tail;   // ring: [head, tail)

// Mouse/keyboard state (Ruffle context.input + mouse_data).
static double g_mouse_x, g_mouse_y;       // stage pixels
static uint8_t g_mouse_btn_down[3];       // left/middle/right
static uint8_t g_key_down_map[256];       // modifier tracking by Flash keyCode
static Avm2Object* g_mouse_hovered;       // interactive object under mouse
static Avm2Object* g_mouse_pressed[3];    // per-button press target
static uint32_t g_left_click_index;       // increments per left press (dbl-click)
static const char* g_clipboard_text;      // SetClipboardText

// --- GC roots + tracing (Stage 11) ------------------------------------------

// avm2_text.c helper: mark the collectable object edges inside an EditText ext
// (currently the attached StyleSheet object). Declared here because the ext is
// opaque to this TU.
void avm2_text_gc_mark_edittext(struct Avm2EditTextExt* et);

// Drag state (defined further down, near update_drag) — tentative decls so the
// root marker below can reference the in-flight drag object + drop target.
static Avm2Object* g_drag_object;
static Avm2Object* g_drag_drop_target;

// Root marker: display-module C-static Avm2Object/Avm2Value stashes that are
// not reachable through the stage/root tree — orphan clips (auto-advance with
// no parent), pending frame-script cleanup, stage focus, the mouse
// hover/press targets, the in-flight drag object + drop target, and the timer
// table (AS3 Timer instances + setTimeout/setInterval callback closures and
// their bound args).
void avm2_gc_mark_roots_display(Avm2Context* ctx)
{
	(void) ctx;
	// The orphan registry is deliberately NOT marked: it holds WEAK references
	// (Ruffle's OrphanManager stores DisplayObjectWeak). A constructed-but-
	// never-parented display object — e.g. a per-frame `new TextField()` drawn
	// into a BitmapData and dropped — must die once nothing else references
	// it; a strong root here retains every such object forever (measured:
	// Seedling idle leaked exactly 2 TextFields + 6 strings per tick). Dead
	// entries are pruned post-mark via avm2_display_gc_prune_dead_orphans().
	for (uint32_t i = 0; i < g_fs_cleanup_count; i++) avm2_gc_mark_object(g_fs_cleanup[i]);
	avm2_gc_mark_object(g_stage_focus);
	avm2_gc_mark_object(g_root_loader_info);
	avm2_gc_mark_object(g_mouse_hovered);
	for (int i = 0; i < 3; i++) avm2_gc_mark_object(g_mouse_pressed[i]);
	avm2_gc_mark_object(g_drag_object);
	avm2_gc_mark_object(g_drag_drop_target);
	for (uint32_t i = 0; i < g_avm2_timer_count; i++)
	{
		Avm2TimerEntry* t = &g_avm2_timers[i];
		avm2_gc_mark_object(t->timer_obj);
		avm2_gc_mark_value(t->fn);
		for (uint32_t a = 0; a < t->argc; a++) avm2_gc_mark_value(t->args[a]);
	}
	// C-static string stashes owned by this module: the Timer event-type
	// singletons and Mouse.cursor (a user-supplied heap string, re-settable).
	avm2_gc_mark_string(g_str_timer);
	avm2_gc_mark_string(g_str_timer_complete);
	avm2_gc_mark_string(g_mouse_cursor);
}

// Post-mark, pre-sweep hook (avm2_gc.c gc_collect): drop orphan entries whose
// object went unmarked this cycle — the sweep is about to free them. This is
// what makes the registry weak; skipping it would leave dangling entries. Only
// called when the mark phase completed (never after a worklist OOM, where
// unmarked does not mean unreachable).
void avm2_display_gc_prune_dead_orphans(void)
{
	uint32_t w = 0;
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		if (avm2_gc_is_marked(g_orphans[i])) g_orphans[w++] = g_orphans[i];
	}
	g_orphan_count = w;
}

// Ext tracer: a DisplayObject's ext holds indirect object edges the
// conservative blob scan cannot reach — the render/depth child lists
// (separately-allocated arrays), the frame-script closures, and the EditText
// StyleSheet. Direct-in-blob fields (parent/mask/graphics/btn_*/bitmap_data/
// meta/accessibility) are left to the conservative scan.
void avm2_display_gc_trace_ext(Avm2Object* o)
{
	Avm2Context* ctx = avm2_get_context();
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, o);
	if (ext == NULL) return;
	for (uint32_t i = 0; i < ext->render_len; i++) avm2_gc_mark_object(ext->render_list[i]);
	for (uint32_t i = 0; i < ext->depth_len; i++) avm2_gc_mark_object(ext->depth_list[i].child);
	for (uint32_t i = 0; i < ext->frame_script_cap; i++) avm2_gc_mark_value(ext->frame_scripts[i]);
	if (ext->edittext != NULL) avm2_text_gc_mark_edittext(ext->edittext);
}

// GC free hook: a swept DisplayObject's ext owns separately-allocated arrays
// (the render/depth child lists, the frame-script table, the per-frame queued
// place ops) — free them so reclaiming the object doesn't leak its backing
// arrays. All avm2_alloc'd + per-object. (The attached EditText ext is freed by
// avm2_text_gc_free_ext.)
void avm2_display_gc_free_ext(Avm2Context* ctx, Avm2Object* o)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, o);
	if (ext == NULL) return;
	if (ext->render_list != NULL) heap_free(ctx->app, ext->render_list);
	if (ext->depth_list != NULL) heap_free(ctx->app, ext->depth_list);
	if (ext->frame_scripts != NULL) heap_free(ctx->app, ext->frame_scripts);
	if (ext->queued_places != NULL) heap_free(ctx->app, ext->queued_places);
}

void avm2_input_load(const char* path)
{
	FILE* f = fopen(path, "r");
	if (f == NULL) return;
	char line[2048];
	size_t count = 0;
	while (fgets(line, sizeof(line), f)) count++;
	rewind(f);
	g_in_events = malloc((count + 1) * sizeof(Avm2InputEvent));
	if (g_in_events == NULL) { fclose(f); return; }
	g_in_count = 0;
	while (fgets(line, sizeof(line), f))
	{
		Avm2InputEvent ev;
		memset(&ev, 0, sizeof(ev));
		if (strncmp(line, "WAIT", 4) == 0)
			ev.kind = IN_WAIT;
		else if (strncmp(line, "MOUSE_MOVE ", 11) == 0)
			{ sscanf(line + 11, "%f %f", &ev.x, &ev.y); ev.kind = IN_MOUSE_MOVE; }
		else if (strncmp(line, "MOUSE_DOWN_LEFT ", 16) == 0)
			{ sscanf(line + 16, "%f %f %d", &ev.x, &ev.y, &ev.code); ev.kind = IN_MOUSE_DOWN; ev.button = 0; }
		else if (strncmp(line, "MOUSE_UP_LEFT ", 14) == 0)
			{ sscanf(line + 14, "%f %f", &ev.x, &ev.y); ev.kind = IN_MOUSE_UP; ev.button = 0; }
		else if (strncmp(line, "MOUSE_DOWN_MIDDLE ", 18) == 0)
			{ sscanf(line + 18, "%f %f", &ev.x, &ev.y); ev.kind = IN_MOUSE_DOWN; ev.button = 1; }
		else if (strncmp(line, "MOUSE_UP_MIDDLE ", 16) == 0)
			{ sscanf(line + 16, "%f %f", &ev.x, &ev.y); ev.kind = IN_MOUSE_UP; ev.button = 1; }
		else if (strncmp(line, "MOUSE_DOWN_RIGHT ", 17) == 0)
			{ sscanf(line + 17, "%f %f", &ev.x, &ev.y); ev.kind = IN_MOUSE_DOWN; ev.button = 2; }
		else if (strncmp(line, "MOUSE_UP_RIGHT ", 15) == 0)
			{ sscanf(line + 15, "%f %f", &ev.x, &ev.y); ev.kind = IN_MOUSE_UP; ev.button = 2; }
		else if (strncmp(line, "MOUSE_WHEEL ", 12) == 0)
			{ sscanf(line + 12, "%d", &ev.code); ev.kind = IN_MOUSE_WHEEL; }
		else if (strncmp(line, "KEY_DOWN ", 9) == 0)
			{ sscanf(line + 9, "%d %d %d", &ev.code, &ev.code2, &ev.code3); ev.kind = IN_KEY_DOWN; }
		else if (strncmp(line, "KEY_UP ", 7) == 0)
			{ sscanf(line + 7, "%d %d %d", &ev.code, &ev.code2, &ev.code3); ev.kind = IN_KEY_UP; }
		else if (strncmp(line, "TEXT_INPUT ", 11) == 0)
			{ sscanf(line + 11, "%d", &ev.code); ev.kind = IN_TEXT_INPUT; }
		else if (strncmp(line, "TEXT_CONTROL ", 13) == 0)
			{ sscanf(line + 13, "%31s", ev.ctrl); ev.kind = IN_TEXT_CONTROL; }
		else if (strncmp(line, "FOCUSGAINED", 11) == 0)
			ev.kind = IN_FOCUS_GAINED;
		else if (strncmp(line, "FOCUSLOST", 9) == 0)
			ev.kind = IN_FOCUS_LOST;
		else if (strncmp(line, "SET_CLIPBOARD_TEXT", 18) == 0)
		{
			ev.kind = IN_SET_CLIPBOARD;
			if (line[18] == ' ')
			{
				// Strip the trailing file newline first, then unescape
				// \\ / \n / \r (the harness escapes embedded newlines).
				char raw[1024];
				strncpy(raw, line + 19, sizeof(raw) - 1);
				raw[sizeof(raw) - 1] = '\0';
				size_t rl = strlen(raw);
				while (rl > 0 && (raw[rl-1] == '\n' || raw[rl-1] == '\r'))
					raw[--rl] = '\0';
				size_t o = 0;
				for (size_t i = 0; i < rl && o < sizeof(ev.text) - 1; i++)
				{
					if (raw[i] == '\\' && i + 1 < rl)
					{
						char n = raw[++i];
						ev.text[o++] = (n == 'n') ? '\n' : (n == 'r') ? '\r' : n;
					}
					else ev.text[o++] = raw[i];
				}
				ev.text[o] = '\0';
			}
		}
		else
			continue;
		g_in_events[g_in_count++] = ev;
	}
	fclose(f);
}

static int mod_shift(void) { return g_key_down_map[16] != 0; }
static int mod_ctrl(void)  { return g_key_down_map[17] != 0; }
static int mod_alt(void)   { return g_key_down_map[18] != 0; }

static int is_interactive(Avm2Context* ctx, Avm2Object* obj)
{
	return obj != NULL && obj->cls != NULL
	       && class_is_a(obj->cls, ctx->builtins.interactive_object_class);
}

// Self bounds including flash.display.Bitmap dims (mirror bounds_with_transform).
static Rect self_bounds_full(Avm2Context* ctx, Avm2Object* obj,
                             Avm2DisplayObjectExt* ext)
{
	Rect self = display_self_bounds(ext);
	if (!self.valid && ext->is_bitmap)
	{
		uint32_t bw = 0, bh = 0;
		if (avm2_bitmap_self_dims(ctx, obj, &bw, &bh))
		{
			self.valid = 1;
			self.xmin = 0;
			self.xmax = (double) bw * 20.0;
			self.ymin = 0;
			self.ymax = (double) bh * 20.0;
		}
	}
	return self;
}

// Does obj's OWN shape (self bounds) contain the stage point (twips)? Maps the
// point into obj's local space so rotation/scale are honored (AABB hit test).
static int point_in_self(Avm2Context* ctx, Avm2Object* obj, double px, double py)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return 0;
	Rect self = self_bounds_full(ctx, obj, ext);
	if (!self.valid) return 0;
	Mat m = display_world_matrix(ctx, obj);
	Mat inv = mat_invert(&m);
	double lx = inv.a * px + inv.c * py + inv.tx;
	double ly = inv.b * px + inv.d * py + inv.ty;
	return lx >= self.xmin && lx <= self.xmax && ly >= self.ymin && ly <= self.ymax;
}

typedef enum { PK_MISS, PK_PROP, PK_HIT } PkKind;
typedef struct { PkKind kind; Avm2Object* target; } Pk;

static Pk pk_make(PkKind k, Avm2Object* t) { Pk p; p.kind = k; p.target = t; return p; }

// Ruffle Avm2MousePick::combine_with_parent.
static Pk pk_combine(Avm2Context* ctx, Pk p, Avm2Object* parent)
{
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	int pme = pext == NULL || pext->mouse_enabled;
	int pmc = pext == NULL || pext->mouse_children;
	switch (p.kind)
	{
	case PK_HIT:
		if (pmc) return p;
		return pme ? pk_make(PK_HIT, parent) : pk_make(PK_PROP, NULL);
	case PK_PROP:
		return pme ? pk_make(PK_HIT, parent) : pk_make(PK_PROP, NULL);
	default:
		return pk_make(PK_MISS, NULL);
	}
}

// Ruffle movie_clip.rs::mouse_pick_avm2 (AABB approximation; no masks/clip
// layers). point in twips.
static Pk mouse_pick(Avm2Context* ctx, Avm2Object* obj, double px, double py)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return pk_make(PK_MISS, NULL);
	if (!ext->is_stage && !ext->visible) return pk_make(PK_MISS, NULL);

	// TextField (Ruffle edit_text.rs::mouse_pick_avm2): a hovered selectable OR
	// non-static field hits; a static non-selectable field propagates to the
	// parent (which may absorb it).
	if (ext->edittext != NULL)
	{
		if (point_in_self(ctx, obj, px, py))
		{
			int selectable = avm2_text_is_selectable(ext->edittext);
			int was_static = avm2_text_was_static(ext->edittext);
			if (ext->mouse_enabled && (selectable || !was_static))
				return pk_make(PK_HIT, obj);
			return pk_make(PK_PROP, NULL);
		}
		return pk_make(PK_MISS, NULL);
	}

	Pk found_prop = pk_make(PK_MISS, NULL);
	// Interactive children first (pass 0), then non-interactive (pass 1); each
	// group top-down (reverse render order).
	for (int pass = 0; pass < 2; pass++)
	{
		for (int32_t i = (int32_t) ext->render_len - 1; i >= 0; i--)
		{
			Avm2Object* child = ext->render_list[i];
			int ci = is_interactive(ctx, child);
			if (pass == 0 && !ci) continue;
			if (pass == 1 && ci) continue;
			Pk res;
			if (ci)
			{
				res = mouse_pick(ctx, child, px, py);
			}
			else
			{
				Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
				if (cext != NULL && cext->visible && point_in_self(ctx, child, px, py))
					res = ext->mouse_enabled ? pk_make(PK_HIT, obj)
					                         : pk_make(PK_PROP, NULL);
				else
					res = pk_make(PK_MISS, NULL);
			}
			if (res.kind == PK_HIT) return pk_combine(ctx, res, obj);
			if (res.kind == PK_PROP) found_prop = res;
		}
	}
	if (found_prop.kind != PK_MISS) return pk_combine(ctx, found_prop, obj);

	// Self drawing / shape.
	if (point_in_self(ctx, obj, px, py))
		return ext->mouse_enabled ? pk_make(PK_HIT, obj) : pk_make(PK_PROP, NULL);
	return pk_make(PK_MISS, NULL);
}

// Ruffle player.rs::run_mouse_pick. Returns the interactive target under the
// mouse, or NULL (stage / miss).
static Avm2Object* run_mouse_pick(Avm2Context* ctx)
{
	Avm2Object* stage = ctx->stage;
	Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, stage);
	if (sext == NULL) return NULL;
	double px = g_mouse_x * 20.0, py = g_mouse_y * 20.0;
	for (int32_t i = (int32_t) sext->render_len - 1; i >= 0; i--)
	{
		Avm2Object* level = sext->render_list[i];
		if (!is_interactive(ctx, level)) continue;
		Pk pick = mouse_pick(ctx, level, px, py);
		pick = pk_combine(ctx, pick, stage);
		if (pick.kind == PK_HIT)
		{
			if (pick.target == stage) return NULL;
			return pick.target;
		}
	}
	return NULL;
}

// --- Drag (Sprite.startDrag / stopDrag / dropTarget; Ruffle update_drag) ---
static Avm2Object* g_drag_object;
static int g_drag_lock_center;
static double g_drag_last_mx, g_drag_last_my;  // stage px
static int g_drag_has_constraint;
static double g_drag_cx0, g_drag_cy0, g_drag_cx1, g_drag_cy1;  // twips
static Avm2Object* g_drag_drop_target;

static void update_drag(Avm2Context* ctx)
{
	if (g_drag_object == NULL) return;
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, g_drag_object);
	if (ext == NULL) return;
	Avm2Object* parent = ext->parent;
	Mat l2g = parent != NULL ? display_world_matrix(ctx, parent) : mat_identity();
	Mat g2l = mat_invert(&l2g);
	double mx = g_mouse_x * 20.0, my = g_mouse_y * 20.0;
	double nx, ny;
	if (g_drag_lock_center)
	{
		nx = g2l.a * mx + g2l.c * my + g2l.tx;
		ny = g2l.b * mx + g2l.d * my + g2l.ty;
	}
	else
	{
		double dmx = (g_mouse_x - g_drag_last_mx) * 20.0;
		double dmy = (g_mouse_y - g_drag_last_my) * 20.0;
		double ldx = g2l.a * dmx + g2l.c * dmy;
		double ldy = g2l.b * dmx + g2l.d * dmy;
		nx = (double) ext->mtx_tx + ldx;
		ny = (double) ext->mtx_ty + ldy;
		g_drag_last_mx = g_mouse_x;
		g_drag_last_my = g_mouse_y;
	}
	if (g_drag_has_constraint)
	{
		if (nx < g_drag_cx0) nx = g_drag_cx0;
		if (nx > g_drag_cx1) nx = g_drag_cx1;
		if (ny < g_drag_cy0) ny = g_drag_cy0;
		if (ny > g_drag_cy1) ny = g_drag_cy1;
	}
	ext->mtx_tx = (int32_t) nearbyint(nx);
	ext->mtx_ty = (int32_t) nearbyint(ny);
	// dropTarget = object under the mouse with the dragged object hidden.
	uint8_t was_vis = ext->visible;
	ext->visible = 0;
	g_drag_drop_target = run_mouse_pick(ctx);
	ext->visible = was_vis;
}

static Avm2Value do_start_drag(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(act->ctx, self);
	if (ext == NULL) return avm2_undefined();
	g_drag_object = self;
	g_drag_lock_center = act->argc > 0 && avm2_coerce_to_boolean(act->args[0]);
	g_drag_last_mx = g_mouse_x;
	g_drag_last_my = g_mouse_y;
	g_drag_has_constraint = 0;
	if (act->argc > 1 && act->args[1].kind == AVM2_VALUE_OBJECT
	    && act->args[1].u.obj != NULL)
	{
		Avm2Object* r = act->args[1].u.obj;
		if (r->slot_count > 4)
		{
			double x = avm2_coerce_to_number(act->ctx, r->slots[1]);
			double y = avm2_coerce_to_number(act->ctx, r->slots[2]);
			double w = avm2_coerce_to_number(act->ctx, r->slots[3]);
			double h = avm2_coerce_to_number(act->ctx, r->slots[4]);
			double x0 = x * 20.0, y0 = y * 20.0, x1 = (x + w) * 20.0, y1 = (y + h) * 20.0;
			g_drag_cx0 = x0 < x1 ? x0 : x1;
			g_drag_cx1 = x0 < x1 ? x1 : x0;
			g_drag_cy0 = y0 < y1 ? y0 : y1;
			g_drag_cy1 = y0 < y1 ? y1 : y0;
			g_drag_has_constraint = 1;
		}
	}
	update_drag(act->ctx);
	return avm2_undefined();
}

static Avm2Value do_stop_drag(Avm2Activation* act)
{
	(void) act;
	g_drag_object = NULL;
	return avm2_undefined();
}

static Avm2Value do_get_drop_target(Avm2Activation* act)
{
	(void) act;
	return g_drag_drop_target != NULL ? avm2_object_value(g_drag_drop_target)
	                                  : avm2_null();
}

static Avm2Value do_get_button_mode(Avm2Activation* act)
{
	Avm2DisplayObjectExt* e = this_display(act);
	return avm2_bool(e != NULL && e->button_mode);
}
static Avm2Value do_set_button_mode(Avm2Activation* act)
{
	Avm2DisplayObjectExt* e = this_display(act);
	if (e != NULL && act->argc > 0)
		e->button_mode = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	return avm2_undefined();
}
static Avm2Value do_get_use_hand(Avm2Activation* act)
{
	Avm2DisplayObjectExt* e = this_display(act);
	return avm2_bool(e == NULL || e->use_hand_cursor);
}
static Avm2Value do_set_use_hand(Avm2Activation* act)
{
	Avm2DisplayObjectExt* e = this_display(act);
	if (e != NULL && act->argc > 0)
		e->use_hand_cursor = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
	return avm2_undefined();
}

// local mouse position of obj (pixels).
static void local_mouse(Avm2Context* ctx, Avm2Object* obj, double* lx, double* ly)
{
	Mat m = display_world_matrix(ctx, obj);
	Mat inv = mat_invert(&m);
	double gx = g_mouse_x * 20.0, gy = g_mouse_y * 20.0;
	*lx = (inv.a * gx + inv.c * gy + inv.tx) / 20.0;
	*ly = (inv.b * gx + inv.d * gy + inv.ty) / 20.0;
}

void avm2_display_event_stage_coords(Avm2Context* ctx, Avm2Object* target,
                                     double lx, double ly, double* sx, double* sy)
{
	if (target == NULL || avm2_display_ext_of(ctx, target) == NULL || isnan(lx))
	{
		*sx = lx; *sy = ly;
		return;
	}
	Mat m = display_world_matrix(ctx, target);
	double px = lx * 20.0, py = ly * 20.0;
	*sx = (m.a * px + m.c * py + m.tx) / 20.0;
	*sy = (m.b * px + m.d * py + m.ty) / 20.0;
}

// Construct + dispatch a MouseEvent to a display object (its object2 is itself).
static int dispatch_mouse(Avm2Context* ctx, Avm2Object* target,
                          const char* type, Avm2Object* related, int32_t delta,
                          int bubbles, int button)
{
	if (target == NULL) return 0;
	double lx = NAN, ly = NAN;
	local_mouse(ctx, target, &lx, &ly);
	int button_down = g_mouse_btn_down[button < 0 || button > 2 ? 0 : button];
	Avm2Object* ev = avm2_mouse_event_new(
		ctx, avm2_string_from_literal(ctx, type), bubbles, 0, lx, ly, related,
		mod_shift(), mod_ctrl(), mod_alt(), button_down, delta);
	return avm2_dispatch_event(ctx, target, ev);
}

static Avm2Object* display_parent_obj(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	return e != NULL ? e->parent : NULL;
}

static Avm2Object* lowest_common_ancestor(Avm2Context* ctx, Avm2Object* from,
                                          Avm2Object* to)
{
	Avm2Object* from_p[64]; int fn = 0;
	for (Avm2Object* u = from; u != NULL && fn < 64; u = display_parent_obj(ctx, u))
		from_p[fn++] = u;
	Avm2Object* to_p[64]; int tn = 0;
	for (Avm2Object* u = to; u != NULL && tn < 64; u = display_parent_obj(ctx, u))
		to_p[tn++] = u;
	Avm2Object* hca = NULL;
	int i = fn - 1, j = tn - 1;
	while (i >= 0 && j >= 0)
	{
		if (from_p[i] == to_p[j]) { hca = from_p[i]; i--; j--; }
		else break;
	}
	return hca;
}

// ClipEvent::RollOut{to} — mouseOut on self + rollOut up to the LCA.
static void dispatch_roll_out(Avm2Context* ctx, Avm2Object* self, Avm2Object* to)
{
	dispatch_mouse(ctx, self, "mouseOut", to, 0, 1, 0);
	Avm2Object* lca = lowest_common_ancestor(ctx, self,
		to != NULL ? to : ctx->stage);
	for (Avm2Object* tgt = self; tgt != NULL && tgt != lca;
	     tgt = display_parent_obj(ctx, tgt))
	{
		dispatch_mouse(ctx, tgt, "rollOut", to, 0, 0, 0);
	}
}

// ClipEvent::RollOver{from} — rollOver down from the LCA + mouseOver on self.
static void dispatch_roll_over(Avm2Context* ctx, Avm2Object* self, Avm2Object* from)
{
	Avm2Object* lca = lowest_common_ancestor(ctx, self,
		from != NULL ? from : ctx->stage);
	for (Avm2Object* tgt = self; tgt != NULL && tgt != lca;
	     tgt = display_parent_obj(ctx, tgt))
	{
		dispatch_mouse(ctx, tgt, "rollOver", from, 0, 0, 0);
	}
	dispatch_mouse(ctx, self, "mouseOver", from, 0, 1, 0);
}

// Focus change on left mouse press (Ruffle update_focus_on_mouse_press): the
// nearest focusable-by-mouse ancestor gets focus; else focus is cleared. Fires
// FocusEvent focusIn/focusOut. Defined in the focus section below.
static void update_focus_on_press(Avm2Context* ctx, Avm2Object* pressed);

static void update_mouse_state(Avm2Context* ctx, int changed_button, int is_moved)
{
	Avm2Object* stage = ctx->stage;
	// Dragged object follows the mouse before hit-testing (Ruffle update_drag).
	update_drag(ctx);
	int mouse_in_stage = 1;
	Avm2Object* new_over = mouse_in_stage ? run_mouse_pick(ctx) : NULL;
	Avm2Object* cur_over = g_mouse_hovered;
	int left_down = g_mouse_btn_down[0];

	if (is_moved)
		dispatch_mouse(ctx, new_over != NULL ? new_over : stage,
		               "mouseMove", NULL, 0, 1, 0);

	// Hover change → roll/over events.
	if (cur_over != new_over)
	{
		if (left_down)
		{
			g_mouse_hovered = new_over;
			if (cur_over != NULL) dispatch_roll_out(ctx, cur_over, new_over);
			if (new_over != NULL) dispatch_roll_over(ctx, new_over, cur_over);
		}
		else
		{
			if (cur_over != NULL) dispatch_roll_out(ctx, cur_over, new_over);
			if (new_over != NULL) dispatch_roll_over(ctx, new_over, cur_over);
		}
	}
	g_mouse_hovered = new_over;

	if (changed_button >= 0 && changed_button <= 2)
	{
		int button = changed_button;
		if (g_mouse_btn_down[button])
		{
			// Press.
			Avm2Object* over = g_mouse_hovered;
			const char* down_type = button == 0 ? "mouseDown"
				: button == 1 ? "middleMouseDown" : "rightMouseDown";
			(void) down_type;
			// Ruffle dispatch loop: focus updates on the press BEFORE the AVM2
			// mouseDown event is dispatched (update_focus_on_mouse_press runs
			// between handle_clip_event and event_dispatch_to_avm2).
			if (over != NULL)
			{
				g_mouse_pressed[button] = over;
				if (button == 0) update_focus_on_press(ctx, over);
				dispatch_mouse(ctx, over,
					button == 0 ? "mouseDown" : button == 1 ? "middleMouseDown"
					: "rightMouseDown", NULL, 0, 1, button);
			}
			else
			{
				if (button == 0) update_focus_on_press(ctx, NULL);
				dispatch_mouse(ctx, stage,
					button == 0 ? "mouseDown" : button == 1 ? "middleMouseDown"
					: "rightMouseDown", NULL, 0, 1, button);
			}
		}
		else
		{
			// Release.
			Avm2Object* over = g_mouse_hovered;
			const char* up_type = button == 0 ? "mouseUp"
				: button == 1 ? "middleMouseUp" : "rightMouseUp";
			dispatch_mouse(ctx, over != NULL ? over : stage, up_type, NULL, 0, 1,
			               button);
			int released_inside = (g_mouse_pressed[button] == over);
			if (released_inside)
			{
				Avm2Object* down = g_mouse_pressed[button];
				Avm2Object* rt = down != NULL ? down : stage;
				if (button == 0)
				{
					int is_double = (g_left_click_index % 2) != 0;
					Avm2DisplayObjectExt* de = avm2_display_ext_of(ctx, rt);
					int dce = de != NULL && de->double_click_enabled;
					if (is_double && dce)
						dispatch_mouse(ctx, rt, "doubleClick", NULL, 0, 1, 0);
					else
						dispatch_mouse(ctx, rt, "click", NULL, 0, 1, 0);
				}
				else
				{
					dispatch_mouse(ctx, rt,
						button == 1 ? "middleClick" : "rightClick", NULL, 0, 1,
						button);
				}
			}
			else
			{
				Avm2Object* down = g_mouse_pressed[button];
				if (button == 0)
				{
					dispatch_mouse(ctx, down != NULL ? down : stage,
					               "releaseOutside", NULL, 0, 1, 0);
					// New object rolled over immediately.
					if (g_mouse_hovered != NULL)
						dispatch_roll_over(ctx, g_mouse_hovered, cur_over);
				}
			}
			g_mouse_pressed[button] = NULL;
		}
	}
}

// --- Keyboard dispatch (Ruffle player.rs KeyDown/KeyUp -> KeyboardEvent) ---
static void dispatch_key(Avm2Context* ctx, int is_down, int32_t key_code,
                         int32_t char_code, int32_t key_location)
{
	Avm2Object* target = g_stage_focus != NULL ? g_stage_focus : ctx->stage;
	if (target == NULL) return;
	Avm2Object* ev = avm2_keyboard_event_new(
		ctx, avm2_string_from_literal(ctx, is_down ? "keyDown" : "keyUp"),
		1, 0, (uint32_t) char_code, (uint32_t) key_code,
		(uint32_t) key_location, mod_ctrl(), mod_alt(), mod_shift());
	avm2_dispatch_event(ctx, target, ev);
}

// Forward decls for keyboard/text/focus routing implemented in the focus/text
// bridge sections.
static void input_handle_key(Avm2Context* ctx, int is_down, int32_t key_code,
                             int32_t char_code, int32_t key_location);
static void input_handle_text(Avm2Context* ctx, int32_t codepoint);
static void input_handle_text_control(Avm2Context* ctx, const char* ctrl);
static void input_handle_tab(Avm2Context* ctx, int shift);

static void input_deliver(Avm2Context* ctx, Avm2InputEvent* ev)
{
	switch (ev->kind)
	{
	case IN_MOUSE_MOVE:
	{
		int moved = (g_mouse_x != ev->x) || (g_mouse_y != ev->y);
		g_mouse_x = ev->x; g_mouse_y = ev->y;
		update_mouse_state(ctx, -1, moved);
		break;
	}
	case IN_MOUSE_DOWN:
	{
		int moved = (g_mouse_x != ev->x) || (g_mouse_y != ev->y);
		g_mouse_x = ev->x; g_mouse_y = ev->y;
		g_mouse_btn_down[ev->button] = 1;
		if (ev->button == 0) g_left_click_index = (uint32_t) ev->code;
		update_mouse_state(ctx, ev->button, moved);
		break;
	}
	case IN_MOUSE_UP:
	{
		int moved = (g_mouse_x != ev->x) || (g_mouse_y != ev->y);
		g_mouse_x = ev->x; g_mouse_y = ev->y;
		g_mouse_btn_down[ev->button] = 0;
		update_mouse_state(ctx, ev->button, moved);
		break;
	}
	case IN_MOUSE_WHEEL:
	{
		Avm2Object* target = g_mouse_hovered != NULL ? g_mouse_hovered : ctx->stage;
		dispatch_mouse(ctx, target, "mouseWheel", NULL, ev->code, 1, 0);
		break;
	}
	case IN_KEY_DOWN:
		if (ev->code >= 0 && ev->code < 256) g_key_down_map[ev->code] = 1;
		input_handle_key(ctx, 1, ev->code, ev->code2, ev->code3);
		break;
	case IN_KEY_UP:
		if (ev->code >= 0 && ev->code < 256) g_key_down_map[ev->code] = 0;
		input_handle_key(ctx, 0, ev->code, ev->code2, ev->code3);
		break;
	case IN_TEXT_INPUT:
		input_handle_text(ctx, ev->code);
		break;
	case IN_TEXT_CONTROL:
		input_handle_text_control(ctx, ev->ctrl);
		break;
	case IN_SET_CLIPBOARD:
	{
		size_t n = strlen(ev->text);
		char* buf = malloc(n + 1);
		if (buf != NULL) { memcpy(buf, ev->text, n + 1); g_clipboard_text = buf; }
		break;
	}
	default:
		break;
	}
}

// Live browser input injector (Stage 13c). Called from the emscripten key
// callbacks (render_webgpu.c) to enqueue a keyDown/keyUp for delivery on the
// next tick. keyCode/charCode/keyLocation come straight from the DOM event
// (DOM keyCode == Flash keyCode for the keys games read). Non-static: the
// rendering TU calls it through a local extern (see render_webgpu.c).
void avm2_input_inject_key(int is_down, int32_t key_code,
                           int32_t char_code, int32_t key_location)
{
	size_t next = (g_live_in_tail + 1) % AVM2_LIVE_IN_CAP;
	if (next == g_live_in_head) return;   // ring full → drop this event
	Avm2InputEvent* ev = &g_live_in[g_live_in_tail];
	memset(ev, 0, sizeof(*ev));
	ev->kind  = is_down ? IN_KEY_DOWN : IN_KEY_UP;
	ev->code  = key_code;
	ev->code2 = char_code;
	ev->code3 = key_location;
	g_live_in_tail = next;
}

// Live browser mouse injection (RWK-3): same ring, called from the emscripten
// mouse callbacks in render_webgpu.c. kind: 0 = move, 1 = down, 2 = up;
// x/y are stage pixels (the callbacks already unscale CSS coordinates);
// button 0/1/2 = left/middle/right, matching the harness event format.
// click_count is the DOM event's `detail` (browser-native double-click
// detection): the delivery path reads MOUSE_DOWN's code as a click index
// whose ODD parity means doubleClick, so map detail>=2 → odd, else even.
void avm2_input_inject_mouse(int kind, float x, float y, int button,
                             int click_count)
{
	size_t next = (g_live_in_tail + 1) % AVM2_LIVE_IN_CAP;
	if (next == g_live_in_head) return;   // ring full → drop this event
	Avm2InputEvent* ev = &g_live_in[g_live_in_tail];
	memset(ev, 0, sizeof(*ev));
	ev->kind = kind == 1 ? IN_MOUSE_DOWN : kind == 2 ? IN_MOUSE_UP : IN_MOUSE_MOVE;
	ev->x = x;
	ev->y = y;
	ev->button = (button >= 0 && button <= 2) ? button : 0;
	if (ev->kind == IN_MOUSE_DOWN && ev->button == 0)
		ev->code = (click_count >= 2) ? 1 : 0;
	g_live_in_tail = next;
}

void avm2_input_pump_tick(Avm2Context* ctx)
{
	// Live browser events first: drain everything buffered since the last tick
	// (delivered in real time, so no WAIT pacing). Each in its own try frame so
	// a throwing AS3 key handler can't abort the rest of the drain or the tick.
	while (g_live_in_head != g_live_in_tail)
	{
		Avm2InputEvent* ev = &g_live_in[g_live_in_head];
		Avm2TryFrame ltop;
		avm2_try_push_catch_all(ctx, &ltop);
		if (setjmp(ltop.jb) == 0)
		{
			input_deliver(ctx, ev);
		}
		avm2_try_pop_frame(&ltop);
		g_live_in_head = (g_live_in_head + 1) % AVM2_LIVE_IN_CAP;
	}

	// Harness file queue: one WAIT group per tick.
	while (g_in_pos < g_in_count)
	{
		Avm2InputEvent* ev = &g_in_events[g_in_pos];
		if (ev->kind == IN_WAIT) { g_in_pos++; return; }
		Avm2TryFrame top;
		avm2_try_push_catch_all(ctx, &top);
		if (setjmp(top.jb) == 0)
		{
			input_deliver(ctx, ev);
		}
		avm2_try_pop_frame(&top);
		g_in_pos++;
	}
}

// ---------------------------------------------------------------------------
// Focus management (Ruffle focus_tracker.rs) + keyboard/text routing.
// ---------------------------------------------------------------------------

static int is_focusable_by_mouse(Avm2Context* ctx, Avm2Object* obj)
{
	// Ruffle: AVM2 objects are mouse-focusable when tabEnabled is true. A
	// TextField that is selectable is also mouse-focusable.
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e == NULL || e->is_stage || e->is_root) return 0;
	if (e->edittext != NULL) return 1;
	return e->tab_enabled_set && e->tab_enabled_val;
}

// Set focus to new_focus (may be NULL), firing FocusEvent focusOut/focusIn.
// related = the "other" object in the transition; when key-driven, key_code=9.
static void set_focus(Avm2Context* ctx, Avm2Object* new_focus)
{
	Avm2Object* old = g_stage_focus;
	if (old == new_focus) return;
	if (new_focus != NULL)
		avm2_text_apply_pending_bounds(ctx, new_focus);
	g_stage_focus = new_focus;
	// focusOut on the old target (bubbles, related = new).
	if (old != NULL)
	{
		Avm2Object* ev = avm2_focus_event_new(ctx,
			avm2_string_from_literal(ctx, "focusOut"), 1, 0, new_focus, 0, 0,
			"none");
		avm2_dispatch_event(ctx, old, ev);
	}
	// focusIn on the new target (bubbles, related = old).
	if (new_focus != NULL)
	{
		Avm2Object* ev = avm2_focus_event_new(ctx,
			avm2_string_from_literal(ctx, "focusIn"), 1, 0, old, 0, 0, "none");
		avm2_dispatch_event(ctx, new_focus, ev);
	}
}

static void update_focus_on_press(Avm2Context* ctx, Avm2Object* pressed)
{
	// Walk up from the pressed object to the nearest mouse-focusable ancestor.
	Avm2Object* focus = NULL;
	for (Avm2Object* o = pressed; o != NULL; o = display_parent_obj(ctx, o))
	{
		if (is_focusable_by_mouse(ctx, o)) { focus = o; break; }
	}
	// A mouseFocusChange (cancelable) fires before the change when focus would
	// move; if not cancelled, apply. (We do not model cancellation of the
	// default yet — apply unconditionally.)
	if (focus != g_stage_focus)
	{
		Avm2Object* related = focus;
		Avm2Object* dispatch_on = g_stage_focus != NULL ? g_stage_focus : ctx->stage;
		Avm2Object* ev = avm2_focus_event_new(ctx,
			avm2_string_from_literal(ctx, "mouseFocusChange"), 1, 1, related, 0,
			0, "none");
		avm2_dispatch_event(ctx, dispatch_on, ev);
		set_focus(ctx, focus);
	}
}

// tab_enabled (Ruffle InteractiveObject::tab_enabled): explicit value or the
// per-type default.
static int obj_tab_enabled(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e == NULL) return 0;
	if (e->tab_enabled_set) return e->tab_enabled_val;
	// tab_enabled_default per type.
	if (e->edittext != NULL) return avm2_text_is_editable(e->edittext);
	if (class_is_a(obj->cls, ctx->builtins.simple_button_class)) return 1;
	if (class_is_a(obj->cls, ctx->builtins.movieclip_class))
		return e->button_mode ? 1 : 0;
	return 0;  // Sprite / base InteractiveObject
}

// is_tabbable (Ruffle per-type).
static int obj_is_tabbable(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e == NULL || e->is_root || e->is_stage) return 0;
	if (e->edittext != NULL)
		return avm2_text_is_editable(e->edittext) && obj_tab_enabled(ctx, obj);
	return obj_tab_enabled(ctx, obj);
}

static int obj_tab_children(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e == NULL) return 1;
	return e->tab_children != 0;
}

// world top-left (twips) for the automatic order key 6*y + x.
static void obj_world_topleft(Avm2Context* ctx, Avm2Object* obj,
                              double* x, double* y)
{
	avm2_text_apply_pending_bounds(ctx, obj);
	Mat m = display_world_matrix(ctx, obj);
	Rect r = { 0, 0, 0, 0, 0 };
	bounds_with_transform(ctx, obj, &m, &r);
	*x = r.valid ? r.xmin : 0;
	*y = r.valid ? r.ymin : 0;
}

typedef struct { Avm2Object* obj; int32_t tab_index; int has_index;
                 double key; uint32_t fill_ord; } TabEnt;

// Ruffle container::fill_tab_order (DFS render order, tabChildren gate).
static void fill_tab_order(Avm2Context* ctx, Avm2Object* obj, TabEnt* list,
                           uint32_t* n, uint32_t cap, int* any_index)
{
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e == NULL) return;
	if (obj != ctx->stage && !obj_tab_children(ctx, obj)) return;
	for (uint32_t i = 0; i < e->render_len; i++)
	{
		Avm2Object* child = e->render_list[i];
		Avm2DisplayObjectExt* ce = avm2_display_ext_of(ctx, child);
		if (ce == NULL || !ce->visible) continue;
		if (is_interactive(ctx, child) && obj_is_tabbable(ctx, child) && *n < cap)
		{
			TabEnt* t = &list[(*n)];
			t->obj = child;
			t->has_index = ce->tab_index >= 0;
			t->tab_index = ce->tab_index;
			t->fill_ord = *n;
			if (t->has_index) *any_index = 1;
			(*n)++;
		}
		fill_tab_order(ctx, child, list, n, cap, any_index);
	}
}

static int tab_cmp_custom(const void* a, const void* b)
{
	const TabEnt* x = a; const TabEnt* y = b;
	if (x->tab_index != y->tab_index) return x->tab_index < y->tab_index ? -1 : 1;
	return x->fill_ord < y->fill_ord ? -1 : (x->fill_ord > y->fill_ord ? 1 : 0);
}
static int tab_cmp_auto(const void* a, const void* b)
{
	const TabEnt* x = a; const TabEnt* y = b;
	if (x->key != y->key) return x->key < y->key ? -1 : 1;
	return x->fill_ord < y->fill_ord ? -1 : (x->fill_ord > y->fill_ord ? 1 : 0);
}

// Build the sorted tab order into `out` (Ruffle TabOrder::sort). Returns count.
static uint32_t build_tab_order(Avm2Context* ctx, Avm2Object** out, uint32_t cap)
{
	TabEnt list[256];
	uint32_t n = 0;
	int any_index = 0;
	fill_tab_order(ctx, ctx->stage, list, &n, 256, &any_index);
	if (any_index)
	{
		// Custom order: retain only tabIndex objects, sort by index.
		uint32_t m = 0;
		for (uint32_t i = 0; i < n; i++)
			if (list[i].has_index) list[m++] = list[i];
		n = m;
		qsort(list, n, sizeof(TabEnt), tab_cmp_custom);
	}
	else
	{
		for (uint32_t i = 0; i < n; i++)
		{
			double x, y;
			obj_world_topleft(ctx, list[i].obj, &x, &y);
			list[i].key = 6.0 * y + x;
		}
		qsort(list, n, sizeof(TabEnt), tab_cmp_auto);
		// Dedup by equal key (keep first in fill order — already the sort tie).
		uint32_t m = 0;
		for (uint32_t i = 0; i < n; i++)
		{
			if (m > 0 && list[i].key == list[m - 1].key) continue;
			list[m++] = list[i];
		}
		n = m;
	}
	uint32_t k = n < cap ? n : cap;
	for (uint32_t i = 0; i < k; i++) out[i] = list[i].obj;
	return k;
}

static void input_handle_tab(Avm2Context* ctx, int shift)
{
	Avm2Object* order[256];
	uint32_t n = build_tab_order(ctx, order, 256);

	Avm2Object* cur = g_stage_focus;
	Avm2Object* next = NULL;
	if (n > 0)
	{
		int cur_idx = -1;
		for (uint32_t i = 0; i < n; i++) if (order[i] == cur) { cur_idx = (int) i; break; }
		if (cur_idx < 0)
		{
			next = shift ? order[n - 1] : order[0];
		}
		else
		{
			int ni = cur_idx + (shift ? -1 : 1);
			if (ni < 0) ni = (int) n - 1;
			if (ni >= (int) n) ni = 0;
			next = order[ni];
		}
	}
	// keyFocusChange (cancelable, bubbles) on the current focus (or stage),
	// relatedObject = the next-focus candidate.
	Avm2Object* dispatch_on = cur != NULL ? cur : ctx->stage;
	Avm2Object* ev = avm2_focus_event_new(ctx,
		avm2_string_from_literal(ctx, "keyFocusChange"), 1, 1, next, shift, 9,
		"none");
	avm2_dispatch_event(ctx, dispatch_on, ev);
	Avm2EventExt* eext = (Avm2EventExt*) ev->native_ext;
	if (eext == NULL || !eext->cancelled)
		set_focus(ctx, next);
}

static void input_handle_key(Avm2Context* ctx, int is_down, int32_t key_code,
                             int32_t char_code, int32_t key_location)
{
	dispatch_key(ctx, is_down, key_code, char_code, key_location);
	// Tab drives focus traversal on keyDown (after the keyDown dispatch).
	if (is_down && key_code == 9)
		input_handle_tab(ctx, mod_shift());
	// Text editing keys route to the focused TextField.
	if (is_down)
		avm2_text_input_key(ctx, g_stage_focus, key_code, char_code, mod_shift());
}

static void input_handle_text(Avm2Context* ctx, int32_t codepoint)
{
	avm2_text_input_char(ctx, g_stage_focus, codepoint);
}

static void input_handle_text_control(Avm2Context* ctx, const char* ctrl)
{
	avm2_text_input_control(ctx, g_stage_focus, ctrl, g_clipboard_text);
}

// flash.ui.Mouse — static cursor property + hide/show. Headless has no real
// cursor; store the last-set string and no-op hide/show (FlashPunk's Splash
// sets Mouse.cursor every frame).
static const Avm2String* g_mouse_cursor;
static Avm2Value mouse_get_cursor(Avm2Activation* act)
{
	const Avm2String* s = g_mouse_cursor != NULL
		? g_mouse_cursor : avm2_string_from_literal(act->ctx, "auto");
	return avm2_string(s);
}
static Avm2Value mouse_set_cursor(Avm2Activation* act)
{
	g_mouse_cursor = avm2_coerce_to_string(act->ctx,
		act->argc > 0 ? act->args[0] : avm2_undefined());
	return avm2_undefined();
}
static Avm2Value mouse_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

void avm2_register_display(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;

	Avm2Class* dobj =
		avm2_builtin_class(ctx, "flash.display", "DisplayObject",
		                   b->event_dispatcher_class);
	dobj->native_ext_size = sizeof(Avm2DisplayObjectExt);
	dobj->native_init = display_native_init_abstract;
	b->display_object_class = dobj;
	avm2_builtin_add_method(ctx, dobj, "hitTestObject", do_hit_test_object);
	avm2_builtin_add_method(ctx, dobj, "getBounds", do_get_bounds);
	avm2_builtin_add_method(ctx, dobj, "getRect", do_get_bounds);
	avm2_builtin_add_method(ctx, dobj, "globalToLocal", do_global_to_local);
	avm2_builtin_add_method(ctx, dobj, "localToGlobal", do_local_to_global);
	avm2_builtin_add_method(ctx, dobj, "hitTestPoint", do_hit_test_point);
	avm2_builtin_add_method(ctx, dobj, "local3DToGlobal", do_local3d_to_global);
	avm2_builtin_add_method(ctx, dobj, "globalToLocal3D", do_local3d_to_global);
	add_getset(ctx, dobj, "x", do_get_x, do_set_x);
	add_getset(ctx, dobj, "y", do_get_y, do_set_y);
	add_getset(ctx, dobj, "scaleX", do_get_scale_x, do_set_scale_x);
	add_getset(ctx, dobj, "scaleY", do_get_scale_y, do_set_scale_y);
	add_getset(ctx, dobj, "rotation", do_get_rotation, do_set_rotation);
	add_getset(ctx, dobj, "width", do_get_width, do_set_width);
	add_getset(ctx, dobj, "height", do_get_height, do_set_height);
	add_getset(ctx, dobj, "alpha", do_get_alpha, do_set_alpha);
	add_getset(ctx, dobj, "visible", do_get_visible, do_set_visible);
	add_getset(ctx, dobj, "name", do_get_name, do_set_name);
	add_getset(ctx, dobj, "mask", do_get_mask, do_set_mask);
	add_getset(ctx, dobj, "metaData", do_get_metadata, do_set_metadata);
	add_getset(ctx, dobj, "filters", do_get_filters, do_set_filters);
	add_getset(ctx, dobj, "transform", do_get_transform, do_set_transform);
	avm2_builtin_add_getter(ctx, dobj, "parent", do_get_parent);
	avm2_builtin_add_getter(ctx, dobj, "root", do_get_root);
	avm2_builtin_add_getter(ctx, dobj, "stage", do_get_stage);
	avm2_builtin_add_getter(ctx, dobj, "mouseX", do_get_mouse_x);
	avm2_builtin_add_getter(ctx, dobj, "mouseY", do_get_mouse_y);
	avm2_builtin_add_getter(ctx, dobj, "loaderInfo", do_get_loader_info);
	add_getset(ctx, dobj, "cacheAsBitmap", do_cab_get, do_cab_set);
	add_getset(ctx, dobj, "opaqueBackground", do_opaquebg_get, do_opaquebg_set);
	add_getset(ctx, dobj, "scrollRect", do_scrollrect_get, do_scrollrect_set);
	add_getset(ctx, dobj, "accessibilityProperties", do_accessprops_get,
	           do_accessprops_set);
	add_getset(ctx, dobj, "blendMode", do_blendmode_get, do_blendmode_set);
	add_getset(ctx, dobj, "scale9Grid", do_scrollrect_get, do_scrollrect_set);
	add_getset(ctx, dobj, "z", do_get_zero, do_set_noop);
	add_getset(ctx, dobj, "rotationX", do_get_zero, do_set_noop);
	add_getset(ctx, dobj, "rotationY", do_get_zero, do_set_noop);
	add_getset(ctx, dobj, "rotationZ", do_get_rotation, do_set_rotation);
	add_getset(ctx, dobj, "scaleZ", do_get_one, do_set_noop);

	// flash.display.LoaderInfo (extends EventDispatcher). The root movie's
	// LoaderInfo singleton is lazily built by avm2_get_root_loader_info.
	Avm2Class* linfo =
		avm2_builtin_class(ctx, "flash.display", "LoaderInfo",
		                   b->event_dispatcher_class);
	linfo->native_ext_size = sizeof(Avm2LoaderInfoExt);
	b->loader_info_class = linfo;
	avm2_builtin_add_getter(ctx, linfo, "bytesLoaded", li_get_bytes_total);
	avm2_builtin_add_getter(ctx, linfo, "bytesTotal", li_get_bytes_total);
	avm2_builtin_add_getter(ctx, linfo, "content", li_get_content);
	avm2_builtin_add_getter(ctx, linfo, "contentType", li_get_content_type);
	avm2_builtin_add_getter(ctx, linfo, "actionScriptVersion", li_get_as_version);
	avm2_builtin_add_getter(ctx, linfo, "frameRate", li_get_frame_rate);
	avm2_builtin_add_getter(ctx, linfo, "width", li_get_width);
	avm2_builtin_add_getter(ctx, linfo, "height", li_get_height);
	avm2_builtin_add_getter(ctx, linfo, "swfVersion", li_get_swf_version);
	avm2_builtin_add_getter(ctx, linfo, "url", li_get_url);
	avm2_builtin_add_getter(ctx, linfo, "loaderURL", li_get_url);
	avm2_builtin_add_getter(ctx, linfo, "parameters", li_get_parameters);
	avm2_builtin_add_getter(ctx, linfo, "applicationDomain",
	                        li_get_application_domain);
	avm2_builtin_add_getter(ctx, linfo, "loader", li_get_loader);
	avm2_builtin_add_getter(ctx, linfo, "childAllowsParent", li_get_true);
	avm2_builtin_add_getter(ctx, linfo, "parentAllowsChild", li_get_true);
	avm2_builtin_add_getter(ctx, linfo, "sameDomain", li_get_true);

	Avm2Class* iobj =
		avm2_builtin_class(ctx, "flash.display", "InteractiveObject", dobj);
	b->interactive_object_class = iobj;
	add_getset(ctx, iobj, "mouseEnabled", io_get_mouse_enabled, io_set_mouse_enabled);
	add_getset(ctx, iobj, "doubleClickEnabled", io_get_double_click_enabled,
	           io_set_double_click_enabled);
	add_getset(ctx, iobj, "tabEnabled", io_get_tab_enabled, io_set_tab_enabled);
	add_getset(ctx, iobj, "tabIndex", io_get_tab_index, io_set_tab_index);
	add_getset(ctx, iobj, "focusRect", io_get_focus_rect, io_set_focus_rect);
	add_getset(ctx, iobj, "needsSoftKeyboard", io_needssoftkbd_get,
	           io_needssoftkbd_set);
	avm2_builtin_add_method(ctx, iobj, "requestSoftKeyboard",
	                        io_request_soft_keyboard);
	add_getset(ctx, iobj, "softKeyboardInputAreaOfInterest",
	           io_softkbdarea_get, io_softkbdarea_set);
	add_getset(ctx, iobj, "accessibilityImplementation", do_accessimpl_get,
	           do_accessimpl_set);
	add_getset(ctx, iobj, "contextMenu", do_contextmenu_get, do_contextmenu_set);
	// soundTransform lives on Sprite + SimpleButton; both derive from
	// InteractiveObject, so registering here covers MovieClip and SimpleButton.
	add_getset(ctx, iobj, "soundTransform", do_get_sound_transform,
	           do_set_sound_transform);

	Avm2Class* doc =
		avm2_builtin_class(ctx, "flash.display", "DisplayObjectContainer", iobj);
	b->doc_class = doc;
	avm2_builtin_add_method(ctx, doc, "addChild", doc_add_child);
	avm2_builtin_add_method(ctx, doc, "addChildAt", doc_add_child_at);
	avm2_builtin_add_method(ctx, doc, "removeChild", doc_remove_child);
	avm2_builtin_add_method(ctx, doc, "removeChildAt", doc_remove_child_at);
	avm2_builtin_add_method(ctx, doc, "removeChildren", doc_remove_children);
	avm2_builtin_add_method(ctx, doc, "getChildAt", doc_get_child_at);
	avm2_builtin_add_method(ctx, doc, "getChildByName", doc_get_child_by_name);
	avm2_builtin_add_method(ctx, doc, "getChildIndex", doc_get_child_index);
	avm2_builtin_add_method(ctx, doc, "setChildIndex", doc_set_child_index);
	avm2_builtin_add_method(ctx, doc, "swapChildren", doc_swap_children);
	avm2_builtin_add_method(ctx, doc, "swapChildrenAt", doc_swap_children_at);
	avm2_builtin_add_method(ctx, doc, "contains", doc_contains);
	avm2_builtin_add_method(ctx, doc, "stopAllMovieClips", doc_stop_all_movie_clips);
	avm2_builtin_add_getter(ctx, doc, "numChildren", doc_get_num_children);
	add_getset(ctx, doc, "mouseChildren", doc_get_mouse_children,
	           doc_set_mouse_children);
	add_getset(ctx, doc, "tabChildren", doc_get_tab_children, doc_set_tab_children);

	Avm2Class* sprite = avm2_builtin_class(ctx, "flash.display", "Sprite", doc);
	sprite->instance_init.fn = sprite_ctor_init;
	sprite->instance_init.debug_name = "Sprite";
	sprite->native_init = display_native_init;  // concrete: no 2012
	b->sprite_class = sprite;
	avm2_builtin_add_method(ctx, sprite, "startDrag", do_start_drag);
	avm2_builtin_add_method(ctx, sprite, "stopDrag", do_stop_drag);
	avm2_builtin_add_getter(ctx, sprite, "dropTarget", do_get_drop_target);
	add_getset(ctx, sprite, "buttonMode", do_get_button_mode, do_set_button_mode);
	add_getset(ctx, sprite, "useHandCursor", do_get_use_hand, do_set_use_hand);
	// `graphics` MUST be registered on Sprite before MovieClip is derived
	// (below) so MovieClip and its subclasses inherit it (Ruffle: graphics is
	// on Sprite). The Graphics class itself (g_graphics_class) is created later
	// but only referenced when the getter is first called at runtime.
	avm2_builtin_add_getter(ctx, sprite, "graphics", do_get_graphics);

	Avm2Class* movieclip = avm2_builtin_class(ctx, "flash.display", "MovieClip", sprite);
	movieclip->native_init = display_native_init;
	// ConstructSuper only invokes the DIRECT super's init: a class
	// extending MovieClip must still get Sprite's constructChildren.
	movieclip->instance_init.fn = sprite_ctor_init;
	movieclip->instance_init.debug_name = "MovieClip";
	b->movieclip_class = movieclip;
	avm2_builtin_add_method(ctx, movieclip, "addFrameScript", mc_add_frame_script);
	avm2_builtin_add_method(ctx, movieclip, "play", mc_play);
	avm2_builtin_add_method(ctx, movieclip, "stop", mc_stop);
	avm2_builtin_add_method(ctx, movieclip, "nextFrame", mc_next_frame);
	avm2_builtin_add_method(ctx, movieclip, "prevFrame", mc_prev_frame);
	avm2_builtin_add_method(ctx, movieclip, "gotoAndPlay", mc_goto_and_play);
	avm2_builtin_add_method(ctx, movieclip, "gotoAndStop", mc_goto_and_stop);
	avm2_builtin_add_method(ctx, movieclip, "nextScene", mc_next_scene);
	avm2_builtin_add_method(ctx, movieclip, "prevScene", mc_prev_scene);
	avm2_builtin_add_getter(ctx, movieclip, "currentFrame", mc_get_current_frame);
	avm2_builtin_add_getter(ctx, movieclip, "totalFrames", mc_get_total_frames);
	avm2_builtin_add_getter(ctx, movieclip, "framesLoaded", mc_get_frames_loaded);
	avm2_builtin_add_getter(ctx, movieclip, "isPlaying", mc_get_is_playing);
	avm2_builtin_add_getter(ctx, movieclip, "currentLabel", mc_get_current_label);
	avm2_builtin_add_getter(ctx, movieclip, "currentFrameLabel",
	                        mc_get_current_frame_label);
	avm2_builtin_add_getter(ctx, movieclip, "currentLabels", mc_get_current_labels);
	avm2_builtin_add_getter(ctx, movieclip, "currentScene", mc_get_current_scene);
	avm2_builtin_add_getter(ctx, movieclip, "scenes", mc_get_scenes);

	Avm2Class* shape = avm2_builtin_class(ctx, "flash.display", "Shape", dobj);
	shape->native_init = display_native_init;
	b->shape_class = shape;

	// flash.display.Bitmap (extends DisplayObject, NOT InteractiveObject).
	// The class shell + display alloc hook live here so the display tree
	// wiring matches; the ctor/accessors are added by avm2_bitmap.c.
	Avm2Class* bitmap = avm2_builtin_class(ctx, "flash.display", "Bitmap", dobj);
	bitmap->native_init = display_native_init;
	b->bitmap_class = bitmap;
	avm2_bitmap_wire_bitmap(ctx, bitmap);

	// flash.text.TextField / StaticText. The property surface lives in
	// avm2_text.c (Stage 6); the class shell stays here so the display
	// alloc hook and timeline instantiation wire up.
	Avm2Class* textfield = avm2_builtin_class(ctx, "flash.text", "TextField", iobj);
	textfield->native_init = display_native_init;
	g_textfield_class = textfield;
	avm2_text_init_textfield_class(ctx, textfield);
	Avm2Class* statictext = avm2_builtin_class(ctx, "flash.text", "StaticText", dobj);
	statictext->native_init = display_native_init;
	g_statictext_class = statictext;

	// flash.display.Graphics (bounds-only stub); graphics getter on both
	// Shape and Sprite.
	Avm2Class* graphics = avm2_builtin_class(ctx, "flash.display", "Graphics",
	                                         b->object_class);
	graphics->native_ext_size = sizeof(Avm2GraphicsExt);
	avm2_builtin_add_method(ctx, graphics, "beginFill", gfx_noop);
	avm2_builtin_add_method(ctx, graphics, "beginGradientFill", gfx_noop);
	avm2_builtin_add_method(ctx, graphics, "beginBitmapFill", gfx_noop);
	avm2_builtin_add_method(ctx, graphics, "endFill", gfx_noop);
	avm2_builtin_add_method(ctx, graphics, "lineStyle", gfx_noop);
	avm2_builtin_add_method(ctx, graphics, "clear", gfx_clear);
	avm2_builtin_add_method(ctx, graphics, "moveTo", gfx_point_op);
	avm2_builtin_add_method(ctx, graphics, "lineTo", gfx_point_op);
	avm2_builtin_add_method(ctx, graphics, "curveTo", gfx_curve_to);
	avm2_builtin_add_method(ctx, graphics, "drawRect", gfx_draw_rect);
	avm2_builtin_add_method(ctx, graphics, "drawRoundRect", gfx_draw_rect);
	avm2_builtin_add_method(ctx, graphics, "drawEllipse", gfx_draw_rect);
	avm2_builtin_add_method(ctx, graphics, "drawCircle", gfx_draw_circle);
	avm2_builtin_add_method(ctx, graphics, "copyFrom", gfx_noop);
	g_graphics_class = graphics;
	avm2_builtin_add_getter(ctx, shape, "graphics", do_get_graphics);
	// NOTE: Sprite's `graphics` getter is registered earlier (right after the
	// Sprite class is created) so MovieClip — derived from Sprite before this
	// point — inherits it. Re-adding here would be a no-op duplicate.

	// flash.geom.Matrix + Transform (transform.matrix surface).
	Avm2Class* geom_matrix = avm2_builtin_class(ctx, "flash.geom", "Matrix",
	                                            b->object_class);
	geom_matrix->instance_init.fn = geom_matrix_init;
	geom_matrix->instance_init.debug_name = "Matrix";
	avm2_builtin_add_method(ctx, geom_matrix, "toString", geom_matrix_to_string);
	avm2_builtin_add_method(ctx, geom_matrix, "identity", geom_matrix_identity);
	avm2_builtin_add_method(ctx, geom_matrix, "clone", geom_matrix_clone);
	avm2_builtin_add_method(ctx, geom_matrix, "scale", geom_matrix_scale);
	avm2_builtin_add_method(ctx, geom_matrix, "rotate", geom_matrix_rotate);
	avm2_builtin_add_method(ctx, geom_matrix, "translate", geom_matrix_translate);
	avm2_builtin_add_method(ctx, geom_matrix, "concat", geom_matrix_concat);
	avm2_builtin_add_method(ctx, geom_matrix, "invert", geom_matrix_invert);
	avm2_builtin_add_method(ctx, geom_matrix, "createBox", geom_matrix_create_box);
	avm2_builtin_add_method(ctx, geom_matrix, "createGradientBox",
	                        geom_matrix_create_gradient_box);
	avm2_builtin_add_method(ctx, geom_matrix, "transformPoint",
	                        geom_matrix_transform_point);
	avm2_builtin_add_method(ctx, geom_matrix, "deltaTransformPoint",
	                        geom_matrix_delta_transform_point);
	avm2_builtin_add_method(ctx, geom_matrix, "setTo", geom_matrix_set_to);
	avm2_builtin_add_method(ctx, geom_matrix, "copyFrom", geom_matrix_copy_from);
	avm2_builtin_add_method(ctx, geom_matrix, "copyRowFrom",
	                        geom_matrix_copy_row_from);
	avm2_builtin_add_method(ctx, geom_matrix, "copyColumnFrom",
	                        geom_matrix_copy_column_from);
	g_matrix_class = geom_matrix;
	Avm2Class* geom_transform = avm2_builtin_class(ctx, "flash.geom", "Transform",
	                                               b->object_class);
	geom_transform->native_ext_size = sizeof(Avm2TransformExt);
	add_getset(ctx, geom_transform, "matrix", transform_get_matrix,
	           transform_set_matrix);
	add_getset(ctx, geom_transform, "colorTransform", transform_get_color_transform,
	           transform_set_color_transform);
	add_getset(ctx, geom_transform, "concatenatedColorTransform",
	           transform_get_color_transform, NULL);
	add_getset(ctx, geom_transform, "concatenatedMatrix",
	           transform_get_concatenated_matrix, NULL);
	add_getset(ctx, geom_transform, "matrix3D", transform_get_matrix3d,
	           transform_set_stub);
	add_getset(ctx, geom_transform, "perspectiveProjection",
	           transform_get_matrix3d, transform_set_stub);
	add_getset(ctx, geom_transform, "pixelBounds",
	           transform_get_pixel_bounds, NULL);
	g_transform_class = geom_transform;

	// flash.geom.Matrix3D + PerspectiveProjection constructible stubs.
	{
		Avm2Class* m3 = avm2_builtin_class(ctx, "flash.geom", "Matrix3D",
		                                   b->object_class);
		(void) m3;
		Avm2Class* pp = avm2_builtin_class(ctx, "flash.geom",
		                                   "PerspectiveProjection",
		                                   b->object_class);
		(void) pp;
		Avm2Class* v3 = avm2_builtin_class(ctx, "flash.geom", "Vector3D",
		                                   b->object_class);
		v3->instance_init.fn = geom_vector3d_init;
		v3->instance_init.debug_name = "Vector3D";
	}

	// flash.geom.ColorTransform (8 numeric slots + FP toString).
	{
		Avm2Class* ct = avm2_builtin_class(ctx, "flash.geom", "ColorTransform",
		                                   b->object_class);
		ct->flags |= AVM2_CLASS_FLAG_SEALED;
		ct->instance_init.fn = colortransform_init;
		ct->instance_init.debug_name = "ColorTransform";
		static const char* const ct_fields[8] = {
			"redMultiplier", "greenMultiplier", "blueMultiplier",
			"alphaMultiplier", "redOffset", "greenOffset", "blueOffset",
			"alphaOffset",
		};
		for (int i = 0; i < 8; i++)
		{
			Avm2PropEntry e;
			memset(&e, 0, sizeof(e));
			e.key = avm2_public_key(ct_fields[i], (uint32_t) strlen(ct_fields[i]));
			e.kind = AVM2_PROP_SLOT;
			e.slot_index = ct->ivtable.slot_count + 1;
			e.defining_class = ct;
			ct->ivtable.slot_count++;
			avm2_vtable_append(ctx, &ct->ivtable, &e);
		}
		avm2_builtin_add_method(ctx, ct, "toString", colortransform_to_string);
		g_colortransform_class = ct;
	}

	// flash.display.FrameLabel (extends EventDispatcher) + Scene.
	Avm2Class* framelabel = avm2_builtin_class(ctx, "flash.display", "FrameLabel",
	                                           b->event_dispatcher_class);
	framelabel->instance_init.fn = framelabel_init;
	framelabel->instance_init.debug_name = "FrameLabel";
	avm2_builtin_add_getter(ctx, framelabel, "name", framelabel_get_name);
	avm2_builtin_add_getter(ctx, framelabel, "frame", framelabel_get_frame);
	g_frame_label_class = framelabel;
	Avm2Class* scene = avm2_builtin_class(ctx, "flash.display", "Scene",
	                                      b->object_class);
	scene->instance_init.fn = scene_init;
	scene->instance_init.debug_name = "Scene";
	avm2_builtin_add_getter(ctx, scene, "name", scene_get_name);
	avm2_builtin_add_getter(ctx, scene, "labels", scene_get_labels);
	avm2_builtin_add_getter(ctx, scene, "numFrames", scene_get_num_frames);
	g_scene_class = scene;

	// flash.display.SimpleButton.
	Avm2Class* button =
		avm2_builtin_class(ctx, "flash.display", "SimpleButton", iobj);
	button->native_init = display_native_init;
	button->instance_init.fn = simplebutton_init;
	button->instance_init.debug_name = "SimpleButton";
	b->simple_button_class = button;
	add_getset(ctx, button, "upState", btn_get_up, btn_set_up);
	add_getset(ctx, button, "overState", btn_get_over, btn_set_over);
	add_getset(ctx, button, "downState", btn_get_down, btn_set_down);
	add_getset(ctx, button, "hitTestState", btn_get_hit, btn_set_hit);
	add_getset(ctx, button, "enabled", btn_enabled_get, btn_enabled_set);
	add_getset(ctx, button, "useHandCursor", btn_handcursor_get, btn_handcursor_set);
	add_getset(ctx, button, "trackAsMenu", btn_trackasmenu_get, btn_trackasmenu_set);

	// flash.display.Stage.
	Avm2Class* stage = avm2_builtin_class(ctx, "flash.display", "Stage", doc);
	stage->native_init = display_native_init;
	b->stage_class = stage;
	add_getset(ctx, stage, "frameRate", stage_get_frame_rate, stage_set_frame_rate);
	add_getset(ctx, stage, "color", stage_get_color, stage_set_color);
	add_getset(ctx, stage, "stageWidth", stage_get_stage_width,
	           stage_set_dimension_noop);
	add_getset(ctx, stage, "stageHeight", stage_get_stage_height,
	           stage_set_dimension_noop);
	avm2_builtin_add_getter(ctx, stage, "allowsFullScreen",
	                        stage_get_allows_fullscreen);
	avm2_builtin_add_getter(ctx, stage, "allowsFullScreenInteractive",
	                        stage_get_allows_fullscreen_interactive);
	avm2_builtin_add_getter(ctx, stage, "browserZoomFactor",
	                        stage_get_browser_zoom_factor);
	avm2_builtin_add_getter(ctx, stage, "contentsScaleFactor",
	                        stage_get_contents_scale_factor);
	add_getset(ctx, stage, "displayState", stage_get_display_state,
	           stage_set_quality);
	add_getset(ctx, stage, "quality", stage_get_quality, stage_set_quality);
	add_getset(ctx, stage, "stageFocusRect", stage_get_stage_focus_rect,
	           stage_set_stage_focus_rect);
	add_getset(ctx, stage, "align", stage_get_align, stage_set_align);
	add_getset(ctx, stage, "scaleMode", stage_get_scale_mode, stage_set_scale_mode);
	add_getset(ctx, stage, "focus", stage_get_focus, stage_set_focus);
	avm2_builtin_add_method(ctx, stage, "invalidate", stage_invalidate);
	// Stage overrides: DisplayObject-surface SETTERS throw 2071 (getters
	// still work); textSnapshot's GETTER throws too. mouseChildren is
	// exempt (stage_overriden_setters).
	{
		static const struct { const char* name; Avm2MethodFn getter; } ov[] = {
			{ "accessibilityImplementation", do_accessimpl_get },
			{ "accessibilityProperties", do_accessprops_get },
			{ "alpha", do_get_alpha }, { "blendMode", do_blendmode_get },
			{ "cacheAsBitmap", do_cab_get }, { "contextMenu", do_contextmenu_get },
			{ "filters", do_get_filters }, { "focusRect", io_get_focus_rect },
			{ "height", do_get_height }, { "mask", do_get_mask },
			{ "name", do_get_name }, { "opaqueBackground", do_opaquebg_get },
			{ "rotation", do_get_rotation }, { "rotationX", do_get_zero },
			{ "rotationY", do_get_zero }, { "rotationZ", do_get_rotation },
			{ "scale9Grid", do_scrollrect_get }, { "scaleX", do_get_scale_x },
			{ "scaleY", do_get_scale_y }, { "scaleZ", do_get_one },
			{ "scrollRect", do_scrollrect_get }, { "tabEnabled", io_get_tab_enabled },
			{ "tabIndex", io_get_tab_index }, { "transform", do_get_transform },
			{ "visible", do_get_visible }, { "width", do_get_width },
			{ "x", do_get_x }, { "y", do_get_y }, { "z", do_get_zero },
		};
		for (size_t i = 0; i < sizeof(ov) / sizeof(ov[0]); i++)
		{
			add_getset(ctx, stage, ov[i].name, ov[i].getter, stage_throw_2071);
		}
		avm2_builtin_add_getter(ctx, stage, "textSnapshot", stage_throw_2071);
	}

	// flash.display string-constant classes (Bitmap.pixelSnapping, blendMode,
	// and the Stage scaleMode/align/quality that FlashPunk's Engine sets at
	// startup). Pure constant bags — no instances.
	{
		Avm2Class* ps = avm2_builtin_class(ctx, "flash.display",
		                                   "PixelSnapping", b->object_class);
		disp_sconst(ctx, ps, "NEVER", "never");
		disp_sconst(ctx, ps, "AUTO", "auto");
		disp_sconst(ctx, ps, "ALWAYS", "always");

		Avm2Class* bm = avm2_builtin_class(ctx, "flash.display",
		                                   "BlendMode", b->object_class);
		static const char* const blends[][2] = {
			{"NORMAL","normal"},{"LAYER","layer"},{"MULTIPLY","multiply"},
			{"SCREEN","screen"},{"LIGHTEN","lighten"},{"DARKEN","darken"},
			{"DIFFERENCE","difference"},{"ADD","add"},{"SUBTRACT","subtract"},
			{"INVERT","invert"},{"ALPHA","alpha"},{"ERASE","erase"},
			{"OVERLAY","overlay"},{"HARDLIGHT","hardlight"},{"SHADER","shader"},
		};
		for (size_t i = 0; i < sizeof(blends)/sizeof(blends[0]); i++)
			disp_sconst(ctx, bm, blends[i][0], blends[i][1]);

		Avm2Class* ssm = avm2_builtin_class(ctx, "flash.display",
		                                    "StageScaleMode", b->object_class);
		disp_sconst(ctx, ssm, "EXACT_FIT", "exactFit");
		disp_sconst(ctx, ssm, "NO_BORDER", "noBorder");
		disp_sconst(ctx, ssm, "NO_SCALE", "noScale");
		disp_sconst(ctx, ssm, "SHOW_ALL", "showAll");

		Avm2Class* sal = avm2_builtin_class(ctx, "flash.display",
		                                    "StageAlign", b->object_class);
		static const char* const aligns[][2] = {
			{"TOP","T"},{"BOTTOM","B"},{"LEFT","L"},{"RIGHT","R"},
			{"TOP_LEFT","TL"},{"TOP_RIGHT","TR"},
			{"BOTTOM_LEFT","BL"},{"BOTTOM_RIGHT","BR"},
		};
		for (size_t i = 0; i < sizeof(aligns)/sizeof(aligns[0]); i++)
			disp_sconst(ctx, sal, aligns[i][0], aligns[i][1]);

		Avm2Class* sq = avm2_builtin_class(ctx, "flash.display",
		                                   "StageQuality", b->object_class);
		disp_sconst(ctx, sq, "LOW", "low");
		disp_sconst(ctx, sq, "MEDIUM", "medium");
		disp_sconst(ctx, sq, "HIGH", "high");
		disp_sconst(ctx, sq, "BEST", "best");
		disp_sconst(ctx, sq, "EIGHT_X_LINEAR", "8x8linear");
		disp_sconst(ctx, sq, "SIXTEEN_X_LINEAR", "16x16linear");

		// FlashPunk's Engine sets stage.displayState = StageDisplayState.NORMAL
		// at startup (Engine.as:113).
		Avm2Class* sds = avm2_builtin_class(ctx, "flash.display",
		                                    "StageDisplayState", b->object_class);
		disp_sconst(ctx, sds, "NORMAL", "normal");
		disp_sconst(ctx, sds, "FULL_SCREEN", "fullScreen");
		disp_sconst(ctx, sds, "FULL_SCREEN_INTERACTIVE", "fullScreenInteractive");

		// FlashPunk's Draw uses LineScaleMode for graphics.lineStyle.
		Avm2Class* lsm = avm2_builtin_class(ctx, "flash.display",
		                                    "LineScaleMode", b->object_class);
		disp_sconst(ctx, lsm, "NORMAL", "normal");
		disp_sconst(ctx, lsm, "HORIZONTAL", "horizontal");
		disp_sconst(ctx, lsm, "VERTICAL", "vertical");
		disp_sconst(ctx, lsm, "NONE", "none");
	}

	// flash.ui.Mouse / MouseCursor — FlashPunk's Splash sets Mouse.cursor to a
	// MouseCursor constant every frame. Headless has no cursor: store the value,
	// no-op hide/show.
	{
		Avm2Class* mc = avm2_builtin_class(ctx, "flash.ui",
		                                   "MouseCursor", b->object_class);
		disp_sconst(ctx, mc, "AUTO", "auto");
		disp_sconst(ctx, mc, "ARROW", "arrow");
		disp_sconst(ctx, mc, "BUTTON", "button");
		disp_sconst(ctx, mc, "HAND", "hand");
		disp_sconst(ctx, mc, "IBEAM", "ibeam");

		Avm2Class* mouse = avm2_builtin_class(ctx, "flash.ui",
		                                      "Mouse", b->object_class);
		avm2_builtin_add_static_getset(ctx, mouse, "cursor",
		                               mouse_get_cursor, mouse_set_cursor);
		avm2_builtin_add_static_method(ctx, mouse, "hide", mouse_noop);
		avm2_builtin_add_static_method(ctx, mouse, "show", mouse_noop);
	}

	// flash.ui.Keyboard — FlashPunk's Input.onKeyDown reads Keyboard.capsLock on
	// every printable keydown; if the class is unregistered, getlex flash.ui::
	// Keyboard throws #1065 and the key handler aborts (space/letters never
	// register in _key[], so only arrow keys — which skip that branch — would
	// work). Headless has no lock state, so capsLock/numLock are const false. The
	// key-code constants are provided for AS3 games that read Keyboard.LEFT etc.
	// directly (FlashPunk uses its own Key class, so Seedling only needs capsLock).
	{
		Avm2Class* kb = avm2_builtin_class(ctx, "flash.ui",
		                                   "Keyboard", b->object_class);
		avm2_builtin_add_static_const(ctx, kb, "capsLock", avm2_bool(false));
		avm2_builtin_add_static_const(ctx, kb, "numLock", avm2_bool(false));
		avm2_builtin_add_static_const(ctx, kb, "hasVirtualKeyboard", avm2_bool(false));

		// Named navigation / whitespace / modifier keys (Flash keyCode == DOM
		// keyCode == AS3 Keyboard constant for all of these).
		struct { const char* n; uint32_t c; } named[] = {
			{"BACKSPACE",8},{"TAB",9},{"ENTER",13},{"SHIFT",16},{"CONTROL",17},
			{"ALTERNATE",18},{"CAPS_LOCK",20},{"ESCAPE",27},{"SPACE",32},
			{"PAGE_UP",33},{"PAGE_DOWN",34},{"END",35},{"HOME",36},
			{"LEFT",37},{"UP",38},{"RIGHT",39},{"DOWN",40},
			{"INSERT",45},{"DELETE",46},
			{"NUMBER_0",48},{"NUMBER_1",49},{"NUMBER_2",50},{"NUMBER_3",51},
			{"NUMBER_4",52},{"NUMBER_5",53},{"NUMBER_6",54},{"NUMBER_7",55},
			{"NUMBER_8",56},{"NUMBER_9",57},
			{"SEMICOLON",186},{"EQUAL",187},{"COMMA",188},{"MINUS",189},
			{"PERIOD",190},{"SLASH",191},{"BACKQUOTE",192},{"LEFTBRACKET",219},
			{"BACKSLASH",220},{"RIGHTBRACKET",221},{"QUOTE",222},
		};
		for (size_t i = 0; i < sizeof(named)/sizeof(named[0]); i++)
			avm2_builtin_add_static_const(ctx, kb, named[i].n, avm2_uint_value(named[i].c));

		// Letters A..Z (keyCode 65..90) and numpad NUMPAD_0..9 (96..105).
		for (uint32_t c = 'A'; c <= 'Z'; c++)
		{
			char n[2] = { (char) c, 0 };
			avm2_builtin_add_static_const(ctx, kb, n, avm2_uint_value(c));
		}
		for (uint32_t i = 0; i <= 9; i++)
		{
			char n[12]; snprintf(n, sizeof(n), "NUMPAD_%u", i);
			avm2_builtin_add_static_const(ctx, kb, n, avm2_uint_value(96 + i));
		}
		for (uint32_t i = 1; i <= 15; i++)
		{
			char n[8]; snprintf(n, sizeof(n), "F%u", i);
			avm2_builtin_add_static_const(ctx, kb, n, avm2_uint_value(111 + i));
		}
	}

	// Stage parameters from the generated tables.
	g_stage_frame_rate = (double) (int16_t) avm2_generated_frame_rate / 256.0;
	g_stage_color = avm2_generated_bg_color & 0xFFFFFF;
}

// ===========================================================================
// AVM2 CPU-composite frame dump (env-gated: AVM2_CPU_DUMP=<path-prefix>).
//
// A GPU-free render-correctness sink for Seedling bring-up. It walks the SAME
// display tree the tick already built, inverse-maps each on-stage Bitmap's
// premultiplied-ARGB pixels into a plain CPU framebuffer, and writes a binary
// PPM (P6) per captured tick. It bypasses the WebGPU/lavapipe path entirely, so
// it validates render *correctness* (does the game produce the right pixels)
// even under the WSL2 lavapipe capture OOM, and in BOTH build modes — this
// block is compiled unconditionally (NOT under OFFSCREEN_RENDER). Scope matches
// Stage 9: the Bitmap/BitmapData blit path only (a FlashPunk display tree is
// just Bitmaps); shapes/gradients/text/masks are not composited.
// ===========================================================================

// Scale a premultiplied-ARGB colour by a 0..1 alpha factor (all four channels
// — premultiplied form makes this a straight per-channel multiply).
static uint32_t avm2_cpu_scale_premul(uint32_t c, double f)
{
	uint32_t a = (uint32_t) (((c >> 24) & 0xFF) * f + 0.5);
	uint32_t r = (uint32_t) (((c >> 16) & 0xFF) * f + 0.5);
	uint32_t g = (uint32_t) (((c >>  8) & 0xFF) * f + 0.5);
	uint32_t b = (uint32_t) ((( c      ) & 0xFF) * f + 0.5);
	return (a << 24) | (r << 16) | (g << 8) | b;
}

// Porter-Duff "over": premultiplied src on top of premultiplied dest
// (matches avm2_bitmap.c blend_over).
static uint32_t avm2_cpu_blend_over(uint32_t dest, uint32_t src)
{
	uint32_t sa = (src >> 24) & 0xFF;
	uint32_t inv = 255 - sa;
	uint32_t r = ((src >> 16) & 0xFF) + (((dest >> 16) & 0xFF) * inv) / 255;
	uint32_t g = ((src >>  8) & 0xFF) + (((dest >>  8) & 0xFF) * inv) / 255;
	uint32_t b = ( (src      ) & 0xFF) + (( (dest      ) & 0xFF) * inv) / 255;
	uint32_t a = sa + (((dest >> 24) & 0xFF) * inv) / 255;
	if (r > 255) r = 255; if (g > 255) g = 255; if (b > 255) b = 255; if (a > 255) a = 255;
	return (a << 24) | (r << 16) | (g << 8) | b;
}

// Composite one on-stage Bitmap into fb via inverse (dest->src) affine
// sampling, so upscales (FP.screen.scale) leave no holes. `world` maps local
// twips -> stage twips (sx = a*lx + c*ly + tx; sy = b*lx + d*ly + ty), and a
// bitmap pixel (px,py) lives at local twips (px*20, py*20) — the same
// convention render_webgpu_draw_bitmap_quad_scaled uses (1 px = 20 twips).
static void avm2_cpu_composite_bitmap(Avm2Context* ctx, Avm2Object* obj,
                                      const Mat* world, double alpha,
                                      uint32_t* fb, int fbw, int fbh)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->bitmap_data == NULL) return;
	Avm2BitmapDataExt* bd =
		avm2_bitmapdata_ext_of(ctx, avm2_object_value(ext->bitmap_data));
	if (bd == NULL || bd->disposed || bd->pixels == NULL
	    || bd->width == 0 || bd->height == 0)
		return;

	int bw = (int) bd->width, bh = (int) bd->height;
	double corners[4][2] = {
		{ 0.0, 0.0 }, { bw * 20.0, 0.0 },
		{ 0.0, bh * 20.0 }, { bw * 20.0, bh * 20.0 }
	};
	double minx = 1e30, miny = 1e30, maxx = -1e30, maxy = -1e30;
	for (int k = 0; k < 4; k++)
	{
		double lx = corners[k][0], ly = corners[k][1];
		double sx = world->a * lx + world->c * ly + world->tx;
		double sy = world->b * lx + world->d * ly + world->ty;
		if (sx < minx) minx = sx;
		if (sx > maxx) maxx = sx;
		if (sy < miny) miny = sy;
		if (sy > maxy) maxy = sy;
	}
	int px0 = (int) floor(minx / 20.0), px1 = (int) ceil(maxx / 20.0);
	int py0 = (int) floor(miny / 20.0), py1 = (int) ceil(maxy / 20.0);
	if (px0 < 0) px0 = 0;
	if (py0 < 0) py0 = 0;
	if (px1 > fbw) px1 = fbw;
	if (py1 > fbh) py1 = fbh;

	double det = world->a * world->d - world->c * world->b;
	if (det == 0.0) return;
	// [lx;ly] = inv([[a,c],[b,d]]) * [STx-tx; STy-ty]
	double ia = world->d / det, ic = -world->c / det;
	double ib = -world->b / det, id = world->a / det;

	for (int dy = py0; dy < py1; dy++)
	{
		for (int dx = px0; dx < px1; dx++)
		{
			double stx = (dx + 0.5) * 20.0 - world->tx;
			double sty = (dy + 0.5) * 20.0 - world->ty;
			double lx = ia * stx + ic * sty;
			double ly = ib * stx + id * sty;
			int spx = (int) floor(lx / 20.0);
			int spy = (int) floor(ly / 20.0);
			if (spx < 0 || spy < 0 || spx >= bw || spy >= bh) continue;
			uint32_t s = bd->pixels[spy * bw + spx];
			if (alpha < 0.999) s = avm2_cpu_scale_premul(s, alpha);
			if ((s >> 24) == 0) continue;  // fully transparent
			uint32_t* d = &fb[dy * fbw + dx];
			*d = avm2_cpu_blend_over(*d, s);
		}
	}
}

// Depth-ordered CPU composite walk (back-to-front paint order), accumulating
// world matrix + concatenated alpha — the CPU twin of avm2_render_node.
static void avm2_cpu_walk(Avm2Context* ctx, Avm2Object* obj,
                          const Mat* parent_world, double parent_alpha,
                          uint32_t* fb, int fbw, int fbh)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (!ext->is_stage && !ext->visible) return;

	Mat local = ext_matrix(ext);
	Mat world = mat_mul(parent_world, &local);
	double alpha = parent_alpha * ((double) ext->alpha_fixed8 / 256.0);

	if (ext->is_bitmap)
		avm2_cpu_composite_bitmap(ctx, obj, &world, alpha, fb, fbw, fbh);

	for (uint32_t i = 0; i < ext->render_len; i++)
		avm2_cpu_walk(ctx, ext->render_list[i], &world, alpha, fb, fbw, fbh);
}

// Env-gated per-tick dump. AVM2_CPU_DUMP=<prefix> writes <prefix>NNN.ppm for
// each tick (frame_index 0-based); AVM2_CPU_DUMP_FRAME=N restricts to one tick.
// Cheap no-op when AVM2_CPU_DUMP is unset. Called from the runSWF_avm2 tick
// loop after avm2_display_run_tick.
void avm2_cpu_dump_frame(Avm2Context* ctx, int frame_index)
{
	const char* prefix = getenv("AVM2_CPU_DUMP");
	if (prefix == NULL || prefix[0] == '\0') return;
	const char* onlys = getenv("AVM2_CPU_DUMP_FRAME");
	if (onlys != NULL && atoi(onlys) != frame_index) return;

	// Stage pixel dims from the recompiler's stage rect (twips) — usable in
	// NO_GRAPHICS builds where ctx->app (SWFAppContext) is an incomplete type.
	int fbw = (int) ((avm2_generated_stage_rect[1]
	                  - avm2_generated_stage_rect[0]) / 20);
	int fbh = (int) ((avm2_generated_stage_rect[3]
	                  - avm2_generated_stage_rect[2]) / 20);
	if (fbw <= 0 || fbh <= 0) return;

	uint32_t* fb = (uint32_t*) malloc((size_t) fbw * fbh * sizeof(uint32_t));
	if (fb == NULL) return;
	// Opaque stage background, premultiplied (alpha 255 => premul == straight).
	uint32_t bg = 0xFF000000u | (g_stage_color & 0xFFFFFFu);
	for (int i = 0; i < fbw * fbh; i++) fb[i] = bg;

	if (ctx->stage != NULL)
	{
		Mat id = mat_identity();
		avm2_cpu_walk(ctx, ctx->stage, &id, 1.0, fb, fbw, fbh);
	}

	char path[1024];
	snprintf(path, sizeof(path), "%s%03d.ppm", prefix, frame_index);
	FILE* f = fopen(path, "wb");
	if (f == NULL) { free(fb); return; }
	fprintf(f, "P6\n%d %d\n255\n", fbw, fbh);
	uint8_t* row = (uint8_t*) malloc((size_t) fbw * 3);
	if (row != NULL)
	{
		for (int y = 0; y < fbh; y++)
		{
			for (int x = 0; x < fbw; x++)
			{
				uint32_t c = fb[y * fbw + x];
				row[x * 3 + 0] = (uint8_t) ((c >> 16) & 0xFF);
				row[x * 3 + 1] = (uint8_t) ((c >>  8) & 0xFF);
				row[x * 3 + 2] = (uint8_t) ((c      ) & 0xFF);
			}
			fwrite(row, 1, (size_t) fbw * 3, f);
		}
		free(row);
	}
	fclose(f);
	free(fb);
	// Quiet by default (a 600-frame drive would otherwise flood stderr and bury
	// the AVM2-uncaught-error divergence signal); confirm every 50th frame.
	if (frame_index == 0 || (frame_index % 50) == 0)
		fprintf(stderr, "AVM2_CPU_DUMP: wrote %s (%dx%d)\n", path, fbw, fbh);
}

// ===========================================================================
// Stage 9 — minimal AVM2 render path (graphics mode only).
//
// A real render-tree traversal over the AVM2 display tree feeding the existing
// WebGPU offscreen backend (the same primitives the AVM1 tag.c renderer uses).
// Compiled ONLY in --mode=graphics builds (OFFSCREEN_RENDER); the NO_GRAPHICS
// runtime never sees this code. Scope: the Bitmap/BitmapData blit path (a
// FlashPunk display tree is just Bitmaps). Shapes/gradients/filters/masks are
// future work — Graphics records only an AABB today.
//
// The render backend (`context`, render_webgpu.c, capture.c) is already
// compiled + linkable in AVM2 graphics builds (verify_output.py adds swf.c +
// render_webgpu.c + capture.c whenever mode==graphics, regardless of AVM2), but
// runSWF_avm2 never drove it. avm2_render_init replicates swfStart's renderer
// setup; avm2_render_frame / avm2_render_finish drive the per-tick + final
// capture, mirroring swf.c/capture.c's last_frame/iteration/fs_command model.
// The render pass reads the SAME depth/render list the tick already built — it
// never re-runs any timeline/goto logic.
// ===========================================================================
// Render gate: the OFFSCREEN_RENDER (graphics-native test) sink AND the browser
// canvas sink (Stage 13a: __EMSCRIPTEN__ && !OFFSCREEN_RENDER, USE_WEBGPU). The
// tree-walk + world-matrix/alpha compose is shared; only the frame driver
// differs — OFFSCREEN captures a PNG, browser acquires+presents the swapchain
// surface (renderer_open_pass/close_pass do that internally). NO_GRAPHICS builds
// see none of this.
#if defined(OFFSCREEN_RENDER) || (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))

#include <renderer.h>
#include <libswf/swf.h>
#ifdef OFFSCREEN_RENDER
#include <libswf/capture.h>
#endif
#if defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)
#include <emscripten.h>
#endif

// Owned by swf.c (compiled in every graphics build); we drive the same handle.
extern RenderContext* context;

// Dynamic xform/cxform slot bump-allocators, past the recompiler's static slots
// (mirrors compose_children's per-frame slot model in tag.c). Bases are set in
// avm2_render_init from the static table sizes; the counters reset each frame.
static uint32_t g_avm2_xform_base = 1;
static uint32_t g_avm2_xform_next = 1;
static uint32_t g_avm2_cxform_base = 1;
static uint32_t g_avm2_cxform_next = 1;

// Flatten an affine Mat (a,b,c,d dimensionless; tx,ty twips) into the
// renderer's column-major mat4 (2D affine embedded), matching xform_buffer's
// layout. The shader computes ndc = stage_to_ndc * xform[id] * pos, and the
// bitmap quad's vertices are in local twips, so this world matrix maps local
// twips -> stage twips.
static void avm2_world_to_mat16(const Mat* m, float out[16])
{
	out[0]  = (float) m->a;  out[1]  = (float) m->b;  out[2]  = 0.0f; out[3]  = 0.0f;
	out[4]  = (float) m->c;  out[5]  = (float) m->d;  out[6]  = 0.0f; out[7]  = 0.0f;
	out[8]  = 0.0f;          out[9]  = 0.0f;          out[10] = 1.0f; out[11] = 0.0f;
	out[12] = (float) m->tx; out[13] = (float) m->ty; out[14] = 0.0f; out[15] = 1.0f;
}

// Blit one Bitmap node: its BitmapData's premultiplied-ARGB pixels as a
// textured quad under the node's world matrix + concatenated alpha. The
// renderer uses a premultiplied-alpha blend, and the pixel store is already
// premultiplied ARGB (0xAARRGGBB), so no conversion is needed.
static void avm2_render_bitmap(Avm2Context* ctx, Avm2Object* obj,
                               const Mat* world, double alpha)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->bitmap_data == NULL) return;
	Avm2BitmapDataExt* bd =
		avm2_bitmapdata_ext_of(ctx, avm2_object_value(ext->bitmap_data));
	if (bd == NULL || bd->disposed || bd->pixels == NULL
	    || bd->width == 0 || bd->height == 0)
		return;
	// Honest failure: a BitmapData larger than the dynamic layer is skipped
	// (blank) rather than corrupting the texture / crashing.
	if (bd->width > context->dynamic_bitmap_max_w
	    || bd->height > context->dynamic_bitmap_max_h)
		return;

	// Per-object world transform slot.
	uint32_t xid = 0;  // identity fallback if we run out of slots
	if (g_avm2_xform_next < context->xform_slot_count)
	{
		float m16[16];
		avm2_world_to_mat16(world, m16);
		xid = g_avm2_xform_next++;
		renderer_write_transform(context, xid, m16);
	}

	// Concatenated-alpha cxform slot (0 = identity for the common alpha == 1).
	uint32_t cxid = 0;
	if (alpha < 0.999 && g_avm2_cxform_next < context->cxform_slot_count)
	{
		float cx[20];
		memset(cx, 0, sizeof(cx));
		cx[0] = 1.0f; cx[5] = 1.0f; cx[10] = 1.0f;  // r/g/b multiply = 1
		cx[15] = (float) alpha;                      // alpha multiply
		cxid = g_avm2_cxform_next++;
		renderer_write_cxform(context, cxid, cx);
	}

	renderer_draw_bitmap_quad_scaled(context, bd->pixels,
		bd->width, bd->height, bd->width, bd->height,
		0.0f, 0.0f, xid, cxid);
}

// Draw one solid-fill timeline shape node (T1): its pre-tessellated triangles
// (resident shape_data vertex range, resolved onto the ext at place-time) under
// the node's world matrix + concatenated alpha. Mirrors avm2_render_bitmap's
// slot-write model, swapping the bitmap quad for renderer_draw_shape — which
// reads the shape_data verts (shape-local Flash Y-down twips) and shades each
// FILL_SOLID triangle from the per-vertex color index (WGSL shader). The world
// matrix maps local twips -> stage twips (Y-down), then stage_to_ndc; no
// coordinate flip is applied because shape_data already stores shape-local
// Y-down coordinates (the recompiler's FRAME_HEIGHT round-trip cancels).
static void avm2_render_shape(Avm2Context* ctx, Avm2Object* obj,
                              const Mat* world, double alpha)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->shape_vert_count == 0) return;

	// Per-object world transform slot (identity fallback if slots run out).
	uint32_t xid = 0;
	if (g_avm2_xform_next < context->xform_slot_count)
	{
		float m16[16];
		avm2_world_to_mat16(world, m16);
		xid = g_avm2_xform_next++;
		renderer_write_transform(context, xid, m16);
	}

	// Concatenated-alpha cxform slot (0 = identity for the common alpha == 1).
	uint32_t cxid = 0;
	if (alpha < 0.999 && g_avm2_cxform_next < context->cxform_slot_count)
	{
		float cx[20];
		memset(cx, 0, sizeof(cx));
		cx[0] = 1.0f; cx[5] = 1.0f; cx[10] = 1.0f;  // r/g/b multiply = 1
		cx[15] = (float) alpha;                      // alpha multiply
		cxid = g_avm2_cxform_next++;
		renderer_write_cxform(context, cxid, cx);
	}

	renderer_draw_shape(context, ext->shape_vert_offset, ext->shape_vert_count,
	                    xid, cxid);
}

// Depth-ordered render-list walk (paint order, back-to-front), accumulating the
// world matrix + concatenated alpha down the tree. Invisible subtrees are
// culled, matching render_apply_text_bounds.
static void avm2_render_node(Avm2Context* ctx, Avm2Object* obj,
                             const Mat* parent_world, double parent_alpha)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (!ext->is_stage && !ext->visible) return;

	Mat local = ext_matrix(ext);
	Mat world = mat_mul(parent_world, &local);
	double alpha = parent_alpha * ((double) ext->alpha_fixed8 / 256.0);

	if (ext->is_bitmap)
		avm2_render_bitmap(ctx, obj, &world, alpha);
	else if (ext->shape_vert_count > 0)
		avm2_render_shape(ctx, obj, &world, alpha);

	for (uint32_t i = 0; i < ext->render_len; i++)
		avm2_render_node(ctx, ext->render_list[i], &world, alpha);
}

static void avm2_render_walk(Avm2Context* ctx)
{
	renderer_open_pass(context);
	g_avm2_xform_next = g_avm2_xform_base;
	g_avm2_cxform_next = g_avm2_cxform_base;
	Mat id = mat_identity();
	if (ctx->stage != NULL)
		avm2_render_node(ctx, ctx->stage, &id, 1.0);
	renderer_close_pass(context);
}

// Replicate swfStart's renderer setup for the AVM2 entry (runSWF_avm2 never
// called renderer_new/init). Must run AFTER heap_init (renderer_init uses the
// heap allocator) and AFTER build_stage (reads g_stage_color for the clear).
void avm2_render_init(Avm2Context* ctx)
{
	SWFAppContext* app = ctx->app;
	context = renderer_new();

	context->width = app->width;
	context->height = app->height;
	context->stage_to_ndc = app->stage_to_ndc;
	context->bitmap_count = app->bitmap_count;
	context->bitmap_highest_w = app->bitmap_highest_w;
	context->bitmap_highest_h = app->bitmap_highest_h;
	context->shape_data = app->shape_data;
	context->shape_data_size = app->shape_data_size;
	context->transform_data = app->transform_data;
	context->transform_data_size = app->transform_data_size;
	context->color_data = app->color_data;
	context->color_data_size = app->color_data_size;
	context->uninv_mat_data = app->uninv_mat_data;
	context->uninv_mat_data_size = app->uninv_mat_data_size;
	context->gradient_data = app->gradient_data;
	context->gradient_data_size = app->gradient_data_size;
	context->bitmap_data = app->bitmap_data;
	context->bitmap_data_size = app->bitmap_data_size;
	context->cxform_data = app->cxform_data;
	context->cxform_data_size = app->cxform_data_size;

	// Dynamic bitmap-layer dims. AVM2 has no static bitmaps (BITMAP_COUNT 0),
	// so the dynamic layer is sized to dynamic_bitmap_max_{w,h}+1 (render_webgpu
	// init) and every runtime BitmapData blits into it. Cover the whole stage;
	// larger BitmapData is skipped (blank) in avm2_render_bitmap.
	uint32_t maxdim = app->width > app->height ? app->width : app->height;
	if (maxdim < 256) maxdim = 256;
	context->dynamic_bitmap_max_w = maxdim;
	context->dynamic_bitmap_max_h = maxdim;

	// Stage background (opaque); g_stage_color was set by build_stage.
	context->red   = (u8) ((g_stage_color >> 16) & 0xFF);
	context->green = (u8) ((g_stage_color >> 8) & 0xFF);
	context->blue  = (u8) (g_stage_color & 0xFF);

	// Dynamic slot bases = count of the recompiler's static xform/cxform slots.
	g_avm2_xform_base = app->transform_data_size
		? (uint32_t) (app->transform_data_size / (16 * sizeof(float))) : 1;
	g_avm2_cxform_base = app->cxform_data_size
		? (uint32_t) (app->cxform_data_size / (20 * sizeof(float))) : 1;

	renderer_init(app, context);
#ifdef OFFSCREEN_RENDER
	// Capture triggers are a graphics-native-test concept (CAPTURE_TRIGGERS env);
	// capture.c isn't linked in the browser build.
	parse_capture_triggers();
#endif
}

#ifdef OFFSCREEN_RENDER
// One rendered frame + the per-tick capture scheduling (last_frame /
// iteration). Called at the tail of each tick, after avm2_display_run_tick.
// OFFSCREEN (graphics-native test) sink only.
void avm2_render_frame(Avm2Context* ctx)
{
	if (context == NULL || !context->renderer_ok) return;
	capture_tick_pre_frame();
	avm2_render_walk(ctx);
	capture_tick_post_frame();
}

// End-of-run: force a final capture + save any unsaved last_frame entries,
// mirroring swfStart's tail.
void avm2_render_finish(Avm2Context* ctx)
{
	if (context == NULL || !context->renderer_ok) return;
	renderer_request_capture(context);
	avm2_render_walk(ctx);
	capture_save_last_frame();
}
#endif  // OFFSCREEN_RENDER

#if defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)
// Stage 13a browser sink: paint one frame onto the real canvas swapchain. The
// SAME depth-ordered tree walk as OFFSCREEN, but renderer_open_pass acquires the
// current surface texture and renderer_close_pass presents it (see
// render_webgpu.c's __EMSCRIPTEN__ && !OFFSCREEN_RENDER surface path) — no PNG
// readback, no capture bookkeeping. renderer_poll is a no-op event drain in the
// browser (mouse/key arrive via emscripten callbacks) but is kept for symmetry
// with swf.c's loop and so a window-close returns nonzero.
int avm2_render_present(Avm2Context* ctx)
{
	if (context == NULL || !context->renderer_ok) return 0;
	avm2_render_walk(ctx);
	return renderer_poll(ctx->app);
}
#endif

#endif  // render gate
