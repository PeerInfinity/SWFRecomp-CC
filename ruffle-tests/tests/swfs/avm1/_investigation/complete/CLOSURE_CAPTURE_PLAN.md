# Closure Variable Capture Plan
<!-- TESTS: focus_keyboard_press, focus_mouse, focus_mouse_rollout, swf5_no_closure -->

<!-- PLAN_META
id: CLOSURE_CAPTURE
status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-02-24

## Status: CLOSURE FIX COMPLETE — remaining test failures blocked on other systems

### Test Results After Fix

| Test | Closure Fixed? | Passing? | Remaining Blocker |
|------|---------------|----------|-------------------|
| focus_keyboard_press | YES | NO (15/60) | Focus cycling (Tab key), key event dispatch ordering, extra events to focused target |
| focus_mouse | YES | NO (7/45) | MC-as-button hit-testing (onPress/onRelease), Focus events |
| focus_mouse_rollout | YES | NO (0/4) | Mouse rollout infrastructure, focus tracking |
| swf5_no_closure | YES | NO (6/19) | SWF5 `this` binding in method calls (`clip.g()`, `obj.g()`) |

### What Was Fixed (commit 7f3569ed)

**Root Cause:** Three call sites invoked closures without restoring captured scope chains:

1. **`mc_call_as2_handler_ng`** (MC event handlers: onKeyDown, onPress, onMouseMove, etc.)
   - Called `func->advanced_func()` directly without pushing `func->captured_scope[]` onto the scope chain
   - Fixed: restore captured scopes before call, pop after return

2. **`broadcastMessage`** (Key/Mouse/Stage listeners)
   - Same issue — called func directly without scope restoration
   - Fixed: added scope push/pop around both type 1 and type 2 function calls

3. **SWF5 no-closure semantics**
   - `actionDefineFunction` and `actionDefineFunction2` captured scopes unconditionally
   - Fixed: gated scope capture on `g_swf_version >= 6`

**Note:** The core `actionCallFunction` path already handled scope restoration correctly.
The bug was only in the "shortcut" call paths for event handlers and broadcast listeners.

### Remaining Blockers (NOT closure-related)

The 4 tests still fail, but for reasons unrelated to closure capture:

- **focus_keyboard_press**: Tab key focus cycling dispatches events to wrong targets; escape key handling; event ordering between key events and focus changes
- **focus_mouse**: MC-as-button hit-testing (onPress/onRelease require mouse position inside MC bounds); focus change events during mouse clicks
- **focus_mouse_rollout**: No mouse rollover/rollout infrastructure; focus tracking for click-to-focus
- **swf5_no_closure**: SWF5 `this` binding — when calling `clip.g()` via actionCallMethod on a MC, `this` should resolve to the clip, not _level0. Similar issue with `obj.g()` where `this` should be `[object Object]`.

These blockers belong to: FOCUS_SYSTEM_PLAN, HIT_TESTING_PLAN, and a potential SWF5_THIS_BINDING issue.

---

## Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Added scope restoration to `mc_call_as2_handler_ng` and `broadcastMessage`; gated scope capture on SWF version >= 6 |

---

## Verification

No regressions on existing passing tests:
- `closure_scope` — PASS (SWF6+ closure capture still works)
- `with` — PASS
- `with_variable_scopes` — PASS
- `movieclip_depth_methods` — PASS
- `boxed_primitives` — PASS
- `try_catch_finally` — PASS
- `extends_native_type` — PASS
- `stage_property_representation` — PASS
- `stage_display_state` — PASS
