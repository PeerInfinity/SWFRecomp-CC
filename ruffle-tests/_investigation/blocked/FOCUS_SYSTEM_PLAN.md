# Focus System Implementation Plan
<!-- TESTS: focus_mouse, focus_mouse_focusable, focus_mouse_rollout, focus_root_movie, focus_keyboard_press, focusrect_focuslost -->

Last updated: 2026-02-24

## Status: BLOCKED — 3/6 tests passing

### Passing tests (3)
- `focus_root_movie` — Root MC rejection in `mc_is_focusable_by_setfocus`
- `focusrect_focuslost` — Tab-triggered onRollOut/onRollOver + window focus lost handling
- `movieclip_focusenabled` — Dot-path resolution in `getMovieClipByTarget` + string focusEnabled + button-handler focusability

### Blocked tests (3) — remaining architectural limitations

| Test | Match | Issue | Blocker |
|------|-------|-------|---------|
| `focus_keyboard_press` | 15/60 | Tab focus cycling dispatches events to wrong target; extra key events; event ordering | **Key event dispatch ordering** |
| `focus_mouse` | 7/45 | Missing onPress/onRelease (needs MC-as-button hit-test); missing Focus events | **Mouse hit-testing + focus change events** |
| `focus_mouse_rollout` | 0/4 | No output — needs mouse rollover/rollout and focus tracking | **Mouse rollout infrastructure** |
| `focus_mouse_focusable` | unknown | Dynamic createEmptyMovieClip/createTextField not fully supported | **Dynamic object creation** |

### Resolved blocker: Closure variable capture (2026-02-24)

The closure capture bug that blocked 3 tests has been fixed (commit 7f3569ed). Event handler closures now correctly resolve captured variables from enclosing function scopes. See `blocked/CLOSURE_CAPTURE_PLAN.md`.

### Remaining blockers

**focus_keyboard_press**: Closure part works (lines 1-15 match). Remaining issues:
- After Tab advances focus to button, key events still fire to clip instead of button
- Tab-triggered focus events (`Tab pressed`, `Focus at: _level0.button`) are interleaved incorrectly with key events
- Expected: Tab → focus change → key events on new target. Actual: key events on old target continue, Tab + focus happen later

**focus_mouse**: Closure part works. Remaining issues:
- MC-as-button: clicking on clip should trigger `onPress`/`onRelease` (needs bounds hit-test for clip area)
- Button press/release actions (`press`, `release`) need to fire when clicking on the button
- Focus acquisition on click (`Focus at: _level0.text`, `Focus at: null`) not implemented for mouse clicks

**focus_mouse_rollout**: Empty output — the test uses mouse movement between objects to trigger `onRollOut`/`onRollOver`, then `onPress` on focused MC. Needs full mouse event dispatch chain.

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
- Closure scope restoration in `mc_call_as2_handler_ng` and `broadcastMessage` (2026-02-24)

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
