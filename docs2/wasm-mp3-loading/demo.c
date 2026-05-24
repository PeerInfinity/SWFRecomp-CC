// WASM MP3 loading demo — three paths to get an MP3 from "somewhere" into
// memory, all decoded by the same in-memory minimp3 call and handed to JS as
// a Float32 PCM buffer for WebAudio playback.
//
//   1. play_bundled()  — opens an /assets/*.mp3 file with fopen(); the
//                        whole assets/ directory lives in MEMFS thanks to
//                        emcc --preload-file assets@/assets. JS picks
//                        which file via a dropdown.
//   2. play_filebuf()  — JS receives bytes from a <input type="file"> or
//                        drag-drop, writes them to /uploads/<name>.mp3 via
//                        FS.writeFile, then calls back into C. Equivalent
//                        to "user installs a mod from disk".
//   3. play_url()      — C-side async HTTP GET via emscripten_fetch; bytes
//                        come back in memory, no MEMFS involved. Equivalent
//                        to "fetch mod from GitHub Pages".
//
// All three converge on play_pcm_buffer() which calls into JS to schedule
// the samples onto an AudioBufferSourceNode.

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>
#include <emscripten/fetch.h>

#define MINIMP3_IMPLEMENTATION
#define MINIMP3_FLOAT_OUTPUT
#include "minimp3.h"

// JS side: receives interleaved-stereo float PCM and schedules playback.
// Defined in demo.html via mergeInto(LibraryManager.library, …).
extern void js_play_pcm(const char* label, int n_label,
                        const float* samples, int n_samples,
                        int channels, int hz);
extern void js_log(const char* msg, int n);

static void log_msg(const char* fmt, ...)
{
    char buf[512];
    va_list args;
    va_start(args, fmt);
    int n = vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    if (n < 0) return;
    if (n >= (int)sizeof(buf)) n = sizeof(buf) - 1;
    js_log(buf, n);
}

// ---- shared decoder ----------------------------------------------------------

// Decode an entire MP3 from a memory buffer using the basic minimp3 API
// (mp3dec_decode_frame loop). Allocates and returns interleaved float PCM.
// Returns 0 on failure.
static float* decode_mp3_buffer(const unsigned char* data, size_t len,
                                size_t* out_samples, int* out_channels, int* out_hz)
{
    mp3dec_t dec;
    mp3dec_init(&dec);

    // Grow as we go. Conservative initial cap: ~10s of stereo @ 44.1kHz.
    size_t cap = 44100 * 2 * 10;
    float* pcm = (float*)malloc(cap * sizeof(float));
    if (!pcm) return NULL;
    size_t written = 0;
    int channels = 0, hz = 0;

    const unsigned char* p = data;
    size_t remaining = len;
    float frame_samples[MINIMP3_MAX_SAMPLES_PER_FRAME];

    while (remaining > 0)
    {
        mp3dec_frame_info_t info;
        int n = mp3dec_decode_frame(&dec, p, (int)remaining, frame_samples, &info);
        if (info.frame_bytes <= 0) break;
        p += info.frame_bytes;
        remaining -= info.frame_bytes;
        if (n == 0) continue;  // skipped frame

        if (channels == 0) { channels = info.channels; hz = info.hz; }
        size_t frame_floats = (size_t)n * (size_t)info.channels;

        if (written + frame_floats > cap)
        {
            cap = (written + frame_floats) * 2;
            float* grown = (float*)realloc(pcm, cap * sizeof(float));
            if (!grown) { free(pcm); return NULL; }
            pcm = grown;
        }
        memcpy(pcm + written, frame_samples, frame_floats * sizeof(float));
        written += frame_floats;
    }

    if (written == 0) { free(pcm); return NULL; }

    *out_samples = written / (channels ? channels : 1);
    *out_channels = channels;
    *out_hz = hz;
    return pcm;
}

static void decode_and_play(const char* label, unsigned char* bytes, size_t len)
{
    log_msg("[%s] received %zu bytes, decoding...", label, len);
    size_t n_samples = 0;
    int channels = 0, hz = 0;
    float* pcm = decode_mp3_buffer(bytes, len, &n_samples, &channels, &hz);
    if (!pcm)
    {
        log_msg("[%s] decode failed", label);
        return;
    }
    log_msg("[%s] decoded %zu samples, %d ch @ %d Hz (%.2fs)",
            label, n_samples, channels, hz,
            (double)n_samples / (hz > 0 ? hz : 1));
    js_play_pcm(label, (int)strlen(label), pcm, (int)n_samples, channels, hz);
    free(pcm);
}

// ---- method 1: bundled MP3 via fopen on MEMFS --------------------------------

EMSCRIPTEN_KEEPALIVE
void play_bundled(const char* path)
{
    FILE* f = fopen(path, "rb");
    if (!f) { log_msg("[bundled] fopen(%s) failed (not in MEMFS?)", path); return; }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0) { fclose(f); log_msg("[bundled] empty file"); return; }
    unsigned char* buf = (unsigned char*)malloc((size_t)sz);
    if (!buf) { fclose(f); return; }
    fread(buf, 1, (size_t)sz, f);
    fclose(f);
    decode_and_play("bundled", buf, (size_t)sz);
    free(buf);
}

// ---- method 2: user-supplied bytes via file picker / drag-drop ---------------
// Called from JS after FS.writeFile completes. The path can also be passed
// directly to fopen — we use a path here to mirror "fopen-based modding".

EMSCRIPTEN_KEEPALIVE
void play_uploaded(const char* path)
{
    FILE* f = fopen(path, "rb");
    if (!f) { log_msg("[uploaded] fopen(%s) failed", path); return; }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0) { fclose(f); return; }
    unsigned char* buf = (unsigned char*)malloc((size_t)sz);
    if (!buf) { fclose(f); return; }
    fread(buf, 1, (size_t)sz, f);
    fclose(f);
    decode_and_play("uploaded", buf, (size_t)sz);
    free(buf);
}

// ---- method 3: remote URL via emscripten_fetch (async) -----------------------

static void on_fetch_success(emscripten_fetch_t* fetch)
{
    log_msg("[url] HTTP %d, %llu bytes from %s",
            fetch->status, (unsigned long long)fetch->numBytes, fetch->url);
    decode_and_play("url", (unsigned char*)fetch->data, (size_t)fetch->numBytes);
    emscripten_fetch_close(fetch);
}

static void on_fetch_error(emscripten_fetch_t* fetch)
{
    log_msg("[url] fetch failed: HTTP %d", fetch->status);
    emscripten_fetch_close(fetch);
}

EMSCRIPTEN_KEEPALIVE
void play_url(const char* url)
{
    emscripten_fetch_attr_t attr;
    emscripten_fetch_attr_init(&attr);
    strcpy(attr.requestMethod, "GET");
    attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    attr.onsuccess = on_fetch_success;
    attr.onerror   = on_fetch_error;
    log_msg("[url] fetching %s...", url);
    emscripten_fetch(&attr, url);
}

int main(void)
{
    const char* probes[] = {
        "/assets/beat-mono.mp3",
        "/assets/beat-stereo.mp3",
        "/assets/stereo8.mp3",
    };
    log_msg("demo ready. MEMFS /assets/ contents:");
    for (size_t i = 0; i < sizeof(probes)/sizeof(probes[0]); i++) {
        FILE* f = fopen(probes[i], "rb");
        if (f) {
            fseek(f, 0, SEEK_END);
            long sz = ftell(f);
            fclose(f);
            log_msg("  %s (%ld bytes)", probes[i], sz);
        } else {
            log_msg("  %s (missing!)", probes[i]);
        }
    }
    return 0;
}
