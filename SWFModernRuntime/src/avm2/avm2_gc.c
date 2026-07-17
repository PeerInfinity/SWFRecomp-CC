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

// String census: every heap Avm2String (avm2_string_new / avm2_string_concat)
// enrolls here and is swept when unreachable. Static pool strings never
// enroll (gc_flags == 0) and are never written to (rodata).
static Avm2String* g_gc_str_head = NULL;
static uint32_t g_gc_live_strings = 0;
static uint64_t g_gc_str_swept_total = 0;

// --- config -----------------------------------------------------------------

static int g_gc_configured = 0;
static int g_gc_enabled = 1;              // AVM2_GC=0 disables
static int g_gc_strings_enabled = 1;      // AVM2_GC_STRINGS=0 disables the
                                          // string sweep only (A/B + kill switch)
static uint64_t g_gc_watermark = 4u * 1024 * 1024; // bytes allocated between collects
static int g_gc_verbose = 0;
static uint32_t g_gc_collections = 0;
static uint64_t g_gc_swept_total = 0;

static void gc_configure(void)
{
	g_gc_configured = 1;
	const char* e = getenv("AVM2_GC");
	if (e != NULL && strcmp(e, "0") == 0) g_gc_enabled = 0;
	const char* es = getenv("AVM2_GC_STRINGS");
	if (es != NULL && strcmp(es, "0") == 0) g_gc_strings_enabled = 0;
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

void avm2_gc_enroll_string(Avm2String* s)
{
	s->gc_next = g_gc_str_head;
	s->gc_flags = AVM2_STR_GC_HEAP;
	g_gc_str_head = s;
	g_gc_live_strings++;
}


uint32_t avm2_gc_live_objects(void) { return g_gc_live_objects; }
uint32_t avm2_gc_live_strings(void) { return g_gc_live_strings; }
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
	else if (v.kind == AVM2_VALUE_STRING) avm2_gc_mark_string(v.u.str);
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

// Sorted snapshot of the STRING census, rebuilt each cycle. Unlike objects,
// string lookups are RANGE-based: a census string's allocation spans
// [s, s + sizeof(Avm2String) + s->len + 1) (header + inline bytes), and live
// references may point at the header (Avm2Value.u.str), at the bytes (a
// by-value Avm2String copy's utf8, e.g. Avm2DynProp.name), or anywhere inside
// (conservative ext-scan words). Any pointer into the span marks the string.
static Avm2String** g_str_census_sorted = NULL;
static uint32_t g_str_census_count = 0, g_str_census_cap = 0;
// O(1) address-bounds gate for the range lookup, set once per cycle after the
// snapshot qsort. Most conservatively-scanned ext words are numbers/flags;
// rejecting them before the binary search keeps the scan near its old cost.
static const char* g_str_census_lo = NULL;
static const char* g_str_census_hi = NULL;

static int str_census_ptr_cmp(const void* a, const void* b)
{
	Avm2String* pa = *(Avm2String* const*) a;
	Avm2String* pb = *(Avm2String* const*) b;
	if (pa < pb) return -1;
	if (pa > pb) return 1;
	return 0;
}

void avm2_gc_mark_string_bytes(const void* p)
{
	if (p == NULL || g_str_census_count == 0) return;
	if ((const char*) p < g_str_census_lo || (const char*) p >= g_str_census_hi) return;
	// Greatest census string whose start <= p.
	uint32_t lo = 0, hi = g_str_census_count;
	while (lo < hi)
	{
		uint32_t mid = lo + (hi - lo) / 2;
		if ((const void*) g_str_census_sorted[mid] <= p) lo = mid + 1;
		else hi = mid;
	}
	if (lo == 0) return;
	Avm2String* s = g_str_census_sorted[lo - 1];
	if ((const char*) p < (const char*) s + sizeof(Avm2String) + s->len + 1)
	{
		s->gc_flags |= AVM2_STR_GC_MARK;
	}
}

void avm2_gc_mark_string(const Avm2String* s)
{
	if (s == NULL) return;
	if ((s->gc_flags & AVM2_STR_GC_HEAP) && s->utf8 == (const char*) (s + 1))
	{
		// The census header itself (every string minted by avm2_string_new /
		// avm2_string_concat has its bytes inline) — O(1).
		((Avm2String*) s)->gc_flags |= AVM2_STR_GC_MARK;
		return;
	}
	// A by-value copy (its utf8 points into some census string's bytes) or a
	// static pool string / literal (lookup misses; no-op).
	avm2_gc_mark_string_bytes(s->utf8);
}

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
		if (cand == NULL) continue;
		if (census_contains(cand)) { avm2_gc_mark_object(cand); continue; }
		// Not an object: it may be a census STRING edge — either an
		// Avm2String* header (Avm2EventExt.type, DisplayObjectExt.name,
		// RegExpExt.source, QName/Namespace ext, ...) or a bare utf8 byte
		// pointer. The range lookup covers both; over-retention only.
		avm2_gc_mark_string_bytes(cand);
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
		// The prop name is a by-value COPY of a heap string (set_dynamic:
		// p->name = *avm2_string_new(...)); its utf8 points into that census
		// string's inline bytes, which must survive as long as the prop does.
		if (p->name.utf8 != NULL) avm2_gc_mark_string_bytes(p->name.utf8);
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

// Free a live object's tombstoned dyn-prop nodes. Tombstones exist only for
// in-flight enumeration cursors (avm2_object.c next_enumerant), and
// collections run strictly between ticks when no for-in can be mid-flight
// (hasnext2 loops live inside method bodies, which complete within a tick) —
// so at sweep time the only reference to a dead node is the object's cached
// cursor, which is reset here (the cursor cache re-derives its position from
// the public index on the next enumeration call; dead nodes are never
// counted, so the enumerable sequence is unchanged). Without this purge, a
// delete→re-add cycle on a long-lived object grows its chain unboundedly
// (the set path skips dead nodes and appends a fresh node + name string).
static void purge_dead_dyn_props(Avm2Context* ctx, Avm2Object* o)
{
	Avm2DynProp** link = &o->dyn_props;
	Avm2DynProp* tail = NULL;
	int purged = 0;
	for (Avm2DynProp* p = o->dyn_props; p != NULL; )
	{
		Avm2DynProp* next = p->next;
		if (p->dead)
		{
			*link = next;
			heap_free(ctx->app, p);
			purged = 1;
		}
		else
		{
			tail = p;
			link = &p->next;
		}
		p = next;
	}
	if (purged)
	{
		o->dyn_tail = tail;
		o->dyn_enum_pos = NULL;
		o->dyn_enum_public = 0;
	}
}

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
	// Per-object vtables: only newactivation/newcatch allocate a vtable owned
	// by a single object, and they are exactly the `no_index` ones (every
	// other object shares its class's embedded ivtable — never no_index, and
	// never freed here). Entry keys point into ABC static data; method_scope
	// chains are shared (not owned); name_index is never built for no_index
	// vtables.
	if (o->vtable != NULL && o->vtable->no_index)
	{
		if (o->vtable->entries != NULL) heap_free(app, o->vtable->entries);
		if (o->vtable->metas != NULL) heap_free(app, o->vtable->metas);
		heap_free(app, (void*) o->vtable);
	}
	// Synthetic catch-scope class (avm2_op_newcatch): owned exclusively by
	// this object; nothing else can reach it (never registered in any
	// file/domain table, has no class_object/prototype).
	if (o->cls != NULL && (o->cls->flags & AVM2_CLASS_FLAG_SYNTH_CATCH))
	{
		heap_free(app, o->cls);
	}
}

// --- collection -------------------------------------------------------------

static void gc_collect(Avm2Context* ctx)
{
	g_gc_collections++;
	// NOTE: the watermark (g_gc_bytes_since_collect) is reset only after both
	// census snapshots are built — a snapshot realloc OOM returns early, and
	// resetting first would silently degrade the collector to a permanent
	// no-op under exactly the memory pressure it exists to relieve (the next
	// avm2_gc_maybe_collect must retry immediately).

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
			if (grown == NULL) { fprintf(stderr, "[avm2-gc] census snapshot OOM — skip collect\n"); return; }
			g_census_sorted = grown;
			g_census_sorted_cap = nc;
		}
		g_census_sorted[g_census_sorted_count++] = o;

		if (o->gc_mark & 2) { o->gc_mark = 2 | 1; wl_push(o); }
		else o->gc_mark = 0;
	}
	qsort(g_census_sorted, g_census_sorted_count, sizeof(Avm2Object*), census_ptr_cmp);

	// String clear pass: reset white + build the sorted range-lookup snapshot.
	// Strings have no outgoing edges, so nothing is seeded to the worklist.
	g_str_census_count = 0;
	for (Avm2String* s = g_gc_str_head; s != NULL; s = s->gc_next)
	{
		if (g_str_census_count == g_str_census_cap)
		{
			uint32_t nc = g_str_census_cap == 0 ? 8192 : g_str_census_cap * 2;
			Avm2String** grown = realloc(g_str_census_sorted, nc * sizeof(Avm2String*));
			if (grown == NULL) { fprintf(stderr, "[avm2-gc] string snapshot OOM — skip collect\n"); g_str_census_count = 0; return; }
			g_str_census_sorted = grown;
			g_str_census_cap = nc;
		}
		g_str_census_sorted[g_str_census_count++] = s;
		s->gc_flags &= ~AVM2_STR_GC_MARK;
	}
	qsort(g_str_census_sorted, g_str_census_count, sizeof(Avm2String*), str_census_ptr_cmp);
	// O(1) reject bounds for the range lookup (most conservatively-scanned
	// ext words are numbers/flags, not string pointers).
	if (g_str_census_count > 0)
	{
		Avm2String* last = g_str_census_sorted[g_str_census_count - 1];
		g_str_census_lo = (const char*) g_str_census_sorted[0];
		g_str_census_hi = (const char*) last + sizeof(Avm2String) + last->len + 1;
	}

	// Watermark reset: both snapshots built, the cycle will complete.
	g_gc_bytes_since_collect = 0;

	// Root markers (per module).
	avm2_gc_mark_roots_main(ctx);
	avm2_gc_mark_roots_globals(ctx);
	avm2_gc_mark_roots_display(ctx);
	avm2_gc_mark_roots_events(ctx);
	avm2_gc_mark_roots_amf(ctx);
	avm2_gc_mark_roots_media(ctx);
	avm2_gc_mark_roots_external(ctx);
	avm2_gc_mark_roots_e4x(ctx);

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
			purge_dead_dyn_props(ctx, o);
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

	// String sweep: free every unmarked census string (header + inline bytes
	// are one allocation). AVM2_GC_STRINGS=0 skips it (exact pre-string-GC
	// behavior for A/B leak measurement, and a kill switch).
	uint32_t str_swept = 0;
	if (g_gc_strings_enabled)
	{
		Avm2String** slink = &g_gc_str_head;
		for (Avm2String* s = g_gc_str_head; s != NULL; )
		{
			Avm2String* snext = s->gc_next;
			if (s->gc_flags & AVM2_STR_GC_MARK)
			{
				slink = &s->gc_next;
				s = snext;
				continue;
			}
			*slink = snext;
			heap_free(ctx->app, s);
			g_gc_live_strings--;
			str_swept++;
			s = snext;
		}
		g_gc_str_swept_total += str_swept;
	}

	// Drop the per-cycle snapshot: it now holds dangling pointers to swept
	// strings, and an out-of-cycle mark call must be a safe no-op, never a
	// read of freed memory.
	g_str_census_count = 0;
	g_str_census_lo = g_str_census_hi = NULL;

	if (g_gc_verbose)
	{
		fprintf(stderr, "[avm2-gc] #%u live=%u swept=%u strings live=%u swept=%u (total alloc %.1f MB)\n",
		        g_gc_collections, g_gc_live_objects, swept,
		        g_gc_live_strings, str_swept,
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
	fprintf(stderr, "[avm2-gc-soak] END live=%u swept_total=%llu strings_live=%u strings_swept_total=%llu collections=%u\n",
	        g_gc_live_objects, (unsigned long long) g_gc_swept_total,
	        g_gc_live_strings, (unsigned long long) g_gc_str_swept_total,
	        g_gc_collections);
}
