// avm2_stage3d.c — flash.display.Stage3D + the flash.display3D family.
//
// Tranche S1 of the shader/3D arc (SWFRecompDocs/plans/shader3d-arc.md).
//
// There is no GPU behind any of this, and the corpus does not ask for one:
// every graded line in the Stage3D block is a *trace*, produced either by the
// profile-negotiation protocol, by the deferred `context3DCreate` timing, or
// by an argument validator. The render-only siblings (21 of them) grade an
// image, not output, and already "pass" with zero expected lines — so the
// requirement here is that the whole surface be reachable and silent, and
// that the validators throw exactly the FP errors.
//
// The three mechanisms that carry the yield:
//
//   * Profile negotiation (Ruffle core/.../display/Stage3D.as +
//     stage_3d.rs:6-69). `requestContext3D` validates ONE profile string and
//     requests it; `requestContext3DMatchingProfiles` validates a whole
//     Vector and the highest-ranked REQUESTED profile wins regardless of the
//     vector's order. The two #2008 messages differ: `checkProfile` names the
//     parameter "profile" (singular), the empty-vector check names it
//     "profiles" (plural).
//
//   * Deferred context creation (stage_3d.rs:55-64 + frame_lifecycle.rs:104).
//     `requestContext3D` only records the request; the Context3D is built and
//     `context3DCreate` dispatched at the END of the frame — after the
//     exitFrame broadcast, before the next frame's enterFrame. That one-frame
//     delay is why request_profiles needs 12 ticks for 6 profiles and
//     request_matching_profiles 126 for 63 subsets, and avm2/context3d_creation
//     grades the interleaving with the frame events exactly.
//
//   * String-argument validators. Every Context3D method that takes an enum
//     string raises ArgumentError #2008 naming its own parameter; the accepted
//     spellings come from ruffle_render::backend's FromWStr impls
//     (render/src/backend.rs:160-520) and are case-SENSITIVE.
//     avm2/stage3d_context3d_string_args enumerates all 158 of them.
//
// Tranche S2 adds the AGAL bytecode validator behind `Program3D.upload`
// (agal_validate below) — a transliteration of naga-agal's parse_bytecode +
// extract_sampler_configs validation arms, with Ruffle's AgalError -> FP error
// mapping from core/src/avm2/error.rs::make_agal_upload_error. Ruffle's parser
// `unwrap()`s on out-of-range register-type bits; we must not copy the panic,
// so an unknown register type validates as "no error" instead.
//
// flash.geom.Matrix3D also lives here: it is not Stage3D, but the only reason
// the corpus needs it is `setProgramConstantsFromMatrix`, and avm2_display.c
// had it as a bare constructible stub.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_gc.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_value.h>

// ---------------------------------------------------------------------------
// shared helpers
// ---------------------------------------------------------------------------

static Avm2Value s3d_str(Avm2Context* ctx, const char* s)
{ return avm2_string(avm2_string_from_literal(ctx, s)); }

static Avm2Object* s3d_this(Avm2Activation* act)
{
	return (act->this_val.kind == AVM2_VALUE_OBJECT) ? act->this_val.u.obj : NULL;
}

static Avm2Value s3d_noop(Avm2Activation* act)
{ (void) act; return avm2_undefined(); }

static _Noreturn void s3d_throw_2008(Avm2Context* ctx, const char* param)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2008: Parameter %s must be one of the accepted values.",
	                 param);
}

// #2007 is a TypeError everywhere in the corpus (Ruffle's
// make_null_or_undefined_error), never an ArgumentError — see
// avm2/matrix3d_append, tabstop_properties, localconnection, ...
static _Noreturn void s3d_throw_2007(Avm2Context* ctx, const char* param)
{
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #2007: Parameter %s must be non-null.", param);
}

static _Noreturn void s3d_throw_2006(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2006: The supplied index is out of bounds.");
}

// Error #3669 "Bad input size." is a plain Error (Ruffle make_error_3669 uses
// the `error` constructor); #3670/#3671 are ArgumentErrors.
static _Noreturn void s3d_throw_3669(Avm2Context* ctx)
{
	avm2_throw_error(ctx, NULL, "Error #3669: Bad input size.");
}

static Avm2Value s3d_arg(Avm2Activation* act, uint32_t i)
{
	return (i < act->argc) ? act->args[i] : avm2_undefined();
}

// A declared `String` parameter in playerglobal reaches the native body already
// coerced; Ruffle then rejects null through get_string_non_null (#2007).
static const Avm2String* s3d_arg_string(Avm2Activation* act, uint32_t i,
                                        const char* param, const char* dflt)
{
	Avm2Value v = s3d_arg(act, i);
	if (v.kind == AVM2_VALUE_UNDEFINED && dflt != NULL)
		return avm2_string_from_literal(act->ctx, dflt);
	if (v.kind == AVM2_VALUE_NULL) s3d_throw_2007(act->ctx, param);
	return avm2_coerce_to_string(act->ctx, v);
}

static int s3d_str_is(const Avm2String* s, const char* lit)
{
	uint32_t n = (uint32_t) strlen(lit);
	return s != NULL && s->len == n && memcmp(s->utf8, lit, n) == 0;
}

// `value ∈ table` (NULL-terminated, case-sensitive) or ArgumentError #2008.
static void s3d_check_enum(Avm2Context* ctx, const Avm2String* v,
                           const char* const* table, const char* param)
{
	for (uint32_t i = 0; table[i] != NULL; i++)
		if (s3d_str_is(v, table[i])) return;
	s3d_throw_2008(ctx, param);
}

static double s3d_arg_number(Avm2Activation* act, uint32_t i, double dflt)
{
	Avm2Value v = s3d_arg(act, i);
	if (v.kind == AVM2_VALUE_UNDEFINED) return dflt;
	return avm2_coerce_to_number(act->ctx, v);
}

static int32_t s3d_arg_i32(Avm2Activation* act, uint32_t i, int32_t dflt)
{
	Avm2Value v = s3d_arg(act, i);
	if (v.kind == AVM2_VALUE_UNDEFINED) return dflt;
	return avm2_coerce_to_i32(act->ctx, v);
}

static uint32_t s3d_arg_u32(Avm2Activation* act, uint32_t i, uint32_t dflt)
{
	Avm2Value v = s3d_arg(act, i);
	if (v.kind == AVM2_VALUE_UNDEFINED) return dflt;
	return avm2_coerce_to_u32(act->ctx, v);
}

static int s3d_arg_bool(Avm2Activation* act, uint32_t i, int dflt)
{
	Avm2Value v = s3d_arg(act, i);
	if (v.kind == AVM2_VALUE_UNDEFINED) return dflt;
	return avm2_coerce_to_boolean(v) ? 1 : 0;
}

static Avm2Object* s3d_arg_object(Avm2Activation* act, uint32_t i)
{
	Avm2Value v = s3d_arg(act, i);
	return (v.kind == AVM2_VALUE_OBJECT) ? v.u.obj : NULL;
}

// A declared class-typed parameter reaches the native body already coerced, so
// anything that is not an object is the `null` Flash rejects with #2007.
static Avm2Object* s3d_arg_object_non_null(Avm2Activation* act, uint32_t i,
                                           const char* param)
{
	Avm2Object* o = s3d_arg_object(act, i);
	if (o == NULL) s3d_throw_2007(act->ctx, param);
	return o;
}

// The accepted-spelling tables (render/src/backend.rs FromWStr impls).
static const char* const S3D_TRIANGLE_FACE[] =
	{ "none", "back", "front", "frontAndBack", NULL };
static const char* const S3D_PROGRAM_TYPE[] = { "vertex", "fragment", NULL };
static const char* const S3D_COMPARE_MODE[] =
	{ "never", "less", "equal", "lessEqual", "greater", "notEqual",
	  "greaterEqual", "always", NULL };
static const char* const S3D_STENCIL_ACTION[] =
	{ "decrementSaturate", "decrementWrap", "incrementSaturate",
	  "incrementWrap", "invert", "keep", "set", "zero", NULL };
static const char* const S3D_BLEND_FACTOR[] =
	{ "destinationAlpha", "destinationColor", "one",
	  "oneMinusDestinationAlpha", "oneMinusDestinationColor",
	  "oneMinusSourceAlpha", "oneMinusSourceColor", "sourceAlpha",
	  "sourceColor", "zero", NULL };
static const char* const S3D_VERTEX_FORMAT[] =
	{ "float1", "float2", "float3", "float4", "bytes4", NULL };
static const char* const S3D_WRAP_MODE[] =
	{ "clamp", "clamp_u_repeat_v", "repeat", "repeat_u_clamp_v", NULL };
static const char* const S3D_TEXTURE_FILTER[] =
	{ "anisotropic16x", "anisotropic2x", "anisotropic4x", "anisotropic8x",
	  "linear", "nearest", NULL };
static const char* const S3D_TEXTURE_FORMAT[] =
	{ "bgra", "bgraPacked4444", "bgrPacked565", "compressed",
	  "compressedAlpha", "rgbaHalfFloat", NULL };

// ---------------------------------------------------------------------------
// Profiles
// ---------------------------------------------------------------------------
//
// stage_3d.rs:6-27 — a FIXED priority order, highest first. Negotiation picks
// the first entry that appears anywhere in the requested set, so the caller's
// vector order is irrelevant.

static const char* const S3D_PROFILES_HIGH_TO_LOW[] = {
	"standardExtended", "standard", "standardConstrained",
	"baselineExtended", "baseline", "baselineConstrained",
};
#define S3D_PROFILE_COUNT 6

// Rank of a profile string, or -1 if it is not a profile at all. Note the
// accepted-values LIST in checkProfile is alphabetical, but membership is all
// that matters, so one table serves both jobs.
static int s3d_profile_rank(const Avm2String* s)
{
	for (int i = 0; i < S3D_PROFILE_COUNT; i++)
		if (s3d_str_is(s, S3D_PROFILES_HIGH_TO_LOW[i])) return i;
	return -1;
}

// ---------------------------------------------------------------------------
// Instance state
// ---------------------------------------------------------------------------

#define S3D_STATUS_NONE      0
#define S3D_STATUS_REQUESTED 1
#define S3D_STATUS_READY     2

typedef struct Avm2Stage3DExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Object* self;
	Avm2Object* context3d;              // non-NULL only while status == READY
	uint8_t status;
	uint8_t profile;                    // rank into S3D_PROFILES_HIGH_TO_LOW
	uint8_t visible;
	double x, y;
} Avm2Stage3DExt;

typedef struct Avm2Context3DExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Object* stage3d;
	uint8_t profile;
	uint8_t enable_error_checking;
} Avm2Context3DExt;

// TextureBase and its three concrete subclasses share one ext (the display-ext
// "one struct for the whole ladder" idiom). `format` is the *original*
// requested format, which is what the compressed-upload gate inspects.
typedef struct Avm2Texture3DExt
{
	Avm2EventDispatcherExt dispatcher;  // TextureBase extends EventDispatcher
	Avm2Object* context3d;
	uint32_t width, height;
	uint8_t is_cube;
	uint8_t format_bgra;                // "bgra"
	uint8_t format_compressed_alpha;    // "compressedAlpha"
} Avm2Texture3DExt;

typedef struct Avm2Buffer3DExt
{
	Avm2Object* context3d;
	uint32_t count;            // numIndices, or numVertices
	uint32_t data32_per_vertex;
} Avm2Buffer3DExt;

typedef struct Avm2Program3DExt
{
	Avm2Object* context3d;
	uint8_t uploaded;
} Avm2Program3DExt;

static Avm2Class* g_stage3d_class;
static Avm2Class* g_context3d_class;
static Avm2Class* g_program3d_class;
static Avm2Class* g_vertexbuffer_class;
static Avm2Class* g_indexbuffer_class;
static Avm2Class* g_texturebase_class;
static Avm2Class* g_texture_class;
static Avm2Class* g_cubetexture_class;
static Avm2Class* g_rectangletexture_class;
static Avm2Class* g_matrix3d_class;
static Avm2Class* g_vector3d_class;

// The four Stage3Ds the Flash projector always exposes (stage.rs:838-843).
// Created lazily on the first `stage.stage3Ds` read and pinned: their identity
// must be stable for the whole movie (a test adds a listener through one read
// and calls requestContext3D through another), and they outlive any collection.
static Avm2Object* g_stage3ds[4];

static int class_is_a(Avm2Class* cls, Avm2Class* want)
{
	for (Avm2Class* c = cls; c != NULL; c = c->super_class)
		if (c == want) return 1;
	return 0;
}

static void* s3d_ext_of(Avm2Object* o, Avm2Class* want)
{
	if (o == NULL || o->native_ext == NULL || want == NULL) return NULL;
	return class_is_a(o->cls, want) ? o->native_ext : NULL;
}

static Avm2Stage3DExt* stage3d_ext(Avm2Activation* act)
{ return (Avm2Stage3DExt*) s3d_ext_of(s3d_this(act), g_stage3d_class); }

static Avm2Context3DExt* context3d_ext(Avm2Activation* act)
{ return (Avm2Context3DExt*) s3d_ext_of(s3d_this(act), g_context3d_class); }

static Avm2Texture3DExt* texture_ext(Avm2Activation* act)
{ return (Avm2Texture3DExt*) s3d_ext_of(s3d_this(act), g_texturebase_class); }

// ---------------------------------------------------------------------------
// flash.display.Stage3D
// ---------------------------------------------------------------------------

static Avm2Value stage3d_init(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	if (e == NULL) return avm2_undefined();
	e->self = s3d_this(act);
	e->context3d = NULL;
	e->status = S3D_STATUS_NONE;
	e->profile = (uint8_t) (S3D_PROFILE_COUNT - 1);
	e->visible = 1;
	e->x = 0.0;
	e->y = 0.0;
	return avm2_undefined();
}

static Avm2Value stage3d_get_context3d(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	if (e == NULL) return avm2_undefined();
	return (e->status == S3D_STATUS_READY && e->context3d != NULL)
		? avm2_object_value(e->context3d) : avm2_null();
}

static Avm2Value stage3d_get_visible(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	return avm2_bool(e != NULL ? e->visible != 0 : 0);
}

static Avm2Value stage3d_set_visible(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	if (e != NULL) e->visible = (uint8_t) s3d_arg_bool(act, 0, 0);
	return avm2_undefined();
}

// stage_3d.rs set_x/set_y: NaN or outside [-8192, 8191] is ArgumentError
// #2006, and the stored value is left untouched. The lower bound really is
// -8192 (the docs say -8191); avm2/stage3d_x_y grades both edges.
static void stage3d_check_coord(Avm2Context* ctx, double v)
{
	if (isnan(v) || v < -8192.0 || v > 8191.0) s3d_throw_2006(ctx);
}

static Avm2Value stage3d_get_x(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	return avm2_number(e != NULL ? e->x : 0.0);
}

static Avm2Value stage3d_set_x(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	double v = s3d_arg_number(act, 0, 0.0);
	stage3d_check_coord(act->ctx, v);
	if (e != NULL) e->x = v;
	return avm2_undefined();
}

static Avm2Value stage3d_get_y(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	return avm2_number(e != NULL ? e->y : 0.0);
}

static Avm2Value stage3d_set_y(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	double v = s3d_arg_number(act, 0, 0.0);
	stage3d_check_coord(act->ctx, v);
	if (e != NULL) e->y = v;
	return avm2_undefined();
}

static Avm2Value stage3d_request_context3d(Avm2Activation* act)
{
	Avm2Stage3DExt* e = stage3d_ext(act);
	// requestContext3D(context3DRenderMode = "auto", profile = "baseline").
	// The render mode string is never validated (stage_3d.rs ignores it).
	const Avm2String* profile = s3d_arg_string(act, 1, "profile", "baseline");
	int rank = s3d_profile_rank(profile);
	if (rank < 0) s3d_throw_2008(act->ctx, "profile");
	if (e != NULL)
	{
		e->status = S3D_STATUS_REQUESTED;
		e->profile = (uint8_t) rank;
	}
	return avm2_undefined();
}

static Avm2Value stage3d_request_matching_profiles(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Stage3DExt* e = stage3d_ext(act);
	Avm2Value arg = s3d_arg(act, 0);
	// Stage3D.as does `profiles.concat()` first, so a null vector is a
	// method-call-on-null TypeError, not #2008.
	if (arg.kind != AVM2_VALUE_OBJECT)
		avm2_throw_null_or_undefined(ctx, arg, "concat", 6);
	Avm2VectorExt* vec = avm2_vector_ext(arg.u.obj);
	if (vec == NULL) avm2_throw_null_or_undefined(ctx, arg, "concat", 6);

	if (vec->length == 0) s3d_throw_2008(ctx, "profiles");

	int best = -1;
	for (uint32_t i = 0; i < vec->length; i++)
	{
		const Avm2String* s = avm2_coerce_to_string(ctx, vec->elems[i]);
		int rank = s3d_profile_rank(s);
		if (rank < 0) s3d_throw_2008(ctx, "profile");
		if (best < 0 || rank < best) best = rank;
	}
	if (e != NULL)
	{
		e->status = S3D_STATUS_REQUESTED;
		e->profile = (uint8_t) best;
	}
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// Deferred context creation
// ---------------------------------------------------------------------------
//
// frame_lifecycle.rs:104 — after broadcast_frame_exited (and Ruffle's
// LoadManager::run_exit_frame, which is our avm2_loaderinfo_run_exit_frame),
// before the frame's orphan cleanup. avm2/context3d_creation grades exactly
// this slot: ... exitFrame(1), context3DCreate(1), enterFrame(2) ...

Avm2Object* avm2_stage3d_at(Avm2Context* ctx, uint32_t index)
{
	if (index >= 4 || g_stage3d_class == NULL) return NULL;
	if (g_stage3ds[index] == NULL)
	{
		Avm2Value v = avm2_class_construct(ctx, g_stage3d_class, NULL, 0);
		if (v.kind != AVM2_VALUE_OBJECT) return NULL;
		g_stage3ds[index] = v.u.obj;
		avm2_gc_pin(g_stage3ds[index]);
	}
	return g_stage3ds[index];
}

void avm2_stage3d_check_requested(Avm2Context* ctx)
{
	if (g_context3d_class == NULL) return;
	for (uint32_t i = 0; i < 4; i++)
	{
		Avm2Object* s = g_stage3ds[i];
		if (s == NULL) continue;
		Avm2Stage3DExt* e = (Avm2Stage3DExt*) s->native_ext;
		if (e == NULL || e->status != S3D_STATUS_REQUESTED) continue;

		Avm2Value cv = avm2_class_construct(ctx, g_context3d_class, NULL, 0);
		if (cv.kind != AVM2_VALUE_OBJECT) continue;
		Avm2Context3DExt* ce = (Avm2Context3DExt*) cv.u.obj->native_ext;
		if (ce != NULL)
		{
			ce->stage3d = s;
			ce->profile = e->profile;
		}
		// Re-read the ext: constructing the Context3D may have run a GC.
		e = (Avm2Stage3DExt*) s->native_ext;
		if (e == NULL) continue;
		e->context3d = cv.u.obj;
		e->status = S3D_STATUS_READY;

		Avm2Object* ev = avm2_event_new(
			ctx, avm2_string_from_literal(ctx, "context3DCreate"), 0, 0);
		if (ev != NULL) avm2_dispatch_event(ctx, s, ev);
	}
}

// `stage.stage3Ds` (Stage.as:311). A fresh Vector.<Stage3D> per read — the
// four ELEMENTS are the stable singletons, the vector is not (stage.rs:422-439
// rebuilds it too, and avm2/stage_stage3Ds_vector grades `fixed: false`).
static Avm2Value stage_get_stage3ds(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (g_stage3d_class == NULL) return avm2_undefined();
	Avm2Class* vc = avm2_vector_apply(ctx, g_stage3d_class);
	Avm2Object* vec = avm2_vector_new(ctx, vc, 4, 0);
	if (vec == NULL) return avm2_undefined();
	for (uint32_t i = 0; i < 4; i++)
	{
		Avm2Object* s = avm2_stage3d_at(ctx, i);
		if (s != NULL) avm2_vector_set_index(ctx, vec, i, avm2_object_value(s));
	}
	return avm2_object_value(vec);
}

// ---------------------------------------------------------------------------
// flash.display3D.Context3D — a validating no-op surface
// ---------------------------------------------------------------------------

static Avm2Value context3d_get_profile(Avm2Activation* act)
{
	Avm2Context3DExt* e = context3d_ext(act);
	if (e == NULL) return avm2_undefined();
	uint8_t r = e->profile < S3D_PROFILE_COUNT ? e->profile
	                                           : (uint8_t) (S3D_PROFILE_COUNT - 1);
	return s3d_str(act->ctx, S3D_PROFILES_HIGH_TO_LOW[r]);
}

static Avm2Value context3d_get_driver_info(Avm2Activation* act)
{ return s3d_str(act->ctx, "Dummy Ruffle driver"); }

static Avm2Value context3d_get_error_checking(Avm2Activation* act)
{
	Avm2Context3DExt* e = context3d_ext(act);
	return avm2_bool(e != NULL ? e->enable_error_checking != 0 : 0);
}

static Avm2Value context3d_set_error_checking(Avm2Activation* act)
{
	Avm2Context3DExt* e = context3d_ext(act);
	if (e != NULL) e->enable_error_checking = (uint8_t) s3d_arg_bool(act, 0, 0);
	return avm2_undefined();
}

static Avm2Value context3d_get_2048(Avm2Activation* act)
{ (void) act; return avm2_integer(2048); }

static Avm2Value context3d_get_supports_video_texture(Avm2Activation* act)
{ (void) act; return avm2_bool(0); }

static Avm2Value context3d_create_video_texture(Avm2Activation* act)
{ (void) act; return avm2_null(); }

// configureBackBuffer (context_3d.rs:67-132). Below SWF 30, an all-zero call
// is a silent no-op and the range errors are #3669 instead of #3780/#3781 —
// avm2/stage3d_errors and avm2/stage3d_errors_swf_29 are the same test at the
// two versions.
static Avm2Value context3d_configure_back_buffer(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	uint32_t width = s3d_arg_u32(act, 0, 0);
	uint32_t height = s3d_arg_u32(act, 1, 0);
	uint32_t anti_alias = s3d_arg_u32(act, 2, 0);
	int depth_stencil = s3d_arg_bool(act, 3, 1);
	int old_swf = ctx->swf_version < 30;

	if (old_swf && width == 0 && height == 0 && anti_alias == 0 && !depth_stencil)
		return avm2_undefined();

	if (width < 32 || width > 16384)
	{
		if (old_swf) s3d_throw_3669(ctx);
		avm2_throw_error(ctx, NULL, "Error #3780: Requested width of backbuffer "
		                            "is not in allowed range 32 to 16384.");
	}
	if (height < 32 || height > 16384)
	{
		if (old_swf) s3d_throw_3669(ctx);
		avm2_throw_error(ctx, NULL, "Error #3781: Requested height of backbuffer "
		                            "is not in allowed range 32 to 16384.");
	}
	return avm2_undefined();
}

static Avm2Value context3d_set_culling(Avm2Activation* act)
{
	s3d_check_enum(act->ctx, s3d_arg_string(act, 0, "triangleFaceToCull", NULL),
	               S3D_TRIANGLE_FACE, "triangleFaceToCull");
	return avm2_undefined();
}

static Avm2Value context3d_set_depth_test(Avm2Activation* act)
{
	s3d_check_enum(act->ctx, s3d_arg_string(act, 1, "passCompareMode", NULL),
	               S3D_COMPARE_MODE, "passCompareMode");
	return avm2_undefined();
}

static Avm2Value context3d_set_blend_factors(Avm2Activation* act)
{
	s3d_check_enum(act->ctx, s3d_arg_string(act, 0, "sourceFactor", NULL),
	               S3D_BLEND_FACTOR, "sourceFactor");
	s3d_check_enum(act->ctx, s3d_arg_string(act, 1, "destinationFactor", NULL),
	               S3D_BLEND_FACTOR, "destinationFactor");
	return avm2_undefined();
}

// setStencilActions's five parameters all default (frontAndBack/always/keep×3)
// and are validated left to right, each naming its own parameter.
static Avm2Value context3d_set_stencil_actions(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	s3d_check_enum(ctx, s3d_arg_string(act, 0, "triangleFace", "frontAndBack"),
	               S3D_TRIANGLE_FACE, "triangleFace");
	s3d_check_enum(ctx, s3d_arg_string(act, 1, "compareMode", "always"),
	               S3D_COMPARE_MODE, "compareMode");
	s3d_check_enum(ctx, s3d_arg_string(act, 2, "actionOnBothPass", "keep"),
	               S3D_STENCIL_ACTION, "actionOnBothPass");
	s3d_check_enum(ctx, s3d_arg_string(act, 3, "actionOnDepthFail", "keep"),
	               S3D_STENCIL_ACTION, "actionOnDepthFail");
	s3d_check_enum(ctx, s3d_arg_string(act, 4, "actionOnDepthPassStencilFail",
	                                   "keep"),
	               S3D_STENCIL_ACTION, "actionOnDepthPassStencilFail");
	return avm2_undefined();
}

static Avm2Value context3d_set_sampler_state_at(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	s3d_check_enum(ctx, s3d_arg_string(act, 1, "wrap", NULL),
	               S3D_WRAP_MODE, "wrap");
	s3d_check_enum(ctx, s3d_arg_string(act, 2, "filter", NULL),
	               S3D_TEXTURE_FILTER, "filter");
	// mipfilter is read but never validated (context_3d.rs:772).
	(void) s3d_arg_string(act, 3, "mipfilter", NULL);
	return avm2_undefined();
}

static Avm2Value context3d_set_program_constants_from_matrix(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	s3d_check_enum(ctx, s3d_arg_string(act, 0, "programType", NULL),
	               S3D_PROGRAM_TYPE, "programType");
	if (s3d_arg_object(act, 2) == NULL) s3d_throw_2007(ctx, "matrix");
	return avm2_undefined();
}

static Avm2Value context3d_set_program_constants_from_vector(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	s3d_check_enum(ctx, s3d_arg_string(act, 0, "programType", NULL),
	               S3D_PROGRAM_TYPE, "programType");
	Avm2Object* vo = s3d_arg_object(act, 2);
	if (vo == NULL) s3d_throw_2007(ctx, "vector");
	Avm2VectorExt* vec = avm2_vector_ext(vo);
	int32_t num_registers = s3d_arg_i32(act, 3, -1);
	// numRegisters == -1 means "use the whole vector"; anything else demands
	// 4 floats per register (context_3d.rs:337-347).
	if (num_registers != -1)
	{
		uint32_t required = (uint32_t) num_registers * 4u;
		if (vec == NULL || vec->length < required) s3d_throw_3669(ctx);
	}
	return avm2_undefined();
}

// Stage3D reads raw little-endian floats out of the ByteArray regardless of
// its `endian` setting, and (unlike the Vector overload) a negative
// numRegisters is invalid rather than "use all" (context_3d.rs:360-404).
static Avm2Value context3d_set_program_constants_from_byte_array(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	s3d_check_enum(ctx, s3d_arg_string(act, 0, "programType", NULL),
	               S3D_PROGRAM_TYPE, "programType");
	int32_t num_registers = s3d_arg_i32(act, 2, 0);
	Avm2Value dv = s3d_arg(act, 3);
	if (dv.kind != AVM2_VALUE_OBJECT) s3d_throw_2007(ctx, "data");
	Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(dv);
	uint32_t offset = s3d_arg_u32(act, 4, 0);

	if (num_registers < 0) s3d_throw_3669(ctx);
	uint32_t len = ba != NULL ? ba->len : 0;
	if (offset > len) s3d_throw_3669(ctx);
	uint32_t whole_floats = (len - offset) / 4u;
	if (whole_floats < (uint32_t) num_registers * 4u) s3d_throw_3669(ctx);
	return avm2_undefined();
}

static Avm2Value context3d_set_scissor_rectangle(Avm2Activation* act)
{
	// A null rectangle turns scissoring off; a zero-width/height one is
	// ignored by Stage3D (stage3d/scissor_rectangle_invalid). Either way
	// nothing is validated.
	(void) s3d_arg(act, 0);
	return avm2_undefined();
}

static Avm2Value context3d_clear(Avm2Activation* act)
{
	// All seven parameters are declared numeric, so they are already coerced;
	// there is nothing left to validate.
	(void) act;
	return avm2_undefined();
}

static Avm2Object* s3d_new_child(Avm2Activation* act, Avm2Class* cls)
{
	Avm2Value v = avm2_class_construct(act->ctx, cls, NULL, 0);
	return (v.kind == AVM2_VALUE_OBJECT) ? v.u.obj : NULL;
}

static Avm2Value context3d_create_index_buffer(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	uint32_t num_indices = s3d_arg_u32(act, 0, 0);
	if (num_indices == 0)
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #3671: Buffer has zero size.");
	Avm2Object* o = s3d_new_child(act, g_indexbuffer_class);
	if (o == NULL) return avm2_null();
	Avm2Buffer3DExt* e = (Avm2Buffer3DExt*) o->native_ext;
	if (e != NULL) { e->context3d = s3d_this(act); e->count = num_indices; }
	return avm2_object_value(o);
}

static Avm2Value context3d_create_vertex_buffer(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	uint32_t num_vertices = s3d_arg_u32(act, 0, 0);
	uint32_t per_vertex = s3d_arg_u32(act, 1, 0);
	if (per_vertex > 64)
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #3670: Buffer too big.");
	if (per_vertex == 0)
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #3671: Buffer has zero size.");
	Avm2Object* o = s3d_new_child(act, g_vertexbuffer_class);
	if (o == NULL) return avm2_null();
	Avm2Buffer3DExt* e = (Avm2Buffer3DExt*) o->native_ext;
	if (e != NULL)
	{
		e->context3d = s3d_this(act);
		e->count = num_vertices;
		e->data32_per_vertex = per_vertex;
	}
	return avm2_object_value(o);
}

static Avm2Value context3d_create_program(Avm2Activation* act)
{
	Avm2Object* o = s3d_new_child(act, g_program3d_class);
	if (o == NULL) return avm2_null();
	Avm2Program3DExt* e = (Avm2Program3DExt*) o->native_ext;
	if (e != NULL) e->context3d = s3d_this(act);
	return avm2_object_value(o);
}

// setVertexBufferAt only checks the format string when the buffer is NON-null
// (context_3d.rs:146) — avm2/stage3d_errors passes garbage with a null buffer
// and expects silence.
static Avm2Value context3d_set_vertex_buffer_at(Avm2Activation* act)
{
	if (s3d_arg_object(act, 1) != NULL)
	{
		s3d_check_enum(act->ctx,
		               s3d_arg_string(act, 3, "vertexStreamFormat", "float4"),
		               S3D_VERTEX_FORMAT, "vertexStreamFormat");
	}
	return avm2_undefined();
}

static Avm2Value context3d_draw_triangles(Avm2Activation* act)
{
	if (s3d_arg_object(act, 0) == NULL) s3d_throw_2007(act->ctx, "indexBuffer");
	return avm2_undefined();
}

static Avm2Object* s3d_make_texture(Avm2Activation* act, Avm2Class* cls,
                                    uint32_t w, uint32_t h,
                                    const Avm2String* format, int is_cube)
{
	Avm2Object* o = s3d_new_child(act, cls);
	if (o == NULL) return NULL;
	Avm2Texture3DExt* e = (Avm2Texture3DExt*) o->native_ext;
	if (e != NULL)
	{
		e->context3d = s3d_this(act);
		e->width = w;
		e->height = h;
		e->is_cube = (uint8_t) (is_cube != 0);
		e->format_bgra = (uint8_t) s3d_str_is(format, "bgra");
		e->format_compressed_alpha =
			(uint8_t) s3d_str_is(format, "compressedAlpha");
	}
	return o;
}

static Avm2Value context3d_create_texture(Avm2Activation* act)
{
	uint32_t w = (uint32_t) s3d_arg_i32(act, 0, 0);
	uint32_t h = (uint32_t) s3d_arg_i32(act, 1, 0);
	const Avm2String* fmt = s3d_arg_string(act, 2, "textureFormat", NULL);
	s3d_check_enum(act->ctx, fmt, S3D_TEXTURE_FORMAT, "textureFormat");
	Avm2Object* o = s3d_make_texture(act, g_texture_class, w, h, fmt, 0);
	return o != NULL ? avm2_object_value(o) : avm2_null();
}

static Avm2Value context3d_create_rectangle_texture(Avm2Activation* act)
{
	uint32_t w = (uint32_t) s3d_arg_i32(act, 0, 0);
	uint32_t h = (uint32_t) s3d_arg_i32(act, 1, 0);
	const Avm2String* fmt = s3d_arg_string(act, 2, "textureFormat", NULL);
	s3d_check_enum(act->ctx, fmt, S3D_TEXTURE_FORMAT, "textureFormat");
	Avm2Object* o =
		s3d_make_texture(act, g_rectangletexture_class, w, h, fmt, 0);
	return o != NULL ? avm2_object_value(o) : avm2_null();
}

static Avm2Value context3d_create_cube_texture(Avm2Activation* act)
{
	uint32_t size = (uint32_t) s3d_arg_i32(act, 0, 0);
	const Avm2String* fmt = s3d_arg_string(act, 1, "textureFormat", NULL);
	s3d_check_enum(act->ctx, fmt, S3D_TEXTURE_FORMAT, "textureFormat");
	Avm2Object* o =
		s3d_make_texture(act, g_cubetexture_class, size, size, fmt, 1);
	return o != NULL ? avm2_object_value(o) : avm2_null();
}

// setRenderToTexture's surfaceSelector bound depends on the texture kind
// (context_3d.rs:632-645).
static Avm2Value context3d_set_render_to_texture(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* t = s3d_arg_object(act, 0);
	if (t == NULL) s3d_throw_2007(ctx, "texture");
	uint32_t surface = s3d_arg_u32(act, 3, 0);
	if (g_cubetexture_class != NULL && class_is_a(t->cls, g_cubetexture_class))
	{
		if (surface > 5)
			avm2_throw_error(ctx, ctx->builtins.argument_error_class,
			                 "Error #3772: Surface selector out of bounds for "
			                 "cube texture, must be 0-5.");
	}
	else if (g_rectangletexture_class != NULL
	         && class_is_a(t->cls, g_rectangletexture_class))
	{
		if (surface != 0)
			avm2_throw_error(ctx, ctx->builtins.argument_error_class,
			                 "Error #3773: Surface selector must be 0 for "
			                 "rectangle textures.");
	}
	else if (surface != 0)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #3771: Surface selector out of bounds for "
		                 "2D texture, must be 0.");
	}
	return avm2_undefined();
}

static Avm2Value context3d_dispose(Avm2Activation* act)
{
	Avm2Context3DExt* e = context3d_ext(act);
	if (e == NULL || e->stage3d == NULL) return avm2_undefined();
	Avm2Stage3DExt* se = (Avm2Stage3DExt*) e->stage3d->native_ext;
	if (se != NULL)
	{
		// dispose() clears the Stage3D's context3D unconditionally — the
		// `recreate` flag does NOT re-request one (context_3d.rs:832-845,
		// graded by stage3d/request_profiles' "After dispose: null").
		se->context3d = NULL;
		se->status = S3D_STATUS_NONE;
	}
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// Tranche S2 — the AGAL bytecode validator behind Program3D.upload
// ---------------------------------------------------------------------------

typedef enum
{
	AGAL_OK = 0,
	AGAL_EMPTY_PROGRAM,
	AGAL_INVALID_HEADER,
	AGAL_READ_ERROR,
	AGAL_INVALID_VERSION,
	AGAL_INVALID_SHADER_TYPE,
	AGAL_INVALID_OPCODE,
	AGAL_READ_OUTPUT_REGISTER,
	AGAL_SAMPLER_AS_SOURCE,
	AGAL_FRAGREG_AS_SOURCE,
	AGAL_INDIRECT_NOT_ALLOWED,
	AGAL_INDIRECT_ONLY_CONSTANTS,
	AGAL_WRITE_CONSTANT,
	AGAL_WRITE_ATTRIBUTE,
	AGAL_WRITE_SAMPLER,
	AGAL_WRITE_FRAGMENT,
	AGAL_SAMPLER_CONFIG_MISMATCH,
} AgalErrKind;

typedef struct AgalErr
{
	AgalErrKind kind;
	uint32_t value;      // InvalidOpcode only
	uint32_t token;      // 1-based token index
	int operand;         // 1 or 2, for the source-operand errors
	int is_fragment;
} AgalErr;

// types.rs RegisterType
#define AGAL_REG_ATTRIBUTE 0
#define AGAL_REG_CONSTANT  1
#define AGAL_REG_TEMPORARY 2
#define AGAL_REG_OUTPUT    3
#define AGAL_REG_VARYING   4
#define AGAL_REG_SAMPLER   5
#define AGAL_REG_FRAGMENT  6

static uint32_t agal_u32le(const uint8_t* p)
{
	return (uint32_t) p[0] | ((uint32_t) p[1] << 8) | ((uint32_t) p[2] << 16)
	       | ((uint32_t) p[3] << 24);
}

static uint64_t agal_u64le(const uint8_t* p)
{
	return (uint64_t) agal_u32le(p) | ((uint64_t) agal_u32le(p + 4) << 32);
}

// types.rs Opcode: 0x00..0x21 contiguous, then 0x27..0x2a, 0x2c, 0x2d.
static int agal_opcode_valid(uint32_t op)
{
	if (op <= 0x21) return 1;
	if (op >= 0x27 && op <= 0x2a) return 1;
	if (op == 0x2c || op == 0x2d) return 1;
	return 0;
}

#define AGAL_OP_KIL 0x27
#define AGAL_OP_TEX 0x28

static int agal_has_dest(uint32_t op)
{
	// Control flow tokens carry zeroed dest/source words, so they skip
	// validation entirely (builder.rs:325-334).
	return !(op == AGAL_OP_KIL || (op >= 0x1c && op <= 0x21));
}

static int agal_has_sources(uint32_t op)
{ return !(op == 0x20 || op == 0x21); }  // Els / Eif

static void agal_fail(AgalErr* err, AgalErrKind kind, uint32_t token,
                      int operand, int is_fragment, uint32_t value)
{
	err->kind = kind;
	err->token = token;
	err->operand = operand;
	err->is_fragment = is_fragment;
	err->value = value;
}

// Validate one source operand. Returns 0 on success.
static int agal_check_source(uint64_t src, uint32_t token, int operand,
                            int is_fragment, AgalErr* err)
{
	uint32_t reg_type = (uint32_t) ((src >> 32) & 0xF);
	int indirect = (int) ((src >> 63) & 0x1);
	// Ruffle unwraps RegisterType::from_u16 here and would panic on 7..15; we
	// treat an unknown register type as unvalidatable rather than inventing an
	// error for it.
	if (reg_type == AGAL_REG_OUTPUT)
	{
		agal_fail(err, AGAL_READ_OUTPUT_REGISTER, token, operand, is_fragment, 0);
		return 1;
	}
	if (reg_type == AGAL_REG_SAMPLER)
	{
		agal_fail(err, AGAL_SAMPLER_AS_SOURCE, token, operand, is_fragment, 0);
		return 1;
	}
	if (reg_type == AGAL_REG_FRAGMENT)
	{
		agal_fail(err, AGAL_FRAGREG_AS_SOURCE, token, operand, is_fragment, 0);
		return 1;
	}
	if (indirect)
	{
		if (is_fragment)
		{
			agal_fail(err, AGAL_INDIRECT_NOT_ALLOWED, token, operand,
			          is_fragment, 0);
			return 1;
		}
		if (reg_type != AGAL_REG_CONSTANT)
		{
			agal_fail(err, AGAL_INDIRECT_ONLY_CONSTANTS, token, operand,
			          is_fragment, 0);
			return 1;
		}
	}
	return 0;
}

// naga_agal::parse_bytecode + (fragment only) extract_sampler_configs.
// `check_samplers` mirrors ShaderPairAgal::new, which runs the sampler-config
// pass on the FRAGMENT program only.
static int agal_validate(const uint8_t* b, uint32_t len, int check_samplers,
                         AgalErr* err)
{
	err->kind = AGAL_OK;
	if (len == 0)
	{
		agal_fail(err, AGAL_EMPTY_PROGRAM, 0, 0, 0, 0);
		return 1;
	}
	if (len < 7)
	{
		// read_exact of the 7-byte header failed -> io::Error -> ReadError.
		agal_fail(err, AGAL_READ_ERROR, 0, 0, 0, 0);
		return 1;
	}
	if (b[0] != 0xa0)
	{
		agal_fail(err, AGAL_INVALID_HEADER, 0, 0, 0, 0);
		return 1;
	}
	uint32_t version = agal_u32le(b + 1);
	if (version != 1 && version != 2)
	{
		agal_fail(err, AGAL_INVALID_VERSION, 0, 0, 0, 0);
		return 1;
	}
	if (b[5] != 0xa1)
	{
		agal_fail(err, AGAL_INVALID_HEADER, 0, 0, 0, 0);
		return 1;
	}
	int is_fragment;
	if (b[6] == 0x00) is_fragment = 0;
	else if (b[6] == 0x01) is_fragment = 1;
	else
	{
		agal_fail(err, AGAL_INVALID_SHADER_TYPE, 0, 0, 0, 0);
		return 1;
	}

	// Sampler configs are keyed by sampler register number (8 of them); the
	// stored triple is (wrapping, filter, mipmap).
	int have_cfg[8];
	uint32_t cfg[8];
	memset(have_cfg, 0, sizeof(have_cfg));
	memset(cfg, 0, sizeof(cfg));

	uint32_t pos = 7;
	uint32_t token = 0;
	while (pos < len)
	{
		if (len - pos < 24)
		{
			agal_fail(err, AGAL_READ_ERROR, 0, 0, 0, 0);
			return 1;
		}
		const uint8_t* t = b + pos;
		pos += 24;
		token++;

		uint32_t op = agal_u32le(t);
		if (!agal_opcode_valid(op))
		{
			agal_fail(err, AGAL_INVALID_OPCODE, token, 0, is_fragment, op);
			return 1;
		}

		if (agal_has_dest(op))
		{
			uint32_t dest_type = (agal_u32le(t + 4) >> 24) & 0xF;
			AgalErrKind k = AGAL_OK;
			if (dest_type == AGAL_REG_CONSTANT) k = AGAL_WRITE_CONSTANT;
			else if (dest_type == AGAL_REG_ATTRIBUTE) k = AGAL_WRITE_ATTRIBUTE;
			else if (dest_type == AGAL_REG_SAMPLER) k = AGAL_WRITE_SAMPLER;
			else if (dest_type == AGAL_REG_FRAGMENT) k = AGAL_WRITE_FRAGMENT;
			if (k != AGAL_OK)
			{
				agal_fail(err, k, token, 0, is_fragment, 0);
				return 1;
			}
		}

		if (agal_has_sources(op))
		{
			if (agal_check_source(agal_u64le(t + 8), token, 1, is_fragment, err))
				return 1;
			// The second word is a SamplerField for `tex`, and `kil` has no
			// second source at all (builder.rs:369-374).
			if (op != AGAL_OP_TEX && op != AGAL_OP_KIL)
			{
				if (agal_check_source(agal_u64le(t + 16), token, 2, is_fragment,
				                      err))
					return 1;
			}
		}

		if (check_samplers && op == AGAL_OP_TEX)
		{
			uint64_t s = agal_u64le(t + 16);
			uint32_t reg_num = (uint32_t) (s & 0xFFFF);
			int ignore_sampler = (((uint32_t) ((s >> 48) & 0xF)) & 0x4) != 0;
			if (!ignore_sampler && reg_num < 8)
			{
				uint32_t wrapping = (uint32_t) ((s >> 52) & 0xF);
				uint32_t mipmap = (uint32_t) ((s >> 56) & 0xF);
				uint32_t filter = (uint32_t) ((s >> 60) & 0xF);
				uint32_t triple = wrapping | (filter << 8) | (mipmap << 16);
				if (!have_cfg[reg_num])
				{
					have_cfg[reg_num] = 1;
					cfg[reg_num] = triple;
				}
				else if (cfg[reg_num] != triple)
				{
					agal_fail(err, AGAL_SAMPLER_CONFIG_MISMATCH, token, 0,
					          is_fragment, 0);
					return 1;
				}
			}
		}
	}
	return 0;
}

// error.rs::make_agal_upload_error. The EmptyProgram / InvalidHeader /
// ReadError arms are ArgumentErrors; everything else is a plain Error.
static _Noreturn void agal_throw(Avm2Context* ctx, const AgalErr* e)
{
	const char* st = e->is_fragment ? "fragment" : "vertex";
	Avm2Class* ae = ctx->builtins.argument_error_class;
	switch (e->kind)
	{
	case AGAL_EMPTY_PROGRAM:
		avm2_throw_error(ctx, ae, "Error #3615: AGAL validation failed: Program "
		                          "size below minimum length for  program.");
	case AGAL_INVALID_HEADER:
	case AGAL_READ_ERROR:
		avm2_throw_error(ctx, ae, "Error #3612: Programs must be in little "
		                          "endian format.");
	case AGAL_INVALID_VERSION:
	case AGAL_INVALID_SHADER_TYPE:
		// Both hardcode "fragment" in Ruffle, regardless of the real header.
		avm2_throw_error(ctx, NULL, "Error #3615: AGAL validation failed: Program "
		                            "size below minimum length for fragment "
		                            "program.");
	case AGAL_INVALID_OPCODE:
		avm2_throw_error(ctx, NULL, "Error #3620: AGAL validation failed: Invalid "
		                            "opcode, value out of range: %u at token %u "
		                            "of %s program.",
		                 (unsigned) e->value, (unsigned) e->token, st);
	case AGAL_READ_OUTPUT_REGISTER:
		avm2_throw_error(ctx, NULL, "Error #3646: AGAL validation failed: Can not "
		                            "read from output register for source operand "
		                            "%d at token %u of %s program.",
		                 e->operand, (unsigned) e->token, st);
	case AGAL_SAMPLER_AS_SOURCE:
		avm2_throw_error(ctx, NULL, "Error #3638: AGAL validation failed: Sampler "
		                            "register only allowed as second operand in "
		                            "texture instructions for source operand %d "
		                            "at token %u of %s program.",
		                 e->operand, (unsigned) e->token, st);
	case AGAL_FRAGREG_AS_SOURCE:
		avm2_throw_error(ctx, NULL, "Error #3749: AGAL validation failed: Depth "
		                            "output register index out of bounds for "
		                            "source operand %d at token %u of %s program.",
		                 e->operand, (unsigned) e->token, st);
	case AGAL_INDIRECT_NOT_ALLOWED:
		avm2_throw_error(ctx, NULL, "Error #3639: AGAL validation failed: Indirect "
		                            "addressing only allowed in vertex programs "
		                            "for source operand %d at token %u of %s "
		                            "program.",
		                 e->operand, (unsigned) e->token, st);
	case AGAL_INDIRECT_ONLY_CONSTANTS:
		avm2_throw_error(ctx, NULL, "Error #3640: AGAL validation failed: Indirect "
		                            "addressing only allowed into constant "
		                            "registers for source operand %d at token %u "
		                            "of %s program.",
		                 e->operand, (unsigned) e->token, st);
	case AGAL_WRITE_CONSTANT:
		avm2_throw_error(ctx, NULL, "Error #3652: AGAL validation failed: Constant "
		                            "registers can not be written to for "
		                            "destination operand at token %u of %s "
		                            "program.",
		                 (unsigned) e->token, st);
	case AGAL_WRITE_ATTRIBUTE:
		avm2_throw_error(ctx, NULL, "Error #3651: AGAL validation failed: Attribute "
		                            "registers can not be written to for "
		                            "destination operand at token %u of %s "
		                            "program.",
		                 (unsigned) e->token, st);
	case AGAL_WRITE_SAMPLER:
		avm2_throw_error(ctx, NULL, "Error #3649: AGAL validation failed: Sampler "
		                            "registers can not be written to for "
		                            "destination operand at token %u of %s "
		                            "program.",
		                 (unsigned) e->token, st);
	case AGAL_WRITE_FRAGMENT:
		avm2_throw_error(ctx, NULL, "Error #3749: AGAL validation failed: Depth "
		                            "output register index out of bounds for "
		                            "destination operand at token %u of %s "
		                            "program.",
		                 (unsigned) e->token, st);
	case AGAL_SAMPLER_CONFIG_MISMATCH:
	default:
		avm2_throw_error(ctx, NULL, "Error #3696: AGAL validation failed: Second "
		                            "use of sampler register needs to specify the "
		                            "exact same properties. At token %u of %s "
		                            "program.",
		                 (unsigned) e->token, st);
	}
}

// Program3D.upload(vertexProgram, fragmentProgram). ShaderPairAgal::new parses
// the vertex program, then the fragment program, then runs the sampler-config
// pass on the fragment one — so a bad vertex program masks a bad fragment one.
static Avm2Value program3d_upload(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value vv = s3d_arg(act, 0);
	Avm2Value fv = s3d_arg(act, 1);
	if (vv.kind != AVM2_VALUE_OBJECT) s3d_throw_2007(ctx, "source_vertex");
	if (fv.kind != AVM2_VALUE_OBJECT) s3d_throw_2007(ctx, "source_fragment");
	Avm2ByteArrayExt* vba = avm2_bytearray_ext_of(vv);
	Avm2ByteArrayExt* fba = avm2_bytearray_ext_of(fv);

	AgalErr err;
	if (agal_validate(vba != NULL ? vba->bytes : NULL,
	                  vba != NULL ? vba->len : 0, 0, &err))
		agal_throw(ctx, &err);
	if (agal_validate(fba != NULL ? fba->bytes : NULL,
	                  fba != NULL ? fba->len : 0, 1, &err))
		agal_throw(ctx, &err);

	Avm2Program3DExt* e =
		(Avm2Program3DExt*) s3d_ext_of(s3d_this(act), g_program3d_class);
	if (e != NULL) e->uploaded = 1;
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// Textures — the ATF compressed-upload gate
// ---------------------------------------------------------------------------
//
// render/src/atf.rs ATFTexture::from_bytes. Only width/height/cubemap are
// needed: the two error checks that avm2/stage3d_errors_atf grades happen
// before any pixel data is touched (atf_jpegxr.rs:24-33), so no JPEG-XR
// decoder is involved.
static int atf_parse_header(const uint8_t* b, uint32_t len,
                            uint32_t* out_w, uint32_t* out_h, int* out_cube)
{
	if (b == NULL || len < 3 || memcmp(b, "ATF", 3) != 0) return 0;
	uint32_t p = 3;
	if (len - p < 4) return 0;
	if (b[p + 3] == 0xFF)
	{
		// Extended header: 5 bytes (incl. version) then a u32 length.
		if (len - p < 9) return 0;
		p += 9;
	}
	else
	{
		// Legacy header: a uint24 length.
		if (len - p < 3) return 0;
		p += 3;
	}
	if (len - p < 3) return 0;
	uint8_t tdata = b[p];
	*out_cube = (tdata >> 7) != 0;
	uint8_t wexp = b[p + 1];
	uint8_t hexp = b[p + 2];
	if (wexp > 31 || hexp > 31) return 0;
	*out_w = 1u << wexp;
	*out_h = 1u << hexp;
	return 1;
}

static Avm2Value texture_upload_compressed(Avm2Activation* act, int is_cube)
{
	Avm2Context* ctx = act->ctx;
	Avm2Texture3DExt* te = texture_ext(act);
	Avm2Value dv = s3d_arg(act, 0);
	if (dv.kind != AVM2_VALUE_OBJECT) s3d_throw_2007(ctx, "data");
	Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(dv);
	uint32_t offset = s3d_arg_u32(act, 1, 0);
	if (te == NULL || ba == NULL) return avm2_undefined();

	// Format gate (texture.rs:81-95 / cube_texture.rs:69-76): a Texture
	// accepts bgra + compressedAlpha, a CubeTexture only bgra. Anything else
	// is a silent stub in Ruffle.
	int format_ok = is_cube
		? te->format_bgra
		: (te->format_bgra || te->format_compressed_alpha);
	if (!format_ok) return avm2_undefined();

	if (offset >= ba->len) return avm2_undefined();
	uint32_t w = 0, h = 0;
	int cube = 0;
	if (!atf_parse_header(ba->bytes + offset, ba->len - offset, &w, &h, &cube))
		return avm2_undefined();

	if (w != te->width || h != te->height)
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #3679: Texture size does not match.");
	if ((is_cube != 0) != (cube != 0))
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #3675: Texture format mismatch.");
	return avm2_undefined();
}

static Avm2Value texture_upload_compressed_2d(Avm2Activation* act)
{ return texture_upload_compressed(act, 0); }

static Avm2Value texture_upload_compressed_cube(Avm2Activation* act)
{ return texture_upload_compressed(act, 1); }

// ---------------------------------------------------------------------------
// flash.geom.Matrix3D
// ---------------------------------------------------------------------------
//
// Column-major 4x4, exactly as Flash's `rawData` orders it. The only reason
// the Stage3D corpus needs it is that setProgramConstantsFromMatrix takes one
// and avm2/stage3d_blend builds one with appendScale/appendTranslation, but a
// half-class is worse than none for the render-only 3D tests, so the usual
// append/prepend/invert set is here too.

typedef struct Avm2Matrix3DExt { double m[16]; } Avm2Matrix3DExt;

// Vector3D keeps x/y/z as dynamic props (avm2_display.c geom_vector3d_init).
static double m3d_component(Avm2Context* ctx, Avm2Object* v, const char* name)
{
	if (v == NULL) return 0.0;
	Avm2Value got = avm2_get_public_property(ctx, avm2_object_value(v), name, 1,
	                                         NULL);
	return avm2_coerce_to_number(ctx, got);
}

static Avm2Matrix3DExt* matrix3d_ext_of(Avm2Object* o)
{ return (Avm2Matrix3DExt*) s3d_ext_of(o, g_matrix3d_class); }

static Avm2Matrix3DExt* matrix3d_ext(Avm2Activation* act)
{ return matrix3d_ext_of(s3d_this(act)); }

static void m3d_identity(double* m)
{
	memset(m, 0, sizeof(double) * 16);
	m[0] = m[5] = m[10] = m[15] = 1.0;
}

// out = a then b ("append b"): column-major, so out = b * a.
static void m3d_mul(double* out, const double* a, const double* b)
{
	double r[16];
	for (int c = 0; c < 4; c++)
	{
		for (int row = 0; row < 4; row++)
		{
			double s = 0.0;
			for (int k = 0; k < 4; k++) s += b[k * 4 + row] * a[c * 4 + k];
			r[c * 4 + row] = s;
		}
	}
	memcpy(out, r, sizeof(r));
}

static Avm2Value matrix3d_init(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	if (e == NULL) return avm2_undefined();
	m3d_identity(e->m);
	Avm2Object* v = s3d_arg_object(act, 0);
	Avm2VectorExt* src = v != NULL ? avm2_vector_ext(v) : NULL;
	if (src != NULL && src->length >= 16)
	{
		for (int i = 0; i < 16; i++)
			e->m[i] = avm2_coerce_to_number(act->ctx, src->elems[i]);
	}
	return avm2_undefined();
}

static Avm2Value matrix3d_get_raw_data(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	if (e == NULL) return avm2_null();
	Avm2Object* vec = avm2_vector_new(ctx, ctx->builtins.vector_double_class,
	                                  16, 0);
	if (vec == NULL) return avm2_null();
	for (uint32_t i = 0; i < 16; i++)
		avm2_vector_set_index(ctx, vec, i, avm2_number(e->m[i]));
	return avm2_object_value(vec);
}

static Avm2Value matrix3d_set_raw_data(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Object* v = s3d_arg_object(act, 0);
	Avm2VectorExt* src = v != NULL ? avm2_vector_ext(v) : NULL;
	if (e != NULL && src != NULL && src->length >= 16)
	{
		for (int i = 0; i < 16; i++)
			e->m[i] = avm2_coerce_to_number(act->ctx, src->elems[i]);
	}
	return avm2_undefined();
}

// flash.geom.Transform's matrix3D surface lives in avm2_display.c, but the
// Matrix3D class is minted HERE (Stage3D needs it first), so minting/reading
// one from there goes through this pair. `raw` is the column-major rawData.
Avm2Object* avm2_geom_matrix3d_new(Avm2Context* ctx, const double* raw)
{
	if (g_matrix3d_class == NULL) return NULL;
	Avm2Value v = avm2_class_construct(ctx, g_matrix3d_class, NULL, 0);
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL) return NULL;
	Avm2Matrix3DExt* e = matrix3d_ext_of(v.u.obj);
	if (e != NULL && raw != NULL) memcpy(e->m, raw, sizeof(double) * 16);
	return v.u.obj;
}

int avm2_geom_matrix3d_read(Avm2Object* o, double* out)
{
	Avm2Matrix3DExt* e = matrix3d_ext_of(o);
	if (e == NULL || out == NULL) return 0;
	memcpy(out, e->m, sizeof(double) * 16);
	return 1;
}

static Avm2Value matrix3d_identity(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	if (e != NULL) m3d_identity(e->m);
	return avm2_undefined();
}

static Avm2Value matrix3d_clone(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Object* o = s3d_new_child(act, g_matrix3d_class);
	if (o == NULL) return avm2_null();
	Avm2Matrix3DExt* ne = matrix3d_ext_of(o);
	if (ne != NULL && e != NULL) memcpy(ne->m, e->m, sizeof(ne->m));
	return avm2_object_value(o);
}

static Avm2Value matrix3d_copy_from(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Matrix3DExt* src = matrix3d_ext_of(s3d_arg_object(act, 0));
	if (e != NULL && src != NULL) memcpy(e->m, src->m, sizeof(e->m));
	return avm2_undefined();
}

static Avm2Value matrix3d_copy_raw_data_from(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Object* v = s3d_arg_object_non_null(act, 0, "source");
	Avm2VectorExt* src = v != NULL ? avm2_vector_ext(v) : NULL;
	uint32_t index = s3d_arg_u32(act, 1, 0);
	int transpose = s3d_arg_bool(act, 2, 0);
	if (e == NULL || src == NULL) return avm2_undefined();
	// A source that cannot supply all 16 entries from `index` on is #2004, and
	// the matrix is left untouched — Flash does not pad from identity. (The
	// Matrix3D(Vector) constructor and the rawData setter DO silently
	// identity-fill; see avm2/matrix3d "Too short:".)
	if ((uint64_t) index + 16 > (uint64_t) src->length)
	{
		avm2_throw_error(act->ctx, act->ctx->builtins.argument_error_class,
		                 "Error #2004: One of the parameters is invalid.");
	}
	double tmp[16];
	m3d_identity(tmp);
	for (uint32_t i = 0; i < 16; i++)
	{
		if (index + i < src->length)
			tmp[i] = avm2_coerce_to_number(act->ctx, src->elems[index + i]);
	}
	if (transpose)
	{
		for (int c = 0; c < 4; c++)
			for (int r = 0; r < 4; r++) e->m[c * 4 + r] = tmp[r * 4 + c];
	}
	else
	{
		memcpy(e->m, tmp, sizeof(tmp));
	}
	return avm2_undefined();
}

static Avm2Value matrix3d_copy_raw_data_to(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Object* v = s3d_arg_object_non_null(act, 0, "dest");
	Avm2VectorExt* dst = v != NULL ? avm2_vector_ext(v) : NULL;
	uint32_t index = s3d_arg_u32(act, 1, 0);
	int transpose = s3d_arg_bool(act, 2, 0);
	if (e == NULL || dst == NULL || v == NULL) return avm2_undefined();
	// A fixed destination that cannot hold all 16 entries is #1126, raised
	// BEFORE any element is written (Flash leaves the vector untouched); the
	// per-element write path would otherwise report #1125 halfway through.
	if (dst->fixed && (uint64_t) index + 16 > (uint64_t) dst->length)
	{
		avm2_throw_error(ctx, ctx->builtins.range_error_class,
		                 "Error #1126: Cannot change the length of a fixed "
		                 "Vector.");
	}
	for (uint32_t i = 0; i < 16; i++)
	{
		double val;
		if (transpose)
		{
			uint32_t c = i / 4, r = i % 4;
			val = e->m[r * 4 + c];
		}
		else
		{
			val = e->m[i];
		}
		avm2_vector_set_index(ctx, v, index + i, avm2_number(val));
	}
	return avm2_undefined();
}

static Avm2Value matrix3d_transpose(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	if (e == NULL) return avm2_undefined();
	double t[16];
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++) t[c * 4 + r] = e->m[r * 4 + c];
	memcpy(e->m, t, sizeof(t));
	return avm2_undefined();
}

static Avm2Value matrix3d_append(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Matrix3DExt* o = matrix3d_ext_of(s3d_arg_object_non_null(act, 0, "lhs"));
	if (e != NULL && o != NULL) m3d_mul(e->m, e->m, o->m);
	return avm2_undefined();
}

static Avm2Value matrix3d_prepend(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Matrix3DExt* o = matrix3d_ext_of(s3d_arg_object_non_null(act, 0, "rhs"));
	if (e != NULL && o != NULL) m3d_mul(e->m, o->m, e->m);
	return avm2_undefined();
}

static void m3d_build_translation(double* m, double x, double y, double z)
{
	m3d_identity(m);
	m[12] = x; m[13] = y; m[14] = z;
}

static void m3d_build_scale(double* m, double x, double y, double z)
{
	m3d_identity(m);
	m[0] = x; m[5] = y; m[10] = z;
}

// Rotation of `deg` degrees about the (possibly unnormalized) axis.
static void m3d_build_rotation(double* m, double deg, double ax, double ay,
                               double az)
{
	double len = sqrt(ax * ax + ay * ay + az * az);
	m3d_identity(m);
	// A zero-length axis skips only the normalization: Flash still runs the
	// Rodrigues formula with ax=ay=az=0, so a 180-degree rotation about the
	// zero axis is diag(c, c, c, 1) = diag(-1, -1, -1, 1), not identity.
	if (len != 0.0) { ax /= len; ay /= len; az /= len; }
	double r = deg * 3.14159265358979323846 / 180.0;
	double c = cos(r), s = sin(r), t = 1.0 - c;
	m[0] = t * ax * ax + c;
	m[1] = t * ax * ay + s * az;
	m[2] = t * ax * az - s * ay;
	m[4] = t * ax * ay - s * az;
	m[5] = t * ay * ay + c;
	m[6] = t * ay * az + s * ax;
	m[8] = t * ax * az + s * ay;
	m[9] = t * ay * az - s * ax;
	m[10] = t * az * az + c;
}

static Avm2Value matrix3d_xform(Avm2Activation* act, int kind, int prepend)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	if (e == NULL) return avm2_undefined();
	double t[16];
	if (kind == 2)
	{
		double deg = s3d_arg_number(act, 0, 0.0);
		double ax = 0.0, ay = 0.0, az = 0.0;
		// `axis` is required non-null; the optional `pivotPoint` below is not.
		Avm2Object* axis = s3d_arg_object_non_null(act, 1, "axis");
		if (axis != NULL)
		{
			ax = m3d_component(act->ctx, axis, "x");
			ay = m3d_component(act->ctx, axis, "y");
			az = m3d_component(act->ctx, axis, "z");
		}
		m3d_build_rotation(t, deg, ax, ay, az);
		// The optional third argument is a pivot point: the rotation happens
		// about `pivot` rather than about the origin, i.e.
		//   v' = (v - p) * R + p  =  v * R + (p - p * R)
		// (row-vector convention, translation in m[12..14]).
		Avm2Object* pivot = s3d_arg_object(act, 2);
		if (pivot != NULL)
		{
			double px = m3d_component(act->ctx, pivot, "x");
			double py = m3d_component(act->ctx, pivot, "y");
			double pz = m3d_component(act->ctx, pivot, "z");
			double rx = px * t[0] + py * t[4] + pz * t[8];
			double ry = px * t[1] + py * t[5] + pz * t[9];
			double rz = px * t[2] + py * t[6] + pz * t[10];
			t[12] = px - rx;
			t[13] = py - ry;
			t[14] = pz - rz;
		}
	}
	else
	{
		double x = s3d_arg_number(act, 0, kind == 1 ? 1.0 : 0.0);
		double y = s3d_arg_number(act, 1, kind == 1 ? 1.0 : 0.0);
		double z = s3d_arg_number(act, 2, kind == 1 ? 1.0 : 0.0);
		if (kind == 1) m3d_build_scale(t, x, y, z);
		else m3d_build_translation(t, x, y, z);
	}
	if (prepend) m3d_mul(e->m, t, e->m);
	else m3d_mul(e->m, e->m, t);
	return avm2_undefined();
}

static Avm2Value matrix3d_append_translation(Avm2Activation* act)
{ return matrix3d_xform(act, 0, 0); }
static Avm2Value matrix3d_append_scale(Avm2Activation* act)
{ return matrix3d_xform(act, 1, 0); }
static Avm2Value matrix3d_append_rotation(Avm2Activation* act)
{ return matrix3d_xform(act, 2, 0); }
static Avm2Value matrix3d_prepend_translation(Avm2Activation* act)
{ return matrix3d_xform(act, 0, 1); }
static Avm2Value matrix3d_prepend_scale(Avm2Activation* act)
{ return matrix3d_xform(act, 1, 1); }
static Avm2Value matrix3d_prepend_rotation(Avm2Activation* act)
{ return matrix3d_xform(act, 2, 1); }

static double m3d_determinant(const double* m)
{
	// 3x3 upper-left cofactor expansion is what Flash's `determinant` is
	// documented to return for an affine matrix; use the full 4x4 form so the
	// value stays right for projection matrices too.
	double s0 = m[0] * m[5] - m[4] * m[1];
	double s1 = m[0] * m[9] - m[8] * m[1];
	double s2 = m[0] * m[13] - m[12] * m[1];
	double s3 = m[4] * m[9] - m[8] * m[5];
	double s4 = m[4] * m[13] - m[12] * m[5];
	double s5 = m[8] * m[13] - m[12] * m[9];
	double c5 = m[10] * m[15] - m[14] * m[11];
	double c4 = m[6] * m[15] - m[14] * m[7];
	double c3 = m[6] * m[11] - m[10] * m[7];
	double c2 = m[2] * m[15] - m[14] * m[3];
	double c1 = m[2] * m[11] - m[10] * m[3];
	double c0 = m[2] * m[7] - m[6] * m[3];
	return s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
}

static Avm2Value matrix3d_get_determinant(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	return avm2_number(e != NULL ? m3d_determinant(e->m) : 0.0);
}

static Avm2Value matrix3d_invert(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	if (e == NULL) return avm2_bool(0);
	const double* m = e->m;
	double s0 = m[0] * m[5] - m[4] * m[1];
	double s1 = m[0] * m[9] - m[8] * m[1];
	double s2 = m[0] * m[13] - m[12] * m[1];
	double s3 = m[4] * m[9] - m[8] * m[5];
	double s4 = m[4] * m[13] - m[12] * m[5];
	double s5 = m[8] * m[13] - m[12] * m[9];
	double c5 = m[10] * m[15] - m[14] * m[11];
	double c4 = m[6] * m[15] - m[14] * m[7];
	double c3 = m[6] * m[11] - m[10] * m[7];
	double c2 = m[2] * m[15] - m[14] * m[3];
	double c1 = m[2] * m[11] - m[10] * m[3];
	double c0 = m[2] * m[7] - m[6] * m[3];
	double det = s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
	if (det == 0.0) return avm2_bool(0);
	double id = 1.0 / det;
	double r[16];
	r[0] = (m[5] * c5 - m[9] * c4 + m[13] * c3) * id;
	r[1] = (-m[1] * c5 + m[9] * c2 - m[13] * c1) * id;
	r[2] = (m[1] * c4 - m[5] * c2 + m[13] * c0) * id;
	r[3] = (-m[1] * c3 + m[5] * c1 - m[9] * c0) * id;
	r[4] = (-m[4] * c5 + m[8] * c4 - m[12] * c3) * id;
	r[5] = (m[0] * c5 - m[8] * c2 + m[12] * c1) * id;
	r[6] = (-m[0] * c4 + m[4] * c2 - m[12] * c0) * id;
	r[7] = (m[0] * c3 - m[4] * c1 + m[8] * c0) * id;
	r[8] = (m[7] * s5 - m[11] * s4 + m[15] * s3) * id;
	r[9] = (-m[3] * s5 + m[11] * s2 - m[15] * s1) * id;
	r[10] = (m[3] * s4 - m[7] * s2 + m[15] * s0) * id;
	r[11] = (-m[3] * s3 + m[7] * s1 - m[11] * s0) * id;
	r[12] = (-m[6] * s5 + m[10] * s4 - m[14] * s3) * id;
	r[13] = (m[2] * s5 - m[10] * s2 + m[14] * s1) * id;
	r[14] = (-m[2] * s4 + m[6] * s2 - m[14] * s0) * id;
	r[15] = (m[2] * s3 - m[6] * s1 + m[10] * s0) * id;
	memcpy(e->m, r, sizeof(r));
	return avm2_bool(1);
}

static Avm2Value matrix3d_transform_vector_common(Avm2Activation* act, int delta)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Object* v = s3d_arg_object_non_null(act, 0, "vector");
	if (e == NULL || v == NULL) return avm2_null();
	double x = m3d_component(ctx, v, "x");
	double y = m3d_component(ctx, v, "y");
	double z = m3d_component(ctx, v, "z");
	const double* m = e->m;
	double ox = m[0] * x + m[4] * y + m[8] * z + (delta ? 0.0 : m[12]);
	double oy = m[1] * x + m[5] * y + m[9] * z + (delta ? 0.0 : m[13]);
	double oz = m[2] * x + m[6] * y + m[10] * z + (delta ? 0.0 : m[14]);
	// The fourth row of the product is returned as the result's `w`; the input
	// vector's own `w` is ignored (verified by the "w set" cases).
	double ow = m[3] * x + m[7] * y + m[11] * z + (delta ? 0.0 : m[15]);
	Avm2Value args[4] = { avm2_number(ox), avm2_number(oy), avm2_number(oz),
	                      avm2_number(ow) };
	return avm2_class_construct(ctx, v->cls, args, 4);
}

static Avm2Value matrix3d_transform_vector(Avm2Activation* act)
{ return matrix3d_transform_vector_common(act, 0); }
static Avm2Value matrix3d_delta_transform_vector(Avm2Activation* act)
{ return matrix3d_transform_vector_common(act, 1); }

static Avm2Value matrix3d_get_position(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	if (e == NULL || g_vector3d_class == NULL) return avm2_null();
	Avm2Value args[3] =
		{ avm2_number(e->m[12]), avm2_number(e->m[13]), avm2_number(e->m[14]) };
	return avm2_class_construct(ctx, g_vector3d_class, args, 3);
}

static Avm2Value matrix3d_set_position(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Object* v = s3d_arg_object(act, 0);
	if (e == NULL || v == NULL) return avm2_undefined();
	e->m[12] = m3d_component(ctx, v, "x");
	e->m[13] = m3d_component(ctx, v, "y");
	e->m[14] = m3d_component(ctx, v, "z");
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// recompose / decompose / transformVectors (Ruffle geom/Matrix3D.as)
// ---------------------------------------------------------------------------

static void m3d_set_component(Avm2Context* ctx, Avm2Object* v, const char* name,
                              double d)
{
	if (v != NULL)
		avm2_set_public_property(ctx, avm2_object_value(v), name, 1,
		                         avm2_number(d));
}

// Every orientation-taking entry point validates first: anything outside the
// three Orientation3D constants is #2187, a plain Error.
static void m3d_check_orientation(Avm2Context* ctx, const Avm2String* s)
{
	if (s != NULL && (s3d_str_is(s, "eulerAngles")
	                  || s3d_str_is(s, "axisAngle")
	                  || s3d_str_is(s, "quaternion")))
	{
		return;
	}
	char buf[256];
	snprintf(buf, sizeof(buf),
	         "Error #2187: Invalid orientation style %.*s.  Value must be one "
	         "of 'Orientation3D.EULER_ANGLES', 'Orientation3D.AXIS_ANGLE', or "
	         "'Orientation3D.QUATERNION'.",
	         s != NULL ? (int) s->len : 4, s != NULL ? s->utf8 : "null");
	avm2_throw_error(ctx, ctx->builtins.error_class, buf);
}

// An omitted (or `undefined`) style defaults to eulerAngles, but an explicit
// `null` is #2007 — the declared `orientationStyle:String` parameter coerces
// `undefined` to `null` before the builtin sees it, so the two are distinct
// here even though they are the same "missing" at the AS3 call site.
static const Avm2String* m3d_orientation_arg(Avm2Activation* act, uint32_t i)
{
	if (act->argc > i && act->args[i].kind == AVM2_VALUE_NULL)
		s3d_throw_2007(act->ctx, "orientationStyle");
	if (act->argc > i && act->args[i].kind != AVM2_VALUE_UNDEFINED)
		return avm2_coerce_to_string(act->ctx, act->args[i]);
	return avm2_string_from_literal(act->ctx, "eulerAngles");
}

// recompose(components:Vector.<Vector3D>, orientationStyle="eulerAngles").
// components is [translation, rotation, scale]. A zero scale component is
// replaced by 1e-15 rather than left at 0 (so the matrix stays invertible) and
// makes the call report false — note the .as's own `components[2].y == 0`
// typo in the third arm, which we replicate.
static Avm2Value matrix3d_recompose(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	// Validation order is measured (matrix3d_recompose_edge_cases): a null
	// `components` first, then a null `orientationStyle` (both #2007), then
	// #2187 on the style spelling, and only then the component count.
	Avm2Object* cv = s3d_arg_object_non_null(act, 0, "components");
	const Avm2String* os = m3d_orientation_arg(act, 1);
	m3d_check_orientation(ctx, os);
	if (e == NULL) return avm2_bool(0);
	Avm2VectorExt* comps = cv != NULL ? avm2_vector_ext(cv) : NULL;
	if (comps == NULL || comps->length < 3) return avm2_bool(0);

	// A null element inside `components` reports false and leaves the matrix
	// untouched, so this has to precede the m3d_identity() below.
	if (comps->elems[0].kind != AVM2_VALUE_OBJECT
	    || comps->elems[1].kind != AVM2_VALUE_OBJECT
	    || comps->elems[2].kind != AVM2_VALUE_OBJECT)
	{
		return avm2_bool(0);
	}
	Avm2Object* t = comps->elems[0].u.obj;
	Avm2Object* r = comps->elems[1].u.obj;
	Avm2Object* sc = comps->elems[2].u.obj;
	double sx3 = m3d_component(ctx, sc, "x");
	double sy3 = m3d_component(ctx, sc, "y");
	double sz3 = m3d_component(ctx, sc, "z");

	m3d_identity(e->m);
	double* m = e->m;
	if (s3d_str_is(os, "eulerAngles"))
	{
		double cx = cos(m3d_component(ctx, r, "x"));
		double cy = cos(m3d_component(ctx, r, "y"));
		double cz = cos(m3d_component(ctx, r, "z"));
		double sx = sin(m3d_component(ctx, r, "x"));
		double sy = sin(m3d_component(ctx, r, "y"));
		double sz = sin(m3d_component(ctx, r, "z"));
		m[0] = cy * cz * sx3;
		m[1] = cy * sz * sx3;
		m[2] = -sy * sx3;
		m[3] = 0;
		m[4] = (sx * sy * cz - cx * sz) * sy3;
		m[5] = (sx * sy * sz + cx * cz) * sy3;
		m[6] = sx * cy * sy3;
		m[7] = 0;
		m[8] = (cx * sy * cz + sx * sz) * sz3;
		m[9] = (cx * sy * sz - sx * cz) * sz3;
		m[10] = cx * cy * sz3;
		m[11] = 0;
	}
	else
	{
		double x = m3d_component(ctx, r, "x");
		double y = m3d_component(ctx, r, "y");
		double z = m3d_component(ctx, r, "z");
		double w = m3d_component(ctx, r, "w");
		if (s3d_str_is(os, "axisAngle"))
		{
			x *= sin(w / 2); y *= sin(w / 2); z *= sin(w / 2);
			w = cos(w / 2);
		}
		m[0] = (1 - 2 * y * y - 2 * z * z) * sx3;
		m[1] = (2 * x * y + 2 * w * z) * sx3;
		m[2] = (2 * x * z - 2 * w * y) * sx3;
		m[3] = 0;
		m[4] = (2 * x * y - 2 * w * z) * sy3;
		m[5] = (1 - 2 * x * x - 2 * z * z) * sy3;
		m[6] = (2 * y * z + 2 * w * x) * sy3;
		m[7] = 0;
		m[8] = (2 * x * z + 2 * w * y) * sz3;
		m[9] = (2 * y * z - 2 * w * x) * sz3;
		m[10] = (1 - 2 * x * x - 2 * y * y) * sz3;
		m[11] = 0;
	}
	m[12] = m3d_component(ctx, t, "x");
	m[13] = m3d_component(ctx, t, "y");
	m[14] = m3d_component(ctx, t, "z");
	m[15] = 1;

	// A zero scale component is written as a literal 0 (no 1e-15 substitution)
	// and still reports true — measured on every zero-scale permutation in
	// matrix3d_recompose_edge_cases, and matches matrix3d_compose's
	// "Recomposed zero scale: 0,0,...". Only a null component (above) or a
	// short `components` reports false.
	return avm2_bool(1);
}

static Avm2Value matrix3d_decompose(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	const Avm2String* os = m3d_orientation_arg(act, 0);
	m3d_check_orientation(ctx, os);
	if (e == NULL || g_vector3d_class == NULL) return avm2_null();

	double mr[16];
	memcpy(mr, e->m, sizeof(mr));
	double px = mr[12], py = mr[13], pz = mr[14];
	mr[12] = mr[13] = mr[14] = 0;

	double sx = sqrt(mr[0] * mr[0] + mr[1] * mr[1] + mr[2] * mr[2]);
	double sy = sqrt(mr[4] * mr[4] + mr[5] * mr[5] + mr[6] * mr[6]);
	double sz = sqrt(mr[8] * mr[8] + mr[9] * mr[9] + mr[10] * mr[10]);
	if (mr[0] * (mr[5] * mr[10] - mr[6] * mr[9])
	  - mr[1] * (mr[4] * mr[10] - mr[6] * mr[8])
	  + mr[2] * (mr[4] * mr[9] - mr[5] * mr[8]) < 0)
	{
		sz = -sz;
	}
	mr[0] /= sx; mr[1] /= sx; mr[2] /= sx;
	mr[4] /= sy; mr[5] /= sy; mr[6] /= sy;
	mr[8] /= sz; mr[9] /= sz; mr[10] /= sz;

	double rx = 0, ry = 0, rz = 0, rw = 0;
	if (s3d_str_is(os, "axisAngle"))
	{
		rw = acos((mr[0] + mr[5] + mr[10] - 1) / 2);
		double len = sqrt((mr[6] - mr[9]) * (mr[6] - mr[9])
		                + (mr[8] - mr[2]) * (mr[8] - mr[2])
		                + (mr[1] - mr[4]) * (mr[1] - mr[4]));
		if (len != 0)
		{
			rx = (mr[6] - mr[9]) / len;
			ry = (mr[8] - mr[2]) / len;
			rz = (mr[1] - mr[4]) / len;
		}
	}
	else if (s3d_str_is(os, "quaternion"))
	{
		double tr = mr[0] + mr[5] + mr[10];
		if (tr > 0)
		{
			rw = sqrt(1 + tr) / 2;
			rx = (mr[6] - mr[9]) / (4 * rw);
			ry = (mr[8] - mr[2]) / (4 * rw);
			rz = (mr[1] - mr[4]) / (4 * rw);
		}
		else if (mr[0] > mr[5] && mr[0] > mr[10])
		{
			rx = sqrt(1 + mr[0] - mr[5] - mr[10]) / 2;
			rw = (mr[6] - mr[9]) / (4 * rx);
			ry = (mr[1] + mr[4]) / (4 * rx);
			rz = (mr[8] + mr[2]) / (4 * rx);
		}
		else if (mr[5] > mr[10])
		{
			ry = sqrt(1 + mr[5] - mr[0] - mr[10]) / 2;
			rx = (mr[1] + mr[4]) / (4 * ry);
			rw = (mr[8] - mr[2]) / (4 * ry);
			rz = (mr[6] + mr[9]) / (4 * ry);
		}
		else
		{
			rz = sqrt(1 + mr[10] - mr[0] - mr[5]) / 2;
			rx = (mr[8] + mr[2]) / (4 * rz);
			ry = (mr[6] + mr[9]) / (4 * rz);
			rw = (mr[1] - mr[4]) / (4 * rz);
		}
	}
	else
	{
		ry = asin(-mr[2]);
		if (mr[2] != 1 && mr[2] != -1)
		{
			rx = atan2(mr[6], mr[10]);
			rz = atan2(mr[1], mr[0]);
		}
		else
		{
			rz = 0;
			rx = atan2(mr[4], mr[5]);
		}
	}

	Avm2Class* vec_cls = avm2_vector_apply(ctx, g_vector3d_class);
	Avm2Object* out = avm2_vector_new(ctx, vec_cls, 0, 0);
	Avm2Value pa[4] = { avm2_number(px), avm2_number(py), avm2_number(pz),
	                    avm2_number(0) };
	avm2_vector_set_index(ctx, out, 0,
		avm2_class_construct(ctx, g_vector3d_class, pa, 3));
	Avm2Value ra[4] = { avm2_number(rx), avm2_number(ry), avm2_number(rz),
	                    avm2_number(rw) };
	avm2_vector_set_index(ctx, out, 1,
		avm2_class_construct(ctx, g_vector3d_class, ra, 4));
	Avm2Value sa[3] = { avm2_number(sx), avm2_number(sy), avm2_number(sz) };
	avm2_vector_set_index(ctx, out, 2,
		avm2_class_construct(ctx, g_vector3d_class, sa, 3));
	return avm2_object_value(out);
}

// transformVectors(vin:Vector.<Number>, vout:Vector.<Number>): floor(len/3)*3
// components are consumed; a fixed vout that is too short is #1126.
static Avm2Value matrix3d_transform_vectors(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Object* vin_o = s3d_arg_object(act, 0);
	Avm2Object* vout_o = s3d_arg_object(act, 1);
	Avm2VectorExt* vin = vin_o != NULL ? avm2_vector_ext(vin_o) : NULL;
	Avm2VectorExt* vout = vout_o != NULL ? avm2_vector_ext(vout_o) : NULL;
	if (vin == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter vin must be non-null.");
	}
	if (vout == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #2007: Parameter vout must be non-null.");
	}
	if (e == NULL) return avm2_undefined();
	uint32_t n = (vin->length / 3) * 3;
	if (n > vout->length && vout->fixed)
	{
		avm2_throw_error(ctx, ctx->builtins.range_error_class,
		                 "Error #1126: Cannot change the length of a fixed "
		                 "Vector.");
	}
	const double* m = e->m;
	for (uint32_t i = 0; i < n; i += 3)
	{
		double x = avm2_coerce_to_number(ctx, vin->elems[i]);
		double y = avm2_coerce_to_number(ctx, vin->elems[i + 1]);
		double z = avm2_coerce_to_number(ctx, vin->elems[i + 2]);
		double ox = m[0] * x + m[4] * y + m[8] * z + m[12];
		double oy = m[1] * x + m[5] * y + m[9] * z + m[13];
		double oz = m[2] * x + m[6] * y + m[10] * z + m[14];
		avm2_vector_set_index(ctx, vout_o, i, avm2_number(ox));
		avm2_vector_set_index(ctx, vout_o, i + 1, avm2_number(oy));
		avm2_vector_set_index(ctx, vout_o, i + 2, avm2_number(oz));
		vout = avm2_vector_ext(vout_o);
		if (vout == NULL) break;
	}
	return avm2_undefined();
}

// copyColumnTo/copyRowTo — the read direction of the pair already registered.
static Avm2Value matrix3d_copy_vec_to(Avm2Activation* act, int column)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	uint32_t idx = act->argc > 0 ? avm2_coerce_to_u32(ctx, act->args[0]) : 0;
	// The null check precedes the range check: copyColumnTo(4, null) is #2007,
	// not #2004.
	Avm2Object* v = s3d_arg_object_non_null(act, 1, "vector3D");
	if (idx > 3)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2004: One of the parameters is invalid.");
	}
	if (e == NULL || v == NULL) return avm2_undefined();
	static const char* const n[4] = { "x", "y", "z", "w" };
	for (int k = 0; k < 4; k++)
	{
		int off = column ? (int) idx * 4 + k : k * 4 + (int) idx;
		m3d_set_component(ctx, v, n[k], e->m[off]);
	}
	return avm2_undefined();
}

static Avm2Value matrix3d_copy_column_to(Avm2Activation* act)
{ return matrix3d_copy_vec_to(act, 1); }
static Avm2Value matrix3d_copy_row_to(Avm2Activation* act)
{ return matrix3d_copy_vec_to(act, 0); }

// The write direction of the same pair: read x/y/z/w off the Vector3D into the
// column (or row) of the matrix.
static Avm2Value matrix3d_copy_vec_from(Avm2Activation* act, int column)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	uint32_t idx = act->argc > 0 ? avm2_coerce_to_u32(ctx, act->args[0]) : 0;
	// Same order as copyColumnTo: null before range.
	Avm2Object* v = s3d_arg_object_non_null(act, 1, "vector3D");
	if (idx > 3)
	{
		avm2_throw_error(ctx, ctx->builtins.argument_error_class,
		                 "Error #2004: One of the parameters is invalid.");
	}
	if (e == NULL || v == NULL) return avm2_undefined();
	static const char* const n[4] = { "x", "y", "z", "w" };
	for (int k = 0; k < 4; k++)
	{
		int off = column ? (int) idx * 4 + k : k * 4 + (int) idx;
		e->m[off] = m3d_component(ctx, v, n[k]);
	}
	return avm2_undefined();
}

static Avm2Value matrix3d_copy_column_from(Avm2Activation* act)
{ return matrix3d_copy_vec_from(act, 1); }
static Avm2Value matrix3d_copy_row_from(Avm2Activation* act)
{ return matrix3d_copy_vec_from(act, 0); }

static Avm2Value matrix3d_copy_to_matrix3d(Avm2Activation* act)
{
	Avm2Matrix3DExt* e = matrix3d_ext(act);
	Avm2Matrix3DExt* o = matrix3d_ext_of(s3d_arg_object(act, 0));
	if (e != NULL && o != NULL) memcpy(o->m, e->m, sizeof(o->m));
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// flash.geom.Utils3D (Ruffle geom/Utils3D.as, itself from OpenFL)
// ---------------------------------------------------------------------------

// projectVector(m, v): transformVector then divide x/y/z by the resulting w.
// w itself is left as the transformed w, which is why the test can print it.
static Avm2Value utils3d_project_vector(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext_of(s3d_arg_object(act, 0));
	Avm2Object* v = s3d_arg_object(act, 1);
	if (e == NULL || v == NULL || g_vector3d_class == NULL) return avm2_null();
	double x = m3d_component(ctx, v, "x");
	double y = m3d_component(ctx, v, "y");
	double z = m3d_component(ctx, v, "z");
	const double* m = e->m;
	double ox = m[0] * x + m[4] * y + m[8] * z + m[12];
	double oy = m[1] * x + m[5] * y + m[9] * z + m[13];
	double oz = m[2] * x + m[6] * y + m[10] * z + m[14];
	double ow = m[3] * x + m[7] * y + m[11] * z + m[15];
	Avm2Value args[4] = { avm2_number(ox / ow), avm2_number(oy / ow),
	                      avm2_number(oz / ow), avm2_number(ow) };
	return avm2_class_construct(ctx, g_vector3d_class, args, 4);
}

// projectVectors(m, verts, projectedVerts, uvts): both output vectors GROW to
// the sizes the loop needs before it runs, which is why a caller can pass empty
// ones. uvts[i+2] receives 1/w — the other two slots of each triple are left
// exactly as the caller had them (the test's "deliberately missing" tail).
static Avm2Value utils3d_project_vectors(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Matrix3DExt* e = matrix3d_ext_of(s3d_arg_object(act, 0));
	Avm2Object* verts_o = s3d_arg_object(act, 1);
	Avm2Object* pv_o = s3d_arg_object(act, 2);
	Avm2Object* uv_o = s3d_arg_object(act, 3);
	Avm2VectorExt* verts = verts_o != NULL ? avm2_vector_ext(verts_o) : NULL;
	if (e == NULL || verts == NULL || pv_o == NULL || uv_o == NULL)
		return avm2_undefined();
	uint32_t vlen = verts->length;

	// Grow through the public `length` setter — vec_resize is private to
	// avm2_vector.c, and a bare index write past the end would be #1125.
	Avm2VectorExt* uv = avm2_vector_ext(uv_o);
	if (uv != NULL && uv->length < vlen)
	{
		avm2_set_public_property(ctx, avm2_object_value(uv_o), "length", 6,
		                         avm2_uint_value(vlen));
	}
	Avm2VectorExt* pv = avm2_vector_ext(pv_o);
	uint32_t need = (vlen / 3) * 2;
	if (pv != NULL && pv->length < need)
	{
		avm2_set_public_property(ctx, avm2_object_value(pv_o), "length", 6,
		                         avm2_uint_value(need));
	}

	const double* n = e->m;
	uint32_t j = 0;
	for (uint32_t i = 0; i + 2 < vlen; i += 3, j += 2)
	{
		verts = avm2_vector_ext(verts_o);
		if (verts == NULL) break;
		double x = avm2_coerce_to_number(ctx, verts->elems[i]);
		double y = avm2_coerce_to_number(ctx, verts->elems[i + 1]);
		double z = avm2_coerce_to_number(ctx, verts->elems[i + 2]);
		double x1 = x * n[0] + y * n[4] + z * n[8] + n[12];
		double y1 = x * n[1] + y * n[5] + z * n[9] + n[13];
		double w1 = x * n[3] + y * n[7] + z * n[11] + n[15];
		avm2_vector_set_index(ctx, pv_o, j, avm2_number(x1 / w1));
		avm2_vector_set_index(ctx, pv_o, j + 1, avm2_number(y1 / w1));
		avm2_vector_set_index(ctx, uv_o, i + 2, avm2_number(1.0 / w1));
	}
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// Registration
// ---------------------------------------------------------------------------

static void s3d_sconst(Avm2Context* ctx, Avm2Class* cls, const char* n,
                       const char* v)
{
	avm2_builtin_add_static_const(ctx, cls, n,
	                              avm2_string(avm2_string_from_literal(ctx, v)));
}

// API-version gate for flash.display3D (Ruffle playerglobal `[API("N")]`,
// ordinal N-660 → api_version.rs). Flash simply does not expose a class to a
// movie older than its introduction version, and avm2/all_classes/display3D
// grades exactly that: swf12 sees only the three UNANNOTATED bags, swf13
// adds the API("674") set, and swf30 sees everything.
//
//   [API("674")] = SWF_13  Context3D, Context3DProgramType,
//                          Context3DRenderMode, Context3DStencilAction,
//                          Context3DTextureFormat, Context3DTriangleFace,
//                          Context3DVertexBufferFormat, IndexBuffer3D,
//                          Program3D, VertexBuffer3D
//   [API("682")] = SWF_17  Context3DProfile
//   [API("686")] = SWF_19  Context3DMipFilter, Context3DTextureFilter,
//                          Context3DWrapMode
//   [API("692")] = SWF_22  Context3DBufferUsage
//   (unannotated)          Context3DBlendFactor, Context3DClearMask,
//                          Context3DCompareMode
static uint8_t s3d_api_min_swf(const char* name)
{
	static const struct { const char* name; uint8_t min_swf; } gates[] = {
		{ "Context3D",                   13 },
		{ "Context3DProgramType",        13 },
		{ "Context3DRenderMode",         13 },
		{ "Context3DStencilAction",      13 },
		{ "Context3DTextureFormat",      13 },
		{ "Context3DTriangleFace",       13 },
		{ "Context3DVertexBufferFormat", 13 },
		{ "IndexBuffer3D",               13 },
		{ "Program3D",                   13 },
		{ "VertexBuffer3D",              13 },
		{ "Context3DProfile",            17 },
		{ "Context3DMipFilter",          19 },
		{ "Context3DTextureFilter",      19 },
		{ "Context3DWrapMode",           19 },
		{ "Context3DBufferUsage",        22 },
	};
	for (size_t i = 0; i < sizeof(gates) / sizeof(gates[0]); i++)
	{
		if (strcmp(gates[i].name, name) == 0) return gates[i].min_swf;
	}
	return 0;
}

static Avm2Class* s3d_class(Avm2Context* ctx, const char* name, Avm2Class* super)
{
	return avm2_builtin_class_api(ctx, "flash.display3D", name, super,
	                              s3d_api_min_swf(name));
}

// The flash.display3D constant bags (one static const per accepted spelling).
static void register_constant_classes(Avm2Context* ctx)
{
	Avm2Class* obj = ctx->builtins.object_class;
	struct { const char* cls; const char* name; const char* val; } consts[] = {
		{ "Context3DProfile", "BASELINE", "baseline" },
		{ "Context3DProfile", "BASELINE_CONSTRAINED", "baselineConstrained" },
		{ "Context3DProfile", "BASELINE_EXTENDED", "baselineExtended" },
		{ "Context3DProfile", "STANDARD", "standard" },
		{ "Context3DProfile", "STANDARD_CONSTRAINED", "standardConstrained" },
		{ "Context3DProfile", "STANDARD_EXTENDED", "standardExtended" },
		{ "Context3DRenderMode", "AUTO", "auto" },
		{ "Context3DRenderMode", "SOFTWARE", "software" },
		{ "Context3DProgramType", "FRAGMENT", "fragment" },
		{ "Context3DProgramType", "VERTEX", "vertex" },
		{ "Context3DBufferUsage", "DYNAMIC_DRAW", "dynamicDraw" },
		{ "Context3DBufferUsage", "STATIC_DRAW", "staticDraw" },
		{ "Context3DMipFilter", "MIPLINEAR", "miplinear" },
		{ "Context3DMipFilter", "MIPNEAREST", "mipnearest" },
		{ "Context3DMipFilter", "MIPNONE", "mipnone" },
		{ "Context3DTextureFormat", "BGRA", "bgra" },
		{ "Context3DTextureFormat", "BGRA_PACKED", "bgraPacked4444" },
		{ "Context3DTextureFormat", "BGR_PACKED", "bgrPacked565" },
		{ "Context3DTextureFormat", "COMPRESSED", "compressed" },
		{ "Context3DTextureFormat", "COMPRESSED_ALPHA", "compressedAlpha" },
		{ "Context3DTextureFormat", "RGBA_HALF_FLOAT", "rgbaHalfFloat" },
		{ "Context3DTriangleFace", "BACK", "back" },
		{ "Context3DTriangleFace", "FRONT", "front" },
		{ "Context3DTriangleFace", "FRONT_AND_BACK", "frontAndBack" },
		{ "Context3DTriangleFace", "NONE", "none" },
		{ "Context3DCompareMode", "ALWAYS", "always" },
		{ "Context3DCompareMode", "EQUAL", "equal" },
		{ "Context3DCompareMode", "GREATER", "greater" },
		{ "Context3DCompareMode", "GREATER_EQUAL", "greaterEqual" },
		{ "Context3DCompareMode", "LESS", "less" },
		{ "Context3DCompareMode", "LESS_EQUAL", "lessEqual" },
		{ "Context3DCompareMode", "NEVER", "never" },
		{ "Context3DCompareMode", "NOT_EQUAL", "notEqual" },
		{ "Context3DStencilAction", "DECREMENT_SATURATE", "decrementSaturate" },
		{ "Context3DStencilAction", "DECREMENT_WRAP", "decrementWrap" },
		{ "Context3DStencilAction", "INCREMENT_SATURATE", "incrementSaturate" },
		{ "Context3DStencilAction", "INCREMENT_WRAP", "incrementWrap" },
		{ "Context3DStencilAction", "INVERT", "invert" },
		{ "Context3DStencilAction", "KEEP", "keep" },
		{ "Context3DStencilAction", "SET", "set" },
		{ "Context3DStencilAction", "ZERO", "zero" },
		{ "Context3DWrapMode", "CLAMP", "clamp" },
		{ "Context3DWrapMode", "CLAMP_U_REPEAT_V", "clamp_u_repeat_v" },
		{ "Context3DWrapMode", "REPEAT", "repeat" },
		{ "Context3DWrapMode", "REPEAT_U_CLAMP_V", "repeat_u_clamp_v" },
		{ "Context3DTextureFilter", "ANISOTROPIC16X", "anisotropic16x" },
		{ "Context3DTextureFilter", "ANISOTROPIC2X", "anisotropic2x" },
		{ "Context3DTextureFilter", "ANISOTROPIC4X", "anisotropic4x" },
		{ "Context3DTextureFilter", "ANISOTROPIC8X", "anisotropic8x" },
		{ "Context3DTextureFilter", "LINEAR", "linear" },
		{ "Context3DTextureFilter", "NEAREST", "nearest" },
		{ "Context3DVertexBufferFormat", "BYTES_4", "bytes4" },
		{ "Context3DVertexBufferFormat", "FLOAT_1", "float1" },
		{ "Context3DVertexBufferFormat", "FLOAT_2", "float2" },
		{ "Context3DVertexBufferFormat", "FLOAT_3", "float3" },
		{ "Context3DVertexBufferFormat", "FLOAT_4", "float4" },
		{ "Context3DBlendFactor", "DESTINATION_ALPHA", "destinationAlpha" },
		{ "Context3DBlendFactor", "DESTINATION_COLOR", "destinationColor" },
		{ "Context3DBlendFactor", "ONE", "one" },
		{ "Context3DBlendFactor", "ONE_MINUS_DESTINATION_ALPHA",
		  "oneMinusDestinationAlpha" },
		{ "Context3DBlendFactor", "ONE_MINUS_DESTINATION_COLOR",
		  "oneMinusDestinationColor" },
		{ "Context3DBlendFactor", "ONE_MINUS_SOURCE_ALPHA",
		  "oneMinusSourceAlpha" },
		{ "Context3DBlendFactor", "ONE_MINUS_SOURCE_COLOR",
		  "oneMinusSourceColor" },
		{ "Context3DBlendFactor", "SOURCE_ALPHA", "sourceAlpha" },
		{ "Context3DBlendFactor", "SOURCE_COLOR", "sourceColor" },
		{ "Context3DBlendFactor", "ZERO", "zero" },
	};
	Avm2Class* cur = NULL;
	const char* cur_name = NULL;
	for (size_t i = 0; i < sizeof(consts) / sizeof(consts[0]); i++)
	{
		if (cur_name == NULL || strcmp(cur_name, consts[i].cls) != 0)
		{
			cur_name = consts[i].cls;
			cur = s3d_class(ctx, cur_name, obj);
		}
		s3d_sconst(ctx, cur, consts[i].name, consts[i].val);
	}

	// Context3DClearMask is the one int-valued bag (and unannotated).
	Avm2Class* cm = s3d_class(ctx, "Context3DClearMask", obj);
	avm2_builtin_add_static_const(ctx, cm, "COLOR", avm2_integer(1));
	avm2_builtin_add_static_const(ctx, cm, "DEPTH", avm2_integer(2));
	avm2_builtin_add_static_const(ctx, cm, "STENCIL", avm2_integer(4));
	avm2_builtin_add_static_const(ctx, cm, "ALL", avm2_integer(7));
}

// The flash.geom.Matrix3D handle, for PerspectiveProjection.toMatrix3D in
// avm2_display.c (avm2_builtin_class MINTS, so it must be shared not re-made).
Avm2Class* avm2_stage3d_matrix3d_class(void)
{ return g_matrix3d_class; }

static void register_matrix3d(Avm2Context* ctx)
{
	Avm2Class* m = avm2_builtin_class(ctx, "flash.geom", "Matrix3D",
	                                  ctx->builtins.object_class);
	g_matrix3d_class = m;
	g_vector3d_class = avm2_geom_vector3d_class();
	m->native_ext_size = sizeof(Avm2Matrix3DExt);
	m->instance_init.fn = matrix3d_init;
	m->instance_init.debug_name = "Matrix3D";
	avm2_builtin_add_getset(ctx, m, "rawData", matrix3d_get_raw_data,
	                        matrix3d_set_raw_data);
	avm2_builtin_add_getter(ctx, m, "determinant", matrix3d_get_determinant);
	avm2_builtin_add_getset(ctx, m, "position", matrix3d_get_position,
	                        matrix3d_set_position);
	avm2_builtin_add_method(ctx, m, "identity", matrix3d_identity);
	avm2_builtin_add_method(ctx, m, "clone", matrix3d_clone);
	avm2_builtin_add_method(ctx, m, "copyFrom", matrix3d_copy_from);
	avm2_builtin_add_method(ctx, m, "copyRawDataFrom", matrix3d_copy_raw_data_from);
	avm2_builtin_add_method(ctx, m, "copyRawDataTo", matrix3d_copy_raw_data_to);
	avm2_builtin_add_method(ctx, m, "transpose", matrix3d_transpose);
	avm2_builtin_add_method(ctx, m, "invert", matrix3d_invert);
	avm2_builtin_add_method(ctx, m, "append", matrix3d_append);
	avm2_builtin_add_method(ctx, m, "prepend", matrix3d_prepend);
	avm2_builtin_add_method(ctx, m, "appendTranslation", matrix3d_append_translation);
	avm2_builtin_add_method(ctx, m, "appendScale", matrix3d_append_scale);
	avm2_builtin_add_method(ctx, m, "appendRotation", matrix3d_append_rotation);
	avm2_builtin_add_method(ctx, m, "prependTranslation", matrix3d_prepend_translation);
	avm2_builtin_add_method(ctx, m, "prependScale", matrix3d_prepend_scale);
	avm2_builtin_add_method(ctx, m, "prependRotation", matrix3d_prepend_rotation);
	avm2_builtin_add_method(ctx, m, "transformVector", matrix3d_transform_vector);
	avm2_builtin_add_method(ctx, m, "deltaTransformVector",
	                        matrix3d_delta_transform_vector);
	avm2_builtin_add_method(ctx, m, "transformVectors",
	                        matrix3d_transform_vectors);
	avm2_builtin_add_method(ctx, m, "recompose", matrix3d_recompose);
	avm2_builtin_add_method(ctx, m, "decompose", matrix3d_decompose);
	avm2_builtin_add_method(ctx, m, "copyColumnTo", matrix3d_copy_column_to);
	avm2_builtin_add_method(ctx, m, "copyRowTo", matrix3d_copy_row_to);
	avm2_builtin_add_method(ctx, m, "copyColumnFrom", matrix3d_copy_column_from);
	avm2_builtin_add_method(ctx, m, "copyRowFrom", matrix3d_copy_row_from);
	avm2_builtin_add_method(ctx, m, "copyToMatrix3D", matrix3d_copy_to_matrix3d);
	// pointAt is a stub in Ruffle too (stub_method, no matrix change), so a
	// caller sees an unchanged matrix rather than an error.
	avm2_builtin_add_method(ctx, m, "pointAt", s3d_noop);
	avm2_builtin_add_method(ctx, m, "interpolateTo", s3d_noop);
	avm2_builtin_add_static_method(ctx, m, "interpolate", s3d_noop);

	// flash.geom.Orientation3D — the three strings recompose/decompose accept.
	Avm2Class* o3 = avm2_builtin_class(ctx, "flash.geom", "Orientation3D",
	                                   ctx->builtins.object_class);
	s3d_sconst(ctx, o3, "AXIS_ANGLE", "axisAngle");
	s3d_sconst(ctx, o3, "EULER_ANGLES", "eulerAngles");
	s3d_sconst(ctx, o3, "QUATERNION", "quaternion");

	// flash.geom.Utils3D. projectVector/projectVectors divide through by the
	// transformed w; pointTowards is a stub in Ruffle as well.
	Avm2Class* u3 = avm2_builtin_class(ctx, "flash.geom", "Utils3D",
	                                   ctx->builtins.object_class);
	avm2_builtin_add_static_method(ctx, u3, "projectVector",
	                               utils3d_project_vector);
	avm2_builtin_add_static_method(ctx, u3, "projectVectors",
	                               utils3d_project_vectors);
	avm2_builtin_add_static_method(ctx, u3, "pointTowards", s3d_noop);
}

void avm2_register_stage3d(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;
	Avm2Class* ed = b->event_dispatcher_class;

	register_constant_classes(ctx);
	register_matrix3d(ctx);

	// flash.display3D.Context3D (final, extends EventDispatcher).
	Avm2Class* c3d = s3d_class(ctx, "Context3D", ed);
	g_context3d_class = c3d;
	c3d->native_ext_size = sizeof(Avm2Context3DExt);
	avm2_builtin_add_getter(ctx, c3d, "profile", context3d_get_profile);
	avm2_builtin_add_getter(ctx, c3d, "driverInfo", context3d_get_driver_info);
	avm2_builtin_add_getset(ctx, c3d, "enableErrorChecking",
	                        context3d_get_error_checking,
	                        context3d_set_error_checking);
	avm2_builtin_add_getter(ctx, c3d, "backBufferWidth", context3d_get_2048);
	avm2_builtin_add_getter(ctx, c3d, "backBufferHeight", context3d_get_2048);
	avm2_builtin_add_getset(ctx, c3d, "maxBackBufferWidth", context3d_get_2048,
	                        s3d_noop);
	avm2_builtin_add_getset(ctx, c3d, "maxBackBufferHeight", context3d_get_2048,
	                        s3d_noop);
	avm2_builtin_add_static_getset(ctx, c3d, "supportsVideoTexture",
	                               context3d_get_supports_video_texture, NULL);
	avm2_builtin_add_method(ctx, c3d, "configureBackBuffer",
	                        context3d_configure_back_buffer);
	avm2_builtin_add_method(ctx, c3d, "createIndexBuffer",
	                        context3d_create_index_buffer);
	avm2_builtin_add_method(ctx, c3d, "createVertexBuffer",
	                        context3d_create_vertex_buffer);
	avm2_builtin_add_method(ctx, c3d, "createProgram", context3d_create_program);
	avm2_builtin_add_method(ctx, c3d, "createTexture", context3d_create_texture);
	avm2_builtin_add_method(ctx, c3d, "createCubeTexture",
	                        context3d_create_cube_texture);
	avm2_builtin_add_method(ctx, c3d, "createRectangleTexture",
	                        context3d_create_rectangle_texture);
	avm2_builtin_add_method(ctx, c3d, "createVideoTexture",
	                        context3d_create_video_texture);
	avm2_builtin_add_method(ctx, c3d, "setVertexBufferAt",
	                        context3d_set_vertex_buffer_at);
	avm2_builtin_add_method(ctx, c3d, "setProgram", s3d_noop);
	avm2_builtin_add_method(ctx, c3d, "setTextureAt", s3d_noop);
	avm2_builtin_add_method(ctx, c3d, "setColorMask", s3d_noop);
	avm2_builtin_add_method(ctx, c3d, "setStencilReferenceValue", s3d_noop);
	avm2_builtin_add_method(ctx, c3d, "setRenderToBackBuffer", s3d_noop);
	avm2_builtin_add_method(ctx, c3d, "drawToBitmapData", s3d_noop);
	avm2_builtin_add_method(ctx, c3d, "present", s3d_noop);
	avm2_builtin_add_method(ctx, c3d, "clear", context3d_clear);
	avm2_builtin_add_method(ctx, c3d, "drawTriangles", context3d_draw_triangles);
	avm2_builtin_add_method(ctx, c3d, "setCulling", context3d_set_culling);
	avm2_builtin_add_method(ctx, c3d, "setDepthTest", context3d_set_depth_test);
	avm2_builtin_add_method(ctx, c3d, "setBlendFactors",
	                        context3d_set_blend_factors);
	avm2_builtin_add_method(ctx, c3d, "setStencilActions",
	                        context3d_set_stencil_actions);
	avm2_builtin_add_method(ctx, c3d, "setSamplerStateAt",
	                        context3d_set_sampler_state_at);
	avm2_builtin_add_method(ctx, c3d, "setScissorRectangle",
	                        context3d_set_scissor_rectangle);
	avm2_builtin_add_method(ctx, c3d, "setProgramConstantsFromMatrix",
	                        context3d_set_program_constants_from_matrix);
	avm2_builtin_add_method(ctx, c3d, "setProgramConstantsFromVector",
	                        context3d_set_program_constants_from_vector);
	avm2_builtin_add_method(ctx, c3d, "setProgramConstantsFromByteArray",
	                        context3d_set_program_constants_from_byte_array);
	avm2_builtin_add_method(ctx, c3d, "setRenderToTexture",
	                        context3d_set_render_to_texture);
	avm2_builtin_add_method(ctx, c3d, "dispose", context3d_dispose);

	// flash.display3D.Program3D / VertexBuffer3D / IndexBuffer3D.
	Avm2Class* p3d = s3d_class(ctx, "Program3D", b->object_class);
	g_program3d_class = p3d;
	p3d->native_ext_size = sizeof(Avm2Program3DExt);
	avm2_builtin_add_method(ctx, p3d, "upload", program3d_upload);
	avm2_builtin_add_method(ctx, p3d, "dispose", s3d_noop);

	Avm2Class* vb = s3d_class(ctx, "VertexBuffer3D", b->object_class);
	g_vertexbuffer_class = vb;
	vb->native_ext_size = sizeof(Avm2Buffer3DExt);
	avm2_builtin_add_method(ctx, vb, "uploadFromByteArray", s3d_noop);
	avm2_builtin_add_method(ctx, vb, "uploadFromVector", s3d_noop);
	avm2_builtin_add_method(ctx, vb, "dispose", s3d_noop);

	Avm2Class* ib = s3d_class(ctx, "IndexBuffer3D", b->object_class);
	g_indexbuffer_class = ib;
	ib->native_ext_size = sizeof(Avm2Buffer3DExt);
	avm2_builtin_add_method(ctx, ib, "uploadFromByteArray", s3d_noop);
	avm2_builtin_add_method(ctx, ib, "uploadFromVector", s3d_noop);
	avm2_builtin_add_method(ctx, ib, "dispose", s3d_noop);

	// flash.display3D.textures.* — one ext for the whole ladder, so the
	// subclasses inherit native_ext_size from TextureBase.
	Avm2Class* tb = avm2_builtin_class(ctx, "flash.display3D.textures",
	                                   "TextureBase", ed);
	g_texturebase_class = tb;
	tb->native_ext_size = sizeof(Avm2Texture3DExt);
	avm2_builtin_add_method(ctx, tb, "dispose", s3d_noop);

	Avm2Class* tex = avm2_builtin_class(ctx, "flash.display3D.textures",
	                                    "Texture", tb);
	g_texture_class = tex;
	avm2_builtin_add_method(ctx, tex, "uploadFromBitmapData", s3d_noop);
	avm2_builtin_add_method(ctx, tex, "uploadFromByteArray", s3d_noop);
	avm2_builtin_add_method(ctx, tex, "uploadCompressedTextureFromByteArray",
	                        texture_upload_compressed_2d);

	Avm2Class* cube = avm2_builtin_class(ctx, "flash.display3D.textures",
	                                     "CubeTexture", tb);
	g_cubetexture_class = cube;
	avm2_builtin_add_method(ctx, cube, "uploadFromBitmapData", s3d_noop);
	avm2_builtin_add_method(ctx, cube, "uploadFromByteArray", s3d_noop);
	avm2_builtin_add_method(ctx, cube, "uploadCompressedTextureFromByteArray",
	                        texture_upload_compressed_cube);

	Avm2Class* rect = avm2_builtin_class(ctx, "flash.display3D.textures",
	                                     "RectangleTexture", tb);
	g_rectangletexture_class = rect;
	avm2_builtin_add_method(ctx, rect, "uploadFromBitmapData", s3d_noop);
	avm2_builtin_add_method(ctx, rect, "uploadFromByteArray", s3d_noop);

	Avm2Class* vt = avm2_builtin_class(ctx, "flash.display3D.textures",
	                                   "VideoTexture", tb);
	avm2_builtin_add_method(ctx, vt, "attachCamera", s3d_noop);
	avm2_builtin_add_method(ctx, vt, "attachNetStream", s3d_noop);

	// flash.display.Stage3D (extends EventDispatcher).
	// flash.display.Stage3D is [API("674")] in playerglobal: SWF 13 and up
	// (avm2/all_classes/display/swf12 does not list it).
	Avm2Class* s3d = avm2_builtin_class_api(ctx, "flash.display", "Stage3D",
	                                        ed, 13);
	g_stage3d_class = s3d;
	s3d->native_ext_size = sizeof(Avm2Stage3DExt);
	s3d->instance_init.fn = stage3d_init;
	s3d->instance_init.debug_name = "Stage3D";
	avm2_builtin_add_getter(ctx, s3d, "context3D", stage3d_get_context3d);
	avm2_builtin_add_getset(ctx, s3d, "visible", stage3d_get_visible,
	                        stage3d_set_visible);
	avm2_builtin_add_getset(ctx, s3d, "x", stage3d_get_x, stage3d_set_x);
	avm2_builtin_add_getset(ctx, s3d, "y", stage3d_get_y, stage3d_set_y);
	avm2_builtin_add_method(ctx, s3d, "requestContext3D",
	                        stage3d_request_context3d);
	avm2_builtin_add_method(ctx, s3d, "requestContext3DMatchingProfiles",
	                        stage3d_request_matching_profiles);

	// `stage.stage3Ds` — registered here rather than in avm2_display.c so the
	// whole Stage3D surface stays in one file.
	if (b->stage_class != NULL)
	{
		avm2_builtin_add_getter(ctx, b->stage_class, "stage3Ds",
		                        stage_get_stage3ds);
	}
}
