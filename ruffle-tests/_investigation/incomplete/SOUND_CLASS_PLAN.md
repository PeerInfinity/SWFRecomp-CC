# Sound Class Implementation Plan
<!-- TESTS: register_class_with_sound, sound -->

Last updated: 2026-03-03

## Status: INCOMPLETE — Phases 0-1 needed

### Overview

The Sound class has a constructor and prototype stubs but most methods are non-functional.
`getVolume()`/`setVolume()` work. All other methods return undefined via `builtin_stub_method`.
This blocks `register_class_with_sound` (5/11) and `sound` (partial).

### Current Infrastructure

**Constructor** (action.c ~28967): Sets `NATIVE_SOUND` type, initializes `__volume__` to 100.

**Prototype methods** (action.c ~16627, `initSoundPrototype`):
- SWF5+: getPan, getTransform, getVolume, setPan, setTransform, setVolume, stop, attachSound, start (9 methods)
- SWF6+: getDuration, setDuration, getPosition, setPosition, loadSound, getBytesLoaded, getBytesTotal (7 more)

**Working**: getVolume (reads `__volume__`), setVolume (writes `__volume__` as int32)
**Stubbed**: Everything else

### Blocked Tests

| Test | Lines | Match | Specific Blocker |
|------|-------|-------|-----------------|
| register_class_with_sound | 11 | 5/11 | getTransform() returns undefined (should return {ll:100, lr:0, rl:0, rr:100}) |
| sound | ~200 | ~10% | getPan returns undefined (should return 0), getTransform returns undefined (should return object), setPan/setTransform non-functional |

### Blocks These Plans
- REGISTERCLASS_PLAN (register_class_with_sound, 6 lines)

---

## Phase 0: Sound Transform Storage (register_class_with_sound fix)

**Goal**: `getTransform()` returns a transform object, `getPan()` returns 0. Fix register_class_with_sound.

### What's Needed

Each Sound instance needs internal stereo transform state:

```c
// Store on the ASObject via properties (like __volume__):
// __ll__ = 100 (left-to-left)
// __lr__ = 0   (left-to-right)
// __rl__ = 0   (right-to-left)
// __rr__ = 100 (right-to-right)
```

### Implementation

1. **Constructor init** — In Sound constructor (action.c ~28967), add:
   ```c
   // After __volume__ = 100:
   setPropertyOnObject(app_context, obj, "__ll__", 100.0);  // left-to-left
   setPropertyOnObject(app_context, obj, "__lr__", 0.0);    // left-to-right
   setPropertyOnObject(app_context, obj, "__rl__", 0.0);    // right-to-left
   setPropertyOnObject(app_context, obj, "__rr__", 100.0);  // right-to-right
   ```

2. **getTransform()** — Replace stub with:
   ```c
   // Create new ASObject with ll, rl, lr, rr properties from internal state
   ASObject* result = allocObject(app_context, 4);
   // Read __ll__, __lr__, __rl__, __rr__ from this_obj
   // Set as integer properties on result
   // Push result as OBJECT
   ```

3. **setTransform(transformObj)** — Replace stub with:
   ```c
   // Read ll, rl, lr, rr from argument object
   // Store back as __ll__, __lr__, __rl__, __rr__ on this_obj
   ```

4. **getPan()** — Replace stub with:
   ```c
   // Pan formula from Ruffle: (rr - ll) / 2, or simplified:
   // If ll=100, rr=100 → pan=0 (center)
   // If ll=100, rr=0 → pan=-100 (full left)
   // If ll=0, rr=100 → pan=100 (full right)
   int ll = read __ll__, rr = read __rr__;
   int pan = rr - ll;  // Simplified; Ruffle uses: (left_transform.volume - right_transform.volume) clamped to -100..100
   push F64(pan);
   ```

5. **setPan(pan)** — Replace stub with:
   ```c
   // Ruffle formula:
   // If pan < 0: ll=100, lr=0, rl=0, rr=100+pan
   // If pan > 0: ll=100-pan, lr=0, rl=0, rr=100
   // If pan == 0: ll=100, lr=0, rl=0, rr=100
   // Store values as __ll__/__lr__/__rl__/__rr__
   ```

### Test Expectations (register_class_with_sound)

```
Construct through attachMovie
typeof this = movieclip
this instanceof Sound = true
this instanceof MovieClip = false
this._name = instance
this._x = 5.5
this.getVolume() = 100           ← already works
this.getVolume() = 10            ← already works (setVolume)
this.getTransform() = [object Object]  ← NEEDS FIX (returns undefined)
getVolume.call({}) = undefined   ← already works
```

Line 9 (`getTransform() = [object Object]`) is the key fix. The test just checks toString(), so we need to return any ASObject.

### Files to Modify
- `SWFModernRuntime/src/actionmodern/action.c`: Sound constructor + getTransform/setTransform/getPan/setPan implementations

### Estimated Effort
~60-80 lines of runtime code. Low-medium difficulty.

---

## Phase 1: attachSound / start / stop (sound test improvements)

**Goal**: Improve `sound` test pass rate. These methods can be no-ops for audio but need correct return values and state tracking.

### What's Needed

Since we're in NO_GRAPHICS/NO_AUDIO mode, actual audio playback isn't needed. But the methods need to:
- Accept correct arguments
- Update internal state (position, duration, playing flag)
- Return correct values

1. **attachSound(id)** — Store the sound ID string on the object. Look up the sound in export table (if available). Set duration if known.

2. **start(offset, loops)** — Set internal "playing" state. Store offset/loops. No actual audio needed for trace tests.

3. **stop(id)** — Clear "playing" state.

4. **getDuration()** — Return stored duration (0 if no sound attached).

5. **getPosition()** — Return stored position (0 if not playing).

### Estimated Effort
~40-60 lines. Low difficulty (mostly property storage).

---

## Phase 2: Sound Event Callbacks (deferred)

**Deferred** — onSoundComplete, onLoad, onID3 require actual audio loading/playback infrastructure that is out of scope for NO_AUDIO mode.

**Tests affected**: sound_duration_position_props, sound_id3, sound_id3_prop, sound_load_start, sound_multiple_load, sound_start_load — all require actual audio loading.

---

## Priority Assessment

| Phase | Effort | Tests Fixed | ROI |
|-------|--------|------------|-----|
| Phase 0 | ~60 lines | register_class_with_sound (+6 lines) | **HIGH** — unblocks REGISTERCLASS |
| Phase 1 | ~50 lines | sound (partial improvement) | Medium |
| Phase 2 | Large | 5 sound tests | Low — deferred |

**Recommendation**: Do Phase 0 first (quick win for register_class_with_sound). Phase 1 if time permits. Phase 2 deferred indefinitely.

## Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=sound_props_swf5 --diff --verbose
python3 ruffle-tests/verify_output.py --test=sound_props_swf6 --diff --verbose
python3 ruffle-tests/verify_output.py --test=register_class_with_sound --diff --verbose
```
