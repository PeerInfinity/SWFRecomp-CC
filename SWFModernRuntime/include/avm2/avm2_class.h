#ifndef AVM2_CLASS_H
#define AVM2_CLASS_H

// Per-class flattened vtable + class metadata, per Ruffle vtable.rs
// (avm2-support-plan §4.2): built at class-definition time by inheriting
// the superclass's table and appending own traits. Native builtins
// register through the same mechanism so the binding surface stays
// playerglobal-shaped (plan §4.5). Kept in its own small header (exposed
// architecture surface — see the plan's LittleCube note).

#include <avm2/avm2_abc.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_value.h>

typedef struct Avm2Context Avm2Context;

// A resolved property name: UTF-8 name + namespace. ns_kind is stored
// FOLDED (Namespace 0x08 → Package 0x16, i.e. "public") so comparisons
// are byte-wise; see avm2_ns_fold().
typedef struct Avm2PropKey
{
	const char* name;
	uint32_t name_len;
	uint8_t ns_kind;
	const char* ns_uri;
	uint32_t ns_len;
} Avm2PropKey;

typedef enum Avm2PropKind
{
	AVM2_PROP_SLOT = 0,   // Slot/Const/Class/Function traits: value in slots[slot_index]
	AVM2_PROP_METHOD = 1,
	AVM2_PROP_GETTER = 2, // Stage 3
	AVM2_PROP_SETTER = 3, // Stage 3
} Avm2PropKind;

typedef struct Avm2PropEntry
{
	Avm2PropKey key;
	uint8_t kind;  // Avm2PropKind
	uint32_t slot_index;
	Avm2MethodRef method;
	Avm2Class* defining_class;      // bound_class for method dispatch
	Avm2ScopeChain* method_scope;   // captured outer scope for the method
} Avm2PropEntry;

struct Avm2VTable
{
	uint32_t count;
	uint32_t cap;
	Avm2PropEntry* entries;
	uint32_t slot_count;  // slots consumed by SLOT-kind entries (1-based ids; index 0 unused)
};

struct Avm2Class
{
	Avm2PropKey name;
	Avm2Class* super_class;
	uint8_t flags;
	Avm2VTable ivtable;            // instance vtable (inherited + own)
	Avm2MethodRef instance_init;
	Avm2ScopeChain* scope;         // scope captured at NewClass (methods' outer chain)
	Avm2Object* class_object;
	// Builtins: bytes of native instance state to allocate into
	// Avm2Object.native_ext at construction (nearest ancestor wins), plus
	// an optional native constructor body.
	uint32_t native_ext_size;
	void (*native_init)(Avm2Context* ctx, Avm2Object* obj);
};

// Immutable captured scope chain (objects only; `with` scopes are Stage 3).
struct Avm2ScopeChain
{
	uint32_t count;
	Avm2Object** objs;  // bottom (0) → top (count-1)
};

// Namespace kind folding for comparisons (public kinds unify).
uint8_t avm2_ns_fold(uint8_t kind);
int avm2_propkey_matches(const Avm2PropKey* a, const Avm2PropKey* b);

// Multiname resolution against a file's pools. propkey_from_qname fails
// (returns 0) on lazy multinames; mn_match handles QName* and static
// Multiname (ns-set) kinds — lazy kinds never reach the Stage-2 ops (the
// verifier splits GetProperty into Static/Fast/Slow).
int avm2_propkey_from_qname(const Avm2AbcFileData* data, uint32_t mn_idx, Avm2PropKey* out);
int avm2_mn_match(const Avm2AbcFileData* data, uint32_t mn_idx, const Avm2PropKey* key);
void avm2_mn_name(const Avm2AbcFileData* data, uint32_t mn_idx,
                  const char** name, uint32_t* name_len);

// VTable build/lookup.
void avm2_vtable_append(Avm2Context* ctx, Avm2VTable* vt, const Avm2PropEntry* e);
const Avm2PropEntry* avm2_vtable_find(const Avm2VTable* vt, const Avm2PropKey* key);

// Add trait entries from static data onto a vtable (used for class
// instance/static traits and script globals). `file` provides pools and
// the method fns; `defining_class`/`scope` are stamped on method entries.
void avm2_vtable_add_traits(Avm2Context* ctx, Avm2VTable* vt, Avm2AbcFileRt* file,
                            const Avm2AbcTrait* traits, uint32_t trait_count,
                            Avm2Class* defining_class, Avm2ScopeChain* scope);

// Scope chains.
Avm2ScopeChain* avm2_scope_capture(Avm2Context* ctx, const Avm2ScopeChain* outer,
                                   Avm2Object* const* lscope, uint32_t scope_n);

// Class realization (NewClass) and construction (ConstructProp / root).
Avm2Class* avm2_class_define(Avm2Context* ctx, Avm2AbcFileRt* file, uint32_t class_idx,
                             Avm2Class* super_class, Avm2ScopeChain* scope);
Avm2Value avm2_class_construct(Avm2Context* ctx, Avm2Class* cls,
                               const Avm2Value* args, uint32_t argc);

// Invoke a method reference (emitted or native).
Avm2Value avm2_call_method_ref(Avm2Context* ctx, const Avm2MethodRef* m,
                               Avm2Class* bound_class, Avm2ScopeChain* outer,
                               Avm2Value this_val, const Avm2Value* args, uint32_t argc);

// Invoke a function object (AVM2_OBJ_FUNCTION closure).
Avm2Value avm2_call_function_obj(Avm2Context* ctx, Avm2Object* fnobj,
                                 const Avm2Value* args, uint32_t argc);

#endif // AVM2_CLASS_H
