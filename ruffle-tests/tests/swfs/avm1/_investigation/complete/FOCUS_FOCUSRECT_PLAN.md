# Focus Visibility & FocusRect Property Plan
<!-- TESTS: focus_visibility_change, focusrect_property_swf5, focusrect_property_swf6, focusrect_property_swf7 -->

<!-- PLAN_META
id: FOCUS_FOCUSRECT
status: complete
dependencies:
  - plan: FOCUS_SYSTEM
    type: requires
    reason: "Focus rect rendering depends on focus management"
blockers: []
-->

Last updated: 2026-03-13

## Status: COMPLETE — 4/4 tests passing

### Test Summary

| Test | Expected | Match | Status |
|------|----------|-------|--------|
| `focus_visibility_change` | 45 | 45/45 (100%) | PASS |
| `focusrect_property_swf5` | 1237 | 1237/1237 (100%) | PASS |
| `focusrect_property_swf6` | 1237 | 1237/1237 (100%) | PASS |
| `focusrect_property_swf7` | 1237 | 1237/1237 (100%) | PASS |

### Related docs
- `blocked/FOCUS_SYSTEM_PLAN.md` — focus mouse/keyboard acquisition (6/7 PASS)
- `complete/TAB_ORDERING_PLAN.md` — tab navigation (16/16 PASS)

---

## Changes Made

### Issue 1: Auto-Clear Focus on `_visible = false` (focus_visibility_change)

Added focus-clear hook at all 4 `_visible` setter sites in `action.c`:
- SetVariable `_visible` path
- SetMember `_visible` path
- SetProperty case 7
- mcGetSetPropertyByName `_visible` path

When `_visible` transitions from true to false on the focused MC, `selection_do_focus_change(app_context, mc, NULL)` fires before setting the flag.

### Issue 2: `_focusrect` Property Semantics (focusrect_property_swf5/6/7)

**Root MC default**: Changed `focusrect` initializer from `-1.0f` to `1.0f` for root MC.

**Getter semantics** (GetVariable, GetMember, GetProperty):
- SWF5: `_focusrect` is a global (stage) flag. All objects read root MC's value. Returns Number 1/0.
- SWF6: Root MC uses stage focusrect (returns Boolean). Non-root objects have per-object tri-state (true/false/null).
- SWF7+: Per-object. Root defaults true, children default null. Returns Boolean/null.
- `refers_to_stage_focus_rect()` logic: `swf_version <= 5 || mc == &root_movieclip`

**Setter semantics** (SetVariable, SetMember, SetProperty case 17):
- Stage setter (root/SWF5): null/undefined → no-op, object/array/function → false, boolean → direct, string → strtod with NaN→no-op, numeric → isnan check
- Per-object setter (non-root SWF6+): null/undefined → null(-1.0f), boolean → direct, object/MC → true, string → SWF7+ truthiness or SWF6 numeric parse, numeric → !isnan && !=0

**SetProperty case 17**: Was completely missing — added full handler.

**GetVariable bare `_focusrect`**: Was not handled in MC builtin GET section — added handler that resolves to root MC.

### Issue 3: Constructor Version Gating

- MovieClip constructor: gated to SWF6+ (both `_global` registration and `getVariable` hardcoded lookup)
- TextField constructor: gated to SWF6+ (same two sites)
- Button constructor: gated to SWF7+ (`_global` registration)

This prevents SWF5 `MovieClip.prototype.hasOwnProperty("_focusrect")` from resolving (MovieClip should be undefined in SWF5).
