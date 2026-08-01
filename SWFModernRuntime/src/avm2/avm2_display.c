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
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <avm2/avm2_class.h>
#include <avm2/avm2_cpu_raster.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_filters.h>
#include <tesselator.h>  // T4 Part B: runtime Graphics tessellation (libtess2)
#include <memory/heap.h>

#include <avm2/avm2_gc.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>
#include <avm2/avm2_value.h>
#include <dialog_events.h>
#include <socket_events.h>
// findDataFile / findMovieEntry: the build-time registries of bundled sibling
// assets that flash.display.Loader loads from (see the load pipeline below).
#include <libswf/swf.h>
// swf_log_fetch_* / SWF_LOG_FETCH_ENABLED: the Ruffle test-navigator request
// log, shared with the AVM1 runtime (see the fetch-log block below).
#include <utils.h>

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

// Catch-up walk gate (defined below, next to the walks it guards).
void avm2_display_mark_frame_work(Avm2Context* ctx, Avm2Object* obj);
static Avm2DisplayObjectExt* display_ext_fast(Avm2Object* obj);
static void mark_attached(Avm2Context* ctx, Avm2DisplayObjectExt* cext,
                          Avm2Object* parent);

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
// The subset of g_orphans that may need a catch-up walk (see "Catch-up walk
// gate"). A build loop that creates and detaches thousands of clips leaves
// tens of thousands of legitimately parentless orphans behind; walking that
// whole list on every goto is the same O(n^2) trap as walking a clean
// subtree. Entries here are candidates only — each is re-validated on use.
static Avm2Object** g_orphan_dirty;
static uint32_t g_orphan_dirty_count, g_orphan_dirty_cap;
// Attach events since the last compaction: the compaction (dropping entries
// that regained a parent) is a pure size optimization — the walk loops skip
// parented entries anyway — so it is amortized instead of run per goto.
static uint32_t g_orphan_reparented;

static void orphan_dirty_push(Avm2Context* ctx, Avm2Object* obj)
{
	if (g_orphan_dirty_count == g_orphan_dirty_cap)
	{
		uint32_t nc = g_orphan_dirty_cap > 0 ? g_orphan_dirty_cap * 2 : 16;
		Avm2Object** grown = avm2_alloc(ctx, nc * sizeof(Avm2Object*));
		memcpy(grown, g_orphan_dirty, g_orphan_dirty_count * sizeof(Avm2Object*));
		g_orphan_dirty = grown;
		g_orphan_dirty_cap = nc;
	}
	g_orphan_dirty[g_orphan_dirty_count++] = obj;
}

static void orphan_add(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* e = display_ext_fast(obj);
	// in_orphan_list replaces the old linear membership scan, which was
	// itself quadratic once the list ran to tens of thousands of entries.
	if (e == NULL || e->in_orphan_list) return;
	if (g_orphan_count == g_orphan_cap)
	{
		uint32_t nc = g_orphan_cap > 0 ? g_orphan_cap * 2 : 16;
		Avm2Object** grown = avm2_alloc(ctx, nc * sizeof(Avm2Object*));
		memcpy(grown, g_orphans, g_orphan_count * sizeof(Avm2Object*));
		g_orphans = grown;
		g_orphan_cap = nc;
	}
	e->in_orphan_list = 1;
	g_orphans[g_orphan_count++] = obj;
	avm2_display_mark_frame_work(ctx, obj);
	orphan_dirty_push(ctx, obj);
}

// A dirty-list entry is walkable only while it is still a parentless member
// of the orphan list with pending work.
static Avm2DisplayObjectExt* orphan_dirty_ext(Avm2Object* obj, int gate)
{
	Avm2DisplayObjectExt* e = display_ext_fast(obj);
	if (e == NULL || e->parent != NULL || !e->in_orphan_list) return NULL;
	if (gate && e->walk_clean) return NULL;
	return e;
}

// Drop entries that are done; keeps the candidate list proportional to the
// work actually outstanding.
static void orphan_dirty_compact(void)
{
	uint32_t w = 0;
	for (uint32_t i = 0; i < g_orphan_dirty_count; i++)
	{
		if (orphan_dirty_ext(g_orphan_dirty[i], 1) != NULL)
		{
			g_orphan_dirty[w++] = g_orphan_dirty[i];
		}
	}
	g_orphan_dirty_count = w;
}

static void orphan_cleanup(Avm2Context* ctx)
{
	(void) ctx;
	orphan_dirty_compact();
	// Ruffle compacts the orphan list on every inner goto; for us that is a
	// pure optimization (the walks skip re-parented entries), so amortize it.
	if (g_orphan_reparented < 64) return;
	g_orphan_reparented = 0;
	uint32_t w = 0;
	for (uint32_t i = 0; i < g_orphan_count; i++)
	{
		Avm2DisplayObjectExt* ext = display_ext_fast(g_orphans[i]);
		if (ext != NULL && ext->parent == NULL)
		{
			g_orphans[w++] = g_orphans[i];
		}
		else if (ext != NULL)
		{
			ext->in_orphan_list = 0;
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
static uint32_t g_symbol_map_cap;

static void symbol_map_add(Avm2Class* cls, uint16_t char_id)
{
	if (cls == NULL || char_id == 0) return;
	if (g_symbol_map_count >= g_symbol_map_cap) return;
	for (uint32_t i = 0; i < g_symbol_map_count; i++)
		if (g_symbol_map[i].cls == cls) return;   // first binding wins
	g_symbol_map[g_symbol_map_count].cls = cls;
	g_symbol_map[g_symbol_map_count].char_id = char_id;
	g_symbol_map_count++;
}

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
static Avm2Class* g_video_class;
static Avm2Class* g_morphshape_class;
static uint8_t g_stage_invalidated_flag;

// Child movies loaded through flash.display.Loader (loader-arc tranche 6).
// The MAIN movie is never in this list — it stays on the avm2_generated_*
// globals, which every one of the ~97 table-reading sites keeps using
// unchanged. Only the char lookups below gain a second place to look, and
// because a child's char ids are offset by its char_id_base at emission,
// the key stays a bare id and a parent id can never match a child row.
#define AVM2_MAX_CHILD_MOVIES 8
static const Avm2MovieTables* g_child_movies[AVM2_MAX_CHILD_MOVIES];
static uint32_t g_child_movie_count;

// char_for_class, but also across CHILD movies (Ruffle `class_symbol`, which
// is keyed by the class's OWN movie). g_symbol_map is built ONCE, at stage
// build, from the main movie's rows, so a class defined by a Loader-loaded SWF
// is invisible to char_for_class. Matching goes the other way here: a child
// class's binding is looked up in the tables of the movie that DEFINES it, by
// qualified name — the class object itself cannot be reached by name from the
// root scope when the child loaded into a fresh ApplicationDomain, which is
// exactly the case Font.registerFont on a getDefinition() result hits.
// Kept a separate entry point so the hot instantiation path stays a pointer
// scan; only script code that can name a child's class needs the slow arm.
uint16_t avm2_display_child_char_for_class(Avm2Context* ctx, Avm2Class* cls)
{
	(void) ctx;
	uint16_t id = char_for_class(cls);
	if (id != 0) return id;
	for (Avm2Class* c = cls; c != NULL; c = c->super_class)
	{
		if (c->instance_init.file == NULL) continue;  // builtin
		const Avm2MovieTables* t =
			avm2_display_movie_for_abc(c->instance_init.file->data);
		if (t == NULL) continue;                      // the MAIN movie: done above
		char qn[256];
		avm2_class_qname_buf(c, qn, sizeof(qn));
		for (uint32_t i = 0; i < t->symbol_class_count; i++)
		{
			if (t->symbol_classes[i].char_id == 0) continue;
			const char* n = t->symbol_classes[i].class_name;
			if (n != NULL && strcmp(n, qn) == 0) return t->symbol_classes[i].char_id;
		}
	}
	return 0;
}

// Exported for avm2_text.c (Font.registerFont / Font.enumerateFonts): the font
// tables are the one character kind whose lookups live outside this file.
uint32_t avm2_display_child_movie_count(void)
{
	return g_child_movie_count;
}

const Avm2MovieTables* avm2_display_child_movie(uint32_t i)
{
	return i < g_child_movie_count ? g_child_movies[i] : NULL;
}

// Ruffle Activation::caller_movie_or_root(): which movie does this ABC file
// belong to? NULL = the MAIN movie (whose tables are the avm2_generated_*
// globals, not an Avm2MovieTables), which is also the answer for a file that
// no child claims.
const Avm2MovieTables* avm2_display_movie_for_abc(const Avm2AbcFileData* f)
{
	if (f == NULL) return NULL;
	for (uint32_t m = 0; m < g_child_movie_count; m++)
	{
		const Avm2MovieTables* t = g_child_movies[m];
		for (uint32_t i = 0; i < t->abc_file_count; i++)
			if (t->abc_files[i] == f) return t;
	}
	return NULL;
}

static const Avm2TimelineData* timeline_for_char(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_timeline_count; i++)
	{
		if (avm2_generated_timelines[i].char_id == char_id)
		{
			return &avm2_generated_timelines[i];
		}
	}
	for (uint32_t m = 0; m < g_child_movie_count; m++)
	{
		const Avm2MovieTables* t = g_child_movies[m];
		for (uint32_t i = 0; i < t->timeline_count; i++)
			if (t->timelines[i].char_id == char_id) return &t->timelines[i];
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
	for (uint32_t m = 0; m < g_child_movie_count; m++)
	{
		const Avm2MovieTables* t = g_child_movies[m];
		for (uint32_t i = 0; i < t->char_count; i++)
			if (t->chars[i].char_id == char_id) return &t->chars[i];
	}
	return NULL;
}

// Ruffle library.character_by_id(id).is_some(): does this movie DEFINE the
// character at all? Used for the root SymbolClass binding — a binding whose id
// names nothing is the movie's root class, whatever the id (movie_clip.rs's
// `None =>` arm: "most SWFs use id 0 here, but some obfuscated SWFs can use
// other invalid IDs"). Every table the emitter can define a character in is
// checked; missing one would silently promote a real symbol's class to root.
int avm2_display_char_is_defined(uint16_t char_id)
{
	if (char_id == 0) return 1;   // the main timeline is always character 0
	if (char_info(char_id) != NULL) return 1;
	for (uint32_t i = 0; i < avm2_generated_timeline_count; i++)
		if (avm2_generated_timelines[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_shape_geom_count; i++)
		if (avm2_generated_shape_geom[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_button_count; i++)
		if (avm2_generated_buttons[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_edittext_count; i++)
		if (avm2_generated_edittexts[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_statictext_count; i++)
		if (avm2_generated_statictexts[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_bitmap_count; i++)
		if (avm2_generated_bitmaps[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_binary_count; i++)
		if (avm2_generated_binaries[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_sound_count; i++)
		if (avm2_generated_sounds[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < avm2_generated_font_count; i++)
		if (avm2_generated_fonts[i].font_id == char_id) return 1;
	return 0;
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

static const Avm2StaticTextData* statictext_for(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_statictext_count; i++)
	{
		if (avm2_generated_statictexts[i].char_id == char_id)
		{
			return &avm2_generated_statictexts[i];
		}
	}
	return NULL;
}

// Resolve a placed character's static-text (DefineText/2) glyph range onto its
// ext (NULL for anything that isn't a StaticText). Mirrors resolve_shape_geom;
// called at place-time so the render walk needs no per-frame lookup.
static void resolve_static_text(Avm2DisplayObjectExt* ext, uint16_t char_id)
{
	ext->statictext = statictext_for(char_id);
}

// Resolve a placed character's renderable shape geometry onto its ext.
// Called at place-time so the render walk needs no per-frame lookup. Clears
// the range for anything that isn't a renderable shape (sprite, bitmap-fill
// shape, script-created, or unresolved char). "Renderable" = solid (T1),
// stroke (T2), and gradient (T3) fills; bitmap-fill shapes stay deferred.
static void resolve_shape_geom(Avm2DisplayObjectExt* ext, uint16_t char_id)
{
	const Avm2ShapeGeom* sg = shape_geom_for(char_id);
	if (sg != NULL && sg->renderable && sg->vert_count > 0)
	{
		ext->shape_vert_offset = sg->vert_offset;
		ext->shape_vert_count = sg->vert_count;
		ext->is_morph_shape = sg->is_morph;
		ext->morph_end_offset = sg->morph_end_offset;
	}
	else
	{
		ext->shape_vert_offset = 0;
		ext->shape_vert_count = 0;
		ext->is_morph_shape = 0;
		ext->morph_end_offset = 0;
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

// A display object's matrix is SWF 16.16 fixed point (swf::Fixed16 in Ruffle's
// swf/src/types/matrix.rs), and Fixed16::from_f64 is a *saturating* i32 cast.
// So a/b/c/d top out at i32::MAX/65536 = 32767.999984741211 no matter how big
// the requested scale is. `scaleX`/`scaleY` are a separate cached double that
// never round-trips through the matrix, which is why `Video.width = 16777215`
// reads back scaleX = 52428.8 but width = 320 * 32768 = 10485760: the bounds
// are transformed by the CAPPED matrix. Only the saturation is modelled here,
// not the 1/65536 quantization — our mtx_* fields are already floats and the
// quantization would perturb every rotated matrix in the corpus.
#define AVM2_FIXED16_MAX 32767.999984741211
#define AVM2_FIXED16_MIN (-32768.0)

static double clamp_fixed16(double v)
{
	if (isnan(v)) return 0.0;  // Rust's float->int cast maps NaN to 0
	if (v > AVM2_FIXED16_MAX) return AVM2_FIXED16_MAX;
	if (v < AVM2_FIXED16_MIN) return AVM2_FIXED16_MIN;
	return v;
}

// Ruffle DisplayObjectBase::set_transformed_by_script(true). Sticky flag: an
// AS write to a transform attribute permanently stops the timeline's
// PlaceObject tags from re-applying to this object (see apply_place_object).
// Every Ruffle call site passes `true`; nothing ever clears it.
static inline void mark_transformed_by_script(Avm2DisplayObjectExt* ext)
{
	if (ext != NULL) ext->transformed_by_script = 1;
}

static void set_rotation_internal(Avm2DisplayObjectExt* ext, double deg)
{
	// Ruffle display_object.rs:511 marks BEFORE the NaN early-return below,
	// so a NaN rotation still counts as a script transform.
	mark_transformed_by_script(ext);
	cache_scale_rotation(ext);
	ext->rotation_deg = deg;
	double rad = deg * (M_PI / 180.0);
	if (isnan(rad)) return;  // NaN rotation leaves the matrix untouched
	double cos_x = cos(rad), sin_x = sin(rad);
	double cos_y = cos(rad + ext->skew), sin_y = sin(rad + ext->skew);
	ext->mtx_a = (float) clamp_fixed16(ext->scale_x * cos_x);
	ext->mtx_b = (float) clamp_fixed16(ext->scale_x * sin_x);
	ext->mtx_c = (float) clamp_fixed16(ext->scale_y * -sin_y);
	ext->mtx_d = (float) clamp_fixed16(ext->scale_y * cos_y);
}

static void set_scale_x_internal(Avm2DisplayObjectExt* ext, double unit)
{
	mark_transformed_by_script(ext);
	cache_scale_rotation(ext);
	ext->scale_x = unit;  // NaN stored verbatim (getter reports it)
	double calc = isnan(unit) ? 0.0 : unit;
	double rot = ext->rotation_deg * (M_PI / 180.0);
	if (isnan(rot)) rot = 0.0;
	ext->mtx_a = (float) clamp_fixed16(cos(rot) * calc);
	ext->mtx_b = (float) clamp_fixed16(sin(rot) * calc);
}

static void set_scale_y_internal(Avm2DisplayObjectExt* ext, double unit)
{
	mark_transformed_by_script(ext);
	cache_scale_rotation(ext);
	ext->scale_y = unit;
	double calc = isnan(unit) ? 0.0 : unit;
	double rot = ext->rotation_deg * (M_PI / 180.0);
	if (isnan(rot)) rot = 0.0;
	ext->mtx_c = (float) clamp_fixed16(-sin(rot + ext->skew) * calc);
	ext->mtx_d = (float) clamp_fixed16(cos(rot + ext->skew) * calc);
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

// Ruffle render/src/matrix.rs round_to_i32. Every translation Ruffle produces
// is an INTEGER twip: the f32 product is rounded half-to-even and lands in an
// i32 before the (already integral) translation is added. Our Mat carries
// doubles, so a composed matrix would otherwise drift a fraction of a twip and
// `width`/`height` would read back 20.999999046325684 where Ruffle and Flash
// both say 21 (see the ruffle-geometry-is-integer-twips note).
static double round_twips_f32(float f)
{
	if (!isfinite(f)) return 0;                       // NaN / Infinity -> 0
	if (f >= 2147483648.0f || f <= -2147483648.0f)
		return (double) INT32_MIN;                    // out of range clamps
	return (double) (int32_t) nearbyintf(f);          // FE_TONEAREST = ties-even
}

static Mat mat_mul(const Mat* m, const Mat* n)  // m * n
{
	Mat r;
	r.a = m->a * n->a + m->c * n->b;
	r.b = m->b * n->a + m->d * n->b;
	r.c = m->a * n->c + m->c * n->d;
	r.d = m->b * n->c + m->d * n->d;
	r.tx = round_twips_f32((float) ((float) m->a * (float) n->tx
	                                + (float) m->c * (float) n->ty)) + m->tx;
	r.ty = round_twips_f32((float) ((float) m->b * (float) n->tx
	                                + (float) m->d * (float) n->ty)) + m->ty;
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
			// Matrix * Point<Twips>: the rotate/scale part rounds to a
			// whole twip before the translation is added, exactly as in
			// Ruffle. Corner-by-corner, so a transformed box is integral.
			double x = round_twips_f32((float) ((float) m->a * (float) xs[i]
			                                    + (float) m->c * (float) ys[j]))
			           + m->tx;
			double y = round_twips_f32((float) ((float) m->b * (float) xs[i]
			                                    + (float) m->d * (float) ys[j]))
			           + m->ty;
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
	// A scrollRect completely overrides the object's bounds — children
	// included — with a box of the rect's SIZE at the object's own origin
	// (Ruffle display_object.rs bounds_with_transform).
	if (ext->has_scroll_rect)
	{
		Rect sr;
		sr.valid = 1;
		sr.xmin = 0;
		sr.ymin = 0;
		sr.xmax = ext->sr_xmax - ext->sr_xmin;
		sr.ymax = ext->sr_ymax - ext->sr_ymin;
		rect_union_xform(acc, &sr, m);
		return;
	}
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
	// A SimpleButton has no inherent bounds and is not a container: its box
	// comes from the child for the CURRENT state, which lives in btn_up /
	// btn_over / … rather than the render list (Ruffle avm2_button.rs
	// bounds_with_transform reads get_state_child(self.state())). Without
	// mouse input the state never leaves Up, so this is the Up child.
	{
		Avm2Object* state = avm2_button_state_child(ext);
		if (state != NULL)
		{
			Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, state);
			if (sext != NULL)
			{
				Mat sm = ext_matrix(sext);
				Mat combined = mat_mul(m, &sm);
				bounds_with_transform(ctx, state, &combined, acc);
			}
		}
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
	mark_attached(ctx, cext, parent);
	render_insert_at_id(ctx, pext, child, index);
	if (parent_changed)
	{
		dispatch_added_event(ctx, parent, child, child_was_on_stage);
	}
}

// Full removal (Ruffle remove_child, AVM2 direct path).
static Avm2Object* g_stage_focus;
static void set_focus(Avm2Context* ctx, Avm2Object* new_focus);

// Focus-highlight state (Ruffle focus_tracker.rs `Highlight`):
// 0 = Inactive, 1 = ActiveHidden, 2 = ActiveVisible. Cached at focus-change
// time; see avm2_update_highlight for how it is derived and avm2_render_walk
// for where it is consumed.
static int g_avm2_highlight = 0;

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
			//
			// The two halves need SEPARATE frames because they report
			// differently (Ruffle container.rs remove_child_from_render_list):
			// a throwing GETTER is swallowed outright — "they don't make it to
			// flashlog or to uncaught error events" — while a throwing SETTER
			// goes to Avm2::uncaught_error and is traced.
			Avm2Value cur = avm2_undefined();
			int read_ok = 0;
			{
				Avm2TryFrame gtop;
				avm2_try_push_catch_all_silent(ctx, &gtop);
				if (setjmp(gtop.jb) == 0)
				{
					cur = avm2_get_public_property(
						ctx, avm2_object_value(cext->parent),
						cext->name->utf8, cext->name->len, NULL);
					read_ok = 1;
				}
				avm2_try_pop_frame(&gtop);
			}
			if (read_ok && cur.kind != AVM2_VALUE_NULL
			    && cur.kind != AVM2_VALUE_UNDEFINED)
			{
				Avm2TryFrame stop;
				avm2_try_push_catch_all(ctx, &stop);
				if (setjmp(stop.jb) == 0)
				{
					avm2_set_public_property(ctx, avm2_object_value(cext->parent),
					                         cext->name->utf8, cext->name->len,
					                         avm2_null());
				}
				avm2_try_pop_frame(&stop);
			}
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

static uint64_t g_gp_ctors_run_fwd;

// Returns 1 when the constructor threw, writing the thrown value to *exc. The
// catch-all frame swallows it either way; only the child-SWF root cares which
// happened (loader_error_in_root_ctor).
static int display_run_constructor_catching(Avm2Context* ctx, Avm2Object* obj,
                                            Avm2Value* exc)
{
	g_gp_ctors_run_fwd++;
	Avm2Class* cls = obj->cls;
	Avm2TryFrame top;
	// A caller that asks for `exc` renders the error itself (the loaded SWF's
	// root ctor does), so print_uncaught must stay out of that path or the
	// traced line appears twice. A caller that discards it is a genuine
	// uncaught error and keeps the normal reporting.
	if (exc != NULL) avm2_try_push_catch_all_silent(ctx, &top);
	else avm2_try_push_catch_all(ctx, &top);
	volatile int threw = 1;   // survives the longjmp
	if (setjmp(top.jb) == 0)
	{
		avm2_call_method_ref(ctx, &cls->instance_init, cls,
		                     cls->iscope != NULL ? cls->iscope : cls->scope,
		                     avm2_object_value(obj), NULL, 0);
		threw = 0;
	}
	if (threw && exc != NULL) *exc = top.exc;
	avm2_try_pop_frame(&top);
	return threw;
}

static void display_run_constructor(Avm2Context* ctx, Avm2Object* obj)
{
	display_run_constructor_catching(ctx, obj, NULL);
}

static void enter_frame_obj(Avm2Context* ctx, Avm2Object* obj);
static void construct_frame_obj(Avm2Context* ctx, Avm2Object* obj);
static void button_construct_states(Avm2Context* ctx, Avm2Object* button);
static void run_frame_scripts_obj(Avm2Context* ctx, Avm2Object* obj);
static void run_goto(Avm2Context* ctx, Avm2Object* obj, uint16_t frame, int is_implicit);
static void on_construction_complete(Avm2Context* ctx, Avm2Object* obj);
static void set_on_parent_field(Avm2Context* ctx, Avm2Object* obj);

// ---------------------------------------------------------------------------
// Catch-up walk gate
//
// Ruffle runs a FULL stage + orphan walk (construct_frame, then
// run_frame_scripts) for every explicit AVM2 goto — frame_lifecycle.rs
// run_inner_goto_frame — and so do we. That is O(display tree) per
// gotoAndStop, which turns any build loop that creates clips and gotos them
// into O(n^2): Elephant Quest's Level.initTiles does `new Tile(); addChild;
// gotoAndStop(type)` a few thousand times, and each goto re-walked every clip
// created so far (measured: 60k nodes and ~35 ms per goto by tile ~4000,
// with 94% of the nodes in the never-shrinking orphan list).
//
// The walks are pure no-ops on a node that is already constructed and
// initialized, has no queued goto, and whose frame script (if any) has
// already run for its current frame. So each node carries `walk_clean`: set
// only at the end of a frame-script walk that found the node AND all of its
// children quiescent, and cleared up the whole ancestor chain the moment a
// node acquires work (creation, goto, queued script, re-parenting). A clean
// node's subtree is skipped by both walks.
//
// Fail-safe by construction: `walk_clean` is zero-initialized, so a node
// nobody accounts for is walked, exactly as before. Env AVM2_NO_WALK_SKIP=1
// disables the gate (A/B and bisecting aid).
// ---------------------------------------------------------------------------

// Fast ext fetch for objects already known to be display objects (render-list
// members, button states, orphan roots). avm2_display_ext_of's class_is_a walk
// is the dominant cost of scanning a large child list, and every ext that
// extends the display ext (Avm2LoaderExt) keeps it as its first member.
static Avm2DisplayObjectExt* display_ext_fast(Avm2Object* obj)
{
	return (obj != NULL && obj->native_ext != NULL)
		? (Avm2DisplayObjectExt*) obj->native_ext : NULL;
}

static int g_walk_skip = -1;

static int walk_skip_on(void)
{
	if (g_walk_skip < 0)
	{
		const char* e = getenv("AVM2_NO_WALK_SKIP");
		g_walk_skip = (e != NULL && e[0] != '\0' && e[0] != '0') ? 0 : 1;
	}
	return g_walk_skip;
}

// Mark `obj` and every ancestor as needing a walk. Stops as soon as it finds
// a node already marked: by the invariant, that node's ancestors are marked
// too. Re-parenting is the one operation that can break the invariant, so
// every site that gives a node a parent re-marks through the new parent.
void avm2_display_mark_frame_work(Avm2Context* ctx, Avm2Object* obj)
{
	while (obj != NULL)
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
		if (e == NULL || !e->walk_clean) return;
		e->walk_clean = 0;
		if (e->parent != NULL)
		{
			Avm2DisplayObjectExt* pe = avm2_display_ext_of(ctx, e->parent);
			if (pe != NULL) pe->dirty_kids++;
		}
		else if (e->in_orphan_list)
		{
			orphan_dirty_push(ctx, obj);
		}
		obj = e->parent;
	}
}

// A node that gains a parent re-enters the walk under a new ancestor chain,
// which is the one operation the "stop at the first marked ancestor" shortcut
// above cannot see. Dirty the child (cheap: at worst one extra subtree walk)
// and mark up through its new parent.
static void mark_attached(Avm2Context* ctx, Avm2DisplayObjectExt* cext,
                          Avm2Object* parent)
{
	if (cext != NULL) cext->walk_clean = 0;
	g_orphan_reparented++;
	// The child is dirty under its NEW parent, whatever it was before.
	if (parent != NULL)
	{
		Avm2DisplayObjectExt* pe = avm2_display_ext_of(ctx, parent);
		if (pe != NULL) pe->dirty_kids++;
	}
	avm2_display_mark_frame_work(ctx, parent);
}

// True when the construct + frame-script walks would do nothing at all for
// this node (its children are accounted for separately by the caller).
// Mirrors, condition for condition, the work in construct_frame_obj and
// run_local_frame_scripts.
static int node_quiescent(Avm2DisplayObjectExt* e)
{
	if (!e->constructed || !e->initialized) return 0;
	if (e->loop_queued) return 0;             // construct_frame_obj clears it
	if (e->btn_weird_order) return 0;         // run_frame_scripts_obj clears it
	if (e->queued_goto_frame >= 0) return 0;  // run_local_frame_scripts flushes
	if (e->executing_frame_script) return 0;
	// A pending frame script only does something when it is FRESH for the
	// frame it is queued on (run_local_frame_scripts' is_fresh).
	uint32_t f = e->queued_script_frame;
	if (e->has_pending_script && f < e->frame_script_cap
	    && e->frame_scripts[f].kind == AVM2_VALUE_OBJECT
	    && e->last_queued_script_frame != (int32_t) f)
	{
		return 0;
	}
	return 1;
}

// ---------------------------------------------------------------------------
// Goto-walk profiler (env AVM2_GOTO_PROF=1) — read-only instrumentation for
// the AVM2 timeline catch-up path. Prints, per OUTERMOST inner-goto, how many
// display nodes the construct / frame-script walks touched, how many nested
// gotos they triggered, and the wall time. The counter that matters is
// nodes-per-goto: if it climbs as the display tree grows, the catch-up is
// super-linear in tree size (EQ init2 DOOR-build, plan gap #2b).
// ---------------------------------------------------------------------------

static int g_goto_prof = -1;
static uint64_t g_gp_construct_nodes;
static uint64_t g_gp_fs_nodes;
static uint64_t g_gp_inner_calls;
static uint64_t g_gp_goto_calls;
static uint64_t g_gp_goto_ops;
static uint64_t g_gp_scripts_run;
static uint64_t g_gp_scan;
static const char* g_gp_src_cls = "?";
static int g_gp_src_frame;
static int g_gp_src_noop;
static int g_gp_depth;
static int g_gp_max_depth;

// AVM2_GOTO_PROF=1: a rolling summary every 1000 outer gotos (low overhead).
// AVM2_GOTO_PROF=2: additionally one line per outer goto and per frame script.
static int goto_prof_on(void)
{
	if (g_goto_prof < 0)
	{
		const char* e = getenv("AVM2_GOTO_PROF");
		g_goto_prof = (e == NULL || e[0] == '\0' || e[0] == '0')
			? 0 : (e[0] == '2' ? 2 : 1);
	}
	return g_goto_prof;
}

static double g_gp_total_ms, g_gp_total_w1, g_gp_total_w2;
static uint64_t g_gp_outer;

static double goto_prof_now_ms(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double) ts.tv_sec * 1000.0 + (double) ts.tv_nsec / 1.0e6;
}

// ---------------------------------------------------------------------------
// Class resolution for characters
// ---------------------------------------------------------------------------

static Avm2Object* find_globals_for_dotted(Avm2Context* ctx,
                                           const Avm2DomainScope* scope,
                                           const char* dotted,
                                           Avm2PropKey* out_key)
{
	const char* last_dot = strrchr(dotted, '.');
	Avm2PropKey key;
	key.ns_kind = 0x16;
	key.ns_priv = NULL;
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
	return avm2_domain_find(ctx, scope, &key);
}

// Resolve a SymbolClass name in a specific movie's domain. The main movie's
// bindings use the root scope (class_for_dotted_name below); a LOADED movie's
// root binding must use the domain it loaded into, or a child in a fresh
// domain binds to the parent's same-named class.
static Avm2Class* class_for_dotted_name_in(Avm2Context* ctx,
                                           const Avm2DomainScope* scope,
                                           const char* dotted)
{
	Avm2PropKey key;
	Avm2Object* globals = find_globals_for_dotted(ctx, scope, dotted, &key);
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

static Avm2Class* class_for_dotted_name(Avm2Context* ctx, const char* dotted)
{
	return class_for_dotted_name_in(ctx, avm2_domain_root_scope(ctx), dotted);
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
	for (uint32_t m = 0; m < g_child_movie_count; m++)
	{
		const Avm2MovieTables* t = g_child_movies[m];
		for (uint32_t i = 0; i < t->symbol_class_count; i++)
		{
			if (t->symbol_classes[i].char_id != char_id
			    || t->symbol_classes[i].class_name == NULL) continue;
			Avm2Class* cls = class_for_dotted_name(
				ctx, t->symbol_classes[i].class_name);
			if (cls != NULL && class_is_a(cls, ctx->builtins.display_object_class))
				return cls;
		}
	}
	const Avm2CharInfo* ci = char_info(char_id);
	uint8_t kind = ci != NULL ? ci->kind : AVM2_CHAR_SPRITE;
	switch (kind)
	{
		case AVM2_CHAR_SHAPE:
			return ctx->builtins.shape_class;
		case AVM2_CHAR_MORPHSHAPE:
			return g_morphshape_class;
		case AVM2_CHAR_BUTTON:
			return ctx->builtins.simple_button_class;
		case AVM2_CHAR_TEXT:
			return g_statictext_class;
		case AVM2_CHAR_EDITTEXT:
			return g_textfield_class;
		case AVM2_CHAR_BITMAP:
			return ctx->builtins.bitmap_class;
		case AVM2_CHAR_VIDEO:
			// The AVM2 character scanner has recorded DefineVideoStream as
			// kind 7 all along; only this arm was missing, so every placed
			// video instantiated as a MovieClip (place_and_lookup/swf{9,10}).
			return g_video_class != NULL ? g_video_class
			                             : ctx->builtins.movieclip_class;
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
	for (uint32_t m = 0; m < g_child_movie_count; m++)
	{
		const Avm2MovieTables* t = g_child_movies[m];
		for (uint32_t i = 0; i < t->symbol_class_count; i++)
		{
			if (t->symbol_classes[i].char_id != char_id
			    || t->symbol_classes[i].class_name == NULL) continue;
			Avm2Class* cls = class_for_dotted_name(
				ctx, t->symbol_classes[i].class_name);
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

// SWF numeric blend id -> the AS name DisplayObject.blendMode reports
// (swf/src/types.rs BlendMode::from_u8 + Display; 1 aliases 0, and anything
// out of range degrades to "normal").
static const char* blend_mode_name(uint8_t id)
{
	switch (id)
	{
		case 2:  return "layer";
		case 3:  return "multiply";
		case 4:  return "screen";
		case 5:  return "lighten";
		case 6:  return "darken";
		case 7:  return "difference";
		case 8:  return "add";
		case 9:  return "subtract";
		case 10: return "invert";
		case 11: return "alpha";
		case 12: return "erase";
		case 13: return "overlay";
		case 14: return "hardlight";
		default: return "normal";
	}
}

// blendMode / cacheAsBitmap are stored as dont_enum dyn props (the same slots
// the AS getters read), so the timeline can seed them without an activation.
static void set_blend_mode_name(Avm2Context* ctx, Avm2Object* obj, const char* name)
{
	if (obj == NULL) return;
	avm2_object_set_dynamic(ctx, obj, "__blendMode", 11,
		avm2_string(avm2_string_from_literal(ctx, name)))->dont_enum = 1;
}

static void set_cache_as_bitmap(Avm2Context* ctx, Avm2Object* obj, int on)
{
	if (obj == NULL) return;
	avm2_object_set_dynamic(ctx, obj, "__cacheAsBitmap", 15,
		avm2_bool(on != 0))->dont_enum = 1;
}

static void apply_place_object(Avm2Context* ctx, Avm2Object* child,
                               const Avm2TimelineOp* op)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, child);
	if (ext == NULL) return;
	// Ruffle display_object.rs:2514 — "PlaceObject tags only apply if this
	// object has not been dynamically moved by AS code." The gate wraps the
	// WHOLE body (matrix, cxform, blend, cacheAsBitmap, visible, ratio,
	// filters); name / clip_depth are purposely outside it and are applied by
	// instantiate_child, not here.
	if (ext->transformed_by_script) return;
	apply_place_matrix(ext, op);
	if (op->flags & AVM2_TLF_HAS_CXFORM)
	{
		ext->cx_rm = op->cx_mult[0];
		ext->cx_gm = op->cx_mult[1];
		ext->cx_bm = op->cx_mult[2];
		ext->alpha_fixed8 = op->cx_mult[3];
		ext->cx_ra = op->cx_add[0];
		ext->cx_ga = op->cx_add[1];
		ext->cx_ba = op->cx_add[2];
		ext->cx_aa = op->cx_add[3];
	}
	if (op->flags & AVM2_TLF_HAS_BLEND)
	{
		set_blend_mode_name(ctx, child, blend_mode_name(op->blend_mode));
	}
	if (op->flags & AVM2_TLF_HAS_CACHE)
	{
		set_cache_as_bitmap(ctx, child, op->bitmap_cache != 0);
	}
	if (op->flags & AVM2_TLF_HAS_VISIBLE)
	{
		ext->visible = op->visible ? 1 : 0;
	}
	// T6: morph interpolation ratio (PlaceObject2 ratio). A move without a ratio
	// field keeps the prior value (Flash semantics); the ext is zero-initialised,
	// so a never-rated placement stays at ratio 0 (pure start shape).
	if (op->flags & AVM2_TLF_HAS_RATIO)
	{
		ext->ratio = op->ratio;
	}
	// SurfaceFilterList. An empty list on a PlaceObject3 is meaningful — it
	// clears whatever the depth had. So is a fresh (non-move) placement with
	// no list at all: on a timeline rewind the depth is re-placed from frame
	// 1, and the object must not keep the filters a later frame gave it
	// (filter_rewind's "No filter" line). A plain MOVE keeps them.
	if (op->flags & AVM2_TLF_HAS_FILTERS)
	{
		avm2_display_apply_tag_filters(ctx, child, op->filters, op->filter_count);
	}
	else if ((op->flags & AVM2_TLF_MOVE) == 0)
	{
		avm2_display_apply_tag_filters(ctx, child, NULL, 0);
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
	resolve_static_text(cext, op->char_id);
	cext->timeline = timeline_for_char(op->char_id);
	Avm2Object* prev = replace_at_depth(ctx, pext, child, op->depth);
	cext->instantiated_by_timeline = 1;
	cext->depth = op->depth;
	cext->parent = parent;
	mark_attached(ctx, cext, parent);
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
	resolve_static_text(cext, char_id);
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

// One depth's slot in Ruffle's per-depth QueuedTagList
// (core/src/display_object/movie_clip.rs:4845-4905):
//
//   enum QueuedTagList { None, Add(t), Remove(t), RemoveThenAdd(t, t) }
//
// encoded here as (remove_op, add_op) op indices, -1 = absent. `add_idx` is
// where the Add landed in ext->queued_places, so a later Remove can VOID it.
typedef struct Avm2QueuedDepth
{
	int32_t depth;
	int32_t remove_op;
	int32_t add_op;
	int32_t add_idx;
} Avm2QueuedDepth;

// run_frame_internal (AS3 arm): queue place ops, run removals, advance.
static void run_frame_internal(Avm2Context* ctx, Avm2Object* obj, int run_display)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->timeline == NULL) return;
	// The per-tick playhead advance below moves current_frame WITHOUT going
	// through run_goto, so it needs its own catch-up walk mark.
	avm2_display_mark_frame_work(ctx, obj);

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
		// Ruffle's per-depth QueuedTagList. BOTH place and remove tags are
		// QUEUED: a Remove ANNIHILATES an earlier queued Add at the same depth
		// (Add -> queue_remove -> None), so a place/remove/place run inside ONE
		// frame ends at the LAST place with no removal fired at all
		// (issue_8630_placeremoveplace). Removals still drain before the frame
		// number advances ("we deliberately run all removals before the frame
		// number or tag position updates"); placements drain later, in
		// flush_queued_places.
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
		Avm2QueuedDepth* qd = NULL;
		uint32_t qd_count = 0;
		if (op_end > op_start)
		{
			qd = avm2_alloc(ctx, (op_end - op_start) * sizeof(Avm2QueuedDepth));
		}
		for (uint32_t i = op_start; i < op_end; i++)
		{
			const Avm2TimelineOp* op = &tl->ops[i];
			if (op->kind != AVM2_TLOP_PLACE && op->kind != AVM2_TLOP_REMOVE) continue;
			Avm2QueuedDepth* s = NULL;
			for (uint32_t k = 0; k < qd_count; k++)
			{
				if (qd[k].depth == (int32_t) op->depth) { s = &qd[k]; break; }
			}
			if (s == NULL)
			{
				s = &qd[qd_count++];
				s->depth = (int32_t) op->depth;
				s->remove_op = -1;
				s->add_op = -1;
				s->add_idx = -1;
			}
			if (op->kind == AVM2_TLOP_PLACE)
			{
				if ((op->flags & AVM2_TLF_HAS_CHAR) == 0)
				{
					// A modify-only place tag is not an Add: it neither
					// displaces a queued Add nor is cancelled by a Remove.
					ext->queued_places[ext->queued_place_count++] = (int32_t) i;
					continue;
				}
				if (s->add_op >= 0 && s->remove_op < 0)
				{
					// Add -> queue_add: the FIRST wins, with a warning
					// (place_object_same_depth_frame).
					fprintf(stderr, "AVM2 timeline: failed to queue place at "
					        "depth %u (already queued)\n", op->depth);
					continue;
				}
				if (s->add_op >= 0)
				{
					// RemoveThenAdd -> queue_add: the LAST wins, silently.
					ext->queued_places[s->add_idx] = -1;
				}
				s->add_op = (int32_t) i;
				s->add_idx = (int32_t) ext->queued_place_count;
				ext->queued_places[ext->queued_place_count++] = (int32_t) i;
			}
			else
			{
				if (s->add_op >= 0)
				{
					// Add -> None (annihilate), or RemoveThenAdd -> Remove(r),
					// which keeps the FIRST remove. Either way the queued Add
					// is dropped.
					ext->queued_places[s->add_idx] = -1;
					s->add_op = -1;
					s->add_idx = -1;
					continue;
				}
				// None/Remove -> Remove(new).
				s->remove_op = (int32_t) i;
			}
		}
		for (uint32_t i = op_start; i < op_end; i++)
		{
			for (uint32_t k = 0; k < qd_count; k++)
			{
				if (qd[k].remove_op == (int32_t) i)
				{
					run_remove_op(ctx, obj, &tl->ops[i]);
					break;
				}
			}
		}
		if (qd != NULL) heap_free(ctx->app, qd);
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
		// -1 = an Add that a later Remove at the same depth annihilated.
		if (ext->queued_places[i] < 0) continue;
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
	// Catch-up walk gate: a clean subtree has nothing to construct.
	if (ext->walk_clean && walk_skip_on()) return;
	g_gp_construct_nodes++;
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
		int scan_kids = (ext->dirty_kids != 0 || !walk_skip_on());
		g_gp_scan += scan_kids ? ext->render_len : 0;
		for (uint32_t i = 0; scan_kids && i < ext->render_len; i++)
		{
			Avm2DisplayObjectExt* cext = display_ext_fast(ext->render_list[i]);
			// Cheap skip of a clean child, before any recursion.
			if (cext != NULL && cext->walk_clean && walk_skip_on()) continue;
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
			g_gp_scripts_run++;
			if (g_goto_prof >= 2)
			{
				fprintf(stderr, "[FS] %s@%u phase=%d\n",
				        (obj->cls != NULL && obj->cls->name.name != NULL)
					? obj->cls->name.name : "?",
				        (unsigned) frame_id, (int) ctx->frame_phase);
			}
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
	int gate = walk_skip_on();
	// Catch-up walk gate: a clean subtree has no frame script to run.
	if (ext->walk_clean && gate) return;
	g_gp_fs_nodes++;
	run_local_frame_scripts(ctx, obj);
	int scan_kids = (ext->dirty_kids != 0 || ext->btn_weird_order || !gate);
	if (scan_kids)
	{
		g_gp_scan += ext->render_len;
		for (uint32_t i = 0; i < ext->render_len; i++)
		{
			Avm2DisplayObjectExt* c = display_ext_fast(ext->render_list[i]);
			if (c != NULL && c->walk_clean && gate) continue;
			run_frame_scripts_obj(ctx, ext->render_list[i]);
		}
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
	if (!gate) return;
	// This walk is the last of the pair, so it is where a subtree can be
	// certified clean. The frame scripts above may have created/gotoed
	// anything, so re-read the children rather than trusting the state they
	// had when we recursed into them — that re-read doubles as the exact
	// recount of dirty_kids.
	if (scan_kids)
	{
		uint32_t nd = 0;
		for (uint32_t i = 0; i < ext->render_len; i++)
		{
			Avm2DisplayObjectExt* c = display_ext_fast(ext->render_list[i]);
			if (c == NULL || !c->walk_clean) nd++;
		}
		Avm2Object* states[4] = { ext->btn_hit, ext->btn_up, ext->btn_down,
		                          ext->btn_over };
		for (int s = 0; s < 4; s++)
		{
			if (states[s] == NULL) continue;
			Avm2DisplayObjectExt* c = display_ext_fast(states[s]);
			if (c == NULL || !c->walk_clean) nd++;
		}
		ext->dirty_kids = nd;
	}
	if (ext->dirty_kids == 0 && node_quiescent(ext)) ext->walk_clean = 1;
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
		avm2_display_mark_frame_work(ctx, obj);
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

	int prof = goto_prof_on();
	double prof_t0 = 0.0;
	uint64_t p_cn = 0, p_fn = 0, p_gc = 0, p_go = 0, p_sr = 0, p_cr = 0;
	uint64_t p_scan = 0;
	int prof_outer = 0;
	if (prof)
	{
		g_gp_inner_calls++;
		if (g_gp_depth == 0)
		{
			prof_outer = 1;
			g_gp_max_depth = 0;
			g_gp_inner_calls = 1;
			prof_t0 = goto_prof_now_ms();
			p_cn = g_gp_construct_nodes;
			p_scan = g_gp_scan;
			p_fn = g_gp_fs_nodes;
			p_gc = g_gp_goto_calls;
			p_go = g_gp_goto_ops;
			p_sr = g_gp_scripts_run;
			p_cr = g_gp_ctors_run_fwd;
		}
		g_gp_depth++;
		if (g_gp_depth > g_gp_max_depth) g_gp_max_depth = g_gp_depth;
	}

	ctx->frame_phase = PHASE_CONSTRUCT;
	for (uint32_t i = 0;
	     i < (walk_skip_on() ? g_orphan_dirty_count : g_orphan_count); i++)
	{
		Avm2Object* o = walk_skip_on() ? g_orphan_dirty[i] : g_orphans[i];
		if (orphan_dirty_ext(o, walk_skip_on()) == NULL) continue;
		construct_frame_obj(ctx, o);
	}
	uint64_t p_orph_nodes = g_gp_construct_nodes;
	if (ctx->stage != NULL) construct_frame_obj(ctx, ctx->stage);
	uint64_t p_stage_nodes = g_gp_construct_nodes - p_orph_nodes;
	double t_walk1 = prof_outer ? goto_prof_now_ms() : 0.0;
	broadcast_named(ctx, "frameConstructed");
	double t_bc1 = prof_outer ? goto_prof_now_ms() : 0.0;

	ctx->frame_phase = PHASE_FRAME_SCRIPTS;
	if (ctx->stage != NULL) run_frame_scripts_obj(ctx, ctx->stage);
	for (uint32_t i = 0;
	     i < (walk_skip_on() ? g_orphan_dirty_count : g_orphan_count); i++)
	{
		Avm2Object* o = walk_skip_on() ? g_orphan_dirty[i] : g_orphans[i];
		if (orphan_dirty_ext(o, walk_skip_on()) == NULL) continue;
		run_frame_scripts_obj(ctx, o);
	}
	run_frame_script_cleanup(ctx);
	double t_walk2 = prof_outer ? goto_prof_now_ms() : 0.0;

	ctx->frame_phase = PHASE_EXIT;
	broadcast_named(ctx, "exitFrame");
	double t_bc2 = prof_outer ? goto_prof_now_ms() : 0.0;
	orphan_cleanup(ctx);
	ctx->frame_phase = old_phase;

	if (prof)
	{
		g_gp_depth--;
		if (prof_outer)
		{
			g_gp_total_ms += goto_prof_now_ms() - prof_t0;
			g_gp_total_w1 += t_walk1 - prof_t0;
			g_gp_total_w2 += t_walk2 - t_bc1;
			if (++g_gp_outer % 1000 == 0)
			{
				fprintf(stderr,
				        "[GOTOSUM] gotos=%llu total=%.1fs construct=%.1fs "
				        "scripts=%.1fs scan=%lluk cnodes=%lluk orphans=%u\n",
				        (unsigned long long) g_gp_outer, g_gp_total_ms / 1000.0,
				        g_gp_total_w1 / 1000.0, g_gp_total_w2 / 1000.0,
				        (unsigned long long) (g_gp_scan / 1000),
				        (unsigned long long) (g_gp_construct_nodes / 1000),
				        (unsigned) g_orphan_count);
			}
		}
		if (prof_outer && prof >= 2)
		{
			fprintf(stderr,
			        "[GOTOPROF] src=%s@%d%s ms=%.2f w1=%.2f bc1=%.2f w2=%.2f bc2=%.2f "
			        "orphans=%u onodes=%llu snodes=%llu "
			        "inner=%llu depth=%d cnodes=%llu "
			        "fsnodes=%llu scan=%llu gotos=%llu tlops=%llu scripts=%llu ctors=%llu\n",
			        g_gp_src_cls, g_gp_src_frame, g_gp_src_noop ? "(noop)" : "",
			        goto_prof_now_ms() - prof_t0,
			        t_walk1 - prof_t0, t_bc1 - t_walk1, t_walk2 - t_bc1,
			        t_bc2 - t_walk2,
			        (unsigned) g_orphan_count,
			        (unsigned long long) (p_orph_nodes - p_cn),
			        (unsigned long long) p_stage_nodes,
			        (unsigned long long) g_gp_inner_calls, g_gp_max_depth,
			        (unsigned long long) (g_gp_construct_nodes - p_cn),
			        (unsigned long long) (g_gp_fs_nodes - p_fn),
			        (unsigned long long) (g_gp_scan - p_scan),
			        (unsigned long long) (g_gp_goto_calls - p_gc),
			        (unsigned long long) (g_gp_goto_ops - p_go),
			        (unsigned long long) (g_gp_scripts_run - p_sr),
			        (unsigned long long) (g_gp_ctors_run_fwd - p_cr));
		}
	}
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

// The effective placement a goto command resolves to, i.e. Ruffle's merged
// `GotoPlaceObject::place_object`. Two things happen here that a raw tag op
// does not do on its own:
//
//  1. On a REWIND, a Place (character, not a move) has every animatable
//     property DEFAULTED in (GotoPlaceObject::new): matrix, colour transform,
//     ratio, blend mode, bitmap caching and filters. That is what makes a
//     rewind to frame 1 undo a later frame's tint/blend/transform even though
//     frame 1's tag never mentions them. Purposely omitted, exactly as in
//     Ruffle: name, clipDepth (initial placement only) and visibility (which
//     persists across a rewind).
//  2. Later modify ops at the same depth are folded on top, field by field
//     (GotoPlaceObject::merge), so `survives_rewind` and the apply step both
//     see the final state rather than the first tag.
static void goto_effective_place(const GotoCmd* cmd, int is_rewind,
                                 Avm2TimelineOp* out)
{
	*out = *cmd->place;
	if (is_rewind && (out->flags & AVM2_TLF_HAS_CHAR)
	    && (out->flags & AVM2_TLF_MOVE) == 0)
	{
		if ((out->flags & AVM2_TLF_HAS_MATRIX) == 0)
		{
			out->mtx_a = 1; out->mtx_b = 0; out->mtx_c = 0; out->mtx_d = 1;
			out->mtx_tx = 0; out->mtx_ty = 0;
			out->flags |= AVM2_TLF_HAS_MATRIX;
		}
		if ((out->flags & AVM2_TLF_HAS_CXFORM) == 0)
		{
			out->cx_mult[0] = 256; out->cx_mult[1] = 256;
			out->cx_mult[2] = 256; out->cx_mult[3] = 256;
			out->cx_add[0] = 0; out->cx_add[1] = 0;
			out->cx_add[2] = 0; out->cx_add[3] = 0;
			out->flags |= AVM2_TLF_HAS_CXFORM;
		}
		if ((out->flags & AVM2_TLF_HAS_RATIO) == 0)
		{
			out->ratio = 0;
			out->flags |= AVM2_TLF_HAS_RATIO;
		}
		if ((out->flags & AVM2_TLF_HAS_BLEND) == 0)
		{
			out->blend_mode = 0;
			out->flags |= AVM2_TLF_HAS_BLEND;
		}
		if ((out->flags & AVM2_TLF_HAS_CACHE) == 0)
		{
			out->bitmap_cache = 0;
			out->flags |= AVM2_TLF_HAS_CACHE;
		}
		if ((out->flags & AVM2_TLF_HAS_FILTERS) == 0)
		{
			out->filter_count = 0;
			out->filters = NULL;
			out->flags |= AVM2_TLF_HAS_FILTERS;
		}
	}
	for (uint32_t i = 0; i < cmd->mod_count; i++)
	{
		const Avm2TimelineOp* m = cmd->mods[i];
		if (m->flags & AVM2_TLF_HAS_MATRIX)
		{
			out->mtx_a = m->mtx_a; out->mtx_b = m->mtx_b;
			out->mtx_c = m->mtx_c; out->mtx_d = m->mtx_d;
			out->mtx_tx = m->mtx_tx; out->mtx_ty = m->mtx_ty;
			out->flags |= AVM2_TLF_HAS_MATRIX;
		}
		if (m->flags & AVM2_TLF_HAS_CXFORM)
		{
			for (int k = 0; k < 4; k++)
			{
				out->cx_mult[k] = m->cx_mult[k];
				out->cx_add[k] = m->cx_add[k];
			}
			out->flags |= AVM2_TLF_HAS_CXFORM;
		}
		if (m->flags & AVM2_TLF_HAS_RATIO)
		{
			out->ratio = m->ratio;
			out->flags |= AVM2_TLF_HAS_RATIO;
		}
		if (m->flags & AVM2_TLF_HAS_BLEND)
		{
			out->blend_mode = m->blend_mode;
			out->flags |= AVM2_TLF_HAS_BLEND;
		}
		if (m->flags & AVM2_TLF_HAS_CACHE)
		{
			out->bitmap_cache = m->bitmap_cache;
			out->flags |= AVM2_TLF_HAS_CACHE;
		}
		if (m->flags & AVM2_TLF_HAS_VISIBLE)
		{
			out->visible = m->visible;
			out->flags |= AVM2_TLF_HAS_VISIBLE;
		}
		if (m->flags & AVM2_TLF_HAS_FILTERS)
		{
			out->filter_count = m->filter_count;
			out->filters = m->filters;
			out->flags |= AVM2_TLF_HAS_FILTERS;
		}
	}
}

// Ruffle MovieClip::survives_rewind. A child that predates the rewind target
// survives untouched — EXCEPT a morph shape, whose interpolation ratio still
// has to be re-checked. Everything else is decided by a per-field comparison
// against the final placement at that depth, and which fields count depends
// on the object's type: a shape/text/morph compares everything, a
// button/edittext/bitmap/video skips the transform, and a MovieClip is
// decided by its ratio alone.
static int survives_rewind(Avm2Context* ctx, Avm2DisplayObjectExt* cext,
                           const GotoCmd* cmds, uint32_t cmd_count,
                           uint16_t clamped)
{
	int candidate = (cext->place_frame > (int32_t) clamped)
	                || cext->placed_by_avm2_script;
	if (!candidate && !cext->is_morph_shape) return 1;

	const GotoCmd* final_cmd = NULL;
	for (uint32_t k = 0; k < cmd_count; k++)
	{
		if (cmds[k].depth == cext->depth && cmds[k].place != NULL)
		{
			final_cmd = &cmds[k];
			break;
		}
	}
	if (final_cmd == NULL) return 0;

	Avm2TimelineOp eff;
	goto_effective_place(final_cmd, 1, &eff);

	int id_eq = (eff.flags & AVM2_TLF_HAS_CHAR)
	            && eff.char_id == cext->char_id;
	int ratio_eq = ((eff.flags & AVM2_TLF_HAS_RATIO) == 0)
	               || eff.ratio == cext->ratio;
	int clip_eq = ((eff.flags & AVM2_TLF_HAS_CLIP_DEPTH) == 0)
	              || (int32_t) eff.clip_depth == cext->clip_depth;
	int cx_eq = ((eff.flags & AVM2_TLF_HAS_CXFORM) == 0)
	            || (eff.cx_mult[0] == cext->cx_rm && eff.cx_mult[1] == cext->cx_gm
	                && eff.cx_mult[2] == cext->cx_bm
	                && eff.cx_mult[3] == cext->alpha_fixed8
	                && eff.cx_add[0] == cext->cx_ra && eff.cx_add[1] == cext->cx_ga
	                && eff.cx_add[2] == cext->cx_ba && eff.cx_add[3] == cext->cx_aa);
	int mtx_eq = ((eff.flags & AVM2_TLF_HAS_MATRIX) == 0)
	             || (eff.mtx_a == cext->mtx_a && eff.mtx_b == cext->mtx_b
	                 && eff.mtx_c == cext->mtx_c && eff.mtx_d == cext->mtx_d
	                 && eff.mtx_tx == cext->mtx_tx && eff.mtx_ty == cext->mtx_ty);

	const Avm2CharInfo* ci = char_info(cext->char_id);
	uint8_t kind = (ci != NULL) ? ci->kind : (uint8_t) AVM2_CHAR_SPRITE;
	(void) ctx;
	switch (kind)
	{
		case AVM2_CHAR_MORPHSHAPE:
		case AVM2_CHAR_SHAPE:
		case AVM2_CHAR_TEXT:
			return ratio_eq && id_eq && clip_eq && mtx_eq && cx_eq;
		case AVM2_CHAR_BUTTON:
		case AVM2_CHAR_EDITTEXT:
		case AVM2_CHAR_BITMAP:
		case AVM2_CHAR_VIDEO:
			return ratio_eq && id_eq && clip_eq;
		default:
			return ratio_eq;
	}
}

static void run_goto(Avm2Context* ctx, Avm2Object* obj, uint16_t frame, int is_implicit)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->timeline == NULL) return;
	const Avm2TimelineData* tl = ext->timeline;
	g_gp_goto_calls++;
	// The playhead, the queued script frame and the child set are all about
	// to change: this subtree needs the catch-up walks again.
	avm2_display_mark_frame_work(ctx, obj);

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
		// survives_rewind).
		for (uint32_t i = ext->render_len; i > 0; i--)
		{
			Avm2Object* child = ext->render_list[i - 1];
			Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
			if (cext == NULL) continue;
			int survives = survives_rewind(ctx, cext, cmds, cmd_count, clamped);
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
		// A rewind resolves each command to its EFFECTIVE placement first:
		// defaults filled in for everything the target frame's tag leaves
		// unmentioned, later modify ops folded on top. A forward goto keeps
		// the raw tag and replays its trailing modify ops below.
		Avm2TimelineOp eff;
		const Avm2TimelineOp* place = cmd->place;
		if (is_rewind)
		{
			goto_effective_place(cmd, 1, &eff);
			place = &eff;
		}
		if (child != NULL && cext != NULL && is_rewind)
		{
			// Rewind always modifies the surviving child in place
			// (survives_rewind scrubbed the mismatches above).
			apply_place_object(ctx, child, place);
		}
		else if (child != NULL && cext != NULL
		         && (place->flags & AVM2_TLF_MOVE))
		{
			// Forward-goto Replace: SAME display object, per-type
			// character swap + place_frame update (Ruffle goto arm
			// Replace(id) + prev_child).
			replace_child_character(ctx, child, place->char_id);
			apply_place_object(ctx, child, place);
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
				fresh = instantiate_child(ctx, obj, place);
			}
			else
			{
				fresh = instantiate_child(ctx, obj, place);
			}
			if (fresh != NULL)
			{
				Avm2DisplayObjectExt* fext = avm2_display_ext_of(ctx, fresh);
				if (fext != NULL) fext->place_frame = cmd->frame;
			}
			child = fresh;
		}
		if (child != NULL && !is_rewind)
		{
			for (uint32_t mi = 0; mi < cmd->mod_count; mi++)
			{
				apply_place_object(ctx, child, cmd->mods[mi]);
			}
		}
	}

	g_gp_goto_ops += op_index;
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
	if (g_goto_prof >= 2)
	{
		g_gp_src_cls = (obj->cls != NULL && obj->cls->name.name != NULL)
			? obj->cls->name.name : "?";
		g_gp_src_frame = (int) frame;
		g_gp_src_noop = (frame == ext->current_frame);
	}
	if (stop) ext->playing = 0;
	else ext->playing = 1;
	if (frame < 1) frame = 1;
	avm2_display_mark_frame_work(ctx, obj);
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
	// A SimpleButton's state child is not in render_list; a TextField inside
	// the painted state still needs its lazy autosize flushed before the
	// render pass reads its bounds.
	{
		Avm2Object* bst = avm2_button_state_child(ext);
		if (bst != NULL) render_apply_text_bounds(ctx, bst, visible);
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

// Loader/LoaderInfo frame hooks (defined with the LoaderInfo state machine
// below): queued fetches resolve, and init/complete fire, after the frame's
// exitFrame broadcast.
static void avm2_loaderinfo_run_exit_frame(Avm2Context* ctx);
static void avm2_loader_drain(Avm2Context* ctx);

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
	for (uint32_t i = 0;
	     i < (walk_skip_on() ? g_orphan_dirty_count : g_orphan_count); i++)
	{
		Avm2Object* o = walk_skip_on() ? g_orphan_dirty[i] : g_orphans[i];
		if (orphan_dirty_ext(o, walk_skip_on()) == NULL) continue;
		construct_frame_obj(ctx, o);
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
	for (uint32_t i = 0;
	     i < (walk_skip_on() ? g_orphan_dirty_count : g_orphan_count); i++)
	{
		Avm2Object* o = walk_skip_on() ? g_orphan_dirty[i] : g_orphans[i];
		if (orphan_dirty_ext(o, walk_skip_on()) == NULL) continue;
		run_frame_scripts_obj(ctx, o);
	}
	run_frame_script_cleanup(ctx);

	ctx->frame_phase = PHASE_EXIT;
	broadcast_named(ctx, "exitFrame");
	// Ruffle run_exit_frame: the root movie's LoaderInfo fires init/complete
	// here — after exitFrame, before the next frame's enterFrame
	// (loaderinfo_events pins this ordering). Loader fetches resolve right
	// after, which is where Ruffle's test harness runs the async executor.
	avm2_loaderinfo_run_exit_frame(ctx);
	// Stage3D context creation is DEFERRED to exactly here (Ruffle
	// frame_lifecycle.rs:104, right after broadcast_frame_exited and its
	// LoadManager::run_exit_frame): a requestContext3D made during frame N
	// gets its Context3D and its `context3DCreate` event at the END of frame
	// N, before frame N+1's enterFrame. avm2/context3d_creation grades that
	// interleaving line by line.
	avm2_stage3d_check_requested(ctx);
	// LocalConnection delivery sits where Ruffle runs
	// LocalConnections::update_connections: inside run_frame, after the AVM2
	// phases and BEFORE the NetConnection flush below (avm2/amf_array_
	// serialization traces its delivered message ahead of both remoting packets).
	avm2_net_deliver_local_connections(ctx);
	avm2_loader_drain(ctx);
	// NetConnection.call: the queued packet is sent and its scripted response
	// dispatched at the same executor-drain point a Loader fetch resolves at, so
	// the fetch log and the Responder callbacks follow the calling frame's traces
	// (netconnection_send_remote pins that interleaving).
	avm2_net_flush_connections(ctx);
	orphan_cleanup(ctx);

	// Sockets: Ruffle's player.tick runs update_sockets right after the frame
	// and before update_timers, then polls the mock transport once the tick is
	// over (runner.rs do_tick -> executor.run). swf_socket_tick is both halves
	// in that order — deliver, then pump — so an action queued during tick N
	// is dispatched after frame N+1 runs. No-op with no socket.json loaded.
	swf_socket_tick(2);

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
	// +AVM2_MAX_CHILD_MOVIES: a Loader-loaded movie adds its own root binding
	// (loader_boot_child_swf) after the stage is built.
	g_symbol_map_cap = avm2_generated_symbol_class_count + 1
	                   + AVM2_MAX_CHILD_MOVIES;
	g_symbol_map = avm2_alloc(ctx, g_symbol_map_cap * sizeof(SymbolClassMap));
	g_symbol_map_count = 0;
	for (uint32_t i = 0; i < avm2_generated_symbol_class_count; i++)
	{
		if (avm2_generated_symbol_classes[i].char_id == 0) continue;
		if (avm2_generated_symbol_classes[i].class_name == NULL) continue;
		Avm2Class* cls =
			class_for_dotted_name(ctx, avm2_generated_symbol_classes[i].class_name);
		symbol_map_add(cls, avm2_generated_symbol_classes[i].char_id);
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

	// Root class: SymbolClass char 0, defaulting to MovieClip. Ruffle
	// avm2.rs lookup_class_for_character: when the bound id names no
	// character (the char-0 root binding) the class MUST inherit Sprite,
	// otherwise linking fails with TypeError #2023 and the root stays a
	// plain MovieClip. Flash and Ruffle (Debug player mode, which the test
	// runner uses) trace the uncaught error — it is the last line of the
	// expected output for every avmplus test whose `Test` class extends
	// nothing (all 177 of them, e4x + as3/Vector).
	Avm2Class* root_cls = ctx->builtins.movieclip_class;
	Avm2Class* bound = NULL;
	if (root_class_name != NULL)
	{
		bound = class_for_dotted_name(ctx, root_class_name);
	}
	if (bound != NULL)
	{
		if (class_is_a(bound, ctx->builtins.sprite_class))
		{
			root_cls = bound;
		}
		else
		{
			// error.rs make_error_2023: the class object's name ("Test$").
			printf("TypeError: Error #2023: Class %.*s$ must inherit from"
			       " Sprite to link to the root.\n",
			       (int) bound->name.name_len, bound->name.name);
		}
	}

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
	mark_attached(ctx, rext, stage);
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
		mark_transformed_by_script(ext);
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
		mark_transformed_by_script(ext);
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
	key.ns_priv = NULL;
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

// Defined with the mouse-pick machinery further down; hitTestPoint's
// shapeFlag arm is the same walk the picker uses.
static int hit_test_shape_obj(Avm2Context* ctx, Avm2Object* obj,
                              double px, double py, int options);
#define HT_AVM_HIT_TEST 1  /* == HT_SKIP_MASK, declared with the picker */

// hitTestPoint(x, y, shapeFlag=false) — Ruffle display_object.rs
// hit_test_point.
//
// The coordinates are documented as stage-relative, and for anything inside a
// Loader-loaded movie they really are. For the PLAYER's own root (the movie
// with no Loader above it) Flash instead reads them as root-relative, matching
// AVM1 hitTest — so a rotated/moved root moves the point with it
// (movieclip_hittest's "inside now because of _root._rotation").
//
// shapeFlag picks the exact-shape walk, and an object that is not on the stage
// answers false outright no matter where its shape is.
static Avm2Value do_hit_test_point(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_bool(false);
	double x = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0;
	double y = act->argc > 1 ? avm2_coerce_to_number(ctx, act->args[1]) : 0;
	int shape_flag = act->argc > 2 && avm2_coerce_to_boolean(act->args[2]);
	avm2_text_apply_pending_bounds(ctx, self);

	double tx = x * 20.0, ty = y * 20.0;
	{
		Avm2Object* root = NULL;
		for (Avm2Object* n = self; n != NULL; )
		{
			Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, n);
			if (e == NULL) break;
			if (e->is_root && !e->is_stage) { root = n; break; }
			n = e->parent;
		}
		Avm2DisplayObjectExt* rext = root != NULL
			? avm2_display_ext_of(ctx, root) : NULL;
		// A Loader-loaded child root carries its own LoaderInfo; the player
		// root does not, and that is the one whose local space the point is in.
		if (rext != NULL && rext->loader_info == NULL)
		{
			Mat rm = display_world_matrix(ctx, root);
			double gx = rm.a * tx + rm.c * ty + rm.tx;
			double gy = rm.b * tx + rm.d * ty + rm.ty;
			tx = gx;
			ty = gy;
		}
	}

	if (shape_flag)
	{
		if (!is_on_stage(ctx, self)) return avm2_bool(false);
		return avm2_bool(hit_test_shape_obj(ctx, self, tx, ty,
		                                    HT_AVM_HIT_TEST) != 0);
	}
	Mat m = display_world_matrix(ctx, self);
	Rect r = { 0, 0, 0, 0, 0 };
	bounds_with_transform(ctx, self, &m, &r);
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
		// the bounds resize, not the scale. Both of those Ruffle setters mark
		// transformed_by_script themselves (edit_text.rs:2651/:2667); the
		// non-EditText arm below is covered transitively via set_scale_*.
		mark_transformed_by_script(ext);
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
		mark_transformed_by_script(ext);
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

// Ruffle DisplayObject::set_mask keeps the pair symmetric: the old mask loses
// its maskee back-pointer, the new one gains it. The pick walk reads `maskee`
// to know an object is "only there to mask" and can never be a mouse target.
static Avm2Value do_set_mask(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && act->argc > 0)
	{
		Avm2Object* next = (act->args[0].kind == AVM2_VALUE_OBJECT)
			? act->args[0].u.obj : NULL;
		if (ext->mask != NULL && ext->mask != next)
		{
			Avm2DisplayObjectExt* old = avm2_display_ext_of(act->ctx, ext->mask);
			if (old != NULL && old->maskee == self) old->maskee = NULL;
		}
		ext->mask = next;
		if (next != NULL)
		{
			Avm2DisplayObjectExt* mext = avm2_display_ext_of(act->ctx, next);
			if (mext != NULL) mext->maskee = self;
		}
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

// Drop a display object's stored filter list (also the free path for a swept
// object: each entry may own an out-of-line convolution matrix).
static void clear_filters(Avm2Context* ctx, Avm2DisplayObjectExt* ext)
{
	if (ext->filters == NULL) { ext->filter_count = 0; return; }
	for (uint32_t i = 0; i < ext->filter_count; i++)
		avm2_filter_release(ctx, &ext->filters[i]);
	heap_free(ctx->app, ext->filters);
	ext->filters = NULL;
	ext->filter_count = 0;
}

// Ruffle display_object.rs set_filters + recheck_cache_as_bitmap.
static void store_filters(Avm2Context* ctx, Avm2DisplayObjectExt* ext,
                          const Avm2FilterVal* src, uint32_t count)
{
	clear_filters(ctx, ext);
	if (count == 0) return;
	ext->filters = (Avm2FilterVal*) avm2_alloc(ctx,
		count * (uint32_t) sizeof(Avm2FilterVal));
	if (ext->filters == NULL) return;
	for (uint32_t i = 0; i < count; i++)
		avm2_filter_copy(ctx, &ext->filters[i], &src[i]);
	ext->filter_count = count;
}

// PlaceObject3 SurfaceFilterList -> the object's filter list. The tag already
// holds the quantized form, so no AS-side conversion is involved.
void avm2_display_apply_tag_filters(Avm2Context* ctx, Avm2Object* obj,
                                    const Avm2TagFilter* tags, uint32_t count)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	clear_filters(ctx, ext);
	if (count == 0 || tags == NULL) return;
	ext->filters = (Avm2FilterVal*) avm2_alloc(ctx,
		count * (uint32_t) sizeof(Avm2FilterVal));
	if (ext->filters == NULL) return;
	for (uint32_t i = 0; i < count; i++)
		avm2_filter_from_tag(&tags[i], &ext->filters[i]);
	ext->filter_count = count;
}

static Avm2Value do_get_filters(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	Avm2Object* arr = avm2_array_new(ctx, 0);
	if (ext == NULL) return avm2_object_value(arr);
	// Brand-new objects every call: `o.filters === o.filters` is FALSE, and
	// `o.filters[0].blurX = 9` cannot reach the stored value.
	for (uint32_t i = 0; i < ext->filter_count; i++)
		avm2_array_push(ctx, arr, avm2_filter_to_object(ctx, &ext->filters[i]));
	return avm2_object_value(arr);
}

static Avm2Value do_set_filters(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	Avm2Value v = act->argc > 0 ? act->args[0] : avm2_undefined();
	// A non-Object (undefined / null / a number) CLEARS the list, no error.
	if (v.kind != AVM2_VALUE_OBJECT)
	{
		clear_filters(ctx, ext);
		return avm2_undefined();
	}
	Avm2ArrayExt* ae = avm2_array_ext(v.u.obj);
	// An Object that is not an Array is a silent no-op — the previous list
	// survives untouched.
	if (ae == NULL) return avm2_undefined();

	// Convert into a scratch list FIRST: a bad element throws #2005 and the
	// previous list must be preserved. avm2_throw_error does not return, so
	// the scratch list is simply abandoned to the collector's free path.
	uint32_t n = ae->length;
	Avm2FilterVal* tmp = NULL;
	uint32_t count = 0;
	if (n > 0)
	{
		tmp = (Avm2FilterVal*) avm2_alloc(ctx, n * (uint32_t) sizeof(Avm2FilterVal));
		if (tmp == NULL) return avm2_undefined();
	}
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2Value e = avm2_array_get(v.u.obj, i);
		// A true HOLE is skipped silently; a stored `undefined` is NOT a hole
		// and does throw.
		if (e.kind == AVM2_VALUE_HOLE) continue;
		if (e.kind != AVM2_VALUE_OBJECT
		    || !avm2_filter_from_object(ctx, e.u.obj, &tmp[count]))
		{
			// The parameter index is HARDCODED 0 whatever the position.
			avm2_throw_error(ctx, ctx->builtins.argument_error_class,
				"Error #2005: Parameter 0 is of the incorrect type. "
				"Should be type Filter.");
		}
		count++;
	}
	store_filters(ctx, ext, tmp, count);
	for (uint32_t i = 0; i < count; i++) avm2_filter_release(ctx, &tmp[i]);
	if (tmp != NULL) heap_free(ctx->app, tmp);
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

// --- flash.display.LoaderInfo (per-instance stream state) ---
//
// Ruffle model (core/src/avm2/object/loaderinfo_object.rs): every LoaderInfo
// carries a LoaderStream — NotYetLoaded(movie, root_clip, is_stage) or
// Swf(movie, root) — plus init/complete-fired flags, `expose_content`,
// `errored` and a sniffed content type. Three flavours exist:
//
//   ROOT   the root movie's LoaderInfo, shared by every on-stage display
//          object and `=== root.loaderInfo` (loaderinfo_root). Its stream is
//          Swf from the start (frameRate/width/… answer immediately) and
//          `expose_content` is set, but `init` does not fire until the first
//          frame's exitFrame boundary and `contentType` stays null until then
//          (content_type_hide_before_init).
//   STAGE  stage.loaderInfo — a DISTINCT object (Ruffle context.rs, is_stage),
//          permanently NotYetLoaded over the root movie: byte counts, url and
//          content read through, but the eight movie-describing getters throw
//          #2099 and contentType is null forever because `init` never fires
//          (stage_loaderinfo_properties).
//   LOADER a Loader's contentLoaderInfo. NotYetLoaded with no root clip until
//          something loads: url/content are null (expose_content unset) and
//          the eight getters throw #2099 (loaderinfo_properties_not_loaded).
//
// Every gate below keys on the state of the receiving instance, never on
// "is this a Loader's LoaderInfo".

enum { LI_KIND_LOADER = 0, LI_KIND_ROOT, LI_KIND_STAGE };

// Ruffle loader::ContentType.
enum { LI_CT_UNKNOWN = 0, LI_CT_SWF, LI_CT_JPEG, LI_CT_JPEGXR, LI_CT_PNG,
       LI_CT_GIF };

typedef struct Avm2LoaderInfoExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Object* parameters;             // stable identity across reads
	Avm2Object* content;                // stream root clip (LOADER only; ROOT
	                                    // and STAGE read ctx->root via `kind`)
	Avm2Object* loader;                 // owning Loader (NULL for ROOT/STAGE)
	Avm2Object* shared_events;          // sharedEvents (lazy EventDispatcher)
	Avm2Object* app_domain;             // LoaderContext's ApplicationDomain
	// The domain the loaded movie's ABC registered into (tranche 8). Drives
	// app_domain above, the movie's own name resolution, and its root binding.
	const Avm2DomainScope* scope;
	const Avm2String* url;              // stream movie URL (LOADER only)
	const Avm2String* loader_url;       // URL of the movie that ISSUED the load
	                                    // (NULL = the root SWF's own URL)
	// A loadBytes SWF whose root is constructed at the next drain rather than
	// inside the loadBytes() call (see loader_deliver). Static storage, so the
	// conservative native_ext scan can only over-retain it.
	const Avm2MovieTables* pending_boot;
	const uint8_t* bytes;               // loaded source bytes (static storage)
	uint32_t bytes_len;
	uint32_t bytes_loaded;
	uint32_t bytes_total;
	uint8_t kind;
	uint8_t loaded;          // 1 = LoaderStream::Swf (else NotYetLoaded)
	uint8_t expose_content;  // content/url readable
	uint8_t load_started;    // a load()/loadBytes() has begun (bytes != null)
	uint8_t init_fired;
	uint8_t complete_fired;
	uint8_t errored;
	uint8_t content_type;
	// The stream came from a real fetch, not loadBytes. Ruffle's navigator
	// reports an HTTPStatusEvent for every fetch (status 0 over file://) and
	// loadBytes never fetches, so this gates the event between init and
	// complete (loader_events expects it; loader_loadbytes_events must not).
	uint8_t from_fetch;
} Avm2LoaderInfoExt;

// GC-rooted in avm2_gc_mark_roots_display.
static Avm2Object* g_root_loader_info;
static Avm2Object* g_stage_loader_info;
static double g_stage_frame_rate;        // tentative decl; defined below (Stage)

static Avm2LoaderInfoExt* loaderinfo_ext_of(Avm2Context* ctx, Avm2Object* o)
{
	if (o == NULL || o->cls == NULL
	    || !class_is_a(o->cls, ctx->builtins.loader_info_class))
		return NULL;
	return (Avm2LoaderInfoExt*) o->native_ext;
}

static uint32_t root_swf_size(void)
{
#ifdef SWF_ONDISK_SIZE
	return (uint32_t) SWF_ONDISK_SIZE;
#else
	return 0;
#endif
}

static const Avm2String* root_swf_url(Avm2Context* ctx)
{
#ifdef SWF_URL
	return avm2_string_from_literal(ctx, SWF_URL);
#else
	return avm2_string_from_literal(ctx, "");
#endif
}

static Avm2Object* loaderinfo_new(Avm2Context* ctx, uint8_t kind)
{
	Avm2Class* cls = ctx->builtins.loader_info_class;
	if (cls == NULL) return NULL;
	Avm2Value v = avm2_class_construct(ctx, cls, NULL, 0);
	if (v.kind != AVM2_VALUE_OBJECT) return NULL;
	Avm2LoaderInfoExt* ext = loaderinfo_ext_of(ctx, v.u.obj);
	if (ext != NULL)
	{
		ext->kind = kind;
		if (kind != LI_KIND_LOADER)
		{
			// Both describe the root SWF and expose their content before
			// `init` (movie_clip.rs::player_root_movie / context.rs).
			ext->expose_content = 1;
			ext->bytes_loaded = ext->bytes_total = root_swf_size();
		}
		if (kind == LI_KIND_ROOT)
		{
			ext->loaded = 1;              // LoaderStream::Swf from the start
			ext->content_type = LI_CT_SWF;
		}
	}
	return v.u.obj;
}

static Avm2Object* avm2_get_root_loader_info(Avm2Context* ctx)
{
	if (g_root_loader_info == NULL)
		g_root_loader_info = loaderinfo_new(ctx, LI_KIND_ROOT);
	return g_root_loader_info;
}

static Avm2Object* avm2_get_stage_loader_info(Avm2Context* ctx)
{
	if (g_stage_loader_info == NULL)
		g_stage_loader_info = loaderinfo_new(ctx, LI_KIND_STAGE);
	return g_stage_loader_info;
}

static Avm2Value do_get_loader_info(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	// The Stage has its OWN LoaderInfo, distinct from the root clip's
	// (Ruffle context.rs, is_stage = true): it never fires `init`.
	Avm2DisplayObjectExt* dext = avm2_display_ext_of(ctx, self);
	if (dext != NULL && dext->is_stage)
	{
		Avm2Object* sli = avm2_get_stage_loader_info(ctx);
		return sli != NULL ? avm2_object_value(sli) : avm2_null();
	}
	// loaderInfo is non-null only for objects connected to the root SWF.
	Avm2Object* root = avm2_root_of(ctx, self);
	if (root == NULL) return avm2_null();
	// A Loader-loaded child movie answers ITS OWN contentLoaderInfo, so
	// `loader.contentLoaderInfo === loader.content.loaderInfo` holds for the
	// child root and for everything under it (loader-arc tranche 6).
	Avm2DisplayObjectExt* rext = avm2_display_ext_of(ctx, root);
	if (rext != NULL && rext->loader_info != NULL)
		return avm2_object_value(rext->loader_info);
	Avm2Object* li = avm2_get_root_loader_info(ctx);
	return li != NULL ? avm2_object_value(li) : avm2_null();
}

static Avm2LoaderInfoExt* this_li(Avm2Activation* act)
{
	return loaderinfo_ext_of(act->ctx, this_obj(act));
}

// The URL of the movie a DisplayObject belongs to. It is the base a relative
// load URL resolves against, and the `loaderURL` stamped on whatever that
// movie loads — both are per-issuer, not per-run: loader_loaderurl chains
// test.swf -> load1.swf -> load2.swf and expects load2's loaderURL to name
// load1. A Loader-loaded child root carries its own LoaderInfo (tranche 6a's
// back-pointer); anything else belongs to the root SWF.
static const Avm2String* movie_url_of(Avm2Context* ctx, Avm2Object* dobj)
{
	Avm2Object* root = dobj != NULL ? avm2_root_of(ctx, dobj) : NULL;
	Avm2DisplayObjectExt* rext = root != NULL
	                             ? avm2_display_ext_of(ctx, root) : NULL;
	if (rext != NULL && rext->loader_info != NULL)
	{
		Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, rext->loader_info);
		if (lx != NULL && lx->url != NULL) return lx->url;
	}
	return root_swf_url(ctx);
}

// The domain a DisplayObject's movie runs in - the scope counterpart of
// movie_url_of. Anything not reached through a Loader is the root movie.
static const Avm2DomainScope* movie_scope_of(Avm2Context* ctx, Avm2Object* dobj)
{
	Avm2Object* root = dobj != NULL ? avm2_root_of(ctx, dobj) : NULL;
	Avm2DisplayObjectExt* rext = root != NULL
	                             ? avm2_display_ext_of(ctx, root) : NULL;
	if (rext != NULL && rext->loader_info != NULL)
	{
		Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, rext->loader_info);
		if (lx != NULL && lx->scope != NULL) return lx->scope;
	}
	return avm2_domain_root_scope(ctx);
}

// The eight getters that describe the *loaded movie* throw while the stream is
// NotYetLoaded (Ruffle make_error_2099): actionScriptVersion, childAllowsParent,
// frameRate, height, parentAllowsChild, sameDomain, swfVersion, width.
static void li_require_loaded(Avm2Activation* act, Avm2LoaderInfoExt* ext)
{
	if (ext != NULL && ext->loaded) return;
	avm2_throw_error(act->ctx, act->ctx->builtins.error_class,
	                 "Error #2099: The loading object is not sufficiently "
	                 "loaded to provide this information.");
}

static Avm2Value li_get_bytes_loaded(Avm2Activation* act)
{
	Avm2LoaderInfoExt* ext = this_li(act);
	return avm2_number(ext != NULL ? (double) ext->bytes_loaded : 0);
}

static Avm2Value li_get_bytes_total(Avm2Activation* act)
{
	Avm2LoaderInfoExt* ext = this_li(act);
	return avm2_number(ext != NULL ? (double) ext->bytes_total : 0);
}

static Avm2Value li_get_content(Avm2Activation* act)
{
	Avm2LoaderInfoExt* ext = this_li(act);
	if (ext == NULL || !ext->expose_content) return avm2_null();
	if (ext->kind != LI_KIND_LOADER)
	{
		Avm2Object* r = act->ctx->root;
		return r != NULL ? avm2_object_value(r) : avm2_null();
	}
	return ext->content != NULL ? avm2_object_value(ext->content) : avm2_null();
}

static Avm2Value li_get_content_type(Avm2Activation* act)
{
	Avm2LoaderInfoExt* ext = this_li(act);
	if (ext == NULL) return avm2_undefined();
	// content_type_hide_before_init: Unknown (→ null) until `init` fired on
	// THIS LoaderInfo. The Stage's never does, so its contentType stays null.
	uint8_t ct = ext->init_fired ? ext->content_type : LI_CT_UNKNOWN;
	const char* s = NULL;
	switch (ct)
	{
		case LI_CT_SWF:    s = "application/x-shockwave-flash"; break;
		case LI_CT_JPEG:   s = "image/jpeg"; break;
		case LI_CT_JPEGXR: s = "image/jpegxr"; break;
		case LI_CT_PNG:    s = "image/png"; break;
		case LI_CT_GIF:    s = "image/gif"; break;
		default: return avm2_null();
	}
	return avm2_string(avm2_string_from_literal(act->ctx, s));
}

static Avm2Value li_get_as_version(Avm2Activation* act)
{
	li_require_loaded(act, this_li(act));
	return avm2_integer(3);
}

static Avm2Value li_get_frame_rate(Avm2Activation* act)
{
	li_require_loaded(act, this_li(act));
	return avm2_number(g_stage_frame_rate);
}

static Avm2Value li_get_width(Avm2Activation* act)
{
	li_require_loaded(act, this_li(act));
	return avm2_integer((avm2_generated_stage_rect[1]
	                     - avm2_generated_stage_rect[0]) / 20);
}

static Avm2Value li_get_height(Avm2Activation* act)
{
	li_require_loaded(act, this_li(act));
	return avm2_integer((avm2_generated_stage_rect[3]
	                     - avm2_generated_stage_rect[2]) / 20);
}

static Avm2Value li_get_swf_version(Avm2Activation* act)
{
	li_require_loaded(act, this_li(act));
	return avm2_integer(avm2_generated_swf_version);
}

static Avm2Value li_get_url(Avm2Activation* act)
{
	Avm2LoaderInfoExt* ext = this_li(act);
	// Ruffle returns null for a LoaderInfo that is not exposing content — a
	// fresh Loader's url is null before, during and after a load
	// (loaderinfo_loadurl).
	if (ext == NULL || !ext->expose_content) return avm2_null();
	if (ext->kind == LI_KIND_LOADER && ext->url != NULL)
		return avm2_string(ext->url);
	return avm2_string(root_swf_url(act->ctx));
}

// loaderURL is the URL of the movie that *initiated* the load, recorded on the
// LoaderInfo when the load is issued. Absent that (the root SWF, and anything
// loaded before the stamp exists) it is the root SWF's own URL.
static Avm2Value li_get_loader_url(Avm2Activation* act)
{
	Avm2LoaderInfoExt* ext = this_li(act);
	if (ext != NULL && ext->loader_url != NULL)
		return avm2_string(ext->loader_url);
	return avm2_string(root_swf_url(act->ctx));
}

// childAllowsParent / parentAllowsChild / sameDomain: Ruffle compares the
// child's and the parent's URL hosts, which for our file:// corpus always
// match. Both are stubbed true; the meaningful part is the NotYetLoaded throw.
static Avm2Value li_get_allows(Avm2Activation* act)
{
	li_require_loaded(act, this_li(act));
	return avm2_bool(1);
}

static Avm2Value li_get_is_url_inaccessible(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(0);
}

static Avm2Value li_get_shared_events(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2LoaderInfoExt* ext = this_li(act);
	if (ext == NULL) return avm2_undefined();
	if (ext->shared_events == NULL)
	{
		Avm2Value v = avm2_class_construct(ctx, ctx->builtins.event_dispatcher_class,
		                                   NULL, 0);
		ext->shared_events = v.kind == AVM2_VALUE_OBJECT ? v.u.obj : NULL;
	}
	return ext->shared_events != NULL ? avm2_object_value(ext->shared_events)
	                                  : avm2_null();
}

// Three-state (Ruffle get_bytes): null before anything starts loading, an
// empty ByteArray while loading or after an unknown-type error, the real
// source bytes once content is loaded. The third state only materialises for
// content whose bytes we still hold (see loader_deliver) — a child SWF's are
// not in the movie registry yet, so it keeps handing back an empty ByteArray.
static Avm2Value li_get_bytes(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2LoaderInfoExt* ext = this_li(act);
	if (ext == NULL) return avm2_undefined();
	if (ext->kind == LI_KIND_LOADER && !ext->load_started) return avm2_null();
	Avm2Value v = avm2_class_construct(ctx, ctx->builtins.bytearray_class,
	                                   NULL, 0);
	if (v.kind != AVM2_VALUE_OBJECT) return avm2_null();
	if (ext->bytes != NULL && ext->bytes_len != 0)
	{
		Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(v);
		if (ba != NULL)
		{
			avm2_bytearray_set_length_public(ctx, ba, ext->bytes_len);
			if (ba->bytes != NULL && ba->len == ext->bytes_len)
				memcpy(ba->bytes, ext->bytes, ext->bytes_len);
			ba->position = 0;   // loader_loadbytes_events pins position 0
		}
	}
	return v;
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
	Avm2LoaderInfoExt* ext = this_li(act);
	if (ext == NULL) return avm2_undefined();
	// The root SWF always has a domain; a Loader's is null until its movie is
	// registered in one, then it is the LoaderContext's (loaderinfo_more).
	if (ext->kind != LI_KIND_LOADER) return avm2_current_domain_value(act->ctx);
	return ext->app_domain != NULL ? avm2_object_value(ext->app_domain)
	                               : avm2_null();
}

static Avm2Value li_get_loader(Avm2Activation* act)
{
	Avm2LoaderInfoExt* ext = this_li(act);
	if (ext == NULL || ext->loader == NULL) return avm2_null();
	return avm2_object_value(ext->loader);
}

// Ruffle fire_init_and_complete_events: idempotent, called at the end of every
// frame for the root movie and for every in-flight loader. `init` precedes
// `complete`, and both land AFTER the frame's exitFrame broadcast
// (loaderinfo_events: … exitFrame, init!, enterFrame, exitFrame).
static void loaderinfo_fire_init_and_complete(Avm2Context* ctx, Avm2Object* li)
{
	Avm2LoaderInfoExt* ext = loaderinfo_ext_of(ctx, li);
	if (ext == NULL) return;
	ext->expose_content = 1;
	if (!ext->init_fired)
	{
		ext->init_fired = 1;
		dispatch_simple_event(ctx, li, "init", 0);
	}
	if (ext->kind == LI_KIND_LOADER && ext->from_fetch && !ext->complete_fired
	    && ext->loaded)
	{
		Avm2Object* hs = avm2_http_status_event_new(
			ctx, avm2_string_from_literal(ctx, "httpStatus"), 0, 0);
		if (hs != NULL) avm2_dispatch_event(ctx, li, hs);
	}
	if (!ext->complete_fired && ext->loaded)
	{
		ext->complete_fired = 1;
		dispatch_simple_event(ctx, li, "complete", 0);
	}
}

// End-of-frame hook: the root movie's LoaderInfo fires init/complete once, at
// the first frame's exitFrame boundary. The Stage's LoaderInfo is deliberately
// left alone — it is permanently NotYetLoaded and never fires `init`.
static void avm2_loaderinfo_run_exit_frame(Avm2Context* ctx)
{
	Avm2Object* li = avm2_get_root_loader_info(ctx);
	if (li != NULL) loaderinfo_fire_init_and_complete(ctx, li);
}

// --- flash.display.Loader ---
//
// A Loader owns its own contentLoaderInfo (a LoaderInfo in the LOADER flavour
// above), so listener registrations and every LoaderInfo getter are per
// instance. `load`/`loadBytes` drive the state machine and the event sequence,
// and an image payload is decoded into a real `Bitmap` content child. What
// they still do NOT instantiate is a child SWF — an AVM2 child has no runtime
// entry point (see SWFRecompDocs/plans/loader-arc.md tranche 6) — so `content`
// stays null for `application/x-shockwave-flash`. Everything a script can
// observe *about the load itself* (open / progress / init / complete / ioError,
// byte counts, contentType, url, applicationDomain) is real.

typedef struct Avm2LoaderExt
{
	Avm2DisplayObjectExt display;       // extends DisplayObjectContainer (MUST be first)
	Avm2Object* content_loader_info;    // own LoaderInfo (EventDispatcher), lazily built
	Avm2Object* content;                // loaded content (SWF: null until tranche 6)
} Avm2LoaderExt;

static Avm2LoaderExt* loader_ext_of(Avm2Context* ctx, Avm2Object* o)
{
	if (o == NULL || o->cls == NULL
	    || ctx->builtins.loader_class == NULL
	    || !class_is_a(o->cls, ctx->builtins.loader_class))
		return NULL;
	return (Avm2LoaderExt*) o->native_ext;
}

// The AGI no-op shell class (see loader_load). A concrete Sprite subclass whose
// ArmorGames-API methods are all no-ops; seeded as a Loader's `content` so a
// game's COMPLETE handler can assign it and call those methods without #1010.
static Avm2Class* g_agi_shell_class;

// Lazily build (and cache) a Loader's own contentLoaderInfo. Shared by the
// getter and the load paths.
static Avm2Object* loader_ensure_cli(Avm2Context* ctx, Avm2LoaderExt* ext,
                                     Avm2Object* self)
{
	if (ext == NULL) return NULL;
	if (ext->content_loader_info == NULL)
	{
		ext->content_loader_info = loaderinfo_new(ctx, LI_KIND_LOADER);
		Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, ext->content_loader_info);
		if (lx != NULL) lx->loader = self;
	}
	return ext->content_loader_info;
}

static Avm2Value loader_get_content_loader_info(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2LoaderExt* ext = loader_ext_of(ctx, self);
	Avm2Object* cli = loader_ensure_cli(ctx, ext, self);
	return cli != NULL ? avm2_object_value(cli) : avm2_null();
}

// Loader.as: `return this._contentLoaderInfo.content` — so it inherits the
// expose_content gate and reads null until `init` has fired.
static Avm2Value loader_get_content(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2LoaderExt* ext = loader_ext_of(ctx, this_obj(act));
	if (ext == NULL || ext->content == NULL) return avm2_null();
	Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, ext->content_loader_info);
	if (lx != NULL && !lx->expose_content) return avm2_null();
	return avm2_object_value(ext->content);
}

static Avm2Value loader_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

// Bounded substring search (Avm2String.utf8 is not guaranteed NUL-terminated).
static int avm2_str_contains(const Avm2String* s, const char* needle)
{
	if (s == NULL || s->utf8 == NULL || needle == NULL) return 0;
	size_t nl = strlen(needle);
	if (nl == 0) return 1;
	if ((size_t) s->len < nl) return 0;
	for (size_t i = 0; i + nl <= (size_t) s->len; i++)
		if (memcmp(s->utf8 + i, needle, nl) == 0) return 1;
	return 0;
}

// --- the load pipeline ------------------------------------------------------

// Ruffle ContentType::sniff. Anything we cannot name is Unknown, which is what
// drives the #2124 error path.
static uint8_t loader_sniff(const uint8_t* d, uint32_t n)
{
	if (d == NULL || n < 4) return LI_CT_UNKNOWN;
	if ((d[0] == 'F' || d[0] == 'C' || d[0] == 'Z')
	    && d[1] == 'W' && d[2] == 'S')
		return LI_CT_SWF;
	if (d[0] == 0xFF && d[1] == 0xD8 && d[2] == 0xFF) return LI_CT_JPEG;
	if (d[0] == 0x89 && d[1] == 'P' && d[2] == 'N' && d[3] == 'G')
		return LI_CT_PNG;
	if (memcmp(d, "GIF8", 4) == 0) return LI_CT_GIF;
	if (d[0] == 'I' && d[1] == 'I' && d[2] == 0xBC) return LI_CT_JPEGXR;
	return LI_CT_UNKNOWN;
}

// Ruffle resolves a request URL against the loading movie's URL before the
// load ever starts, so a relative "data.txt" is reported — and named in the
// #2124 message — as "file:///data.txt".
// `base` is the ISSUING movie's URL (movie_url_of), not the root SWF's — a
// child that loads "sibling.swf" resolves it next to itself.
static const Avm2String* loader_absolute_url(Avm2Context* ctx,
                                             const Avm2String* url,
                                             const Avm2String* base)
{
	if (url == NULL || url->utf8 == NULL) return url;
	for (uint32_t i = 0; i + 3 <= (uint32_t) url->len; i++)
		if (memcmp(url->utf8 + i, "://", 3) == 0) return url;
	if (base == NULL || base->len == 0) base = root_swf_url(ctx);
	if (base == NULL || base->len == 0) return url;
	uint32_t cut = 0;   // base up to and including its last '/'
	for (uint32_t i = 0; i < (uint32_t) base->len; i++)
		if (base->utf8[i] == '/') cut = i + 1;
	uint32_t skip = (url->len > 0 && url->utf8[0] == '/') ? 1 : 0;
	char buf[512];
	int n = snprintf(buf, sizeof(buf), "%.*s%.*s", (int) cut, base->utf8,
	                 (int) ((uint32_t) url->len - skip), url->utf8 + skip);
	if (n <= 0) return url;
	if (n > (int) sizeof(buf) - 1) n = (int) sizeof(buf) - 1;
	return avm2_string_new(ctx, buf, (uint32_t) n);
}

// The synthetic URL Flash gives a movie that arrived through `loadBytes`:
// the ISSUING movie's URL with "/[[DYNAMIC]]/<n>" appended (Ruffle
// loader.rs::loader_loadbytes). FP's <n> is a player-wide counter that never
// resets; Ruffle pins it at 1, and so do we — loader_loadbytes_url, the only
// test that grades this, rewrites "/<digit>" to "/<id>" in ActionScript before
// it traces, so the digit's value is not observable and its SHAPE is.
static const Avm2String* loader_dynamic_url(Avm2Context* ctx,
                                            const Avm2String* loader_url)
{
	if (loader_url == NULL || loader_url->utf8 == NULL)
		loader_url = root_swf_url(ctx);
	if (loader_url == NULL || loader_url->utf8 == NULL) return NULL;
	char buf[512];
	int n = snprintf(buf, sizeof(buf), "%.*s/[[DYNAMIC]]/1",
	                 (int) loader_url->len, loader_url->utf8);
	if (n <= 0) return NULL;
	if (n > (int) sizeof(buf) - 1) n = (int) sizeof(buf) - 1;
	return avm2_string_new(ctx, buf, (uint32_t) n);
}

// Trailing path component of a URL, as the bundled-asset registries key them.
static void loader_basename(const Avm2String* url, char* out, size_t out_len)
{
	out[0] = '\0';
	if (url == NULL || url->utf8 == NULL) return;
	// A query string is not part of the file name: `./loadable.swf?a=1` keys
	// the registry as `loadable.swf` (loader_events).
	uint32_t end = 0;
	while (end < (uint32_t) url->len && url->utf8[end] != '?'
	       && url->utf8[end] != '#') end++;
	uint32_t start = 0;
	for (uint32_t i = 0; i < end; i++)
		if (url->utf8[i] == '/' || url->utf8[i] == '\\') start = i + 1;
	uint32_t n = end - start;
	if (n >= out_len) n = (uint32_t) out_len - 1;
	memcpy(out, url->utf8 + start, n);
	out[n] = '\0';
}

// The same URL keyed by its RELATIVE PATH rather than its trailing component
// (loader-arc tranche 8). Four Loader tests keep their children in
// subdirectories and load them as "child/child.swf"; two of
// loader_duplicate_class's share a basename across directories, so the
// basename alone cannot tell them apart. Writes nothing for an absolute URL —
// the basename key is the only thing that can match one of those.
static void loader_relpath(const Avm2String* url, char* out, size_t out_len)
{
	out[0] = '\0';
	if (url == NULL || url->utf8 == NULL) return;
	uint32_t end = 0;
	while (end < (uint32_t) url->len && url->utf8[end] != '?'
	       && url->utf8[end] != '#') end++;
	for (uint32_t i = 0; i + 3 <= end; i++)
		if (memcmp(url->utf8 + i, "://", 3) == 0) return;
	uint32_t start = 0;
	for (;;)
	{
		if (start + 2 <= end && url->utf8[start] == '.'
		    && url->utf8[start + 1] == '/') { start += 2; continue; }
		if (start < end && url->utf8[start] == '/') { start += 1; continue; }
		break;
	}
	uint32_t n = end - start;
	if (n >= out_len) n = (uint32_t) out_len - 1;
	memcpy(out, url->utf8 + start, n);
	out[n] = '\0';
}

// Everything a queued load needs to replay at the next frame boundary.
typedef struct Avm2PendingLoad
{
	Avm2Object* loader_info;
	Avm2Object* app_domain;    // the LoaderContext's domain, or NULL
	const Avm2DomainScope* scope;   // ...as a resolution scope (NULL = fresh)
	const Avm2String* url;
	const uint8_t* data;       // NULL when only a byte count is known
	uint32_t len;
	// SWF content only (loader-arc tranche 6). `len` above stays the FILE
	// size, which is what the progress events report; a compressed SWF's
	// `bytes` is its DECOMPRESSED image, so it needs its own pair.
	const Avm2MovieTables* tables;  // child's emitted table set (NULL = none)
	const uint8_t* swf_bytes;
	uint32_t swf_bytes_len;
	// The file as it sits on disk (see MovieEntry.raw_bytes). Only a URLLoader
	// reads this; the Loader pipeline works off `tables` + `swf_bytes`.
	const uint8_t* raw_bytes;
	uint32_t raw_bytes_len;
	uint8_t content_type;
	uint8_t data_static;       // `data` is generated-static (safe to alias)
} Avm2PendingLoad;

// Loads issued in one frame all resolve at the next frame's start; a handful
// is all any test (or game) has in flight at once.
#define AVM2_MAX_PENDING_LOADS 32
static Avm2PendingLoad g_pending_loads[AVM2_MAX_PENDING_LOADS];
static uint32_t g_pending_load_count;

// LoaderInfos with a load in flight. Walked at the end of every frame so that
// init/complete land after the exitFrame broadcast (Ruffle run_exit_frame).
#define AVM2_MAX_ACTIVE_LOADS 32
static Avm2Object* g_active_loader_infos[AVM2_MAX_ACTIVE_LOADS];
static uint32_t g_active_loader_info_count;

static void loader_track_active(Avm2Object* li)
{
	for (uint32_t i = 0; i < g_active_loader_info_count; i++)
		if (g_active_loader_infos[i] == li) return;
	if (g_active_loader_info_count < AVM2_MAX_ACTIVE_LOADS)
		g_active_loader_infos[g_active_loader_info_count++] = li;
}

// Reset a LoaderInfo to the fresh NotYetLoaded state — Ruffle's
// LoaderInfoObject::unload, run both by Loader.unload() and at the start of
// every load (loaderinfo_more reads applicationDomain back as null after
// unload; loaderinfo_loadurl reads url as null in all four states).
static void loaderinfo_reset_stream(Avm2LoaderInfoExt* lx)
{
	if (lx == NULL) return;
	lx->loaded = 0;
	lx->expose_content = 0;
	lx->load_started = 0;
	lx->init_fired = 0;
	lx->complete_fired = 0;
	lx->errored = 0;
	lx->content_type = LI_CT_UNKNOWN;
	lx->content = NULL;
	lx->app_domain = NULL;
	lx->url = NULL;
	lx->loader_url = NULL;
	lx->pending_boot = NULL;
	lx->bytes = NULL;
	lx->bytes_len = 0;
	lx->bytes_loaded = 0;
	lx->bytes_total = 0;
	lx->from_fetch = 0;
	// `parameters` keeps its identity across a reload (Ruffle rebuilds the
	// bag per movie, but no test observes the old object surviving) — its
	// CONTENTS must not, or a second load of a query-less URL would still
	// report the first load's flashvars.
	lx->parameters = NULL;
}

// Drop whatever a Loader is currently showing: Ruffle's Loader::unload removes
// the content from the display list as well as clearing the stream, and every
// load() / loadBytes() begins with an implicit unload.
static void loader_drop_content(Avm2Context* ctx, Avm2Object* self,
                                Avm2LoaderExt* ext)
{
	if (ext == NULL) return;
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, self);
	if (ext->content != NULL && pext != NULL
	    && render_index_of(pext, ext->content) >= 0)
	{
		full_remove_child(ctx, pext, ext->content);
	}
	ext->content = NULL;
	loaderinfo_reset_stream(loaderinfo_ext_of(ctx, ext->content_loader_info));
}

// Read `url` off a URLRequest argument (NULL when absent or not a request).
static const Avm2String* request_url(Avm2Context* ctx, Avm2Value v)
{
	if (v.kind != AVM2_VALUE_OBJECT) return NULL;
	int found = 0;
	Avm2Value uv = avm2_get_public_property(ctx, v, "url", 3, &found);
	return (found && uv.kind == AVM2_VALUE_STRING) ? uv.u.str : NULL;
}

// --- Ruffle test-navigator fetch log ---------------------------------------
//
// `log_fetch = true` tests grade the request the player WOULD have made, in
// TestNavigatorBackend::fetch's format (utils.h). What gets logged is the
// `Request` that globals/flash/display/loader.rs::request_from_url_request
// derives from the URLRequest, so this mirrors that conversion exactly — the
// GET-appends-data rule, the last-wins/first-position header map, the
// ByteArray-vs-toString payload, and the "empty payload demotes POST to GET"
// rule are all observable in the log and nowhere else.
//
// The log is QUEUED, not printed: Ruffle's fetch runs inside the spawned load
// future, which its harness only polls once the frame is over, so the block
// lands after the calling frame's traces (loader_method interleaves
// `undefined` from `trace(loader.load(req))` BEFORE its own fetch block).
// avm2_loader_drain flushes it.

#if SWF_LOG_FETCH_ENABLED

#define AVM2_MAX_LOG_HEADERS 32

static const Avm2String* log_str_prop(Avm2Context* ctx, Avm2Value v,
                                      const char* name, uint32_t nlen)
{
	int found = 0;
	Avm2Value pv = avm2_get_public_property(ctx, v, name, nlen, &found);
	if (!found || pv.kind == AVM2_VALUE_NULL || pv.kind == AVM2_VALUE_UNDEFINED)
		return NULL;
	return avm2_coerce_to_string(ctx, pv);
}

static int log_str_eq(const Avm2String* s, const char* lit)
{
	size_t n = strlen(lit);
	return s != NULL && s->len == n && memcmp(s->utf8, lit, n) == 0;
}

static void avm2_log_fetch_request(Avm2Context* ctx, Avm2Value request)
{
	if (request.kind != AVM2_VALUE_OBJECT) return;
	// A null url is #2007 in Ruffle, thrown before any fetch is spawned.
	const Avm2String* url = log_str_prop(ctx, request, "url", 3);
	if (url == NULL) return;

	const Avm2String* method = log_str_prop(ctx, request, "method", 6);
	int is_post = log_str_eq(method, "POST") || log_str_eq(method, "post");

	// requestHeaders: an IndexMap insert per URLRequestHeader entry, so a
	// repeated name keeps its FIRST position but takes its LAST value.
	// Non-URLRequestHeader array entries are skipped.
	SwfLogPair headers[AVM2_MAX_LOG_HEADERS];
	size_t nheaders = 0;
	int found = 0;
	Avm2Value hv = avm2_get_public_property(ctx, request, "requestHeaders", 14,
	                                        &found);
	if (found && hv.kind == AVM2_VALUE_OBJECT
	    && avm2_array_ext(hv.u.obj) != NULL)
	{
		uint32_t n = avm2_array_ext(hv.u.obj)->length;
		for (uint32_t i = 0; i < n; i++)
		{
			Avm2Value ev = avm2_array_get(hv.u.obj, i);
			if (ev.kind != AVM2_VALUE_OBJECT) continue;
			Avm2Class* c = avm2_value_class(ctx, ev);
			if (c == NULL || c->name.name_len != 16
			    || memcmp(c->name.name, "URLRequestHeader", 16) != 0) continue;
			const Avm2String* hn = log_str_prop(ctx, ev, "name", 4);
			const Avm2String* hval = log_str_prop(ctx, ev, "value", 5);
			if (hn == NULL) hn = avm2_string_from_literal(ctx, "");
			if (hval == NULL) hval = avm2_string_from_literal(ctx, "");
			size_t slot = nheaders;
			for (size_t j = 0; j < nheaders; j++)
			{
				if (headers[j].name_len == hn->len
				    && memcmp(headers[j].name, hn->utf8, hn->len) == 0)
				{
					slot = j;
					break;
				}
			}
			if (slot == nheaders)
			{
				if (nheaders >= AVM2_MAX_LOG_HEADERS) continue;
				nheaders++;
				headers[slot].name = hn->utf8;
				headers[slot].name_len = hn->len;
			}
			headers[slot].value = hval->utf8;
			headers[slot].value_len = hval->len;
		}
	}

	// The body. `data` null/undefined means no body at all; a GET instead
	// appends the stringified data to the URL (Flash-correct, per Ruffle).
	Avm2Value data = avm2_get_public_property(ctx, request, "data", 4, &found);
	if (!found) data = avm2_undefined();
	int has_data = !(data.kind == AVM2_VALUE_NULL
	                 || data.kind == AVM2_VALUE_UNDEFINED);

	char url_buf[2048];
	const char* url_ptr = url->utf8;
	size_t url_len = url->len;
	const unsigned char* body = NULL;
	size_t body_len = 0;
	const Avm2String* mime = NULL;
	int has_body = 0;

	if (has_data && !is_post)
	{
		const Avm2String* ds = avm2_coerce_to_string(ctx, data);
		int has_q = 0;
		for (uint32_t i = 0; i < url->len; i++)
			if (url->utf8[i] == '?') { has_q = 1; break; }
		size_t n = 0;
		for (uint32_t i = 0; i < url->len && n + 1 < sizeof(url_buf); i++)
			url_buf[n++] = url->utf8[i];
		if (!has_q && n + 1 < sizeof(url_buf)) url_buf[n++] = '?';
		for (uint32_t i = 0; i < ds->len && n + 1 < sizeof(url_buf); i++)
			url_buf[n++] = ds->utf8[i];
		url_ptr = url_buf;
		url_len = n;
	}
	else if (has_data)
	{
		Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(data);
		if (ba != NULL)
		{
			body = (const unsigned char*) ba->bytes;
			body_len = ba->len;
		}
		else
		{
			const Avm2String* ds = avm2_coerce_to_string(ctx, data);
			body = (const unsigned char*) ds->utf8;
			body_len = ds->len;
		}
		// An empty payload is no payload — and a request with no payload is
		// sent as a GET no matter what `method` says.
		if (body_len > 0)
		{
			has_body = 1;
			mime = log_str_prop(ctx, request, "contentType", 11);
			if (mime == NULL) mime = avm2_string_from_literal(ctx, "");
		}
	}
	if (!has_body) is_post = 0;

	int form = has_body
		&& log_str_eq(mime, "application/x-www-form-urlencoded");
	swf_log_fetch_queue(url_ptr, url_len, is_post ? "POST" : "GET",
	                    is_post ? 4 : 3, headers, nheaders,
	                    has_body ? mime->utf8 : NULL,
	                    has_body ? mime->len : 0,
	                    body, body_len, has_body, form);
}

#else

static void avm2_log_fetch_request(Avm2Context* ctx, Avm2Value request)
{
	(void) ctx; (void) request;
}

#endif

// Read `applicationDomain` off a LoaderContext argument (null when absent).
static Avm2Object* loader_context_domain(Avm2Context* ctx, Avm2Value v)
{
	if (v.kind != AVM2_VALUE_OBJECT) return NULL;
	int found = 0;
	Avm2Value d = avm2_get_public_property(ctx, v, "applicationDomain", 17,
	                                       &found);
	return (found && d.kind == AVM2_VALUE_OBJECT) ? d.u.obj : NULL;
}

// ...and the scope it stands for. NULL means "no domain was requested", which
// Ruffle answers with a fresh child of the loading movie's domain.
static const Avm2DomainScope* loader_context_scope(Avm2Context* ctx, Avm2Value v)
{
	Avm2Object* o = loader_context_domain(ctx, v);
	return o != NULL ? avm2_domain_scope_of_object(ctx, o) : NULL;
}

static int loader_hex_digit(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return -1;
}

// Populate LoaderInfo.parameters from the load URL's query string (Ruffle
// LoaderInfo parameters: the loaded movie's own flashvars). `?a=1&b=2` becomes
// two dynamic properties; a key with no `=` maps to the empty string, and
// percent-escapes are decoded. Called once per delivery, before the final
// progress event — loader_events reads `Parameters: (len=2)` there.
static void loaderinfo_fill_parameters(Avm2Context* ctx,
                                       Avm2LoaderInfoExt* lx,
                                       const Avm2String* url)
{
	if (lx == NULL || url == NULL || url->utf8 == NULL) return;
	uint32_t q = 0;
	while (q < (uint32_t) url->len && url->utf8[q] != '?') q++;
	if (q >= (uint32_t) url->len) return;
	if (lx->parameters == NULL)
	{
		Avm2Value o = avm2_class_construct(ctx, ctx->builtins.object_class,
		                                   NULL, 0);
		lx->parameters = o.kind == AVM2_VALUE_OBJECT ? o.u.obj : NULL;
	}
	if (lx->parameters == NULL) return;
	uint32_t i = q + 1;
	while (i < (uint32_t) url->len)
	{
		uint32_t start = i;
		while (i < (uint32_t) url->len && url->utf8[i] != '&') i++;
		uint32_t eq = start;
		while (eq < i && url->utf8[eq] != '=') eq++;
		char key[128], val[512];
		uint32_t kn = 0, vn = 0;
		for (uint32_t k = start; k < eq && kn + 1 < sizeof(key); k++)
			key[kn++] = url->utf8[k];
		key[kn] = '\0';
		for (uint32_t v = (eq < i ? eq + 1 : i); v < i && vn + 1 < sizeof(val); v++)
		{
			// %XX and '+' are the two escapes a query string can carry.
			if (url->utf8[v] == '+') { val[vn++] = ' '; continue; }
			if (url->utf8[v] == '%' && v + 2 < i)
			{
				int hi = loader_hex_digit(url->utf8[v + 1]);
				int lo = loader_hex_digit(url->utf8[v + 2]);
				if (hi >= 0 && lo >= 0)
				{
					val[vn++] = (char) ((hi << 4) | lo);
					v += 2;
					continue;
				}
			}
			val[vn++] = url->utf8[v];
		}
		val[vn] = '\0';
		if (kn != 0)
		{
			avm2_set_public_property(ctx, avm2_object_value(lx->parameters),
			                         key, kn,
			                         avm2_string(avm2_string_new(ctx, val, vn)));
		}
		i++;  // step past the '&'
	}
}

// Instantiate a loaded child SWF's root and hand it to the Loader
// (loader-arc.md tranche 6). Ruffle's movie_loader_data for SWF content
// registers the movie's ABC, links its root class and builds the root clip;
// the ORDER here is pinned by loader_events' output.txt, where the child's
// constructor traces `this.stage=null this.parent=null` and the circle it
// adds fires `added` (parent = the child root, stage null) BEFORE the child
// is attached to the Loader — so the ctor runs first, attachment second, and
// the recursive addedToStage falls out of insert_at_index.
// avm2_display_char_is_defined scoped to ONE loaded movie's tables rather than
// the main movie's globals. Same table list, same reason for checking all of
// them: missing one silently promotes a real symbol's class to root.
static int movie_char_is_defined(const Avm2MovieTables* t, uint16_t char_id)
{
	if (char_id == (uint16_t) t->char_id_base) return 1;   // its own timeline
	for (uint32_t i = 0; i < t->char_count; i++)
		if (t->chars[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->timeline_count; i++)
		if (t->timelines[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->shape_geom_count; i++)
		if (t->shape_geom[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->button_count; i++)
		if (t->buttons[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->edittext_count; i++)
		if (t->edittexts[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->statictext_count; i++)
		if (t->statictexts[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->bitmap_count; i++)
		if (t->bitmaps[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->binary_count; i++)
		if (t->binaries[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->sound_count; i++)
		if (t->sounds[i].char_id == char_id) return 1;
	for (uint32_t i = 0; i < t->font_count; i++)
		if (t->fonts[i].font_id == char_id) return 1;
	return 0;
}

static void loader_boot_child_swf(Avm2Context* ctx, Avm2Object* li,
                                  Avm2LoaderInfoExt* lx,
                                  const Avm2MovieTables* tables)
{
	if (tables == NULL || lx == NULL || lx->loader == NULL) return;
	// Everything this movie defines lands in ITS domain, and everything its
	// code resolves starts there (avm2_abc_load stamps the scope onto each
	// Avm2AbcFileRt). loader_deliver has already picked the scope: the
	// LoaderContext's, or a fresh child of the loading movie's.
	const Avm2DomainScope* scope = lx->scope != NULL
		? lx->scope : avm2_domain_root_scope(ctx);
	avm2_abc_register_movie(ctx, tables, scope);
	if (g_child_movie_count < AVM2_MAX_CHILD_MOVIES)
	{
		uint32_t i = 0;
		while (i < g_child_movie_count && g_child_movies[i] != tables) i++;
		if (i == g_child_movie_count) g_child_movies[g_child_movie_count++] = tables;
	}

	// The movie's own root binding: SymbolClass char 0, which the emitter
	// wrote as char_id_base + 0.
	uint16_t root_char = (uint16_t) tables->char_id_base;
	const char* root_name = NULL;
	for (uint32_t i = 0; i < tables->symbol_class_count; i++)
	{
		if (tables->symbol_classes[i].char_id == root_char)
			root_name = tables->symbol_classes[i].class_name;
	}
	// Same `None =>` arm the main movie takes (avm2_main.c build_stage): a
	// binding whose id names no character in THIS movie is its root class,
	// whatever the id. loader_loadbytes_url self-loads a SWF that binds Test to
	// character 1 and defines no character 1, so without this the loaded copy
	// comes up a bare MovieClip and its whole test body never runs.
	for (uint32_t i = 0; root_name == NULL && i < tables->symbol_class_count; i++)
	{
		if (!movie_char_is_defined(tables, tables->symbol_classes[i].char_id))
			root_name = tables->symbol_classes[i].class_name;
	}
	Avm2Class* root_cls = ctx->builtins.movieclip_class;
	if (root_name != NULL)
	{
		Avm2Class* bound = class_for_dotted_name_in(ctx, scope, root_name);
		if (bound != NULL)
		{
			// Same #2023 gate as the main movie's root (build_stage).
			if (class_is_a(bound, ctx->builtins.sprite_class)) root_cls = bound;
			else
				printf("TypeError: Error #2023: Class %.*s$ must inherit from"
				       " Sprite to link to the root.\n",
				       (int) bound->name.name_len, bound->name.name);
			// movie_clip.rs preload_symbol_class, the `None =>` arm: a binding
			// whose id names no character does NOT stop at "this is the root
			// class" — Ruffle also registers the root clip itself AS that
			// character ("We also need to register this MovieClip as a
			// character now"), so a later script `new RootClass()` instantiates
			// a fresh copy of the root TIMELINE, children and all. We key the
			// symbol map by the timeline's own char (base + 0), which is the
			// same object under a different id. Without it,
			// `new getDefinition("LoadableMain")()` comes up childless and
			// `instance.myChild` reads null (instantiate_root_character).
			if (root_cls != ctx->builtins.movieclip_class)
				symbol_map_add(root_cls, root_char);
		}
	}

	g_timeline_instantiation = 1;
	Avm2Object* child = display_alloc_instance(ctx, root_cls);
	g_timeline_instantiation = 0;
	Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
	if (cext == NULL) return;
	cext->is_root = 1;
	cext->char_id = root_char;
	cext->timeline = timeline_for_char(root_char);
	cext->instantiated_by_timeline = 1;
	cext->depth = 0;
	cext->loader_info = li;   // loader.content.loaderInfo === contentLoaderInfo

	// Constructed here, not by the next tick's construct walk: the ctor must
	// observe a null stage and a null parent.
	//
	// An uncaught error in the ROOT constructor aborts the load outright: the
	// debug player traces it, the content never becomes the Loader's child, and
	// neither `init` nor `complete` ever fires (loader_error_in_root_ctor).
	// The trace is LOCAL to this call site — the corpus-wide uncaught-error
	// tracing of `d1c307c51` stays reverted.
	cext->constructed = 1;
	Avm2Value exc = avm2_undefined();
	if (display_run_constructor_catching(ctx, child, &exc))
	{
		const Avm2String* s = avm2_error_stack_string(ctx, exc);
		printf("%.*s\n", (int) s->len, s->utf8);
		lx->errored = 1;   // drops it from the active list (run_exit_frame)
		return;
	}

	lx->content = child;
	// content/url become readable at ATTACH, not at init: the child's own
	// ctor reads them as null (`Loaded swf loaderInfo.url: null content:
	// null`) and its addedToStage handler, one step later, reads them both
	// (loader_loadbytes_events).
	lx->expose_content = 1;
	Avm2LoaderExt* lext = loader_ext_of(ctx, lx->loader);
	if (lext != NULL) lext->content = child;
	insert_at_index(ctx, lx->loader, child, 0);
	// Ruffle's movie_loader_data catches the new root up to its first frame
	// as part of the load (catchup_display_object_to_frame), so a child whose
	// constructor called addFrameScript runs it HERE — before init, not on
	// the next tick. loader_loadbytes_events pins the position: `Framescript
	// frame 1` sits between addedToStage and the identity checks.
	// Enter -> Construct -> FrameScripts for this subtree only. The phase is
	// borrowed for the construct leg because that is what arms a frame script
	// (check_has_pending_script runs only in PHASE_CONSTRUCT), and restored
	// afterwards so the caller's phase is unchanged.
	uint8_t saved_phase = ctx->frame_phase;
	if (cext->timeline != NULL && cext->playing) run_frame_internal(ctx, child, 1);
	ctx->frame_phase = PHASE_CONSTRUCT;
	construct_frame_obj(ctx, child);
	ctx->frame_phase = PHASE_FRAME_SCRIPTS;
	run_frame_scripts_obj(ctx, child);
	ctx->frame_phase = saved_phase;
	// The catch-up WAS this movie's first frame, so the next tick's enter
	// phase must not advance it again — otherwise a two-frame child runs
	// frames 1,2,1,2 across four ticks where Flash runs 1,1,2,1
	// (loader_loadbytes_events' trailing framescript traces).
	cext->skip_next_enter_frame = 1;
}

// The tail of a load, shared by the deferred `load` path and the synchronous
// `loadBytes` path (Ruffle movie_loader_data). `from_bytes` suppresses the URL
// suffix on the #2124 message, exactly as Ruffle does.
static void loader_deliver(Avm2Context* ctx, Avm2Object* li,
                           const Avm2PendingLoad* pl, int from_bytes)
{
	Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, li);
	if (lx == NULL) return;

	// Ruffle swaps in a "fake" movie whose compressed length is the fetched
	// byte count, so bytesTotal is live during the first progress event while
	// bytesLoaded is still 0.
	lx->content_type = pl->content_type;
	lx->from_fetch = from_bytes ? 0 : 1;
	lx->bytes_loaded = 0;
	lx->bytes_total = pl->len;
	Avm2Object* ev = avm2_progress_event_new(
		ctx, avm2_string_from_literal(ctx, "progress"), 0, (double) pl->len);
	if (ev != NULL) avm2_dispatch_event(ctx, li, ev);

	if (pl->content_type == LI_CT_UNKNOWN)
	{
		lx->errored = 1;
		lx->bytes_loaded = pl->len;
		ev = avm2_progress_event_new(ctx,
		                             avm2_string_from_literal(ctx, "progress"),
		                             (double) pl->len, (double) pl->len);
		if (ev != NULL) avm2_dispatch_event(ctx, li, ev);

		char msg[512];
		if (from_bytes || pl->url == NULL)
		{
			snprintf(msg, sizeof(msg),
			         "Error #2124: Loaded file is an unknown type.");
		}
		else
		{
			snprintf(msg, sizeof(msg),
			         "Error #2124: Loaded file is an unknown type. URL: %.*s",
			         (int) pl->url->len, pl->url->utf8);
		}
		ev = avm2_io_error_event_new(ctx,
		                             avm2_string_from_literal(ctx, "ioError"),
		                             avm2_string_from_literal(ctx, msg), 2124);
		if (ev != NULL) avm2_dispatch_event(ctx, li, ev);
		return;
	}

	// Known content. An image is decoded here — Ruffle builds the Bitmap before
	// it reports the final progress — and becomes the Loader's `content` and,
	// per movie_loader_complete, its child at index 0. JPEG-XR deliberately
	// gets no decode attempt: stb cannot read it, and loader_jpegxr /
	// loader_jpegxr_alpha only ever trace `contentType`, so sniffing it must
	// keep short-circuiting here rather than falling into a failed decode.
	// A SWF's content still awaits an AVM2 child entry point (loader-arc.md
	// tranche 6), so `content` stays null for it.
	int is_image = (pl->content_type == LI_CT_PNG || pl->content_type == LI_CT_JPEG
	                || pl->content_type == LI_CT_GIF);
	// A child SWF's `bytes` and `parameters` are readable from the FINAL
	// progress event onwards (loader_events reads bytes.length = 1490 and
	// Parameters: (len=2) there), so they land before it — unlike the byte
	// aliasing below, which stays where it is for image/loadBytes content.
	if (pl->content_type == LI_CT_SWF && pl->swf_bytes != NULL)
	{
		lx->bytes = pl->swf_bytes;
		lx->bytes_len = pl->swf_bytes_len;
	}
	if (pl->content_type == LI_CT_SWF) loaderinfo_fill_parameters(ctx, lx, pl->url);
	if (is_image && pl->data != NULL)
	{
		Avm2Object* bmp = avm2_bitmap_from_image_bytes(ctx, pl->data, pl->len);
		if (bmp != NULL)
		{
			lx->content = bmp;
			Avm2LoaderExt* lext = loader_ext_of(ctx, lx->loader);
			if (lext != NULL)
			{
				lext->content = bmp;
				insert_at_index(ctx, lx->loader, bmp, 0);
			}
		}
	}

	// The stream becomes Swf, so the eight movie getters answer and contentType
	// resolves once `init` fires.
	lx->bytes_loaded = pl->len;
	ev = avm2_progress_event_new(ctx, avm2_string_from_literal(ctx, "progress"),
	                             (double) pl->len, (double) pl->len);
	if (ev != NULL) avm2_dispatch_event(ctx, li, ev);
	lx->loaded = 1;
	lx->url = pl->url;
	// The movie's ApplicationDomain has to be settled BEFORE its root boots:
	// loader_boot_child_swf registers the ABC into it, and every file the
	// registration loads is stamped with it.
	if (pl->scope != NULL)
	{
		lx->scope = pl->scope;
	}
	else
	{
		// No LoaderContext domain: Ruffle gives the movie a FRESH child domain
		// of the LOADING movie's (Domain::movie_domain). That is what lets a
		// child define its own class of a name the parent also has -
		// loader_duplicate_class's first two loads.
		lx->scope = avm2_domain_scope_new(ctx, movie_scope_of(ctx, lx->loader));
	}
	lx->app_domain = avm2_domain_scope_object(ctx, lx->scope);
	// The child SWF's root: constructed and attached after the final progress
	// event, before init/complete (which the active list still defers a tick).
	//
	// A fetch delivers from inside the drain, past this tick's active-list
	// flush, so its boot has to happen here to stay ahead of init/complete
	// (loader_events). loadBytes runs in the middle of script execution
	// instead, and Flash does NOT construct the root there: the statement
	// after `loadBytes()` still reads `contentLoaderInfo.content` as null
	// (loader_error_in_root_ctor). Hand it to the next drain, which boots it
	// immediately before firing init/complete — the same position relative to
	// the surrounding events that loader_loadbytes_events pins.
	if (pl->content_type == LI_CT_SWF && pl->tables != NULL)
	{
		if (from_bytes) lx->pending_boot = pl->tables;
		else loader_boot_child_swf(ctx, li, lx, pl->tables);
	}
	// Third `bytes` state: the real source bytes, now that content is loaded.
	// Only bundled assets are kept — their storage is generated-static and
	// outlives everything. A loadBytes source ByteArray can be resized or
	// dropped by the script afterwards, so its buffer is deliberately NOT
	// aliased here (no test needs it yet; tranche 6's `loader_events` wants a
	// child SWF's decompressed bytes, which come from the movie registry).
	if (pl->data_static)
	{
		lx->bytes = pl->data;
		lx->bytes_len = pl->len;
	}
	// Ruffle movie_loader_complete calls fire_init_and_complete_events inline
	// only when the content is NOT a MovieClip — i.e. for an image. A child
	// SWF's init/complete are deferred to the clip's own on_exit_frame
	// (movie_clip.rs), one tick later, and from_shumway as3-loader/LoaderTest
	// pins that: its `enterFrame` sits between the last progress event and
	// `init`. Anything else therefore waits on the active list, which the drain
	// flushes at the START of a tick's loader phase.
	//
	// loadBytes is excluded as well: Ruffle delays a from_bytes image's complete
	// by two post-frame callbacks, so keeping it on the active list holds it at
	// this tick's boundary instead of firing inside the loadBytes call.
	if (is_image && !from_bytes) loaderinfo_fire_init_and_complete(ctx, li);
}

// Deliver every queued fetch. A load() issued during frame N never resolves
// inside frame N — loaderinfo_more traces applicationDomain twice as null
// before its `complete` handler ever runs — so this runs from the drain below,
// past the frame's exitFrame.
static void avm2_loader_run_pending(Avm2Context* ctx)
{
	uint32_t n = g_pending_load_count;
	if (n == 0) return;
	Avm2PendingLoad batch[AVM2_MAX_PENDING_LOADS];
	memcpy(batch, g_pending_loads, n * sizeof(Avm2PendingLoad));
	g_pending_load_count = 0;
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2Object* li = batch[i].loader_info;
		if (li == NULL) continue;
		// The fetch opened successfully; loadBytes has no fetch and so no
		// `open` event (loader_bytes_unknown_content).
		dispatch_simple_event(ctx, li, "open", 0);
		loader_deliver(ctx, li, &batch[i], 0);
	}
}

// Every tracked LoaderInfo whose stream reached Swf fires init and then
// complete. Entries whose load has not resolved yet stay tracked; errored and
// completed ones drop out.
static void avm2_loader_run_exit_frame(Avm2Context* ctx)
{
	uint32_t n = g_active_loader_info_count;
	if (n == 0) return;
	Avm2Object* batch[AVM2_MAX_ACTIVE_LOADS];
	memcpy(batch, g_active_loader_infos, n * sizeof(Avm2Object*));
	g_active_loader_info_count = 0;
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, batch[i]);
		if (lx == NULL || lx->errored) continue;
		// A loadBytes SWF's root is constructed here, immediately before its
		// init/complete (loader_deliver). A throw out of that constructor sets
		// `errored`, which skips both and drops the entry.
		if (lx->pending_boot != NULL)
		{
			const Avm2MovieTables* t = lx->pending_boot;
			lx->pending_boot = NULL;
			loader_boot_child_swf(ctx, batch[i], lx, t);
			if (lx->errored) continue;
		}
		if (lx->loaded) loaderinfo_fire_init_and_complete(ctx, batch[i]);
		else loader_track_active(batch[i]);
	}
}

// End-of-frame hook, run right after the root LoaderInfo's own init/complete.
//
// Two stages, in this order:
//
//  1. Flush the active list — streams that resolved during an EARLIER tick and
//     whose init/complete Ruffle defers by a frame (a child SWF's, via
//     MovieClip::on_exit_frame), plus loadBytes deliveries from this tick.
//  2. Resolve queued fetches. Ruffle's loads are async tasks and its test
//     harness runs the executor to quiescence after every tick, so a fetch
//     issued during the frame delivers its events once the frame is over — and
//     a load STARTED by one of those handlers resolves in the same drain,
//     because the executor picks up newly-spawned tasks. That is what
//     loader_bitmap_transparency needs: three sequential loads, each begun from
//     the previous one's `complete` handler, all finishing inside its two ticks.
#define AVM2_MAX_LOAD_CHAIN 16
static void avm2_url_loader_run_pending(Avm2Context* ctx);
static uint32_t g_pending_url_load_count;

static void avm2_loader_drain(Avm2Context* ctx)
{
	avm2_loader_run_exit_frame(ctx);
	for (uint32_t round = 0; round < AVM2_MAX_LOAD_CHAIN; round++)
	{
		// The queued fetch log belongs to THIS round's requests: Ruffle logs
		// inside fetch(), i.e. on the first poll of the future, before any of
		// that load's events. A URL that resolves to nothing queues a log but
		// no load, so it has to keep the loop alive on its own.
		if (g_pending_load_count == 0 && g_pending_url_load_count == 0
		    && !swf_log_fetch_pending() && !swf_dialog_pending()) break;
		swf_log_fetch_flush();
		avm2_loader_run_pending(ctx);
		avm2_url_loader_run_pending(ctx);
		// File dialogs are futures on the same executor: one opened during the
		// frame resolves here, and one opened from a resolution callback
		// resolves in the same drain (filereference_save_and_browse chains
		// save -> browse -> load under num_ticks = 1).
		swf_dialog_pump();
	}
}

// Resolve a URL to bundled bytes. Sibling data files (`data.txt`, `test.png`)
// are linked verbatim; sibling SWFs are recompiled into the binary and carry
// only their size in the movie registry. Returns 0 when nothing matches, in
// which case the load stays silent rather than inventing an #2032 ioError for
// URLs a game legitimately fetches from the network.
static int loader_resolve_url(const Avm2String* url, Avm2PendingLoad* out)
{
	char name[256];
	loader_basename(url, name, sizeof(name));
	if (name[0] == '\0') return 0;
	DataFileEntry* d = findDataFile(name);
	if (d != NULL && d->content != NULL)
	{
		out->data = (const uint8_t*) d->content;
		out->len = (uint32_t) d->content_length;
		out->content_type = loader_sniff(out->data, out->len);
		out->data_static = 1;
		return 1;
	}
	// A nested child is registered under its relative path; everything else
	// under its bare filename, which is what the relative path collapses to.
	char rel[256];
	loader_relpath(url, rel, sizeof(rel));
	MovieEntry* m = rel[0] != '\0' ? findMovieEntry(rel) : NULL;
	if (m == NULL) m = findMovieEntry(name);
	if (m != NULL)
	{
		out->data = NULL;
		out->len = m->file_size;
		out->content_type = LI_CT_SWF;
		// AVM2 child (loader-arc tranche 6): its emitted tables and its
		// decompressed bytes. Both stay NULL for an AVM1 child or an image
		// shell, which is exactly the pre-tranche-6 behaviour.
		out->tables = (const Avm2MovieTables*) m->avm2_tables;
		out->swf_bytes = m->swf_bytes;
		out->swf_bytes_len = m->swf_bytes_len;
		out->raw_bytes = m->raw_bytes;
		out->raw_bytes_len = m->raw_bytes_len;
		return 1;
	}
	return 0;
}

// flash.display.Loader.load(request, context). One URL is special-cased before
// the pipeline: the ArmorGames AGI helper SWF (cache.armorgames.com/assets/agi/
// AGI.swf). EQ (and every AG-portal game) registers a COMPLETE handler on
// contentLoaderInfo and then runs the UNGUARDED `agi.hideLoginStatus()` where
// `agi = loaderInfo.content`; with no content that throws #1010. AGI.swf is not
// bundled, so the pipeline below would leave the load silent — instead we seed a
// no-op AGI shell as `content` and fire a synthetic COMPLETE, letting the game's
// own loadComplete assign and addChild it. Reusable: unblocks New Game on any
// AG/AGI game.
static Avm2Value loader_load(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2LoaderExt* ext = loader_ext_of(ctx, self);
	if (ext == NULL) return avm2_undefined();
	Avm2Object* cli = loader_ensure_cli(ctx, ext, self);
	if (cli == NULL) return avm2_undefined();

	const Avm2String* url = request_url(ctx, act->argc > 0 ? act->args[0]
	                                                      : avm2_null());

	if (url != NULL && avm2_str_contains(url, "AGI.swf")
	    && g_agi_shell_class != NULL)
	{
		Avm2Value sv = avm2_class_construct(ctx, g_agi_shell_class, NULL, 0);
		if (sv.kind != AVM2_VALUE_OBJECT) return avm2_undefined();
		ext->content = sv.u.obj;
		Avm2LoaderInfoExt* clx = loaderinfo_ext_of(ctx, cli);
		if (clx != NULL)
		{
			// Present the shell as a finished SWF load, so a game reading
			// contentType/frameRate/applicationDomain off it sees a loaded
			// stream rather than #2099.
			clx->content = sv.u.obj;   // contentLoaderInfo.content = shell
			clx->expose_content = 1;
			clx->loaded = 1;
			clx->load_started = 1;
			clx->init_fired = 1;
			clx->complete_fired = 1;
			clx->content_type = LI_CT_SWF;
			clx->url = url;
			Avm2Value cur = avm2_current_domain_value(ctx);
			clx->app_domain = cur.kind == AVM2_VALUE_OBJECT ? cur.u.obj : NULL;
		}
		dispatch_simple_event(ctx, cli, "complete", 0);  // Event.COMPLETE
		return avm2_undefined();
	}

	// Starting a load unloads whatever was there (Ruffle Loader.load).
	loader_drop_content(ctx, self, ext);
	Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, cli);

	// The request is logged whether or not the URL resolves to a bundled
	// asset — Ruffle spawns the fetch either way, and log_fetch tests point at
	// hosts that were never going to answer.
	avm2_log_fetch_request(ctx, act->argc > 0 ? act->args[0] : avm2_null());

	Avm2PendingLoad pl;
	memset(&pl, 0, sizeof(pl));
	if (url == NULL || !loader_resolve_url(url, &pl)) return avm2_undefined();
	const Avm2String* issuer_url = movie_url_of(ctx, self);
	if (lx != NULL)
	{
		lx->load_started = 1;
		lx->loader_url = issuer_url;
	}
	pl.loader_info = cli;
	pl.url = loader_absolute_url(ctx, url, issuer_url);
	pl.app_domain = act->argc > 1 ? loader_context_domain(ctx, act->args[1]) : NULL;
	pl.scope = act->argc > 1 ? loader_context_scope(ctx, act->args[1]) : NULL;
	if (g_pending_load_count < AVM2_MAX_PENDING_LOADS)
		g_pending_loads[g_pending_load_count++] = pl;
	loader_track_active(cli);
	return avm2_undefined();
}

// flash.display.Loader.loadBytes(bytes, context). No fetch, so no `open` event
// and no deferral: Flash (and Ruffle) run the whole sequence synchronously —
// loader_bytes_unknown_content prints every event before the line that follows
// the loadBytes call.
static Avm2Value loader_load_bytes(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2LoaderExt* ext = loader_ext_of(ctx, self);
	if (ext == NULL) return avm2_undefined();
	Avm2Object* cli = loader_ensure_cli(ctx, ext, self);
	if (cli == NULL) return avm2_undefined();

	loader_drop_content(ctx, self, ext);
	Avm2LoaderInfoExt* lx = loaderinfo_ext_of(ctx, cli);

	Avm2ByteArrayExt* ba = act->argc > 0 ? avm2_bytearray_ext_of(act->args[0])
	                                     : NULL;
	if (ba == NULL) return avm2_undefined();
	if (lx != NULL)
	{
		lx->load_started = 1;
		lx->loader_url = movie_url_of(ctx, self);
	}

	Avm2PendingLoad pl;
	memset(&pl, 0, sizeof(pl));
	pl.loader_info = cli;
	pl.data = ba->bytes;
	pl.len = ba->len;
	pl.url = loader_dynamic_url(ctx, lx != NULL ? lx->loader_url : NULL);
	pl.content_type = loader_sniff(ba->bytes, ba->len);
	// A loadBytes SWF payload carries no filename, so it is matched to a
	// recompiled sibling movie by its file size — the payload IS one of the
	// test's own .swf files, embedded (loader_loadbytes_events embeds
	// loadable.swf via [Embed]). Ahead-of-time compilation means an
	// unrecognized payload can never run: it stays content-less, exactly as
	// before tranche 6.
	if (pl.content_type == LI_CT_SWF)
	{
		for (int i = 0; ; i++)
		{
			MovieEntry* m = getMovieEntryAt(i);
			if (m == NULL) break;
			if (m->avm2_tables == NULL || m->file_size != ba->len) continue;
			pl.tables = (const Avm2MovieTables*) m->avm2_tables;
			pl.swf_bytes = m->swf_bytes;
			pl.swf_bytes_len = m->swf_bytes_len;
			break;
		}
	}
	pl.app_domain = act->argc > 1 ? loader_context_domain(ctx, act->args[1]) : NULL;
	pl.scope = act->argc > 1 ? loader_context_scope(ctx, act->args[1]) : NULL;
	loader_deliver(ctx, cli, &pl, 1);
	loader_track_active(cli);   // init/complete still land at the frame's end
	return avm2_undefined();
}

// flash.display.Loader.unload() / unloadAndStop(): drop the content and put the
// LoaderInfo back in the fresh NotYetLoaded state.
static Avm2Value loader_unload(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	loader_drop_content(ctx, self, loader_ext_of(ctx, self));
	return avm2_undefined();
}

// --- flash.net.URLLoader ----------------------------------------------------
//
// Ruffle load_data_into_url_loader (core/src/loader.rs). It lives beside the
// Loader pipeline rather than with the rest of flash.net in avm2_globals.c
// because it shares this file's URL resolution, event dispatch and load drain;
// the class itself is still created over there and wired through
// avm2_display_wire_url_loader.
//
// On success the order is `open`, then bytesLoaded/bytesTotal/data, then
// progress(len, len), httpStatus, complete — Ruffle fires `open` after the
// fetch resolves precisely so that a file missing on disk fires no `open` at
// all. On failure `data` is CLEARED to the empty value for the current
// dataFormat (Flash does this, per the comment in Ruffle's error arm) and
// httpStatus precedes an ioError carrying "Error #2032: Stream Error".

typedef struct Avm2UrlLoaderExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Value data;                     // undefined until the first delivery
	const Avm2String* data_format;      // NULL == "text"
	uint32_t bytes_loaded;
	uint32_t bytes_total;
} Avm2UrlLoaderExt;

static Avm2Class* g_url_loader_class;

static Avm2UrlLoaderExt* url_loader_ext_of(Avm2Object* o)
{
	if (o == NULL || o->cls == NULL || g_url_loader_class == NULL
	    || !class_is_a(o->cls, g_url_loader_class))
		return NULL;
	return (Avm2UrlLoaderExt*) o->native_ext;
}

static int ul_format_is(const Avm2UrlLoaderExt* ext, const char* name)
{
	if (ext->data_format == NULL) return strcmp(name, "text") == 0;
	size_t n = strlen(name);
	return (size_t) ext->data_format->len == n
	       && memcmp(ext->data_format->utf8, name, n) == 0;
}

// A queued URLLoader fetch. `found` distinguishes "bundled asset, here are the
// bytes" from "no such file", which is the whole difference between the success
// and #2032 paths.
typedef struct Avm2PendingUrlLoad
{
	Avm2Object* loader;
	const uint8_t* data;
	uint32_t len;
	uint8_t found;
	uint8_t is_stream;   // the target is a URLStream, not a URLLoader
} Avm2PendingUrlLoad;

#define AVM2_MAX_PENDING_URL_LOADS 32
static Avm2PendingUrlLoad g_pending_url_loads[AVM2_MAX_PENDING_URL_LOADS];

// Ruffle's set_data. `body`/`len` may be empty, which is exactly what the error
// arm passes in to clear `data`.
static void ul_set_data(Avm2Context* ctx, Avm2UrlLoaderExt* ext,
                        const uint8_t* body, uint32_t len)
{
	ext->bytes_loaded = len;
	ext->bytes_total = len;
	if (ul_format_is(ext, "binary"))
	{
		Avm2Value v = avm2_class_construct(ctx, ctx->builtins.bytearray_class,
		                                   NULL, 0);
		Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(v);
		if (ba != NULL && len != 0)
		{
			avm2_bytearray_set_length_public(ctx, ba, len);
			if (ba->bytes != NULL && ba->len == len) memcpy(ba->bytes, body, len);
			ba->position = 0;   // the script reads from the start
		}
		ext->data = v;
		return;
	}
	// "text" and "variables". Ruffle honours a leading BOM before handing the
	// string on; avm2_strip_bom is the same helper ByteArray.toString uses,
	// so UTF-16LE/BE responses decode too.
	ext->data = avm2_string(avm2_strip_bom(ctx, body, len));
	// dataFormat="variables" hands that string to URLVariables, whose ctor
	// decodes the query string (Ruffle set_data: `urlvariables.construct(
	// &[strip_bom(body)])`). An empty body constructs an empty bag, which is
	// what the #2032 arm needs.
	if (ul_format_is(ext, "variables"))
	{
		Avm2Class* uvc = avm2_url_variables_class();
		if (uvc != NULL)
		{
			Avm2Value arg = ext->data;
			ext->data = avm2_class_construct(ctx, uvc, &arg, 1);
		}
	}
}

static void us_deliver(Avm2Context* ctx, const Avm2PendingUrlLoad* pl);

static void ul_deliver(Avm2Context* ctx, const Avm2PendingUrlLoad* pl)
{
	if (pl->is_stream)
	{
		us_deliver(ctx, pl);
		return;
	}
	Avm2Object* self = pl->loader;
	Avm2UrlLoaderExt* ext = url_loader_ext_of(self);
	if (ext == NULL) return;

	if (!pl->found)
	{
		ul_set_data(ctx, ext, NULL, 0);
		Avm2Object* ev = avm2_http_status_event_new(
			ctx, avm2_string_from_literal(ctx, "httpStatus"), 0, 0);
		if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
		ev = avm2_io_error_event_new(
			ctx, avm2_string_from_literal(ctx, "ioError"),
			avm2_string_from_literal(ctx, "Error #2032: Stream Error"), 2032);
		if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
		return;
	}

	dispatch_simple_event(ctx, self, "open", 0);
	ul_set_data(ctx, ext, pl->data, pl->len);
	Avm2Object* ev = avm2_progress_event_new(
		ctx, avm2_string_from_literal(ctx, "progress"), (double) pl->len,
		(double) pl->len);
	if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
	ev = avm2_http_status_event_new(ctx,
	                               avm2_string_from_literal(ctx, "httpStatus"),
	                               0, 0);
	if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
	dispatch_simple_event(ctx, self, "complete", 0);
}

static void avm2_url_loader_run_pending(Avm2Context* ctx)
{
	uint32_t n = g_pending_url_load_count;
	if (n == 0) return;
	Avm2PendingUrlLoad batch[AVM2_MAX_PENDING_URL_LOADS];
	memcpy(batch, g_pending_url_loads, n * sizeof(Avm2PendingUrlLoad));
	g_pending_url_load_count = 0;
	for (uint32_t i = 0; i < n; i++) ul_deliver(ctx, &batch[i]);
}

// Queue a fetch. Like Loader.load it never resolves inside the calling frame.
// `is_stream` picks the delivery half: URLStream borrows this whole pipeline
// (Ruffle's URLStream.as is literally a URLLoader wrapper) and differs only in
// where the bytes land and which events it re-dispatches.
static void ul_start_load(Avm2Context* ctx, Avm2Object* self, Avm2Value request,
                          int is_stream)
{
	avm2_log_fetch_request(ctx, request);
	const Avm2String* url = request_url(ctx, request);
	if (url == NULL) return;
	Avm2PendingUrlLoad pl;
	memset(&pl, 0, sizeof(pl));
	pl.loader = self;
	pl.is_stream = (uint8_t) (is_stream != 0);
	Avm2PendingLoad probe;
	memset(&probe, 0, sizeof(probe));
	// Unlike Loader.load, a URL that resolves to nothing is an ERROR here
	// (#2032) rather than a silent no-op: url_loader asks for missingFile.bin
	// on purpose.
	if (loader_resolve_url(url, &probe))
	{
		// A bundled data file answers with `data`; a recompiled child SWF has
		// no `data` (the Loader pipeline runs it from its emitted tables) but
		// does carry the on-disk file, which is what a fetch returns — Flash
		// hands a URLLoader the compressed .swf verbatim, so a loadBytes() of
		// the result matches the movie by its FILE size exactly as an [Embed]
		// of the same file would (loader_error_in_root_ctor).
		if (probe.data == NULL && probe.raw_bytes != NULL)
		{
			probe.data = probe.raw_bytes;
			probe.len = probe.raw_bytes_len;
		}
		if (probe.data != NULL)
		{
			pl.data = probe.data;
			pl.len = probe.len;
			pl.found = 1;
		}
	}
	if (g_pending_url_load_count < AVM2_MAX_PENDING_URL_LOADS)
		g_pending_url_loads[g_pending_url_load_count++] = pl;
}

static Avm2Value url_loader_init(Avm2Activation* act)
{
	// `new URLLoader(request)` starts the load immediately (URLLoader.as).
	if (act->argc > 0 && act->args[0].kind == AVM2_VALUE_OBJECT
	    && url_loader_ext_of(this_obj(act)) != NULL)
		ul_start_load(act->ctx, this_obj(act), act->args[0], 0);
	return avm2_undefined();
}

static Avm2Value url_loader_load(Avm2Activation* act)
{
	if (url_loader_ext_of(this_obj(act)) == NULL) return avm2_undefined();
	ul_start_load(act->ctx, this_obj(act),
	              act->argc > 0 ? act->args[0] : avm2_null(), 0);
	return avm2_undefined();
}

static Avm2Value ul_get_data(Avm2Activation* act)
{
	Avm2UrlLoaderExt* ext = url_loader_ext_of(this_obj(act));
	return ext != NULL ? ext->data : avm2_undefined();
}

static Avm2Value ul_set_data_prop(Avm2Activation* act)
{
	Avm2UrlLoaderExt* ext = url_loader_ext_of(this_obj(act));
	if (ext != NULL && act->argc > 0) ext->data = act->args[0];
	return avm2_undefined();
}

static Avm2Value ul_get_data_format(Avm2Activation* act)
{
	Avm2UrlLoaderExt* ext = url_loader_ext_of(this_obj(act));
	if (ext != NULL && ext->data_format != NULL)
		return avm2_string(ext->data_format);
	return avm2_string(avm2_string_from_literal(act->ctx, "text"));
}

static Avm2Value ul_set_data_format(Avm2Activation* act)
{
	Avm2UrlLoaderExt* ext = url_loader_ext_of(this_obj(act));
	if (ext != NULL && act->argc > 0)
		ext->data_format = avm2_coerce_to_string(act->ctx, act->args[0]);
	return avm2_undefined();
}

static Avm2Value ul_get_bytes_loaded(Avm2Activation* act)
{
	Avm2UrlLoaderExt* ext = url_loader_ext_of(this_obj(act));
	return avm2_number(ext != NULL ? (double) ext->bytes_loaded : 0);
}

static Avm2Value ul_get_bytes_total(Avm2Activation* act)
{
	Avm2UrlLoaderExt* ext = url_loader_ext_of(this_obj(act));
	return avm2_number(ext != NULL ? (double) ext->bytes_total : 0);
}

static Avm2Value ul_close(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

void avm2_display_wire_url_loader(Avm2Context* ctx, Avm2Class* ul)
{
	if (ul == NULL) return;
	g_url_loader_class = ul;
	ul->native_ext_size = sizeof(Avm2UrlLoaderExt);
	ul->instance_init.fn = url_loader_init;
	ul->instance_init.debug_name = "URLLoader";
	avm2_builtin_add_method(ctx, ul, "load", url_loader_load);
	avm2_builtin_add_method(ctx, ul, "close", ul_close);
	avm2_builtin_add_getset(ctx, ul, "data", ul_get_data, ul_set_data_prop);
	avm2_builtin_add_getset(ctx, ul, "dataFormat", ul_get_data_format,
	                        ul_set_data_format);
	avm2_builtin_add_getter(ctx, ul, "bytesLoaded", ul_get_bytes_loaded);
	avm2_builtin_add_getter(ctx, ul, "bytesTotal", ul_get_bytes_total);
}

// --- flash.net.URLStream ----------------------------------------------------
//
// URLStream.as is a thin AS3 wrapper around a *private* URLLoader in binary
// mode: it re-dispatches open/progress/httpStatus/complete/ioError and forwards
// every IDataInput method to `_loader.data`. Here it is the same wrapper
// written in C — one ByteArray ext as the sink, filled by the URLLoader fetch
// pipeline above, and the 14 IDataInput bodies borrowed verbatim through
// avm2_bytearray.c's alt resolver (the mechanism tranche 2 built for Socket).
// Nothing actually streams in either player: the bytes land all at once when
// the fetch resolves, which is what `urlstream_basic` grades (bytesAvailable
// is 0 in the `open` handler and the full length from `progress` on).

typedef struct Avm2UrlStreamExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2ByteArrayExt buf;               // == the private URLLoader's binary data
	uint8_t connected;                  // load() sets it, close() clears it
} Avm2UrlStreamExt;

static Avm2Class* g_url_stream_class;

static Avm2UrlStreamExt* url_stream_ext_of(Avm2Object* o)
{
	if (o == NULL || o->cls == NULL || g_url_stream_class == NULL
	    || !class_is_a(o->cls, g_url_stream_class))
		return NULL;
	return (Avm2UrlStreamExt*) o->native_ext;
}

// avm2_bytearray.c's alt resolver. Only IDataInput is registered on the class,
// so the direction is always read; an unloaded stream still resolves, and the
// empty buffer makes every read raise the ByteArray EOFError, exactly as
// Ruffle's forwarding to a zero-length `_loader.data` does.
static Avm2ByteArrayExt* url_stream_ba_resolve(Avm2Activation* act, int write_dir)
{
	(void) write_dir;
	Avm2UrlStreamExt* ext = url_stream_ext_of(this_obj(act));
	return ext != NULL ? &ext->buf : NULL;
}

static void us_deliver(Avm2Context* ctx, const Avm2PendingUrlLoad* pl)
{
	Avm2Object* self = pl->loader;
	Avm2UrlStreamExt* ext = url_stream_ext_of(self);
	if (ext == NULL) return;

	if (!pl->found)
	{
		Avm2Object* ev = avm2_http_status_event_new(
			ctx, avm2_string_from_literal(ctx, "httpStatus"), 0, 0);
		if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
		// The wrapper builds a bare `new IOErrorEvent(IO_ERROR)`, so unlike
		// URLLoader's the relayed event carries no text.
		ev = avm2_io_error_event_new(ctx,
		                             avm2_string_from_literal(ctx, "ioError"),
		                             avm2_string_from_literal(ctx, ""), 0);
		if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
		return;
	}

	dispatch_simple_event(ctx, self, "open", 0);
	// Append behind the read cursor, the Socket convention: `position` is the
	// only thing bytesAvailable subtracts.
	uint32_t at = ext->buf.len;
	avm2_bytearray_set_length_public(ctx, &ext->buf, at + pl->len);
	if (pl->len != 0 && ext->buf.bytes != NULL && ext->buf.len == at + pl->len)
		memcpy(ext->buf.bytes + at, pl->data, pl->len);
	Avm2Object* ev = avm2_progress_event_new(
		ctx, avm2_string_from_literal(ctx, "progress"), (double) pl->len,
		(double) pl->len);
	if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
	ev = avm2_http_status_event_new(ctx,
	                                avm2_string_from_literal(ctx, "httpStatus"),
	                                0, 0);
	if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
	dispatch_simple_event(ctx, self, "complete", 0);
}

static Avm2Value url_stream_load(Avm2Activation* act)
{
	Avm2UrlStreamExt* ext = url_stream_ext_of(this_obj(act));
	if (ext == NULL) return avm2_undefined();
	ul_start_load(act->ctx, this_obj(act),
	              act->argc > 0 ? act->args[0] : avm2_null(), 1);
	ext->connected = 1;
	return avm2_undefined();
}

static Avm2Value url_stream_close(Avm2Activation* act)
{
	Avm2UrlStreamExt* ext = url_stream_ext_of(this_obj(act));
	if (ext != NULL) ext->connected = 0;
	return avm2_undefined();
}

static Avm2Value us_get_connected(Avm2Activation* act)
{
	Avm2UrlStreamExt* ext = url_stream_ext_of(this_obj(act));
	return avm2_bool(ext != NULL && ext->connected != 0);
}

static Avm2Value us_get_bytes_available(Avm2Activation* act)
{
	Avm2UrlStreamExt* ext = url_stream_ext_of(this_obj(act));
	if (ext == NULL || ext->buf.position >= ext->buf.len) return avm2_uint_value(0);
	return avm2_uint_value(ext->buf.len - ext->buf.position);
}

static Avm2Value us_get_endian(Avm2Activation* act)
{
	Avm2UrlStreamExt* ext = url_stream_ext_of(this_obj(act));
	return avm2_string(avm2_string_from_literal(
		act->ctx, (ext != NULL && ext->buf.endian_little) ? "littleEndian"
		                                                  : "bigEndian"));
}

static Avm2Value us_set_endian(Avm2Activation* act)
{
	Avm2UrlStreamExt* ext = url_stream_ext_of(this_obj(act));
	const Avm2String* s = act->argc > 0
		? avm2_coerce_to_string(act->ctx, act->args[0]) : NULL;
	int little = s != NULL && s->len == 12 && memcmp(s->utf8, "littleEndian", 12) == 0;
	int big = s != NULL && s->len == 9 && memcmp(s->utf8, "bigEndian", 9) == 0;
	if (!little && !big)
	{
		avm2_throw_error(act->ctx, act->ctx->builtins.argument_error_class,
		                 "Error #2008: Parameter endian must be one of the "
		                 "accepted values.");
	}
	if (ext != NULL) ext->buf.endian_little = (uint8_t) little;
	return avm2_undefined();
}

// Ruffle stubs both halves (`stub_getter`/`stub_setter`) and always reports 0.
static Avm2Value us_get_object_encoding(Avm2Activation* act)
{
	(void) act;
	return avm2_uint_value(0);
}

static Avm2Value us_set_object_encoding(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

void avm2_display_wire_url_stream(Avm2Context* ctx, Avm2Class* us)
{
	if (us == NULL) return;
	g_url_stream_class = us;
	us->native_ext_size = sizeof(Avm2UrlStreamExt);
	avm2_bytearray_set_alt_resolver(url_stream_ba_resolve);
	avm2_builtin_add_method(ctx, us, "load", url_stream_load);
	avm2_builtin_add_method(ctx, us, "close", url_stream_close);
	avm2_builtin_add_getter(ctx, us, "connected", us_get_connected);
	avm2_builtin_add_getter(ctx, us, "bytesAvailable", us_get_bytes_available);
	avm2_builtin_add_getset(ctx, us, "endian", us_get_endian, us_set_endian);
	avm2_builtin_add_getset(ctx, us, "objectEncoding", us_get_object_encoding,
	                        us_set_object_encoding);
	// IDataInput only — URLStream has no write half.
	avm2_bytearray_install_data_input(ctx, us);
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
	// focusRect is typed `Object`, so *both* null and undefined clear it and
	// the getter then reads back null (avm2/focusrect_property).
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
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
				avm2_display_mark_frame_work(ctx, this_obj(act));
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

// T4 Part B — runtime Graphics geometry recording. One recorded pen command
// (pixels; cx/cy = quadratic control for CURVE). type: 0 move, 1 line, 2 curve.
typedef struct { uint8_t type; float x, y, cx, cy; } Avm2GfxCmd;

// A finalized subpath: fill kind + params + tessellated fill triangles, and the
// stroke's triangle list, all in shape-LOCAL twips (the same convention T5's
// static shape_data uses). Fill kind: 0 none, 1 solid, 2 gradient.
typedef struct
{
	int      fill_kind;
	float    fr, fg, fb, fa;        // solid straight 0..1
	// gradient (fill_kind==2)
	uint8_t  grad_type;             // 0x10 linear, 0x12 radial, 0x13 focal
	uint8_t  grad_spread;           // 0 pad, 1 reflect, 2 repeat
	uint8_t  grad_interp;           // 0 rgb, 1 linearRGB
	float    grad_focal;
	uint8_t  grad_ramp[256 * 4];    // RGBA8 (sRGB for rgb interp, linear for linearRGB)
	float    grad_fwd16[16];        // GPU: col-major, gradient[-16384,16384] -> local twips
	float    grad_inv2d[6];         // CPU: local twips -> UV[0,1] (normalized inverse)
	float*   fill_verts;            // local twips, xy pairs, count%3==0
	uint32_t fill_vert_count;
	// stroke
	int      has_line;
	float    lr, lg, lb, la;        // straight 0..1
	float*   line_verts;            // local twips
	uint32_t line_vert_count;
} Avm2GfxPath;

typedef struct Avm2GraphicsExt
{
	Avm2Object* owner;
	// Current recording state.
	int      cur_fill;              // 0 none, 1 solid, 2 gradient
	float    cfr, cfg, cfb, cfa;
	uint8_t  cgt, cgs, cgi;         // gradient type/spread/interp
	float    cgf;                   // focal
	uint8_t  cramp[256 * 4];
	float    cfwd16[16];
	float    cinv2d[6];
	int      cur_line;
	float    clr, clg, clb, cla;
	float    clw;                   // line width (pixels)
	// Active pen-command buffer (flushed on begin*/endFill/clear/draw*).
	Avm2GfxCmd* cmds;
	uint32_t cmd_count, cmd_cap;
	float    pen_x, pen_y;          // last pen position (pixels)
	int      pen_set;
	// Finalized paths.
	Avm2GfxPath* paths;
	uint32_t path_count, path_cap;
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

// ---- T4 Part B: geometry recording, tessellation, strokes, gradient ramps ----

static double matrix_get_prop(Avm2Context* ctx, Avm2Object* m, const char* name);
static int gfx_str_is(const Avm2String* s, const char* lit);  // defined in Part A

// The Graphics object's own ext (recorded geometry lives here, per-instance).
static Avm2GraphicsExt* gfx_self_ext(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL) return NULL;
	return (Avm2GraphicsExt*) self->native_ext;
}

static void gfx_add_cmd(Avm2GraphicsExt* g, uint8_t type, float x, float y,
                        float cx, float cy)
{
	if (g->cmd_count >= g->cmd_cap)
	{
		g->cmd_cap = g->cmd_cap ? g->cmd_cap * 2 : 64;
		g->cmds = realloc(g->cmds, g->cmd_cap * sizeof(Avm2GfxCmd));
	}
	Avm2GfxCmd* c = &g->cmds[g->cmd_count++];
	c->type = type; c->x = x; c->y = y; c->cx = cx; c->cy = cy;
	g->pen_x = x; g->pen_y = y; g->pen_set = 1;
}

static void gfx_free_path(Avm2GfxPath* p)
{
	free(p->fill_verts); p->fill_verts = NULL; p->fill_vert_count = 0;
	free(p->line_verts); p->line_verts = NULL; p->line_vert_count = 0;
}

static void gfx_reset(Avm2GraphicsExt* g)
{
	for (uint32_t i = 0; i < g->path_count; i++) gfx_free_path(&g->paths[i]);
	free(g->paths); g->paths = NULL; g->path_count = g->path_cap = 0;
	free(g->cmds); g->cmds = NULL; g->cmd_count = g->cmd_cap = 0;
	g->cur_fill = g->cur_line = 0; g->pen_set = 0;
}

// Miter/bevel join (miter-limit 4), mirrors action.c drawing_emit_stroke_join.
// Inputs in pixels; outputs in twips. Returns verts written (0/3/6).
static uint32_t gfx_stroke_join(float* out, float ax, float ay, float vx,
                                float vy, float bx, float by, float half_w)
{
	ax *= 20.0f; ay *= 20.0f; vx *= 20.0f; vy *= 20.0f; bx *= 20.0f; by *= 20.0f;
	float d0x = vx - ax, d0y = vy - ay, d1x = bx - vx, d1y = by - vy;
	float l0 = sqrtf(d0x * d0x + d0y * d0y), l1 = sqrtf(d1x * d1x + d1y * d1y);
	if (l0 < 0.001f || l1 < 0.001f) return 0;
	d0x /= l0; d0y /= l0; d1x /= l1; d1y /= l1;
	float cross = d0x * d1y - d0y * d1x;
	if (fabsf(cross) < 1e-6f) return 0;
	float sign = (cross > 0.0f) ? -1.0f : 1.0f;
	float o0x = sign * -d0y, o0y = sign * d0x, o1x = sign * -d1y, o1y = sign * d1x;
	float p0x = vx + o0x * half_w, p0y = vy + o0y * half_w;
	float p1x = vx + o1x * half_w, p1y = vy + o1y * half_w;
	float mx = o0x + o1x, my = o0y + o1y, mlen = sqrtf(mx * mx + my * my);
	if (mlen > 1e-4f)
	{
		float mhx = mx / mlen, mhy = my / mlen, cos_half = mhx * o0x + mhy * o0y;
		if (cos_half > 0.25f)
		{
			float ml = half_w / cos_half, Mx = vx + mhx * ml, My = vy + mhy * ml;
			out[0]=vx; out[1]=vy; out[2]=p0x; out[3]=p0y; out[4]=Mx; out[5]=My;
			out[6]=vx; out[7]=vy; out[8]=Mx; out[9]=My; out[10]=p1x; out[11]=p1y;
			return 6;
		}
	}
	out[0]=vx; out[1]=vy; out[2]=p0x; out[3]=p0y; out[4]=p1x; out[5]=p1y;
	return 3;
}

// Build stroke triangles from a contour polyline (pixels) at half_w (twips).
// Mirrors action.c drawingBuildStroke (butt caps, miter/bevel joins). `filled`
// auto-closes open contours (Flash closes fill+stroke of `moveTo;lineTo*;endFill`).
static void gfx_build_stroke(Avm2GfxPath* path, const float* poly,
                             uint32_t poly_count, const uint32_t* cstarts,
                             uint32_t ccount, int filled, float half_w)
{
	free(path->line_verts); path->line_verts = NULL; path->line_vert_count = 0;
	if (poly == NULL || ccount == 0) return;
	#define _GNEEDCLOSE(cs, ce) (filled && ((ce)-(cs)) >= 3 && ( \
		fabsf(poly[((ce)-1)*2]   - poly[(cs)*2])   > 0.01f || \
		fabsf(poly[((ce)-1)*2+1] - poly[(cs)*2+1]) > 0.01f))
	#define _GEXPLCLOSED(cs, ce) (((ce)-(cs)) >= 3 && \
		fabsf(poly[((ce)-1)*2]   - poly[(cs)*2])   <= 0.01f && \
		fabsf(poly[((ce)-1)*2+1] - poly[(cs)*2+1]) <= 0.01f)
	uint32_t total_segs = 0;
	for (uint32_t ci = 0; ci < ccount; ci++)
	{
		uint32_t cs = cstarts[ci];
		uint32_t ce = (ci + 1 < ccount) ? cstarts[ci + 1] : poly_count;
		if (ce > cs + 1) total_segs += (ce - cs - 1);
		if (_GNEEDCLOSE(cs, ce)) total_segs += 1;
	}
	if (total_segs == 0) return;
	uint32_t alloc_verts = total_segs * 6 + poly_count * 6;
	path->line_verts = malloc(alloc_verts * 2 * sizeof(float));
	uint32_t wv = 0;
	#define _GSEG(_x0,_y0,_x1,_y1) do { \
		float x0=(_x0)*20.0f, y0=(_y0)*20.0f, x1=(_x1)*20.0f, y1=(_y1)*20.0f; \
		float dx=x1-x0, dy=y1-y0, len=sqrtf(dx*dx+dy*dy); if(len<0.001f)len=0.001f; \
		float nx=-dy/len*half_w, ny=dx/len*half_w; float* o=&path->line_verts[wv*2]; \
		o[0]=x0+nx;o[1]=y0+ny;o[2]=x0-nx;o[3]=y0-ny;o[4]=x1+nx;o[5]=y1+ny; \
		o[6]=x0-nx;o[7]=y0-ny;o[8]=x1-nx;o[9]=y1-ny;o[10]=x1+nx;o[11]=y1+ny; wv+=6; \
	} while (0)
	#define _GJOIN(_kp,_kv,_kn) do { \
		wv += gfx_stroke_join(&path->line_verts[wv*2], \
			poly[(_kp)*2], poly[(_kp)*2+1], poly[(_kv)*2], poly[(_kv)*2+1], \
			poly[(_kn)*2], poly[(_kn)*2+1], half_w); \
	} while (0)
	for (uint32_t ci = 0; ci < ccount; ci++)
	{
		uint32_t cs = cstarts[ci];
		uint32_t ce = (ci + 1 < ccount) ? cstarts[ci + 1] : poly_count;
		int needs_close = _GNEEDCLOSE(cs, ce), expl = _GEXPLCLOSED(cs, ce);
		for (uint32_t i = cs; i + 1 < ce; i++)
			_GSEG(poly[i*2], poly[i*2+1], poly[(i+1)*2], poly[(i+1)*2+1]);
		if (needs_close)
			_GSEG(poly[(ce-1)*2], poly[(ce-1)*2+1], poly[cs*2], poly[cs*2+1]);
		for (uint32_t k = cs + 1; k + 1 < ce; k++) _GJOIN(k-1, k, k+1);
		if (needs_close && (ce - cs) >= 2)
		{
			_GJOIN(ce-1, cs, cs+1);
			_GJOIN(ce-2, ce-1, cs);
		}
		else if (expl) _GJOIN(ce-2, cs, cs+1);
	}
	#undef _GJOIN
	#undef _GSEG
	#undef _GEXPLCLOSED
	#undef _GNEEDCLOSE
	path->line_vert_count = wv;
}

// Flatten the active command buffer into contours (pixels), tessellate the fill
// (libtess2, nonzero winding) and build the stroke, into a new Avm2GfxPath that
// snapshots the current fill/line style. Mirrors action.c drawingFinalizePath.
static void gfx_finalize_path(Avm2GraphicsExt* g)
{
	if (g->cmd_count == 0) return;
	int want_fill = (g->cur_fill != 0);
	int want_line = (g->cur_line != 0);
	if (!want_fill && !want_line) { g->cmd_count = 0; return; }

	float* poly = NULL; uint32_t poly_count = 0, poly_cap = 0;
	uint32_t* cstarts = NULL, ccount = 0, ccap = 0;
	#define _GADDC() do { if (ccount >= ccap) { ccap = ccap ? ccap*2 : 8; \
		cstarts = realloc(cstarts, ccap * sizeof(uint32_t)); } \
		cstarts[ccount++] = poly_count; } while (0)
	#define _GADDP(px,py) do { if (poly_count >= poly_cap) { \
		poly_cap = poly_cap ? poly_cap*2 : 64; \
		poly = realloc(poly, poly_cap * 2 * sizeof(float)); } \
		poly[poly_count*2] = (px); poly[poly_count*2+1] = (py); poly_count++; } while (0)
	for (uint32_t i = 0; i < g->cmd_count; i++)
	{
		Avm2GfxCmd* c = &g->cmds[i];
		if (c->type == 0) { _GADDC(); _GADDP(c->x, c->y); }
		else if (c->type == 2)
		{
			float sx = (i > 0) ? g->cmds[i-1].x : 0.0f;
			float sy = (i > 0) ? g->cmds[i-1].y : 0.0f;
			if (ccount == 0) _GADDC();
			float mx = (sx + c->x) * 0.5f, my = (sy + c->y) * 0.5f;
			float dx = c->cx - mx, dy = c->cy - my, flat = dx*dx + dy*dy;
			int segs = flat < 0.25f ? 1 : flat < 4.0f ? 4 : flat < 25.0f ? 8 : 16;
			for (int s = 1; s <= segs; s++)
			{
				float t = (float) s / (float) segs, u = 1.0f - t;
				_GADDP(u*u*sx + 2*u*t*c->cx + t*t*c->x,
				       u*u*sy + 2*u*t*c->cy + t*t*c->y);
			}
		}
		else { if (ccount == 0) _GADDC(); _GADDP(c->x, c->y); }
	}
	#undef _GADDP
	#undef _GADDC

	if (g->path_count >= g->path_cap)
	{
		g->path_cap = g->path_cap ? g->path_cap * 2 : 8;
		g->paths = realloc(g->paths, g->path_cap * sizeof(Avm2GfxPath));
	}
	Avm2GfxPath* path = &g->paths[g->path_count++];
	memset(path, 0, sizeof(Avm2GfxPath));
	path->fill_kind = g->cur_fill;
	path->fr = g->cfr; path->fg = g->cfg; path->fb = g->cfb; path->fa = g->cfa;
	if (g->cur_fill == 2)
	{
		path->grad_type = g->cgt; path->grad_spread = g->cgs;
		path->grad_interp = g->cgi; path->grad_focal = g->cgf;
		memcpy(path->grad_ramp, g->cramp, sizeof(path->grad_ramp));
		memcpy(path->grad_fwd16, g->cfwd16, sizeof(path->grad_fwd16));
		memcpy(path->grad_inv2d, g->cinv2d, sizeof(path->grad_inv2d));
	}
	path->has_line = g->cur_line;
	path->lr = g->clr; path->lg = g->clg; path->lb = g->clb; path->la = g->cla;

	if (want_fill && poly_count >= 3 && ccount > 0)
	{
		float* tw = malloc(poly_count * 2 * sizeof(float));
		for (uint32_t i = 0; i < poly_count; i++)
		{
			tw[i*2] = poly[i*2] * 20.0f; tw[i*2+1] = poly[i*2+1] * 20.0f;
		}
		TESStesselator* tess = tessNewTess(NULL);
		if (tess)
		{
			tessSetOption(tess, TESS_CONSTRAINED_DELAUNAY_TRIANGULATION, 1);
			int contrib = 0;
			for (uint32_t ci = 0; ci < ccount; ci++)
			{
				uint32_t cs = cstarts[ci];
				uint32_t ce = (ci + 1 < ccount) ? cstarts[ci + 1] : poly_count;
				int n = (int) (ce - cs);
				if (n < 3) continue;
				tessAddContour(tess, 2, &tw[cs*2], sizeof(float) * 2, n);
				contrib++;
			}
			if (contrib > 0 && tessTesselate(tess, TESS_WINDING_NONZERO,
			                                 TESS_POLYGONS, 3, 2, NULL))
			{
				const TESSreal* v = tessGetVertices(tess);
				const TESSindex* el = tessGetElements(tess);
				int nt = tessGetElementCount(tess);
				path->fill_vert_count = (uint32_t) nt * 3;
				path->fill_verts = malloc(path->fill_vert_count * 2 * sizeof(float));
				for (int i = 0; i < nt; i++)
					for (int j = 0; j < 3; j++)
					{
						TESSindex idx = el[i*3 + j];
						path->fill_verts[i*6 + j*2]   = v[idx*2];
						path->fill_verts[i*6 + j*2+1] = v[idx*2+1];
					}
			}
			tessDeleteTess(tess);
		}
		free(tw);
	}
	if (want_line)
		gfx_build_stroke(path, poly, poly_count, cstarts, ccount,
		                 want_fill, g->clw * 0.5f * 20.0f);

	free(poly); free(cstarts);
	g->cmd_count = 0;
}

// sRGB<->linear for linearRGB ramp interpolation (mirror action.c, Ruffle parity).
static float gfx_srgb_to_linear(float c)
{
	return c <= 0.04045f ? c / 12.92f : powf((c + 0.055f) / 1.055f, 2.4f);
}
static uint8_t gfx_srgb_to_linear_u8(uint8_t c)
{
	return (uint8_t) (gfx_srgb_to_linear(c / 255.0f) * 255.0f);
}
static uint8_t gfx_lin_lerp(uint8_t a, uint8_t b, float t)
{
	return (uint8_t) (a + t * (float) (b - a));
}
static uint8_t gfx_rgb_lerp(uint8_t a, uint8_t b, float t)
{
	return (uint8_t) (a + t * (b - a) + 0.5f);
}

// 256-row RGBA8 ramp from stops (colors 0xRRGGBB, alphas 0..1, ratios 0..255).
// linearRGB stores linear (shader/raster converts back). Mirrors action.c.
static void gfx_gen_ramp(const uint32_t* colors, const float* alphas,
                         const uint8_t* ratios, int n, int linear, uint8_t* out)
{
	if (n <= 0) { memset(out, 0, 256 * 4); return; }
	uint8_t r0 = (colors[0] >> 16) & 0xFF, g0 = (colors[0] >> 8) & 0xFF;
	uint8_t b0 = colors[0] & 0xFF, a0 = (uint8_t) (alphas[0] * 255.0f + 0.5f);
	if (linear) { r0 = gfx_srgb_to_linear_u8(r0); g0 = gfx_srgb_to_linear_u8(g0);
	              b0 = gfx_srgb_to_linear_u8(b0); }
	for (int i = 0; i < 256; i++)
	{ out[i*4]=r0; out[i*4+1]=g0; out[i*4+2]=b0; out[i*4+3]=a0; }
	for (int s = 1; s < n; s++)
	{
		uint8_t r_s = ratios[s-1], r_e = ratios[s];
		uint8_t sr=(colors[s-1]>>16)&0xFF, sg=(colors[s-1]>>8)&0xFF, sb=colors[s-1]&0xFF;
		uint8_t sa=(uint8_t)(alphas[s-1]*255.0f+0.5f);
		uint8_t er=(colors[s]>>16)&0xFF, eg=(colors[s]>>8)&0xFF, eb=colors[s]&0xFF;
		uint8_t ea=(uint8_t)(alphas[s]*255.0f+0.5f);
		if (linear) { sr=gfx_srgb_to_linear_u8(sr); sg=gfx_srgb_to_linear_u8(sg);
		              sb=gfx_srgb_to_linear_u8(sb); er=gfx_srgb_to_linear_u8(er);
		              eg=gfx_srgb_to_linear_u8(eg); eb=gfx_srgb_to_linear_u8(eb); }
		float range = (float) (r_e - r_s); if (range <= 0) range = 1;
		for (int i = r_s; i <= r_e; i++)
		{
			float t = (float) (i - r_s) / range;
			if (linear) { out[i*4]=gfx_lin_lerp(sr,er,t); out[i*4+1]=gfx_lin_lerp(sg,eg,t);
			              out[i*4+2]=gfx_lin_lerp(sb,eb,t); }
			else { out[i*4]=gfx_rgb_lerp(sr,er,t); out[i*4+1]=gfx_rgb_lerp(sg,eg,t);
			       out[i*4+2]=gfx_rgb_lerp(sb,eb,t); }
			out[i*4+3] = gfx_rgb_lerp(sa, ea, t);
			if (i == 255) break;
		}
		if (s == n - 1 && r_e < 255)
			for (int i = r_e + 1; i < 256; i++)
			{ out[i*4]=er; out[i*4+1]=eg; out[i*4+2]=eb; out[i*4+3]=ea; }
	}
}

// From a Flash 2x3 affine (a,b,c,d dimensionless; tx,ty twips) mapping gradient
// [-16384,16384] -> local twips: fill grad_fwd16 (GPU) and grad_inv2d (CPU: the
// normalized inverse local-twips -> UV[0,1], mirroring render_webgpu.c's dynamic
// gradient norm_inv).
static void gfx_set_gradient_matrix(Avm2GraphicsExt* g, float a, float b,
                                    float c, float d, float tx, float ty)
{
	memset(g->cfwd16, 0, sizeof(g->cfwd16));
	g->cfwd16[0]=a; g->cfwd16[1]=b; g->cfwd16[4]=c; g->cfwd16[5]=d;
	g->cfwd16[10]=1.0f; g->cfwd16[12]=tx; g->cfwd16[13]=ty; g->cfwd16[15]=1.0f;
	double det = (double) a * d - (double) b * c;
	double ia, ib, ic, id, itx, ity;
	if (det == 0.0) { ia=ib=ic=id=itx=ity=0.0; }
	else
	{
		double inv = 1.0 / det;
		ia =  d * inv; ib = -b * inv; ic = -c * inv; id = a * inv;
		itx = ((double) c * ty - (double) d * tx) * inv;
		ity = ((double) b * tx - (double) a * ty) * inv;
	}
	double s = 1.0 / 32768.0;
	g->cinv2d[0] = (float) (ia * s); g->cinv2d[1] = (float) (ib * s);
	g->cinv2d[2] = (float) (ic * s); g->cinv2d[3] = (float) (id * s);
	g->cinv2d[4] = (float) (itx * s + 0.5); g->cinv2d[5] = (float) (ity * s + 0.5);
}

// Build a CPU-raster fill descriptor from a finalized path's fill style.
static void gfx_fill_from_path(const Avm2GfxPath* p, Avm2GfxFill* f)
{
	memset(f, 0, sizeof(*f));
	f->kind = p->fill_kind;
	if (p->fill_kind == 1)
	{ f->r = p->fr; f->g = p->fg; f->b = p->fb; f->a = p->fa; }
	else if (p->fill_kind == 2)
	{
		f->grad_type = p->grad_type; f->spread = p->grad_spread;
		f->interp = p->grad_interp; f->focal = p->grad_focal;
		f->ramp = p->grad_ramp;
		memcpy(f->inv2d, p->grad_inv2d, sizeof(f->inv2d));
	}
}

// The Graphics ext attached to a display node (its `graphics` object), or NULL.
static Avm2GraphicsExt* gfx_node_ext(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->graphics_obj == NULL
	    || ext->graphics_obj->native_ext == NULL)
		return NULL;
	return (Avm2GraphicsExt*) ext->graphics_obj->native_ext;
}

// CPU-composite a node's recorded Graphics geometry into a premultiplied-ARGB
// target (`w*` = shape-local twips -> target twips). Fills then strokes, back to
// front, mirroring the WGSL/GPU order. Used by avm2_cpu_walk (headless dump) and
// BitmapData.draw (the getPixel gate). Non-static: bd_draw calls it.
void avm2_graphics_cpu_composite(Avm2Context* ctx, Avm2Object* obj,
                                 double wa, double wb, double wc, double wd,
                                 double wtx, double wty, double alpha,
                                 uint32_t* buf, int W, int H, int transparent)
{
	Avm2GraphicsExt* g = gfx_node_ext(ctx, obj);
	if (g == NULL) return;
	gfx_finalize_path(g);  // commit any pending (un-endFilled) subpath
	for (uint32_t i = 0; i < g->path_count; i++)
	{
		Avm2GfxPath* p = &g->paths[i];
		if (p->fill_kind != 0 && p->fill_vert_count >= 3)
		{
			Avm2GfxFill f; gfx_fill_from_path(p, &f);
			avm2_cpu_raster_tris(buf, W, H, transparent, p->fill_verts,
			                     p->fill_vert_count, &f, wa, wb, wc, wd,
			                     wtx, wty, alpha);
		}
		if (p->has_line && p->line_vert_count >= 3)
		{
			Avm2GfxFill sf; memset(&sf, 0, sizeof(sf));
			sf.kind = 1; sf.r = p->lr; sf.g = p->lg; sf.b = p->lb; sf.a = p->la;
			avm2_cpu_raster_tris(buf, W, H, transparent, p->line_verts,
			                     p->line_vert_count, &sf, wa, wb, wc, wd,
			                     wtx, wty, alpha);
		}
	}
}

static Avm2Value gfx_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

// clear(): drop recorded geometry + AABB.
static Avm2Value gfx_clear(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	if (ext != NULL) ext->draw_valid = 0;
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g != NULL) gfx_reset(g);
	return avm2_undefined();
}

// beginFill(color:uint, alpha:Number=1): flush the pending subpath, then set a
// solid current fill.
static Avm2Value gfx_begin_fill(Avm2Activation* act)
{
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g == NULL) return avm2_undefined();
	gfx_finalize_path(g);
	uint32_t rgb = act->argc > 0 ? avm2_coerce_to_u32(act->ctx, act->args[0]) : 0;
	double a = act->argc > 1 ? avm2_coerce_to_number(act->ctx, act->args[1]) : 1.0;
	if (a < 0) a = 0; else if (a > 1) a = 1;
	g->cur_fill = 1;
	g->cfr = ((rgb >> 16) & 0xFF) / 255.0f;
	g->cfg = ((rgb >>  8) & 0xFF) / 255.0f;
	g->cfb = ( rgb        & 0xFF) / 255.0f;
	g->cfa = (float) a;
	return avm2_undefined();
}

// Read an Array/Vector arg's numeric elements into out[max]; returns count.
static uint32_t gfx_read_num_array(Avm2Context* ctx, Avm2Value v, double* out,
                                   uint32_t max)
{
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL) return 0;
	Avm2VectorExt* vec = avm2_vector_ext(v.u.obj);
	uint32_t n = 0;
	if (vec != NULL)
	{
		for (uint32_t i = 0; i < vec->length && n < max; i++)
			out[n++] = avm2_coerce_to_number(ctx, vec->elems[i]);
		return n;
	}
	// Plain Array: read numeric-index length + elements.
	double len = avm2_coerce_to_number(ctx,
		avm2_get_public_property(ctx, v, "length", 6, NULL));
	uint32_t ln = (len > 0 && len < (double) max) ? (uint32_t) len : max;
	for (uint32_t i = 0; i < ln; i++)
	{
		char idx[16]; int il = snprintf(idx, sizeof(idx), "%u", i);
		Avm2Value e = avm2_get_public_property(ctx, v, idx, (uint32_t) il, NULL);
		if (e.kind == AVM2_VALUE_UNDEFINED) break;
		out[n++] = avm2_coerce_to_number(ctx, e);
	}
	return n;
}

// beginGradientFill(type, colors, alphas, ratios, matrix, spread="pad",
// interp="rgb", focal=0). Builds a 256-row ramp + gradient matrix now.
static Avm2Value gfx_begin_gradient_fill(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g == NULL) return avm2_undefined();
	gfx_finalize_path(g);
	if (act->argc < 4) { g->cur_fill = 0; return avm2_undefined(); }

	const Avm2String* ts = avm2_coerce_to_string(ctx, act->args[0]);
	uint8_t gt = gfx_str_is(ts, "radial") ? 0x12 : 0x10;
	double colv[64], alpv[64], ratv[64];
	uint32_t nc = gfx_read_num_array(ctx, act->args[1], colv, 64);
	uint32_t na = gfx_read_num_array(ctx, act->args[2], alpv, 64);
	uint32_t nr = gfx_read_num_array(ctx, act->args[3], ratv, 64);
	uint32_t n = nc < na ? nc : na; if (nr < n) n = nr;
	if (n == 0) { g->cur_fill = 0; return avm2_undefined(); }
	uint32_t cols[64]; float alps[64]; uint8_t rats[64];
	for (uint32_t i = 0; i < n; i++)
	{
		cols[i] = (uint32_t) colv[i] & 0xFFFFFF;
		float a = (float) alpv[i]; alps[i] = a < 0 ? 0 : a > 1 ? 1 : a;
		int rr = (int) ratv[i]; rats[i] = rr < 0 ? 0 : rr > 255 ? 255 : (uint8_t) rr;
	}
	uint8_t spread = 0, interp = 0;
	if (act->argc > 5)
	{
		const Avm2String* ss = avm2_coerce_to_string(ctx, act->args[5]);
		spread = gfx_str_is(ss, "reflect") ? 1 : gfx_str_is(ss, "repeat") ? 2 : 0;
	}
	if (act->argc > 6)
	{
		const Avm2String* is = avm2_coerce_to_string(ctx, act->args[6]);
		interp = gfx_str_is(is, "linearRGB") ? 1 : 0;
	}
	double focal = act->argc > 7 ? avm2_coerce_to_number(ctx, act->args[7]) : 0.0;
	if (focal != 0.0) gt = 0x13;

	g->cur_fill = 2;
	g->cgt = gt; g->cgs = spread; g->cgi = interp; g->cgf = (float) focal;
	gfx_gen_ramp(cols, alps, rats, (int) n, interp, g->cramp);

	// Gradient matrix from the flash.geom.Matrix arg (a,b,c,d,tx,ty). Default
	// identity box if absent.
	double ma = 1, mb = 0, mc = 0, md = 1, mtx = 0, mty = 0;
	if (act->argc > 4 && act->args[4].kind == AVM2_VALUE_OBJECT
	    && act->args[4].u.obj != NULL)
	{
		Avm2Object* m = act->args[4].u.obj;
		ma = matrix_get_prop(ctx, m, "a"); mb = matrix_get_prop(ctx, m, "b");
		mc = matrix_get_prop(ctx, m, "c"); md = matrix_get_prop(ctx, m, "d");
		mtx = matrix_get_prop(ctx, m, "tx"); mty = matrix_get_prop(ctx, m, "ty");
	}
	gfx_set_gradient_matrix(g, (float) ma, (float) mb, (float) mc, (float) md,
	                        (float) (mtx * 20.0), (float) (mty * 20.0));
	return avm2_undefined();
}

// endFill(): flush the pending subpath and clear the current fill.
static Avm2Value gfx_end_fill(Avm2Activation* act)
{
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g == NULL) return avm2_undefined();
	gfx_finalize_path(g);
	g->cur_fill = 0;
	return avm2_undefined();
}

// lineStyle(thickness, color=0, alpha=1, ...): flush, then set the current
// stroke (solid only this tranche; a fill-typed stroke degrades to no stroke).
static Avm2Value gfx_line_style(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g == NULL) return avm2_undefined();
	gfx_finalize_path(g);
	if (act->argc == 0 || act->args[0].kind == AVM2_VALUE_UNDEFINED)
	{
		g->cur_line = 0;
		return avm2_undefined();
	}
	double w = avm2_coerce_to_number(ctx, act->args[0]);
	uint32_t rgb = act->argc > 1 ? avm2_coerce_to_u32(ctx, act->args[1]) : 0;
	double a = act->argc > 2 ? avm2_coerce_to_number(ctx, act->args[2]) : 1.0;
	if (a < 0) a = 0; else if (a > 1) a = 1;
	g->cur_line = 1;
	g->clw = (float) (w > 0 ? w : 1.0);  // hairline (0/NaN) -> nominal 1px
	g->clr = ((rgb >> 16) & 0xFF) / 255.0f;
	g->clg = ((rgb >>  8) & 0xFF) / 255.0f;
	g->clb = ( rgb        & 0xFF) / 255.0f;
	g->cla = (float) a;
	return avm2_undefined();
}

// moveTo(x, y)
static Avm2Value gfx_move_to(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (act->argc >= 2)
	{
		double x = avm2_coerce_to_number(act->ctx, act->args[0]);
		double y = avm2_coerce_to_number(act->ctx, act->args[1]);
		if (ext != NULL) draw_union_point(ext, x, y);
		if (g != NULL) gfx_add_cmd(g, 0, (float) x, (float) y, 0, 0);
	}
	return avm2_undefined();
}

// lineTo(x, y)
static Avm2Value gfx_line_to(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (act->argc >= 2)
	{
		double x = avm2_coerce_to_number(act->ctx, act->args[0]);
		double y = avm2_coerce_to_number(act->ctx, act->args[1]);
		if (ext != NULL) draw_union_point(ext, x, y);
		if (g != NULL)
		{
			if (!g->pen_set) gfx_add_cmd(g, 0, 0, 0, 0, 0);
			gfx_add_cmd(g, 1, (float) x, (float) y, 0, 0);
		}
	}
	return avm2_undefined();
}

// curveTo(cx, cy, ax, ay)
static Avm2Value gfx_curve_to(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (act->argc >= 4)
	{
		double cx = avm2_coerce_to_number(act->ctx, act->args[0]);
		double cy = avm2_coerce_to_number(act->ctx, act->args[1]);
		double ax = avm2_coerce_to_number(act->ctx, act->args[2]);
		double ay = avm2_coerce_to_number(act->ctx, act->args[3]);
		if (ext != NULL) { draw_union_point(ext, cx, cy); draw_union_point(ext, ax, ay); }
		if (g != NULL)
		{
			if (!g->pen_set) gfx_add_cmd(g, 0, 0, 0, 0, 0);
			gfx_add_cmd(g, 2, (float) ax, (float) ay, (float) cx, (float) cy);
		}
	}
	return avm2_undefined();
}

// Append a moveTo + n lineTo (closed) polygon to the pen buffer.
static void gfx_emit_rect(Avm2GraphicsExt* g, double x, double y,
                          double w, double h)
{
	gfx_add_cmd(g, 0, (float) x,       (float) y,       0, 0);
	gfx_add_cmd(g, 1, (float)(x + w),  (float) y,       0, 0);
	gfx_add_cmd(g, 1, (float)(x + w),  (float)(y + h),  0, 0);
	gfx_add_cmd(g, 1, (float) x,       (float)(y + h),  0, 0);
	gfx_add_cmd(g, 1, (float) x,       (float) y,       0, 0);
}

// drawRect/drawRoundRect/drawEllipse(x, y, w, h) — round-rect corner radii are
// approximated as a plain rect this tranche (AABB unchanged).
static Avm2Value gfx_draw_rect(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (act->argc >= 4)
	{
		double x = avm2_coerce_to_number(act->ctx, act->args[0]);
		double y = avm2_coerce_to_number(act->ctx, act->args[1]);
		double w = avm2_coerce_to_number(act->ctx, act->args[2]);
		double h = avm2_coerce_to_number(act->ctx, act->args[3]);
		if (ext != NULL) { draw_union_point(ext, x, y); draw_union_point(ext, x + w, y + h); }
		if (g != NULL) gfx_emit_rect(g, x, y, w, h);
	}
	return avm2_undefined();
}

// drawRoundRectComplex(x, y, w, h, tl, tr, bl, br) — the four radii are
// approximated away exactly like drawRoundRect's single radius (AABB unchanged).
static Avm2Value gfx_draw_round_rect_complex(Avm2Activation* act)
{
	return gfx_draw_rect(act);
}

// cubicCurveTo(c1x, c1y, c2x, c2y, ax, ay). Our command stream carries
// quadratics only (that is what the SWF shape record has), so the cubic is
// split into 8 sub-curves by de Casteljau and each is replaced by its
// least-squares quadratic (control = (3*C1 - P0 + 3*C2 - P3)/4). At 8 segments
// the deviation is far below a twip for any on-screen curve.
static Avm2Value gfx_cubic_curve_to(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (act->argc < 6) return avm2_undefined();
	Avm2Context* ctx = act->ctx;
	double c1x = avm2_coerce_to_number(ctx, act->args[0]);
	double c1y = avm2_coerce_to_number(ctx, act->args[1]);
	double c2x = avm2_coerce_to_number(ctx, act->args[2]);
	double c2y = avm2_coerce_to_number(ctx, act->args[3]);
	double ax  = avm2_coerce_to_number(ctx, act->args[4]);
	double ay  = avm2_coerce_to_number(ctx, act->args[5]);
	if (ext != NULL)
	{
		draw_union_point(ext, c1x, c1y);
		draw_union_point(ext, c2x, c2y);
		draw_union_point(ext, ax, ay);
	}
	if (g == NULL) return avm2_undefined();
	if (!g->pen_set) gfx_add_cmd(g, 0, 0, 0, 0, 0);
	double p0x = g->pen_x, p0y = g->pen_y;
	const int N = 8;
	for (int i = 0; i < N; i++)
	{
		double t0 = (double) i / N, t1 = (double)(i + 1) / N;
		// Cubic point + derivative-scaled control points on [t0, t1].
		#define CUB(t, a, b, c, d) ((1 - (t)) * (1 - (t)) * (1 - (t)) * (a) \
			+ 3 * (1 - (t)) * (1 - (t)) * (t) * (b) \
			+ 3 * (1 - (t)) * (t) * (t) * (c) + (t) * (t) * (t) * (d))
		#define DER(t, a, b, c, d) (3 * (1 - (t)) * (1 - (t)) * ((b) - (a)) \
			+ 6 * (1 - (t)) * (t) * ((c) - (b)) + 3 * (t) * (t) * ((d) - (c)))
		double dt = t1 - t0;
		double sx = CUB(t0, p0x, c1x, c2x, ax), sy = CUB(t0, p0y, c1y, c2y, ay);
		double ex = CUB(t1, p0x, c1x, c2x, ax), ey = CUB(t1, p0y, c1y, c2y, ay);
		double b1x = sx + DER(t0, p0x, c1x, c2x, ax) * dt / 3.0;
		double b1y = sy + DER(t0, p0y, c1y, c2y, ay) * dt / 3.0;
		double b2x = ex - DER(t1, p0x, c1x, c2x, ax) * dt / 3.0;
		double b2y = ey - DER(t1, p0y, c1y, c2y, ay) * dt / 3.0;
		#undef CUB
		#undef DER
		double qx = (3 * b1x - sx + 3 * b2x - ex) * 0.25;
		double qy = (3 * b1y - sy + 3 * b2y - ey) * 0.25;
		gfx_add_cmd(g, 2, (float) ex, (float) ey, (float) qx, (float) qy);
	}
	return avm2_undefined();
}

// drawCircle(x, y, r) / drawEllipse via 4 cubic-equivalent quadratic arcs.
static Avm2Value gfx_draw_circle(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (act->argc >= 3)
	{
		double x = avm2_coerce_to_number(act->ctx, act->args[0]);
		double y = avm2_coerce_to_number(act->ctx, act->args[1]);
		double r = avm2_coerce_to_number(act->ctx, act->args[2]);
		if (ext != NULL) { draw_union_point(ext, x - r, y - r); draw_union_point(ext, x + r, y + r); }
		if (g != NULL)
		{
			// 8 quadratic segments approximating the circle (control point at
			// tan(pi/8) out along the bisector). Good to <0.1% radius.
			const int N = 8;
			double kct = 1.0 / cos(M_PI / N);   // control radius factor
			gfx_add_cmd(g, 0, (float)(x + r), (float) y, 0, 0);
			for (int i = 0; i < N; i++)
			{
				double a0 = 2.0 * M_PI * i / N, a1 = 2.0 * M_PI * (i + 1) / N;
				double am = (a0 + a1) * 0.5;
				double ex = x + r * cos(a1), ey = y + r * sin(a1);
				double cxp = x + r * kct * cos(am), cyp = y + r * kct * sin(am);
				gfx_add_cmd(g, 2, (float) ex, (float) ey, (float) cxp, (float) cyp);
			}
		}
	}
	return avm2_undefined();
}

// drawEllipse(x, y, w, h) — x/y is the TOP-LEFT corner, not the centre. It used
// to share drawRect's body, which drew a box where Flash draws an oval.
static Avm2Value gfx_draw_ellipse(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = graphics_owner_ext(act);
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (act->argc < 4) return avm2_undefined();
	double x = avm2_coerce_to_number(act->ctx, act->args[0]);
	double y = avm2_coerce_to_number(act->ctx, act->args[1]);
	double w = avm2_coerce_to_number(act->ctx, act->args[2]);
	double h = avm2_coerce_to_number(act->ctx, act->args[3]);
	if (ext != NULL)
	{
		draw_union_point(ext, x, y);
		draw_union_point(ext, x + w, y + h);
	}
	if (g == NULL) return avm2_undefined();
	double rx = w * 0.5, ry = h * 0.5, cx = x + rx, cy = y + ry;
	const int N = 8;
	double kct = 1.0 / cos(M_PI / N);
	gfx_add_cmd(g, 0, (float)(cx + rx), (float) cy, 0, 0);
	for (int i = 0; i < N; i++)
	{
		double a0 = 2.0 * M_PI * i / N, a1 = 2.0 * M_PI * (i + 1) / N;
		double am = (a0 + a1) * 0.5;
		double ex = cx + rx * cos(a1), ey = cy + ry * sin(a1);
		double ccx = cx + rx * kct * cos(am), ccy = cy + ry * kct * sin(am);
		gfx_add_cmd(g, 2, (float) ex, (float) ey, (float) ccx, (float) ccy);
	}
	return avm2_undefined();
}

// beginBitmapFill(bitmap, matrix, repeat, smooth) / lineBitmapStyle(...) /
// lineGradientStyle(...). The command stream carries a solid or gradient fill
// and a SOLID stroke; a bitmap fill and any non-solid stroke have no
// representation in it. Rather than silently keeping whatever style was
// current — which is what the old gfx_noop did, so a beginBitmapFill leaked the
// previous colour onto the next shape — each of these flushes the pending
// subpath and clears the style it governs. gfx_line_style already documents
// that convention for a fill-typed stroke.
static Avm2Value gfx_begin_bitmap_fill(Avm2Activation* act)
{
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g == NULL) return avm2_undefined();
	gfx_finalize_path(g);
	g->cur_fill = 0;
	return avm2_undefined();
}

static Avm2Value gfx_line_fill_style(Avm2Activation* act)
{
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g == NULL) return avm2_undefined();
	gfx_finalize_path(g);
	g->cur_line = 0;
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// flash.media.Video — a DisplayObject whose bounds are its declared size
// ---------------------------------------------------------------------------

// Ruffle core/src/bitmap.rs is_size_valid: the same limits BitmapData uses,
// version-gated. Video's ctor reaches it only for a non-zero pair.
static int video_size_valid(uint32_t swf_version, uint32_t w, uint32_t h)
{
	if (w == 0 || h == 0) return 0;
	if (swf_version <= 9) return w <= 2880 && h <= 2880;
	if (swf_version <= 12)
		return w < 0x2000 && h < 0x2000 && (uint64_t) w * h < 0x1000000;
	// Undocumented but reliable (Ruffle's own comment).
	return w <= 0x6666666 && h <= 0x6666666
	    && (uint64_t) w * (uint64_t) h < 0x20000000;
}

// Video(width:int = 320, height:int = 240) -> globals/flash/media/video.rs
// `init`. Negative EITHER dimension is #2006; a ZERO in either falls back to
// the 320x240 default pair (Adobe's documented behaviour, and why
// `new Video(100, 0)` is 320x240 rather than 100x240). The resulting size is
// the object's intrinsic bounds, so width/height/scaleX all fall out of the
// existing DisplayObject machinery.
static Avm2Value video_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	int32_t w = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 320;
	int32_t h = act->argc > 1 ? avm2_coerce_to_i32(ctx, act->args[1]) : 240;
	if (w < 0 || h < 0)
	{
		avm2_throw_error(ctx, ctx->builtins.range_error_class,
		                 "Error #2006: The supplied index is out of bounds.");
	}
	if (w == 0 || h == 0)
	{
		w = 320; h = 240;
	}
	else if (!video_size_valid(ctx->swf_version, (uint32_t) w, (uint32_t) h))
	{
		avm2_throw_error(ctx, ctx->builtins.range_error_class,
		                 "Error #2006: The supplied index is out of bounds.");
	}
	if (ext != NULL)
	{
		draw_union_point(ext, 0, 0);
		draw_union_point(ext, (double) w, (double) h);
	}
	return avm2_undefined();
}

static Avm2Value video_get_deblocking(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2Value* v = self != NULL
		? avm2_object_find_dynamic(self, "_deblocking", 11) : NULL;
	return v != NULL ? *v : avm2_integer(0);
}

static Avm2Value video_set_deblocking(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL || act->argc < 1) return avm2_undefined();
	avm2_object_set_dynamic(act->ctx, self, "_deblocking", 11,
		avm2_integer(avm2_coerce_to_i32(act->ctx, act->args[0])))->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value video_get_smoothing(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	Avm2Value* v = self != NULL
		? avm2_object_find_dynamic(self, "_smoothing", 10) : NULL;
	return v != NULL ? *v : avm2_bool(0);
}

static Avm2Value video_set_smoothing(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL || act->argc < 1) return avm2_undefined();
	avm2_object_set_dynamic(act->ctx, self, "_smoothing", 10,
		avm2_bool(avm2_coerce_to_boolean(act->args[0]) ? 1 : 0))->dont_enum = 1;
	return avm2_undefined();
}

// videoWidth/videoHeight are stubbed to 0 in Ruffle too (no decoder is
// attached in the test harness), and are getter-only so a write raises #1074.
static Avm2Value video_get_zero(Avm2Activation* act)
{
	(void) act;
	return avm2_integer(0);
}

static Avm2Value video_noop(Avm2Activation* act)
{
	(void) act;
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
// T4 Part A — flash.display.Graphics runtime drawing: command decoding +
// argument validation. drawPath / drawTriangles / drawGraphicsData plus the
// GraphicsPath / GraphicsTrianglePath / GraphicsPathCommand / GraphicsPathWinding
// / IGraphicsData / GraphicsSolidFill / GraphicsGradientFill / GraphicsStroke
// surface. Error codes + stack frames mirror Ruffle/Flash exactly (upstream
// graphics_draw_path / graphics_draw_triangles / graphics_path /
// graphics_bad_direct_commands):
//   - drawPath / drawTriangles throw #2004/#2008 DIRECTLY, so the trace top is
//     the native method frame "flash.display::Graphics/drawPath()" — no
//     throwError frame (Ruffle's make_error_2004/2008 add no AS frame).
//   - GraphicsPath ctor + `set winding` throw #2008 through a synthetic
//     "Error$/throwError()" frame (FP playerglobal routes through
//     Error.throwError; Ruffle's GraphicsPath.as `throw new ArgumentError`).
// Geometry recording + tessellation + rendering is Part B.
// ===========================================================================

static Avm2Class* g_graphicspath_class;
static Avm2Class* g_graphicstrianglepath_class;
static Avm2Class* g_igraphicsdata_class;

// Exact byte compare of an Avm2String to a C literal.
static int gfx_str_is(const Avm2String* s, const char* lit)
{
	size_t n = strlen(lit);
	return s != NULL && s->len == n && memcmp(s->utf8, lit, n) == 0;
}

// The Vector.<T> storage behind arg[i], or NULL if the arg is absent, null, or
// not a Vector.
static Avm2VectorExt* gfx_vec_arg(Avm2Activation* act, uint32_t i)
{
	if (i >= act->argc) return NULL;
	Avm2Value v = act->args[i];
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL) return NULL;
	return avm2_vector_ext(v.u.obj);
}

// The Vector.<T> storage stored in dynamic property `name` of `o`, or NULL.
static Avm2VectorExt* gfx_vec_prop(Avm2Object* o, const char* name, uint32_t nlen)
{
	Avm2Value* v = avm2_object_find_dynamic(o, name, nlen);
	if (v == NULL || v->kind != AVM2_VALUE_OBJECT || v->u.obj == NULL) return NULL;
	return avm2_vector_ext(v->u.obj);
}

static _Noreturn void gfx_throw_2004(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2004: One of the parameters is invalid.");
}

static _Noreturn void gfx_throw_2008(Avm2Context* ctx, const char* param)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2008: Parameter %s must be one of the accepted values.",
	                 param);
}

// #2008 as FP's playerglobal throws it: through Error.throwError, which shows as
// an "Error$/throwError()" frame atop the trace. The synthetic native frame
// (bound_class NULL + file NULL => debug_name printed verbatim by
// avm2_callstack_frame_name) is discarded by the longjmp that unwinds call_depth
// back to the nearest try frame, so no explicit pop is needed.
static _Noreturn void gfx_throw_2008_via_throwerror(Avm2Context* ctx, const char* param)
{
	static const Avm2MethodRef throwerror = { NULL, NULL, "Error$/throwError", 0 };
	avm2_callstack_push(ctx, &throwerror, NULL);
	gfx_throw_2008(ctx, param);
}

// TriangleData::new validation (Ruffle graphics.rs) — throws #2004; empty /
// out-of-bounds inputs produce no triangles (no throw). Part A: validation only.
static void gfx_validate_triangles(Avm2Context* ctx, Avm2VectorExt* verts,
                                   Avm2VectorExt* indices)
{
	uint32_t nv = verts != NULL ? verts->length : 0;
	if ((nv & 1u) != 0) gfx_throw_2004(ctx);   // vertices not pairs
	if (nv == 0) return;                        // no vertices -> no triangles
	if (indices != NULL)
	{
		if ((indices->length % 3u) != 0) gfx_throw_2004(ctx);
		return;   // empty / all-out-of-bounds -> no triangles (no throw)
	}
	if (((nv / 2u) % 3u) != 0) gfx_throw_2004(ctx);   // vertex triples
}

// Snapshot the current fill into a fresh finalized path (no geometry yet); the
// caller fills fill_verts. Used by drawTriangles (explicit triangles, no tess).
static Avm2GfxPath* gfx_new_fill_path(Avm2GraphicsExt* g)
{
	if (g->path_count >= g->path_cap)
	{
		g->path_cap = g->path_cap ? g->path_cap * 2 : 8;
		g->paths = realloc(g->paths, g->path_cap * sizeof(Avm2GfxPath));
	}
	Avm2GfxPath* p = &g->paths[g->path_count++];
	memset(p, 0, sizeof(Avm2GfxPath));
	p->fill_kind = g->cur_fill;
	p->fr = g->cfr; p->fg = g->cfg; p->fb = g->cfb; p->fa = g->cfa;
	if (g->cur_fill == 2)
	{
		p->grad_type = g->cgt; p->grad_spread = g->cgs;
		p->grad_interp = g->cgi; p->grad_focal = g->cgf;
		memcpy(p->grad_ramp, g->cramp, sizeof(p->grad_ramp));
		memcpy(p->grad_fwd16, g->cfwd16, sizeof(p->grad_fwd16));
		memcpy(p->grad_inv2d, g->cinv2d, sizeof(p->grad_inv2d));
	}
	return p;
}

// drawTriangles geometry: expand vertices(+indices) into a flat twips triangle
// list. Flash stops at the first out-of-bounds index (mirrors TriangleData::new).
static void gfx_append_triangles(Avm2GraphicsExt* g, Avm2Context* ctx,
                                 Avm2VectorExt* verts, Avm2VectorExt* indices)
{
	uint32_t nvp = verts->length / 2;
	if (nvp < 3) return;
	uint32_t max_tris = indices != NULL ? indices->length / 3 : nvp / 3;
	if (max_tris == 0) return;
	float* out = malloc(max_tris * 3 * 2 * sizeof(float));
	uint32_t vc = 0;
	if (indices != NULL)
	{
		for (uint32_t t = 0; t + 3 <= indices->length; t += 3)
		{
			uint32_t i0 = (uint32_t) avm2_coerce_to_i32(ctx, indices->elems[t]);
			uint32_t i1 = (uint32_t) avm2_coerce_to_i32(ctx, indices->elems[t + 1]);
			uint32_t i2 = (uint32_t) avm2_coerce_to_i32(ctx, indices->elems[t + 2]);
			if (i0 >= nvp || i1 >= nvp || i2 >= nvp) break;  // Flash stops here
			uint32_t idx[3] = { i0, i1, i2 };
			for (int k = 0; k < 3; k++)
			{
				out[vc * 2]     = (float)(avm2_coerce_to_number(ctx, verts->elems[idx[k]*2]) * 20.0);
				out[vc * 2 + 1] = (float)(avm2_coerce_to_number(ctx, verts->elems[idx[k]*2+1]) * 20.0);
				vc++;
			}
		}
	}
	else
	{
		uint32_t tris = nvp / 3;
		for (uint32_t i = 0; i < tris * 3; i++)
		{
			out[vc * 2]     = (float)(avm2_coerce_to_number(ctx, verts->elems[i*2]) * 20.0);
			out[vc * 2 + 1] = (float)(avm2_coerce_to_number(ctx, verts->elems[i*2+1]) * 20.0);
			vc++;
		}
	}
	if (vc < 3) { free(out); return; }
	Avm2GfxPath* p = gfx_new_fill_path(g);
	p->fill_verts = out;
	p->fill_vert_count = vc;
}

// drawPath command decode: append pen commands (moveTo/lineTo/curveTo) mirroring
// Ruffle process_commands. data is pixels. Cubic curves are flattened to lines.
static void gfx_decode_path(Avm2GraphicsExt* g, Avm2Context* ctx,
                            Avm2VectorExt* commands, Avm2VectorExt* data)
{
	uint32_t di = 0, nd = data != NULL ? data->length : 0;
	#define _GRDPT(px, py) do { \
		if (di + 2 > nd) return; \
		(px) = avm2_coerce_to_number(ctx, data->elems[di]); \
		(py) = avm2_coerce_to_number(ctx, data->elems[di + 1]); di += 2; } while (0)
	for (uint32_t i = 0; i < commands->length; i++)
	{
		int32_t cmd = avm2_coerce_to_i32(ctx, commands->elems[i]);
		double x, y, cx, cy, c2x, c2y;
		switch (cmd)
		{
			case 0: break;                                  // NO_OP
			case 1: _GRDPT(x, y); gfx_add_cmd(g, 0, (float)x, (float)y, 0, 0); break;
			case 2: _GRDPT(x, y); gfx_add_cmd(g, 1, (float)x, (float)y, 0, 0); break;
			case 3: _GRDPT(cx, cy); _GRDPT(x, y);
				gfx_add_cmd(g, 2, (float)x, (float)y, (float)cx, (float)cy); break;
			case 4: di += 2; _GRDPT(x, y); gfx_add_cmd(g, 0, (float)x, (float)y, 0, 0); break;
			case 5: di += 2; _GRDPT(x, y); gfx_add_cmd(g, 1, (float)x, (float)y, 0, 0); break;
			case 6:                                         // CUBIC -> flatten
			{
				double sx = g->pen_set ? g->pen_x : 0, sy = g->pen_set ? g->pen_y : 0;
				_GRDPT(cx, cy); _GRDPT(c2x, c2y); _GRDPT(x, y);
				const int N = 16;
				for (int s = 1; s <= N; s++)
				{
					double t = (double) s / N, u = 1 - t;
					double bx = u*u*u*sx + 3*u*u*t*cx + 3*u*t*t*c2x + t*t*t*x;
					double by = u*u*u*sy + 3*u*u*t*cy + 3*u*t*t*c2y + t*t*t*y;
					gfx_add_cmd(g, 1, (float) bx, (float) by, 0, 0);
				}
				break;
			}
			default: return;                                // unknown -> stop
		}
	}
	#undef _GRDPT
}

// Graphics.drawPath(commands:Vector.<int>, data:Vector.<Number>, winding:String)
static Avm2Value gfx_draw_path(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	const Avm2String* w = (act->argc > 2)
		? avm2_coerce_to_string(ctx, act->args[2])
		: avm2_string_from_literal(ctx, "evenOdd");
	if (!gfx_str_is(w, "evenOdd") && !gfx_str_is(w, "nonZero"))
		gfx_throw_2008(ctx, "winding");

	// process_commands: empty commands is a no-op even with odd data; otherwise
	// odd data.length is always #2004 (superfluous data included).
	Avm2VectorExt* commands = gfx_vec_arg(act, 0);
	Avm2VectorExt* data = gfx_vec_arg(act, 1);
	uint32_t ncmd = commands != NULL ? commands->length : 0;
	uint32_t ndata = data != NULL ? data->length : 0;
	if (ncmd == 0) return avm2_undefined();
	if ((ndata & 1u) != 0) gfx_throw_2004(ctx);
	// Part B: decode the command stream into pen commands (flushed on endFill).
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g != NULL) gfx_decode_path(g, ctx, commands, data);
	return avm2_undefined();
}

// Graphics.drawTriangles(vertices, indices, uvtData, culling) — bad culling is
// #2004 here (GraphicsTrianglePath's ctor reports the same as #2008).
static Avm2Value gfx_draw_triangles(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	const Avm2String* culling = (act->argc > 3)
		? avm2_coerce_to_string(ctx, act->args[3])
		: avm2_string_from_literal(ctx, "none");
	if (!gfx_str_is(culling, "none") && !gfx_str_is(culling, "positive")
	    && !gfx_str_is(culling, "negative"))
		gfx_throw_2004(ctx);
	Avm2VectorExt* verts = gfx_vec_arg(act, 0);
	Avm2VectorExt* indices = gfx_vec_arg(act, 1);
	gfx_validate_triangles(ctx, verts, indices);
	// Part B: build an explicit-triangle fill path (no tessellation) with the
	// current fill. Winding/culling honoured only as far as the fill covers.
	Avm2GraphicsExt* g = gfx_self_ext(act);
	if (g != NULL && g->cur_fill != 0 && verts != NULL)
		gfx_append_triangles(g, ctx, verts, indices);
	return avm2_undefined();
}

// Graphics.drawGraphicsData(graphicsData:Vector.<IGraphicsData>) — dispatch each
// IGraphicsData item. A GraphicsPath re-runs process_commands validation (#2004);
// its winding was validated at construction. Ruffle omits the inner drawPath /
// drawPathObject frames here (output.ruffle.txt), so a single drawGraphicsData
// frame is a subset of FP's trace => ruffle_matched.
static Avm2Value gfx_draw_graphics_data(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2VectorExt* items = gfx_vec_arg(act, 0);
	if (items == NULL) return avm2_undefined();
	for (uint32_t i = 0; i < items->length; i++)
	{
		Avm2Value it = items->elems[i];
		if (it.kind != AVM2_VALUE_OBJECT || it.u.obj == NULL) continue;
		Avm2Object* o = it.u.obj;
		if (o->cls == g_graphicspath_class)
		{
			Avm2VectorExt* cv = gfx_vec_prop(o, "commands", 8);
			Avm2VectorExt* dv = gfx_vec_prop(o, "data", 4);
			uint32_t ncmd = cv != NULL ? cv->length : 0;
			uint32_t ndata = dv != NULL ? dv->length : 0;
			if (ncmd != 0 && (ndata & 1u) != 0) gfx_throw_2004(ctx);
		}
		else if (o->cls == g_graphicstrianglepath_class)
		{
			gfx_validate_triangles(ctx, gfx_vec_prop(o, "vertices", 8),
			                       gfx_vec_prop(o, "indices", 7));
		}
		// GraphicsSolidFill / GraphicsGradientFill / GraphicsStroke / bitmap fills
		// set fill/stroke state (Part B); no Part-A validation error.
	}
	return avm2_undefined();
}

// GraphicsPath(commands = null, data = null, winding = "evenOdd"). Stores
// commands/data as public dynamic vars; validates winding inline (NOT via the
// `set winding` setter, so no "set winding" frame appears — matching FP's ctor
// trace of just Error$/throwError -> GraphicsPath()).
static Avm2Value graphicspath_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	avm2_object_set_dynamic(ctx, self, "commands", 8,
	                        act->argc > 0 ? act->args[0] : avm2_null());
	avm2_object_set_dynamic(ctx, self, "data", 4,
	                        act->argc > 1 ? act->args[1] : avm2_null());
	const Avm2String* w = (act->argc > 2)
		? avm2_coerce_to_string(ctx, act->args[2])
		: avm2_string_from_literal(ctx, "evenOdd");
	if (!gfx_str_is(w, "evenOdd") && !gfx_str_is(w, "nonZero"))
		gfx_throw_2008_via_throwerror(ctx, "winding");
	avm2_object_set_dynamic(ctx, self, "_winding", 8, avm2_string(w))->dont_enum = 1;
	return avm2_undefined();
}

// --- GraphicsPath's own path builders (Ruffle GraphicsPath.as:40-113) ------
// Each one lazily creates the two vectors, pushes ONE command id and its
// coordinates. The two "wide" variants exist purely so their record is the same
// width as curveTo's — the leading pair is arbitrary and ignored on consumption,
// which is why Ruffle pushes literal zeroes.

// Append to the `commands`/`data` dynamic slot, creating the Vector if the
// property is still null. `elem` is the builtin Vector.<T> class to mint.
static void gp_push(Avm2Activation* act, Avm2Object* self, const char* prop,
                    uint32_t plen, Avm2Class* vec_class, const Avm2Value* vals,
                    uint32_t n)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value* slot = avm2_object_find_dynamic(self, prop, plen);
	Avm2Object* vecobj = (slot != NULL && slot->kind == AVM2_VALUE_OBJECT)
		? slot->u.obj : NULL;
	if (vecobj == NULL || avm2_vector_ext(vecobj) == NULL)
	{
		vecobj = avm2_vector_new(ctx, vec_class, 0, 0);
		avm2_object_set_dynamic(ctx, self, prop, plen,
		                        avm2_object_value(vecobj));
	}
	// Re-read the ext each round: appending may reallocate the backing store.
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2VectorExt* vec = avm2_vector_ext(vecobj);
		if (vec == NULL) return;
		avm2_vector_set_index(ctx, vecobj, vec->length, vals[i]);
	}
}

// cmd id, then `n` coordinate arguments read straight off the activation.
static Avm2Value gp_emit(Avm2Activation* act, int cmd, const double* extra,
                         uint32_t nextra, uint32_t nargs)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	Avm2Value c = avm2_integer(cmd);
	gp_push(act, self, "commands", 8, act->ctx->builtins.vector_int_class,
	        &c, 1);
	Avm2Value data[6];
	uint32_t n = 0;
	for (uint32_t i = 0; i < nextra; i++) data[n++] = avm2_number(extra[i]);
	for (uint32_t i = 0; i < nargs && n < 6; i++)
	{
		data[n++] = avm2_number(avm2_coerce_to_number(act->ctx,
			i < act->argc ? act->args[i] : avm2_undefined()));
	}
	gp_push(act, self, "data", 4, act->ctx->builtins.vector_double_class,
	        data, n);
	return avm2_undefined();
}

static Avm2Value graphicspath_move_to(Avm2Activation* act)
{ return gp_emit(act, 1, NULL, 0, 2); }
static Avm2Value graphicspath_line_to(Avm2Activation* act)
{ return gp_emit(act, 2, NULL, 0, 2); }
static Avm2Value graphicspath_curve_to(Avm2Activation* act)
{ return gp_emit(act, 3, NULL, 0, 4); }
static Avm2Value graphicspath_cubic_curve_to(Avm2Activation* act)
{ return gp_emit(act, 6, NULL, 0, 6); }
static Avm2Value graphicspath_wide_move_to(Avm2Activation* act)
{ static const double z[2] = { 0, 0 }; return gp_emit(act, 4, z, 2, 2); }
static Avm2Value graphicspath_wide_line_to(Avm2Activation* act)
{ static const double z[2] = { 0, 0 }; return gp_emit(act, 5, z, 2, 2); }

static Avm2Value graphicspath_get_winding(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	Avm2Value* v = avm2_object_find_dynamic(self, "_winding", 8);
	return v != NULL ? *v : avm2_undefined();
}

static Avm2Value graphicspath_set_winding(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	const Avm2String* w = act->argc > 0
		? avm2_coerce_to_string(ctx, act->args[0])
		: avm2_string_from_literal(ctx, "");
	if (!gfx_str_is(w, "evenOdd") && !gfx_str_is(w, "nonZero"))
		gfx_throw_2008_via_throwerror(ctx, "winding");
	if (self != NULL)
		avm2_object_set_dynamic(ctx, self, "_winding", 8,
		                        avm2_string(w))->dont_enum = 1;
	return avm2_undefined();
}

// GraphicsTrianglePath(vertices, indices, uvtData, culling = "none"). Validates
// culling (#2008 "culling"); vertex/index validation happens at draw time.
static Avm2Value graphicstrianglepath_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	const Avm2String* culling = (act->argc > 3)
		? avm2_coerce_to_string(ctx, act->args[3])
		: avm2_string_from_literal(ctx, "none");
	if (!gfx_str_is(culling, "none") && !gfx_str_is(culling, "positive")
	    && !gfx_str_is(culling, "negative"))
		gfx_throw_2008(ctx, "culling");
	if (self != NULL)
	{
		avm2_object_set_dynamic(ctx, self, "vertices", 8,
		                        act->argc > 0 ? act->args[0] : avm2_null());
		avm2_object_set_dynamic(ctx, self, "indices", 7,
		                        act->argc > 1 ? act->args[1] : avm2_null());
		avm2_object_set_dynamic(ctx, self, "uvtData", 7,
		                        act->argc > 2 ? act->args[2] : avm2_null());
		avm2_object_set_dynamic(ctx, self, "culling", 7, avm2_string(culling));
	}
	return avm2_undefined();
}

// Register the T4 Graphics-drawing methods + data classes. `graphics` is the
// flash.display.Graphics class; `object_class` its base.
static void avm2_graphics_register(Avm2Context* ctx, Avm2Class* graphics,
                                   Avm2Class* object_class)
{
	avm2_builtin_add_method(ctx, graphics, "drawPath", gfx_draw_path);
	avm2_builtin_add_method(ctx, graphics, "drawTriangles", gfx_draw_triangles);
	avm2_builtin_add_method(ctx, graphics, "drawGraphicsData", gfx_draw_graphics_data);

	// IGraphicsData marker interface (Vector.<IGraphicsData> element coercion +
	// `is IGraphicsData`).
	Avm2Class* igd = avm2_builtin_class(ctx, "flash.display", "IGraphicsData", NULL);
	igd->flags |= AVM2_CLASS_FLAG_INTERFACE;
	g_igraphicsdata_class = igd;

	// Implementors declare the interface directly (native classes skip the ABC
	// mn-resolution path; avm2_class_has_interface reads the resolved cache).
	#define GFX_IMPLEMENTS_IGRAPHICSDATA(cls) do { \
		(cls)->interface_count = 1; \
		(cls)->interfaces = avm2_alloc(ctx, sizeof(Avm2Class*)); \
		(cls)->interfaces[0] = igd; \
	} while (0)

	Avm2Class* gp = avm2_builtin_class(ctx, "flash.display", "GraphicsPath",
	                                   object_class);
	gp->instance_init.fn = graphicspath_init;
	gp->instance_init.debug_name = "GraphicsPath";
	avm2_builtin_add_getset(ctx, gp, "winding", graphicspath_get_winding,
	                        graphicspath_set_winding);
	avm2_builtin_add_method(ctx, gp, "moveTo", graphicspath_move_to);
	avm2_builtin_add_method(ctx, gp, "lineTo", graphicspath_line_to);
	avm2_builtin_add_method(ctx, gp, "curveTo", graphicspath_curve_to);
	avm2_builtin_add_method(ctx, gp, "cubicCurveTo", graphicspath_cubic_curve_to);
	avm2_builtin_add_method(ctx, gp, "wideMoveTo", graphicspath_wide_move_to);
	avm2_builtin_add_method(ctx, gp, "wideLineTo", graphicspath_wide_line_to);
	GFX_IMPLEMENTS_IGRAPHICSDATA(gp);
	g_graphicspath_class = gp;

	Avm2Class* gtp = avm2_builtin_class(ctx, "flash.display",
	                                    "GraphicsTrianglePath", object_class);
	gtp->instance_init.fn = graphicstrianglepath_init;
	gtp->instance_init.debug_name = "GraphicsTrianglePath";
	GFX_IMPLEMENTS_IGRAPHICSDATA(gtp);
	g_graphicstrianglepath_class = gtp;

	// Fill / stroke IGraphicsData carriers — non-sealed so AS3 can set their
	// properties (colors/matrix/fill/...); Part B reads them. No ctor needed.
	const char* fills[3] = { "GraphicsSolidFill", "GraphicsGradientFill",
	                         "GraphicsStroke" };
	for (int i = 0; i < 3; i++)
	{
		Avm2Class* fc = avm2_builtin_class(ctx, "flash.display", fills[i],
		                                   object_class);
		GFX_IMPLEMENTS_IGRAPHICSDATA(fc);
	}
	#undef GFX_IMPLEMENTS_IGRAPHICSDATA

	// GraphicsPathCommand (int) + GraphicsPathWinding (string) constant holders.
	Avm2Class* gpc = avm2_builtin_class(ctx, "flash.display",
	                                    "GraphicsPathCommand", object_class);
	avm2_builtin_add_static_const(ctx, gpc, "NO_OP", avm2_integer(0));
	avm2_builtin_add_static_const(ctx, gpc, "MOVE_TO", avm2_integer(1));
	avm2_builtin_add_static_const(ctx, gpc, "LINE_TO", avm2_integer(2));
	avm2_builtin_add_static_const(ctx, gpc, "CURVE_TO", avm2_integer(3));
	avm2_builtin_add_static_const(ctx, gpc, "WIDE_MOVE_TO", avm2_integer(4));
	avm2_builtin_add_static_const(ctx, gpc, "WIDE_LINE_TO", avm2_integer(5));
	avm2_builtin_add_static_const(ctx, gpc, "CUBIC_CURVE_TO", avm2_integer(6));

	Avm2Class* gpw = avm2_builtin_class(ctx, "flash.display",
	                                    "GraphicsPathWinding", object_class);
	disp_sconst(ctx, gpw, "EVEN_ODD", "evenOdd");
	disp_sconst(ctx, gpw, "NON_ZERO", "nonZero");

	// TriangleCulling constants (imported by some tests; string values).
	Avm2Class* tc = avm2_builtin_class(ctx, "flash.display", "TriangleCulling",
	                                   object_class);
	disp_sconst(ctx, tc, "NONE", "none");
	disp_sconst(ctx, tc, "POSITIVE", "positive");
	disp_sconst(ctx, tc, "NEGATIVE", "negative");

	// CapsStyle / JointStyle — lineStyle's 6th and 7th arguments are compared
	// as strings, so the bags only have to exist (LineScaleMode already did).
	Avm2Class* caps = avm2_builtin_class(ctx, "flash.display", "CapsStyle",
	                                     object_class);
	disp_sconst(ctx, caps, "NONE", "none");
	disp_sconst(ctx, caps, "ROUND", "round");
	disp_sconst(ctx, caps, "SQUARE", "square");

	Avm2Class* joint = avm2_builtin_class(ctx, "flash.display", "JointStyle",
	                                      object_class);
	disp_sconst(ctx, joint, "BEVEL", "bevel");
	disp_sconst(ctx, joint, "MITER", "miter");
	disp_sconst(ctx, joint, "ROUND", "round");

	// The two remaining IGraphicsData carriers. GraphicsBitmapFill/
	// GraphicsEndFill sit in the same drawGraphicsData stream as the three
	// registered above, so they get the same non-sealed shape + marker.
	const char* more_fills[2] = { "GraphicsBitmapFill", "GraphicsEndFill" };
	for (int i = 0; i < 2; i++)
	{
		Avm2Class* fc = avm2_builtin_class(ctx, "flash.display", more_fills[i],
		                                   object_class);
		fc->interface_count = 1;
		fc->interfaces = avm2_alloc(ctx, sizeof(Avm2Class*));
		fc->interfaces[0] = igd;
	}
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

// ---------------------------------------------------------------------------
// flash.geom.Vector3D — a direct port of Ruffle's geom/Vector3D.as
// ---------------------------------------------------------------------------
// x/y/z/w are dynamic props (Matrix3D's copyRow/copyColumnFrom and
// setProgramConstantsFromMatrix already read them by name). Almost every
// mutator here deliberately leaves `w` ALONE — only the constructor, clone and
// crossProduct write it — and crossProduct always sets it to 1. nearEquals
// carries a Flash Player bug Ruffle documents and replicates: with allFour it
// compares the OTHER vector's raw w against the tolerance instead of the
// difference.

static Avm2Class* g_vector3d_class;

static double v3_get(Avm2Context* ctx, Avm2Object* o, const char* n)
{
	if (o == NULL) return 0.0;
	Avm2Value* v = avm2_object_find_dynamic(o, n, 1);
	return v != NULL ? avm2_coerce_to_number(ctx, *v) : 0.0;
}

static void v3_set(Avm2Context* ctx, Avm2Object* o, const char* n, double d)
{
	if (o != NULL) avm2_object_set_dynamic(ctx, o, n, 1, avm2_number(d));
}

static Avm2Object* v3_self(Avm2Activation* act)
{
	return this_obj(act);
}

// Argument 0 as an object; null/undefined yields NULL and every component
// then reads 0, which is what an untyped `null` coerces to in the .as body.
static Avm2Object* v3_arg(Avm2Activation* act, uint32_t i)
{
	return (act->argc > i && act->args[i].kind == AVM2_VALUE_OBJECT)
		? act->args[i].u.obj : NULL;
}

static Avm2Value v3_make(Avm2Context* ctx, double x, double y, double z, double w)
{
	Avm2Value a[4] = { avm2_number(x), avm2_number(y), avm2_number(z),
	                   avm2_number(w) };
	return avm2_class_construct(ctx, g_vector3d_class, a, 4);
}

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
		avm2_object_set_dynamic(ctx, self, n[i], 1, avm2_number(v));
	}
	return avm2_undefined();
}

static double v3_length_squared(Avm2Context* ctx, Avm2Object* o)
{
	double x = v3_get(ctx, o, "x"), y = v3_get(ctx, o, "y"),
	       z = v3_get(ctx, o, "z");
	return x * x + y * y + z * z;
}

static Avm2Value v3_get_length(Avm2Activation* act)
{
	return avm2_number(sqrt(v3_length_squared(act->ctx, v3_self(act))));
}

static Avm2Value v3_get_length_squared(Avm2Activation* act)
{
	return avm2_number(v3_length_squared(act->ctx, v3_self(act)));
}

static Avm2Value v3_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act);
	char n[3][40];
	avm2_format_number(n[0], sizeof(n[0]), v3_get(ctx, s, "x"));
	avm2_format_number(n[1], sizeof(n[1]), v3_get(ctx, s, "y"));
	avm2_format_number(n[2], sizeof(n[2]), v3_get(ctx, s, "z"));
	char buf[160];
	snprintf(buf, sizeof(buf), "Vector3D(%s, %s, %s)", n[0], n[1], n[2]);
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

// add/subtract drop w (the result's w is 0, not either operand's).
static Avm2Value v3_add(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	return v3_make(ctx, v3_get(ctx, s, "x") + v3_get(ctx, a, "x"),
	                    v3_get(ctx, s, "y") + v3_get(ctx, a, "y"),
	                    v3_get(ctx, s, "z") + v3_get(ctx, a, "z"), 0);
}

static Avm2Value v3_subtract(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	return v3_make(ctx, v3_get(ctx, s, "x") - v3_get(ctx, a, "x"),
	                    v3_get(ctx, s, "y") - v3_get(ctx, a, "y"),
	                    v3_get(ctx, s, "z") - v3_get(ctx, a, "z"), 0);
}

static Avm2Value v3_increment_by(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	v3_set(ctx, s, "x", v3_get(ctx, s, "x") + v3_get(ctx, a, "x"));
	v3_set(ctx, s, "y", v3_get(ctx, s, "y") + v3_get(ctx, a, "y"));
	v3_set(ctx, s, "z", v3_get(ctx, s, "z") + v3_get(ctx, a, "z"));
	return avm2_undefined();
}

static Avm2Value v3_decrement_by(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	v3_set(ctx, s, "x", v3_get(ctx, s, "x") - v3_get(ctx, a, "x"));
	v3_set(ctx, s, "y", v3_get(ctx, s, "y") - v3_get(ctx, a, "y"));
	v3_set(ctx, s, "z", v3_get(ctx, s, "z") - v3_get(ctx, a, "z"));
	return avm2_undefined();
}

static Avm2Value v3_clone(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act);
	return v3_make(ctx, v3_get(ctx, s, "x"), v3_get(ctx, s, "y"),
	               v3_get(ctx, s, "z"), v3_get(ctx, s, "w"));
}

static Avm2Value v3_copy_from(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	v3_set(ctx, s, "x", v3_get(ctx, a, "x"));
	v3_set(ctx, s, "y", v3_get(ctx, a, "y"));
	v3_set(ctx, s, "z", v3_get(ctx, a, "z"));
	return avm2_undefined();
}

static Avm2Value v3_equals(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	int all_four = act->argc > 1 && avm2_coerce_to_boolean(act->args[1]);
	int eq = v3_get(ctx, s, "x") == v3_get(ctx, a, "x")
	      && v3_get(ctx, s, "y") == v3_get(ctx, a, "y")
	      && v3_get(ctx, s, "z") == v3_get(ctx, a, "z")
	      && (!all_four || v3_get(ctx, s, "w") == v3_get(ctx, a, "w"));
	return avm2_bool(eq);
}

static Avm2Value v3_near_equals(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	double tol = act->argc > 1 ? avm2_coerce_to_number(ctx, act->args[1]) : 0.0;
	int all_four = act->argc > 2 && avm2_coerce_to_boolean(act->args[2]);
	int eq = fabs(v3_get(ctx, s, "x") - v3_get(ctx, a, "x")) < tol
	      && fabs(v3_get(ctx, s, "y") - v3_get(ctx, a, "y")) < tol
	      && fabs(v3_get(ctx, s, "z") - v3_get(ctx, a, "z")) < tol
	      // FP BUG (replicated): the w arm forgets the subtraction.
	      && (!all_four || fabs(v3_get(ctx, a, "w")) < tol);
	return avm2_bool(eq);
}

static Avm2Value v3_set_to(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act);
	static const char* const n[3] = { "x", "y", "z" };
	for (int i = 0; i < 3; i++)
	{
		v3_set(ctx, s, n[i], avm2_coerce_to_number(ctx,
			(uint32_t) i < act->argc ? act->args[i] : avm2_undefined()));
	}
	return avm2_undefined();
}

static Avm2Value v3_scale_by(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act);
	double k = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0.0;
	v3_set(ctx, s, "x", v3_get(ctx, s, "x") * k);
	v3_set(ctx, s, "y", v3_get(ctx, s, "y") * k);
	v3_set(ctx, s, "z", v3_get(ctx, s, "z") * k);
	return avm2_undefined();
}

static Avm2Value v3_negate(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act);
	v3_set(ctx, s, "x", v3_get(ctx, s, "x") * -1.0);
	v3_set(ctx, s, "y", v3_get(ctx, s, "y") * -1.0);
	v3_set(ctx, s, "z", v3_get(ctx, s, "z") * -1.0);
	return avm2_undefined();
}

static Avm2Value v3_project(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act);
	double w = v3_get(ctx, s, "w");
	v3_set(ctx, s, "x", v3_get(ctx, s, "x") / w);
	v3_set(ctx, s, "y", v3_get(ctx, s, "y") / w);
	v3_set(ctx, s, "z", v3_get(ctx, s, "z") / w);
	return avm2_undefined();
}

// normalize() returns the ORIGINAL length. A zero length zeroes the vector; a
// NaN length (i.e. any NaN component) makes all three NaN — the `else` arm of
// the .as, which `len > 0` deliberately falls through to.
static Avm2Value v3_normalize(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act);
	double len = sqrt(v3_length_squared(ctx, s));
	if (len == 0)
	{
		v3_set(ctx, s, "x", 0); v3_set(ctx, s, "y", 0); v3_set(ctx, s, "z", 0);
	}
	else if (len > 0)
	{
		v3_set(ctx, s, "x", v3_get(ctx, s, "x") / len);
		v3_set(ctx, s, "y", v3_get(ctx, s, "y") / len);
		v3_set(ctx, s, "z", v3_get(ctx, s, "z") / len);
	}
	else
	{
		double nan = (double) NAN;
		v3_set(ctx, s, "x", nan); v3_set(ctx, s, "y", nan);
		v3_set(ctx, s, "z", nan);
	}
	return avm2_number(len);
}

static Avm2Value v3_dot_product(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	return avm2_number(v3_get(ctx, s, "x") * v3_get(ctx, a, "x")
	                 + v3_get(ctx, s, "y") * v3_get(ctx, a, "y")
	                 + v3_get(ctx, s, "z") * v3_get(ctx, a, "z"));
}

static Avm2Value v3_cross_product(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* s = v3_self(act), *a = v3_arg(act, 0);
	double sx = v3_get(ctx, s, "x"), sy = v3_get(ctx, s, "y"),
	       sz = v3_get(ctx, s, "z");
	double ax = v3_get(ctx, a, "x"), ay = v3_get(ctx, a, "y"),
	       az = v3_get(ctx, a, "z");
	// w is always 1 here, "for whatever reason" (Ruffle's own note).
	return v3_make(ctx, sy * az - sz * ay, sz * ax - sx * az,
	               sx * ay - sy * ax, 1);
}

static Avm2Value v3_angle_between(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* a = v3_arg(act, 0), *b = v3_arg(act, 1);
	double dot = v3_get(ctx, a, "x") * v3_get(ctx, b, "x")
	           + v3_get(ctx, a, "y") * v3_get(ctx, b, "y")
	           + v3_get(ctx, a, "z") * v3_get(ctx, b, "z");
	double la = sqrt(v3_length_squared(ctx, a));
	double lb = sqrt(v3_length_squared(ctx, b));
	return avm2_number(acos(dot / (la * lb)));
}

static Avm2Value v3_distance(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* p1 = v3_arg(act, 0), *p2 = v3_arg(act, 1);
	double dx = v3_get(ctx, p2, "x") - v3_get(ctx, p1, "x");
	double dy = v3_get(ctx, p2, "y") - v3_get(ctx, p1, "y");
	double dz = v3_get(ctx, p2, "z") - v3_get(ctx, p1, "z");
	return avm2_number(sqrt(dx * dx + dy * dy + dz * dz));
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
	// Ruffle avm2/globals/flash/geom/transform.rs:87. NOTE: only the Transform
	// object's own matrix= setter marks; DisplayObject.transform = ... writes
	// the matrix directly and does NOT mark (see do_set_transform).
	mark_transformed_by_script(ext);
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
// flash.geom.Vector3D. avm2_stage3d.c's Matrix3D constructs one for `position`
// / transformVector, and avm2_builtin_class always MINTS a class rather than
// looking one up, so the handle has to be shared rather than re-registered.
// (Declared just above the Vector3D method bodies, which need it for v3_make.)

Avm2Class* avm2_geom_vector3d_class(void)
{ return g_vector3d_class; }

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

// ColorTransform.color (Ruffle geom/ColorTransform.as:47-58): reads the three
// offsets packed as RGB; writing it zeroes the RGB multipliers and rewrites the
// offsets, so the object becomes a flat tint. The class is SEALED, so without
// the accessor `ct.color = n` raised #1056 instead.
static Avm2Value colortransform_get_color(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->slot_count < 9) return avm2_undefined();
	Avm2Context* ctx = act->ctx;
	uint32_t r = avm2_coerce_to_u32(ctx, self->slots[5]);
	uint32_t g = avm2_coerce_to_u32(ctx, self->slots[6]);
	uint32_t b = avm2_coerce_to_u32(ctx, self->slots[7]);
	return avm2_uint_value(((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

static Avm2Value colortransform_set_color(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->slot_count < 9 || act->argc < 1)
		return avm2_undefined();
	uint32_t c = avm2_coerce_to_u32(act->ctx, act->args[0]);
	self->slots[1] = avm2_integer(0);
	self->slots[2] = avm2_integer(0);
	self->slots[3] = avm2_integer(0);
	self->slots[5] = avm2_uint_value((c >> 16) & 0xFF);
	self->slots[6] = avm2_uint_value((c >> 8) & 0xFF);
	self->slots[7] = avm2_uint_value(c & 0xFF);
	return avm2_undefined();
}

// concat(second): Ruffle geom/ColorTransform.as:60 — offsets pick up the
// receiver's multiplier scaling first, then the multipliers compose.
static Avm2Value colortransform_concat(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2Value sv = act->argc > 0 ? act->args[0] : avm2_undefined();
	if (self == NULL || self->slot_count < 9 || sv.kind != AVM2_VALUE_OBJECT
	    || sv.u.obj == NULL || sv.u.obj->slot_count < 9)
	{
		return avm2_undefined();
	}
	Avm2Object* o = sv.u.obj;
	// slots 1-4 multipliers (r,g,b,a), 5-8 offsets (r,g,b,a).
	for (int i = 0; i < 4; i++)
	{
		double mul = avm2_coerce_to_number(ctx, self->slots[1 + i]);
		double off = avm2_coerce_to_number(ctx, self->slots[5 + i]);
		double omul = avm2_coerce_to_number(ctx, o->slots[1 + i]);
		double ooff = avm2_coerce_to_number(ctx, o->slots[5 + i]);
		self->slots[5 + i] = avm2_number(off + mul * ooff);
		self->slots[1 + i] = avm2_number(mul * omul);
	}
	return avm2_undefined();
}

// Fixed8 (Ruffle Fixed8::from_f64: multiply then saturate to i16).
static int16_t to_fixed8(double v)
{
	double s = v * 256.0;
	if (isnan(s)) return 0;
	if (s >= 32767.0) return 32767;
	if (s <= -32768.0) return -32768;
	return (int16_t) s;
}

static int16_t to_i16_trunc(double v)
{
	if (isnan(v)) return 0;
	if (v >= 32767.0) return 32767;
	if (v <= -32768.0) return -32768;
	return (int16_t) v;
}

static Avm2Value transform_get_color_transform(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2DisplayObjectExt* ext = NULL;
	if (self != NULL && self->native_ext != NULL)
	{
		Avm2TransformExt* text = self->native_ext;
		if (text->target != NULL) ext = avm2_display_ext_of(ctx, text->target);
	}
	if (ext == NULL)
	{
		return avm2_class_construct(ctx, g_colortransform_class, NULL, 0);
	}
	Avm2Value args[8] = {
		avm2_number((double) ext->cx_rm / 256.0),
		avm2_number((double) ext->cx_gm / 256.0),
		avm2_number((double) ext->cx_bm / 256.0),
		avm2_number((double) ext->alpha_fixed8 / 256.0),
		avm2_number(ext->cx_ra), avm2_number(ext->cx_ga),
		avm2_number(ext->cx_ba), avm2_number(ext->cx_aa),
	};
	return avm2_class_construct(ctx, g_colortransform_class, args, 8);
}

// Ruffle Transform.as: concatenatedColorTransform is a stub that hands back a
// fresh identity ColorTransform, NOT the concatenation up the parent chain.
static Avm2Value transform_get_concat_color_transform(Avm2Activation* act)
{
	return avm2_class_construct(act->ctx, g_colortransform_class, NULL, 0);
}

static Avm2Value transform_set_color_transform(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL || act->argc < 1)
	{
		return avm2_undefined();
	}
	Avm2TransformExt* text = self->native_ext;
	if (text->target == NULL) return avm2_undefined();
	Avm2Value v = act->args[0];
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL
	    || v.u.obj->slot_count < 9)
	{
		return avm2_undefined();
	}
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, text->target);
	if (ext == NULL) return avm2_undefined();
	// Ruffle avm2/globals/flash/geom/transform.rs:50 (same asymmetry as
	// matrix=: DisplayObject.transform = ... does NOT mark).
	mark_transformed_by_script(ext);
	Avm2Object* ct = v.u.obj;
	ext->cx_rm = to_fixed8(avm2_coerce_to_number(ctx, ct->slots[1]));
	ext->cx_gm = to_fixed8(avm2_coerce_to_number(ctx, ct->slots[2]));
	ext->cx_bm = to_fixed8(avm2_coerce_to_number(ctx, ct->slots[3]));
	ext->alpha_fixed8 = to_fixed8(avm2_coerce_to_number(ctx, ct->slots[4]));
	ext->cx_ra = to_i16_trunc(avm2_coerce_to_number(ctx, ct->slots[5]));
	ext->cx_ga = to_i16_trunc(avm2_coerce_to_number(ctx, ct->slots[6]));
	ext->cx_ba = to_i16_trunc(avm2_coerce_to_number(ctx, ct->slots[7]));
	ext->cx_aa = to_i16_trunc(avm2_coerce_to_number(ctx, ct->slots[8]));
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

// --- flash.geom.PerspectiveProjection ---------------------------------------
// Ruffle render/src/perspective_projection.rs: fov 55 degrees, centre (250,250),
// and a focal length derived from the projection width — 500 when the object is
// the stage or has no display object, otherwise the stage width. toMatrix3D
// builds a bare projection matrix from that focal length.
//
// transform.perspectiveProjection is NON-NULL for the stage and the root and
// null for every other object (perspective_projection_basic grades exactly
// that). Assigning null does not make the stage's null — the getter simply
// re-mints the default — so "assign null" is stored as "no override".

static Avm2Class* g_pperspective_class;

static double pp_slot(Avm2Context* ctx, Avm2Object* o, const char* n,
                      uint32_t nlen, double dflt)
{
	Avm2Value* v = o != NULL ? avm2_object_find_dynamic(o, n, nlen) : NULL;
	return v != NULL ? avm2_coerce_to_number(ctx, *v) : dflt;
}

// The projection width: 500 unless the object is a non-stage DisplayObject,
// in which case it is the stage width.
static double pp_width(Avm2Activation* act, Avm2Object* self)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value* t = self != NULL
		? avm2_object_find_dynamic(self, "__target", 8) : NULL;
	if (t == NULL || t->kind != AVM2_VALUE_OBJECT) return 500.0;
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, t->u.obj);
	if (ext == NULL || ext->is_stage) return 500.0;
	return (double) ((avm2_generated_stage_rect[1]
	                  - avm2_generated_stage_rect[0]) / 20);
}

static double pp_focal_length(Avm2Activation* act, Avm2Object* self)
{
	double fov = pp_slot(act->ctx, self, "__fov", 5, 55.0);
	double rad = fov * (M_PI / 180.0);
	// Ruffle computes this half in f32 (`... as f32`), so keep the cast.
	return (double) (float) ((pp_width(act, self) / 2.0) * tan((M_PI - rad) / 2.0));
}

static Avm2Value pp_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL) return avm2_undefined();
	avm2_object_set_dynamic(ctx, self, "__fov", 5, avm2_number(55.0))
		->dont_enum = 1;
	avm2_object_set_dynamic(ctx, self, "__cx", 4, avm2_number(250.0))
		->dont_enum = 1;
	avm2_object_set_dynamic(ctx, self, "__cy", 4, avm2_number(250.0))
		->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value pp_get_fov(Avm2Activation* act)
{
	return avm2_number(pp_slot(act->ctx, this_obj(act), "__fov", 5, 55.0));
}

static Avm2Value pp_set_fov(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	double fov = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0.0;
	if (fov <= 0.0 || fov >= 180.0)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2182: Invalid fieldOfView value.  The value "
		                 "must be greater than 0 and less than 180.");
	}
	if (self != NULL)
		avm2_object_set_dynamic(ctx, self, "__fov", 5, avm2_number(fov))
			->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value pp_get_focal_length(Avm2Activation* act)
{
	return avm2_number(pp_focal_length(act, this_obj(act)));
}

static Avm2Value pp_set_focal_length(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	double fl = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0.0;
	if (fl <= 0.0)
	{
		char buf[128];
		char num[40];
		avm2_format_number(num, sizeof(num), fl);
		snprintf(buf, sizeof(buf),
		         "Error #2186: Invalid focalLength %s.", num);
		avm2_throw_error(ctx, ctx->builtins.argument_error_class, buf);
	}
	double fov = atan((pp_width(act, self) / 2.0) / fl) / (M_PI / 180.0) * 2.0;
	if (self != NULL)
		avm2_object_set_dynamic(ctx, self, "__fov", 5, avm2_number(fov))
			->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value pp_get_center(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	extern Avm2Class* avm2_display_point_class(Avm2Context* ctx);
	Avm2Value a[2] = { avm2_number(pp_slot(ctx, self, "__cx", 4, 250.0)),
	                   avm2_number(pp_slot(ctx, self, "__cy", 4, 250.0)) };
	return avm2_class_construct(ctx, avm2_display_point_class(ctx), a, 2);
}

static Avm2Value pp_set_center(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2Value p = act->argc > 0 ? act->args[0] : avm2_undefined();
	if (self == NULL) return avm2_undefined();
	double x = avm2_coerce_to_number(ctx,
		avm2_get_public_property(ctx, p, "x", 1, NULL));
	double y = avm2_coerce_to_number(ctx,
		avm2_get_public_property(ctx, p, "y", 1, NULL));
	avm2_object_set_dynamic(ctx, self, "__cx", 4, avm2_number(x))->dont_enum = 1;
	avm2_object_set_dynamic(ctx, self, "__cy", 4, avm2_number(y))->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value pp_to_matrix3d(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double fl = pp_focal_length(act, this_obj(act));
	extern Avm2Class* avm2_stage3d_matrix3d_class(void);
	Avm2Class* m3d = avm2_stage3d_matrix3d_class();
	if (m3d == NULL) return avm2_null();
	static const int kOnes[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
	                               0, 0, 0, 0 };
	Avm2Object* raw = avm2_vector_new(ctx, ctx->builtins.vector_double_class,
	                                  0, 0);
	for (int i = 0; i < 16; i++)
	{
		double d = (i == 0 || i == 5) ? fl : (double) kOnes[i];
		avm2_vector_set_index(ctx, raw, (uint32_t) i, avm2_number(d));
	}
	Avm2Value arg = avm2_object_value(raw);
	return avm2_class_construct(ctx, m3d, &arg, 1);
}

// transform.perspectiveProjection: the override stored on the target, else a
// freshly minted default for the stage/root, else null.
static Avm2Value transform_get_perspective_projection(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL || g_pperspective_class == NULL)
		return avm2_null();
	Avm2Object* target = ((Avm2TransformExt*) self->native_ext)->target;
	if (target == NULL) return avm2_null();
	Avm2Value* stored = avm2_object_find_dynamic(target, "__pproj", 7);
	if (stored != NULL && stored->kind == AVM2_VALUE_OBJECT) return *stored;
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, target);
	if (ext == NULL || (!ext->is_stage && !ext->is_root)) return avm2_null();
	Avm2Value pp = avm2_class_construct(ctx, g_pperspective_class, NULL, 0);
	if (pp.kind == AVM2_VALUE_OBJECT)
	{
		avm2_object_set_dynamic(ctx, pp.u.obj, "__target", 8,
		                        avm2_object_value(target))->dont_enum = 1;
	}
	return pp;
}

static Avm2Value transform_set_perspective_projection(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	if (self == NULL || self->native_ext == NULL) return avm2_undefined();
	Avm2Object* target = ((Avm2TransformExt*) self->native_ext)->target;
	if (target == NULL) return avm2_undefined();
	Avm2Value v = act->argc > 0 ? act->args[0] : avm2_null();
	if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL)
	{
		avm2_object_set_dynamic(ctx, v.u.obj, "__target", 8,
		                        avm2_object_value(target))->dont_enum = 1;
		avm2_object_set_dynamic(ctx, target, "__pproj", 7, v)->dont_enum = 1;
	}
	else
	{
		// "No override" — the stage/root getter then re-mints its default,
		// while a plain object goes back to null.
		avm2_object_set_dynamic(ctx, target, "__pproj", 7, avm2_null())
			->dont_enum = 1;
	}
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

// cacheAsBitmap's GETTER is is_bitmap_cached(), not the stored preference:
// a non-empty filter list forces it true (display_object.rs
// recheck_cache_as_bitmap). The setter only records the preference.
static Avm2Value do_cab_get(Avm2Activation* act)
{
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext != NULL && ext->filter_count > 0) return avm2_bool(true);
	return dyn_prop_get(act, "__cacheAsBitmap", avm2_bool(false));
}
static Avm2Value do_cab_set(Avm2Activation* act)
{
	dyn_prop_set(act, "__cacheAsBitmap");
	return avm2_undefined();
}
// `opaqueBackground` is declared `Object`, so assigning UNDEFINED stores the
// AS3 coercion of undefined to Object — null — and reads back as `null`, not
// `undefined` (displayobject_opaque_background's third read).
static Avm2Value do_opaquebg_get(Avm2Activation* act)
{
	return dyn_prop_get(act, "__opaqueBackground", avm2_null());
}
static Avm2Value do_opaquebg_set(Avm2Activation* act)
{
	Avm2Object* self = this_obj(act);
	if (self != NULL)
	{
		Avm2Value v = (act->argc > 0) ? act->args[0] : avm2_undefined();
		if (v.kind == AVM2_VALUE_UNDEFINED) v = avm2_null();
		avm2_object_set_dynamic(act->ctx, self, "__opaqueBackground",
		                        (uint32_t) strlen("__opaqueBackground"),
		                        v)->dont_enum = 1;
	}
	return avm2_undefined();
}
// scale9Grid keeps the old dyn-prop stub. It used to SHARE the scrollRect
// accessors, which would now have made a scale9Grid assignment resize the
// object's bounds.
STUB_GETSET(do_scale9grid, "__scale9Grid", avm2_null())

// scrollRect. Ruffle object_to_rectangle: x/y and x+width/y+height are each
// rounded to a whole PIXEL, half-to-even, before becoming twips — which is why
// Rectangle(2.2, 2.2, 0.3, 0.3) reads back as (x=2, y=2, w=0, h=0). Stored as
// the committed rect; Flash's one-frame delay before localToGlobal and hit
// tests see it is NOT modelled (nothing here consults it but the bounds).
static double round_half_to_even(double v)
{
	double r = nearbyint(v);           // FE_TONEAREST == half-to-even
	if (!isfinite(v)) return 0;
	return r;
}

static Avm2Value do_scrollrect_get(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL || !ext->has_scroll_rect) return avm2_null();
	extern Avm2Value avm2_text_new_rectangle(Avm2Context* ctx, double x, double y,
	                                         double w, double h);
	return avm2_text_new_rectangle(ctx, ext->sr_xmin / 20.0, ext->sr_ymin / 20.0,
	                               (ext->sr_xmax - ext->sr_xmin) / 20.0,
	                               (ext->sr_ymax - ext->sr_ymin) / 20.0);
}

static Avm2Value do_scrollrect_set(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DisplayObjectExt* ext = this_display(act);
	if (ext == NULL) return avm2_undefined();
	Avm2Value v = (act->argc > 0) ? act->args[0] : avm2_undefined();
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL
	    || v.u.obj->slot_count < 5)
	{
		ext->has_scroll_rect = 0;
		return avm2_undefined();
	}
	Avm2Object* r = v.u.obj;
	double x = avm2_coerce_to_number(ctx, r->slots[1]);
	double y = avm2_coerce_to_number(ctx, r->slots[2]);
	double w = avm2_coerce_to_number(ctx, r->slots[3]);
	double h = avm2_coerce_to_number(ctx, r->slots[4]);
	ext->sr_xmin = (int32_t) round_half_to_even(x) * 20;
	ext->sr_ymin = (int32_t) round_half_to_even(y) * 20;
	ext->sr_xmax = (int32_t) round_half_to_even(x + w) * 20;
	ext->sr_ymax = (int32_t) round_half_to_even(y + h) * 20;
	ext->has_scroll_rect = 1;
	return avm2_undefined();
}
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
static Avm2Value do_blendmode_get(Avm2Activation* act)
{
	return dyn_prop_get(act, "__blendMode",
	                    avm2_string(avm2_string_from_literal(act->ctx, "normal")));
}

// Assigning a name outside ExtendedBlendMode throws ArgumentError #2008 and
// leaves the old value in place (display_object.rs set_blend_mode); null or
// undefined is the earlier #2007 non-null check.
static Avm2Value do_blendmode_set(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value v = (act->argc > 0) ? act->args[0] : avm2_undefined();
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter blendMode must be non-null.");
	}
	const Avm2String* s = avm2_coerce_to_string(ctx, v);
	static const char* const known[] = {
		"normal", "layer", "multiply", "screen", "lighten", "darken",
		"difference", "add", "subtract", "invert", "alpha", "erase",
		"overlay", "hardlight", "shader",
	};
	int ok = 0;
	for (size_t i = 0; i < sizeof(known) / sizeof(known[0]); i++)
	{
		if (gfx_str_is(s, known[i])) { ok = 1; break; }
	}
	if (!ok)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2008: Parameter blendMode must be one of "
		                 "the accepted values.");
	}
	Avm2Object* self = this_obj(act);
	if (self != NULL)
	{
		avm2_object_set_dynamic(ctx, self, "__blendMode", 11,
		                        avm2_string(s))->dont_enum = 1;
	}
	return avm2_undefined();
}

// blendShader is write-only in DisplayObject.as. Assigning a usable Shader
// also flips blendMode to "shader" (display_object.rs:2108-2111), and that
// survives a later blendMode change — we only have to model the flip, since
// nothing reads the shader back.
static Avm2Value do_blendshader_set(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value v = (act->argc > 0) ? act->args[0] : avm2_undefined();
	if (v.kind != AVM2_VALUE_OBJECT)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter shader must be non-null.");
	}
	if (avm2_shader_blend_state(v) != 2)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter data must be non-null.");
	}
	Avm2Object* self = this_obj(act);
	if (self != NULL)
	{
		avm2_object_set_dynamic(ctx, self, "__blendMode", 11,
			avm2_string(avm2_string_from_literal(ctx, "shader")))->dont_enum = 1;
	}
	return avm2_undefined();
}

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
		// A button record's character is placed exactly like a timeline
		// child, so it needs the SAME place-time resolution (place_child /
		// replace_child_character both do both halves). Without the shape
		// half a DefineShape state child ends up with shape_vert_count 0 and
		// the render walk has nothing to draw — which is why every
		// DefineButton2 in the corpus rendered blank even once the walk arm
		// existed.
		resolve_shape_geom(cext, rec->char_id);
		resolve_static_text(cext, rec->char_id);
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
		mark_attached(ctx, cext, button);
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
	mark_attached(ctx, wext, button);
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, children[i]);
		replace_at_depth(ctx, wext, children[i], cext->depth);
		// Construction happens while parent is the BUTTON (a
		// non-container), so `parent` reads null from the ctor
		// (simplebutton_childprops); the wrapper becomes parent after.
		cext->parent = button;
		mark_attached(ctx, cext, button);
		set_default_instance_name(ctx, cext);
		enter_frame_obj(ctx, children[i]);
		construct_frame_obj(ctx, children[i]);
		cext->parent = wrapper;
		mark_attached(ctx, cext, wrapper);
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
		mark_attached(ctx, sext, old_parent);
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
		mark_attached(ctx, uext, button);
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
	// Only the child for the button's CURRENT state is parented to the button
	// and gets the added/removed + framescript broadcasts (Ruffle
	// set_state_child). Without mouse input btn_state never leaves Up, so this
	// is btn_up in every trace test; hitTestState is never "current".
	static const size_t cur_off[3] = {
		offsetof(Avm2DisplayObjectExt, btn_up),
		offsetof(Avm2DisplayObjectExt, btn_over),
		offsetof(Avm2DisplayObjectExt, btn_down),
	};
	int is_cur_state = (off == cur_off[ext->btn_state < 3 ? ext->btn_state : 0]);
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
			mark_attached(ctx, vext, button);
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

// --- SimpleButton state machine (Ruffle avm2_button.rs set_state/:279-288) ---
//
// Swap which state child the button paints and measures. NOTHING moves into or
// out of a render list: a SimpleButton is not a container, and the passing
// numChildren/getChildAt/parent tests (simplebutton_structure, _childshuffle,
// _childprops, _multi_children) depend on it staying one. Only `parent`
// bookkeeping moves, exactly as Ruffle's set_state does — the render walks key
// off btn_up/btn_over/btn_down via avm2_button_state_child, never off parent.
//
// Deviation from Ruffle, deliberate: Ruffle's all_state_children() also clears
// hitTestState's parent here. Ours leaves btn_hit alone — button_create_state
// parents every timeline state child to the button, run_mouse_pick and
// obj_highlight_bounds both read btn_hit, and no corpus test observes
// hitTestState.parent. Changing it would be churn with no yield.
static void button_set_state(Avm2Context* ctx, Avm2Object* button, uint8_t st)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, button);
	if (ext == NULL || ext->btn_state == st) return;
	ext->btn_state = st;
	Avm2Object* all[3] = { ext->btn_up, ext->btn_over, ext->btn_down };
	for (int i = 0; i < 3; i++)
	{
		if (all[i] == NULL) continue;
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, all[i]);
		if (e != NULL && e->parent == button) e->parent = NULL;
	}
	Avm2Object* cur = avm2_button_state_child(ext);
	if (cur != NULL)
	{
		Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, cur);
		if (e != NULL)
		{
			e->parent = button;
			mark_attached(ctx, e, button);
		}
	}
}

// Ruffle avm2_button.rs::event_dispatch's clip-event -> ButtonState table
// (:736-743). Called at the six dispatch points in update_mouse_state, each
// time BEFORE the matching AVM2 event goes out, mirroring Ruffle's
// handle_clip_event-then-event_dispatch_to_avm2 order. No-op on anything that
// is not a SimpleButton, and on a button whose state does not actually change.
#define BTN_ST_UP    0
#define BTN_ST_OVER  1
#define BTN_ST_DOWN  2
static void button_clip_state(Avm2Context* ctx, Avm2Object* obj, uint8_t st)
{
	if (obj == NULL || obj->cls == NULL) return;
	if (!class_is_a(obj->cls, ctx->builtins.simple_button_class)) return;
	button_set_state(ctx, obj, st);
}

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


// Stage.tabChildren is a write-through proxy, not storage (Ruffle Stage.as:169
// + stage.rs::set_tab_children): the getter is hardcoded true, and the setter
// forwards the value to the AVM2 root. So `stage.tabChildren = false` leaves
// stage.tabChildren === true and makes root.tabChildren === false.
static Avm2Value stage_get_tab_children(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(1);
}

static Avm2Value stage_set_tab_children(Avm2Activation* act)
{
	Avm2Object* root = act->ctx->root;
	Avm2DisplayObjectExt* rext = root != NULL
		? avm2_display_ext_of(act->ctx, root) : NULL;
	if (rext != NULL && act->argc > 0)
		rext->tab_children = avm2_coerce_to_boolean(act->args[0]) ? 1 : 0;
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
	ext->cx_rm = 256;
	ext->cx_gm = 256;
	ext->cx_bm = 256;
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

// flash.text.engine.TextLine: a DisplayObjectContainer that only
// TextBlock.createTextLine may build. The class is [Ruffle(Abstract)], so a
// script `new TextLine()` throws #2012 like the abstract display bases — but
// unlike them the hook is conditional, because the FTE layout core has to
// allocate one. It goes through display_alloc_instance precisely so the line
// consumes a number from the shared instance counter (textline_name grades
// `name == "instance1"`), and so nothing else may — in particular we build no
// internal fallback text object, which would steal that number.
static Avm2Class* g_textline_class;
static int g_textline_alloc_ok;

static void textline_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	if (!g_textline_alloc_ok)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2012: TextLine$ class cannot be instantiated.");
		return;
	}
	display_native_init(ctx, obj);
}

Avm2Object* avm2_display_new_textline(Avm2Context* ctx)
{
	if (g_textline_class == NULL) return NULL;
	g_textline_alloc_ok = 1;
	Avm2Object* obj = display_alloc_instance(ctx, g_textline_class);
	g_textline_alloc_ok = 0;
	return obj;
}

// MorphShape (flash.display.MorphShape): a DisplayObject the timeline places
// for a DefineMorphShape character, but which script CANNOT instantiate —
// `new MorphShape()` throws #2012 (avmplus ArgumentError). Unlike the abstract
// display bases (display_native_init_abstract, which throw unconditionally),
// MorphShape IS timeline-instantiable, so the #2012 guard is conditional on
// this being a script `new` (g_timeline_instantiation == 0). Timeline placement
// runs the ordinary concrete init.
static void morphshape_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	if (!g_timeline_instantiation)
	{
		const char* name = "MorphShape";
		uint32_t name_len = 10;
		if (obj->cls != NULL)
		{
			name = obj->cls->name.name;
			name_len = obj->cls->name.name_len;
		}
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2012: %.*s$ class cannot be instantiated.",
		                 (int) name_len, name);
		return;
	}
	display_native_init(ctx, obj);
}

// flash.display.Stage: `new Stage()` is #2012, but display_alloc_instance
// mints the real stage through this same hook — and it does NOT go through
// avm2_class_alloc_instance, so avm2_class_alloc_is_script_new() is false
// there for free.
static void stage_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	if (avm2_class_alloc_is_script_new())
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2012: Stage$ class cannot be instantiated.");
		return;
	}
	display_native_init(ctx, obj);
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
			// Both halves are ours now — drop any per-setter binding the
			// inherited entry carried.
			e->setter_defining_class = NULL;
			e->setter_scope = NULL;
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

// Ruffle input.rs `keys_down_phys_loc`: the (physical key, location) pairs a
// KeyDown has claimed. A KeyUp with no matching entry is dropped as spurious.
// Ruffle keys this on the winit PhysicalKey; the harness only carries the
// Flash keyCode, which for every key the corpus exercises maps 1:1 onto the
// physical key (both 'a' and 'A' are keyCode 65 / PhysicalKey::KeyA, both '"'
// and '\'' are 222 / Quote, and an unmapped key is 0 / Unknown on both sides).
#define AVM2_KEYS_DOWN_CAP 64
static struct { int32_t code, loc; } g_keys_down_phys[AVM2_KEYS_DOWN_CAP];
static uint32_t g_keys_down_phys_n;

static void keys_down_phys_add(int32_t code, int32_t loc)
{
	for (uint32_t i = 0; i < g_keys_down_phys_n; i++)
		if (g_keys_down_phys[i].code == code && g_keys_down_phys[i].loc == loc)
			return;
	if (g_keys_down_phys_n >= AVM2_KEYS_DOWN_CAP) return;
	g_keys_down_phys[g_keys_down_phys_n].code = code;
	g_keys_down_phys[g_keys_down_phys_n].loc = loc;
	g_keys_down_phys_n++;
}

// Returns 1 if the pair was present (and removes it), 0 if the KeyUp is spurious.
static int keys_down_phys_remove(int32_t code, int32_t loc)
{
	for (uint32_t i = 0; i < g_keys_down_phys_n; i++)
	{
		if (g_keys_down_phys[i].code != code || g_keys_down_phys[i].loc != loc)
			continue;
		g_keys_down_phys[i] = g_keys_down_phys[--g_keys_down_phys_n];
		return 1;
	}
	return 0;
}
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
	avm2_gc_mark_object(g_stage_loader_info);
	// In-flight loads: the queue and the tracked LoaderInfos are the only
	// reference to a Loader whose script dropped it mid-load.
	for (uint32_t i = 0; i < g_pending_load_count; i++)
	{
		avm2_gc_mark_object(g_pending_loads[i].loader_info);
		avm2_gc_mark_object(g_pending_loads[i].app_domain);
		avm2_gc_mark_string(g_pending_loads[i].url);
	}
	for (uint32_t i = 0; i < g_active_loader_info_count; i++)
		avm2_gc_mark_object(g_active_loader_infos[i]);
	// Same for an in-flight URLLoader/URLStream: between load() and the drain
	// the queue can be the only reference (urlstream_basic drops its stream
	// into listener closures the stream itself owns, a cycle nothing else
	// reaches).
	for (uint32_t i = 0; i < g_pending_url_load_count; i++)
		avm2_gc_mark_object(g_pending_url_loads[i].loader);
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
	// The candidate list aliases the same objects: an unmarked entry is
	// about to be freed, so it must go too.
	w = 0;
	for (uint32_t i = 0; i < g_orphan_dirty_count; i++)
	{
		if (avm2_gc_is_marked(g_orphan_dirty[i]))
		{
			g_orphan_dirty[w++] = g_orphan_dirty[i];
		}
	}
	g_orphan_dirty_count = w;
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
	// A stored ShaderFilter keeps its Shader BY IDENTITY, and the filter list
	// is out of line — the conservative blob scan never sees it.
	avm2_filter_gc_mark(ext->filters, ext->filter_count);
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
	clear_filters(ctx, ext);
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
		else if (strncmp(line, "IME_PREEDIT ", 12) == 0)
		{
			// "IME_PREEDIT <cursor_from> <cursor_to> <text>", both cursor
			// fields -1 for Ruffle's `None`. The text runs to end of line and
			// may be empty (a cleared preedit).
			ev.kind = IN_IME_PREEDIT;
			int consumed = 0;
			if (sscanf(line + 12, "%d %d %n", &ev.code, &ev.code2, &consumed) < 2)
				{ ev.code = -1; ev.code2 = -1; consumed = 0; }
			const char* rest = line + 12 + consumed;
			strncpy(ev.text, rest, sizeof(ev.text) - 1);
			ev.text[sizeof(ev.text) - 1] = '\0';
			size_t tl = strlen(ev.text);
			while (tl > 0 && (ev.text[tl-1] == '\n' || ev.text[tl-1] == '\r'))
				ev.text[--tl] = '\0';
		}
		else if (strncmp(line, "IME_COMMIT ", 11) == 0)
		{
			ev.kind = IN_IME_COMMIT;
			strncpy(ev.text, line + 11, sizeof(ev.text) - 1);
			ev.text[sizeof(ev.text) - 1] = '\0';
			size_t tl = strlen(ev.text);
			while (tl > 0 && (ev.text[tl-1] == '\n' || ev.text[tl-1] == '\r'))
				ev.text[--tl] = '\0';
		}
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

// Resident recompiler geometry (generated draws.c), linked into every build —
// see the matching extern near avm2_render_morph. Read here for shape-accurate
// hit testing: each row is one vertex {x_bits(float), y_bits(float), ...} in
// shape-LOCAL twips, three consecutive rows per triangle.
extern uint32_t shape_data[][4];

static inline float pick_bits_to_f(uint32_t u)
{
	float f;
	memcpy(&f, &u, sizeof(f));
	return f;
}

// Barycentric sign test, boundary inclusive (copy of libswf hit_test.c's
// point_in_triangle, which the AVM1 side has used since the beginning).
static int pick_tri_contains(double px, double py, double ax, double ay,
                             double bx, double by, double cx, double cy)
{
	double d1 = (px - bx) * (ay - by) - (ax - bx) * (py - by);
	double d2 = (px - cx) * (by - cy) - (bx - cx) * (py - cy);
	double d3 = (px - ax) * (cy - ay) - (cx - ax) * (py - ay);
	int has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	int has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(has_neg && has_pos);
}

static int pick_tris_contain(const float* v, uint32_t n, double lx, double ly)
{
	for (uint32_t t = 0; t + 3 <= n; t += 3)
		if (pick_tri_contains(lx, ly,
		                      v[t * 2],       v[t * 2 + 1],
		                      v[(t + 1) * 2], v[(t + 1) * 2 + 1],
		                      v[(t + 2) * 2], v[(t + 2) * 2 + 1]))
			return 1;
	return 0;
}

// Does obj carry real (triangulated) geometry we can test exactly, rather than
// only a bounding box? Ruffle draws the same line: Graphic and MovieClip test
// their shape / Drawing (shape_hit_test, Drawing::hit_test), while Bitmap,
// EditText and StaticText fall through to DisplayObject::hit_test_shape's
// "default to using bounding box".
static int has_pick_geometry(Avm2DisplayObjectExt* ext)
{
	if (ext->shape_vert_count > 0 && !ext->is_morph_shape) return 1;
	if (ext->graphics_obj != NULL)
	{
		Avm2GraphicsExt* g = (Avm2GraphicsExt*) ext->graphics_obj->native_ext;
		if (g != NULL && (g->path_count > 0 || g->cmd_count > 0)) return 1;
	}
	return 0;
}

// Exact shape test in obj's LOCAL twips space: the placed timeline shape's
// triangles, then the drawing API's tessellated fills and strokes.
static int shape_contains_local(Avm2DisplayObjectExt* ext, double lx, double ly)
{
	if (ext->shape_vert_count > 0 && !ext->is_morph_shape)
	{
		uint32_t off = ext->shape_vert_offset, n = ext->shape_vert_count;
		for (uint32_t t = 0; t + 3 <= n; t += 3)
		{
			const uint32_t* a = shape_data[off + t];
			const uint32_t* b = shape_data[off + t + 1];
			const uint32_t* c = shape_data[off + t + 2];
			if (pick_tri_contains(lx, ly,
			                      pick_bits_to_f(a[0]), pick_bits_to_f(a[1]),
			                      pick_bits_to_f(b[0]), pick_bits_to_f(b[1]),
			                      pick_bits_to_f(c[0]), pick_bits_to_f(c[1])))
				return 1;
		}
	}
	if (ext->graphics_obj != NULL)
	{
		Avm2GraphicsExt* g = (Avm2GraphicsExt*) ext->graphics_obj->native_ext;
		if (g != NULL)
		{
			// Ruffle's Drawing::hit_test also tests the *pending* (un-endFilled)
			// subpath; committing it here is exactly what the render walk does.
			gfx_finalize_path(g);
			for (uint32_t i = 0; i < g->path_count; i++)
			{
				Avm2GfxPath* p = &g->paths[i];
				if (p->fill_kind != 0
				    && pick_tris_contain(p->fill_verts, p->fill_vert_count, lx, ly))
					return 1;
				if (p->has_line
				    && pick_tris_contain(p->line_verts, p->line_vert_count, lx, ly))
					return 1;
			}
		}
	}
	return 0;
}

// Does obj's OWN shape contain the stage point (twips)? Maps the point into
// obj's local space so rotation/scale are honored, AABB-rejects against the
// self bounds (Ruffle's `world_bounds().contains(point)` guard), and then —
// for objects that carry triangulated geometry — tests the actual shape.
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
	if (lx < self.xmin || lx > self.xmax || ly < self.ymin || ly > self.ymax)
		return 0;
	if (!has_pick_geometry(ext)) return 1;
	return shape_contains_local(ext, lx, ly);
}

// Ruffle HitTestOptions (display_object.rs) — the two bits that reach us.
#define HT_SKIP_MASK      1
#define HT_SKIP_INVISIBLE 2
#define HT_SKIP_CHILDREN  4
#define HT_MOUSE_PICK     (HT_SKIP_MASK | HT_SKIP_INVISIBLE)

// Ruffle DisplayObject::hit_test_shape. The container flavour (movie_clip.rs)
// honors the masker/maskee pair and the timeline clip layers and recurses into
// the render list; Graphic/Bitmap/EditText use the leaf flavour, which is just
// "visible enough, and inside my shape". Point in stage twips.
static int hit_test_shape_obj(Avm2Context* ctx, Avm2Object* obj,
                              double px, double py, int options)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return 0;
	int is_container = obj->cls != NULL
	                   && class_is_a(obj->cls, ctx->builtins.sprite_class);
	if (!is_container)
		return ((options & HT_SKIP_INVISIBLE) == 0 || ext->visible)
		       && point_in_self(ctx, obj, px, py);

	// A maskee stays hit-testable while invisible: `visible = false` is how a
	// mask is normally hidden, and the mask still has to answer hit tests.
	if ((options & HT_SKIP_INVISIBLE) && !ext->visible && ext->maskee == NULL)
		return 0;
	if ((options & HT_SKIP_MASK) && ext->maskee != NULL) return 0;
	if (ext->mask != NULL
	    && !hit_test_shape_obj(ctx, ext->mask, px, py, HT_SKIP_INVISIBLE))
		return 0;

	int32_t clip_depth = 0;
	for (uint32_t i = 0; (options & HT_SKIP_CHILDREN) == 0 && i < ext->render_len;
	     i++)
	{
		Avm2Object* child = ext->render_list[i];
		Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
		if (cext == NULL) continue;
		if (cext->clip_depth > 0)
			clip_depth = hit_test_shape_obj(ctx, child, px, py,
			                                HT_SKIP_MASK | HT_SKIP_INVISIBLE)
				? 0 : cext->clip_depth;
		else if (cext->depth >= clip_depth
		         && hit_test_shape_obj(ctx, child, px, py, options))
			return 1;
	}
	return point_in_self(ctx, obj, px, py);
}

typedef enum { PK_MISS, PK_PROP, PK_HIT } PkKind;
typedef struct { PkKind kind; Avm2Object* target; } Pk;

static Pk pk_make(PkKind k, Avm2Object* t) { Pk p; p.kind = k; p.target = t; return p; }

// "The root object of a loader or stage is never a valid target of hit events"
// (Ruffle combine_with_parent, `target.loader_info().is_none()`). A movie root
// is exactly the object that owns a LoaderInfo: the main SWF's root, and every
// Loader-loaded child's root. A hit on one is absorbed by the parent as if the
// parent had mouseChildren=false — which for the main root means the Stage, and
// therefore no target at all (loader_noninteractive_try_click_root clicks the
// root's own Shape and expects `[object Stage]`).
static int pk_is_movie_root(Avm2Context* ctx, Avm2Object* o)
{
	Avm2DisplayObjectExt* e = o != NULL ? avm2_display_ext_of(ctx, o) : NULL;
	return e != NULL && e->is_root && !e->is_stage;
}

// Ruffle Avm2MousePick::combine_with_parent.
static Pk pk_combine(Avm2Context* ctx, Pk p, Avm2Object* parent)
{
	Avm2DisplayObjectExt* pext = avm2_display_ext_of(ctx, parent);
	int pme = pext == NULL || pext->mouse_enabled;
	int pmc = pext == NULL || pext->mouse_children;
	switch (p.kind)
	{
	case PK_HIT:
		if (pmc && !pk_is_movie_root(ctx, p.target)) return p;
		return pme ? pk_make(PK_HIT, parent) : pk_make(PK_PROP, NULL);
	case PK_PROP:
		return pme ? pk_make(PK_HIT, parent) : pk_make(PK_PROP, NULL);
	default:
		return pk_make(PK_MISS, NULL);
	}
}

// Ruffle movie_clip.rs::mouse_pick_avm2. point in twips.
static Pk mouse_pick(Avm2Context* ctx, Avm2Object* obj, double px, double py)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return pk_make(PK_MISS, NULL);
	if (!ext->is_stage && !ext->visible) return pk_make(PK_MISS, NULL);

	// Masked away, or busy being someone else's mask: not a target either way.
	if (ext->mask != NULL
	    && !hit_test_shape_obj(ctx, ext->mask, px, py, 0))
		return pk_make(PK_MISS, NULL);
	if (ext->maskee != NULL) return pk_make(PK_MISS, NULL);

	// SimpleButton (Ruffle avm2_button.rs::mouse_pick_avm2): the visual/hit
	// state children live in btn_hit/btn_up, NOT render_list, so the generic
	// render_list + self-bounds pick below never sees them. Hit-test the hit
	// state (fall back to the up state when there is no dedicated hit shape),
	// inverse-mapping the stage point into the state's local space so
	// rotation/scale are honored. The BUTTON itself is the pick target — a
	// button's states are never interactive and never receive the event.
	if (obj->cls != NULL
	    && class_is_a(obj->cls, ctx->builtins.simple_button_class))
	{
		Avm2Object* hit = ext->btn_hit != NULL ? ext->btn_hit : ext->btn_up;
		Avm2DisplayObjectExt* hext = hit != NULL
			? avm2_display_ext_of(ctx, hit) : NULL;
		if (hext != NULL)
		{
			Mat bw = display_world_matrix(ctx, obj);
			Mat hl = ext_matrix(hext);
			Mat hw = mat_mul(&bw, &hl);       // hit-local -> world
			Mat idm = mat_identity();
			Rect hb = { 0, 0, 0, 0, 0 };
			bounds_with_transform(ctx, hit, &idm, &hb);  // subtree in hit-local
			if (hb.valid)
			{
				Mat inv = mat_invert(&hw);
				double lx = inv.a * px + inv.c * py + inv.tx;
				double ly = inv.b * px + inv.d * py + inv.ty;
				if (lx >= hb.xmin && lx <= hb.xmax
				    && ly >= hb.ymin && ly <= hb.ymax)
					return ext->mouse_enabled ? pk_make(PK_HIT, obj)
					                          : pk_make(PK_PROP, NULL);
			}
		}
		return pk_make(PK_MISS, NULL);
	}

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
	// Timeline clip layers: every child with clip_depth > 0 masks the depth
	// range (depth+1 ..= clip_depth). Ruffle walks them as a single reversed,
	// peekable cursor shared across BOTH child passes — the cursor only ever
	// advances, so replicate it exactly rather than re-deriving per child.
	int32_t clip_idx = (int32_t) ext->render_len - 1;
	// A child in a clip layer's range is hit only if the layer's shape is hit.
	int hit_options = HT_SKIP_INVISIBLE;
	if (ext->maskee == NULL) hit_options |= HT_SKIP_MASK;

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
			Avm2DisplayObjectExt* cext = avm2_display_ext_of(ctx, child);
			// Mask children — a clip layer or a `mask` target — are not clickable.
			if (cext == NULL || cext->clip_depth > 0 || cext->maskee != NULL)
				continue;
			Pk res;
			if (ci)
			{
				res = mouse_pick(ctx, child, px, py);
			}
			else
			{
				int in = cext->visible && point_in_self(ctx, child, px, py)
				         && (cext->mask == NULL
				             || hit_test_shape_obj(ctx, cext->mask, px, py,
				                                   hit_options));
				if (in)
					res = ext->mouse_enabled ? pk_make(PK_HIT, obj)
					                         : pk_make(PK_PROP, NULL);
				else
					res = pk_make(PK_MISS, NULL);
			}

			// Apply the innermost clip layer that still covers this child's depth.
			while (clip_idx >= 0)
			{
				Avm2Object* clip = ext->render_list[clip_idx];
				Avm2DisplayObjectExt* clext = avm2_display_ext_of(ctx, clip);
				if (clext == NULL || clext->clip_depth <= 0) { clip_idx--; continue; }
				if (clext->depth + 1 > cext->depth) { clip_idx--; continue; }
				if (cext->depth <= clext->clip_depth
				    && !hit_test_shape_obj(ctx, clip, px, py, hit_options))
					res = pk_make(PK_MISS, NULL);
				break;
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

// DisplayObjectContainer.getObjectsUnderPoint (Ruffle
// display_object_container.rs). A depth-first pre-order walk from the receiver:
// children are pushed in REVERSE render order so they pop front-to-back, and
// each node is tested with SKIP_CHILDREN so it answers for its OWN shape only.
// The receiver itself is walked but never reported. Point is stage-relative.
static Avm2Value doc_get_objects_under_point(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2Value pv = act->argc > 0 ? act->args[0] : avm2_undefined();
	if (self == NULL || pv.kind != AVM2_VALUE_OBJECT || pv.u.obj == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter point must be non-null.");
	}
	double px = 0, py = 0;
	if (pv.u.obj->slot_count > 2)
	{
		px = avm2_coerce_to_number(ctx, pv.u.obj->slots[1]) * 20.0;
		py = avm2_coerce_to_number(ctx, pv.u.obj->slots[2]) * 20.0;
	}

	Avm2Value* out = NULL;
	uint32_t out_n = 0, out_cap = 0;
	Avm2Object** stack = NULL;
	uint32_t stack_n = 0, stack_cap = 0;
	#define GOUP_PUSH(arr, n, cap, v, type) \
		do { \
			if ((n) == (cap)) { \
				uint32_t nc = (cap) ? (cap) * 2 : 16; \
				type* nb = realloc((arr), nc * sizeof(type)); \
				if (nb == NULL) break; \
				(arr) = nb; (cap) = nc; \
			} \
			(arr)[(n)++] = (v); \
		} while (0)

	GOUP_PUSH(stack, stack_n, stack_cap, self, Avm2Object*);
	while (stack_n > 0)
	{
		Avm2Object* node = stack[--stack_n];
		Avm2DisplayObjectExt* next = avm2_display_ext_of(ctx, node);
		if (next == NULL) continue;
		if (node != self
		    && hit_test_shape_obj(ctx, node, px, py,
		                          HT_SKIP_MASK | HT_SKIP_INVISIBLE
		                          | HT_SKIP_CHILDREN))
		{
			Avm2Value v = avm2_object_value(node);
			GOUP_PUSH(out, out_n, out_cap, v, Avm2Value);
		}
		for (uint32_t i = next->render_len; i > 0; i--)
		{
			GOUP_PUSH(stack, stack_n, stack_cap, next->render_list[i - 1],
			          Avm2Object*);
		}
	}
	#undef GOUP_PUSH
	free(stack);
	Avm2Object* arr = avm2_array_from_values(ctx, out, out_n);
	free(out);
	return avm2_object_value(arr);
}

static Avm2Value doc_are_inaccessible_objects_under_point(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(false);
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
	// Ruffle's `start_drag` only *records* the drag; the object does not move
	// until the next `update_drag` (mouse event or end of frame). A
	// `startDrag(true)` inside a mouseDown handler therefore leaves x/y alone
	// for the rest of that handler — see from_shumway/mouse/start_drag_lock,
	// whose own comment reads "in FP x and y will update in about 70-100ms".
	return avm2_undefined();
}

static Avm2Value do_stop_drag(Avm2Activation* act)
{
	// Ruffle sprite.rs::stop_drag: "We might not have had an opportunity to
	// call `update_drag` if AS did `startDrag(mc); stopDrag();` in one go".
	update_drag(act->ctx);
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
// Ruffle global_to_local returns a Point<TWIPS> — the local coordinate is an
// integer number of twips, and MouseEvent.localX/localY are that integer's
// to_pixels(). Snapping here is what makes stageX/stageY round-trip: they map
// the local value back through local_to_global, and Twips::from_pixels
// truncates, so an unsnapped local that landed a hair below a twip boundary
// came back one twip short (mouse_pick_masking's 282.75-for-282.8).
static void local_mouse(Avm2Context* ctx, Avm2Object* obj, double* lx, double* ly)
{
	Mat m = display_world_matrix(ctx, obj);
	Mat inv = mat_invert(&m);
	double gx = g_mouse_x * 20.0, gy = g_mouse_y * 20.0;
	*lx = round(inv.a * gx + inv.c * gy + inv.tx) / 20.0;
	*ly = round(inv.b * gx + inv.d * gy + inv.ty) / 20.0;
}

// Ruffle mouse_event.rs::local_to_stage_{x,y}: local pixels -> twips
// (Twips::from_pixels truncates toward zero) -> the target's local_to_global
// matrix -> back to pixels. Returns 1 when a display-object target supplied
// the mapping; 0 means the caller must apply the no-target rule itself
// (`local * 0.0`, i.e. 0 with the sign of the local coordinate).
int avm2_display_event_stage_coords(Avm2Context* ctx, Avm2Object* target,
                                    double lx, double ly, double* sx, double* sy)
{
	if (target == NULL || avm2_display_ext_of(ctx, target) == NULL
	    || isnan(lx) || isnan(ly))
	{
		*sx = lx; *sy = ly;
		return 0;
	}
	Mat m = display_world_matrix(ctx, target);
	double px = (double) (int32_t) (lx * 20.0), py = (double) (int32_t) (ly * 20.0);
	*sx = (m.a * px + m.c * py + m.tx) / 20.0;
	*sy = (m.b * px + m.d * py + m.ty) / 20.0;
	return 1;
}

// Construct + dispatch a MouseEvent to a display object (its object2 is itself).
static int dispatch_mouse(Avm2Context* ctx, Avm2Object* target,
                          const char* type, Avm2Object* related, int32_t delta,
                          int bubbles, int button)
{
	if (target == NULL) return 0;
	// Ruffle interactive.rs::event_dispatch_to_avm2: "Flash appears to not fire
	// events *at all* for a targeted EditText that was originally created by the
	// timeline" — not even the Stage sees them. mouse_pick still HITS such a
	// field (that is what puts the I-beam cursor up); the suppression is here,
	// at dispatch, so the event is dropped rather than reassigned to an ancestor.
	{
		Avm2DisplayObjectExt* text = avm2_display_ext_of(ctx, target);
		if (text != NULL && text->edittext != NULL
		    && avm2_text_is_selectable(text->edittext)
		    && avm2_text_was_static(text->edittext))
			return 0;
	}
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

// --- Caret placement / mouse selection bridge (avm2_text.c owns the layout
// query; the display side owns the global -> local mapping) ---
extern void avm2_text_mouse_press(Avm2Context* ctx, Avm2Object* obj,
                                  uint32_t click_index,
                                  int32_t local_x, int32_t local_y);
extern void avm2_text_mouse_drag(Avm2Context* ctx, Avm2Object* obj,
                                 int32_t local_x, int32_t local_y);

// Mouse position in obj's local space, snapped to whole twips — Ruffle's
// `self.global_to_local(*context.mouse_position)`, which is Point<Twips>.
static int local_mouse_twips(Avm2Context* ctx, Avm2Object* obj,
                             int32_t* lx, int32_t* ly)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->edittext == NULL) return 0;
	Mat m = display_world_matrix(ctx, obj);
	Mat inv = mat_invert(&m);
	double gx = g_mouse_x * 20.0, gy = g_mouse_y * 20.0;
	*lx = (int32_t) round(inv.a * gx + inv.c * gy + inv.tx);
	*ly = (int32_t) round(inv.b * gx + inv.d * gy + inv.ty);
	return 1;
}

static void text_mouse_press(Avm2Context* ctx, Avm2Object* obj,
                             uint32_t click_index)
{
	int32_t lx = 0, ly = 0;
	if (local_mouse_twips(ctx, obj, &lx, &ly))
		avm2_text_mouse_press(ctx, obj, click_index, lx, ly);
}

static void text_mouse_drag(Avm2Context* ctx, Avm2Object* obj)
{
	int32_t lx = 0, ly = 0;
	if (local_mouse_twips(ctx, obj, &lx, &ly))
		avm2_text_mouse_drag(ctx, obj, lx, ly);
}

// Env AVM2_MOUSE_DEBUG: compact "Class 'name'" label for a picked target.
static void avm2_dbg_pick_label(Avm2Context* ctx, const char* tag, Avm2Object* o)
{
	if (getenv("AVM2_MOUSE_DEBUG") == NULL) return;
	if (o == NULL) { fprintf(stderr, "MPICK %s = NULL (stage)\n", tag); return; }
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, o);
	const char* cn = (o->cls != NULL && o->cls->name.name != NULL)
		? o->cls->name.name : "?";
	const char* nm = (ext != NULL && ext->name != NULL && ext->name->utf8 != NULL)
		? ext->name->utf8 : "(anon)";
	fprintf(stderr, "MPICK %s = %s '%s' me=%d\n", tag, cn, nm,
		ext != NULL ? ext->mouse_enabled : -1);
}

static void update_mouse_state(Avm2Context* ctx, int changed_button, int is_moved)
{
	Avm2Object* stage = ctx->stage;
	// Dragged object follows the mouse before hit-testing (Ruffle update_drag).
	update_drag(ctx);
	int mouse_in_stage = 1;
	Avm2Object* new_over = mouse_in_stage ? run_mouse_pick(ctx) : NULL;
	if (changed_button == 0)
		avm2_dbg_pick_label(ctx, g_mouse_btn_down[0] ? "down" : "up", new_over);
	Avm2Object* cur_over = g_mouse_hovered;
	int left_down = g_mouse_btn_down[0];

	// Ruffle EditText::event_dispatch(ClipEvent::MouseMove): a move while THIS
	// field is the pressed object extends its selection. The MouseMove clip
	// event goes to the pressed object, not the hovered one, so a drag that
	// leaves the field keeps selecting.
	if (is_moved && left_down && g_mouse_pressed[0] != NULL)
		text_mouse_drag(ctx, g_mouse_pressed[0]);

	if (is_moved)
		dispatch_mouse(ctx, new_over != NULL ? new_over : stage,
		               "mouseMove", NULL, 0, 1, 0);

	// Hover change → roll/over events.
	if (cur_over != new_over)
	{
		if (left_down)
		{
			g_mouse_hovered = new_over;
			// Ruffle queues the PRESSED object's DragOut/DragOver first and
			// the AS3 RollOut/RollOver after, so for a button that is both
			// pressed and rolled the later event wins the state
			// (player.rs:1636-1723 + avm2_button.rs:736-743).
			Avm2Object* down_obj = g_mouse_pressed[0];
			if (down_obj != NULL)
			{
				if (down_obj == cur_over)
					button_clip_state(ctx, down_obj, BTN_ST_OVER);   // DragOut
				else if (down_obj == new_over)
					button_clip_state(ctx, down_obj, BTN_ST_DOWN);   // DragOver
			}
			if (cur_over != NULL)
			{
				button_clip_state(ctx, cur_over, BTN_ST_UP);         // RollOut
				dispatch_roll_out(ctx, cur_over, new_over);
			}
			if (new_over != NULL)
			{
				button_clip_state(ctx, new_over, BTN_ST_OVER);       // RollOver
				dispatch_roll_over(ctx, new_over, cur_over);
			}
		}
		else
		{
			if (cur_over != NULL)
			{
				button_clip_state(ctx, cur_over, BTN_ST_UP);         // RollOut
				dispatch_roll_out(ctx, cur_over, new_over);
			}
			if (new_over != NULL)
			{
				button_clip_state(ctx, new_over, BTN_ST_OVER);       // RollOver
				dispatch_roll_over(ctx, new_over, cur_over);
			}
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
				// ClipEvent::Press -> ButtonState::Down. Only the LEFT button
				// is in Avm2Button's table (Right/MiddlePress fall through).
				// Same clip-event tier as text_mouse_press below, so it lands
				// before the AVM2 mouseDown, exactly like Ruffle.
				if (button == 0) button_clip_state(ctx, over, BTN_ST_DOWN);
				// Ruffle's dispatch loop runs handle_clip_event (EditText's
				// caret placement) BEFORE update_focus_on_mouse_press.
				if (button == 0) text_mouse_press(ctx, over, g_left_click_index);
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
			// Player::should_reset_highlight: a LEFT mouse-down always kills
			// the highlight, whether or not the focus moved. (The extra SWF<9
			// cases — move / right / up — can't apply: AVM2 content is SWF 9+.)
			if (button == 0) g_avm2_highlight = 0;
		}
		else
		{
			// Release.
			Avm2Object* over = g_mouse_hovered;
			const char* up_type = button == 0 ? "mouseUp"
				: button == 1 ? "middleMouseUp" : "rightMouseUp";
			// ClipEvent::MouseUpInside goes to the HOVERED object first
			// (player.rs:1777-1787) -> ButtonState::Up. A release inside the
			// same button immediately re-raises it to Over below, so the net
			// effect there is Over — which is what Flash shows after a click.
			if (button == 0 && over != NULL)
				button_clip_state(ctx, over, BTN_ST_UP);
			dispatch_mouse(ctx, over != NULL ? over : stage, up_type, NULL, 0, 1,
			               button);
			int released_inside = (g_mouse_pressed[button] == over);
			if (released_inside)
			{
				Avm2Object* down = g_mouse_pressed[button];
				Avm2Object* rt = down != NULL ? down : stage;
				// ClipEvent::Release -> ButtonState::Over (left button only).
				if (button == 0) button_clip_state(ctx, rt, BTN_ST_OVER);
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
					// ClipEvent::ReleaseOutside -> ButtonState::Up.
					if (down != NULL) button_clip_state(ctx, down, BTN_ST_UP);
					dispatch_mouse(ctx, down != NULL ? down : stage,
					               "releaseOutside", NULL, 0, 1, 0);
					// New object rolled over immediately (RollOver -> Over).
					if (g_mouse_hovered != NULL)
					{
						button_clip_state(ctx, g_mouse_hovered, BTN_ST_OVER);
						dispatch_roll_over(ctx, g_mouse_hovered, cur_over);
					}
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
static void set_focus(Avm2Context* ctx, Avm2Object* new_focus);
static void avm2_update_highlight(Avm2Context* ctx);

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
		// Ruffle player.rs dispatches the MouseEvent and *then* hands the same
		// wheel to the target's own clip-event handler; the only AVM2 handler
		// that consumes it is EditText, which scrolls itself.
		avm2_text_mouse_wheel(ctx, target, ev->code);
		break;
	}
	case IN_KEY_DOWN:
		if (ev->code >= 0 && ev->code < 256) g_key_down_map[ev->code] = 1;
		keys_down_phys_add(ev->code, ev->code3);
		input_handle_key(ctx, 1, ev->code, ev->code2, ev->code3);
		break;
	case IN_KEY_UP:
		// Ruffle input.rs: "Ignore spurious KeyUp events that may happen e.g.
		// during IME. We assume that in order for a key to generate KeyUp, it
		// had to generate KeyDown for the same physical key and location."
		// This is what swallows the dead-key `Unknown` releases and the
		// `Char` releases an IME commit stands in for — it is a bookkeeping
		// rule about physical keys, not a composition-active flag.
		if (!keys_down_phys_remove(ev->code, ev->code3)) break;
		if (ev->code >= 0 && ev->code < 256) g_key_down_map[ev->code] = 0;
		input_handle_key(ctx, 0, ev->code, ev->code2, ev->code3);
		break;
	case IN_IME_PREEDIT:
		if (g_stage_focus != NULL)
			avm2_text_ime_preedit(ctx, g_stage_focus, ev->text, ev->code,
			                      ev->code2);
		break;
	case IN_IME_COMMIT:
		if (g_stage_focus != NULL)
			avm2_text_ime_commit(ctx, g_stage_focus, ev->text);
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
	// The player *window* losing focus drops stage focus entirely, firing the
	// usual focusOut with relatedObject = null (AVM1: actionWindowFocusLost).
	// Regaining it restores nothing — Flash does not remember the old target.
	case IN_FOCUS_LOST:
		set_focus(ctx, NULL);
		break;
	case IN_FOCUS_GAINED:
		break;
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

// --- Debug: read-only display-tree dump (env AVM2_DUMP_TREE), stage-space AABB
// in px, per node. For SimpleButtons the state children live in btn_up/btn_hit
// (NOT render_list), so the self bbox is EMPTY; print the up/hit state world
// bbox separately so a click coordinate can be read off. Never mutates state.
static void avm2_dbg_dump_node(Avm2Context* ctx, Avm2Object* obj, int depth)
{
	if (obj == NULL || depth > 14) return;
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	const char* cn = (obj->cls != NULL && obj->cls->name.name != NULL)
		? obj->cls->name.name : "?";
	const char* nm = (ext->name != NULL && ext->name->utf8 != NULL)
		? ext->name->utf8 : "(anon)";
	Mat wm = display_world_matrix(ctx, obj);
	Rect acc = { 0, 0, 0, 0, 0 };
	bounds_with_transform(ctx, obj, &wm, &acc);
	fprintf(stderr, "TREE ");
	for (int i = 0; i < depth; i++) fprintf(stderr, "  ");
	if (acc.valid)
		fprintf(stderr, "%s '%s' vis=%d bbox=[%.1f,%.1f..%.1f,%.1f]px\n",
			cn, nm, ext->visible, acc.xmin / 20.0, acc.ymin / 20.0,
			acc.xmax / 20.0, acc.ymax / 20.0);
	else
		fprintf(stderr, "%s '%s' vis=%d bbox=EMPTY\n", cn, nm, ext->visible);
	Avm2Object* st = ext->btn_hit != NULL ? ext->btn_hit
		: ext->btn_up != NULL ? ext->btn_up : NULL;
	if (st != NULL)
	{
		Avm2DisplayObjectExt* sext = avm2_display_ext_of(ctx, st);
		if (sext != NULL)
		{
			Mat sl = ext_matrix(sext);
			Mat sw = mat_mul(&wm, &sl);
			Rect sb = { 0, 0, 0, 0, 0 };
			bounds_with_transform(ctx, st, &sw, &sb);
			fprintf(stderr, "TREE ");
			for (int i = 0; i <= depth; i++) fprintf(stderr, "  ");
			if (sb.valid)
				fprintf(stderr, "[btn-%s state] bbox=[%.1f,%.1f..%.1f,%.1f]px "
					"center=(%.1f,%.1f)\n",
					ext->btn_hit != NULL ? "hit" : "up",
					sb.xmin / 20.0, sb.ymin / 20.0, sb.xmax / 20.0, sb.ymax / 20.0,
					(sb.xmin + sb.xmax) / 40.0, (sb.ymin + sb.ymax) / 40.0);
			else
				fprintf(stderr, "[btn state] bbox=EMPTY\n");
		}
	}
	for (uint32_t i = 0; i < ext->render_len; i++)
		avm2_dbg_dump_node(ctx, ext->render_list[i], depth + 1);
}

static void avm2_dbg_dump_tree(Avm2Context* ctx)
{
	if (getenv("AVM2_DUMP_TREE") == NULL) return;
	fprintf(stderr, "TREE ===== tick tree dump =====\n");
	if (ctx->stage != NULL) avm2_dbg_dump_node(ctx, ctx->stage, 0);
}

void avm2_input_pump_tick(Avm2Context* ctx)
{
	avm2_dbg_dump_tree(ctx);
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

static int obj_tab_enabled(Avm2Context* ctx, Avm2Object* obj);

static int is_focusable_by_mouse(Avm2Context* ctx, Avm2Object* obj)
{
	// Ruffle InteractiveObject::is_focusable_by_mouse — `is_action_script_3()
	// && tab_enabled(context)`. `tab_enabled` includes the per-type DEFAULT
	// (SimpleButton true, MovieClip when buttonMode, editable TextField), not
	// just an explicitly assigned value. EditText overrides the whole thing to
	// "true for AS3 content" (edit_text.rs:3166).
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e == NULL || e->is_stage || e->is_root) return 0;
	if (e->edittext != NULL) return 1;
	return obj_tab_enabled(ctx, obj);
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
	// EditText::on_focus_changed(focused=false) runs BEFORE the AVM2 focusOut
	// (Ruffle set_internal calls on_focus_changed then call_focus_handler), and
	// commits any open IME composition — so the preedit becomes real text and
	// fires its textInput before anything observes the focus change.
	if (old != NULL) avm2_text_ime_commit_pending(ctx, old);
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
	// "The highlight always follows the focus" (FocusTracker::set_internal).
	// Only a real focus CHANGE recomputes it — the early return above is what
	// makes `stage.stageFocusRect = false; stage.focus = <already focused>`
	// leave a visible highlight alone.
	avm2_update_highlight(ctx);
}

// Ruffle Player::update_focus_on_mouse_press + FocusTracker::set_by_mouse.
//
// The pressed object itself is the candidate — there is no walk up to the
// nearest focusable ancestor (the pick already propagates to the parent when
// a child is not a valid target). AVM2 content dispatches the focus-change
// event even when that candidate is not focusable; only *setting* the focus
// is filtered, which is what makes `mouseFocusChange` fire with a
// `relatedObject` while `stage.focus` stays put.
static void update_focus_on_press(Avm2Context* ctx, Avm2Object* pressed)
{
	// The stage is "no object" for focus purposes.
	if (pressed == ctx->stage) pressed = NULL;
	Avm2Object* old = g_stage_focus;
	Avm2Object* target;
	if (pressed != NULL)
	{
		target = pressed;  // should_focus: always true for AS3 content
	}
	else if (old != NULL && is_focusable_by_mouse(ctx, old))
	{
		target = NULL;  // clicking away clears a mouse-acquired focus
	}
	else
	{
		return;  // nothing was focusable either side; no event
	}
	// set_by_mouse: unchanged object dispatches nothing (unlike keyFocusChange).
	if (old == target) return;
	// dispatch_focus_change_event: the OLD focus is the target, falling back to
	// the stage when there is none.
	Avm2Object* dispatch_on = old != NULL ? old : ctx->stage;
	Avm2Object* ev = avm2_focus_event_new(ctx,
		avm2_string_from_literal(ctx, "mouseFocusChange"), 1, 1, target, 0,
		0, "none");
	avm2_dispatch_event(ctx, dispatch_on, ev);
	Avm2EventExt* eext = (Avm2EventExt*) ev->native_ext;
	if (eext != NULL && eext->cancelled) return;
	// `new.filter(is_focusable_by_mouse)` — the event fires for anything, the
	// focus only lands on something that can hold it.
	if (target != NULL && !is_focusable_by_mouse(ctx, target)) target = NULL;
	set_focus(ctx, target);
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

// World top-left (twips) of the HIGHLIGHT bounds — the input to the automatic
// order key 6*y + x. Ruffle InteractiveObject::highlight_bounds is the world
// bounds, except for SimpleButton (avm2_button.rs:811), which uses its
// hit-area child instead: a button's own render list is empty because its
// states live outside it.
//
// Invalid bounds map to Twips::INVALID on BOTH axes, not to the origin
// (`Matrix * Rectangle::INVALID == Rectangle::INVALID`, render/src/matrix.rs).
// That distinction is load-bearing: a stateless `new SimpleButton()` has no
// hit area, so keying it at 0 collides with every other object whose top-left
// is (0,0) and the equal-key dedup below then drops it from the order
// entirely (avm2/tab_ordering_tabbable). Ruffle sorts it to the far end.
#define TWIPS_INVALID 134217727.0   /* swf::Twips::INVALID == 0x7ffffff */

// Ruffle InteractiveObject::highlight_bounds, as a whole rectangle.
// `Rectangle::INVALID` sets ALL FOUR edges to `Twips::INVALID`, not just the
// top-left (swf/src/types/rectangle.rs:84) — the directional-navigation keys
// below compare every edge, so the full sentinel matters there.
static void obj_highlight_bounds(Avm2Context* ctx, Avm2Object* obj, Rect* out)
{
	avm2_text_apply_pending_bounds(ctx, obj);
	Mat m = display_world_matrix(ctx, obj);
	Rect r = { 0, 0, 0, 0, 0 };
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (obj != NULL && class_is_a(obj->cls, ctx->builtins.simple_button_class))
	{
		Avm2Object* hit = e != NULL ? e->btn_hit : NULL;
		Avm2DisplayObjectExt* he = hit != NULL
			? avm2_display_ext_of(ctx, hit) : NULL;
		if (he != NULL)
		{
			Mat hl = ext_matrix(he);
			Mat hw = mat_mul(&m, &hl);
			bounds_with_transform(ctx, hit, &hw, &r);
		}
	}
	else
	{
		bounds_with_transform(ctx, obj, &m, &r);
	}
	if (r.valid)
	{
		// Ruffle's bounds are `Rectangle<Twips>` — whole twips. Ours are
		// doubles, and the difference is load-bearing: a sprite scaled to
		// `height = 12` over 10px of content lands at 12.0000005px here, and
		// the navigation keys below compare rectangle edges with exact `<=`.
		// `tab_ordering_arrows`'s "Size vs distance behind" stage puts two
		// objects' `y_max` EXACTLY on the origin's, where a half-microtwip
		// decides whether they are candidates at all. Same lesson as tranche
		// 2's `local_mouse` snap.
		out->valid = 1;
		out->xmin = nearbyint(r.xmin); out->xmax = nearbyint(r.xmax);
		out->ymin = nearbyint(r.ymin); out->ymax = nearbyint(r.ymax);
		return;
	}
	out->valid = 0;
	out->xmin = out->xmax = out->ymin = out->ymax = TWIPS_INVALID;
}

static void obj_world_topleft(Avm2Context* ctx, Avm2Object* obj,
                              double* x, double* y)
{
	Rect r;
	obj_highlight_bounds(ctx, obj, &r);
	*x = r.xmin;
	*y = r.ymin;
}

// ---------------------------------------------------------------------------
// Focus highlight (Ruffle focus_tracker.rs `Highlight`)
// ---------------------------------------------------------------------------
// 0 = Inactive, 1 = ActiveHidden, 2 = ActiveVisible. The state is CACHED at
// focus-change time (`g_avm2_highlight`, declared above) and only the bounds
// are recomputed at render time, which is what makes `stageFocusRect` /
// `focusRect` writes that are *not* followed by a focus change invisible to an
// already-drawn highlight.

// Ruffle InteractiveObject::is_highlight_enabled — the object's own focusRect
// (Object-typed: null/undefined means "inherit"), falling back to the stage's.
// The `movie().version() >= 6` arm is unconditional here: AVM2 is SWF 9+.
static int obj_is_highlight_enabled(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e != NULL && e->focus_rect_set) return e->focus_rect_val != 0;
	return g_stage_focus_rect != 0;
}

// Ruffle InteractiveObject::is_highlightable, plus the per-type overrides:
//   Stage        -> false ("Stage cannot be highlighted")
//   MovieClip    -> !is_root && is_highlight_enabled
//   EditText     -> false ("TextField is incapable of rendering a highlight")
static int obj_is_highlightable(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* e = avm2_display_ext_of(ctx, obj);
	if (e == NULL || e->is_stage) return 0;
	if (e->edittext != NULL) return 0;
	if (e->is_root) return 0;
	return obj_is_highlight_enabled(ctx, obj);
}

// Ruffle FocusTracker::calculate_highlight. Degenerate bounds (invalid, or a
// single point) hide the highlight without deactivating it — that is FP's
// "clip focused before it had any content" behaviour, and it is also what
// keeps `focus_highlight_empty_clip` blank.
static void avm2_update_highlight(Avm2Context* ctx)
{
	if (g_stage_focus == NULL) { g_avm2_highlight = 0; return; }
	if (!obj_is_highlightable(ctx, g_stage_focus)) { g_avm2_highlight = 1; return; }
	Rect r;
	obj_highlight_bounds(ctx, g_stage_focus, &r);
	if (!r.valid || (r.xmin == r.xmax && r.ymin == r.ymax))
	{
		g_avm2_highlight = 1;
		return;
	}
	g_avm2_highlight = 2;
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

// Ruffle TabOrder::fill + the tabIndex retention in `add_object`: once any
// object carries a tabIndex, the order keeps ONLY such objects — for keyboard
// navigation too, not just tabbing. Unsorted; `*any_index` reports which
// ordering the caller should apply.
static uint32_t collect_tab_order(Avm2Context* ctx, TabEnt* list, uint32_t cap,
                                  int* any_index)
{
	uint32_t n = 0;
	*any_index = 0;
	fill_tab_order(ctx, ctx->stage, list, &n, cap, any_index);
	if (*any_index)
	{
		uint32_t m = 0;
		for (uint32_t i = 0; i < n; i++)
			if (list[i].has_index) list[m++] = list[i];
		n = m;
	}
	return n;
}

// Build the sorted tab order into `out` (Ruffle TabOrder::sort). Returns count.
static uint32_t build_tab_order(Avm2Context* ctx, Avm2Object** out, uint32_t cap)
{
	TabEnt list[256];
	int any_index = 0;
	uint32_t n = collect_tab_order(ctx, list, 256, &any_index);
	if (any_index)
	{
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

// Ruffle FocusTracker::set_by_key: a cancelable, bubbling `keyFocusChange` on
// the current focus (or the Stage) with `relatedObject` = the candidate, then
// the move — unless a listener called preventDefault().
static void focus_change_by_key(Avm2Context* ctx, Avm2Object* next,
                                int32_t key_code, int shift)
{
	Avm2Object* cur = g_stage_focus;
	Avm2Object* dispatch_on = cur != NULL ? cur : ctx->stage;
	Avm2Object* ev = avm2_focus_event_new(ctx,
		avm2_string_from_literal(ctx, "keyFocusChange"), 1, 1, next, shift,
		key_code, "none");
	avm2_dispatch_event(ctx, dispatch_on, ev);
	Avm2EventExt* eext = (Avm2EventExt*) ev->native_ext;
	if (eext == NULL || !eext->cancelled)
		set_focus(ctx, next);
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
	focus_change_by_key(ctx, next, 9, shift);
	// FocusTracker::cycle updates the highlight AGAIN after set_by_key, and
	// unconditionally: Tab onto the object that already holds focus (a one-entry
	// tab order, or a mouse press that reset the highlight without moving the
	// focus) must still re-activate it.
	avm2_update_highlight(ctx);
}

// ---------------------------------------------------------------------------
// Arrow-key directional focus (Ruffle FocusTracker::navigate +
// NavigationOrdering). The algorithm is ~90 lines of rectangle arithmetic in
// focus_tracker.rs; `avm2/tab_ordering_arrows` is its 998-line acceptance
// table (60-odd declarative stages x 4 directions), not 998 lines of work.
// ---------------------------------------------------------------------------

enum { NAV_UP = 0, NAV_RIGHT, NAV_DOWN, NAV_LEFT };

// x- or y-axis distance between two rectangles (Ruffle calculate_distance).
static double nav_axis_distance(const Rect* a, const Rect* b, int vertical)
{
	double p = vertical ? a->ymax - b->ymin : a->xmax - b->xmin;
	double q = vertical ? b->ymax - a->ymin : b->xmax - a->xmin;
	return p > q ? p : q;
}

// NavigationOrdering::key. Returns 0 for Ruffle's `None` (object excluded);
// otherwise fills the (category, distance) pair that objects are min'd by.
// Category 0 is "directly behind the origin along the axis", category 1 is the
// Down-only left/right band, category 2 is everything else by 2D distance.
static int nav_key(const Rect* o, const Rect* t, int dir,
                   int* cat, double* dist)
{
	switch (dir)
	{
	case NAV_DOWN:
		if (t->ymax <= o->ymax) return 0;
		if (t->xmax >= o->xmin && t->xmin <= o->xmax)
			{ *cat = 0; *dist = t->ymin - o->ymin; return 1; }
		// Down is the only direction with this rule: an object level with the
		// origin outranks one further away, but never one behind it.
		if (t->ymin <= o->ymax)
			{ *cat = 1; *dist = nav_axis_distance(o, t, 0); return 1; }
		break;
	case NAV_UP:
		if (t->ymax >= o->ymax) return 0;
		if (t->xmax >= o->xmin && t->xmin <= o->xmax)
			{ *cat = 0; *dist = o->ymax - t->ymax; return 1; }
		break;
	case NAV_RIGHT:
		if (t->xmax <= o->xmax) return 0;
		if (t->ymax >= o->ymin && t->ymin <= o->ymax)
			{ *cat = 0; *dist = t->xmin - o->xmin; return 1; }
		break;
	case NAV_LEFT:
		if (t->xmin >= o->xmin) return 0;
		if (t->ymax >= o->ymin && t->ymin <= o->ymax)
			{ *cat = 0; *dist = o->xmax - t->xmax; return 1; }
		break;
	default:
		return 0;
	}
	double dx = nav_axis_distance(o, t, 0), dy = nav_axis_distance(o, t, 1);
	*cat = 2;
	*dist = dx * dx + dy * dy;
	return 1;
}

static void input_handle_navigate(Avm2Context* ctx, int32_t key_code)
{
	int dir;
	switch (key_code)
	{
	case 37: dir = NAV_LEFT; break;
	case 38: dir = NAV_UP; break;
	case 39: dir = NAV_RIGHT; break;
	case 40: dir = NAV_DOWN; break;
	default: return;
	}
	Avm2Object* cur = g_stage_focus;
	if (cur == NULL) return;   // Ruffle: no focus, nothing to navigate from

	Rect origin;
	obj_highlight_bounds(ctx, cur, &origin);

	// `navigate` reads the UNSORTED filled order and takes the minimum; ties go
	// to the first in fill order (Rust `min_by_key` keeps the first minimum),
	// and unlike the automatic order there is no equal-key dedup.
	TabEnt list[256];
	int any_index = 0;
	uint32_t n = collect_tab_order(ctx, list, 256, &any_index);

	Avm2Object* best = NULL;
	int best_cat = 0;
	double best_dist = 0.0;
	for (uint32_t i = 0; i < n; i++)
	{
		Rect t;
		obj_highlight_bounds(ctx, list[i].obj, &t);
		int cat = 0; double dist = 0.0;
		if (!nav_key(&origin, &t, dir, &cat, &dist)) continue;
		if (best != NULL
		    && !(cat < best_cat || (cat == best_cat && dist < best_dist)))
			continue;
		best = list[i].obj; best_cat = cat; best_dist = dist;
	}
	// Nothing in that direction dispatches NOTHING — not even a cancelled
	// keyFocusChange (focus_events_key_navigation's "Pressed right" from the
	// rightmost sprite traces the keyDown and then falls silent).
	if (best == NULL) return;
	focus_change_by_key(ctx, best, key_code, 0);
}

static void input_handle_key(Avm2Context* ctx, int is_down, int32_t key_code,
                             int32_t char_code, int32_t key_location)
{
	dispatch_key(ctx, is_down, key_code, char_code, key_location);
	// Tab drives focus traversal on keyDown (after the keyDown dispatch).
	if (is_down && key_code == 9)
		input_handle_tab(ctx, mod_shift());
	// Arrows drive directional focus navigation, after the Tab branch
	// (Ruffle player.rs: "KeyPress events also take precedence over keyboard
	// navigation", then `NavigationDirection::from_key_code`).
	if (is_down)
		input_handle_navigate(ctx, key_code);
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
	add_getset(ctx, dobj, "blendShader", NULL, do_blendshader_set);
	add_getset(ctx, dobj, "scale9Grid", do_scale9grid_get, do_scale9grid_set);
	add_getset(ctx, dobj, "z", do_get_zero, do_set_noop);
	add_getset(ctx, dobj, "rotationX", do_get_zero, do_set_noop);
	add_getset(ctx, dobj, "rotationY", do_get_zero, do_set_noop);
	add_getset(ctx, dobj, "rotationZ", do_get_rotation, do_set_rotation);
	add_getset(ctx, dobj, "scaleZ", do_get_one, do_set_noop);

	// flash.display.LoaderInfo (extends EventDispatcher). Every getter reads
	// the receiving instance's stream state; the root movie's and the Stage's
	// instances are lazily built by avm2_get_{root,stage}_loader_info.
	Avm2Class* linfo =
		avm2_builtin_class(ctx, "flash.display", "LoaderInfo",
		                   b->event_dispatcher_class);
	linfo->native_ext_size = sizeof(Avm2LoaderInfoExt);
	b->loader_info_class = linfo;
	avm2_builtin_add_getter(ctx, linfo, "bytesLoaded", li_get_bytes_loaded);
	avm2_builtin_add_getter(ctx, linfo, "bytesTotal", li_get_bytes_total);
	avm2_builtin_add_getter(ctx, linfo, "bytes", li_get_bytes);
	avm2_builtin_add_getter(ctx, linfo, "content", li_get_content);
	avm2_builtin_add_getter(ctx, linfo, "contentType", li_get_content_type);
	avm2_builtin_add_getter(ctx, linfo, "actionScriptVersion", li_get_as_version);
	avm2_builtin_add_getter(ctx, linfo, "frameRate", li_get_frame_rate);
	avm2_builtin_add_getter(ctx, linfo, "width", li_get_width);
	avm2_builtin_add_getter(ctx, linfo, "height", li_get_height);
	avm2_builtin_add_getter(ctx, linfo, "swfVersion", li_get_swf_version);
	avm2_builtin_add_getter(ctx, linfo, "url", li_get_url);
	avm2_builtin_add_getter(ctx, linfo, "loaderURL", li_get_loader_url);
	avm2_builtin_add_getter(ctx, linfo, "parameters", li_get_parameters);
	avm2_builtin_add_getter(ctx, linfo, "applicationDomain",
	                        li_get_application_domain);
	avm2_builtin_add_getter(ctx, linfo, "loader", li_get_loader);
	avm2_builtin_add_getter(ctx, linfo, "isURLInaccessible",
	                        li_get_is_url_inaccessible);
	avm2_builtin_add_getter(ctx, linfo, "sharedEvents", li_get_shared_events);
	avm2_builtin_add_getter(ctx, linfo, "childAllowsParent", li_get_allows);
	avm2_builtin_add_getter(ctx, linfo, "parentAllowsChild", li_get_allows);
	avm2_builtin_add_getter(ctx, linfo, "sameDomain", li_get_allows);

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
	avm2_builtin_add_method(ctx, doc, "getObjectsUnderPoint",
	                        doc_get_objects_under_point);
	avm2_builtin_add_method(ctx, doc, "areInaccessibleObjectsUnderPoint",
	                        doc_are_inaccessible_objects_under_point);
	avm2_builtin_add_getter(ctx, doc, "numChildren", doc_get_num_children);
	add_getset(ctx, doc, "mouseChildren", doc_get_mouse_children,
	           doc_set_mouse_children);
	add_getset(ctx, doc, "tabChildren", doc_get_tab_children, doc_set_tab_children);

	// flash.text.engine.TextLine (extends DisplayObjectContainer). The shell
	// lives here so it picks up the display alloc hook and ext; avm2_text.c
	// wires the FTE surface (validity, rawTextLength, the five #2181 setters).
	{
		Avm2Class* tl = avm2_builtin_class(ctx, "flash.text.engine", "TextLine",
		                                   doc);
		tl->native_init = textline_native_init;
		tl->native_ext_size = sizeof(Avm2TextLineExt);
		g_textline_class = tl;
		avm2_text_init_textline_class(ctx, tl);
	}

	// flash.display.Loader (extends DisplayObjectContainer). `new Loader()` is
	// non-throwing (concrete display_native_init, larger native_ext for the
	// per-instance contentLoaderInfo/content); load/loadBytes drive the
	// LoaderInfo state machine and event sequence, and decode an image payload
	// into a Bitmap `content`. A child SWF is still not instantiated
	// (loader-arc tranche 6), so `content` stays null for one.
	Avm2Class* loader =
		avm2_builtin_class(ctx, "flash.display", "Loader", doc);
	loader->native_init = display_native_init;   // concrete: no #2012
	loader->native_ext_size = sizeof(Avm2LoaderExt);
	b->loader_class = loader;
	avm2_builtin_add_getter(ctx, loader, "contentLoaderInfo",
	                        loader_get_content_loader_info);
	avm2_builtin_add_getter(ctx, loader, "content", loader_get_content);
	avm2_builtin_add_method(ctx, loader, "load", loader_load);
	avm2_builtin_add_method(ctx, loader, "loadBytes", loader_load_bytes);
	avm2_builtin_add_method(ctx, loader, "close", loader_noop);
	avm2_builtin_add_method(ctx, loader, "unload", loader_unload);
	avm2_builtin_add_method(ctx, loader, "unloadAndStop", loader_unload);

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

	// The AGI no-op shell (see loader_load): a concrete Sprite subclass seeded as
	// a Loader's `content` for the ArmorGames AGI SWF. Every AG-API method the
	// game calls on it (AGIStuff.loadComplete → init/initAGUI; MainMenu New Game →
	// hideAGILogin → hideLoginStatus; and the guarded show*/submit*/retrieve*
	// paths) is a no-op returning undefined. Internal name — the game never
	// constructs it by QName, only receives it as loaded content.
	Avm2Class* agishell = avm2_builtin_class(ctx, "swfrecomp.internal",
	                                         "AGINoopShell", sprite);
	agishell->native_init = display_native_init;   // concrete: no #2012
	agishell->instance_init.fn = sprite_ctor_init;  // constructChildren like Sprite
	agishell->instance_init.debug_name = "AGINoopShell";
	static const char* const agi_noop_methods[] = {
		"init", "initAGUI", "hideLoginStatus", "showLoginStatus",
		"retrieveUserData", "submitUserData", "showScoreboardSubmit",
		"showScoreboardList", "showGameShareList", "showGameShareNavi",
		"showAGILogin", "hideAGILogin", NULL };
	for (int i = 0; agi_noop_methods[i] != NULL; i++)
		avm2_builtin_add_method(ctx, agishell, agi_noop_methods[i], loader_noop);
	g_agi_shell_class = agishell;

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

	// flash.display.MorphShape (extends DisplayObject): timeline-only —
	// `new MorphShape()` throws #2012, timeline placement constructs normally.
	Avm2Class* morphshape = avm2_builtin_class(ctx, "flash.display",
	                                           "MorphShape", dobj);
	morphshape->native_init = morphshape_native_init;
	g_morphshape_class = morphshape;

	// flash.display.Bitmap (extends DisplayObject, NOT InteractiveObject).
	// The class shell + display alloc hook live here so the display tree
	// wiring matches; the ctor/accessors are added by avm2_bitmap.c.
	Avm2Class* bitmap = avm2_builtin_class(ctx, "flash.display", "Bitmap", dobj);
	bitmap->native_init = display_native_init;
	b->bitmap_class = bitmap;
	avm2_bitmap_wire_bitmap(ctx, bitmap);

	// flash.media.Video (extends DisplayObject). It lives here rather than in
	// avm2_media.c because everything it needs — display_native_init and the
	// draw-AABB that gives it intrinsic bounds — is private to this file.
	Avm2Class* video = avm2_builtin_class(ctx, "flash.media", "Video", dobj);
	g_video_class = video;
	video->native_init = display_native_init;
	video->instance_init.fn = video_init;
	video->instance_init.debug_name = "Video";
	avm2_builtin_add_getset(ctx, video, "deblocking", video_get_deblocking,
	                        video_set_deblocking);
	avm2_builtin_add_getset(ctx, video, "smoothing", video_get_smoothing,
	                        video_set_smoothing);
	avm2_builtin_add_getter(ctx, video, "videoWidth", video_get_zero);
	avm2_builtin_add_getter(ctx, video, "videoHeight", video_get_zero);
	avm2_builtin_add_method(ctx, video, "attachNetStream", video_noop);
	avm2_builtin_add_method(ctx, video, "attachCamera", video_noop);
	avm2_builtin_add_method(ctx, video, "clear", video_noop);

	// flash.text.TextField / StaticText. The property surface lives in
	// avm2_text.c (Stage 6); the class shell stays here so the display
	// alloc hook and timeline instantiation wire up.
	Avm2Class* textfield = avm2_builtin_class(ctx, "flash.text", "TextField", iobj);
	textfield->native_init = display_native_init;
	g_textfield_class = textfield;
	avm2_text_init_textfield_class(ctx, textfield);
	// StaticText is [Ruffle(Abstract)] but IS timeline-instantiable, so it
	// takes MorphShape's conditional gate rather than the unconditional
	// abstract one: a script `new StaticText()` is #2012, a DefineText
	// placement is not.
	Avm2Class* statictext = avm2_builtin_class(ctx, "flash.text", "StaticText", dobj);
	statictext->native_init = morphshape_native_init;
	g_statictext_class = statictext;

	// flash.display.AVM1Movie — the DisplayObject wrapper an AVM2 movie sees
	// around a loaded AVM1 child. We do not execute cross-VM children yet, so
	// nothing ever mints one; the class exists to resolve.
	{
		Avm2Class* avm1movie = avm2_builtin_class(ctx, "flash.display",
		                                          "AVM1Movie", dobj);
		avm1movie->native_init = display_native_init_abstract;
	}

	// flash.display.Graphics (bounds-only stub); graphics getter on both
	// Shape and Sprite.
	Avm2Class* graphics = avm2_builtin_class(ctx, "flash.display", "Graphics",
	                                         b->object_class);
	graphics->native_ext_size = sizeof(Avm2GraphicsExt);
	avm2_builtin_add_method(ctx, graphics, "beginFill", gfx_begin_fill);
	avm2_builtin_add_method(ctx, graphics, "beginGradientFill", gfx_begin_gradient_fill);
	avm2_builtin_add_method(ctx, graphics, "beginBitmapFill", gfx_begin_bitmap_fill);
	avm2_builtin_add_method(ctx, graphics, "lineBitmapStyle", gfx_line_fill_style);
	avm2_builtin_add_method(ctx, graphics, "lineGradientStyle", gfx_line_fill_style);
	avm2_builtin_add_method(ctx, graphics, "lineShaderStyle", gfx_line_fill_style);
	avm2_builtin_add_method(ctx, graphics, "beginShaderFill", gfx_begin_bitmap_fill);
	avm2_builtin_add_method(ctx, graphics, "endFill", gfx_end_fill);
	avm2_builtin_add_method(ctx, graphics, "lineStyle", gfx_line_style);
	avm2_builtin_add_method(ctx, graphics, "clear", gfx_clear);
	avm2_builtin_add_method(ctx, graphics, "moveTo", gfx_move_to);
	avm2_builtin_add_method(ctx, graphics, "lineTo", gfx_line_to);
	avm2_builtin_add_method(ctx, graphics, "curveTo", gfx_curve_to);
	avm2_builtin_add_method(ctx, graphics, "cubicCurveTo", gfx_cubic_curve_to);
	avm2_builtin_add_method(ctx, graphics, "drawRect", gfx_draw_rect);
	avm2_builtin_add_method(ctx, graphics, "drawRoundRect", gfx_draw_rect);
	avm2_builtin_add_method(ctx, graphics, "drawRoundRectComplex",
	                        gfx_draw_round_rect_complex);
	avm2_builtin_add_method(ctx, graphics, "drawEllipse", gfx_draw_ellipse);
	avm2_builtin_add_method(ctx, graphics, "drawCircle", gfx_draw_circle);
	avm2_builtin_add_method(ctx, graphics, "copyFrom", gfx_noop);
	g_graphics_class = graphics;
	// T4: drawPath/drawTriangles/drawGraphicsData + the Graphics* data classes.
	avm2_graphics_register(ctx, graphics, b->object_class);
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
	           transform_get_concat_color_transform, NULL);
	add_getset(ctx, geom_transform, "concatenatedMatrix",
	           transform_get_concatenated_matrix, NULL);
	add_getset(ctx, geom_transform, "matrix3D", transform_get_matrix3d,
	           transform_set_stub);
	add_getset(ctx, geom_transform, "perspectiveProjection",
	           transform_get_perspective_projection,
	           transform_set_perspective_projection);
	add_getset(ctx, geom_transform, "pixelBounds",
	           transform_get_pixel_bounds, NULL);
	g_transform_class = geom_transform;

	// flash.geom.PerspectiveProjection + Vector3D constructible stubs.
	// Matrix3D used to be a bare stub here too; it is a real class now and
	// lives in avm2_stage3d.c (setProgramConstantsFromMatrix needs it), which
	// registers AFTER this — so creating a shell here would shadow it.
	{
		Avm2Class* pp = avm2_builtin_class(ctx, "flash.geom",
		                                   "PerspectiveProjection",
		                                   b->object_class);
		pp->instance_init.fn = pp_init;
		pp->instance_init.debug_name = "PerspectiveProjection";
		g_pperspective_class = pp;
		avm2_builtin_add_getset(ctx, pp, "fieldOfView", pp_get_fov, pp_set_fov);
		avm2_builtin_add_getset(ctx, pp, "focalLength", pp_get_focal_length,
		                        pp_set_focal_length);
		avm2_builtin_add_getset(ctx, pp, "projectionCenter", pp_get_center,
		                        pp_set_center);
		avm2_builtin_add_method(ctx, pp, "toMatrix3D", pp_to_matrix3d);
		Avm2Class* v3 = avm2_builtin_class(ctx, "flash.geom", "Vector3D",
		                                   b->object_class);
		v3->instance_init.fn = geom_vector3d_init;
		v3->instance_init.debug_name = "Vector3D";
		g_vector3d_class = v3;
		avm2_builtin_add_getter(ctx, v3, "length", v3_get_length);
		avm2_builtin_add_getter(ctx, v3, "lengthSquared", v3_get_length_squared);
		avm2_builtin_add_method(ctx, v3, "toString", v3_to_string);
		avm2_builtin_add_method(ctx, v3, "add", v3_add);
		avm2_builtin_add_method(ctx, v3, "subtract", v3_subtract);
		avm2_builtin_add_method(ctx, v3, "incrementBy", v3_increment_by);
		avm2_builtin_add_method(ctx, v3, "decrementBy", v3_decrement_by);
		avm2_builtin_add_method(ctx, v3, "clone", v3_clone);
		avm2_builtin_add_method(ctx, v3, "copyFrom", v3_copy_from);
		avm2_builtin_add_method(ctx, v3, "equals", v3_equals);
		avm2_builtin_add_method(ctx, v3, "nearEquals", v3_near_equals);
		avm2_builtin_add_method(ctx, v3, "setTo", v3_set_to);
		avm2_builtin_add_method(ctx, v3, "scaleBy", v3_scale_by);
		avm2_builtin_add_method(ctx, v3, "negate", v3_negate);
		avm2_builtin_add_method(ctx, v3, "project", v3_project);
		avm2_builtin_add_method(ctx, v3, "normalize", v3_normalize);
		avm2_builtin_add_method(ctx, v3, "dotProduct", v3_dot_product);
		avm2_builtin_add_method(ctx, v3, "crossProduct", v3_cross_product);
		avm2_builtin_add_static_method(ctx, v3, "angleBetween", v3_angle_between);
		avm2_builtin_add_static_method(ctx, v3, "distance", v3_distance);
		// The three axis constants. describeType reports them in this order
		// (Z before X before Y), which is the order Ruffle's .as declares.
		avm2_builtin_add_static_const(ctx, v3, "Z_AXIS", v3_make(ctx, 0, 0, 1, 0));
		avm2_builtin_add_static_const(ctx, v3, "X_AXIS", v3_make(ctx, 1, 0, 0, 0));
		avm2_builtin_add_static_const(ctx, v3, "Y_AXIS", v3_make(ctx, 0, 1, 0, 0));
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
		avm2_builtin_add_method(ctx, ct, "concat", colortransform_concat);
		avm2_builtin_add_getset(ctx, ct, "color", colortransform_get_color,
		                        colortransform_set_color);
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

	// flash.display.Stage. [Ruffle(Abstract)] to script, but the player mints
	// the one real stage itself — so the gate is script-only, like MorphShape's
	// is timeline-only.
	Avm2Class* stage = avm2_builtin_class(ctx, "flash.display", "Stage", doc);
	stage->native_init = stage_native_init;
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
	add_getset(ctx, stage, "tabChildren", stage_get_tab_children,
	           stage_set_tab_children);
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
			{ "scale9Grid", do_scale9grid_get }, { "scaleX", do_get_scale_x },
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

		// The three constant bags Graphics.beginGradientFill's own signature
		// names — its `type`/`spreadMethod`/`interpolationMethod` arguments
		// are compared as strings, so these only have to exist.
		Avm2Class* gtc = avm2_builtin_class(ctx, "flash.display",
		                                    "GradientType", b->object_class);
		disp_sconst(ctx, gtc, "LINEAR", "linear");
		disp_sconst(ctx, gtc, "RADIAL", "radial");

		Avm2Class* spm = avm2_builtin_class(ctx, "flash.display",
		                                    "SpreadMethod", b->object_class);
		disp_sconst(ctx, spm, "PAD", "pad");
		disp_sconst(ctx, spm, "REFLECT", "reflect");
		disp_sconst(ctx, spm, "REPEAT", "repeat");

		Avm2Class* ipm = avm2_builtin_class(ctx, "flash.display",
		                                    "InterpolationMethod", b->object_class);
		disp_sconst(ctx, ipm, "RGB", "rgb");
		disp_sconst(ctx, ipm, "LINEAR_RGB", "linearRGB");

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
	else if (ext->is_morph_shape && ext->shape_vert_count > 0)
		// T6: CPU twin of avm2_render_morph — ratio-lerp the START/END verts +
		// solid colour into the framebuffer.
		avm2_cpu_raster_morph(fb, fbw, fbh, /*transparent=*/0,
		                      ext->shape_vert_offset, ext->shape_vert_count,
		                      ext->morph_end_offset,
		                      (double) ext->ratio / 65535.0,
		                      world.a, world.b, world.c, world.d,
		                      world.tx, world.ty, alpha);
	else if (ext->shape_vert_count > 0)
		// T5: CPU-composite a resident timeline shape (the headless twin of
		// avm2_render_shape's GPU dispatch), mirroring the WGSL shader so the
		// dump matches the Dawn/Ruffle pixels. fb is premultiplied ARGB.
		avm2_cpu_raster_shape(fb, fbw, fbh, /*transparent=*/0,
		                      ext->shape_vert_offset, ext->shape_vert_count,
		                      world.a, world.b, world.c, world.d,
		                      world.tx, world.ty, alpha);

	// Native timeline TextField (DefineEditText) glyphs — CPU twin of
	// avm2_render_text. Composites the laid-out field glyphs into the dump.
	if (ext->edittext != NULL)
		avm2_cpu_raster_text(fb, fbw, fbh, /*transparent=*/0, ctx, obj,
		                     world.a, world.b, world.c, world.d,
		                     world.tx, world.ty, alpha);

	// Native timeline static text (DefineText/2) glyphs — CPU twin of
	// avm2_render_statictext.
	if (ext->statictext != NULL)
		avm2_cpu_raster_statictext(fb, fbw, fbh, /*transparent=*/0, ctx, obj,
		                           world.a, world.b, world.c, world.d,
		                           world.tx, world.ty, alpha);

	// T4: script-drawn Graphics geometry (independent of a timeline shape).
	avm2_graphics_cpu_composite(ctx, obj, world.a, world.b, world.c, world.d,
	                            world.tx, world.ty, alpha, fb, fbw, fbh, 0);

	// SimpleButton: paint the current state child (Ruffle render_self). It
	// lives in btn_up/btn_over/btn_down, never in render_list, so the loop
	// below cannot reach it. Kept in lockstep with avm2_render_node or the
	// CPU dump and the GPU render diverge on every button.
	{
		Avm2Object* bst = avm2_button_state_child(ext);
		if (bst != NULL) avm2_cpu_walk(ctx, bst, &world, alpha, fb, fbw, fbh);
	}

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

// Draw one renderable timeline shape node: its pre-tessellated triangles
// (resident shape_data vertex range, resolved onto the ext at place-time) under
// the node's world matrix + concatenated alpha. Mirrors avm2_render_bitmap's
// slot-write model, swapping the bitmap quad for renderer_draw_shape — one draw
// covers every triangle, shaded per-vertex by the WGSL shader from the packed
// style bits: solid color index (T1), stroke 0x80000000 color index (T2), and
// gradient fill_type|spread|interp sampling the resident ramp (T3). The world
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

// Resident recompiler geometry (draws.c), read directly for the morph lerp —
// the same globals avm2_cpu_raster.c reads. shape_data/color_data are also
// mirrored into the render context, but the START/END lerp is cleanest against
// the raw tables. morph_end_* are NOT copied into the context (T6 loads them
// as externs, the T5 pattern).
extern uint32_t shape_data[][4];
extern float    color_data[][4];
extern float    morph_end_shape_data[][2];
extern float    morph_end_color_data[][4];

static inline float avm2_bits_to_f(uint32_t u)
{
	float f;
	memcpy(&f, &u, sizeof(f));
	return f;
}

// T6 — draw a DefineMorphShape node on the GPU at its placement ratio. Lerped
// vertices are RUNTIME geometry (per-frame lerp(start, end, ratio)), so they go
// through the runtime-tris path (renderer_draw_tris) T4 built, NOT the static
// renderer_draw_shape. Solid fills lerp colour too; consecutive same-style
// triangles are batched into one draw (the recompiler emits each fill's tris
// contiguously). Gradient / stroke morph is deferred (skipped). CPU twin:
// avm2_cpu_raster_morph.
static void avm2_render_morph(Avm2Context* ctx, Avm2Object* obj,
                              const Mat* world, double alpha)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->shape_vert_count == 0) return;
	double ratio = (double) ext->ratio / 65535.0;
	if (ratio < 0.0) ratio = 0.0; else if (ratio > 1.0) ratio = 1.0;
	double b_w = ratio, a_w = 1.0 - ratio;  // Ruffle: b weights END, a START

	uint32_t n = ext->shape_vert_count;
	float* verts = (float*) malloc((size_t) n * 2 * sizeof(float));
	if (verts == NULL) return;
	for (uint32_t i = 0; i < n; i++)
	{
		uint32_t si = ext->shape_vert_offset + i;
		uint32_t ei = ext->morph_end_offset + i;
		double sxs = (double) avm2_bits_to_f(shape_data[si][0]);
		double sys = (double) avm2_bits_to_f(shape_data[si][1]);
		double sxe = (double) morph_end_shape_data[ei][0];
		double sye = (double) morph_end_shape_data[ei][1];
		// Ruffle lerp_twips: round(start*a + end*b) to integer twips.
		verts[i * 2]     = (float) floor(sxs * a_w + sxe * b_w + 0.5);
		verts[i * 2 + 1] = (float) floor(sys * a_w + sye * b_w + 0.5);
	}

	uint32_t xid = 0;
	if (g_avm2_xform_next < context->xform_slot_count)
	{
		float m16[16];
		avm2_world_to_mat16(world, m16);
		xid = g_avm2_xform_next++;
		renderer_write_transform(context, xid, m16);
	}
	uint32_t cxid = 0;
	if (alpha < 0.999 && g_avm2_cxform_next < context->cxform_slot_count)
	{
		float cx[20];
		memset(cx, 0, sizeof(cx));
		cx[0] = 1.0f; cx[5] = 1.0f; cx[10] = 1.0f;
		cx[15] = (float) alpha;
		cxid = g_avm2_cxform_next++;
		renderer_write_cxform(context, cxid, cx);
	}

	uint32_t t = 0;
	while (t + 3 <= n)
	{
		uint32_t i0 = ext->shape_vert_offset + t;
		uint32_t style_packed = shape_data[i0][2];
		uint32_t style_index  = shape_data[i0][3];
		uint32_t style_type   = style_packed & 0xFFu;

		// Extend the run over triangles sharing this exact style_index.
		uint32_t run_end = t + 3;
		while (run_end + 3 <= n
		       && (shape_data[ext->shape_vert_offset + run_end][2] & 0xFFu) == style_type
		       && shape_data[ext->shape_vert_offset + run_end][3] == style_index)
			run_end += 3;

		if (style_type == 0x00u)
		{
			// Ruffle lerp_color: (a*start + b*end) as u8 (truncation), per
			// channel. color_data holds u8/255; recover u8, lerp, re-normalise.
			uint32_t sid = style_index & 0xFFFFu;
			uint32_t eid = (style_index >> 16) & 0xFFFFu;
			uint32_t sr = (uint32_t)(color_data[sid][0]*255.0f+0.5f), er = (uint32_t)(morph_end_color_data[eid][0]*255.0f+0.5f);
			uint32_t sg = (uint32_t)(color_data[sid][1]*255.0f+0.5f), eg = (uint32_t)(morph_end_color_data[eid][1]*255.0f+0.5f);
			uint32_t sb = (uint32_t)(color_data[sid][2]*255.0f+0.5f), eb = (uint32_t)(morph_end_color_data[eid][2]*255.0f+0.5f);
			uint32_t sa = (uint32_t)(color_data[sid][3]*255.0f+0.5f), ea = (uint32_t)(morph_end_color_data[eid][3]*255.0f+0.5f);
			float r = (float)(uint32_t)(a_w * sr + b_w * er) / 255.0f;
			float g = (float)(uint32_t)(a_w * sg + b_w * eg) / 255.0f;
			float b = (float)(uint32_t)(a_w * sb + b_w * eb) / 255.0f;
			float a = (float)(uint32_t)(a_w * sa + b_w * ea) / 255.0f;
			renderer_draw_tris(context, &verts[t * 2], run_end - t,
			                   r, g, b, a, xid, cxid);
		}
		t = run_end;
	}
	free(verts);
}

// T4: draw a node's recorded flash.display.Graphics geometry on the GPU. One
// transform + cxform slot for the node, then per finalized path a solid /
// gradient fill (renderer_draw_tris / draw_gradient_tris, dynamic gradient pool)
// and a solid stroke. Mirrors action.c's render_drawing_path fill-type dispatch.
static void avm2_render_graphics(Avm2Context* ctx, Avm2Object* obj,
                                 const Mat* world, double alpha)
{
	Avm2GraphicsExt* g = gfx_node_ext(ctx, obj);
	if (g == NULL) return;
	gfx_finalize_path(g);
	if (g->path_count == 0) return;

	uint32_t xid = 0;
	if (g_avm2_xform_next < context->xform_slot_count)
	{
		float m16[16];
		avm2_world_to_mat16(world, m16);
		xid = g_avm2_xform_next++;
		renderer_write_transform(context, xid, m16);
	}
	uint32_t cxid = 0;
	if (alpha < 0.999 && g_avm2_cxform_next < context->cxform_slot_count)
	{
		float cx[20];
		memset(cx, 0, sizeof(cx));
		cx[0] = 1.0f; cx[5] = 1.0f; cx[10] = 1.0f;
		cx[15] = (float) alpha;
		cxid = g_avm2_cxform_next++;
		renderer_write_cxform(context, cxid, cx);
	}

	for (uint32_t i = 0; i < g->path_count; i++)
	{
		Avm2GfxPath* p = &g->paths[i];
		if (p->fill_kind == 1 && p->fill_vert_count >= 3)
			renderer_draw_tris(context, p->fill_verts, p->fill_vert_count,
			                   p->fr, p->fg, p->fb, p->fa, xid, cxid);
		else if (p->fill_kind == 2 && p->fill_vert_count >= 3)
			renderer_draw_gradient_tris(context, p->fill_verts, p->fill_vert_count,
			                            p->grad_type, p->grad_spread, p->grad_interp,
			                            p->grad_focal, p->grad_ramp, p->grad_fwd16,
			                            xid, cxid);
		if (p->has_line && p->line_vert_count >= 3)
			renderer_draw_tris(context, p->line_verts, p->line_vert_count,
			                   p->lr, p->lg, p->lb, p->la, xid, cxid);
	}
}

// avm2_text.c: layout-engine glyph collection (field-local twips placements).
uint32_t avm2_edittext_collect_glyphs(Avm2Context* ctx, Avm2Object* tf_obj,
                                      Avm2GlyphPlacement** out,
                                      int32_t out_clip[4]);
uint32_t avm2_statictext_collect_glyphs(Avm2Context* ctx,
                                        const Avm2StaticTextData* st,
                                        Avm2GlyphPlacement** out);

// Native TEXT/EDITTEXT — draw a timeline-placed TextField on the GPU. GPU twin of
// avm2_cpu_raster_text: collect the laid-out glyphs, tessellate each glyph's
// flattened outline (field-local twips: x_twips + scale*px, y_twips + scale*py)
// with libtess2 NONZERO winding (the same rule the CPU scanline uses, so glyph
// holes render), and draw per glyph via renderer_draw_tris under one
// world-transform + alpha-cxform slot. Chosen glyph-geometry form: runtime-
// tessellate outlines -> tris (the T4/T6 runtime-tris path — crisp, scale-
// independent). Device-font glyphs (no outlines) and x-clip to the field bounds
// are skipped (see avm2-native-text-render-plan.md). CPU twin: avm2_cpu_raster_text.
// Shared GPU glyph draw (placement-source-agnostic): tessellate + draw an
// already-collected Avm2GlyphPlacement[] under one world-transform + alpha-cxform
// slot. Both EditText (avm2_render_text) and static text (avm2_render_statictext)
// feed it, so the two sources share ONE GPU draw path. Caller owns `gl`.
static void avm2_render_glyphs(Avm2Context* ctx, const Avm2GlyphPlacement* gl,
                              uint32_t n, const Mat* world, double alpha)
{
	if (gl == NULL || n == 0) return;

	// One world-transform slot (field-local twips -> stage) for the whole field.
	uint32_t xid = 0;
	if (g_avm2_xform_next < context->xform_slot_count)
	{
		float m16[16];
		avm2_world_to_mat16(world, m16);
		xid = g_avm2_xform_next++;
		renderer_write_transform(context, xid, m16);
	}
	uint32_t cxid = 0;
	if (alpha < 0.999 && g_avm2_cxform_next < context->cxform_slot_count)
	{
		float cx[20];
		memset(cx, 0, sizeof(cx));
		cx[0] = 1.0f; cx[5] = 1.0f; cx[10] = 1.0f;
		cx[15] = (float) alpha;
		cxid = g_avm2_cxform_next++;
		renderer_write_cxform(context, cxid, cx);
	}

	for (uint32_t gi = 0; gi < n; gi++)
	{
		const Avm2FontData* fd = gl[gi].font;
		if (fd == NULL || fd->glyph_pts == NULL) continue;
		uint32_t g = gl[gi].glyph;
		uint32_t p0 = fd->glyph_pt_start[g], p1 = fd->glyph_pt_start[g + 1];
		uint32_t c0 = fd->glyph_contour_start[g], c1 = fd->glyph_contour_start[g + 1];
		uint32_t np = p1 - p0;
		if (np < 3 || c1 <= c0) continue;

		// Glyph outline points -> field-local twips (font units * scale = twips).
		double s = (double) gl[gi].scale;
		double bx = (double) gl[gi].x_twips, by = (double) gl[gi].y_twips;
		float* pts = (float*) malloc((size_t) np * 2 * sizeof(float));
		if (pts == NULL) continue;
		for (uint32_t i = 0; i < np; i++)
		{
			pts[i * 2]     = (float) (bx + s * (double) fd->glyph_pts[2 * (p0 + i)]);
			pts[i * 2 + 1] = (float) (by + s * (double) fd->glyph_pts[2 * (p0 + i) + 1]);
		}

		TESStesselator* tess = tessNewTess(NULL);
		if (tess != NULL)
		{
			tessSetOption(tess, TESS_CONSTRAINED_DELAUNAY_TRIANGULATION, 1);
			int contrib = 0;
			for (uint32_t k = c0; k < c1; k++)
			{
				uint32_t cs = (k == c0 ? p0 : fd->glyph_contour_ends[k - 1]) - p0;
				uint32_t ce = fd->glyph_contour_ends[k] - p0;
				int cn = (int) (ce - cs);
				if (cn < 3) continue;
				tessAddContour(tess, 2, &pts[cs * 2], sizeof(float) * 2, cn);
				contrib++;
			}
			if (contrib > 0 && tessTesselate(tess, TESS_WINDING_NONZERO,
			                                 TESS_POLYGONS, 3, 2, NULL))
			{
				const TESSreal* v = tessGetVertices(tess);
				const TESSindex* el = tessGetElements(tess);
				int nt = tessGetElementCount(tess);
				if (nt > 0)
				{
					float* verts = (float*) malloc((size_t) nt * 3 * 2 * sizeof(float));
					if (verts != NULL)
					{
						for (int i = 0; i < nt; i++)
							for (int j = 0; j < 3; j++)
							{
								TESSindex idx = el[i * 3 + j];
								verts[i * 6 + j * 2]     = v[idx * 2];
								verts[i * 6 + j * 2 + 1] = v[idx * 2 + 1];
							}
						uint32_t col = gl[gi].color;
						float r = (float) ((col >> 16) & 0xFF) / 255.0f;
						float gg = (float) ((col >> 8) & 0xFF) / 255.0f;
						float b = (float) (col & 0xFF) / 255.0f;
						renderer_draw_tris(context, verts, (uint32_t) nt * 3,
						                   r, gg, b, 1.0f, xid, cxid);
						free(verts);
					}
				}
			}
			tessDeleteTess(tess);
		}
		free(pts);
	}
}

// EditText/TextField GPU entry: collect the field's laid-out glyphs, draw via the
// shared avm2_render_glyphs. Thin wrapper (unchanged dispatch from
// avm2_render_node for ext->edittext).
static void avm2_render_text(Avm2Context* ctx, Avm2Object* obj,
                             const Mat* world, double alpha)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->edittext == NULL) return;
	Avm2GlyphPlacement* gl = NULL;
	int32_t clip[4];
	uint32_t n = avm2_edittext_collect_glyphs(ctx, obj, &gl, clip);
	if (n == 0)
	{
		if (gl != NULL) heap_free(ctx->app, gl);
		return;
	}
	avm2_render_glyphs(ctx, gl, n, world, alpha);
	heap_free(ctx->app, gl);
}

// Static text (DefineText/2 -> StaticText) GPU entry: same shared glyph draw,
// sourcing placements from the recompiler-baked ext->statictext table.
static void avm2_render_statictext(Avm2Context* ctx, Avm2Object* obj,
                                   const Mat* world, double alpha)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL || ext->statictext == NULL) return;
	Avm2GlyphPlacement* gl = NULL;
	uint32_t n = avm2_statictext_collect_glyphs(ctx, ext->statictext, &gl);
	if (n == 0)
	{
		if (gl != NULL) heap_free(ctx->app, gl);
		return;
	}
	avm2_render_glyphs(ctx, gl, n, world, alpha);
	heap_free(ctx->app, gl);
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
	else if (ext->is_morph_shape && ext->shape_vert_count > 0)
		avm2_render_morph(ctx, obj, &world, alpha);
	else if (ext->shape_vert_count > 0)
		avm2_render_shape(ctx, obj, &world, alpha);

	// Native timeline TextField (DefineEditText) glyphs.
	if (ext->edittext != NULL)
		avm2_render_text(ctx, obj, &world, alpha);

	// Native timeline static text (DefineText/2 -> StaticText) glyphs.
	if (ext->statictext != NULL)
		avm2_render_statictext(ctx, obj, &world, alpha);

	// T4: script-drawn Graphics geometry (independent of a timeline shape).
	avm2_render_graphics(ctx, obj, &world, alpha);

	// SimpleButton (Ruffle avm2_button.rs::render_self): paint the child for
	// the CURRENT state, and only that one — never the hit area, and no Up
	// fallback when the current state has no records. The state children are
	// deliberately NOT in render_list (a button is not a container; the
	// numChildren/getChildAt semantics simplebutton_structure asserts depend
	// on that), so this arm is the only way they are ever drawn.
	{
		Avm2Object* bst = avm2_button_state_child(ext);
		if (bst != NULL) avm2_render_node(ctx, bst, &world, alpha);
	}

	for (uint32_t i = 0; i < ext->render_len; i++)
		avm2_render_node(ctx, ext->render_list[i], &world, alpha);
}

// Focus highlight, drawn on TOP of the whole stage (Ruffle
// Stage::render_viewport calls focus_tracker().render_highlight AFTER
// self.render). Yellow 3px outline drawn INSIDE the focused object's world
// highlight bounds, matching RenderContext::draw_rect_outline. The visibility
// decision is the cached `g_avm2_highlight`; only the bounds are fresh.
static void avm2_render_highlight(Avm2Context* ctx)
{
	if (g_avm2_highlight != 2 || g_stage_focus == NULL) return;
	Rect r;
	obj_highlight_bounds(ctx, g_stage_focus, &r);
	if (!r.valid) return;
	float t  = 3.0f * 20.0f;                 // HIGHLIGHT_THICKNESS, twips
	float fx = (float) r.xmin, fy = (float) r.ymin;
	float fw = (float) (r.xmax - r.xmin), fh = (float) (r.ymax - r.ymin);
	if (fw <= 0.0f || fh <= 0.0f) return;
	// Transform slot 0 is identity (see avm2_render_bitmap's fallback), so
	// these world-twips rects go straight through stage_to_ndc.
	renderer_draw_rect(context, fx, fy, fw, t, 1, 1, 0, 1, 0, 0);              // top
	renderer_draw_rect(context, fx, fy + fh - t, fw, t, 1, 1, 0, 1, 0, 0);     // bottom
	renderer_draw_rect(context, fx, fy, t, fh, 1, 1, 0, 1, 0, 0);              // left
	renderer_draw_rect(context, fx + fw - t, fy, t, fh, 1, 1, 0, 1, 0, 0);     // right
}

static void avm2_render_walk(Avm2Context* ctx)
{
	renderer_open_pass(context);
	g_avm2_xform_next = g_avm2_xform_base;
	g_avm2_cxform_next = g_avm2_cxform_base;
	Mat id = mat_identity();
	if (ctx->stage != NULL)
		avm2_render_node(ctx, ctx->stage, &id, 1.0);
	avm2_render_highlight(ctx);
	renderer_close_pass(context);
}

// Replicate swfStart's renderer setup for the AVM2 entry (runSWF_avm2 never
// called renderer_new/init). Must run AFTER heap_init (renderer_init uses the
// heap allocator) and AFTER build_stage (reads g_stage_color for the clear).
void avm2_render_init(Avm2Context* ctx)
{
	SWFAppContext* app = ctx->app;
	context = renderer_new();

	// Render target = declared viewport when the harness gave us one, stage size
	// otherwise. app->width/height stay stage pixels (see swfStart).
	context->width = app->render_width > 0 ? app->render_width : app->width;
	context->height = app->render_height > 0 ? app->render_height : app->height;
	context->stage_scale = app->stage_scale > 0.0f ? app->stage_scale : 1.0f;
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

// Release the WebGPU device/instance before the process exits.
//
// This is not (only) about leaks. swfStart's tail has always called
// renderer_free; runSWF_avm2 never did, so an AVM2 graphics-native binary
// returned from main with the Vulkan driver's worker threads still running.
// _dl_fini then tore the shared libraries down underneath them. Captured core
// (CI run 30314779577 shard 9, avm2/edittext_align — the intermittent
// segfault of loader-arc.md §7): the main thread sits in
// __GI_exit -> __run_exit_handlers -> _dl_fini, while a lavapipe worker
// thread faults at address 0 inside LLVM's MCJIT (LLVMGetPointerToGlobal <-
// libvulkan_lvp.so) — a shader still being JIT-compiled after the library
// holding the JIT was unloaded. All trace output is already flushed by then,
// which is why the test scored 60/60 correct lines AND a SIGSEGV.
//
// Releasing the device joins the driver's threads inside vkDestroyInstance,
// so teardown becomes synchronous instead of a race with the dynamic linker.
// Must run after avm2_render_finish (the last capture reads back through the
// queue) and before heap teardown (render_webgpu_free frees from the heap).
void avm2_render_shutdown(Avm2Context* ctx)
{
	if (context == NULL) return;
	renderer_free(ctx->app, context);
	context = NULL;
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
