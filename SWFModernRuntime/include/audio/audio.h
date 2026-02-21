#pragma once

#include <common.h>

// Forward declaration
typedef struct SWFAppContext SWFAppContext;

// Sound format codes (from SWF spec)
#define SOUND_FORMAT_UNCOMPRESSED_NE  0  // Native-endian
#define SOUND_FORMAT_ADPCM            1
#define SOUND_FORMAT_MP3              2
#define SOUND_FORMAT_UNCOMPRESSED_LE  3
#define SOUND_FORMAT_NELLYMOSER_16K   4
#define SOUND_FORMAT_NELLYMOSER_8K    5
#define SOUND_FORMAT_NELLYMOSER       6
#define SOUND_FORMAT_SPEEX           11

// Sound rate codes
#define SOUND_RATE_5512   0
#define SOUND_RATE_11025  1
#define SOUND_RATE_22050  2
#define SOUND_RATE_44100  3

// Maximum concurrent sounds
#define MAX_SOUND_CHANNELS 32

#ifndef NO_GRAPHICS

// A defined sound asset (from DefineSound tag)
typedef struct SoundAsset {
	u16 sound_id;
	u8 format;           // SOUND_FORMAT_*
	u8 rate;             // SOUND_RATE_*
	u8 sample_size;      // 0 = 8-bit, 1 = 16-bit
	u8 stereo;           // 0 = mono, 1 = stereo
	u32 sample_count;
	const u8* data;      // Compressed sound data
	size_t data_size;
} SoundAsset;

// A currently-playing sound instance
typedef struct SoundChannel {
	int active;
	const SoundAsset* asset;
	float* pcm_data;      // Decoded PCM (float, interleaved)
	size_t pcm_samples;   // Total decoded samples (per channel)
	size_t pcm_position;  // Current playback position
	int channels;         // 1=mono, 2=stereo
	int sample_rate;      // Actual sample rate in Hz
	u32 loop_count;       // 0 = no loop, >0 = remaining loops
} SoundChannel;

// Streaming sound state
typedef struct StreamingSound {
	int active;
	u8 format;
	u8 rate;
	u8 sample_size;
	u8 stereo;
	float* pcm_buffer;    // Ring buffer of decoded streaming PCM
	size_t buffer_size;   // Total buffer capacity (samples)
	size_t write_pos;     // Next write position
	size_t read_pos;      // Next read position
	int sample_rate;
	int channels;
	size_t prebuffer;     // Samples to buffer before starting playback
	int started;          // 1 once prebuffer threshold reached
} StreamingSound;

// Audio context
typedef struct AudioContext {
	SoundAsset* assets;       // Array of defined sounds
	size_t asset_count;
	size_t asset_capacity;

	SoundChannel channels[MAX_SOUND_CHANNELS];
	StreamingSound stream;

	int initialized;
	float master_volume;
} AudioContext;

// Initialize audio subsystem
void audio_init(SWFAppContext* app_context);

// Define a sound asset
void audio_define_sound(SWFAppContext* app_context, u16 sound_id,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u32 sample_count, const u8* data, size_t data_size);

// Start playing a sound
void audio_start_sound(SWFAppContext* app_context, u16 sound_id,
	int stop, u32 loop_count, u32 in_point, u32 out_point);

// Stop all sounds
void audio_stop_all_sounds(SWFAppContext* app_context);

// Setup streaming sound header
void audio_stream_head(SWFAppContext* app_context,
	u8 format, u8 rate, u8 sample_size, u8 stereo,
	u16 avg_sample_count);

// Feed a streaming sound block
void audio_stream_block(SWFAppContext* app_context,
	const u8* data, size_t data_size);

// Mix audio for output callback (called by SDL)
void audio_mix(AudioContext* ctx, float* output, size_t frames, int out_channels, int out_rate);

// Shutdown audio
void audio_shutdown(SWFAppContext* app_context);

// Audio output (platform-specific)
void audio_output_init(SWFAppContext* app_context);
void audio_output_shutdown(void);

#endif
