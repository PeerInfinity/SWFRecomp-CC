// Class realization, flattened vtables (Ruffle vtable.rs model), scope
// chains, and method invocation. SWF-defined classes are built by NewClass
// from the emitted static data; builtins (avm2_globals.c) register through
// the same vtable mechanism.

#include <stdio.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_ops.h>

uint8_t avm2_ns_fold(uint8_t kind)
{
	// Namespace (0x08) and Package (0x16) are both "public" (Ruffle
	// namespace.rs is_public folds them).
	return (kind == 0x08) ? 0x16 : kind;
}

int avm2_propkey_matches(const Avm2PropKey* a, const Avm2PropKey* b)
{
	if (a->name_len != b->name_len || a->ns_len != b->ns_len) return 0;
	if (avm2_ns_fold(a->ns_kind) != avm2_ns_fold(b->ns_kind)) return 0;
	if (memcmp(a->name, b->name, a->name_len) != 0) return 0;
	if (a->ns_len > 0 && memcmp(a->ns_uri, b->ns_uri, a->ns_len) != 0) return 0;
	return 1;
}

static void propkey_from_parts(const Avm2AbcFileData* data, uint32_t ns_idx,
                               uint32_t name_idx, Avm2PropKey* out)
{
	const Avm2AbcNamespace* ns = &data->namespaces[ns_idx];
	out->name = data->strings[name_idx].utf8;
	out->name_len = data->strings[name_idx].len;
	out->ns_kind = ns->kind;
	out->ns_uri = data->strings[ns->name].utf8;
	out->ns_len = data->strings[ns->name].len;
}

int avm2_propkey_from_qname(const Avm2AbcFileData* data, uint32_t mn_idx, Avm2PropKey* out)
{
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
	if (mn->kind != 0x07 && mn->kind != 0x0d) return 0;  // QName / QNameA only
	propkey_from_parts(data, mn->ns, mn->name, out);
	return 1;
}

void avm2_mn_name(const Avm2AbcFileData* data, uint32_t mn_idx,
                  const char** name, uint32_t* name_len)
{
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
	*name = data->strings[mn->name].utf8;
	*name_len = data->strings[mn->name].len;
}

int avm2_mn_match(const Avm2AbcFileData* data, uint32_t mn_idx, const Avm2PropKey* key)
{
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
	switch (mn->kind)
	{
		case 0x07:  // QName
		case 0x0d:  // QNameA
		{
			Avm2PropKey k;
			propkey_from_parts(data, mn->ns, mn->name, &k);
			return avm2_propkey_matches(&k, key);
		}
		case 0x09:  // Multiname (static name + ns set)
		case 0x0e:  // MultinameA
		{
			const Avm2String* name = &data->strings[mn->name];
			if (name->len != key->name_len
			    || memcmp(name->utf8, key->name, name->len) != 0)
			{
				return 0;
			}
			const Avm2AbcNsSet* set = &data->ns_sets[mn->ns_set];
			for (uint32_t i = 0; i < set->count; i++)
			{
				Avm2PropKey k;
				propkey_from_parts(data, set->ns_indices[i], mn->name, &k);
				if (avm2_propkey_matches(&k, key)) return 1;
			}
			return 0;
		}
		default:
			// Lazy (runtime) multinames never reach Stage-2 ops.
			return 0;
	}
}

// ---------------------------------------------------------------------------
// VTable
// ---------------------------------------------------------------------------

void avm2_vtable_append(Avm2Context* ctx, Avm2VTable* vt, const Avm2PropEntry* e)
{
	if (vt->count == vt->cap)
	{
		uint32_t new_cap = vt->cap == 0 ? 8 : vt->cap * 2;
		Avm2PropEntry* grown = avm2_alloc(ctx, new_cap * sizeof(Avm2PropEntry));
		if (vt->count > 0)
		{
			memcpy(grown, vt->entries, vt->count * sizeof(Avm2PropEntry));
		}
		vt->entries = grown;
		vt->cap = new_cap;
	}
	vt->entries[vt->count++] = *e;
}

const Avm2PropEntry* avm2_vtable_find(const Avm2VTable* vt, const Avm2PropKey* key)
{
	if (vt == NULL) return NULL;
	for (uint32_t i = 0; i < vt->count; i++)
	{
		if (avm2_propkey_matches(&vt->entries[i].key, key))
		{
			return &vt->entries[i];
		}
	}
	return NULL;
}

static Avm2PropEntry* vtable_find_mut(Avm2VTable* vt, const Avm2PropKey* key)
{
	for (uint32_t i = 0; i < vt->count; i++)
	{
		if (avm2_propkey_matches(&vt->entries[i].key, key))
		{
			return &vt->entries[i];
		}
	}
	return NULL;
}

void avm2_vtable_add_traits(Avm2Context* ctx, Avm2VTable* vt, Avm2AbcFileRt* file,
                            const Avm2AbcTrait* traits, uint32_t trait_count,
                            Avm2Class* defining_class, Avm2ScopeChain* scope)
{
	for (uint32_t i = 0; i < trait_count; i++)
	{
		const Avm2AbcTrait* t = &traits[i];
		Avm2PropEntry e;
		memset(&e, 0, sizeof(e));
		if (!avm2_propkey_from_qname(file->data, t->name_mn, &e.key))
		{
			avm2_fatal("AVM2: trait name multiname %u is not a QName", t->name_mn);
		}
		e.defining_class = defining_class;
		e.method_scope = scope;

		switch (t->kind)
		{
			case 0:  // Slot
			case 4:  // Class
			case 5:  // Function
			case 6:  // Const
			{
				e.kind = AVM2_PROP_SLOT;
				uint32_t slot_id = t->slot_or_disp_id;
				if (slot_id == 0)
				{
					slot_id = vt->slot_count + 1;  // auto-assign
				}
				e.slot_index = slot_id;
				if (slot_id > vt->slot_count) vt->slot_count = slot_id;
				break;
			}
			case 1:  // Method
			case 2:  // Getter
			case 3:  // Setter
			{
				e.kind = (t->kind == 1) ? AVM2_PROP_METHOD
				       : (t->kind == 2) ? AVM2_PROP_GETTER : AVM2_PROP_SETTER;
				const Avm2AbcMethodData* m = &file->data->methods[t->method_or_class];
				e.method.fn = m->fn;
				e.method.file = file;
				e.method.debug_name = m->debug_name;
				break;
			}
			default:
				avm2_fatal("AVM2: unknown trait kind %u", t->kind);
		}

		// Overrides replace the inherited entry (parent disp/slot reuse is
		// a Stage 3 concern; Stage 2 keeps lookup-by-name semantics).
		Avm2PropEntry* existing = vtable_find_mut(vt, &e.key);
		if (existing != NULL)
		{
			if (e.kind == AVM2_PROP_SLOT)
			{
				e.slot_index = existing->slot_index;
			}
			*existing = e;
		}
		else
		{
			avm2_vtable_append(ctx, vt, &e);
		}
	}
}

// ---------------------------------------------------------------------------
// Scope chains
// ---------------------------------------------------------------------------

Avm2ScopeChain* avm2_scope_capture(Avm2Context* ctx, const Avm2ScopeChain* outer,
                                   Avm2Object* const* lscope, uint32_t scope_n)
{
	uint32_t outer_n = (outer != NULL) ? outer->count : 0;
	Avm2ScopeChain* chain = avm2_alloc(ctx, sizeof(Avm2ScopeChain));
	chain->count = outer_n + scope_n;
	chain->objs = NULL;
	if (chain->count > 0)
	{
		chain->objs = avm2_alloc(ctx, chain->count * sizeof(Avm2Object*));
		for (uint32_t i = 0; i < outer_n; i++) chain->objs[i] = outer->objs[i];
		for (uint32_t i = 0; i < scope_n; i++) chain->objs[outer_n + i] = lscope[i];
	}
	return chain;
}

// ---------------------------------------------------------------------------
// Invocation
// ---------------------------------------------------------------------------

Avm2Value avm2_call_method_ref(Avm2Context* ctx, const Avm2MethodRef* m,
                               Avm2Class* bound_class, Avm2ScopeChain* outer,
                               Avm2Value this_val, const Avm2Value* args, uint32_t argc)
{
	if (m->fn == NULL)
	{
		if (m->file == NULL)
		{
			// Builtin stub with no native body (e.g. Object/Sprite
			// constructors) — deliberate no-op.
			return avm2_undefined();
		}
		avm2_fatal("AVM2: call to method '%s' with no body",
		           m->debug_name ? m->debug_name : "<anon>");
	}
	Avm2Activation act;
	act.ctx = ctx;
	act.file = m->file;
	act.bound_class = bound_class;
	act.outer = outer;
	act.this_val = this_val;
	act.args = args;
	act.argc = argc;
	return m->fn(&act);
}

Avm2Value avm2_call_function_obj(Avm2Context* ctx, Avm2Object* fnobj,
                                 const Avm2Value* args, uint32_t argc)
{
	if (fnobj == NULL || fnobj->kind != AVM2_OBJ_FUNCTION)
	{
		avm2_fatal("AVM2: call to a non-function value");
	}
	return avm2_call_method_ref(ctx, &fnobj->fn_method, fnobj->fn_bound_class,
	                            fnobj->fn_scope, fnobj->fn_receiver, args, argc);
}

// ---------------------------------------------------------------------------
// Class definition + construction
// ---------------------------------------------------------------------------

Avm2Class* avm2_class_define(Avm2Context* ctx, Avm2AbcFileRt* file, uint32_t class_idx,
                             Avm2Class* super_class, Avm2ScopeChain* scope)
{
	const Avm2AbcClassData* cd = &file->data->classes[class_idx];

	Avm2Class* cls = avm2_alloc(ctx, sizeof(Avm2Class));
	memset(cls, 0, sizeof(Avm2Class));
	if (!avm2_propkey_from_qname(file->data, cd->name_mn, &cls->name))
	{
		avm2_fatal("AVM2: class name multiname %u is not a QName", cd->name_mn);
	}
	cls->super_class = super_class;
	cls->flags = cd->flags;
	cls->scope = scope;

	const Avm2AbcMethodData* iinit = &file->data->methods[cd->instance_init];
	cls->instance_init.fn = iinit->fn;
	cls->instance_init.file = file;
	cls->instance_init.debug_name = iinit->debug_name;

	// Inherit the flattened instance vtable, then append own traits
	// (vtable.rs model).
	if (super_class != NULL)
	{
		cls->ivtable.slot_count = super_class->ivtable.slot_count;
		for (uint32_t i = 0; i < super_class->ivtable.count; i++)
		{
			avm2_vtable_append(ctx, &cls->ivtable, &super_class->ivtable.entries[i]);
		}
		cls->native_ext_size = super_class->native_ext_size;
		cls->native_init = super_class->native_init;
	}
	avm2_vtable_add_traits(ctx, &cls->ivtable, file,
	                       cd->instance_traits, cd->instance_trait_count, cls, scope);

	// Class object: holds the static (class) traits.
	Avm2VTable* cvt = avm2_alloc(ctx, sizeof(Avm2VTable));
	memset(cvt, 0, sizeof(Avm2VTable));
	avm2_vtable_add_traits(ctx, cvt, file, cd->class_traits, cd->class_trait_count,
	                       cls, scope);
	Avm2Object* cobj = avm2_object_alloc(ctx, AVM2_OBJ_CLASS, cvt->slot_count + 1);
	cobj->vtable = cvt;
	cobj->class_ref = cls;
	cobj->cls = ctx->builtins.class_class;
	cls->class_object = cobj;

	// Run the static initializer now (Ruffle runs it during NewClass).
	const Avm2AbcMethodData* cinit = &file->data->methods[cd->class_init];
	Avm2MethodRef cinit_ref = { cinit->fn, file, cinit->debug_name };
	avm2_call_method_ref(ctx, &cinit_ref, cls, scope,
	                     avm2_object_value(cobj), NULL, 0);

	file->classes[class_idx] = cls;
	return cls;
}

Avm2Value avm2_class_construct(Avm2Context* ctx, Avm2Class* cls,
                               const Avm2Value* args, uint32_t argc)
{
	if (cls->flags & AVM2_CLASS_FLAG_INTERFACE)
	{
		avm2_fatal("AVM2: cannot construct interface %.*s",
		           (int) cls->name.name_len, cls->name.name);
	}
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, cls->ivtable.slot_count + 1);
	obj->cls = cls;
	obj->vtable = &cls->ivtable;
	if (cls->native_ext_size > 0)
	{
		obj->native_ext = avm2_alloc(ctx, cls->native_ext_size);
		memset(obj->native_ext, 0, cls->native_ext_size);
	}
	if (cls->native_init != NULL)
	{
		cls->native_init(ctx, obj);
	}
	Avm2Value this_val = avm2_object_value(obj);
	avm2_call_method_ref(ctx, &cls->instance_init, cls, cls->scope,
	                     this_val, args, argc);
	return this_val;
}
