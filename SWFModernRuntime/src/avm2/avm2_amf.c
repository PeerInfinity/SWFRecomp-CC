// AMF3/AMF0 serialization — ByteArray.readObject/writeObject,
// flash.net.registerClassAlias/getClassByAlias/ObjectEncoding, plus the
// minimal Date the AMF tests need.
//
// The wire format is a byte-exact port of the flash-lso crate
// (amf3/write.rs + length.rs + element_cache.rs, amf0/write.rs, read.rs)
// as DRIVEN BY Ruffle's bridge (core/src/avm2/amf.rs), quirks included:
//
// - Objects/arrays are never written as object references (flash-lso
//   hardcodes Length::Size for them) — repeated objects re-serialize in
//   full, but their TRAIT definition is reference-shared. Only repeated
//   VectorObject/Dictionary values collapse to object references; Date/
//   ByteArray/scalar-Vector values are looked up in the object table but
//   never stored into it, so they always write in full.
// - The object reference table still accumulates Object/ECMAArray/
//   StrictArray/VectorObject/Dictionary entries (index bookkeeping).
// - Static (trait) properties are the class's public slots and full
//   get/set accessor pairs, SORTED by name (Ruffle sorts for stable
//   output); dynamic props follow in enumeration order. Function-valued
//   entries are skipped in the dynamic part only.
// - AMF0 writes class_def-less objects (marker 0x03) even for aliased
//   classes, and Integers widen to Numbers; vectors/dictionaries/
//   bytearrays become 0x0D Unsupported (flash-lso fallback arm).
// - Values normalize before dispatch (Ruffle Value::normalize): Numbers
//   with exact-i32 bit patterns inside ±2^28 become Integers and vice
//   versa.
//
// Deserialization builds AVM2 values directly, inserting containers into
// the reference table before their children (circular refs). Property
// sets on typed objects that throw are caught, stringified, and TRACED
// (Ruffle read_object error handling — amf_setter_error); errors thrown
// by the stringification itself propagate.

#include <math.h>
#include <setjmp.h>
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

// ---------------------------------------------------------------------------
// Class alias registry (flash.net.registerClassAlias)
// ---------------------------------------------------------------------------

typedef struct AliasEntry
{
	struct AliasEntry* next;
	const Avm2String* alias;
	Avm2Class* cls;
} AliasEntry;

static AliasEntry* g_aliases;

static Avm2Class* alias_to_class(const char* name, uint32_t len)
{
	for (AliasEntry* a = g_aliases; a != NULL; a = a->next)
	{
		if (a->alias->len == len && memcmp(a->alias->utf8, name, len) == 0)
		{
			return a->cls;
		}
	}
	return NULL;
}

static const Avm2String* class_to_alias(Avm2Context* ctx, Avm2Class* cls)
{
	for (AliasEntry* a = g_aliases; a != NULL; a = a->next)
	{
		if (a->cls == cls) return a->alias;
	}
	return avm2_string_from_literal(ctx, "");
}

// ---------------------------------------------------------------------------
// Minimal Date (upgrades the Stage-3 stub; enough for AMF round-trips)
// ---------------------------------------------------------------------------

Avm2DateExt* avm2_date_ext_of(Avm2Value v)
{
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL) return NULL;
	Avm2Context* ctx = avm2_get_context();
	if (ctx->builtins.date_class == NULL) return NULL;
	for (Avm2Class* c = v.u.obj->cls; c != NULL; c = c->super_class)
	{
		if (c == ctx->builtins.date_class)
		{
			return (Avm2DateExt*) v.u.obj->native_ext;
		}
	}
	return NULL;
}

#ifndef MOCK_DATE_TIME
#define MOCK_DATE_TIME 981152406000ll
#endif

static void date_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	(void) ctx;
	((Avm2DateExt*) obj->native_ext)->millis = (double) MOCK_DATE_TIME;
}

static Avm2Value date_init(Avm2Activation* act)
{
	Avm2DateExt* ext = avm2_date_ext_of(act->this_val);
	if (ext == NULL) return avm2_undefined();
	if (act->argc == 1)
	{
		// One numeric-ish argument = milliseconds since epoch (strings
		// would parse in FP; unsupported here -> NaN).
		if (act->args[0].kind == AVM2_VALUE_STRING)
		{
			ext->millis = __builtin_nan("");
		}
		else
		{
			ext->millis = avm2_coerce_to_number(act->ctx, act->args[0]);
		}
	}
	else if (act->argc > 1)
	{
		// Component form unimplemented (no AMF test constructs one).
		ext->millis = __builtin_nan("");
	}
	if (!isnan(ext->millis))
	{
		// FP truncates fractional milliseconds.
		ext->millis = trunc(ext->millis);
	}
	return avm2_undefined();
}

static Avm2Value date_get_time(Avm2Activation* act)
{
	Avm2DateExt* ext = avm2_date_ext_of(act->this_val);
	return avm2_number(ext != NULL ? ext->millis : __builtin_nan(""));
}

static Avm2Value date_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2DateExt* ext = avm2_date_ext_of(act->this_val);
	double m = (ext != NULL) ? ext->millis : __builtin_nan("");
	if (isnan(m))
	{
		return avm2_string(avm2_string_from_literal(ctx, "Invalid Date"));
	}
	// UTC render (CI runs UTC); only reached if a test prints a valid Date.
	static const char* const days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu",
	                                     "Fri", "Sat" };
	static const char* const months[12] = { "Jan", "Feb", "Mar", "Apr", "May",
	                                        "Jun", "Jul", "Aug", "Sep", "Oct",
	                                        "Nov", "Dec" };
	int64_t secs = (int64_t) floor(m / 1000.0);
	int64_t days_since = secs / 86400;
	int64_t tod = secs % 86400;
	if (tod < 0)
	{
		tod += 86400;
		days_since--;
	}
	// Civil-from-days (Howard Hinnant's algorithm).
	int64_t z = days_since + 719468;
	int64_t era = (z >= 0 ? z : z - 146096) / 146097;
	int64_t doe = z - era * 146097;
	int64_t yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
	int64_t y = yoe + era * 400;
	int64_t doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
	int64_t mp = (5 * doy + 2) / 153;
	int64_t d = doy - (153 * mp + 2) / 5 + 1;
	int64_t mo = mp < 10 ? mp + 3 : mp - 9;
	if (mo <= 2) y++;
	int wd = (int) (((days_since % 7) + 11) % 7);  // 1970-01-01 = Thursday
	char buf[64];
	snprintf(buf, sizeof(buf), "%s %s %d %02d:%02d:%02d GMT+0000 %d",
	         days[wd], months[mo - 1], (int) d,
	         (int) (tod / 3600), (int) ((tod / 60) % 60), (int) (tod % 60),
	         (int) y);
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

static Avm2Value date_value_of(Avm2Activation* act)
{
	return date_get_time(act);
}

// ---------------------------------------------------------------------------
// Growable output buffer
// ---------------------------------------------------------------------------

typedef struct AmfBuf
{
	Avm2Context* ctx;
	uint8_t* b;
	uint32_t len;
	uint32_t cap;
} AmfBuf;

static void buf_put(AmfBuf* w, const void* p, uint32_t n)
{
	if (w->len + n > w->cap)
	{
		uint32_t new_cap = w->cap == 0 ? 64 : w->cap;
		while (new_cap < w->len + n) new_cap *= 2;
		uint8_t* grown = avm2_alloc(w->ctx, new_cap);
		if (w->len > 0) memcpy(grown, w->b, w->len);
		w->b = grown;
		w->cap = new_cap;
	}
	memcpy(w->b + w->len, p, n);
	w->len += n;
}

static void buf_u8(AmfBuf* w, uint8_t v) { buf_put(w, &v, 1); }

static void buf_u16be(AmfBuf* w, uint16_t v)
{
	uint8_t b[2] = { (uint8_t) (v >> 8), (uint8_t) v };
	buf_put(w, b, 2);
}

static void buf_u32be(AmfBuf* w, uint32_t v)
{
	uint8_t b[4] = { (uint8_t) (v >> 24), (uint8_t) (v >> 16),
	                 (uint8_t) (v >> 8), (uint8_t) v };
	buf_put(w, b, 4);
}

static void buf_f64be(AmfBuf* w, double d)
{
	uint64_t bits;
	memcpy(&bits, &d, 8);
	uint8_t b[8];
	for (int i = 0; i < 8; i++) b[i] = (uint8_t) (bits >> (56 - i * 8));
	buf_put(w, b, 8);
}

// ---------------------------------------------------------------------------
// AMF3 writer
// ---------------------------------------------------------------------------

enum
{
	M3_UNDEF = 0x00, M3_NULL = 0x01, M3_FALSE = 0x02, M3_TRUE = 0x03,
	M3_INT = 0x04, M3_NUM = 0x05, M3_STR = 0x06, M3_XMLDOC = 0x07,
	M3_DATE = 0x08, M3_ARRAY = 0x09, M3_OBJECT = 0x0A, M3_XMLSTR = 0x0B,
	M3_BYTEARRAY = 0x0C, M3_VECINT = 0x0D, M3_VECUINT = 0x0E,
	M3_VECDOUBLE = 0x0F, M3_VECOBJ = 0x10, M3_DICT = 0x11,
};

typedef struct StrEntry
{
	const char* p;
	uint32_t n;
} StrEntry;

typedef struct TraitEntry
{
	const Avm2String* name;
	int dynamic;
	uint32_t static_count;
	const Avm2String** statics;
} TraitEntry;

// Object-table entry: identity of the source object (bridge-level Rc
// identity approximated by Avm2Object identity).
typedef struct ObjEntry
{
	Avm2Object* src;
} ObjEntry;

typedef struct Amf3Wr
{
	Avm2Context* ctx;
	AmfBuf out;
	StrEntry* strings;
	uint32_t str_count, str_cap;
	TraitEntry* traits;
	uint32_t trait_count, trait_cap;
	ObjEntry* objs;
	uint32_t obj_count, obj_cap;
} Amf3Wr;

static void w3_u29(Amf3Wr* w, int32_t i)
{
	int32_t n = (i < 0) ? i + 0x20000000 : i;
	if (n > 0x1fffff)
	{
		buf_u8(&w->out, (uint8_t) ((n >> 22) | 0x80));
		buf_u8(&w->out, (uint8_t) ((n >> 15) | 0x80));
		buf_u8(&w->out, (uint8_t) ((n >> 8) | 0x80));
		buf_u8(&w->out, (uint8_t) (n & 0xFF));
	}
	else if (n > 0x3fff)
	{
		buf_u8(&w->out, (uint8_t) ((n >> 14) | 0x80));
		buf_u8(&w->out, (uint8_t) ((n >> 7) | 0x80));
		buf_u8(&w->out, (uint8_t) (n & 0x7F));
	}
	else if (n > 0x7f)
	{
		buf_u8(&w->out, (uint8_t) ((n >> 7) | 0x80));
		buf_u8(&w->out, (uint8_t) (n & 0x7F));
	}
	else
	{
		buf_u8(&w->out, (uint8_t) (n & 0x7F));
	}
}

// Byte string with the AMF3 string reference table (empty never cached).
static void w3_str(Amf3Wr* w, const char* p, uint32_t n)
{
	if (n > 0)
	{
		for (uint32_t i = 0; i < w->str_count; i++)
		{
			if (w->strings[i].n == n && memcmp(w->strings[i].p, p, n) == 0)
			{
				w3_u29(w, (int32_t) (i << 1));
				return;
			}
		}
		if (w->str_count == w->str_cap)
		{
			uint32_t nc = w->str_cap == 0 ? 16 : w->str_cap * 2;
			StrEntry* g = avm2_alloc(w->ctx, nc * sizeof(StrEntry));
			memcpy(g, w->strings, w->str_count * sizeof(StrEntry));
			w->strings = g;
			w->str_cap = nc;
		}
		w->strings[w->str_count].p = p;
		w->strings[w->str_count].n = n;
		w->str_count++;
	}
	w3_u29(w, (int32_t) ((n << 1) | 1));
	buf_put(&w->out, p, n);
}

// Object reference table (identity). Returns index or -1.
static int32_t w3_obj_find(Amf3Wr* w, Avm2Object* src)
{
	for (uint32_t i = 0; i < w->obj_count; i++)
	{
		if (w->objs[i].src == src) return (int32_t) i;
	}
	return -1;
}

static void w3_obj_store(Amf3Wr* w, Avm2Object* src)
{
	if (w3_obj_find(w, src) >= 0) return;
	if (w->obj_count == w->obj_cap)
	{
		uint32_t nc = w->obj_cap == 0 ? 16 : w->obj_cap * 2;
		ObjEntry* g = avm2_alloc(w->ctx, nc * sizeof(ObjEntry));
		memcpy(g, w->objs, w->obj_count * sizeof(ObjEntry));
		w->objs = g;
		w->obj_cap = nc;
	}
	w->objs[w->obj_count++].src = src;
}

static void w3_value(Amf3Wr* w, Avm2Value v);
static void w0_value(Amf3Wr* w, Avm2Value v);

// Ruffle Value::normalize.
static Avm2Value amf_normalize(Avm2Value v)
{
	if (v.kind == AVM2_VALUE_NUMBER)
	{
		int32_t i = (int32_t) v.u.d;
		double rt = (double) i;
		uint64_t a, b;
		memcpy(&a, &v.u.d, 8);
		memcpy(&b, &rt, 8);
		if (a == b && i < (1 << 28) && i >= -(1 << 28))
		{
			return avm2_integer(i);
		}
	}
	else if (v.kind == AVM2_VALUE_INTEGER)
	{
		if (!(v.u.i < (1 << 28) && v.u.i >= -(1 << 28)))
		{
			return avm2_number((double) v.u.i);
		}
	}
	return v;
}

// The class's serializable "static" properties: public slots + full
// accessor pairs, sorted by name (UTF-16 order). Returns count.
static uint32_t collect_static_props(Avm2Context* ctx, Avm2Object* obj,
                                     const Avm2String*** out_names)
{
	const Avm2VTable* vt = obj->vtable;
	uint32_t cap = (vt != NULL) ? vt->count : 0;
	const Avm2String** names = avm2_alloc(ctx, (cap + 1) * sizeof(Avm2String*));
	uint32_t n = 0;
	for (uint32_t i = 0; vt != NULL && i < vt->count; i++)
	{
		const Avm2PropEntry* e = &vt->entries[i];
		if (!avm2_propkey_is_public(&e->key)) continue;
		if (e->kind == AVM2_PROP_METHOD) continue;
		if (e->kind == AVM2_PROP_GETTER || e->kind == AVM2_PROP_SETTER) continue;
		// duplicate keys (alias entries) — skip repeats by name
		int dup = 0;
		for (uint32_t j = 0; j < n; j++)
		{
			if (names[j]->len == e->key.name_len
			    && memcmp(names[j]->utf8, e->key.name, e->key.name_len) == 0)
			{
				dup = 1;
				break;
			}
		}
		if (dup) continue;
		names[n++] = avm2_string_new(ctx, e->key.name, e->key.name_len);
	}
	// Insertion sort by UTF-16 order.
	for (uint32_t i = 1; i < n; i++)
	{
		const Avm2String* key = names[i];
		uint32_t j = i;
		while (j > 0 && avm2_string_utf16_cmp(names[j - 1], key) > 0)
		{
			names[j] = names[j - 1];
			j--;
		}
		names[j] = key;
	}
	*out_names = names;
	return n;
}

static int value_is_function(Avm2Value v)
{
	return v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL
	       && v.u.obj->kind == AVM2_OBJ_FUNCTION;
}

// Generic object body: static values (sorted) then, when dynamic, the
// name/value expando pairs and a terminator (flash-lso write_object_full
// tail shared with write_trait_reference).
static void w3_object_body(Amf3Wr* w, Avm2Object* obj, int dynamic,
                           const Avm2String** statics, uint32_t static_count)
{
	Avm2Context* ctx = w->ctx;
	Avm2Value recv = avm2_object_value(obj);
	for (uint32_t i = 0; i < static_count; i++)
	{
		Avm2Value pv = avm2_get_public_property(ctx, recv, statics[i]->utf8,
		                                        statics[i]->len, NULL);
		w3_value(w, pv);
	}
	if (dynamic)
	{
		uint32_t idx = avm2_object_next_enumerant(obj, 0);
		while (idx != 0)
		{
			Avm2Value name = avm2_object_enumerant_name(ctx, obj, idx);
			Avm2Value val = avm2_object_enumerant_value(ctx, obj, idx);
			if (!value_is_function(val))
			{
				const Avm2String* ns = avm2_coerce_to_string(ctx, name);
				w3_str(w, ns->utf8, ns->len);
				w3_value(w, val);
			}
			idx = avm2_object_next_enumerant(obj, idx);
		}
		w3_str(w, "", 0);
	}
}

static void w3_object(Amf3Wr* w, Avm2Object* obj)
{
	Avm2Context* ctx = w->ctx;
	w3_obj_store(w, obj);

	const Avm2String* alias = class_to_alias(ctx, avm2_value_class(
		ctx, avm2_object_value(obj)));
	int dynamic = 1;
	Avm2Class* cls = obj->cls;
	if (cls != NULL && (cls->flags & AVM2_CLASS_FLAG_SEALED)) dynamic = 0;

	const Avm2String** statics;
	uint32_t static_count = collect_static_props(ctx, obj, &statics);

	// Trait table lookup: name + dynamic + static list.
	int32_t trait_idx = -1;
	for (uint32_t i = 0; i < w->trait_count; i++)
	{
		TraitEntry* t = &w->traits[i];
		if (t->dynamic != dynamic) continue;
		if (!avm2_string_equals(t->name, alias)) continue;
		if (t->static_count != static_count) continue;
		int same = 1;
		for (uint32_t j = 0; j < static_count; j++)
		{
			if (!avm2_string_equals(t->statics[j], statics[j]))
			{
				same = 0;
				break;
			}
		}
		if (!same) continue;
		trait_idx = (int32_t) i;
		break;
	}

	buf_u8(&w->out, M3_OBJECT);
	if (trait_idx >= 0)
	{
		w3_u29(w, (int32_t) ((((uint32_t) trait_idx << 1) << 1) | 1));
	}
	else
	{
		if (w->trait_count == w->trait_cap)
		{
			uint32_t nc = w->trait_cap == 0 ? 8 : w->trait_cap * 2;
			TraitEntry* g = avm2_alloc(ctx, nc * sizeof(TraitEntry));
			memcpy(g, w->traits, w->trait_count * sizeof(TraitEntry));
			w->traits = g;
			w->trait_cap = nc;
		}
		TraitEntry* t = &w->traits[w->trait_count++];
		t->name = alias;
		t->dynamic = dynamic;
		t->static_count = static_count;
		t->statics = statics;

		uint32_t encoding = dynamic ? 0x2 : 0x0;
		uint32_t size = ((((static_count << 2) | encoding) << 1 | 1) << 1) | 1;
		w3_u29(w, (int32_t) size);
		w3_str(w, alias->utf8, alias->len);
		for (uint32_t i = 0; i < static_count; i++)
		{
			w3_str(w, statics[i]->utf8, statics[i]->len);
		}
	}
	w3_object_body(w, obj, dynamic, statics, static_count);
}

static void w3_array(Amf3Wr* w, Avm2Object* arr)
{
	Avm2Context* ctx = w->ctx;
	w3_obj_store(w, arr);

	// Ruffle amf.rs: enumerate everything, splitting entries whose name
	// matches its running position into the dense part.
	uint32_t cap = 8;
	Avm2Value* dense = avm2_alloc(ctx, cap * sizeof(Avm2Value));
	uint32_t dense_n = 0;
	Avm2Value* sp_names = avm2_alloc(ctx, cap * sizeof(Avm2Value));
	Avm2Value* sp_vals = avm2_alloc(ctx, cap * sizeof(Avm2Value));
	uint32_t sp_n = 0;
	uint32_t pos = 0;
	uint32_t idx = avm2_object_next_enumerant(arr, 0);
	while (idx != 0)
	{
		Avm2Value name = avm2_object_enumerant_name(ctx, arr, idx);
		Avm2Value val = avm2_object_enumerant_value(ctx, arr, idx);
		if (dense_n >= cap || sp_n >= cap)
		{
			uint32_t nc = cap * 2;
			Avm2Value* d2 = avm2_alloc(ctx, nc * sizeof(Avm2Value));
			memcpy(d2, dense, dense_n * sizeof(Avm2Value));
			Avm2Value* n2 = avm2_alloc(ctx, nc * sizeof(Avm2Value));
			memcpy(n2, sp_names, sp_n * sizeof(Avm2Value));
			Avm2Value* v2 = avm2_alloc(ctx, nc * sizeof(Avm2Value));
			memcpy(v2, sp_vals, sp_n * sizeof(Avm2Value));
			dense = d2;
			sp_names = n2;
			sp_vals = v2;
			cap = nc;
		}
		// Function-valued entries are skipped BEFORE the dense/sparse
		// position split (Ruffle recursive_serialize filters them out of
		// `values`, and the enumerate() index runs over the filtered list).
		if (value_is_function(val))
		{
			idx = avm2_object_next_enumerant(arr, idx);
			continue;
		}
		const Avm2String* ns = avm2_coerce_to_string(ctx, name);
		char posbuf[16];
		int pn = snprintf(posbuf, sizeof(posbuf), "%u", pos);
		if ((uint32_t) pn == ns->len && memcmp(posbuf, ns->utf8, pn) == 0)
		{
			dense[dense_n++] = val;
		}
		else
		{
			sp_names[sp_n] = avm2_string(ns);
			sp_vals[sp_n] = val;
			sp_n++;
		}
		pos++;
		idx = avm2_object_next_enumerant(arr, idx);
	}

	buf_u8(&w->out, M3_ARRAY);
	w3_u29(w, (int32_t) ((dense_n << 1) | 1));
	for (uint32_t i = 0; i < sp_n; i++)
	{
		const Avm2String* ns = sp_names[i].u.str;
		w3_str(w, ns->utf8, ns->len);
		w3_value(w, sp_vals[i]);
	}
	w3_str(w, "", 0);
	for (uint32_t i = 0; i < dense_n; i++)
	{
		w3_value(w, dense[i]);
	}
}

static void w3_vector(Amf3Wr* w, Avm2Object* vec)
{
	Avm2Context* ctx = w->ctx;
	Avm2Builtins* b = &ctx->builtins;
	Avm2VectorExt* ext = avm2_vector_ext(vec);
	Avm2Class* t = ext->value_type;
	if (t == b->int_class || t == b->uint_class || t == b->number_class)
	{
		// Scalar vectors: looked up in the object table but never stored
		// (flash-lso to_length without store) — always full.
		uint8_t marker = (t == b->int_class) ? M3_VECINT
		                 : (t == b->uint_class) ? M3_VECUINT
		                                        : M3_VECDOUBLE;
		buf_u8(&w->out, marker);
		w3_u29(w, (int32_t) ((ext->length << 1) | 1));
		buf_u8(&w->out, ext->fixed ? 1 : 0);
		for (uint32_t i = 0; i < ext->length; i++)
		{
			if (t == b->number_class)
			{
				buf_f64be(&w->out, avm2_coerce_to_number(ctx, ext->elems[i]));
			}
			else
			{
				buf_u32be(&w->out, (uint32_t) avm2_coerce_to_i32(ctx, ext->elems[i]));
			}
		}
		return;
	}
	// Object vectors participate in the reference table for real.
	int32_t r = w3_obj_find(w, vec);
	buf_u8(&w->out, M3_VECOBJ);
	if (r >= 0)
	{
		w3_u29(w, r << 1);
		return;
	}
	w3_obj_store(w, vec);
	const Avm2String* tname = class_to_alias(
		ctx, (t != NULL) ? t : b->object_class);
	w3_u29(w, (int32_t) ((ext->length << 1) | 1));
	buf_u8(&w->out, ext->fixed ? 1 : 0);
	w3_str(w, tname->utf8, tname->len);
	for (uint32_t i = 0; i < ext->length; i++)
	{
		w3_value(w, ext->elems[i]);
	}
}

static void w3_dictionary(Amf3Wr* w, Avm2Object* dict)
{
	Avm2Context* ctx = w->ctx;
	int32_t r = w3_obj_find(w, dict);
	buf_u8(&w->out, M3_DICT);
	if (r >= 0)
	{
		w3_u29(w, r << 1);
		return;
	}
	w3_obj_store(w, dict);
	uint32_t count = 0;
	uint32_t idx = avm2_object_next_enumerant(dict, 0);
	while (idx != 0)
	{
		count++;
		idx = avm2_object_next_enumerant(dict, idx);
	}
	w3_u29(w, (int32_t) ((count << 1) | 1));
	buf_u8(&w->out, 0);  // weak_keys (unobservable; always strong)
	idx = avm2_object_next_enumerant(dict, 0);
	while (idx != 0)
	{
		w3_value(w, avm2_object_enumerant_name(ctx, dict, idx));
		w3_value(w, avm2_object_enumerant_value(ctx, dict, idx));
		idx = avm2_object_next_enumerant(dict, idx);
	}
}

static void w3_value(Amf3Wr* w, Avm2Value v)
{
	Avm2Context* ctx = w->ctx;
	v = amf_normalize(v);
	switch (v.kind)
	{
		case AVM2_VALUE_UNDEFINED: buf_u8(&w->out, M3_UNDEF); return;
		case AVM2_VALUE_NULL: buf_u8(&w->out, M3_NULL); return;
		case AVM2_VALUE_BOOL: buf_u8(&w->out, v.u.b ? M3_TRUE : M3_FALSE); return;
		case AVM2_VALUE_INTEGER:
			buf_u8(&w->out, M3_INT);
			w3_u29(w, v.u.i);
			return;
		case AVM2_VALUE_NUMBER:
			buf_u8(&w->out, M3_NUM);
			buf_f64be(&w->out, v.u.d);
			return;
		case AVM2_VALUE_STRING:
			buf_u8(&w->out, M3_STR);
			w3_str(w, v.u.str->utf8, v.u.str->len);
			return;
	}
	Avm2Object* obj = v.u.obj;
	if (obj == NULL || obj->kind == AVM2_OBJ_FUNCTION
	    || obj->kind == AVM2_OBJ_CLASS)
	{
		buf_u8(&w->out, M3_UNDEF);
		return;
	}
	if (obj->kind == AVM2_OBJ_ARRAY)
	{
		w3_array(w, obj);
		return;
	}
	if (obj->kind == AVM2_OBJ_VECTOR)
	{
		w3_vector(w, obj);
		return;
	}
	Avm2DateExt* date = avm2_date_ext_of(v);
	if (date != NULL)
	{
		// Dates are never stored in the table (flash-lso to_length-only).
		buf_u8(&w->out, M3_DATE);
		w3_u29(w, 1);  // Size(0)
		buf_f64be(&w->out, date->millis);
		return;
	}
	Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(v);
	if (ba != NULL)
	{
		buf_u8(&w->out, M3_BYTEARRAY);
		w3_u29(w, (int32_t) ((ba->len << 1) | 1));
		buf_put(&w->out, ba->bytes, ba->len);
		return;
	}
	if (avm2_is_dictionary(obj))
	{
		w3_dictionary(w, obj);
		return;
	}
	{
		// XML (not XMLList) writes as XmlString: toXMLString() bytes,
		// prettyPrinting-sensitive (Ruffle amf.rs as_xml_object arm).
		Avm2XmlExt* xe = avm2_xml_ext_of(v);
		if (xe != NULL)
		{
			const Avm2String* xs = avm2_e4x_to_xml_string(w->ctx, xe->node);
			buf_u8(&w->out, M3_XMLSTR);
			w3_u29(w, (int32_t) ((xs->len << 1) | 1));
			buf_put(&w->out, (const uint8_t*) xs->utf8, xs->len);
			return;
		}
	}
	w3_object(w, obj);
}

// ---------------------------------------------------------------------------
// AMF0 writer (flash-lso amf0/write.rs; no reference table on write)
// ---------------------------------------------------------------------------

enum
{
	M0_NUM = 0x00, M0_BOOL = 0x01, M0_STR = 0x02, M0_OBJECT = 0x03,
	M0_NULL = 0x05, M0_UNDEF = 0x06, M0_REF = 0x07, M0_ECMA = 0x08,
	M0_OBJEND = 0x09, M0_STRICT = 0x0A, M0_DATE = 0x0B, M0_LONGSTR = 0x0C,
	M0_UNSUPPORTED = 0x0D, M0_XML = 0x0F, M0_TYPED = 0x10, M0_AMF3 = 0x11,
};

static void w0_short_str(Amf3Wr* w, const char* p, uint32_t n)
{
	buf_u16be(&w->out, (uint16_t) n);
	buf_put(&w->out, p, n);
}

static void w0_object_body(Amf3Wr* w, Avm2Object* obj)
{
	Avm2Context* ctx = w->ctx;
	Avm2Value recv = avm2_object_value(obj);
	const Avm2String** statics;
	uint32_t static_count = collect_static_props(ctx, obj, &statics);
	for (uint32_t i = 0; i < static_count; i++)
	{
		Avm2Value pv = avm2_get_public_property(ctx, recv, statics[i]->utf8,
		                                        statics[i]->len, NULL);
		w0_short_str(w, statics[i]->utf8, statics[i]->len);
		w0_value(w, pv);
	}
	uint32_t idx = avm2_object_next_enumerant(obj, 0);
	while (idx != 0)
	{
		Avm2Value name = avm2_object_enumerant_name(ctx, obj, idx);
		Avm2Value val = avm2_object_enumerant_value(ctx, obj, idx);
		if (!value_is_function(val))
		{
			const Avm2String* ns = avm2_coerce_to_string(ctx, name);
			w0_short_str(w, ns->utf8, ns->len);
			w0_value(w, val);
		}
		idx = avm2_object_next_enumerant(obj, idx);
	}
	buf_u16be(&w->out, 0);
	buf_u8(&w->out, M0_OBJEND);
}

static void w0_value(Amf3Wr* w, Avm2Value v)
{
	Avm2Context* ctx = w->ctx;
	v = amf_normalize(v);
	switch (v.kind)
	{
		case AVM2_VALUE_UNDEFINED: buf_u8(&w->out, M0_UNDEF); return;
		case AVM2_VALUE_NULL: buf_u8(&w->out, M0_NULL); return;
		case AVM2_VALUE_BOOL:
			buf_u8(&w->out, M0_BOOL);
			buf_u8(&w->out, v.u.b ? 1 : 0);
			return;
		case AVM2_VALUE_INTEGER:
			buf_u8(&w->out, M0_NUM);
			buf_f64be(&w->out, (double) v.u.i);
			return;
		case AVM2_VALUE_NUMBER:
			buf_u8(&w->out, M0_NUM);
			buf_f64be(&w->out, v.u.d);
			return;
		case AVM2_VALUE_STRING:
			if (v.u.str->len > 65535)
			{
				buf_u8(&w->out, M0_LONGSTR);
				buf_u32be(&w->out, v.u.str->len);
				buf_put(&w->out, v.u.str->utf8, v.u.str->len);
			}
			else
			{
				buf_u8(&w->out, M0_STR);
				w0_short_str(w, v.u.str->utf8, v.u.str->len);
			}
			return;
	}
	Avm2Object* obj = v.u.obj;
	if (obj == NULL || obj->kind == AVM2_OBJ_FUNCTION
	    || obj->kind == AVM2_OBJ_CLASS)
	{
		buf_u8(&w->out, M0_UNDEF);
		return;
	}
	if (obj->kind == AVM2_OBJ_ARRAY)
	{
		// Ruffle AMF0 arrays: ECMA array, u32 = Array.length, every entry
		// as a named element (dense indices become string names).
		Avm2ArrayExt* ext = avm2_array_ext(obj);
		buf_u8(&w->out, M0_ECMA);
		buf_u32be(&w->out, ext->length);
		uint32_t idx = avm2_object_next_enumerant(obj, 0);
		while (idx != 0)
		{
			Avm2Value name = avm2_object_enumerant_name(ctx, obj, idx);
			Avm2Value val = avm2_object_enumerant_value(ctx, obj, idx);
			if (!value_is_function(val))
			{
				const Avm2String* ns = avm2_coerce_to_string(ctx, name);
				w0_short_str(w, ns->utf8, ns->len);
				w0_value(w, val);
			}
			idx = avm2_object_next_enumerant(obj, idx);
		}
		buf_u16be(&w->out, 0);
		buf_u8(&w->out, M0_OBJEND);
		return;
	}
	Avm2DateExt* date = avm2_date_ext_of(v);
	if (date != NULL)
	{
		buf_u8(&w->out, M0_DATE);
		buf_f64be(&w->out, date->millis);
		buf_u16be(&w->out, 0);
		return;
	}
	if (obj->kind == AVM2_OBJ_VECTOR || avm2_bytearray_ext_of(v) != NULL
	    || avm2_is_dictionary(obj))
	{
		// flash-lso amf0 fallback arm.
		buf_u8(&w->out, M0_UNSUPPORTED);
		return;
	}
	// Anonymous object (Ruffle passes class_def None for AMF0 always).
	buf_u8(&w->out, M0_OBJECT);
	w0_object_body(w, obj);
}

// ---------------------------------------------------------------------------
// AMF3 reader
// ---------------------------------------------------------------------------

typedef struct Rd
{
	Avm2Context* ctx;
	const uint8_t* p;
	uint32_t n;
	uint32_t pos;
	// AMF3 tables.
	const Avm2String** strings;
	uint32_t str_count, str_cap;
	TraitEntry* traits;
	uint32_t trait_count, trait_cap;
	Avm2Value* objs;
	uint32_t obj_count, obj_cap;
	// AMF0 reference table.
	Avm2Value* refs0;
	uint32_t ref0_count, ref0_cap;
} Rd;

static _Noreturn void rd_fail(Rd* r)
{
	avm2_throw_error(r->ctx, r->ctx->builtins.error_class, "Error: Invalid object");
}

static uint8_t rd_u8(Rd* r)
{
	if (r->pos >= r->n) rd_fail(r);
	return r->p[r->pos++];
}

static const uint8_t* rd_bytes(Rd* r, uint32_t n)
{
	if ((uint64_t) r->pos + n > r->n) rd_fail(r);
	const uint8_t* p = r->p + r->pos;
	r->pos += n;
	return p;
}

static uint16_t rd_u16be(Rd* r)
{
	const uint8_t* p = rd_bytes(r, 2);
	return (uint16_t) ((p[0] << 8) | p[1]);
}

static uint32_t rd_u32be(Rd* r)
{
	const uint8_t* p = rd_bytes(r, 4);
	return ((uint32_t) p[0] << 24) | ((uint32_t) p[1] << 16)
	       | ((uint32_t) p[2] << 8) | p[3];
}

static double rd_f64be(Rd* r)
{
	const uint8_t* p = rd_bytes(r, 8);
	uint64_t bits = 0;
	for (int i = 0; i < 8; i++) bits = (bits << 8) | p[i];
	double d;
	memcpy(&d, &bits, 8);
	return d;
}

static uint32_t rd_u29(Rd* r)
{
	uint32_t v = 0;
	for (int i = 0; i < 3; i++)
	{
		uint8_t b = rd_u8(r);
		if (b & 0x80)
		{
			v = (v << 7) | (b & 0x7F);
		}
		else
		{
			return (v << 7) | b;
		}
	}
	return (v << 8) | rd_u8(r);
}

static const Avm2String* rd3_str(Rd* r)
{
	uint32_t u = rd_u29(r);
	if (!(u & 1))
	{
		uint32_t idx = u >> 1;
		if (idx >= r->str_count) rd_fail(r);
		return r->strings[idx];
	}
	uint32_t len = u >> 1;
	const uint8_t* p = rd_bytes(r, len);
	const Avm2String* s = avm2_string_new(r->ctx, (const char*) p, len);
	if (len > 0)
	{
		if (r->str_count == r->str_cap)
		{
			uint32_t nc = r->str_cap == 0 ? 16 : r->str_cap * 2;
			const Avm2String** g = avm2_alloc(r->ctx, nc * sizeof(Avm2String*));
			memcpy(g, r->strings, r->str_count * sizeof(Avm2String*));
			r->strings = g;
			r->str_cap = nc;
		}
		r->strings[r->str_count++] = s;
	}
	return s;
}

static uint32_t rd3_obj_reserve(Rd* r, Avm2Value v)
{
	if (r->obj_count == r->obj_cap)
	{
		uint32_t nc = r->obj_cap == 0 ? 16 : r->obj_cap * 2;
		Avm2Value* g = avm2_alloc(r->ctx, nc * sizeof(Avm2Value));
		memcpy(g, r->objs, r->obj_count * sizeof(Avm2Value));
		r->objs = g;
		r->obj_cap = nc;
	}
	r->objs[r->obj_count] = v;
	return r->obj_count++;
}

static Avm2Value rd3_value(Rd* r);

// Set a deserialized property, catching + tracing errors from setters
// (Ruffle read_object; errors from the STRINGIFICATION propagate).
static void rd_set_prop_guarded(Rd* r, Avm2Value recv, const Avm2String* name,
                                Avm2Value value)
{
	Avm2Context* ctx = r->ctx;
	static const Avm2AbcException catch_any = { 0, 0xFFFFFFFF, 0, 0, 0, 1 };
	Avm2TryFrame tf;
	avm2_try_push_frame(ctx, &tf, &catch_any, 1, NULL);
	tf.op_index = 1;
	if (setjmp(tf.jb) == 0)
	{
		avm2_set_public_property(ctx, recv, name->utf8, name->len, value);
		avm2_try_pop_frame(&tf);
	}
	else
	{
		Avm2Value err = tf.exc;
		avm2_try_pop_frame(&tf);
		const Avm2String* s = avm2_coerce_to_string(ctx, err);
		printf("%.*s\n", (int) s->len, s->utf8);
	}
}

static Avm2Value rd3_read_object(Rd* r)
{
	Avm2Context* ctx = r->ctx;
	uint32_t u = rd_u29(r);
	if (!(u & 1))
	{
		uint32_t idx = u >> 1;
		if (idx >= r->obj_count) rd_fail(r);
		return r->objs[idx];
	}
	TraitEntry* trait;
	if (!(u & 2))
	{
		uint32_t idx = u >> 2;
		if (idx >= r->trait_count) rd_fail(r);
		trait = &r->traits[idx];
	}
	else
	{
		if (u & 4)
		{
			// Externalizable (IExternalizable) — not implemented.
			avm2_fatal("AMF3 readObject: externalizable objects unsupported");
		}
		if (r->trait_count == r->trait_cap)
		{
			uint32_t nc = r->trait_cap == 0 ? 8 : r->trait_cap * 2;
			TraitEntry* g = avm2_alloc(ctx, nc * sizeof(TraitEntry));
			memcpy(g, r->traits, r->trait_count * sizeof(TraitEntry));
			r->traits = g;
			r->trait_cap = nc;
		}
		trait = &r->traits[r->trait_count++];
		trait->dynamic = (u & 8) ? 1 : 0;
		trait->static_count = u >> 4;
		trait->name = rd3_str(r);
		trait->statics = avm2_alloc(ctx, (trait->static_count + 1)
		                                     * sizeof(Avm2String*));
		for (uint32_t i = 0; i < trait->static_count; i++)
		{
			trait->statics[i] = rd3_str(r);
		}
	}

	Avm2Class* cls = (trait->name->len > 0)
		? alias_to_class(trait->name->utf8, trait->name->len)
		: NULL;
	if (cls == NULL) cls = ctx->builtins.object_class;
	Avm2Value objv = avm2_class_construct(ctx, cls, NULL, 0);
	rd3_obj_reserve(r, objv);

	for (uint32_t i = 0; i < trait->static_count; i++)
	{
		Avm2Value v = rd3_value(r);
		rd_set_prop_guarded(r, objv, trait->statics[i], v);
	}
	if (trait->dynamic)
	{
		for (;;)
		{
			const Avm2String* name = rd3_str(r);
			if (name->len == 0) break;
			Avm2Value v = rd3_value(r);
			rd_set_prop_guarded(r, objv, name, v);
		}
	}
	return objv;
}

static Avm2Value rd3_value(Rd* r)
{
	Avm2Context* ctx = r->ctx;
	uint8_t marker = rd_u8(r);
	switch (marker)
	{
		case M3_UNDEF: return avm2_undefined();
		case M3_NULL: return avm2_null();
		case M3_FALSE: return avm2_bool(false);
		case M3_TRUE: return avm2_bool(true);
		case M3_INT:
		{
			uint32_t u = rd_u29(r);
			int32_t v = (int32_t) u;
			if (u & 0x10000000) v -= 0x20000000;
			return avm2_integer(v);
		}
		case M3_NUM: return avm2_number(rd_f64be(r));
		case M3_STR: return avm2_string(rd3_str(r));
		case M3_XMLDOC:
		case M3_XMLSTR:
		{
			uint32_t u = rd_u29(r);
			if (!(u & 1))
			{
				uint32_t idx = u >> 1;
				if (idx >= r->obj_count) rd_fail(r);
				return r->objs[idx];
			}
			uint32_t len = u >> 1;
			const uint8_t* p = rd_bytes(r, len);
			Avm2Value arg = avm2_string(
				avm2_string_new(ctx, (const char*) p, len));
			Avm2Value xml = avm2_class_construct(ctx, ctx->builtins.xml_class,
			                                     &arg, 1);
			rd3_obj_reserve(r, xml);
			return xml;
		}
		case M3_DATE:
		{
			uint32_t u = rd_u29(r);
			if (!(u & 1))
			{
				uint32_t idx = u >> 1;
				if (idx >= r->obj_count) rd_fail(r);
				return r->objs[idx];
			}
			double millis = rd_f64be(r);
			Avm2Value arg = avm2_number(millis);
			Avm2Value d = avm2_class_construct(ctx, ctx->builtins.date_class,
			                                   &arg, 1);
			rd3_obj_reserve(r, d);
			return d;
		}
		case M3_ARRAY:
		{
			uint32_t u = rd_u29(r);
			if (!(u & 1))
			{
				uint32_t idx = u >> 1;
				if (idx >= r->obj_count) rd_fail(r);
				return r->objs[idx];
			}
			uint32_t dense_n = u >> 1;
			Avm2Object* arr = avm2_array_new(ctx, 0);
			Avm2Value arrv = avm2_object_value(arr);
			rd3_obj_reserve(r, arrv);
			// Assoc part first (name/value pairs until the empty name).
			for (;;)
			{
				const Avm2String* name = rd3_str(r);
				if (name->len == 0) break;
				Avm2Value v = rd3_value(r);
				avm2_set_public_property(ctx, arrv, name->utf8, name->len, v);
			}
			for (uint32_t i = 0; i < dense_n; i++)
			{
				avm2_array_set(ctx, arr, i, rd3_value(r));
			}
			return arrv;
		}
		case M3_OBJECT: return rd3_read_object(r);
		case M3_BYTEARRAY:
		{
			uint32_t u = rd_u29(r);
			if (!(u & 1))
			{
				uint32_t idx = u >> 1;
				if (idx >= r->obj_count) rd_fail(r);
				return r->objs[idx];
			}
			uint32_t len = u >> 1;
			const uint8_t* p = rd_bytes(r, len);
			Avm2Value bav = avm2_class_construct(
				ctx, ctx->builtins.bytearray_class, NULL, 0);
			Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(bav);
			avm2_bytearray_set_length_public(ctx, ba, len);
			memcpy(ba->bytes, p, len);
			ba->position = 0;
			rd3_obj_reserve(r, bav);
			return bav;
		}
		case M3_VECINT:
		case M3_VECUINT:
		case M3_VECDOUBLE:
		{
			uint32_t u = rd_u29(r);
			if (!(u & 1))
			{
				uint32_t idx = u >> 1;
				if (idx >= r->obj_count) rd_fail(r);
				return r->objs[idx];
			}
			uint32_t count = u >> 1;
			int fixed = rd_u8(r) != 0;
			Avm2Class* t = (marker == M3_VECINT) ? ctx->builtins.int_class
			               : (marker == M3_VECUINT)
			                   ? ctx->builtins.uint_class
			                   : ctx->builtins.number_class;
			Avm2Class* vc = avm2_vector_apply(ctx, t);
			Avm2Object* vec = avm2_vector_new(ctx, vc, count, 0);
			Avm2Value vv = avm2_object_value(vec);
			rd3_obj_reserve(r, vv);
			Avm2VectorExt* ext = avm2_vector_ext(vec);
			for (uint32_t i = 0; i < count; i++)
			{
				if (marker == M3_VECDOUBLE)
				{
					ext->elems[i] = avm2_number(rd_f64be(r));
				}
				else if (marker == M3_VECUINT)
				{
					ext->elems[i] = avm2_uint_value(rd_u32be(r));
				}
				else
				{
					ext->elems[i] = avm2_integer((int32_t) rd_u32be(r));
				}
			}
			ext->fixed = fixed ? 1 : 0;
			return vv;
		}
		case M3_VECOBJ:
		{
			uint32_t u = rd_u29(r);
			if (!(u & 1))
			{
				uint32_t idx = u >> 1;
				if (idx >= r->obj_count) rd_fail(r);
				return r->objs[idx];
			}
			uint32_t count = u >> 1;
			int fixed = rd_u8(r) != 0;
			const Avm2String* tname = rd3_str(r);
			Avm2Class* t = (tname->len > 0)
				? alias_to_class(tname->utf8, tname->len)
				: NULL;
			if (t == NULL) t = ctx->builtins.object_class;
			Avm2Class* vc = avm2_vector_apply(ctx, t);
			Avm2Object* vec = avm2_vector_new(ctx, vc, count, 0);
			Avm2Value vv = avm2_object_value(vec);
			rd3_obj_reserve(r, vv);
			Avm2VectorExt* ext = avm2_vector_ext(vec);
			for (uint32_t i = 0; i < count; i++)
			{
				Avm2Value v = rd3_value(r);
				// No Vector.<void>: Undefined items become Null.
				if (v.kind == AVM2_VALUE_UNDEFINED) v = avm2_null();
				ext->elems[i] = v;
			}
			ext->fixed = fixed ? 1 : 0;
			return vv;
		}
		case M3_DICT:
		{
			uint32_t u = rd_u29(r);
			if (!(u & 1))
			{
				uint32_t idx = u >> 1;
				if (idx >= r->obj_count) rd_fail(r);
				return r->objs[idx];
			}
			uint32_t count = u >> 1;
			Avm2Value weak = avm2_bool(rd_u8(r) != 0);
			Avm2Value dv = avm2_class_construct(
				ctx, ctx->builtins.dictionary_class, &weak, 1);
			rd3_obj_reserve(r, dv);
			for (uint32_t i = 0; i < count; i++)
			{
				Avm2Value key = rd3_value(r);
				Avm2Value val = rd3_value(r);
				if (key.kind == AVM2_VALUE_OBJECT)
				{
					avm2_object_set_dynamic_obj(ctx, dv.u.obj, key.u.obj, val);
				}
				else
				{
					const Avm2String* ks = avm2_coerce_to_string(ctx, key);
					avm2_object_set_dynamic(ctx, dv.u.obj, ks->utf8, ks->len,
					                        val);
				}
			}
			return dv;
		}
		default:
			rd_fail(r);
	}
}

// ---------------------------------------------------------------------------
// AMF0 reader
// ---------------------------------------------------------------------------

static Avm2Value rd0_value(Rd* r);

static uint32_t rd0_ref_reserve(Rd* r, Avm2Value v)
{
	if (r->ref0_count == r->ref0_cap)
	{
		uint32_t nc = r->ref0_cap == 0 ? 16 : r->ref0_cap * 2;
		Avm2Value* g = avm2_alloc(r->ctx, nc * sizeof(Avm2Value));
		memcpy(g, r->refs0, r->ref0_count * sizeof(Avm2Value));
		r->refs0 = g;
		r->ref0_cap = nc;
	}
	r->refs0[r->ref0_count] = v;
	return r->ref0_count++;
}

static const Avm2String* rd0_short_str(Rd* r)
{
	uint16_t len = rd_u16be(r);
	const uint8_t* p = rd_bytes(r, len);
	return avm2_string_new(r->ctx, (const char*) p, len);
}

// name/value pairs terminated by "" + ObjectEnd, applied to recv.
static void rd0_pairs_into(Rd* r, Avm2Value recv)
{
	Avm2Context* ctx = r->ctx;
	(void) ctx;
	for (;;)
	{
		const Avm2String* name = rd0_short_str(r);
		if (name->len == 0)
		{
			uint8_t end = rd_u8(r);
			if (end != M0_OBJEND) rd_fail(r);
			break;
		}
		Avm2Value v = rd0_value(r);
		rd_set_prop_guarded(r, recv, name, v);
	}
}

static Avm2Value rd0_value(Rd* r)
{
	Avm2Context* ctx = r->ctx;
	uint8_t marker = rd_u8(r);
	switch (marker)
	{
		case M0_NUM: return avm2_number(rd_f64be(r));
		case M0_BOOL: return avm2_bool(rd_u8(r) != 0);
		case M0_STR: return avm2_string(rd0_short_str(r));
		case M0_LONGSTR:
		case M0_XML:
		{
			uint32_t len = rd_u32be(r);
			const uint8_t* p = rd_bytes(r, len);
			return avm2_string(avm2_string_new(ctx, (const char*) p, len));
		}
		case M0_NULL: return avm2_null();
		case M0_UNDEF: return avm2_undefined();
		case M0_REF:
		{
			uint16_t idx = rd_u16be(r);
			if (idx >= r->ref0_count) rd_fail(r);
			return r->refs0[idx];
		}
		case M0_OBJECT:
		{
			Avm2Value obj = avm2_class_construct(
				ctx, ctx->builtins.object_class, NULL, 0);
			rd0_ref_reserve(r, obj);
			rd0_pairs_into(r, obj);
			return obj;
		}
		case M0_TYPED:
		{
			const Avm2String* name = rd0_short_str(r);
			Avm2Class* cls = (name->len > 0)
				? alias_to_class(name->utf8, name->len)
				: NULL;
			if (cls == NULL) cls = ctx->builtins.object_class;
			Avm2Value obj = avm2_class_construct(ctx, cls, NULL, 0);
			rd0_ref_reserve(r, obj);
			rd0_pairs_into(r, obj);
			return obj;
		}
		case M0_ECMA:
		{
			(void) rd_u32be(r);  // declared length (ignored on read)
			Avm2Object* arr = avm2_array_new(ctx, 0);
			Avm2Value arrv = avm2_object_value(arr);
			rd0_ref_reserve(r, arrv);
			for (;;)
			{
				const Avm2String* name = rd0_short_str(r);
				if (name->len == 0)
				{
					uint8_t end = rd_u8(r);
					if (end != M0_OBJEND) rd_fail(r);
					break;
				}
				Avm2Value v = rd0_value(r);
				avm2_set_public_property(ctx, arrv, name->utf8, name->len, v);
			}
			return arrv;
		}
		case M0_STRICT:
		{
			uint32_t count = rd_u32be(r);
			Avm2Object* arr = avm2_array_new(ctx, 0);
			Avm2Value arrv = avm2_object_value(arr);
			rd0_ref_reserve(r, arrv);
			for (uint32_t i = 0; i < count; i++)
			{
				avm2_array_set(ctx, arr, i, rd0_value(r));
			}
			return arrv;
		}
		case M0_DATE:
		{
			double millis = rd_f64be(r);
			(void) rd_u16be(r);  // timezone
			Avm2Value arg = avm2_number(millis);
			return avm2_class_construct(ctx, ctx->builtins.date_class, &arg, 1);
		}
		case M0_UNSUPPORTED: return avm2_undefined();
		case M0_AMF3: return rd3_value(r);
		default:
			rd_fail(r);
	}
}

// ---------------------------------------------------------------------------
// ByteArray natives
// ---------------------------------------------------------------------------

Avm2Value avm2_amf_write_object(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(act->this_val);
	if (ba == NULL) return avm2_undefined();
	Avm2Value obj = (act->argc > 0) ? act->args[0] : avm2_undefined();

	Amf3Wr w;
	memset(&w, 0, sizeof(w));
	w.ctx = ctx;
	w.out.ctx = ctx;
	if (ba->object_encoding == 0)
	{
		w0_value(&w, obj);
	}
	else
	{
		w3_value(&w, obj);
	}
	// Append at the cursor like any other write.
	extern void avm2_bytearray_set_length_public(Avm2Context*, Avm2ByteArrayExt*, uint32_t);
	uint32_t pos = ba->position;
	if (ba->len < pos + w.out.len)
	{
		avm2_bytearray_set_length_public(ctx, ba, pos + w.out.len);
	}
	memcpy(ba->bytes + pos, w.out.b, w.out.len);
	ba->position = pos + w.out.len;
	return avm2_undefined();
}

Avm2Value avm2_amf_read_object(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(act->this_val);
	if (ba == NULL) return avm2_undefined();
	Rd r;
	memset(&r, 0, sizeof(r));
	r.ctx = ctx;
	r.p = ba->bytes;
	r.n = ba->len;
	r.pos = ba->position;
	Avm2Value v = (ba->object_encoding == 0) ? rd0_value(&r) : rd3_value(&r);
	ba->position = r.pos;
	return v;
}

// ---------------------------------------------------------------------------
// flash.net toplevel + registration
// ---------------------------------------------------------------------------

static Avm2Value net_register_class_alias(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc < 2 || act->args[0].kind == AVM2_VALUE_NULL
	    || act->args[0].kind == AVM2_VALUE_UNDEFINED)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter aliasName must be non-null.");
	}
	const Avm2String* alias = avm2_coerce_to_string(ctx, act->args[0]);
	if (act->args[1].kind != AVM2_VALUE_OBJECT
	    || act->args[1].u.obj->kind != AVM2_OBJ_CLASS)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter classObject must be non-null.");
	}
	Avm2Class* cls = act->args[1].u.obj->class_ref;
	// Re-registering an alias replaces the class.
	for (AliasEntry* a = g_aliases; a != NULL; a = a->next)
	{
		if (avm2_string_equals(a->alias, alias))
		{
			a->cls = cls;
			return avm2_undefined();
		}
	}
	AliasEntry* a = avm2_alloc(ctx, sizeof(AliasEntry));
	a->alias = alias;
	a->cls = cls;
	a->next = g_aliases;
	g_aliases = a;
	return avm2_undefined();
}

static Avm2Value net_get_class_by_alias(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->argc < 1 || act->args[0].kind == AVM2_VALUE_NULL
	    || act->args[0].kind == AVM2_VALUE_UNDEFINED)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter aliasName must be non-null.");
	}
	const Avm2String* alias = avm2_coerce_to_string(ctx, act->args[0]);
	Avm2Class* cls = alias_to_class(alias->utf8, alias->len);
	if (cls == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.reference_error_class,
		                 "Error #1014: Class %.*s could not be found.",
		                 (int) alias->len, alias->utf8);
	}
	return avm2_object_value(cls->class_object);
}

// ---------------------------------------------------------------------------
// flash.net.SharedObject (Stage 10). Minimal in-process model: getLocal(name)
// returns a per-name SharedObject whose `data` is a dynamic Object. Persistence
// to a .sol file + AMF `size` accounting are NOT modeled (the full shared_object
// test needs the two-run .sol harness); flush reports "flushed" so the common
// getLocal/data/flush path works (shared_object_no_root).
// ---------------------------------------------------------------------------

typedef struct Avm2SharedObjectExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Object* data;                   // dynamic Object
} Avm2SharedObjectExt;

static Avm2Class* g_shared_object_class;

static Avm2Object* this_obj_amf(Avm2Activation* act)
{
	return act->this_val.kind == AVM2_VALUE_OBJECT ? act->this_val.u.obj : NULL;
}

typedef struct SoCacheEntry { char* name; Avm2Object* obj; } SoCacheEntry;
static SoCacheEntry g_so_cache[64];
static uint32_t g_so_cache_count;

static Avm2SharedObjectExt* so_ext_of(Avm2Context* ctx, Avm2Object* o)
{
	if (o == NULL || o->cls == NULL || g_shared_object_class == NULL) return NULL;
	for (const Avm2Class* c = o->cls; c != NULL; c = c->super_class)
		if (c == g_shared_object_class) return (Avm2SharedObjectExt*) o->native_ext;
	return NULL;
}

static Avm2Object* so_new_data(Avm2Context* ctx)
{
	Avm2Value v = avm2_class_construct(ctx, ctx->builtins.object_class, NULL, 0);
	return v.u.obj;
}

static Avm2Value so_get_local(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	const Avm2String* name = act->argc > 0
		? avm2_coerce_to_string(ctx, act->args[0])
		: avm2_string_from_literal(ctx, "");
	// Same-run identity: return the cached instance for this name.
	for (uint32_t i = 0; i < g_so_cache_count; i++)
	{
		if (strncmp(g_so_cache[i].name, name->utf8, name->len) == 0
		    && g_so_cache[i].name[name->len] == '\0')
			return avm2_object_value(g_so_cache[i].obj);
	}
	Avm2Value v = avm2_class_construct(ctx, g_shared_object_class, NULL, 0);
	Avm2SharedObjectExt* ext = so_ext_of(ctx, v.u.obj);
	if (ext != NULL && ext->data == NULL) ext->data = so_new_data(ctx);
	if (g_so_cache_count < 64)
	{
		char* copy = avm2_alloc(ctx, name->len + 1);
		memcpy(copy, name->utf8, name->len);
		copy[name->len] = '\0';
		g_so_cache[g_so_cache_count].name = copy;
		g_so_cache[g_so_cache_count].obj = v.u.obj;
		g_so_cache_count++;
	}
	return v;
}

static Avm2Value so_get_data(Avm2Activation* act)
{
	Avm2SharedObjectExt* ext = so_ext_of(act->ctx, this_obj_amf(act));
	if (ext == NULL) return avm2_undefined();
	if (ext->data == NULL) ext->data = so_new_data(act->ctx);
	return avm2_object_value(ext->data);
}

static Avm2Value so_get_size(Avm2Activation* act)
{
	(void) act;
	return avm2_uint_value(0);
}

static Avm2Value so_flush(Avm2Activation* act)
{
	// SharedObjectFlushStatus.FLUSHED
	return avm2_string(avm2_string_from_literal(act->ctx, "flushed"));
}

static Avm2Value so_clear(Avm2Activation* act)
{
	Avm2SharedObjectExt* ext = so_ext_of(act->ctx, this_obj_amf(act));
	if (ext != NULL) ext->data = so_new_data(act->ctx);
	return avm2_undefined();
}

static Avm2Value so_noop(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

void avm2_register_amf(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;
	g_aliases = NULL;

	// flash.net toplevel functions (package-qualified keys).
	{
		Avm2PropKey key;
		key.ns_kind = 0x16;
		key.ns_uri = "flash.net";
		key.ns_len = 9;
		key.name = "registerClassAlias";
		key.name_len = 18;
		Avm2Object* fn = avm2_function_new(
			ctx, &(Avm2MethodRef) { net_register_class_alias, NULL,
			                        "registerClassAlias", 0 },
			NULL, NULL, avm2_undefined(), false);
		avm2_builtin_define_alias(ctx, key, avm2_object_value(fn));
		key.name = "getClassByAlias";
		key.name_len = 15;
		fn = avm2_function_new(
			ctx, &(Avm2MethodRef) { net_get_class_by_alias, NULL,
			                        "getClassByAlias", 0 },
			NULL, NULL, avm2_undefined(), false);
		avm2_builtin_define_alias(ctx, key, avm2_object_value(fn));
	}

	// flash.net.ObjectEncoding constants.
	{
		Avm2Class* oe = avm2_builtin_class(ctx, "flash.net", "ObjectEncoding",
		                                   b->object_class);
		avm2_builtin_add_static_const(ctx, oe, "AMF0", avm2_uint_value(0));
		avm2_builtin_add_static_const(ctx, oe, "AMF3", avm2_uint_value(3));
		avm2_builtin_add_static_const(ctx, oe, "DEFAULT", avm2_uint_value(3));
	}

	// flash.net.SharedObject (extends EventDispatcher).
	{
		g_so_cache_count = 0;
		Avm2Class* so = avm2_builtin_class(ctx, "flash.net", "SharedObject",
		                                   b->event_dispatcher_class);
		so->native_ext_size = sizeof(Avm2SharedObjectExt);
		g_shared_object_class = so;
		avm2_builtin_add_static_method(ctx, so, "getLocal", so_get_local);
		avm2_builtin_add_static_method(ctx, so, "getRemote", so_get_local);
		avm2_builtin_add_getset(ctx, so, "data", so_get_data, NULL);
		avm2_builtin_add_getset(ctx, so, "size", so_get_size, NULL);
		avm2_builtin_add_method(ctx, so, "flush", so_flush);
		avm2_builtin_add_method(ctx, so, "clear", so_clear);
		avm2_builtin_add_method(ctx, so, "close", so_noop);
		avm2_builtin_add_method(ctx, so, "setProperty", so_noop);
	}

	// Upgrade the Date stub: millis state + the members AMF needs.
	{
		Avm2Class* date = b->date_class;
		date->native_ext_size = sizeof(Avm2DateExt);
		date->native_init = date_native_init;
		date->instance_init.fn = date_init;
		date->instance_init.debug_name = "Date";
		avm2_builtin_add_method(ctx, date, "getTime", date_get_time);
		avm2_builtin_add_method(ctx, date, "valueOf", date_value_of);
		avm2_builtin_add_method(ctx, date, "toString", date_to_string);
		avm2_proto_add_function(ctx, date->prototype_obj, "toString",
		                        date_to_string);
		avm2_proto_add_function(ctx, date->prototype_obj, "valueOf",
		                        date_value_of);
	}
}
