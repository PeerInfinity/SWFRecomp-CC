# Focus System Implementation Plan
<!-- TESTS: focus_mouse, focus_mouse_focusable, focus_mouse_rollout, focus_root_movie, focus_keyboard_press, focusrect_focuslost -->

Last updated: 2026-02-23

## Status: BLOCKED — 3/6 tests passing

### Passing tests (3)
- `focus_root_movie` — Root MC rejection in `mc_is_focusable_by_setfocus`
- `focusrect_focuslost` — Tab-triggered onRollOut/onRollOver + window focus lost handling
- `movieclip_focusenabled` — Dot-path resolution in `getMovieClipByTarget` + string focusEnabled + button-handler focusability

### Blocked tests (4) — pre-existing architectural limitations

| Test | Issue | Blocker |
|------|-------|---------|
| `focus_keyboard_press` | Closures over function parameters show "undefined" instead of MC path | **Closure variable capture bug** |
| `focus_mouse` | Same closure bug + hit-test for MC-as-button | **Closure variable capture bug** |
| `focus_mouse_rollout` | Same closure bug + empty output (no hit test match) | **Closure variable capture bug** |
| `focus_mouse_focusable` | createEmptyMovieClip/createTextField dynamic objects not fully supported | **Dynamic object creation infrastructure** |

### Blocker: Closure variable capture

The test SWFs define handler functions like:
```actionscript
function setHandlers(obj) {
    obj.onKeyDown = function() { trace(obj + ".onKeyDown: " + Key.getCode()); };
}
```
The inner function captures `obj` (a function parameter). In Flash, this works via the scope chain. In our runtime, closures over function parameters don't capture the value — `obj` resolves to `undefined` at call time. This produces `undefined.onKeyDown` instead of `_level0.clip.onKeyDown`.

This affects 3 of the 4 blocked tests. Fixing closure variable capture is a significant architectural change to the scope chain/function call system.

### Blocker: Dynamic object creation

`focus_mouse_focusable` creates ~40 dynamic objects via `createEmptyMovieClip`/`createTextField` with specific positions and properties. While these functions exist, the click-focus hit testing doesn't properly match dynamically created objects. This is a separate infrastructure gap.

---

## What was implemented

### In `action.c`:
- `mc_is_focusable_by_setfocus()`: Checks root MC rejection, textfield (static + dynamic), button, button-mode handlers (onPress/onRelease/etc), and focusEnabled (boolean/F64/string)
- `mc_is_focusable_by_click()`: Only text fields (selectable) and buttons gain focus on click
- `actionDispatchMCMouseMoveGlobal()`: Global onMouseMove to all sprite MCs
- `actionDispatchMCMouseDown()` / `actionDispatchMCMouseUp()`: Global onMouseDown/Up to sprite MCs
- `actionDispatchKeyDownToFocused()`: onKeyDown to focused MC (excludes Tab)
- `actionDispatchKeyPressToFocused()`: Enter/Space simulated press+release on focused MC
- `actionDispatchKeyUpToFocused()`: onKeyUp to focused MC
- `actionMouseClickFocus()`: Mouse click focus acquisition via hit-test
- `actionWindowFocusLost()`: Clear focus on window focus loss
- `getMovieClipByTarget()`: Extended to resolve `_level0.child` and `_root.child` dot-paths
- Tab focus now fires onRollOut/onRollOver during `actionAdvanceTabFocus()`

### In `swf_core.c`:
- EV_MOUSE_MOVE: calls `actionDispatchMCMouseMoveGlobal()`
- EV_MOUSE_DOWN_LEFT: calls `actionDispatchMCMouseDown()` + `actionMouseClickFocus()`
- EV_MOUSE_UP_LEFT: calls `actionDispatchMCMouseUp()`
- EV_KEY_DOWN: calls `actionDispatchKeyDownToFocused()` before Key broadcast, `actionDispatchKeyPressToFocused()` after button key actions
- EV_KEY_UP: calls `actionDispatchKeyUpToFocused()` before Key broadcast
- EV_FOCUS_LOST: calls `actionWindowFocusLost()`

### In `action.h`:
- Declared all new dispatch functions

---

## Side benefit

The `getMovieClipByTarget()` dot-path fix also improved `movieclip_focusenabled` from 89/99 to 99/99 — `Selection.setFocus/getFocus` now work with `_level0.child` string paths.
