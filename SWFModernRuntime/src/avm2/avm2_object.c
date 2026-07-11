// ScriptObject allocation + dynamic (expando) properties.
//
// GC note (memory-reclamation rules): AVM2 objects allocate from the shared
// o1heap but are NOT enrolled in the AVM1 mark-sweep census (g_mt_obj_head /
// g_mt_arr_head track ASObject/ASArray only), so the collector can neither
// mark nor sweep them — every Stage-2 AVM2 allocation is immortal by
// construction, and none holds an edge into a collectable AVM1 object.
// That satisfies "rooted or scrubbed" trivially; see avm2GcMarkRoots in
// avm2_main.c for the aggregator participant + the Stage 3 TODO (enroll
// AVM2 objects in their own census once tests create garbage).

#include <string.h>

#include <avm2/avm2_object.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_main.h>

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

void avm2_object_set_dynamic(Avm2Context* ctx, Avm2Object* obj, const char* name,
                             uint32_t name_len, Avm2Value value)
{
	Avm2Value* existing = avm2_object_find_dynamic(obj, name, name_len);
	if (existing != NULL)
	{
		*existing = value;
		return;
	}
	Avm2DynProp* p = avm2_alloc(ctx, sizeof(Avm2DynProp));
	const Avm2String* s = avm2_string_new(ctx, name, name_len);
	p->name = *s;
	p->value = value;
	p->next = obj->dyn_props;
	obj->dyn_props = p;
}
