// flash.events — the real event machinery (Stage 5 tranche 1).
//
// Event carries internal state (Ruffle events.rs Event struct) surfaced
// through const getters; EventDispatcher implements Ruffle's DispatchList
// semantics (per-type priority buckets, capture split, dedup by
// (listener, useCapture)) and the 3-phase DOM dispatch algorithm
// (events.rs dispatch_event), plus the FP broadcast-event registry
// (avm2.rs BROADCAST_WHITELIST / broadcast_event) that the frame
// lifecycle (tranche 3) drives.
//
// Sources of truth: Ruffle core/src/avm2/events.rs,
// globals/flash/events/{Event,EventDispatcher}.as + event*.rs.

#include <stdio.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>
#include <avm2/avm2_value.h>

// ---------------------------------------------------------------------------
// Shared helpers
// ---------------------------------------------------------------------------

static Avm2PropKey events_key(const char* ns, const char* name)
{
	Avm2PropKey k;
	k.name = name;
	k.name_len = (uint32_t) strlen(name);
	k.ns_kind = 0x16;
	k.ns_uri = ns;
	k.ns_len = (uint32_t) strlen(ns);
	return k;
}

static int class_is_a(const Avm2Class* cls, const Avm2Class* ancestor)
{
	for (const Avm2Class* c = cls; c != NULL; c = c->super_class)
	{
		if (c == ancestor) return 1;
	}
	return 0;
}

Avm2EventExt* avm2_event_ext_of(Avm2Value v)
{
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL) return NULL;
	Avm2Object* o = v.u.obj;
	Avm2Context* ctx = avm2_get_context();
	if (o->cls == NULL || !class_is_a(o->cls, ctx->builtins.event_class)) return NULL;
	return (Avm2EventExt*) o->native_ext;
}

Avm2EventDispatcherExt* avm2_dispatcher_ext_of(Avm2Context* ctx, Avm2Object* obj)
{
	if (obj == NULL || obj->cls == NULL) return NULL;
	if (!class_is_a(obj->cls, ctx->builtins.event_dispatcher_class)) return NULL;
	return (Avm2EventDispatcherExt*) obj->native_ext;
}

Avm2Object* avm2_display_parent(Avm2Context* ctx, Avm2Object* obj)
{
	if (obj == NULL || obj->cls == NULL || obj->native_ext == NULL) return NULL;
	if (!class_is_a(obj->cls, ctx->builtins.display_object_class)) return NULL;
	return ((Avm2DisplayObjectExt*) obj->native_ext)->parent;
}

// ---------------------------------------------------------------------------
// flash.events.Event
// ---------------------------------------------------------------------------

enum
{
	EVT_PROP_ALLOW = 0,
	EVT_PROP_STOP = 1,
	EVT_PROP_STOP_IMMEDIATE = 2,
};

enum
{
	EVT_PHASE_CAPTURING = 1,
	EVT_PHASE_AT_TARGET = 2,
	EVT_PHASE_BUBBLING = 3,
};

static void event_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	(void) ctx;
	Avm2EventExt* ext = obj->native_ext;
	ext->phase = EVT_PHASE_AT_TARGET;
}

static Avm2EventExt* this_event(Avm2Activation* act)
{
	Avm2EventExt* ext = avm2_event_ext_of(act->this_val);
	if (ext == NULL)
	{
		avm2_fatal("flash.events.Event native on a non-Event receiver");
	}
	return ext;
}

static Avm2Value event_init(Avm2Activation* act)
{
	Avm2EventExt* ext = this_event(act);
	ext->type = act->argc > 0 ? avm2_coerce_to_string(act->ctx, act->args[0]) : NULL;
	ext->bubbles = act->argc > 1 && avm2_coerce_to_boolean(act->args[1]);
	ext->cancelable = act->argc > 2 && avm2_coerce_to_boolean(act->args[2]);
	return avm2_undefined();
}

static Avm2Value event_get_type(Avm2Activation* act)
{
	Avm2EventExt* ext = this_event(act);
	return ext->type != NULL ? avm2_string(ext->type) : avm2_null();
}

static Avm2Value event_get_bubbles(Avm2Activation* act)
{
	return avm2_bool(this_event(act)->bubbles != 0);
}

static Avm2Value event_get_cancelable(Avm2Activation* act)
{
	return avm2_bool(this_event(act)->cancelable != 0);
}

static Avm2Value event_get_target(Avm2Activation* act)
{
	Avm2EventExt* ext = this_event(act);
	return ext->target != NULL ? avm2_object_value(ext->target) : avm2_null();
}

static Avm2Value event_get_current_target(Avm2Activation* act)
{
	Avm2EventExt* ext = this_event(act);
	return ext->current_target != NULL ? avm2_object_value(ext->current_target)
	                                   : avm2_null();
}

static Avm2Value event_get_event_phase(Avm2Activation* act)
{
	return avm2_uint_value(this_event(act)->phase);
}

static Avm2Value event_is_default_prevented(Avm2Activation* act)
{
	return avm2_bool(this_event(act)->cancelled != 0);
}

static Avm2Value event_prevent_default(Avm2Activation* act)
{
	Avm2EventExt* ext = this_event(act);
	if (ext->cancelable) ext->cancelled = 1;
	return avm2_undefined();
}

static Avm2Value event_stop_propagation(Avm2Activation* act)
{
	Avm2EventExt* ext = this_event(act);
	if (ext->propagation != EVT_PROP_STOP_IMMEDIATE)
	{
		ext->propagation = EVT_PROP_STOP;
	}
	return avm2_undefined();
}

static Avm2Value event_stop_immediate_propagation(Avm2Activation* act)
{
	this_event(act)->propagation = EVT_PROP_STOP_IMMEDIATE;
	return avm2_undefined();
}

static Avm2Value event_clone(Avm2Activation* act)
{
	// Event.as: return new Event(this.type, this.bubbles, this.cancelable)
	// — always the BASE Event class (a subclass that fails to override
	// clone loses its type — event_clone), reading the props virtually.
	Avm2Context* ctx = act->ctx;
	Avm2Value args[3];
	args[0] = avm2_get_public_property(ctx, act->this_val, "type", 4, NULL);
	args[1] = avm2_get_public_property(ctx, act->this_val, "bubbles", 7, NULL);
	args[2] = avm2_get_public_property(ctx, act->this_val, "cancelable", 10, NULL);
	return avm2_class_construct(ctx, ctx->builtins.event_class, args, 3);
}

static Avm2Value event_format_to_string(Avm2Activation* act)
{
	// Event.as formatToString(className, ...arguments): each key reads
	// `this[key]` virtually; String values print quoted.
	Avm2Context* ctx = act->ctx;
	const Avm2String* cname = act->argc > 0
		? avm2_coerce_to_string(ctx, act->args[0])
		: avm2_string_from_literal(ctx, "undefined");
	// Build into a growing heap buffer.
	uint32_t cap = 64 + cname->len;
	char* buf = avm2_alloc(ctx, cap);
	uint32_t len = 0;
	buf[len++] = '[';
	memcpy(buf + len, cname->utf8, cname->len);
	len += cname->len;
	for (uint32_t i = 1; i < act->argc; i++)
	{
		// The rest params are typed String in Event.as: undefined/null
		// coerce to null, which concatenates (and property-reads) as
		// "null" — `formatToString("C", undefined)` prints null=undefined.
		const Avm2String* key =
			(act->args[i].kind == AVM2_VALUE_UNDEFINED
			 || act->args[i].kind == AVM2_VALUE_NULL)
				? avm2_string_from_literal(ctx, "null")
				: avm2_coerce_to_string(ctx, act->args[i]);
		Avm2Value val = avm2_get_public_property(ctx, act->this_val,
		                                         key->utf8, key->len, NULL);
		int quoted = (val.kind == AVM2_VALUE_STRING);
		const Avm2String* vs = avm2_coerce_to_string(ctx, val);
		uint32_t need = len + 1 + key->len + 1 + vs->len + 4;
		if (need > cap)
		{
			uint32_t new_cap = need * 2;
			char* grown = avm2_alloc(ctx, new_cap);
			memcpy(grown, buf, len);
			buf = grown;
			cap = new_cap;
		}
		buf[len++] = ' ';
		memcpy(buf + len, key->utf8, key->len);
		len += key->len;
		buf[len++] = '=';
		if (quoted) buf[len++] = '"';
		memcpy(buf + len, vs->utf8, vs->len);
		len += vs->len;
		if (quoted) buf[len++] = '"';
	}
	if (len + 2 > cap)
	{
		char* grown = avm2_alloc(ctx, len + 2);
		memcpy(grown, buf, len);
		buf = grown;
	}
	buf[len++] = ']';
	return avm2_string(avm2_string_new(ctx, buf, len));
}

static Avm2Value event_to_string(Avm2Activation* act)
{
	// Event.as: this.formatToString("Event","type","bubbles","cancelable",
	// "eventPhase") — a virtual call (subclasses may override).
	Avm2Context* ctx = act->ctx;
	Avm2Value args[5];
	args[0] = avm2_string(avm2_string_from_literal(ctx, "Event"));
	args[1] = avm2_string(avm2_string_from_literal(ctx, "type"));
	args[2] = avm2_string(avm2_string_from_literal(ctx, "bubbles"));
	args[3] = avm2_string(avm2_string_from_literal(ctx, "cancelable"));
	args[4] = avm2_string(avm2_string_from_literal(ctx, "eventPhase"));
	return avm2_call_public_property(ctx, act->this_val, "formatToString", 14,
	                                 args, 5);
}

Avm2Object* avm2_event_new(Avm2Context* ctx, const Avm2String* type,
                           int bubbles, int cancelable)
{
	Avm2Value args[3];
	args[0] = avm2_string(type);
	args[1] = avm2_bool(bubbles != 0);
	args[2] = avm2_bool(cancelable != 0);
	Avm2Value v = avm2_class_construct(ctx, ctx->builtins.event_class, args, 3);
	return v.u.obj;
}

// ---------------------------------------------------------------------------
// EventDispatcher listener list (Ruffle events.rs DispatchList)
// ---------------------------------------------------------------------------

struct EDListener
{
	EDListener* next;
	const Avm2String* type;
	Avm2Value fn;
	int32_t priority;
	uint8_t use_capture;
};

// Any registration with the same (type, listener, useCapture) already
// present (at ANY priority) makes addEventListener a silent no-op.
static int ed_list_contains(EDListener* head, const Avm2String* type,
                            Avm2Value fn, int use_capture)
{
	for (EDListener* l = head; l != NULL; l = l->next)
	{
		if (l->use_capture == use_capture && avm2_string_equals(l->type, type)
		    && avm2_strict_eq(l->fn, fn))
		{
			return 1;
		}
	}
	return 0;
}

static void ed_list_add(Avm2Context* ctx, Avm2EventDispatcherExt* ext,
                        const Avm2String* type, Avm2Value fn, int use_capture,
                        int32_t priority)
{
	if (ed_list_contains(ext->head, type, fn, use_capture)) return;
	EDListener* nl = avm2_alloc(ctx, sizeof(EDListener));
	nl->type = type;
	nl->fn = fn;
	nl->priority = priority;
	nl->use_capture = (uint8_t) use_capture;
	// Insertion point: before the first same-type node with a strictly
	// lower priority (higher priorities run first; equal priorities run in
	// insertion order — eventdispatcher_dispatchevent_handlerorder).
	EDListener** link = &ext->head;
	while (*link != NULL)
	{
		EDListener* cur = *link;
		if (avm2_string_equals(cur->type, type) && cur->priority < priority)
		{
			break;
		}
		link = &cur->next;
	}
	nl->next = *link;
	*link = nl;
}

static void ed_list_remove(Avm2EventDispatcherExt* ext, const Avm2String* type,
                           Avm2Value fn, int use_capture)
{
	for (EDListener** link = &ext->head; *link != NULL; )
	{
		EDListener* l = *link;
		if (l->use_capture == (uint8_t) use_capture
		    && avm2_string_equals(l->type, type) && avm2_strict_eq(l->fn, fn))
		{
			*link = l->next;
		}
		else
		{
			link = &l->next;
		}
	}
}

static int ed_list_has_type(EDListener* head, const Avm2String* type)
{
	for (EDListener* l = head; l != NULL; l = l->next)
	{
		if (avm2_string_equals(l->type, type)) return 1;
	}
	return 0;
}

// ---------------------------------------------------------------------------
// Broadcast registry (Ruffle avm2.rs BROADCAST_WHITELIST / broadcast_list)
// ---------------------------------------------------------------------------

static const char* const k_broadcast_whitelist[4] = {
	"enterFrame", "exitFrame", "frameConstructed", "render"
};

typedef struct BroadcastBucket
{
	uint32_t count;
	uint32_t cap;
	Avm2Object** objs;  // registration order; dedup by identity
} BroadcastBucket;

static BroadcastBucket g_broadcast[4];

static int broadcast_index(const Avm2String* type)
{
	for (int i = 0; i < 4; i++)
	{
		size_t wl = strlen(k_broadcast_whitelist[i]);
		if (type->len == wl && memcmp(type->utf8, k_broadcast_whitelist[i], wl) == 0)
		{
			return i;
		}
	}
	return -1;
}

static void broadcast_register(Avm2Context* ctx, Avm2Object* obj,
                               const Avm2String* type)
{
	int bi = broadcast_index(type);
	if (bi < 0) return;
	BroadcastBucket* b = &g_broadcast[bi];
	for (uint32_t i = 0; i < b->count; i++)
	{
		if (b->objs[i] == obj) return;
	}
	if (b->count == b->cap)
	{
		uint32_t new_cap = b->cap > 0 ? b->cap * 2 : 16;
		Avm2Object** grown = avm2_alloc(ctx, new_cap * sizeof(Avm2Object*));
		memcpy(grown, b->objs, b->count * sizeof(Avm2Object*));
		b->objs = grown;
		b->cap = new_cap;
	}
	b->objs[b->count++] = obj;
}

// ---------------------------------------------------------------------------
// Dispatch (Ruffle events.rs dispatch_event_to_target / dispatch_event)
// ---------------------------------------------------------------------------

// Call every matching handler on `dispatcher` for the event's current
// phase. target/currentTarget are only stamped when at least one handler
// matched (that is FP's "handled" signal — event_target_set).
static void dispatch_event_to_target(Avm2Context* ctx, Avm2Object* dispatcher,
                                     Avm2Object* real_target,
                                     Avm2Object* current_target, Avm2Object* event)
{
	Avm2EventDispatcherExt* ext = avm2_dispatcher_ext_of(ctx, dispatcher);
	Avm2EventExt* evt = (Avm2EventExt*) event->native_ext;
	if (ext == NULL || evt == NULL || evt->type == NULL) return;

	int use_capture = (evt->phase == EVT_PHASE_CAPTURING);

	// Snapshot the handlers before calling any of them: listeners added or
	// removed by a handler don't affect the in-flight dispatch.
	uint32_t n = 0;
	for (EDListener* l = ext->head; l != NULL; l = l->next)
	{
		if (l->use_capture == use_capture && avm2_string_equals(l->type, evt->type))
		{
			n++;
		}
	}
	if (n == 0) return;
	Avm2Value stack_fns[16];
	Avm2Value* fns = (n <= 16) ? stack_fns : avm2_alloc(ctx, n * sizeof(Avm2Value));
	uint32_t k = 0;
	for (EDListener* l = ext->head; l != NULL; l = l->next)
	{
		if (l->use_capture == use_capture && avm2_string_equals(l->type, evt->type))
		{
			fns[k++] = l->fn;
		}
	}

	evt->target = real_target;
	evt->current_target = current_target;

	// Handlers run with the toplevel global as `this` (function_unbound_this)
	// and an uncaught error aborts only that handler, not the dispatch
	// (event_handler_exception).
	Avm2Value recv = avm2_object_value(ctx->builtin_globals);
	for (uint32_t i = 0; i < n; i++)
	{
		if (evt->propagation == EVT_PROP_STOP_IMMEDIATE) break;
		Avm2TryFrame top;
		avm2_try_push_catch_all(ctx, &top);
		if (setjmp(top.jb) == 0)
		{
			Avm2Value args[1] = { avm2_object_value(event) };
			avm2_call_value(ctx, fns[i], recv, args, 1);
		}
		avm2_try_pop_frame(&top);
	}
}

int avm2_dispatch_event(Avm2Context* ctx, Avm2Object* dispatcher, Avm2Object* event)
{
	Avm2EventDispatcherExt* ext = avm2_dispatcher_ext_of(ctx, dispatcher);
	Avm2EventExt* evt = (Avm2EventExt*) event->native_ext;
	if (evt == NULL)
	{
		avm2_fatal("avm2_dispatch_event on a non-Event object");
	}

	Avm2Object* target = dispatcher;
	if (ext != NULL && ext->ed_target.kind == AVM2_VALUE_OBJECT
	    && ext->ed_target.u.obj != NULL)
	{
		target = ext->ed_target.u.obj;
	}

	// Ancestor chain: nearest parent first (Ruffle builds the same list).
	uint32_t anc_count = 0;
	Avm2Object* anc_stack[64];
	for (Avm2Object* p = avm2_display_parent(ctx, target);
	     p != NULL && anc_count < 64; p = avm2_display_parent(ctx, p))
	{
		anc_stack[anc_count++] = p;
	}

	evt->phase = EVT_PHASE_CAPTURING;
	for (uint32_t i = anc_count; i > 0; i--)
	{
		if (evt->propagation != EVT_PROP_ALLOW) break;
		Avm2Object* anc = anc_stack[i - 1];
		dispatch_event_to_target(ctx, anc, target, anc, event);
	}

	evt->phase = EVT_PHASE_AT_TARGET;
	if (evt->propagation == EVT_PROP_ALLOW)
	{
		dispatch_event_to_target(ctx, dispatcher, target, target, event);
	}

	evt->phase = EVT_PHASE_BUBBLING;
	if (evt->bubbles)
	{
		for (uint32_t i = 0; i < anc_count; i++)
		{
			if (evt->propagation != EVT_PROP_ALLOW) break;
			dispatch_event_to_target(ctx, anc_stack[i], target, anc_stack[i], event);
		}
	}

	return evt->target != NULL;
}

void avm2_broadcast_event(Avm2Context* ctx, Avm2Object* event, Avm2Class* filter_class)
{
	Avm2EventExt* evt = (Avm2EventExt*) event->native_ext;
	if (evt == NULL || evt->type == NULL) return;
	int bi = broadcast_index(evt->type);
	if (bi < 0) return;
	BroadcastBucket* b = &g_broadcast[bi];
	// Ruffle captures the list length BEFORE iterating: dispatchers
	// registered DURING the broadcast wait until the next one
	// (movieclip_displayevents_enterframesymbol).
	uint32_t n = b->count;
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2Object* obj = b->objs[i];
		if (filter_class != NULL
		    && (obj->cls == NULL || !class_is_a(obj->cls, filter_class)))
		{
			continue;
		}
		Avm2EventDispatcherExt* ext = avm2_dispatcher_ext_of(ctx, obj);
		Avm2Object* target = obj;
		if (ext != NULL && ext->ed_target.kind == AVM2_VALUE_OBJECT
		    && ext->ed_target.u.obj != NULL)
		{
			target = ext->ed_target.u.obj;
		}
		evt->phase = EVT_PHASE_AT_TARGET;
		evt->propagation = EVT_PROP_ALLOW;
		dispatch_event_to_target(ctx, obj, target, target, event);
	}
}

// ---------------------------------------------------------------------------
// EventDispatcher natives
// ---------------------------------------------------------------------------

static Avm2EventDispatcherExt* this_dispatcher(Avm2Activation* act)
{
	if (act->this_val.kind != AVM2_VALUE_OBJECT) return NULL;
	return avm2_dispatcher_ext_of(act->ctx, act->this_val.u.obj);
}

static Avm2Value ed_init(Avm2Activation* act)
{
	// EventDispatcher(target:IEventDispatcher = null).
	Avm2EventDispatcherExt* ext = this_dispatcher(act);
	if (ext != NULL && act->argc > 0)
	{
		ext->ed_target = act->args[0];
	}
	return avm2_undefined();
}

static Avm2Value ed_add_event_listener(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2EventDispatcherExt* ext = this_dispatcher(act);
	if (ext == NULL) return avm2_undefined();
	Avm2Value listener = act->argc > 1 ? act->args[1] : avm2_null();
	if (listener.kind == AVM2_VALUE_NULL || listener.kind == AVM2_VALUE_UNDEFINED)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter listener must be non-null.");
	}
	const Avm2String* type = act->argc > 0
		? avm2_coerce_to_string(ctx, act->args[0])
		: avm2_string_from_literal(ctx, "null");
	int use_capture = act->argc > 2 && avm2_coerce_to_boolean(act->args[2]);
	int32_t priority = act->argc > 3 ? avm2_coerce_to_i32(ctx, act->args[3]) : 0;
	ed_list_add(ctx, ext, type, listener, use_capture, priority);
	broadcast_register(ctx, act->this_val.u.obj, type);
	return avm2_undefined();
}

static Avm2Value ed_remove_event_listener(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2EventDispatcherExt* ext = this_dispatcher(act);
	if (ext == NULL || act->argc < 2) return avm2_undefined();
	const Avm2String* type = avm2_coerce_to_string(ctx, act->args[0]);
	int use_capture = act->argc > 2 && avm2_coerce_to_boolean(act->args[2]);
	ed_list_remove(ext, type, act->args[1], use_capture);
	return avm2_undefined();
}

static Avm2Value ed_has_event_listener(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2EventDispatcherExt* ext = this_dispatcher(act);
	if (ext == NULL || act->argc < 1) return avm2_bool(false);
	const Avm2String* type = avm2_coerce_to_string(ctx, act->args[0]);
	return avm2_bool(ed_list_has_type(ext->head, type) != 0);
}

static Avm2Value ed_will_trigger(Avm2Activation* act)
{
	// Ruffle event_dispatcher.rs will_trigger: own list, else recurse on
	// the display parent of the aggregation target.
	Avm2Context* ctx = act->ctx;
	if (act->argc < 1 || act->this_val.kind != AVM2_VALUE_OBJECT)
	{
		return avm2_bool(false);
	}
	const Avm2String* type = avm2_coerce_to_string(ctx, act->args[0]);
	Avm2Object* cur = act->this_val.u.obj;
	while (cur != NULL)
	{
		Avm2EventDispatcherExt* ext = avm2_dispatcher_ext_of(ctx, cur);
		if (ext != NULL && ed_list_has_type(ext->head, type))
		{
			return avm2_bool(true);
		}
		Avm2Object* target = cur;
		if (ext != NULL && ext->ed_target.kind == AVM2_VALUE_OBJECT
		    && ext->ed_target.u.obj != NULL)
		{
			target = ext->ed_target.u.obj;
		}
		cur = avm2_display_parent(ctx, target);
	}
	return avm2_bool(false);
}

static Avm2Value ed_dispatch_event(Avm2Activation* act)
{
	// EventDispatcher.as dispatchEvent: a redispatch (event.target already
	// set — read via the PUBLIC getter) dispatches event.clone() (also a
	// virtual call); a null clone throws 2007 (event_clone_error_redispatch).
	Avm2Context* ctx = act->ctx;
	Avm2Value event_val = act->argc > 0 ? act->args[0] : avm2_null();
	if (event_val.kind != AVM2_VALUE_OBJECT || event_val.u.obj == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter event must be non-null.");
	}
	Avm2Value tv = avm2_get_public_property(ctx, event_val, "target", 6, NULL);
	if (avm2_coerce_to_boolean(tv))
	{
		event_val = avm2_call_public_property(ctx, event_val, "clone", 5, NULL, 0);
		if (event_val.kind != AVM2_VALUE_OBJECT || event_val.u.obj == NULL)
		{
			avm2_throw_error(ctx, ctx->builtins.type_error_class,
			                 "Error #2007: Parameter event must be non-null.");
		}
	}
	Avm2EventExt* evt = avm2_event_ext_of(event_val);
	if (evt == NULL)
	{
		avm2_fatal("dispatchEvent on a non-Event argument (unimplemented coercion)");
	}
	if (act->this_val.kind != AVM2_VALUE_OBJECT)
	{
		return avm2_bool(false);
	}
	avm2_dispatch_event(ctx, act->this_val.u.obj, event_val.u.obj);
	return avm2_bool(evt->cancelled == 0);
}

static Avm2Value ed_to_string(Avm2Activation* act)
{
	// EventDispatcher.as: Object.prototype.toString.call(this) — the
	// CURRENT prototype function, looked up dynamically
	// (eventdispatcher_tostring replaces it and expects the shim to run).
	Avm2Context* ctx = act->ctx;
	Avm2Object* oproto = ctx->builtins.object_class->prototype_obj;
	Avm2Value* ts = avm2_object_find_dynamic(oproto, "toString", 8);
	if (ts != NULL)
	{
		return avm2_call_value(ctx, *ts, act->this_val, NULL, 0);
	}
	return avm2_string(avm2_string_from_literal(ctx, "[object Object]"));
}

// ---------------------------------------------------------------------------
// Registration
// ---------------------------------------------------------------------------

void avm2_register_events(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;

	// flash.events.Event.
	Avm2Class* event = avm2_builtin_class(ctx, "flash.events", "Event",
	                                      b->object_class);
	event->instance_init.fn = event_init;
	event->instance_init.debug_name = "Event";
	event->native_ext_size = sizeof(Avm2EventExt);
	event->native_init = event_native_init;
	b->event_class = event;
	avm2_builtin_add_getter(ctx, event, "type", event_get_type);
	avm2_builtin_add_getter(ctx, event, "bubbles", event_get_bubbles);
	avm2_builtin_add_getter(ctx, event, "cancelable", event_get_cancelable);
	avm2_builtin_add_getter(ctx, event, "target", event_get_target);
	avm2_builtin_add_getter(ctx, event, "currentTarget", event_get_current_target);
	avm2_builtin_add_getter(ctx, event, "eventPhase", event_get_event_phase);
	avm2_builtin_add_method(ctx, event, "clone", event_clone);
	avm2_builtin_add_method(ctx, event, "toString", event_to_string);
	avm2_builtin_add_method(ctx, event, "formatToString", event_format_to_string);
	avm2_builtin_add_method(ctx, event, "isDefaultPrevented", event_is_default_prevented);
	avm2_builtin_add_method(ctx, event, "preventDefault", event_prevent_default);
	avm2_builtin_add_method(ctx, event, "stopPropagation", event_stop_propagation);
	avm2_builtin_add_method(ctx, event, "stopImmediatePropagation",
	                        event_stop_immediate_propagation);
	// Static const inventory from Ruffle Event.as.
	static const struct { const char* name; const char* v; } consts[] = {
		{ "ACTIVATE", "activate" }, { "ADDED", "added" },
		{ "ADDED_TO_STAGE", "addedToStage" },
		{ "BROWSER_ZOOM_CHANGE", "browserZoomChange" }, { "CANCEL", "cancel" },
		{ "CHANGE", "change" }, { "CLEAR", "clear" }, { "CLOSE", "close" },
		{ "CLOSING", "closing" }, { "COMPLETE", "complete" },
		{ "CONNECT", "connect" }, { "COPY", "copy" }, { "CUT", "cut" },
		{ "DEACTIVATE", "deactivate" }, { "ENTER_FRAME", "enterFrame" },
		{ "FRAME_CONSTRUCTED", "frameConstructed" }, { "EXITING", "exiting" },
		{ "EXIT_FRAME", "exitFrame" }, { "FRAME_LABEL", "frameLabel" },
		{ "ID3", "id3" }, { "INIT", "init" }, { "MOUSE_LEAVE", "mouseLeave" },
		{ "OPEN", "open" }, { "PASTE", "paste" }, { "REMOVED", "removed" },
		{ "REMOVED_FROM_STAGE", "removedFromStage" }, { "RENDER", "render" },
		{ "RESIZE", "resize" }, { "SCROLL", "scroll" },
		{ "TEXT_INTERACTION_MODE_CHANGE", "textInteractionModeChange" },
		{ "SELECT", "select" }, { "SELECT_ALL", "selectAll" },
		{ "SOUND_COMPLETE", "soundComplete" },
		{ "TAB_CHILDREN_CHANGE", "tabChildrenChange" },
		{ "TAB_ENABLED_CHANGE", "tabEnabledChange" },
		{ "TAB_INDEX_CHANGE", "tabIndexChange" }, { "UNLOAD", "unload" },
		{ "FULLSCREEN", "fullScreen" },
		{ "CONTEXT3D_CREATE", "context3DCreate" },
		{ "TEXTURE_READY", "textureReady" }, { "VIDEO_FRAME", "videoFrame" },
		{ "SUSPEND", "suspend" }, { "CHANNEL_MESSAGE", "channelMessage" },
		{ "CHANNEL_STATE", "channelState" }, { "WORKER_STATE", "workerState" },
	};
	for (size_t i = 0; i < sizeof(consts) / sizeof(consts[0]); i++)
	{
		avm2_builtin_add_static_const(
			ctx, event, consts[i].name,
			avm2_string(avm2_string_from_literal(ctx, consts[i].v)));
	}

	// flash.events.EventPhase.
	{
		Avm2Class* phase = avm2_builtin_class(ctx, "flash.events", "EventPhase",
		                                      b->object_class);
		avm2_builtin_add_static_const(ctx, phase, "CAPTURING_PHASE", avm2_uint_value(1));
		avm2_builtin_add_static_const(ctx, phase, "AT_TARGET", avm2_uint_value(2));
		avm2_builtin_add_static_const(ctx, phase, "BUBBLING_PHASE", avm2_uint_value(3));
	}

	// flash.events.IEventDispatcher (interface): vtable entries carry the
	// interface namespace so implementor classes get call-through aliases
	// (avm2_class.c add_iface_aliases_from).
	Avm2Class* iface = avm2_builtin_class(ctx, "flash.events", "IEventDispatcher", NULL);
	iface->flags |= AVM2_CLASS_FLAG_INTERFACE;
	b->ievent_dispatcher_class = iface;
	{
		static const char* const inames[5] = {
			"addEventListener", "removeEventListener", "dispatchEvent",
			"hasEventListener", "willTrigger"
		};
		for (int i = 0; i < 5; i++)
		{
			Avm2PropEntry e;
			memset(&e, 0, sizeof(e));
			e.key = events_key("flash.events:IEventDispatcher", inames[i]);
			e.kind = AVM2_PROP_METHOD;
			e.method.debug_name = inames[i];
			e.defining_class = iface;
			avm2_vtable_append(ctx, &iface->ivtable, &e);
		}
	}

	// flash.events.EventDispatcher.
	Avm2Class* ed = avm2_builtin_class(ctx, "flash.events", "EventDispatcher",
	                                   b->object_class);
	ed->instance_init.fn = ed_init;
	ed->instance_init.debug_name = "EventDispatcher";
	ed->native_ext_size = sizeof(Avm2EventDispatcherExt);
	b->event_dispatcher_class = ed;
	avm2_builtin_add_method(ctx, ed, "addEventListener", ed_add_event_listener);
	avm2_builtin_add_method(ctx, ed, "removeEventListener", ed_remove_event_listener);
	avm2_builtin_add_method(ctx, ed, "hasEventListener", ed_has_event_listener);
	avm2_builtin_add_method(ctx, ed, "willTrigger", ed_will_trigger);
	avm2_builtin_add_method(ctx, ed, "dispatchEvent", ed_dispatch_event);
	avm2_builtin_add_method(ctx, ed, "toString", ed_to_string);
	// Declare + alias the interface (emitted classes get the same aliases
	// from class_add_interface_aliases).
	ed->interface_count = 1;
	ed->interfaces = avm2_alloc(ctx, sizeof(Avm2Class*));
	ed->interfaces[0] = iface;
	for (uint32_t i = 0; i < iface->ivtable.count; i++)
	{
		const Avm2PropEntry* ie = &iface->ivtable.entries[i];
		Avm2PropKey pub = avm2_public_key(ie->key.name, ie->key.name_len);
		const Avm2PropEntry* own = avm2_vtable_find(&ed->ivtable, &pub);
		if (own == NULL) continue;
		Avm2PropEntry alias = *own;
		alias.key = ie->key;
		avm2_vtable_append(ctx, &ed->ivtable, &alias);
	}
}
