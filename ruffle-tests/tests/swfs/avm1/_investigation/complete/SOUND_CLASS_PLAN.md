# Sound Class Implementation Plan
<!-- TESTS: register_class_with_sound, sound -->

Last updated: 2026-03-05

## Status: COMPLETE — All 4 tests PASS (628/628 for sound)

### Overview

Sound class fully implemented: all getter/setter methods, attachSound with duration lookup, shared owner-based transform model.

### Test Results

| Test | Lines | Match | Status |
|------|-------|-------|--------|
| register_class_with_sound | 11 | 11/11 | PASS |
| sound | 628 | 628/628 | PASS |
| sound_props_swf5 | — | — | PASS |
| sound_props_swf6 | — | — | PASS |

### Implementation Summary

**Phase 0** (previously complete):
- Constructor sets `NATIVE_SOUND` type
- getVolume, setVolume (clamp_to_i32 coercion)
- getPan, setPan (stereo pan formula)
- getTransform, setTransform (own properties only, ECMAScript ToInt32)
- `checkInstanceOf` for MOVIECLIP walks dynamic_props.__proto__ chain
- `resolveSoundThis()` fallback for MOVIECLIP dispatch

**Phase 1** (completed 2026-03-05):

1. **Sound metadata registry** (tag_stubs.c): `g_sound_metadata[]` stores char_id, rate, sample_count from `tagDefineSound`. `ng_getSoundDuration(char_id)` computes duration = round(sample_count * 1000 / sample_rate).

2. **attachSound(id)** (action.c): Looks up export name → char_id via `ng_lookupExport`, then char_id → duration via `ng_getSoundDuration`. Stores `__duration__` and `duration` as hidden properties on the Sound object.

3. **getDuration()** (action.c): Returns `__duration__` property from Sound object, or undefined if no sound attached.

4. **Owner-based shared transform model** (action.c):
   - `g_sound_global_transform` — lazy-init global ASObject shared by all ownerless Sound objects
   - `initSoundTransformDefaults()` — sets volume=100, ll=100, lr=0, rl=0, rr=100 on any ASObject
   - `resolveSoundTransformTarget()` — resolves Sound object → transform-holding ASObject:
     - If `__sound_owner__` property exists (MOVIECLIP type) → use MC's `dynamic_props` (creates if NULL)
     - If no owner AND native_type == NATIVE_SOUND → use `g_sound_global_transform`
     - If not a Sound object → return NULL (prevents non-Sound `this` from accessing global transform)
   - All Sound methods (getVolume, setVolume, getPan, setPan, getTransform, setTransform) use this helper
   - Constructor stores `__sound_owner__` when first arg is MOVIECLIP (all 3 constructor paths updated)
   - Transform data (__volume__, __ll__, etc.) stored on the target, not on the Sound object itself

**Key insight**: `new Sound()` (no owner) → global transform. `new Sound(mc)` → MC's transform. Multiple Sound objects targeting the same MC share its transform. This matches Ruffle's `AudioManager.global_sound_transform` and per-DisplayObject transform model.

### Remaining Stubs (not needed for current tests)
- stop, start, setDuration, getPosition, setPosition, loadSound, getBytesLoaded, getBytesTotal
- Sound event callbacks (onSoundComplete, onLoad, onID3) — require audio playback infrastructure

### Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=sound_props_swf5 --test=sound_props_swf6 --test=register_class_with_sound --test=sound --diff --verbose
```
