# Sound Loading Plan
<!-- TESTS: sound_load_start, sound_multiple_load -->

<!-- PLAN_META
id: SOUND_LOADING
status: complete
phases:
  - id: 1
    name: "loadSound() with embedded data"
    status: complete
  - id: 2
    name: "onLoad callback dispatch"
    status: complete
  - id: 3
    name: "Sound playback simulation (onSoundComplete)"
    status: complete
  - id: 4
    name: "Integrate with frame loop"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-03-31

## Status: COMPLETE — sound_load_start 3/3 PASS, sound_multiple_load 1/1 PASS

### Implementation (2026-03-31)

Commit `a6a3e688`: All 4 phases implemented.

- **Phase 1**: `builtin_sound_loadSound` looks up embedded MP3 data via `findDataFile()`, parses MPEG audio frame header for bitrate-based duration calculation (handles ID3v2 header skipping). Stores duration as `__duration__` on Sound instance.
- **Phase 2**: `soundFireCallback` generic dispatcher handles both type-1 and type-2 AS functions with scope chain, captured scopes, and base_clip context switching. Dispatches `onID3` (duration=0) then `onLoad` (with computed duration) during loadSound.
- **Phase 3**: `PlayingSoundEntry` tracking array (16 slots). `soundStartPlayback` adds entries, `soundFireOnComplete` dispatches onSoundComplete + sets `__completed__` flag. `soundStopForObject` clears entries. Second `loadSound` clears previous duration and stops active playback.
- **Phase 4**: `processSoundPlayback` called from swf_core.c frame loop after `processTimers`. `hasPlayingSounds` added to both exit conditions (past-last-frame branch and frame-advance branch) to keep loop alive during playback.

### Test Summary

| Test | Lines | Current | Status | Notes |
|------|-------|---------|--------|-------|
| sound_load_start | 3 | 0/3 (0%) | ignored | loadSound + onSoundComplete callback |
| sound_multiple_load | 1 | 0/1 (0%) | ignored | Multiple loadSound + single onSoundComplete |

### Expected Output

**sound_load_start** (3 lines, 100 ticks, `with_audio = true`):
```
Sound complete
Sound complete
Sound complete
```

The test loads `noise.mp3` (8.3K) and plays it to completion 3 times. Each completion
fires `onSoundComplete`.

**sound_multiple_load** (1 line, 100 ticks, `with_audio = true`):
```
Sound complete
```

Loads multiple sounds but only one completes within the test timeframe.

### Current Infrastructure

#### What Exists

1. **MP3 decoder**: `minimp3.h` in `SWFModernRuntime/src/audio/audio.c` — full MP3 → float PCM decoding
2. **Sound asset registry**: 64-slot `SoundAsset` table, 32-channel mixer, streaming buffers
3. **Data file embedding**: `verify_output.py` `generate_data_registry()` embeds test data files
   (including `noise.mp3`) as C byte arrays via `find_data_files()`
4. **attachSound()**: Works — looks up exported sound by name via `ng_lookupExport()`,
   stores duration via `ng_getSoundDuration()`
5. **getDuration()**: Works — reads `__duration__` property set by attachSound
6. **Sound constructor**: Sets `NATIVE_SOUND` type, creates instance with prototype

#### What's Stubbed

- `loadSound(url, isStreaming)` — returns undefined, does nothing (`action.c:23063`)
- `start()` — stub (`action.c:23044`)
- `stop()` — stub (`action.c:23031`)
- `onSoundComplete` — never dispatched
- `onLoad` — never dispatched
- `getBytesLoaded()` / `getBytesTotal()` — stubs

### Implementation Plan

#### Phase 1: loadSound() with Embedded Data

Implement `loadSound(url, isStreaming)` to load MP3 data from the embedded data registry.

The test runner already embeds `noise.mp3` as a C byte array via `generate_data_registry()`.
The runtime needs to:

1. Extract the URL string from the first argument
2. Look up the filename in the data registry (strip path, match basename)
3. Decode the MP3 data using `minimp3.h` (already available)
4. Store the decoded PCM + metadata (duration, sample rate) on the Sound instance
5. Set `__duration__` property from decoded sample count / sample rate

```c
// In the loadSound implementation:
void builtin_sound_loadSound(SWFAppContext* ctx, ActionVar* args, ...) {
    const char* url = convertString(args[0]);
    int is_streaming = varToBool(args[1]);

    // Look up in data registry
    const DataEntry* entry = lookupDataFile(url);
    if (!entry) return;

    // Decode MP3 via minimp3
    mp3dec_t mp3d;
    mp3dec_init(&mp3d);
    // ... decode entry->data, entry->size ...

    // Store decoded audio on Sound instance
    // Set __duration__ = sample_count * 1000 / sample_rate
}
```

#### Phase 2: onLoad Callback Dispatch

After `loadSound()` completes (or on the next frame tick), dispatch the `onLoad` callback:

1. Look up `onLoad` property on the Sound instance
2. If it's a function, call it with `(success_boolean)` argument
3. For embedded data, success is always `true`

**Timing**: In Flash, `onLoad` fires asynchronously (after the current frame script).
For trace-only mode, dispatch at the end of the frame that called `loadSound()`,
or on the next `processTimers()` / frame tick.

#### Phase 3: Sound Playback Simulation (onSoundComplete)

For trace-only mode, actual audio playback isn't needed — just the timing of callbacks.
Simulate playback:

1. When `start()` is called (or loadSound with `isStreaming=true`), record the start time
   and compute the end time from duration
2. On each frame tick, check if any playing sounds have "completed"
3. When a sound completes, dispatch `onSoundComplete` callback

**Frame-based timing**: At 12fps (default SWF frame rate), each frame = ~83ms. A 1045ms
sound would complete after ~13 frames. The test runs for 100 ticks, so completion is
expected well within the test window.

```c
// Sound playback state
typedef struct {
    int playing;
    int start_frame;
    int duration_ms;    // from MP3 decode
    int frames_per_ms;  // from SWF frame rate
} SoundPlaybackState;
```

#### Phase 4: Integrate with Frame Loop

Add `processSoundCallbacks()` to the frame loop (alongside `processTimers()`):
- Check all active Sound instances for pending callbacks (onLoad, onSoundComplete)
- Dispatch callbacks in the correct order

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Sound prototype setup | `action.c` | 22930-23066 |
| Sound method implementations | `action.c` | 1240-1560 |
| loadSound stub | `action.c` | 23063 |
| start/stop stubs | `action.c` | 23031, 23044 |
| minimp3 decoder | `SWFModernRuntime/src/audio/audio.c` | (full file) |
| Data registry generation | `verify_output.py` | `generate_data_registry()` |
| Data file finder | `verify_output.py` | `find_data_files()` |
| Frame loop (timers) | `swf_core.c` | `processTimers()` call |

### Dependencies

- None — MP3 decoder and data embedding both exist
- Shares infrastructure with SOUND_DURATION_POSITION_PLAN.md (playback state tracking)

### Estimated Complexity

Medium. ~200 lines across phases:
- Phase 1 (loadSound with embedded data): ~60 lines
- Phase 2 (onLoad dispatch): ~30 lines
- Phase 3 (playback simulation): ~60 lines
- Phase 4 (frame loop integration): ~30 lines
- verify_output.py changes (data file path resolution): ~20 lines
