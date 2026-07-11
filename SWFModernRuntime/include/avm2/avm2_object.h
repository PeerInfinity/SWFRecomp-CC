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
	AVM2_OBJ_ARRAY = 3,    // Array instance (native_ext = Avm2ArrayExt)
} Avm2ObjectKind;

typedef struct Avm2DynProp
{
	struct Avm2DynProp* next;
	Avm2String name;
	Avm2Value value;
	uint8_t dont_enum;
} Avm2DynProp;

// Bound-method closure cache: obj.method === obj.method must hold (Ruffle
// caches bound methods per (receiver, trait)).
typedef struct Avm2BoundMethod
{
	struct Avm2BoundMethod* next;
	const void* entry;  // the Avm2PropEntry this closure was bound from
	Avm2Object* fn;
} Avm2BoundMethod;

// Method reference: emitted method fn (with its defining file) or native.
typedef struct Avm2MethodRef
{
	Avm2MethodFn fn;
	Avm2AbcFileRt* file;  // NULL for native builtins
	const char* debug_name;
	uint32_t method_index;  // index into file->data->methods (emitted only)
} Avm2MethodRef;

struct Avm2Object
{
	uint8_t kind;             // Avm2ObjectKind
	Avm2Class* cls;           // class this object is an instance of
	Avm2Object* proto;        // prototype link (ES3 chain, dynamic reads)
	const Avm2VTable* vtable; // instance vtable (usually &cls->ivtable) or own
	Avm2Value* slots;
	uint32_t slot_count;
	Avm2DynProp* dyn_props;   // insertion order (append at tail)
	Avm2DynProp* dyn_tail;
	Avm2BoundMethod* bound_methods;
	void* native_ext;         // builtin instance data (arrays, MovieClip, ...)

	// AVM2_OBJ_FUNCTION payload: a bound method closure.
	Avm2MethodRef fn_method;
	Avm2Value fn_receiver;
	uint8_t fn_has_receiver;  // bound method: receiver overrides call-site this
	Avm2ScopeChain* fn_scope;
	Avm2Class* fn_bound_class;
	Avm2Object* fn_prototype; // lazily created `prototype` object
	uint8_t fn_proto_nulled;  // prototype was explicitly set to null

	// AVM2_OBJ_CLASS payload.
	Avm2Class* class_ref;
};

// Array storage (Ruffle array.rs ArrayStorage): a dense region with holes
// plus a sorted sparse overflow list for far indices (a[4294967294] must
// not allocate 4G slots — array_index_max).
typedef struct Avm2SparseElem
{
	struct Avm2SparseElem* next;  // ascending by idx
	uint32_t idx;
	Avm2Value v;
} Avm2SparseElem;

typedef struct Avm2ArrayExt
{
	uint32_t length;     // logical Array.length (max index + 1)
	uint32_t dense_len;  // valid entries in elems
	uint32_t cap;
	Avm2Value* elems;    // AVM2_VALUE_HOLE marks holes
	Avm2SparseElem* sparse;
} Avm2ArrayExt;

// Allocation (from the shared o1heap; see avm2GcMarkRoots in avm2_main.c
// for the immortality note).
Avm2Object* avm2_object_alloc(Avm2Context* ctx, uint8_t kind, uint32_t slot_count);

// Dynamic (expando) properties.
Avm2Value* avm2_object_find_dynamic(Avm2Object* obj, const char* name, uint32_t name_len);
Avm2DynProp* avm2_object_set_dynamic(Avm2Context* ctx, Avm2Object* obj, const char* name,
                                     uint32_t name_len, Avm2Value value);
// Returns 1 if the property existed and was removed.
int avm2_object_delete_dynamic(Avm2Object* obj, const char* name, uint32_t name_len);

// Enumeration (Ruffle get_next_enumerant / get_enumerant_name protocol):
// enumerants are numbered from 1; 0 means exhausted. Arrays enumerate
// dense non-hole indices first, then dynamic props (skipping dont_enum).
uint32_t avm2_object_next_enumerant(Avm2Object* obj, uint32_t cur);
Avm2Value avm2_object_enumerant_name(Avm2Context* ctx, Avm2Object* obj, uint32_t idx);
Avm2Value avm2_object_enumerant_value(Avm2Context* ctx, Avm2Object* obj, uint32_t idx);

// Arrays.
Avm2Object* avm2_array_new(Avm2Context* ctx, uint32_t length);  // length holes
Avm2Object* avm2_array_from_values(Avm2Context* ctx, const Avm2Value* vals, uint32_t n);
Avm2ArrayExt* avm2_array_ext(Avm2Object* obj);  // NULL if not an array
// Element get: returns HOLE-kind value if out of range / a hole.
Avm2Value avm2_array_get(Avm2Object* arr, uint32_t idx);
void avm2_array_set(Avm2Context* ctx, Avm2Object* arr, uint32_t idx, Avm2Value v);
void avm2_array_set_length(Avm2Context* ctx, Avm2Object* arr, uint32_t new_len);
int avm2_array_delete(Avm2Object* arr, uint32_t idx);  // 1 if it became a hole
void avm2_array_push(Avm2Context* ctx, Avm2Object* arr, Avm2Value v);

#endif // AVM2_OBJECT_H
