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
// flash.media.AVTagData — a value object carrying an AV tag's payload and
// the media time it belongs to. Both are read-only after construction.
// ---------------------------------------------------------------------------

static Avm2Value avtagdata_ctor(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->this_val.kind != AVM2_VALUE_OBJECT) return avm2_undefined();
	Avm2Object* self = act->this_val.u.obj;
	Avm2Value data = (act->argc > 0) ? act->args[0] : avm2_null();
	if (data.kind != AVM2_VALUE_NULL && data.kind != AVM2_VALUE_UNDEFINED)
		data = avm2_string(avm2_coerce_to_string(ctx, data));
	double local = (act->argc > 1) ? avm2_coerce_to_number(ctx, act->args[1])
	                               : 0.0;
	avm2_object_set_dynamic(ctx, self, "_data", 5, data)->dont_enum = 1;
	avm2_object_set_dynamic(ctx, self, "_localTime", 10,
	                        avm2_number(local))->dont_enum = 1;
	return avm2_undefined();
}

static Avm2Value avtagdata_get_data(Avm2Activation* act)
{
	return avm2_get_public_property(act->ctx, act->this_val, "_data", 5, NULL);
}

static Avm2Value avtagdata_get_local_time(Avm2Activation* act)
{
	return avm2_get_public_property(act->ctx, act->this_val, "_localTime", 10,
	                                NULL);
}

// ---------------------------------------------------------------------------
// The rest of the flash.media.AV* value-object family (13 classes)
// ---------------------------------------------------------------------------
//
// AVTagData above is the shape they all share: a constructor that coerces its
// arguments into DECLARED slot types, then getter-only (for two of them,
// get/set) access to the results. That slot typing is most of what av_classes
// grades -- `new AVABRParameters("hello", 2.2, 3.3, 4.4)` reads back 2/3/4
// because those slots are `int`, and AVTrackInfo's 7.7 reads back as the
// STRING "7.7" while its 8.8 reads back as the int 8.
//
// The backing store is a fixed set of dont-enum dynamic props "_av0".."_av10",
// so the GC traces them for free (no native_ext, no mark hook), and one
// accessor per slot INDEX serves every class in the family.

#define AV_MAX_SLOTS 11

static const char* const AV_SLOT_NAMES[AV_MAX_SLOTS] = {
	"_av0", "_av1", "_av2", "_av3", "_av4", "_av5",
	"_av6", "_av7", "_av8", "_av9", "_av10"
};

static Avm2Value av_slot_get(Avm2Activation* act, int i)
{
	const char* n = AV_SLOT_NAMES[i];
	return avm2_get_public_property(act->ctx, act->this_val, n,
	                                (uint32_t) strlen(n), NULL);
}

// 'S' String, 'I' int, 'N' Number, 'B' Boolean, 'O' a typed object slot.
static Avm2Value av_coerce(Avm2Context* ctx, Avm2Value v, char type)
{
	switch (type)
	{
		case 'S':
			// String is nullable, so null/undefined survive as null.
			return (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
				? avm2_null() : avm2_string(avm2_coerce_to_string(ctx, v));
		case 'I': return avm2_integer(avm2_coerce_to_i32(ctx, v));
		case 'N': return avm2_number(avm2_coerce_to_number(ctx, v));
		case 'B': return avm2_bool(avm2_coerce_to_boolean(v));
		default:  return (v.kind == AVM2_VALUE_OBJECT) ? v : avm2_null();
	}
}

static void av_slot_put(Avm2Activation* act, int i, Avm2Value v)
{
	if (act->this_val.kind != AVM2_VALUE_OBJECT) return;
	const char* n = AV_SLOT_NAMES[i];
	avm2_object_set_dynamic(act->ctx, act->this_val.u.obj, n,
	                        (uint32_t) strlen(n), v)->dont_enum = 1;
}

static Avm2Value av_slot_set(Avm2Activation* act, int i, char type)
{
	Avm2Value v = (act->argc > 0) ? act->args[0] : avm2_undefined();
	av_slot_put(act, i, av_coerce(act->ctx, v, type));
	return avm2_undefined();
}

// A constructor body IS the declared parameter-type string, nothing more.
static Avm2Value av_ctor(Avm2Activation* act, const char* types)
{
	for (int i = 0; types[i] != '\0' && i < AV_MAX_SLOTS; i++)
	{
		Avm2Value v = ((uint32_t) i < act->argc) ? act->args[i]
		                                        : avm2_undefined();
		av_slot_put(act, i, av_coerce(act->ctx, v, types[i]));
	}
	return avm2_undefined();
}

#define AV_GETTER(i)                                                          \
	static Avm2Value av_get_##i(Avm2Activation* act)                          \
	{ return av_slot_get(act, i); }
#define AV_SETTER_S(i)                                                        \
	static Avm2Value av_set_s##i(Avm2Activation* act)                         \
	{ return av_slot_set(act, i, 'S'); }
#define AV_SETTER_I(i)                                                        \
	static Avm2Value av_set_i##i(Avm2Activation* act)                         \
	{ return av_slot_set(act, i, 'I'); }

AV_GETTER(0)  AV_GETTER(1)  AV_GETTER(2)  AV_GETTER(3)
AV_GETTER(4)  AV_GETTER(5)  AV_GETTER(6)  AV_GETTER(7)
AV_GETTER(8)  AV_GETTER(9)  AV_GETTER(10)
// Only two of the family are writable at all: AVCaptionStyle (11 String
// props) and AVABRParameters (one String plus three ints).
AV_SETTER_S(0)  AV_SETTER_S(1)  AV_SETTER_S(2)  AV_SETTER_S(3)
AV_SETTER_S(4)  AV_SETTER_S(5)  AV_SETTER_S(6)  AV_SETTER_S(7)
AV_SETTER_S(8)  AV_SETTER_S(9)  AV_SETTER_S(10)
AV_SETTER_I(1)  AV_SETTER_I(2)  AV_SETTER_I(3)

#undef AV_GETTER
#undef AV_SETTER_S
#undef AV_SETTER_I

static Avm2MethodFn const AV_GETTERS[AV_MAX_SLOTS] = {
	av_get_0, av_get_1, av_get_2, av_get_3, av_get_4, av_get_5,
	av_get_6, av_get_7, av_get_8, av_get_9, av_get_10
};

static Avm2Value avabrparams_ctor(Avm2Activation* act)
{ return av_ctor(act, "SIII"); }
static Avm2Value avabrprofile_ctor(Avm2Activation* act)
{ return av_ctor(act, "III"); }
static Avm2Value avcuepoint_ctor(Avm2Activation* act)
{ return av_ctor(act, "ON"); }
static Avm2Value avresult_ctor(Avm2Activation* act)
{ return av_ctor(act, "I"); }
// AVInsertionResult extends AVResult, but a builtin class's instance_init is
// never chained (avm2_class_construct calls only the most-derived one), so it
// writes its inherited `result` slot itself.
static Avm2Value avinsertion_ctor(Avm2Activation* act)
{ return av_ctor(act, "IIB"); }
static Avm2Value avperiodinfo_ctor(Avm2Activation* act)
{ return av_ctor(act, "NNNIIIIIBN"); }
static Avm2Value avplaystate_ctor(Avm2Activation* act)
{ return av_ctor(act, "I"); }
static Avm2Value avtimeline_ctor(Avm2Activation* act)
{ return av_ctor(act, "SNNIIIIB"); }
static Avm2Value avtrackinfo_ctor(Avm2Activation* act)
{ return av_ctor(act, "SSBBBBSI"); }

// AVCaptionStyle takes no arguments; every field initialises to "" EXCEPT
// bottomInset, which initialises to the string "0".
static Avm2Value avcaptionstyle_ctor(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	for (int i = 0; i < 11; i++)
	{
		av_slot_put(act, i, avm2_string(
			avm2_string_from_literal(ctx, (i == 2) ? "0" : "")));
	}
	return avm2_undefined();
}

static void av_iconst(Avm2Context* ctx, Avm2Class* cls, const char* n, int32_t v)
{ avm2_builtin_add_static_const(ctx, cls, n, avm2_integer(v)); }

static void av_sconst(Avm2Context* ctx, Avm2Class* cls, const char* n,
                      const char* v)
{
	avm2_builtin_add_static_const(ctx, cls, n,
	                              avm2_string(avm2_string_from_literal(ctx, v)));
}

// Register names[0..n) as getter-only props bound to slots first_slot..+n.
static void av_add_ro_props(Avm2Context* ctx, Avm2Class* cls,
                            const char* const* names, int n, int first_slot)
{
	for (int i = 0; i < n; i++)
	{
		avm2_builtin_add_getset(ctx, cls, names[i],
		                        AV_GETTERS[first_slot + i], NULL);
	}
}

static Avm2Class* av_class(Avm2Context* ctx, const char* name, Avm2Class* super,
                           Avm2MethodFn ctor)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "flash.media", name, super);
	if (ctor != NULL)
	{
		cls->instance_init.fn = ctor;
		cls->instance_init.debug_name = name;
	}
	return cls;
}

static void register_av_classes(Avm2Context* ctx)
{
	Avm2Class* obj = ctx->builtins.object_class;
	Avm2Class* ed = ctx->builtins.event_dispatcher_class;
	if (ed == NULL) ed = obj;

	// --- AVABRParameters
	{
		Avm2Class* cls = av_class(ctx, "AVABRParameters", obj,
		                          avabrparams_ctor);
		avm2_builtin_add_getset(ctx, cls, "policy", av_get_0, av_set_s0);
		avm2_builtin_add_getset(ctx, cls, "startBitsPerSecond",
		                        av_get_1, av_set_i1);
		avm2_builtin_add_getset(ctx, cls, "minBitsPerSecond",
		                        av_get_2, av_set_i2);
		avm2_builtin_add_getset(ctx, cls, "maxBitsPerSecond",
		                        av_get_3, av_set_i3);
		av_sconst(ctx, cls, "AGGRESSIVE", "aggressive");
		av_sconst(ctx, cls, "CONSERVATIVE", "conservative");
		av_sconst(ctx, cls, "MODERATE", "moderate");
	}

	// --- AVABRProfileInfo
	{
		static const char* const props[] = {
			"bitsPerSecond", "width", "height"
		};
		Avm2Class* cls = av_class(ctx, "AVABRProfileInfo", obj,
		                          avabrprofile_ctor);
		av_add_ro_props(ctx, cls, props, 3, 0);
	}

	// --- AVCaptionStyle
	{
		static const char* const props[] = {
			"backgroundColor", "backgroundOpacity", "bottomInset", "edgeColor",
			"fillColor", "fillOpacity", "font", "fontColor", "fontEdge",
			"fontOpacity", "size"
		};
		static Avm2MethodFn const setters[] = {
			av_set_s0, av_set_s1, av_set_s2, av_set_s3, av_set_s4, av_set_s5,
			av_set_s6, av_set_s7, av_set_s8, av_set_s9, av_set_s10
		};
		static const struct { const char* n; const char* v; } consts[] = {
			{ "DEFAULT", "default" },
			{ "NONE", "none" },
			{ "MONOSPACE_WITH_SERIFS", "monospaced_with_serifs" },
			{ "MONOSPACED_WITHOUT_SERIFS", "monospaced_without_serifs" },
			{ "PROPORTIONAL_WITH_SERIFS", "proportional_with_serifs" },
			{ "PROPORTIONAL_WITHOUT_SERIFS", "proportional_without_serifs" },
			{ "CASUAL", "casual" },
			{ "CURSIVE", "cursive" },
			{ "DEPRESSED", "depressed" },
			{ "RAISED", "raised" },
			{ "SMALL_CAPITALS", "small_capitals" },
			{ "UNIFORM", "uniform" },
			{ "SMALL", "small" },
			{ "MEDIUM", "medium" },
			{ "LARGE", "large" },
			{ "BRIGHT_MAGENTA", "bright_magenta" },
			{ "MAGENTA", "magenta" },
			{ "DARK_MAGENTA", "dark_magenta" },
			{ "BRIGHT_RED", "bright_red" },
			{ "RED", "red" },
			{ "DARK_RED", "dark_red" },
			{ "BRIGHT_YELLOW", "bright_yellow" },
			{ "YELLOW", "yellow" },
			{ "DARK_YELLOW", "dark_yellow" },
			{ "BRIGHT_GREEN", "bright_green" },
			{ "GREEN", "green" },
			{ "DARK_GREEN", "dark_green" },
			{ "BRIGHT_CYAN", "bright_cyan" },
			{ "CYAN", "cyan" },
			{ "DARK_CYAN", "dark_cyan" },
			{ "BRIGHT_BLUE", "bright_blue" },
			{ "BLUE", "blue" },
			{ "DARK_BLUE", "dark_blue" },
			{ "BRIGHT_WHITE", "bright_white" },
			{ "WHITE", "white" },
			{ "GRAY", "gray" },
			{ "BLACK", "black" },
			// Not a transposition: FP really does put the side LAST.
			{ "LEFT_DROP_SHADOW", "drop_shadow_left" },
			{ "RIGHT_DROP_SHADOW", "drop_shadow_right" },
		};
		Avm2Class* cls = av_class(ctx, "AVCaptionStyle", obj,
		                          avcaptionstyle_ctor);
		for (int i = 0; i < 11; i++)
			avm2_builtin_add_getset(ctx, cls, props[i], AV_GETTERS[i],
			                        setters[i]);
		for (size_t i = 0; i < sizeof(consts) / sizeof(consts[0]); i++)
			av_sconst(ctx, cls, consts[i].n, consts[i].v);
	}

	// --- AVCuePoint: the Dictionary is held BY IDENTITY, not stringified.
	{
		static const char* const props[] = { "dictionary", "localTime" };
		Avm2Class* cls = av_class(ctx, "AVCuePoint", obj, avcuepoint_ctor);
		av_add_ro_props(ctx, cls, props, 2, 0);
	}

	// --- AVResult, then AVInsertionResult which extends it.
	Avm2Class* avresult;
	{
		static const char* const props[] = { "result" };
		static const struct { const char* n; int32_t v; } consts[] = {
			{ "END_OF_PERIOD", -1 },
			{ "SUCCESS", 0 },
			{ "ASYNC_OPERATION_IN_PROGRESS", 1 },
			{ "EOF", 2 },
			{ "DECODER_FAILED", 3 },
			{ "DEVICE_OPEN_ERROR", 4 },
			{ "FILE_NOT_FOUND", 5 },
			{ "GENERIC_ERROR", 6 },
			{ "IRRECOVERABLE_ERROR", 7 },
			{ "LOST_CONNECTION_RECOVERABLE", 8 },
			{ "NO_FIXED_SIZE", 9 },
			{ "NOT_IMPLEMENTED", 10 },
			{ "OUT_OF_MEMORY", 11 },
			{ "PARSE_ERROR", 12 },
			{ "SIZE_UNKNOWN", 13 },
			{ "UNDERFLOW", 14 },
			{ "UNSUPPORTED_CONFIGURATION", 15 },
			{ "UNSUPPORTED_OPERATION", 16 },
			{ "WAITING_FOR_INIT", 17 },
			{ "INVALID_PARAMETER", 18 },
			{ "INVALID_OPERATION", 19 },
			{ "ONLY_ALLOWED_IN_PAUSED_STATE", 20 },
			{ "INVALID_WITH_AUDIO_ONLY_FILE", 21 },
			{ "PREVIOUS_STEP_SEEK_IN_PROGRESS", 22 },
			{ "RESOURCE_NOT_SPECIFIED", 23 },
			{ "RANGE_ERROR", 24 },
			{ "INVALID_SEEK_TIME", 25 },
			{ "FILE_STRUCTURE_INVALID", 26 },
			{ "COMPONENT_CREATION_FAILURE", 27 },
			{ "DRM_INIT_ERROR", 28 },
			{ "CONTAINER_NOT_SUPPORTED", 29 },
			{ "SEEK_FAILED", 30 },
			{ "CODEC_NOT_SUPPORTED", 31 },
			{ "NETWORK_UNAVAILABLE", 32 },
			{ "NETWORK_ERROR", 33 },
			{ "OVERFLOW", 34 },
			{ "VIDEO_PROFILE_NOT_SUPPORTED", 35 },
			{ "PERIOD_NOT_LOADED", 36 },
			{ "INVALID_REPLACE_DURATION", 37 },
			{ "CALLED_FROM_WRONG_THREAD", 38 },
			{ "FRAGMENT_READ_ERROR", 39 },
			{ "OPERATION_ABORTED", 40 },
			{ "UNSUPPORTED_HLS_VERSION", 41 },
			{ "CANNOT_FAIL_OVER", 42 },
			{ "HTTP_TIME_OUT", 43 },
			{ "NETWORK_DOWN", 44 },
			{ "NO_USEABLE_BITRATE_PROFILE", 45 },
			{ "BAD_MANIFEST_SIGNATURE", 46 },
			{ "CANNOT_LOAD_PLAY_LIST", 47 },
			{ "REPLACEMENT_FAILED", 48 },
			{ "SWITCH_TO_ASYMMETRIC_PROFILE", 49 },
			{ "LIVE_WINDOW_MOVED_BACKWARD", 50 },
			{ "CURRENT_PERIOD_EXPIRED", 51 },
			{ "CONTENT_LENGTH_MISMATCH", 52 },
			{ "PERIOD_HOLD", 53 },
			{ "LIVE_HOLD", 54 },
			{ "BAD_MEDIA_INTERLEAVING", 55 },
			{ "DRM_NOT_AVAILABLE", 56 },
			{ "PLAYBACK_NOT_ENABLED", 57 },
			{ "BAD_MEDIASAMPLE_FOUND", 58 },
			{ "RANGE_SPANS_READHEAD", 59 },
			{ "POSTROLL_WITH_LIVE_NOT_ALLOWED", 60 },
			{ "INTERNAL_ERROR", 61 },
			{ "SPS_PPS_FOUND_OUTSIDE_AVCC", 62 },
			{ "PARTIAL_REPLACEMENT", 63 },
			{ "RENDITION_M3U8_ERROR", 64 },
			{ "NULL_OPERATION", 65 },
			{ "SEGMENT_SKIPPED_ON_FAILURE", 66 },
			{ "INCOMPATIBLE_RENDER_MODE", 67 },
			{ "PROTOCOL_NOT_SUPPORTED", 68 },
			{ "INCOMPATIBLE_VERSION", 69 },
			{ "MANIFEST_FILE_UNEXPECTEDLY_CHANGED", 70 },
			{ "CANNOT_SPLIT_TIMELINE", 71 },
			{ "CANNOT_ERASE_TIMELINE", 72 },
			{ "DID_NOT_GET_NEXT_FRAGMENT", 73 },
			{ "NO_TIMELINE", 74 },
			{ "LISTENER_NOT_FOUND", 75 },
			{ "AUDIO_START_ERROR", 76 },
			{ "NO_AUDIO_SINK", 77 },
			{ "FILE_OPEN_ERROR", 78 },
			{ "FILE_WRITE_ERROR", 79 },
			{ "FILE_READ_ERROR", 80 },
			{ "ID3_PARSE_ERROR", 81 },
			{ "SECURITY_ERROR", 82 },
			{ "TIMELINE_TOO_SHORT", 83 },
			{ "AUDIO_ONLY_STREAM_START", 84 },
			{ "AUDIO_ONLY_STREAM_END", 85 },
			{ "CANNOT_HANDLE_MAIN_MANIFEST_UPDATE", 86 },
			{ "KEY_NOT_FOUND", 87 },
			{ "INVALID_KEY", 88 },
			{ "KEY_SERVER_NOT_FOUND", 89 },
			{ "MAIN_MANIFEST_UPDATE_TO_BE_HANDLED", 90 },
			{ "UNREPORTED_TIME_DISCONTINUITY_FOUND", 91 },
			// The crypto block is NOT contiguous with the rest: 92..299 are
			// unassigned.
			{ "CRYPTO_ALGORITHM_NOT_SUPPORTED", 300 },
			{ "CRYPTO_ERROR_CORRUPTED_DATA", 301 },
			{ "CRYPTO_ERROR_BUFFER_TOO_SMALL", 302 },
			{ "CRYPTO_ERROR_BAD_CERTIFICATE", 303 },
			{ "CRYPTO_ERROR_DIGEST_UPDATE", 304 },
			{ "CRYPTO_ERROR_DIGEST_FINISH", 305 },
			{ "CRYPTO_ERROR_BAD_PARAMETER", 306 },
			{ "CRYPTO_ERROR_UNKNOWN", 307 },
		};
		avresult = av_class(ctx, "AVResult", obj, avresult_ctor);
		av_add_ro_props(ctx, avresult, props, 1, 0);
		for (size_t i = 0; i < sizeof(consts) / sizeof(consts[0]); i++)
			av_iconst(ctx, avresult, consts[i].n, consts[i].v);
	}
	{
		static const char* const props[] = {
			"periodIndex", "insertedBeforeReadHead"
		};
		Avm2Class* cls = av_class(ctx, "AVInsertionResult", avresult,
		                          avinsertion_ctor);
		av_add_ro_props(ctx, cls, props, 2, 1);
	}

	// --- AVPeriodInfo: 3 Numbers, 5 ints, 1 Boolean, 1 Number.
	{
		static const char* const props[] = {
			"localStartTime", "virtualStartTime", "duration",
			"firstCuePointIndex", "lastCuePointIndex",
			"firstSubscribedTagIndex", "lastSubscribedTagIndex",
			"userData", "supportsTrickPlay", "targetDuration"
		};
		Avm2Class* cls = av_class(ctx, "AVPeriodInfo", obj, avperiodinfo_ctor);
		av_add_ro_props(ctx, cls, props, 10, 0);
	}

	// --- AVPlayState: nine int consts, 0..8, in declaration order.
	{
		static const char* const props[] = { "state" };
		static const char* const consts[] = {
			"UNINITIALIZED", "READY", "BUFFERING", "PLAYING", "PAUSED",
			"EOF", "SUSPENDED", "TRICK_PLAY", "UNRECOVERABLE_ERROR"
		};
		Avm2Class* cls = av_class(ctx, "AVPlayState", obj, avplaystate_ctor);
		av_add_ro_props(ctx, cls, props, 1, 0);
		for (int i = 0; i < 9; i++) av_iconst(ctx, cls, consts[i], i);
	}

	// --- AVSource / AVSegmentedSource / AVStream: EventDispatcher subclasses
	//     with no instance state of their own (AVStream's `source` argument is
	//     not readable back).
	Avm2Class* avsource = av_class(ctx, "AVSource", ed, NULL);
	{
		static const struct { const char* n; const char* v; } consts[] = {
			// The casing really is inconsistent upstream: the two protocol
			// names are upper-case, every content kind is lower-case.
			{ "AUDIO", "audio" },
			{ "AUDIO_DESCRIPTION", "audiodescription" },
			{ "AUDIO_LANGUAGE", "audiolanguage" },
			{ "AUDIO_PID", "audiopid" },
			{ "DASH", "DASH" },
			{ "DATA", "data" },
			{ "DATA_DESCRIPTION", "datadescription" },
			{ "HLS", "HLS" },
			{ "VIDEO", "video" },
			{ "VIDEO_DESCRIPTION", "videodescription" },
		};
		Avm2Class* cls = av_class(ctx, "AVSegmentedSource", avsource, NULL);
		for (size_t i = 0; i < sizeof(consts) / sizeof(consts[0]); i++)
			av_sconst(ctx, cls, consts[i].n, consts[i].v);
	}
	{
		Avm2Class* cls = av_class(ctx, "AVStream", ed, NULL);
		av_sconst(ctx, cls, "HARDWARE", "hardware");
		// "sofware" is not a typo here -- it is FP's typo, and av_classes
		// pins it verbatim.
		av_sconst(ctx, cls, "SOFTWARE", "sofware");
		av_sconst(ctx, cls, "UNDEFINED", "undefined");
	}

	// --- AVTimeline
	{
		static const char* const props[] = {
			"type", "virtualStartTime", "virtualDuration", "firstPeriodIndex",
			"lastPeriodIndex", "firstSubscribedTagIndex",
			"lastSubscribedTagIndex", "complete"
		};
		Avm2Class* cls = av_class(ctx, "AVTimeline", obj, avtimeline_ctor);
		av_add_ro_props(ctx, cls, props, 8, 0);
	}

	// --- AVTrackInfo: dataTrackInfoServiceType is a STRING slot while pid is
	//     an int, so 7.7 reads back "7.7" and 8.8 reads back 8.
	{
		static const char* const props[] = {
			"description", "language", "defaultTrack", "autoSelect", "forced",
			"activity", "dataTrackInfoServiceType", "pid"
		};
		Avm2Class* cls = av_class(ctx, "AVTrackInfo", obj, avtrackinfo_ctor);
		av_add_ro_props(ctx, cls, props, 8, 0);
		av_sconst(ctx, cls, "DTI_608_CAPTIONS", "DTI608Captions");
		av_sconst(ctx, cls, "DTI_708_CAPTIONS", "DTI708Captions");
		av_sconst(ctx, cls, "DTI_WEBVTT_CAPTIONS", "DTIWebVTTCaptions");
	}
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

	// flash.media.StageVideo — [Ruffle(Abstract)], no members at all. Only
	// abstract_classes reads it.
	{
		Avm2Class* sv = avm2_builtin_class(ctx, "flash.media", "StageVideo",
		                                   b->object_class);
		sv->flags |= AVM2_CLASS_FLAG_SEALED;
		avm2_builtin_set_abstract(ctx, sv);
	}

	// flash.media.AVTagData(data, localTime) — a two-field value object with
	// getter-only access. The backing fields are dont-enum dynamic props so
	// the GC traces them for free (no native_ext, no mark hook).
	{
		Avm2Class* tag = avm2_builtin_class(ctx, "flash.media", "AVTagData",
		                                    b->object_class);
		tag->instance_init.fn = avtagdata_ctor;
		tag->instance_init.debug_name = "AVTagData";
		avm2_builtin_add_getset(ctx, tag, "data", avtagdata_get_data, NULL);
		avm2_builtin_add_getset(ctx, tag, "localTime", avtagdata_get_local_time,
		                        NULL);
	}

	// The other 13 flash.media.AV* value objects (AVNetworkingParams is the
	// 15th and lives in avm2_net.c, next to the rest of the networking API).
	register_av_classes(ctx);
}
