// rando.c — the `Rando` AVM1 builtin class: an Archipelago (AP) client exposed
// to ActionScript. Modeled on date.c (native-backed constructable class).
//
// Phase 1 (native, polling) — see
// SWFRecompDocs/plans/archipelago-randomizer-integration.md.
//
// AS surface:
//   var r:Rando = new Rando(host, port, game, slot, password);
//   r.connect();
//   r.isConnected();                 -> Boolean
//   r.receivedItemsSize();           -> Number
//   r.receivedItem(i);               -> Number (item id)
//   r.hasItem(itemId);               -> Boolean
//   r.locationIsChecked(locId);      -> Boolean
//   r.sendLocation(locId);           -> undefined
//   r.storyComplete();               -> undefined
//
// The native AP_State handle is wrapped (RandoAP*) by the rando_ap.cpp shim and
// stashed on the instance as a hidden DontEnum property "__ap_handle__" (its
// pointer bits live in numeric_value, same trick date.c uses for __date_time__).
//
// Entirely gated on WITH_AP. Without it, initRandoPrototype() is a no-op and
// actionRandoGetConstructor() returns NULL, so `Rando` never registers.

#include <actionmodern/action_internal.h>
#include <actionmodern/actionrando.h>

#ifdef WITH_AP

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <actionmodern/object.h>
#include <actionmodern/rando_ap.h>

// ============================================================================
// Rando class state
// ============================================================================

#define RANDO_NUM_METHODS 8

static ASFunction g_rando_constructor;
static ASFunction g_rando_funcs[RANDO_NUM_METHODS];
static ASObject* g_rando_prototype = NULL;
static int g_rando_init_done = 0;

static const char RANDO_HANDLE_PROP[] = "__ap_handle__";
#define RANDO_HANDLE_PROP_LEN 13  // strlen("__ap_handle__")

// ============================================================================
// Small helpers
// ============================================================================

static ActionVar rando_ret_undef(void) {
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_UNDEFINED;
	return r;
}

static ActionVar rando_ret_bool(int b) {
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_BOOLEAN;
	r.data.numeric_value = b ? 1 : 0;
	return r;
}

static ActionVar rando_ret_num(double d) {
	ActionVar r = {0};
	r.type = ACTION_STACK_VALUE_F64;
	VAL(double, &r.data.numeric_value) = d;
	return r;
}

// Coerce a constructor string argument (host/port/game/slot/password) into a
// NUL-terminated UTF-8 C string. Handles STRING (UTF-16 → UTF-8) and numeric
// args (e.g. a port passed as a Number). Anything else yields "".
static void rando_arg_cstr(ActionVar* a, char* buf, int bufsize) {
	if (bufsize <= 0) return;
	buf[0] = '\0';
	if (a == NULL) return;
	if (a->type == ACTION_STACK_VALUE_STRING) {
		u16_to_utf8(a->data.string_data.heap_ptr, a->str_size, buf, bufsize);
	} else if (a->type == ACTION_STACK_VALUE_F64) {
		double d = VAL(double, &a->data.numeric_value);
		if (d == (double)(long long)d) {
			snprintf(buf, bufsize, "%lld", (long long)d);
		} else {
			snprintf(buf, bufsize, "%g", d);
		}
	} else if (a->type == ACTION_STACK_VALUE_F32) {
		snprintf(buf, bufsize, "%g", (double)VAL(float, &a->data.numeric_value));
	}
}

// Store the native handle pointer bits on the instance (hidden, DontEnum).
static void rando_set_handle(SWFAppContext* app_context, ASObject* obj, RandoAP* h) {
	ActionVar v = {0};
	v.type = ACTION_STACK_VALUE_F64;  // tag is a placeholder; we read the u64 view
	VAL(u64, &v.data.numeric_value) = (u64)(uintptr_t)h;
	setPropertyWithFlags(app_context, obj, RANDO_HANDLE_PROP, RANDO_HANDLE_PROP_LEN,
	                     &v, PROPERTY_FLAGS_DONTENUM);
}

// Read the native handle off `this`. Returns NULL for a missing/foreign
// receiver. Mirrors date_has_backing's ARRAY-thisArg guard: a Rando method
// invoked via .call([]) gets a raw ASArray* as this_obj — never Rando-backed.
static RandoAP* rando_handle(void* this_obj) {
	if (this_obj == NULL) return NULL;
	if (g_call_this_type == ACTION_STACK_VALUE_ARRAY) return NULL;
	ActionVar* v = getProperty((ASObject*)this_obj, RANDO_HANDLE_PROP, RANDO_HANDLE_PROP_LEN);
	if (v == NULL) return NULL;
	return (RandoAP*)(uintptr_t)VAL(u64, &v->data.numeric_value);
}

// Read arg[idx] as an int64 location/item id (0 if absent).
static int64_t rando_arg_id(ActionVar* args, u32 arg_count, u32 idx) {
	if (idx >= arg_count) return 0;
	return (int64_t)varToDoubleSimple(&args[idx]);
}

// ============================================================================
// Native method handlers
// ============================================================================

static ActionVar builtin_rando_constructor(SWFAppContext* app_context, ActionVar* args,
                                            u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)registers;
	if (this_obj == NULL) return rando_ret_undef();
	ASObject* obj = (ASObject*)this_obj;

	// Native-type guards (match builtin_date_constructor): don't re-init.
	if (obj->native_type != NATIVE_NONE && obj->native_type != NATIVE_RANDO) {
		return rando_ret_undef();
	}
	if (obj->native_type == NATIVE_RANDO) {
		return rando_ret_undef();
	}
	obj->native_type = NATIVE_RANDO;

	char host[256], port[64], game[128], slot[128], password[256];
	rando_arg_cstr(arg_count > 0 ? &args[0] : NULL, host, sizeof(host));
	rando_arg_cstr(arg_count > 1 ? &args[1] : NULL, port, sizeof(port));
	rando_arg_cstr(arg_count > 2 ? &args[2] : NULL, game, sizeof(game));
	rando_arg_cstr(arg_count > 3 ? &args[3] : NULL, slot, sizeof(slot));
	rando_arg_cstr(arg_count > 4 ? &args[4] : NULL, password, sizeof(password));

	RandoAP* h = rando_ap_new(host, port, game, slot, password);
	rando_set_handle(app_context, obj, h);
	return rando_ret_undef();
}

static ActionVar builtin_rando_connect(SWFAppContext* app_context, ActionVar* args,
                                        u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	rando_ap_connect(rando_handle(this_obj));
	return rando_ret_undef();
}

static ActionVar builtin_rando_isConnected(SWFAppContext* app_context, ActionVar* args,
                                           u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	return rando_ret_bool(rando_ap_is_connected(rando_handle(this_obj)));
}

static ActionVar builtin_rando_receivedItemsSize(SWFAppContext* app_context, ActionVar* args,
                                                 u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	return rando_ret_num((double)rando_ap_received_items_size(rando_handle(this_obj)));
}

static ActionVar builtin_rando_receivedItem(SWFAppContext* app_context, ActionVar* args,
                                            u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)registers;
	int64_t idx = rando_arg_id(args, arg_count, 0);
	if (idx < 0) return rando_ret_num(-1.0);
	return rando_ret_num((double)rando_ap_received_item(rando_handle(this_obj), (size_t)idx));
}

static ActionVar builtin_rando_hasItem(SWFAppContext* app_context, ActionVar* args,
                                       u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)registers;
	return rando_ret_bool(rando_ap_has_item(rando_handle(this_obj), rando_arg_id(args, arg_count, 0)));
}

static ActionVar builtin_rando_locationIsChecked(SWFAppContext* app_context, ActionVar* args,
                                                 u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)registers;
	return rando_ret_bool(rando_ap_location_is_checked(rando_handle(this_obj), rando_arg_id(args, arg_count, 0)));
}

static ActionVar builtin_rando_sendLocation(SWFAppContext* app_context, ActionVar* args,
                                            u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)registers;
	rando_ap_send_location(rando_handle(this_obj), rando_arg_id(args, arg_count, 0));
	return rando_ret_undef();
}

static ActionVar builtin_rando_storyComplete(SWFAppContext* app_context, ActionVar* args,
                                             u32 arg_count, ActionVar* registers, void* this_obj) {
	(void)app_context; (void)args; (void)arg_count; (void)registers;
	rando_ap_story_complete(rando_handle(this_obj));
	return rando_ret_undef();
}

// ============================================================================
// Prototype initialization + global registration accessor
// ============================================================================

void initRandoPrototype(SWFAppContext* app_context) {
	if (g_rando_init_done) return;
	g_rando_init_done = 1;

	memset(&g_rando_constructor, 0, sizeof(ASFunction));
	strncpy(g_rando_constructor.name, "Rando", 255);
	g_rando_constructor.function_type = 2;
	g_rando_constructor.param_count = 0;
	g_rando_constructor.advanced_func = (Function2Ptr)builtin_rando_constructor;
	registerNativeFunction(&g_rando_constructor);

	g_rando_prototype = allocObject(app_context, 16);
	retainObject(g_rando_prototype);
	g_rando_constructor.prototype_obj = g_rando_prototype;
	setObjectProto(app_context, g_rando_prototype);

	struct { const char* name; u32 name_len; Function2Ptr func; } methods[RANDO_NUM_METHODS] = {
		{"connect",          7, (Function2Ptr)builtin_rando_connect},
		{"isConnected",     11, (Function2Ptr)builtin_rando_isConnected},
		{"receivedItemsSize",17,(Function2Ptr)builtin_rando_receivedItemsSize},
		{"receivedItem",    12, (Function2Ptr)builtin_rando_receivedItem},
		{"hasItem",          7, (Function2Ptr)builtin_rando_hasItem},
		{"locationIsChecked",17,(Function2Ptr)builtin_rando_locationIsChecked},
		{"sendLocation",    12, (Function2Ptr)builtin_rando_sendLocation},
		{"storyComplete",   13, (Function2Ptr)builtin_rando_storyComplete},
	};

	for (int i = 0; i < RANDO_NUM_METHODS; i++) {
		memset(&g_rando_funcs[i], 0, sizeof(ASFunction));
		strncpy(g_rando_funcs[i].name, methods[i].name, 255);
		g_rando_funcs[i].function_type = 2;
		g_rando_funcs[i].param_count = 0;
		g_rando_funcs[i].advanced_func = methods[i].func;
		registerNativeFunction(&g_rando_funcs[i]);

		ActionVar fv = {0};
		fv.type = ACTION_STACK_VALUE_FUNCTION;
		VAL(u64, &fv.data.numeric_value) = (u64)&g_rando_funcs[i];
		setProperty(app_context, g_rando_prototype, methods[i].name, methods[i].name_len, &fv);
	}
}

ASFunction* actionRandoGetConstructor(SWFAppContext* app_context) {
	initRandoPrototype(app_context);
	return &g_rando_constructor;
}

#else  // !WITH_AP

void initRandoPrototype(SWFAppContext* app_context) { (void)app_context; }
ASFunction* actionRandoGetConstructor(SWFAppContext* app_context) { (void)app_context; return NULL; }

#endif  // WITH_AP
