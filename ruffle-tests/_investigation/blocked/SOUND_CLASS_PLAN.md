# Sound Class Implementation Plan
<!-- TESTS: register_class_with_sound, sound -->

Last updated: 2026-03-03

## Status: BLOCKED — Phase 0 complete, remaining failures need attachSound/shared transform

### Overview

Sound class Phase 0 is complete: getPan, setPan, getTransform, setTransform all work correctly.
`register_class_with_sound` now passes (11/11). `sound` matches 622/628 lines.

### Current Infrastructure

**Constructor** (action.c ~28967): Sets `NATIVE_SOUND` type, initializes `__volume__=100`, `__ll__=100`, `__lr__=0`, `__rl__=0`, `__rr__=100`.

**Working methods** (real implementations on Sound.prototype):
- getVolume, setVolume (clamp_to_i32 coercion)
- getPan (formula: if ll!=100: 100-abs(ll), else: abs(rr)-100)
- setPan (clamp_to_i32 coercion, formula: pan>=0 → ll=100-pan,rr=100; pan<0 → ll=100,rr=100+pan)
- getTransform (returns {ll,lr,rl,rr} object with Object.prototype)
- setTransform (reads own properties only, ECMAScript ToInt32 wrapping)

**Stubbed**: stop, attachSound, start, getDuration, setDuration, getPosition, setPosition, loadSound, getBytesLoaded, getBytesTotal

**Key fixes applied**:
- `checkInstanceOf` for MOVIECLIP now walks dynamic_props.__proto__ chain (supports registerClass)
- `resolveSoundThis()` helper falls back to g_event_this_mc->dynamic_props for MOVIECLIP dispatch
- `soundArgToInt32()` uses clamp_to_i32 semantics (NaN/out-of-range → INT32_MIN)
- `ecmaToInt32()` (existing) used for setTransform coercion
- setTransform checks OWN properties only (has_own_property, not prototype chain)

### Test Results

| Test | Lines | Match | Status |
|------|-------|-------|--------|
| register_class_with_sound | 11 | 11/11 | PASS |
| sound | 628 | 622/628 | 6 lines failing |
| sound_props_swf5 | — | — | PASS |
| sound_props_swf6 | — | — | PASS |

### Remaining Failures in `sound` Test (6 lines)

1. **duration/getDuration (4 lines)**: sound1.duration=1452, sound1.getDuration()=1452, sound2.duration=907, sound2.getDuration()=907. Requires `attachSound` to look up sound by export name and report its duration. Phase 1 work.

2. **Shared volume (2 lines)**: sound1.setVolume(50) → sound2.getVolume()=50 (shared global transform), sound3.getVolume()=1 (separate owner). Requires implementing Ruffle's shared transform model (Sound objects with no owner share global transform). Significant architecture change.

### Blocks These Plans
- REGISTERCLASS_PLAN (register_class_with_sound) — NOW UNBLOCKED

---

## Phase 1: attachSound / duration / shared transform (deferred)

**Goal**: Fix remaining 6 lines in `sound` test.

### What's Needed

1. **attachSound(id)**: Look up sound by export name. Set duration from sound metadata. Store sound ID.
2. **getDuration()**: Return stored duration (from attachSound), undefined if no sound attached.
3. **Shared global transform**: Sound objects with no owner should share a single global transform state, not individual per-object hidden properties. This requires:
   - A global `{volume, ll, lr, rl, rr}` state
   - Sound methods that check `owner == NULL` and use global state instead of per-object props
   - This is a significant refactor of the current per-object property storage

### Estimated Effort
~100+ lines. Medium difficulty for attachSound/duration, higher for shared transform model.

### Decision
**BLOCKED**: The shared transform model is a significant architecture change for just 2 lines of improvement. The attachSound/duration fix requires audio metadata lookup infrastructure. Moving to blocked/.

---

## Phase 2: Sound Event Callbacks (deferred)

**Deferred** — onSoundComplete, onLoad, onID3 require actual audio loading/playback infrastructure.

## Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=sound_props_swf5 --diff --verbose
python3 ruffle-tests/verify_output.py --test=sound_props_swf6 --diff --verbose
python3 ruffle-tests/verify_output.py --test=register_class_with_sound --diff --verbose
python3 ruffle-tests/verify_output.py --test=sound --diff --verbose
```
