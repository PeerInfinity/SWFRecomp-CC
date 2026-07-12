// Builtins + the definition domain (avm2-support-plan §4.5).
//
// Builtins register through the same vtable mechanism as SWF-defined
// classes (playerglobal-shaped binding surface). ES3-style methods
// (toString, hasOwnProperty, ...) live on the class prototype objects as
// dont-enum function-valued dynamic props, exactly where the proto-chain
// read path finds them.
//
// The domain mirrors Ruffle's Domain: FindPropStrict's last resort maps a
// definition name to the globals object defining it, running the defining
// script's initializer lazily on first touch. Builtins are seeded first,
// so parent-domain (playerglobal) definitions win over movie definitions,
// matching avmplus precedence.

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_e4x.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

void avm2_register_function_builtins(Avm2Context* ctx);

// ---------------------------------------------------------------------------
// Domain
// ---------------------------------------------------------------------------

void avm2_domain_add(Avm2Context* ctx, const Avm2PropKey* key,
                     Avm2AbcFileRt* file, uint32_t script_index)
{
	Avm2Domain* d = &ctx->domain;
	if (d->count == d->cap)
	{
		uint32_t new_cap = d->cap == 0 ? 16 : d->cap * 2;
		Avm2DomainEntry* grown = avm2_alloc(ctx, new_cap * sizeof(Avm2DomainEntry));
		if (d->count > 0)
		{
			memcpy(grown, d->entries, d->count * sizeof(Avm2DomainEntry));
		}
		d->entries = grown;
		d->cap = new_cap;
	}
	Avm2DomainEntry* e = &d->entries[d->count++];
	e->key = *key;
	e->file = file;
	e->script_index = script_index;
}

void avm2_script_ensure_init(Avm2AbcFileRt* file, uint32_t script_index)
{
	if (file->script_init_state[script_index] != AVM2_SCRIPT_UNINITIALIZED)
	{
		return;
	}
	file->script_init_state[script_index] = AVM2_SCRIPT_INITIALIZING;

	const Avm2AbcScriptData* sd = &file->data->scripts[script_index];
	const Avm2AbcMethodData* init = &file->data->methods[sd->init_method];
	Avm2MethodRef ref = { init->fn, file, init->debug_name, sd->init_method };
	avm2_call_method_ref(file->ctx, &ref, NULL, NULL,
	                     avm2_object_value(file->script_globals[script_index]),
	                     NULL, 0);

	file->script_init_state[script_index] = AVM2_SCRIPT_INITIALIZED;
}

Avm2Object* avm2_domain_find(Avm2Context* ctx, const Avm2PropKey* key)
{
	for (uint32_t i = 0; i < ctx->domain.count; i++)
	{
		Avm2DomainEntry* e = &ctx->domain.entries[i];
		if (!avm2_propkey_matches(&e->key, key)) continue;
		if (e->file == NULL)
		{
			return ctx->builtin_globals;
		}
		avm2_script_ensure_init(e->file, e->script_index);
		return e->file->script_globals[e->script_index];
	}
	return NULL;
}

// ---------------------------------------------------------------------------
// Builtin registration helpers
// ---------------------------------------------------------------------------

static Avm2PropKey builtin_key(const char* ns, const char* name)
{
	Avm2PropKey k;
	k.name = name;
	k.name_len = (uint32_t) strlen(name);
	k.ns_kind = 0x16;  // package
	k.ns_uri = ns;
	k.ns_len = (uint32_t) strlen(ns);
	return k;
}

// Define a value on the builtin globals object as a proper trait slot with
// its package-qualified key (dynamic props are public-only, so a
// package-qualified multiname like flash.display.MovieClip would never
// match one).
static void builtin_global_define(Avm2Context* ctx, Avm2PropKey key, Avm2Value value)
{
	Avm2Object* g = ctx->builtin_globals;
	Avm2VTable* vt = (Avm2VTable*) g->vtable;
	if (vt == NULL)
	{
		vt = avm2_alloc(ctx, sizeof(Avm2VTable));
		memset(vt, 0, sizeof(Avm2VTable));
		g->vtable = vt;
	}
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = key;
	e.kind = AVM2_PROP_SLOT;
	e.slot_index = vt->slot_count + 1;
	vt->slot_count++;
	avm2_vtable_append(ctx, vt, &e);

	if (vt->slot_count + 1 > g->slot_count)
	{
		uint32_t new_count = (vt->slot_count + 1) * 2;
		Avm2Value* grown = avm2_alloc(ctx, new_count * sizeof(Avm2Value));
		for (uint32_t i = 0; i < new_count; i++)
		{
			grown[i] = (i < g->slot_count) ? g->slots[i] : avm2_undefined();
		}
		g->slots = grown;
		g->slot_count = new_count;
	}
	g->slots[e.slot_index] = value;
}

// Expose a value on the builtin globals + domain under an arbitrary key
// (e.g. the package-internal Vector$int legacy aliases).
void avm2_builtin_define_alias(Avm2Context* ctx, Avm2PropKey key, Avm2Value value)
{
	builtin_global_define(ctx, key, value);
	avm2_domain_add(ctx, &key, NULL, 0);
}

Avm2Class* avm2_builtin_class(Avm2Context* ctx, const char* ns, const char* name,
                              Avm2Class* super)
{
	Avm2Class* cls = avm2_alloc(ctx, sizeof(Avm2Class));
	memset(cls, 0, sizeof(Avm2Class));
	cls->name = builtin_key(ns, name);
	cls->super_class = super;
	cls->instance_init.fn = NULL;    // no-op stub constructor
	cls->instance_init.file = NULL;
	cls->instance_init.debug_name = name;
	if (super != NULL)
	{
		cls->ivtable.slot_count = super->ivtable.slot_count;
		for (uint32_t i = 0; i < super->ivtable.count; i++)
		{
			avm2_vtable_append(ctx, &cls->ivtable, &super->ivtable.entries[i]);
		}
		cls->native_ext_size = super->native_ext_size;
		cls->native_init = super->native_init;
	}

	Avm2Object* cobj = avm2_object_alloc(ctx, AVM2_OBJ_CLASS, 1);
	cobj->class_ref = cls;
	cobj->cls = ctx->builtins.class_class;  // NULL while bootstrapping Object/Class
	if (ctx->builtins.class_class != NULL)
	{
		cobj->proto = ctx->builtins.class_class->prototype_obj;
	}
	cls->class_object = cobj;

	// Prototype object.
	Avm2Object* proto = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);
	proto->cls = ctx->builtins.object_class;  // may be NULL for Object itself
	if (super != NULL)
	{
		proto->proto = super->prototype_obj;
	}
	cls->prototype_obj = proto;
	Avm2DynProp* p = avm2_object_set_dynamic(ctx, proto, "constructor", 11,
	                                         avm2_object_value(cobj));
	p->dont_enum = 1;

	// Expose on the builtin globals object + in the domain.
	builtin_global_define(ctx, cls->name, avm2_object_value(cobj));
	avm2_domain_add(ctx, &cls->name, NULL, 0);
	return cls;
}

void avm2_builtin_add_method(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn fn)
{
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = builtin_key("", name);
	e.kind = AVM2_PROP_METHOD;
	e.method.fn = fn;
	e.method.file = NULL;
	e.method.debug_name = name;
	e.defining_class = cls;
	e.method_scope = NULL;
	avm2_vtable_append(ctx, &cls->ivtable, &e);
}

void avm2_builtin_add_getter(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn fn)
{
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = builtin_key("", name);
	e.kind = AVM2_PROP_GETTER;
	e.method.fn = fn;
	e.method.file = NULL;
	e.method.debug_name = name;
	e.defining_class = cls;
	avm2_vtable_append(ctx, &cls->ivtable, &e);
}

void avm2_builtin_add_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                             Avm2MethodFn getter, Avm2MethodFn setter)
{
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = builtin_key("", name);
	e.kind = (setter != NULL) ? AVM2_PROP_GETSET : AVM2_PROP_GETTER;
	// FP stack frames name accessors "get x"/"set x"
	// ("at flash.text::TextFormat/set display()" — textformat_display).
	size_t nlen = strlen(name);
	char* gname = avm2_alloc(ctx, nlen + 5);
	char* sname = avm2_alloc(ctx, nlen + 5);
	snprintf(gname, nlen + 5, "get %s", name);
	snprintf(sname, nlen + 5, "set %s", name);
	e.method.fn = getter;
	e.method.debug_name = gname;
	e.setter.fn = setter;
	e.setter.debug_name = sname;
	e.defining_class = cls;
	avm2_vtable_append(ctx, &cls->ivtable, &e);
}

// Class-object (static) members live on the class object's own vtable.
static Avm2VTable* class_static_vtable(Avm2Context* ctx, Avm2Class* cls)
{
	if (cls->class_object->vtable == NULL)
	{
		Avm2VTable* vt = avm2_alloc(ctx, sizeof(Avm2VTable));
		memset(vt, 0, sizeof(Avm2VTable));
		cls->class_object->vtable = vt;
	}
	return (Avm2VTable*) cls->class_object->vtable;
}

void avm2_builtin_add_static_method(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                    Avm2MethodFn fn)
{
	Avm2VTable* vt = class_static_vtable(ctx, cls);
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = builtin_key("", name);
	e.kind = AVM2_PROP_METHOD;
	e.method.fn = fn;
	e.method.debug_name = name;
	e.defining_class = cls;
	avm2_vtable_append(ctx, vt, &e);
}

void avm2_builtin_add_static_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                    Avm2MethodFn getter, Avm2MethodFn setter)
{
	Avm2VTable* vt = class_static_vtable(ctx, cls);
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = builtin_key("", name);
	e.kind = (setter != NULL) ? AVM2_PROP_GETSET : AVM2_PROP_GETTER;
	e.method.fn = getter;
	e.method.debug_name = name;
	e.setter.fn = setter;
	e.setter.debug_name = name;
	e.defining_class = cls;
	avm2_vtable_append(ctx, vt, &e);
}

void avm2_builtin_add_static_const(Avm2Context* ctx, Avm2Class* cls, const char* name,
                                   Avm2Value value)
{
	// Statics-as-slots would need slot storage; a dont-enum dynamic prop on
	// the class object gives identical read behavior.
	avm2_object_set_dynamic(ctx, cls->class_object, name,
	                        (uint32_t) strlen(name), value)->dont_enum = 1;
}

void avm2_proto_add_function(Avm2Context* ctx, Avm2Object* proto, const char* name,
                             Avm2MethodFn fn)
{
	Avm2MethodRef ref = { fn, NULL, name, 0 };
	Avm2Object* fnobj = avm2_function_new(ctx, &ref, NULL, NULL,
	                                      avm2_undefined(), false);
	avm2_object_set_dynamic(ctx, proto, name, (uint32_t) strlen(name),
	                        avm2_object_value(fnobj))->dont_enum = 1;
}

void avm2_builtin_add_global_fn(Avm2Context* ctx, const char* name, Avm2MethodFn fn)
{
	Avm2MethodRef ref = { fn, NULL, name, 0 };
	Avm2Object* fnobj = avm2_function_new(ctx, &ref, NULL, NULL,
	                                      avm2_object_value(ctx->builtin_globals), true);
	// The key points at the caller's literal, which is static — fine.
	Avm2PropKey key = builtin_key("", name);
	builtin_global_define(ctx, key, avm2_object_value(fnobj));
	avm2_domain_add(ctx, &key, NULL, 0);
}

// ---------------------------------------------------------------------------
// Object / Class builtins
// ---------------------------------------------------------------------------

static Avm2Value object_proto_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	char buf[160];
	if (act->this_val.kind == AVM2_VALUE_OBJECT
	    && act->this_val.u.obj->kind == AVM2_OBJ_CLASS)
	{
		// Ruffle's Object._toString reports class objects as [class N].
		Avm2Class* c = act->this_val.u.obj->class_ref;
		snprintf(buf, sizeof(buf), "[class %.*s]",
		         (int) c->name.name_len, c->name.name);
	}
	else if (act->this_val.kind == AVM2_VALUE_OBJECT
	         && act->this_val.u.obj->kind == AVM2_OBJ_FUNCTION)
	{
		snprintf(buf, sizeof(buf), "function Function() {}");
	}
	else if (act->this_val.kind == AVM2_VALUE_UNDEFINED
	         || act->this_val.kind == AVM2_VALUE_NULL)
	{
		snprintf(buf, sizeof(buf), "[object Object]");
	}
	else
	{
		Avm2Class* c = avm2_value_class(ctx, act->this_val);
		snprintf(buf, sizeof(buf), "[object %.*s]",
		         (int) c->name.name_len, c->name.name);
	}
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

static Avm2Value object_proto_value_of(Avm2Activation* act)
{
	return act->this_val;
}

static Avm2Value object_proto_to_locale_string(Avm2Activation* act)
{
	// avmplus Object.toLocaleString stringifies via Object.prototype's own
	// toString, NOT the receiver's (a primitive string yields
	// "[object String]" — array_tolocalestring).
	return object_proto_to_string(act);
}

static Avm2Value object_proto_has_own_property(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0) return avm2_bool(false);
	// The PROTOTYPE hasOwnProperty never consults a Proxy's hooks or its
	// traits — always false on Proxy receivers (proxy_hasproperty).
	if (act->this_val.kind == AVM2_VALUE_OBJECT
	    && avm2_is_proxy(act->this_val.u.obj))
	{
		return avm2_bool(false);
	}
	// NOTE: Dictionary object-space keys are invisible here — avmplus
	// hasOwnProperty stringifies its argument (dictionary_hasownproperty).
	const Avm2String* name = avm2_coerce_to_string(ctx, act->args[0]);
	return avm2_bool(avm2_has_own_public_property(ctx, act->this_val,
	                                              name->utf8, name->len) != 0);
}

// The AS3/public instance METHOD routes Proxy receivers to the hasProperty
// hook (proxy_hasownproperty), unlike the prototype function above.
static Avm2Value object_as3_has_own_property(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->this_val.kind == AVM2_VALUE_OBJECT
	    && avm2_is_proxy(act->this_val.u.obj))
	{
		Avm2Value arg = (act->argc > 0) ? act->args[0] : avm2_undefined();
		Avm2Value name = avm2_string(avm2_coerce_to_string(ctx, arg));
		Avm2Value v = avm2_proxy_call_hook(ctx, act->this_val.u.obj,
		                                   "hasProperty", &name, 1);
		return avm2_bool(avm2_coerce_to_boolean(v));
	}
	return object_proto_has_own_property(act);
}

static Avm2Value object_proto_is_prototype_of(Avm2Activation* act)
{
	if (act->argc == 0 || act->args[0].kind != AVM2_VALUE_OBJECT
	    || act->this_val.kind != AVM2_VALUE_OBJECT)
	{
		return avm2_bool(false);
	}
	for (Avm2Object* p = act->args[0].u.obj->proto; p != NULL; p = p->proto)
	{
		if (p == act->this_val.u.obj) return avm2_bool(true);
	}
	return avm2_bool(false);
}

static Avm2Value object_proto_property_is_enumerable(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0 || act->this_val.kind != AVM2_VALUE_OBJECT)
	{
		return avm2_bool(false);
	}
	const Avm2String* name = avm2_coerce_to_string(ctx, act->args[0]);
	Avm2Object* obj = act->this_val.u.obj;
	// Array index?
	if (obj->kind == AVM2_OBJ_ARRAY && name->len > 0 && name->len <= 10)
	{
		uint64_t idx = 0;
		int is_index = 1;
		for (uint32_t i = 0; i < name->len; i++)
		{
			if (name->utf8[i] < '0' || name->utf8[i] > '9') { is_index = 0; break; }
			idx = idx * 10 + (uint64_t) (name->utf8[i] - '0');
		}
		if (is_index && idx < 0xFFFFFFFFull)
		{
			Avm2Value v = avm2_array_get(obj, (uint32_t) idx);
			return avm2_bool(v.kind != AVM2_VALUE_HOLE);
		}
	}
	for (Avm2DynProp* p = obj->dyn_props; p != NULL; p = p->next)
	{
		if (p->name.len == name->len && memcmp(p->name.utf8, name->utf8, name->len) == 0)
		{
			return avm2_bool(!p->dont_enum);
		}
	}
	return avm2_bool(false);
}

static Avm2Value object_proto_set_property_is_enumerable(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc < 2 || act->this_val.kind != AVM2_VALUE_OBJECT)
	{
		return avm2_undefined();
	}
	// Dictionary: stringified properties are always enumerable — no-op
	// (Ruffle dictionary_object.rs set_local_property_is_enumerable).
	if (avm2_is_dictionary(act->this_val.u.obj))
	{
		return avm2_undefined();
	}
	const Avm2String* name = avm2_coerce_to_string(ctx, act->args[0]);
	bool enumerable = avm2_coerce_to_boolean(act->args[1]);
	Avm2Object* obj = act->this_val.u.obj;
	for (Avm2DynProp* p = obj->dyn_props; p != NULL; p = p->next)
	{
		if (p->name.len == name->len && memcmp(p->name.utf8, name->utf8, name->len) == 0)
		{
			p->dont_enum = enumerable ? 0 : 1;
		}
	}
	return avm2_undefined();
}

static Avm2Value object_construct(Avm2Context* ctx, Avm2Class* cls,
                                  const Avm2Value* args, uint32_t argc)
{
	(void) cls;
	if (argc > 0 && args[0].kind != AVM2_VALUE_UNDEFINED
	    && args[0].kind != AVM2_VALUE_NULL)
	{
		return args[0];
	}
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);
	obj->cls = ctx->builtins.object_class;
	obj->proto = ctx->builtins.object_class->prototype_obj;
	return avm2_object_value(obj);
}

static Avm2Value class_proto_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	char buf[160];
	if (act->this_val.kind == AVM2_VALUE_OBJECT
	    && act->this_val.u.obj->kind == AVM2_OBJ_CLASS)
	{
		Avm2Class* c = act->this_val.u.obj->class_ref;
		snprintf(buf, sizeof(buf), "[class %.*s]",
		         (int) c->name.name_len, c->name.name);
	}
	else
	{
		snprintf(buf, sizeof(buf), "[object Class]");
	}
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

static Avm2Value class_get_prototype(Avm2Activation* act)
{
	if (act->this_val.kind == AVM2_VALUE_OBJECT
	    && act->this_val.u.obj->kind == AVM2_OBJ_CLASS)
	{
		Avm2Object* proto = act->this_val.u.obj->class_ref->prototype_obj;
		if (proto != NULL) return avm2_object_value(proto);
	}
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// flash.display stub chain + trace
// ---------------------------------------------------------------------------

static Avm2Value native_trace(Avm2Activation* act)
{
	// Ruffle globals/toplevel.rs trace: join args with " ", newline-terminate.
	for (uint32_t i = 0; i < act->argc; i++)
	{
		if (i > 0) fputc(' ', stdout);
		const Avm2String* s = avm2_coerce_to_string(act->ctx, act->args[i]);
		// NUL bytes vanish from FP/Ruffle trace output.
		for (uint32_t j = 0; j < s->len; j++)
		{
			if (s->utf8[j] != '\0') fputc(s->utf8[j], stdout);
		}
	}
	fputc('\n', stdout);
	return avm2_undefined();
}

static Avm2Value point_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = act->this_val.u.obj;
	Avm2Value x = act->argc > 0
		? avm2_number(avm2_coerce_to_number(ctx, act->args[0])) : avm2_integer(0);
	Avm2Value y = act->argc > 1
		? avm2_number(avm2_coerce_to_number(ctx, act->args[1])) : avm2_integer(0);
	// x/y are proper SLOTS on a sealed class (AMF serializes Point as two
	// static trait props — bytearray_method_serialization's 25 bytes).
	if (self->slot_count > 2)
	{
		self->slots[1] = x;
		self->slots[2] = y;
	}
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// Toplevel functions
// ---------------------------------------------------------------------------

static Avm2Value global_is_nan(Avm2Activation* act)
{
	double d = act->argc > 0 ? avm2_coerce_to_number(act->ctx, act->args[0]) : NAN;
	return avm2_bool(isnan(d));
}

static Avm2Value global_is_finite(Avm2Activation* act)
{
	double d = act->argc > 0 ? avm2_coerce_to_number(act->ctx, act->args[0]) : NAN;
	return avm2_bool(isfinite(d) != 0);
}

static Avm2Value global_parse_int(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0) return avm2_number(NAN);
	const Avm2String* s = avm2_coerce_to_string(ctx, act->args[0]);
	int32_t radix = act->argc > 1 ? avm2_coerce_to_i32(ctx, act->args[1]) : 0;
	return avm2_number(avm2_string_to_int(s->utf8, s->len, radix, false));
}

static Avm2Value global_parse_float(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0) return avm2_number(NAN);
	const Avm2String* s = avm2_coerce_to_string(ctx, act->args[0]);
	double d;
	if (avm2_string_to_f64(s->utf8, s->len, false, &d))
	{
		return avm2_number(d);
	}
	return avm2_number(NAN);
}

// escape(): encode everything except [A-Za-z0-9 @-_.*+/] (Ruffle toplevel.rs).
static Avm2Value global_escape(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0)
	{
		return avm2_string(avm2_string_from_literal(ctx, "undefined"));
	}
	const Avm2String* s = avm2_coerce_to_string(ctx, act->args[0]);
	char* out = avm2_alloc(ctx, s->len * 3 + 1);
	uint32_t n = 0;
	for (uint32_t i = 0; i < s->len; i++)
	{
		unsigned char c = (unsigned char) s->utf8[i];
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		    || (c >= '0' && c <= '9')
		    || c == '@' || c == '-' || c == '_' || c == '.' || c == '*'
		    || c == '+' || c == '/')
		{
			out[n++] = (char) c;
		}
		else
		{
			n += (uint32_t) snprintf(out + n, 4, "%%%02X", c);
		}
	}
	return avm2_string(avm2_string_new(ctx, out, n));
}

static int hex_digit(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return -1;
}

static Avm2Value global_unescape(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0)
	{
		return avm2_string(avm2_string_from_literal(ctx, "undefined"));
	}
	const Avm2String* s = avm2_coerce_to_string(ctx, act->args[0]);
	char* out = avm2_alloc(ctx, s->len * 3 + 4);
	uint32_t n = 0;
	for (uint32_t i = 0; i < s->len; )
	{
		if (s->utf8[i] == '%' && i + 5 < s->len
		    && (s->utf8[i + 1] == 'u' || s->utf8[i + 1] == 'U')
		    && hex_digit(s->utf8[i + 2]) >= 0 && hex_digit(s->utf8[i + 3]) >= 0
		    && hex_digit(s->utf8[i + 4]) >= 0 && hex_digit(s->utf8[i + 5]) >= 0)
		{
			uint32_t cp = (uint32_t) ((hex_digit(s->utf8[i + 2]) << 12)
			              | (hex_digit(s->utf8[i + 3]) << 8)
			              | (hex_digit(s->utf8[i + 4]) << 4)
			              | hex_digit(s->utf8[i + 5]));
			// UTF-8 encode the BMP code point.
			if (cp < 0x80) out[n++] = (char) cp;
			else if (cp < 0x800)
			{
				out[n++] = (char) (0xC0 | (cp >> 6));
				out[n++] = (char) (0x80 | (cp & 0x3F));
			}
			else
			{
				out[n++] = (char) (0xE0 | (cp >> 12));
				out[n++] = (char) (0x80 | ((cp >> 6) & 0x3F));
				out[n++] = (char) (0x80 | (cp & 0x3F));
			}
			i += 6;
		}
		else if (s->utf8[i] == '%' && i + 2 < s->len
		         && hex_digit(s->utf8[i + 1]) >= 0 && hex_digit(s->utf8[i + 2]) >= 0)
		{
			unsigned char c = (unsigned char) ((hex_digit(s->utf8[i + 1]) << 4)
			                  | hex_digit(s->utf8[i + 2]));
			// Bytes >= 0x80 become Latin-1 code points → UTF-8.
			if (c < 0x80) out[n++] = (char) c;
			else
			{
				out[n++] = (char) (0xC0 | (c >> 6));
				out[n++] = (char) (0x80 | (c & 0x3F));
			}
			i += 3;
		}
		else
		{
			out[n++] = s->utf8[i];
			i++;
		}
	}
	return avm2_string(avm2_string_new(ctx, out, n));
}


// --- flash.utils.getQualifiedClassName / getDefinitionByName ---

// avmplus reports value classes: integral i32-representable numbers are
// "int" (the Integer/Number duality is observable here).
static Avm2Value global_get_qualified_class_name(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0)
	{
		return avm2_string(avm2_string_from_literal(ctx, "void"));
	}
	Avm2Value v = act->args[0];
	const char* simple = NULL;
	switch (v.kind)
	{
		case AVM2_VALUE_UNDEFINED: simple = "void"; break;
		case AVM2_VALUE_NULL: simple = "null"; break;
		case AVM2_VALUE_BOOL: simple = "Boolean"; break;
		case AVM2_VALUE_STRING: simple = "String"; break;
		case AVM2_VALUE_INTEGER:
			// avmplus atom-int range (Ruffle fits_in_value_integer_i32):
			// only 29-bit signed integers report as "int".
			simple = (v.u.i < (1 << 28) && v.u.i >= -(1 << 28)) ? "int" : "Number";
			break;
		case AVM2_VALUE_NUMBER:
		{
			int32_t i = (int32_t) v.u.d;
			simple = (v.u.d == (double) i && !(v.u.d == 0.0 && signbit(v.u.d))
			          && i < (1 << 28) && i >= -(1 << 28)) ? "int" : "Number";
			break;
		}
		default: break;
	}
	if (simple != NULL)
	{
		return avm2_string(avm2_string_from_literal(ctx, simple));
	}
	Avm2Class* cls = (v.u.obj->kind == AVM2_OBJ_CLASS)
		? v.u.obj->class_ref : avm2_value_class(ctx, v);
	char buf[256];
	if (cls->name.ns_len > 0)
	{
		snprintf(buf, sizeof(buf), "%.*s::%.*s",
		         (int) cls->name.ns_len, cls->name.ns_uri,
		         (int) cls->name.name_len, cls->name.name);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%.*s",
		         (int) cls->name.name_len, cls->name.name);
	}
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

// Splits "pkg::Name"/"pkg.Name"/"Name" into a public-package key.
static void definition_key_split(const char* s, uint32_t len, Avm2PropKey* key)
{
	key->ns_kind = 0x16;
	key->ns_uri = s;
	key->ns_len = 0;
	key->name = s;
	key->name_len = len;
	for (int64_t i = (int64_t) len - 1; i >= 0; i--)
	{
		if (s[i] == ':' || s[i] == '.')
		{
			uint32_t name_start = (uint32_t) i + 1;
			uint32_t ns_end = (uint32_t) i;
			if (s[i] == ':' && i > 0 && s[i - 1] == ':') ns_end--;
			key->name = s + name_start;
			key->name_len = len - name_start;
			key->ns_len = ns_end;
			break;
		}
	}
}

Avm2Value avm2_find_definition(Avm2Context* ctx, const char* s, uint32_t len,
                               int* found)
{
	*found = 0;
	// Vector.<...> names resolve to (and create on demand) the applied class
	// (avmplus behavior; the name embeds dots that would break the split).
	Avm2Class* vc = avm2_vector_class_by_name(ctx, s, len);
	if (vc != NULL)
	{
		*found = 1;
		return avm2_object_value(vc->class_object);
	}
	Avm2PropKey key;
	definition_key_split(s, len, &key);
	Avm2Object* g = avm2_domain_find(ctx, &key);
	if (g != NULL)
	{
		const Avm2PropEntry* e = avm2_vtable_find(g->vtable, &key);
		if (e != NULL && e->kind == AVM2_PROP_SLOT)
		{
			*found = 1;
			return g->slots[e->slot_index];
		}
		Avm2Value* dyn = avm2_object_find_dynamic(g, key.name, key.name_len);
		if (dyn != NULL)
		{
			*found = 1;
			return *dyn;
		}
	}
	return avm2_undefined();
}

_Noreturn static void throw_1065_for_definition(Avm2Context* ctx,
                                                const char* s, uint32_t len)
{
	Avm2PropKey key;
	definition_key_split(s, len, &key);
	avm2_throw_error(ctx, ctx->builtins.reference_error_class,
	                 "Error #1065: Variable %.*s is not defined.",
	                 (int) key.name_len, key.name);
}

static Avm2Value global_get_definition_by_name(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	const Avm2String* s = (act->argc > 0)
		? avm2_coerce_to_string(ctx, act->args[0])
		: avm2_string_from_literal(ctx, "");
	int found = 0;
	Avm2Value v = avm2_find_definition(ctx, s->utf8, s->len, &found);
	if (found) return v;
	throw_1065_for_definition(ctx, s->utf8, s->len);
}

// flash.utils.describeType: builds a real E4X <type> tree (Ruffle
// avmplus.as describeType over describeTypeJSON). Scope: attributes,
// the extendsClass chain, the constructor (signature from emitted class
// data when available; builtins report the avmplus 1-optional-* form),
// and Object's three AS3 instance methods (declaredBy Object). Trait
// enumeration for arbitrary classes is not modeled yet.
static void dt_set_attr(Avm2Context* ctx, E4XNode* elem, const char* name,
                        const char* value)
{
	E4XNode* a = avm2_e4x_attribute(ctx, NULL,
	                                avm2_string_from_literal(ctx, name),
	                                avm2_string_from_literal(ctx, value), elem);
	avm2_e4x_append_attribute(ctx, elem, a);
}

static E4XNode* dt_child(Avm2Context* ctx, E4XNode* parent, const char* name)
{
	E4XNode* e = avm2_e4x_element(ctx, NULL, avm2_string_from_literal(ctx, name),
	                              parent);
	avm2_e4x_insert_at(ctx, parent, parent->child_count, e);
	return e;
}

static void dt_param(Avm2Context* ctx, E4XNode* parent, int index,
                     const char* type, int optional)
{
	E4XNode* pe = dt_child(ctx, parent, "parameter");
	char ib[16];
	snprintf(ib, sizeof(ib), "%d", index);
	dt_set_attr(ctx, pe, "index", ib);
	dt_set_attr(ctx, pe, "type", type);
	dt_set_attr(ctx, pe, "optional", optional ? "true" : "false");
}

static Avm2Value global_get_qualified_superclass_name(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value v = (act->argc > 0) ? act->args[0] : avm2_undefined();
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		return avm2_null();
	}
	Avm2Class* cls;
	if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL
	    && v.u.obj->kind == AVM2_OBJ_CLASS)
	{
		cls = v.u.obj->class_ref;
	}
	else
	{
		cls = avm2_value_class(ctx, v);
	}
	if (cls == NULL || cls->super_class == NULL) return avm2_null();
	char buf[256];
	Avm2Class* sc = cls->super_class;
	if (sc->name.ns_len > 0)
	{
		snprintf(buf, sizeof(buf), "%.*s::%.*s",
		         (int) sc->name.ns_len, sc->name.ns_uri,
		         (int) sc->name.name_len, sc->name.name);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%.*s",
		         (int) sc->name.name_len, sc->name.name);
	}
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

static Avm2Value global_describe_type(Avm2Activation* act);

// flash.utils.describeType: throws 1010 on undefined (Ruffle
// flash/utils.as — avmplus raises it from the alias-lookup code), then
// delegates to the avmplus form.
static Avm2Value global_describe_type_utils(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0 || act->args[0].kind == AVM2_VALUE_UNDEFINED)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #1010: A term is undefined and has no "
		                 "properties.");
	}
	return global_describe_type(act);
}

static Avm2Value global_describe_type(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	E4XNode* type = avm2_e4x_element(ctx, NULL,
	                                 avm2_string_from_literal(ctx, "type"), NULL);
	if (act->argc == 0)
	{
		return avm2_object_value(avm2_xml_object_for_node(ctx, type));
	}
	Avm2Value v = act->args[0];
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		// describeType(null) / describeType(undefined) — null_void_types.
		dt_set_attr(ctx, type, "name",
		            v.kind == AVM2_VALUE_NULL ? "null" : "void");
		dt_set_attr(ctx, type, "isDynamic", "false");
		dt_set_attr(ctx, type, "isFinal", "true");
		dt_set_attr(ctx, type, "isStatic", "false");
		return avm2_object_value(avm2_xml_object_for_node(ctx, type));
	}
	int is_static = v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL
	                && v.u.obj->kind == AVM2_OBJ_CLASS;
	Avm2Class* cls;
	if (is_static)
	{
		cls = v.u.obj->class_ref;
	}
	else if (v.kind == AVM2_VALUE_INTEGER
	         && v.u.i < (1 << 28) && v.u.i >= -(1 << 28))
	{
		// avmplus atom-int range (same rule as getQualifiedClassName).
		cls = ctx->builtins.int_class;
	}
	else if (v.kind == AVM2_VALUE_NUMBER)
	{
		int32_t i = (int32_t) v.u.d;
		cls = (v.u.d == (double) i && !(v.u.d == 0.0 && signbit(v.u.d))
		       && i < (1 << 28) && i >= -(1 << 28))
			? ctx->builtins.int_class : ctx->builtins.number_class;
	}
	else
	{
		cls = avm2_value_class(ctx, v);
	}
	char nb[256];
	if (cls->name.ns_len > 0)
	{
		snprintf(nb, sizeof(nb), "%.*s::%.*s",
		         (int) cls->name.ns_len, cls->name.ns_uri,
		         (int) cls->name.name_len, cls->name.name);
	}
	else
	{
		snprintf(nb, sizeof(nb), "%.*s",
		         (int) cls->name.name_len, cls->name.name);
	}
	dt_set_attr(ctx, type, "name", nb);
	if (cls->super_class != NULL)
	{
		char bb[256];
		avm2_class_qname_buf(cls->super_class, bb, sizeof(bb));
		dt_set_attr(ctx, type, "base", bb);
	}
	dt_set_attr(ctx, type, "isDynamic",
	            (cls->flags & AVM2_CLASS_FLAG_SEALED) == 0 ? "true" : "false");
	dt_set_attr(ctx, type, "isFinal",
	            (cls->flags & AVM2_CLASS_FLAG_FINAL) != 0 ? "true" : "false");
	dt_set_attr(ctx, type, "isStatic", is_static ? "true" : "false");

	for (Avm2Class* b = cls->super_class; b != NULL; b = b->super_class)
	{
		char bb[256];
		avm2_class_qname_buf(b, bb, sizeof(bb));
		E4XNode* ec = dt_child(ctx, type, "extendsClass");
		dt_set_attr(ctx, ec, "type", bb);
	}

	if (cls != ctx->builtins.object_class)
	{
		E4XNode* ctor = dt_child(ctx, type, "constructor");
		const Avm2MethodRef* init = &cls->instance_init;
		if (init->file != NULL)
		{
			const Avm2AbcMethodData* m =
				&init->file->data->methods[init->method_index];
			for (uint32_t i = 0; i < m->param_count; i++)
			{
				char tb[256] = "*";
				uint32_t tmn = m->param_types[i];
				if (tmn != 0)
				{
					Avm2PropKey k;
					if (avm2_propkey_from_qname(init->file->data, tmn, &k))
					{
						if (k.ns_len > 0)
						{
							snprintf(tb, sizeof(tb), "%.*s::%.*s",
							         (int) k.ns_len, k.ns_uri,
							         (int) k.name_len, k.name);
						}
						else
						{
							snprintf(tb, sizeof(tb), "%.*s",
							         (int) k.name_len, k.name);
						}
					}
				}
				int opt = m->optionals != NULL && m->optionals[i].has_value;
				dt_param(ctx, ctor, (int) i + 1, tb, opt);
			}
		}
		else
		{
			// Builtin natives: the avmplus shell reports one optional-any
			// parameter (int/uint/Number/Boolean/String/Object family).
			dt_param(ctx, ctor, 1, "*", 1);
		}
		if (ctor->child_count == 0)
		{
			avm2_e4x_delete_by_index(type, (uint32_t) avm2_e4x_child_index(ctor));
		}
	}

	if (cls == ctx->builtins.object_class && !is_static)
	{
		static const char* const trio[3] = {
			"hasOwnProperty", "isPrototypeOf", "propertyIsEnumerable"
		};
		for (int i = 0; i < 3; i++)
		{
			E4XNode* me = dt_child(ctx, type, "method");
			dt_set_attr(ctx, me, "name", trio[i]);
			dt_set_attr(ctx, me, "declaredBy", "Object");
			dt_set_attr(ctx, me, "returnType", "Boolean");
			dt_param(ctx, me, 1, "*", 1);
			dt_set_attr(ctx, me, "uri", "http://adobe.com/AS3/2006/builtin");
		}
	}
	return avm2_object_value(avm2_xml_object_for_node(ctx, type));
}

// --- flash.system.ApplicationDomain (minimal: currentDomain +
// hasDefinition/getDefinition over the single global domain) ---

static Avm2Object* g_current_domain;

static Avm2Value appdomain_get_current(Avm2Activation* act)
{
	(void) act;
	return avm2_object_value(g_current_domain);
}

static Avm2Value appdomain_has_definition(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc == 0) return avm2_bool(false);
	const Avm2String* s = avm2_coerce_to_string(ctx, act->args[0]);
	int found = 0;
	avm2_find_definition(ctx, s->utf8, s->len, &found);
	return avm2_bool(found != 0);
}

static Avm2Value appdomain_get_definition(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	const Avm2String* s = (act->argc > 0)
		? avm2_coerce_to_string(ctx, act->args[0])
		: avm2_string_from_literal(ctx, "");
	int found = 0;
	Avm2Value v = avm2_find_definition(ctx, s->utf8, s->len, &found);
	if (found) return v;
	throw_1065_for_definition(ctx, s->utf8, s->len);
}

static Avm2Value system_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

// flash.system.System: gc/pauseForGCIfCollectionImminent no-ops (tests
// call System.gc() between phases; aborting there kills the frame script).
static void register_system(Avm2Context* ctx)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "flash.system", "System",
	                                    ctx->builtins.object_class);
	avm2_builtin_add_static_method(ctx, cls, "gc", system_noop);
	avm2_builtin_add_static_method(ctx, cls, "pauseForGCIfCollectionImminent",
	                               system_noop);
}

static void register_application_domain(Avm2Context* ctx)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "flash.system", "ApplicationDomain",
	                                    ctx->builtins.object_class);
	avm2_builtin_add_method(ctx, cls, "hasDefinition", appdomain_has_definition);
	avm2_builtin_add_method(ctx, cls, "getDefinition", appdomain_get_definition);
	g_current_domain = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 1);
	g_current_domain->cls = cls;
	g_current_domain->vtable = &cls->ivtable;
	g_current_domain->proto = cls->prototype_obj;
	// Static getter currentDomain on the class object.
	Avm2VTable* vt = class_static_vtable(ctx, cls);
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = avm2_public_key("currentDomain", 13);
	e.kind = AVM2_PROP_GETTER;
	e.method.fn = appdomain_get_current;
	e.method.debug_name = "get currentDomain";
	e.defining_class = cls;
	avm2_vtable_append(ctx, vt, &e);
}

// Register a toplevel native in a specific package namespace.
static void builtin_add_global_fn_ns(Avm2Context* ctx, const char* ns,
                                     const char* name, Avm2MethodFn fn)
{
	// Prebuild the FP stack-frame form ("global/flash.utils::name").
	char dbuf[160];
	snprintf(dbuf, sizeof(dbuf), "global/%s%s%s", ns, ns[0] ? "::" : "", name);
	char* dname = avm2_alloc(ctx, strlen(dbuf) + 1);
	strcpy(dname, dbuf);
	Avm2MethodRef ref = { fn, NULL, dname, 0 };
	Avm2Object* fnobj = avm2_function_new(ctx, &ref, NULL, NULL,
	                                      avm2_object_value(ctx->builtin_globals), true);
	Avm2PropKey key = builtin_key(ns, name);
	builtin_global_define(ctx, key, avm2_object_value(fnobj));
	avm2_domain_add(ctx, &key, NULL, 0);
}

void avm2_register_toplevel(Avm2Context* ctx)
{
	avm2_builtin_add_global_fn(ctx, "trace", native_trace);
	avm2_builtin_add_global_fn(ctx, "isNaN", global_is_nan);
	avm2_builtin_add_global_fn(ctx, "isFinite", global_is_finite);
	avm2_builtin_add_global_fn(ctx, "parseInt", global_parse_int);
	avm2_builtin_add_global_fn(ctx, "parseFloat", global_parse_float);
	avm2_builtin_add_global_fn(ctx, "escape", global_escape);
	avm2_builtin_add_global_fn(ctx, "unescape", global_unescape);
	builtin_add_global_fn_ns(ctx, "flash.utils", "getQualifiedClassName",
	                         global_get_qualified_class_name);
	builtin_add_global_fn_ns(ctx, "flash.utils", "getDefinitionByName",
	                         global_get_definition_by_name);
	// The avmplus shell exposes the same helpers in ns "avmplus"
	// (number_autoconv and friends are compiled against it).
	builtin_add_global_fn_ns(ctx, "avmplus", "getQualifiedClassName",
	                         global_get_qualified_class_name);
	builtin_add_global_fn_ns(ctx, "avmplus", "getDefinitionByName",
	                         global_get_definition_by_name);
	builtin_add_global_fn_ns(ctx, "flash.utils", "getQualifiedSuperclassName",
	                         global_get_qualified_superclass_name);
	builtin_add_global_fn_ns(ctx, "avmplus", "getQualifiedSuperclassName",
	                         global_get_qualified_superclass_name);
	builtin_add_global_fn_ns(ctx, "flash.utils", "describeType",
	                         global_describe_type_utils);
	builtin_add_global_fn_ns(ctx, "avmplus", "describeType",
	                         global_describe_type);
	// The avmplus describeTypeJSON flag constants (avmplus.as).
	{
		static const struct { const char* name; int32_t v; } dtflags[] = {
			{ "HIDE_NSURI_METHODS", 0x0001 }, { "INCLUDE_BASES", 0x0002 },
			{ "INCLUDE_INTERFACES", 0x0004 }, { "INCLUDE_VARIABLES", 0x0008 },
			{ "INCLUDE_ACCESSORS", 0x0010 }, { "INCLUDE_METHODS", 0x0020 },
			{ "INCLUDE_METADATA", 0x0040 }, { "INCLUDE_CONSTRUCTOR", 0x0080 },
			{ "INCLUDE_TRAITS", 0x0100 }, { "USE_ITRAITS", 0x0200 },
			{ "HIDE_OBJECT", 0x0400 }, { "FLASH10_FLAGS", 0x05FF },
		};
		for (size_t i = 0; i < sizeof(dtflags) / sizeof(dtflags[0]); i++)
		{
			avm2_builtin_define_alias(ctx, builtin_key("avmplus", dtflags[i].name),
			                          avm2_integer(dtflags[i].v));
		}
	}

	// Global constants.
	static const char* const_names[3] = { "NaN", "Infinity", "undefined" };
	Avm2Value const_vals[3];
	const_vals[0] = avm2_number(NAN);
	const_vals[1] = avm2_number(INFINITY);
	const_vals[2] = avm2_undefined();
	for (int i = 0; i < 3; i++)
	{
		Avm2PropKey key = builtin_key("", const_names[i]);
		builtin_global_define(ctx, key, const_vals[i]);
		avm2_domain_add(ctx, &key, NULL, 0);
	}
}

// ---------------------------------------------------------------------------
// Init
// ---------------------------------------------------------------------------

void avm2_globals_init(Avm2Context* ctx)
{
	ctx->builtin_globals = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);

	Avm2Builtins* b = &ctx->builtins;
	b->object_class = avm2_builtin_class(ctx, "", "Object", NULL);
	b->class_class = avm2_builtin_class(ctx, "", "Class", b->object_class);
	b->function_class = avm2_builtin_class(ctx, "", "Function", b->object_class);
	// Bootstrap fixups: objects made before Object/Class fully existed.
	b->object_class->class_object->cls = b->class_class;
	b->class_class->class_object->cls = b->class_class;
	b->function_class->class_object->cls = b->class_class;
	b->object_class->class_object->proto = b->class_class->prototype_obj;
	b->class_class->class_object->proto = b->class_class->prototype_obj;
	b->function_class->class_object->proto = b->class_class->prototype_obj;
	b->object_class->prototype_obj->cls = b->object_class;
	b->class_class->prototype_obj->cls = b->object_class;
	b->function_class->prototype_obj->cls = b->object_class;
	b->object_class->native_construct = object_construct;
	b->object_class->native_call = object_construct;

	// The hidden "global" class: global objects trace as [object global]
	// and never surface through the domain.
	{
		Avm2Class* gc = avm2_alloc(ctx, sizeof(Avm2Class));
		memset(gc, 0, sizeof(Avm2Class));
		gc->name = builtin_key("", "global");
		gc->super_class = b->object_class;
		b->global_class = gc;
	}
	ctx->builtin_globals->cls = b->global_class;
	ctx->builtin_globals->proto = b->object_class->prototype_obj;

	// Object.prototype methods.
	Avm2Object* oproto = b->object_class->prototype_obj;
	avm2_proto_add_function(ctx, oproto, "toString", object_proto_to_string);
	avm2_proto_add_function(ctx, oproto, "toLocaleString", object_proto_to_locale_string);
	avm2_proto_add_function(ctx, oproto, "valueOf", object_proto_value_of);
	avm2_proto_add_function(ctx, oproto, "hasOwnProperty", object_proto_has_own_property);
	avm2_proto_add_function(ctx, oproto, "isPrototypeOf", object_proto_is_prototype_of);
	avm2_proto_add_function(ctx, oproto, "propertyIsEnumerable",
	                        object_proto_property_is_enumerable);
	avm2_proto_add_function(ctx, oproto, "setPropertyIsEnumerable",
	                        object_proto_set_property_is_enumerable);
	// Instance-side mirrors (AS3 namespace methods surface publicly here).
	avm2_builtin_add_method(ctx, b->object_class, "hasOwnProperty",
	                        object_as3_has_own_property);
	avm2_builtin_add_method(ctx, b->object_class, "isPrototypeOf",
	                        object_proto_is_prototype_of);
	avm2_builtin_add_method(ctx, b->object_class, "propertyIsEnumerable",
	                        object_proto_property_is_enumerable);

	// Class.prototype.
	avm2_proto_add_function(ctx, b->class_class->prototype_obj, "toString",
	                        class_proto_to_string);
	avm2_builtin_add_getter(ctx, b->class_class, "prototype", class_get_prototype);

	// XML/XMLList: the E4X engine (avm2_xml.c / avm2_e4x.c).
	avm2_register_xml(ctx);
	// Date is a stub (upgraded by avm2_register_amf): exists so
	// `x as Date` / `is Date` type checks resolve.
	b->date_class = avm2_builtin_class(ctx, "", "Date", b->object_class);
	// flash.geom.Point minimal stub: constructible, x/y as expando props
	// (slots_force_autoassigned only needs the definition to exist).
	{
		Avm2Class* point = avm2_builtin_class(ctx, "flash.geom", "Point", b->object_class);
		point->flags |= AVM2_CLASS_FLAG_SEALED;
		point->instance_init.fn = point_init;
		point->instance_init.debug_name = "Point";
		static const char* const xy[2] = { "x", "y" };
		for (int i = 0; i < 2; i++)
		{
			Avm2PropEntry e;
			memset(&e, 0, sizeof(e));
			e.key = avm2_public_key(xy[i], 1);
			e.kind = AVM2_PROP_SLOT;
			e.slot_index = point->ivtable.slot_count + 1;
			e.defining_class = point;
			point->ivtable.slot_count++;
			avm2_vtable_append(ctx, &point->ivtable, &e);
		}
	}

	avm2_register_function_builtins(ctx);
	avm2_register_error(ctx);
	avm2_register_number(ctx);
	avm2_register_string(ctx);
	avm2_register_array(ctx);
	avm2_register_vector(ctx);
	avm2_register_regexp(ctx);
	avm2_register_nsqname(ctx);
	avm2_register_dictionary(ctx);
	avm2_register_proxy(ctx);
	avm2_register_bytearray(ctx);
	avm2_register_amf(ctx);
	// JSON is API-versioned (674 / FP11): invisible below SWF13
	// (json_version_gated expects 1065 in a SWF12 movie).
	if (ctx->swf_version >= 13)
	{
		avm2_register_json(ctx);
	}
	avm2_register_toplevel(ctx);
	register_application_domain(ctx);
	register_system(ctx);

	// flash.events (Event/EventDispatcher/EventPhase/IEventDispatcher —
	// avm2_events.c).
	avm2_register_events(ctx);

	// flash.text (avm2_text.c — Stage-6 TextFormat/TextField engine).
	// Before display: the TextField class shell wires into it.
	avm2_register_text(ctx);

	// flash.display (avm2_display.c — Stage-5 display tree).
	avm2_register_display(ctx);
}
