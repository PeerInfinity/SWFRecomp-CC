#ifndef AVM2_GC_H
#define AVM2_GC_H

// AVM2 mark-sweep garbage collector (Stage 11).
//
// AVM2 objects allocate from the shared o1heap but are a SEPARATE census from
// AVM1's ASObject/ASArray (g_mt_obj_head / g_mt_arr_head, object.c). Before
// Stage 11 every avm2_object_alloc'd object was immortal — fine for
// MAX_FRAMES-bounded trace tests, unbounded growth for a 30fps blitting game
// (Seedling). This collector enrolls every Avm2Object in an intrusive census
// list, marks the reachable set from a persistent root graph, and sweeps the
// rest back to o1heap.
//
// COLLECTION IS ONLY SAFE BETWEEN TICKS. Emitted method bodies keep their
// operand stack and locals as C locals (the Avm2Activation record holds no
// stack), so a mid-method collection could free a value reachable only from
// the C stack. The collector therefore runs from runSWF_avm2's tick loop when
// the VM is quiescent (no method body on the C stack); at that point the live
// set is exactly the persistent root graph.
//
// Root markers live in each module (main/display/events/amf/globals) and are
// invoked by the collector each cycle, mirroring object.c's per-TU marker
// pattern (actionGcMarkRoots / timerGcMarkRoots / ...).
//
// Edge tracing: Avm2Object struct fields (proto, slots, dyn_props,
// bound_methods, fn_* closure fields, class_ref) are traced precisely, and
// Array/Vector element storage is walked. Every other native_ext blob is
// conservatively pointer-scanned (native_ext_size bytes) — any word equal to a
// live census-object address is marked. Conservative scanning can only
// over-retain (bounded), never free a live object, so a missed ext edge is
// impossible — the correctness-critical safety property.

#include <avm2/avm2_object.h>
#include <avm2/avm2_value.h>

typedef struct Avm2Context Avm2Context;

// Enroll a freshly-allocated object in the census (called by
// avm2_object_alloc). Sets gc_next/gc_mark.
void avm2_gc_enroll(Avm2Object* obj);

// String census (collectable strings). Heap strings enroll at their two
// creation sites (avm2_string_new / avm2_string_concat) and are swept
// alongside objects when unreachable. Static pool strings (gc_flags == 0)
// are immortal and never written to.
void avm2_gc_enroll_string(Avm2String* s);

// Mark a string reachable. Handles all three shapes safely:
//  - a census header (the common case: every Avm2Value string) — O(1) flag;
//  - a by-value COPY of a census string (Avm2DynProp.name): the copy's
//    utf8 points into the census string's inline bytes, so the byte owner
//    is found by census range lookup;
//  - a static pool string / literal: no-op.
// Only valid during a collection (the range lookup uses the per-cycle
// census snapshot; outside a cycle both calls are safe no-ops).
// Strings stored into immortal NON-census structures need a root marker
// that re-marks them each cycle (the E4X all-nodes registry pattern,
// avm2_gc_mark_roots_e4x) — there is no pin API for strings.
void avm2_gc_mark_string(const Avm2String* s);

// Mark the census string whose allocation contains `p` (interior-pointer
// tolerant). No-op if p is not inside any census string. Used for bare
// `utf8` byte pointers and by the conservative ext scan.
void avm2_gc_mark_string_bytes(const void* p);

// Allocation accounting (called by avm2_alloc for every AVM2 allocation, so
// the cadence trigger and the census report see the whole heap, not just
// objects).
void avm2_gc_note_alloc(uint32_t bytes);

// Mark primitives, called from root markers and edge tracers. Safe on NULL /
// non-object values.
void avm2_gc_mark_object(Avm2Object* obj);
void avm2_gc_mark_value(Avm2Value v);
// Mark a captured scope chain's entries.
void avm2_gc_mark_scope(const Avm2ScopeChain* scope);

// Pin an object as permanently live (never swept, always a root). Used for
// structural singletons that outlive any collection.
void avm2_gc_pin(Avm2Object* obj);

// Run a collection if the deterministic cadence has been reached. Call only
// when the VM is quiescent (between ticks). No-op when the collector is
// disabled (AVM2_GC=0).
void avm2_gc_maybe_collect(Avm2Context* ctx);

// Force a collection now (soak harness / shutdown accounting). Same quiescence
// requirement as avm2_gc_maybe_collect.
void avm2_gc_collect_now(Avm2Context* ctx);

// Live-census accessors (soak / report).
uint32_t avm2_gc_live_objects(void);
uint32_t avm2_gc_live_strings(void);
uint64_t avm2_gc_live_bytes(void);

// Soak driver (AVM2_GC_SOAK=<ticks>): synthetic per-frame garbage on the real
// context, logging live-object N to stderr. Proves flat growth.
void avm2_gc_soak(Avm2Context* ctx, uint64_t ticks);

// Per-module root markers (implemented in each module, invoked by the
// collector). Each marks its C-static Avm2Object*/Avm2Value stashes.
void avm2_gc_mark_roots_main(Avm2Context* ctx);
void avm2_gc_mark_roots_display(Avm2Context* ctx);
void avm2_gc_mark_roots_events(Avm2Context* ctx);
void avm2_gc_mark_roots_amf(Avm2Context* ctx);
void avm2_gc_mark_roots_media(Avm2Context* ctx);
void avm2_gc_mark_roots_globals(Avm2Context* ctx);
void avm2_gc_mark_roots_external(Avm2Context* ctx);
// E4X all-nodes registry: nodes are immortal non-census allocations whose
// local/text/namespace string fields must stay live (avm2_e4x.c).
void avm2_gc_mark_roots_e4x(Avm2Context* ctx);

// Per-module ext tracers for the exts whose object edges hang off intermediate
// (non-census) allocations the conservative blob scan cannot follow: the
// EventDispatcher listener list and the DisplayObject child/frame-script/
// EditText edges. Invoked by the collector for every ext-bearing object;
// each is a no-op unless the object is of its type.
void avm2_events_gc_trace_ext(Avm2Object* o);
void avm2_display_gc_trace_ext(Avm2Object* o);
void avm2_text_gc_trace_ext(Avm2Object* o);

// Per-module ext-FREE hooks: when the collector sweeps an ext-bearing object,
// its native_ext blob owns further heap allocations (BitmapData pixel buffer,
// ByteArray backing bytes, DisplayObject child/frame-script arrays,
// EventDispatcher listener nodes, StyleSheet entry array) that heap_free-ing
// the blob alone would leak — a native-heap leak invisible to the object-count
// census. Each hook frees its module's sub-allocations for a swept object (a
// no-op unless the object is of its type); the collector calls them just
// before freeing the ext blob itself. These allocations are per-object (never
// shared), so freeing on sweep is safe.
void avm2_bitmap_gc_free_ext(Avm2Context* ctx, Avm2Object* o);
void avm2_bytearray_gc_free_ext(Avm2Context* ctx, Avm2Object* o);
void avm2_display_gc_free_ext(Avm2Context* ctx, Avm2Object* o);
void avm2_events_gc_free_ext(Avm2Context* ctx, Avm2Object* o);
void avm2_text_gc_free_ext(Avm2Context* ctx, Avm2Object* o);

#endif // AVM2_GC_H
