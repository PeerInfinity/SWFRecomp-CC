// flash.text engine (Stage 6): TextFormat, the TextField/EditText state
// model (FormatSpans), the HTML span parser, and the property surface.
// Ported from Ruffle core/src/html/text_format.rs +
// core/src/avm2/globals/flash/text/{text_format,text_field}.rs +
// core/src/display_object/edit_text.rs. Layout (measurement) lives in the
// Stage-6 tranche-2 half of this file.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <avm2/avm2_value.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_ops.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_abc.h>
#include <avm2/avm2_main.h>

// ===========================================================================
// Small helpers
// ===========================================================================

static Avm2Class* g_textformat_class;
static Avm2Class* g_textfield_class2;

static void throw_2006(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.range_error_class,
	                 "Error #2006: The supplied index is out of bounds.");
}

static void throw_2007(Avm2Context* ctx, const char* param)
{
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #2007: Parameter %s must be non-null.", param);
}

static void throw_2008(Avm2Context* ctx, const char* param)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2008: Parameter %s must be one of the accepted "
	                 "values.", param);
}

static Avm2Object* this_obj(Avm2Activation* act)
{
	return act->this_val.kind == AVM2_VALUE_OBJECT ? act->this_val.u.obj : NULL;
}

static Avm2Value arg_or_undef(Avm2Activation* act, uint32_t i)
{
	return i < act->argc ? act->args[i] : avm2_undefined();
}

// ecma_conversions::round_to_even — round-half-even, i32::MIN for
// NaN/inf/out-of-range.
static int32_t round_to_even_i32(double n)
{
	double out = nearbyint(n);  // default FE_TONEAREST = ties-to-even
	if (isfinite(out) && out <= 2147483647.0 && out >= -2147483648.0)
	{
		return (int32_t) out;
	}
	return INT32_MIN;
}

// UTF-16 view helpers over UTF-8 storage (mirrors avm2_string.c).
static uint32_t u16_length(const Avm2String* s)
{
	uint32_t n = 0;
	for (uint32_t i = 0; i < s->len; )
	{
		unsigned char c = (unsigned char) s->utf8[i];
		if (c < 0x80) { i += 1; n += 1; }
		else if (c < 0xE0) { i += 2; n += 1; }
		else if (c < 0xF0) { i += 3; n += 1; }
		else { i += 4; n += 2; }
	}
	return n;
}

static uint32_t u16_to_byte(const Avm2String* s, uint32_t u16idx)
{
	uint32_t n = 0;
	uint32_t i = 0;
	while (i < s->len && n < u16idx)
	{
		unsigned char c = (unsigned char) s->utf8[i];
		if (c < 0x80) { i += 1; n += 1; }
		else if (c < 0xE0) { i += 2; n += 1; }
		else if (c < 0xF0) { i += 3; n += 1; }
		else { i += 4; n += 2; }
	}
	return i;
}

static const Avm2String* empty_string(Avm2Context* ctx)
{
	return avm2_string_new(ctx, "", 0);
}

// Dynamic UTF-8 string builder.
typedef struct SB
{
	char* buf;
	uint32_t len, cap;
} SB;

static void sb_init(SB* sb) { sb->buf = NULL; sb->len = sb->cap = 0; }
static void sb_reserve(Avm2Context* ctx, SB* sb, uint32_t extra)
{
	if (sb->len + extra <= sb->cap) return;
	uint32_t ncap = sb->cap ? sb->cap * 2 : 64;
	while (ncap < sb->len + extra) ncap *= 2;
	char* nb = avm2_alloc(ctx, ncap);
	if (sb->len > 0) memcpy(nb, sb->buf, sb->len);
	sb->buf = nb;
	sb->cap = ncap;
}
static void sb_bytes(Avm2Context* ctx, SB* sb, const char* p, uint32_t n)
{
	sb_reserve(ctx, sb, n);
	memcpy(sb->buf + sb->len, p, n);
	sb->len += n;
}
static void sb_ch(Avm2Context* ctx, SB* sb, char c) { sb_bytes(ctx, sb, &c, 1); }
static void sb_cp(Avm2Context* ctx, SB* sb, uint32_t cp)
{
	char tmp[4];
	uint32_t n;
	if (cp < 0x80) { tmp[0] = (char) cp; n = 1; }
	else if (cp < 0x800)
	{
		tmp[0] = (char) (0xC0 | (cp >> 6));
		tmp[1] = (char) (0x80 | (cp & 0x3F));
		n = 2;
	}
	else if (cp < 0x10000)
	{
		tmp[0] = (char) (0xE0 | (cp >> 12));
		tmp[1] = (char) (0x80 | ((cp >> 6) & 0x3F));
		tmp[2] = (char) (0x80 | (cp & 0x3F));
		n = 3;
	}
	else
	{
		tmp[0] = (char) (0xF0 | (cp >> 18));
		tmp[1] = (char) (0x80 | ((cp >> 12) & 0x3F));
		tmp[2] = (char) (0x80 | ((cp >> 6) & 0x3F));
		tmp[3] = (char) (0x80 | (cp & 0x3F));
		n = 4;
	}
	sb_bytes(ctx, sb, tmp, n);
}
static const Avm2String* sb_str(Avm2Context* ctx, SB* sb)
{
	return avm2_string_new(ctx, sb->buf != NULL ? sb->buf : "", sb->len);
}

// ===========================================================================
// TextFormat field storage
// ===========================================================================

enum
{
	TFP_FONT = 1 << 0,
	TFP_SIZE = 1 << 1,
	TFP_COLOR = 1 << 2,
	TFP_ALIGN = 1 << 3,
	TFP_BOLD = 1 << 4,
	TFP_ITALIC = 1 << 5,
	TFP_UNDERLINE = 1 << 6,
	TFP_LEFT_MARGIN = 1 << 7,
	TFP_RIGHT_MARGIN = 1 << 8,
	TFP_INDENT = 1 << 9,
	TFP_BLOCK_INDENT = 1 << 10,
	TFP_KERNING = 1 << 11,
	TFP_LEADING = 1 << 12,
	TFP_LETTER_SPACING = 1 << 13,
	TFP_TAB_STOPS = 1 << 14,
	TFP_BULLET = 1 << 15,
	TFP_URL = 1 << 16,
	TFP_TARGET = 1 << 17,
	TFP_DISPLAY = 1 << 18,
	TFP_ALL = (1 << 19) - 1,
};

// swf::TextAlign order (SWF tag encoding): 0 left, 1 right, 2 center,
// 3 justify.
enum { ALIGN_LEFT = 0, ALIGN_RIGHT = 1, ALIGN_CENTER = 2, ALIGN_JUSTIFY = 3 };
// TextDisplay
enum { DISPLAY_BLOCK = 0, DISPLAY_INLINE = 1, DISPLAY_NONE = 2 };

// Fields are meaningful only when the matching TFP_ bit is set in
// `present`. Spans always carry a fully-present format.
struct Avm2TextFormatFields
{
	uint32_t present;
	const Avm2String* font;
	double size;
	uint32_t color;   // 0xRRGGBBAA
	uint8_t align;
	uint8_t bold, italic, underline, kerning, bullet;
	double left_margin, right_margin, indent, block_indent, leading,
	       letter_spacing;
	double* tab_stops;
	uint32_t tab_stop_count;
	const Avm2String* url;
	const Avm2String* target;
	uint8_t display;
};
typedef struct Avm2TextFormatFields Avm2TextFormatFields;

// TextSpan::default: concrete values for a span with no explicit format.
static Avm2TextFormatFields span_default(Avm2Context* ctx)
{
	Avm2TextFormatFields f;
	memset(&f, 0, sizeof(f));
	f.present = TFP_ALL;
	f.font = empty_string(ctx);
	f.size = 12.0;
	f.color = 0;  // transparent black
	f.align = ALIGN_LEFT;
	f.url = empty_string(ctx);
	f.target = empty_string(ctx);
	f.display = DISPLAY_BLOCK;
	return f;
}

// TextFormat::default(): everything absent except display=block.
static Avm2TextFormatFields format_default(void)
{
	Avm2TextFormatFields f;
	memset(&f, 0, sizeof(f));
	f.present = TFP_DISPLAY;
	f.display = DISPLAY_BLOCK;
	return f;
}

// Apply src's present fields onto dst (TextSpan::set_text_format).
static void fields_apply(Avm2TextFormatFields* dst, const Avm2TextFormatFields* src)
{
	uint32_t p = src->present;
	if (p & TFP_FONT) dst->font = src->font;
	if (p & TFP_SIZE) dst->size = src->size;
	if (p & TFP_COLOR) dst->color = src->color;
	if (p & TFP_ALIGN) dst->align = src->align;
	if (p & TFP_BOLD) dst->bold = src->bold;
	if (p & TFP_ITALIC) dst->italic = src->italic;
	if (p & TFP_UNDERLINE) dst->underline = src->underline;
	if (p & TFP_LEFT_MARGIN) dst->left_margin = src->left_margin;
	if (p & TFP_RIGHT_MARGIN) dst->right_margin = src->right_margin;
	if (p & TFP_INDENT) dst->indent = src->indent;
	if (p & TFP_BLOCK_INDENT) dst->block_indent = src->block_indent;
	if (p & TFP_KERNING) dst->kerning = src->kerning;
	if (p & TFP_LEADING) dst->leading = src->leading;
	if (p & TFP_LETTER_SPACING) dst->letter_spacing = src->letter_spacing;
	if (p & TFP_TAB_STOPS)
	{
		dst->tab_stops = src->tab_stops;
		dst->tab_stop_count = src->tab_stop_count;
	}
	if (p & TFP_BULLET) dst->bullet = src->bullet;
	if (p & TFP_URL) dst->url = src->url;
	if (p & TFP_TARGET) dst->target = src->target;
	if (p & TFP_DISPLAY) dst->display = src->display;
	dst->present |= p;
}

static int str_eq(const Avm2String* a, const Avm2String* b)
{
	if (a == b) return 1;
	if (a == NULL || b == NULL) return 0;
	return a->len == b->len && memcmp(a->utf8, b->utf8, a->len) == 0;
}

static int tab_stops_eq(const Avm2TextFormatFields* a, const Avm2TextFormatFields* b)
{
	if (a->tab_stop_count != b->tab_stop_count) return 0;
	for (uint32_t i = 0; i < a->tab_stop_count; i++)
	{
		if (a->tab_stops[i] != b->tab_stops[i]) return 0;
	}
	return 1;
}

// TextFormat::merge_matching_properties — keep matching present fields,
// drop the rest.
static void fields_merge_matching(Avm2TextFormatFields* a, const Avm2TextFormatFields* b)
{
	uint32_t keep = 0;
	uint32_t both;
#define BOTH(bit) (((a->present & (bit)) != 0) && ((b->present & (bit)) != 0))
	both = 0; (void) both;
	if (BOTH(TFP_FONT) && str_eq(a->font, b->font)) keep |= TFP_FONT;
	if (BOTH(TFP_SIZE) && a->size == b->size) keep |= TFP_SIZE;
	if (BOTH(TFP_COLOR) && a->color == b->color) keep |= TFP_COLOR;
	if (BOTH(TFP_ALIGN) && a->align == b->align) keep |= TFP_ALIGN;
	if (BOTH(TFP_BOLD) && a->bold == b->bold) keep |= TFP_BOLD;
	if (BOTH(TFP_ITALIC) && a->italic == b->italic) keep |= TFP_ITALIC;
	if (BOTH(TFP_UNDERLINE) && a->underline == b->underline) keep |= TFP_UNDERLINE;
	if (BOTH(TFP_LEFT_MARGIN) && a->left_margin == b->left_margin) keep |= TFP_LEFT_MARGIN;
	if (BOTH(TFP_RIGHT_MARGIN) && a->right_margin == b->right_margin) keep |= TFP_RIGHT_MARGIN;
	if (BOTH(TFP_INDENT) && a->indent == b->indent) keep |= TFP_INDENT;
	if (BOTH(TFP_BLOCK_INDENT) && a->block_indent == b->block_indent) keep |= TFP_BLOCK_INDENT;
	if (BOTH(TFP_KERNING) && a->kerning == b->kerning) keep |= TFP_KERNING;
	if (BOTH(TFP_LEADING) && a->leading == b->leading) keep |= TFP_LEADING;
	if (BOTH(TFP_LETTER_SPACING) && a->letter_spacing == b->letter_spacing) keep |= TFP_LETTER_SPACING;
	if (BOTH(TFP_TAB_STOPS) && tab_stops_eq(a, b)) keep |= TFP_TAB_STOPS;
	if (BOTH(TFP_BULLET) && a->bullet == b->bullet) keep |= TFP_BULLET;
	if (BOTH(TFP_URL) && str_eq(a->url, b->url)) keep |= TFP_URL;
	if (BOTH(TFP_TARGET) && str_eq(a->target, b->target)) keep |= TFP_TARGET;
	if (BOTH(TFP_DISPLAY) && a->display == b->display) keep |= TFP_DISPLAY;
#undef BOTH
	a->present = keep;
}

static int fields_equal(const Avm2TextFormatFields* a, const Avm2TextFormatFields* b)
{
	if (a->present != b->present) return 0;
	Avm2TextFormatFields tmp = *a;
	fields_merge_matching(&tmp, b);
	return tmp.present == a->present;
}

// TextFormat::mix_with — self's present fields win (font wins only when
// non-empty), rhs fills the gaps.
static void fields_mix_with(Avm2TextFormatFields* self, const Avm2TextFormatFields* rhs)
{
	Avm2TextFormatFields out = *rhs;
	Avm2TextFormatFields top = *self;
	if ((top.present & TFP_FONT) && top.font != NULL && top.font->len == 0)
	{
		top.present &= ~(uint32_t) TFP_FONT;
	}
	fields_apply(&out, &top);
	*self = out;
}

// ===========================================================================
// TextFormat class (native state = Avm2TextFormatFields)
// ===========================================================================

static Avm2TextFormatFields* tf_fields_of(Avm2Object* obj)
{
	if (obj == NULL || obj->native_ext == NULL) return NULL;
	if (obj->cls == NULL || g_textformat_class == NULL) return NULL;
	for (Avm2Class* c = obj->cls; c != NULL; c = c->super_class)
	{
		if (c == g_textformat_class) return (Avm2TextFormatFields*) obj->native_ext;
	}
	return NULL;
}

static Avm2TextFormatFields* this_tf(Avm2Activation* act)
{
	return tf_fields_of(this_obj(act));
}

// Make a new TextFormat object from fields.
static Avm2Object* textformat_object_from_fields(Avm2Context* ctx,
                                                 const Avm2TextFormatFields* f)
{
	Avm2Value v = avm2_class_construct(ctx, g_textformat_class, NULL, 0);
	Avm2Object* obj = v.u.obj;
	*(Avm2TextFormatFields*) obj->native_ext = *f;
	return obj;
}

// --- getters ---

static Avm2Value tfmt_get_string(Avm2Activation* act, uint32_t bit,
                                 const Avm2String* val)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	if ((f->present & bit) == 0) return avm2_null();
	return avm2_string(val);
}

static Avm2Value tfmt_get_font(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_string(act, TFP_FONT, f->font) : avm2_undefined(); }
static Avm2Value tfmt_get_url(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_string(act, TFP_URL, f->url) : avm2_undefined(); }
static Avm2Value tfmt_get_target(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_string(act, TFP_TARGET, f->target) : avm2_undefined(); }

static Avm2Value tfmt_get_align(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	if ((f->present & TFP_ALIGN) == 0) return avm2_null();
	const char* s = f->align == ALIGN_LEFT ? "left"
	              : f->align == ALIGN_RIGHT ? "right"
	              : f->align == ALIGN_CENTER ? "center" : "justify";
	return avm2_string(avm2_string_from_literal(act->ctx, s));
}

static Avm2Value tfmt_get_display(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	if ((f->present & TFP_DISPLAY) == 0) return avm2_null();
	const char* s = f->display == DISPLAY_BLOCK ? "block"
	              : f->display == DISPLAY_INLINE ? "inline" : "none";
	return avm2_string(avm2_string_from_literal(act->ctx, s));
}

static Avm2Value tfmt_get_number(Avm2Activation* act, uint32_t bit, double val)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	if ((f->present & bit) == 0) return avm2_null();
	return avm2_number(val);
}

static Avm2Value tfmt_get_size(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_number(act, TFP_SIZE, f->size) : avm2_undefined(); }
static Avm2Value tfmt_get_left_margin(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_number(act, TFP_LEFT_MARGIN, f->left_margin) : avm2_undefined(); }
static Avm2Value tfmt_get_right_margin(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_number(act, TFP_RIGHT_MARGIN, f->right_margin) : avm2_undefined(); }
static Avm2Value tfmt_get_indent(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_number(act, TFP_INDENT, f->indent) : avm2_undefined(); }
static Avm2Value tfmt_get_block_indent(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_number(act, TFP_BLOCK_INDENT, f->block_indent) : avm2_undefined(); }
static Avm2Value tfmt_get_leading(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_number(act, TFP_LEADING, f->leading) : avm2_undefined(); }
static Avm2Value tfmt_get_letter_spacing(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_number(act, TFP_LETTER_SPACING, f->letter_spacing) : avm2_undefined(); }

static Avm2Value tfmt_get_color(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	if ((f->present & TFP_COLOR) == 0) return avm2_null();
	// to_rgba() as i32: 0xAARRGGBB signed.
	uint32_t rgba = f->color;
	uint32_t argb = ((rgba & 0xFF) << 24) | (rgba >> 8);
	return avm2_number((double) (int32_t) argb);
}

static Avm2Value tfmt_get_bool(Avm2Activation* act, uint32_t bit, uint8_t val)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	if ((f->present & bit) == 0) return avm2_null();
	return avm2_bool(val != 0);
}

static Avm2Value tfmt_get_bold(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_bool(act, TFP_BOLD, f->bold) : avm2_undefined(); }
static Avm2Value tfmt_get_italic(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_bool(act, TFP_ITALIC, f->italic) : avm2_undefined(); }
static Avm2Value tfmt_get_underline(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_bool(act, TFP_UNDERLINE, f->underline) : avm2_undefined(); }
static Avm2Value tfmt_get_kerning(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_bool(act, TFP_KERNING, f->kerning) : avm2_undefined(); }
static Avm2Value tfmt_get_bullet(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_get_bool(act, TFP_BULLET, f->bullet) : avm2_undefined(); }

static Avm2Value tfmt_get_tab_stops(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	if ((f->present & TFP_TAB_STOPS) == 0) return avm2_null();
	Avm2Object* arr = avm2_array_new(act->ctx, f->tab_stop_count);
	for (uint32_t i = 0; i < f->tab_stop_count; i++)
	{
		avm2_array_set(act->ctx, arr, i, avm2_number(f->tab_stops[i]));
	}
	return avm2_object_value(arr);
}

// --- setters ---

// String-typed AS3 param: null/undefined -> null, else coerce (an object's
// toString result of null stays null through the String coercion).
static const Avm2String* coerce_string_param(Avm2Context* ctx, Avm2Value v)
{
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED) return NULL;
	return avm2_coerce_to_string(ctx, v);
}

static Avm2Value tfmt_set_font(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	const Avm2String* s = coerce_string_param(act->ctx, arg_or_undef(act, 0));
	if (s == NULL)
	{
		f->present &= ~(uint32_t) TFP_FONT;
	}
	else
	{
		// Truncated to 64 UTF-16 units (textformat_font_max_length).
		if (u16_length(s) > 64)
		{
			uint32_t nbytes = u16_to_byte(s, 64);
			s = avm2_string_new(act->ctx, s->utf8, nbytes);
		}
		f->font = s;
		f->present |= TFP_FONT;
	}
	return avm2_undefined();
}

static Avm2Value tfmt_set_url(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	const Avm2String* s = coerce_string_param(act->ctx, arg_or_undef(act, 0));
	if (s == NULL) f->present &= ~(uint32_t) TFP_URL;
	else { f->url = s; f->present |= TFP_URL; }
	return avm2_undefined();
}

static Avm2Value tfmt_set_target(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	const Avm2String* s = coerce_string_param(act->ctx, arg_or_undef(act, 0));
	if (s == NULL) f->present &= ~(uint32_t) TFP_TARGET;
	else { f->target = s; f->present |= TFP_TARGET; }
	return avm2_undefined();
}

static Avm2Value tfmt_set_align(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	const Avm2String* s = coerce_string_param(act->ctx, arg_or_undef(act, 0));
	if (s == NULL)
	{
		f->present &= ~(uint32_t) TFP_ALIGN;
		return avm2_undefined();
	}
	if (s->len == 4 && memcmp(s->utf8, "left", 4) == 0) f->align = ALIGN_LEFT;
	else if (s->len == 6 && memcmp(s->utf8, "center", 6) == 0) f->align = ALIGN_CENTER;
	else if (s->len == 5 && memcmp(s->utf8, "right", 5) == 0) f->align = ALIGN_RIGHT;
	else if (s->len == 7 && memcmp(s->utf8, "justify", 7) == 0) f->align = ALIGN_JUSTIFY;
	else throw_2008(act->ctx, "align");
	f->present |= TFP_ALIGN;
	return avm2_undefined();
}

static Avm2Value tfmt_set_display(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "display");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	if (s->len == 5 && memcmp(s->utf8, "block", 5) == 0)
	{ f->display = DISPLAY_BLOCK; f->present |= TFP_DISPLAY; }
	else if (s->len == 6 && memcmp(s->utf8, "inline", 6) == 0)
	{ f->display = DISPLAY_INLINE; f->present |= TFP_DISPLAY; }
	else if (s->len == 4 && memcmp(s->utf8, "none", 4) == 0)
	{ f->display = DISPLAY_NONE; f->present |= TFP_DISPLAY; }
	else
	{
		// Invalid values silently clear (Ruffle set_display).
		f->present &= ~(uint32_t) TFP_DISPLAY;
	}
	return avm2_undefined();
}

// Object-typed numeric prop: null/undefined -> absent, else
// round_to_even(coerce_to_number).
static Avm2Value tfmt_set_rounded(Avm2Activation* act, uint32_t bit, double* slot)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		f->present &= ~bit;
		return avm2_undefined();
	}
	*slot = (double) round_to_even_i32(avm2_coerce_to_number(act->ctx, v));
	f->present |= bit;
	return avm2_undefined();
}

static Avm2Value tfmt_set_size(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_rounded(act, TFP_SIZE, &f->size) : avm2_undefined(); }
static Avm2Value tfmt_set_left_margin(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_rounded(act, TFP_LEFT_MARGIN, &f->left_margin) : avm2_undefined(); }
static Avm2Value tfmt_set_right_margin(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_rounded(act, TFP_RIGHT_MARGIN, &f->right_margin) : avm2_undefined(); }
static Avm2Value tfmt_set_indent(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_rounded(act, TFP_INDENT, &f->indent) : avm2_undefined(); }
static Avm2Value tfmt_set_block_indent(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_rounded(act, TFP_BLOCK_INDENT, &f->block_indent) : avm2_undefined(); }
static Avm2Value tfmt_set_leading(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_rounded(act, TFP_LEADING, &f->leading) : avm2_undefined(); }

static Avm2Value tfmt_set_letter_spacing(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		f->present &= ~(uint32_t) TFP_LETTER_SPACING;
		return avm2_undefined();
	}
	f->letter_spacing = avm2_coerce_to_number(act->ctx, v);  // no rounding
	f->present |= TFP_LETTER_SPACING;
	return avm2_undefined();
}

static Avm2Value tfmt_set_color(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		f->present &= ~(uint32_t) TFP_COLOR;
		return avm2_undefined();
	}
	uint32_t argb = avm2_coerce_to_u32(act->ctx, v);
	// from_rgba(u32): stored as rgba with the incoming alpha byte.
	f->color = (argb << 8) | (argb >> 24);
	f->present |= TFP_COLOR;
	return avm2_undefined();
}

static Avm2Value tfmt_set_bool(Avm2Activation* act, uint32_t bit, uint8_t* slot)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		f->present &= ~bit;
		return avm2_undefined();
	}
	*slot = avm2_coerce_to_boolean(v) ? 1 : 0;
	f->present |= bit;
	return avm2_undefined();
}

static Avm2Value tfmt_set_bold(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_bool(act, TFP_BOLD, &f->bold) : avm2_undefined(); }
static Avm2Value tfmt_set_italic(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_bool(act, TFP_ITALIC, &f->italic) : avm2_undefined(); }
static Avm2Value tfmt_set_underline(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_bool(act, TFP_UNDERLINE, &f->underline) : avm2_undefined(); }
static Avm2Value tfmt_set_kerning(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_bool(act, TFP_KERNING, &f->kerning) : avm2_undefined(); }
static Avm2Value tfmt_set_bullet(Avm2Activation* act)
{ Avm2TextFormatFields* f = this_tf(act); return f ? tfmt_set_bool(act, TFP_BULLET, &f->bullet) : avm2_undefined(); }

static Avm2Value tfmt_set_tab_stops(Avm2Activation* act)
{
	Avm2TextFormatFields* f = this_tf(act);
	if (f == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	Avm2ArrayExt* ax = (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL)
		? avm2_array_ext(v.u.obj) : NULL;
	if (ax == NULL)
	{
		f->present &= ~(uint32_t) TFP_TAB_STOPS;
		return avm2_undefined();
	}
	uint32_t n = ax->length;
	double* stops = n > 0 ? avm2_alloc(act->ctx, n * sizeof(double)) : NULL;
	for (uint32_t i = 0; i < n; i++)
	{
		Avm2Value e = avm2_array_get(v.u.obj, i);
		if (e.kind == AVM2_VALUE_UNDEFINED || e.kind == AVM2_VALUE_HOLE)
		{
			e = avm2_number(0.0);
		}
		stops[i] = (double) round_to_even_i32(avm2_coerce_to_number(act->ctx, e));
	}
	f->tab_stops = stops;
	f->tab_stop_count = n;
	f->present |= TFP_TAB_STOPS;
	return avm2_undefined();
}

// TextFormat(font, size, color, bold, italic, underline, url, target,
// align, leftMargin, rightMargin, indent, leading): each non-null arg goes
// through the corresponding setter.
static Avm2Value tfmt_ctor(Avm2Activation* act)
{
	static Avm2Value (*setters[13])(Avm2Activation*) = {
		tfmt_set_font, tfmt_set_size, tfmt_set_color, tfmt_set_bold,
		tfmt_set_italic, tfmt_set_underline, tfmt_set_url, tfmt_set_target,
		tfmt_set_align, tfmt_set_left_margin, tfmt_set_right_margin,
		tfmt_set_indent, tfmt_set_leading,
	};
	for (uint32_t i = 0; i < act->argc && i < 13; i++)
	{
		Avm2Value v = act->args[i];
		if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED) continue;
		Avm2Activation sub = *act;
		sub.args = &act->args[i];
		sub.argc = 1;
		setters[i](&sub);
	}
	return avm2_undefined();
}

static void textformat_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	(void) ctx;
	Avm2TextFormatFields* f = (Avm2TextFormatFields*) obj->native_ext;
	// TextFormat::default(): everything absent except display=block.
	*f = format_default();
}

// ===========================================================================
// EditText state (FormatSpans port)
// ===========================================================================

typedef struct Avm2TextSpan
{
	uint32_t length;  // UTF-16 units
	Avm2TextFormatFields fmt;  // fully present
} Avm2TextSpan;

struct Avm2EditTextExt
{
	const Avm2String* text;
	Avm2TextFormatFields default_format;  // fully present
	Avm2TextSpan* spans;
	uint32_t span_count, span_cap;
	const Avm2String* original_html;  // cache for html_text getter
	Avm2Object* style_sheet;

	uint8_t is_html, condense_white, word_wrap, multiline, password,
	        read_only, no_select, border, background, was_static, device_font,
	        always_show_selection, mouse_wheel_enabled, from_tag;
	uint8_t autosize;      // 0 none 1 left 2 center 3 right
	uint8_t aa_advanced;   // antiAliasType: 1 = advanced (default)
	uint8_t grid_fit;      // 0 none 1 pixel (default) 2 subpixel
	double thickness, sharpness;
	uint32_t border_color, background_color;  // 0xRRGGBB
	int32_t max_chars;
	const Avm2String* restrict_str;
	uint8_t has_restrict;
	double hscroll;        // scrollH in px
	int32_t scroll;        // scrollV (1-based line)
	int32_t sel_begin, sel_end;
	// EditText-owned bounds (twips). Distinct from the display matrix.
	int32_t bounds_x, bounds_y, bounds_w, bounds_h;
	uint16_t font_id;
};
typedef struct Avm2EditTextExt Avm2EditTextExt;

static Avm2EditTextExt* edittext_of(Avm2Context* ctx, Avm2Object* obj)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	return ext != NULL ? ext->edittext : NULL;
}

static Avm2EditTextExt* this_et(Avm2Activation* act)
{
	return edittext_of(act->ctx, this_obj(act));
}

static void spans_reserve(Avm2Context* ctx, Avm2EditTextExt* et, uint32_t extra)
{
	if (et->span_count + extra <= et->span_cap) return;
	uint32_t ncap = et->span_cap ? et->span_cap * 2 : 8;
	while (ncap < et->span_count + extra) ncap *= 2;
	Avm2TextSpan* ns = avm2_alloc(ctx, ncap * sizeof(Avm2TextSpan));
	if (et->span_count > 0) memcpy(ns, et->spans, et->span_count * sizeof(Avm2TextSpan));
	et->spans = ns;
	et->span_cap = ncap;
}

static void spans_push(Avm2Context* ctx, Avm2EditTextExt* et, uint32_t length,
                       const Avm2TextFormatFields* tf)
{
	spans_reserve(ctx, et, 1);
	Avm2TextSpan* s = &et->spans[et->span_count++];
	s->length = length;
	// TextSpan::with_length_and_format: defaults + tf, display forced BLOCK.
	s->fmt = span_default(ctx);
	fields_apply(&s->fmt, tf);
	s->fmt.display = DISPLAY_BLOCK;
}

static void spans_insert(Avm2Context* ctx, Avm2EditTextExt* et, uint32_t at,
                         uint32_t length, const Avm2TextFormatFields* concrete)
{
	spans_reserve(ctx, et, 1);
	memmove(&et->spans[at + 1], &et->spans[at],
	        (et->span_count - at) * sizeof(Avm2TextSpan));
	et->spans[at].length = length;
	et->spans[at].fmt = *concrete;
	et->span_count++;
}

static void spans_remove_range(Avm2EditTextExt* et, uint32_t from, uint32_t to)
{
	if (to <= from) return;
	memmove(&et->spans[from], &et->spans[to],
	        (et->span_count - to) * sizeof(Avm2TextSpan));
	et->span_count -= (to - from);
}

// FormatSpans::normalize.
static void spans_normalize(Avm2Context* ctx, Avm2EditTextExt* et)
{
	uint32_t text_len = u16_length(et->text);
	uint64_t span_len = 0;
	for (uint32_t i = 0; i < et->span_count; i++) span_len += et->spans[i].length;
	if (span_len < text_len)
	{
		spans_push(ctx, et, (uint32_t) (text_len - span_len), &et->default_format);
	}
	else if (span_len > text_len)
	{
		uint64_t deficiency = span_len - text_len;
		while (deficiency > 0 && et->span_count > 0)
		{
			Avm2TextSpan* last = &et->spans[et->span_count - 1];
			if (last->length > deficiency)
			{
				last->length -= (uint32_t) deficiency;
				break;
			}
			deficiency -= last->length;
			et->span_count--;
		}
	}
	// Remove leading null-length spans.
	while (et->span_count > 0 && et->spans[0].length == 0)
	{
		spans_remove_range(et, 0, 1);
	}
	// Merge adjacent spans with equal formats; drop null-length spans.
	uint32_t i = 0;
	while (et->span_count > 1 && i < et->span_count - 1)
	{
		Avm2TextSpan* a = &et->spans[i];
		Avm2TextSpan* b = &et->spans[i + 1];
		if (b->length == 0)
		{
			spans_remove_range(et, i + 1, i + 2);
		}
		else if (fields_equal(&a->fmt, &b->fmt))
		{
			a->length += b->length;
			spans_remove_range(et, i + 1, i + 2);
		}
		else
		{
			i++;
		}
	}
	// An empty span list gets one default span.
	if (et->span_count == 0)
	{
		spans_push(ctx, et, text_len, &et->default_format);
	}
}

// Returns [start_pos, end_pos) span indices covering [from, to).
static void span_boundaries(const Avm2EditTextExt* et, uint32_t from, uint32_t to,
                            uint32_t* start_pos, uint32_t* end_pos)
{
	uint32_t acc = 0;
	uint32_t sp = et->span_count, ep = et->span_count;
	for (uint32_t i = 0; i < et->span_count; i++)
	{
		uint32_t s = acc, e = acc + et->spans[i].length;
		if (sp == et->span_count && e > from) sp = i;
		if (s >= to) { ep = i; break; }
		acc = e;
	}
	if (sp > ep) sp = ep;
	*start_pos = sp;
	*end_pos = ep;
}

// FormatSpans::ensure_span_break_at.
static void span_break_at(Avm2Context* ctx, Avm2EditTextExt* et, uint32_t pos)
{
	uint32_t acc = 0;
	for (uint32_t i = 0; i < et->span_count; i++)
	{
		uint32_t s = acc, e = acc + et->spans[i].length;
		if (pos > s && pos < e)
		{
			uint32_t first = pos - s;
			Avm2TextFormatFields fmt = et->spans[i].fmt;
			et->spans[i].length = first;
			spans_insert(ctx, et, i + 1, e - pos, &fmt);
			return;
		}
		acc = e;
	}
}

// FormatSpans::get_text_format(from, to) — nullable intersection.
static Avm2TextFormatFields spans_get_format(const Avm2EditTextExt* et,
                                             uint32_t from, uint32_t to)
{
	if (from == to) return format_default();
	uint32_t sp, ep;
	span_boundaries(et, from, to, &sp, &ep);
	if (sp >= et->span_count) return format_default();
	Avm2TextFormatFields merged = et->spans[sp].fmt;
	for (uint32_t i = sp + 1; i < ep && i < et->span_count; i++)
	{
		fields_merge_matching(&merged, &et->spans[i].fmt);
	}
	return merged;
}

// FormatSpans::set_text_format(from, to, fmt).
static void spans_set_format(Avm2Context* ctx, Avm2EditTextExt* et,
                             uint32_t from, uint32_t to,
                             const Avm2TextFormatFields* fmt)
{
	span_break_at(ctx, et, from);
	span_break_at(ctx, et, to);
	uint32_t sp, ep;
	span_boundaries(et, from, to, &sp, &ep);
	for (uint32_t i = sp; i < ep && i < et->span_count; i++)
	{
		fields_apply(&et->spans[i].fmt, fmt);
	}
	spans_normalize(ctx, et);
}

// FormatSpans::from_text.
static void spans_from_text(Avm2Context* ctx, Avm2EditTextExt* et,
                            const Avm2String* text)
{
	et->text = text;
	et->span_count = 0;
	et->original_html = NULL;
	spans_push(ctx, et, u16_length(text), &et->default_format);
}

// FormatSpans::set_default_format — mix onto the existing default.
static void spans_set_default_format(Avm2Context* ctx, Avm2EditTextExt* et,
                                     const Avm2TextFormatFields* tf)
{
	Avm2TextFormatFields mixed = *tf;
	fields_mix_with(&mixed, &et->default_format);
	et->default_format = mixed;
	if (et->text == NULL || et->text->len == 0)
	{
		et->span_count = 0;
		spans_push(ctx, et, 0, &et->default_format);
	}
}

// FormatSpans::replace_text (from, to in UTF-16 units).
static void spans_replace_text(Avm2Context* ctx, Avm2EditTextExt* et,
                               uint32_t from, uint32_t to, const Avm2String* with)
{
	if (to < from) return;
	uint32_t text_len = u16_length(et->text);
	uint32_t with_len = u16_length(with);
	if (from < text_len)
	{
		span_break_at(ctx, et, from);
		span_break_at(ctx, et, to);
		uint32_t sp, ep;
		span_boundaries(et, from, to, &sp, &ep);
		Avm2TextFormatFields new_tf;
		if (ep < et->span_count)
		{
			new_tf = et->spans[ep].fmt;
		}
		else
		{
			// Fall back to the default format, resolved onto span defaults.
			new_tf = span_default(ctx);
			fields_apply(&new_tf, &et->default_format);
			new_tf.display = DISPLAY_BLOCK;
		}
		spans_remove_range(et, sp, ep);
		spans_insert(ctx, et, sp, with_len, &new_tf);
	}
	else
	{
		spans_push(ctx, et, with_len, &et->default_format);
	}

	// Splice the text: text[0..from] + with + text[to..].
	SB sb;
	sb_init(&sb);
	uint32_t from_b = u16_to_byte(et->text, from);
	uint32_t to_b = u16_to_byte(et->text, to);
	if (from >= text_len) from_b = et->text->len;
	if (to >= text_len) to_b = et->text->len;
	sb_bytes(ctx, &sb, et->text->utf8, from_b);
	sb_bytes(ctx, &sb, with->utf8, with->len);
	if (to_b < et->text->len)
	{
		sb_bytes(ctx, &sb, et->text->utf8 + to_b, et->text->len - to_b);
	}
	et->text = sb_str(ctx, &sb);
	et->original_html = NULL;
	spans_normalize(ctx, et);
}

// ===========================================================================
// HTML parser (FormatSpans::from_html port)
// ===========================================================================

// Decode &entities; in [p, p+n) into sb (process_html_entity).
static void html_decode_entities(Avm2Context* ctx, SB* sb, const char* p, uint32_t n)
{
	uint32_t i = 0;
	while (i < n)
	{
		if (p[i] != '&')
		{
			sb_ch(ctx, sb, p[i++]);
			continue;
		}
		// Find ';'
		uint32_t j = i + 1;
		while (j < n && p[j] != ';') j++;
		if (j >= n)
		{
			// No terminator: copy the rest verbatim.
			sb_bytes(ctx, sb, p + i, n - i);
			break;
		}
		const char* name = p + i + 1;
		uint32_t name_len = j - i - 1;
#define ENT_EQ(lit) (name_len == sizeof(lit) - 1 && strncasecmp(name, lit, name_len) == 0)
		if (ENT_EQ("amp")) sb_ch(ctx, sb, '&');
		else if (ENT_EQ("lt")) sb_ch(ctx, sb, '<');
		else if (ENT_EQ("gt")) sb_ch(ctx, sb, '>');
		else if (ENT_EQ("quot")) sb_ch(ctx, sb, '"');
		else if (ENT_EQ("apos")) sb_ch(ctx, sb, '\'');
		else if (ENT_EQ("nbsp")) sb_cp(ctx, sb, 0xA0);
		else if (name_len >= 2 && name[0] == '#')
		{
			const char* digits;
			uint32_t dl;
			int radix;
			if (name[1] == 'x' || name[1] == 'X')
			{
				// Only the trailing 4 hex digits are used.
				digits = name + 2;
				dl = name_len - 2;
				if (dl > 4) { digits += dl - 4; dl = 4; }
				radix = 16;
			}
			else
			{
				digits = name + 1;
				dl = name_len - 1;
				if (dl > 16) { digits += dl - 16; dl = 16; }
				radix = 10;
			}
			uint64_t val = 0;
			int ok = dl > 0;
			for (uint32_t k = 0; k < dl && ok; k++)
			{
				int d;
				char c = digits[k];
				if (c >= '0' && c <= '9') d = c - '0';
				else if (radix == 16 && c >= 'a' && c <= 'f') d = c - 'a' + 10;
				else if (radix == 16 && c >= 'A' && c <= 'F') d = c - 'A' + 10;
				else { ok = 0; break; }
				val = val * radix + d;
				if (val > 0x10FFFF) val = 0x110000;  // invalid marker
			}
			if (ok && val <= 0x10FFFF && !(val >= 0xD800 && val <= 0xDFFF))
			{
				sb_cp(ctx, sb, (uint32_t) val);
			}
			else if (!ok)
			{
				sb_bytes(ctx, sb, p + i, j - i + 1);
			}
			// A valid-syntax but out-of-range codepoint emits nothing.
		}
		else
		{
			// Invalid entity: verbatim.
			sb_bytes(ctx, sb, p + i, j - i + 1);
		}
#undef ENT_EQ
		i = j + 1;
	}
}

typedef struct HtmlAttr
{
	const char* name;
	uint32_t name_len;
	char* value;      // decoded, NUL-terminated
	uint32_t value_len;
} HtmlAttr;

static const HtmlAttr* attr_find(const HtmlAttr* attrs, uint32_t n, const char* name)
{
	uint32_t nl = (uint32_t) strlen(name);
	for (uint32_t i = 0; i < n; i++)
	{
		if (attrs[i].name_len == nl && strncasecmp(attrs[i].name, name, nl) == 0)
		{
			return &attrs[i];
		}
	}
	return NULL;
}

// Parse a leading double from s (like WStr::parse<f64> — full-string strict
// parse; Ruffle uses .parse().ok() which requires the WHOLE string).
static int parse_f64_strict(const char* s, uint32_t len, double* out)
{
	if (len == 0) return 0;
	char buf[64];
	if (len >= sizeof(buf)) return 0;
	memcpy(buf, s, len);
	buf[len] = '\0';
	char* end = NULL;
	double v = strtod(buf, &end);
	if (end != buf + len) return 0;
	*out = v;
	return 1;
}

// condense_white_in_text: any run of whitespace -> single space.
static int swf_is_ws(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
	       || c == '\v';
}

// from_html: parse html into et->text/spans. No stylesheet support yet.
static void spans_from_html(Avm2Context* ctx, Avm2EditTextExt* et,
                            const Avm2String* html, int is_multiline,
                            int condense_white)
{
	uint8_t swf_version = ctx->swf_version;
	Avm2TextFormatFields default_format = et->default_format;
	if (swf_version <= 6) is_multiline = 1;
	if (swf_version < 8)
	{
		default_format.align = ALIGN_LEFT;
		default_format.present |= TFP_ALIGN;
	}
	et->default_format = default_format;

	// Format stack.
	uint32_t stack_cap = 16, stack_n = 1;
	Avm2TextFormatFields* stack = avm2_alloc(ctx, stack_cap * sizeof(*stack));
	stack[0] = default_format;

	// Open-tag name stack (for mismatched end tags).
	struct { char name[16]; } open_tags[64];
	uint32_t open_n = 0;

	SB text;
	sb_init(&text);
	et->span_count = 0;
	et->text = empty_string(ctx);

	int p_open = 0;
	int display_block = 0;
	Avm2TextFormatFields last_closed_font;
	int have_last_closed_font = 0;

	const char* p = html->utf8;
	uint32_t n = html->len;
	uint32_t i = 0;

	// Emits one text span for the decoded segment.
#define PUSH_TEXT_SPAN(seg, seg_len, fmtp) \
	do { \
		uint32_t u16 = 0; \
		for (uint32_t _k = 0; _k < (seg_len); ) { \
			unsigned char _c = (unsigned char) (seg)[_k]; \
			if (_c < 0x80) { _k += 1; u16 += 1; } \
			else if (_c < 0xE0) { _k += 2; u16 += 1; } \
			else if (_c < 0xF0) { _k += 3; u16 += 1; } \
			else { _k += 4; u16 += 2; } \
		} \
		sb_bytes(ctx, &text, (seg), (seg_len)); \
		spans_push(ctx, et, u16, (fmtp)); \
	} while (0)

	while (i < n)
	{
		if (p[i] != '<')
		{
			// Text run up to the next '<'.
			uint32_t start = i;
			while (i < n && p[i] != '<') i++;
			SB decoded;
			sb_init(&decoded);
			html_decode_entities(ctx, &decoded, p + start, i - start);
			if (decoded.len == 0) continue;
			Avm2TextFormatFields* fmt = &stack[stack_n - 1];
			if ((fmt->present & TFP_DISPLAY) && fmt->display == DISPLAY_NONE)
			{
				continue;
			}
			if (swf_version <= 7)
			{
				int all_ws = 1;
				for (uint32_t k = 0; k < decoded.len; k++)
				{
					if (!swf_is_ws(decoded.buf[k])) { all_ws = 0; break; }
				}
				if (all_ws) continue;
			}
			SB out;
			sb_init(&out);
			if (condense_white)
			{
				int last_white = 0;
				for (uint32_t k = 0; k < decoded.len; k++)
				{
					if (swf_is_ws(decoded.buf[k]))
					{
						if (!last_white) { sb_ch(ctx, &out, ' '); last_white = 1; }
					}
					else
					{
						sb_ch(ctx, &out, decoded.buf[k]);
						last_white = 0;
					}
				}
			}
			else
			{
				// Newlines normalize to \r.
				for (uint32_t k = 0; k < decoded.len; k++)
				{
					char c = decoded.buf[k];
					sb_ch(ctx, &out, (c == '\n') ? '\r' : c);
				}
			}
			if (out.len > 0)
			{
				PUSH_TEXT_SPAN(out.buf, out.len, fmt);
			}
			continue;
		}

		// Comment?
		if (i + 3 < n && memcmp(p + i, "<!--", 4) == 0)
		{
			const char* close = NULL;
			for (uint32_t k = i + 4; k + 2 < n; k++)
			{
				if (memcmp(p + k, "-->", 3) == 0) { close = p + k; break; }
			}
			if (close == NULL) break;
			i = (uint32_t) (close - p) + 3;
			continue;
		}

		// Tag.
		uint32_t tag_end = i + 1;
		int in_quote = 0;
		char quote_ch = 0;
		while (tag_end < n)
		{
			char c = p[tag_end];
			if (in_quote)
			{
				if (c == quote_ch) in_quote = 0;
			}
			else if (c == '"' || c == '\'')
			{
				in_quote = 1;
				quote_ch = c;
			}
			else if (c == '>')
			{
				break;
			}
			tag_end++;
		}
		if (tag_end >= n) break;  // malformed trailing tag: stop parsing

		const char* tp = p + i + 1;
		uint32_t tlen = tag_end - i - 1;
		i = tag_end + 1;
		if (tlen == 0) continue;

		int is_end = (tp[0] == '/');
		if (is_end) { tp++; tlen--; }
		int self_closing = (tlen > 0 && tp[tlen - 1] == '/');
		if (self_closing) tlen--;

		// Tag name (lowercased).
		char tag_name[16];
		uint32_t tn = 0;
		uint32_t k = 0;
		while (k < tlen && !swf_is_ws(tp[k]) && tn < sizeof(tag_name) - 1)
		{
			char c = tp[k];
			if (c >= 'A' && c <= 'Z') c += 32;
			tag_name[tn++] = c;
			k++;
		}
		tag_name[tn] = '\0';

		// Attributes.
		HtmlAttr attrs[16];
		uint32_t attr_n = 0;
		while (k < tlen && attr_n < 16)
		{
			while (k < tlen && (swf_is_ws(tp[k]) || tp[k] == '/')) k++;
			if (k >= tlen) break;
			uint32_t name_s = k;
			while (k < tlen && tp[k] != '=' && !swf_is_ws(tp[k])) k++;
			attrs[attr_n].name = tp + name_s;
			attrs[attr_n].name_len = k - name_s;
			attrs[attr_n].value = NULL;
			attrs[attr_n].value_len = 0;
			while (k < tlen && swf_is_ws(tp[k])) k++;
			if (k < tlen && tp[k] == '=')
			{
				k++;
				while (k < tlen && swf_is_ws(tp[k])) k++;
				const char* vs;
				uint32_t vl;
				if (k < tlen && (tp[k] == '"' || tp[k] == '\''))
				{
					char q = tp[k];
					k++;
					vs = tp + k;
					while (k < tlen && tp[k] != q) k++;
					vl = (uint32_t) (tp + k - vs);
					if (k < tlen) k++;
				}
				else
				{
					vs = tp + k;
					while (k < tlen && !swf_is_ws(tp[k])) k++;
					vl = (uint32_t) (tp + k - vs);
				}
				SB dv;
				sb_init(&dv);
				html_decode_entities(ctx, &dv, vs, vl);
				sb_ch(ctx, &dv, '\0');
				attrs[attr_n].value = dv.buf;
				attrs[attr_n].value_len = dv.len - 1;
			}
			if (attrs[attr_n].name_len > 0) attr_n++;
		}

#define ATTR(nm) attr_find(attrs, attr_n, nm)

		int handle_start = !is_end;
		int handle_end = is_end || self_closing;

		if (handle_start)
		{
			Avm2TextFormatFields format = stack[stack_n - 1];
			int skip_push = 0;
			if (strcmp(tag_name, "br") == 0)
			{
				if (is_multiline)
				{
					PUSH_TEXT_SPAN("\r", 1, &format);
				}
				skip_push = 1;
				handle_end = 0;
			}
			else if (strcmp(tag_name, "sbr") == 0)
			{
				PUSH_TEXT_SPAN("\r", 1, &format);
				skip_push = 1;
				handle_end = 0;
			}
			else if (strcmp(tag_name, "p") == 0)
			{
				p_open = 1;
				const HtmlAttr* a = ATTR("align");
				if (a != NULL && a->value != NULL)
				{
					if (strcasecmp(a->value, "left") == 0)
					{ format.align = ALIGN_LEFT; format.present |= TFP_ALIGN; }
					else if (strcasecmp(a->value, "center") == 0)
					{ format.align = ALIGN_CENTER; format.present |= TFP_ALIGN; }
					else if (strcasecmp(a->value, "right") == 0)
					{ format.align = ALIGN_RIGHT; format.present |= TFP_ALIGN; }
					else if (strcasecmp(a->value, "justify") == 0)
					{ format.align = ALIGN_JUSTIFY; format.present |= TFP_ALIGN; }
				}
			}
			else if (strcmp(tag_name, "a") == 0)
			{
				const HtmlAttr* href = ATTR("href");
				if (href != NULL && href->value != NULL)
				{
					format.url = avm2_string_new(ctx, href->value, href->value_len);
					format.present |= TFP_URL;
				}
				const HtmlAttr* tgt = ATTR("target");
				if (tgt != NULL && tgt->value != NULL)
				{
					format.target = avm2_string_new(ctx, tgt->value, tgt->value_len);
					format.present |= TFP_TARGET;
				}
			}
			else if (strcmp(tag_name, "font") == 0)
			{
				const HtmlAttr* face = ATTR("face");
				if (face != NULL && face->value != NULL)
				{
					format.font = avm2_string_new(ctx, face->value, face->value_len);
					format.present |= TFP_FONT;
				}
				const HtmlAttr* size = ATTR("size");
				if (size != NULL && size->value != NULL)
				{
					const char* sv = size->value;
					uint32_t sl = size->value_len;
					char prefix = 0;
					if (sl > 0 && (sv[0] == '+' || sv[0] == '-'))
					{
						prefix = sv[0];
						sv++;
						sl--;
					}
					// Digits until the first non-numeric char.
					uint32_t dl = 0;
					while (dl < sl && sv[dl] >= '0' && sv[dl] <= '9') dl++;
					double sz;
					if (parse_f64_strict(sv, dl, &sz))
					{
						int ok = 1;
						if (prefix == '+')
						{
							if (format.present & TFP_SIZE) sz = format.size + sz;
							else ok = 0;
						}
						else if (prefix == '-')
						{
							if (format.present & TFP_SIZE) sz = format.size - sz;
							else ok = 0;
						}
						if (ok)
						{
							if (swf_version < 13)
							{
								if (sz < 1.0) sz = 1.0;
								if (sz > 127.0) sz = 127.0;
							}
							else if (sz < 1.0) sz = 1.0;
							format.size = sz;
							format.present |= TFP_SIZE;
						}
					}
				}
				const HtmlAttr* color = ATTR("color");
				if (color != NULL && color->value != NULL && color->value[0] == '#')
				{
					const char* hex = color->value + 1;
					while (*hex == ' ' || *hex == '\t') hex++;
					uint32_t end = 0;
					while (hex[end] != '\0'
					       && ((hex[end] >= '0' && hex[end] <= '9')
					           || (hex[end] >= 'a' && hex[end] <= 'f')
					           || (hex[end] >= 'A' && hex[end] <= 'F')))
					{
						end++;
					}
					uint32_t start = end > 6 ? end - 6 : 0;
					if (end > start)
					{
						uint32_t rgb = 0;
						for (uint32_t h = start; h < end; h++)
						{
							char c = hex[h];
							int d = c <= '9' ? c - '0'
							        : (c | 32) - 'a' + 10;
							rgb = (rgb << 4) | (uint32_t) d;
						}
						format.color = (rgb << 8);  // alpha 0
						format.present |= TFP_COLOR;
					}
				}
				const HtmlAttr* ls = ATTR("letterSpacing");
				if (ls != NULL && ls->value != NULL)
				{
					double v;
					if (parse_f64_strict(ls->value, ls->value_len, &v))
					{
						format.letter_spacing = v;
						format.present |= TFP_LETTER_SPACING;
					}
					else
					{
						format.present &= ~(uint32_t) TFP_LETTER_SPACING;
					}
				}
				const HtmlAttr* kern = ATTR("kerning");
				if (kern != NULL && kern->value != NULL)
				{
					if (strcmp(kern->value, "1") == 0 && swf_version >= 8)
					{
						format.kerning = 1;
						format.present |= TFP_KERNING;
					}
					else if (strcmp(kern->value, "0") == 0)
					{
						format.kerning = 0;
						format.present |= TFP_KERNING;
					}
				}
			}
			else if (strcmp(tag_name, "b") == 0)
			{
				format.bold = 1;
				format.present |= TFP_BOLD;
			}
			else if (strcmp(tag_name, "i") == 0)
			{
				format.italic = 1;
				format.present |= TFP_ITALIC;
			}
			else if (strcmp(tag_name, "u") == 0)
			{
				format.underline = 1;
				format.present |= TFP_UNDERLINE;
			}
			else if (strcmp(tag_name, "li") == 0)
			{
				int is_last_nl = text.len > 0 && text.buf[text.len - 1] == '\r';
				if (is_multiline && !is_last_nl && text.len > 0)
				{
					PUSH_TEXT_SPAN("\r", 1, &stack[stack_n - 1]);
				}
				format.bullet = 1;
				format.present |= TFP_BULLET;
			}
			else if (strcmp(tag_name, "textformat") == 0)
			{
				const HtmlAttr* a;
				double v;
				if ((a = ATTR("leftmargin")) != NULL && a->value != NULL
				    && parse_f64_strict(a->value, a->value_len, &v))
				{ format.left_margin = v; format.present |= TFP_LEFT_MARGIN; }
				if ((a = ATTR("rightmargin")) != NULL && a->value != NULL
				    && parse_f64_strict(a->value, a->value_len, &v))
				{ format.right_margin = v; format.present |= TFP_RIGHT_MARGIN; }
				if ((a = ATTR("indent")) != NULL && a->value != NULL
				    && parse_f64_strict(a->value, a->value_len, &v))
				{ format.indent = v; format.present |= TFP_INDENT; }
				if ((a = ATTR("blockindent")) != NULL && a->value != NULL
				    && parse_f64_strict(a->value, a->value_len, &v))
				{ format.block_indent = v; format.present |= TFP_BLOCK_INDENT; }
				if ((a = ATTR("leading")) != NULL && a->value != NULL
				    && parse_f64_strict(a->value, a->value_len, &v))
				{ format.leading = v; format.present |= TFP_LEADING; }
				if ((a = ATTR("tabstops")) != NULL && a->value != NULL)
				{
					double* stops = avm2_alloc(ctx, 32 * sizeof(double));
					uint32_t cnt = 0;
					const char* sv = a->value;
					while (*sv != '\0' && cnt < 32)
					{
						const char* comma = strchr(sv, ',');
						uint32_t seg = comma != NULL ? (uint32_t) (comma - sv)
						                             : (uint32_t) strlen(sv);
						// trim
						const char* ts = sv;
						uint32_t tl2 = seg;
						while (tl2 > 0 && swf_is_ws(ts[0])) { ts++; tl2--; }
						while (tl2 > 0 && swf_is_ws(ts[tl2 - 1])) tl2--;
						double tv;
						if (parse_f64_strict(ts, tl2, &tv)) stops[cnt++] = tv;
						if (comma == NULL) break;
						sv = comma + 1;
					}
					format.tab_stops = stops;
					format.tab_stop_count = cnt;
					format.present |= TFP_TAB_STOPS;
				}
			}
			else if (strcmp(tag_name, "span") == 0)
			{
				// Stylesheet-only tag; no-op without one.
			}
			else
			{
				// Unstyled unknown tag: display resolves to inline.
				format.present &= ~(uint32_t) TFP_DISPLAY;
			}

			if (!skip_push)
			{
				if (stack_n == stack_cap)
				{
					uint32_t ncap = stack_cap * 2;
					Avm2TextFormatFields* ns = avm2_alloc(ctx, ncap * sizeof(*ns));
					memcpy(ns, stack, stack_n * sizeof(*ns));
					stack = ns;
					stack_cap = ncap;
				}
				stack[stack_n++] = format;
				if (open_n < 64)
				{
					strncpy(open_tags[open_n].name, tag_name,
					        sizeof(open_tags[open_n].name) - 1);
					open_tags[open_n].name[sizeof(open_tags[open_n].name) - 1] = '\0';
					open_n++;
				}
			}
		}

		if (handle_end && strcmp(tag_name, "br") != 0
		    && strcmp(tag_name, "sbr") != 0)
		{
			// Mismatched end tags are ignored.
			if (open_n == 0) continue;
			if (strcmp(open_tags[open_n - 1].name, tag_name) != 0) continue;
			open_n--;

			if (display_block)
			{
				display_block = 0;
				PUSH_TEXT_SPAN("\r", 1, &stack[stack_n - 1]);
			}

			if (strcmp(tag_name, "li") == 0 && is_multiline)
			{
				PUSH_TEXT_SPAN("\r", 1, &stack[stack_n - 1]);
			}
			else if (strcmp(tag_name, "p") == 0 && is_multiline)
			{
				if (p_open)
				{
					p_open = 0;
					// </p>'s newline span: style/url/target reset; the font
					// half comes from the last </font> (or the default).
					Avm2TextFormatFields span_fmt = stack[stack_n - 1];
					span_fmt.bold = 0;
					span_fmt.italic = 0;
					span_fmt.underline = 0;
					span_fmt.present |= TFP_BOLD | TFP_ITALIC | TFP_UNDERLINE;
					span_fmt.url = empty_string(ctx);
					span_fmt.target = empty_string(ctx);
					span_fmt.present |= TFP_URL | TFP_TARGET;
					Avm2TextFormatFields font_src = have_last_closed_font
						? last_closed_font : default_format;
					// Copy the font-family fields.
					if (font_src.present & TFP_FONT)
					{ span_fmt.font = font_src.font; span_fmt.present |= TFP_FONT; }
					if (font_src.present & TFP_SIZE)
					{ span_fmt.size = font_src.size; span_fmt.present |= TFP_SIZE; }
					if (font_src.present & TFP_COLOR)
					{ span_fmt.color = font_src.color; span_fmt.present |= TFP_COLOR; }
					if (font_src.present & TFP_LETTER_SPACING)
					{
						span_fmt.letter_spacing = font_src.letter_spacing;
						span_fmt.present |= TFP_LETTER_SPACING;
					}
					if (font_src.present & TFP_KERNING)
					{ span_fmt.kerning = font_src.kerning; span_fmt.present |= TFP_KERNING; }
					PUSH_TEXT_SPAN("\r", 1, &span_fmt);
				}
			}
			else if (strcmp(tag_name, "font") == 0)
			{
				last_closed_font = stack[stack_n - 1];
				have_last_closed_font = 1;
			}
			if (stack_n > 1) stack_n--;
		}
#undef ATTR
	}

	et->text = sb_str(ctx, &text);
	et->original_html = NULL;
	spans_normalize(ctx, et);
#undef PUSH_TEXT_SPAN
}

// ===========================================================================
// EditText init / tag seeding
// ===========================================================================

static const Avm2FontData* font_by_id(uint16_t font_id)
{
	for (uint32_t i = 0; i < avm2_generated_font_count; i++)
	{
		if (avm2_generated_fonts[i].font_id == font_id)
		{
			return &avm2_generated_fonts[i];
		}
	}
	return NULL;
}

static const Avm2EditTextData* edittext_data_by_id(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_edittext_count; i++)
	{
		if (avm2_generated_edittexts[i].char_id == char_id)
		{
			return &avm2_generated_edittexts[i];
		}
	}
	return NULL;
}

// Shared EditText construction from tag data (Ruffle from_swf_tag +
// TextFormat::from_swf_tag). `td` NULL = the synthetic script-created tag
// (read-only, selectable, 100x100 px bounds, font 0 height 12px, black).
static void edittext_init_common(Avm2Context* ctx, Avm2Object* obj,
                                 const Avm2EditTextData* td,
                                 const Avm2CharInfo* ci)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, obj);
	if (ext == NULL) return;
	Avm2EditTextExt* et = avm2_alloc(ctx, sizeof(Avm2EditTextExt));
	memset(et, 0, sizeof(*et));
	ext->edittext = et;

	et->aa_advanced = 1;
	et->grid_fit = 1;  // pixel
	et->border_color = 0x000000;
	et->background_color = 0xFFFFFF;
	et->scroll = 1;
	et->text = empty_string(ctx);
	et->style_sheet = NULL;

	uint16_t flags = td != NULL ? td->flags : 0;
	int has_font = (flags & AVM2_ETF_HAS_FONT) != 0;
	int has_layout = (flags & AVM2_ETF_HAS_LAYOUT) != 0;
	int is_html = (flags & AVM2_ETF_HTML) != 0;
	int has_text = (flags & AVM2_ETF_HAS_TEXT) != 0;

	if (td != NULL)
	{
		et->word_wrap = (flags & AVM2_ETF_WORD_WRAP) != 0;
		et->multiline = (flags & AVM2_ETF_MULTILINE) != 0;
		et->password = (flags & AVM2_ETF_PASSWORD) != 0;
		et->read_only = (flags & AVM2_ETF_READ_ONLY) != 0;
		et->no_select = (flags & AVM2_ETF_NO_SELECT) != 0;
		et->border = (flags & AVM2_ETF_BORDER) != 0;
		et->was_static = (flags & AVM2_ETF_WAS_STATIC) != 0;
		et->is_html = is_html;
		et->device_font = (flags & AVM2_ETF_USE_OUTLINES) == 0;
		et->autosize = (flags & AVM2_ETF_AUTO_SIZE) != 0 ? 1 : 0;  // left
		et->max_chars = (flags & AVM2_ETF_HAS_MAX_LENGTH) ? td->max_length : 0;
		et->font_id = td->font_id;
		et->from_tag = 1;
		if (ci != NULL)
		{
			et->bounds_x = ci->xmin;
			et->bounds_y = ci->ymin;
			et->bounds_w = ci->xmax - ci->xmin;
			et->bounds_h = ci->ymax - ci->ymin;
		}
	}
	else
	{
		et->read_only = 1;
		et->device_font = 1;
		et->bounds_w = 100 * 20;
		et->bounds_h = 100 * 20;
	}

	// Default format (TextFormat::from_swf_tag).
	Avm2TextFormatFields df;
	memset(&df, 0, sizeof(df));
	df.present = TFP_ALL;
	const Avm2FontData* font = (td != NULL && has_font) ? font_by_id(td->font_id)
	                                                    : NULL;
	if (td != NULL && (flags & AVM2_ETF_HAS_FONT_CLASS) && td->font_class != NULL)
	{
		df.font = avm2_string_from_literal(ctx, td->font_class);
	}
	else if (font != NULL)
	{
		df.font = avm2_string_from_literal(ctx, font->name);
	}
	else
	{
		df.font = avm2_string_from_literal(ctx, "Times New Roman");
	}
	if (is_html && (ctx->swf_version < 8 || !has_text))
	{
		df.align = ALIGN_LEFT;
	}
	else
	{
		df.align = (td != NULL && has_layout) ? td->align : ALIGN_LEFT;
		if (df.align > 3) df.align = ALIGN_LEFT;
	}
	df.size = (td != NULL && has_font) ? td->font_height / 20.0
	        : (td == NULL ? 12.0 : 12.0);
	if (td != NULL && (flags & AVM2_ETF_HAS_TEXT_COLOR))
	{
		// from_rgb(color.to_rgb(), 0): rgb kept, alpha 0.
		df.color = td->color_rgba & 0xFFFFFF00u;
	}
	else if (td == NULL)
	{
		df.color = 0x00000000;  // BLACK rgb with alpha 0
	}
	else
	{
		df.color = 0;  // TRANSPARENT
	}
	df.bold = (!is_html && font != NULL && font->bold) ? 1 : 0;
	df.italic = (!is_html && font != NULL && font->italic) ? 1 : 0;
	df.underline = 0;
	df.display = DISPLAY_BLOCK;
	if (td != NULL && has_layout)
	{
		df.left_margin = td->left_margin / 20.0;
		df.right_margin = td->right_margin / 20.0;
		double indent_px = td->indent / 20.0;
		df.indent = nearbyint(indent_px);
		df.leading = td->leading / 20.0;
	}
	df.block_indent = 0;
	df.kerning = 0;
	df.letter_spacing = 0;
	df.tab_stops = NULL;
	df.tab_stop_count = 0;
	df.bullet = 0;
	df.url = empty_string(ctx);
	df.target = empty_string(ctx);
	et->default_format = df;

	// Initial text.
	if (td != NULL && has_text && td->raw_text != NULL)
	{
		const Avm2String* raw = avm2_string_from_literal(ctx, td->raw_text);
		if (is_html)
		{
			spans_from_html(ctx, et, raw, et->multiline, et->condense_white);
		}
		else
		{
			spans_from_text(ctx, et, raw);
		}
	}
	else
	{
		spans_from_text(ctx, et, empty_string(ctx));
	}

	// Keep the legacy tf_text mirror for display code.
	ext->tf_text = et->text;
}

// Alloc hook half for script-created TextFields (`new TextField()`).
void avm2_text_edittext_init(Avm2Context* ctx, Avm2Object* obj)
{
	edittext_init_common(ctx, obj, NULL, NULL);
}

// Timeline instantiation: seed from the DefineEditText tag data.
void avm2_text_seed_from_tag(Avm2Context* ctx, Avm2Object* obj, uint16_t char_id)
{
	const Avm2EditTextData* td = edittext_data_by_id(char_id);
	const Avm2CharInfo* ci = NULL;
	for (uint32_t i = 0; i < avm2_generated_char_count; i++)
	{
		if (avm2_generated_chars[i].char_id == char_id)
		{
			ci = &avm2_generated_chars[i];
			break;
		}
	}
	if (td == NULL) return;
	edittext_init_common(ctx, obj, td, ci);
}

// ===========================================================================
// TextField natives
// ===========================================================================

static void et_sync_mirror(Avm2Activation* act, Avm2EditTextExt* et)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(act->ctx, this_obj(act));
	if (ext != NULL) ext->tf_text = et->text;
}

static Avm2Value txt_get_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	return avm2_string(et->text);
}

static Avm2Value txt_set_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "text");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	if (str_eq(et->text, s)) return avm2_undefined();
	if (et->style_sheet != NULL)
	{
		spans_from_html(act->ctx, et, s, et->multiline, et->condense_white);
	}
	else
	{
		spans_from_text(act->ctx, et, s);
	}
	et_sync_mirror(act, et);
	return avm2_undefined();
}

static Avm2Value txt_get_html_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	if (et->is_html || et->style_sheet != NULL)
	{
		if (et->original_html != NULL) return avm2_string(et->original_html);
		avm2_fatal("AVM2: TextField.htmlText getter (spans-to-html) is not "
		           "implemented yet (Stage-6 tranche 3)");
	}
	return avm2_string(et->text);
}

static Avm2Value txt_set_html_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	// AS3 glue uses get_string: null becomes the literal string "null".
	const Avm2String* s;
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		s = avm2_string_from_literal(act->ctx, "null");
	}
	else
	{
		s = avm2_coerce_to_string(act->ctx, v);
	}
	// The AS3 htmlText setter always switches the field into HTML mode
	// (Ruffle set_html_text glue: set_is_html(true) first).
	et->is_html = 1;
	// set_html_text no-op check (observable: formats are not reset). We can
	// only compare against the cached original html; the spans-to-html
	// writer lands in tranche 3.
	if (et->original_html != NULL && str_eq(et->original_html, s))
	{
		return avm2_undefined();
	}
	spans_from_html(act->ctx, et, s, et->multiline, et->condense_white);
	if (et->style_sheet == NULL) et->original_html = s;
	et_sync_mirror(act, et);
	return avm2_undefined();
}

static Avm2Value txt_get_length(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	return avm2_integer((int32_t) u16_length(et->text));
}

// --- boolean/data properties ---

#define ET_BOOL_GETSET(name, field) \
	static Avm2Value txt_get_##name(Avm2Activation* act) \
	{ \
		Avm2EditTextExt* et = this_et(act); \
		return et != NULL ? avm2_bool(et->field != 0) : avm2_undefined(); \
	} \
	static Avm2Value txt_set_##name(Avm2Activation* act) \
	{ \
		Avm2EditTextExt* et = this_et(act); \
		if (et != NULL) et->field = avm2_coerce_to_boolean(arg_or_undef(act, 0)) ? 1 : 0; \
		return avm2_undefined(); \
	}

ET_BOOL_GETSET(word_wrap, word_wrap)
ET_BOOL_GETSET(multiline, multiline)
ET_BOOL_GETSET(border, border)
ET_BOOL_GETSET(background, background)
ET_BOOL_GETSET(display_as_password, password)
ET_BOOL_GETSET(condense_white, condense_white)
ET_BOOL_GETSET(always_show_selection, always_show_selection)
ET_BOOL_GETSET(mouse_wheel_enabled, mouse_wheel_enabled)

static Avm2Value txt_get_selectable(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_bool(et->no_select == 0) : avm2_undefined();
}
static Avm2Value txt_set_selectable(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et != NULL)
	{
		et->no_select = avm2_coerce_to_boolean(arg_or_undef(act, 0)) ? 0 : 1;
	}
	return avm2_undefined();
}

static Avm2Value txt_get_embed_fonts(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_bool(et->device_font == 0) : avm2_undefined();
}
static Avm2Value txt_set_embed_fonts(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et != NULL)
	{
		et->device_font = avm2_coerce_to_boolean(arg_or_undef(act, 0)) ? 0 : 1;
	}
	return avm2_undefined();
}

static Avm2Value txt_get_type(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	return avm2_string(avm2_string_from_literal(act->ctx,
	                   et->read_only ? "dynamic" : "input"));
}

static Avm2Value txt_set_type(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "type");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	if (s->len == 5 && memcmp(s->utf8, "input", 5) == 0) et->read_only = 0;
	else if (s->len == 7 && memcmp(s->utf8, "dynamic", 7) == 0) et->read_only = 1;
	else throw_2008(act->ctx, "type");
	return avm2_undefined();
}

static Avm2Value txt_get_auto_size(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	const char* s = et->autosize == 1 ? "left"
	              : et->autosize == 2 ? "center"
	              : et->autosize == 3 ? "right" : "none";
	return avm2_string(avm2_string_from_literal(act->ctx, s));
}

static Avm2Value txt_set_auto_size(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "autoSize");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	if (s->len == 4 && memcmp(s->utf8, "left", 4) == 0) et->autosize = 1;
	else if (s->len == 6 && memcmp(s->utf8, "center", 6) == 0) et->autosize = 2;
	else if (s->len == 5 && memcmp(s->utf8, "right", 5) == 0) et->autosize = 3;
	else if (s->len == 4 && memcmp(s->utf8, "none", 4) == 0) et->autosize = 0;
	else throw_2008(act->ctx, "autoSize");
	return avm2_undefined();
}

static Avm2Value txt_get_border_color(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_number((double) et->border_color) : avm2_undefined();
}
static Avm2Value txt_set_border_color(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et != NULL)
	{
		et->border_color =
			avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0)) & 0xFFFFFF;
	}
	return avm2_undefined();
}

static Avm2Value txt_get_background_color(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_number((double) et->background_color) : avm2_undefined();
}
static Avm2Value txt_set_background_color(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et != NULL)
	{
		et->background_color =
			avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0)) & 0xFFFFFF;
	}
	return avm2_undefined();
}

static Avm2Value txt_get_text_color(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	if (et->default_format.present & TFP_COLOR)
	{
		return avm2_number((double) (et->default_format.color >> 8));
	}
	return avm2_number(0.0);
}

static Avm2Value txt_set_text_color(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	uint32_t rgb = avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0)) & 0xFFFFFF;
	Avm2TextFormatFields desired = format_default();
	desired.color = (rgb << 8) | 0xFF;  // from_rgb(rgb, 0xFF)
	desired.present |= TFP_COLOR;
	spans_set_format(act->ctx, et, 0, u16_length(et->text), &desired);
	spans_set_default_format(act->ctx, et, &desired);
	return avm2_undefined();
}

static Avm2Value txt_get_max_chars(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_integer(et->max_chars) : avm2_undefined();
}
static Avm2Value txt_set_max_chars(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et != NULL)
	{
		et->max_chars = avm2_coerce_to_i32(act->ctx, arg_or_undef(act, 0));
	}
	return avm2_undefined();
}

static Avm2Value txt_get_restrict(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	if (!et->has_restrict) return avm2_null();
	return avm2_string(et->restrict_str);
}
static Avm2Value txt_set_restrict(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		et->has_restrict = 0;
		et->restrict_str = NULL;
	}
	else
	{
		et->has_restrict = 1;
		et->restrict_str = avm2_coerce_to_string(act->ctx, v);
	}
	return avm2_undefined();
}

static Avm2Value txt_get_scroll_v(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_integer(et->scroll) : avm2_undefined();
}

static Avm2Value txt_get_scroll_h(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_integer((int32_t) et->hscroll) : avm2_undefined();
}

static Avm2Value txt_get_anti_alias_type(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	return avm2_string(avm2_string_from_literal(act->ctx,
	                   et->aa_advanced ? "advanced" : "normal"));
}
static Avm2Value txt_set_anti_alias_type(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "antiAliasType");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	if (s->len == 8 && memcmp(s->utf8, "advanced", 8) == 0) et->aa_advanced = 1;
	else if (s->len == 6 && memcmp(s->utf8, "normal", 6) == 0) et->aa_advanced = 0;
	return avm2_undefined();
}

static Avm2Value txt_get_grid_fit_type(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	const char* s = et->grid_fit == 1 ? "pixel"
	              : et->grid_fit == 2 ? "subpixel" : "none";
	return avm2_string(avm2_string_from_literal(act->ctx, s));
}
static Avm2Value txt_set_grid_fit_type(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "gridFitType");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	if (s->len == 5 && memcmp(s->utf8, "pixel", 5) == 0) et->grid_fit = 1;
	else if (s->len == 8 && memcmp(s->utf8, "subpixel", 8) == 0) et->grid_fit = 2;
	else et->grid_fit = 0;  // invalid values -> none
	return avm2_undefined();
}

static Avm2Value txt_get_thickness(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_number(et->thickness) : avm2_undefined();
}
static Avm2Value txt_set_thickness(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	double v = avm2_coerce_to_number(act->ctx, arg_or_undef(act, 0));
	if (v < -200.0 || isnan(v)) v = -200.0;
	if (v > 200.0) v = 200.0;
	// f32 storage in Ruffle; values here stay integral in tests.
	et->thickness = (double) (float) v;
	return avm2_undefined();
}

static Avm2Value txt_get_sharpness(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_number(et->sharpness) : avm2_undefined();
}
static Avm2Value txt_set_sharpness(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	double v = avm2_coerce_to_number(act->ctx, arg_or_undef(act, 0));
	if (v < -400.0 || isnan(v)) v = -400.0;
	if (v > 400.0) v = 400.0;
	et->sharpness = (double) (float) v;
	return avm2_undefined();
}

static Avm2Value txt_get_style_sheet(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	return et->style_sheet != NULL ? avm2_object_value(et->style_sheet)
	                               : avm2_null();
}

static Avm2Value txt_set_style_sheet(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL)
	{
		avm2_fatal("AVM2: TextField.styleSheet is not implemented yet "
		           "(Stage-6 tranche 3)");
	}
	et->style_sheet = NULL;
	return avm2_undefined();
}

// --- selection (data model) ---

static Avm2Value txt_get_selection_begin(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_integer(et->sel_begin) : avm2_undefined();
}
static Avm2Value txt_get_selection_end(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_integer(et->sel_end) : avm2_undefined();
}
static Avm2Value txt_get_caret_index(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	return et != NULL ? avm2_integer(et->sel_end) : avm2_undefined();
}

static Avm2Value txt_set_selection(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	int32_t b = avm2_coerce_to_i32(act->ctx, arg_or_undef(act, 0));
	int32_t e = avm2_coerce_to_i32(act->ctx, arg_or_undef(act, 1));
	int32_t len = (int32_t) u16_length(et->text);
	if (b < 0) b = 0;
	if (b > len) b = len;
	if (e < 0) e = 0;
	if (e > len) e = len;
	et->sel_begin = b < e ? b : e;
	et->sel_end = b < e ? e : b;
	return avm2_undefined();
}

static Avm2Value txt_get_selected_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	uint32_t b = (uint32_t) et->sel_begin, e = (uint32_t) et->sel_end;
	uint32_t bb = u16_to_byte(et->text, b);
	uint32_t eb = u16_to_byte(et->text, e);
	if (eb < bb) eb = bb;
	return avm2_string(avm2_string_new(act->ctx, et->text->utf8 + bb, eb - bb));
}

static Avm2Value txt_replace_selected_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "value");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	spans_replace_text(act->ctx, et, (uint32_t) et->sel_begin,
	                   (uint32_t) et->sel_end, s);
	et_sync_mirror(act, et);
	return avm2_undefined();
}

// --- formats ---

// Convert a TextFormat OBJECT's fields into internal fields.
static Avm2TextFormatFields fields_from_object(Avm2Object* obj)
{
	Avm2TextFormatFields* f = tf_fields_of(obj);
	return f != NULL ? *f : format_default();
}

static Avm2Value txt_get_default_text_format(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	return avm2_object_value(
		textformat_object_from_fields(act->ctx, &et->default_format));
}

static Avm2Value txt_set_default_text_format(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_OBJECT && v.u.obj != NULL)
	{
		Avm2TextFormatFields* f = tf_fields_of(v.u.obj);
		if (f != NULL)
		{
			spans_set_default_format(act->ctx, et, f);
		}
	}
	return avm2_undefined();
}

static Avm2Value txt_get_text_format(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	int32_t begin = act->argc > 0 ? avm2_coerce_to_i32(act->ctx, act->args[0]) : -1;
	int32_t end = act->argc > 1 ? avm2_coerce_to_i32(act->ctx, act->args[1]) : -1;
	if (end >= 0 && (begin >= end || begin < 0))
	{
		throw_2006(act->ctx);
	}
	if (begin < 0) begin = 0;
	if (end < 0) end = (int32_t) u16_length(et->text);
	Avm2TextFormatFields f = spans_get_format(et, (uint32_t) begin, (uint32_t) end);
	return avm2_object_value(textformat_object_from_fields(act->ctx, &f));
}

static Avm2Value txt_set_text_format(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value fmt = arg_or_undef(act, 0);
	if (fmt.kind != AVM2_VALUE_OBJECT || fmt.u.obj == NULL)
	{
		return avm2_undefined();
	}
	Avm2TextFormatFields* f = tf_fields_of(fmt.u.obj);
	if (f == NULL) return avm2_undefined();
	int32_t begin = act->argc > 1 ? avm2_coerce_to_i32(act->ctx, act->args[1]) : -1;
	int32_t end = act->argc > 2 ? avm2_coerce_to_i32(act->ctx, act->args[2]) : -1;
	int32_t len = (int32_t) u16_length(et->text);
	if (begin < 0) begin = 0;
	if (begin > len) throw_2006(act->ctx);
	if (end < 0) end = len;
	if (end > len) throw_2006(act->ctx);
	spans_set_format(act->ctx, et, (uint32_t) begin, (uint32_t) end, f);
	return avm2_undefined();
}

static Avm2Value txt_append_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	Avm2Value v = arg_or_undef(act, 0);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "text");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	uint32_t len = u16_length(et->text);
	spans_replace_text(act->ctx, et, len, len, s);
	et_sync_mirror(act, et);
	return avm2_undefined();
}

static Avm2Value txt_replace_text(Avm2Activation* act)
{
	Avm2EditTextExt* et = this_et(act);
	if (et == NULL) return avm2_undefined();
	int32_t begin = act->argc > 0 ? avm2_coerce_to_i32(act->ctx, act->args[0]) : 0;
	int32_t end = act->argc > 1 ? avm2_coerce_to_i32(act->ctx, act->args[1]) : 0;
	Avm2Value v = arg_or_undef(act, 2);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, "text");
	}
	const Avm2String* s = avm2_coerce_to_string(act->ctx, v);
	spans_replace_text(act->ctx, et, (uint32_t) begin, (uint32_t) end, s);
	et_sync_mirror(act, et);
	return avm2_undefined();
}

// ===========================================================================
// Registration
// ===========================================================================

void avm2_register_text(Avm2Context* ctx)
{
	Avm2Class* tf = avm2_builtin_class(ctx, "flash.text", "TextFormat",
	                                   ctx->builtins.object_class);
	g_textformat_class = tf;
	tf->native_ext_size = sizeof(Avm2TextFormatFields);
	tf->native_init = textformat_native_init;
	tf->instance_init.fn = tfmt_ctor;
	avm2_builtin_add_getset(ctx, tf, "font", tfmt_get_font, tfmt_set_font);
	avm2_builtin_add_getset(ctx, tf, "size", tfmt_get_size, tfmt_set_size);
	avm2_builtin_add_getset(ctx, tf, "color", tfmt_get_color, tfmt_set_color);
	avm2_builtin_add_getset(ctx, tf, "align", tfmt_get_align, tfmt_set_align);
	avm2_builtin_add_getset(ctx, tf, "bold", tfmt_get_bold, tfmt_set_bold);
	avm2_builtin_add_getset(ctx, tf, "italic", tfmt_get_italic, tfmt_set_italic);
	avm2_builtin_add_getset(ctx, tf, "underline", tfmt_get_underline, tfmt_set_underline);
	avm2_builtin_add_getset(ctx, tf, "url", tfmt_get_url, tfmt_set_url);
	avm2_builtin_add_getset(ctx, tf, "target", tfmt_get_target, tfmt_set_target);
	avm2_builtin_add_getset(ctx, tf, "leftMargin", tfmt_get_left_margin, tfmt_set_left_margin);
	avm2_builtin_add_getset(ctx, tf, "rightMargin", tfmt_get_right_margin, tfmt_set_right_margin);
	avm2_builtin_add_getset(ctx, tf, "indent", tfmt_get_indent, tfmt_set_indent);
	avm2_builtin_add_getset(ctx, tf, "blockIndent", tfmt_get_block_indent, tfmt_set_block_indent);
	avm2_builtin_add_getset(ctx, tf, "leading", tfmt_get_leading, tfmt_set_leading);
	avm2_builtin_add_getset(ctx, tf, "letterSpacing", tfmt_get_letter_spacing, tfmt_set_letter_spacing);
	avm2_builtin_add_getset(ctx, tf, "kerning", tfmt_get_kerning, tfmt_set_kerning);
	avm2_builtin_add_getset(ctx, tf, "bullet", tfmt_get_bullet, tfmt_set_bullet);
	avm2_builtin_add_getset(ctx, tf, "tabStops", tfmt_get_tab_stops, tfmt_set_tab_stops);
	avm2_builtin_add_getset(ctx, tf, "display", tfmt_get_display, tfmt_set_display);
}

void avm2_text_init_textfield_class(Avm2Context* ctx, Avm2Class* textfield)
{
	g_textfield_class2 = textfield;
	avm2_builtin_add_getset(ctx, textfield, "text", txt_get_text, txt_set_text);
	avm2_builtin_add_getset(ctx, textfield, "htmlText", txt_get_html_text, txt_set_html_text);
	avm2_builtin_add_getset(ctx, textfield, "length", txt_get_length, NULL);
	avm2_builtin_add_getset(ctx, textfield, "wordWrap", txt_get_word_wrap, txt_set_word_wrap);
	avm2_builtin_add_getset(ctx, textfield, "multiline", txt_get_multiline, txt_set_multiline);
	avm2_builtin_add_getset(ctx, textfield, "border", txt_get_border, txt_set_border);
	avm2_builtin_add_getset(ctx, textfield, "background", txt_get_background, txt_set_background);
	avm2_builtin_add_getset(ctx, textfield, "displayAsPassword", txt_get_display_as_password, txt_set_display_as_password);
	avm2_builtin_add_getset(ctx, textfield, "condenseWhite", txt_get_condense_white, txt_set_condense_white);
	avm2_builtin_add_getset(ctx, textfield, "alwaysShowSelection", txt_get_always_show_selection, txt_set_always_show_selection);
	avm2_builtin_add_getset(ctx, textfield, "mouseWheelEnabled", txt_get_mouse_wheel_enabled, txt_set_mouse_wheel_enabled);
	avm2_builtin_add_getset(ctx, textfield, "selectable", txt_get_selectable, txt_set_selectable);
	avm2_builtin_add_getset(ctx, textfield, "embedFonts", txt_get_embed_fonts, txt_set_embed_fonts);
	avm2_builtin_add_getset(ctx, textfield, "type", txt_get_type, txt_set_type);
	avm2_builtin_add_getset(ctx, textfield, "autoSize", txt_get_auto_size, txt_set_auto_size);
	avm2_builtin_add_getset(ctx, textfield, "borderColor", txt_get_border_color, txt_set_border_color);
	avm2_builtin_add_getset(ctx, textfield, "backgroundColor", txt_get_background_color, txt_set_background_color);
	avm2_builtin_add_getset(ctx, textfield, "textColor", txt_get_text_color, txt_set_text_color);
	avm2_builtin_add_getset(ctx, textfield, "maxChars", txt_get_max_chars, txt_set_max_chars);
	avm2_builtin_add_getset(ctx, textfield, "restrict", txt_get_restrict, txt_set_restrict);
	avm2_builtin_add_getset(ctx, textfield, "antiAliasType", txt_get_anti_alias_type, txt_set_anti_alias_type);
	avm2_builtin_add_getset(ctx, textfield, "gridFitType", txt_get_grid_fit_type, txt_set_grid_fit_type);
	avm2_builtin_add_getset(ctx, textfield, "thickness", txt_get_thickness, txt_set_thickness);
	avm2_builtin_add_getset(ctx, textfield, "sharpness", txt_get_sharpness, txt_set_sharpness);
	avm2_builtin_add_getset(ctx, textfield, "styleSheet", txt_get_style_sheet, txt_set_style_sheet);
	avm2_builtin_add_getset(ctx, textfield, "defaultTextFormat", txt_get_default_text_format, txt_set_default_text_format);
	avm2_builtin_add_getset(ctx, textfield, "selectionBeginIndex", txt_get_selection_begin, NULL);
	avm2_builtin_add_getset(ctx, textfield, "selectionEndIndex", txt_get_selection_end, NULL);
	avm2_builtin_add_getset(ctx, textfield, "caretIndex", txt_get_caret_index, NULL);
	avm2_builtin_add_getset(ctx, textfield, "selectedText", txt_get_selected_text, NULL);
	avm2_builtin_add_method(ctx, textfield, "getTextFormat", txt_get_text_format);
	avm2_builtin_add_method(ctx, textfield, "setTextFormat", txt_set_text_format);
	avm2_builtin_add_method(ctx, textfield, "appendText", txt_append_text);
	avm2_builtin_add_method(ctx, textfield, "replaceText", txt_replace_text);
	avm2_builtin_add_method(ctx, textfield, "setSelection", txt_set_selection);
	avm2_builtin_add_method(ctx, textfield, "replaceSelectedText", txt_replace_selected_text);
	avm2_builtin_add_getset(ctx, textfield, "scrollV", txt_get_scroll_v, NULL);
	avm2_builtin_add_getset(ctx, textfield, "scrollH", txt_get_scroll_h, NULL);
}
