// Number / int / uint / Boolean wrapper classes + Math (port of Ruffle
// globals/{number,int,uint,boolean,math}.rs). AVM2 has no boxed numeric
// objects: constructing/calling these classes returns primitives; instance
// methods dispatch off the Number class ivtable for primitive receivers.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

// ---------------------------------------------------------------------------
// avmplus number -> string (exact port of tamarin-redux core/d2a.cpp,
// core/BigInteger.cpp's semantics and core/MathUtils.cpp
// convertDoubleToString / convertDoubleToStringRadix).
//
// Flash Player's Number formatting is NOT shortest-round-trip and NOT
// correctly rounded: it is Burger & Dybvig with avmplus's own shortcuts, and
// every quirk of those shortcuts is observable in FP32 goldens:
//   * the fast (double) estimate path for values with |e|+prec < 50, rounding
//     a fixed-width digit string by the NEXT generated digit (> 4);
//   * the BigInteger path skips that rounding in NORMAL mode, so the
//     15-digit exponential mantissa is TRUNCATED, and toExponential(0) of
//     77.1234 is "7e+1";
//   * fixed-precision modes scale r and s by 10^precision but leave m+/m-
//     alone, so digit generation runs on after the shortest digits; when it
//     "finishes" the rest is zero fill (1000000000000000128.toFixed(0) is
//     "1000000000000000100");
//   * frexp() normalises subnormals, so their m+/m- are 2^52 too narrow and
//     they print 17-ish digits;
//   * 2^1022 and 2^1023 take the asymmetric-boundary arm, whose value*4.0
//     overflows to Infinity (FP prints "1e+308");
//   * the SWF < 15 toFixed arm (bugzilla 513039: "-0.", "1.", "0.01").
// The digit generator is exact integer arithmetic, so any correct bignum
// reproduces BigInteger; the double fast path is replicated op-for-op.
// ---------------------------------------------------------------------------

#define D2A_BIG_WORDS 160

typedef struct
{
	uint32_t w[D2A_BIG_WORDS];
	int n; // significant words, >= 1
} D2aBig;

static void big_trim(D2aBig* b)
{
	while (b->n > 1 && b->w[b->n - 1] == 0) b->n--;
}

static void big_set_u64(D2aBig* b, uint64_t v)
{
	b->w[0] = (uint32_t) v;
	b->w[1] = (uint32_t) (v >> 32);
	b->n = 2;
	big_trim(b);
}

static void big_lshift(D2aBig* b, int k)
{
	if (k <= 0) return;
	int ws = k / 32, bs = k % 32;
	int nn = b->n + ws + 1;
	if (nn > D2A_BIG_WORDS) nn = D2A_BIG_WORDS;
	for (int i = nn - 1; i >= 0; i--)
	{
		int src = i - ws;
		uint64_t hi = (src >= 0 && src < b->n) ? b->w[src] : 0;
		uint64_t lo = (src - 1 >= 0 && src - 1 < b->n) ? b->w[src - 1] : 0;
		b->w[i] = bs ? (uint32_t) ((hi << bs) | (lo >> (32 - bs))) : (uint32_t) hi;
	}
	b->n = nn;
	big_trim(b);
}

static void big_rshift(D2aBig* b, int k)
{
	if (k <= 0) return;
	int ws = k / 32, bs = k % 32;
	if (ws >= b->n) { b->w[0] = 0; b->n = 1; return; }
	int nn = b->n - ws;
	for (int i = 0; i < nn; i++)
	{
		uint64_t lo = b->w[i + ws];
		uint64_t hi = (i + ws + 1 < b->n) ? b->w[i + ws + 1] : 0;
		b->w[i] = bs ? (uint32_t) ((lo >> bs) | (hi << (32 - bs))) : (uint32_t) lo;
	}
	b->n = nn;
	big_trim(b);
}

static void big_mul_small(D2aBig* b, uint32_t m)
{
	uint64_t carry = 0;
	for (int i = 0; i < b->n; i++)
	{
		uint64_t t = (uint64_t) b->w[i] * m + carry;
		b->w[i] = (uint32_t) t;
		carry = t >> 32;
	}
	if (carry && b->n < D2A_BIG_WORDS) b->w[b->n++] = (uint32_t) carry;
}

static void big_mul_big(D2aBig* b, const D2aBig* m)
{
	uint32_t out[D2A_BIG_WORDS];
	int nn = b->n + m->n;
	if (nn > D2A_BIG_WORDS) nn = D2A_BIG_WORDS;
	memset(out, 0, sizeof(out));
	for (int i = 0; i < b->n; i++)
	{
		uint64_t carry = 0;
		for (int j = 0; j < m->n && i + j < nn; j++)
		{
			uint64_t t = (uint64_t) b->w[i] * m->w[j] + out[i + j] + carry;
			out[i + j] = (uint32_t) t;
			carry = t >> 32;
		}
		if (i + m->n < nn) out[i + m->n] = (uint32_t) carry;
	}
	memcpy(b->w, out, sizeof(uint32_t) * (size_t) nn);
	b->n = nn;
	big_trim(b);
}

static int big_cmp(const D2aBig* a, const D2aBig* b)
{
	if (a->n != b->n) return a->n > b->n ? 1 : -1;
	for (int i = a->n - 1; i >= 0; i--)
	{
		if (a->w[i] != b->w[i]) return a->w[i] > b->w[i] ? 1 : -1;
	}
	return 0;
}

static void big_add(D2aBig* out, const D2aBig* a, const D2aBig* b)
{
	int nn = a->n > b->n ? a->n : b->n;
	uint64_t carry = 0;
	for (int i = 0; i < nn; i++)
	{
		uint64_t t = carry + (i < a->n ? a->w[i] : 0) + (i < b->n ? b->w[i] : 0);
		out->w[i] = (uint32_t) t;
		carry = t >> 32;
	}
	out->n = nn;
	if (carry && nn < D2A_BIG_WORDS) out->w[out->n++] = (uint32_t) carry;
}

// BigInteger::compareOffset: compare (a + off) with b.
static int big_cmp_offset(const D2aBig* a, const D2aBig* b, const D2aBig* off)
{
	D2aBig t;
	big_add(&t, a, off);
	return big_cmp(&t, b);
}

static void big_sub_in_place(D2aBig* a, const D2aBig* b) // a >= b
{
	int64_t borrow = 0;
	for (int i = 0; i < a->n; i++)
	{
		int64_t t = (int64_t) a->w[i] - (i < b->n ? b->w[i] : 0) - borrow;
		borrow = t < 0;
		a->w[i] = (uint32_t) (t + (borrow ? ((int64_t) 1 << 32) : 0));
	}
	big_trim(a);
}

// r = r % s; returns the (low word of the) quotient, as BigInteger::divBy.
static uint32_t big_divmod(D2aBig* r, const D2aBig* s)
{
	uint32_t q = 0;
	while (big_cmp(r, s) >= 0)
	{
		big_sub_in_place(r, s);
		q++;
	}
	return q;
}

// MathUtils::frexp (unix/arm/win32 all agree): value = mantissa * 2^e with
// an integer 53-bit mantissa. Infinity (only reachable through the
// asymmetric-boundary arm's value*4.0 overflow) follows x86-64: glibc frexp
// returns inf with *e = 0 and cvttsd2si of inf*2^53 yields 2^63.
static uint64_t d2a_frexp(double value, int32_t* eptr)
{
	if (isinf(value))
	{
		*eptr = -53;
		return 0x8000000000000000ull;
	}
	int e = 0;
	double frac = frexp(value, &e);
	*eptr = e - 53;
	return (uint64_t) (frac * (double) (1LL << 53));
}

// BigInteger::setFromDouble: exact (truncated) integer value.
static void big_set_double(D2aBig* b, double value)
{
	int32_t e;
	uint64_t m = d2a_frexp(value, &e);
	big_set_u64(b, m);
	if (e < 0) big_rshift(b, -e);
	else big_lshift(b, e);
}

static const double d2a_pow10_tab[23] = {
	1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11,
	1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19, 1e20, 1e21, 1e22
};

// MathUtils::powInt (integer exponent, repeated squaring).
static double d2a_pow_int(double base, int32_t exponent)
{
	double value = 1.0;
	int32_t orig = exponent;
	double orig_base = base;
	if (exponent < 0)
	{
		exponent = -exponent;
		while (exponent)
		{
			if (exponent & 1)
			{
				value /= base;
				if (value == 0 && base != 0) return pow(orig_base, (double) orig);
			}
			exponent >>= 1;
			base *= base;
		}
	}
	else
	{
		while (exponent)
		{
			if (exponent & 1) value *= base;
			exponent >>= 1;
			base *= base;
		}
	}
	return value;
}

static double d2a_quick_pow10(int32_t exp)
{
	if (0 <= exp && exp < 23) return d2a_pow10_tab[exp];
	return d2a_pow_int(10, exp);
}

static double d2a_quick_pow2(int32_t exp)
{
	if (0 < exp && exp < 64) return (double) (1ull << exp);
	return d2a_pow_int(2, exp);
}

static void big_pow10(int32_t exp, D2aBig* out)
{
	if (0 < exp && exp < 22) big_set_double(out, d2a_pow10_tab[exp]);
	else if (exp > 0)
	{
		big_set_double(out, d2a_pow10_tab[21]);
		exp -= 21;
		while (exp-- > 0) big_mul_small(out, 10);
	}
	else big_set_double(out, d2a_pow_int(10, exp));
}

typedef struct
{
	int32_t e;
	uint64_t mantissa;
	int32_t mantissa_prec;
	int32_t base10_exp;
	bool finished;
	bool fast;
	bool low_ok, high_ok;
	D2aBig r, s, mplus, mminus;
	double dr, ds, dmplus, dmminus;
} D2a;

static int32_t d2a_fixup(D2a* d, int32_t est)
{
	if (d->fast)
	{
		if (d->high_ok ? (d->dr + d->dmplus) >= d->ds : d->dr + d->dmplus > d->ds)
			return est + 1;
		d->dr *= 10;
		d->dmplus *= 10;
		d->dmminus *= 10;
		return est;
	}
	int c = big_cmp_offset(&d->r, &d->s, &d->mplus);
	if (d->high_ok ? (c != -1) : (c == 1)) return est + 1;
	big_mul_small(&d->r, 10);
	big_mul_small(&d->mplus, 10);
	big_mul_small(&d->mminus, 10);
	return est;
}

static int32_t d2a_scale(D2a* d)
{
	const double kLog2_10 = 0.30102999566398119521373889472449;
	int32_t b2 = d->e + d->mantissa_prec - 1;
	int32_t est = (int32_t) ceil((b2 * kLog2_10) - 0.0000000001);
	int32_t aest = est > 0 ? est : -est;
	if (d->fast)
	{
		double sc = d2a_quick_pow10(aest);
		if (est >= 0) d->ds *= sc;
		else
		{
			d->dr *= sc;
			d->dmplus *= sc;
			d->dmminus *= sc;
		}
		return d2a_fixup(d, est);
	}
	D2aBig sc;
	big_set_u64(&sc, 0);
	big_pow10(aest, &sc);
	if (est >= 0) big_mul_big(&d->s, &sc);
	else
	{
		big_mul_big(&d->r, &sc);
		big_mul_big(&d->mplus, &sc);
		big_mul_big(&d->mminus, &sc);
	}
	return d2a_fixup(d, est);
}

static void d2a_init(D2a* d, double value, bool fixed, int32_t min_prec)
{
	const uint64_t two52 = 1ull << 52;
	d->finished = false;
	d->fast = false;
	d->mantissa = d2a_frexp(value, &d->e);
	if (fixed) d->low_ok = d->high_ok = true;
	else d->low_ok = d->high_ok = (d->mantissa & 1) == 0;

	d->mantissa_prec = 53;
	while (d->mantissa_prec != 0 && (((d->mantissa >> --d->mantissa_prec) & 1) == 0))
		;
	d->mantissa_prec++;

	int32_t abs_e = d->e > 0 ? d->e : -d->e;
	if (abs_e + d->mantissa_prec - 1 < 50) d->fast = true;

	if (d->fast)
	{
		if (d->e >= 0)
		{
			double be = d2a_quick_pow2(d->e);
			if (d->mantissa != two52)
			{
				d->dr = (double) d->mantissa * be * 2;
				d->ds = 2;
				d->dmplus = be;
				d->dmminus = be;
			}
			else
			{
				double be1 = be * 2;
				d->dr = (double) d->mantissa * be1 * 2;
				d->ds = 4;
				d->dmplus = be1;
				d->dmminus = be;
			}
		}
		else if (d->mantissa != two52)
		{
			d->dr = (double) d->mantissa * 2.0;
			d->ds = d2a_quick_pow2(1 - d->e);
			d->dmplus = 1;
			d->dmminus = 1;
		}
		else
		{
			d->dr = (double) d->mantissa * 4.0;
			d->ds = d2a_quick_pow2(2 - d->e);
			d->dmplus = 2;
			d->dmminus = 1;
		}
		if (fixed)
		{
			double p = d2a_quick_pow10(min_prec);
			d->ds *= p;
			d->dr *= p;
		}
	}
	else
	{
		if (d->e >= 0)
		{
			D2aBig be;
			big_set_u64(&be, 1);
			big_lshift(&be, d->e);
			if (d->mantissa != two52)
			{
				big_set_double(&d->r, value);
				big_lshift(&d->r, 1);
				big_set_u64(&d->s, 2);
				d->mplus = be;
				d->mminus = be;
			}
			else
			{
				D2aBig be1 = be;
				big_lshift(&be1, 1);
				big_set_double(&d->r, value * 4.0);
				big_set_u64(&d->s, 4);
				d->mplus = be1;
				d->mminus = be;
			}
		}
		else if (d->mantissa != two52)
		{
			big_set_double(&d->r, (double) (d->mantissa * 2));
			big_set_u64(&d->s, 2);
			big_lshift(&d->s, -d->e);
			big_set_u64(&d->mplus, 1);
			big_set_u64(&d->mminus, 1);
		}
		else
		{
			big_set_double(&d->r, (double) (d->mantissa * 4));
			big_set_u64(&d->s, 2);
			big_lshift(&d->s, 1 - d->e);
			big_set_u64(&d->mplus, 2);
			big_set_u64(&d->mminus, 1);
		}
		if (fixed)
		{
			D2aBig p;
			big_set_u64(&p, 0);
			big_pow10(min_prec, &p);
			big_mul_big(&d->s, &p);
			big_mul_big(&d->r, &p);
		}
	}
	d->base10_exp = d2a_scale(d);
}

static int32_t d2a_next_digit(D2a* d)
{
	if (d->finished) return -1;
	bool within_low, within_high;
	int32_t q;
	if (d->fast)
	{
		q = (int32_t) (d->dr / d->ds);
		d->dr = fmod(d->dr, d->ds);
		within_low = d->low_ok ? (d->dr <= d->dmminus) : (d->dr < d->dmminus);
		within_high = d->high_ok ? (d->dr + d->dmplus >= d->ds)
		                         : (d->dr + d->dmplus > d->ds);
	}
	else
	{
		q = (int32_t) big_divmod(&d->r, &d->s);
		int cl = big_cmp(&d->r, &d->mminus);
		within_low = d->low_ok ? (cl != 1) : (cl == -1);
		int ch = big_cmp_offset(&d->r, &d->s, &d->mplus);
		within_high = d->high_ok ? (ch != -1) : (ch == 1);
	}
	if (q < 0 || q > 9) q = 0;
	if (!within_low)
	{
		if (!within_high)
		{
			if (d->fast)
			{
				d->dr *= 10;
				d->dmplus *= 10;
				d->dmminus *= 10;
			}
			else
			{
				big_mul_small(&d->r, 10);
				big_mul_small(&d->mplus, 10);
				big_mul_small(&d->mminus, 10);
			}
		}
		else
		{
			q++;
			d->finished = true;
		}
	}
	else if (!within_high)
	{
		d->finished = true;
	}
	else
	{
		bool half_less = d->fast ? (d->dr * 2 < d->ds)
		                         : (big_cmp_offset(&d->r, &d->s, &d->r) == -1);
		if (!half_less) q++;
		d->finished = true;
	}
	return q;
}

// MathUtils::convertDoubleToString. `bug513039_fixed` is avmplus's
// bugzilla513039 compatibility flag (set for SWF >= 15). Returns the length.
int avm2_d2s(char* out, int out_size, double value, int mode, int precision,
             bool bug513039_fixed)
{
	if (out_size <= 0) return 0;
	if (isinf(value)) return snprintf(out, (size_t) out_size, value < 0 ? "-Infinity" : "Infinity");
	if (isnan(value)) return snprintf(out, (size_t) out_size, "NaN");

	if (mode == AVM2_DTOSTR_NORMAL && value > -2147483648.0 && value < 2147483648.0)
	{
		int32_t iv = (int32_t) value;
		if (value == (double) iv) return snprintf(out, (size_t) out_size, "%d", iv);
	}

	char buffer[1400];
	char* s = buffer;
	const bool negative = value < 0.0;
	const bool zero = value == 0.0;
	const bool no_fraction = precision == 0;
	bool round = true;
	if (negative)
	{
		value = -value;
		s++;
	}
	D2a dd;
	D2a* d2a = &dd;
	d2a_init(d2a, value, mode != AVM2_DTOSTR_NORMAL, precision);
	int32_t exp10 = d2a->base10_exp - 1;
	char* const sentinel = s;

	enum { kNormal, kExponential, kFraction, kFixedFraction } format;
	switch (mode)
	{
		case AVM2_DTOSTR_FIXED:
			if (exp10 < 0) format = kFixedFraction;
			else { format = kNormal; precision++; }
			break;
		case AVM2_DTOSTR_PRECISION:
			if (exp10 < 0) format = kFraction;
			else if (exp10 >= precision) format = kExponential;
			else format = kNormal;
			break;
		case AVM2_DTOSTR_EXPONENTIAL:
			format = kExponential;
			precision++;
			break;
		default:
			if (exp10 < 0 && exp10 > -7)
			{
				if (exp10 < -precision) exp10 = -precision - 1;
				format = kFraction;
			}
			else if (exp10 > 20) format = kExponential;
			else format = kNormal;
			break;
	}

	bool wrote_decimal = false;
	switch (format)
	{
		case kNormal:
		{
			int32_t digits = 0, digit;
			*s++ = '0';
			digit = d2a_next_digit(d2a);
			if (digit > 0) *s++ = (char) (digit + '0');
			while (exp10 > 0)
			{
				digit = d2a->finished ? 0 : d2a_next_digit(d2a);
				*s++ = (char) (digit + '0');
				exp10--;
				digits++;
			}
			if (mode == AVM2_DTOSTR_FIXED) digits = 0;
			if (mode == AVM2_DTOSTR_NORMAL)
			{
				if (!d2a->finished)
				{
					*s++ = '.';
					wrote_decimal = true;
					while (!d2a->finished) *s++ = (char) (d2a_next_digit(d2a) + '0');
				}
			}
			else if (digits < precision - 1)
			{
				*s++ = '.';
				wrote_decimal = true;
				for (; digits < precision - 1; digits++)
				{
					digit = d2a->finished ? 0 : d2a_next_digit(d2a);
					*s++ = (char) (digit + '0');
				}
			}
			break;
		}
		case kFixedFraction:
		{
			*s++ = '0';
			*s++ = '0';
			*s++ = '.';
			wrote_decimal = true;
			int32_t digits = 0;
			if (exp10 > 0)
			{
				while (++exp10 < 10 && digits < precision)
				{
					*s++ = '0';
					digits++;
				}
			}
			else if (exp10 < 0)
			{
				if (bug513039_fixed)
				{
					while ((exp10 < -1) && (precision > 0))
					{
						exp10++;
						precision--;
						*s++ = '0';
					}
					if (precision == 0 && exp10 != 0) round = false;
				}
				else
				{
					while ((++exp10 < 0) && (precision-- > 0)) *s++ = '0';
				}
			}
			for (; digits < precision; digits++)
			{
				if (d2a->finished)
				{
					if (mode == AVM2_DTOSTR_NORMAL) break;
					*s++ = '0';
				}
				else *s++ = (char) (d2a_next_digit(d2a) + '0');
			}
			exp10 = 0;
			break;
		}
		case kFraction:
		{
			*s++ = '0';
			*s++ = '0';
			*s++ = '.';
			wrote_decimal = true;
			if (!zero)
			{
				for (int32_t i = exp10; i < -1; i++) *s++ = '0';
			}
			int32_t i = 0;
			while (!d2a->finished)
			{
				*s++ = (char) (d2a_next_digit(d2a) + '0');
				if (mode != AVM2_DTOSTR_NORMAL && ++i >= precision) break;
			}
			if (mode == AVM2_DTOSTR_PRECISION)
			{
				while (i++ < precision)
					*s++ = (char) (d2a->finished ? '0' : d2a_next_digit(d2a) + '0');
			}
			exp10 = 0;
			break;
		}
		case kExponential:
		{
			int32_t digit = d2a->finished ? 0 : d2a_next_digit(d2a);
			*s++ = (char) (digit + '0');
			if (((mode == AVM2_DTOSTR_NORMAL) && !d2a->finished)
			    || ((mode != AVM2_DTOSTR_NORMAL) && precision > 1))
			{
				*s++ = '.';
				wrote_decimal = true;
				for (int32_t i = 0; i < precision - 1; i++)
				{
					if (d2a->finished)
					{
						if (mode == AVM2_DTOSTR_NORMAL) break;
						*s++ = '0';
					}
					else *s++ = (char) (d2a_next_digit(d2a) + '0');
				}
			}
			break;
		}
	}

	if (round && (d2a->fast || mode == AVM2_DTOSTR_FIXED || mode == AVM2_DTOSTR_PRECISION))
	{
		if (d2a_next_digit(d2a) > 4)
		{
			for (char* p = s - 1; p >= sentinel; p--)
			{
				if (*p == '.') continue;
				*p = (char) (*p + 1);
				if (*p != ('9' + 1)) break;
				*p = '0';
			}
		}
		if (mode == AVM2_DTOSTR_NORMAL && wrote_decimal)
		{
			while (*(s - 1) == '0') s--;
			if (*(s - 1) == '.') s--;
		}
	}

	if (exp10)
	{
		char* first_nz = sentinel;
		while (first_nz < s && *first_nz == '0') first_nz++;
		if (s == first_nz)
		{
			*s++ = '1';
			exp10++;
		}
		else if (!zero)
		{
			char* last_nz = s;
			while (last_nz > first_nz && *--last_nz == '0')
				;
			if (first_nz == last_nz)
			{
				exp10 += (int32_t) (s - first_nz - 1);
				s = last_nz + 1;
			}
		}
		*s++ = 'e';
		if (exp10 > 0) *s++ = '+';
		s += sprintf(s, "%d", (int) exp10);
	}

	int32_t len = (int32_t) (s - buffer);
	s = sentinel;
	if (sentinel[0] == '0' && sentinel[1] != '.')
	{
		s = sentinel + 1;
		len--;
	}
	if (negative) *--s = '-';

	if (bug513039_fixed && mode == AVM2_DTOSTR_FIXED && no_fraction && wrote_decimal)
	{
		char* p;
		for (p = s + len - 1; *p != '.'; p--)
			;
		len = (int32_t) (p - s);
	}

	if (len > out_size - 1) len = out_size - 1;
	memcpy(out, s, (size_t) len);
	out[len] = '\0';
	return len;
}

// MathUtils::convertDoubleToStringRadix: the integer part only, built from
// the bottom with double floor/divide (so digits past 2^53 are whatever the
// doubles leave, typically zero fill), and any |value| < 1 -- including a
// negative one -- is "0" with no sign.
int avm2_d2s_radix(char* out, int out_size, double value, int radix)
{
	char tmp[1100];
	char* src = tmp + sizeof(tmp) - 1;
	char* end = src;
	bool negative = value < 0;
	if (negative) value = -value;
	if (value < 1)
	{
		*src-- = '0';
	}
	else
	{
		double u = floor(value);
		while (u != 0 && src > tmp + 1)
		{
			double j = u;
			u = floor(u / radix);
			j -= (u * radix);
			*src-- = (char) ((j < 10) ? ((int32_t) j + '0') : ((int32_t) j + ('a' - 10)));
		}
		if (negative) *src-- = '-';
	}
	int len = (int) (end - src);
	if (len > out_size - 1) len = out_size - 1;
	memcpy(out, src + 1, (size_t) len);
	out[len] = '\0';
	return len;
}

// BigInteger::doubleValueOf: top 53 bits, round-half-even on bit 54 + rest.
static double big_double_value(const D2aBig* b)
{
	if (b->n == 1) return (double) b->w[0];
	int bits_top = 1;
	for (uint32_t t = b->w[b->n - 1]; t > 1; t >>= 1) bits_top++;
	int next = b->n - 1;
	bool bit53 = false, bit54 = false, rest = false;
	uint64_t mant = 0, w = 0;
	int pos = 53, bits = bits_top, wshift = 0;
	while (pos > 0)
	{
		w = b->w[next--];
		mant |= (w >> wshift);
		pos -= bits;
		if (pos > 0)
		{
			if (next > -1)
			{
				bits = (pos > 31) ? 32 : pos;
				wshift = (pos > 31) ? 0 : 32 - bits;
				mant <<= bits;
			}
			else break;
		}
	}
	if (pos <= 0)
	{
		bit53 = (mant & 1) != 0;
		if (bits == 32)
		{
			if (next > -1)
			{
				w = b->w[next--];
				bit54 = (w & (1ull << 31)) != 0;
				rest = (w & ((1ull << 31) - 1)) != 0;
			}
		}
		else
		{
			bit54 = (w & (1ull << (wshift - 1))) != 0;
			if (wshift > 1) rest = (w & ((1ull << (wshift - 1)) - 1)) != 0;
			if (next > -1) rest = rest || (b->w[next--] != 0);
		}
	}
	if (bit54 && (bit53 || rest)) mant += 1;
	uint32_t lg2 = (uint32_t) (b->n - 1) * 32;
	for (uint32_t t = b->w[b->n - 1]; t > 1; t >>= 1) lg2++;
	int32_t e2 = (int32_t) lg2 + 1 - 53;
	double result = (double) mant;
	if (e2 > 0)
	{
		if (e2 < 64) result *= (double) (1ull << e2);
		else result *= d2a_pow_int(2, e2);
	}
	return result;
}

// MathUtils.cpp's own quickPowTen (note: 0 goes through pow, = 1).
static double s2d_pow10(int32_t exp)
{
	if (exp < 23 && exp > 0) return d2a_pow10_tab[exp];
	return d2a_pow_int(10, exp);
}

// avmplus MathUtils::convertStringToDouble for an already-validated JSON
// number token ([-]digits[.digits][(e|E)[+-]digits]); JSONParser::parseFloat
// maps a failure to NaN. Flash's reader is NOT correctly rounded: up to 15
// digits it accumulates in a double and scales by a (pow-computed) power of
// ten; past 15 it builds the exact integer, multiplies it by a DOUBLE 10^k
// (inexact for k >= 23) and divides by another. So
// "1.7976931348623157e308" overflows to Infinity and "1.1754944e-38" lands one
// ulp low (avm2/json_parse_numbers, Flash-captured).
double avm2_avmplus_json_number(const char* s, uint32_t len)
{
	uint32_t i = 0;
	bool negate = false;
	if (i < len && (s[i] == '-' || s[i] == '+'))
	{
		negate = s[i] == '-';
		i++;
	}
	uint32_t start = i;
	int32_t num_digits = 0, exp10 = 0;
	while (i < len && s[i] >= '0' && s[i] <= '9') { num_digits++; i++; }
	if (i < len && s[i] == '.')
	{
		i++;
		while (i < len && s[i] >= '0' && s[i] <= '9') { num_digits++; i++; }
	}
	uint32_t limit = i;
	if (i < len && (s[i] == 'e' || s[i] == 'E'))
	{
		i++;
		bool negexp = false;
		if (i < len && (s[i] == '-' || s[i] == '+')) { negexp = s[i] == '-'; i++; }
		uint32_t num = 0;
		while (i < len && s[i] >= '0' && s[i] <= '9') { num = num * 10u + (uint32_t) (s[i] - '0'); i++; }
		exp10 += negexp ? -(int32_t) num : (int32_t) num;
	}
	if (num_digits == 0) return NAN;
	double result = 0;
	int32_t decimal_digits = -1;
	if (num_digits > 15)
	{
		D2aBig x;
		big_set_u64(&x, 0);
		for (uint32_t k = start; k < limit; k++)
		{
			if (decimal_digits != -1) decimal_digits++;
			if (s[k] != '.')
			{
				big_mul_small(&x, 10);
				D2aBig dg;
				big_set_u64(&dg, (uint64_t) (s[k] - '0'));
				big_add(&x, &x, &dg);
			}
			else decimal_digits = 0;
		}
		if (decimal_digits > 0) exp10 -= decimal_digits;
		if (exp10 > 0)
		{
			D2aBig f;
			big_set_double(&f, s2d_pow10(exp10));
			if (x.n + f.n > 128 + 2) return NAN;
			big_mul_big(&x, &f);
			exp10 = 0;
		}
		result = big_double_value(&x);
		if (exp10 < 0)
		{
			if (exp10 < -307)
			{
				int32_t diff = exp10 + 307;
				result /= s2d_pow10(-diff);
				exp10 -= diff;
			}
			result /= s2d_pow10(-exp10);
		}
	}
	else
	{
		for (uint32_t k = start; k < limit; k++)
		{
			if (decimal_digits != -1) decimal_digits++;
			if (s[k] != '.') result = result * 10 + (double) (unsigned char) s[k] - '0';
			else decimal_digits = 0;
		}
		if (decimal_digits > 0) exp10 -= decimal_digits;
		if (exp10 >= 0) result *= s2d_pow10(exp10);
		else
		{
			if (exp10 < -307)
			{
				int32_t diff = exp10 + 307;
				result /= s2d_pow10(-diff);
				exp10 -= diff;
			}
			result /= s2d_pow10(-exp10);
		}
	}
	return negate ? -result : result;
}

static double this_number(Avm2Activation* act)
{
	return avm2_coerce_to_number(act->ctx, act->this_val);
}

static double arg_f64(Avm2Activation* act, uint32_t i)
{
	return i < act->argc ? avm2_coerce_to_number(act->ctx, act->args[i])
	                     : NAN;
}

// ---------------------------------------------------------------------------
// Number methods
// ---------------------------------------------------------------------------

// FP's range check does not live in toFixed/toPrecision/toExponential: those
// three are thin AS3 wrappers around one static helper, `Number$/_convert`,
// and that helper is what raises #1002 -- so its frame sits INNERMOST in the
// trace (avm2/number_convert_errors pins 250 such lines). It is deliberately
// absent from the argument-coercion traces in the same test: the argument is
// coerced in the caller's own frame, BEFORE _convert is entered, so the push
// must stay here and not move up into the three entry points.
_Noreturn static void throw_1002(Avm2Context* ctx)
{
	static const Avm2MethodRef convert = { NULL, NULL, "Number$/_convert", 0, 0 };
	avm2_callstack_push(ctx, &convert, NULL);
	avm2_throw_error(ctx, ctx->builtins.range_error_class,
	                 "Error #1002: Number.toPrecision has a range of 1 to 21. "
	                 "Number.toFixed and Number.toExponential have a range of 0 to "
	                 "20. Specified value is not within expected range.");
}

// Number$/_numberToString (avmplus NumberClass.cpp): radix 10, NaN and
// +-Infinity print through doubleToString BEFORE the radix range check (so
// NaN.toString(1) is "NaN"); any other radix prints the integer part only,
// via convertDoubleToStringRadix.
static const Avm2String* print_with_radix(Avm2Context* ctx, double number, int radix)
{
	char buf[1100];
	if (radix == 10 || isnan(number) || isinf(number))
	{
		avm2_format_number(buf, sizeof(buf), number);
		return avm2_string_from_literal(ctx, buf);
	}
	int n = avm2_d2s_radix(buf, sizeof(buf), number, radix);
	// avmplus builds this string with newStringLatin1, and past 2^53 its
	// double digit `j` can fall outside [0, radix): the "digit" is then any
	// byte ('W', '(', ' ', 0x97, ...). Those are deterministic (avm2/
	// number_tostring pins 31 of them), so re-encode the bytes as Latin-1.
	char u8[2200];
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		unsigned char c = (unsigned char) buf[i];
		if (c < 0x80) u8[m++] = (char) c;
		else
		{
			u8[m++] = (char) (0xC0 | (c >> 6));
			u8[m++] = (char) (0x80 | (c & 0x3F));
		}
	}
	return avm2_string_new(ctx, u8, (uint32_t) m);
}

static Avm2Value number_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	int32_t radix = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 10;
	if (radix != 10 && !isnan(number) && !isinf(number) && (radix < 2 || radix > 36))
	{
		avm2_throw_error(ctx, ctx->builtins.range_error_class,
		                 "Error #1003: The radix argument must be between 2 and 36; "
		                 "got %d.", radix);
	}
	return avm2_string(print_with_radix(ctx, number, radix));
}

static Avm2Value number_value_of(Avm2Activation* act)
{
	return act->this_val;
}

// Number.prototype.toString / .valueOf / .toLocaleString.
//
// Same hazard as String.prototype.toString: the receiver can be
// `Number.prototype` itself, a bare object with no primitive value.
// this_number() would coerce it, which calls valueOf -> number_value_of,
// which hands the object straight back -> coerce again -> infinite
// recursion and a stack-overflow SIGSEGV. In avmplus `Number.prototype`
// is a Number object whose value is 0, and the tests assert exactly that
// (`Number.prototype.valueOf()` -> 0, `Number.prototype.toString()` ->
// "0"), so a non-numeric receiver is treated as 0.
static bool numeric_receiver(Avm2Value v)
{
	return v.kind == AVM2_VALUE_NUMBER || v.kind == AVM2_VALUE_INTEGER;
}

// ...but only for the prototype ITSELF. Any other object receiver is
// incompatible, and avmplus says so with #1004 (avm2/primitive_valueOf,
// ecma3/Exceptions/number_002_rt assign Number.prototype.valueOf onto a plain
// Object and expect the call to throw). The class name in the message is the
// prototype the shim was installed on, hence one pair per class.
static void number_proto_receiver_check(Avm2Activation* act, Avm2Class* cls,
                                        const char* cls_name, const char* meth)
{
	if (act->this_val.kind == AVM2_VALUE_OBJECT
	    && act->this_val.u.obj == cls->prototype_obj)
	{
		return;
	}
	// The prototype shims are AS3 playerglobal, so FP's trace carries the
	// "Error$/throwError()" frame (avm2/primitive_toString, primitive_valueOf).
	// Per-site opt-in — see avm2_error.h.
	avm2_callstack_push_throwerror(act->ctx);
	avm2_throw_error(act->ctx, act->ctx->builtins.type_error_class,
	                 "Error #1004: Method %s.prototype.%s was invoked on an "
	                 "incompatible object.", cls_name, meth);
}

// How strict each shim is about a NUMERIC receiver. FP's three prototypes do
// not agree, and avm2/primitive_{toString,valueOf} pin every cell of the
// table with `Cls.prototype.m.call(v)` over {1.5, uint(2), -2}:
//
//            | Number | int      | uint
//   toString | any    | integral | any        <- uint.toString(1.5) -> "1.5"
//   valueOf  | any    | integral | uint-exact <- uint.valueOf(-2) throws #1004
//
// (i.e. only uint's two halves disagree with each other — an avmplus
// implementation asymmetry, not a typo: both tests show it, for both signs.)
static bool numeric_receiver_ok(Avm2Value v, int strict)
{
	if (!numeric_receiver(v)) return false;
	if (strict == 0) return true;
	double d = (v.kind == AVM2_VALUE_INTEGER) ? (double) v.u.i : v.u.d;
	if (!isfinite(d) || d != (double) (int64_t) d) return false;
	return strict == 1 || d >= 0.0;
}

#define NUM_RECV_ANY 0
#define NUM_RECV_INT 1
#define NUM_RECV_UINT 2

#define DEFINE_NUMBER_PROTO_SHIMS(tag, cls_field, cls_name, ts_strict, vo_strict) \
	static Avm2Value tag##_proto_to_string(Avm2Activation* act)                \
	{                                                                          \
		if (numeric_receiver_ok(act->this_val, ts_strict))                     \
			return number_to_string(act);                                      \
		number_proto_receiver_check(act, act->ctx->builtins.cls_field,         \
		                            cls_name, "toString");                     \
		Avm2Activation zero = *act;                                            \
		zero.this_val = avm2_number(0.0);                                      \
		return number_to_string(&zero);                                        \
	}                                                                          \
	static Avm2Value tag##_proto_value_of(Avm2Activation* act)                 \
	{                                                                          \
		if (numeric_receiver_ok(act->this_val, vo_strict))                     \
			return act->this_val;                                              \
		number_proto_receiver_check(act, act->ctx->builtins.cls_field,         \
		                            cls_name, "valueOf");                      \
		return avm2_number(0.0);                                               \
	}

DEFINE_NUMBER_PROTO_SHIMS(number, number_class, "Number",
                          NUM_RECV_ANY, NUM_RECV_ANY)
DEFINE_NUMBER_PROTO_SHIMS(int, int_class, "int",
                          NUM_RECV_INT, NUM_RECV_INT)
DEFINE_NUMBER_PROTO_SHIMS(uint, uint_class, "uint",
                          NUM_RECV_ANY, NUM_RECV_UINT)

// Number$/_convert (avmplus NumberClass.cpp): range check, then
// MathUtils::convertDoubleToString in the requested mode (port above).
static Avm2Value number_convert(Avm2Context* ctx, double number, int digits, int mode)
{
	char buf[1400];
	int n = avm2_d2s(buf, sizeof(buf), number, mode, digits, ctx->swf_version >= 15);
	return avm2_string(avm2_string_new(ctx, buf, (uint32_t) n));
}

static Avm2Value number_to_fixed(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	int32_t digits = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	if (digits < 0 || digits > 20) throw_1002(ctx);
	return number_convert(ctx, number, digits, AVM2_DTOSTR_FIXED);
}

static Avm2Value number_to_exponential(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	int32_t digits = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	if (digits < 0 || digits > 20) throw_1002(ctx);
	return number_convert(ctx, number, digits, AVM2_DTOSTR_EXPONENTIAL);
}

static Avm2Value number_to_precision(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	// An ABSENT precision means plain toString — and FP treats `null` as absent
	// here, not as 0: NaN.toPrecision(null) is "NaN" while NaN.toPrecision(0)
	// is #1002 (avm2/number_convert_edge_cases, six rows).
	if (act->argc == 0 || act->args[0].kind == AVM2_VALUE_UNDEFINED
	    || act->args[0].kind == AVM2_VALUE_NULL)
	{
		char buf[420];
		avm2_format_number(buf, sizeof(buf), number);
		return avm2_string(avm2_string_from_literal(ctx, buf));
	}
	int32_t digits = avm2_coerce_to_i32(ctx, act->args[0]);
	if (digits < 1 || digits > 21) throw_1002(ctx);
	// avmplus DTOSTR_PRECISION: exponent >= precision goes exponential, any
	// negative exponent stays fixed ((1.2315e-8).toPrecision(1) is
	// "0.00000001", avm2/number_toprecision), and zero is "0." + p zeros.
	return number_convert(ctx, number, digits, AVM2_DTOSTR_PRECISION);
}

static Avm2Value number_construct(Avm2Context* ctx, Avm2Class* cls,
                                  const Avm2Value* args, uint32_t argc)
{
	(void) cls;
	if (argc == 0) return avm2_number(0.0);
	return avm2_number(avm2_coerce_to_number(ctx, args[0]));
}

static Avm2Value int_construct(Avm2Context* ctx, Avm2Class* cls,
                               const Avm2Value* args, uint32_t argc)
{
	(void) cls;
	if (argc == 0) return avm2_integer(0);
	return avm2_integer(avm2_coerce_to_i32(ctx, args[0]));
}

static Avm2Value uint_construct(Avm2Context* ctx, Avm2Class* cls,
                                const Avm2Value* args, uint32_t argc)
{
	(void) cls;
	if (argc == 0) return avm2_integer(0);
	return avm2_uint_value(avm2_coerce_to_u32(ctx, args[0]));
}

static Avm2Value boolean_construct(Avm2Context* ctx, Avm2Class* cls,
                                   const Avm2Value* args, uint32_t argc)
{
	(void) ctx; (void) cls;
	if (argc == 0) return avm2_bool(false);
	return avm2_bool(avm2_coerce_to_boolean(args[0]));
}

static Avm2Value boolean_to_string(Avm2Activation* act)
{
	bool b = avm2_coerce_to_boolean(act->this_val);
	return avm2_string(avm2_string_from_literal(act->ctx, b ? "true" : "false"));
}

static Avm2Value boolean_value_of(Avm2Activation* act)
{
	return avm2_bool(avm2_coerce_to_boolean(act->this_val));
}

// Boolean.prototype.toString / .valueOf.
//
// Same shape as number_proto_to_string/value_of above: in avmplus
// `Boolean.prototype` is a Boolean object whose value is false, so the
// tests assert `Boolean.prototype.valueOf()` -> false and
// `String(Boolean.prototype)` -> "false". The class methods coerce their
// receiver, and an object coerces to true, so registering them directly
// on the prototype yields true for both. A non-boolean receiver is the
// prototype (or something equally value-less) and reads as false.
static Avm2Value boolean_proto_to_string(Avm2Activation* act)
{
	if (act->this_val.kind != AVM2_VALUE_BOOL)
	{
		number_proto_receiver_check(act, act->ctx->builtins.boolean_class,
		                            "Boolean", "toString");
	}
	bool b = act->this_val.kind == AVM2_VALUE_BOOL && act->this_val.u.b;
	return avm2_string(avm2_string_from_literal(act->ctx, b ? "true" : "false"));
}

static Avm2Value boolean_proto_value_of(Avm2Activation* act)
{
	if (act->this_val.kind == AVM2_VALUE_BOOL) return act->this_val;
	number_proto_receiver_check(act, act->ctx->builtins.boolean_class,
	                            "Boolean", "valueOf");
	return avm2_bool(false);
}

// ---------------------------------------------------------------------------
// Math
// ---------------------------------------------------------------------------

#define MATH1(name, expr) \
	static Avm2Value math_##name(Avm2Activation* act) \
	{ \
		double x = arg_f64(act, 0); \
		(void) x; \
		return avm2_number(expr); \
	}

MATH1(abs, fabs(x))
MATH1(acos, acos(x))
MATH1(asin, asin(x))
MATH1(atan, atan(x))
MATH1(ceil, ceil(x))
MATH1(cos, cos(x))
MATH1(exp, exp(x))
MATH1(floor, floor(x))
MATH1(log, log(x))
MATH1(sin, sin(x))
MATH1(sqrt, sqrt(x))
MATH1(tan, tan(x))
MATH1(round, floor(x + 0.5))
#undef MATH1

static Avm2Value math_atan2(Avm2Activation* act)
{
	return avm2_number(atan2(arg_f64(act, 0), arg_f64(act, 1)));
}

static Avm2Value math_pow(Avm2Activation* act)
{
	double n = arg_f64(act, 0);
	double p = arg_f64(act, 1);
	// Flash quirks (Ruffle math.rs pow).
	if (!isfinite(n) || !isfinite(p))
	{
		if (isnan(p)) return avm2_number(NAN);
		if ((n == 1.0 || n == -1.0) && isinf(p)) return avm2_number(NAN);
		if (n == -INFINITY && p < 0.0 && isfinite(p)
		    && p == floor(p) && fmod(p, 2.0) == 0.0)
		{
			return avm2_number(-0.0);
		}
	}
	return avm2_number(pow(n, p));
}

static Avm2Value math_max(Avm2Activation* act)
{
	double cur = -INFINITY;
	for (uint32_t i = 0; i < act->argc; i++)
	{
		double v = avm2_coerce_to_number(act->ctx, act->args[i]);
		if (isnan(v)) return avm2_number(NAN);
		// total order: +0 > -0.
		if (v > cur || (v == cur && !signbit(v) && signbit(cur))) cur = v;
	}
	return avm2_number(cur);
}

static Avm2Value math_min(Avm2Activation* act)
{
	double cur = INFINITY;
	for (uint32_t i = 0; i < act->argc; i++)
	{
		double v = avm2_coerce_to_number(act->ctx, act->args[i]);
		if (isnan(v)) return avm2_number(NAN);
		if (v < cur || (v == cur && signbit(v) && !signbit(cur))) cur = v;
	}
	return avm2_number(cur);
}

// avmplus-compatible RNG (same algorithm + MOCK_DATE_TIME seeding as
// actionmodern/math.c, whose state is file-static and unreachable here).
typedef struct { uint32_t uValue, uSequenceLength, uXorMask; } Avm2RandomFast;
static Avm2RandomFast g_avm2_rng;

static const uint32_t avm2_random_xor_masks[31] = {
	0x00000003, 0x00000006, 0x0000000C, 0x00000014, 0x00000030, 0x00000060,
	0x000000B8, 0x00000110, 0x00000240, 0x00000500, 0x00000CA0, 0x00001B00,
	0x00003500, 0x00006000, 0x0000B400, 0x00012000, 0x00020400, 0x00072000,
	0x00090000, 0x00140000, 0x00300000, 0x00400000, 0x00D80000, 0x01200000,
	0x03880000, 0x07200000, 0x09000000, 0x14000000, 0x32800000, 0x48000000,
	0xA3000000,
};

static int32_t avm2_random_pure_hasher(int32_t iSeed)
{
	// uint32_t wrapping arithmetic: the int32_t form was signed-overflow UB
	// that emcc folded differently from gcc (browser-WASM drew a different
	// sequence from the same seed). Same fix as actionmodern/math.c
	// RandomPureHasher (s26 n-browser-pfx).
	const uint32_t c1 = 1376312589u;
	const uint32_t c2 = 789221u;
	const uint32_t c3 = 15731u;
	uint32_t s = (uint32_t) iSeed;
	s = ((s << 13) ^ s) - (uint32_t) ((int32_t) s >> 21);
	uint32_t r = (s * (s * s * c3 + c2) + c1) & 0x7FFFFFFFu;
	r += s;
	r = ((r << 13) ^ r) - (uint32_t) ((int32_t) r >> 21);
	return (int32_t) r;
}

// The build's own boot seed. MOCK_DATE_TIME is a -D and the artifact hash is
// what pins it; the reset hook below COMPOSES with it (seed 0 means "back to
// this build's boot state") rather than replacing it.
static uint32_t avm2_random_boot_seed(void)
{
#ifdef MOCK_DATE_TIME
	return (uint32_t) ((int64_t) (MOCK_DATE_TIME) * 1000LL);
#else
	return 987654321u;
#endif
}

static void avm2_random_seed(Avm2RandomFast* r, uint32_t seed)
{
	int n = 31;
	r->uValue = (seed == 0) ? avm2_random_boot_seed() : seed;
	r->uSequenceLength = (uint32_t) ((1ULL << n) - 1ULL);
	r->uXorMask = avm2_random_xor_masks[n - 2];
}

static int32_t avm2_random_next(Avm2RandomFast* r)
{
	if (r->uValue == 0) avm2_random_seed(r, 0);
	if (r->uValue & 1u)
	{
		r->uValue = (r->uValue >> 1) ^ r->uXorMask;
	}
	else
	{
		r->uValue >>= 1;
	}
	int32_t aNum = (int32_t) r->uValue;
	aNum = avm2_random_pure_hasher((int32_t) ((uint32_t) aNum * 71u));
	return aNum & 0x7FFFFFFF;
}

// Draws taken from the MAIN stream. `Math.random()` is the only way to move
// that generator, so this counts exactly the numbers a replay would have to
// step past. It is deliberately NOT reset by setState: the point of a
// monotonic counter is that a per-tick sample can subtract two readings and
// get a draw COUNT, and a reset would silently make a window read as zero.
// `cosmetic()` runs a separate generator and is not counted -- counting it
// would defeat the whole reason the second stream exists.
static uint64_t g_avm2_rng_draws;

static int32_t avm2_generate_random_number(void)
{
	g_avm2_rng_draws++;
	return avm2_random_next(&g_avm2_rng);
}

static Avm2Value math_random(Avm2Activation* act)
{
	(void) act;
	int32_t raw = avm2_generate_random_number();
	return avm2_number((double) raw / 2147483648.0);
}

// ── swfmodern.Rng — the determinism hooks ────────────────────────────────
//
// `Math.random()` is one global 31-bit XOR-shift LFSR whose whole state is
// the single uint32 above, so a page's draw sequence is a pure function of
// its boot seed and of HOW MANY DRAWS HAVE HAPPENED. That second half is the
// problem this class exists for: a harness replaying a recorded input tape
// can prove the game REPRODUCES (same page, same tape, same rocks) without
// being able to PREDICT anything, because the stream position at the start of
// the interesting window is the whole page's history — every Tile and Enemy
// constructed since load, every sound index rolled, every frame of camera
// shake. No readout carries that number.
//
// `reset(seed)` deletes the question instead of answering it: after it, a
// model owes only the draws the window itself consumes. `state`/`setState`
// exist so an instrument can SAMPLE the stream (draw N values, then put the
// state back) without perturbing the run it is measuring.
//
// `cosmetic()` is the second half: a SEPARATE generator, so cooperative
// content can route draws whose values nothing gameplay-visible reads (sprite
// frames, particle jitter, sound indices) off the main stream, where they
// otherwise shift every gameplay draw that follows. Nothing routes itself —
// only the content knows which of its own draws are which — so this is inert
// until something calls it, and `Math.random()` is untouched either way.
//
// `draws()` closes the loop on the paragraph above: `state` says WHERE the
// stream is, `draws()` says HOW FAR it has come. With one seeded generator the
// values themselves are then recoverable offline (step the LFSR N times), so a
// per-tick sample of the pair describes the stream completely instead of
// merely proving it moved.
//
// Reachable from AS3 as flash.utils.getDefinitionByName("swfmodern.Rng"); a
// build without it throws #1065 there, which is a loud absence rather than a
// silent unseeded run.
static Avm2RandomFast g_avm2_rng_cosmetic;

static uint32_t rng_arg_u32(Avm2Activation* act, uint32_t i)
{
	if (act->argc <= i) return 0;
	double v = avm2_coerce_to_number(act->ctx, act->args[i]);
	if (!isfinite(v) || v < 0.0) return 0;
	return (uint32_t) fmod(v, 4294967296.0);
}

static Avm2Value rng_state(Avm2Activation* act)
{
	(void) act;
	return avm2_number((double) g_avm2_rng.uValue);
}

static Avm2Value rng_set_state(Avm2Activation* act)
{
	avm2_random_seed(&g_avm2_rng, rng_arg_u32(act, 0));
	return avm2_undefined();
}

static Avm2Value rng_cosmetic_state(Avm2Activation* act)
{
	(void) act;
	return avm2_number((double) g_avm2_rng_cosmetic.uValue);
}

static Avm2Value rng_set_cosmetic_state(Avm2Activation* act)
{
	avm2_random_seed(&g_avm2_rng_cosmetic, rng_arg_u32(act, 0));
	return avm2_undefined();
}

static Avm2Value rng_draws(Avm2Activation* act)
{
	(void) act;
	// A double carries every count below 2^53; the LFSR would have to be
	// stepped for millennia to reach that, so no precision note is needed.
	return avm2_number((double) g_avm2_rng_draws);
}

static Avm2Value rng_cosmetic(Avm2Activation* act)
{
	(void) act;
	int32_t raw = avm2_random_next(&g_avm2_rng_cosmetic);
	return avm2_number((double) raw / 2147483648.0);
}

// `Math` is a pure static namespace: avmplus gives it neither a call nor a
// construct behaviour and has dedicated errors for each attempt. Without
// these hooks `Math()` would fall through to the generic one-arg class
// coercion (#1112) and `new Math()` would happily hand back an instance.
// Only Math gets this -- `JSON()` really is #1112 (ecma3/JSON/e15_12_0).
static Avm2Value math_class_call(Avm2Context* ctx, Avm2Class* cls,
                                 const Avm2Value* args, uint32_t argc)
{
	(void) cls; (void) args; (void) argc;
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1075: Math is not a function.");
}

static Avm2Value math_class_construct(Avm2Context* ctx, Avm2Class* cls,
                                      const Avm2Value* args, uint32_t argc)
{
	(void) cls; (void) args; (void) argc;
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1076: Math is not a constructor.");
}

// ---------------------------------------------------------------------------
// Number static math (Flash 11.3 / API 680)
// ---------------------------------------------------------------------------
//
// `Number` re-exports the whole `Math` surface as statics. It is NOT a plain
// alias: these are *declared* natives, so the arg count is checked (avmplus
// throws ArgumentError #1063 when it does not match the signature) and each
// one's `.length` is the declared arity, which as3/Types/Number pins per
// method. `max`/`min` are variadic (`...rest`) with a declared length of 2, so
// they accept any count — as3/Types/Number/visibility/v16 calls both with none.
//
// The results still come back as plain doubles: getQualifiedClassName maps an
// integral double to "int", which is exactly what the tests assert
// (`Number.abs(1)` → "int", `Number.abs(3.14)` → "Number").

static void num_check_argc(Avm2Activation* act, const char* name, uint32_t expected)
{
	if (act->argc == expected) return;
	avm2_throw_error(act->ctx, act->ctx->builtins.argument_error_class,
	                 "Error #1063: Argument count mismatch on Number$/%s(). "
	                 "Expected %u, got %u.", name, expected, act->argc);
}

#define NUMSTATIC(name, arity) \
	static Avm2Value number_static_##name(Avm2Activation* act) \
	{ \
		num_check_argc(act, #name, arity); \
		return math_##name(act); \
	}

NUMSTATIC(abs, 1)
NUMSTATIC(acos, 1)
NUMSTATIC(asin, 1)
NUMSTATIC(atan, 1)
NUMSTATIC(ceil, 1)
NUMSTATIC(cos, 1)
NUMSTATIC(exp, 1)
NUMSTATIC(floor, 1)
NUMSTATIC(log, 1)
NUMSTATIC(round, 1)
NUMSTATIC(sin, 1)
NUMSTATIC(sqrt, 1)
NUMSTATIC(tan, 1)
NUMSTATIC(atan2, 2)
NUMSTATIC(pow, 2)
NUMSTATIC(random, 0)
#undef NUMSTATIC

// The eight constants must be read-only (`Number.E = 0` throws
// ReferenceError #1074), non-deletable and non-enumerable — as3/Types/Number/e
// asserts all four. A getter-only static trait gives all of that for free;
// `avm2_builtin_add_static_const` installs a dont-enum *dynamic* property,
// which is writable and deletable.
#define NUMCONST(fname, value) \
	static Avm2Value number_const_##fname(Avm2Activation* act) \
	{ \
		(void) act; \
		return avm2_number(value); \
	}

NUMCONST(e, 2.718281828459045)
NUMCONST(ln10, 2.302585092994046)
NUMCONST(ln2, 0.6931471805599453)
NUMCONST(log10e, 0.4342944819032518)
NUMCONST(log2e, 1.4426950408889634)
NUMCONST(pi, 3.141592653589793)
NUMCONST(sqrt1_2, 0.7071067811865476)
NUMCONST(sqrt2, 1.4142135623730951)
#undef NUMCONST

static void add_number_statics(Avm2Context* ctx, Avm2Class* cls)
{
	static const struct { const char* name; Avm2MethodFn fn; uint32_t arity; }
	methods[] = {
		{ "abs", number_static_abs, 1 },     { "acos", number_static_acos, 1 },
		{ "asin", number_static_asin, 1 },   { "atan", number_static_atan, 1 },
		{ "atan2", number_static_atan2, 2 }, { "ceil", number_static_ceil, 1 },
		{ "cos", number_static_cos, 1 },     { "exp", number_static_exp, 1 },
		{ "floor", number_static_floor, 1 }, { "log", number_static_log, 1 },
		{ "max", math_max, 2 },              { "min", math_min, 2 },
		{ "pow", number_static_pow, 2 },     { "random", number_static_random, 0 },
		{ "round", number_static_round, 1 }, { "sin", number_static_sin, 1 },
		{ "sqrt", number_static_sqrt, 1 },   { "tan", number_static_tan, 1 },
	};
	for (size_t i = 0; i < sizeof(methods) / sizeof(methods[0]); i++)
	{
		avm2_builtin_add_static_method_n(ctx, cls, methods[i].name,
		                                 methods[i].fn, methods[i].arity);
	}

	static const struct { const char* name; Avm2MethodFn fn; } consts[] = {
		{ "E", number_const_e },           { "LN10", number_const_ln10 },
		{ "LN2", number_const_ln2 },       { "LOG10E", number_const_log10e },
		{ "LOG2E", number_const_log2e },   { "PI", number_const_pi },
		{ "SQRT1_2", number_const_sqrt1_2 }, { "SQRT2", number_const_sqrt2 },
	};
	for (size_t i = 0; i < sizeof(consts) / sizeof(consts[0]); i++)
	{
		avm2_builtin_add_static_getset(ctx, cls, consts[i].name, consts[i].fn, NULL);
	}
}

// ---------------------------------------------------------------------------
// Stack-frame spelling for the three convert methods
// ---------------------------------------------------------------------------
//
// toFixed / toExponential / toPrecision are declared in the AS3 builtin
// namespace in playerglobal, and FP spells a non-public trait's frame with its
// URI: "Number/http://adobe.com/AS3/2006/builtin::toFixed()". Same rule as
// "Function/http://adobe.com/AS3/2006/builtin::call()" (avm2_function.c) --
// only the frame name moves, dispatch keys stay public.
//
// The receiver class is always Number here even for an `int`/`uint` receiver:
// avm2_value_class maps AVM2_VALUE_INTEGER and AVM2_VALUE_NUMBER alike to
// Number, so a primitive never reaches int's or uint's own vtable. That is
// also why FP's SECOND frame for an int receiver ("int/...::toFixed()" outside
// "Number/...::toFixed()") is not reproduced -- it is a STATIC-type rule, not
// a value-kind one, and int and uint are the same runtime value here. See the
// session-18 w2-avmplus-numerics report.
#define AS3_BUILTIN_NS "http://adobe.com/AS3/2006/builtin::"

static Avm2Value convert_framed(Avm2Activation* act, Avm2MethodFn self,
                                Avm2MethodFn impl, const char* frame)
{
	Avm2Context* ctx = act->ctx;
	uint32_t depth0 = ctx->call_depth;
	avm2_callstack_rename_frame(ctx, self, frame);
	Avm2Value r = impl(act);
	// Restore exactly what we found; the throwing path longjmps past this and
	// the unwind resets call_depth for us.
	ctx->call_depth = depth0;
	return r;
}

#define DEFINE_CONVERT_WRAPPER(impl, meth)                                     \
	static Avm2Value impl##_framed(Avm2Activation* act)                        \
	{                                                                          \
		return convert_framed(act, impl##_framed, impl,                        \
		                      "Number/" AS3_BUILTIN_NS meth);                  \
	}

DEFINE_CONVERT_WRAPPER(number_to_fixed, "toFixed")
DEFINE_CONVERT_WRAPPER(number_to_exponential, "toExponential")
DEFINE_CONVERT_WRAPPER(number_to_precision, "toPrecision")

// ---------------------------------------------------------------------------
// Registration
// ---------------------------------------------------------------------------

static void add_number_methods(Avm2Context* ctx, Avm2Class* cls,
                               Avm2MethodFn proto_to_string,
                               Avm2MethodFn proto_value_of)
{
	avm2_builtin_add_method(ctx, cls, "toString", number_to_string);
	// No `toLocaleString` TRAIT. avmplus's Number/int/uint declare toString,
	// valueOf, toFixed, toExponential and toPrecision, but toLocaleString
	// exists only as a *prototype function* (ES3 compat) -- it is absent from
	// the AS3 Object and Number class surfaces alike. The difference is
	// observable: writing a method name that IS a trait reports #1037
	// (ecma3/Exceptions/number_003_rt `o.valueOf = ...`, number_004_rt
	// `o.toString = ...`, both on `new Number()`), while writing
	// toLocaleString finds no trait, so the sealed receiver reports #1056
	// (ecma3/Number/toLocaleString_rt). Ordinary `n.toLocaleString()` calls
	// still resolve through the prototype entry added below, whose numeric
	// arm is number_to_string.
	avm2_builtin_add_method(ctx, cls, "valueOf", number_value_of);
	// The three convert methods carry their AS3 namespace URI in a stack
	// frame; the ES3 prototype copies below deliberately do NOT (a prototype
	// call is a Function frame in FP, not a class-trait one).
	avm2_builtin_add_method(ctx, cls, "toFixed", number_to_fixed_framed);
	avm2_builtin_add_method(ctx, cls, "toExponential",
	                        number_to_exponential_framed);
	avm2_builtin_add_method(ctx, cls, "toPrecision", number_to_precision_framed);

	// ES3-compat layer on the prototype (Ruffle globals/Number.as).
	Avm2Object* proto = cls->prototype_obj;
	avm2_proto_add_function_n(ctx, proto, "toString", proto_to_string, 1);
	avm2_proto_add_function_n(ctx, proto, "toLocaleString", proto_to_string, 1);
	avm2_proto_add_function_n(ctx, proto, "valueOf", proto_value_of, 0);
	avm2_proto_add_function_n(ctx, proto, "toFixed", number_to_fixed, 1);
	avm2_proto_add_function_n(ctx, proto, "toExponential", number_to_exponential, 1);
	avm2_proto_add_function_n(ctx, proto, "toPrecision", number_to_precision, 1);
}

void avm2_register_number(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;

	b->number_class = avm2_builtin_class(ctx, "", "Number", b->object_class);
	b->number_class->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	b->number_class->native_construct = number_construct;
	b->number_class->native_call = number_construct;
	add_number_methods(ctx, b->number_class, number_proto_to_string,
	                   number_proto_value_of);
	avm2_builtin_add_static_const(ctx, b->number_class, "MAX_VALUE",
	                              avm2_number(1.7976931348623157e308));
	avm2_builtin_add_static_const(ctx, b->number_class, "MIN_VALUE",
	                              avm2_number(4.9406564584124654e-324));
	avm2_builtin_add_static_const(ctx, b->number_class, "NaN", avm2_number(NAN));
	avm2_builtin_add_static_const(ctx, b->number_class, "POSITIVE_INFINITY",
	                              avm2_number(INFINITY));
	avm2_builtin_add_static_const(ctx, b->number_class, "NEGATIVE_INFINITY",
	                              avm2_number(-INFINITY));
	// API 680: the Math surface on Number is SWF16+ only. SWF15 content must
	// still see `Number.abs` as undefined (as3/Types/Number/visibility/v15
	// asserts TypeError #1006 for every one of them).
	if (ctx->swf_version >= 16) add_number_statics(ctx, b->number_class);

	b->int_class = avm2_builtin_class(ctx, "", "int", b->object_class);
	b->int_class->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	b->int_class->native_construct = int_construct;
	b->int_class->native_call = int_construct;
	add_number_methods(ctx, b->int_class, int_proto_to_string,
	                   int_proto_value_of);
	avm2_builtin_add_static_const(ctx, b->int_class, "MAX_VALUE",
	                              avm2_integer(2147483647));
	avm2_builtin_add_static_const(ctx, b->int_class, "MIN_VALUE",
	                              avm2_integer((int32_t) -2147483648LL));

	b->uint_class = avm2_builtin_class(ctx, "", "uint", b->object_class);
	b->uint_class->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	b->uint_class->native_construct = uint_construct;
	b->uint_class->native_call = uint_construct;
	add_number_methods(ctx, b->uint_class, uint_proto_to_string,
	                   uint_proto_value_of);
	avm2_builtin_add_static_const(ctx, b->uint_class, "MAX_VALUE",
	                              avm2_number(4294967295.0));
	avm2_builtin_add_static_const(ctx, b->uint_class, "MIN_VALUE", avm2_integer(0));

	b->boolean_class = avm2_builtin_class(ctx, "", "Boolean", b->object_class);
	b->boolean_class->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	b->boolean_class->native_construct = boolean_construct;
	b->boolean_class->native_call = boolean_construct;
	avm2_builtin_add_method(ctx, b->boolean_class, "toString", boolean_to_string);
	avm2_builtin_add_method(ctx, b->boolean_class, "valueOf", boolean_value_of);
	avm2_proto_add_function(ctx, b->boolean_class->prototype_obj, "toString",
	                        boolean_proto_to_string);
	avm2_proto_add_function(ctx, b->boolean_class->prototype_obj, "valueOf",
	                        boolean_proto_value_of);

	Avm2Class* math = avm2_builtin_class(ctx, "", "Math", b->object_class);
	b->math_class = math;
	math->native_call = math_class_call;
	math->native_construct = math_class_construct;
	avm2_builtin_add_static_method(ctx, math, "abs", math_abs);
	avm2_builtin_add_static_method(ctx, math, "acos", math_acos);
	avm2_builtin_add_static_method(ctx, math, "asin", math_asin);
	avm2_builtin_add_static_method(ctx, math, "atan", math_atan);
	avm2_builtin_add_static_method(ctx, math, "atan2", math_atan2);
	avm2_builtin_add_static_method(ctx, math, "ceil", math_ceil);
	avm2_builtin_add_static_method(ctx, math, "cos", math_cos);
	avm2_builtin_add_static_method(ctx, math, "exp", math_exp);
	avm2_builtin_add_static_method(ctx, math, "floor", math_floor);
	avm2_builtin_add_static_method(ctx, math, "log", math_log);
	avm2_builtin_add_static_method(ctx, math, "max", math_max);
	avm2_builtin_add_static_method(ctx, math, "min", math_min);
	avm2_builtin_add_static_method(ctx, math, "pow", math_pow);
	avm2_builtin_add_static_method(ctx, math, "random", math_random);
	avm2_builtin_add_static_method(ctx, math, "round", math_round);
	avm2_builtin_add_static_method(ctx, math, "sin", math_sin);
	avm2_builtin_add_static_method(ctx, math, "sqrt", math_sqrt);
	avm2_builtin_add_static_method(ctx, math, "tan", math_tan);
	avm2_builtin_add_static_const(ctx, math, "E", avm2_number(2.718281828459045));
	avm2_builtin_add_static_const(ctx, math, "LN10", avm2_number(2.302585092994046));
	avm2_builtin_add_static_const(ctx, math, "LN2", avm2_number(0.6931471805599453));
	avm2_builtin_add_static_const(ctx, math, "LOG10E", avm2_number(0.4342944819032518));
	avm2_builtin_add_static_const(ctx, math, "LOG2E", avm2_number(1.4426950408889634));
	avm2_builtin_add_static_const(ctx, math, "PI", avm2_number(3.141592653589793));
	avm2_builtin_add_static_const(ctx, math, "SQRT1_2", avm2_number(0.7071067811865476));
	avm2_builtin_add_static_const(ctx, math, "SQRT2", avm2_number(1.4142135623730951));

	// The determinism hooks (see swfmodern.Rng above). Its own class in its
	// own package rather than four more statics on Math: Math's surface is
	// graded against avmplus and this is a runtime instrument, not ECMA.
	// ⛓ `setState` IS `reset` for this generator — the state is one uint32
	// and the seed is written straight into it, so "reset to seed s" and
	// "put the state back to s" are the same call. 0 means the build's own
	// boot seed (and is not a reachable state: the LFSR never enters 0).
	Avm2Class* rng = avm2_builtin_class(ctx, "swfmodern", "Rng", b->object_class);
	rng->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	avm2_builtin_add_static_method_n(ctx, rng, "state", rng_state, 0);
	avm2_builtin_add_static_method_n(ctx, rng, "setState", rng_set_state, 1);
	avm2_builtin_add_static_method_n(ctx, rng, "cosmeticState",
	                                 rng_cosmetic_state, 0);
	avm2_builtin_add_static_method_n(ctx, rng, "setCosmeticState",
	                                 rng_set_cosmetic_state, 1);
	avm2_builtin_add_static_method_n(ctx, rng, "cosmetic", rng_cosmetic, 0);
	// ⛓ `draws` is MONOTONIC for the life of the process — setState does not
	// zero it. A stream that reports only its state says the state moved; one
	// that also reports its draw count is self-describing (the values are
	// recoverable offline by stepping the generator that many times).
	avm2_builtin_add_static_method_n(ctx, rng, "draws", rng_draws, 0);
}
