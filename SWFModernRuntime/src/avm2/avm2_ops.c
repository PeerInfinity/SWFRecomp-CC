// Opcode helpers backing the generated C in RecompiledABC/. Semantics per
// Ruffle core/src/avm2/ops (interpreter.rs / activation dispatch); Stage 2
// implements exactly what hello_world's 21-op surface needs, and every
// unsupported path aborts loudly (honest failure for the rest of the
// corpus).

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

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
	fflush(stdout);
	fprintf(stderr, "AVM2: unimplemented op %s at op index %u (Stage 2 supports "
	        "only hello_world's opcode surface; see avm2-support-plan.md Stage 3)\n",
	        op_name, op_index);
	exit(1);
}

_Noreturn void avm2_verify_error_body(Avm2Activation* act, const char* message)
{
	(void) act;
	fflush(stdout);
	fprintf(stderr, "AVM2: VerifyError body invoked: %s\n", message);
	exit(1);
}

void avm2_setup_locals(Avm2Value* loc, uint32_t num_locals, const Avm2Activation* act)
{
	if (num_locals == 0) return;
	loc[0] = act->this_val;
	for (uint32_t i = 1; i < num_locals; i++)
	{
		loc[i] = (i - 1 < act->argc) ? act->args[i - 1] : avm2_undefined();
	}
}

Avm2Object* avm2_op_pushscope(Avm2Activation* act, Avm2Value v)
{
	(void) act;
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL)
	{
		// TypeError 1009/1010 parity is Stage 3.
		avm2_fatal("PushScope on a non-object value (kind %u)", v.kind);
	}
	return v.u.obj;
}

// Resolve a static multiname on one object: flattened vtable, then dynamic
// props (name-only match — expando props are public; Stage 3 refines).
// Proto-chain walking is Stage 3.
typedef struct ResolveResult
{
	const Avm2PropEntry* entry;
	Avm2Value* dyn;
} ResolveResult;

static int object_resolve(const Avm2AbcFileData* data, Avm2Object* obj,
                          uint32_t mn_idx, ResolveResult* out)
{
	out->entry = NULL;
	out->dyn = NULL;
	if (obj->vtable != NULL)
	{
		for (uint32_t i = 0; i < obj->vtable->count; i++)
		{
			if (avm2_mn_match(data, mn_idx, &obj->vtable->entries[i].key))
			{
				out->entry = &obj->vtable->entries[i];
				return 1;
			}
		}
	}
	const char* name;
	uint32_t name_len;
	avm2_mn_name(data, mn_idx, &name, &name_len);
	out->dyn = avm2_object_find_dynamic(obj, name, name_len);
	return out->dyn != NULL;
}

Avm2Object* avm2_op_findpropstrict(Avm2Activation* act, Avm2Object* const* lscope,
                                   uint32_t scope_n, uint32_t mn_idx)
{
	const Avm2AbcFileData* data = act->file->data;
	ResolveResult r;

	// Local scope stack, top → bottom.
	for (uint32_t i = scope_n; i > 0; i--)
	{
		if (object_resolve(data, lscope[i - 1], mn_idx, &r)) return lscope[i - 1];
	}
	// Captured outer chain, top → bottom.
	if (act->outer != NULL)
	{
		for (uint32_t i = act->outer->count; i > 0; i--)
		{
			if (object_resolve(data, act->outer->objs[i - 1], mn_idx, &r))
			{
				return act->outer->objs[i - 1];
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
				Avm2Object* g = avm2_domain_find(act->ctx, &key);
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
				Avm2Object* g = avm2_domain_find(act->ctx, &key);
				if (g != NULL) return g;
			}
		}
	}

	const char* name;
	uint32_t name_len;
	avm2_mn_name(data, mn_idx, &name, &name_len);
	avm2_fatal("ReferenceError: Error #1065: Variable %.*s is not defined.",
	           (int) name_len, name);
}

// Bind a method trait into a fresh closure (GetProperty on a method trait).
static Avm2Value bind_method_entry(Avm2Context* ctx, const Avm2PropEntry* e, Avm2Value recv)
{
	Avm2Object* fnobj = avm2_object_alloc(ctx, AVM2_OBJ_FUNCTION, 0);
	fnobj->cls = ctx->builtins.function_class;
	fnobj->fn_method = e->method;
	fnobj->fn_receiver = recv;
	fnobj->fn_scope = e->method_scope;
	fnobj->fn_bound_class = e->defining_class;
	return avm2_object_value(fnobj);
}

static Avm2Object* require_object(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                  const char* op)
{
	if (recv.kind != AVM2_VALUE_OBJECT || recv.u.obj == NULL)
	{
		const char* name;
		uint32_t name_len;
		avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
		// Primitive receivers (String.length, ...) are Stage 3.
		avm2_fatal("%s '%.*s' on a non-object value (kind %u)",
		           op, (int) name_len, name, recv.kind);
	}
	return recv.u.obj;
}

Avm2Value avm2_op_getproperty_static(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx)
{
	Avm2Object* obj = require_object(act, recv, mn_idx, "GetProperty");
	ResolveResult r;
	if (!object_resolve(act->file->data, obj, mn_idx, &r))
	{
		const char* name;
		uint32_t name_len;
		avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
		avm2_fatal("ReferenceError: Error #1069: Property %.*s not found and "
		           "there is no default value.", (int) name_len, name);
	}
	if (r.dyn != NULL) return *r.dyn;
	switch (r.entry->kind)
	{
		case AVM2_PROP_SLOT:
			return obj->slots[r.entry->slot_index];
		case AVM2_PROP_METHOD:
			return bind_method_entry(act->ctx, r.entry, recv);
		default:
			// Getter dispatch is Stage 3.
			avm2_fatal("GetProperty on a getter/setter trait (Stage 3)");
	}
}

void avm2_op_initproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx, Avm2Value val)
{
	Avm2Object* obj = require_object(act, recv, mn_idx, "InitProperty");
	ResolveResult r;
	if (object_resolve(act->file->data, obj, mn_idx, &r))
	{
		if (r.dyn != NULL)
		{
			*r.dyn = val;
			return;
		}
		if (r.entry->kind == AVM2_PROP_SLOT)
		{
			obj->slots[r.entry->slot_index] = val;
			return;
		}
		avm2_fatal("InitProperty on a non-slot trait");
	}
	// No declared trait: define as a dynamic property.
	const char* name;
	uint32_t name_len;
	avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
	avm2_object_set_dynamic(act->ctx, obj, name, name_len, val);
}

Avm2Value avm2_op_callproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                               const Avm2Value* args, uint32_t argc)
{
	Avm2Object* obj = require_object(act, recv, mn_idx, "CallProperty");
	ResolveResult r;
	if (!object_resolve(act->file->data, obj, mn_idx, &r))
	{
		const char* name;
		uint32_t name_len;
		avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
		avm2_fatal("TypeError: Error #1006: %.*s is not a function.",
		           (int) name_len, name);
	}
	if (r.entry != NULL && r.entry->kind == AVM2_PROP_METHOD)
	{
		return avm2_call_method_ref(act->ctx, &r.entry->method,
		                            r.entry->defining_class, r.entry->method_scope,
		                            recv, args, argc);
	}
	// Slot / dynamic value: must hold a callable.
	Avm2Value v = (r.dyn != NULL) ? *r.dyn : obj->slots[r.entry->slot_index];
	if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL)
	{
		if (v.u.obj->kind == AVM2_OBJ_FUNCTION)
		{
			return avm2_call_function_obj(act->ctx, v.u.obj, args, argc);
		}
		if (v.u.obj->kind == AVM2_OBJ_CLASS)
		{
			// Calling a class = coercion (Stage 3).
			avm2_fatal("CallProperty on a class object (coercion call, Stage 3)");
		}
	}
	avm2_fatal("TypeError: Error #1006: value is not a function.");
}

Avm2Value avm2_op_constructprop(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                const Avm2Value* args, uint32_t argc)
{
	Avm2Value v = avm2_op_getproperty_static(act, recv, mn_idx);
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL
	    || v.u.obj->kind != AVM2_OBJ_CLASS)
	{
		const char* name;
		uint32_t name_len;
		avm2_mn_name(act->file->data, mn_idx, &name, &name_len);
		// Constructing plain functions is Stage 3.
		avm2_fatal("ConstructProp: %.*s is not a class", (int) name_len, name);
	}
	return avm2_class_construct(act->ctx, v.u.obj->class_ref, args, argc);
}

void avm2_op_constructsuper(Avm2Activation* act, Avm2Value recv,
                            const Avm2Value* args, uint32_t argc)
{
	if (act->bound_class == NULL || act->bound_class->super_class == NULL)
	{
		avm2_fatal("ConstructSuper outside a class constructor with a superclass");
	}
	Avm2Class* super = act->bound_class->super_class;
	avm2_call_method_ref(act->ctx, &super->instance_init, super, super->scope,
	                     recv, args, argc);
}

Avm2Value avm2_op_newclass(Avm2Activation* act, uint32_t class_idx, Avm2Value base,
                           Avm2Object* const* lscope, uint32_t scope_n)
{
	Avm2Class* super = NULL;
	if (base.kind == AVM2_VALUE_OBJECT && base.u.obj != NULL
	    && base.u.obj->kind == AVM2_OBJ_CLASS)
	{
		super = base.u.obj->class_ref;
	}
	else if (base.kind != AVM2_VALUE_NULL)
	{
		avm2_fatal("NewClass: base value is not a class (kind %u)", base.kind);
	}
	Avm2ScopeChain* scope = avm2_scope_capture(act->ctx, act->outer, lscope, scope_n);
	Avm2Class* cls = avm2_class_define(act->ctx, act->file, class_idx, super, scope);
	return avm2_object_value(cls->class_object);
}
