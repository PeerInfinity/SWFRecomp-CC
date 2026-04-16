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
