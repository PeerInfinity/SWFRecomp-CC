// JSON builtin — port of Ruffle core/src/avm2/globals/json.rs (which backs
// it with serde_json): strict ECMA-404 parsing with insertion-order object
// keys (Ruffle enables serde's preserve_order), integral numbers landing
// as wrapping-i32 Integers, reviver/replacer (function or prop-list array)
// semantics, toJSON hooks, cyclic detection (TypeError 1129), and the
// serde compact/pretty output formats (lowercase \u escapes, ryu-style
// float text). Registration is SWF-version-gated by avm2_globals.c: the
// JSON class appears from SWF13 (API 674 — json_version_gated is SWF12).

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

_Noreturn static void throw_1132(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.syntax_error_class,
	                 "Error #1132: Invalid JSON parse input.");
}

_Noreturn static void throw_1131(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1131: Replacer argument to JSON stringifier must "
	                 "be an array or a two parameter function.");
}

_Noreturn static void throw_1129(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1129: Cyclic structure cannot be converted to "
	                 "JSON string.");
}

// ---------------------------------------------------------------------------
// Parse: strict JSON → JVal tree (validated before any reviver runs, like
// Ruffle's serde_json::from_str pass)
// ---------------------------------------------------------------------------

typedef struct JVal JVal;

typedef struct JEntry
{
	const char* key;  // object entries only (decoded UTF-8)
	uint32_t key_len;
	JVal* val;
} JEntry;

struct JVal
{
	uint8_t kind;  // 0 null, 1 bool, 2 number, 3 string, 4 object, 5 array
	int b;
	double num;
	const char* str;
	uint32_t str_len;
	JEntry* items;
	uint32_t count;
};

typedef struct JParser
{
	Avm2Context* ctx;
	const char* s;
	uint32_t len;
	uint32_t i;
	int failed;
} JParser;

static void jp_ws(JParser* p)
{
	while (p->i < p->len)
	{
		char c = p->s[p->i];
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r') p->i++;
		else break;
	}
}

static JVal* jv_new(JParser* p, uint8_t kind)
{
	JVal* v = avm2_alloc(p->ctx, sizeof(JVal));
	memset(v, 0, sizeof(JVal));
	v->kind = kind;
	return v;
}

static JVal* jp_value(JParser* p);

static int jp_hex(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return -1;
}

// Parse a JSON string body (after the opening quote). Returns decoded
// UTF-8; NULL on error.
static const char* jp_string(JParser* p, uint32_t* out_len)
{
	char* out = avm2_alloc(p->ctx, p->len - p->i + 4);
	uint32_t n = 0;
	while (p->i < p->len)
	{
		unsigned char c = (unsigned char) p->s[p->i];
		if (c == '"')
		{
			p->i++;
			out[n] = '\0';
			*out_len = n;
			return out;
		}
		if (c < 0x20)
		{
			return NULL;  // raw control chars are invalid
		}
		if (c != '\\')
		{
			out[n++] = (char) c;
			p->i++;
			continue;
		}
		p->i++;
		if (p->i >= p->len) return NULL;
		char e = p->s[p->i++];
		switch (e)
		{
			case '"': out[n++] = '"'; break;
			case '\\': out[n++] = '\\'; break;
			case '/': out[n++] = '/'; break;
			case 'b': out[n++] = '\b'; break;
			case 'f': out[n++] = '\f'; break;
			case 'n': out[n++] = '\n'; break;
			case 'r': out[n++] = '\r'; break;
			case 't': out[n++] = '\t'; break;
			case 'u':
			{
				if (p->i + 4 > p->len) return NULL;
				int h0 = jp_hex(p->s[p->i]);
				int h1 = jp_hex(p->s[p->i + 1]);
				int h2 = jp_hex(p->s[p->i + 2]);
				int h3 = jp_hex(p->s[p->i + 3]);
				if (h0 < 0 || h1 < 0 || h2 < 0 || h3 < 0) return NULL;
				uint32_t cp = (uint32_t) ((h0 << 12) | (h1 << 8) | (h2 << 4) | h3);
				p->i += 4;
				if (cp >= 0xD800 && cp < 0xDC00)
				{
					// High surrogate: require the low half (serde errors on
					// lone surrogates).
					if (p->i + 6 > p->len || p->s[p->i] != '\\'
					    || p->s[p->i + 1] != 'u')
					{
						return NULL;
					}
					int g0 = jp_hex(p->s[p->i + 2]);
					int g1 = jp_hex(p->s[p->i + 3]);
					int g2 = jp_hex(p->s[p->i + 4]);
					int g3 = jp_hex(p->s[p->i + 5]);
					if (g0 < 0 || g1 < 0 || g2 < 0 || g3 < 0) return NULL;
					uint32_t lo = (uint32_t) ((g0 << 12) | (g1 << 8) | (g2 << 4) | g3);
					if (lo < 0xDC00 || lo >= 0xE000) return NULL;
					p->i += 6;
					cp = 0x10000 + ((cp - 0xD800) << 10) + (lo - 0xDC00);
				}
				else if (cp >= 0xDC00 && cp < 0xE000)
				{
					return NULL;
				}
				// UTF-8 encode.
				if (cp < 0x80) out[n++] = (char) cp;
				else if (cp < 0x800)
				{
					out[n++] = (char) (0xC0 | (cp >> 6));
					out[n++] = (char) (0x80 | (cp & 0x3F));
				}
				else if (cp < 0x10000)
				{
					out[n++] = (char) (0xE0 | (cp >> 12));
					out[n++] = (char) (0x80 | ((cp >> 6) & 0x3F));
					out[n++] = (char) (0x80 | (cp & 0x3F));
				}
				else
				{
					out[n++] = (char) (0xF0 | (cp >> 18));
					out[n++] = (char) (0x80 | ((cp >> 12) & 0x3F));
					out[n++] = (char) (0x80 | ((cp >> 6) & 0x3F));
					out[n++] = (char) (0x80 | (cp & 0x3F));
				}
				break;
			}
			default:
				return NULL;
		}
	}
	return NULL;  // unterminated
}

static int jp_append(JParser* p, JVal* v, uint32_t* cap, JEntry e)
{
	if (v->count == *cap)
	{
		uint32_t new_cap = *cap == 0 ? 8 : *cap * 2;
		JEntry* grown = avm2_alloc(p->ctx, new_cap * sizeof(JEntry));
		if (v->count > 0) memcpy(grown, v->items, v->count * sizeof(JEntry));
		v->items = grown;
		*cap = new_cap;
	}
	v->items[v->count++] = e;
	return 1;
}

static JVal* jp_value(JParser* p)
{
	jp_ws(p);
	if (p->i >= p->len) return NULL;
	char c = p->s[p->i];
	if (c == 'n')
	{
		if (p->i + 4 > p->len || memcmp(p->s + p->i, "null", 4) != 0) return NULL;
		p->i += 4;
		return jv_new(p, 0);
	}
	if (c == 't')
	{
		if (p->i + 4 > p->len || memcmp(p->s + p->i, "true", 4) != 0) return NULL;
		p->i += 4;
		JVal* v = jv_new(p, 1);
		v->b = 1;
		return v;
	}
	if (c == 'f')
	{
		if (p->i + 5 > p->len || memcmp(p->s + p->i, "false", 5) != 0) return NULL;
		p->i += 5;
		return jv_new(p, 1);
	}
	if (c == '"')
	{
		p->i++;
		uint32_t sl = 0;
		const char* s = jp_string(p, &sl);
		if (s == NULL) return NULL;
		JVal* v = jv_new(p, 3);
		v->str = s;
		v->str_len = sl;
		return v;
	}
	if (c == '-' || (c >= '0' && c <= '9'))
	{
		// Strict JSON number grammar.
		uint32_t start = p->i;
		if (p->s[p->i] == '-') p->i++;
		if (p->i >= p->len) return NULL;
		if (p->s[p->i] == '0')
		{
			p->i++;
		}
		else if (p->s[p->i] >= '1' && p->s[p->i] <= '9')
		{
			while (p->i < p->len && p->s[p->i] >= '0' && p->s[p->i] <= '9') p->i++;
		}
		else
		{
			return NULL;
		}
		if (p->i < p->len && p->s[p->i] == '.')
		{
			p->i++;
			if (p->i >= p->len || p->s[p->i] < '0' || p->s[p->i] > '9') return NULL;
			while (p->i < p->len && p->s[p->i] >= '0' && p->s[p->i] <= '9') p->i++;
		}
		if (p->i < p->len && (p->s[p->i] == 'e' || p->s[p->i] == 'E'))
		{
			p->i++;
			if (p->i < p->len && (p->s[p->i] == '+' || p->s[p->i] == '-')) p->i++;
			if (p->i >= p->len || p->s[p->i] < '0' || p->s[p->i] > '9') return NULL;
			while (p->i < p->len && p->s[p->i] >= '0' && p->s[p->i] <= '9') p->i++;
		}
		char buf[64];
		uint32_t nl = p->i - start;
		if (nl >= sizeof(buf))
		{
			// Very long numbers still parse (strtod handles the precision).
			char* big = avm2_alloc(p->ctx, nl + 1);
			memcpy(big, p->s + start, nl);
			big[nl] = '\0';
			JVal* v = jv_new(p, 2);
			v->num = strtod(big, NULL);
			return v;
		}
		memcpy(buf, p->s + start, nl);
		buf[nl] = '\0';
		JVal* v = jv_new(p, 2);
		v->num = strtod(buf, NULL);
		return v;
	}
	if (c == '{')
	{
		p->i++;
		JVal* v = jv_new(p, 4);
		uint32_t cap = 0;
		jp_ws(p);
		if (p->i < p->len && p->s[p->i] == '}')
		{
			p->i++;
			return v;
		}
		for (;;)
		{
			jp_ws(p);
			if (p->i >= p->len || p->s[p->i] != '"') return NULL;
			p->i++;
			JEntry e;
			e.key = jp_string(p, &e.key_len);
			if (e.key == NULL) return NULL;
			jp_ws(p);
			if (p->i >= p->len || p->s[p->i] != ':') return NULL;
			p->i++;
			e.val = jp_value(p);
			if (e.val == NULL) return NULL;
			jp_append(p, v, &cap, e);
			jp_ws(p);
			if (p->i >= p->len) return NULL;
			if (p->s[p->i] == ',')
			{
				p->i++;
				continue;
			}
			if (p->s[p->i] == '}')
			{
				p->i++;
				return v;
			}
			return NULL;
		}
	}
	if (c == '[')
	{
		p->i++;
		JVal* v = jv_new(p, 5);
		uint32_t cap = 0;
		jp_ws(p);
		if (p->i < p->len && p->s[p->i] == ']')
		{
			p->i++;
			return v;
		}
		for (;;)
		{
			JEntry e;
			e.key = NULL;
			e.key_len = 0;
			e.val = jp_value(p);
			if (e.val == NULL) return NULL;
			jp_append(p, v, &cap, e);
			jp_ws(p);
			if (p->i >= p->len) return NULL;
			if (p->s[p->i] == ',')
			{
				p->i++;
				continue;
			}
			if (p->s[p->i] == ']')
			{
				p->i++;
				return v;
			}
			return NULL;
		}
	}
	return NULL;
}

// deserialize_json_inner (Ruffle): JVal → Avm2Value with reviver applied
// bottom-up.
static Avm2Value j_deserialize(Avm2Context* ctx, const JVal* v, Avm2Value reviver)
{
	int has_reviver = reviver.kind != AVM2_VALUE_UNDEFINED;
	switch (v->kind)
	{
		case 0: return avm2_null();
		case 1: return avm2_bool(v->b != 0);
		case 2:
			// Integral doubles land as wrapping-i32 Integers (Ruffle).
			if (v->num == trunc(v->num) && !isinf(v->num))
			{
				return avm2_integer(avm2_f64_to_wrapping_i32(v->num));
			}
			return avm2_number(v->num);
		case 3: return avm2_string(avm2_string_new(ctx, v->str, v->str_len));
		case 4:
		{
			Avm2Object* obj = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);
			obj->cls = ctx->builtins.object_class;
			obj->proto = ctx->builtins.object_class->prototype_obj;
			for (uint32_t i = 0; i < v->count; i++)
			{
				const JEntry* e = &v->items[i];
				Avm2Value val = j_deserialize(ctx, e->val, reviver);
				Avm2Value mapped = val;
				if (has_reviver)
				{
					Avm2Value args[2];
					args[0] = avm2_string(avm2_string_new(ctx, e->key, e->key_len));
					args[1] = val;
					mapped = avm2_call_value(ctx, reviver, avm2_null(), args, 2);
				}
				if (mapped.kind == AVM2_VALUE_UNDEFINED)
				{
					avm2_object_delete_dynamic(obj, e->key, e->key_len);
				}
				else
				{
					avm2_object_set_dynamic(ctx, obj, e->key, e->key_len, mapped);
				}
			}
			return avm2_object_value(obj);
		}
		case 5:
		{
			Avm2Object* arr = avm2_array_new(ctx, 0);
			for (uint32_t i = 0; i < v->count; i++)
			{
				Avm2Value val = j_deserialize(ctx, v->items[i].val, reviver);
				if (has_reviver)
				{
					Avm2Value args[2];
					args[0] = avm2_uint_value(i);
					args[1] = val;
					val = avm2_call_value(ctx, reviver, avm2_null(), args, 2);
				}
				avm2_array_push(ctx, arr, val);
			}
			return avm2_object_value(arr);
		}
		default: return avm2_undefined();
	}
}

static Avm2Value json_parse(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value input = act->argc > 0 ? act->args[0] : avm2_undefined();
	if (input.kind == AVM2_VALUE_UNDEFINED || input.kind == AVM2_VALUE_NULL)
	{
		throw_1132(ctx);
	}
	const Avm2String* text = avm2_coerce_to_string(ctx, input);

	Avm2Value reviver = avm2_undefined();
	if (act->argc > 1 && act->args[1].kind != AVM2_VALUE_UNDEFINED
	    && act->args[1].kind != AVM2_VALUE_NULL)
	{
		if (act->args[1].kind != AVM2_VALUE_OBJECT
		    || act->args[1].u.obj->kind != AVM2_OBJ_FUNCTION)
		{
			avm2_throw_error(ctx, ctx->builtins.type_error_class,
			                 "Error #1034: Type Coercion failed: cannot convert "
			                 "value to Function.");
		}
		reviver = act->args[1];
	}

	JParser p = { ctx, text->utf8, text->len, 0, 0 };
	JVal* v = jp_value(&p);
	if (v == NULL) throw_1132(ctx);
	jp_ws(&p);
	if (p.i != p.len) throw_1132(ctx);

	Avm2Value val = j_deserialize(ctx, v, reviver);
	if (reviver.kind != AVM2_VALUE_UNDEFINED)
	{
		Avm2Value args[2];
		args[0] = avm2_string(avm2_string_from_literal(ctx, ""));
		args[1] = val;
		val = avm2_call_value(ctx, reviver, avm2_null(), args, 2);
	}
	return val;
}

// ---------------------------------------------------------------------------
// Stringify
// ---------------------------------------------------------------------------

typedef struct StrBuf
{
	Avm2Context* ctx;
	char* p;
	uint32_t n;
	uint32_t cap;
} StrBuf;

static void sb_reserve(StrBuf* b, uint32_t extra)
{
	if (b->n + extra <= b->cap) return;
	uint32_t new_cap = b->cap == 0 ? 128 : b->cap;
	while (new_cap < b->n + extra) new_cap *= 2;
	char* grown = avm2_alloc(b->ctx, new_cap);
	if (b->n > 0) memcpy(grown, b->p, b->n);
	b->p = grown;
	b->cap = new_cap;
}

static void sb_put(StrBuf* b, const char* s, uint32_t len)
{
	sb_reserve(b, len);
	memcpy(b->p + b->n, s, len);
	b->n += len;
}

static void sb_putc(StrBuf* b, char c)
{
	sb_reserve(b, 1);
	b->p[b->n++] = c;
}

static void sb_lit(StrBuf* b, const char* s)
{
	sb_put(b, s, (uint32_t) strlen(s));
}

// serde_json string escaping: ", \, \b \t \n \f \r, other controls as
// lowercase \u00xx. Non-ASCII passes through as raw UTF-8.
static void sb_json_string(StrBuf* b, const char* s, uint32_t len)
{
	static const char hex[] = "0123456789abcdef";
	sb_putc(b, '"');
	for (uint32_t i = 0; i < len; i++)
	{
		unsigned char c = (unsigned char) s[i];
		switch (c)
		{
			case '"': sb_lit(b, "\\\""); break;
			case '\\': sb_lit(b, "\\\\"); break;
			case '\b': sb_lit(b, "\\b"); break;
			case '\f': sb_lit(b, "\\f"); break;
			case '\n': sb_lit(b, "\\n"); break;
			case '\r': sb_lit(b, "\\r"); break;
			case '\t': sb_lit(b, "\\t"); break;
			default:
				if (c < 0x20)
				{
					char e[7] = { '\\', 'u', '0', '0', hex[c >> 4], hex[c & 15], 0 };
					sb_put(b, e, 6);
				}
				else
				{
					sb_putc(b, (char) c);
				}
		}
	}
	sb_putc(b, '"');
}

// serde/ryu float text: shortest round-trip, integral values keep a ".0",
// exponents render as "e21"/"e-7" (no '+').
static void sb_json_number(StrBuf* b, double n)
{
	char buf[48];
	int len = avm2_format_number(buf, sizeof(buf), n);
	int has_frac = 0;
	int epos = -1;
	for (int i = 0; i < len; i++)
	{
		if (buf[i] == '.') has_frac = 1;
		if (buf[i] == 'e' || buf[i] == 'E') epos = i;
	}
	if (epos >= 0 && buf[epos + 1] == '+')
	{
		memmove(buf + epos + 1, buf + epos + 2, (size_t) (len - epos - 2));
		len--;
	}
	sb_put(b, buf, (uint32_t) len);
	if (!has_frac && epos < 0)
	{
		sb_lit(b, ".0");
	}
}

typedef struct JSer
{
	Avm2Context* ctx;
	Avm2Activation* act;
	Avm2Value replacer_fn;      // undefined = none
	Avm2Object* prop_list;      // NULL = none
	const char* indent;         // NULL = compact
	uint32_t indent_len;
	uint32_t depth;
	Avm2Object* stack[256];     // cycle detection
	uint32_t stack_n;
} JSer;

static void js_newline_indent(JSer* js, StrBuf* b)
{
	sb_putc(b, '\n');
	for (uint32_t i = 0; i < js->depth; i++)
	{
		sb_put(b, js->indent, js->indent_len);
	}
}

static void js_serialize_value(JSer* js, StrBuf* b, Avm2Value v);

// toJSON + replacer-function mapping (Ruffle map_value).
static Avm2Value js_map_value(JSer* js, const char* key, uint32_t key_len, Avm2Value v)
{
	Avm2Context* ctx = js->ctx;
	if (v.kind == AVM2_VALUE_OBJECT
	    && avm2_has_public_property(ctx, v, "toJSON", 6))
	{
		Avm2Value args[1];
		args[0] = avm2_string(avm2_string_new(ctx, key, key_len));
		v = avm2_call_public_property(ctx, v, "toJSON", 6, args, 1);
	}
	if (js->replacer_fn.kind != AVM2_VALUE_UNDEFINED)
	{
		Avm2Value args[2];
		args[0] = avm2_string(avm2_string_new(ctx, key, key_len));
		args[1] = v;
		v = avm2_call_value(ctx, js->replacer_fn, avm2_null(), args, 2);
	}
	return v;
}

// Ruffle Value::normalize: integral doubles in the 29-bit atom range
// become Integers before serialization.
static Avm2Value js_normalize(Avm2Value v)
{
	if (v.kind == AVM2_VALUE_NUMBER)
	{
		int32_t i = (int32_t) v.u.d;
		if (v.u.d == (double) i && !(v.u.d == 0.0 && signbit(v.u.d))
		    && i < (1 << 28) && i >= -(1 << 28))
		{
			return avm2_integer(i);
		}
	}
	return v;
}

static Avm2Value js_iter_get(JSer* js, Avm2Object* obj, uint32_t i,
                             const char* key, uint32_t key_len)
{
	Avm2Context* ctx = js->ctx;
	if (obj->kind == AVM2_OBJ_ARRAY)
	{
		Avm2Value v = avm2_array_get(obj, i);
		if (v.kind != AVM2_VALUE_HOLE) return v;
		return avm2_get_public_property(ctx, avm2_object_value(obj), key, key_len,
		                                NULL);
	}
	if (obj->kind == AVM2_OBJ_VECTOR)
	{
		Avm2VectorExt* ext = avm2_vector_ext(obj);
		if (i < ext->length) return ext->elems[i];
		return avm2_undefined();
	}
	return avm2_get_public_property(ctx, avm2_object_value(obj), key, key_len, NULL);
}

static void js_serialize_iterable(JSer* js, StrBuf* b, Avm2Object* obj)
{
	Avm2Context* ctx = js->ctx;
	Avm2Value lenv = avm2_get_public_property(ctx, avm2_object_value(obj),
	                                          "length", 6, NULL);
	uint32_t len = avm2_coerce_to_u32(ctx, lenv);
	sb_putc(b, '[');
	js->depth++;
	for (uint32_t i = 0; i < len; i++)
	{
		char kb[16];
		int kl = snprintf(kb, sizeof(kb), "%u", i);
		Avm2Value item = js_iter_get(js, obj, i, kb, (uint32_t) kl);
		Avm2Value mapped = js_map_value(js, kb, (uint32_t) kl, item);
		if (i > 0) sb_putc(b, ',');
		if (js->indent != NULL) js_newline_indent(js, b);
		js_serialize_value(js, b, mapped);
	}
	js->depth--;
	if (len > 0 && js->indent != NULL) js_newline_indent(js, b);
	sb_putc(b, ']');
}

static void js_obj_entry(JSer* js, StrBuf* b, int* first,
                         const char* key, uint32_t key_len, Avm2Value mapped)
{
	if (!*first) sb_putc(b, ',');
	if (js->indent != NULL) js_newline_indent(js, b);
	*first = 0;
	sb_json_string(b, key, key_len);
	sb_putc(b, ':');
	if (js->indent != NULL) sb_putc(b, ' ');
	js_serialize_value(js, b, mapped);
}

static void js_serialize_object(JSer* js, StrBuf* b, Avm2Object* obj)
{
	Avm2Context* ctx = js->ctx;
	sb_putc(b, '{');
	js->depth++;
	int first = 1;
	if (js->prop_list != NULL)
	{
		// PropList replacer: serialize exactly those properties.
		Avm2Value lenv = avm2_get_public_property(
			ctx, avm2_object_value(js->prop_list), "length", 6, NULL);
		uint32_t len = avm2_coerce_to_u32(ctx, lenv);
		for (uint32_t i = 0; i < len; i++)
		{
			char kb[16];
			int kl = snprintf(kb, sizeof(kb), "%u", i);
			Avm2Value item = js_iter_get(js, js->prop_list, i, kb, (uint32_t) kl);
			const Avm2String* key = avm2_coerce_to_string(ctx, item);
			Avm2Value value = avm2_get_public_property(
				ctx, avm2_object_value(obj), key->utf8, key->len, NULL);
			Avm2Value mapped = js_map_value(js, key->utf8, key->len, value);
			if (mapped.kind == AVM2_VALUE_UNDEFINED) continue;
			js_obj_entry(js, b, &first, key->utf8, key->len, mapped);
		}
	}
	else
	{
		// Declared public slots/const/getters in vtable order (Ruffle
		// public_vtable_properties), then dynamic props in insertion order.
		const Avm2VTable* vt = obj->vtable;
		for (uint32_t i = 0; vt != NULL && i < vt->count; i++)
		{
			const Avm2PropEntry* e = &vt->entries[i];
			if (!avm2_propkey_is_public(&e->key)) continue;
			Avm2Value value;
			if (e->kind == AVM2_PROP_SLOT)
			{
				value = obj->slots[e->slot_index];
			}
			else if (e->kind == AVM2_PROP_GETTER || e->kind == AVM2_PROP_GETSET)
			{
				value = avm2_call_method_ref(ctx, &e->method, e->defining_class,
				                             e->method_scope,
				                             avm2_object_value(obj), NULL, 0);
			}
			else
			{
				continue;
			}
			Avm2Value mapped = js_map_value(js, e->key.name, e->key.name_len, value);
			if (mapped.kind == AVM2_VALUE_UNDEFINED) continue;
			js_obj_entry(js, b, &first, e->key.name, e->key.name_len, mapped);
		}
		for (Avm2DynProp* p = obj->dyn_props; p != NULL; p = p->next)
		{
			if (p->dont_enum) continue;
			Avm2Value mapped = js_map_value(js, p->name.utf8, p->name.len, p->value);
			if (mapped.kind == AVM2_VALUE_UNDEFINED) continue;
			js_obj_entry(js, b, &first, p->name.utf8, p->name.len, mapped);
		}
	}
	js->depth--;
	if (!first && js->indent != NULL) js_newline_indent(js, b);
	sb_putc(b, '}');
}

static void js_serialize_value(JSer* js, StrBuf* b, Avm2Value v)
{
	Avm2Context* ctx = js->ctx;
	v = js_normalize(v);
	switch (v.kind)
	{
		case AVM2_VALUE_NULL:
		case AVM2_VALUE_UNDEFINED:
			sb_lit(b, "null");
			return;
		case AVM2_VALUE_BOOL:
			sb_lit(b, v.u.b ? "true" : "false");
			return;
		case AVM2_VALUE_INTEGER:
		{
			char nb[16];
			sb_put(b, nb, (uint32_t) snprintf(nb, sizeof(nb), "%d", v.u.i));
			return;
		}
		case AVM2_VALUE_NUMBER:
			if (isnan(v.u.d) || isinf(v.u.d))
			{
				sb_lit(b, "null");  // serde Number::from_f64 → None → null
				return;
			}
			sb_json_number(b, v.u.d);
			return;
		case AVM2_VALUE_STRING:
			sb_json_string(b, v.u.str->utf8, v.u.str->len);
			return;
		case AVM2_VALUE_OBJECT:
		{
			Avm2Object* obj = v.u.obj;
			for (uint32_t i = 0; i < js->stack_n; i++)
			{
				if (js->stack[i] == obj) throw_1129(ctx);
			}
			if (js->stack_n >= 256) throw_1129(ctx);
			js->stack[js->stack_n++] = obj;
			if (obj->kind == AVM2_OBJ_ARRAY || obj->kind == AVM2_OBJ_VECTOR)
			{
				js_serialize_iterable(js, b, obj);
			}
			else
			{
				js_serialize_object(js, b, obj);
			}
			js->stack_n--;
			return;
		}
		default:
			sb_lit(b, "null");
			return;
	}
}

static Avm2Value json_stringify(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value val = act->argc > 0 ? act->args[0] : avm2_undefined();
	// The AS3 signature defaults replacer/space to null; an explicit
	// undefined is NOT null and trips 1131 (json_errors).
	Avm2Value replacer = act->argc > 1 ? act->args[1] : avm2_null();
	Avm2Value spaces = act->argc > 2 ? act->args[2] : avm2_null();

	JSer js;
	memset(&js, 0, sizeof(js));
	js.ctx = ctx;
	js.act = act;
	js.replacer_fn = avm2_undefined();

	if (replacer.kind != AVM2_VALUE_NULL)
	{
		if (replacer.kind != AVM2_VALUE_OBJECT) throw_1131(ctx);
		if (replacer.u.obj->kind == AVM2_OBJ_FUNCTION)
		{
			js.replacer_fn = replacer;
		}
		else if (replacer.u.obj->kind == AVM2_OBJ_ARRAY)
		{
			js.prop_list = replacer.u.obj;
		}
		else
		{
			throw_1131(ctx);
		}
	}

	// Indent: only String / Number values count (no coercion).
	static char indent_buf[16];
	if (spaces.kind == AVM2_VALUE_STRING && spaces.u.str->len > 0)
	{
		uint32_t n = spaces.u.str->len > 10 ? 10 : spaces.u.str->len;
		memcpy(indent_buf, spaces.u.str->utf8, n);
		js.indent = indent_buf;
		js.indent_len = n;
	}
	else if (spaces.kind == AVM2_VALUE_INTEGER || spaces.kind == AVM2_VALUE_NUMBER)
	{
		double d = spaces.kind == AVM2_VALUE_INTEGER ? (double) spaces.u.i
		                                             : spaces.u.d;
		if (d != d) d = 0.0;
		if (d < 0.0) d = 0.0;
		if (d > 10.0) d = 10.0;
		uint32_t n = (uint32_t) d;
		if (n > 0)
		{
			memset(indent_buf, ' ', n);
			js.indent = indent_buf;
			js.indent_len = n;
		}
	}

	StrBuf b;
	memset(&b, 0, sizeof(b));
	b.ctx = ctx;
	Avm2Value mapped = js_map_value(&js, "", 0, val);
	js_serialize_value(&js, &b, mapped);
	return avm2_string(avm2_string_new(ctx, b.p != NULL ? b.p : "", b.n));
}

// ---------------------------------------------------------------------------
// Registration (avm2_globals.c gates on SWF version)
// ---------------------------------------------------------------------------

void avm2_register_json(Avm2Context* ctx)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "", "JSON", ctx->builtins.object_class);
	cls->flags |= AVM2_CLASS_FLAG_SEALED | AVM2_CLASS_FLAG_FINAL;
	avm2_builtin_add_static_method(ctx, cls, "parse", json_parse);
	avm2_builtin_add_static_method(ctx, cls, "stringify", json_stringify);
}
