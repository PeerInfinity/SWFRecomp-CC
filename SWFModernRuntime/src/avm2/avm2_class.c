// Class realization, flattened vtables (Ruffle vtable.rs model), scope
// chains, method invocation, type checks, and function objects. SWF-defined
// classes are built by NewClass from the emitted static data; builtins
// (avm2_globals.c and friends) register through the same vtable mechanism.

#include <stdio.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

int avm2_class_qname_buf(const Avm2Class* cls, char* buf, int size)
{
	if (cls == NULL)
	{
		return snprintf(buf, size, "Object");
	}
	if (cls->name.ns_len > 0)
	{
		return snprintf(buf, size, "%.*s.%.*s",
		                (int) cls->name.ns_len, cls->name.ns_uri,
		                (int) cls->name.name_len, cls->name.name);
	}
	return snprintf(buf, size, "%.*s", (int) cls->name.name_len, cls->name.name);
}

uint8_t avm2_ns_fold(uint8_t kind)
{
	// Namespace (0x08) and Package (0x16) are both "public" (Ruffle
	// namespace.rs is_public folds them).
	return (kind == 0x08) ? 0x16 : kind;
}

// The AS3 builtin namespace: methods invoked as obj.AS3::meth() by
// strict-mode compilers. Our builtins register public keys only, so both
// fold to public for matching purposes.
static const char AS3_NS[] = "http://adobe.com/AS3/2006/builtin";

static int key_ns_is_public(uint8_t folded_kind, const char* uri, uint32_t len)
{
	if (folded_kind != 0x16) return 0;
	if (len == 0) return 1;
	return len == sizeof(AS3_NS) - 1 && memcmp(uri, AS3_NS, len) == 0;
}

int avm2_propkey_is_public(const Avm2PropKey* k)
{
	// STRICT: kind public with an empty URI. (The AS3 builtin ns unifies
	// with public only inside propkey_matches, for method dispatch.)
	return avm2_ns_fold(k->ns_kind) == 0x16 && k->ns_len == 0;
}

Avm2PropKey avm2_public_key(const char* name, uint32_t name_len)
{
	Avm2PropKey k;
	k.name = name;
	k.name_len = name_len;
	k.ns_kind = 0x16;
	k.ns_uri = "";
	k.ns_len = 0;
	return k;
}

int avm2_propkey_matches(const Avm2PropKey* a, const Avm2PropKey* b)
{
	if (a->name_len != b->name_len) return 0;
	if (memcmp(a->name, b->name, a->name_len) != 0) return 0;
	uint8_t ka = avm2_ns_fold(a->ns_kind);
	uint8_t kb = avm2_ns_fold(b->ns_kind);
	// AS3-builtin ns unifies with public (both directions).
	int pa = key_ns_is_public(ka, a->ns_uri, a->ns_len);
	int pb = key_ns_is_public(kb, b->ns_uri, b->ns_len);
	if (pa || pb) return pa && pb;
	if (ka != kb) return 0;
	if (a->ns_len != b->ns_len) return 0;
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
	if (mn->kind == 0x07 || mn->kind == 0x0d)  // QName / QNameA
	{
		propkey_from_parts(data, mn->ns, mn->name, out);
		return 1;
	}
	if (mn->kind == 0x09 || mn->kind == 0x0e)  // Multiname with a 1-ns set
	{
		const Avm2AbcNsSet* set = &data->ns_sets[mn->ns_set];
		if (set->count == 1)
		{
			propkey_from_parts(data, set->ns_indices[0], mn->name, out);
			return 1;
		}
	}
	return 0;
}

void avm2_mn_name(const Avm2AbcFileData* data, uint32_t mn_idx,
                  const char** name, uint32_t* name_len)
{
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
	*name = data->strings[mn->name].utf8;
	*name_len = data->strings[mn->name].len;
}

int avm2_mn_has_public_ns(const Avm2AbcFileData* data, uint32_t mn_idx)
{
	// STRICT publicness (empty-URI Namespace/Package): the AS3 builtin ns
	// does NOT enable dynamic-property access (array_access_interpreter's
	// JIT probe expects 1081 with an AS3-only ns set).
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
	switch (mn->kind)
	{
		case 0x07:
		case 0x0d:
		{
			const Avm2AbcNamespace* ns = &data->namespaces[mn->ns];
			return avm2_ns_fold(ns->kind) == 0x16
			       && data->strings[ns->name].len == 0;
		}
		case 0x09:
		case 0x0e:
		case 0x1b:
		case 0x1c:
		{
			const Avm2AbcNsSet* set = &data->ns_sets[mn->ns_set];
			for (uint32_t i = 0; i < set->count; i++)
			{
				const Avm2AbcNamespace* ns = &data->namespaces[set->ns_indices[i]];
				if (avm2_ns_fold(ns->kind) == 0x16
				    && data->strings[ns->name].len == 0)
				{
					return 1;
				}
			}
			return 0;
		}
		default:
			// Lazy-name kinds without a set: RTQName* — treat as public.
			return 1;
	}
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
			// Lazy (runtime) multinames are resolved by the *_dyn op
			// helpers before matching.
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

const Avm2PropEntry* avm2_vtable_find_mn(const Avm2VTable* vt, const Avm2AbcFileData* data,
                                         uint32_t mn_idx)
{
	if (vt == NULL) return NULL;
	for (uint32_t i = 0; i < vt->count; i++)
	{
		if (avm2_mn_match(data, mn_idx, &vt->entries[i].key))
		{
			return &vt->entries[i];
		}
	}
	return NULL;
}

const Avm2PropEntry* avm2_vtable_find_public(const Avm2VTable* vt,
                                             const char* name, uint32_t name_len)
{
	if (vt == NULL) return NULL;
	for (uint32_t i = 0; i < vt->count; i++)
	{
		const Avm2PropEntry* e = &vt->entries[i];
		if (e->key.name_len == name_len
		    && memcmp(e->key.name, name, name_len) == 0
		    && avm2_propkey_is_public(&e->key))
		{
			return e;
		}
	}
	return NULL;
}

const Avm2PropEntry* avm2_vtable_find_mn_named(const Avm2VTable* vt,
                                               const Avm2AbcFileData* data,
                                               uint32_t mn_idx,
                                               const char* name, uint32_t name_len)
{
	if (vt == NULL) return NULL;
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];
	uint32_t single_ns = 0;
	const Avm2AbcNsSet* set = NULL;
	switch (mn->kind)
	{
		case 0x1b: case 0x1c:  // MultinameL / MultinameLA
			set = &data->ns_sets[mn->ns_set];
			break;
		case 0x07: case 0x0d:  // QName kinds (name replaced at runtime)
			single_ns = mn->ns;
			break;
		default:
			return NULL;
	}
	uint32_t count = (set != NULL) ? set->count : 1;
	for (uint32_t i = 0; i < count; i++)
	{
		uint32_t ns_idx = (set != NULL) ? set->ns_indices[i] : single_ns;
		const Avm2AbcNamespace* ns = &data->namespaces[ns_idx];
		Avm2PropKey key;
		key.name = name;
		key.name_len = name_len;
		key.ns_kind = ns->kind;
		key.ns_uri = data->strings[ns->name].utf8;
		key.ns_len = data->strings[ns->name].len;
		const Avm2PropEntry* e = avm2_vtable_find(vt, &key);
		if (e != NULL) return e;
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

// Record slot metadata for slot id `idx` (grows the table).
static void vtable_set_slot_meta(Avm2Context* ctx, Avm2VTable* vt, uint32_t idx,
                                 const Avm2SlotMeta* meta)
{
	if (idx >= vt->meta_cap)
	{
		uint32_t new_cap = vt->meta_cap == 0 ? 8 : vt->meta_cap;
		while (new_cap <= idx) new_cap *= 2;
		Avm2SlotMeta* grown = avm2_alloc(ctx, new_cap * sizeof(Avm2SlotMeta));
		memset(grown, 0, new_cap * sizeof(Avm2SlotMeta));
		if (vt->meta_cap > 0)
		{
			memcpy(grown, vt->metas, vt->meta_cap * sizeof(Avm2SlotMeta));
		}
		vt->metas = grown;
		vt->meta_cap = new_cap;
	}
	vt->metas[idx] = *meta;
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
				e.is_const = (t->kind == 6);
				uint32_t slot_id = t->slot_or_disp_id;
				if (slot_id == 0)
				{
					slot_id = vt->slot_count + 1;  // auto-assign
				}
				e.slot_index = slot_id;
				e.type_mn = t->type_mn;
				e.type_file = file;
				e.value = t->value;
				{
					Avm2SlotMeta meta;
					memset(&meta, 0, sizeof(meta));
					meta.used = 1;
					meta.type_mn = t->type_mn;
					meta.type_file = file;
					meta.value = t->value;
					meta.defining_class = defining_class;
					meta.method_scope = scope;
					if (t->kind == 5)
					{
						const Avm2AbcMethodData* fm = &file->data->methods[t->method_or_class];
						meta.is_function_trait = 1;
						meta.fn_method.fn = fm->fn;
						meta.fn_method.file = file;
						meta.fn_method.debug_name = fm->debug_name;
						meta.fn_method.method_index = t->method_or_class;
					}
					vtable_set_slot_meta(ctx, vt, slot_id, &meta);
				}
				if (t->kind == 5)
				{
					// Function trait: the slot's default is a closure over
					// the entry's scope (realized in slots_init_defaults).
					const Avm2AbcMethodData* m = &file->data->methods[t->method_or_class];
					e.is_function_trait = 1;
					e.method.fn = m->fn;
					e.method.file = file;
					e.method.debug_name = m->debug_name;
					e.method.method_index = t->method_or_class;
				}
				if (slot_id > vt->slot_count) vt->slot_count = slot_id;
				break;
			}
			case 1:  // Method
			case 2:  // Getter
			case 3:  // Setter
			{
				const Avm2AbcMethodData* m = &file->data->methods[t->method_or_class];
				Avm2MethodRef ref;
				ref.fn = m->fn;
				ref.file = file;
				ref.debug_name = m->debug_name;
				ref.method_index = t->method_or_class;

				Avm2PropEntry* existing = vtable_find_mut(vt, &e.key);
				if (t->kind == 1)
				{
					e.kind = AVM2_PROP_METHOD;
					e.method = ref;
				}
				else if (t->kind == 2)
				{
					// Merge with an inherited/sibling setter.
					if (existing != NULL && (existing->kind == AVM2_PROP_SETTER
					                         || existing->kind == AVM2_PROP_GETSET))
					{
						existing->kind = AVM2_PROP_GETSET;
						existing->method = ref;
						existing->defining_class = defining_class;
						existing->method_scope = scope;
						continue;
					}
					e.kind = AVM2_PROP_GETTER;
					e.method = ref;
				}
				else
				{
					if (existing != NULL && (existing->kind == AVM2_PROP_GETTER
					                         || existing->kind == AVM2_PROP_GETSET))
					{
						existing->kind = AVM2_PROP_GETSET;
						existing->setter = ref;
						continue;
					}
					e.kind = AVM2_PROP_SETTER;
					e.setter = ref;
				}
				break;
			}
			default:
				avm2_fatal("AVM2: unknown trait kind %u", t->kind);
		}

		// Overrides replace the inherited entry, keeping the parent's slot
		// index (slot_disp_id_shared_numbering).
		Avm2PropEntry* existing = vtable_find_mut(vt, &e.key);
		if (existing != NULL)
		{
			// NOTE: a redeclared var/const/class slot keeps its NEW slot
			// index (Ruffle vtable.rs always appends) — the parent's slot
			// storage survives for GetSuper/SetSuper shadowing
			// (class_supercalls_errors).
			Avm2PropEntry old = *existing;
			Avm2PropKey saved_key = existing->key;
			*existing = e;
			existing->key = saved_key;
			// Protected/interface members are aliased under other
			// namespaces (ancestor protected ns, interface ns); an
			// override must update every alias that shared the old
			// implementation.
			for (uint32_t j = 0; j < vt->count; j++)
			{
				Avm2PropEntry* o = &vt->entries[j];
				if (o == existing) continue;
				if (o->key.name_len != e.key.name_len) continue;
				if (memcmp(o->key.name, e.key.name, e.key.name_len) != 0) continue;
				if (o->kind != old.kind) continue;
				if (o->method.fn == old.method.fn
				    && o->method.file == old.method.file
				    && o->setter.fn == old.setter.fn)
				{
					Avm2PropKey k2 = o->key;
					*o = e;
					o->key = k2;
				}
			}
		}
		else
		{
			avm2_vtable_append(ctx, vt, &e);
		}
	}
}

// Slot defaults: trait value if present, else the type's default.
static Avm2Value slot_type_default(Avm2Context* ctx, const Avm2PropEntry* e)
{
	if (e->type_mn == 0 || e->type_file == NULL)
	{
		return avm2_undefined();
	}
	const char* tn;
	uint32_t tn_len;
	avm2_mn_name(e->type_file->data, e->type_mn, &tn, &tn_len);
	if (tn_len == 3 && memcmp(tn, "int", 3) == 0) return avm2_integer(0);
	if (tn_len == 4 && memcmp(tn, "uint", 4) == 0) return avm2_integer(0);
	if (tn_len == 6 && memcmp(tn, "Number", 6) == 0) return avm2_number(__builtin_nan(""));
	if (tn_len == 7 && memcmp(tn, "Boolean", 7) == 0) return avm2_bool(false);
	if (tn_len == 1 && tn[0] == '*') return avm2_undefined();
	return avm2_null();
}

Avm2Value avm2_default_value(Avm2Context* ctx, Avm2AbcFileRt* file, const Avm2AbcDefault* d)
{
	const Avm2AbcFileData* data = file->data;
	switch (d->kind)
	{
		case 0x01: return avm2_string(&data->strings[d->index]);
		case 0x03: return avm2_integer(data->ints[d->index]);
		case 0x04: return avm2_uint_value(data->uints[d->index]);
		case 0x06: return avm2_number(data->doubles[d->index]);
		case 0x0a: return avm2_bool(false);
		case 0x0b: return avm2_bool(true);
		case 0x0c: return avm2_null();
		case 0x00: return avm2_undefined();
		// Namespace kinds (`namespace n = "uri"` consts): box the pool
		// namespace as a Namespace object.
		case 0x05: case 0x08: case 0x16: case 0x17: case 0x18: case 0x19:
		case 0x1a:
			return avm2_object_value(avm2_namespace_from_pool(ctx, file, d->index));
		default:
			return avm2_undefined();
	}
}

void avm2_slots_init_defaults(Avm2Context* ctx, Avm2Object* obj, const Avm2VTable* vt)
{
	if (vt == NULL) return;
	// The slot-meta table covers every slot ever allocated, including
	// parent slots shadowed by a subclass redeclaration.
	for (uint32_t s = 1; s <= vt->slot_count && s < obj->slot_count; s++)
	{
		if (s >= vt->meta_cap || !vt->metas[s].used) continue;
		const Avm2SlotMeta* m = &vt->metas[s];
		if (m->value.has_value && m->type_file != NULL)
		{
			Avm2Value dv = avm2_default_value(ctx, m->type_file, &m->value);
			// Coerce the constant to the slot's declared type (int slots
			// with a double initializer, etc.).
			if (m->type_mn != 0)
			{
				dv = avm2_coerce_to_type_mn(ctx, m->type_file, m->type_mn, dv);
			}
			obj->slots[s] = dv;
		}
		else if (m->is_function_trait)
		{
			obj->slots[s] = avm2_object_value(
				avm2_function_new(ctx, &m->fn_method, m->defining_class,
				                  m->method_scope, avm2_undefined(), false));
		}
		else if (m->type_mn != 0 && m->type_file != NULL)
		{
			Avm2PropEntry tmp;
			memset(&tmp, 0, sizeof(tmp));
			tmp.type_mn = m->type_mn;
			tmp.type_file = m->type_file;
			obj->slots[s] = slot_type_default(ctx, &tmp);
		}
		else
		{
			obj->slots[s] = avm2_undefined();
		}
	}
}

// ---------------------------------------------------------------------------
// Scope chains
// ---------------------------------------------------------------------------

Avm2ScopeChain* avm2_scope_capture(Avm2Context* ctx, const Avm2ScopeChain* outer,
                                   const Avm2ScopeEntry* lscope, uint32_t scope_n)
{
	uint32_t outer_n = (outer != NULL) ? outer->count : 0;
	Avm2ScopeChain* chain = avm2_alloc(ctx, sizeof(Avm2ScopeChain));
	chain->count = outer_n + scope_n;
	chain->entries = NULL;
	if (chain->count > 0)
	{
		chain->entries = avm2_alloc(ctx, chain->count * sizeof(Avm2ScopeEntry));
		for (uint32_t i = 0; i < outer_n; i++) chain->entries[i] = outer->entries[i];
		for (uint32_t i = 0; i < scope_n; i++) chain->entries[outer_n + i] = lscope[i];
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
	act.callee = NULL;
	// Default XML namespace propagation (Ruffle activation.rs): callees
	// inherit the caller's dxns; SET_DXNS methods start fresh. Restored on
	// return (exception unwinds restore via the try-frame snapshot).
	const Avm2String* saved_dxns = ctx->dxns;
	if (m->file != NULL
	    && (m->file->data->methods[m->method_index].flags & (1u << 6)) != 0)
	{
		ctx->dxns = NULL;
	}
	avm2_callstack_push(ctx, m, bound_class);
	Avm2Value result = m->fn(&act);
	avm2_callstack_pop(ctx);
	ctx->dxns = saved_dxns;
	return result;
}

Avm2Object* avm2_function_new(Avm2Context* ctx, const Avm2MethodRef* method,
                              Avm2Class* bound_class, Avm2ScopeChain* scope,
                              Avm2Value receiver, bool has_receiver)
{
	Avm2Object* fnobj = avm2_object_alloc(ctx, AVM2_OBJ_FUNCTION, 0);
	fnobj->cls = ctx->builtins.function_class;
	fnobj->vtable = &ctx->builtins.function_class->ivtable;
	fnobj->proto = ctx->builtins.function_class->prototype_obj;
	fnobj->fn_method = *method;
	fnobj->fn_receiver = receiver;
	fnobj->fn_has_receiver = has_receiver;
	fnobj->fn_scope = scope;
	fnobj->fn_bound_class = bound_class;
	return fnobj;
}

Avm2Value avm2_call_function_obj(Avm2Context* ctx, Avm2Object* fnobj,
                                 Avm2Value receiver, const Avm2Value* args, uint32_t argc)
{
	if (fnobj == NULL || fnobj->kind != AVM2_OBJ_FUNCTION)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #1006: value is not a function.");
	}
	Avm2Value this_val = fnobj->fn_has_receiver ? fnobj->fn_receiver : receiver;
	if (this_val.kind == AVM2_VALUE_NULL || this_val.kind == AVM2_VALUE_UNDEFINED)
	{
		// A null/undefined `this` binds to the function's global object
		// (the bottom of its captured scope chain).
		if (fnobj->fn_scope != NULL && fnobj->fn_scope->count > 0)
		{
			this_val = avm2_object_value(fnobj->fn_scope->entries[0].obj);
		}
		else
		{
			this_val = avm2_object_value(ctx->builtin_globals);
		}
	}
	if (fnobj->fn_method.fn == NULL && fnobj->fn_method.file == NULL)
	{
		return avm2_undefined();
	}
	Avm2Activation act;
	act.ctx = ctx;
	act.file = fnobj->fn_method.file;
	act.bound_class = fnobj->fn_bound_class;
	act.outer = fnobj->fn_scope;
	act.this_val = this_val;
	act.args = args;
	act.argc = argc;
	act.callee = fnobj;
	avm2_callstack_push(ctx, &fnobj->fn_method, fnobj->fn_bound_class);
	Avm2Value result = fnobj->fn_method.fn(&act);
	avm2_callstack_pop(ctx);
	return result;
}

Avm2Value avm2_call_value(Avm2Context* ctx, Avm2Value func, Avm2Value receiver,
                          const Avm2Value* args, uint32_t argc)
{
	if (func.kind == AVM2_VALUE_OBJECT && func.u.obj != NULL)
	{
		Avm2Object* o = func.u.obj;
		if (o->kind == AVM2_OBJ_FUNCTION)
		{
			return avm2_call_function_obj(ctx, o, receiver, args, argc);
		}
		if (o->kind == AVM2_OBJ_CLASS)
		{
			// Class call = coercion (int(x), String(x), ...).
			Avm2Class* cls = o->class_ref;
			if (cls->native_call != NULL)
			{
				return cls->native_call(ctx, cls, args, argc);
			}
			if (argc == 0)
			{
				// C() behaves like C(undefined) coercion for primitives;
				// for other classes avmplus throws 1112 — approximate by
				// coercing undefined.
				Avm2Value undef = avm2_undefined();
				return avm2_coerce_to_class(ctx, cls, undef);
			}
			return avm2_coerce_to_class(ctx, cls, args[0]);
		}
	}
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1006: value is not a function.");
}

// ---------------------------------------------------------------------------
// Class definition + construction
// ---------------------------------------------------------------------------

static void resolve_interfaces(Avm2Context* ctx, Avm2Class* cls);

// Interface-namespace aliases (Ruffle vtable.rs): a call through an
// interface-typed reference uses the interface's namespace, so every
// implemented interface's members must appear on the class vtable under
// the interface namespace, pointing at the class's public implementation.
static void add_iface_aliases_from(Avm2Context* ctx, Avm2Class* cls, Avm2Class* iface)
{
	if (iface == NULL) return;
	for (uint32_t i = 0; i < iface->ivtable.count; i++)
	{
		const Avm2PropEntry* ie = &iface->ivtable.entries[i];
		if (avm2_vtable_find(&cls->ivtable, &ie->key) != NULL) continue;
		Avm2PropKey pub = avm2_public_key(ie->key.name, ie->key.name_len);
		const Avm2PropEntry* own = avm2_vtable_find(&cls->ivtable, &pub);
		if (own == NULL) continue;
		Avm2PropEntry alias = *own;
		alias.key = ie->key;
		avm2_vtable_append(ctx, &cls->ivtable, &alias);
	}
	resolve_interfaces(ctx, iface);
	for (uint32_t i = 0; i < iface->interface_count; i++)
	{
		if (iface->interfaces != NULL)
		{
			add_iface_aliases_from(ctx, cls, iface->interfaces[i]);
		}
	}
}

static void class_add_interface_aliases(Avm2Context* ctx, Avm2Class* cls)
{
	if (cls->interface_count == 0) return;
	resolve_interfaces(ctx, cls);
	for (uint32_t i = 0; i < cls->interface_count; i++)
	{
		add_iface_aliases_from(ctx, cls, cls->interfaces[i]);
	}
}

static void class_setup_prototype(Avm2Context* ctx, Avm2Class* cls)
{
	Avm2Object* proto = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);
	proto->cls = ctx->builtins.object_class;
	if (cls->super_class != NULL)
	{
		proto->proto = cls->super_class->prototype_obj;
	}
	cls->prototype_obj = proto;
	if (cls->class_object != NULL)
	{
		Avm2DynProp* p = avm2_object_set_dynamic(ctx, proto, "constructor", 11,
		                                         avm2_object_value(cls->class_object));
		p->dont_enum = 1;
	}
}

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
	// Instance scope = class scope + [class object] (Ruffle
	// ClassObject::from_class): instance methods and the constructor see the
	// class object on their outer chain, so FindProperty reaches static
	// traits (`INSTANCE = this` inside a ctor). The entry is patched with
	// the real class object once it exists below.
	{
		uint32_t outer_n = scope != NULL ? scope->count : 0;
		Avm2ScopeChain* iscope = avm2_alloc(ctx, sizeof(Avm2ScopeChain));
		iscope->count = outer_n + 1;
		iscope->entries = avm2_alloc(ctx, iscope->count * sizeof(Avm2ScopeEntry));
		for (uint32_t i = 0; i < outer_n; i++) iscope->entries[i] = scope->entries[i];
		iscope->entries[outer_n].obj = NULL;
		iscope->entries[outer_n].is_with = 0;
		cls->iscope = iscope;
	}
	cls->interface_count = cd->interface_count;
	cls->interface_mns = cd->interface_mns;
	cls->iface_file = file;

	if (cd->has_protected_ns)
	{
		const Avm2AbcNamespace* pns = &file->data->namespaces[cd->protected_ns];
		cls->has_protected_ns = 1;
		cls->protected_key.ns_kind = pns->kind;
		cls->protected_key.ns_uri = file->data->strings[pns->name].utf8;
		cls->protected_key.ns_len = file->data->strings[pns->name].len;
	}

	const Avm2AbcMethodData* iinit = &file->data->methods[cd->instance_init];
	cls->instance_init.fn = iinit->fn;
	cls->instance_init.file = file;
	cls->instance_init.debug_name = iinit->debug_name;
	cls->instance_init.method_index = cd->instance_init;

	// Inherit the flattened instance vtable, then append own traits
	// (vtable.rs model). Inherited protected-ns entries are re-keyed onto
	// this class's protected namespace so subclass protected access
	// resolves (es4_protected_inheritance).
	if (super_class != NULL)
	{
		cls->ivtable.slot_count = super_class->ivtable.slot_count;
		for (uint32_t i = 0; i < super_class->ivtable.count; i++)
		{
			avm2_vtable_append(ctx, &cls->ivtable, &super_class->ivtable.entries[i]);
		}
		for (uint32_t s = 1; s < super_class->ivtable.meta_cap; s++)
		{
			if (super_class->ivtable.metas[s].used)
			{
				vtable_set_slot_meta(ctx, &cls->ivtable, s,
				                     &super_class->ivtable.metas[s]);
			}
		}
		// Protected traits are ALSO visible under this class's protected
		// namespace (Ruffle vtable.rs keeps the original key and inserts a
		// copy under the child's ns; overrides sync both — see
		// vtable_add_traits).
		if (cls->has_protected_ns && super_class->has_protected_ns)
		{
			uint32_t inherited = cls->ivtable.count;
			for (uint32_t i = 0; i < inherited; i++)
			{
				Avm2PropEntry e = cls->ivtable.entries[i];
				if (avm2_ns_fold(e.key.ns_kind) == 0x18
				    && e.key.ns_len == super_class->protected_key.ns_len
				    && memcmp(e.key.ns_uri, super_class->protected_key.ns_uri,
				              e.key.ns_len) == 0)
				{
					e.key.ns_kind = cls->protected_key.ns_kind;
					e.key.ns_uri = cls->protected_key.ns_uri;
					e.key.ns_len = cls->protected_key.ns_len;
					if (avm2_vtable_find(&cls->ivtable, &e.key) == NULL)
					{
						avm2_vtable_append(ctx, &cls->ivtable, &e);
					}
				}
			}
		}
		cls->native_ext_size = super_class->native_ext_size;
		cls->native_init = super_class->native_init;
		// native_construct is deliberately NOT inherited: a SWF subclass of
		// Object/Error/... constructs through the standard alloc+init path
		// (its own constructor chains to super via ConstructSuper).
	}
	avm2_vtable_add_traits(ctx, &cls->ivtable, file,
	                       cd->instance_traits, cd->instance_trait_count, cls, cls->iscope);
	if ((cd->flags & AVM2_CLASS_FLAG_INTERFACE) == 0)
	{
		class_add_interface_aliases(ctx, cls);
	}

	// Class object: holds the static (class) traits.
	Avm2VTable* cvt = avm2_alloc(ctx, sizeof(Avm2VTable));
	memset(cvt, 0, sizeof(Avm2VTable));
	avm2_vtable_add_traits(ctx, cvt, file, cd->class_traits, cd->class_trait_count,
	                       cls, scope);
	Avm2Object* cobj = avm2_object_alloc(ctx, AVM2_OBJ_CLASS, cvt->slot_count + 1);
	cobj->vtable = cvt;
	cobj->class_ref = cls;
	cobj->cls = ctx->builtins.class_class;
	cobj->proto = ctx->builtins.class_class->prototype_obj;
	cls->class_object = cobj;
	cls->iscope->entries[cls->iscope->count - 1].obj = cobj;
	avm2_slots_init_defaults(ctx, cobj, cvt);

	class_setup_prototype(ctx, cls);

	// Run the static initializer now (Ruffle runs it during NewClass).
	const Avm2AbcMethodData* cinit = &file->data->methods[cd->class_init];
	Avm2MethodRef cinit_ref = { cinit->fn, file, cinit->debug_name, cd->class_init };
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
		avm2_throw_error(ctx, ctx->builtins.verify_error_class,
		                 "Error #1001: The method undefined is not implemented.");
	}
	if (cls->native_construct != NULL)
	{
		return cls->native_construct(ctx, cls, args, argc);
	}
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, cls->ivtable.slot_count + 1);
	obj->cls = cls;
	obj->vtable = &cls->ivtable;
	obj->proto = cls->prototype_obj;
	avm2_slots_init_defaults(ctx, obj, &cls->ivtable);
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
	avm2_call_method_ref(ctx, &cls->instance_init, cls,
	                     cls->iscope != NULL ? cls->iscope : cls->scope,
	                     this_val, args, argc);
	return this_val;
}

Avm2Value avm2_construct_value(Avm2Context* ctx, Avm2Value ctor,
                               const Avm2Value* args, uint32_t argc)
{
	if (ctor.kind == AVM2_VALUE_OBJECT && ctor.u.obj != NULL)
	{
		Avm2Object* o = ctor.u.obj;
		if (o->kind == AVM2_OBJ_CLASS)
		{
			return avm2_class_construct(ctx, o->class_ref, args, argc);
		}
		if (o->kind == AVM2_OBJ_FUNCTION)
		{
			// ES3 constructor call: new object, proto = fn.prototype,
			// call with this = the new object; an object return value
			// replaces the new object.
			Avm2Object* inst = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);
			inst->cls = ctx->builtins.object_class;
			inst->vtable = &ctx->builtins.object_class->ivtable;
			Avm2Value protov = avm2_get_public_property(
				ctx, ctor, "prototype", 9, NULL);
			if (protov.kind == AVM2_VALUE_OBJECT)
			{
				inst->proto = protov.u.obj;
			}
			else
			{
				// A nulled fn.prototype resets to Object.prototype on
				// construction (Ruffle FunctionObject::construct;
				// prototype_set_null).
				o->fn_prototype = ctx->builtins.object_class->prototype_obj;
				o->fn_proto_nulled = 0;
				inst->proto = o->fn_prototype;
			}
			Avm2Value result = avm2_call_function_obj(ctx, o, avm2_object_value(inst),
			                                          args, argc);
			if (result.kind == AVM2_VALUE_OBJECT)
			{
				return result;
			}
			return avm2_object_value(inst);
		}
	}
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1007: Instantiation attempted on a non-constructor.");
}

// ---------------------------------------------------------------------------
// Types / classes of values
// ---------------------------------------------------------------------------

Avm2Class* avm2_value_class(Avm2Context* ctx, Avm2Value v)
{
	switch (v.kind)
	{
		case AVM2_VALUE_BOOL: return ctx->builtins.boolean_class;
		case AVM2_VALUE_INTEGER:
		case AVM2_VALUE_NUMBER: return ctx->builtins.number_class;
		case AVM2_VALUE_STRING: return ctx->builtins.string_class;
		case AVM2_VALUE_OBJECT:
			return v.u.obj->cls != NULL ? v.u.obj->cls : ctx->builtins.object_class;
		default:
			avm2_fatal("avm2_value_class on null/undefined");
	}
}

const Avm2VTable* avm2_value_vtable(Avm2Context* ctx, Avm2Value v)
{
	if (v.kind == AVM2_VALUE_OBJECT)
	{
		if (v.u.obj->vtable != NULL)
		{
			return v.u.obj->vtable;
		}
		// Plain objects (NewObject, ES3-constructed instances, JSON) carry
		// no own vtable: their class's instance vtable applies (Object's
		// hasOwnProperty & co resolve through the AS3 namespace).
		return v.u.obj->cls != NULL ? &v.u.obj->cls->ivtable : NULL;
	}
	Avm2Class* cls = avm2_value_class(ctx, v);
	return &cls->ivtable;
}

Avm2Object* avm2_value_proto(Avm2Context* ctx, Avm2Value v)
{
	if (v.kind == AVM2_VALUE_OBJECT)
	{
		return v.u.obj->proto;
	}
	Avm2Class* cls = avm2_value_class(ctx, v);
	return cls->prototype_obj;
}

static void resolve_interfaces(Avm2Context* ctx, Avm2Class* cls)
{
	if (cls->interfaces != NULL || cls->interface_count == 0) return;
	cls->interfaces = avm2_alloc(ctx, cls->interface_count * sizeof(Avm2Class*));
	for (uint32_t i = 0; i < cls->interface_count; i++)
	{
		cls->interfaces[i] = avm2_class_for_mn(ctx, cls->iface_file,
		                                       cls->interface_mns[i]);
	}
}

// Does `cls` implement `iface` directly or transitively?
bool avm2_class_has_interface(Avm2Context* ctx, Avm2Class* cls, Avm2Class* iface)
{
	for (Avm2Class* c = cls; c != NULL; c = c->super_class)
	{
		if (c->interface_count == 0) continue;
		resolve_interfaces(ctx, c);
		for (uint32_t i = 0; i < c->interface_count; i++)
		{
			Avm2Class* di = c->interfaces[i];
			if (di == NULL) continue;
			if (di == iface) return true;
			// Super-interfaces are declared as the interface's own
			// interface list.
			if (avm2_class_has_interface(ctx, di, iface)) return true;
		}
	}
	return false;
}

bool avm2_value_is_of_type(Avm2Context* ctx, Avm2Value v, Avm2Class* type_class)
{
	Avm2Builtins* b = &ctx->builtins;
	if (type_class == b->number_class) return avm2_value_is_number(v);
	if (type_class == b->uint_class) return avm2_value_is_u32(v);
	if (type_class == b->int_class) return avm2_value_is_i32(v);
	if (type_class == b->boolean_class) return v.kind == AVM2_VALUE_BOOL;
	if (type_class == b->string_class) return v.kind == AVM2_VALUE_STRING;
	if (type_class == b->object_class)
	{
		return v.kind != AVM2_VALUE_UNDEFINED && v.kind != AVM2_VALUE_NULL;
	}
	if (v.kind == AVM2_VALUE_UNDEFINED || v.kind == AVM2_VALUE_NULL)
	{
		return false;
	}
	if (v.kind != AVM2_VALUE_OBJECT)
	{
		// Primitives are instances of their builtin classes only (handled
		// above); Function/Class subclass checks need an object.
		Avm2Class* vc = avm2_value_class(ctx, v);
		for (Avm2Class* c = vc; c != NULL; c = c->super_class)
		{
			if (c == type_class) return true;
		}
		return false;
	}
	Avm2Class* vc = v.u.obj->cls;
	for (Avm2Class* c = vc; c != NULL; c = c->super_class)
	{
		if (c == type_class) return true;
	}
	if (type_class->flags & AVM2_CLASS_FLAG_INTERFACE)
	{
		return avm2_class_has_interface(ctx, vc, type_class);
	}
	return false;
}

Avm2Class* avm2_class_for_mn(Avm2Context* ctx, Avm2AbcFileRt* file, uint32_t mn_idx)
{
	if (mn_idx == 0 || file == NULL) return NULL;
	const Avm2AbcFileData* data = file->data;
	const Avm2AbcMultiname* mn = &data->multinames[mn_idx];

	if (mn->kind == 0x1d)  // TypeName: Vector.<T>
	{
		Avm2Class* base = avm2_class_for_mn(ctx, file, mn->base_type);
		if (base == NULL || !base->is_generic_vector) return NULL;
		Avm2Class* param = NULL;
		if (mn->type_param_count >= 1 && mn->type_params[0] != 0)
		{
			// A param naming "*" also means Vector.<*>.
			const char* pn;
			uint32_t pn_len;
			avm2_mn_name(data, mn->type_params[0], &pn, &pn_len);
			if (!(pn_len == 1 && pn[0] == '*'))
			{
				param = avm2_class_for_mn(ctx, file, mn->type_params[0]);
				if (param == NULL) return NULL;
			}
		}
		return avm2_vector_apply(ctx, param);
	}

	Avm2PropKey key;
	Avm2Object* globals = NULL;
	if (mn->kind == 0x07 || mn->kind == 0x0d)
	{
		if (!avm2_propkey_from_qname(data, mn_idx, &key)) return NULL;
		globals = avm2_domain_find(ctx, &key);
	}
	else if (mn->kind == 0x09 || mn->kind == 0x0e)
	{
		const Avm2AbcNsSet* set = &data->ns_sets[mn->ns_set];
		for (uint32_t i = 0; i < set->count && globals == NULL; i++)
		{
			key.name = data->strings[mn->name].utf8;
			key.name_len = data->strings[mn->name].len;
			const Avm2AbcNamespace* ns = &data->namespaces[set->ns_indices[i]];
			key.ns_kind = ns->kind;
			key.ns_uri = data->strings[ns->name].utf8;
			key.ns_len = data->strings[ns->name].len;
			globals = avm2_domain_find(ctx, &key);
		}
	}
	if (globals == NULL) return NULL;

	// Fetch the class value off the globals (slot or dynamic).
	const Avm2PropEntry* entry = avm2_vtable_find(globals->vtable, &key);
	Avm2Value cv = avm2_undefined();
	if (entry != NULL && entry->kind == AVM2_PROP_SLOT)
	{
		cv = globals->slots[entry->slot_index];
	}
	else
	{
		Avm2Value* dyn = avm2_object_find_dynamic(globals, key.name, key.name_len);
		if (dyn != NULL) cv = *dyn;
	}
	if (cv.kind == AVM2_VALUE_OBJECT && cv.u.obj != NULL
	    && cv.u.obj->kind == AVM2_OBJ_CLASS)
	{
		return cv.u.obj->class_ref;
	}
	return NULL;
}

// Coercion by class (Ruffle value.rs coerce_to_type).
Avm2Value avm2_coerce_to_class(Avm2Context* ctx, Avm2Class* cls, Avm2Value v)
{
	Avm2Builtins* b = &ctx->builtins;
	if (cls == NULL) return v;
	if (cls == b->int_class) return avm2_integer(avm2_coerce_to_i32(ctx, v));
	if (cls == b->uint_class) return avm2_uint_value(avm2_coerce_to_u32(ctx, v));
	if (cls == b->number_class) return avm2_number(avm2_coerce_to_number(ctx, v));
	if (cls == b->boolean_class) return avm2_bool(avm2_coerce_to_boolean(v));
	if (v.kind == AVM2_VALUE_UNDEFINED || v.kind == AVM2_VALUE_NULL)
	{
		return avm2_null();
	}
	if (cls == b->string_class) return avm2_string(avm2_coerce_to_string(ctx, v));
	if (cls == b->object_class) return v;
	if (avm2_value_is_of_type(ctx, v, cls))
	{
		return v;
	}
	// Error #1034 with a debug string for the value.
	char dbg[128];
	if (v.kind == AVM2_VALUE_STRING)
	{
		snprintf(dbg, sizeof(dbg), "\"%.*s\"",
		         v.u.str->len > 100 ? 100 : (int) v.u.str->len, v.u.str->utf8);
	}
	else if (v.kind == AVM2_VALUE_OBJECT)
	{
		// FP prints the VALUE's type ns::name (colons) but the TARGET
		// class dotted (vector_coercion).
		Avm2Class* vc = avm2_value_class(ctx, v);
		if (vc->name.ns_len > 0)
		{
			snprintf(dbg, sizeof(dbg), "%.*s::%.*s@00000000000",
			         (int) vc->name.ns_len, vc->name.ns_uri,
			         (int) vc->name.name_len, vc->name.name);
		}
		else
		{
			snprintf(dbg, sizeof(dbg), "%.*s@00000000000",
			         (int) vc->name.name_len, vc->name.name);
		}
	}
	else
	{
		const Avm2String* s = avm2_coerce_to_string(ctx, v);
		snprintf(dbg, sizeof(dbg), "%.*s",
		         s->len > 100 ? 100 : (int) s->len, s->utf8);
	}
	char cq[160];
	avm2_class_qname_buf(cls, cq, sizeof(cq));
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1034: Type Coercion failed: cannot convert %s to %s.",
	                 dbg, cq);
}

Avm2Value avm2_coerce_to_type_mn(Avm2Context* ctx, Avm2AbcFileRt* file,
                                 uint32_t mn_idx, Avm2Value v)
{
	if (mn_idx == 0) return v;  // any
	const char* tn;
	uint32_t tn_len;
	avm2_mn_name(file->data, mn_idx, &tn, &tn_len);
	if (tn_len == 1 && tn[0] == '*') return v;
	if (tn_len == 4 && memcmp(tn, "void", 4) == 0)
	{
		return (v.kind == AVM2_VALUE_UNDEFINED || v.kind == AVM2_VALUE_NULL)
		       ? avm2_undefined() : v;
	}
	Avm2Class* cls = avm2_class_for_mn(ctx, file, mn_idx);
	if (cls == NULL)
	{
		// Unresolvable type name (e.g. the class's own slot during its
		// cinit): null/undefined still coerce to null; other values are
		// left alone.
		if (v.kind == AVM2_VALUE_UNDEFINED || v.kind == AVM2_VALUE_NULL)
		{
			return avm2_null();
		}
		return v;
	}
	return avm2_coerce_to_class(ctx, cls, v);
}
