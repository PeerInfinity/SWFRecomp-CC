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
void avm2_set_public_property(Avm2Context* ctx, Avm2Value recv,
                              const char* name, uint32_t name_len, Avm2Value value);
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
// Static accessor pair on the class object (setter may be NULL).
void avm2_builtin_add_static_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                    Avm2MethodFn getter, Avm2MethodFn setter);
// Install a native function on a prototype object (dont_enum).
void avm2_proto_add_function(Avm2Context* ctx, Avm2Object* proto, const char* name,
                             Avm2MethodFn fn);
// Register a toplevel native function on the builtin globals + domain.
void avm2_builtin_add_global_fn(Avm2Context* ctx, const char* name, Avm2MethodFn fn);
// Expose a value on the builtin globals + domain under an arbitrary key.
void avm2_builtin_define_alias(Avm2Context* ctx, Avm2PropKey key, Avm2Value value);

// Per-module builtin registration (called from avm2_globals_init).
void avm2_register_string(Avm2Context* ctx);
void avm2_register_number(Avm2Context* ctx);   // Number/int/uint/Boolean/Math
void avm2_register_array(Avm2Context* ctx);
void avm2_register_error(Avm2Context* ctx);
void avm2_register_toplevel(Avm2Context* ctx); // trace/isNaN/parseInt/...
void avm2_register_vector(Avm2Context* ctx);   // __AS3__.vec::Vector + specializations
void avm2_register_regexp(Avm2Context* ctx);   // RegExp + String regex paths
void avm2_register_json(Avm2Context* ctx);     // SWF13+ (caller gates)
void avm2_register_nsqname(Avm2Context* ctx);  // Namespace + QName
void avm2_register_dictionary(Avm2Context* ctx);  // flash.utils.Dictionary
// Is `obj` an instance of (a subclass of) flash.utils.Dictionary?
int avm2_is_dictionary(Avm2Object* obj);
void avm2_register_bytearray(Avm2Context* ctx);  // flash.utils.ByteArray (+Endian)
void avm2_register_amf(Avm2Context* ctx);  // flash.net alias fns + Date upgrade

// Minimal Date instance state (avm2_amf.c upgrades the stub).
typedef struct Avm2DateExt
{
	double millis;
} Avm2DateExt;
Avm2DateExt* avm2_date_ext_of(Avm2Value v);

// ByteArray instance state (avm2_bytearray.c).
typedef struct Avm2ByteArrayExt
{
	uint8_t* bytes;
	uint32_t len;
	uint32_t cap;
	uint32_t position;
	uint8_t endian_little;    // 0 = bigEndian (default)
	uint8_t object_encoding;  // 0 = AMF0, 3 = AMF3
} Avm2ByteArrayExt;

// NULL when the value is not a ByteArray (subclasses included).
Avm2ByteArrayExt* avm2_bytearray_ext_of(Avm2Value v);
// Grow/shrink storage (clamps position; used by the [] index write path).
void avm2_bytearray_set_length_public(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                                      uint32_t new_len);

void avm2_register_proxy(Avm2Context* ctx);  // flash.utils.Proxy
// Is `obj` an instance of (a subclass of) flash.utils.Proxy?
int avm2_is_proxy(Avm2Object* obj);
// Invoke a flash_proxy-namespace hook (getProperty/setProperty/...) on a
// Proxy instance, honoring subclass overrides.
Avm2Value avm2_proxy_call_hook(Avm2Context* ctx, Avm2Object* obj, const char* mname,
                               const Avm2Value* args, uint32_t argc);
// Enumeration hooks (avm2_object.c protocol); return 0 if not a Proxy.
int avm2_proxy_next_enumerant(Avm2Object* obj, uint32_t cur, uint32_t* out);
int avm2_proxy_enumerant_name(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                              Avm2Value* out);
int avm2_proxy_enumerant_value(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                               Avm2Value* out);

// Namespace/QName instance state (avm2_nsqname.c). prefix == NULL is the
// undefined prefix; a QName uri == NULL is the any namespace and local ==
// NULL the any name. kind is the raw ABC namespace kind (0 = any).
typedef struct Avm2NamespaceExt
{
	const Avm2String* uri;
	const Avm2String* prefix;
	uint8_t kind;
} Avm2NamespaceExt;

typedef struct Avm2QNameExt
{
	const Avm2String* uri;
	const Avm2String* local;
	// The Ruffle Multiname ATTRIBUTE flag: set when the QName names an
	// attribute (e.g. xml.attributes()[0].name()); honored by E4X lazy
	// names and Proxy's flash_proxy::isAttribute.
	uint8_t is_attribute;
} Avm2QNameExt;

// NULL when the value is not a Namespace / QName instance.
Avm2NamespaceExt* avm2_namespace_ext_of(Avm2Value v);
Avm2QNameExt* avm2_qname_ext_of(Avm2Value v);
Avm2Object* avm2_namespace_new(Avm2Context* ctx, const Avm2String* uri,
                               const Avm2String* prefix, uint8_t kind);
// Box a constant-pool namespace (PushNamespace, namespace trait defaults).
Avm2Object* avm2_namespace_from_pool(Avm2Context* ctx, Avm2AbcFileRt* file,
                                     uint32_t ns_idx);
Avm2Object* avm2_qname_new(Avm2Context* ctx, const Avm2String* uri,
                           const Avm2String* local);
const Avm2String* avm2_qname_to_string(Avm2Context* ctx, const Avm2QNameExt* ext);
// Enumeration hooks (called from avm2_object.c); return 0 if `obj` is not
// a Namespace/QName.
int avm2_nsqname_next_enumerant(Avm2Object* obj, uint32_t cur, uint32_t* out);
int avm2_nsqname_enumerant_name(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                                Avm2Value* out);
int avm2_nsqname_enumerant_value(Avm2Context* ctx, Avm2Object* obj, uint32_t idx,
                                 Avm2Value* out);

// Plain (non-regex) String.split — the regex-aware split falls back to it.
Avm2Value avm2_string_split_plain(struct Avm2Activation* act);

// Definition lookup by dotted/:: name ("pkg::Name", "pkg.Name", "Name"),
// including on-demand "Vector.<...>" applications. Sets *found.
Avm2Value avm2_find_definition(Avm2Context* ctx, const char* s, uint32_t len,
                               int* found);

// Vector machinery (avm2_vector.c).
Avm2VectorExt* avm2_vector_ext(Avm2Object* obj);  // NULL if not a Vector
// Resolve "Vector.<...>" (optional __AS3__.vec prefix) to the applied class.
Avm2Class* avm2_vector_class_by_name(Avm2Context* ctx, const char* s, uint32_t len);
// The parameterized class Vector.<param> (param NULL = *): cached per param.
Avm2Class* avm2_vector_apply(Avm2Context* ctx, Avm2Class* param);
// New Vector.<T> instance of the given PARAMETERIZED class.
Avm2Object* avm2_vector_new(Avm2Context* ctx, Avm2Class* vec_class,
                            uint32_t length, int fixed);
// Index access with Ruffle vector_object.rs error semantics (1125 on
// SWF>=11). set coerces to T; get throws on out-of-range.
Avm2Value avm2_vector_get_index(Avm2Context* ctx, Avm2Object* obj, uint32_t idx);
void avm2_vector_set_index(Avm2Context* ctx, Avm2Object* obj, uint32_t idx, Avm2Value v);
// Numeric-name access path (name parses as f64 but maybe not a valid u32
// index): returns 0 if the name is not numeric (caller falls through to the
// normal property path), 1 if handled; throws per version semantics.
// `out` NULL = write `set_value`, else read into *out. May "handle" a read
// by falling back (returns 0) for negative indices on SWF10.
int avm2_vector_name_access(Avm2Context* ctx, Avm2Object* obj, const char* name,
                            uint32_t name_len, Avm2Value* out, Avm2Value set_value);

// The avmplus QuickSort shared by Array.sort/sortOn and Vector.sort
// (Ruffle globals/array.rs qsort).
typedef struct Avm2SortItem { uint32_t idx; Avm2Value v; } Avm2SortItem;
typedef int (*Avm2SortCmp)(void* ud, const Avm2SortItem* a, const Avm2SortItem* b);
void avm2_avmplus_qsort(void* ud, Avm2SortCmp cmp, Avm2SortItem* s, uint32_t n);

// EventDispatcher instance state (Avm2Object.native_ext).
typedef struct EDListener EDListener;
typedef struct Avm2EventDispatcherExt
{
	EDListener* head;
} Avm2EventDispatcherExt;

// MovieClip stub instance state (Avm2Object.native_ext). The dispatcher
// ext MUST stay first: MovieClips inherit EventDispatcher's natives, which
// read native_ext as Avm2EventDispatcherExt.
typedef struct Avm2MovieClipExt
{
	Avm2EventDispatcherExt dispatcher;
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
	Avm2Class* regexp_class;
	Avm2Class* namespace_class;
	Avm2Class* qname_class;
	Avm2Class* dictionary_class;
	Avm2Class* proxy_class;
	Avm2Class* bytearray_class;
	Avm2Class* eof_error_class;
	Avm2Class* date_class;
	Avm2Class* vector_class;         // generic __AS3__.vec::Vector
	Avm2Class* vector_int_class;     // Vector.<int>
	Avm2Class* vector_uint_class;    // Vector.<uint>
	Avm2Class* vector_double_class;  // Vector.<Number>
	Avm2Class* vector_object_class;  // Vector.<*>
} Avm2Builtins;

#endif // AVM2_GLOBALS_H
