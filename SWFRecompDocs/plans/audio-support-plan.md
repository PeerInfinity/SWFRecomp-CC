# SWFRecomp Audio Support - Implementation Plan

**Document Version:** 1.0

**Created:** November 29, 2025

**Status:** Planning

---

## Table of Contents

1. [Executive Summary](#executive-summary)
2. [Background and Context](#background-and-context)
3. [SWF Audio Architecture](#swf-audio-architecture)
4. [Technical Requirements](#technical-requirements)
5. [Implementation Strategy](#implementation-strategy)
6. [Phase 1: Foundation](#phase-1-foundation)
7. [Phase 2: Event Sounds](#phase-2-event-sounds)
8. [Phase 3: Streaming Sounds](#phase-3-streaming-sounds)
9. [Phase 4: ActionScript Sound Control](#phase-4-actionscript-sound-control)
10. [Audio Backend Architecture](#audio-backend-architecture)
11. [Third-Party Libraries](#third-party-libraries)
12. [Testing Strategy](#testing-strategy)
13. [Risk Management](#risk-management)
14. [Open Questions](#open-questions)

---

## Executive Summary

This document outlines the plan for implementing audio support in SWFRecomp and SWFModernRuntime. The implementation will enable playback of both event sounds (triggered by ActionScript) and streaming sounds (synchronized with the timeline) from SWF files.

### Goals

**Primary Goals:**
- Parse and extract audio data from SWF files (DefineSound, SoundStreamHead/Block tags)
- Decode compressed audio formats (MP3, ADPCM, uncompressed PCM)
- Play event sounds triggered by StartSound tags and ActionScript
- Play streaming sounds synchronized with the SWF timeline
- Support sound control (volume, looping, start/stop)

**Secondary Goals:**
- Maintain compatibility with NO_GRAPHICS mode (audio-only)
- Support WASM builds via Emscripten
- Efficient memory usage for embedded systems

### Non-Goals

- Real-time audio recording/microphone support
- NetStream audio (video playback)
- Nellymoser or Speex codec support (rare in older SWFs)
- AS3 Sound class (full implementation)

### Success Criteria

1. DefineSound tags are parsed and audio data is extracted
2. MP3 and ADPCM audio decodes correctly
3. Event sounds play when triggered by StartSound tags
4. Streaming sounds remain synchronized with animation
5. ActionStopSounds opcode stops all playing audio
6. Audio works in both native (SDL3) and WASM builds

---

## Background and Context

### Current State

The SWFRecomp project currently has **no audio support**:

- **SWFRecomp (Compiler):** Does not parse audio tags (DefineSound, StartSound, SoundStreamHead, SoundStreamBlock)
- **SWFModernRuntime:** Has a stub `actionStopSounds()` function that does nothing
- **Tag Definitions:** Audio tag constants are not defined in `tag.hpp`

The only audio-related code is:
- `actionStopSounds()` stub in `SWFModernRuntime/src/actionmodern/action.c:2235`
- `soundbuftime` property (default 5 seconds) in MovieClip context

### Why Audio Matters

Many Flash games and animations depend on audio:
- Background music and sound effects
- Audio cues for gameplay events
- Voice acting and narration
- Audio-synchronized animations (lip sync, music videos)

Without audio support, the recompiled SWFs provide an incomplete experience.

---

## SWF Audio Architecture

### Two Types of Sound

SWF files support two fundamentally different approaches to audio:

#### 1. Event Sounds

Event sounds are **complete audio assets** stored in the SWF and triggered on demand:

```
SWF Structure:
┌─────────────────────────────┐
│ DefineSound (Tag 14)        │ ← Defines audio data with SoundId
│   - SoundId: 2              │
│   - Format: MP3             │
│   - SampleRate: 44kHz       │
│   - SoundData: [bytes...]   │
└─────────────────────────────┘
        ⋮
┌─────────────────────────────┐
│ StartSound (Tag 15)         │ ← Triggers playback of SoundId 2
│   - SoundId: 2              │
│   - SOUNDINFO:              │
│     - LoopCount: 3          │
│     - InPoint: 1000         │
└─────────────────────────────┘
```

**Characteristics:**
- Entire audio loaded before playback
- Can loop, seek, and apply envelopes
- Multiple instances can play simultaneously
- Triggered by timeline or ActionScript

#### 2. Streaming Sounds

Streaming sounds are **interleaved with frame data** for synchronized playback:

```
SWF Structure:
┌─────────────────────────────┐
│ SoundStreamHead (Tag 18)    │ ← Declares streaming format
│   - StreamFormat: MP3       │
│   - SampleRate: 44kHz       │
│   - SampleCount: 1024/frame │
└─────────────────────────────┘
┌─────────────────────────────┐
│ ShowFrame (Frame 1)         │
│ SoundStreamBlock (Tag 19)   │ ← Audio for frame 1
│   - StreamSoundData: [...]  │
└─────────────────────────────┘
┌─────────────────────────────┐
│ ShowFrame (Frame 2)         │
│ SoundStreamBlock (Tag 19)   │ ← Audio for frame 2
│   - StreamSoundData: [...]  │
└─────────────────────────────┘
```

**Characteristics:**
- Audio packets delivered per-frame
- Flash Player skips animation frames to maintain audio sync
- Only one streaming sound per timeline
- Best for music and long audio

### Audio Coding Formats

The SWF specification supports multiple audio formats:

| Format | Code | Min SWF | Description | Priority |
|--------|------|---------|-------------|----------|
| Uncompressed (native-endian) | 0 | 1 | Raw PCM samples | High |
| ADPCM | 1 | 1 | 2-5 bit differential coding | High |
| MP3 | 2 | 4 | MPEG Layer III | **Critical** |
| Uncompressed (little-endian) | 3 | 4 | Raw PCM, cross-platform | High |
| Nellymoser 16kHz | 4 | 10 | Speech codec | Low |
| Nellymoser 8kHz | 5 | 10 | Speech codec | Low |
| Nellymoser | 6 | 6 | Speech codec | Low |
| Speex | 11 | 10 | Open speech codec | Low |

**Implementation Priority:**
1. **MP3** - Most common format in SWF files
2. **Uncompressed** - Simple to implement
3. **ADPCM** - Common in older SWFs
4. Nellymoser/Speex - Low priority (primarily for microphone streaming)

---

## Technical Requirements

### SWF Tags to Implement

#### Required (Phase 1-2)

| Tag | Code | Purpose |
|-----|------|---------|
| DefineSound | 14 | Define event sound |
| StartSound | 15 | Play event sound |
| SoundStreamHead | 18 | Declare streaming format |
| SoundStreamBlock | 19 | Streaming audio data |
| SoundStreamHead2 | 45 | Enhanced streaming format |

#### Optional (Phase 3+)

| Tag | Code | Purpose |
|-----|------|---------|
| StartSound2 | 89 | Play sound from external SWF (SWF 9+) |
| DefineButtonSound | 17 | Button click sounds |

### SOUNDINFO Record

The SOUNDINFO record controls playback parameters:

```
SOUNDINFO Structure:
┌─────────────────────────────────────────┐
│ SyncStop (1 bit)      │ Stop sound now  │
│ SyncNoMultiple (1 bit)│ No duplicate    │
│ HasEnvelope (1 bit)   │ Volume envelope │
│ HasLoops (1 bit)      │ Loop count      │
│ HasOutPoint (1 bit)   │ End position    │
│ HasInPoint (1 bit)    │ Start position  │
├─────────────────────────────────────────┤
│ InPoint (if flag)     │ UI32, samples   │
│ OutPoint (if flag)    │ UI32, samples   │
│ LoopCount (if flag)   │ UI16            │
│ EnvPoints (if flag)   │ UI8, count      │
│ EnvelopeRecords[]     │ Time-based vol  │
└─────────────────────────────────────────┘
```

### ActionScript Operations

#### Currently Stubbed

| Opcode | Name | Status |
|--------|------|--------|
| 0x09 | ActionStopSounds | Stub exists |

#### Not Yet Implemented

ActionScript 1.0/2.0 sound control is primarily done through the **Sound object**, which requires:

- `new Sound()` - Create Sound object
- `Sound.attachSound(id)` - Attach library sound
- `Sound.start(offset, loops)` - Play sound
- `Sound.stop()` - Stop sound
- `Sound.setVolume(vol)` - Set volume (0-100)
- `Sound.setPan(pan)` - Set stereo pan (-100 to 100)
- `Sound.getVolume()` / `Sound.getPan()` - Get current values
- `Sound.getBytesLoaded()` / `Sound.getBytesTotal()` - Loading progress
- `Sound.duration` / `Sound.position` - Playback position

**Note:** Full Sound object implementation is complex. Initial phases will focus on tag-based playback (StartSound) rather than ActionScript Sound class.

---

## Implementation Strategy

### Approach: Static Extraction + Runtime Playback

Following the existing SWFRecomp architecture:

```
Compile Time (SWFRecomp):
┌──────────────┐    ┌───────────────────────────────────────────┐
│              │    │ 1. Parse DefineSound tags                 │
│   SWF File   │───►│ 2. Decode audio to PCM (or keep MP3)      │
│              │    │ 3. Generate C code with audio data arrays │
│              │    │ 4. Generate StartSound trigger calls      │
└──────────────┘    └───────────────────────────────────────────┘
                                        │
                                        ▼
                    ┌───────────────────────────────────────────┐
                    │ Generated C Files:                        │
                    │   - sounds.c (audio data arrays)          │
                    │   - tagMain.c (StartSound triggers)       │
                    └───────────────────────────────────────────┘

Runtime (SWFModernRuntime):
┌───────────────────┐    ┌──────────────────────────────────────┐
│ Compiled Runtime  │───►│ Audio Subsystem:                     │
│ + Generated Code  │    │   - Load PCM data into audio buffers │
│                   │    │   - Mix and play on SDL3 audio device│
│                   │    │   - Handle StartSound/StopSounds     │
└───────────────────┘    └──────────────────────────────────────┘
```

### Design Decisions

#### Decision 1: Decode at Compile Time vs Runtime

**Option A: Decode at Compile Time**
- Pro: Simpler runtime, no decoder needed
- Pro: Faster playback startup
- Con: Larger generated code size (PCM >> MP3)
- Con: Requires decoder in SWFRecomp (C++)

**Option B: Decode at Runtime**
- Pro: Smaller generated code (keep MP3 compressed)
- Pro: Memory efficient (decode on demand)
- Con: Requires decoder in runtime (C)
- Con: Decoder must work in WASM

**Recommendation:** **Option B (Runtime Decoding)**
- MP3 files can be 10x smaller than PCM
- Single-header decoders (minimp3, dr_mp3) work well in C and WASM
- Memory-efficient for games with lots of sounds

#### Decision 2: Audio Backend

**Option A: SDL3 Audio API**
- Pro: Already using SDL3 for graphics
- Pro: Cross-platform (Windows, Linux, macOS, Web)
- Pro: Well-documented, actively maintained
- Con: Requires SDL3 initialization (done already)

**Option B: Direct Platform APIs**
- Pro: No additional dependencies
- Con: Platform-specific code (Windows/Linux/macOS/WASM)
- Con: More maintenance burden

**Option C: SDL3_mixer**
- Pro: Higher-level mixing API
- Con: Additional dependency
- Con: May be overkill for our needs

**Recommendation:** **Option A (SDL3 Audio API)**
- SDL3 is already integrated
- Audio streams are flexible and efficient
- Works with Emscripten for WASM

---

## Phase 1: Foundation

**Goal:** Establish audio infrastructure

### Tasks

#### 1.1 Add Audio Tag Definitions

Update `SWFRecomp/include/tag.hpp`:

```cpp
enum TagType
{
    // ... existing tags ...
    SWF_TAG_DEFINE_SOUND = 14,
    SWF_TAG_START_SOUND = 15,
    SWF_TAG_DEFINE_BUTTON_SOUND = 17,
    SWF_TAG_SOUND_STREAM_HEAD = 18,
    SWF_TAG_SOUND_STREAM_BLOCK = 19,
    SWF_TAG_SOUND_STREAM_HEAD_2 = 45,
    SWF_TAG_START_SOUND_2 = 89
};
```

#### 1.2 Integrate Audio Decoder Library

Add [minimp3](https://github.com/lieff/minimp3) or [dr_mp3](https://github.com/mackron/dr_libs) as a submodule:

```
SWFModernRuntime/lib/
├── minimp3/
│   └── minimp3.h        # Single-header MP3 decoder
└── ...
```

**Selection Criteria:**
- minimp3: Smaller, faster, SIMD-optimized
- dr_mp3: Better pull API, easier integration

**Recommendation:** Start with **minimp3** for its simplicity and proven WASM compatibility.

#### 1.3 Create Audio Subsystem Headers

Create `SWFModernRuntime/include/audio/audio.h`:

```c
#ifndef SWF_AUDIO_H
#define SWF_AUDIO_H

#include <common.h>

// Sound formats
typedef enum {
    SWF_SOUND_FORMAT_UNCOMPRESSED = 0,
    SWF_SOUND_FORMAT_ADPCM = 1,
    SWF_SOUND_FORMAT_MP3 = 2,
    SWF_SOUND_FORMAT_UNCOMPRESSED_LE = 3
} SWFSoundFormat;

// Sound rates
typedef enum {
    SWF_SOUND_RATE_5512 = 0,   // 5512 Hz
    SWF_SOUND_RATE_11025 = 1,  // 11025 Hz
    SWF_SOUND_RATE_22050 = 2,  // 22050 Hz
    SWF_SOUND_RATE_44100 = 3   // 44100 Hz
} SWFSoundRate;

// Sound definition (from DefineSound tag)
typedef struct SWFSound {
    u16 sound_id;
    SWFSoundFormat format;
    SWFSoundRate rate;
    u8 is_16bit;       // 0 = 8-bit, 1 = 16-bit
    u8 is_stereo;      // 0 = mono, 1 = stereo
    u32 sample_count;
    u8* data;          // Compressed or raw audio data
    size_t data_size;
} SWFSound;

// Playback instance
typedef struct SWFSoundInstance {
    u16 sound_id;
    u32 position;      // Current sample position
    u16 loop_count;    // Remaining loops (0 = infinite disabled)
    u32 in_point;      // Start sample
    u32 out_point;     // End sample (0 = full length)
    float volume_left;
    float volume_right;
    u8 active;
} SWFSoundInstance;

// Audio context
typedef struct SWFAudioContext {
    // Sound library
    SWFSound* sounds;
    size_t sound_count;
    size_t sound_capacity;

    // Active instances
    SWFSoundInstance* instances;
    size_t instance_count;
    size_t max_instances;

    // Streaming sound
    u8 stream_active;
    SWFSoundFormat stream_format;
    SWFSoundRate stream_rate;
    u8* stream_buffer;
    size_t stream_buffer_size;
    size_t stream_position;

    // SDL3 audio
    #ifndef NO_GRAPHICS
    void* sdl_audio_stream;  // SDL_AudioStream*
    void* sdl_audio_device;  // SDL_AudioDeviceID
    #endif
} SWFAudioContext;

// Core API
SWFAudioContext* audio_init(void);
void audio_shutdown(SWFAudioContext* ctx);

// Sound library management
int audio_define_sound(SWFAudioContext* ctx, u16 sound_id,
                       SWFSoundFormat format, SWFSoundRate rate,
                       u8 is_16bit, u8 is_stereo, u32 sample_count,
                       const u8* data, size_t data_size);

// Playback control
int audio_start_sound(SWFAudioContext* ctx, u16 sound_id,
                      u32 in_point, u32 out_point, u16 loop_count,
                      float volume_left, float volume_right);
void audio_stop_sound(SWFAudioContext* ctx, u16 sound_id);
void audio_stop_all(SWFAudioContext* ctx);

// Streaming sound
void audio_stream_head(SWFAudioContext* ctx, SWFSoundFormat format,
                       SWFSoundRate rate, u8 is_stereo, u16 sample_count);
void audio_stream_block(SWFAudioContext* ctx, const u8* data, size_t size);

// Per-frame update (mix and queue audio)
void audio_update(SWFAudioContext* ctx);

#endif // SWF_AUDIO_H
```

#### 1.4 Initialize SDL3 Audio

Modify `SWFModernRuntime/src/flashbang/flashbang.c` or create `audio.c`:

```c
#include <audio/audio.h>
#include <SDL3/SDL.h>

#define AUDIO_SAMPLE_RATE 44100
#define AUDIO_CHANNELS 2
#define AUDIO_BUFFER_SIZE 4096
#define MAX_SOUND_INSTANCES 32

SWFAudioContext* audio_init(void) {
    SWFAudioContext* ctx = calloc(1, sizeof(SWFAudioContext));

    ctx->sounds = NULL;
    ctx->sound_count = 0;
    ctx->sound_capacity = 64;
    ctx->sounds = calloc(ctx->sound_capacity, sizeof(SWFSound));

    ctx->max_instances = MAX_SOUND_INSTANCES;
    ctx->instances = calloc(ctx->max_instances, sizeof(SWFSoundInstance));

    #ifndef NO_GRAPHICS
    // Initialize SDL3 audio
    SDL_AudioSpec spec = {
        .freq = AUDIO_SAMPLE_RATE,
        .format = SDL_AUDIO_S16LE,
        .channels = AUDIO_CHANNELS
    };

    ctx->sdl_audio_stream = SDL_OpenAudioDeviceStream(
        SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
        &spec,
        NULL,  // No callback, we'll queue data
        NULL
    );

    if (ctx->sdl_audio_stream) {
        SDL_ResumeAudioStreamDevice(ctx->sdl_audio_stream);
    }
    #endif

    return ctx;
}
```

### Deliverables

- [ ] Tag definitions in `tag.hpp`
- [ ] minimp3 or dr_mp3 integrated
- [ ] `audio.h` header with data structures
- [ ] `audio.c` with SDL3 initialization
- [ ] Basic test that plays a hardcoded sound

---

## Phase 2: Event Sounds

**Goal:** Parse DefineSound and play with StartSound

### Tasks

#### 2.1 Parse DefineSound Tag

Update `SWFRecomp/src/swf.cpp`:

```cpp
case SWF_TAG_DEFINE_SOUND:
{
    // Parse DefineSound fields
    u16 sound_id = readU16(tag_buffer);
    u8 format_flags = readU8(tag_buffer);

    SWFSoundFormat format = (format_flags >> 4) & 0x0F;
    SWFSoundRate rate = (format_flags >> 2) & 0x03;
    bool is_16bit = (format_flags >> 1) & 0x01;
    bool is_stereo = format_flags & 0x01;

    u32 sample_count = readU32(tag_buffer);

    // Remaining bytes are sound data
    size_t data_size = tag.length - 7;  // 2 + 1 + 4 = 7 bytes header

    // Generate C code to register sound
    out_tag << "// DefineSound: ID=" << sound_id
            << ", Format=" << format
            << ", Rate=" << rate << "\n";
    out_tag << "static const u8 sound_" << sound_id << "_data[] = {";

    for (size_t i = 0; i < data_size; i++) {
        if (i % 16 == 0) out_tag << "\n    ";
        out_tag << "0x" << std::hex << (int)(u8)tag_buffer[i] << ", ";
    }
    out_tag << "\n};\n\n";

    out_tag << "audio_define_sound(audio_ctx, " << sound_id << ", "
            << format << ", " << rate << ", "
            << is_16bit << ", " << is_stereo << ", "
            << sample_count << ", "
            << "sound_" << sound_id << "_data, " << data_size << ");\n";

    break;
}
```

#### 2.2 Parse StartSound Tag

```cpp
case SWF_TAG_START_SOUND:
{
    u16 sound_id = readU16(tag_buffer);

    // Parse SOUNDINFO
    u8 flags = readU8(tag_buffer);
    bool sync_stop = (flags >> 5) & 0x01;
    bool sync_no_multiple = (flags >> 4) & 0x01;
    bool has_envelope = (flags >> 3) & 0x01;
    bool has_loops = (flags >> 2) & 0x01;
    bool has_out_point = (flags >> 1) & 0x01;
    bool has_in_point = flags & 0x01;

    u32 in_point = has_in_point ? readU32(tag_buffer) : 0;
    u32 out_point = has_out_point ? readU32(tag_buffer) : 0;
    u16 loop_count = has_loops ? readU16(tag_buffer) : 1;

    // Generate C code
    if (sync_stop) {
        out_tag << "audio_stop_sound(audio_ctx, " << sound_id << ");\n";
    } else {
        out_tag << "audio_start_sound(audio_ctx, " << sound_id << ", "
                << in_point << ", " << out_point << ", " << loop_count
                << ", 1.0f, 1.0f);\n";
    }

    break;
}
```

#### 2.3 Implement MP3 Decoding

Create `SWFModernRuntime/src/audio/mp3_decoder.c`:

```c
#define MINIMP3_IMPLEMENTATION
#include "minimp3.h"
#include <audio/audio.h>

// Decode MP3 data to PCM
// Returns: number of samples decoded
int audio_decode_mp3(const u8* mp3_data, size_t mp3_size,
                     s16** pcm_out, size_t* pcm_size,
                     int* sample_rate, int* channels) {

    mp3dec_t mp3d;
    mp3dec_init(&mp3d);

    // First pass: count samples
    size_t total_samples = 0;
    size_t offset = 0;
    mp3dec_frame_info_t info;
    s16 temp_pcm[MINIMP3_MAX_SAMPLES_PER_FRAME];

    while (offset < mp3_size) {
        int samples = mp3dec_decode_frame(&mp3d, mp3_data + offset,
                                          mp3_size - offset, temp_pcm, &info);
        if (samples == 0 && info.frame_bytes == 0) break;
        total_samples += samples;
        offset += info.frame_bytes;
        if (offset == 0) offset++;  // Prevent infinite loop
    }

    if (total_samples == 0) return 0;

    // Allocate output buffer
    *sample_rate = info.hz;
    *channels = info.channels;
    *pcm_size = total_samples * info.channels * sizeof(s16);
    *pcm_out = malloc(*pcm_size);

    // Second pass: decode
    mp3dec_init(&mp3d);
    offset = 0;
    s16* write_ptr = *pcm_out;

    while (offset < mp3_size) {
        int samples = mp3dec_decode_frame(&mp3d, mp3_data + offset,
                                          mp3_size - offset, write_ptr, &info);
        if (samples == 0 && info.frame_bytes == 0) break;
        write_ptr += samples * info.channels;
        offset += info.frame_bytes;
        if (offset == 0) offset++;
    }

    return total_samples;
}
```

#### 2.4 Audio Mixing

Implement mixing in `audio_update()`:

```c
void audio_update(SWFAudioContext* ctx) {
    #ifndef NO_GRAPHICS
    if (!ctx->sdl_audio_stream) return;

    // Check how much we can queue
    int queued = SDL_GetAudioStreamQueued(ctx->sdl_audio_stream);
    if (queued > AUDIO_BUFFER_SIZE * 4) return;  // Buffer is full enough

    // Mix buffer
    s16 mix_buffer[AUDIO_BUFFER_SIZE * 2];  // Stereo
    memset(mix_buffer, 0, sizeof(mix_buffer));

    for (size_t i = 0; i < ctx->instance_count; i++) {
        SWFSoundInstance* inst = &ctx->instances[i];
        if (!inst->active) continue;

        SWFSound* sound = audio_get_sound(ctx, inst->sound_id);
        if (!sound) continue;

        // Mix this instance into the buffer
        audio_mix_instance(ctx, inst, sound, mix_buffer, AUDIO_BUFFER_SIZE);
    }

    // Queue mixed audio
    SDL_PutAudioStreamData(ctx->sdl_audio_stream, mix_buffer, sizeof(mix_buffer));
    #endif
}
```

### Deliverables

- [ ] DefineSound parsing in SWFRecomp
- [ ] StartSound parsing with SOUNDINFO
- [ ] MP3 decoding with minimp3
- [ ] Audio mixing with multiple instances
- [ ] Test SWF with event sounds playing

---

## Phase 3: Streaming Sounds

**Goal:** Timeline-synchronized audio

### Tasks

#### 3.1 Parse SoundStreamHead/Head2

```cpp
case SWF_TAG_SOUND_STREAM_HEAD:
case SWF_TAG_SOUND_STREAM_HEAD_2:
{
    u8 playback_flags = readU8(tag_buffer) >> 4;  // Low nibble reserved
    u8 stream_flags = readU8(tag_buffer);

    SWFSoundFormat format = (stream_flags >> 4) & 0x0F;
    SWFSoundRate rate = (stream_flags >> 2) & 0x03;
    bool is_16bit = (stream_flags >> 1) & 0x01;
    bool is_stereo = stream_flags & 0x01;

    u16 sample_count = readU16(tag_buffer);

    // MP3 latency seek
    s16 latency_seek = 0;
    if (format == 2) {  // MP3
        latency_seek = readS16(tag_buffer);
    }

    // Generate streaming init code
    out_tag << "audio_stream_head(audio_ctx, " << format << ", "
            << rate << ", " << is_stereo << ", " << sample_count << ");\n";

    break;
}
```

#### 3.2 Parse SoundStreamBlock

```cpp
case SWF_TAG_SOUND_STREAM_BLOCK:
{
    size_t data_size = tag.length;

    // For MP3, first 4 bytes are SampleCount + SeekSamples
    // Generate code to feed audio data per frame
    out_tag << "static const u8 stream_block_" << current_frame << "_data[] = {";

    for (size_t i = 0; i < data_size; i++) {
        if (i % 16 == 0) out_tag << "\n    ";
        out_tag << "0x" << std::hex << (int)(u8)tag_buffer[i] << ", ";
    }
    out_tag << "\n};\n";

    // In frame function
    out_frame << "audio_stream_block(audio_ctx, stream_block_" << current_frame
              << "_data, " << data_size << ");\n";

    break;
}
```

#### 3.3 Streaming Buffer Management

```c
void audio_stream_block(SWFAudioContext* ctx, const u8* data, size_t size) {
    if (!ctx->stream_active) return;

    if (ctx->stream_format == SWF_SOUND_FORMAT_MP3) {
        // Skip MP3STREAMSOUNDDATA header (4 bytes)
        u16 sample_count = data[0] | (data[1] << 8);
        // s16 seek_samples = data[2] | (data[3] << 8);  // For sync

        const u8* mp3_data = data + 4;
        size_t mp3_size = size - 4;

        // Decode and buffer
        s16* pcm = NULL;
        size_t pcm_size = 0;
        int rate, channels;

        audio_decode_mp3(mp3_data, mp3_size, &pcm, &pcm_size, &rate, &channels);

        if (pcm) {
            // Append to stream buffer
            audio_stream_append(ctx, pcm, pcm_size);
            free(pcm);
        }
    } else {
        // Uncompressed or ADPCM - decode directly
        audio_stream_append_raw(ctx, data, size);
    }
}
```

### Deliverables

- [ ] SoundStreamHead parsing
- [ ] SoundStreamBlock parsing
- [ ] Streaming buffer with frame sync
- [ ] Test SWF with timeline music

---

## Phase 4: ActionScript Sound Control

**Goal:** ActionScript Sound object basics

### Tasks

#### 4.1 Implement ActionStopSounds

Update the existing stub in `action.c`:

```c
void actionStopSounds(char* stack, u32* sp)
{
    (void)stack;
    (void)sp;

    #ifndef NO_GRAPHICS
    if (g_audio_ctx) {
        audio_stop_all(g_audio_ctx);
    }
    #endif
}
```

#### 4.2 Sound Object (Basic)

Create a basic Sound object for AS2:

```c
// In object.c
StackValue* soundObjectConstructor(StackValue* args, int argc) {
    // Create Sound object
    ASObject* sound_obj = createObject("Sound");

    // Initialize properties
    setObjectProperty(sound_obj, "volume", createNumber(100.0));
    setObjectProperty(sound_obj, "pan", createNumber(0.0));
    setObjectProperty(sound_obj, "_soundID", createNumber(-1.0));

    return createObjectValue(sound_obj);
}

void soundObjectStart(ASObject* self, double offset, int loops) {
    double sound_id = getObjectPropertyNumber(self, "_soundID");
    if (sound_id < 0) return;

    #ifndef NO_GRAPHICS
    if (g_audio_ctx) {
        audio_start_sound(g_audio_ctx, (u16)sound_id,
                         (u32)(offset * 44100), 0, loops,
                         1.0f, 1.0f);
    }
    #endif
}

void soundObjectStop(ASObject* self) {
    double sound_id = getObjectPropertyNumber(self, "_soundID");
    if (sound_id < 0) return;

    #ifndef NO_GRAPHICS
    if (g_audio_ctx) {
        audio_stop_sound(g_audio_ctx, (u16)sound_id);
    }
    #endif
}
```

### Deliverables

- [ ] Working `actionStopSounds`
- [ ] Basic Sound object constructor
- [ ] `Sound.attachSound()`
- [ ] `Sound.start()` / `Sound.stop()`
- [ ] `Sound.setVolume()` / `Sound.getVolume()`

---

## Audio Backend Architecture

### Architecture Diagram

```
┌─────────────────────────────────────────────────────────────────────┐
│                     SWFModernRuntime Audio Stack                    │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                    ActionScript Layer                        │   │
│  │  - Sound object methods                                      │   │
│  │  - actionStopSounds opcode                                   │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                     Audio Control API                        │   │
│  │  - audio_start_sound()                                       │   │
│  │  - audio_stop_sound()                                        │   │
│  │  - audio_stream_block()                                      │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                      Audio Mixer                             │   │
│  │  - Instance management                                       │   │
│  │  - Volume/pan application                                    │   │
│  │  - Multi-channel mixing                                      │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                     Audio Decoders                           │   │
│  │  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐          │   │
│  │  │   minimp3   │  │    ADPCM    │  │     PCM     │          │   │
│  │  │   decoder   │  │   decoder   │  │   passthru  │          │   │
│  │  └─────────────┘  └─────────────┘  └─────────────┘          │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                              │                                      │
│                              ▼                                      │
│  ┌─────────────────────────────────────────────────────────────┐   │
│  │                    Platform Backend                          │   │
│  │  ┌────────────────────┐  ┌────────────────────┐             │   │
│  │  │    SDL3 Audio      │  │   Emscripten       │             │   │
│  │  │ (Native: Win/Lin/  │  │   Web Audio API    │             │   │
│  │  │  macOS)            │  │   (WASM)           │             │   │
│  │  └────────────────────┘  └────────────────────┘             │   │
│  └─────────────────────────────────────────────────────────────┘   │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

### File Organization

```
SWFModernRuntime/
├── include/
│   └── audio/
│       ├── audio.h         # Main API
│       ├── decoder.h       # Decoder interface
│       └── mixer.h         # Mixer internals
├── src/
│   └── audio/
│       ├── audio.c         # Core implementation
│       ├── mixer.c         # Mixing engine
│       ├── decoder_mp3.c   # MP3 decoder (minimp3)
│       ├── decoder_adpcm.c # ADPCM decoder
│       └── backend_sdl3.c  # SDL3 audio backend
└── lib/
    └── minimp3/
        └── minimp3.h       # Single-header MP3 decoder
```

---

## Third-Party Libraries

### Recommended: minimp3

**Repository:** https://github.com/lieff/minimp3

**Features:**
- Single header file (easy integration)
- No dependencies
- SSE/NEON SIMD optimizations
- ISO-conformant MP3 decoding
- Works in WASM

**Integration:**

```c
// In exactly one .c file:
#define MINIMP3_IMPLEMENTATION
#include "minimp3.h"

// Everywhere else:
#include "minimp3.h"
```

### Alternative: dr_mp3

**Repository:** https://github.com/mackron/dr_libs

**Features:**
- Based on minimp3
- Pull-style API (easier streaming)
- Better file/memory abstraction
- Public domain or MIT-0 license

### ADPCM Decoder

ADPCM decoding is straightforward and can be implemented directly:

```c
// Based on SWF spec - Jansen's ADPCM implementation
static const int adpcm_index_table[16] = {
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8
};

static const int adpcm_step_table[89] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

int audio_decode_adpcm(const u8* data, size_t size, s16** out, size_t* out_size);
```

---

## Testing Strategy

### Unit Tests

Create tests in `SWFRecomp/tests/`:

```
tests/
├── audio_mp3_event_sound/      # Basic MP3 event sound
│   ├── test.swf
│   ├── create_test_swf.py
│   └── expected_output.txt
├── audio_adpcm_event_sound/    # ADPCM format test
├── audio_streaming_mp3/        # Streaming MP3 audio
├── audio_loop_sound/           # Loop count test
├── audio_stop_sounds/          # ActionStopSounds test (exists)
└── audio_sound_object/         # AS Sound object test
```

### Test SWF Creation

```python
#!/usr/bin/env python3
# create_test_swf.py for audio_mp3_event_sound

import struct

def create_audio_test_swf():
    # Generate a simple 1-second 440Hz sine wave MP3
    # Or embed a pre-made test MP3

    swf_data = bytearray()

    # SWF Header
    swf_data.extend(b'FWS')  # Uncompressed
    swf_data.append(4)       # SWF version
    # ... (length placeholder)

    # DefineSound tag (ID=1, MP3, 44kHz, 16-bit, mono)
    # ... tag data ...

    # ShowFrame
    # StartSound (ID=1)
    # ShowFrame (wait for sound)
    # End

    return bytes(swf_data)
```

### Integration Tests

1. **Visual/Audio Inspection:** Play generated executable, verify sound
2. **Waveform Comparison:** Capture audio output, compare to expected
3. **Timing Tests:** Verify streaming sync with animation frames

### WASM Testing

- Test in browser with Web Audio API backend
- Verify latency is acceptable
- Test on mobile browsers (Safari, Chrome)

---

## Risk Management

### Technical Risks

#### Risk 1: MP3 Licensing Concerns

**Probability:** Low (patents expired)

**Impact:** Low

**Mitigation:** MP3 patents have expired (2017). Use of MP3 decoders is now unrestricted.

#### Risk 2: WASM Audio Latency

**Probability:** Medium

**Impact:** Medium

**Mitigation:**
- Use Emscripten's SDL audio support
- Pre-buffer audio data
- Consider Web Audio API direct integration

#### Risk 3: Memory Usage

**Probability:** Medium

**Impact:** Medium

**Mitigation:**
- Decode audio on-demand, not upfront
- Limit simultaneous sound instances
- Use streaming for long sounds

#### Risk 4: Complex Sound Envelopes

**Probability:** Low

**Impact:** Low

**Mitigation:** Start with basic volume control, add envelope support later

### Schedule Risks

#### Risk: Scope Creep

**Mitigation:**
- Clear phase boundaries
- Defer Sound object complexity to Phase 4+
- Focus on tag-based playback first

---

## Open Questions

### Q1: Compile-Time vs Runtime Decoding?

**Current Decision:** Runtime decoding (smaller binary size)

**Reconsider if:** WASM decoder performance is problematic

### Q2: Maximum Concurrent Sounds?

**Proposal:** 32 simultaneous instances

**Tradeoff:** Memory usage vs flexibility

### Q3: Resampling Strategy?

**Options:**
- Decode to native rate (44.1kHz always)
- Preserve original rate, resample at playback
- Let SDL3 handle resampling

**Recommendation:** Let SDL3 handle resampling (simplest)

### Q4: Sound Object Complexity?

**Minimum Viable:** `start()`, `stop()`, `setVolume()`

**Full Implementation:** Events (`onSoundComplete`), dynamic loading

**Recommendation:** Start minimal, expand based on game requirements

### Q5: NO_GRAPHICS Mode Audio?

**Options:**
- No audio in NO_GRAPHICS mode
- Separate audio-only mode flag
- Use different audio backend (OpenAL, etc.)

**Recommendation:** NO_GRAPHICS = no audio (simplest)

---

## Appendix A: SWF Audio Tag Reference

### DefineSound (Tag 14)

```
Field                Type      Description
-----                ----      -----------
Header               RECORDHEADER  Tag type = 14
SoundId              UI16      Sound character ID
SoundFormat          UB[4]     0=uncompressed, 1=ADPCM, 2=MP3, 3=uncompressed LE
SoundRate            UB[2]     0=5.5kHz, 1=11kHz, 2=22kHz, 3=44kHz
SoundSize            UB[1]     0=8-bit, 1=16-bit
SoundType            UB[1]     0=mono, 1=stereo
SoundSampleCount     UI32      Number of samples
SoundData            UI8[...]  Compressed or raw audio data
```

### StartSound (Tag 15)

```
Field                Type      Description
-----                ----      -----------
Header               RECORDHEADER  Tag type = 15
SoundId              UI16      Sound character ID to play
SoundInfo            SOUNDINFO Sound style information
```

### SOUNDINFO Record

```
Field                Type         Description
-----                ----         -----------
Reserved             UB[2]        Always 0
SyncStop             UB[1]        Stop sound
SyncNoMultiple       UB[1]        Don't restart if playing
HasEnvelope          UB[1]        Has envelope data
HasLoops             UB[1]        Has loop count
HasOutPoint          UB[1]        Has end position
HasInPoint           UB[1]        Has start position
InPoint              If flag, UI32    Start sample
OutPoint             If flag, UI32    End sample
LoopCount            If flag, UI16    Loop iterations
EnvPoints            If flag, UI8     Envelope point count
EnvelopeRecords      SOUNDENVELOPE[]  Volume envelope
```

---

## Appendix B: References

- [SWF Specification v19](../specs/swf-spec-19.txt) - Official Adobe specification
- [minimp3](https://github.com/lieff/minimp3) - MP3 decoder library
- [dr_libs](https://github.com/mackron/dr_libs) - Alternative audio decoders
- [SDL3 Audio Category](https://wiki.libsdl.org/SDL3/CategoryAudio) - SDL3 audio documentation
- [SDL3_mixer](https://wiki.libsdl.org/SDL3_mixer/FrontPage) - Higher-level audio library

---

## Document History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2025-11-29 | Initial planning document |

---

*End of Planning Document*
