# FLVPlayback Component Investigation

Last updated: 2026-04-07

## Context

The `netstream_play_flv_screen` image test requires the FLVPlayback component (Adobe's `mx.video.*` AS2 classes, ~93K lines of generated C) to successfully play an FLV file. All 3 FLV trace tests pass, and the video rendering infrastructure is complete (Phase 7 in FLV_PLAYBACK_PLAN), but the image test fails because the component never reaches `NetStream.play()`.

## Root Cause Found: `actionSetVariable` Missing addProperty Setter Invocation

**Bug:** When a clip action on a non-root MovieClip calls `SetVariable("contentPath", "rufflelogo.flv")`, the runtime stores the value directly on the MC's `dynamic_props` via `setProperty()` — bypassing the `addProperty` virtual property setter (`__set__contentPath`) that the FLVPlayback component registered on its prototype.

**Fix applied:** Added `addProperty` setter check in the `actionSetVariable` non-root MC path. Uses the `g_event_this_mc` pattern (same as `actionInvokeRegisteredClassConstructor`) to pass the MC as MOVIECLIP type, not OBJECT type.

**Impact:** This fix is general — any clip action that sets a variable matching an addProperty name on a non-root MC will now correctly invoke the setter. This could affect other tests that use `registerClass` + `addProperty` + clip actions.

## Current Status After Fix

With the fix, the `__set__contentPath` setter IS invoked. However, the component still doesn't reach `NetStream.play()` or `VideoPlayer.load()`. Tracing shows:

### Method Call Chain (confirmed working)
1. `registerClass` — FLVPlayback, VideoPlayer registered ✓
2. `initialize` — EventDispatcher setup ✓
3. `createUIManager` — UI setup ✓
4. `addEventListener` ×7 — Event listeners ✓
5. `createVideoPlayer` — Creates VideoPlayer via `attachMovie` ✓
6. `attachMovie("VideoPlayer")` — Creates child sprite ✓
7. `setVolume`, `setSize`, various getters — VP initialization ✓
8. `reset` — VideoPlayer reset ✓
9. `__set__contentPath` invoked (confirmed via setter trace) ✓

### Missing Calls (never reached)
- `connect` — NetConnection.connect()
- `_load` — VideoPlayer._load()
- `doContentPathConnect` — Connection initiation
- `connectToURL` — NCManager URL connection
- `play` / `load` — NetStream.play() / VideoPlayer.load()
- `_createStream` — NetStream creation

## Analysis: Where `__set__contentPath` Exits Early

The setter function (`func2_anonymous_49` at script_defs.c:10234) flow:

1. **`!isLivePreview` check** (line 10280): Correctly continues (jumps to label_19 when isLivePreview is undefined — normal playback mode). ✓
2. **`this._vp[this._activeVP] != undefined`** (line 10292-10314): Checks if VideoPlayer exists. ✓
3. **URL comparison** (line 10369-10390): Checks if new URL differs from existing. ✓
4. **`_vpState[_activeVP].minProgressPercent = undefined`** (line 10392-10412) ✓
5. **`onEnterFrame` check** (line 10428-10442): Checks if VP has onEnterFrame handler ✓
6. **`_cpMgr[_activeVP].reset()`** (label_231, line 10486-10504): CuePointManager reset — **may silently fail** if `_cpMgr` is undefined
7. **`_vpState[_activeVP].autoPlay` check** (line 10519-10533): **KEY CHECK** — if autoPlay is falsy, jumps to load path; if truthy + `_firstStreamShown`, goes to play path
8. **`_firstStreamShown` check** (line 10537-10548): If false → goto label_391 (load path)
9. **load/play call** (line 10604-10672): Should call `load()` or `play()` on VideoPlayer but NEVER REACHED

The likely failure point is **step 7/8**: `_vpState[_activeVP].autoPlay` or `_firstStreamShown` is undefined/falsy, causing the code to jump past the load/play calls.

## `this` Binding Architecture Issue

The FLVPlayback component constructor is called via `actionInvokeRegisteredClassConstructor`, which uses a special pattern:

```c
// From actionInvokeRegisteredClassConstructor (line 41762):
g_event_this_mc = mc;           // Set MC as event_this
ctor_func->advanced_func(app_context, NULL, 0, registers, NULL);  // Pass NULL as this_obj
```

This ensures the function's preload code stores `this` as `ACTION_STACK_VALUE_MOVIECLIP` (not OBJECT). When `this` is MOVIECLIP type, `actionGetMember` checks MC builtins + `dynamic_props`, which is correct.

**However**, when the component's methods are called via `actionCallMethod` on an OBJECT reference, the `this` is stored as `ACTION_STACK_VALUE_OBJECT` with a pointer that might be the MC's `dynamic_props` ASObject. This means `GetMember` goes through the OBJECT path (which uses `getPropertyWithPrototype` on the ASObject), NOT the MOVIECLIP path. Properties stored on the MC itself (via the constructor's MOVIECLIP path) may not be found via the OBJECT path.

This `this` type mismatch between constructor (MOVIECLIP) and method calls (OBJECT) may cause properties set by the constructor to be invisible to later methods, leading to `undefined` results for `_vp`, `_activeVP`, etc. inside `__set__contentPath`.

## Recommended Next Steps

1. **Verify `_vpState[_activeVP].autoPlay` value**: Add targeted trace at the autoPlay check (step 7) to confirm whether it's truthy or undefined. This determines which branch the setter takes.

2. **Check property storage consistency**: The constructor stores `_vp`, `_vpState` etc. via `actionSetMember` on a MOVIECLIP `this`. Later, the setter reads them via `actionGetMember` on a MOVIECLIP `this`. Verify these access the same `dynamic_props` object.

3. **Broader fix for MC method `this` binding**: In `actionSetMember` for MOVIECLIP addProperty setters (line 43244 in action.c), the setter is called with `(void*)mc` as `this_obj`, which gets stored as OBJECT type. This should use the `g_event_this_mc` pattern instead, matching the constructor. This would be a more invasive change but architecturally correct.

4. **Trace the `load()`/`play()` path**: If the `_vpState.autoPlay` check is confirmed working, trace what happens inside `VideoPlayer.load()` (func2_anonymous_142) to find the next failure point.

## Files Modified

| File | Change |
|------|--------|
| `action.c` (actionSetVariable) | Added addProperty setter check for non-root MC context, using `g_event_this_mc` pattern |
| `tag_stubs.c` | `ng_isVideoChar()` public function (from previous commit) |
| `tag.c` | Video rendering in `render_single_object`/`render_display_list` (from previous commit) |
| `action.h` | `actionGetVideoFramePixels()` declaration (from previous commit) |
| `tag.h` | `ng_isVideoChar()` declaration (from previous commit) |
