// ScriptObject allocation + dynamic (expando) properties + array storage +
// enumeration.
//
// GC note (memory-reclamation rules): AVM2 objects allocate from the shared
// o1heap but are NOT enrolled in the AVM1 mark-sweep census (g_mt_obj_head /
// g_mt_arr_head track ASObject/ASArray only), so the collector can neither
// mark nor sweep them — every AVM2 allocation is immortal by construction,
// and none holds an edge into a collectable AVM1 object. That satisfies
// "rooted or scrubbed" trivially; see avm2GcMarkRoots in avm2_main.c.
// Tranche-1 runs are short (MAX_FRAMES-bounded), so immortality is correct,
// just wasteful; revisit if anything OOMs.

#include <stdio.h>
#include <string.h>

#include <avm2/avm2_object.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_value.h>

Avm2Object* avm2_object_alloc(Avm2Context* ctx, uint8_t kind, uint32_t slot_count)
{
	Avm2Object* obj = avm2_alloc(ctx, sizeof(Avm2Object));
	memset(obj, 0, sizeof(Avm2Object));
	obj->kind = kind;
	obj->slot_count = slot_count;
	if (slot_count > 0)
	{
		obj->slots = avm2_alloc(ctx, slot_count * sizeof(Avm2Value));
		for (uint32_t i = 0; i < slot_count; i++)
		{
			obj->slots[i] = avm2_undefined();
		}
	}
	return obj;
}

Avm2Value* avm2_object_find_dynamic(Avm2Object* obj, const char* name, uint32_t name_len)
{
	for (Avm2DynProp* p = obj->dyn_props; p != NULL; p = p->next)
	{
		if (p->name.len == name_len && memcmp(p->name.utf8, name, name_len) == 0)
		{
			return &p->value;
		}
	}
	return NULL;
}

Avm2DynProp* avm2_object_set_dynamic(Avm2Context* ctx, Avm2Object* obj, const char* name,
                                     uint32_t name_len, Avm2Value value)
{
	for (Avm2DynProp* p = obj->dyn_props; p != NULL; p = p->next)
	{
		if (p->name.len == name_len && memcmp(p->name.utf8, name, name_len) == 0)
		{
			p->value = value;
			return p;
		}
	}
	Avm2DynProp* p = avm2_alloc(ctx, sizeof(Avm2DynProp));
	const Avm2String* s = avm2_string_new(ctx, name, name_len);
	p->name = *s;
	p->value = value;
	p->next = NULL;
	p->dont_enum = 0;
	// Append at tail: enumeration order is insertion order.
	if (obj->dyn_tail != NULL)
	{
		obj->dyn_tail->next = p;
	}
	else
	{
		obj->dyn_props = p;
	}
	obj->dyn_tail = p;
	return p;
}

int avm2_object_delete_dynamic(Avm2Object* obj, const char* name, uint32_t name_len)
{
	Avm2DynProp* prev = NULL;
	for (Avm2DynProp* p = obj->dyn_props; p != NULL; prev = p, p = p->next)
	{
		if (p->name.len == name_len && memcmp(p->name.utf8, name, name_len) == 0)
		{
			if (prev != NULL) prev->next = p->next;
			else obj->dyn_props = p->next;
			if (obj->dyn_tail == p) obj->dyn_tail = prev;
			return 1;
		}
	}
	return 0;
}

// ---------------------------------------------------------------------------
// Arrays
// ---------------------------------------------------------------------------

// Far writes go to the sorted sparse list instead of growing the dense
// region. Ruffle keeps arrays dense up to 2^28 entries; we cap at 2^22
// (64 MB of slots) — everything below stays dense (holes included), so the
// dense-based Array methods keep exact semantics; only truly huge indices
// (array_index_max) go sparse.
#define AVM2_ARRAY_MAX_DENSE (1u << 22)

Avm2ArrayExt* avm2_array_ext(Avm2Object* obj)
{
	if (obj == NULL || obj->kind != AVM2_OBJ_ARRAY) return NULL;
	return (Avm2ArrayExt*) obj->native_ext;
}

static void array_reserve(Avm2Context* ctx, Avm2ArrayExt* ext, uint32_t need)
{
	if (need <= ext->cap) return;
	uint32_t new_cap = ext->cap == 0 ? 8 : ext->cap;
	while (new_cap < need) new_cap *= 2;
	Avm2Value* grown = avm2_alloc(ctx, new_cap * sizeof(Avm2Value));
	if (ext->dense_len > 0)
	{
		memcpy(grown, ext->elems, ext->dense_len * sizeof(Avm2Value));
	}
	ext->elems = grown;
	ext->cap = new_cap;
}

Avm2Object* avm2_array_new(Avm2Context* ctx, uint32_t length)
{
	Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_ARRAY, 1);
	obj->cls = ctx->builtins.array_class;
	obj->vtable = &ctx->builtins.array_class->ivtable;
	obj->proto = ctx->builtins.array_class->prototype_obj;
	Avm2ArrayExt* ext = avm2_alloc(ctx, sizeof(Avm2ArrayExt));
	memset(ext, 0, sizeof(Avm2ArrayExt));
	obj->native_ext = ext;
	if (length > 0)
	{
		if (length <= AVM2_ARRAY_MAX_DENSE)
		{
			array_reserve(ctx, ext, length);
			for (uint32_t i = 0; i < length; i++)
			{
				ext->elems[i].kind = AVM2_VALUE_HOLE;
			}
			ext->dense_len = length;
		}
		ext->length = length;
	}
	return obj;
}

Avm2Object* avm2_array_from_values(Avm2Context* ctx, const Avm2Value* vals, uint32_t n)
{
	Avm2Object* obj = avm2_array_new(ctx, 0);
	Avm2ArrayExt* ext = avm2_array_ext(obj);
	if (n > 0)
	{
		array_reserve(ctx, ext, n);
		memcpy(ext->elems, vals, n * sizeof(Avm2Value));
		ext->dense_len = n;
		ext->length = n;
	}
	return obj;
}

Avm2Value avm2_array_get(Avm2Object* arr, uint32_t idx)
{
	Avm2ArrayExt* ext = avm2_array_ext(arr);
	Avm2Value hole = { AVM2_VALUE_HOLE, 0, { 0 } };
	if (ext == NULL) return hole;
	if (idx < ext->dense_len) return ext->elems[idx];
	for (Avm2SparseElem* s = ext->sparse; s != NULL && s->idx <= idx; s = s->next)
	{
		if (s->idx == idx) return s->v;
	}
	return hole;
}

void avm2_array_set(Avm2Context* ctx, Avm2Object* arr, uint32_t idx, Avm2Value v)
{
	Avm2ArrayExt* ext = avm2_array_ext(arr);
	if (ext == NULL) return;
	if (idx < ext->dense_len)
	{
		ext->elems[idx] = v;
		return;
	}
	if (idx < AVM2_ARRAY_MAX_DENSE && ext->sparse == NULL)
	{
		array_reserve(ctx, ext, idx + 1);
		for (uint32_t i = ext->dense_len; i < idx; i++)
		{
			ext->elems[i].kind = AVM2_VALUE_HOLE;
		}
		ext->elems[idx] = v;
		ext->dense_len = idx + 1;
	}
	else
	{
		// Sorted insert into the sparse list.
		Avm2SparseElem** link = &ext->sparse;
		while (*link != NULL && (*link)->idx < idx) link = &(*link)->next;
		if (*link != NULL && (*link)->idx == idx)
		{
			(*link)->v = v;
		}
		else
		{
			Avm2SparseElem* n = avm2_alloc(ctx, sizeof(Avm2SparseElem));
			n->idx = idx;
			n->v = v;
			n->next = *link;
			*link = n;
		}
	}
	if (idx + 1 > ext->length && idx != 0xFFFFFFFFu)
	{
		ext->length = idx + 1;
	}
	else if (idx == 0xFFFFFFFFu)
	{
		// Index 2^32-1 can't extend length past 2^32-1.
		if (ext->length < 0xFFFFFFFFu) ext->length = 0xFFFFFFFFu;
	}
}

void avm2_array_set_length(Avm2Context* ctx, Avm2Object* arr, uint32_t new_len)
{
	Avm2ArrayExt* ext = avm2_array_ext(arr);
	if (ext == NULL) return;
	if (new_len < ext->dense_len)
	{
		ext->dense_len = new_len;
	}
	else if (new_len > ext->dense_len && new_len <= AVM2_ARRAY_MAX_DENSE
	         && ext->sparse == NULL)
	{
		array_reserve(ctx, ext, new_len);
		for (uint32_t i = ext->dense_len; i < new_len; i++)
		{
			ext->elems[i].kind = AVM2_VALUE_HOLE;
		}
		ext->dense_len = new_len;
	}
	// Drop sparse entries at/after the new length.
	Avm2SparseElem** link = &ext->sparse;
	while (*link != NULL)
	{
		if ((*link)->idx >= new_len) *link = (*link)->next;
		else link = &(*link)->next;
	}
	ext->length = new_len;
}

int avm2_array_delete(Avm2Object* arr, uint32_t idx)
{
	Avm2ArrayExt* ext = avm2_array_ext(arr);
	if (ext == NULL) return 0;
	if (idx < ext->dense_len)
	{
		if (ext->elems[idx].kind == AVM2_VALUE_HOLE) return 0;
		ext->elems[idx].kind = AVM2_VALUE_HOLE;
		return 1;
	}
	Avm2SparseElem** link = &ext->sparse;
	while (*link != NULL && (*link)->idx < idx) link = &(*link)->next;
	if (*link != NULL && (*link)->idx == idx)
	{
		*link = (*link)->next;
		return 1;
	}
	return 0;
}

void avm2_array_push(Avm2Context* ctx, Avm2Object* arr, Avm2Value v)
{
	Avm2ArrayExt* ext = avm2_array_ext(arr);
	avm2_array_set(ctx, arr, ext->length, v);
}

// ---------------------------------------------------------------------------
// Enumeration (Ruffle get_next_enumerant protocol; 1-based, 0 = done)
// ---------------------------------------------------------------------------

// Enumerant layout: arrays first expose their dense non-hole indices (in
// index order), then dynamic props (insertion order, skipping dont_enum).
// Plain objects expose dynamic props only (declared traits don't enumerate).

static uint32_t array_enum_count(Avm2Object* obj)
{
	Avm2ArrayExt* ext = avm2_array_ext(obj);
	if (ext == NULL) return 0;
	uint32_t n = 0;
	for (uint32_t i = 0; i < ext->dense_len; i++)
	{
		if (ext->elems[i].kind != AVM2_VALUE_HOLE) n++;
	}
	for (Avm2SparseElem* s = ext->sparse; s != NULL; s = s->next) n++;
	return n;
}

// Returns the index of the nth (1-based) non-hole element, or -1.
static int64_t array_nth_index(Avm2Object* obj, uint32_t nth)
{
	Avm2ArrayExt* ext = avm2_array_ext(obj);
	if (ext == NULL) return -1;
	uint32_t seen = 0;
	for (uint32_t i = 0; i < ext->dense_len; i++)
	{
		if (ext->elems[i].kind != AVM2_VALUE_HOLE)
		{
			seen++;
			if (seen == nth) return (int64_t) i;
		}
	}
	for (Avm2SparseElem* s = ext->sparse; s != NULL; s = s->next)
	{
		seen++;
		if (seen == nth) return (int64_t) s->idx;
	}
	return -1;
}

static Avm2DynProp* nth_enumerable_dyn(Avm2Object* obj, uint32_t nth)
{
	uint32_t seen = 0;
	for (Avm2DynProp* p = obj->dyn_props; p != NULL; p = p->next)
	{
		if (p->dont_enum) continue;
		seen++;
		if (seen == nth) return p;
	}
	return NULL;
}

static uint32_t dyn_enum_count(Avm2Object* obj)
{
	uint32_t n = 0;
	for (Avm2DynProp* p = obj->dyn_props; p != NULL; p = p->next)
	{
		if (!p->dont_enum) n++;
	}
	return n;
}

uint32_t avm2_object_next_enumerant(Avm2Object* obj, uint32_t cur)
{
	if (obj->kind == AVM2_OBJ_VECTOR)
	{
		// Ruffle vector_object.rs: indices 0..length-1 (1-based enumerants).
		Avm2VectorExt* ext = (Avm2VectorExt*) obj->native_ext;
		return cur < ext->length ? cur + 1 : 0;
	}
	uint32_t total = array_enum_count(obj) + dyn_enum_count(obj);
	if (cur + 1 <= total) return cur + 1;
	return 0;
}

Avm2Value avm2_object_enumerant_name(Avm2Context* ctx, Avm2Object* obj, uint32_t idx)
{
	if (obj->kind == AVM2_OBJ_VECTOR)
	{
		Avm2VectorExt* ext = (Avm2VectorExt*) obj->native_ext;
		if (idx >= 1 && idx <= ext->length) return avm2_uint_value(idx - 1);
		return avm2_null();
	}
	uint32_t arr_n = array_enum_count(obj);
	if (idx >= 1 && idx <= arr_n)
	{
		int64_t dense = array_nth_index(obj, idx);
		return avm2_uint_value((uint32_t) dense);
	}
	Avm2DynProp* p = nth_enumerable_dyn(obj, idx - arr_n);
	if (p == NULL) return avm2_null();
	return avm2_string(avm2_string_new(ctx, p->name.utf8, p->name.len));
}

Avm2Value avm2_object_enumerant_value(Avm2Context* ctx, Avm2Object* obj, uint32_t idx)
{
	if (obj->kind == AVM2_OBJ_VECTOR)
	{
		Avm2VectorExt* ext = (Avm2VectorExt*) obj->native_ext;
		if (idx >= 1 && idx <= ext->length) return ext->elems[idx - 1];
		return avm2_undefined();
	}
	uint32_t arr_n = array_enum_count(obj);
	if (idx >= 1 && idx <= arr_n)
	{
		int64_t dense = array_nth_index(obj, idx);
		Avm2Value v = avm2_array_get(obj, (uint32_t) dense);
		if (v.kind == AVM2_VALUE_HOLE) return avm2_undefined();
		return v;
	}
	Avm2DynProp* p = nth_enumerable_dyn(obj, idx - arr_n);
	if (p == NULL) return avm2_undefined();
	return p->value;
}
