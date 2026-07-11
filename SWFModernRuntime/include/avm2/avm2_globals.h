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
int avm2_has_own_public_property(Avm2Context* ctx, Avm2Value recv,
                                 const char* name, uint32_t name_len);

// Builtin class registration helpers (also used by avm2_string.c etc.).
Avm2Class* avm2_builtin_class(Avm2Context* ctx, const char* ns, const char* name,
                              Avm2Class* super);
void avm2_builtin_add_method(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn fn);
void avm2_builtin_add_getter(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn fn);
void avm2_builtin_add_static_method(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                    Avm2MethodFn fn);
void avm2_builtin_add_static_const(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                   Avm2Value value);
// Install a native function on a prototype object (dont_enum).
void avm2_proto_add_function(Avm2Context* ctx, Avm2Object* proto, const char* name,
                             Avm2MethodFn fn);
// Register a toplevel native function on the builtin globals + domain.
void avm2_builtin_add_global_fn(Avm2Context* ctx, const char* name, Avm2MethodFn fn);

// Per-module builtin registration (called from avm2_globals_init).
void avm2_register_string(Avm2Context* ctx);
void avm2_register_number(Avm2Context* ctx);   // Number/int/uint/Boolean/Math
void avm2_register_array(Avm2Context* ctx);
void avm2_register_error(Avm2Context* ctx);
void avm2_register_toplevel(Avm2Context* ctx); // trace/isNaN/parseInt/...

// MovieClip stub instance state (Avm2Object.native_ext).
typedef struct Avm2MovieClipExt
{
	uint32_t frame_script_cap;
	Avm2Value* frame_scripts;  // indexed by 0-based frame; unset = undefined kind
} Avm2MovieClipExt;

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
} Avm2Builtins;

#endif // AVM2_GLOBALS_H
