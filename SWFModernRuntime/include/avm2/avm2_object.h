#ifndef AVM2_OBJECT_H
#define AVM2_OBJECT_H

// ScriptObject per Ruffle script_object.rs:61-79 (avm2-support-plan §4.2):
// fixed slot array for declared traits + dynamic property map for expando
// props + proto link + class/vtable pointers. Kept in its own small header
// (exposed architecture surface — see the plan's LittleCube note).
//
// NOT an ASObject/ASFunction — the AVM2 runtime never touches AVM1's
// ActionVar object model.

#include <avm2/avm2_abc.h>
#include <avm2/avm2_value.h>

typedef struct Avm2VTable Avm2VTable;
typedef struct Avm2Context Avm2Context;

typedef enum Avm2ObjectKind
{
	AVM2_OBJ_SCRIPT = 0,   // plain ScriptObject / class instance / script globals
	AVM2_OBJ_CLASS = 1,    // class object (holds class_ref + static traits)
	AVM2_OBJ_FUNCTION = 2, // function / bound-method closure
} Avm2ObjectKind;

typedef struct Avm2DynProp
{
	struct Avm2DynProp* next;
	Avm2String name;
	Avm2Value value;
} Avm2DynProp;

// Method reference: emitted method fn (with its defining file) or native.
typedef struct Avm2MethodRef
{
	Avm2MethodFn fn;
	Avm2AbcFileRt* file;  // NULL for native builtins
	const char* debug_name;
} Avm2MethodRef;

struct Avm2Object
{
	uint8_t kind;             // Avm2ObjectKind
	Avm2Class* cls;           // class this object is an instance of
	Avm2Object* proto;        // prototype link (Stage 3: proto-chain reads)
	const Avm2VTable* vtable; // instance vtable (usually &cls->ivtable) or own
	Avm2Value* slots;
	uint32_t slot_count;
	Avm2DynProp* dyn_props;
	void* native_ext;         // builtin instance data (e.g. MovieClip frame scripts)

	// AVM2_OBJ_FUNCTION payload: a bound method closure.
	Avm2MethodRef fn_method;
	Avm2Value fn_receiver;
	Avm2ScopeChain* fn_scope;
	Avm2Class* fn_bound_class;

	// AVM2_OBJ_CLASS payload.
	Avm2Class* class_ref;
};

// Allocation (from the shared o1heap; see avm2GcMarkRoots in avm2_main.c
// for the Stage-2 immortality note).
Avm2Object* avm2_object_alloc(Avm2Context* ctx, uint8_t kind, uint32_t slot_count);

// Dynamic (expando) properties.
Avm2Value* avm2_object_find_dynamic(Avm2Object* obj, const char* name, uint32_t name_len);
void avm2_object_set_dynamic(Avm2Context* ctx, Avm2Object* obj, const char* name,
                             uint32_t name_len, Avm2Value value);

#endif // AVM2_OBJECT_H
