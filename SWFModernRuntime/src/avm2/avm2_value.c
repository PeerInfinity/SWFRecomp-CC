// Avm2Value constructors + coercions + abstract operators (port of Ruffle
// core/src/avm2/value.rs; helper names 1:1 with Ruffle's methods).
// Number-to-string follows value.rs's coerce_to_string Number arm:
// shortest round-trip decimal inside [1e-6, 1e21), MAX_PRECISION (15)
// exponential outside it.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avm2/avm2_value.h>
#include <avm2/avm2_e4x.h>
#include <avm2/avm2_gc.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_ops.h>

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

Avm2Value avm2_uint_value(uint32_t u)
{
	if (u <= 0x7fffffffu)
	{
		return avm2_integer((int32_t) u);
	}
	return avm2_number((double) u);
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
	avm2_gc_enroll_string(s);
	return s;
}

const Avm2String* avm2_string_from_literal(Avm2Context* ctx, const char* lit)
{
	return avm2_string_new(ctx, lit, (uint32_t) strlen(lit));
}

const Avm2String* avm2_string_concat(Avm2Context* ctx, const Avm2String* a, const Avm2String* b)
{
	Avm2String* s = avm2_alloc(ctx, sizeof(Avm2String) + a->len + b->len + 1);
	char* bytes = (char*) (s + 1);
	memcpy(bytes, a->utf8, a->len);
	memcpy(bytes + a->len, b->utf8, b->len);
	bytes[a->len + b->len] = '\0';
	s->len = a->len + b->len;
	s->utf8 = bytes;
	avm2_gc_enroll_string(s);
	return s;
}

bool avm2_string_equals(const Avm2String* a, const Avm2String* b)
{
	if (a == b) return true;
	if (a == NULL || b == NULL) return false;
	return a->len == b->len && memcmp(a->utf8, b->utf8, a->len) == 0;
}

// ---------------------------------------------------------------------------
// ECMA f64 → int conversions (Ruffle ecma_conversions.rs)
// ---------------------------------------------------------------------------

uint32_t avm2_f64_to_wrapping_u32(double n)
{
	if (!isfinite(n)) return 0;
	double t = trunc(n);
	double r = fmod(t, 4294967296.0);
	if (r < 0.0) r += 4294967296.0;
	return (uint32_t) r;
}

int32_t avm2_f64_to_wrapping_i32(double n)
{
	return (int32_t) avm2_f64_to_wrapping_u32(n);
}

// ---------------------------------------------------------------------------
// String → number parsing (Ruffle value.rs string_to_int / string_to_f64)
// ---------------------------------------------------------------------------

static bool is_space_cp(unsigned char c)
{
	// ASCII whitespace subset of Ruffle's list (the Unicode spaces are
	// multi-byte UTF-8; the corpus is ASCII here).
	return c == 0x20 || c == 0x09 || c == 0x0d || c == 0x0a || c == 0x0c || c == 0x0b;
}

static void skip_spaces(const char** s, const char* end)
{
	while (*s < end && is_space_cp((unsigned char) **s)) (*s)++;
}

static bool parse_sign(const char** s, const char* end)
{
	if (*s < end && **s == '-') { (*s)++; return true; }
	if (*s < end && **s == '+') { (*s)++; return false; }
	return false;
}

static int digit_value(char c, int radix)
{
	int d;
	if (c >= '0' && c <= '9') d = c - '0';
	else if (c >= 'a' && c <= 'z') d = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z') d = c - 'A' + 10;
	else return -1;
	return d < radix ? d : -1;
}

double avm2_string_to_int(const char* s, uint32_t len, int32_t radix, bool strict)
{
	const char* p = s;
	const char* end = s + len;
	skip_spaces(&p, end);
	bool neg = parse_sign(&p, end);

	if (radix == 16 || radix == 0)
	{
		if (end - p >= 2 && p[0] == '0' && (p[1] == 'x' || p[1] == 'X'))
		{
			p += 2;
			radix = 16;
		}
		else if (radix == 0)
		{
			radix = 10;
		}
	}
	if (radix < 2 || radix > 36 || p >= end) return NAN;

	double result = 0.0;
	const char* start = p;
	while (p < end)
	{
		int d = digit_value(*p, radix);
		if (d < 0) break;
		result = result * (double) radix + (double) d;
		p++;
	}
	if (p == start) return NAN;

	if (strict)
	{
		skip_spaces(&p, end);
		if (p < end) return NAN;
	}
	return neg ? -result : result;
}


// LLVM __powidf2 (f64::powi): binary exponentiation, NOT correctly
// rounded — Ruffle's string_to_f64 uses powi, and the 1-ulp differences
// are observable (coerce_string_precision).
static double f64_powi(double a, int32_t b)
{
	const int recip = b < 0;
	double r = 1.0;
	uint32_t ub = (uint32_t) (recip ? -(int64_t) b : b);
	for (;;)
	{
		if (ub & 1u) r *= a;
		ub >>= 1;
		if (ub == 0) break;
		a *= a;
	}
	return recip ? 1.0 / r : r;
}

bool avm2_string_to_f64(const char* s, uint32_t len, bool strict, double* out_d)
{
	const char* p = s;
	const char* end = s + len;
	skip_spaces(&p, end);

	if (p >= end)
	{
		if (strict) { *out_d = 0.0; return true; }
		return false;
	}

	bool neg = parse_sign(&p, end);
	const char* after_sign = p;

	// Digits before the decimal point.
	while (p < end && *p >= '0' && *p <= '9') p++;
	int total_digits = (int) (p - after_sign);

	// Digits after the decimal point.
	if (p < end && *p == '.')
	{
		p++;
		const char* frac_start = p;
		while (p < end && *p >= '0' && *p <= '9') p++;
		total_digits += (int) (p - frac_start);
	}

	// Exponent.
	int32_t exponent = 0;
	if (p < end && (*p == 'e' || *p == 'E'))
	{
		p++;
		bool exp_neg = parse_sign(&p, end);
		if (exp_neg && p >= end) return false;
		while (p < end && *p >= '0' && *p <= '9')
		{
			exponent = exponent * 10 + (*p - '0');
			p++;
		}
		if (exp_neg) exponent = -exponent;
	}

	skip_spaces(&p, end);

	if (total_digits == 0)
	{
		// Infinity / -Infinity.
		if (end - p >= 8 && memcmp(p, "Infinity", 8) == 0)
		{
			const char* q = p + 8;
			if (q < end)
			{
				const char* q2 = q;
				skip_spaces(&q2, end);
				if (q2 == q) return false;  // trailing garbage, no space
			}
			*out_d = neg ? -INFINITY : INFINITY;
			return true;
		}
		return false;
	}

	if (strict && p < end && *p != '\0') return false;

	// Accumulate over the consumed span only (SWF >= 11 semantics).
	const char* span_end = p;

	double result = 0.0;
	int decimal_digits = -1;
	if (total_digits > 15)
	{
		// avmplus builds the digit string as an exact integer (BigInt in
		// Ruffle) and converts once; strtod of the digits WITHOUT the dot
		// reproduces that single rounding, then the decimal shift below
		// applies in float exactly like Ruffle.
		char tmp[400];
		const char* q = after_sign;
		int ti = 0;
		while (q < span_end
		       && ((*q >= '0' && *q <= '9') || *q == '.'))
		{
			if (*q == '.')
			{
				decimal_digits = 0;
			}
			else
			{
				if (decimal_digits >= 0) decimal_digits++;
				if (ti < 380) tmp[ti++] = *q;
			}
			q++;
		}
		tmp[ti] = '\0';
		result = strtod(tmp, NULL);
	}
	else
	{
		const char* q = after_sign;
		while (q < span_end)
		{
			if (*q >= '0' && *q <= '9')
			{
				if (decimal_digits != -1) decimal_digits++;
				result = result * 10.0 + (double) (*q - '0');
			}
			else if (*q == '.')
			{
				decimal_digits = 0;
			}
			else
			{
				break;
			}
			q++;
		}
	}

	if (decimal_digits > 0)
	{
		exponent -= decimal_digits;
	}
	if (exponent > 0)
	{
		result *= f64_powi(10.0, exponent);
	}
	if (exponent < 0)
	{
		if (exponent < -307)
		{
			int diff = exponent + 307;
			result /= f64_powi(10.0, -diff);
			exponent = -307;
		}
		result /= f64_powi(10.0, -exponent);
	}

	*out_d = neg ? -result : result;
	return true;
}

// ---------------------------------------------------------------------------
// Number → string (Ruffle value.rs coerce_to_string Number arm)
// ---------------------------------------------------------------------------

// Shortest decimal digit string that round-trips `d` (> 0, finite).
// Writes the significant digits (no dot) to digs (cap >= 20) and the
// power-of-ten of the first digit to *exp10. Mirrors Rust's f64 Display.
static int shortest_digits(double d, char* digs, int* exp10)
{
	char tmp[48];
	for (int prec = 0; prec <= 17; prec++)
	{
		snprintf(tmp, sizeof(tmp), "%.*e", prec, d);
		if (strtod(tmp, NULL) == d)
		{
			int n = 0;
			const char* q = tmp;
			int e = 0;
			for (; *q != '\0'; q++)
			{
				if (*q >= '0' && *q <= '9')
				{
					digs[n++] = *q;
				}
				else if (*q == 'e' || *q == 'E')
				{
					e = atoi(q + 1);
					break;
				}
			}
			// Trim trailing zeros (keep at least one digit).
			while (n > 1 && digs[n - 1] == '0') n--;
			digs[n] = '\0';
			*exp10 = e;
			return n;
		}
	}
	// Unreachable: 17 significant digits always round-trip.
	digs[0] = '0';
	digs[1] = '\0';
	*exp10 = 0;
	return 1;
}

// Plain (exponent-free) decimal rendering of a positive double, Rust
// Display style.
static int format_plain(char* buf, int buf_size, double d)
{
	char digs[24];
	int e;
	int n = shortest_digits(d, digs, &e);
	int pos = 0;

#define PUTC(c) do { if (pos < buf_size - 1) buf[pos] = (c); pos++; } while (0)
	if (e >= 0)
	{
		if (e + 1 >= n)
		{
			for (int i = 0; i < n; i++) PUTC(digs[i]);
			for (int i = 0; i < e + 1 - n; i++) PUTC('0');
		}
		else
		{
			for (int i = 0; i <= e; i++) PUTC(digs[i]);
			PUTC('.');
			for (int i = e + 1; i < n; i++) PUTC(digs[i]);
		}
	}
	else
	{
		PUTC('0');
		PUTC('.');
		for (int i = 0; i < -e - 1; i++) PUTC('0');
		for (int i = 0; i < n; i++) PUTC(digs[i]);
	}
#undef PUTC
	int written = pos < buf_size - 1 ? pos : buf_size - 1;
	buf[written] = '\0';
	return written;
}

int avm2_format_number(char* buf, int buf_size, double d)
{
	if (isnan(d)) return snprintf(buf, buf_size, "NaN");
	if (d == 0.0) return snprintf(buf, buf_size, "0");
	if (d < 0.0)
	{
		int n = snprintf(buf, buf_size, "-");
		return n + avm2_format_number(buf + 1, buf_size - 1, -d);
	}
	if (isinf(d)) return snprintf(buf, buf_size, "Infinity");

	// Fast path: exact positive integers below 1e15 render as a plain decimal
	// (floor(log10(d)) < 15 < MAX_DIGITS, so the plain branch would apply), but
	// skip shortest_digits' up-to-18 snprintf("%.*e")/strtod round-trip probes —
	// number formatting is ~10% of Seedling's frame self-time and dominated by
	// integer coordinates/counters. Integers < 1e15 are exact in f64 (< 2^53),
	// and this is byte-identical to format_plain (verified over 0..2e6 + edges).
	if (d < 1e15 && d == floor(d))
	{
		uint64_t u = (uint64_t) d;
		char tmp[20];
		int n = 0;
		do { tmp[n++] = (char) ('0' + (u % 10)); u /= 10; } while (u != 0);
		int w = 0;
		while (n > 0 && w < buf_size - 1) buf[w++] = tmp[--n];
		buf[w] = '\0';
		return w;
	}

	const double MIN_DIGITS = -6.0;
	const double MAX_DIGITS = 21.0;
	const double MAX_PRECISION = 15.0;

	double digits = floor(log10(d));

	if (digits < MIN_DIGITS || digits >= MAX_DIGITS)
	{
		// Ruffle: precision-truncate to 15 significant digits, then format
		// "{mantissa}e{sign}{digits}" (mantissa via Display).
		double precision = floor(d * pow(10.0, MAX_PRECISION - digits))
		                   / pow(10.0, MAX_PRECISION - digits);
		double mantissa = precision / pow(10.0, digits);
		char mbuf[40];
		format_plain(mbuf, sizeof(mbuf), mantissa);
		return snprintf(buf, buf_size, "%se%c%.0f", mbuf,
		                digits < 0.0 ? '-' : '+', fabs(digits));
	}

	return format_plain(buf, buf_size, d);
}

// ---------------------------------------------------------------------------
// Coercions
// ---------------------------------------------------------------------------

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

Avm2Value avm2_coerce_to_primitive(Avm2Context* ctx, Avm2Value v, int hint)
{
	if (v.kind != AVM2_VALUE_OBJECT)
	{
		return v;
	}
	if (hint == 0)
	{
		// Default hint: Number (Date would be String; no Date yet).
		hint = 1;
	}
	const char* first = (hint == 2) ? "toString" : "valueOf";
	const char* second = (hint == 2) ? "valueOf" : "toString";

	Avm2Value prim = avm2_call_public_property(ctx, v, first, (uint32_t) strlen(first), NULL, 0);
	if (prim.kind != AVM2_VALUE_OBJECT) return prim;
	prim = avm2_call_public_property(ctx, v, second, (uint32_t) strlen(second), NULL, 0);
	if (prim.kind != AVM2_VALUE_OBJECT) return prim;

	Avm2Class* cls = avm2_value_class(ctx, v);
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1050: Cannot convert %.*s to primitive.",
	                 (int) cls->name.name_len, cls->name.name);
}

double avm2_coerce_to_number(Avm2Context* ctx, Avm2Value v)
{
	switch (v.kind)
	{
		case AVM2_VALUE_NUMBER:
			return v.u.d;
		case AVM2_VALUE_INTEGER:
			return (double) v.u.i;
		case AVM2_VALUE_UNDEFINED:
			return NAN;
		case AVM2_VALUE_NULL:
			return 0.0;
		case AVM2_VALUE_BOOL:
			return v.u.b ? 1.0 : 0.0;
		case AVM2_VALUE_STRING:
		{
			double d;
			if (avm2_string_to_f64(v.u.str->utf8, v.u.str->len, true, &d))
			{
				return d;
			}
			return avm2_string_to_int(v.u.str->utf8, v.u.str->len, 0, true);
		}
		case AVM2_VALUE_OBJECT:
			return avm2_coerce_to_number(ctx, avm2_coerce_to_primitive(ctx, v, 1));
	}
	return NAN;
}

uint32_t avm2_coerce_to_u32(Avm2Context* ctx, Avm2Value v)
{
	switch (v.kind)
	{
		case AVM2_VALUE_NUMBER:
			return avm2_f64_to_wrapping_u32(v.u.d);
		case AVM2_VALUE_INTEGER:
			return (uint32_t) v.u.i;
		case AVM2_VALUE_BOOL:
			return v.u.b ? 1u : 0u;
		case AVM2_VALUE_UNDEFINED:
		case AVM2_VALUE_NULL:
			return 0;
		default:
			return avm2_f64_to_wrapping_u32(avm2_coerce_to_number(ctx, v));
	}
}

int32_t avm2_coerce_to_i32(Avm2Context* ctx, Avm2Value v)
{
	switch (v.kind)
	{
		case AVM2_VALUE_NUMBER:
			return avm2_f64_to_wrapping_i32(v.u.d);
		case AVM2_VALUE_INTEGER:
			return v.u.i;
		case AVM2_VALUE_BOOL:
			return v.u.b ? 1 : 0;
		case AVM2_VALUE_UNDEFINED:
		case AVM2_VALUE_NULL:
			return 0;
		default:
			return avm2_f64_to_wrapping_i32(avm2_coerce_to_number(ctx, v));
	}
}

// Signed 32-bit int -> decimal, no printf. Byte-identical to snprintf("%d"),
// including INT32_MIN (magnitude taken in uint32 to avoid -INT32_MIN UB).
// Integer stringification (counters, coordinates, String(int), concat) is a
// hot path; snprintf's printf_core dominated ~10% of Seedling's frame.
static int write_i32_decimal(char* buf, int32_t v)
{
	uint32_t mag = (v < 0) ? (uint32_t) -(int64_t) v : (uint32_t) v;
	char tmp[10];
	int n = 0;
	do { tmp[n++] = (char) ('0' + (mag % 10)); mag /= 10; } while (mag != 0);
	int w = 0;
	if (v < 0) buf[w++] = '-';
	while (n > 0) buf[w++] = tmp[--n];
	buf[w] = '\0';
	return w;
}

const Avm2String* avm2_coerce_to_string(Avm2Context* ctx, Avm2Value v)
{
	char buf[420];
	switch (v.kind)
	{
		case AVM2_VALUE_UNDEFINED:
			return avm2_string_from_literal(ctx, "undefined");
		case AVM2_VALUE_NULL:
			return avm2_string_from_literal(ctx, "null");
		case AVM2_VALUE_BOOL:
			return avm2_string_from_literal(ctx, v.u.b ? "true" : "false");
		case AVM2_VALUE_INTEGER:
			write_i32_decimal(buf, v.u.i);
			return avm2_string_from_literal(ctx, buf);
		case AVM2_VALUE_NUMBER:
			avm2_format_number(buf, sizeof(buf), v.u.d);
			return avm2_string_from_literal(ctx, buf);
		case AVM2_VALUE_STRING:
			return v.u.str;
		case AVM2_VALUE_OBJECT:
			return avm2_coerce_to_string(ctx, avm2_coerce_to_primitive(ctx, v, 2));
	}
	return avm2_string_from_literal(ctx, "undefined");
}

// ---------------------------------------------------------------------------
// Numeric predicates
// ---------------------------------------------------------------------------

bool avm2_value_is_number(Avm2Value v)
{
	return v.kind == AVM2_VALUE_NUMBER || v.kind == AVM2_VALUE_INTEGER;
}

bool avm2_value_is_u32(Avm2Value v)
{
	if (v.kind == AVM2_VALUE_INTEGER) return v.u.i >= 0;
	if (v.kind == AVM2_VALUE_NUMBER)
	{
		return v.u.d == (double) (uint32_t) v.u.d;
	}
	return false;
}

bool avm2_value_is_i32(Avm2Value v)
{
	if (v.kind == AVM2_VALUE_INTEGER) return true;
	if (v.kind == AVM2_VALUE_NUMBER)
	{
		return v.u.d == (double) (int32_t) v.u.d;
	}
	return false;
}

bool avm2_value_as_index(Avm2Value v, uint32_t* out_idx)
{
	if (v.kind == AVM2_VALUE_INTEGER && v.u.i >= 0)
	{
		*out_idx = (uint32_t) v.u.i;
		return true;
	}
	if (v.kind == AVM2_VALUE_NUMBER && avm2_value_is_u32(v)
	    && v.u.d < 4294967295.0)
	{
		*out_idx = (uint32_t) v.u.d;
		return true;
	}
	return false;
}

// ---------------------------------------------------------------------------
// Abstract operators (value.rs / activation.rs)
// ---------------------------------------------------------------------------

Avm2Value avm2_op_add_values(Avm2Context* ctx, Avm2Value a, Avm2Value b)
{
	if (a.kind == AVM2_VALUE_INTEGER && b.kind == AVM2_VALUE_INTEGER)
	{
		int64_t sum = (int64_t) a.u.i + (int64_t) b.u.i;
		if (sum >= INT32_MIN && sum <= INT32_MAX)
		{
			return avm2_integer((int32_t) sum);
		}
		return avm2_number((double) sum);
	}
	if (a.kind == AVM2_VALUE_NUMBER && b.kind == AVM2_VALUE_NUMBER)
	{
		return avm2_number(a.u.d + b.u.d);
	}
	if (avm2_value_is_xmlish(a) && avm2_value_is_xmlish(b))
	{
		// E4X: XML/XMLList + XML/XMLList concatenates into a new XMLList
		// (Ruffle activation.rs op_add; xml_list_concat).
		Avm2Object* out = avm2_xmllist_new(ctx, NULL, NULL);
		Avm2XmlListExt* oe = (Avm2XmlListExt*) out->native_ext;
		Avm2Value halves[2] = { a, b };
		for (int h = 0; h < 2; h++)
		{
			Avm2XmlListExt* le = avm2_xmllist_ext_of(halves[h]);
			if (le != NULL)
			{
				// append(list): copy target linkage, clear dirty.
				oe->target_dirty = 0;
				oe->target_object = le->target_object;
				oe->has_target_prop = le->has_target_prop;
				oe->target_prop = le->target_prop;
				for (uint32_t i = 0; i < le->count; i++)
				{
					avm2_xmllist_push(ctx, oe, le->items[i]);
				}
			}
			else
			{
				Avm2XmlExt* xe = avm2_xml_ext_of(halves[h]);
				oe->target_dirty = 1;
				avm2_xmllist_push(ctx, oe, xe->node);
			}
		}
		return avm2_object_value(out);
	}
	if (a.kind == AVM2_VALUE_STRING)
	{
		return avm2_string(avm2_string_concat(ctx, a.u.str, avm2_coerce_to_string(ctx, b)));
	}
	if (b.kind == AVM2_VALUE_STRING)
	{
		return avm2_string(avm2_string_concat(ctx, avm2_coerce_to_string(ctx, a), b.u.str));
	}

	Avm2Value pa = avm2_coerce_to_primitive(ctx, a, 0);
	Avm2Value pb = avm2_coerce_to_primitive(ctx, b, 0);
	if (pa.kind == AVM2_VALUE_STRING)
	{
		return avm2_string(avm2_string_concat(ctx, pa.u.str, avm2_coerce_to_string(ctx, pb)));
	}
	if (pb.kind == AVM2_VALUE_STRING)
	{
		return avm2_string(avm2_string_concat(ctx, avm2_coerce_to_string(ctx, pa), pb.u.str));
	}
	return avm2_number(avm2_coerce_to_number(ctx, pa) + avm2_coerce_to_number(ctx, pb));
}

bool avm2_strict_eq(Avm2Value a, Avm2Value b)
{
	switch (a.kind)
	{
		case AVM2_VALUE_UNDEFINED:
			return b.kind == AVM2_VALUE_UNDEFINED;
		case AVM2_VALUE_NULL:
			return b.kind == AVM2_VALUE_NULL;
		case AVM2_VALUE_BOOL:
			return b.kind == AVM2_VALUE_BOOL && a.u.b == b.u.b;
		case AVM2_VALUE_INTEGER:
			if (b.kind == AVM2_VALUE_INTEGER) return a.u.i == b.u.i;
			if (b.kind == AVM2_VALUE_NUMBER) return (double) a.u.i == b.u.d;
			return false;
		case AVM2_VALUE_NUMBER:
			if (b.kind == AVM2_VALUE_INTEGER) return a.u.d == (double) b.u.i;
			if (b.kind == AVM2_VALUE_NUMBER) return a.u.d == b.u.d;
			return false;
		case AVM2_VALUE_STRING:
			return b.kind == AVM2_VALUE_STRING && avm2_string_equals(a.u.str, b.u.str);
		case AVM2_VALUE_OBJECT:
			return b.kind == AVM2_VALUE_OBJECT && a.u.obj == b.u.obj;
	}
	return false;
}

bool avm2_abstract_eq(Avm2Context* ctx, Avm2Value a, Avm2Value b)
{
	// E4X arms come first (Ruffle value.rs: XML/XMLList/QName before the
	// ECMA algorithm — an empty XMLList == undefined).
	{
		int eq;
		if (avm2_xml_abstract_eq(ctx, a, b, &eq)) return eq != 0;
		if (avm2_xml_abstract_eq(ctx, b, a, &eq)) return eq != 0;
		Avm2QNameExt* qa = avm2_qname_ext_of(a);
		Avm2QNameExt* qb = avm2_qname_ext_of(b);
		if (qa != NULL && qb != NULL)
		{
			int uri_eq = (qa->uri == NULL && qb->uri == NULL)
			             || (qa->uri != NULL && qb->uri != NULL
			                 && avm2_string_equals(qa->uri, qb->uri));
			int local_eq = (qa->local == NULL && qb->local == NULL)
			               || (qa->local != NULL && qb->local != NULL
			                   && avm2_string_equals(qa->local, qb->local));
			return uri_eq && local_eq;
		}
	}

	// ECMA-262 3rd ed. 11.9.3 (value.rs abstract_eq).
	bool a_num = avm2_value_is_number(a);
	bool b_num = avm2_value_is_number(b);

	if (a.kind == AVM2_VALUE_UNDEFINED || a.kind == AVM2_VALUE_NULL)
	{
		return b.kind == AVM2_VALUE_UNDEFINED || b.kind == AVM2_VALUE_NULL;
	}
	if (b.kind == AVM2_VALUE_UNDEFINED || b.kind == AVM2_VALUE_NULL)
	{
		return false;
	}
	if (a_num && b_num)
	{
		return avm2_coerce_to_number(ctx, a) == avm2_coerce_to_number(ctx, b);
	}
	if (a.kind == AVM2_VALUE_STRING && b.kind == AVM2_VALUE_STRING)
	{
		return avm2_string_equals(a.u.str, b.u.str);
	}
	if (a.kind == AVM2_VALUE_BOOL && b.kind == AVM2_VALUE_BOOL)
	{
		return a.u.b == b.u.b;
	}
	if (a.kind == AVM2_VALUE_OBJECT && b.kind == AVM2_VALUE_OBJECT)
	{
		// Two Namespaces compare by URI (Ruffle value.rs abstract_eq).
		Avm2NamespaceExt* na = avm2_namespace_ext_of(a);
		Avm2NamespaceExt* nb = avm2_namespace_ext_of(b);
		if (na != NULL && nb != NULL)
		{
			return avm2_string_equals(na->uri, nb->uri);
		}
		return a.u.obj == b.u.obj;
	}
	if (a_num && b.kind == AVM2_VALUE_STRING)
	{
		return avm2_abstract_eq(ctx, a, avm2_number(avm2_coerce_to_number(ctx, b)));
	}
	if (a.kind == AVM2_VALUE_STRING && b_num)
	{
		return avm2_abstract_eq(ctx, avm2_number(avm2_coerce_to_number(ctx, a)), b);
	}
	if (a.kind == AVM2_VALUE_BOOL)
	{
		return avm2_abstract_eq(ctx, avm2_number(avm2_coerce_to_number(ctx, a)), b);
	}
	if (b.kind == AVM2_VALUE_BOOL)
	{
		return avm2_abstract_eq(ctx, a, avm2_number(avm2_coerce_to_number(ctx, b)));
	}
	if ((a.kind == AVM2_VALUE_STRING || a_num) && b.kind == AVM2_VALUE_OBJECT)
	{
		return avm2_abstract_eq(ctx, a, avm2_coerce_to_primitive(ctx, b, 1));
	}
	if (a.kind == AVM2_VALUE_OBJECT && (b.kind == AVM2_VALUE_STRING || b_num))
	{
		return avm2_abstract_eq(ctx, avm2_coerce_to_primitive(ctx, a, 1), b);
	}
	return false;
}


// Lexicographic comparison in UTF-16 code-unit order (WStr order): astral
// codepoints order by their HIGH surrogate, which sorts below U+E000+.
static uint32_t next_unit_key(const Avm2String* s, uint32_t* i)
{
	unsigned char c = (unsigned char) s->utf8[*i];
	uint32_t cp;
	uint32_t clen;
	if (c < 0x80) { cp = c; clen = 1; }
	else if (c < 0xE0) { cp = c & 0x1F; clen = 2; }
	else if (c < 0xF0) { cp = c & 0x0F; clen = 3; }
	else { cp = c & 0x07; clen = 4; }
	for (uint32_t k = 1; k < clen && *i + k < s->len; k++)
	{
		cp = (cp << 6) | ((unsigned char) s->utf8[*i + k] & 0x3F);
	}
	*i += clen;
	if (cp >= 0x10000)
	{
		return 0xD800 + ((cp - 0x10000) >> 10);
	}
	return cp;
}

int avm2_string_utf16_cmp(const Avm2String* a, const Avm2String* b)
{
	uint32_t ia = 0;
	uint32_t ib = 0;
	while (ia < a->len && ib < b->len)
	{
		uint32_t ua = next_unit_key(a, &ia);
		uint32_t ub = next_unit_key(b, &ib);
		if (ua != ub) return ua < ub ? -1 : 1;
	}
	if (ia < a->len) return 1;
	if (ib < b->len) return -1;
	return 0;
}

int avm2_abstract_lt(Avm2Context* ctx, Avm2Value a, Avm2Value b)
{
	if (a.kind == AVM2_VALUE_INTEGER && b.kind == AVM2_VALUE_INTEGER)
	{
		return a.u.i < b.u.i ? 1 : 0;
	}
	Avm2Value pa = avm2_coerce_to_primitive(ctx, a, 1);
	Avm2Value pb = avm2_coerce_to_primitive(ctx, b, 1);

	if (pa.kind == AVM2_VALUE_STRING && pb.kind == AVM2_VALUE_STRING)
	{
		return avm2_string_utf16_cmp(pa.u.str, pb.u.str) < 0 ? 1 : 0;
	}

	double na = avm2_coerce_to_number(ctx, pa);
	double nb = avm2_coerce_to_number(ctx, pb);
	if (isnan(na) || isnan(nb)) return -1;
	return na < nb ? 1 : 0;
}
