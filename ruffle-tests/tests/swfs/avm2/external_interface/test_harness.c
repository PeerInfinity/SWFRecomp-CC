/*
 * Test harness for avm2/external_interface.
 *
 * Ruffle runs this SWF from tests/tests/external_interface/tests.rs
 * (external_interface_avm2) with ExternalInterfaceTestProvider (mod.rs):
 *
 *   "ping"    -> traces "[ExternalInterface] ping", returns "Pong!"
 *   "trace"   -> traces "[ExternalInterface] trace: <args Debug>", returns "Traced!"
 *   "reentry" -> traces "[ExternalInterface] starting reentry", then calls the
 *                registered "callWith" callback with ("trace", "successful reentry!")
 *                and returns its result
 *   anything else -> Null
 *
 * After the first tick the harness makes five host calls (parrot x2,
 * freestanding, removeMe, callWith) and traces each result's Rust Debug form.
 * The AVM1 twin is avm1/external_interface/test_harness.c.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <swf.h>
#include <avm2/avm2_external.h>

/* ------------------------------------------------------------------ */
/* Rust #[derive(Debug)] formatting of ruffle_core::external::Value    */
/* ------------------------------------------------------------------ */

typedef struct DbgBuf
{
	char* buf;
	size_t len;
	size_t cap;
} DbgBuf;

static void db_put(DbgBuf* b, const char* s, size_t n)
{
	if (b->len + n + 1 > b->cap)
	{
		size_t cap = b->cap ? b->cap : 256;
		while (cap < b->len + n + 1) cap *= 2;
		b->buf = realloc(b->buf, cap);
		b->cap = cap;
	}
	memcpy(b->buf + b->len, s, n);
	b->len += n;
	b->buf[b->len] = '\0';
}

static void db_puts(DbgBuf* b, const char* s) { db_put(b, s, strlen(s)); }

/* f64 Debug (core::fmt::float, float_to_general_debug): shortest round-trip
 * digits; decimal with at least one fractional digit when
 * 1e-4 <= |d| < 1e16 (or d == 0), otherwise exponential ("1e16", "1.5e-5"). */
static void db_f64(DbgBuf* b, double d)
{
	char out[64];
	if (isnan(d)) { db_puts(b, "NaN"); return; }
	if (isinf(d)) { db_puts(b, d < 0 ? "-inf" : "inf"); return; }
	if (d == 0.0) { db_puts(b, signbit(d) ? "-0.0" : "0.0"); return; }

	char e[40];
	for (int p = 0; p < 17; p++)
	{
		snprintf(e, sizeof(e), "%.*e", p, d);
		if (strtod(e, NULL) == d) break;
	}
	/* e = [-]D[.DDD]e[+-]XX */
	const char* s = e;
	int neg = 0;
	if (*s == '-') { neg = 1; s++; }
	char digits[32];
	int nd = 0;
	for (; *s && *s != 'e'; s++)
	{
		if (*s != '.') digits[nd++] = *s;
	}
	digits[nd] = '\0';
	int exp = atoi(s + 1);

	int pos = 0;
	if (neg) out[pos++] = '-';
	double a = fabs(d);
	if (a < 1e-4 || a >= 1e16)
	{
		out[pos++] = digits[0];
		if (nd > 1)
		{
			out[pos++] = '.';
			memcpy(out + pos, digits + 1, (size_t) nd - 1);
			pos += nd - 1;
		}
		pos += snprintf(out + pos, sizeof(out) - (size_t) pos, "e%d", exp);
	}
	else if (exp < 0)
	{
		out[pos++] = '0';
		out[pos++] = '.';
		for (int i = 0; i < -exp - 1; i++) out[pos++] = '0';
		memcpy(out + pos, digits, (size_t) nd);
		pos += nd;
	}
	else
	{
		int int_digits = exp + 1;
		for (int i = 0; i < int_digits; i++) out[pos++] = i < nd ? digits[i] : '0';
		out[pos++] = '.';
		if (nd > int_digits)
		{
			memcpy(out + pos, digits + int_digits, (size_t) (nd - int_digits));
			pos += nd - int_digits;
		}
		else
		{
			out[pos++] = '0';
		}
	}
	out[pos] = '\0';
	db_puts(b, out);
}

/* str Debug: quotes, with \" \\ \n \r \t \0 and \u{..} for other controls. */
static void db_str(DbgBuf* b, const char* s)
{
	db_put(b, "\"", 1);
	for (; *s; s++)
	{
		unsigned char c = (unsigned char) *s;
		char esc[16];
		switch (c)
		{
			case '"':  db_puts(b, "\\\""); break;
			case '\\': db_puts(b, "\\\\"); break;
			case '\n': db_puts(b, "\\n"); break;
			case '\r': db_puts(b, "\\r"); break;
			case '\t': db_puts(b, "\\t"); break;
			case '\0': db_puts(b, "\\0"); break;
			default:
				if (c < 0x20 || c == 0x7f)
				{
					snprintf(esc, sizeof(esc), "\\u{%x}", c);
					db_puts(b, esc);
				}
				else
				{
					db_put(b, (const char*) &c, 1);
				}
		}
	}
	db_put(b, "\"", 1);
}

static void db_value(DbgBuf* b, const Avm2EiValue* v)
{
	switch (v->kind)
	{
		case AVM2_EI_UNDEFINED: db_puts(b, "Undefined"); break;
		case AVM2_EI_NULL:      db_puts(b, "Null"); break;
		case AVM2_EI_BOOL:      db_puts(b, v->b ? "Bool(true)" : "Bool(false)"); break;
		case AVM2_EI_NUMBER:
			db_puts(b, "Number(");
			db_f64(b, v->d);
			db_puts(b, ")");
			break;
		case AVM2_EI_STRING:
			db_puts(b, "String(");
			db_str(b, v->str);
			db_puts(b, ")");
			break;
		case AVM2_EI_LIST:
			db_puts(b, "List([");
			for (uint32_t i = 0; i < v->count; i++)
			{
				if (i > 0) db_puts(b, ", ");
				db_value(b, &v->items[i]);
			}
			db_puts(b, "])");
			break;
		case AVM2_EI_OBJECT:
			db_puts(b, "Object({");
			for (uint32_t i = 0; i < v->count; i++)
			{
				if (i > 0) db_puts(b, ", ");
				db_str(b, v->keys[i]);
				db_puts(b, ": ");
				db_value(b, &v->items[i]);
			}
			db_puts(b, "})");
			break;
	}
}

/* Debug of a value, or of an args slice ("[a, b]") when `slice` is set. */
static void trace_debug(const char* prefix, const Avm2EiValue* vals, uint32_t n, int slice)
{
	DbgBuf b = {0};
	db_puts(&b, prefix);
	if (slice) db_puts(&b, "[");
	for (uint32_t i = 0; i < n; i++)
	{
		if (i > 0) db_puts(&b, ", ");
		db_value(&b, &vals[i]);
	}
	if (slice) db_puts(&b, "]");
	printf("%s\n", b.buf);
	free(b.buf);
}

/* ------------------------------------------------------------------ */
/* ExternalInterfaceTestProvider                                       */
/* ------------------------------------------------------------------ */

static Avm2EiValue provider_call(const char* name, const Avm2EiValue* args, uint32_t argc)
{
	if (strcmp(name, "trace") == 0)
	{
		trace_debug("[ExternalInterface] trace: ", args, argc, 1);
		return avm2_ei_string("Traced!");
	}
	if (strcmp(name, "ping") == 0)
	{
		printf("[ExternalInterface] ping\n");
		return avm2_ei_string("Pong!");
	}
	if (strcmp(name, "reentry") == 0)
	{
		printf("[ExternalInterface] starting reentry\n");
		Avm2EiValue cb_args[2] = {
			avm2_ei_string("trace"),
			avm2_ei_string("successful reentry!"),
		};
		Avm2EiValue r = avm2_ei_call_internal("callWith", cb_args, 2);
		avm2_ei_value_free(&cb_args[0]);
		avm2_ei_value_free(&cb_args[1]);
		return r;
	}
	return avm2_ei_null();
}

/* ------------------------------------------------------------------ */
/* Host calls after the first tick (tests.rs external_interface_avm2)  */
/* ------------------------------------------------------------------ */

static void host_call(const char* name, Avm2EiValue* args, uint32_t argc, const char* label)
{
	Avm2EiValue r = avm2_ei_call_internal(name, args, argc);
	for (uint32_t i = 0; i < argc; i++) avm2_ei_value_free(&args[i]);
	if (label != NULL) trace_debug(label, &r, 1, 0);
	avm2_ei_value_free(&r);
}

static void after_tick(SWFAppContext* ctx, int tick)
{
	(void) ctx;
	if (tick != 1) return;

	{
		Avm2EiValue args[1] = { avm2_ei_string("Hello World!") };
		host_call("parrot", args, 1, "After calling `parrot` with a string: ");
	}
	{
		char** keys = malloc(2 * sizeof(char*));
		Avm2EiValue* vals = malloc(2 * sizeof(Avm2EiValue));
		keys[0] = strdup("a");
		vals[0] = avm2_ei_number(100.0);
		keys[1] = strdup("b");
		vals[1] = avm2_ei_string("string");
		Avm2EiValue args[1] = { avm2_ei_object(keys, vals, 2) };
		host_call("parrot", args, 1, "After calling `parrot` with an object: ");
	}
	{
		Avm2EiValue args[1] = { avm2_ei_string("Hello World!") };
		host_call("freestanding", args, 1, NULL);
	}
	printf("Before calling `removeMe`\n");
	host_call("removeMe", NULL, 0, "After calling `removeMe`: ");
	{
		Avm2EiValue items[4] = {
			avm2_ei_string("string"),
			avm2_ei_number(100.0),
			avm2_ei_null(),
			avm2_ei_bool(false),
		};
		Avm2EiValue args[2] = { avm2_ei_string("trace"), avm2_ei_list(items, 4) };
		host_call("callWith", args, 2, "After calling `callWith` with a complex payload: ");
	}
	fflush(stdout);
}

/* ------------------------------------------------------------------ */
/* Initialization                                                      */
/* ------------------------------------------------------------------ */

void test_harness_init(SWFAppContext* ctx)
{
	typedef void (*AfterTickHandler)(SWFAppContext*, int);
	extern AfterTickHandler g_after_tick_handler;
	(void) ctx;
	avm2_ei_set_provider(provider_call);
	g_after_tick_handler = after_tick;
}
