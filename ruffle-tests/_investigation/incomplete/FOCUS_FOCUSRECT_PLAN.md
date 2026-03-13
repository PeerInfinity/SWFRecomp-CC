# Focus Visibility & FocusRect Property Plan
<!-- TESTS: focus_visibility_change, focusrect_property_swf5, focusrect_property_swf6, focusrect_property_swf7 -->

Last updated: 2026-03-12

## Status: INCOMPLETE — 0/4 tests passing

### Test Summary

| Test | Expected | Match | Issue |
|------|----------|-------|-------|
| `focus_visibility_change` | 45 | 7/45 (16%) | `_visible=false` doesn't auto-clear focus |
| `focusrect_property_swf5` | 1237 | 261/1237 (21%) | `_focusrect` defaults + global scope + coercion |
| `focusrect_property_swf6` | 1237 | 560/1237 (45%) | Same as swf5, different case rules |
| `focusrect_property_swf7` | 1237 | 718/1237 (58%) | Same as swf5, SWF7 case-sensitive |

### Related docs
- `blocked/FOCUS_SYSTEM_PLAN.md` — focus mouse/keyboard acquisition (6/7 PASS)
- `complete/TAB_ORDERING_PLAN.md` — tab navigation (16/16 PASS)

---

## Issue 1: Auto-Clear Focus on `_visible = false`

**Test**: `focus_visibility_change`

**Expected behavior**: When a focused object (MC, TextField, Button) is made invisible via `_visible = false`:
1. Focus is automatically cleared
2. `onSetFocus(old, null)` event fires on Selection listeners
3. `Selection.getFocus()` returns `null`
4. Making the object visible again does NOT restore focus

**Current behavior**: Setting `_visible = false` just sets the visible flag. Focus is not cleared, no events fire, `Selection.getFocus()` still returns the old path.

### Fix

In `action.c`, the `_visible` setter (around line 24155 and 28487 for MC builtins) sets `mc->visible = 0/1`. When setting to 0, add a check:

```c
if (mc->visible && !new_visible && g_focused_mc == mc) {
    selection_do_focus_change(app_context, mc, NULL);
}
mc->visible = new_visible;
```

Same logic needed for:
- MC `_visible` setter (SetMember / SetProperty paths)
- TextField `_visible` setter
- Button `_visible` setter (if separate)

**Complexity**: Low. Straightforward focus-clear hook.

---

## Issue 2: `_focusrect` Property Semantics

**Tests**: `focusrect_property_swf5`, `focusrect_property_swf6`, `focusrect_property_swf7`

These are exhaustive tests of `_focusrect` get/set behavior across MC, Button, TextField, and the global/root scope. Each SWF version tests the same property logic but with different case-sensitivity rules.

### Problem A: Root MC `_focusrect` default

**Expected**: Root MC's `_focusrect` defaults to `true` (boolean). The global-scope bare variable `_focusrect` resolves to root MC's `_focusrect`.

**Current**: Root MC's `focusrect` field initializes to `-1.0f` (null sentinel), so reading `_root._focusrect` returns `null`. And `_focusrect` as a bare variable returns `undefined` (doesn't resolve to root).

**Fix**:
1. In `actionFindOrCreateMovieClip` (or wherever root MC is initialized), set `focusrect = 1.0f` for the root MC specifically (depth==0 or however root is identified). Other MCs keep `-1.0f` (null default).
2. In `getVariable("_focusrect")`, add a fallback that resolves to root MC's `_focusrect` builtin property (similar to how `_x`, `_y` resolve on root).

### Problem B: Root `_focusrect` coercion to boolean

**Expected**: Root MC's `_focusrect` getter returns `true`/`false` (boolean), not raw float or null. Non-root MCs return `true`/`false`/`null` (tri-state).

**Current**: The MC `_focusrect` getter returns null for `-1.0f` and F32 otherwise. Root MC needs special boolean coercion.

**Fix**: In the `_focusrect` getter, if the MC is root, coerce: `focusrect > 0 → true, else → false`. For non-root MCs, keep tri-state behavior (`-1.0f → null, 0 → false, >0 → true`).

### Problem C: `_focusrect` setter type coercion

**Expected**: Setting `_focusrect` coerces values:
- Objects with `valueOf()` → call valueOf, then coerce result
- Strings → some become `true`/`false`/`null` based on rules
- The coercion rules differ between root (boolean only) and non-root (tri-state)

**Fix**: Match the coercion rules observed in the test output. The exact rules need careful extraction from the expected output for each SWF version.

### Problem D: Case sensitivity per SWF version

- SWF5/6: `_focusrect` is case-insensitive (`_foCusRect` works)
- SWF7+: `_focusrect` is case-insensitive for builtin properties (builtins are always case-insensitive)

This likely already works correctly if the MC builtin property lookup is case-insensitive, which it should be.

---

## Implementation Order

1. **Root `_focusrect` default** (Problem A) — change init from `-1.0f` to `1.0f` for root MC
2. **Root `_focusrect` boolean coercion** (Problem B) — root-specific getter
3. **Global `_focusrect` resolution** (Problem A) — `getVariable` fallback to root MC
4. **Focus auto-clear on `_visible=false`** (Issue 1) — hook in visible setter
5. **Setter coercion** (Problem C) — match Flash's type coercion rules

Steps 1-4 should get the majority of lines matching. Step 5 is refinement for remaining edge cases.

---

## Estimated Impact

- `focus_visibility_change`: Issue 1 alone should fix most of the 38 missing lines
- `focusrect_property_swf7`: Problems A+B should fix ~500+ lines (root/global sections)
- `focusrect_property_swf5/6`: Same fixes, different match improvement due to case rules
