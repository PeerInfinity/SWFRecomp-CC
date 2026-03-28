# Sound Duration/Position Properties Plan
<!-- TESTS: sound_duration_position_props -->

Last updated: 2026-03-27

## Status: NOT STARTED — Depends on SOUND_LOADING_PLAN Phase 1-3

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
