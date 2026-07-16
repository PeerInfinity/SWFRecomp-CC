// flash.media Sound family (Stage 10), ported from Ruffle
// core/src/avm2/globals/flash/media/* + core/src/display_object.rs SoundTransform.
//
//   SoundTransform  — 5 f64 channel gains + pan math (pure computation).
//   SoundChannel    — extends EventDispatcher; stores a core i32×100 sound
//                     transform (so the AS3 f64 round-trips through Flash's
//                     integer store); stop()/position/leftPeak/rightPeak.
//   SoundMixer      — static bufferTime (int) + a global i32×100 soundTransform.
//   Sound           — extends EventDispatcher; embedded DefineSound metadata
//                     via SymbolClass binding (length/bytesTotal from the
//                     recompiler table); play() returns a SoundChannel unless
//                     the start position is past the clip length (then null).
//
// Graphics builds additionally bridge to the shared src/audio mixer
// (audio.c): embedded DefineSound payloads register at boot
// (avm2_media_register_sounds), play()/stop()/stopAll()/soundTransform drive
// real mixer channels, and avm2_media_poll dispatches Event.SOUND_COMPLETE
// when a channel drains. The bridge is inert for trace grading: nothing here
// writes stdout, and channel positions only advance when an output sink pulls
// audio_mix (browser Web Audio) — never in the native test harness.
//
// NO_GRAPHICS builds compile the trace-graded surface only (the mixer does
// not exist there); the bridge bodies compile away.

#include <math.h>
#include <string.h>

#include <audio/audio.h>
#ifndef NO_GRAPHICS
#include <libswf/swf.h>   // full SWFAppContext (app->audio_ctx)
#endif

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_gc.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>
#include <avm2/avm2_value.h>

#ifndef NO_GRAPHICS
// Live playback registry for SOUND_COMPLETE: mixer channel index -> the AS3
// SoundChannel object whose playback occupies that slot. Entries are cleared
// on stop()/stopAll() (Flash does not dispatch soundComplete for manual
// stops) and when avm2_media_poll observes the channel drained. Registered
// objects are GC roots (avm2_gc_mark_roots_media) — the mixer slot may be the
// only live reference to a playing channel.
static Avm2Object* g_live_channels[MAX_SOUND_CHANNELS];
#endif

static int media_class_is_a(const Avm2Class* cls, const Avm2Class* ancestor)
{
	for (const Avm2Class* c = cls; c != NULL; c = c->super_class)
		if (c == ancestor) return 1;
	return 0;
}

static Avm2Object* this_obj(Avm2Activation* act)
{
	return act->this_val.kind == AVM2_VALUE_OBJECT ? act->this_val.u.obj : NULL;
}

// DefineSound rate code -> Hz (SWF19 §DefineSound). MP3 sounds use code 3.
static double rate_code_hz(uint8_t rate)
{
	static const double hz[4] = { 5512.5, 11025.0, 22050.0, 44100.0 };
	return hz[rate & 3];
}

// ---------------------------------------------------------------------------
// SoundTransform
// ---------------------------------------------------------------------------

typedef struct Avm2SoundTransformExt
{
	double left_to_left, left_to_right, right_to_left, right_to_right, volume;
} Avm2SoundTransformExt;

static Avm2SoundTransformExt* st_ext_of(Avm2Context* ctx, Avm2Value v)
{
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL) return NULL;
	Avm2Object* o = v.u.obj;
	if (o->cls == NULL || ctx->builtins.sound_transform_class == NULL) return NULL;
	if (!media_class_is_a(o->cls, ctx->builtins.sound_transform_class)) return NULL;
	return (Avm2SoundTransformExt*) o->native_ext;
}

static Avm2SoundTransformExt* this_st(Avm2Activation* act)
{
	return st_ext_of(act->ctx, act->this_val);
}

static void st_apply_pan(Avm2SoundTransformExt* st, double pan)
{
	st->left_to_left = sqrt(1.0 - pan);
	st->right_to_right = sqrt(1.0 + pan);
	st->left_to_right = 0.0;
	st->right_to_left = 0.0;
}

// SoundTransform(vol:Number = 1, panning:Number = 0)
static Avm2Value st_ctor(Avm2Activation* act)
{
	Avm2SoundTransformExt* st = this_st(act);
	if (st == NULL) return avm2_undefined();
	st->volume = act->argc > 0 ? avm2_coerce_to_number(act->ctx, act->args[0]) : 1.0;
	double pan = act->argc > 1 ? avm2_coerce_to_number(act->ctx, act->args[1]) : 0.0;
	st_apply_pan(st, pan);
	return avm2_undefined();
}

#define ST_ACCESSOR(field)                                                    \
	static Avm2Value st_get_##field(Avm2Activation* act)                      \
	{                                                                         \
		Avm2SoundTransformExt* st = this_st(act);                             \
		return avm2_number(st != NULL ? st->field : 0.0);                     \
	}                                                                         \
	static Avm2Value st_set_##field(Avm2Activation* act)                      \
	{                                                                         \
		Avm2SoundTransformExt* st = this_st(act);                             \
		if (st != NULL)                                                       \
			st->field = act->argc > 0                                         \
				? avm2_coerce_to_number(act->ctx, act->args[0]) : 0.0;        \
		return avm2_undefined();                                              \
	}

ST_ACCESSOR(left_to_left)
ST_ACCESSOR(left_to_right)
ST_ACCESSOR(right_to_left)
ST_ACCESSOR(right_to_right)
ST_ACCESSOR(volume)

static Avm2Value st_get_pan(Avm2Activation* act)
{
	Avm2SoundTransformExt* st = this_st(act);
	if (st == NULL) return avm2_number(0.0);
	if (st->left_to_right != 0.0 || st->right_to_left != 0.0)
		return avm2_number(0.0);
	return avm2_number(1.0 - pow(st->left_to_left, 2.0));
}

static Avm2Value st_set_pan(Avm2Activation* act)
{
	Avm2SoundTransformExt* st = this_st(act);
	if (st != NULL)
		st_apply_pan(st, act->argc > 0
			? avm2_coerce_to_number(act->ctx, act->args[0]) : 0.0);
	return avm2_undefined();
}

// Build an AS3 SoundTransform from core i32×100 fields (Ruffle
// SoundTransform::into_avm2_object).
static Avm2Object* st_from_core(Avm2Context* ctx, int32_t l2l, int32_t l2r,
                                int32_t r2l, int32_t r2r, int32_t vol)
{
	Avm2Value v = avm2_class_construct(ctx, ctx->builtins.sound_transform_class,
	                                   NULL, 0);
	Avm2SoundTransformExt* st = st_ext_of(ctx, v);
	if (st != NULL)
	{
		st->left_to_left = l2l / 100.0;
		st->left_to_right = l2r / 100.0;
		st->right_to_left = r2l / 100.0;
		st->right_to_right = r2r / 100.0;
		st->volume = vol / 100.0;
	}
	return v.u.obj;
}

Avm2Value avm2_sound_transform_from_core(Avm2Context* ctx, const int32_t core[5])
{
	return avm2_object_value(st_from_core(ctx, core[0], core[1], core[2],
	                                      core[3], core[4]));
}

int avm2_sound_transform_read(Avm2Context* ctx, Avm2Value v, int32_t out[5])
{
	Avm2SoundTransformExt* st = st_ext_of(ctx, v);
	if (st == NULL) return 0;
	out[0] = (int32_t) (st->left_to_left * 100.0);
	out[1] = (int32_t) (st->left_to_right * 100.0);
	out[2] = (int32_t) (st->right_to_left * 100.0);
	out[3] = (int32_t) (st->right_to_right * 100.0);
	out[4] = (int32_t) (st->volume * 100.0);
	return 1;
}

// ---------------------------------------------------------------------------
// SoundChannel
// ---------------------------------------------------------------------------

typedef struct Avm2SoundChannelExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	int32_t st_l2l, st_l2r, st_r2l, st_r2r, st_volume;  // core SoundTransform ×100
	// Mixer playback handle (graphics builds; see audio_start_sound_ex).
	// mixer_live means "a mixer start succeeded for this channel object" —
	// the (mixer_ch, mixer_gen) pair stays valid-checked on every use.
	int32_t mixer_ch;
	uint32_t mixer_gen;
	uint8_t mixer_live;
} Avm2SoundChannelExt;

static void sound_channel_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	(void) ctx;
	Avm2SoundChannelExt* sc = (Avm2SoundChannelExt*) obj->native_ext;
	sc->st_l2l = 100;
	sc->st_l2r = 0;
	sc->st_r2l = 0;
	sc->st_r2r = 100;
	sc->st_volume = 100;
	sc->mixer_ch = -1;
}

#ifndef NO_GRAPHICS
// Mixer gain vector {l2l, l2r, r2l, r2r, vol} from the channel's core
// i32×100 SoundTransform store.
static void sc_mixer_gains(const Avm2SoundChannelExt* sc, float gains[5])
{
	gains[0] = (float) sc->st_l2l / 100.0f;
	gains[1] = (float) sc->st_l2r / 100.0f;
	gains[2] = (float) sc->st_r2l / 100.0f;
	gains[3] = (float) sc->st_r2r / 100.0f;
	gains[4] = (float) sc->st_volume / 100.0f;
}
#endif

static Avm2SoundChannelExt* this_sc(Avm2Activation* act)
{
	Avm2Object* o = this_obj(act);
	if (o == NULL || o->cls == NULL
	    || !media_class_is_a(o->cls, act->ctx->builtins.sound_channel_class))
		return NULL;
	return (Avm2SoundChannelExt*) o->native_ext;
}

static Avm2Value sc_get_sound_transform(Avm2Activation* act)
{
	Avm2SoundChannelExt* sc = this_sc(act);
	if (sc == NULL) return avm2_undefined();
	return avm2_object_value(st_from_core(act->ctx, sc->st_l2l, sc->st_l2r,
	                                      sc->st_r2l, sc->st_r2r, sc->st_volume));
}

static Avm2Value sc_set_sound_transform(Avm2Activation* act)
{
	Avm2SoundChannelExt* sc = this_sc(act);
	if (sc == NULL) return avm2_undefined();
	Avm2SoundTransformExt* st = act->argc > 0
		? st_ext_of(act->ctx, act->args[0]) : NULL;
	if (st == NULL)
	{
		avm2_throw_error(act->ctx, act->ctx->builtins.type_error_class,
		                 "Error #2007: Parameter soundChannel must be non-null.");
	}
	sc->st_l2l = (int32_t) (st->left_to_left * 100.0);
	sc->st_l2r = (int32_t) (st->left_to_right * 100.0);
	sc->st_r2l = (int32_t) (st->right_to_left * 100.0);
	sc->st_r2r = (int32_t) (st->right_to_right * 100.0);
	sc->st_volume = (int32_t) (st->volume * 100.0);
#ifndef NO_GRAPHICS
	if (sc->mixer_live)
	{
		float gains[5];
		sc_mixer_gains(sc, gains);
		audio_channel_set_gains(act->ctx->app, sc->mixer_ch, sc->mixer_gen,
		                        gains);
	}
#endif
	return avm2_undefined();
}

static Avm2Value sc_get_position(Avm2Activation* act)
{
	Avm2SoundChannelExt* sc = this_sc(act);
	if (sc == NULL) return avm2_number(0.0);
#ifndef NO_GRAPHICS
	// Live mixer playback clock (browser builds; in the native test harness
	// nothing pulls audio_mix, so an active channel reports 0 — trace-inert).
	if (sc->mixer_live)
	{
		double pos = audio_channel_position_ms(act->ctx->app, sc->mixer_ch,
		                                       sc->mixer_gen);
		if (pos >= 0.0) return avm2_number(pos);
	}
#endif
	return avm2_number(0.0);
}

static Avm2Value sc_get_peak(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();  // no instance
}

static Avm2Value sc_stop(Avm2Activation* act)
{
#ifndef NO_GRAPHICS
	Avm2SoundChannelExt* sc = this_sc(act);
	if (sc != NULL && sc->mixer_live)
	{
		audio_channel_stop(act->ctx->app, sc->mixer_ch, sc->mixer_gen);
		// Manual stop: no soundComplete (Flash semantics) — unregister.
		if (g_live_channels[sc->mixer_ch] == this_obj(act))
			g_live_channels[sc->mixer_ch] = NULL;
		sc->mixer_live = 0;
	}
#else
	(void) act;
#endif
	return avm2_undefined();
}

static Avm2Object* sound_channel_new(Avm2Context* ctx)
{
	Avm2Value v = avm2_class_construct(ctx, ctx->builtins.sound_channel_class,
	                                   NULL, 0);
	return v.u.obj;
}

// ---------------------------------------------------------------------------
// SoundMixer (statics)
// ---------------------------------------------------------------------------

static int32_t g_mixer_buffer_time = 5;
static int32_t g_mixer_l2l = 100, g_mixer_l2r = 0, g_mixer_r2l = 0,
               g_mixer_r2r = 100, g_mixer_volume = 100;

static Avm2Value sm_get_buffer_time(Avm2Activation* act)
{
	(void) act;
	return avm2_integer(g_mixer_buffer_time);
}

static Avm2Value sm_set_buffer_time(Avm2Activation* act)
{
	g_mixer_buffer_time = act->argc > 0
		? avm2_coerce_to_i32(act->ctx, act->args[0]) : 0;
	return avm2_undefined();
}

static Avm2Value sm_get_sound_transform(Avm2Activation* act)
{
	return avm2_object_value(st_from_core(act->ctx, g_mixer_l2l, g_mixer_l2r,
	                                      g_mixer_r2l, g_mixer_r2r, g_mixer_volume));
}

static Avm2Value sm_set_sound_transform(Avm2Activation* act)
{
	Avm2SoundTransformExt* st = act->argc > 0
		? st_ext_of(act->ctx, act->args[0]) : NULL;
	if (st == NULL) return avm2_undefined();
	g_mixer_l2l = (int32_t) (st->left_to_left * 100.0);
	g_mixer_l2r = (int32_t) (st->left_to_right * 100.0);
	g_mixer_r2l = (int32_t) (st->right_to_left * 100.0);
	g_mixer_r2r = (int32_t) (st->right_to_right * 100.0);
	g_mixer_volume = (int32_t) (st->volume * 100.0);
#ifndef NO_GRAPHICS
	// Global transform applies at mix time as the output master volume
	// (pan cross-gains on the global transform are not wired — volume is
	// what real content uses).
	audio_set_master_volume(act->ctx->app, (float) g_mixer_volume / 100.0f);
#endif
	return avm2_undefined();
}

static Avm2Value sm_stop_all(Avm2Activation* act)
{
#ifndef NO_GRAPHICS
	audio_stop_all_sounds(act->ctx->app);
	// stopAll is a manual stop: no soundComplete for any channel.
	memset(g_live_channels, 0, sizeof(g_live_channels));
#else
	(void) act;
#endif
	return avm2_undefined();
}

static Avm2Value sm_are_sounds_inaccessible(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(false);
}

// ---------------------------------------------------------------------------
// Sound
// ---------------------------------------------------------------------------

typedef struct Avm2SoundObjExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	uint8_t has_sound;
	uint16_t char_id;    // DefineSound char id (0 = none; mixer asset key)
	uint32_t sample_count;
	double sample_rate;
	uint32_t data_size;  // bytesTotal (compressed, excl. MP3 seek prefix)
} Avm2SoundObjExt;

static Avm2SoundObjExt* sound_ext_of(Avm2Context* ctx, Avm2Object* o)
{
	if (o == NULL || o->cls == NULL
	    || !media_class_is_a(o->cls, ctx->builtins.sound_class))
		return NULL;
	return (Avm2SoundObjExt*) o->native_ext;
}

static Avm2SoundObjExt* this_sound(Avm2Activation* act)
{
	return sound_ext_of(act->ctx, this_obj(act));
}

static const Avm2SoundData* sound_data_for_char(uint16_t char_id)
{
	for (uint32_t i = 0; i < avm2_generated_sound_count; i++)
		if (avm2_generated_sounds[i].char_id == char_id)
			return &avm2_generated_sounds[i];
	return NULL;
}

// Sound(stream:URLRequest = null, context:SoundLoaderContext = null).
static Avm2Value sound_ctor(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = this_obj(act);
	Avm2SoundObjExt* s = sound_ext_of(ctx, self);
	if (s == NULL) return avm2_undefined();
	// SymbolClass-bound embedded sound: seed metadata from the DefineSound
	// table (ignores any ctor args, like BitmapData subclasses do).
	uint16_t char_id = avm2_display_char_for_class(self->cls);
	const Avm2SoundData* sd = char_id != 0 ? sound_data_for_char(char_id) : NULL;
	if (sd != NULL)
	{
		s->has_sound = 1;
		s->char_id = char_id;
		s->sample_count = sd->sample_count;
		s->sample_rate = rate_code_hz(sd->rate);
		s->data_size = sd->data_size;
	}
	// External URL loading (new Sound(urlReq)) is deferred; leave has_sound 0.
	return avm2_undefined();
}

static double sound_length_ms(Avm2SoundObjExt* s)
{
	if (s == NULL || !s->has_sound || s->sample_rate <= 0) return 0.0;
	return (double) s->sample_count * 1000.0 / s->sample_rate;
}

static Avm2Value sound_get_length(Avm2Activation* act)
{
	return avm2_number(sound_length_ms(this_sound(act)));
}

static Avm2Value sound_get_bytes_total(Avm2Activation* act)
{
	Avm2SoundObjExt* s = this_sound(act);
	return avm2_integer(s != NULL ? (int32_t) s->data_size : 0);
}

static Avm2Value sound_get_bytes_loaded(Avm2Activation* act)
{
	Avm2SoundObjExt* s = this_sound(act);
	return avm2_uint_value(s != NULL ? s->data_size : 0);
}

static Avm2Value sound_get_is_buffering(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(false);
}

static Avm2Value sound_get_is_url_inaccessible(Avm2Activation* act)
{
	(void) act;
	return avm2_bool(false);
}

static Avm2Value sound_get_url(Avm2Activation* act)
{
	(void) act;
	return avm2_null();
}

static Avm2Value sound_get_id3(Avm2Activation* act)
{
	(void) act;
	return avm2_null();
}

// play(startTime:Number = 0, loops:int = 0, sndTransform:SoundTransform = null)
// Returns a SoundChannel, or null when startTime is past the clip length
// (Ruffle play_queued: position > duration -> false -> null).
static Avm2Value sound_play(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2SoundObjExt* s = this_sound(act);
	if (s == NULL) return avm2_null();
	double position = act->argc > 0 ? avm2_coerce_to_number(ctx, act->args[0]) : 0.0;
	if (s->has_sound && position > sound_length_ms(s))
		return avm2_null();
	Avm2Object* ch = sound_channel_new(ctx);
	// Apply the optional sound transform to the channel (core i32×100).
	Avm2SoundTransformExt* st = act->argc > 2 ? st_ext_of(ctx, act->args[2]) : NULL;
	if (st != NULL && ch != NULL)
	{
		Avm2SoundChannelExt* sc = (Avm2SoundChannelExt*) ch->native_ext;
		sc->st_l2l = (int32_t) (st->left_to_left * 100.0);
		sc->st_l2r = (int32_t) (st->left_to_right * 100.0);
		sc->st_r2l = (int32_t) (st->right_to_left * 100.0);
		sc->st_r2r = (int32_t) (st->right_to_right * 100.0);
		sc->st_volume = (int32_t) (st->volume * 100.0);
	}
#ifndef NO_GRAPHICS
	// Start real playback on the shared mixer. AS3 loops semantics: the
	// sound plays max(loops, 1) times total, each pass restarting at
	// startTime (Ruffle play_queued) — the mixer takes the ADDITIONAL plays.
	if (ch != NULL && s->has_sound && s->char_id != 0)
	{
		Avm2SoundChannelExt* sc = (Avm2SoundChannelExt*) ch->native_ext;
		int32_t loops = act->argc > 1 ? avm2_coerce_to_i32(ctx, act->args[1]) : 0;
		if (loops < 1) loops = 1;
		float gains[5];
		sc_mixer_gains(sc, gains);
		uint32_t gen = 0;
		int mch = audio_start_sound_ex(ctx->app, s->char_id,
		                               (uint32_t) (loops - 1), position,
		                               gains, &gen);
		if (mch >= 0)
		{
			sc->mixer_ch = mch;
			sc->mixer_gen = gen;
			sc->mixer_live = 1;
			g_live_channels[mch] = ch;
		}
	}
#endif
	return avm2_object_value(ch);
}

static Avm2Value sound_close(Avm2Activation* act)
{
	(void) act;
	return avm2_undefined();
}

static Avm2Value sound_load(Avm2Activation* act)
{
	// External loading deferred; a no-op keeps SymbolClass-bound sounds usable.
	(void) act;
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// Mixer lifecycle (graphics builds; all no-ops under NO_GRAPHICS)
// ---------------------------------------------------------------------------

// Register every embedded DefineSound payload with the shared mixer so
// Sound.play() can start it. Called once at AVM2 boot (runSWF_avm2).
void avm2_media_register_sounds(Avm2Context* ctx)
{
#ifndef NO_GRAPHICS
	if (avm2_generated_sound_count == 0) return;
	if (ctx->app->audio_ctx == NULL) audio_init(ctx->app);
	for (uint32_t i = 0; i < avm2_generated_sound_count; i++)
	{
		const Avm2SoundData* sd = &avm2_generated_sounds[i];
		if (sd->data == NULL || sd->data_len == 0) continue;
		audio_define_sound(ctx->app, sd->char_id, sd->format, sd->rate,
		                   sd->sample_size, sd->stereo, sd->sample_count,
		                   sd->data, sd->data_len);
	}
#else
	(void) ctx;
#endif
}

// Dispatch Event.SOUND_COMPLETE for channels whose mixer playback drained.
// Called once per tick after frame scripts (may run user handlers — the
// caller wraps it in the tick's catch-all try frame).
void avm2_media_poll(Avm2Context* ctx)
{
#ifndef NO_GRAPHICS
	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		Avm2Object* obj = g_live_channels[i];
		if (obj == NULL) continue;
		Avm2SoundChannelExt* sc = (Avm2SoundChannelExt*) obj->native_ext;
		if (audio_channel_active(ctx->app, sc->mixer_ch, sc->mixer_gen))
			continue;
		// Unregister BEFORE dispatch: the handler may call play() and land
		// on this same (now free) mixer slot.
		g_live_channels[i] = NULL;
		sc->mixer_live = 0;
		Avm2Object* ev = avm2_event_new(
			ctx, avm2_string_from_literal(ctx, "soundComplete"), 0, 0);
		avm2_dispatch_event(ctx, obj, ev);
	}
#else
	(void) ctx;
#endif
}

// GC root marker: a playing SoundChannel may be referenced only by the
// mixer registry (fire-and-forget play()); keep it alive until it drains.
void avm2_gc_mark_roots_media(Avm2Context* ctx)
{
	(void) ctx;
#ifndef NO_GRAPHICS
	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		if (g_live_channels[i] != NULL)
			avm2_gc_mark_object(g_live_channels[i]);
	}
#endif
}

// ---------------------------------------------------------------------------
// Registration
// ---------------------------------------------------------------------------

void avm2_register_media(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;

	// flash.media.SoundTransform (final, extends Object).
	Avm2Class* st = avm2_builtin_class(ctx, "flash.media", "SoundTransform",
	                                   b->object_class);
	st->instance_init.fn = st_ctor;
	st->instance_init.debug_name = "SoundTransform";
	st->native_ext_size = sizeof(Avm2SoundTransformExt);
	b->sound_transform_class = st;
	avm2_builtin_add_getset(ctx, st, "leftToLeft", st_get_left_to_left,
	                        st_set_left_to_left);
	avm2_builtin_add_getset(ctx, st, "leftToRight", st_get_left_to_right,
	                        st_set_left_to_right);
	avm2_builtin_add_getset(ctx, st, "rightToLeft", st_get_right_to_left,
	                        st_set_right_to_left);
	avm2_builtin_add_getset(ctx, st, "rightToRight", st_get_right_to_right,
	                        st_set_right_to_right);
	avm2_builtin_add_getset(ctx, st, "volume", st_get_volume, st_set_volume);
	avm2_builtin_add_getset(ctx, st, "pan", st_get_pan, st_set_pan);

	// flash.media.SoundChannel (final, extends EventDispatcher).
	Avm2Class* sc = avm2_builtin_class(ctx, "flash.media", "SoundChannel",
	                                   b->event_dispatcher_class);
	sc->native_ext_size = sizeof(Avm2SoundChannelExt);
	sc->native_init = sound_channel_native_init;
	b->sound_channel_class = sc;
	avm2_builtin_add_getset(ctx, sc, "soundTransform", sc_get_sound_transform,
	                        sc_set_sound_transform);
	avm2_builtin_add_getset(ctx, sc, "position", sc_get_position, NULL);
	avm2_builtin_add_getset(ctx, sc, "leftPeak", sc_get_peak, NULL);
	avm2_builtin_add_getset(ctx, sc, "rightPeak", sc_get_peak, NULL);
	avm2_builtin_add_method(ctx, sc, "stop", sc_stop);

	// flash.media.SoundMixer (all statics).
	Avm2Class* sm = avm2_builtin_class(ctx, "flash.media", "SoundMixer",
	                                   b->object_class);
	avm2_builtin_add_static_getset(ctx, sm, "bufferTime", sm_get_buffer_time,
	                               sm_set_buffer_time);
	avm2_builtin_add_static_getset(ctx, sm, "soundTransform",
	                               sm_get_sound_transform, sm_set_sound_transform);
	avm2_builtin_add_static_method(ctx, sm, "stopAll", sm_stop_all);
	avm2_builtin_add_static_method(ctx, sm, "areSoundsInaccessible",
	                               sm_are_sounds_inaccessible);

	// flash.media.Sound (extends EventDispatcher).
	Avm2Class* snd = avm2_builtin_class(ctx, "flash.media", "Sound",
	                                    b->event_dispatcher_class);
	snd->instance_init.fn = sound_ctor;
	snd->instance_init.debug_name = "Sound";
	snd->native_ext_size = sizeof(Avm2SoundObjExt);
	b->sound_class = snd;
	avm2_builtin_add_getset(ctx, snd, "length", sound_get_length, NULL);
	avm2_builtin_add_getset(ctx, snd, "bytesTotal", sound_get_bytes_total, NULL);
	avm2_builtin_add_getset(ctx, snd, "bytesLoaded", sound_get_bytes_loaded, NULL);
	avm2_builtin_add_getset(ctx, snd, "isBuffering", sound_get_is_buffering, NULL);
	avm2_builtin_add_getset(ctx, snd, "isURLInaccessible",
	                        sound_get_is_url_inaccessible, NULL);
	avm2_builtin_add_getset(ctx, snd, "url", sound_get_url, NULL);
	avm2_builtin_add_getset(ctx, snd, "id3", sound_get_id3, NULL);
	avm2_builtin_add_method(ctx, snd, "play", sound_play);
	avm2_builtin_add_method(ctx, snd, "close", sound_close);
	avm2_builtin_add_method(ctx, snd, "load", sound_load);
}
