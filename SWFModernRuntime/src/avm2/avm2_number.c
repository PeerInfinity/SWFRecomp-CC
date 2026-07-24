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

_Noreturn static void throw_1002(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.range_error_class,
	                 "Error #1002: Number.toPrecision has a range of 1 to 21. "
	                 "Number.toFixed and Number.toExponential have a range of 0 to "
	                 "20. Specified value is not within expected range.");
}

// print_with_radix (Ruffle number.rs): radix 10 → normal coercion.
static const Avm2String* print_with_radix(Avm2Context* ctx, double number, int radix)
{
	char buf[420];
	if (radix == 10)
	{
		avm2_format_number(buf, sizeof(buf), number);
		return avm2_string_from_literal(ctx, buf);
	}
	if (isnan(number)) return avm2_string_from_literal(ctx, "NaN");
	if (isinf(number))
	{
		return avm2_string_from_literal(ctx, number < 0 ? "-Infinity" : "Infinity");
	}
	static const char DIGIT_CHARS[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char digits[1200];
	int n = 0;
	int neg = number < 0.0;
	number = fabs(number);
	do
	{
		double digit = fmod(number, (double) radix);
		number /= (double) radix;
		digits[n++] = DIGIT_CHARS[(int) digit];
	} while (number >= 1.0 && n < (int) sizeof(digits) - 2);
	if (neg) digits[n++] = '-';
	// Reverse.
	char out[1204];
	for (int i = 0; i < n; i++) out[i] = digits[n - 1 - i];
	return avm2_string_new(ctx, out, (uint32_t) n);
}

static Avm2Value number_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	int32_t radix = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 10;
	if (radix < 2 || radix > 36)
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

static Avm2Value number_proto_to_string(Avm2Activation* act)
{
	if (numeric_receiver(act->this_val)) return number_to_string(act);
	Avm2Activation zero = *act;
	zero.this_val = avm2_number(0.0);
	return number_to_string(&zero);
}

static Avm2Value number_proto_value_of(Avm2Activation* act)
{
	if (numeric_receiver(act->this_val)) return act->this_val;
	return avm2_number(0.0);
}

static Avm2Value number_to_fixed(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	int32_t digits = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	if (digits < 0 || digits > 20) throw_1002(ctx);
	char buf[400];
	if (isnan(number)) return avm2_string(avm2_string_from_literal(ctx, "NaN"));
	if (isinf(number))
	{
		return avm2_string(avm2_string_from_literal(
			ctx, number < 0 ? "-Infinity" : "Infinity"));
	}
	snprintf(buf, sizeof(buf), "%.*f", (int) digits, number);
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

static Avm2Value number_to_exponential(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	int32_t digits = act->argc > 0 ? avm2_coerce_to_i32(ctx, act->args[0]) : 0;
	if (digits < 0 || digits > 20) throw_1002(ctx);
	char buf[80];
	if (number == 0.0)
	{
		// Ruffle quirk-for-quirk: 0.toExponential(0) = "1e-15",
		// 0.toExponential(d) = "0.000...e-16".
		if (digits == 0)
		{
			return avm2_string(avm2_string_from_literal(ctx, "1e-15"));
		}
		int n = snprintf(buf, sizeof(buf), "0.");
		for (int i = 0; i < digits && n < (int) sizeof(buf) - 6; i++) buf[n++] = '0';
		snprintf(buf + n, sizeof(buf) - n, "e-16");
		return avm2_string(avm2_string_from_literal(ctx, buf));
	}
	if (isnan(number)) return avm2_string(avm2_string_from_literal(ctx, "NaN"));
	if (isinf(number))
	{
		return avm2_string(avm2_string_from_literal(
			ctx, number < 0 ? "-Infinity" : "Infinity"));
	}
	// C %.*e gives "d.ddde±XX" (2+ exponent digits); Rust gives "e±X" with
	// no zero padding and drops "e+0" entirely.
	char tmp[80];
	snprintf(tmp, sizeof(tmp), "%.*e", (int) digits, number);
	char* e = strchr(tmp, 'e');
	int exp_val = atoi(e + 1);
	*e = '\0';
	if (exp_val == 0)
	{
		snprintf(buf, sizeof(buf), "%s", tmp);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%se%+d", tmp, exp_val);
	}
	return avm2_string(avm2_string_from_literal(ctx, buf));
}

// print_with_precision (Ruffle number.rs).
static const Avm2String* print_with_precision(Avm2Context* ctx, double number,
                                              int wanted_digits)
{
	char buf[420];
	double available_digits = floor(log10(fabs(number)));
	if (isnan(available_digits) || isinf(available_digits))
	{
		available_digits = 1.0;
	}
	double scale = pow(10.0, (double) wanted_digits - available_digits - 1.0);
	double precision = floor(number * scale) / scale;
	if ((double) wanted_digits <= available_digits)
	{
		char mbuf[400];
		avm2_format_number(mbuf, sizeof(mbuf), precision / pow(10.0, available_digits));
		snprintf(buf, sizeof(buf), "%se%c%.0f", mbuf,
		         available_digits < 0.0 ? '-' : '+', fabs(available_digits));
	}
	else
	{
		avm2_format_number(buf, sizeof(buf), precision);
	}
	return avm2_string_from_literal(ctx, buf);
}

static Avm2Value number_to_precision(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	double number = this_number(act);
	if (act->argc == 0 || act->args[0].kind == AVM2_VALUE_UNDEFINED)
	{
		char buf[420];
		avm2_format_number(buf, sizeof(buf), number);
		return avm2_string(avm2_string_from_literal(ctx, buf));
	}
	int32_t digits = avm2_coerce_to_i32(ctx, act->args[0]);
	if (digits < 1 || digits > 21) throw_1002(ctx);
	return avm2_string(print_with_precision(ctx, number, digits));
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
	const int32_t c1 = 1376312589L;
	const int32_t c2 = 789221L;
	const int32_t c3 = 15731L;
	iSeed = ((iSeed << 13) ^ iSeed) - (iSeed >> 21);
	int32_t iResult = (iSeed * (iSeed * iSeed * c3 + c2) + c1) & 0x7FFFFFFF;
	iResult += iSeed;
	iResult = ((iResult << 13) ^ iResult) - (iResult >> 21);
	return iResult;
}

static int32_t avm2_generate_random_number(void)
{
	if (g_avm2_rng.uValue == 0)
	{
		uint32_t seed;
#ifdef MOCK_DATE_TIME
		seed = (uint32_t) ((int64_t) (MOCK_DATE_TIME) * 1000LL);
#else
		seed = 987654321u;
#endif
		int n = 31;
		g_avm2_rng.uValue = seed;
		g_avm2_rng.uSequenceLength = (uint32_t) ((1ULL << n) - 1ULL);
		g_avm2_rng.uXorMask = avm2_random_xor_masks[n - 2];
	}
	if (g_avm2_rng.uValue & 1u)
	{
		g_avm2_rng.uValue = (g_avm2_rng.uValue >> 1) ^ g_avm2_rng.uXorMask;
	}
	else
	{
		g_avm2_rng.uValue >>= 1;
	}
	int32_t aNum = (int32_t) g_avm2_rng.uValue;
	aNum = avm2_random_pure_hasher(aNum * 71L);
	return aNum & 0x7FFFFFFF;
}

static Avm2Value math_random(Avm2Activation* act)
{
	(void) act;
	int32_t raw = avm2_generate_random_number();
	return avm2_number((double) raw / 2147483648.0);
}

// ---------------------------------------------------------------------------
// Registration
// ---------------------------------------------------------------------------

static void add_number_methods(Avm2Context* ctx, Avm2Class* cls)
{
	avm2_builtin_add_method(ctx, cls, "toString", number_to_string);
	avm2_builtin_add_method(ctx, cls, "toLocaleString", number_to_string);
	avm2_builtin_add_method(ctx, cls, "valueOf", number_value_of);
	avm2_builtin_add_method(ctx, cls, "toFixed", number_to_fixed);
	avm2_builtin_add_method(ctx, cls, "toExponential", number_to_exponential);
	avm2_builtin_add_method(ctx, cls, "toPrecision", number_to_precision);

	// ES3-compat layer on the prototype (Ruffle globals/Number.as).
	Avm2Object* proto = cls->prototype_obj;
	avm2_proto_add_function_n(ctx, proto, "toString", number_proto_to_string, 1);
	avm2_proto_add_function_n(ctx, proto, "toLocaleString", number_proto_to_string, 1);
	avm2_proto_add_function_n(ctx, proto, "valueOf", number_proto_value_of, 0);
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
	add_number_methods(ctx, b->number_class);
	avm2_builtin_add_static_const(ctx, b->number_class, "MAX_VALUE",
	                              avm2_number(1.7976931348623157e308));
	avm2_builtin_add_static_const(ctx, b->number_class, "MIN_VALUE",
	                              avm2_number(4.9406564584124654e-324));
	avm2_builtin_add_static_const(ctx, b->number_class, "NaN", avm2_number(NAN));
	avm2_builtin_add_static_const(ctx, b->number_class, "POSITIVE_INFINITY",
	                              avm2_number(INFINITY));
	avm2_builtin_add_static_const(ctx, b->number_class, "NEGATIVE_INFINITY",
	                              avm2_number(-INFINITY));

	b->int_class = avm2_builtin_class(ctx, "", "int", b->object_class);
	b->int_class->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	b->int_class->native_construct = int_construct;
	b->int_class->native_call = int_construct;
	add_number_methods(ctx, b->int_class);
	avm2_builtin_add_static_const(ctx, b->int_class, "MAX_VALUE",
	                              avm2_integer(2147483647));
	avm2_builtin_add_static_const(ctx, b->int_class, "MIN_VALUE",
	                              avm2_integer((int32_t) -2147483648LL));

	b->uint_class = avm2_builtin_class(ctx, "", "uint", b->object_class);
	b->uint_class->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	b->uint_class->native_construct = uint_construct;
	b->uint_class->native_call = uint_construct;
	add_number_methods(ctx, b->uint_class);
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
	                        boolean_to_string);
	avm2_proto_add_function(ctx, b->boolean_class->prototype_obj, "valueOf",
	                        boolean_value_of);

	Avm2Class* math = avm2_builtin_class(ctx, "", "Math", b->object_class);
	b->math_class = math;
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
}
