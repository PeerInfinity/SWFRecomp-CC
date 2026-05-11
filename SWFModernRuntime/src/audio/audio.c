#ifndef NO_GRAPHICS

#include <audio/audio.h>
#include <swf.h>
#include <stdlib.h>
#include <string.h>

#define MINIMP3_IMPLEMENTATION
#include <audio/minimp3.h>

// ---------------------------------------------------------------------------
// Internal helpers
// ---------------------------------------------------------------------------

static int rate_code_to_hz(u8 rate)
{
	switch (rate)
	{
		case SOUND_RATE_5512:  return 5512;
		case SOUND_RATE_11025: return 11025;
		case SOUND_RATE_22050: return 22050;
		case SOUND_RATE_44100: return 44100;
		default: return 44100;
	}
}

static AudioContext* get_audio_ctx(SWFAppContext* app_context)
{
	return (AudioContext*)app_context->audio_ctx;
}

// ---------------------------------------------------------------------------
// Decode MP3 data into float PCM
// ---------------------------------------------------------------------------
static float* decode_mp3(const u8* data, size_t data_size,
	size_t* out_samples, int* out_channels, int* out_rate)
{
	mp3dec_t dec;
	mp3dec_init(&dec);

	// First pass: count total samples
	size_t total_samples = 0;
	size_t offset = 0;
	mp3dec_frame_info_t info;
	short pcm_buf[MINIMP3_MAX_SAMPLES_PER_FRAME];

	while (offset < data_size)
	{
		int samples = mp3dec_decode_frame(&dec, data + offset,
			(int)(data_size - offset), pcm_buf, &info);
		if (info.frame_bytes == 0) break;
		total_samples += samples;
		offset += info.frame_bytes;
	}

	if (total_samples == 0)
	{
		*out_samples = 0;
		*out_channels = 1;
		*out_rate = 44100;
		return NULL;
	}

	// Second pass: decode into float buffer
	mp3dec_init(&dec);
	int channels = info.channels;
	float* result = (float*)malloc(total_samples * channels * sizeof(float));
	size_t write_pos = 0;
	offset = 0;

	while (offset < data_size)
	{
		int samples = mp3dec_decode_frame(&dec, data + offset,
			(int)(data_size - offset), pcm_buf, &info);
		if (info.frame_bytes == 0) break;

		for (int i = 0; i < samples * channels; i++)
		{
			result[write_pos++] = pcm_buf[i] / 32768.0f;
		}
		offset += info.frame_bytes;
	}

	*out_samples = total_samples;
	*out_channels = channels;
	*out_rate = info.hz;
	return result;
}

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

void audio_init(SWFAppContext* app_context)
{
	AudioContext* ctx = (AudioContext*)calloc(1, sizeof(AudioContext));
	ctx->asset_capacity = 64;
	ctx->assets = (SoundAsset*)calloc(ctx->asset_capacity, sizeof(SoundAsset));
	ctx->asset_count = 0;
	ctx->master_volume = 1.0f;
	ctx->initialized = 1;
	memset(&ctx->stream, 0, sizeof(StreamingSound));
	app_context->audio_ctx = ctx;
}

void audio_define_sound(SWFAppContext* app_context, u16 sound_id,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u32 sample_count, const u8* data, size_t data_size)
{
	AudioContext* ctx = get_audio_ctx(app_context);
	if (!ctx) return;

	// Grow array if needed
	if (ctx->asset_count >= ctx->asset_capacity)
	{
		ctx->asset_capacity *= 2;
		ctx->assets = (SoundAsset*)realloc(ctx->assets,
			ctx->asset_capacity * sizeof(SoundAsset));
	}

	SoundAsset* asset = &ctx->assets[ctx->asset_count++];
	asset->sound_id = sound_id;
	asset->format = format;
	asset->rate = rate;
	asset->sample_size = sample_size;
	asset->stereo = stereo;
	asset->sample_count = sample_count;
	asset->data = data;
	asset->data_size = data_size;
}

static const SoundAsset* find_asset(AudioContext* ctx, u16 sound_id)
{
	for (size_t i = 0; i < ctx->asset_count; i++)
	{
		if (ctx->assets[i].sound_id == sound_id)
			return &ctx->assets[i];
	}
	return NULL;
}

void audio_start_sound(SWFAppContext* app_context, u16 sound_id,
	int stop, u32 loop_count, u32 in_point, u32 out_point)
{
	AudioContext* ctx = get_audio_ctx(app_context);
	if (!ctx) return;

	// If stop flag, stop any playing instances of this sound
	if (stop)
	{
		for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
		{
			if (ctx->channels[i].active && ctx->channels[i].asset &&
				ctx->channels[i].asset->sound_id == sound_id)
			{
				ctx->channels[i].active = 0;
				if (ctx->channels[i].pcm_data)
				{
					free(ctx->channels[i].pcm_data);
					ctx->channels[i].pcm_data = NULL;
				}
			}
		}
		return;
	}

	const SoundAsset* asset = find_asset(ctx, sound_id);
	if (!asset) return;

	// Find free channel
	int ch = -1;
	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		if (!ctx->channels[i].active)
		{
			ch = i;
			break;
		}
	}
	if (ch < 0) return; // All channels busy

	// Decode
	float* pcm = NULL;
	size_t pcm_samples = 0;
	int channels = 1;
	int sample_rate = rate_code_to_hz(asset->rate);

	if (asset->format == SOUND_FORMAT_MP3)
	{
		// MP3 data in DefineSound has a 2-byte SeekSamples field before the MP3 frames
		const u8* mp3_data = asset->data + 2;
		size_t mp3_size = asset->data_size - 2;
		pcm = decode_mp3(mp3_data, mp3_size, &pcm_samples, &channels, &sample_rate);
	}
	else if (asset->format == SOUND_FORMAT_UNCOMPRESSED_NE ||
			 asset->format == SOUND_FORMAT_UNCOMPRESSED_LE)
	{
		channels = asset->stereo ? 2 : 1;
		if (asset->sample_size == 1) // 16-bit
		{
			pcm_samples = asset->data_size / (2 * channels);
			pcm = (float*)malloc(pcm_samples * channels * sizeof(float));
			const s16* src = (const s16*)asset->data;
			for (size_t i = 0; i < pcm_samples * (size_t)channels; i++)
				pcm[i] = src[i] / 32768.0f;
		}
		else // 8-bit
		{
			pcm_samples = asset->data_size / channels;
			pcm = (float*)malloc(pcm_samples * channels * sizeof(float));
			for (size_t i = 0; i < pcm_samples * (size_t)channels; i++)
				pcm[i] = (asset->data[i] - 128) / 128.0f;
		}
	}

	if (!pcm) return;

	SoundChannel* channel = &ctx->channels[ch];
	channel->active = 1;
	channel->asset = asset;
	channel->pcm_data = pcm;
	channel->pcm_samples = pcm_samples;
	channel->pcm_position = (in_point < pcm_samples) ? in_point : 0;
	channel->channels = channels;
	channel->sample_rate = sample_rate;
	channel->loop_count = loop_count;
}

void audio_stop_all_sounds(SWFAppContext* app_context)
{
	AudioContext* ctx = get_audio_ctx(app_context);
	if (!ctx) return;

	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		if (ctx->channels[i].active)
		{
			ctx->channels[i].active = 0;
			if (ctx->channels[i].pcm_data)
			{
				free(ctx->channels[i].pcm_data);
				ctx->channels[i].pcm_data = NULL;
			}
		}
	}
}

void audio_stream_head(SWFAppContext* app_context,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u16 avg_sample_count)
{
	AudioContext* ctx = get_audio_ctx(app_context);
	if (!ctx) return;

	ctx->stream.active = 1;
	ctx->stream.format = format;
	ctx->stream.rate = rate;
	ctx->stream.sample_size = sample_size;
	ctx->stream.stereo = stereo;
	ctx->stream.sample_rate = rate_code_to_hz(rate);
	ctx->stream.channels = stereo ? 2 : 1;

	// Pre-buffer 0.5 seconds of audio before starting playback.
	// emscripten_sleep() has inherent overhead making frames run slightly slower
	// than real-time, so the audio callback consumes data faster than frames
	// produce it. A large pre-buffer absorbs this drift for many seconds.
	ctx->stream.prebuffer = (size_t)ctx->stream.sample_rate / 2;
	ctx->stream.started = 0;

	// Allocate a streaming buffer (enough for ~2 seconds)
	size_t buf_samples = (size_t)ctx->stream.sample_rate * 2;
	ctx->stream.buffer_size = buf_samples;
	ctx->stream.pcm_buffer = (float*)calloc(buf_samples * ctx->stream.channels, sizeof(float));
	ctx->stream.write_pos = 0;
	ctx->stream.read_pos = 0;
}

void audio_stream_block(SWFAppContext* app_context,
	const u8* data, size_t data_size)
{
	AudioContext* ctx = get_audio_ctx(app_context);
	if (!ctx || !ctx->stream.active) return;

	if (ctx->stream.format == SOUND_FORMAT_MP3)
	{
		// MP3 streaming blocks have: SampleCount(UI16) + SeekSamples(SI16) + MP3Frames
		if (data_size < 4) return;
		const u8* mp3_data = data + 4;
		size_t mp3_size = data_size - 4;

		size_t pcm_samples;
		int channels, rate;
		float* pcm = decode_mp3(mp3_data, mp3_size, &pcm_samples, &channels, &rate);
		if (!pcm) return;

		// Write into ring buffer
		int ch = ctx->stream.channels;
		for (size_t i = 0; i < pcm_samples; i++)
		{
			size_t wp = ctx->stream.write_pos % ctx->stream.buffer_size;
			for (int c = 0; c < ch && c < channels; c++)
				ctx->stream.pcm_buffer[wp * ch + c] = pcm[i * channels + c];
			ctx->stream.write_pos++;
		}

		free(pcm);
	}
	else if (ctx->stream.format == SOUND_FORMAT_UNCOMPRESSED_NE ||
			 ctx->stream.format == SOUND_FORMAT_UNCOMPRESSED_LE)
	{
		int ch = ctx->stream.channels;
		if (ctx->stream.sample_size == 1) // 16-bit
		{
			size_t pcm_samples = data_size / (2 * ch);
			const s16* src = (const s16*)data;
			for (size_t i = 0; i < pcm_samples; i++)
			{
				size_t wp = ctx->stream.write_pos % ctx->stream.buffer_size;
				for (int c = 0; c < ch; c++)
					ctx->stream.pcm_buffer[wp * ch + c] = src[i * ch + c] / 32768.0f;
				ctx->stream.write_pos++;
			}
		}
		else // 8-bit
		{
			size_t pcm_samples = data_size / ch;
			for (size_t i = 0; i < pcm_samples; i++)
			{
				size_t wp = ctx->stream.write_pos % ctx->stream.buffer_size;
				for (int c = 0; c < ch; c++)
					ctx->stream.pcm_buffer[wp * ch + c] = (data[i * ch + c] - 128) / 128.0f;
				ctx->stream.write_pos++;
			}
		}
	}
}

void audio_mix(AudioContext* ctx, float* output, size_t frames, int out_channels, int out_rate)
{
	memset(output, 0, frames * out_channels * sizeof(float));

	// Mix event sounds
	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		SoundChannel* ch = &ctx->channels[i];
		if (!ch->active) continue;

		for (size_t f = 0; f < frames; f++)
		{
			if (ch->pcm_position >= ch->pcm_samples)
			{
				if (ch->loop_count > 0)
				{
					ch->loop_count--;
					ch->pcm_position = 0;
				}
				else
				{
					ch->active = 0;
					free(ch->pcm_data);
					ch->pcm_data = NULL;
					break;
				}
			}

			for (int c = 0; c < out_channels; c++)
			{
				int src_c = (c < ch->channels) ? c : 0;
				output[f * out_channels + c] +=
					ch->pcm_data[ch->pcm_position * ch->channels + src_c] * ctx->master_volume;
			}
			ch->pcm_position++;
		}
	}

	// Mix streaming sound
	if (ctx->stream.active && ctx->stream.pcm_buffer)
	{
		// Wait until enough data is buffered before starting playback.
		// Also re-triggers after underrun to accumulate a fresh buffer.
		if (!ctx->stream.started)
		{
			size_t available = ctx->stream.write_pos - ctx->stream.read_pos;
			if (available >= ctx->stream.prebuffer)
				ctx->stream.started = 1;
		}

		if (ctx->stream.started)
		{
			int ch = ctx->stream.channels;
			for (size_t f = 0; f < frames; f++)
			{
				if (ctx->stream.read_pos >= ctx->stream.write_pos)
				{
					// Buffer underrun — stop reading and rebuffer
					ctx->stream.started = 0;
					break;
				}

				size_t rp = ctx->stream.read_pos % ctx->stream.buffer_size;
				for (int c = 0; c < out_channels; c++)
				{
					int src_c = (c < ch) ? c : 0;
					output[f * out_channels + c] +=
						ctx->stream.pcm_buffer[rp * ch + src_c] * ctx->master_volume;
				}
				ctx->stream.read_pos++;
			}
		}
	}

	// Clamp output
	for (size_t i = 0; i < frames * (size_t)out_channels; i++)
	{
		if (output[i] > 1.0f) output[i] = 1.0f;
		if (output[i] < -1.0f) output[i] = -1.0f;
	}
}

void audio_shutdown(SWFAppContext* app_context)
{
	AudioContext* ctx = get_audio_ctx(app_context);
	if (!ctx) return;

	audio_stop_all_sounds(app_context);

	if (ctx->stream.pcm_buffer)
	{
		free(ctx->stream.pcm_buffer);
		ctx->stream.pcm_buffer = NULL;
	}

	free(ctx->assets);
	free(ctx);
	app_context->audio_ctx = NULL;
}

// ---------------------------------------------------------------------------
// Tag wrapper functions (called from generated code)
// ---------------------------------------------------------------------------

void tagDefineSound(SWFAppContext* app_context, u16 sound_id,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u32 sample_count, const u8* data, size_t data_size)
{
	if (!app_context->audio_ctx)
		audio_init(app_context);

	audio_define_sound(app_context, sound_id,
		format, rate, sample_size, stereo,
		sample_count, data, data_size);

	extern void ng_registerSoundMetadata(u16 sound_id, u8 rate, u32 sample_count);
	ng_registerSoundMetadata(sound_id, rate, sample_count);
}

void tagStartSound(SWFAppContext* app_context, u16 sound_id,
	int stop, u32 loop_count, u32 in_point, u32 out_point)
{
	if (!app_context->audio_ctx)
		audio_init(app_context);

	audio_start_sound(app_context, sound_id, stop, loop_count, in_point, out_point);
}

void tagSoundStreamHead(SWFAppContext* app_context,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u16 avg_sample_count)
{
	if (!app_context->audio_ctx)
		audio_init(app_context);

	audio_stream_head(app_context, format, rate, sample_size, stereo, avg_sample_count);
}

void tagSoundStreamBlock(SWFAppContext* app_context,
	const u8* data, size_t data_size)
{
	if (!app_context->audio_ctx)
		audio_init(app_context);

	audio_stream_block(app_context, data, data_size);
}

void tagStopAllSounds(SWFAppContext* app_context)
{
	if (!app_context->audio_ctx) return;
	audio_stop_all_sounds(app_context);
}

#endif
