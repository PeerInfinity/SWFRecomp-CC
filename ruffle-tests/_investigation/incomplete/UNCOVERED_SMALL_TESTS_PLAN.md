# Uncovered Small/Miscellaneous Tests Catalog
<!-- TESTS: define_local_with_paths, device_font_spacing, gettextextent, get_bytes_total, geturl, issue_2030, issue_2084, issue_3169, resolve_different_root, root_global_parent, root_onload, sandbox_type_remote, string_paths_keyevents, string_paths_timer, displacementmapfilter_mappoint_throw_error, localconnection -->

Last updated: 2026-03-13

## Status: 11/19 PASS — 2 actionable fixes, 6 blocked

### Overview

This document catalogs 19 tests that don't fit into any existing plan's scope. Each is small (0-579 expected lines) and either done, blocked by a larger feature, or a standalone fix.

---

### Results Summary

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| root_onload | 2 | **PASS** | |
| issue_3169 | 2 | **PASS** | |
| get_bytes_total | 4 | **PASS** | |
| gettextextent | 56 | **PASS** | |
| define_local_with_paths | 55 | **PASS** | |
| device_font_spacing | 91 | **PASS** | |
| movieclip_setmask | 14 | **PASS** | |
| selection_handlers | 27 | **PASS** | |
| define_local | 27 | **PASS** | |
| resolve_different_root | 2 | **PASS** | |
| root_global_parent | 6 | **PASS** | |
| string_paths_keyevents | 0 | FAIL | **Actionable**: Key listener cleanup on removeMovieClip |
| string_paths_timer | 0 | FAIL | **Actionable**: Timer cleanup on removeMovieClip |
| issue_2030 | 4 | FAIL | Blocked: needs attachBitmap + BitmapData pixel buffer |
| displacementmapfilter_mappoint_throw_error | 13 | FAIL | Blocked: Point.toString() + Error throw from native ctor |
| sandbox_type_remote | 3 | FAIL | Blocked: loadMovie multi-SWF |
| issue_2084 | 16 | FAIL | Blocked: loadMovie + onLoad positioning |
| geturl | 7 | FAIL | Blocked: navigator/network trace infrastructure |
| localconnection | 579 | FAIL | Blocked: full LocalConnection protocol |

---

## Actionable: Removed MC Listener/Timer Cleanup

### Problem

Two tests expect that removing a MovieClip via `removeMovieClip()` also cleans up its event listeners and timers:

**`string_paths_keyevents`** (0 expected lines):
1. Creates `clip` via `createEmptyMovieClip`
2. Sets `clip.onKeyDown = function() { trace("Keypress"); }`
3. Calls `Key.addListener(clip)` to register clip as a key listener
4. Immediately calls `clip.removeMovieClip()`
5. Input sends a key event
6. Expected: no output (removed MC shouldn't receive key events)
7. Actual: traces "Keypress" — the Key listener array still holds the removed MC

**`string_paths_timer`** (0 expected lines):
1. Creates `clip` via `createEmptyMovieClip`
2. Sets `clip.foo = function() { trace("Foo"); }`
3. Calls `setInterval(clip, "foo", ...)` — method-form timer
4. Immediately calls `clip.removeMovieClip()`
5. Expected: no output (timer on removed MC shouldn't fire)
6. Actual: traces "Foo" 5 times — the timer still fires its callback

### Root Cause

`removeMovieClip` invalidates the MC (sets `depth = INT_MIN`, clears `dynamic_props` via `actionInvalidateCachedMovieClip` or the pending removal path) but does NOT:
1. Remove the MC from AsBroadcaster `_listeners` arrays (Key, Mouse, Stage, Selection, etc.)
2. Deactivate timers whose `object` field references the removed MC

### Fix Plan

#### Fix A: Skip removed MCs in broadcastMessage dispatch

In `builtin_broadcaster_broadcastMessage` (action.c ~line 19702), when iterating the `_listeners` array, check if each listener is a MovieClip with `depth == INT_MIN` (dead) or `pending_removal == 1`, and skip it:

```c
// In broadcastMessage listener dispatch loop:
for (int i = 0; i < arr->length; i++) {
    ActionVar* listener = &arr->elements[i];
    // Skip removed MovieClips
    if (listener->type == ACTION_STACK_VALUE_MOVIECLIP) {
        MovieClip* mc = (MovieClip*)listener->data.numeric_value;
        if (mc == NULL || mc->depth == INT_MIN) continue;
    }
    // ... dispatch to listener ...
}
```

This fixes `string_paths_keyevents` because `Key.broadcastMessage("onKeyDown")` will skip the removed clip.

#### Fix B: Skip removed MC timers in processTimers

In `processTimers` (action.c ~line 48434), when a method-form timer fires, check if the target object is a removed MovieClip:

```c
// In processTimers, before invoking timer callback:
if (t->is_method && t->object.type == ACTION_STACK_VALUE_MOVIECLIP) {
    MovieClip* mc = (MovieClip*)t->object.data.numeric_value;
    if (mc == NULL || mc->depth == INT_MIN) {
        t->active = 0;  // Deactivate timer permanently
        continue;
    }
}
```

This fixes `string_paths_timer` because the timer is deactivated when its target MC is dead.

### Files to modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | broadcastMessage: skip dead MC listeners. processTimers: deactivate timers on dead MCs. |

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=string_paths_keyevents --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_timer --diff --verbose
```

### Potential side effects

- `broadcastMessage` change: could affect any test using Key/Mouse/Stage listeners. Verify `focus_keyboard_press`, `focus_mouse`, `mouse_events`, `key_events` still pass.
- Timer change: could affect `set_interval` test (27/27 PASS). Verify it still passes.

---

## Blocked Tests

### issue_2030 (4 lines) — Blocked on BITMAP_DATA_PLAN Phase 1

Creates an empty MC, creates a 10x10 BitmapData, calls `mc.attachBitmap(bitmap, 0)`, then checks `mc._width` and `mc._height`. Expects 10/10 from the attached bitmap dimensions. Requires:
1. BitmapData pixel buffer (BITMAP_DATA_PLAN Phase 1)
2. `MovieClip.attachBitmap()` method that sets MC dimensions from bitmap

### displacementmapfilter_mappoint_throw_error (13 lines) — Partially blocked

Two issues:
1. **Point.toString()** returns `[object Object]` instead of `(x=1, y=2)`. The Point class exists but its toString is not implemented. This is fixable independently.
2. **Error throw from native constructor** — the test expects `DisplacementMapFilter` constructor to throw an Error when `mapPoint` is invalid. Our try/catch infrastructure exists but native constructors don't throw. Requires throw-from-native support.

### sandbox_type_remote (3 lines) — Blocked on loadMovie

Line 1 passes (`localTrusted` for root SWF). Lines 2-3 need a loaded child SWF with `remote` sandbox type.

### issue_2084 (16 lines) — Blocked on loadMovie

Tests onLoad + attachMovie positioning in loaded child clips. Needs multi-SWF execution.

### geturl (7 lines) — Blocked on navigator infrastructure

Tests `getURL()` with POST parameters. Expected output traces the URL, target, method, and POST parameters. Would need a navigator/network logging hook in the test harness.

### localconnection (579 lines) — Low priority

Full LocalConnection protocol with domain management, send/receive, connect/close. Very complex, 579 expected lines. Consider adding to ignored_tests.txt if effort exceeds ROI.
