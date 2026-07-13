// AVM2 mark-sweep garbage collector (Stage 11). See avm2_gc.h for the design
// rationale (separate census from AVM1; collect only between ticks because
// method-body operand stacks/locals live on the C stack; conservative ext
// scan as the missed-edge safety net).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <memory/heap.h>

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_gc.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_value.h>

// --- census -----------------------------------------------------------------

static Avm2Object* g_gc_head = NULL;   // intrusive census (all Avm2Objects)
static uint32_t g_gc_live_objects = 0; // enrolled minus swept (net live count)
static uint64_t g_gc_total_alloc_bytes = 0;   // monotonic: every avm2_alloc byte
static uint64_t g_gc_bytes_since_collect = 0; // reset each collect (watermark)

// --- config -----------------------------------------------------------------

static int g_gc_configured = 0;
static int g_gc_enabled = 1;              // AVM2_GC=0 disables
static uint64_t g_gc_watermark = 4u * 1024 * 1024; // bytes allocated between collects
static int g_gc_verbose = 0;
static uint32_t g_gc_collections = 0;
static uint64_t g_gc_swept_total = 0;

static void gc_configure(void)
{
	g_gc_configured = 1;
	const char* e = getenv("AVM2_GC");
	if (e != NULL && strcmp(e, "0") == 0) g_gc_enabled = 0;
	const char* w = getenv("AVM2_GC_WATERMARK");
	if (w != NULL)
	{
		long long v = atoll(w);
		if (v > 0) g_gc_watermark = (uint64_t) v;
	}
	// Stress mode (CI correctness gate, the AVM1 swf_gc=1/cadence-1 precedent):
	// collect between EVERY tick regardless of allocation volume, so short
	// trace tests actually exercise mark-sweep. A collection that frees a live
	// object surfaces as a wrong trace — the honest-failure tripwire. Treat
	// empty / "0" as off (CI sets the var to "" when the input is blank).
	const char* stress = getenv("AVM2_GC_STRESS");
	if (stress != NULL && stress[0] != '\0' && strcmp(stress, "0") != 0) g_gc_watermark = 0;
	if (getenv("AVM2_GC_VERBOSE") != NULL) g_gc_verbose = 1;
}

// --- enrollment + accounting ------------------------------------------------

void avm2_gc_enroll(Avm2Object* obj)
{
	obj->gc_next = g_gc_head;
	obj->gc_mark = 0;
	g_gc_head = obj;
	g_gc_live_objects++;
}

void avm2_gc_note_alloc(uint32_t bytes)
{
	g_gc_total_alloc_bytes += bytes;
	g_gc_bytes_since_collect += bytes;
}

void avm2_gc_pin(Avm2Object* obj)
{
	if (obj != NULL) obj->gc_mark |= 2;
}

uint32_t avm2_gc_live_objects(void) { return g_gc_live_objects; }
uint64_t avm2_gc_live_bytes(void) { return g_gc_total_alloc_bytes; }

// --- worklist ---------------------------------------------------------------

static Avm2Object** g_wl = NULL;
static uint32_t g_wl_count = 0, g_wl_cap = 0;
static int g_gc_mark_failed = 0;  // worklist grow OOM this cycle → abort sweep

static void wl_push(Avm2Object* o)
{
	if (g_wl_count == g_wl_cap)
	{
		uint32_t nc = g_wl_cap == 0 ? 4096 : g_wl_cap * 2;
		Avm2Object** grown = realloc(g_wl, nc * sizeof(Avm2Object*));
		if (grown == NULL)
		{
			// Can't grow the worklist: dropping queued objects would leave
			// their children untraced → swept-while-live (UAF). Flag the
			// failure; gc_collect aborts the sweep entirely (over-retain,
			// never free). Drop THIS push (o stays marked; a marked object
			// that never gets traced is fine when nothing is swept).
			g_gc_mark_failed = 1;
			return;
		}
		g_wl = grown;
		g_wl_cap = nc;
	}
	g_wl[g_wl_count++] = o;
}

void avm2_gc_mark_object(Avm2Object* obj)
{
	if (obj == NULL) return;
	if (obj->gc_mark & 1) return;  // already marked (or pinned+marked)
	obj->gc_mark |= 1;
	wl_push(obj);
}

void avm2_gc_mark_value(Avm2Value v)
{
	if (v.kind == AVM2_VALUE_OBJECT) avm2_gc_mark_object(v.u.obj);
}

void avm2_gc_mark_scope(const Avm2ScopeChain* scope)
{
	if (scope == NULL) return;
	for (uint32_t i = 0; i < scope->count; i++)
	{
		avm2_gc_mark_object(scope->entries[i].obj);
	}
}

// --- conservative census-membership test ------------------------------------
//
// A sorted snapshot of every census-object address, rebuilt each cycle during
// the clear pass. The conservative ext scan binary-searches it: any ext word
// equal to a census-object start is treated as a live edge. Over-retention
// (a non-pointer word that happens to equal an address) is safe; the only
// forbidden outcome — freeing a still-referenced object — cannot occur because
// every raw object pointer in a live ext is caught here.

static Avm2Object** g_census_sorted = NULL;
static uint32_t g_census_sorted_count = 0, g_census_sorted_cap = 0;

static int census_ptr_cmp(const void* a, const void* b)
{
	Avm2Object* pa = *(Avm2Object* const*) a;
	Avm2Object* pb = *(Avm2Object* const*) b;
	if (pa < pb) return -1;
	if (pa > pb) return 1;
	return 0;
}

static int census_contains(Avm2Object* p)
{
	uint32_t lo = 0, hi = g_census_sorted_count;
	while (lo < hi)
	{
		uint32_t mid = lo + (hi - lo) / 2;
		if (g_census_sorted[mid] < p) lo = mid + 1;
		else hi = mid;
	}
	return lo < g_census_sorted_count && g_census_sorted[lo] == p;
}

static void conservative_scan(Avm2Object* o)
{
	if (o->native_ext == NULL || o->native_ext_size == 0) return;
	// native_ext blobs are O1HEAP_ALIGNMENT-aligned; pointer fields are
	// word-aligned. Scan word by word for embedded census-object starts.
	char* base = (char*) o->native_ext;
	uint32_t nwords = o->native_ext_size / sizeof(void*);
	for (uint32_t i = 0; i < nwords; i++)
	{
		Avm2Object* cand;
		memcpy(&cand, base + i * sizeof(void*), sizeof(void*));
		if (cand != NULL && census_contains(cand)) avm2_gc_mark_object(cand);
	}
}

// --- precise edge tracing ---------------------------------------------------

static void trace_array(Avm2Object* o)
{
	Avm2ArrayExt* ext = (Avm2ArrayExt*) o->native_ext;
	if (ext == NULL) return;
	for (uint32_t i = 0; i < ext->dense_len; i++) avm2_gc_mark_value(ext->elems[i]);
	for (Avm2SparseElem* s = ext->sparse; s != NULL; s = s->next) avm2_gc_mark_value(s->v);
}

static void trace_vector(Avm2Object* o)
{
	Avm2VectorExt* ext = (Avm2VectorExt*) o->native_ext;
	if (ext == NULL) return;
	for (uint32_t i = 0; i < ext->length; i++) avm2_gc_mark_value(ext->elems[i]);
}

static void trace_object(Avm2Object* o)
{
	avm2_gc_mark_object(o->proto);
	for (uint32_t i = 0; i < o->slot_count; i++) avm2_gc_mark_value(o->slots[i]);
	for (Avm2DynProp* p = o->dyn_props; p != NULL; p = p->next)
	{
		avm2_gc_mark_value(p->value);
		avm2_gc_mark_object(p->key_obj);
	}
	for (Avm2BoundMethod* bm = o->bound_methods; bm != NULL; bm = bm->next)
	{
		avm2_gc_mark_object(bm->fn);
	}
	// Function-closure payload.
	avm2_gc_mark_value(o->fn_receiver);
	avm2_gc_mark_object(o->fn_prototype);
	avm2_gc_mark_scope(o->fn_scope);
	if (o->fn_bound_class != NULL) avm2_gc_mark_object(o->fn_bound_class->class_object);
	// Class object payload: keep the class's proto + class object alive, and
	// trace the class's captured scope chains. A class scope can hold arbitrary
	// objects (avmplus captures `new C()` instances as scope bases — see
	// supercall_two_classobjects), and the object is reachable ONLY through the
	// class object's scope. Because every class object is pinned (hence traced
	// each cycle), tracing scopes here covers ALL class objects — including
	// ones overwritten in file->classes when the ABC reuses a class index.
	if (o->class_ref != NULL)
	{
		Avm2Class* c = o->class_ref;
		avm2_gc_mark_object(c->prototype_obj);
		avm2_gc_mark_object(c->class_object);
		avm2_gc_mark_scope(c->scope);
		avm2_gc_mark_scope(c->iscope);
		for (uint32_t i = 0; i < c->ivtable.count; i++)
			avm2_gc_mark_scope(c->ivtable.entries[i].method_scope);
		for (uint32_t i = 0; i < c->ivtable.meta_cap; i++)
			if (c->ivtable.metas != NULL && c->ivtable.metas[i].used)
				avm2_gc_mark_scope(c->ivtable.metas[i].method_scope);
	}
	// native_ext: precise for the two element-storage kinds; for every other
	// ext blob, run the two module tracers that follow indirect edges the
	// conservative scan cannot (dispatcher listeners, display child lists),
	// then conservatively scan the blob for any remaining direct object
	// pointers (event target, transform target, sharedobject data, ...).
	if (o->kind == AVM2_OBJ_ARRAY) { trace_array(o); return; }
	if (o->kind == AVM2_OBJ_VECTOR) { trace_vector(o); return; }
	if (o->native_ext != NULL)
	{
		avm2_events_gc_trace_ext(o);
		avm2_display_gc_trace_ext(o);
		avm2_text_gc_trace_ext(o);
		conservative_scan(o);
	}
}

// --- sweep ------------------------------------------------------------------

static void free_innards(Avm2Context* ctx, Avm2Object* o)
{
	SWFAppContext* app = ctx->app;
	if (o->slots != NULL) heap_free(app, o->slots);
	for (Avm2DynProp* p = o->dyn_props; p != NULL; )
	{
		Avm2DynProp* next = p->next;
		heap_free(app, p);
		p = next;
	}
	if (o->kind == AVM2_OBJ_ARRAY && o->native_ext != NULL)
	{
		Avm2ArrayExt* ext = (Avm2ArrayExt*) o->native_ext;
		if (ext->elems != NULL) heap_free(app, ext->elems);
		for (Avm2SparseElem* s = ext->sparse; s != NULL; )
		{
			Avm2SparseElem* n = s->next;
			heap_free(app, s);
			s = n;
		}
		heap_free(app, ext);
	}
	else if (o->kind == AVM2_OBJ_VECTOR && o->native_ext != NULL)
	{
		Avm2VectorExt* ext = (Avm2VectorExt*) o->native_ext;
		if (ext->elems != NULL) heap_free(app, ext->elems);
		heap_free(app, ext);
	}
	else if (o->native_ext != NULL)
	{
		// Generic ext blob. First let each module free the further heap
		// allocations its ext owns (pixel buffer, byte buffer, child arrays,
		// listener nodes, style entries) — freeing the blob alone would leak
		// them (a native-heap leak invisible to the object census). Each hook
		// no-ops unless the object is its type. Then free the blob.
		avm2_bitmap_gc_free_ext(ctx, o);
		avm2_bytearray_gc_free_ext(ctx, o);
		avm2_display_gc_free_ext(ctx, o);
		avm2_events_gc_free_ext(ctx, o);
		avm2_text_gc_free_ext(ctx, o);
		heap_free(app, o->native_ext);
	}
}

// --- collection -------------------------------------------------------------

static void gc_collect(Avm2Context* ctx)
{
	g_gc_collections++;
	g_gc_bytes_since_collect = 0;

	// Clear pass: build the sorted census snapshot; reset white; seed pinned
	// objects (marked + queued so their edges are traced).
	g_census_sorted_count = 0;
	g_wl_count = 0;
	g_gc_mark_failed = 0;
	for (Avm2Object* o = g_gc_head; o != NULL; o = o->gc_next)
	{
		if (g_census_sorted_count == g_census_sorted_cap)
		{
			uint32_t nc = g_census_sorted_cap == 0 ? 8192 : g_census_sorted_cap * 2;
			Avm2Object** grown = realloc(g_census_sorted, nc * sizeof(Avm2Object*));
			if (grown == NULL) { if (g_gc_verbose) fprintf(stderr, "[avm2-gc] census snapshot OOM — skip collect\n"); return; }
			g_census_sorted = grown;
			g_census_sorted_cap = nc;
		}
		g_census_sorted[g_census_sorted_count++] = o;

		if (o->gc_mark & 2) { o->gc_mark = 2 | 1; wl_push(o); }
		else o->gc_mark = 0;
	}
	qsort(g_census_sorted, g_census_sorted_count, sizeof(Avm2Object*), census_ptr_cmp);

	// Root markers (per module).
	avm2_gc_mark_roots_main(ctx);
	avm2_gc_mark_roots_globals(ctx);
	avm2_gc_mark_roots_display(ctx);
	avm2_gc_mark_roots_events(ctx);
	avm2_gc_mark_roots_amf(ctx);

	// Drain: trace every marked object's edges (may mark more).
	while (g_wl_count > 0)
	{
		Avm2Object* o = g_wl[--g_wl_count];
		trace_object(o);
	}

	// If the worklist couldn't grow at any point this cycle, the mark is
	// incomplete — abort the sweep (over-retain, never free a live object).
	if (g_gc_mark_failed)
	{
		if (g_gc_verbose)
			fprintf(stderr, "[avm2-gc] #%u worklist OOM — sweep aborted\n", g_gc_collections);
		return;
	}

	// Sweep: free every unmarked (white) census object.
	uint32_t swept = 0;
	Avm2Object** link = &g_gc_head;
	for (Avm2Object* o = g_gc_head; o != NULL; )
	{
		Avm2Object* next = o->gc_next;
		if (o->gc_mark & 1)
		{
			link = &o->gc_next;
			o = next;
			continue;
		}
		// Unlink + free.
		*link = next;
		free_innards(ctx, o);
		heap_free(ctx->app, o);
		g_gc_live_objects--;
		swept++;
		o = next;
	}
	g_gc_swept_total += swept;

	if (g_gc_verbose)
	{
		fprintf(stderr, "[avm2-gc] #%u live=%u swept=%u (total alloc %.1f MB)\n",
		        g_gc_collections, g_gc_live_objects, swept,
		        (double) g_gc_total_alloc_bytes / (1024.0 * 1024.0));
	}
}

void avm2_gc_collect_now(Avm2Context* ctx)
{
	if (!g_gc_configured) gc_configure();
	if (!g_gc_enabled) return;
	gc_collect(ctx);
}

void avm2_gc_maybe_collect(Avm2Context* ctx)
{
	if (!g_gc_configured) gc_configure();
	if (!g_gc_enabled) return;
	if (g_gc_bytes_since_collect < g_gc_watermark) return;
	gc_collect(ctx);
}

// --- soak harness (AVM2_GC_SOAK=<ticks>) ------------------------------------
//
// Drives `ticks` synthetic frames on the real, fully-constructed context, each
// allocating a batch of UNREACHABLE arrays (per-frame garbage, the dominant
// leak class for a blitting game). With the collector on, live-object N goes
// flat; with AVM2_GC=0 it climbs linearly — the before/after picture the
// Stage-11 soak must show. Logs to stderr; does not touch stdout (trace
// output stays byte-identical). Runs only when AVM2_GC_SOAK is set.

void avm2_gc_soak(Avm2Context* ctx, uint64_t ticks)
{
	if (!g_gc_configured) gc_configure();
	const uint32_t per_tick = 200;
	fprintf(stderr, "[avm2-gc-soak] start ticks=%llu per_tick=%u gc=%s watermark=%lluB\n",
	        (unsigned long long) ticks, per_tick, g_gc_enabled ? "on" : "off",
	        (unsigned long long) g_gc_watermark);
	uint32_t base_live = g_gc_live_objects;
	for (uint64_t t = 0; t < ticks; t++)
	{
		for (uint32_t i = 0; i < per_tick; i++)
		{
			Avm2Object* a = avm2_array_new(ctx, 0);
			avm2_array_push(ctx, a, avm2_integer((int32_t) i));
			avm2_array_push(ctx, a, avm2_object_value(avm2_array_new(ctx, 0)));
			(void) a;  // never stored → unreachable garbage
		}
		avm2_gc_maybe_collect(ctx);
		if (t % 500 == 0 || t == ticks - 1)
		{
			fprintf(stderr, "[avm2-gc-soak] tick=%-6llu live=%-8u (delta %+d) total_alloc=%.1fMB collections=%u\n",
			        (unsigned long long) t, g_gc_live_objects,
			        (int) g_gc_live_objects - (int) base_live,
			        (double) g_gc_total_alloc_bytes / (1024.0 * 1024.0),
			        g_gc_collections);
		}
	}
	fprintf(stderr, "[avm2-gc-soak] END live=%u swept_total=%llu collections=%u\n",
	        g_gc_live_objects, (unsigned long long) g_gc_swept_total, g_gc_collections);
}
