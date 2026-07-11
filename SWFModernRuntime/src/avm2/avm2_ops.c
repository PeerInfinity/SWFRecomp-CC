// Opcode helpers backing the generated C in RecompiledABC/. Semantics per
// Ruffle core/src/avm2/activation.rs (op impls) and value.rs (property
// dispatch): vtable traits (slots / methods / accessors) → own dynamic
// props → prototype chain, with array-index fast paths, primitive
// receivers via their builtin class vtables, and typed errors everywhere
// (avm2_error.h). Anything not implemented aborts loudly (honest failure).

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_e4x.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

// E4XName from a lazy QName value (uri NULL = any namespace).
static E4XName e4x_name_from_qext(const Avm2QNameExt* q, int force_attr)
{
	E4XName n;
	memset(&n, 0, sizeof(n));
	n.local = q->local;
	n.is_attribute = (uint8_t) (q->is_attribute || force_attr);
	if (q->uri == NULL)
	{
		n.any_ns = 1;
	}
	else
	{
		n.is_qname = 1;
		n.single_uri = q->uri;
		n.single_is_real = 1;
	}
	return n;
}

// E4XName from a popped RTQName namespace + a name string. An empty-URI
// (public) namespace rebuilds via string_to_multiname (dxns handling).
static E4XName e4x_name_from_rtns(Avm2Context* ctx, Avm2Value ns_val,
                                  const Avm2String* local, int attr)
{
	Avm2NamespaceExt* n = avm2_namespace_ext_of(ns_val);
	if (n != NULL && n->uri != NULL && n->uri->len > 0)
	{
		E4XName name;
		memset(&name, 0, sizeof(name));
		name.local = local;
		name.is_attribute = (uint8_t) attr;
		name.is_qname = 1;
		name.single_uri = n->uri;
		name.single_is_real = 1;
		return name;
	}
	return avm2_e4x_name_from_string(ctx, local, attr);
}

static int mn_is_attribute_kind(const Avm2AbcFileData* data, uint32_t mn_idx)
{
	uint8_t k = data->multinames[mn_idx].kind;
	return k == 0x0d || k == 0x10 || k == 0x12 || k == 0x0e || k == 0x1c;
}

// Lazy-name fill keeps the multiname's static ns set (handle_input then
// adds public): a plain rebuilt name gains the compiler set so
// use-namespace lookups still match (xml_explicit_use_namespace).
static void e4x_name_attach_mn_set(Avm2Activation* act, uint32_t mn_idx, E4XName* n)
{
	const Avm2AbcFileData* data = act->file->data;
	uint8_t k = data->multinames[mn_idx].kind;
	if (k != 0x09 && k != 0x0e && k != 0x1b && k != 0x1c) return;
	if (n->is_qname || n->any_ns || n->is_attribute || n->local == NULL) return;
	if (avm2_dxns_uri(act->ctx) != NULL) return;
	n->single_uri = NULL;
	n->single_is_real = 0;
	n->data = data;
	n->ns_set = data->multinames[mn_idx].ns_set;
	n->also_public = 1;
}

_Noreturn void avm2_fatal(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	fprintf(stderr, "AVM2 fatal: ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	fflush(stdout);
	exit(1);
}

_Noreturn void avm2_unimplemented_op(Avm2Activation* act, const char* op_name, uint32_t op_index)
{
	(void) act;
	fflush(stdout);
	fprintf(stderr, "AVM2: unimplemented op %s at op index %u (Stage-3 surface; "
	        "see avm2-support-plan.md)\n", op_name, op_index);
	exit(1);
}

_Noreturn void avm2_verify_error_body(Avm2Activation* act, const char* message)
{
	// Reachable VerifyError bodies throw a catchable VerifyError.
	avm2_throw_error(act->ctx, act->ctx->builtins.verify_error_class, "%s", message);
}

// ---------------------------------------------------------------------------
// Property resolution engine
// ---------------------------------------------------------------------------

// How a property was resolved on a receiver.
typedef struct Resolved
{
	const Avm2PropEntry* entry;  // vtable trait
	Avm2Value* dyn;              // own dynamic slot
	Avm2Object* proto_holder;    // proto-chain holder of `dyn`
	int is_array_elem;
	int is_vector_elem;
	int is_bytearray_elem;
	uint32_t arr_index;
	// Proxy receiver whose declared traits missed: route the access to the
	// flash_proxy hooks with QName(proxy_uri, proxy_local) — NULL = any
	// (Ruffle proxy_object.rs *_local overrides).
	int is_proxy;
	const Avm2String* proxy_uri;
	const Avm2String* proxy_local;
} Resolved;

static int value_is_null_like(Avm2Value v)
{
	return v.kind == AVM2_VALUE_UNDEFINED || v.kind == AVM2_VALUE_NULL;
}

// Is `obj` allowed to grow dynamic props?
static int object_is_dynamic(Avm2Object* obj)
{
	if (obj->kind == AVM2_OBJ_CLASS || obj->kind == AVM2_OBJ_FUNCTION
	    || obj->kind == AVM2_OBJ_ARRAY)
	{
		return 1;
	}
	if (obj->cls == NULL) return 1;
	return (obj->cls->flags & AVM2_CLASS_FLAG_SEALED) == 0;
}

// Dictionary receivers route OBJECT-valued lazy names to object space
// (Ruffle op_get_property_fast Object arm).
static int dict_object_key(Avm2Value recv, Avm2Value name_val,
                           Avm2Object** out_dict, Avm2Object** out_key)
{
	if (recv.kind != AVM2_VALUE_OBJECT || name_val.kind != AVM2_VALUE_OBJECT)
	{
		return 0;
	}
	if (!avm2_is_dictionary(recv.u.obj)) return 0;
	*out_dict = recv.u.obj;
	*out_key = name_val.u.obj;
	return 1;
}

// QName components of a static multiname for Proxy hooks (Ruffle
// QNameObject::from_name): single-ns set -> that URI, multi-ns set -> "",
// the any namespace / any name -> NULL.
static void mn_qname_parts(Avm2Context* ctx, const Avm2AbcFileData* data,
                           uint32_t mn_idx, const Avm2String** uri,
                           const Avm2String** local)
{
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
	*local = (mn->name != 0) ? &data->strings[mn->name] : NULL;
	switch (mn->kind)
	{
		case 0x07: case 0x0d:  // QName / QNameA
			*uri = (mn->ns != 0) ? &data->strings[data->namespaces[mn->ns].name]
			                     : NULL;
			break;
		case 0x09: case 0x0e: case 0x1b: case 0x1c:  // Multiname(L)(A)
		{
			const Avm2AbcNsSet* set = &data->ns_sets[mn->ns_set];
			if (set->count == 1 && set->ns_indices[0] != 0)
			{
				*uri = &data->strings[data->namespaces[set->ns_indices[0]].name];
			}
			else if (set->count == 1)
			{
				*uri = NULL;
			}
			else
			{
				*uri = avm2_string_from_literal(ctx, "");
			}
			break;
		}
		default:
			*uri = avm2_string_from_literal(ctx, "");
			break;
	}
}

// Try to parse a property name as an array index ("0", "42").
static int name_as_index(const char* name, uint32_t len, uint32_t* out)
{
	if (len == 0 || len > 10) return 0;
	uint64_t v = 0;
	for (uint32_t i = 0; i < len; i++)
	{
		if (name[i] < '0' || name[i] > '9') return 0;
		v = v * 10 + (uint64_t) (name[i] - '0');
	}
	if (len > 1 && name[0] == '0') return 0;
	if (v >= 0xFFFFFFFFull) return 0;
	*out = (uint32_t) v;
	return 1;
}

// Resolve by name-key: vtable → array index → own dynamic → proto chain.
// `public_ok` gates the dynamic/proto part (dynamic props are public).
static int resolve_key(Avm2Context* ctx, Avm2Value recv, const Avm2PropKey* key,
                       int public_ok, Resolved* out)
{
	memset(out, 0, sizeof(*out));

	const Avm2VTable* vt = avm2_value_vtable(ctx, recv);
	const Avm2PropEntry* e = avm2_vtable_find(vt, key);
	if (e == NULL && recv.kind == AVM2_VALUE_OBJECT
	    && recv.u.obj->kind == AVM2_OBJ_CLASS
	    && ctx->builtins.class_class != NULL)
	{
		// Class objects carry their static traits; Class's own instance
		// members (the `prototype` getter) come from Class's ivtable.
		e = avm2_vtable_find(&ctx->builtins.class_class->ivtable, key);
	}
	if (e != NULL)
	{
		out->entry = e;
		return 1;
	}
	if (recv.kind == AVM2_VALUE_OBJECT && avm2_is_proxy(recv.u.obj))
	{
		// Proxies replace the whole local half (dynamic + proto) with the
		// flash_proxy hooks, for ANY namespace.
		out->is_proxy = 1;
		out->proxy_uri = avm2_string_new(ctx, key->ns_uri, key->ns_len);
		out->proxy_local = avm2_string_new(ctx, key->name, key->name_len);
		return 1;
	}
	if (!public_ok) return 0;

	if (recv.kind == AVM2_VALUE_OBJECT)
	{
		Avm2Object* obj = recv.u.obj;
		uint32_t idx;
		if (obj->kind == AVM2_OBJ_ARRAY && name_as_index(key->name, key->name_len, &idx))
		{
			Avm2Value v = avm2_array_get(obj, idx);
			if (v.kind != AVM2_VALUE_HOLE)
			{
				out->is_array_elem = 1;
				out->arr_index = idx;
				return 1;
			}
			// A hole / out-of-range falls through to dynamic + proto.
		}
		if (obj->kind == AVM2_OBJ_VECTOR
		    && name_as_index(key->name, key->name_len, &idx)
		    && idx < avm2_vector_ext(obj)->length)
		{
			out->is_vector_elem = 1;
			out->arr_index = idx;
			return 1;
		}
		if (avm2_bytearray_ext_of(recv) != NULL
		    && name_as_index(key->name, key->name_len, &idx))
		{
			// ByteArrays never forward index access (even out of bounds).
			out->is_bytearray_elem = 1;
			out->arr_index = idx;
			return 1;
		}
		out->dyn = avm2_object_find_dynamic(obj, key->name, key->name_len);
		if (out->dyn != NULL) return 1;
	}

	// Prototype chain (reads only).
	Avm2Object* proto = avm2_value_proto(ctx, recv);
	while (proto != NULL)
	{
		Avm2Value* dv = avm2_object_find_dynamic(proto, key->name, key->name_len);
		if (dv != NULL)
		{
			out->dyn = dv;
			out->proto_holder = proto;
			return 1;
		}
		proto = proto->proto;
	}
	return 0;
}

// Resolve a static multiname: vtable by multiname → dynamic/proto by name.
static int resolve_mn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx, Resolved* out)
{
	Avm2Context* ctx = act->ctx;
	const Avm2AbcFileData* data = act->file->data;
	memset(out, 0, sizeof(*out));

	const Avm2VTable* vt = avm2_value_vtable(ctx, recv);
	const Avm2PropEntry* e = avm2_vtable_find_mn(vt, data, mn_idx);
	if (e == NULL && recv.kind == AVM2_VALUE_OBJECT
	    && recv.u.obj->kind == AVM2_OBJ_CLASS
	    && ctx->builtins.class_class != NULL)
	{
		e = avm2_vtable_find_mn(&ctx->builtins.class_class->ivtable, data, mn_idx);
	}
	if (e != NULL)
	{
		out->entry = e;
		return 1;
	}
	if (recv.kind == AVM2_VALUE_OBJECT && avm2_is_proxy(recv.u.obj))
	{
		out->is_proxy = 1;
		mn_qname_parts(ctx, data, mn_idx, &out->proxy_uri, &out->proxy_local);
		return 1;
	}
	if (!avm2_mn_has_public_ns(data, mn_idx)) return 0;

	const char* name;
	uint32_t name_len;
	avm2_mn_name(data, mn_idx, &name, &name_len);
	Avm2PropKey key = avm2_public_key(name, name_len);
	if (recv.kind == AVM2_VALUE_OBJECT)
	{
		Avm2Object* obj = recv.u.obj;
		uint32_t idx;
		if (obj->kind == AVM2_OBJ_ARRAY && name_as_index(key.name, key.name_len, &idx))
		{
			Avm2Value v = avm2_array_get(obj, idx);
			if (v.kind != AVM2_VALUE_HOLE)
			{
				out->is_array_elem = 1;
				out->arr_index = idx;
				return 1;
			}
		}
		if (obj->kind == AVM2_OBJ_VECTOR
		    && name_as_index(key.name, key.name_len, &idx)
		    && idx < avm2_vector_ext(obj)->length)
		{
			out->is_vector_elem = 1;
			out->arr_index = idx;
			return 1;
		}
		if (avm2_bytearray_ext_of(recv) != NULL
		    && name_as_index(key.name, key.name_len, &idx))
		{
			out->is_bytearray_elem = 1;
			out->arr_index = idx;
			return 1;
		}
		out->dyn = avm2_object_find_dynamic(obj, key.name, key.name_len);
		if (out->dyn != NULL) return 1;
	}
	Avm2Object* proto = avm2_value_proto(ctx, recv);
	while (proto != NULL)
	{
		Avm2Value* dv = avm2_object_find_dynamic(proto, key.name, key.name_len);
		if (dv != NULL)
		{
			out->dyn = dv;
			out->proto_holder = proto;
			return 1;
		}
		proto = proto->proto;
	}
	return 0;
}

// Bind a method trait into a bound-method closure, cached per receiver so
// obj.method === obj.method holds (Ruffle get_bound_method).
static Avm2Value bind_method_entry(Avm2Context* ctx, const Avm2PropEntry* e, Avm2Value recv)
{
	Avm2Object* holder = (recv.kind == AVM2_VALUE_OBJECT) ? recv.u.obj : NULL;
	if (holder != NULL)
	{
		for (Avm2BoundMethod* bm = holder->bound_methods; bm != NULL; bm = bm->next)
		{
			if (bm->entry == e) return avm2_object_value(bm->fn);
		}
	}
	Avm2Object* fnobj = avm2_function_new(ctx, &e->method, e->defining_class,
	                                      e->method_scope, recv, true);
	if (holder != NULL)
	{
		Avm2BoundMethod* bm = avm2_alloc(ctx, sizeof(Avm2BoundMethod));
		bm->entry = e;
		bm->fn = fnobj;
		bm->next = holder->bound_methods;
		holder->bound_methods = bm;
	}
	return avm2_object_value(fnobj);
}

// Qualified class name of a receiver, for error messages.
static const char* class_name_of(Avm2Context* ctx, Avm2Value recv, char* buf, int size)
{
	avm2_class_qname_buf(avm2_value_class(ctx, recv), buf, size);
	return buf;
}

// Read the resolved property's value with `recv` as the getter receiver.
static Avm2Value resolved_get(Avm2Context* ctx, Avm2Value recv, const Resolved* r,
                              const char* name, uint32_t name_len)
{
	if (r->is_proxy)
	{
		Avm2Value qn = avm2_object_value(
			avm2_qname_new(ctx, r->proxy_uri, r->proxy_local));
		return avm2_proxy_call_hook(ctx, recv.u.obj, "getProperty", &qn, 1);
	}
	if (r->is_array_elem)
	{
		Avm2Value v = avm2_array_get(recv.u.obj, r->arr_index);
		return v.kind == AVM2_VALUE_HOLE ? avm2_undefined() : v;
	}
	if (r->is_vector_elem)
	{
		return avm2_vector_get_index(ctx, recv.u.obj, r->arr_index);
	}
	if (r->is_bytearray_elem)
	{
		Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(recv);
		if (r->arr_index < ba->len)
		{
			return avm2_integer(ba->bytes[r->arr_index]);
		}
		return avm2_undefined();
	}
	if (r->dyn != NULL) return *r->dyn;
	const Avm2PropEntry* e = r->entry;
	switch (e->kind)
	{
		case AVM2_PROP_SLOT:
			return recv.u.obj->slots[e->slot_index];
		case AVM2_PROP_METHOD:
			return bind_method_entry(ctx, e, recv);
		case AVM2_PROP_GETTER:
		case AVM2_PROP_GETSET:
			return avm2_call_method_ref(ctx, &e->method, e->defining_class,
			                            e->method_scope, recv, NULL, 0);
		default:
		{
			char cn[160];
			class_name_of(ctx, recv, cn, sizeof(cn));
			avm2_throw_error(ctx, ctx->builtins.reference_error_class,
			                 "Error #1077: Illegal read of write-only property "
			                 "%.*s on %s.", (int) name_len, name, cn);
		}
	}
}

// ---------------------------------------------------------------------------
// GetProperty / SetProperty / InitProperty / DeleteProperty
// ---------------------------------------------------------------------------

static Avm2Value getproperty_common(Avm2Activation* act, Avm2Value recv,
                                    const char* name, uint32_t name_len,
                                    int resolved_ok, const Resolved* r,
                                    int mn_public)
{
	Avm2Context* ctx = act->ctx;
	if (resolved_ok)
	{
		return resolved_get(ctx, recv, r, name, name_len);
	}
	// Miss: dynamic receivers yield undefined for public names; a
	// non-public multiname can never match an expando prop (1081 on a
	// dynamic receiver). Sealed receivers always throw 1069.
	int dynamic = recv.kind == AVM2_VALUE_OBJECT && object_is_dynamic(recv.u.obj);
	if (dynamic && mn_public)
	{
		return avm2_undefined();
	}
	char cn[160];
	class_name_of(ctx, recv, cn, sizeof(cn));
	avm2_throw_error(ctx, ctx->builtins.reference_error_class,
	                 "Error #%s: Property %.*s not found on %s and there is "
	                 "no default value.", dynamic ? "1081" : "1069",
	                 (int) name_len, name, cn);
}

Avm2Value avm2_op_getproperty_static(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(act->ctx, recv, name, name_len);
	}
	if (avm2_value_is_xmlish(recv))
	{
		Avm2Value out;
		if (avm2_xml_get_mn(act->ctx, recv, act->file->data, mn_idx, &out))
		{
			return out;
		}
	}
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_VECTOR
	    && avm2_mn_has_public_ns(act->file->data, mn_idx))
	{
		Avm2Value out;
		if (avm2_vector_name_access(act->ctx, recv.u.obj, name, name_len,
		                            &out, avm2_undefined()))
		{
			return out;
		}
	}
	Resolved r;
	int ok = resolve_mn(act, recv, mn_idx, &r);
	return getproperty_common(act, recv, name, name_len, ok, &r,
	                          avm2_mn_has_public_ns(act->file->data, mn_idx));
}

static Avm2Value getproperty_qname(Avm2Activation* act, Avm2Value recv,
                                   const Avm2QNameExt* q);

Avm2Value avm2_op_getproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                  Avm2Value name_val, int interp)
{
	Avm2Context* ctx = act->ctx;
	(void) mn_idx;
	{
		// Dictionary receivers key objects by identity — but only on the
		// FAST path (public ns in the set, or an interpreter-mode body):
		// Ruffle op_get_property_fast; the slow path stringifies the name
		// (dictionary_access_no_pubns expects the 1056/1081 miss).
		Avm2Object* dict;
		Avm2Object* key;
		if ((interp || avm2_mn_has_public_ns(act->file->data, mn_idx))
		    && dict_object_key(recv, name_val, &dict, &key))
		{
			Avm2Value* v = avm2_object_find_dynamic_obj(dict, key);
			return (v != NULL) ? *v : avm2_undefined();
		}
		// A QName object as the lazy name resolves by its own uri::local
		// key (Ruffle fill_with_runtime_params — qname_indexing).
		const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
		if (q != NULL) return getproperty_qname(act, recv, q);
	}
	if (avm2_value_is_xmlish(recv))
	{
		int attr = mn_is_attribute_kind(act->file->data, mn_idx);
		E4XName n = avm2_e4x_name_from_value(ctx, name_val, attr);
		e4x_name_attach_mn_set(act, mn_idx, &n);
		Avm2Value out;
		if (avm2_xml_get_name(ctx, recv, &n, &out)) return out;
	}
	if (value_is_null_like(recv))
	{
		const Avm2String* ns = avm2_coerce_to_string(ctx, name_val);
		avm2_throw_null_or_undefined(ctx, recv, ns->utf8, ns->len);
	}
	// Array index fast path with a numeric name value (public names only,
	// except interpreter-mode bodies).
	uint32_t idx;
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_ARRAY
	    && avm2_value_as_index(name_val, &idx)
	    && (interp || avm2_mn_has_public_ns(act->file->data, mn_idx)))
	{
		Avm2Value v = avm2_array_get(recv.u.obj, idx);
		if (v.kind != AVM2_VALUE_HOLE) return v;
		// fall through (holes may be shadowed by dyn/proto)
	}
	{
		Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(recv);
		if (ba != NULL && avm2_value_as_index(name_val, &idx)
		    && (interp || avm2_mn_has_public_ns(act->file->data, mn_idx)))
		{
			return (idx < ba->len) ? avm2_integer(ba->bytes[idx])
			                       : avm2_undefined();
		}
	}
	const Avm2String* ns = avm2_coerce_to_string(ctx, name_val);
	int mn_public = avm2_mn_has_public_ns(act->file->data, mn_idx);
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_VECTOR
	    && (interp || mn_public))
	{
		Avm2Value out;
		if (avm2_vector_name_access(ctx, recv.u.obj, ns->utf8, ns->len,
		                            &out, avm2_undefined()))
		{
			return out;
		}
	}
	if (!mn_public)
	{
		// Non-public ns set (dict.test::["name"]): traits keyed in any of
		// the set's namespaces still match.
		const Avm2PropEntry* e = avm2_vtable_find_mn_named(
			avm2_value_vtable(ctx, recv), act->file->data, mn_idx,
			ns->utf8, ns->len);
		if (e != NULL)
		{
			Resolved r2;
			memset(&r2, 0, sizeof(r2));
			r2.entry = e;
			return getproperty_common(act, recv, ns->utf8, ns->len, 1, &r2,
			                          mn_public);
		}
	}
	Avm2PropKey key = avm2_public_key(ns->utf8, ns->len);
	Resolved r;
	int ok = resolve_key(ctx, recv, &key, mn_public, &r);
	return getproperty_common(act, recv, ns->utf8, ns->len, ok, &r, mn_public);
}

// Common write path once resolution is done.
static void setproperty_resolved(Avm2Context* ctx, Avm2Value recv, const Resolved* r,
                                 const char* name, uint32_t name_len, Avm2Value value,
                                 int allow_const)
{
	if (r->is_proxy)
	{
		Avm2Value args[2];
		args[0] = avm2_object_value(
			avm2_qname_new(ctx, r->proxy_uri, r->proxy_local));
		args[1] = value;
		avm2_proxy_call_hook(ctx, recv.u.obj, "setProperty", args, 2);
		return;
	}
	if (r->is_array_elem)
	{
		avm2_array_set(ctx, recv.u.obj, r->arr_index, value);
		return;
	}
	if (r->is_vector_elem)
	{
		avm2_vector_set_index(ctx, recv.u.obj, r->arr_index, value);
		return;
	}
	if (r->is_bytearray_elem)
	{
		Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(recv);
		uint8_t byte = (uint8_t) avm2_coerce_to_u32(ctx, value);
		if (r->arr_index >= ba->len)
		{
			avm2_bytearray_set_length_public(ctx, ba, r->arr_index + 1);
		}
		ba->bytes[r->arr_index] = byte;
		return;
	}
	if (r->dyn != NULL && r->proto_holder == NULL)
	{
		*r->dyn = value;
		return;
	}
	if (r->dyn != NULL)
	{
		// Proto-chain hit: writes shadow on the receiver itself.
		avm2_object_set_dynamic(ctx, recv.u.obj, name, name_len, value);
		return;
	}
	const Avm2PropEntry* e = r->entry;
	char cn[160];
	class_name_of(ctx, recv, cn, sizeof(cn));
	switch (e->kind)
	{
		case AVM2_PROP_SLOT:
		{
			if (e->is_const && !allow_const)
			{
				avm2_throw_error(ctx, ctx->builtins.reference_error_class,
				                 "Error #1074: Illegal write to read-only property "
				                 "%.*s on %s.", (int) name_len, name, cn);
			}
			Avm2Value cv = value;
			if (e->type_mn != 0 && e->type_file != NULL)
			{
				cv = avm2_coerce_to_type_mn(ctx, e->type_file, e->type_mn, value);
			}
			recv.u.obj->slots[e->slot_index] = cv;
			return;
		}
		case AVM2_PROP_SETTER:
			avm2_call_method_ref(ctx, &e->setter, e->defining_class,
			                     e->method_scope, recv, &value, 1);
			return;
		case AVM2_PROP_GETSET:
			avm2_call_method_ref(ctx, &e->setter, e->defining_class,
			                     e->method_scope, recv, &value, 1);
			return;
		case AVM2_PROP_GETTER:
			avm2_throw_error(ctx, ctx->builtins.reference_error_class,
			                 "Error #1074: Illegal write to read-only property "
			                 "%.*s on %s.", (int) name_len, name, cn);
		case AVM2_PROP_METHOD:
		default:
			avm2_throw_error(ctx, ctx->builtins.reference_error_class,
			                 "Error #1037: Cannot assign to a method %.*s on %s.",
			                 (int) name_len, name, cn);
	}
}

static void setproperty_miss(Avm2Context* ctx, Avm2Value recv,
                             const char* name, uint32_t name_len, Avm2Value value)
{
	if (recv.kind == AVM2_VALUE_OBJECT && object_is_dynamic(recv.u.obj))
	{
		avm2_object_set_dynamic(ctx, recv.u.obj, name, name_len, value);
		return;
	}
	char cn[160];
	class_name_of(ctx, recv, cn, sizeof(cn));
	avm2_throw_error(ctx, ctx->builtins.reference_error_class,
	                 "Error #1056: Cannot create property %.*s on %s.",
	                 (int) name_len, name, cn);
}

static void setproperty_impl(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                             Avm2Value value, int allow_const)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(act->ctx, recv, name, name_len);
	}
	if (avm2_value_is_xmlish(recv)
	    && avm2_xml_set_mn(act->ctx, recv, act->file->data, mn_idx, value))
	{
		return;
	}
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_VECTOR
	    && avm2_mn_has_public_ns(act->file->data, mn_idx)
	    && avm2_vector_name_access(act->ctx, recv.u.obj, name, name_len,
	                               NULL, value))
	{
		return;
	}
	Resolved r;
	if (resolve_mn(act, recv, mn_idx, &r))
	{
		// Proto-chain dynamic hits shadow onto the receiver; array holes
		// resolved as miss go to setproperty_miss (below) — resolve_mn
		// treats in-range holes as unresolved, but writes must still land
		// in storage, so handle arrays first.
		setproperty_resolved(act->ctx, recv, &r, name, name_len, value, allow_const);
		return;
	}
	uint32_t idx;
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_ARRAY
	    && name_as_index(name, name_len, &idx))
	{
		avm2_array_set(act->ctx, recv.u.obj, idx, value);
		return;
	}
	setproperty_miss(act->ctx, recv, name, name_len, value);
}

void avm2_op_setproperty_static(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                Avm2Value value)
{
	setproperty_impl(act, recv, mn_idx, value, 0);
}

void avm2_op_initproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx, Avm2Value val)
{
	setproperty_impl(act, recv, mn_idx, val, 1);
}

static void setproperty_qname(Avm2Activation* act, Avm2Value recv,
                              const Avm2QNameExt* q, Avm2Value value);

void avm2_op_setproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                             Avm2Value name_val, Avm2Value value, int interp)
{
	Avm2Context* ctx = act->ctx;
	(void) mn_idx;
	{
		// FAST-path-only, like the get side (dictionary_access_no_pubns).
		Avm2Object* dict;
		Avm2Object* key;
		if ((interp || avm2_mn_has_public_ns(act->file->data, mn_idx))
		    && dict_object_key(recv, name_val, &dict, &key))
		{
			avm2_object_set_dynamic_obj(ctx, dict, key, value);
			return;
		}
		const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
		if (q != NULL)
		{
			setproperty_qname(act, recv, q, value);
			return;
		}
	}
	if (avm2_value_is_xmlish(recv))
	{
		int attr = mn_is_attribute_kind(act->file->data, mn_idx);
		E4XName n = avm2_e4x_name_from_value(ctx, name_val, attr);
		e4x_name_attach_mn_set(act, mn_idx, &n);
		if (avm2_xml_set_name(ctx, recv, &n, value)) return;
	}
	if (value_is_null_like(recv))
	{
		const Avm2String* ns = avm2_coerce_to_string(ctx, name_val);
		avm2_throw_null_or_undefined(ctx, recv, ns->utf8, ns->len);
	}
	uint32_t idx;
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_ARRAY
	    && avm2_value_as_index(name_val, &idx)
	    && (interp || avm2_mn_has_public_ns(act->file->data, mn_idx)))
	{
		avm2_array_set(ctx, recv.u.obj, idx, value);
		return;
	}
	{
		Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(recv);
		if (ba != NULL && avm2_value_as_index(name_val, &idx)
		    && (interp || avm2_mn_has_public_ns(act->file->data, mn_idx)))
		{
			uint8_t byte = (uint8_t) avm2_coerce_to_u32(ctx, value);
			if (idx >= ba->len)
			{
				avm2_bytearray_set_length_public(ctx, ba, idx + 1);
			}
			ba->bytes[idx] = byte;
			return;
		}
	}
	const Avm2String* ns = avm2_coerce_to_string(ctx, name_val);
	int mn_public = avm2_mn_has_public_ns(act->file->data, mn_idx);
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_VECTOR
	    && (interp || mn_public)
	    && avm2_vector_name_access(ctx, recv.u.obj, ns->utf8, ns->len,
	                               NULL, value))
	{
		return;
	}
	if (!mn_public)
	{
		const Avm2PropEntry* e = avm2_vtable_find_mn_named(
			avm2_value_vtable(ctx, recv), act->file->data, mn_idx,
			ns->utf8, ns->len);
		if (e != NULL)
		{
			Resolved r2;
			memset(&r2, 0, sizeof(r2));
			r2.entry = e;
			setproperty_resolved(ctx, recv, &r2, ns->utf8, ns->len, value, 0);
			return;
		}
	}
	Avm2PropKey key = avm2_public_key(ns->utf8, ns->len);
	Resolved r;
	if (resolve_key(ctx, recv, &key, mn_public, &r))
	{
		setproperty_resolved(ctx, recv, &r, ns->utf8, ns->len, value, 0);
		return;
	}
	if (mn_public
	    && recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_ARRAY
	    && name_as_index(ns->utf8, ns->len, &idx))
	{
		avm2_array_set(ctx, recv.u.obj, idx, value);
		return;
	}
	if (!mn_public && recv.kind == AVM2_VALUE_OBJECT)
	{
		// Expando props are public-only: a non-public name can't create one.
		char cn[160];
		class_name_of(ctx, recv, cn, sizeof(cn));
		avm2_throw_error(ctx, ctx->builtins.reference_error_class,
		                 "Error #1056: Cannot create property %.*s on %s.",
		                 (int) ns->len, ns->utf8, cn);
	}
	setproperty_miss(ctx, recv, ns->utf8, ns->len, value);
}

static Avm2Value deleteproperty_common(Avm2Activation* act, Avm2Value recv,
                                       const char* name, uint32_t name_len)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	if (recv.kind != AVM2_VALUE_OBJECT)
	{
		return avm2_bool(false);
	}
	Avm2Object* obj = recv.u.obj;
	uint32_t idx;
	if (obj->kind == AVM2_OBJ_ARRAY && name_as_index(name, name_len, &idx))
	{
		avm2_array_delete(obj, idx);
		return avm2_bool(true);
	}
	if (obj->kind == AVM2_OBJ_VECTOR)
	{
		// FP never deletes vector elements; delete always reports true.
		return avm2_bool(true);
	}
	// Declared traits can't be deleted.
	Avm2PropKey key = avm2_public_key(name, name_len);
	if (avm2_vtable_find(obj->vtable, &key) != NULL)
	{
		return avm2_bool(false);
	}
	if (avm2_object_delete_dynamic(obj, name, name_len))
	{
		return avm2_bool(true);
	}
	// Deleting a missing property returns true (ES3).
	return avm2_bool(true);
}

Avm2Value avm2_op_deleteproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx)
{
	Avm2Context* ctx = act->ctx;
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (avm2_value_is_xmlish(recv))
	{
		Avm2Value out;
		if (avm2_xml_delete_mn(ctx, recv, act->file->data, mn_idx, &out))
		{
			return out;
		}
	}
	if (recv.kind == AVM2_VALUE_OBJECT && avm2_is_proxy(recv.u.obj))
	{
		// Declared traits (in ANY ns of the multiname) can't be deleted;
		// everything else routes to the deleteProperty hook.
		if (avm2_vtable_find_mn(recv.u.obj->vtable, act->file->data, mn_idx))
		{
			return avm2_bool(false);
		}
		const Avm2String* uri;
		const Avm2String* local;
		mn_qname_parts(ctx, act->file->data, mn_idx, &uri, &local);
		Avm2Value qn = avm2_object_value(avm2_qname_new(ctx, uri, local));
		Avm2Value v = avm2_proxy_call_hook(ctx, recv.u.obj, "deleteProperty",
		                                   &qn, 1);
		return avm2_bool(avm2_coerce_to_boolean(v));
	}
	return deleteproperty_common(act, recv, name, name_len);
}

static Avm2Value deleteproperty_qname(Avm2Activation* act, Avm2Value recv,
                                      const Avm2QNameExt* q);

Avm2Value avm2_op_deleteproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                     Avm2Value name_val)
{
	(void) mn_idx;
	{
		Avm2Object* dict;
		Avm2Object* key;
		if (dict_object_key(recv, name_val, &dict, &key))
		{
			avm2_object_delete_dynamic_obj(dict, key);
			return avm2_bool(true);
		}
		const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
		if (q != NULL) return deleteproperty_qname(act, recv, q);
	}
	if (avm2_value_is_xmlish(recv))
	{
		Avm2Context* xctx = act->ctx;
		int attr = mn_is_attribute_kind(act->file->data, mn_idx);
		E4XName n = avm2_e4x_name_from_value(xctx, name_val, attr);
		e4x_name_attach_mn_set(act, mn_idx, &n);
		Avm2Value out;
		if (avm2_xml_delete_name(xctx, recv, &n, &out)) return out;
	}
	if (recv.kind == AVM2_VALUE_OBJECT && avm2_is_proxy(recv.u.obj))
	{
		Avm2Context* dctx = act->ctx;
		const Avm2String* nm = avm2_coerce_to_string(dctx, name_val);
		if (avm2_vtable_find_mn_named(recv.u.obj->vtable, act->file->data,
		                              mn_idx, nm->utf8, nm->len))
		{
			return avm2_bool(false);
		}
		const Avm2String* uri;
		const Avm2String* local;
		mn_qname_parts(dctx, act->file->data, mn_idx, &uri, &local);
		Avm2Value qn = avm2_object_value(avm2_qname_new(dctx, uri, nm));
		Avm2Value v = avm2_proxy_call_hook(dctx, recv.u.obj, "deleteProperty",
		                                   &qn, 1);
		return avm2_bool(avm2_coerce_to_boolean(v));
	}
	uint32_t idx;
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj != NULL
	    && recv.u.obj->kind == AVM2_OBJ_ARRAY && avm2_value_as_index(name_val, &idx))
	{
		avm2_array_delete(recv.u.obj, idx);
		return avm2_bool(true);
	}
	const Avm2String* ns = avm2_coerce_to_string(act->ctx, name_val);
	return deleteproperty_common(act, recv, ns->utf8, ns->len);
}

// ---------------------------------------------------------------------------
// Lazy-namespace (RTQName / RTQNameL) property ops + QName-valued lazy names
// ---------------------------------------------------------------------------

// Key from a popped Namespace value. Returns whether the namespace is the
// public (empty-URI) one, i.e. whether dynamic props are reachable.
static int key_from_ns_value(Avm2Value ns_val, const char* name, uint32_t name_len,
                             Avm2PropKey* key)
{
	Avm2NamespaceExt* n = avm2_namespace_ext_of(ns_val);
	if (n == NULL)
	{
		avm2_fatal("lazy-ns property op: popped namespace is not a Namespace value");
	}
	key->name = name;
	key->name_len = name_len;
	key->ns_kind = (n->kind != 0) ? n->kind : 0x16;
	key->ns_uri = n->uri->utf8;
	key->ns_len = n->uri->len;
	return avm2_propkey_is_public(key);
}

// Key from a QName object used as a lazy name. `*any_ns` reports the
// any-namespace QName (name-only matching).
static int key_from_qname_ext(const Avm2QNameExt* q, Avm2PropKey* key, int* any_ns)
{
	const char* name = (q->local != NULL) ? q->local->utf8 : "*";
	uint32_t name_len = (q->local != NULL) ? q->local->len : 1;
	*any_ns = (q->uri == NULL);
	if (q->uri == NULL)
	{
		*key = avm2_public_key(name, name_len);
		return 1;
	}
	key->name = name;
	key->name_len = name_len;
	key->ns_kind = 0x16;
	key->ns_uri = q->uri->utf8;
	key->ns_len = q->uri->len;
	return avm2_propkey_is_public(key);
}

// resolve_key plus the any-namespace fallback: a name-only vtable scan.
static int resolve_generic_key(Avm2Context* ctx, Avm2Value recv, const Avm2PropKey* key,
                               int public_ok, int any_ns, Resolved* out)
{
	if (resolve_key(ctx, recv, key, public_ok, out)) return 1;
	if (any_ns)
	{
		const Avm2VTable* vt = avm2_value_vtable(ctx, recv);
		if (vt != NULL)
		{
			for (uint32_t i = 0; i < vt->count; i++)
			{
				if (vt->entries[i].key.name_len == key->name_len
				    && memcmp(vt->entries[i].key.name, key->name, key->name_len) == 0)
				{
					memset(out, 0, sizeof(*out));
					out->entry = &vt->entries[i];
					return 1;
				}
			}
		}
	}
	return 0;
}

static Avm2Value getproperty_qname(Avm2Activation* act, Avm2Value recv,
                                   const Avm2QNameExt* q)
{
	Avm2Context* ctx = act->ctx;
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = e4x_name_from_qext(q, 0);
		Avm2Value out;
		if (avm2_xml_get_name(ctx, recv, &n, &out)) return out;
	}
	Avm2PropKey key;
	int any_ns;
	int pub = key_from_qname_ext(q, &key, &any_ns);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, key.name, key.name_len);
	}
	Resolved r;
	int ok = resolve_generic_key(ctx, recv, &key, pub, any_ns, &r);
	return getproperty_common(act, recv, key.name, key.name_len, ok, &r, pub);
}

static void setproperty_nonpublic_miss(Avm2Context* ctx, Avm2Value recv,
                                       const char* name, uint32_t name_len)
{
	char cn[160];
	class_name_of(ctx, recv, cn, sizeof(cn));
	avm2_throw_error(ctx, ctx->builtins.reference_error_class,
	                 "Error #1056: Cannot create property %.*s on %s.",
	                 (int) name_len, name, cn);
}

static void setproperty_qname(Avm2Activation* act, Avm2Value recv,
                              const Avm2QNameExt* q, Avm2Value value)
{
	Avm2Context* ctx = act->ctx;
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = e4x_name_from_qext(q, 0);
		if (avm2_xml_set_name(ctx, recv, &n, value)) return;
	}
	Avm2PropKey key;
	int any_ns;
	int pub = key_from_qname_ext(q, &key, &any_ns);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, key.name, key.name_len);
	}
	Resolved r;
	if (resolve_generic_key(ctx, recv, &key, pub, any_ns, &r))
	{
		setproperty_resolved(ctx, recv, &r, key.name, key.name_len, value, 0);
		return;
	}
	if (!pub && recv.kind == AVM2_VALUE_OBJECT)
	{
		setproperty_nonpublic_miss(ctx, recv, key.name, key.name_len);
	}
	setproperty_miss(ctx, recv, key.name, key.name_len, value);
}

static Avm2Value deleteproperty_qname(Avm2Activation* act, Avm2Value recv,
                                      const Avm2QNameExt* q)
{
	Avm2Context* ctx = act->ctx;
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = e4x_name_from_qext(q, 0);
		Avm2Value out;
		if (avm2_xml_delete_name(ctx, recv, &n, &out)) return out;
	}
	Avm2PropKey key;
	int any_ns;
	int pub = key_from_qname_ext(q, &key, &any_ns);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, key.name, key.name_len);
	}
	if (recv.kind != AVM2_VALUE_OBJECT) return avm2_bool(false);
	Avm2Object* obj = recv.u.obj;
	Resolved r;
	if (resolve_generic_key(ctx, recv, &key, 0, any_ns, &r))
	{
		if (r.is_proxy)
		{
			Avm2Value qn = avm2_object_value(
				avm2_qname_new(ctx, q->uri, q->local));
			Avm2Value v = avm2_proxy_call_hook(ctx, obj, "deleteProperty",
			                                   &qn, 1);
			return avm2_bool(avm2_coerce_to_boolean(v));
		}
		return avm2_bool(false);  // declared traits can't be deleted
	}
	if (pub && avm2_object_delete_dynamic(obj, key.name, key.name_len))
	{
		return avm2_bool(true);
	}
	return avm2_bool(true);  // deleting a missing property returns true
}

Avm2Value avm2_op_pushnamespace(Avm2Activation* act, uint32_t ns_idx)
{
	return avm2_object_value(avm2_namespace_from_pool(act->ctx, act->file, ns_idx));
}

Avm2Value avm2_op_getproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                   Avm2Value ns_val)
{
	Avm2Context* ctx = act->ctx;
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = e4x_name_from_rtns(ctx, ns_val,
		                               avm2_string_new(ctx, name, name_len),
		                               mn_is_attribute_kind(act->file->data, mn_idx));
		Avm2Value out;
		if (avm2_xml_get_name(ctx, recv, &n, &out)) return out;
	}
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, name, name_len, &key);
	Resolved r;
	int ok = resolve_key(ctx, recv, &key, pub, &r);
	return getproperty_common(act, recv, name, name_len, ok, &r, pub);
}

Avm2Value avm2_op_getproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                     Avm2Value ns_val, Avm2Value name_val)
{
	Avm2Context* ctx = act->ctx;
	const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
	if (q != NULL)
	{
		// A QName name overrides the popped namespace entirely.
		return getproperty_qname(act, recv, q);
	}
	const Avm2String* s = avm2_coerce_to_string(ctx, name_val);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, s->utf8, s->len);
	}
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = e4x_name_from_rtns(ctx, ns_val, s,
		                               mn_is_attribute_kind(act->file->data, mn_idx));
		Avm2Value out;
		if (avm2_xml_get_name(ctx, recv, &n, &out)) return out;
	}
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, s->utf8, s->len, &key);
	Resolved r;
	int ok = resolve_key(ctx, recv, &key, pub, &r);
	return getproperty_common(act, recv, s->utf8, s->len, ok, &r, pub);
}

static void setproperty_rtns_common(Avm2Activation* act, Avm2Value recv,
                                    Avm2Value ns_val, const char* name,
                                    uint32_t name_len, Avm2Value value)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = e4x_name_from_rtns(ctx, ns_val,
		                               avm2_string_new(ctx, name, name_len), 0);
		if (avm2_xml_set_name(ctx, recv, &n, value)) return;
	}
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, name, name_len, &key);
	Resolved r;
	if (resolve_key(ctx, recv, &key, pub, &r))
	{
		setproperty_resolved(ctx, recv, &r, name, name_len, value, 0);
		return;
	}
	if (!pub && recv.kind == AVM2_VALUE_OBJECT)
	{
		setproperty_nonpublic_miss(ctx, recv, name, name_len);
	}
	setproperty_miss(ctx, recv, name, name_len, value);
}

void avm2_op_setproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                              Avm2Value ns_val, Avm2Value value)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	setproperty_rtns_common(act, recv, ns_val, name, name_len, value);
}

void avm2_op_setproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                Avm2Value ns_val, Avm2Value name_val, Avm2Value value)
{
	(void) mn_idx;
	const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
	if (q != NULL)
	{
		setproperty_qname(act, recv, q, value);
		return;
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, name_val);
	setproperty_rtns_common(act, recv, ns_val, s->utf8, s->len, value);
}

static Avm2Value deleteproperty_rtns_common(Avm2Activation* act, Avm2Value recv,
                                            Avm2Value ns_val, const char* name,
                                            uint32_t name_len)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = e4x_name_from_rtns(ctx, ns_val,
		                               avm2_string_new(ctx, name, name_len), 0);
		Avm2Value out;
		if (avm2_xml_delete_name(ctx, recv, &n, &out)) return out;
	}
	if (recv.kind != AVM2_VALUE_OBJECT) return avm2_bool(false);
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, name, name_len, &key);
	const Avm2VTable* vt = avm2_value_vtable(ctx, recv);
	if (avm2_vtable_find(vt, &key) != NULL)
	{
		return avm2_bool(false);
	}
	if (avm2_is_proxy(recv.u.obj))
	{
		Avm2Value qn = avm2_object_value(avm2_qname_new(
			ctx, avm2_string_new(ctx, key.ns_uri, key.ns_len),
			avm2_string_new(ctx, name, name_len)));
		Avm2Value v = avm2_proxy_call_hook(ctx, recv.u.obj, "deleteProperty",
		                                   &qn, 1);
		return avm2_bool(avm2_coerce_to_boolean(v));
	}
	if (pub && avm2_object_delete_dynamic(recv.u.obj, name, name_len))
	{
		return avm2_bool(true);
	}
	return avm2_bool(true);
}

Avm2Value avm2_op_deleteproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                      Avm2Value ns_val)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	return deleteproperty_rtns_common(act, recv, ns_val, name, name_len);
}

Avm2Value avm2_op_deleteproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                        Avm2Value ns_val, Avm2Value name_val)
{
	(void) mn_idx;
	const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
	if (q != NULL)
	{
		return deleteproperty_qname(act, recv, q);
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, name_val);
	return deleteproperty_rtns_common(act, recv, ns_val, s->utf8, s->len);
}

// ---------------------------------------------------------------------------
// Slots
// ---------------------------------------------------------------------------

static const Avm2PropEntry* find_slot_entry(const Avm2VTable* vt, uint32_t slot_index)
{
	if (vt == NULL) return NULL;
	for (uint32_t i = 0; i < vt->count; i++)
	{
		if (vt->entries[i].kind == AVM2_PROP_SLOT
		    && vt->entries[i].slot_index == slot_index)
		{
			return &vt->entries[i];
		}
	}
	return NULL;
}

Avm2Value avm2_op_getslot(Avm2Activation* act, Avm2Value objv, uint32_t index0)
{
	if (value_is_null_like(objv))
	{
		avm2_throw_null_or_undefined(act->ctx, objv, NULL, 0);
	}
	Avm2Object* obj = objv.u.obj;
	uint32_t slot = index0 + 1;  // IR is 0-based; slot arrays are 1-based
	if (obj == NULL || slot >= obj->slot_count)
	{
		avm2_fatal("GetSlot %u out of range (slot_count %u)", slot,
		           obj != NULL ? obj->slot_count : 0);
	}
	return obj->slots[slot];
}

void avm2_op_setslot(Avm2Activation* act, Avm2Value objv, uint32_t index0, Avm2Value value)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(objv))
	{
		avm2_throw_null_or_undefined(ctx, objv, NULL, 0);
	}
	Avm2Object* obj = objv.u.obj;
	uint32_t slot = index0 + 1;
	if (obj == NULL || slot >= obj->slot_count)
	{
		avm2_fatal("SetSlot %u out of range (slot_count %u)", slot,
		           obj != NULL ? obj->slot_count : 0);
	}
	const Avm2PropEntry* e = find_slot_entry(obj->vtable, slot);
	if (e != NULL && e->type_mn != 0 && e->type_file != NULL)
	{
		value = avm2_coerce_to_type_mn(ctx, e->type_file, e->type_mn, value);
	}
	obj->slots[slot] = value;
}

// ---------------------------------------------------------------------------
// Scopes and name lookup
// ---------------------------------------------------------------------------

Avm2Object* avm2_op_pushscope(Avm2Activation* act, Avm2Value v)
{
	if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL)
	{
		return v.u.obj;
	}
	if (value_is_null_like(v))
	{
		avm2_throw_null_or_undefined(act->ctx, v, NULL, 0);
	}
	// A primitive scope (p-code can push anything): box it — vtable and
	// prototype-chain lookups on the box behave like the primitive
	// (findprop_global_prototype pushes the number 4 as its global scope).
	Avm2Context* ctx = act->ctx;
	Avm2Object* box = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 1);
	box->cls = avm2_value_class(ctx, v);
	box->vtable = &box->cls->ivtable;
	box->proto = box->cls->prototype_obj;
	return box;
}

Avm2Object* avm2_op_getglobalscope(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                   uint32_t scope_n)
{
	if (act->outer != NULL && act->outer->count > 0)
	{
		return act->outer->entries[0].obj;
	}
	if (scope_n > 0)
	{
		return lscope[0].obj;
	}
	avm2_fatal("GetGlobalScope with an empty scope stack");
}

Avm2Object* avm2_op_getouterscope(Avm2Activation* act, uint32_t index)
{
	if (act->outer == NULL || index >= act->outer->count)
	{
		avm2_fatal("GetOuterScope %u out of range", index);
	}
	return act->outer->entries[index].obj;
}

// Does a scope object define the multiname? Plain scopes expose declared
// traits only; with-scopes expose everything (Ruffle scope.rs find).
static int scope_defines_mn(Avm2Activation* act, const Avm2ScopeEntry* se, uint32_t mn_idx)
{
	if (se->obj == NULL) return 0;
	if (!se->is_with)
	{
		return avm2_vtable_find_mn(se->obj->vtable, act->file->data, mn_idx) != NULL;
	}
	Avm2Value sv = avm2_object_value(se->obj);
	if (avm2_value_is_xmlish(sv))
	{
		// E4X filter loops (with-scope per item): has_property semantics.
		return avm2_xml_has_property_mn(act->ctx, sv, act->file->data, mn_idx);
	}
	Resolved r;
	return resolve_mn(act, sv, mn_idx, &r);
}

static Avm2Object* findproperty_impl(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                     uint32_t scope_n, uint32_t mn_idx,
                                     const char* name, uint32_t name_len, int strict)
{
	const Avm2AbcFileData* data = act->file->data;
	Avm2Context* ctx = act->ctx;

	// Local scope stack, top → bottom.
	for (uint32_t i = scope_n; i > 0; i--)
	{
		if (scope_defines_mn(act, &lscope[i - 1], mn_idx)) return lscope[i - 1].obj;
	}
	// Captured outer chain, top → bottom.
	if (act->outer != NULL)
	{
		for (uint32_t i = act->outer->count; i > 0; i--)
		{
			if (scope_defines_mn(act, &act->outer->entries[i - 1], mn_idx))
			{
				return act->outer->entries[i - 1].obj;
			}
		}
	}
	// Domain of the defining file (lazy script init happens inside).
	{
		Avm2PropKey key;
		const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
		if (mn->kind == 0x07 || mn->kind == 0x0d)
		{
			if (avm2_propkey_from_qname(data, mn_idx, &key))
			{
				Avm2Object* g = avm2_domain_find(ctx, &key);
				if (g != NULL) return g;
			}
		}
		else if (mn->kind == 0x09 || mn->kind == 0x0e)
		{
			const Avm2AbcNsSet* set = &data->ns_sets[mn->ns_set];
			for (uint32_t i = 0; i < set->count; i++)
			{
				const Avm2AbcNamespace* ns = &data->namespaces[set->ns_indices[i]];
				key.name = data->strings[mn->name].utf8;
				key.name_len = data->strings[mn->name].len;
				key.ns_kind = ns->kind;
				key.ns_uri = data->strings[ns->name].utf8;
				key.ns_len = data->strings[ns->name].len;
				Avm2Object* g = avm2_domain_find(ctx, &key);
				if (g != NULL) return g;
			}
		}
		else
		{
			// Lazy name resolved by the caller: public key lookup.
			key = avm2_public_key(name, name_len);
			Avm2Object* g = avm2_domain_find(ctx, &key);
			if (g != NULL) return g;
		}
	}

	// Last resort (Ruffle find_definition): the global scope's own dynamic
	// props and its prototype chain (findprop_global_prototype).
	if (avm2_mn_has_public_ns(data, mn_idx))
	{
		Avm2Object* global = NULL;
		if (act->outer != NULL && act->outer->count > 0)
		{
			global = act->outer->entries[0].obj;
		}
		else if (scope_n > 0)
		{
			global = lscope[0].obj;
		}
		for (Avm2Object* p = global; p != NULL; p = p->proto)
		{
			if (avm2_object_find_dynamic(p, name, name_len) != NULL)
			{
				return global;
			}
		}
	}

	if (!strict)
	{
		return avm2_op_getglobalscope(act, lscope, scope_n);
	}
	avm2_throw_1065(ctx, name, name_len);
}

Avm2Object* avm2_op_findproperty(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                 uint32_t scope_n, uint32_t mn_idx, int strict)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	return findproperty_impl(act, lscope, scope_n, mn_idx, name, name_len, strict);
}

// Key-based scope search shared by the lazy-name and lazy-ns FindProperty
// variants. `public_ok` gates dynamic-prop matching (with-scopes and the
// global prototype-chain fallback).
static Avm2Object* findproperty_key(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                    uint32_t scope_n, const Avm2PropKey* key,
                                    int public_ok, int strict)
{
	Avm2Context* ctx = act->ctx;
	for (uint32_t i = scope_n; i > 0; i--)
	{
		Avm2Object* so = lscope[i - 1].obj;
		Resolved r;
		if (lscope[i - 1].is_with)
		{
			Avm2Value sv = avm2_object_value(so);
			if (avm2_value_is_xmlish(sv))
			{
				if (avm2_xml_has_property_via_in(ctx, sv,
				        avm2_string_new(ctx, key->name, key->name_len)))
				{
					return so;
				}
			}
			else if (resolve_key(ctx, sv, key, public_ok, &r))
			{
				return so;
			}
		}
		else if (avm2_vtable_find(so->vtable, key) != NULL)
		{
			return so;
		}
	}
	if (act->outer != NULL)
	{
		for (uint32_t i = act->outer->count; i > 0; i--)
		{
			Avm2Object* so = act->outer->entries[i - 1].obj;
			Resolved r;
			if (act->outer->entries[i - 1].is_with)
			{
				if (resolve_key(ctx, avm2_object_value(so), key, public_ok, &r)) return so;
			}
			else if (avm2_vtable_find(so->vtable, key) != NULL)
			{
				return so;
			}
		}
	}
	Avm2Object* g = avm2_domain_find(ctx, key);
	if (g != NULL) return g;
	if (public_ok)
	{
		Avm2Object* global = NULL;
		if (act->outer != NULL && act->outer->count > 0)
		{
			global = act->outer->entries[0].obj;
		}
		else if (scope_n > 0)
		{
			global = lscope[0].obj;
		}
		for (Avm2Object* p = global; p != NULL; p = p->proto)
		{
			if (avm2_object_find_dynamic(p, key->name, key->name_len) != NULL)
			{
				return global;
			}
		}
	}
	if (!strict)
	{
		return avm2_op_getglobalscope(act, lscope, scope_n);
	}
	avm2_throw_1065(ctx, key->name, key->name_len);
}

Avm2Object* avm2_op_findproperty_dyn(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                     uint32_t scope_n, uint32_t mn_idx, Avm2Value name,
                                     int strict)
{
	// Resolve the runtime name to a string and search scope objects for a
	// public property of that name (with-scope semantics apply the same).
	Avm2Context* ctx = act->ctx;
	(void) mn_idx;
	{
		const Avm2QNameExt* q = avm2_qname_ext_of(name);
		if (q != NULL)
		{
			Avm2PropKey key;
			int any_ns;
			int pub = key_from_qname_ext(q, &key, &any_ns);
			return findproperty_key(act, lscope, scope_n, &key, pub, strict);
		}
	}
	const Avm2String* ns = avm2_coerce_to_string(ctx, name);
	Avm2PropKey key = avm2_public_key(ns->utf8, ns->len);
	return findproperty_key(act, lscope, scope_n, &key, 1, strict);
}

Avm2Object* avm2_op_findproperty_rtns(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                      uint32_t scope_n, uint32_t mn_idx, Avm2Value ns_val,
                                      int strict)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, name, name_len, &key);
	return findproperty_key(act, lscope, scope_n, &key, pub, strict);
}

Avm2Object* avm2_op_findproperty_rtns_l(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                        uint32_t scope_n, uint32_t mn_idx, Avm2Value ns_val,
                                        Avm2Value name_val, int strict)
{
	(void) mn_idx;
	{
		const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
		if (q != NULL)
		{
			Avm2PropKey key;
			int any_ns;
			int pub = key_from_qname_ext(q, &key, &any_ns);
			return findproperty_key(act, lscope, scope_n, &key, pub, strict);
		}
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, name_val);
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, s->utf8, s->len, &key);
	return findproperty_key(act, lscope, scope_n, &key, pub, strict);
}

Avm2Object* avm2_op_finddef(Avm2Activation* act, uint32_t mn_idx)
{
	const Avm2AbcFileData* data = act->file->data;
	Avm2PropKey key;
	if (avm2_propkey_from_qname(data, mn_idx, &key))
	{
		Avm2Object* g = avm2_domain_find(act->ctx, &key);
		if (g != NULL) return g;
	}
	else if (data->multinames[mn_idx].kind == 0x09
	         || data->multinames[mn_idx].kind == 0x0e)
	{
		const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
		const Avm2AbcNsSet* set = &data->ns_sets[mn->ns_set];
		for (uint32_t i = 0; i < set->count; i++)
		{
			const Avm2AbcNamespace* ns = &data->namespaces[set->ns_indices[i]];
			key.name = data->strings[mn->name].utf8;
			key.name_len = data->strings[mn->name].len;
			key.ns_kind = ns->kind;
			key.ns_uri = data->strings[ns->name].utf8;
			key.ns_len = data->strings[ns->name].len;
			Avm2Object* g = avm2_domain_find(act->ctx, &key);
			if (g != NULL) return g;
		}
	}
	const char* name;
	uint32_t name_len;
	avm2_mn_name(data, mn_idx, &name, &name_len);
	avm2_throw_1065(act->ctx, name, name_len);
}

// ---------------------------------------------------------------------------
// Calls
// ---------------------------------------------------------------------------

static Avm2Value callproperty_common(Avm2Context* ctx, Avm2Value recv,
                                     const char* name, uint32_t name_len,
                                     int resolved_ok, const Resolved* r,
                                     const Avm2Value* args, uint32_t argc,
                                     Avm2Value call_recv)
{
	if (resolved_ok && r->is_proxy)
	{
		Avm2Value* a = avm2_alloc(ctx, (argc + 1) * sizeof(Avm2Value));
		a[0] = avm2_object_value(
			avm2_qname_new(ctx, r->proxy_uri, r->proxy_local));
		for (uint32_t i = 0; i < argc; i++) a[i + 1] = args[i];
		return avm2_proxy_call_hook(ctx, recv.u.obj, "callProperty", a, argc + 1);
	}
	if (resolved_ok && r->entry != NULL && r->entry->kind == AVM2_PROP_METHOD)
	{
		return avm2_call_method_ref(ctx, &r->entry->method,
		                            r->entry->defining_class, r->entry->method_scope,
		                            call_recv, args, argc);
	}
	if (resolved_ok)
	{
		Avm2Value v = resolved_get(ctx, recv, r, name, name_len);
		if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL)
		{
			return avm2_call_value(ctx, v, call_recv, args, argc);
		}
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #1006: %.*s is not a function.",
		                 (int) name_len, name);
	}
	// Miss.
	if (recv.kind == AVM2_VALUE_OBJECT && !object_is_dynamic(recv.u.obj))
	{
		char cn[160];
		class_name_of(ctx, recv, cn, sizeof(cn));
		avm2_throw_error(ctx, ctx->builtins.reference_error_class,
		                 "Error #1069: Property %.*s not found on %s and there "
		                 "is no default value.", (int) name_len, name, cn);
	}
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1006: %.*s is not a function.", (int) name_len, name);
}

Avm2Value avm2_op_callproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                               const Avm2Value* args, uint32_t argc)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(act->ctx, recv, name, name_len);
	}
	Resolved r;
	int ok = resolve_mn(act, recv, mn_idx, &r);
	if (!ok && avm2_value_is_xmlish(recv))
	{
		return avm2_xml_call_fallback(act->ctx, recv, name, name_len, args, argc);
	}
	return callproperty_common(act->ctx, recv, name, name_len, ok, &r, args, argc, recv);
}

static Avm2Value callproperty_qname(Avm2Activation* act, Avm2Value recv,
                                    const Avm2QNameExt* q,
                                    const Avm2Value* args, uint32_t argc);

Avm2Value avm2_op_callproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                   Avm2Value name_val, const Avm2Value* args, uint32_t argc)
{
	Avm2Context* ctx = act->ctx;
	(void) mn_idx;
	{
		const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
		if (q != NULL) return callproperty_qname(act, recv, q, args, argc);
	}
	if (value_is_null_like(recv))
	{
		const Avm2String* ns = avm2_coerce_to_string(ctx, name_val);
		avm2_throw_null_or_undefined(ctx, recv, ns->utf8, ns->len);
	}
	uint32_t idx;
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_ARRAY
	    && avm2_value_as_index(name_val, &idx))
	{
		Avm2Value v = avm2_array_get(recv.u.obj, idx);
		if (v.kind != AVM2_VALUE_HOLE)
		{
			return avm2_call_value(ctx, v, recv, args, argc);
		}
	}
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_VECTOR
	    && avm2_value_as_index(name_val, &idx)
	    && idx < avm2_vector_ext(recv.u.obj)->length)
	{
		return avm2_call_value(ctx, avm2_vector_get_index(ctx, recv.u.obj, idx),
		                       recv, args, argc);
	}
	const Avm2String* ns = avm2_coerce_to_string(ctx, name_val);
	Avm2PropKey key = avm2_public_key(ns->utf8, ns->len);
	Resolved r;
	int ok = resolve_key(ctx, recv, &key, 1, &r);
	if (!ok && avm2_value_is_xmlish(recv))
	{
		return avm2_xml_call_fallback(ctx, recv, ns->utf8, ns->len, args, argc);
	}
	return callproperty_common(act->ctx, recv, ns->utf8, ns->len, ok, &r, args, argc, recv);
}

static Avm2Value callproperty_qname(Avm2Activation* act, Avm2Value recv,
                                    const Avm2QNameExt* q,
                                    const Avm2Value* args, uint32_t argc)
{
	Avm2Context* ctx = act->ctx;
	Avm2PropKey key;
	int any_ns;
	int pub = key_from_qname_ext(q, &key, &any_ns);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, key.name, key.name_len);
	}
	Resolved r;
	int ok = resolve_generic_key(ctx, recv, &key, pub, any_ns, &r);
	if (!ok && avm2_value_is_xmlish(recv))
	{
		return avm2_xml_call_fallback(ctx, recv, key.name, key.name_len, args, argc);
	}
	return callproperty_common(ctx, recv, key.name, key.name_len, ok, &r, args, argc, recv);
}

Avm2Value avm2_op_callproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                    Avm2Value ns_val, const Avm2Value* args, uint32_t argc)
{
	Avm2Context* ctx = act->ctx;
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, name, name_len, &key);
	Resolved r;
	int ok = resolve_key(ctx, recv, &key, pub, &r);
	if (!ok && avm2_value_is_xmlish(recv))
	{
		return avm2_xml_call_fallback(ctx, recv, name, name_len, args, argc);
	}
	return callproperty_common(ctx, recv, name, name_len, ok, &r, args, argc, recv);
}

Avm2Value avm2_op_callproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                      Avm2Value ns_val, Avm2Value name_val,
                                      const Avm2Value* args, uint32_t argc)
{
	(void) mn_idx;
	Avm2Context* ctx = act->ctx;
	const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
	if (q != NULL)
	{
		return callproperty_qname(act, recv, q, args, argc);
	}
	const Avm2String* s = avm2_coerce_to_string(ctx, name_val);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, s->utf8, s->len);
	}
	Avm2PropKey key;
	int pub = key_from_ns_value(ns_val, s->utf8, s->len, &key);
	Resolved r;
	int ok = resolve_key(ctx, recv, &key, pub, &r);
	if (!ok && avm2_value_is_xmlish(recv))
	{
		return avm2_xml_call_fallback(ctx, recv, s->utf8, s->len, args, argc);
	}
	return callproperty_common(ctx, recv, s->utf8, s->len, ok, &r, args, argc, recv);
}

Avm2Value avm2_op_callproplex(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                              const Avm2Value* args, uint32_t argc)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(act->ctx, recv, name, name_len);
	}
	Resolved r;
	int ok = resolve_mn(act, recv, mn_idx, &r);
	// Lex call: the callee receives null as `this`.
	return callproperty_common(act->ctx, recv, name, name_len, ok, &r, args, argc,
	                           avm2_null());
}

Avm2Value avm2_op_call(Avm2Activation* act, Avm2Value func, Avm2Value recv,
                       const Avm2Value* args, uint32_t argc)
{
	return avm2_call_value(act->ctx, func, recv, args, argc);
}

Avm2Value avm2_op_callstatic(Avm2Activation* act, uint32_t method_index, Avm2Value recv,
                             const Avm2Value* args, uint32_t argc)
{
	const Avm2AbcMethodData* m = &act->file->data->methods[method_index];
	Avm2MethodRef ref = { m->fn, act->file, m->debug_name, method_index };
	return avm2_call_method_ref(act->ctx, &ref, NULL, act->outer, recv, args, argc);
}

// Super dispatch: resolve on the bound class's SUPERCLASS vtable.
static Avm2Class* super_class_of(Avm2Activation* act)
{
	if (act->bound_class == NULL || act->bound_class->super_class == NULL)
	{
		// avmplus VerifyError 1035 (catchable) — array_access_interpreter
		// probes JIT-vs-interpreter behavior with an illegal super op.
		avm2_throw_error(act->ctx, act->ctx->builtins.verify_error_class,
		                 "Error #1035: Illegal super expression found in method.");
	}
	return act->bound_class->super_class;
}

Avm2Value avm2_op_callsuper(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                            const Avm2Value* args, uint32_t argc)
{
	Avm2Context* ctx = act->ctx;
	Avm2Class* super = super_class_of(act);
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	const Avm2PropEntry* e = avm2_vtable_find_mn(&super->ivtable, act->file->data, mn_idx);
	if (e == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.reference_error_class,
		                 "Error #1070: Method %.*s not found on %.*s",
		                 (int) name_len, name,
		                 (int) super->name.name_len, super->name.name);
	}
	switch (e->kind)
	{
		case AVM2_PROP_METHOD:
			return avm2_call_method_ref(ctx, &e->method, e->defining_class,
			                            e->method_scope, recv, args, argc);
		case AVM2_PROP_GETTER:
		case AVM2_PROP_GETSET:
		{
			Avm2Value v = avm2_call_method_ref(ctx, &e->method, e->defining_class,
			                                   e->method_scope, recv, NULL, 0);
			return avm2_call_value(ctx, v, recv, args, argc);
		}
		case AVM2_PROP_SLOT:
		{
			Avm2Value v = recv.u.obj->slots[e->slot_index];
			return avm2_call_value(ctx, v, recv, args, argc);
		}
		default:
			avm2_throw_1006(ctx, name, name_len);
	}
}

Avm2Value avm2_op_getsuper(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx)
{
	Avm2Context* ctx = act->ctx;
	Avm2Class* super = super_class_of(act);
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	const Avm2PropEntry* e = avm2_vtable_find_mn(&super->ivtable, act->file->data, mn_idx);
	if (e == NULL)
	{
		avm2_throw_1069(ctx, name, name_len, super);
	}
	Resolved r;
	memset(&r, 0, sizeof(r));
	r.entry = e;
	return resolved_get(ctx, recv, &r, name, name_len);
}

void avm2_op_setsuper(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx, Avm2Value value)
{
	Avm2Context* ctx = act->ctx;
	Avm2Class* super = super_class_of(act);
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	const Avm2PropEntry* e = avm2_vtable_find_mn(&super->ivtable, act->file->data, mn_idx);
	if (e == NULL)
	{
		avm2_throw_1069(ctx, name, name_len, super);
	}
	// avmplus is lenient on setsuper: writes to const slots and getter-only
	// properties silently succeed / no-op (class_supercalls_errors e2/e5).
	if (e->kind == AVM2_PROP_GETTER)
	{
		return;
	}
	if (e->kind == AVM2_PROP_SLOT && e->is_const)
	{
		Avm2Value cv = value;
		if (e->type_mn != 0 && e->type_file != NULL)
		{
			cv = avm2_coerce_to_type_mn(ctx, e->type_file, e->type_mn, value);
		}
		recv.u.obj->slots[e->slot_index] = cv;
		return;
	}
	Resolved r;
	memset(&r, 0, sizeof(r));
	r.entry = e;
	setproperty_resolved(ctx, recv, &r, name, name_len, value, 0);
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

Avm2Value avm2_op_construct(Avm2Activation* act, Avm2Value ctor,
                            const Avm2Value* args, uint32_t argc)
{
	return avm2_construct_value(act->ctx, ctor, args, argc);
}

Avm2Value avm2_op_constructprop(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                const Avm2Value* args, uint32_t argc)
{
	// Primitive receivers resolve the ctor LENIENTLY: a miss yields
	// undefined (→ TypeError 1007 in construct), not 1069 (Ruffle
	// Value::construct_prop; constructprop_dynamic_primitive).
	if (recv.kind != AVM2_VALUE_OBJECT && !value_is_null_like(recv))
	{
		const char* name;
		uint32_t name_len;
		avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
		Resolved r;
		Avm2Value ctor = resolve_mn(act, recv, mn_idx, &r)
			? resolved_get(act->ctx, recv, &r, name, name_len)
			: avm2_undefined();
		return avm2_construct_value(act->ctx, ctor, args, argc);
	}
	Avm2Value ctor = avm2_op_getproperty_static(act, recv, mn_idx);
	return avm2_construct_value(act->ctx, ctor, args, argc);
}

Avm2Value avm2_op_constructprop_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                    Avm2Value name, const Avm2Value* args, uint32_t argc)
{
	Avm2Value ctor = avm2_op_getproperty_dyn(act, recv, mn_idx, name, 0);
	return avm2_construct_value(act->ctx, ctor, args, argc);
}

void avm2_op_constructsuper(Avm2Activation* act, Avm2Value recv,
                            const Avm2Value* args, uint32_t argc)
{
	if (act->bound_class == NULL)
	{
		// Script initializers may constructsuper on the global object; the
		// global's superclass is Object, whose constructor is a no-op.
		(void) recv;
		(void) args;
		(void) argc;
		return;
	}
	Avm2Class* super = super_class_of(act);
	avm2_call_method_ref(act->ctx, &super->instance_init, super, super->scope,
	                     recv, args, argc);
}

Avm2Value avm2_op_newclass(Avm2Activation* act, uint32_t class_idx, Avm2Value base,
                           const Avm2ScopeEntry* lscope, uint32_t scope_n)
{
	Avm2Context* ctx = act->ctx;
	Avm2Class* super = NULL;
	if (base.kind == AVM2_VALUE_OBJECT && base.u.obj != NULL
	    && base.u.obj->kind == AVM2_OBJ_CLASS)
	{
		super = base.u.obj->class_ref;
	}
	else if (base.kind != AVM2_VALUE_NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.verify_error_class,
		                 "Error #1108: The OP_newclass opcode was used with the "
		                 "incorrect base class.");
	}
	Avm2ScopeChain* scope = avm2_scope_capture(ctx, act->outer, lscope, scope_n);
	Avm2Class* cls = avm2_class_define(ctx, act->file, class_idx, super, scope);
	return avm2_object_value(cls->class_object);
}

Avm2Value avm2_op_newfunction(Avm2Activation* act, uint32_t method_index,
                              const Avm2ScopeEntry* lscope, uint32_t scope_n)
{
	Avm2Context* ctx = act->ctx;
	const Avm2AbcMethodData* m = &act->file->data->methods[method_index];
	Avm2ScopeChain* scope = avm2_scope_capture(ctx, act->outer, lscope, scope_n);
	Avm2MethodRef ref = { m->fn, act->file, m->debug_name, method_index };
	Avm2Object* fnobj = avm2_function_new(ctx, &ref, NULL, scope,
	                                      avm2_undefined(), false);
	return avm2_object_value(fnobj);
}

Avm2Value avm2_op_newactivation(Avm2Activation* act, uint32_t method_index)
{
	Avm2Context* ctx = act->ctx;
	const Avm2AbcMethodData* m = &act->file->data->methods[method_index];
	Avm2VTable* vt = avm2_alloc(ctx, sizeof(Avm2VTable));
	memset(vt, 0, sizeof(Avm2VTable));
	avm2_vtable_add_traits(ctx, vt, act->file, m->body_traits, m->body_trait_count,
	                       act->bound_class, act->outer);
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, vt->slot_count + 1);
	obj->cls = ctx->builtins.object_class;
	obj->vtable = vt;
	avm2_slots_init_defaults(ctx, obj, vt);
	return avm2_object_value(obj);
}

Avm2Value avm2_op_newcatch(Avm2Activation* act, uint32_t method_index, uint32_t exc_index)
{
	Avm2Context* ctx = act->ctx;
	const Avm2AbcMethodData* m = &act->file->data->methods[method_index];
	if (exc_index >= m->exception_count)
	{
		avm2_fatal("NewCatch exception index %u out of range", exc_index);
	}
	const Avm2AbcException* e = &m->exceptions[exc_index];
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 2);
	obj->cls = ctx->builtins.object_class;
	if (e->variable_mn != 0)
	{
		Avm2VTable* vt = avm2_alloc(ctx, sizeof(Avm2VTable));
		memset(vt, 0, sizeof(Avm2VTable));
		Avm2PropEntry pe;
		memset(&pe, 0, sizeof(pe));
		if (!avm2_propkey_from_qname(act->file->data, e->variable_mn, &pe.key))
		{
			avm2_fatal("NewCatch variable multiname %u is not a QName", e->variable_mn);
		}
		pe.kind = AVM2_PROP_SLOT;
		pe.slot_index = 1;
		// SetSlot into the catch variable coerces to the declared catch
		// type (catch_scope_slot expects the 1034 from a mismatched write).
		pe.type_mn = e->type_mn;
		pe.type_file = act->file;
		vt->slot_count = 1;
		avm2_vtable_append(ctx, vt, &pe);
		obj->vtable = vt;

		// avmplus gives the catch scope a synthetic SEALED class named
		// after the catch variable, with no prototype ("Property toString
		// not found on e" in catch_scope_slot).
		Avm2Class* cc = avm2_alloc(ctx, sizeof(Avm2Class));
		memset(cc, 0, sizeof(Avm2Class));
		cc->name = pe.key;
		cc->flags = AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
		obj->cls = cc;
	}
	return avm2_object_value(obj);
}

Avm2Value avm2_op_newobject(Avm2Activation* act, const Avm2Value* name_value_pairs,
                            uint32_t num_pairs)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);
	obj->cls = ctx->builtins.object_class;
	obj->proto = ctx->builtins.object_class->prototype_obj;
	// Ruffle pops pairs from the top of the stack, so the LAST pair is set
	// first (visible in enumeration order).
	for (uint32_t i = num_pairs; i > 0; i--)
	{
		Avm2Value name = name_value_pairs[(i - 1) * 2];
		Avm2Value value = name_value_pairs[(i - 1) * 2 + 1];
		const Avm2String* ns = avm2_coerce_to_string(ctx, name);
		avm2_object_set_dynamic(ctx, obj, ns->utf8, ns->len, value);
	}
	return avm2_object_value(obj);
}

Avm2Value avm2_op_newarray(Avm2Activation* act, const Avm2Value* values, uint32_t n)
{
	return avm2_object_value(avm2_array_from_values(act->ctx, values, n));
}

// ---------------------------------------------------------------------------
// Operators
// ---------------------------------------------------------------------------

Avm2Value avm2_op_add(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	return avm2_op_add_values(act->ctx, a, b);
}

Avm2Value avm2_op_subtract(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	double x = avm2_coerce_to_number(act->ctx, a);
	double y = avm2_coerce_to_number(act->ctx, b);
	return avm2_number(x - y);
}

Avm2Value avm2_op_multiply(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	double x = avm2_coerce_to_number(act->ctx, a);
	double y = avm2_coerce_to_number(act->ctx, b);
	return avm2_number(x * y);
}

Avm2Value avm2_op_divide(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	double x = avm2_coerce_to_number(act->ctx, a);
	double y = avm2_coerce_to_number(act->ctx, b);
	return avm2_number(x / y);
}

Avm2Value avm2_op_modulo(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	double x = avm2_coerce_to_number(act->ctx, a);
	double y = avm2_coerce_to_number(act->ctx, b);
	return avm2_number(fmod(x, y));
}

Avm2Value avm2_op_negate(Avm2Activation* act, Avm2Value a)
{
	return avm2_number(-avm2_coerce_to_number(act->ctx, a));
}

Avm2Value avm2_op_increment(Avm2Activation* act, Avm2Value a)
{
	return avm2_number(avm2_coerce_to_number(act->ctx, a) + 1.0);
}

Avm2Value avm2_op_decrement(Avm2Activation* act, Avm2Value a)
{
	return avm2_number(avm2_coerce_to_number(act->ctx, a) - 1.0);
}

Avm2Value avm2_op_add_i(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	int32_t y = avm2_coerce_to_i32(act->ctx, b);
	return avm2_integer((int32_t) ((uint32_t) x + (uint32_t) y));
}

Avm2Value avm2_op_subtract_i(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	int32_t y = avm2_coerce_to_i32(act->ctx, b);
	return avm2_integer((int32_t) ((uint32_t) x - (uint32_t) y));
}

Avm2Value avm2_op_multiply_i(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	int32_t y = avm2_coerce_to_i32(act->ctx, b);
	return avm2_integer((int32_t) ((uint32_t) x * (uint32_t) y));
}

Avm2Value avm2_op_negate_i(Avm2Activation* act, Avm2Value a)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	return avm2_integer((int32_t) (0u - (uint32_t) x));
}

Avm2Value avm2_op_increment_i(Avm2Activation* act, Avm2Value a)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	return avm2_integer((int32_t) ((uint32_t) x + 1u));
}

Avm2Value avm2_op_decrement_i(Avm2Activation* act, Avm2Value a)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	return avm2_integer((int32_t) ((uint32_t) x - 1u));
}

Avm2Value avm2_op_bitand(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	int32_t y = avm2_coerce_to_i32(act->ctx, b);
	return avm2_integer(x & y);
}

Avm2Value avm2_op_bitor(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	int32_t y = avm2_coerce_to_i32(act->ctx, b);
	return avm2_integer(x | y);
}

Avm2Value avm2_op_bitxor(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	int32_t y = avm2_coerce_to_i32(act->ctx, b);
	return avm2_integer(x ^ y);
}

Avm2Value avm2_op_bitnot(Avm2Activation* act, Avm2Value a)
{
	return avm2_integer(~avm2_coerce_to_i32(act->ctx, a));
}

Avm2Value avm2_op_lshift(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	uint32_t y = avm2_coerce_to_u32(act->ctx, b) & 0x1f;
	return avm2_integer((int32_t) ((uint32_t) x << y));
}

Avm2Value avm2_op_rshift(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int32_t x = avm2_coerce_to_i32(act->ctx, a);
	uint32_t y = avm2_coerce_to_u32(act->ctx, b) & 0x1f;
	return avm2_integer(x >> y);
}

Avm2Value avm2_op_urshift(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	uint32_t x = avm2_coerce_to_u32(act->ctx, a);
	uint32_t y = avm2_coerce_to_u32(act->ctx, b) & 0x1f;
	return avm2_uint_value(x >> y);
}

Avm2Value avm2_op_equals(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	return avm2_bool(avm2_abstract_eq(act->ctx, a, b));
}

Avm2Value avm2_op_strictequals(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	(void) act;
	return avm2_bool(avm2_strict_eq(a, b));
}

Avm2Value avm2_op_lessthan(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int r = avm2_abstract_lt(act->ctx, a, b);
	return avm2_bool(r == 1);
}

Avm2Value avm2_op_lessequals(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int r = avm2_abstract_lt(act->ctx, b, a);
	return avm2_bool(r == 0);
}

Avm2Value avm2_op_greaterthan(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int r = avm2_abstract_lt(act->ctx, b, a);
	return avm2_bool(r == 1);
}

Avm2Value avm2_op_greaterequals(Avm2Activation* act, Avm2Value a, Avm2Value b)
{
	int r = avm2_abstract_lt(act->ctx, a, b);
	return avm2_bool(r == 0);
}

Avm2Value avm2_op_not(Avm2Activation* act, Avm2Value a)
{
	(void) act;
	return avm2_bool(!avm2_coerce_to_boolean(a));
}

Avm2Value avm2_op_typeof(Avm2Activation* act, Avm2Value a)
{
	Avm2Context* ctx = act->ctx;
	const char* s;
	switch (a.kind)
	{
		case AVM2_VALUE_UNDEFINED: s = "undefined"; break;
		case AVM2_VALUE_NULL: s = "object"; break;
		case AVM2_VALUE_BOOL: s = "boolean"; break;
		case AVM2_VALUE_INTEGER:
		case AVM2_VALUE_NUMBER: s = "number"; break;
		case AVM2_VALUE_STRING: s = "string"; break;
		case AVM2_VALUE_OBJECT:
			if (a.u.obj->kind == AVM2_OBJ_FUNCTION
			    && a.u.obj->cls == ctx->builtins.function_class)
			{
				s = "function";
			}
			else if (a.u.obj->cls == ctx->builtins.xml_class
			         || a.u.obj->cls == ctx->builtins.xml_list_class)
			{
				s = "xml";
			}
			else
			{
				s = "object";
			}
			break;
		default: s = "undefined"; break;
	}
	return avm2_string(avm2_string_from_literal(ctx, s));
}

Avm2Value avm2_op_in(Avm2Activation* act, Avm2Value name, Avm2Value obj)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(obj))
	{
		avm2_throw_null_or_undefined(ctx, obj, NULL, 0);
	}
	{
		Avm2Object* dict;
		Avm2Object* key;
		if (dict_object_key(obj, name, &dict, &key))
		{
			return avm2_bool(avm2_object_find_dynamic_obj(dict, key) != NULL);
		}
	}
	if (obj.kind == AVM2_VALUE_OBJECT && avm2_is_proxy(obj.u.obj))
	{
		// `in` on a Proxy calls hasProperty with the STRING form of the
		// name (QNames stringify — proxy_hasproperty).
		Avm2Value arg = avm2_string(avm2_coerce_to_string(ctx, name));
		Avm2Value v = avm2_proxy_call_hook(ctx, obj.u.obj, "hasProperty", &arg, 1);
		return avm2_bool(avm2_coerce_to_boolean(v));
	}
	const Avm2String* ns = avm2_coerce_to_string(ctx, name);
	if (avm2_value_is_xmlish(obj))
	{
		return avm2_bool(avm2_xml_has_property_via_in(ctx, obj, ns) != 0);
	}
	return avm2_bool(avm2_has_public_property(ctx, obj, ns->utf8, ns->len) != 0);
}

Avm2Value avm2_op_instanceof(Avm2Activation* act, Avm2Value value, Avm2Value type)
{
	Avm2Context* ctx = act->ctx;
	if (type.kind != AVM2_VALUE_OBJECT || type.u.obj == NULL
	    || (type.u.obj->kind != AVM2_OBJ_CLASS && type.u.obj->kind != AVM2_OBJ_FUNCTION))
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #1040: The right-hand side of instanceof must be a "
		                 "class or function.");
	}
	if (value.kind == AVM2_VALUE_UNDEFINED)
	{
		avm2_throw_null_or_undefined(ctx, value, NULL, 0);
	}
	if (value.kind == AVM2_VALUE_NULL)
	{
		return avm2_bool(false);
	}
	// ES3 proto-chain check.
	Avm2Object* type_proto = NULL;
	if (type.u.obj->kind == AVM2_OBJ_CLASS)
	{
		type_proto = type.u.obj->class_ref->prototype_obj;
	}
	else
	{
		Avm2Value pv = avm2_get_public_property(ctx, type, "prototype", 9, NULL);
		if (pv.kind == AVM2_VALUE_OBJECT) type_proto = pv.u.obj;
	}
	if (type_proto == NULL) return avm2_bool(false);
	for (Avm2Object* p = avm2_value_proto(ctx, value); p != NULL; p = p->proto)
	{
		if (p == type_proto) return avm2_bool(true);
	}
	return avm2_bool(false);
}

Avm2Value avm2_op_istype(Avm2Activation* act, Avm2Value value, uint32_t mn_idx)
{
	Avm2Class* cls = avm2_class_for_mn(act->ctx, act->file, mn_idx);
	if (cls == NULL) return avm2_bool(false);
	return avm2_bool(avm2_value_is_of_type(act->ctx, value, cls));
}

Avm2Value avm2_op_astype(Avm2Activation* act, Avm2Value value, uint32_t mn_idx)
{
	Avm2Class* cls = avm2_class_for_mn(act->ctx, act->file, mn_idx);
	if (cls == NULL) return avm2_null();
	return avm2_value_is_of_type(act->ctx, value, cls) ? value : avm2_null();
}

static Avm2Class* require_class_value(Avm2Context* ctx, Avm2Value type)
{
	if (type.kind == AVM2_VALUE_UNDEFINED)
	{
		avm2_throw_null_or_undefined(ctx, type, NULL, 0);
	}
	if (type.kind != AVM2_VALUE_OBJECT || type.u.obj == NULL)
	{
		avm2_throw_null_or_undefined(ctx, avm2_null(), NULL, 0);
	}
	if (type.u.obj->kind != AVM2_OBJ_CLASS)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #1041: The right-hand side of operator must be a class.");
	}
	return type.u.obj->class_ref;
}

Avm2Value avm2_op_istypelate(Avm2Activation* act, Avm2Value value, Avm2Value type)
{
	Avm2Class* cls = require_class_value(act->ctx, type);
	return avm2_bool(avm2_value_is_of_type(act->ctx, value, cls));
}

Avm2Value avm2_op_astypelate(Avm2Activation* act, Avm2Value value, Avm2Value type)
{
	Avm2Class* cls = require_class_value(act->ctx, type);
	return avm2_value_is_of_type(act->ctx, value, cls) ? value : avm2_null();
}

// ---------------------------------------------------------------------------
// Coercion ops
// ---------------------------------------------------------------------------

Avm2Value avm2_op_coerce(Avm2Activation* act, Avm2Value v, uint32_t mn_idx)
{
	return avm2_coerce_to_type_mn(act->ctx, act->file, mn_idx, v);
}

Avm2Value avm2_op_coerce_s(Avm2Activation* act, Avm2Value v)
{
	if (value_is_null_like(v)) return avm2_null();
	return avm2_string(avm2_coerce_to_string(act->ctx, v));
}

Avm2Value avm2_op_convert_s(Avm2Activation* act, Avm2Value v)
{
	return avm2_string(avm2_coerce_to_string(act->ctx, v));
}

Avm2Value avm2_op_coerce_o(Avm2Activation* act, Avm2Value v)
{
	(void) act;
	if (v.kind == AVM2_VALUE_UNDEFINED) return avm2_null();
	return v;
}

Avm2Value avm2_op_convert_o(Avm2Activation* act, Avm2Value v)
{
	if (value_is_null_like(v))
	{
		avm2_throw_null_or_undefined(act->ctx, v, NULL, 0);
	}
	return v;
}


// E4X escapes (ECMA-357 EscapeAttributeValue / EscapeElementValue).
static Avm2Value esc_xml(Avm2Activation* act, Avm2Value v, int attr)
{
	Avm2Context* ctx = act->ctx;
	const Avm2String* s = avm2_coerce_to_string(ctx, v);
	char* out = avm2_alloc(ctx, s->len * 6 + 1);
	uint32_t n = 0;
	for (uint32_t i = 0; i < s->len; i++)
	{
		char c = s->utf8[i];
		const char* rep = NULL;
		if (c == '&') rep = "&amp;";
		else if (c == '<') rep = "&lt;";
		else if (!attr && c == '>') rep = "&gt;";
		else if (attr && c == '"') rep = "&quot;";
		else if (attr && c == '\n') rep = "&#xA;";
		else if (attr && c == '\r') rep = "&#xD;";
		else if (attr && c == '\t') rep = "&#x9;";
		if (rep != NULL)
		{
			size_t rl = strlen(rep);
			memcpy(out + n, rep, rl);
			n += (uint32_t) rl;
		}
		else
		{
			out[n++] = c;
		}
	}
	return avm2_string(avm2_string_new(ctx, out, n));
}

Avm2Value avm2_op_esc_xattr(Avm2Activation* act, Avm2Value v)
{
	return esc_xml(act, v, 1);
}

Avm2Value avm2_op_esc_xelem(Avm2Activation* act, Avm2Value v)
{
	return esc_xml(act, v, 0);
}

// ---------------------------------------------------------------------------
// Enumeration (Ruffle activation.rs op_has_next_2 etc.)
// ---------------------------------------------------------------------------

Avm2Value avm2_op_hasnext2(Avm2Activation* act, Avm2Value* obj_reg, Avm2Value* idx_reg)
{
	Avm2Context* ctx = act->ctx;
	int32_t cur = avm2_coerce_to_i32(ctx, *idx_reg);
	if (cur < 0)
	{
		return avm2_bool(false);
	}
	uint32_t cur_index = (uint32_t) cur;
	Avm2Value result_value = *obj_reg;
	Avm2Object* object = NULL;

	if (value_is_null_like(*obj_reg))
	{
		cur_index = 0;
	}
	else if (obj_reg->kind == AVM2_VALUE_OBJECT)
	{
		object = obj_reg->u.obj->proto;
		cur_index = avm2_object_next_enumerant(obj_reg->u.obj, cur_index);
	}
	else
	{
		Avm2Object* proto = avm2_value_proto(ctx, *obj_reg);
		if (proto != NULL)
		{
			object = proto->proto;
			cur_index = avm2_object_next_enumerant(proto, cur_index);
		}
	}

	while (object != NULL && cur_index == 0)
	{
		Avm2Object* cur_object = object;
		cur_index = avm2_object_next_enumerant(cur_object, cur_index);
		result_value = avm2_object_value(cur_object);
		object = cur_object->proto;
	}

	if (cur_index == 0)
	{
		result_value = avm2_null();
	}
	*idx_reg = avm2_uint_value(cur_index);
	*obj_reg = result_value;
	return avm2_bool(cur_index != 0);
}

Avm2Value avm2_op_hasnext(Avm2Activation* act, Avm2Value obj, Avm2Value idx)
{
	Avm2Context* ctx = act->ctx;
	int32_t cur = avm2_coerce_to_i32(ctx, idx);
	if (cur < 0) return avm2_integer(0);
	Avm2Object* o = NULL;
	if (obj.kind == AVM2_VALUE_OBJECT) o = obj.u.obj;
	else if (!value_is_null_like(obj)) o = avm2_value_proto(ctx, obj);
	if (o == NULL) return avm2_integer(0);
	return avm2_uint_value(avm2_object_next_enumerant(o, (uint32_t) cur));
}

Avm2Value avm2_op_nextname(Avm2Activation* act, Avm2Value obj, Avm2Value idx)
{
	Avm2Context* ctx = act->ctx;
	int32_t cur = avm2_coerce_to_i32(ctx, idx);
	if (cur <= 0) return avm2_null();
	if (value_is_null_like(obj))
	{
		avm2_throw_null_or_undefined(ctx, obj, NULL, 0);
	}
	Avm2Object* o = (obj.kind == AVM2_VALUE_OBJECT) ? obj.u.obj
	                                                : avm2_value_proto(ctx, obj);
	return avm2_object_enumerant_name(ctx, o, (uint32_t) cur);
}

Avm2Value avm2_op_nextvalue(Avm2Activation* act, Avm2Value obj, Avm2Value idx)
{
	Avm2Context* ctx = act->ctx;
	int32_t cur = avm2_coerce_to_i32(ctx, idx);
	if (cur <= 0) return avm2_undefined();
	if (value_is_null_like(obj))
	{
		avm2_throw_null_or_undefined(ctx, obj, NULL, 0);
	}
	Avm2Object* o = (obj.kind == AVM2_VALUE_OBJECT) ? obj.u.obj
	                                                : avm2_value_proto(ctx, obj);
	return avm2_object_enumerant_value(ctx, o, (uint32_t) cur);
}

// ---------------------------------------------------------------------------
// Throw
// ---------------------------------------------------------------------------

_Noreturn void avm2_op_throw(Avm2Activation* act, Avm2Value v)
{
	avm2_throw(act->ctx, v);
}

// ---------------------------------------------------------------------------
// Name-based public property access (no multiname pools; used by
// coerce_to_primitive, builtins, `in`, and enumeration paths)
// ---------------------------------------------------------------------------

Avm2Value avm2_get_public_property(Avm2Context* ctx, Avm2Value recv,
                                   const char* name, uint32_t name_len, int* found)
{
	if (found != NULL) *found = 0;
	if (value_is_null_like(recv))
	{
		return avm2_undefined();
	}
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = avm2_e4x_name_from_string(
			ctx, avm2_string_new(ctx, name, name_len), 0);
		Avm2Value out;
		if (avm2_xml_get_name(ctx, recv, &n, &out))
		{
			if (found != NULL) *found = 1;
			return out;
		}
	}
	Avm2PropKey key = avm2_public_key(name, name_len);
	Resolved r;
	if (!resolve_key(ctx, recv, &key, 1, &r))
	{
		return avm2_undefined();
	}
	if (found != NULL) *found = 1;
	return resolved_get(ctx, recv, &r, name, name_len);
}

Avm2Value avm2_call_public_property(Avm2Context* ctx, Avm2Value recv,
                                    const char* name, uint32_t name_len,
                                    const Avm2Value* args, uint32_t argc)
{
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	Avm2PropKey key = avm2_public_key(name, name_len);
	Resolved r;
	int ok = resolve_key(ctx, recv, &key, 1, &r);
	if (!ok && avm2_value_is_xmlish(recv))
	{
		return avm2_xml_call_fallback(ctx, recv, name, name_len, args, argc);
	}
	return callproperty_common(ctx, recv, name, name_len, ok, &r, args, argc, recv);
}

// Name-based public property WRITE (traits + setters + dynamic creation);
// used by the AMF deserializer. Throws like SetProperty.
void avm2_set_public_property(Avm2Context* ctx, Avm2Value recv,
                              const char* name, uint32_t name_len, Avm2Value value)
{
	if (value_is_null_like(recv))
	{
		avm2_throw_null_or_undefined(ctx, recv, name, name_len);
	}
	if (avm2_value_is_xmlish(recv))
	{
		E4XName n = avm2_e4x_name_from_string(
			ctx, avm2_string_new(ctx, name, name_len), 0);
		if (avm2_xml_set_name(ctx, recv, &n, value)) return;
	}
	uint32_t idx;
	if (recv.kind == AVM2_VALUE_OBJECT && recv.u.obj->kind == AVM2_OBJ_ARRAY
	    && name_as_index(name, name_len, &idx))
	{
		avm2_array_set(ctx, recv.u.obj, idx, value);
		return;
	}
	Avm2PropKey key = avm2_public_key(name, name_len);
	Resolved r;
	if (resolve_key(ctx, recv, &key, 1, &r))
	{
		setproperty_resolved(ctx, recv, &r, name, name_len, value, 0);
		return;
	}
	setproperty_miss(ctx, recv, name, name_len, value);
}

int avm2_has_public_property(Avm2Context* ctx, Avm2Value recv,
                             const char* name, uint32_t name_len)
{
	if (value_is_null_like(recv)) return 0;
	if (avm2_value_is_xmlish(recv))
	{
		return avm2_xml_has_property_via_in(
			ctx, recv, avm2_string_new(ctx, name, name_len));
	}
	Avm2PropKey key = avm2_public_key(name, name_len);
	Resolved r;
	return resolve_key(ctx, recv, &key, 1, &r);
}

int avm2_has_own_public_property(Avm2Context* ctx, Avm2Value recv,
                                 const char* name, uint32_t name_len)
{
	if (value_is_null_like(recv)) return 0;
	if (avm2_value_is_xmlish(recv))
	{
		return avm2_xml_has_own(ctx, recv, name, name_len);
	}
	// STRICT publicness: hasOwnProperty must not see AS3-namespace traits
	// (hasownproperty_namespaces).
	const Avm2VTable* vt = avm2_value_vtable(ctx, recv);
	if (avm2_vtable_find_public(vt, name, name_len) != NULL) return 1;
	if (recv.kind != AVM2_VALUE_OBJECT) return 0;
	Avm2Object* obj = recv.u.obj;
	uint32_t idx;
	if (obj->kind == AVM2_OBJ_ARRAY && name_as_index(name, name_len, &idx))
	{
		Avm2Value v = avm2_array_get(obj, idx);
		if (v.kind != AVM2_VALUE_HOLE) return 1;
	}
	if (obj->kind == AVM2_OBJ_VECTOR && name_as_index(name, name_len, &idx))
	{
		return idx < avm2_vector_ext(obj)->length;
	}
	return avm2_object_find_dynamic(obj, name, name_len) != NULL;
}

// ---------------------------------------------------------------------------
// E4X ops: GetDescendants / CheckFilter / Dxns / DxnsLate
// ---------------------------------------------------------------------------

// Static-multiname has_property for with-scope finds (filter expressions).
int avm2_xml_has_property_mn(Avm2Context* ctx, Avm2Value recv,
                             const Avm2AbcFileData* data, uint32_t mn_idx)
{
	const char* name;
	uint32_t name_len;
	avm2_mn_name(data, mn_idx, &name, &name_len);
	E4XName n = avm2_e4x_name_from_mn(ctx, data, mn_idx);
	Avm2XmlExt* xe = avm2_xml_ext_of(recv);
	Avm2XmlListExt* le = avm2_xmllist_ext_of(recv);
	// Any-name / attribute forms have no string equivalent; probe directly.
	if (xe != NULL)
	{
		E4XNode* node = xe->node;
		if (node->kind != E4X_ELEMENT) return 0;
		E4XNode** arr = n.is_attribute ? node->attributes : node->children;
		uint32_t cnt = n.is_attribute ? node->attr_count : node->child_count;
		for (uint32_t i = 0; i < cnt; i++)
		{
			if (avm2_e4x_matches_name(arr[i], &n)) return 1;
		}
		return 0;
	}
	if (le != NULL)
	{
		for (uint32_t i = 0; i < le->count; i++)
		{
			Avm2Value item = avm2_object_value(
				avm2_xml_object_for_node(ctx, le->items[i]));
			if (avm2_xml_has_property_mn(ctx, item, data, mn_idx)) return 1;
		}
		return 0;
	}
	return 0;
}

Avm2Value avm2_op_getdescendants(Avm2Activation* act, Avm2Value v, uint32_t mn_idx)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(v))
	{
		avm2_throw_null_or_undefined(ctx, v, NULL, 0);
	}
	E4XName name = avm2_e4x_name_from_mn(ctx, act->file->data, mn_idx);
	return avm2_xml_descendants_value(ctx, v, &name);
}

Avm2Value avm2_op_getdescendants_dyn(Avm2Activation* act, Avm2Value v, uint32_t mn_idx,
                                     Avm2Value name_val)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(v))
	{
		avm2_throw_null_or_undefined(ctx, v, NULL, 0);
	}
	int attr = mn_is_attribute_kind(act->file->data, mn_idx);
	E4XName name = avm2_e4x_name_from_value(ctx, name_val, attr);
	return avm2_xml_descendants_value(ctx, v, &name);
}

Avm2Value avm2_op_getdescendants_rtns(Avm2Activation* act, Avm2Value v, uint32_t mn_idx,
                                       Avm2Value ns_val)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(v))
	{
		avm2_throw_null_or_undefined(ctx, v, NULL, 0);
	}
	const char* nm;
	uint32_t nm_len;
	avm2_mn_name(act->file->data, mn_idx, &nm, &nm_len);
	E4XName name = e4x_name_from_rtns(ctx, ns_val, avm2_string_new(ctx, nm, nm_len),
	                                  mn_is_attribute_kind(act->file->data, mn_idx));
	return avm2_xml_descendants_value(ctx, v, &name);
}

Avm2Value avm2_op_getdescendants_rtns_l(Avm2Activation* act, Avm2Value v, uint32_t mn_idx,
                                        Avm2Value ns_val, Avm2Value name_val)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(v))
	{
		avm2_throw_null_or_undefined(ctx, v, NULL, 0);
	}
	const Avm2QNameExt* q = avm2_qname_ext_of(name_val);
	if (q != NULL)
	{
		E4XName name = e4x_name_from_qext(
			q, mn_is_attribute_kind(act->file->data, mn_idx));
		return avm2_xml_descendants_value(ctx, v, &name);
	}
	const Avm2String* s = avm2_coerce_to_string(ctx, name_val);
	E4XName name = e4x_name_from_rtns(ctx, ns_val, s,
	                                  mn_is_attribute_kind(act->file->data, mn_idx));
	return avm2_xml_descendants_value(ctx, v, &name);
}

Avm2Value avm2_op_checkfilter(Avm2Activation* act, Avm2Value v)
{
	Avm2Context* ctx = act->ctx;
	if (value_is_null_like(v))
	{
		avm2_throw_null_or_undefined(ctx, v, NULL, 0);
	}
	if (avm2_value_is_xmlish(v)) return v;
	char cn[160];
	class_name_of(ctx, v, cn, sizeof(cn));
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1123: Filter operator not supported on type %s.", cn);
}

void avm2_op_dxns(Avm2Activation* act, uint32_t str_idx)
{
	act->ctx->dxns = &act->file->data->strings[str_idx];
}

void avm2_op_dxnslate(Avm2Activation* act, Avm2Value v)
{
	Avm2Context* ctx = act->ctx;
	Avm2NamespaceExt* n = avm2_namespace_ext_of(v);
	ctx->dxns = (n != NULL) ? n->uri : avm2_coerce_to_string(ctx, v);
}
