#ifndef AVM2_ABC_H
#define AVM2_ABC_H

// Static ABC data contract between the recompiler's C emitter
// (SWFRecomp/src/abc/abc_emit.cpp → RecompiledABC/) and the AVM2 runtime.
//
// The emitter lowers the verified IR's pool/table indices
// (SWFRecomp/include/abc/abc_ir.hpp) into these const tables; every index
// here is a direct index into the owning Avm2AbcFileData's arrays,
// INCLUDING the synthetic entry 0 ("any"/no value) that the parser gives
// every constant pool. Runtime-mutable state (script globals, init flags,
// realized classes) lives in the parallel Avm2AbcFileRt.

#include <stddef.h>
#include <stdint.h>

#include <avm2/avm2_value.h>

typedef struct Avm2AbcFileRt Avm2AbcFileRt;
typedef struct Avm2Class Avm2Class;
typedef struct Avm2ScopeChain Avm2ScopeChain;

// Namespace kinds: raw ABC values (abc_types.hpp NamespaceKind).
// Package (0x16) and Namespace (0x08) fold together as "public" during
// name matching, mirroring Ruffle namespace.rs is_public.
typedef struct Avm2AbcNamespace
{
	uint8_t kind;
	uint32_t name;  // string index
} Avm2AbcNamespace;

typedef struct Avm2AbcNsSet
{
	uint32_t count;
	const uint32_t* ns_indices;  // namespace indices
} Avm2AbcNsSet;

// Multiname kinds: raw ABC values (abc_types.hpp MultinameKind).
typedef struct Avm2AbcMultiname
{
	uint8_t kind;
	uint32_t ns;      // namespace index (QName/QNameA)
	uint32_t name;    // string index
	uint32_t ns_set;  // ns-set index (Multiname*/MultinameL*)
} Avm2AbcMultiname;

// Trait kinds: raw ABC values (abc_types.hpp TraitKindType):
// 0 Slot, 1 Method, 2 Getter, 3 Setter, 4 Class, 5 Function, 6 Const.
typedef struct Avm2AbcTrait
{
	uint8_t kind;
	uint32_t name_mn;         // multiname index (QName)
	uint32_t slot_or_disp_id; // 0 = auto-assign
	uint32_t type_mn;         // multiname index (Slot/Const)
	uint32_t method_or_class; // method index (Method/Getter/Setter/Function) or class index (Class)
} Avm2AbcTrait;

struct Avm2Activation;
typedef Avm2Value (*Avm2MethodFn)(struct Avm2Activation* act);

// Exception table entry, offsets resolved to op indices (data only in
// Stage 2 — runtime dispatch is a Stage 3 TODO; see abc_ir.hpp).
typedef struct Avm2AbcException
{
	uint32_t from_op;
	uint32_t to_op;
	uint32_t target_op;
	uint32_t type_mn;
	uint32_t variable_mn;
	uint8_t active;
} Avm2AbcException;

typedef struct Avm2AbcMethodData
{
	Avm2MethodFn fn;         // NULL = no body (native / interface method)
	const char* debug_name;  // pool name, for diagnostics
	uint32_t param_count;
	uint32_t exception_count;
	const Avm2AbcException* exceptions;
} Avm2AbcMethodData;

enum
{
	AVM2_CLASS_FLAG_SEALED = 1 << 0,
	AVM2_CLASS_FLAG_FINAL = 1 << 1,
	AVM2_CLASS_FLAG_INTERFACE = 1 << 2,
};

typedef struct Avm2AbcClassData
{
	uint32_t name_mn;       // multiname index (QName)
	uint32_t super_mn;      // multiname index (0 = none: Object/interface)
	uint8_t flags;
	uint32_t instance_init; // method index
	uint32_t class_init;    // method index (static initializer)
	uint32_t instance_trait_count;
	const Avm2AbcTrait* instance_traits;
	uint32_t class_trait_count;
	const Avm2AbcTrait* class_traits;
} Avm2AbcClassData;

typedef struct Avm2AbcScriptData
{
	uint32_t init_method;  // method index
	uint32_t trait_count;
	const Avm2AbcTrait* traits;
} Avm2AbcScriptData;

typedef struct Avm2AbcFileData
{
	uint32_t string_count;
	const Avm2String* strings;
	uint32_t namespace_count;
	const Avm2AbcNamespace* namespaces;
	uint32_t ns_set_count;
	const Avm2AbcNsSet* ns_sets;
	uint32_t multiname_count;
	const Avm2AbcMultiname* multinames;
	uint32_t method_count;
	const Avm2AbcMethodData* methods;
	uint32_t class_count;
	const Avm2AbcClassData* classes;
	uint32_t script_count;
	const Avm2AbcScriptData* scripts;
} Avm2AbcFileData;

// SymbolClass (tag 76): char_id 0 = the root/main timeline class.
typedef struct Avm2SymbolClassBinding
{
	uint16_t char_id;
	const char* class_name;  // dotted ("test_fla.MainTimeline")
} Avm2SymbolClassBinding;

// Provided by the generated RecompiledABC/abc_registry.c:
extern const Avm2AbcFileData* const avm2_generated_abc_files[];
extern const uint32_t avm2_generated_abc_file_count;
extern const Avm2SymbolClassBinding avm2_generated_symbol_classes[];
extern const uint32_t avm2_generated_symbol_class_count;

// ---------------------------------------------------------------------------
// Runtime-mutable per-file state
// ---------------------------------------------------------------------------

enum
{
	AVM2_SCRIPT_UNINITIALIZED = 0,
	AVM2_SCRIPT_INITIALIZING = 1,
	AVM2_SCRIPT_INITIALIZED = 2,
};

struct Avm2AbcFileRt
{
	const Avm2AbcFileData* data;
	Avm2Context* ctx;
	Avm2Object** script_globals;  // one per script
	uint8_t* script_init_state;
	Avm2Class** classes;          // realized by NewClass; NULL until then
};

// Activation record passed to every emitted method body and native method.
typedef struct Avm2Activation
{
	Avm2Context* ctx;
	Avm2AbcFileRt* file;       // defining ABC file (NULL for pure natives)
	Avm2Class* bound_class;    // defining class (ConstructSuper); NULL for scripts
	Avm2ScopeChain* outer;     // captured outer scope chain (NULL = empty)
	Avm2Value this_val;
	const Avm2Value* args;
	uint32_t argc;
} Avm2Activation;

#endif // AVM2_ABC_H
