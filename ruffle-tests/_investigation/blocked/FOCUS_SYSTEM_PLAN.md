# Focus System Implementation Plan
<!-- TESTS: focus_mouse, focus_mouse_focusable, focus_mouse_rollout, focus_root_movie, focus_keyboard_press, focusrect_focuslost, movieclip_focusenabled -->

Last updated: 2026-03-07

## Status: BLOCKED — 6/7 tests passing

### Passing tests (6)
- `focus_root_movie` — Root MC rejection in `mc_is_focusable_by_setfocus`
- `focusrect_focuslost` — Tab-triggered onRollOut/onRollOver + window focus lost handling
- `movieclip_focusenabled` — Dot-path resolution in `getMovieClipByTarget` + string focusEnabled + button-handler focusability
- `focus_mouse` — **45/45 PASS** ✅ (text field hit-testing via mc_get_pixel_aabb_ng, commit e7974be4)
- `focus_keyboard_press` — **60/60 PASS** ✅ (fixed by MOUSE_EVENTS_ADVANCED Phase 3: key simulation)
- `focus_mouse_rollout` — **4/4 PASS** ✅ (fixed by MOUSE_EVENTS_ADVANCED Phase 2: roll dispatch)

### Blocked tests (1)

| Test | Match | Issue | Blocker |
|------|-------|-------|---------|
| `focus_mouse_focusable` | 0/8 | Needs dynamic createEmptyMovieClip/createTextField + "Focus changed" listener | **Dynamic object creation** |

### Resolved issues (2026-02-25, commit d9138260)

1. **AVM1 mouse-focus rules**: Buttons are NOT focusable by mouse click in AVM1 (only text fields). `mc_is_focusable_by_click` updated.
2. **Focus clearing logic**: Clicking non-focusable area only clears focus if current focus was mouse-focusable (text field). Tab/setFocus-set focus on buttons/MCs is preserved.
3. **`_focusrect` gating**: When `_focusrect = false`, Enter/Space no longer fire onPress/onRelease on focused MCs. Only onKeyDown/onKeyUp still fire.
4. **Button DoAction interleaving**: Keyboard activation of SWF buttons now correctly interleaves: press DoAction → onPress → release DoAction → onRelease.

### Resolved blocker: Closure variable capture (2026-02-24)

The closure capture bug that blocked 3 tests has been fixed (commit 7f3569ed). Event handler closures now correctly resolve captured variables from enclosing function scopes. See `blocked/CLOSURE_CAPTURE_PLAN.md`.

### Remaining blockers

**focus_keyboard_press** (15/60): Lines 1-15 match perfectly. The _focusrect gating and button DoAction interleaving work correctly (visible in post-Escape section). The blocker is that our event pump processes all events in one go, producing a SECOND round of Enter/Space/A events per focus group that Ruffle's output doesn't include. Root cause unknown — Ruffle also pumps all events in one `injector.next()` call (no Wait markers), yet the second batch doesn't produce output in Ruffle.

**focus_mouse** (17/45 match, 45 lines actual): Lines 1-17 match. The button mouse-focus fix resolved the incorrect "Focus at: _level0.button" issue. Now the blocker is text field mouse-click focus: clicking at coordinates (360, 190) should focus the text field, but `actionMouseClickFocus` can't find it via `mc_get_pixel_aabb_ng` hit-test (text field bounds may not be computed, or coordinate mapping is wrong).

**focus_mouse_rollout** (0/4): The first expected line is `Focus at: _level0.text` (text field click focus), which is the same blocker as focus_mouse.

**focus_mouse_focusable** (0/8): Entirely blocked by dynamic `createEmptyMovieClip`/`createTextField` + "Focus changed" (onSetFocus with oldFocus/newFocus args).

---

## What was implemented

### In `action.c`:
- `mc_is_focusable_by_setfocus()`: Checks root MC rejection, textfield (static + dynamic), button, button-mode handlers (onPress/onRelease/etc), and focusEnabled (boolean/F64/string)
- `mc_is_focusable_by_click()`: Only text fields (editable/selectable) gain focus on click. Buttons and MCs are NOT mouse-focusable in AVM1.
- `actionDispatchMCMouseMoveGlobal()`: Global onMouseMove to all sprite MCs
- `actionDispatchMCMouseDown()` / `actionDispatchMCMouseUp()`: Global onMouseDown/Up to sprite MCs
- `actionDispatchKeyDownToFocused()`: onKeyDown to focused MC (excludes Tab)
- `actionDispatchKeyPressToFocused()`: Enter/Space simulated press+release on focused MC. Gated by `_focusrect` (root_movieclip.focusrect). For SWF buttons, interleaves DoAction and AS2 handlers.
- `actionDispatchKeyUpToFocused()`: onKeyUp to focused MC
- `actionMouseClickFocus()`: Mouse click focus acquisition. Only clears focus if current focus was mouse-focusable.
- `actionWindowFocusLost()`: Clear focus on window focus loss
- `getMovieClipByTarget()`: Extended to resolve `_level0.child` and `_root.child` dot-paths
- Tab focus fires onRollOut/onRollOver during `actionAdvanceTabFocus()`
- Closure scope restoration in `mc_call_as2_handler_ng` and `broadcastMessage` (2026-02-24)

### In `tag.c`:
- `ng_simulateButtonTransition()`: Fire button DoAction conditions for a specific transition mask (0x0004=press, 0x0008=release)
- `ng_simulateButtonPressRelease()`: Convenience wrapper for full press+release

### In `swf_core.c`:
- EV_MOUSE_MOVE: calls `actionDispatchMCMouseMoveGlobal()`
- EV_MOUSE_DOWN_LEFT: calls `actionDispatchMCMouseDown()` + `actionMouseClickFocus()`
- EV_MOUSE_UP_LEFT: calls `actionDispatchMCMouseUp()`
- EV_KEY_DOWN: calls `actionDispatchKeyDownToFocused()` before Key broadcast, `actionDispatchKeyPressToFocused()` after button key actions
- EV_KEY_UP: calls `actionDispatchKeyUpToFocused()` before Key broadcast
- EV_FOCUS_LOST: calls `actionWindowFocusLost()`

### In `tag.h` / `action.h`:
- Declared all new dispatch functions

---

## Side benefit

The `getMovieClipByTarget()` dot-path fix also improved `movieclip_focusenabled` from 89/99 to 99/99 — `Selection.setFocus/getFocus` now work with `_level0.child` string paths.
