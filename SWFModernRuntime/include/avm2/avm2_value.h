#ifndef AVM2_VALUE_H
#define AVM2_VALUE_H

// Avm2Value — the AVM2 tagged value type (avm2-support-plan §4.2).
//
// 16 bytes, mirroring Ruffle's core/src/avm2/value.rs Value enum (Ruffle
// asserts the same size). Deliberately a DIFFERENT type from AVM1's
// ActionVar: the two VMs never share values except through interop shims
// (much later). Kept in its own small header so a late reshape after
// upstream (LittleCube) feedback stays cheap.
//
// Number/Integer duality (avmplus): i32-representable numbers canonicalize
// to AVM2_VALUE_INTEGER where the source pushes them that way (PushInt);
// arithmetic promoting to f64 is a Stage 3 concern. Coercion helpers are
// named 1:1 with Ruffle's value.rs methods (coerce_to_string, ...).

#include <stdbool.h>
#include <stdint.h>

typedef struct Avm2Object Avm2Object;
typedef struct Avm2Context Avm2Context;

// Interned or heap string: UTF-8 bytes + explicit length (ABC strings may
// embed NULs). Static pool entries are emitted by the recompiler; runtime
// strings are heap-allocated. `utf8` is also NUL-terminated for printf
// convenience wherever the runtime creates one; pool entries emitted by
// the recompiler are NUL-terminated too (string literals).
typedef struct Avm2String
{
	uint32_t len;
	const char* utf8;
} Avm2String;

typedef enum Avm2ValueKind
{
	AVM2_VALUE_UNDEFINED = 0,
	AVM2_VALUE_NULL = 1,
	AVM2_VALUE_BOOL = 2,
	AVM2_VALUE_INTEGER = 3,
	AVM2_VALUE_NUMBER = 4,
	AVM2_VALUE_STRING = 5,
	AVM2_VALUE_OBJECT = 6,
} Avm2ValueKind;

typedef struct Avm2Value
{
	uint32_t kind;   // Avm2ValueKind
	uint32_t _pad;
	union
	{
		bool b;
		int32_t i;
		double d;
		const Avm2String* str;
		Avm2Object* obj;
	} u;
} Avm2Value;

// Constructors
Avm2Value avm2_undefined(void);
Avm2Value avm2_null(void);
Avm2Value avm2_bool(bool b);
Avm2Value avm2_integer(int32_t i);
Avm2Value avm2_number(double d);
Avm2Value avm2_string(const Avm2String* s);
Avm2Value avm2_object_value(Avm2Object* obj);

// Coercions (port of Ruffle value.rs semantics; only the cases Stage 2
// needs are complete — number formatting is minimal with a Stage 3 TODO).
// coerce_to_string returns a heap or interned Avm2String, never NULL.
const Avm2String* avm2_coerce_to_string(Avm2Context* ctx, Avm2Value v);
bool avm2_coerce_to_boolean(Avm2Value v);
int32_t avm2_coerce_to_i32(Avm2Value v);

// Heap string helper (copies bytes, NUL-terminates).
const Avm2String* avm2_string_new(Avm2Context* ctx, const char* utf8, uint32_t len);

#endif // AVM2_VALUE_H
