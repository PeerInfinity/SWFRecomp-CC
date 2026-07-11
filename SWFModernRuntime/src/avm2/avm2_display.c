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
#include <stdio.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
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
	for (uint32_t i = 0; i < g_symbol_map_count; i++)
	{
		if (g_symbol_map[i].cls == cls) return g_symbol_map[i].char_id;
	}
	return 0;
}

// While instantiating a timeline child the alloc hook must not apply the
// script-created extras (skip flag, orphan registration, symbol lookup).
static int g_timeline_instantiation;

// ---------------------------------------------------------------------------
// Static-table lookups
// ---------------------------------------------------------------------------

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

// bounds_with_transform: self bounds + children, all through `m`.
static void bounds_with_transform(Avm2Context* ctx, Avm2Object* obj,
                                  const Mat* m, Rect* acc)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (ext->char_id != 0)
	{
		Rect self = char_self_bounds(ext->char_id);
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
	snprintf(buf, sizeof(buf), "instance%u", ctx->instance_counter);
	ctx->instance_counter++;
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
static void full_remove_child(Avm2Context* ctx, Avm2DisplayObjectExt* pext,
                              Avm2Object* child)
{
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
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
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				Avm2Value cur = avm2_get_public_property(
					ctx, avm2_object_value(cext->parent),
					cext->name->utf8, cext->name->len, NULL);
				if (cur.kind == AVM2_VALUE_OBJECT && cur.u.obj == child)
				{
					avm2_set_public_property(ctx, avm2_object_value(cext->parent),
					                         cext->name->utf8, cext->name->len,
					                         avm2_null());
				}
			}
			avm2_try_pop_frame(&top);
		}
		cext->parent = NULL;
		orphan_add(ctx, child);
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
		avm2_call_method_ref(ctx, &cls->instance_init, cls, cls->scope,
		                     avm2_object_value(obj), NULL, 0);
	}
	avm2_try_pop_frame(&top);
}

static void enter_frame_obj(Avm2Context* ctx, Avm2Object* obj);
static void construct_frame_obj(Avm2Context* ctx, Avm2Object* obj);
static void run_frame_scripts_obj(Avm2Context* ctx, Avm2Object* obj);
static void run_goto(Avm2Context* ctx, Avm2Object* obj, uint16_t frame, int is_implicit);
static void on_construction_complete(Avm2Context* ctx, Avm2Object* obj);

// catchup_display_object_to_frame (Ruffle frame_lifecycle.rs).
static void catchup_to_frame(Avm2Context* ctx, Avm2Object* obj)
{
	if (ctx->frame_phase == PHASE_ENTER)
	{
		enter_frame_obj(ctx, obj);
	}
	else
	{
		enter_frame_obj(ctx, obj);
		construct_frame_obj(ctx, obj);
	}
}

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
			if (cls != NULL) return cls;
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
		default:
			return ctx->builtins.movieclip_class;
	}
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
	cext->timeline = timeline_for_char(op->char_id);
	Avm2Object* prev = replace_at_depth(ctx, pext, child, op->depth);
	cext->instantiated_by_timeline = 1;
	cext->depth = op->depth;
	cext->parent = parent;
	cext->place_frame = pext->current_frame;
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
	set_default_instance_name(ctx, cext);
	enter_frame_obj(ctx, child);
	if (prev != NULL)
	{
		dispatch_removed_event(ctx, prev);
	}
	return child;
}

// Timeline place op against a live display list (non-goto path).
static void run_place_op(Avm2Context* ctx, Avm2Object* parent, const Avm2TimelineOp* op)
{
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	if (pext == NULL) return;
	if (op->flags & AVM2_TLF_HAS_CHAR)
	{
		instantiate_child(ctx, parent, op);
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
	return ext->timeline != NULL ? ext->timeline->frame_count : 1;
}

static uint32_t total_frames(const Avm2DisplayObjectExt* ext)
{
	if (ext->timeline == NULL) return 1;
	uint32_t declared = ext->timeline->declared_frames;
	return declared > 0 ? declared : ext->timeline->frame_count;
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
				ext->queued_places[ext->queued_place_count++] = (int32_t) i;
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
	int needs_construction = !ext->constructed;
	ext->loop_queued = 0;
	if (needs_construction)
	{
		ext->constructed = 1;
		display_run_constructor(ctx, obj);
		on_construction_complete(ctx, obj);
	}
	else
	{
		for (uint32_t i = 0; i < ext->render_len; i++)
		{
			construct_frame_obj(ctx, ext->render_list[i]);
		}
	}
	if (ctx->frame_phase == PHASE_CONSTRUCT)
	{
		check_has_pending_script(ext);
	}
}

static void on_construction_complete(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	if (!ext->placed_by_avm2_script && ext->parent != NULL)
	{
		dispatch_simple_event(ctx, obj, "added", 1);
		if (is_on_stage(ctx, obj))
		{
			dispatch_added_to_stage_recursive(ctx, obj);
		}
	}
	// set_on_parent_field (Ruffle DO:2328): a timeline child with an
	// explicit name becomes a property on its parent.
	if (!ext->placed_by_avm2_script && ext->has_explicit_name
	    && ext->name != NULL && ext->parent != NULL)
	{
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
	if (ext == NULL) return;
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

	if (is_rewind)
	{
		// Remove children that don't survive the rewind.
		for (uint32_t i = ext->render_len; i > 0; i--)
		{
			Avm2Object* child = ext->render_list[i - 1];
			Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
			if (cext == NULL) continue;
			int survives = 0;
			if (cext->placed_by_avm2_script)
			{
				remove_child_from_depth_list(ext, child);
				continue;
			}
			// Survives if a final placement at the same depth places the
			// same character (reuse), and it was placed at or before the
			// target frame.
			for (uint32_t k = 0; k < cmd_count; k++)
			{
				if (cmds[k].depth == cext->depth && cmds[k].place != NULL
				    && cmds[k].place->char_id == cext->char_id)
				{
					survives = 1;
					break;
				}
			}
			if (!survives)
			{
				full_remove_child(ctx, ext, child);
			}
		}
	}

	ext->current_frame = clamped;
	ext->queued_script_frame = clamped;
	if (ext->last_queued_script_frame != (int32_t) clamped)
	{
		ext->last_queued_script_frame = -1;
	}

	// Materialize commands in op order: reuse matching children, create
	// the rest.
	for (uint32_t k = 0; k < cmd_count; k++)
	{
		const GotoCmd* cmd = &cmds[k];
		Avm2Object* child = child_by_depth(ext, cmd->depth);
		Avm2DisplayObjectExt* cext = child != NULL
			? avm2_display_ext_of(ctx, child) : NULL;
		if (child != NULL && cext != NULL && cext->char_id == cmd->place->char_id)
		{
			apply_place_object(ctx, child, cmd->place);
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
	return avm2_number(ext != NULL ? twips_to_pixels(ext->mtx_tx) : 0);
}

static Avm2Value do_set_x(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->mtx_tx = twips_from_pixels(avm2_coerce_to_number(act->ctx, act->args[0]));
	}
	return avm2_undefined();
}

static Avm2Value do_get_y(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	return avm2_number(ext != NULL ? twips_to_pixels(ext->mtx_ty) : 0);
}

static Avm2Value do_set_y(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->mtx_ty = twips_from_pixels(avm2_coerce_to_number(act->ctx, act->args[0]));
	}
	return avm2_undefined();
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
	double rem = fmod(ext->rotation_deg, 360.0);
	return avm2_number(rem <= 180.0 ? rem : rem - 360.0);
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
	Rect r = display_bounds(act->ctx, this_obj(act), 1);
	return avm2_number(rect_width_px(&r));
}

static Avm2Value do_get_height(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_number(0);
	Rect r = display_bounds(act->ctx, this_obj(act), 1);
	return avm2_number(rect_height_px(&r));
}

// set_width/set_height (Ruffle TDisplayObject::set_width/set_height).
static void set_width_height(Avm2Activation* act, int is_width)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || act->argc < 1) return;
	double value = avm2_coerce_to_number(act->ctx, act->args[0]);
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
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
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

static Avm2Value do_get_mouse_x(Avm2Activation* act)
{
	(void) act;
	return avm2_number(0);  // no input injection in trace tests
}

static Avm2Value do_get_mouse_y(Avm2Activation* act)
{
	(void) act;
	return avm2_number(0);
}

static Avm2Value do_get_loader_info(Avm2Activation* act)
{
	(void) act;
	return avm2_null();
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

	int64_t frame = 0;
	Avm2Value arg = act->args[0];
	int is_int = (arg.kind == AVM2_VALUE_INTEGER)
	             || (arg.kind == AVM2_VALUE_NUMBER
	                 && arg.u.d == floor(arg.u.d) && isfinite(arg.u.d)
	                 && fabs(arg.u.d) <= 2147483647.0);
	if (is_int)
	{
		int32_t i = arg.kind == AVM2_VALUE_INTEGER ? arg.u.i : (int32_t) arg.u.d;
		frame = (int64_t) i + scene_offset;
	}
	else
	{
		const Avm2String* s = avm2_coerce_to_string(ctx, arg);
		double n = avm2_string_to_int(s->utf8, s->len, 10, true);
		if (!isnan(n))
		{
			frame = (int64_t) n + scene_offset;
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
	if (frame > 65535) frame = 65535;
	mc_goto_frame(ctx, obj, (uint16_t) frame, stop);
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
	return avm2_null();
}

static Avm2Value stage_set_focus(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Avm2Value stage_invalidate(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
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
	ext->playing = 1;
	ext->queued_goto_frame = -1;
	ext->last_queued_script_frame = -1;
	ext->tab_index = -1;

	if (!g_timeline_instantiation)
	{
		// Script-created (Ruffle AVM2 display-object allocator): attach
		// the symbol timeline for SymbolClass-bound classes, auto-name,
		// catch up to the current phase, and skip the first enterFrame.
		ext->constructed = 1;
		uint16_t char_id = char_for_class(obj->cls);
		if (char_id != 0)
		{
			ext->char_id = char_id;
			ext->timeline = timeline_for_char(char_id);
		}
		set_default_instance_name(ctx, ext);
		orphan_add(ctx, obj);
		catchup_to_frame(ctx, obj);
		ext->skip_next_enter_frame = 1;
	}
}

// Sprite constructor body (runs at super() time): constructChildren —
// timeline children placed before the ctor get their constructors here.
static Avm2Value sprite_ctor_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* obj = this_obj(act);
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	for (uint32_t i = 0; i < ext->render_len; i++)
	{
		Avm2Object* child = ext->render_list[i];
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
		if (cext != NULL && !cext->constructed)
		{
			cext->constructed = 1;
			display_run_constructor(ctx, child);
			on_construction_complete(ctx, child);
		}
	}
	(void) obj;
	return avm2_undefined();
}

// ===========================================================================
// Registration
// ===========================================================================

static void add_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                       Avm2MethodFn getter, Avm2MethodFn setter)
{
	avm2_builtin_add_getset(ctx, cls, name, getter, setter);
}

void avm2_register_display(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;

	Avm2Class* dobj =
		avm2_builtin_class(ctx, "flash.display", "DisplayObject",
		                   b->event_dispatcher_class);
	dobj->native_ext_size = sizeof(Avm2DisplayObjectExt);
	dobj->native_init = display_native_init;
	b->display_object_class = dobj;
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
	avm2_builtin_add_getter(ctx, dobj, "parent", do_get_parent);
	avm2_builtin_add_getter(ctx, dobj, "root", do_get_root);
	avm2_builtin_add_getter(ctx, dobj, "stage", do_get_stage);
	avm2_builtin_add_getter(ctx, dobj, "mouseX", do_get_mouse_x);
	avm2_builtin_add_getter(ctx, dobj, "mouseY", do_get_mouse_y);
	avm2_builtin_add_getter(ctx, dobj, "loaderInfo", do_get_loader_info);

	Avm2Class* iobj =
		avm2_builtin_class(ctx, "flash.display", "InteractiveObject", dobj);
	b->interactive_object_class = iobj;
	add_getset(ctx, iobj, "mouseEnabled", io_get_mouse_enabled, io_set_mouse_enabled);
	add_getset(ctx, iobj, "doubleClickEnabled", io_get_double_click_enabled,
	           io_set_double_click_enabled);
	add_getset(ctx, iobj, "tabEnabled", io_get_tab_enabled, io_set_tab_enabled);
	add_getset(ctx, iobj, "tabIndex", io_get_tab_index, io_set_tab_index);
	add_getset(ctx, iobj, "focusRect", io_get_focus_rect, io_set_focus_rect);

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
	b->sprite_class = sprite;

	Avm2Class* movieclip = avm2_builtin_class(ctx, "flash.display", "MovieClip", sprite);
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
	b->shape_class = shape;

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

	// flash.display.SimpleButton (structural stub until tranche 5).
	Avm2Class* button =
		avm2_builtin_class(ctx, "flash.display", "SimpleButton", iobj);
	b->simple_button_class = button;

	// flash.display.Stage.
	Avm2Class* stage = avm2_builtin_class(ctx, "flash.display", "Stage", doc);
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

	// Stage parameters from the generated tables.
	g_stage_frame_rate = (double) (int16_t) avm2_generated_frame_rate / 256.0;
	g_stage_color = avm2_generated_bg_color & 0xFFFFFF;
}
