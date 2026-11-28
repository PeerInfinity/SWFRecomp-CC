// Avm2Value constructors + coercions + abstract operators (port of Ruffle
// core/src/avm2/value.rs; helper names 1:1 with Ruffle's methods).
// Number-to-string is avmplus's (Flash Player's) convertDoubleToString,
// ported in avm2_number.c (avm2_d2s).

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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

// --- canonical WTF-8 -------------------------------------------------------
//
// AVM2 strings are sequences of UTF-16 code units and an unpaired surrogate is
// a perfectly ordinary value (`String.fromCharCode(0xDC00)`), which strict
// UTF-8 cannot represent. Storage is therefore WTF-8: UTF-8 extended so that
// U+D800..U+DFFF may appear as the 3-byte sequence ED A0 80 .. ED BF BF (never
// valid UTF-8, so nothing else can collide with it).
//
// The form is CANONICAL: a high surrogate immediately followed by a low one is
// ALWAYS stored as the 4-byte UTF-8 of the combined astral code point, never as
// the 6-byte CESU-8 pair. That invariant is what keeps `avm2_string_equals`
// (a memcmp) equivalent to code-unit equality — `"\u{20B9F}"` and
// `fromCharCode(0xD842) + fromCharCode(0xDF9F)` must compare equal
// (ecma3/Unicode/utf8count).
//
// Concatenation is the only operation that can bring an unpaired high and an
// unpaired low together, so it re-normalizes the seam. (This is exactly the
// WTF-8 spec's concatenation rule.) Every other producer emits canonical form
// directly.

// s ends with an unpaired high surrogate (ED A0..AF xx)?
static bool wtf8_ends_with_high_surrogate(const Avm2String* s)
{
	if (s->len < 3) return false;
	const unsigned char* p = (const unsigned char*) s->utf8 + s->len - 3;
	return p[0] == 0xED && p[1] >= 0xA0 && p[1] <= 0xAF
	    && (p[2] & 0xC0) == 0x80;
}

// s starts with an unpaired low surrogate (ED B0..BF xx)?
static bool wtf8_starts_with_low_surrogate(const Avm2String* s)
{
	if (s->len < 3) return false;
	const unsigned char* p = (const unsigned char*) s->utf8;
	return p[0] == 0xED && p[1] >= 0xB0 && p[1] <= 0xBF
	    && (p[2] & 0xC0) == 0x80;
}

static uint32_t wtf8_decode3(const unsigned char* p)
{
	return ((uint32_t) (p[0] & 0x0F) << 12) | ((uint32_t) (p[1] & 0x3F) << 6)
	     | (uint32_t) (p[2] & 0x3F);
}

// --- append-in-place buffers (see avm2_value.h) -----------------------------
//
// AVM2_STRBUF_CENSUS=1 prints a hit census at exit (in-place appends, buffers
// minted, plain copies of branches off a stale prefix, avm2_string_cstr copies
// of stale prefixes).

static int g_strbuf_census = -1;  // -1 = env not read yet
static unsigned long long g_strbuf_appends = 0;
static unsigned long long g_strbuf_new = 0;
static unsigned long long g_strbuf_new_bytes = 0;
static unsigned long long g_strbuf_cstr_copies = 0;
static unsigned long long g_strbuf_branches = 0;

static void strbuf_census_report(void)
{
	fprintf(stderr, "[avm2-strbuf] appends=%llu buffers=%llu buffer_bytes=%llu branch_copies=%llu cstr_copies=%llu\n",
	        g_strbuf_appends, g_strbuf_new, g_strbuf_new_bytes, g_strbuf_branches,
	        g_strbuf_cstr_copies);
}

static int strbuf_census_on(void)
{
	if (g_strbuf_census < 0)
	{
		const char* e = getenv("AVM2_STRBUF_CENSUS");
		g_strbuf_census = (e != NULL && e[0] != '\0' && strcmp(e, "0") != 0);
		if (g_strbuf_census) atexit(strbuf_census_report);
	}
	return g_strbuf_census;
}

static inline uint32_t strbuf_cap(const Avm2String* buf)
{
	return *(const uint32_t*) (const void*) (buf + 1);
}

// `a` (len >= 1) + `b` (len >= 1) through a buffer; NULL when `a` is a stale
// prefix or the result is too large for one allocation (the caller falls back
// to a plain copy).
static const Avm2String* strbuf_append(Avm2Context* ctx, const Avm2String* a,
                                       const Avm2String* b, uint32_t total)
{
	Avm2String* buf = NULL;
	if ((a->gc_flags & AVM2_STR_GC_DEP))
	{
		// In place only when `a` IS the frontier: an older prefix must never
		// see its tail rewritten (a second branch off it would clobber the
		// first's bytes). A branch off a stale prefix (`x = base + i` in a
		// loop) copies exactly instead of minting a 2x buffer per branch.
		Avm2String* o = avm2_strbuf_owner(a);
		if (o->len != a->len)
		{
			if (strbuf_census_on()) g_strbuf_branches++;
			return NULL;
		}
		if ((uint64_t) total + 1 <= strbuf_cap(o)) buf = o;
	}
	if (buf == NULL)
	{
		uint64_t cap = (uint64_t) total * 2u + 1u;
		if (sizeof(Avm2String) + AVM2_STRBUF_PREFIX + cap > 0xFFFFFFF0u) return NULL;
		buf = avm2_alloc(ctx, (uint32_t) (sizeof(Avm2String) + AVM2_STRBUF_PREFIX + cap));
		*(uint32_t*) (void*) (buf + 1) = (uint32_t) cap;
		char* nb = (char*) (buf + 1) + AVM2_STRBUF_PREFIX;
		memcpy(nb, a->utf8, a->len);
		buf->len = a->len;
		buf->utf8 = nb;
		avm2_gc_enroll_string(buf);
		buf->gc_flags |= AVM2_STR_GC_BUF;
		if (strbuf_census_on()) { g_strbuf_new++; g_strbuf_new_bytes += cap; }
	}
	else if (strbuf_census_on())
	{
		g_strbuf_appends++;
	}
	char* bytes = (char*) buf->utf8;
	memcpy(bytes + buf->len, b->utf8, b->len);
	bytes[total] = '\0';
	buf->len = total;
	Avm2String* d = avm2_alloc(ctx, sizeof(Avm2String));
	d->len = total;
	d->utf8 = bytes;
	avm2_gc_enroll_string(d);
	d->gc_flags |= AVM2_STR_GC_DEP;
	return d;
}

const char* avm2_string_cstr(Avm2Context* ctx, const Avm2String* s)
{
	if (s->utf8[s->len] == '\0') return s->utf8;
	if (strbuf_census_on()) g_strbuf_cstr_copies++;
	return avm2_string_new(ctx, s->utf8, s->len)->utf8;
}

const Avm2String* avm2_string_concat(Avm2Context* ctx, const Avm2String* a, const Avm2String* b)
{
	// WTF-8 seam: an unpaired high surrogate at the end of `a` followed by an
	// unpaired low surrogate at the start of `b` re-forms one astral code
	// point, shrinking the result by two bytes (3 + 3 -> 4).
	bool join = wtf8_ends_with_high_surrogate(a) && wtf8_starts_with_low_surrogate(b);
	// Long results append in place (a seam join rewrites a's tail, so it
	// always copies).
	if (!join && a->len > 0 && b->len > 0
	    && (uint64_t) a->len + b->len >= AVM2_STRBUF_MIN_LEN
	    && (uint64_t) a->len + b->len < 0x7FFFFFFFu)
	{
		const Avm2String* r = strbuf_append(ctx, a, b, a->len + b->len);
		if (r != NULL) return r;
	}
	uint32_t total = a->len + b->len - (join ? 2u : 0u);
	Avm2String* s = avm2_alloc(ctx, sizeof(Avm2String) + total + 1);
	char* bytes = (char*) (s + 1);
	if (join)
	{
		uint32_t hi = wtf8_decode3((const unsigned char*) a->utf8 + a->len - 3);
		uint32_t lo = wtf8_decode3((const unsigned char*) b->utf8);
		uint32_t cp = 0x10000u + ((hi - 0xD800u) << 10) + (lo - 0xDC00u);
		memcpy(bytes, a->utf8, a->len - 3);
		char* w = bytes + (a->len - 3);
		w[0] = (char) (0xF0 | (cp >> 18));
		w[1] = (char) (0x80 | ((cp >> 12) & 0x3F));
		w[2] = (char) (0x80 | ((cp >> 6) & 0x3F));
		w[3] = (char) (0x80 | (cp & 0x3F));
		memcpy(w + 4, b->utf8 + 3, b->len - 3);
	}
	else
	{
		memcpy(bytes, a->utf8, a->len);
		memcpy(bytes + a->len, b->utf8, b->len);
	}
	bytes[total] = '\0';
	s->len = total;
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
// ECMA f64 → int conversions (Ruffle core/src/ecma_conversions.rs)
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
// String → number parsing (Ruffle core/src/avm2/value.rs string_to_int / string_to_f64)
// ---------------------------------------------------------------------------

static bool is_space_cp(unsigned char c)
{
	return c == 0x20 || c == 0x09 || c == 0x0d || c == 0x0a || c == 0x0c || c == 0x0b;
}

// Ruffle's leading-whitespace set is NOT ASCII-only: 0x2000..=0x200b, 0x2028,
// 0x2029, 0x205f and 0x3000 count too, and the corpus does reach them —
// `parseInt(" 1234 ")` is 1234, not NaN, in both avmplus and
// Ruffle. Returns the UTF-8 length of the space at `p`, or 0 if it is not one.
static uint32_t space_len_utf8(const char* p, const char* end)
{
	unsigned char b = (unsigned char) *p;
	if (b < 0x80) return is_space_cp(b) ? 1u : 0u;
	// Every non-ASCII space in the set is U+2000..U+3000, i.e. 3 UTF-8 bytes.
	if ((b & 0xF0) != 0xE0 || end - p < 3) return 0;
	uint32_t cp = ((uint32_t) (b & 0x0F) << 12)
	            | ((uint32_t) ((unsigned char) p[1] & 0x3F) << 6)
	            | ((uint32_t) ((unsigned char) p[2] & 0x3F));
	if ((cp >= 0x2000 && cp <= 0x200b) || cp == 0x2028 || cp == 0x2029
	    || cp == 0x205f || cp == 0x3000)
	{
		return 3u;
	}
	return 0u;
}

static void skip_spaces(const char** s, const char* end)
{
	for (;;)
	{
		if (*s >= end) return;
		uint32_t n = space_len_utf8(*s, end);
		if (n == 0) return;
		*s += n;
	}
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

// avmplus core/MathUtils.cpp parseInt, the `result >= 0x20000000000000`
// power-of-two-radix block (s30 w1-rm-avm2). `s`..`lim` is the string from
// the first digit to its END (avmplus indexes s->length(), not the digit
// run). Out-of-range reads give -1, as an invalid digit.
static int pow2_digit(const char* s, const char* lim, int32_t radix)
{
	if (s >= lim) return -1;
	return digit_value(*s, radix);
}

static double avmplus_pow2_parse(const char* s, const char* lim, int32_t radix)
{
	double result = 0;
	int32_t powOf2 = 1;
	for (int32_t x = radix; x != 1; x >>= 1) powOf2++;
	powOf2--;
	const char* end = s;
	int32_t v = 0;
	while (end < lim && *end == '0') end++;
	if (end >= lim) return 0;
	int32_t next;
	for (next = 0; next * powOf2 <= 52; next++)
	{
		v = pow2_digit(end++, lim, radix);
		if (v == -1)
		{
			v = 0;
			break;
		}
		result = result * radix + v;
		if (end >= lim) break;
	}
	if (next * powOf2 > 52)
	{
		int roundUp = 0, bit53 = 0, bit54 = 0;
		double factor = 1;
		switch (radix)
		{
		case 32:
			bit53 = v & (1 << 2);
			bit54 = v & (1 << 1);
			roundUp = (v & 1);
			break;
		case 16:
			bit53 = v & (1 << 0);
			v = pow2_digit(end, lim, radix);
			if (v != -1)
			{
				factor *= radix;
				bit54 = v & (1 << 3);
				roundUp = (v & 0x3) != 0;
			}
			else
			{
				roundUp = bit53 != 0;
			}
			break;
		case 8:
		case 4:
			v = pow2_digit(end, lim, radix);
			if (v == -1) v = 0;
			factor *= radix;
			bit53 = v & (1 << 1);
			bit54 = v & (1 << 0);
			break;
		case 2:
			bit53 = v & (1 << 0);
			v = pow2_digit(end, lim, radix);
			if (v != -1)
			{
				factor *= radix;
				bit54 = v & (1 << 0);
			}
			break;
		}
		bit53 = !!bit53;
		bit54 = !!bit54;
		while (++end < lim)
		{
			v = digit_value(*end, radix);
			if (v == -1) break;
			roundUp |= (v != 0);
			factor *= radix;
		}
		roundUp = bit54 && (bit53 || roundUp);
		result += (roundUp ? 1.0 : 0.0);
		result *= factor;
	}
	return result;
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

	// avmplus is exact for a POWER-OF-TWO radix and runs Ruffle's
	// `result = result * radix + digit` double chain for every other one, and
	// its .out files are these tests' oracle. All three graded values say so:
	// `parseInt("0x1000000000000081")` is 1152921504606847200, the double
	// nearest the true ...105, where the chain drifts to ...847000; the
	// 60-digit base-2 string likewise wants the exact ...724 over the chain's
	// ...720. But `parseInt("123456789012345678")` — radix 10, and comfortably
	// inside 64 bits — wants ...345700, which is the CHAIN's answer, not the
	// exact ...345680. So the split is the radix, not the width; a
	// power-of-two radix is just digit-shifting and stays exact for free.
	// (Ruffle ships an output.ruffle.txt for both parseInt tests because it
	// runs the chain throughout.)
	//
	// Past 2^64 the exact half stops contributing and `result` has carried the
	// same chain from the first digit, so long inputs are unaffected either way.
	double result = 0.0;
	uint64_t exact = 0;
	bool exact_ok = (radix & (radix - 1)) == 0;
	const char* start = p;
	while (p < end)
	{
		int d = digit_value(*p, radix);
		if (d < 0) break;
		result = result * (double) radix + (double) d;
		if (exact_ok)
		{
			uint64_t r = (uint64_t) radix;
			if (exact > (UINT64_MAX - (uint64_t) d) / r) exact_ok = false;
			else exact = exact * r + (uint64_t) d;
		}
		p++;
	}
	if (p == start) return NAN;
	if (exact_ok) result = (double) exact;
	// s30 w1-rm-avm2: avmplus MathUtils::parseInt re-reads a power-of-two
	// radix string once the chain reaches 2^53, and that re-read is what FP
	// prints, bugs included (FP32 golden from_avmplus/as3/Math/e15_1_2_2:
	// parseInt("1234567890123", 32) is 38390726480134180, not ...293600; the
	// `while (++end < len)` tail skips the digit after the rounding digit, so
	// the result is short one radix factor). Ported line for line; an index
	// past the string reads as "no digit".
	if (result >= 9007199254740992.0 && (radix & (radix - 1)) == 0)
	{
		result = avmplus_pow2_parse(start, end, radix);
	}

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

bool avm2_string_to_f64(Avm2Context* ctx, const char* s, uint32_t len, bool strict,
                        double* out_d)
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

	// Bug compatibility (Ruffle value.rs string_to_f64, bugzilla 513018): SWF
	// >= 11 accumulates over the SCANNED prefix only, but SWF <= 10 re-walks
	// the WHOLE remainder, so a SECOND '.' RESETS the fractional-digit count
	// instead of ending the number — parseFloat("1.2345.678") is 12345.678 and
	// parseFloat("1.2345.6e50") is 12345.6 (avm2/parse_float_swf10). Both
	// accumulator arms below break on the first byte that is neither a digit
	// nor '.', exactly like Ruffle's two loops, so this one line covers both.
	// Inert on the `strict` path: strict already rejected trailing garbage
	// above, so p == end there.
	const char* span_end = (ctx == NULL || ctx->swf_version >= 11) ? p : end;

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
// Number -> string: ECMA ToString(Number) as Flash Player prints it, i.e.
// avmplus AvmCore::doubleToString = MathUtils::convertDoubleToString(d,
// DTOSTR_NORMAL, 15). The port lives in avm2_number.c (avm2_d2s), next to
// toFixed/toExponential/toPrecision, which share its digit generator.
//
// This replaced a Ruffle-model formatter (shortest round-trip digits via
// printf/strtod probes + Rust tie rules + a 16-char exponential mantissa
// cut). avmplus is the reference both reproduce: its 15-digit truncated
// exponential mantissa, its full-digit "x.yyye-7" negative arm, the 2^1022 /
// 2^1023 "1e+308" pair and the subnormal spellings all fall out of D2A.
// ---------------------------------------------------------------------------

int avm2_format_number(char* buf, int buf_size, double d)
{
	// Hot path (number formatting is ~10% of Seedling's frame self-time,
	// dominated by integer coordinates/counters): exact integers below 1e15
	// print as plain decimals, which is what D2A produces for them (checked
	// over 3M random integers in [0, 1e15) against "%.0f"). -0 prints "0".
	if (d > -1e15 && d < 1e15 && d == floor(d))
	{
		int64_t v = (int64_t) d;
		uint64_t u = v < 0 ? (uint64_t) (-v) : (uint64_t) v;
		char tmp[24];
		int n = 0;
		do { tmp[n++] = (char) ('0' + (u % 10)); u /= 10; } while (u != 0);
		if (v < 0) tmp[n++] = '-';
		int w = 0;
		while (n > 0 && w < buf_size - 1) buf[w++] = tmp[--n];
		if (buf_size > 0) buf[w] = '\0';
		return w;
	}
	return avm2_d2s(buf, buf_size, d, AVM2_DTOSTR_NORMAL, 15, true);
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
		// ES3 8.6.2.6 [[DefaultValue]] with no hint: Number for every object
		// except Date, whose [[DefaultValue]] uses the String hint (15.9.6),
		// so `date + x` concatenates rather than adding milliseconds.
		// ecma3/Expressions/e11_6_1_3 pins exactly that. Only the `add`
		// operator passes hint 0, so the arm is confined to `+`.
		hint = 1;
		for (Avm2Class* c = (v.u.obj != NULL) ? v.u.obj->cls : NULL;
		     c != NULL; c = c->super_class)
		{
			if (c == ctx->builtins.date_class)
			{
				hint = 2;
				break;
			}
		}
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
			if (avm2_string_to_f64(ctx, v.u.str->utf8, v.u.str->len, true, &d))
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
	//
	// The object-kind gate below is EXACT, not heuristic: every probe in this
	// block (avm2_xml_ext_of / avm2_xmllist_ext_of / avm2_qname_ext_of) tests
	// `v.kind == AVM2_VALUE_OBJECT` first and returns NULL otherwise, so
	//   - avm2_xml_abstract_eq(ctx, a, b, ..) can only return nonzero if `a`
	//     is an OBJECT (it dispatches solely on a's XML/XMLList ext),
	//   - the mirrored call likewise needs `b` to be an OBJECT,
	//   - the QName arm needs BOTH to be OBJECTs.
	// So when neither operand is an object the whole block is a proven no-op.
	// The asymmetric cases the Ruffle ordering comment protects (empty XMLList
	// == undefined, XML == "string") keep one OBJECT operand and still enter.
	// Motivation: this block was ~2.6% of all instructions in a game with zero
	// E4X — five ext probes (each an avm2_get_context() + class compare) on
	// every numeric/string equality.
	if (a.kind == AVM2_VALUE_OBJECT || b.kind == AVM2_VALUE_OBJECT)
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
	// Mixed/double numeric fast path, exactly equivalent to the generic tail
	// below: avm2_coerce_to_primitive is the identity on non-objects, two
	// numbers are never both strings, and avm2_coerce_to_number on a numeric
	// value is just the widening below. Saves two calls per compare on the
	// dominant shape (Number vs int / Number vs Number).
	if (avm2_value_is_number(a) && avm2_value_is_number(b))
	{
		double na = a.kind == AVM2_VALUE_INTEGER ? (double) a.u.i : a.u.d;
		double nb = b.kind == AVM2_VALUE_INTEGER ? (double) b.u.i : b.u.d;
		if (isnan(na) || isnan(nb)) return -1;
		return na < nb ? 1 : 0;
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
