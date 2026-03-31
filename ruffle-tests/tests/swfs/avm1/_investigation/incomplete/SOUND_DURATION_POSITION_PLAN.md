# Sound Duration/Position Properties Plan
<!-- TESTS: sound_duration_position_props -->

<!-- PLAN_META
id: SOUND_DURATION_POSITION
status: complete
phases:
  - id: 1
    name: "getPosition() implementation"
    status: complete
  - id: 2
    name: "duration/position property getters"
    status: complete
  - id: 3
    name: "Playback lifecycle integration"
    status: complete
dependencies:
  - plan: SOUND_LOADING
    phases: [1, 2, 3]
    type: requires
    reason: "loadSound() and playback infrastructure"
blockers: []
-->

Last updated: 2026-03-31

## Status: COMPLETE — sound_duration_position_props 290/290 PASS

### Implementation (2026-03-31)

Commit `a6a3e688`: All 3 phases implemented.

- **Phase 1**: `builtin_sound_getPosition` returns elapsed ms from `soundGetElapsedForObject` during playback, or duration when `__completed__` flag is set. Returns undefined when not loaded.
- **Phase 2**: Native `duration`/`position` property getters intercepted in `actionGetMember` for `NATIVE_SOUND` objects. Key behavior: after `__loaded__` flag is set, computed values always returned (user writes silently ignored). Before loading, own property values are respected. Pre-loadSound string overrides persist only when BOTH `duration` AND `position` are set (Place 0 SWF5 pattern) — stored as `__dur_override__`/`__pos_override__`.
- **Phase 3**: `onID3` fires with `__duration__=0` (temporarily cleared during callback). `onLoad` fires with full duration. `onSoundComplete` fires from frame loop via `processSoundPlayback`. `builtin_sound_stop` registered as real method. Streaming mode (`isStreaming=true`) auto-starts playback after load.

### Discovered Behaviors
- Flash's `Sound.duration`/`Sound.position` are effectively native getters that ignore user writes after loadSound
- Exception: setting both to strings BEFORE loadSound persists (Place 0 pattern)
- Setting only one (Place -1, -2) does NOT persist
- `onID3` callback fires synchronously during loadSound with duration=0
- `onLoad` fires synchronously after onID3 with full duration

### Test Summary

| Test | Lines | Current | Status | Notes |
|------|-------|---------|--------|-------|
| sound_duration_position_props | 290 | 2/290 (1%) | ignored | Duration/position getters during playback lifecycle |

### Expected Output Pattern (290 lines, 200 ticks, `with_audio = true`)

The test creates Sound instances in multiple "Places" (0-4, -1, -2), each with different
configurations. For each Place, it:

1. Calls `loadSound("noise.mp3", false)` or `attachSound(id)`
2. Registers `onID3`, `onLoad`, `onSoundComplete` callbacks
3. In each callback, traces the current values of:
   - `sound.getDuration()` / `sound.duration`
   - `sound.getPosition()` / `sound.position`
4. Calls `sound.start()` and tracks position during playback

**Key expected values:**
- Before load: `getDuration()` = 0, `getPosition()` = 0
- After load: `getDuration()` = 1045 (ms, from noise.mp3)
- During playback: `getPosition()` increases from 0 toward 1045
- After completion: `getPosition()` = 1045 (or 0 after stop)

**Place variations test:**
- Place 0: Properties accessed as strings (SWF5-style `"x"` output)
- Place 1+: Properties accessed as numbers
- Place -1/-2: Edge cases (negative place IDs)

### Current Infrastructure

- `getDuration()`: Implemented (`action.c:1540`) — reads `__duration__` property
- `getPosition()`: **Stub** — returns undefined
- `duration` property: Not implemented as getter
- `position` property: Not implemented as getter
- `onID3` / `onLoad` / `onSoundComplete` callbacks: Not dispatched

### Implementation Plan

#### Phase 1: getPosition() Implementation

Track current playback position on the Sound instance:

```c
// On start(): record start time
sound_obj.__start_time__ = current_frame_time_ms;
sound_obj.__playing__ = true;

// getPosition(): compute elapsed time
if (sound_obj.__playing__) {
    int elapsed = current_frame_time_ms - sound_obj.__start_time__;
    return min(elapsed, sound_obj.__duration__);
} else if (sound_obj.__completed__) {
    return sound_obj.__duration__;
}
return 0;
```

In trace-only mode, frame time can be derived from frame count × frame duration.

#### Phase 2: duration/position Property Getters

Flash exposes both method and property access:
- `sound.getDuration()` and `sound.duration` return the same value
- `sound.getPosition()` and `sound.position` return the same value

Implement as native getters on the Sound prototype, or intercept in `actionGetMember`
for `NATIVE_SOUND` objects.

#### Phase 3: Playback Lifecycle Integration

This test depends heavily on the callback dispatch from SOUND_LOADING_PLAN:
- `onID3` fires after MP3 metadata is parsed (before full decode)
- `onLoad` fires after full load completes
- `onSoundComplete` fires when playback reaches the end
- Between these events, `getPosition()` must return increasing values

**Frame-based simulation**: At each frame tick, update position for all playing sounds:
```c
void updateSoundPositions(int frame_duration_ms) {
    for each playing_sound:
        playing_sound.position += frame_duration_ms;
        if (playing_sound.position >= playing_sound.duration) {
            playing_sound.position = playing_sound.duration;
            playing_sound.completed = true;
            // Queue onSoundComplete dispatch
        }
}
```

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| getDuration() implementation | `action.c` | 1540 |
| getPosition() stub | `action.c` | 23061 |
| Sound prototype setup | `action.c` | 22930-23066 |

### Dependencies

- **Requires SOUND_LOADING_PLAN.md** Phases 1-3 (loadSound, onLoad/onSoundComplete dispatch)
- Additionally needs onID3 dispatch (shared with SOUND_ID3_PLAN.md)

### Estimated Complexity

Medium. ~100 lines beyond what SOUND_LOADING_PLAN provides:
- Phase 1 (getPosition): ~30 lines
- Phase 2 (property getters): ~20 lines
- Phase 3 (position tracking in frame loop): ~50 lines
