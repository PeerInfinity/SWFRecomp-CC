// registered_class.c — Object.registerClass registry + invocation.
//
// Carved out of action.c per
// SWFRecompDocs/plans/split-action-c-math-first.md (third subsystem,
// after Math and Date). Holds the dual case-sensitive / case-insensitive
// registry Ruffle uses, the `lookupRegisteredClassByCharId` iterator,
// and the `actionSetupRegisteredClassPrototype` /
// `actionInvokeRegisteredClassConstructor` invocation pair called by
// action.c's attachMovie paths and libswf/tag.c's sprite-init path.
//
// The invoke function is essentially a specialized actionCallFunction
// variant (pushes super/ctor context, switches current_context, dispatches
// the ctor with MC as 'this'); it pulls dispatch state from
// action_internal.h rather than reimplementing it.

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <actionmodern/action_internal.h>
#include <actionmodern/actionregclass.h>
#include <tag.h>    // ng_lookupExportVersion

// ng_forEachExportName lives in libswf/ng_shared.c but isn't declared
// in a header — match action.c's inline extern.
extern int ng_forEachExportName(size_t char_id, int (*callback)(const char* name, void* user_data), void* user_data);

// ==================================================================
// Object.registerClass Registry
// ==================================================================
// Ruffle uses TWO constructor registries: case-sensitive (SWF7+) and
// case-insensitive (SWF<=6). Registration uses the calling code's SWF
// version; lookup uses the new MC's movie SWF version. The two registries
// are completely separate.
#define MAX_REGISTERED_CLASSES 128

typedef struct {
	char symbol_name[128];
	void* constructor; // ASFunction* or NULL (unregistered)
} RegisteredClassEntry;

// Case-sensitive registry (SWF7+)
static RegisteredClassEntry g_registered_classes_cs[MAX_REGISTERED_CLASSES];
static size_t g_registered_class_count_cs = 0;

// Case-insensitive registry (SWF<=6) — keys stored as lowercase
static RegisteredClassEntry g_registered_classes_ci[MAX_REGISTERED_CLASSES];
static size_t g_registered_class_count_ci = 0;

static void _toLowerBuf(char* dst, const char* src, size_t max_len)
{
	size_t i;
	for (i = 0; i < max_len - 1 && src[i]; i++)
		dst[i] = (src[i] >= 'A' && src[i] <= 'Z') ? (src[i] + 32) : src[i];
	dst[i] = '\0';
}

// Forward declaration for version-aware internal register.
static void registerClassForSymbolVersion(const char* symbol_name, void* constructor, int swf_version);

// Look up a registered class constructor by symbol name.
// swf_version determines which registry (case-sensitive vs insensitive).
// Returns NULL if not found or if unregistered (constructor == NULL).
void* lookupRegisteredClass(const char* symbol_name)
{
	// Default: use g_swf_version for backward compat with old call sites
	return lookupRegisteredClassVersion(symbol_name, g_swf_version);
}

void* lookupRegisteredClassVersion(const char* symbol_name, int swf_version)
{
	if (swf_version >= 7)
	{
		// Case-sensitive lookup
		void* result = NULL;
		for (size_t i = 0; i < g_registered_class_count_cs; i++)
		{
			if (strcmp(g_registered_classes_cs[i].symbol_name, symbol_name) == 0)
				result = g_registered_classes_cs[i].constructor;
		}
		return result;
	}
	else
	{
		// Case-insensitive lookup — lowercase the query
		char lower[128];
		_toLowerBuf(lower, symbol_name, sizeof(lower));
		void* result = NULL;
		for (size_t i = 0; i < g_registered_class_count_ci; i++)
		{
			if (strcmp(g_registered_classes_ci[i].symbol_name, lower) == 0)
				result = g_registered_classes_ci[i].constructor;
		}
		return result;
	}
}

// Callback context for lookupRegisteredClassByCharId
typedef struct {
	int swf_version;
	void* found_ctor;
	const char* found_name;
} _CharIdClassLookupCtx;

static int _charIdClassLookupCb(const char* name, void* user_data)
{
	_CharIdClassLookupCtx* ctx = (_CharIdClassLookupCtx*)user_data;
	void* ctor = lookupRegisteredClassVersion(name, ctx->swf_version);
	if (ctor != NULL) {
		ctx->found_ctor = ctor;
		ctx->found_name = name;
		return 1; // stop iteration
	}
	return 0; // continue
}

// Look up a registered class by char_id: iterate all export names for the given
// char_id and return the first one that has a registered class constructor.
// This handles cases where a sprite has multiple export names (e.g., "CCC" and "DDD")
// and registerClass was called with one name but attachMovie uses the other.
// If out_export_name is non-NULL, the matching export name is written there.
void* lookupRegisteredClassByCharId(size_t char_id, int swf_version, const char** out_export_name)
{
	_CharIdClassLookupCtx ctx = { swf_version, NULL, NULL };
	ng_forEachExportName(char_id, _charIdClassLookupCb, &ctx);
	if (ctx.found_ctor != NULL && out_export_name)
		*out_export_name = ctx.found_name;
	return ctx.found_ctor;
}

// Register or unregister a class for a symbol name.
// swf_version determines which registry. constructor=NULL means unregister.
void actionRegisterClassForSymbol(const char* symbol_name, void* constructor)
{
	// Use g_swf_version (current execution context)
	registerClassForSymbolVersion(symbol_name, constructor, g_swf_version);
}

static void registerClassForSymbolVersion(const char* symbol_name, void* constructor, int swf_version)
{
	if (swf_version >= 7)
	{
		// Case-sensitive registry
		for (size_t i = 0; i < g_registered_class_count_cs; i++)
		{
			if (strcmp(g_registered_classes_cs[i].symbol_name, symbol_name) == 0)
			{
				g_registered_classes_cs[i].constructor = constructor;
				return;
			}
		}
		if (g_registered_class_count_cs < MAX_REGISTERED_CLASSES)
		{
			strncpy(g_registered_classes_cs[g_registered_class_count_cs].symbol_name, symbol_name, 127);
			g_registered_classes_cs[g_registered_class_count_cs].symbol_name[127] = '\0';
			g_registered_classes_cs[g_registered_class_count_cs].constructor = constructor;
			g_registered_class_count_cs++;
		}
	}
	else
	{
		// Case-insensitive registry — store key as lowercase
		char lower[128];
		_toLowerBuf(lower, symbol_name, sizeof(lower));
		for (size_t i = 0; i < g_registered_class_count_ci; i++)
		{
			if (strcmp(g_registered_classes_ci[i].symbol_name, lower) == 0)
			{
				g_registered_classes_ci[i].constructor = constructor;
				return;
			}
		}
		if (g_registered_class_count_ci < MAX_REGISTERED_CLASSES)
		{
			strncpy(g_registered_classes_ci[g_registered_class_count_ci].symbol_name, lower, 127);
			g_registered_classes_ci[g_registered_class_count_ci].symbol_name[127] = '\0';
			g_registered_classes_ci[g_registered_class_count_ci].constructor = constructor;
			g_registered_class_count_ci++;
		}
	}
}

// ==================================================================
// Constructor application
// ==================================================================

// Invoke the registered class constructor on a timeline-placed movieclip.
// Called from tag.c during sprite init when the sprite's export name has a registered class.
// Sets __proto__ to ctor.prototype, then calls the constructor with mc as 'this'.
// Set __proto__ and __constructor__ for a registered class, WITHOUT calling the constructor.
// This should be called before on(construct) clip events fire so prototype properties are accessible.
void actionSetupRegisteredClassPrototype(SWFAppContext* app_context, const char* export_name, MovieClip* mc)
{
	if (export_name == NULL || mc == NULL) return;
	// Use the export's defining SWF version for registerClass registry lookup
	int exp_ver = ng_lookupExportVersion(export_name);
	int mc_ver = exp_ver ? exp_ver : ((mc->swf_version) ? mc->swf_version : g_swf_version);
	void* raw_ctor = lookupRegisteredClassVersion(export_name, mc_ver);
	if (raw_ctor == NULL) return;

	ASFunction* ctor_func = (ASFunction*)raw_ctor;

	if (mc->dynamic_props == NULL)
	{
		mc->dynamic_props = allocObject(app_context, 8);
		retainObject((ASObject*)mc->dynamic_props);
	}
	ASObject* obj = (ASObject*)mc->dynamic_props;

	if (ctor_func->prototype_obj == NULL)
	{
		ctor_func->prototype_obj = allocObject(app_context, 4);
		retainObject(ctor_func->prototype_obj);
		setObjectProto(app_context, ctor_func->prototype_obj);
		ActionVar ctor_var;
		ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
		ctor_var.str_size = 0;
		ctor_var.data.numeric_value = (u64) ctor_func;
		setProperty(app_context, ctor_func->prototype_obj, "constructor", 11, &ctor_var);
	}
	{
		ActionVar proto_var;
		proto_var.type = ACTION_STACK_VALUE_OBJECT;
		proto_var.str_size = 0;
		proto_var.data.numeric_value = (u64) ctor_func->prototype_obj;
		setProperty(app_context, obj, "__proto__", 9, &proto_var);
	}
	{
		ActionVar ctor_inst_var;
		ctor_inst_var.type = ACTION_STACK_VALUE_FUNCTION;
		ctor_inst_var.str_size = 0;
		ctor_inst_var.data.numeric_value = (u64) ctor_func;
		setPropertyWithFlags(app_context, obj, "__constructor__", 15, &ctor_inst_var, PROPERTY_FLAGS_DONTENUM);
	}
}

void actionInvokeRegisteredClassConstructor(SWFAppContext* app_context, const char* export_name, MovieClip* mc)
{
	if (export_name == NULL || mc == NULL) return;
	// Use the export's defining SWF version for registerClass registry lookup
	int exp_ver = ng_lookupExportVersion(export_name);
	int mc_ver = exp_ver ? exp_ver : ((mc->swf_version) ? mc->swf_version : g_swf_version);
	void* raw_ctor = lookupRegisteredClassVersion(export_name, mc_ver);
	if (raw_ctor == NULL) return;

	ASFunction* ctor_func = (ASFunction*)raw_ctor;

	// Ensure __proto__/__constructor__ are set (may already be done by actionSetupRegisteredClassPrototype)
	actionSetupRegisteredClassPrototype(app_context, export_name, mc);

	ASObject* obj = (ASObject*)mc->dynamic_props;

	// Push super context for constructor call.
	// Use pushSuperContextWithMC so super() in the constructor can pass
	// the MovieClip (not just dynamic_props) to the parent constructor.
	pushSuperContextWithMC((void*)obj, 1, (void*)mc);

	// Switch to MC's context for the constructor call
	MovieClip* saved_ctx = g_current_context;
	actionSetCurrentContext(mc);

	// Call constructor with mc as 'this' (MOVIECLIP type, not OBJECT)
	if (ctor_func->function_type == 1 && ctor_func->simple_func != NULL)
	{
		// Type 1: simple function — push local scope + captured scopes (matching actionCallFunction)
		ASObject* local_scope = allocObject(app_context, 8);
		if (scope_depth < MAX_SCOPE_DEPTH)
		{
			scope_is_with[scope_depth] = 0;
			scope_mc[scope_depth] = NULL;
			scope_chain[scope_depth++] = local_scope;
		}
		u32 captured_count = ctor_func->captured_scope_count;
		for (u32 i = 0; i < captured_count && scope_depth < MAX_SCOPE_DEPTH; i++)
		{
			scope_is_with[scope_depth] = 1;
			scope_mc[scope_depth] = (MovieClip*)ctor_func->captured_scope_mc[i];
			scope_chain[scope_depth++] = (ASObject*)ctor_func->captured_scope[i];
		}
		// SWF6+ closure: switch to function's base_clip context
		MovieClip* saved_base = NULL;
		if (g_swf_version >= 6 && ctor_func->base_clip != NULL) {
			saved_base = g_current_context;
			actionSetCurrentContext(ctor_func->base_clip);
		}
		// Push 'this' as MOVIECLIP onto g_this_stack (GetVariable("this") checks this first)
		u32 saved_this_depth = g_this_depth;
		if (g_this_depth < MAX_THIS_DEPTH) {
			g_this_stack[g_this_depth].type = ACTION_STACK_VALUE_MOVIECLIP;
			g_this_stack[g_this_depth].str_size = 0;
			g_this_stack[g_this_depth].data.numeric_value = (u64) mc;
			g_this_depth++;
		}
		ActionVar this_var;
		this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
		this_var.str_size = 0;
		this_var.data.numeric_value = (u64) mc;
		setVariableByName("this", &this_var);
		g_call_depth++;
		pushCtorContext(1);
		((ActionVar(*)(SWFAppContext*))ctor_func->simple_func)(app_context);
		popCtorContext();
		g_call_depth--;
		g_this_depth = saved_this_depth;
		if (saved_base != NULL)
			actionSetCurrentContext(saved_base);
		for (u32 i = 0; i < captured_count && scope_depth > 0; i++)
			scope_depth--;
		if (scope_depth > 0) scope_depth--;
		releaseObject(app_context, local_scope);
	}
	else if (ctor_func->function_type == 2 && ctor_func->advanced_func != NULL)
	{
		// Type 2: advanced function with registers
		ActionVar registers[256] = {0};

		ASObject* ctor_scope = allocObject(app_context, 4);
		u32 saved_this_depth = g_this_depth;
		{
			u16 f2flags = ctor_func->flags;
			int preload_this  = (f2flags & 0x0001);
			int suppress_this = (f2flags & 0x0002);
			if (!preload_this && !suppress_this) {
				if (g_this_depth < MAX_THIS_DEPTH) {
					g_this_stack[g_this_depth].type = ACTION_STACK_VALUE_MOVIECLIP;
					g_this_stack[g_this_depth].data.numeric_value = (u64)mc;
					g_this_depth++;
				}
				ActionVar ctor_this_var = {0};
				ctor_this_var.type = ACTION_STACK_VALUE_MOVIECLIP;
				ctor_this_var.data.numeric_value = (u64)mc;
				setProperty(app_context, ctor_scope, "this", 4, &ctor_this_var);
			}
		}

		// Restore captured scope chain entries (closure support)
		u8 captured = ctor_func->captured_scope_count;
		for (u8 ci = 0; ci < captured; ci++) {
			if (scope_depth < MAX_SCOPE_DEPTH) {
				scope_is_with[scope_depth] = ctor_func->captured_scope_is_with[ci];
				scope_mc[scope_depth] = ctor_func->captured_scope_mc[ci];
				scope_chain[scope_depth++] = ctor_func->captured_scope[ci];
			}
		}
		if (scope_depth < MAX_SCOPE_DEPTH) {
			scope_is_with[scope_depth] = 0;
			scope_mc[scope_depth] = NULL;
			scope_chain[scope_depth++] = ctor_scope;
		}

		// SWF6+ closure: switch to function's base_clip context
		MovieClip* saved_base = NULL;
		if (g_swf_version >= 6 && ctor_func->base_clip != NULL) {
			saved_base = g_current_context;
			actionSetCurrentContext(ctor_func->base_clip);
		}

		g_call_depth++;
		pushCtorContext(1);
		// Use g_event_this_mc so generated preload_this code picks up MC type correctly
		// (passing mc as this_obj would make it ACTION_STACK_VALUE_OBJECT in generated code)
		MovieClip* saved_event_this = g_event_this_mc;
		g_event_this_mc = mc;
		ctor_func->advanced_func(app_context, NULL, 0, registers, NULL);
		g_event_this_mc = saved_event_this;
		popCtorContext();
		g_call_depth--;

		if (saved_base != NULL)
			actionSetCurrentContext(saved_base);

		// Pop local scope + captured scopes
		for (u8 ci = 0; ci < captured + 1; ci++) {
			if (scope_depth > 0) scope_depth--;
		}
		releaseObject(app_context, ctor_scope);
		g_this_depth = saved_this_depth;
	}

	popSuperContext();
	actionSetCurrentContext(saved_ctx);
}
