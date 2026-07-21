#ifndef AVM2_GLOBALS_H
#define AVM2_GLOBALS_H

// Builtins (avm2-support-plan §4.5): hand-written C implementations of the
// tranche-1 core (Object, Class, Function, String, Number/int/uint,
// Boolean, Array, Math, the Error family, toplevel functions) registered
// through the same vtable mechanism as SWF classes so the binding surface
// stays playerglobal-shaped. flash.display remains a stub chain
// (EventDispatcher → ... → MovieClip with addFrameScript).
//
// Also owns the "domain": the FindPropStrict last-resort lookup from a
// definition name to the globals object defining it (Ruffle Domain
// equivalent), including lazy script initialization.

#include <avm2/avm2_class.h>

typedef struct Avm2Context Avm2Context;

typedef struct Avm2DomainEntry
{
	Avm2PropKey key;
	Avm2AbcFileRt* file;    // NULL = builtin
	uint32_t script_index;  // valid when file != NULL
} Avm2DomainEntry;

typedef struct Avm2Domain
{
	uint32_t count;
	uint32_t cap;
	Avm2DomainEntry* entries;
	// Name-keyed lookup accelerator (avm2_globals.c, opaque), mirroring the
	// Avm2VTable index: avm2_domain_find is a per-findproperty linear scan of
	// every global class/function, so hashing by name makes it O(1)+small-
	// bucket. Lazily (re)built when `indexed_count != count`; holds only entry
	// indices (no GC pointers), malloc'd, GC-invisible.
	void* name_index;        // Avm2DomainIndex* (NULL until first index)
	uint32_t indexed_count;  // `count` at the last index build
} Avm2Domain;

// Creates builtin classes + the builtin globals object and seeds the domain.
void avm2_globals_init(Avm2Context* ctx);

// Domain registration (called during ABC load for every script trait).
void avm2_domain_add(Avm2Context* ctx, const Avm2PropKey* key,
                     Avm2AbcFileRt* file, uint32_t script_index);

// Domain lookup: returns the globals object defining `key` (running the
// defining script's initializer lazily if needed), or NULL if undefined.
Avm2Object* avm2_domain_find(Avm2Context* ctx, const Avm2PropKey* key);

// Runs a script's initializer if it has not run yet (lazy or eager init).
void avm2_script_ensure_init(Avm2AbcFileRt* file, uint32_t script_index);

// Name-based public property access (no multiname pools required): used
// by coerce_to_primitive (toString/valueOf), builtins, and the `in`/
// enumeration paths. get sets *found (may be NULL) and returns undefined
// when missing.
Avm2Value avm2_get_public_property(Avm2Context* ctx, Avm2Value recv,
                                   const char* name, uint32_t name_len, int* found);
Avm2Value avm2_call_public_property(Avm2Context* ctx, Avm2Value recv,
                                    const char* name, uint32_t name_len,
                                    const Avm2Value* args, uint32_t argc);
int avm2_has_public_property(Avm2Context* ctx, Avm2Value recv,
                             const char* name, uint32_t name_len);
void avm2_set_public_property(Avm2Context* ctx, Avm2Value recv,
                              const char* name, uint32_t name_len, Avm2Value value);
int avm2_has_own_public_property(Avm2Context* ctx, Avm2Value recv,
                                 const char* name, uint32_t name_len);

// Builtin class registration helpers (also used by avm2_string.c etc.).
Avm2Class* avm2_builtin_class(Avm2Context* ctx, const char* ns, const char* name,
                              Avm2Class* super);
void avm2_builtin_add_method(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn fn);
void avm2_builtin_add_getter(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn fn);
// Instance accessor pair (setter may be NULL for a getter-only prop).
void avm2_builtin_add_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn getter, Avm2MethodFn setter);
void avm2_builtin_add_static_method(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                    Avm2MethodFn fn);
void avm2_builtin_add_static_const(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                   Avm2Value value);
// Static accessor pair on the class object (setter may be NULL).
void avm2_builtin_add_static_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                    Avm2MethodFn getter, Avm2MethodFn setter);
// Install a native function on a prototype object (dont_enum).
void avm2_proto_add_function(Avm2Context* ctx, Avm2Object* proto, const char* name,
                             Avm2MethodFn fn);
// Register a toplevel native function on the builtin globals + domain.
void avm2_builtin_add_global_fn(Avm2Context* ctx, const char* name, Avm2MethodFn fn);
// Expose a value on the builtin globals + domain under an arbitrary key.
void avm2_builtin_define_alias(Avm2Context* ctx, Avm2PropKey key, Avm2Value value);

// Per-module builtin registration (called from avm2_globals_init).
void avm2_register_string(Avm2Context* ctx);
void avm2_register_number(Avm2Context* ctx);   // Number/int/uint/Boolean/Math
void avm2_register_array(Avm2Context* ctx);
void avm2_register_error(Avm2Context* ctx);
void avm2_register_toplevel(Avm2Context* ctx); // trace/isNaN/parseInt/...
void avm2_register_vector(Avm2Context* ctx);   // __AS3__.vec::Vector + specializations
void avm2_register_regexp(Avm2Context* ctx);   // RegExp + String regex paths
void avm2_register_json(Avm2Context* ctx);     // SWF13+ (caller gates)
void avm2_register_nsqname(Avm2Context* ctx);  // Namespace + QName
void avm2_register_dictionary(Avm2Context* ctx);  // flash.utils.Dictionary
// Is `obj` an instance of (a subclass of) flash.utils.Dictionary?
int avm2_is_dictionary(Avm2Object* obj);
void avm2_register_bytearray(Avm2Context* ctx);  // flash.utils.ByteArray (+Endian)
void avm2_register_amf(Avm2Context* ctx);  // flash.net alias fns + Date upgrade
void avm2_register_external(Avm2Context* ctx);  // flash.external.ExternalInterface

// Minimal Date instance state (avm2_amf.c upgrades the stub).
typedef struct Avm2DateExt
{
	double millis;
} Avm2DateExt;
Avm2DateExt* avm2_date_ext_of(Avm2Value v);

// ByteArray instance state (avm2_bytearray.c).
typedef struct Avm2ByteArrayExt
{
	uint8_t* bytes;
	uint32_t len;
	uint32_t cap;
	uint32_t position;
	uint8_t endian_little;    // 0 = bigEndian (default)
	uint8_t object_encoding;  // 0 = AMF0, 3 = AMF3
} Avm2ByteArrayExt;

// NULL when the value is not a ByteArray (subclasses included).
Avm2ByteArrayExt* avm2_bytearray_ext_of(Avm2Value v);
// Grow/shrink storage (clamps position; used by the [] index write path).
void avm2_bytearray_set_length_public(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                                      uint32_t new_len);
// write/readUnsignedInt at the current position, honoring endianness (used
// by BitmapData get/setPixels). The read throws EOFError on underflow.
void avm2_bytearray_write_uint_public(Avm2Context* ctx, Avm2ByteArrayExt* ba, uint32_t v);
uint32_t avm2_bytearray_read_uint_public(Avm2Context* ctx, Avm2ByteArrayExt* ba);

void avm2_register_proxy(Avm2Context* ctx);  // flash.utils.Proxy
// Is `obj` an instance of (a subclass of) flash.utils.Proxy?
int avm2_is_proxy(Avm2Object* obj);
// Invoke a flash_proxy-namespace hook (getProperty/setProperty/...) on a
// Proxy instance, honoring subclass overrides.
Avm2Value avm2_proxy_call_hook(Avm2Context* ctx, Avm2Object* obj, const char* mname,
                               const Avm2Value* args, uint32_t argc);
// Enumeration hooks (avm2_object.c protocol); return 0 if not a Proxy.
int avm2_proxy_next_enumerant(Avm2Object* obj, uint32_t cur, uint32_t* out);
int avm2_proxy_enumerant_name(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                              Avm2Value* out);
int avm2_proxy_enumerant_value(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                               Avm2Value* out);

// Namespace/QName instance state (avm2_nsqname.c). prefix == NULL is the
// undefined prefix; a QName uri == NULL is the any namespace and local ==
// NULL the any name. kind is the raw ABC namespace kind (0 = any).
typedef struct Avm2NamespaceExt
{
	const Avm2String* uri;
	const Avm2String* prefix;
	uint8_t kind;
} Avm2NamespaceExt;

typedef struct Avm2QNameExt
{
	const Avm2String* uri;
	const Avm2String* local;
	// The Ruffle Multiname ATTRIBUTE flag: set when the QName names an
	// attribute (e.g. xml.attributes()[0].name()); honored by E4X lazy
	// names and Proxy's flash_proxy::isAttribute.
	uint8_t is_attribute;
} Avm2QNameExt;

// NULL when the value is not a Namespace / QName instance.
Avm2NamespaceExt* avm2_namespace_ext_of(Avm2Value v);
Avm2QNameExt* avm2_qname_ext_of(Avm2Value v);
Avm2Object* avm2_namespace_new(Avm2Context* ctx, const Avm2String* uri,
                               const Avm2String* prefix, uint8_t kind);
// Box a constant-pool namespace (PushNamespace, namespace trait defaults).
Avm2Object* avm2_namespace_from_pool(Avm2Context* ctx, Avm2AbcFileRt* file,
                                     uint32_t ns_idx);
Avm2Object* avm2_qname_new(Avm2Context* ctx, const Avm2String* uri,
                           const Avm2String* local);
const Avm2String* avm2_qname_to_string(Avm2Context* ctx, const Avm2QNameExt* ext);
// Enumeration hooks (called from avm2_object.c); return 0 if `obj` is not
// a Namespace/QName.
int avm2_nsqname_next_enumerant(Avm2Object* obj, uint32_t cur, uint32_t* out);
int avm2_nsqname_enumerant_name(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                                Avm2Value* out);
int avm2_nsqname_enumerant_value(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                                 Avm2Value* out);

// Plain (non-regex) String.split — the regex-aware split falls back to it.
Avm2Value avm2_string_split_plain(struct Avm2Activation* act);

// The current (root) ApplicationDomain as a value, or null if not yet built.
Avm2Value avm2_current_domain_value(Avm2Context* ctx);

// Definition lookup by dotted/:: name ("pkg::Name", "pkg.Name", "Name"),
// including on-demand "Vector.<...>" applications. Sets *found.
Avm2Value avm2_find_definition(Avm2Context* ctx, const char* s, uint32_t len,
                               int* found);

// Vector machinery (avm2_vector.c).
Avm2VectorExt* avm2_vector_ext(Avm2Object* obj);  // NULL if not a Vector
// Resolve "Vector.<...>" (optional __AS3__.vec prefix) to the applied class.
Avm2Class* avm2_vector_class_by_name(Avm2Context* ctx, const char* s, uint32_t len);
// The parameterized class Vector.<param> (param NULL = *): cached per param.
Avm2Class* avm2_vector_apply(Avm2Context* ctx, Avm2Class* param);
// New Vector.<T> instance of the given PARAMETERIZED class.
Avm2Object* avm2_vector_new(Avm2Context* ctx, Avm2Class* vec_class,
                            uint32_t length, int fixed);
// Index access with Ruffle vector_object.rs error semantics (1125 on
// SWF>=11). set coerces to T; get throws on out-of-range.
Avm2Value avm2_vector_get_index(Avm2Context* ctx, Avm2Object* obj, uint32_t idx);
void avm2_vector_set_index(Avm2Context* ctx, Avm2Object* obj, uint32_t idx, Avm2Value v);
// Numeric-name access path (name parses as f64 but maybe not a valid u32
// index): returns 0 if the name is not numeric (caller falls through to the
// normal property path), 1 if handled; throws per version semantics.
// `out` NULL = write `set_value`, else read into *out. May "handle" a read
// by falling back (returns 0) for negative indices on SWF10.
int avm2_vector_name_access(Avm2Context* ctx, Avm2Object* obj, const char* name,
                            uint32_t name_len, Avm2Value* out, Avm2Value set_value);

// The avmplus QuickSort shared by Array.sort/sortOn and Vector.sort
// (Ruffle globals/array.rs qsort).
typedef struct Avm2SortItem { uint32_t idx; Avm2Value v; } Avm2SortItem;
typedef int (*Avm2SortCmp)(void* ud, const Avm2SortItem* a, const Avm2SortItem* b);
void avm2_avmplus_qsort(void* ud, Avm2SortCmp cmp, Avm2SortItem* s, uint32_t n);

// EventDispatcher instance state (Avm2Object.native_ext). ed_target is the
// EventDispatcher(target) constructor arg (the IEventDispatcher aggregation
// pattern); undefined/null = the dispatcher itself is the target.
typedef struct EDListener EDListener;
typedef struct Avm2EventDispatcherExt
{
	Avm2Value ed_target;
	EDListener* head;
} Avm2EventDispatcherExt;

// flash.events.Event instance state (Ruffle events.rs Event struct).
// Stage 8: the same struct also carries MouseEvent/KeyboardEvent/FocusEvent
// subclass fields (the display-ext "one struct for the whole ladder" pattern);
// Event subclasses inherit native_ext_size, so the base size below suffices.
typedef struct Avm2EventExt
{
	const Avm2String* type;      // NULL until init
	Avm2Object* target;
	Avm2Object* current_target;
	uint8_t bubbles;
	uint8_t cancelable;
	uint8_t cancelled;
	uint8_t propagation;         // 0 allow, 1 stop, 2 stop-immediate
	uint8_t phase;               // 1 capturing, 2 at-target, 3 bubbling

	// --- MouseEvent / KeyboardEvent / FocusEvent shared modifier flags ---
	uint8_t ctrl_key;
	uint8_t alt_key;
	uint8_t shift_key;
	uint8_t control_key;         // KeyboardEvent controlKey (Mac ctrl)
	uint8_t command_key;         // KeyboardEvent commandKey (Mac cmd)
	uint8_t button_down;         // MouseEvent buttonDown
	Avm2Object* related_object;  // MouseEvent/FocusEvent relatedObject
	// --- MouseEvent ---
	double local_x, local_y;     // NaN = unset
	int32_t delta;
	int32_t movement_x, movement_y;
	// --- KeyboardEvent ---
	uint32_t char_code;
	uint32_t key_code;
	uint32_t key_location;
	// --- FocusEvent ---
	const Avm2String* direction; // NULL = "none"
	uint8_t related_object_inaccessible;
	// --- TextEvent / ErrorEvent (text = error message) ---
	const Avm2String* text;
	// --- ProgressEvent ---
	double bytes_loaded, bytes_total;
	// --- ErrorEvent family ---
	int32_t error_id;
	// --- HTTPStatusEvent ---
	int32_t http_status;
	uint8_t redirected;
	const Avm2String* response_url;
	// --- StatusEvent ---
	const Avm2String* status_code;
	const Avm2String* status_level;
} Avm2EventExt;

// DisplayObject instance state (avm2_display.c). One struct serves the
// whole display ladder (DisplayObject..MovieClip/Stage): per-class size
// juggling is not worth the bytes. The dispatcher ext MUST stay first:
// display classes inherit EventDispatcher's natives, which read native_ext
// as Avm2EventDispatcherExt.
typedef struct Avm2DepthEntry
{
	int32_t depth;
	Avm2Object* child;
} Avm2DepthEntry;

typedef struct Avm2DisplayObjectExt
{
	Avm2EventDispatcherExt dispatcher;

	// --- DisplayObject core ---
	Avm2Object* parent;          // display parent (NULL = not on a tree)
	const Avm2String* name;      // NULL only for the Stage
	uint8_t has_explicit_name;
	uint8_t parent_field_done;   // set_on_parent_field already ran (buttons
	                             // set the field BEFORE construction)
	uint8_t manual_frame_construct; // placed while the parent was still
	                             // unconstructed: ONLY Sprite.constructChildren
	                             // may construct it (Ruffle MANUAL_FRAME_CONSTRUCT
	                             // — movieclip_frameconstruct_skipped)
	uint8_t instantiated_by_timeline;
	uint8_t placed_by_avm2_script;
	uint8_t is_root;
	uint8_t is_stage;
	uint8_t visible;             // default 1
	uint8_t constructed;         // AVM2 constructor has run
	uint8_t skip_next_enter_frame;
	// Sprite.constructChildren is iterating this container (Ruffle
	// RUNNING_CONSTRUCT_FRAME): nested construct_frame passes skip its
	// still-unconstructed children (constructors_vs_timeline).
	uint8_t running_construct_frame;
	uint16_t char_id;            // 0 = script-created (or root)
	// T1 solid-fill shape geometry, resolved from char_id at place-time
	// (avm2_generated_shape_geom). shape_vert_count == 0 means "no solid
	// shape to draw" (script-created, sprite, gradient/stroke shape, or
	// unresolved) — the render walk then draws nothing for this node.
	uint32_t shape_vert_offset;
	uint32_t shape_vert_count;
	int32_t depth;               // timeline depth
	int32_t clip_depth;
	int32_t place_frame;
	// Matrix: scale/rot f32, translate twips (Ruffle Matrix layout).
	float mtx_a, mtx_b, mtx_c, mtx_d;
	int32_t mtx_tx, mtx_ty;
	// Decomposed transform cache (Ruffle DisplayObjectBase).
	uint8_t scale_rot_cached;
	double rotation_deg;         // raw degrees (may be NaN/Inf)
	double scale_x, scale_y;     // unit values (may be NaN)
	double skew;                 // radians
	int16_t alpha_fixed8;        // 8.8 fixed a_multiply; default 256
	// InteractiveObject.
	uint8_t mouse_enabled;       // default 1
	uint8_t double_click_enabled;
	uint8_t tab_enabled_set, tab_enabled_val;
	int32_t tab_index;           // -1 = unset
	uint8_t focus_rect_set, focus_rect_val;
	Avm2Value meta_data;         // metaData (undefined = unset)
	Avm2Object* mask;

	// Drawing API (flash.display.Graphics stub): cached instance +
	// accumulated AABB of drawn geometry (twips), feeding self bounds.
	Avm2Object* graphics_obj;
	uint8_t draw_valid;
	int32_t draw_xmin, draw_xmax, draw_ymin, draw_ymax;

	// --- DisplayObjectContainer ---
	Avm2Object** render_list;
	uint32_t render_len, render_cap;
	Avm2DepthEntry* depth_list;  // sorted ascending by depth
	uint32_t depth_len, depth_cap;
	uint8_t mouse_children;      // default 1
	uint8_t tab_children;        // default 1
	uint8_t tab_children_set;    // tabChildren explicitly assigned
	uint8_t button_mode;         // Sprite.buttonMode
	uint8_t use_hand_cursor;     // Sprite.useHandCursor (default 1)

	// --- MovieClip / timeline ---
	const Avm2TimelineData* timeline;  // NULL = no timeline (plain Sprite etc.)
	uint16_t current_frame;      // 1-based; 0 = before frame 1
	uint8_t playing;             // default 1 for timeline clips
	uint8_t programmatically_played;
	uint8_t executing_frame_script;
	uint8_t loop_queued;
	uint8_t initialized;
	int32_t queued_goto_frame;   // -1 = none
	uint16_t queued_script_frame;
	int32_t last_queued_script_frame;  // -1 = none
	uint8_t has_pending_script;
	// Queued AS3 place/remove tags for this tick (per-depth, Ruffle
	// QueuedTagList): index into the current frame's op array, or -1.
	int32_t* queued_places;      // [frame op count] worth of op indices
	uint32_t queued_place_count;
	uint32_t frame_script_cap;
	Avm2Value* frame_scripts;    // indexed by 0-based frame; unset = undefined kind

	// --- SimpleButton ---
	Avm2Object* btn_up;
	Avm2Object* btn_over;
	Avm2Object* btn_down;
	Avm2Object* btn_hit;
	uint8_t btn_states_created;
	uint8_t btn_weird_order;  // one-shot framescript order after construction

	// --- Bitmap (flash.display.Bitmap; avm2_bitmap.c) ---
	Avm2Object* bitmap_data;         // the BitmapData object (NULL = none)
	const Avm2String* pixel_snapping;  // NULL = default "auto"
	uint8_t smoothing;
	uint8_t is_bitmap;               // this display object is a flash.display.Bitmap
	// Cached width/height (pixels) captured when bitmapData is assigned —
	// Ruffle Bitmap keeps these even after the BitmapData is disposed.
	uint32_t bitmap_w, bitmap_h;

	// --- TextField ---
	const Avm2String* tf_text;   // NULL = default "" (mirror of edittext->text)
	// TextField/EditText engine state (avm2_text.c; NULL for non-TextFields).
	struct Avm2EditTextExt* edittext;
	// accessibilityImplementation/accessibilityProperties (stored verbatim).
	Avm2Value accessibility_impl;
	Avm2Value accessibility_props;

	// soundTransform: core i32×100 {l2l,l2r,r2l,r2r,volume}; unset = default.
	int32_t sound_transform[5];
	uint8_t sound_transform_set;
} Avm2DisplayObjectExt;

// Compatibility alias: MovieClip state is the shared display ext.
typedef Avm2DisplayObjectExt Avm2MovieClipExt;

// flash.events registration (avm2_events.c): Event (real internal state,
// clone/formatToString/preventDefault family), EventDispatcher (3-phase
// dispatch, priority buckets, capture split, broadcast registry),
// EventPhase, IEventDispatcher.
void avm2_register_events(Avm2Context* ctx);
// NULL when the value/object is not an Event / EventDispatcher-descendant.
Avm2EventExt* avm2_event_ext_of(Avm2Value v);
Avm2EventDispatcherExt* avm2_dispatcher_ext_of(Avm2Context* ctx, Avm2Object* obj);
// New base flash.events.Event instance (type interned by the caller).
Avm2Object* avm2_event_new(Avm2Context* ctx, const Avm2String* type,
                           int bubbles, int cancelable);
// Full 3-phase dispatch on a dispatcher object (Ruffle events.rs
// dispatch_event). Returns 1 if the event was handled (some listener ran).
int avm2_dispatch_event(Avm2Context* ctx, Avm2Object* dispatcher, Avm2Object* event);
// FP broadcast semantics: deliver to every dispatcher registered for this
// event type (registration order), no capture/bubble, ignoring propagation
// stops between targets. `filter_class` NULL = no class filter.
void avm2_broadcast_event(Avm2Context* ctx, Avm2Object* event, Avm2Class* filter_class);
// Stage 8: construct a MouseEvent/KeyboardEvent/FocusEvent with its native
// state filled directly (bypassing the AS3 ctor arg dance). `type` interned by
// the caller. The returned object is a fully-formed Event subclass instance.
Avm2Object* avm2_mouse_event_new(Avm2Context* ctx, const Avm2String* type,
                                 int bubbles, int cancelable, double local_x,
                                 double local_y, Avm2Object* related,
                                 int shift, int ctrl, int alt, int button_down,
                                 int32_t delta);
Avm2Object* avm2_keyboard_event_new(Avm2Context* ctx, const Avm2String* type,
                                    int bubbles, int cancelable,
                                    uint32_t char_code, uint32_t key_code,
                                    uint32_t key_location, int ctrl, int alt,
                                    int shift);
Avm2Object* avm2_focus_event_new(Avm2Context* ctx, const Avm2String* type,
                                 int bubbles, int cancelable,
                                 Avm2Object* related, int shift,
                                 uint32_t key_code, const char* direction);
// flash.events.TextEvent (Stage 8: TextField textInput). Returns the event;
// dispatch it and read ->cancelled to honor preventDefault.
Avm2Object* avm2_text_event_new(Avm2Context* ctx, const Avm2String* type,
                                int bubbles, int cancelable,
                                const Avm2String* text);
// Was the event's default prevented (cancelled)? NULL-safe.
int avm2_event_is_cancelled(Avm2Object* event);
// Display parent hook used for ancestor walks; reads the display ext.
Avm2Object* avm2_display_parent(Avm2Context* ctx, Avm2Object* obj);

// flash.utils.Timer / flash.events.TimerEvent (Stage 10). The Timer class +
// the shared setTimeout/setInterval/Timer priority list live in avm2_display.c
// (co-located with the tick); TimerEvent lives in avm2_events.c.
void avm2_register_timer_class(Avm2Context* ctx);   // avm2_display.c
Avm2Object* avm2_timer_event_new(Avm2Context* ctx, const Avm2String* type,
                                 int bubbles, int cancelable);
// getTimer() elapsed-time value (ms since start), read off the timer clock.
double avm2_timer_elapsed_ms(void);

// flash.media Sound family (avm2_media.c — Stage 10).
void avm2_register_media(Avm2Context* ctx);
// Build an AS3 SoundTransform object from a core i32×100 transform, and read
// one back into a 5-slot core array {l2l,l2r,r2l,r2r,volume}. Used by
// SoundChannel/SoundMixer and DisplayObject.soundTransform. read returns 0 if
// `v` is not a SoundTransform.
Avm2Value avm2_sound_transform_from_core(Avm2Context* ctx, const int32_t core[5]);
int avm2_sound_transform_read(Avm2Context* ctx, Avm2Value v, int32_t out[5]);
// Mixer bridge (real audio output; both are no-ops under NO_GRAPHICS):
// register embedded DefineSound payloads with the shared audio mixer at boot,
// and per-tick dispatch Event.SOUND_COMPLETE for drained playbacks.
void avm2_media_register_sounds(Avm2Context* ctx);
void avm2_media_poll(Avm2Context* ctx);

// flash.text module (avm2_text.c — Stage 6): TextFormat/TextField engine.
void avm2_register_text(Avm2Context* ctx);
// Adds the full TextField property surface to the class shell created by
// avm2_display.c.
void avm2_text_init_textfield_class(Avm2Context* ctx, Avm2Class* textfield);
// Alloc hook half for script-created TextFields (`new TextField()`).
void avm2_text_edittext_init(Avm2Context* ctx, Avm2Object* obj);
// Timeline instantiation: seed EditText state from the DefineEditText tag.
void avm2_text_seed_from_tag(Avm2Context* ctx, Avm2Object* obj, uint16_t char_id);
// EditText-owned bounds accessors (TextField width/height/x/y semantics —
// only valid when ext->edittext != NULL).
double avm2_text_get_width_px(Avm2Context* ctx, Avm2Object* obj);
double avm2_text_get_height_px(Avm2Context* ctx, Avm2Object* obj);
void avm2_text_set_width_px(Avm2Context* ctx, Avm2Object* obj, double value);
void avm2_text_set_height_px(Avm2Context* ctx, Avm2Object* obj, double value);
int32_t avm2_text_bounds_x_offset(Avm2Context* ctx, Avm2Object* obj, double scale_x);
void avm2_text_apply_pending_bounds(Avm2Context* ctx, Avm2Object* obj);
int32_t avm2_text_bounds_y_offset(Avm2Context* ctx, Avm2Object* obj, double scale_y);

// flash.display.BitmapData / Bitmap (avm2_bitmap.c — Stage 7).
void avm2_register_bitmap(Avm2Context* ctx);
// Wire the Bitmap class shell (created by avm2_register_display, so it gets
// display_native_init): adds the ctor + bitmapData/pixelSnapping/smoothing
// accessors. Called from avm2_register_display.
void avm2_bitmap_wire_bitmap(Avm2Context* ctx, Avm2Class* bitmap_cls);
// BitmapData instance state. Pixels are premultiplied ARGB, one uint32 per
// pixel in 0xAARRGGBB form (the value AS3 reads/writes), row-major.
typedef struct Avm2BitmapDataExt
{
	uint32_t width, height;
	uint8_t transparency;
	uint8_t disposed;
	uint32_t* pixels;  // width*height entries; NULL when 0-size / disposed
} Avm2BitmapDataExt;
// NULL when the value is not a BitmapData (subclasses included).
Avm2BitmapDataExt* avm2_bitmapdata_ext_of(Avm2Context* ctx, Avm2Value v);
// Bitmap self-bounds hook for avm2_display.c: 1 + w/h (pixels) if obj is a
// Bitmap with a live bitmapData, else 0.
int avm2_bitmap_self_dims(Avm2Context* ctx, Avm2Object* obj, uint32_t* w, uint32_t* h);
// Timeline placement of a bitmap character: seed `child` (a plain Bitmap
// display object) with a bitmapData. `bd_class` (a BitmapData subclass bound
// to the char, or NULL) is constructed with (1,1) — running its user ctor —
// else a plain BitmapData is seeded from the embedded asset for char_id.
void avm2_bitmap_seed_timeline(Avm2Context* ctx, Avm2Object* child,
                               uint16_t char_id, Avm2Class* bd_class);

// Display module (avm2_display.c — Stage-5 tranche 2+).
void avm2_register_display(Avm2Context* ctx);
// NULL when obj is not a DisplayObject descendant.
Avm2DisplayObjectExt* avm2_display_ext_of(Avm2Context* ctx, Avm2Object* obj);
// SymbolClass char bound to a class (walks the class hierarchy); 0 = none.
uint16_t avm2_display_char_for_class(Avm2Class* cls);
// Build the stage + root (SymbolClass char 0 / bound placed symbols) and
// remember them on ctx. Called from runSWF_avm2 after script eager-init.
void avm2_display_build_stage(Avm2Context* ctx, const char* root_class_name);
// One full frame tick: Enter -> Construct -> FrameScripts -> Exit
// (Ruffle frame_lifecycle.rs run_all_phases_avm2).
void avm2_display_run_tick(Avm2Context* ctx);

// Stage 8 input harness (avm2_display.c): parse input_events.txt (main.c) and
// pump one WAIT group per tick (called at the tail of avm2_display_run_tick).
void avm2_input_load(const char* path);
void avm2_input_pump_tick(Avm2Context* ctx);
// Live browser key injection (Stage 13c) — called from the emscripten keyboard
// callbacks to enqueue a keyDown/keyUp drained by avm2_input_pump_tick.
void avm2_input_inject_key(int is_down, int32_t key_code,
                           int32_t char_code, int32_t key_location);
// Live browser mouse injection (RWK-3) — same ring. kind 0=move/1=down/2=up,
// x/y stage pixels, button 0/1/2, click_count = DOM detail (>=2 → doubleClick).
void avm2_input_inject_mouse(int kind, float x, float y, int button,
                             int click_count);

// Text-editing bridge (avm2_text.c): route a physical key / typed char /
// text-control command to the focused TextField's EditText engine. `focus` may
// be NULL or a non-TextField (ignored). Returns nothing; a non-editable field
// still consumes selection/caret navigation keys.
void avm2_text_input_key(Avm2Context* ctx, Avm2Object* focus, int32_t key_code,
                         int32_t char_code, int shift);
void avm2_text_input_char(Avm2Context* ctx, Avm2Object* focus, int32_t codepoint);
void avm2_text_input_control(Avm2Context* ctx, Avm2Object* focus,
                             const char* ctrl, const char* clipboard);
// EditText flag accessors for the mouse-pick path (NULL-safe on the ext ptr).
int avm2_text_is_selectable(struct Avm2EditTextExt* et);
int avm2_text_was_static(struct Avm2EditTextExt* et);
int avm2_text_is_editable(struct Avm2EditTextExt* et);

// Builtin class handles the runtime needs by identity.
typedef struct Avm2Builtins
{
	Avm2Class* object_class;
	Avm2Class* class_class;
	Avm2Class* function_class;
	Avm2Class* global_class;  // class of global objects ("[object global]")
	Avm2Class* number_class;
	Avm2Class* int_class;
	Avm2Class* uint_class;
	Avm2Class* boolean_class;
	Avm2Class* string_class;
	Avm2Class* array_class;
	Avm2Class* math_class;
	Avm2Class* error_class;
	Avm2Class* type_error_class;
	Avm2Class* reference_error_class;
	Avm2Class* argument_error_class;
	Avm2Class* range_error_class;
	Avm2Class* verify_error_class;
	Avm2Class* eval_error_class;
	Avm2Class* security_error_class;
	Avm2Class* definition_error_class;
	Avm2Class* uri_error_class;
	Avm2Class* syntax_error_class;
	Avm2Class* uninitialized_error_class;
	Avm2Class* io_error_class;
	Avm2Class* memory_error_class;
	Avm2Class* illegal_operation_error_class;
	Avm2Class* xml_class;       // stub: only typeof/is checks
	Avm2Class* xml_list_class;  // stub
	Avm2Class* movieclip_class;
	Avm2Class* event_class;
	Avm2Class* mouse_event_class;
	Avm2Class* keyboard_event_class;
	Avm2Class* focus_event_class;
	Avm2Class* text_event_class;
	Avm2Class* timer_event_class;
	Avm2Class* timer_class;             // flash.utils.Timer
	Avm2Class* sound_class;             // flash.media.Sound
	Avm2Class* sound_channel_class;     // flash.media.SoundChannel
	Avm2Class* sound_transform_class;   // flash.media.SoundTransform
	Avm2Class* event_dispatcher_class;
	Avm2Class* ievent_dispatcher_class;  // interface
	Avm2Class* display_object_class;
	Avm2Class* loader_info_class;        // flash.display.LoaderInfo
	Avm2Class* interactive_object_class;
	Avm2Class* doc_class;                // DisplayObjectContainer
	Avm2Class* sprite_class;
	Avm2Class* shape_class;
	Avm2Class* bitmap_class;
	Avm2Class* bitmapdata_class;
	Avm2Class* stage_class;
	Avm2Class* simple_button_class;
	Avm2Class* regexp_class;
	Avm2Class* namespace_class;
	Avm2Class* qname_class;
	Avm2Class* dictionary_class;
	Avm2Class* proxy_class;
	Avm2Class* bytearray_class;
	Avm2Class* eof_error_class;
	Avm2Class* date_class;
	Avm2Class* vector_class;         // generic __AS3__.vec::Vector
	Avm2Class* vector_int_class;     // Vector.<int>
	Avm2Class* vector_uint_class;    // Vector.<uint>
	Avm2Class* vector_double_class;  // Vector.<Number>
	Avm2Class* vector_object_class;  // Vector.<*>
} Avm2Builtins;

#endif // AVM2_GLOBALS_H
