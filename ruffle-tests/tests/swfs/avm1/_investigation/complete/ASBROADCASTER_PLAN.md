# AsBroadcaster Implementation Plan
<!-- TESTS: as_broadcaster, as_broadcaster_undef -->

<!-- PLAN_META
id: ASBROADCASTER
status: complete
dependencies:
  - plan: ARRAY_METHODS
    type: complements
    reason: "ASBroadcaster uses array-based listener management"
blockers: []
-->

Last updated: 2026-03-04

## Status: COMPLETE — both tests PASS (41/41 + 90/90)

### Overview

AsBroadcaster is a mixin that adds event broadcasting capabilities to any object. It's used internally by MovieClipLoader, Key, Mouse, Selection, and Stage.

### Test Results

| Test | Lines | Result |
|------|-------|--------|
| as_broadcaster | 41 | **41/41 PASS** |
| as_broadcaster_undef | 90 | **90/90 PASS** |

### What Was Implemented

1. **`AsBroadcaster.initialize(obj)`** — static method (was `builtin_stub_method`, now `builtin_asbroadcaster_initialize`). Calls `installAsBroadcaster()` to set up `_listeners` array and install `addListener`/`removeListener`/`broadcastMessage` on the target object. Handles OBJECT, ARRAY, FUNCTION, and MOVIECLIP targets.

2. **`addListener(listener)` fixes**:
   - No-arg case now adds `undefined` to _listeners (was returning true immediately)
   - Dedup uses `listenerAbstractEq()` — AS2 abstract equality where `null == undefined`
   - When dedup match found, REPLACES the existing entry (e.g. undefined→null)
   - Always returns `true`

3. **`removeListener(listener)` fixes**:
   - No-arg case now treats target as `undefined`
   - Uses `listenerAbstractEq()` for matching (removeListener(undefined) removes null entries)
   - Returns `true` if found, `false` if not

4. **`broadcastMessage(event_name, ...args)` fixes**:
   - Method name coercion via `pushVar`+`convertString` (handles boolean, number, null, undefined, not just string)
   - Empty method name calls listener as function directly (not method lookup)
   - Returns `true` (was returning `undefined`)

5. **`listenerAbstractEq()` helper** — simplified AS2 abstract equality for listener comparison: null==undefined, otherwise same-type same-value.

### Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Added `listenerAbstractEq`, `builtin_asbroadcaster_initialize`; rewrote addListener, removeListener, broadcastMessage |
