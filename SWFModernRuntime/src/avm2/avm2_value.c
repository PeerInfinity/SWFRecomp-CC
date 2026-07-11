// Avm2Value constructors + coercions (port of Ruffle core/src/avm2/value.rs;
// helper names 1:1 with Ruffle's methods). Stage 2 implements the cases
// hello_world exercises completely; f64 formatting is minimal (Stage 3 TODO:
// full avmplus MAX_PRECISION decimal/exponent rules from value.rs).

#include <stdio.h>
#include <string.h>
#include <math.h>

#include <avm2/avm2_value.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_main.h>

_Static_assert(sizeof(Avm2Value) == 16, "Avm2Value must be 16 bytes (plan §4.2)");

Avm2Value avm2_undefined(void)
{
	Avm2Value v = { AVM2_VALUE_UNDEFINED, 0, { 0 } };
	return v;
}

Avm2Value avm2_null(void)
{
	Avm2Value v = { AVM2_VALUE_NULL, 0, { 0 } };
	return v;
}

Avm2Value avm2_bool(bool b)
{
	Avm2Value v = { AVM2_VALUE_BOOL, 0, { 0 } };
	v.u.b = b;
	return v;
}

Avm2Value avm2_integer(int32_t i)
{
	Avm2Value v = { AVM2_VALUE_INTEGER, 0, { 0 } };
	v.u.i = i;
	return v;
}

Avm2Value avm2_number(double d)
{
	Avm2Value v = { AVM2_VALUE_NUMBER, 0, { 0 } };
	v.u.d = d;
	return v;
}

Avm2Value avm2_string(const Avm2String* s)
{
	Avm2Value v = { AVM2_VALUE_STRING, 0, { 0 } };
	v.u.str = s;
	return v;
}

Avm2Value avm2_object_value(Avm2Object* obj)
{
	Avm2Value v = { AVM2_VALUE_OBJECT, 0, { 0 } };
	v.u.obj = obj;
	return v;
}

const Avm2String* avm2_string_new(Avm2Context* ctx, const char* utf8, uint32_t len)
{
	Avm2String* s = avm2_alloc(ctx, sizeof(Avm2String) + len + 1);
	char* bytes = (char*) (s + 1);
	memcpy(bytes, utf8, len);
	bytes[len] = '\0';
	s->len = len;
	s->utf8 = bytes;
	return s;
}

static const Avm2String* string_from_literal(Avm2Context* ctx, const char* lit)
{
	return avm2_string_new(ctx, lit, (uint32_t) strlen(lit));
}

const Avm2String* avm2_coerce_to_string(Avm2Context* ctx, Avm2Value v)
{
	char buf[64];
	switch (v.kind)
	{
		case AVM2_VALUE_UNDEFINED:
			return string_from_literal(ctx, "undefined");
		case AVM2_VALUE_NULL:
			return string_from_literal(ctx, "null");
		case AVM2_VALUE_BOOL:
			return string_from_literal(ctx, v.u.b ? "true" : "false");
		case AVM2_VALUE_INTEGER:
			snprintf(buf, sizeof(buf), "%d", v.u.i);
			return string_from_literal(ctx, buf);
		case AVM2_VALUE_NUMBER:
		{
			double d = v.u.d;
			if (isnan(d)) return string_from_literal(ctx, "NaN");
			if (d == 0.0) return string_from_literal(ctx, "0");
			if (isinf(d)) return string_from_literal(ctx, d < 0 ? "-Infinity" : "Infinity");
			if (d == (double) (int64_t) d && d >= -9007199254740992.0 && d <= 9007199254740992.0)
			{
				snprintf(buf, sizeof(buf), "%lld", (long long) d);
				return string_from_literal(ctx, buf);
			}
			// Stage 3 TODO: avmplus 15-significant-digit decimal/exponent
			// formatting (value.rs coerce_to_string Number arm).
			snprintf(buf, sizeof(buf), "%.15g", d);
			return string_from_literal(ctx, buf);
		}
		case AVM2_VALUE_STRING:
			return v.u.str;
		case AVM2_VALUE_OBJECT:
		{
			// Stage 3 TODO: call the object's toString(). Minimal
			// "[object Class]" per Object.prototype.toString.
			Avm2Object* obj = v.u.obj;
			const char* cname = (obj != NULL && obj->cls != NULL && obj->cls->name.name != NULL)
			                    ? obj->cls->name.name : "Object";
			if (obj != NULL && obj->kind == AVM2_OBJ_FUNCTION)
			{
				return string_from_literal(ctx, "function Function() {}");
			}
			snprintf(buf, sizeof(buf), "[object %s]", cname);
			return string_from_literal(ctx, buf);
		}
	}
	return string_from_literal(ctx, "undefined");
}

bool avm2_coerce_to_boolean(Avm2Value v)
{
	switch (v.kind)
	{
		case AVM2_VALUE_UNDEFINED:
		case AVM2_VALUE_NULL:
			return false;
		case AVM2_VALUE_BOOL:
			return v.u.b;
		case AVM2_VALUE_INTEGER:
			return v.u.i != 0;
		case AVM2_VALUE_NUMBER:
			return !isnan(v.u.d) && v.u.d != 0.0;
		case AVM2_VALUE_STRING:
			return v.u.str != NULL && v.u.str->len > 0;
		case AVM2_VALUE_OBJECT:
			return true;
	}
	return false;
}

int32_t avm2_coerce_to_i32(Avm2Value v)
{
	switch (v.kind)
	{
		case AVM2_VALUE_INTEGER:
			return v.u.i;
		case AVM2_VALUE_BOOL:
			return v.u.b ? 1 : 0;
		case AVM2_VALUE_NUMBER:
		{
			// ECMA ToInt32 (value.rs coerce_to_i32); Stage 2 covers the
			// finite in-range cases only.
			double d = v.u.d;
			if (isnan(d) || isinf(d)) return 0;
			return (int32_t) (int64_t) fmod(d, 4294967296.0);
		}
		default:
			// Stage 3: string parsing, object valueOf.
			return 0;
	}
}
