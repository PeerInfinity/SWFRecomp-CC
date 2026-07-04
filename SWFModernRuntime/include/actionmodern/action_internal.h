#pragma once

// action_internal.h — helpers shared across subsystem source files
// ($PROJECT/src/actionmodern/*.c). Not a public API.
//
// Added as part of the action.c carve-out effort (see
// SWFRecompDocs/plans/split-action-c-math-first.md). Grows with each new
// subsystem that moves out of action.c.

#include <actionmodern/action.h>     // MovieClip, Function2Ptr, g_swf_version, VAL
#include <actionmodern/object.h>     // ASObject, ASProperty
#include <actionmodern/variables.h>  // ActionVar, ActionStackValueType

// Simple-function pointer (Function2Ptr is already in action.h)
typedef void (*SimpleFunctionPtr)(SWFAppContext* app_context);

// Function-call recursion depth. Incremented on entry to a user-defined
// function and decremented on exit. Used by EFFECTIVE_SWF_VERSION() below
// and by various SWF4/5-gated code paths.
extern u32 g_call_depth;

// Effective SWF version (accounts for function context).
// In Flash, DefineFunction (SWF5 opcode) causes code inside functions to
// behave as SWF5+ even in a SWF4 file. When inside a function call
// (g_call_depth > 0) and g_swf_version < 5, we promote to 5.
#define EFFECTIVE_SWF_VERSION() ((g_swf_version < 5 && g_call_depth > 0) ? 5 : g_swf_version)

// ------------------------------------------------------------------
// ASFunction — built-in and user-defined function object.
// Used by all subsystem files; definition lives here so every .c in
// src/actionmodern/ can reference it.
// ------------------------------------------------------------------
typedef struct ASFunction {
	char name[256];           // Function name (can be empty for anonymous)
	u8 function_type;         // 1 = simple (DefineFunction), 2 = advanced (DefineFunction2)
	u32 param_count;          // Number of parameters

	// For DefineFunction (type 1)
	SimpleFunctionPtr simple_func;

	// For DefineFunction2 (type 2)
	Function2Ptr advanced_func;
	u8 register_count;
	u16 flags;

	// Prototype object (for constructor usage)
	ASObject* prototype_obj;  // Created lazily on first access

	// Own properties on the function object itself (e.g., toString override)
	ASObject* own_props;  // Created lazily when SetMember is called

	// Captured scope chain (scope entries at time of definition)
	u8 captured_scope_count;
	ASObject* captured_scope[8];   // scope objects
	MovieClip* captured_scope_mc[8]; // associated MovieClip (if any)
	u8 captured_scope_is_with[8]; // 1 = with scope, 0 = local scope

	// Closure context: the MovieClip where this function was defined
	// SWF6+: GotoFrame/GetProperty("") operate on base_clip, not caller's context
	// SWF5: base_clip is not used (functions execute in caller's context)
	MovieClip* base_clip;

	// SWF version at function definition time (Phase 3: per-function version tracking)
	// When called, g_swf_version is switched to this value so version-dependent
	// behavior matches the SWF where the function was originally defined.
	u16 swf_version;

	// Per-movie global index: reserved for future per-movie _global isolation.
	// Currently unused (always 0). Built-in functions are zero-initialized.
	u16 movie_global_idx;

	// If set, this function does not get a lazily-created .prototype object.
	// Used for native/built-in functions that don't have prototypes in Flash.
	u8 no_lazy_prototype;
} ASFunction;

// ------------------------------------------------------------------
// Stack / coercion helpers (defined in action.c)
// ------------------------------------------------------------------
void pushVar(SWFAppContext* app_context, ActionVar* var);
void popVar(SWFAppContext* app_context, ActionVar* var);
ActionStackValueType convertFloat(SWFAppContext* app_context);
double varToDoubleSWF(SWFAppContext* app_context, ActionVar* v, int swf_version);

// Simple SWF5-style number coercion (no hex/octal, no valueOf call).
// Used by Date argument coercion alongside varToDoubleSWF.
double varToDoubleSimple(ActionVar* v);

// UTF-8 → malloc-allocated UTF-16 conversion. Returned pointer owns
// its buffer (freed via ActionVar refcount semantics or explicit free).
// Uses plain malloc (not the heap arena) so long-lived strings don't
// exhaust it.
uint16_t* utf8_to_u16(SWFAppContext* app_context, const char* utf8, u32 byte_len, u32* out_u16_len);

// UTF-16 → UTF-8 into caller-provided buffer. Returns bytes written
// (not including NUL). Pair of utf8_to_u16.
int u16_to_utf8(const uint16_t* u16, u32 u16_len, char* out, int out_size);

// Return the u16 character pointer for an ActionVar of STRING type
// (handles both heap-owned and ID-based storage). Returns NULL for
// non-strings or empty/zero-size strings.
const uint16_t* varGetU16Ptr(ActionVar* v);

// Push an UNDEFINED ActionVar onto the VM stack.
void pushUndefined(SWFAppContext* app_context);

// Convert the top-of-stack value to STRING in place. Used whenever a
// builtin needs to read a string from whatever the caller passed
// (including objects with toString).
ActionStackValueType convertString(SWFAppContext* app_context, char* var_str);

// Flush a deferred onChanged handler queued by replaceSel, if any.
// Timer tick hook — called from processTimers after each timer fires.
void actionFlushPendingOnChanged(SWFAppContext* app_context);

// Coerce first min(arg_count,max_args) args to f64 via pushVar/convertFloat/popVar
// (calls valueOf on objects). Used by Math builtins, ASnative, and Date.
void coerceMathArgs(SWFAppContext* app_context, ActionVar* args, u32 arg_count, u32 max_args);

// Extract f64 from a coerced ActionVar (F32 or F64). Returns NaN for others.
double mathArgToDouble(ActionVar* v);

// Build an ActionVar holding the given f64. Used by Math + Date.
ActionVar mathReturnDouble(double val);

// ------------------------------------------------------------------
// Native function setup helpers (defined in action.c)
// ------------------------------------------------------------------

// Set up own_props on a native function with __proto__ + constructor (no prototype).
void setupNativeFuncOwnProps(SWFAppContext* app_context, ASFunction* func);

// Install a builtin toString that returns "[object Object]" on a native ASObject.
void installNativeToString(SWFAppContext* app_context, ASObject* obj);

// Set __proto__ → Object.prototype on a user-created object (WRITABLE).
void setObjectProto(SWFAppContext* app_context, ASObject* obj);

// Make __proto__ READ_ONLY on an object (after setObjectProto established it).
// Used for singleton globals (Accessibility, Key, Math, Mouse, Selection, etc.)
void makeProtoReadOnly(ASObject* obj);

// Register a native ASFunction in the global function_registry so
// lookupFunctionByName() can find it. Bounds-checked; silently no-ops
// if the registry is full. Used by subsystem files (date.c, etc.)
// carved out of action.c.
void registerNativeFunction(ASFunction* fn);

// ------------------------------------------------------------------
// Call-dispatch state (exposed so subsystem files carved out of
// action.c can inline call-dispatch patterns without duplicating the
// storage or the push/pop bookkeeping).
// ------------------------------------------------------------------

// WITH scope chain + function local scope
#define MAX_SCOPE_DEPTH 32
extern ASObject* scope_chain[MAX_SCOPE_DEPTH];
extern u8 scope_is_with[MAX_SCOPE_DEPTH];
extern MovieClip* scope_mc[MAX_SCOPE_DEPTH];
extern u32 scope_depth;

// Per-call-frame `this` binding stack (GetVariable("this") checks this
// before the scope chain).
#define MAX_THIS_DEPTH 64
extern ActionVar g_this_stack[MAX_THIS_DEPTH];
extern u32 g_this_depth;

// MovieClip receiver context for clip-event handlers; consumed by
// DefineFunction2 preload_this so generated code sees MC type.
extern MovieClip* g_event_this_mc;

// MovieClip currently executing (targetClip/base_clip interaction).
extern MovieClip* g_current_context;

// Type tag of the thisArg passed through Function.prototype.call/apply
// (ACTION_STACK_VALUE_*). Lets builtin wrappers distinguish an ASArray
// receiver (this_obj is a raw ASArray*, NOT an ASObject*) from a real
// ASObject. Builtins that cast this_obj to ASObject* must check this
// first — see builtin_array_method / date_has_backing. 0 when not in a
// call/apply dispatch.
extern u8 g_call_this_type;

// Super context stack — (this, depth, mc) triple tracks prototype
// chain position for super() / super.method() resolution.
void pushSuperContextWithMC(void* this_obj, u8 depth, void* mc);
void popSuperContext(void);

// Per-function SWF-version switch (see ASFunction::swf_version). Swaps
// g_swf_version and the active version-group global (_global legacy vs
// modern) to the function's defining-movie values; restore reverses it.
// Wrappers around action.c's static-inline helpers.
void actionSwitchToFunctionVersion(ASFunction* func, int* saved_ver, ASObject** saved_global, int* saved_movie_idx);
void actionRestoreFunctionVersion(int saved_ver, ASObject* saved_global, int saved_movie_idx);

// Constructor context stack — marks whether the active call is a
// constructor invocation (changes return-value semantics).
void pushCtorContext(u8 is_constructor);
void popCtorContext(void);
