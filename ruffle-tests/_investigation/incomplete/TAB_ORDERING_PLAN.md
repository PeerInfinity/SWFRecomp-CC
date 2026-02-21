# Tab Ordering Implementation Plan
<!-- TESTS: tab_ordering_automatic_basic, tab_ordering_automatic_order_grid, tab_ordering_automatic_order_same_position, tab_ordering_children, tab_ordering_custom_basic, tab_ordering_custom_duplicate_index, tab_ordering_custom_i32_vs_u32, tab_ordering_custom_m1, tab_ordering_events, tab_ordering_events_mouse, tab_ordering_movieclip_enabled_default, tab_ordering_reverse, tab_ordering_tabbable, edittext_tab_focus, focusrect_swf5, focusrect_swf6 -->

Last updated: 2026-02-20

## Status: NOT STARTED

Prerequisites:
- **FOCUS_SYSTEM_PLAN.md** (focus state tracking, onSetFocus/onKillFocus callbacks,
  `Selection.getFocus()`, focus dispatch to clips). Tab ordering builds on the focus
  system — Tab key just advances which clip is focused.
- **input-event-injection.md Phase 7** (Key AsBroadcaster) — COMPLETE (Tab key delivered as
  `EV_KEY_DOWN` with code 9)

Corresponds to **Phase 9** of `input-event-injection.md`.

---

## Overview

14 `tab_ordering_*` tests + 2 `edittext_tab_focus` + 2 `focusrect_swf*` tests cover Flash's
Tab-key focus navigation. All use `input.json` with `KeyDown/Wait` events.

Tab ordering in Flash:
1. Objects with explicit `tabIndex` are visited first, sorted numerically ascending
2. Objects without `tabIndex` (automatic order) follow, sorted by position (top-to-bottom, then
   left-to-right within a row)
3. Escape key reverses to the previous focus (NOT Shift+Tab = backwards; Escape = undo)
4. `tabEnabled` controls whether an object participates in Tab navigation
5. `tabChildren` on a parent clip controls whether its children participate
6. `Selection.addListener` receives `onSetFocus(oldFocus, newFocus)` callbacks
7. `onSetFocus`/`onKillFocus` also fire directly on the clips

---

## Test Inventory

| Test | Lines | Input | Key behavior |
|------|-------|-------|--------------|
| `tab_ordering_automatic_basic` | 48 | Tab×8 | 3 text fields (no tabIndex), automatic position ordering |
| `tab_ordering_automatic_order_grid` | ? | Tab×N | Grid of clips, verify position-based order |
| `tab_ordering_automatic_order_same_position` | ? | Tab×N | Two clips at same position — stable sort order |
| `tab_ordering_children` | ? | Tab×N | `tabChildren=false` excludes nested children |
| `tab_ordering_custom_basic` | 48 | Tab×8 + Escape | `tabIndex` values reorder: text1=3, text3=1, text2=2 etc. |
| `tab_ordering_custom_duplicate_index` | ? | Tab×N | Two clips with same `tabIndex` — tie-break by position |
| `tab_ordering_custom_i32_vs_u32` | ? | Tab×N | `tabIndex` with large values (int32 vs uint32 semantics) |
| `tab_ordering_custom_m1` | ? | Tab×N | `tabIndex = -1` behavior |
| `tab_ordering_events` | 56 | Tab×N | `Selection.addListener` + clip.onSetFocus/onKillFocus event order |
| `tab_ordering_events_mouse` | ? | Tab + MouseDown | Mix of Tab and mouse clicks for focus |
| `tab_ordering_movieclip_enabled_default` | ? | Tab×N | Default `tabEnabled` for MovieClips is undefined (auto-false) |
| `tab_ordering_reverse` | ? | Shift+Tab×N | Shift+Tab navigates backwards |
| `tab_ordering_tabbable` | 14 | Tab×1 | Enumerate all tabbable elements and their tab-enabled status |
| `edittext_tab_focus` | ? | Tab×N | Tab focus between edit text fields |
| `focusrect_swf5` | 6 | Tab×6 | SWF5: focusrect + tab, "Setting test stage to N" traces |
| `focusrect_swf6` | ? | Tab×N | SWF6: same with focusrect semantics |

---

## Tab Order Algorithm

### Step 1: Collect focusable objects

Traverse `display_list[1..max_depth]`. For each entry:

**Buttons (`CHAR_TYPE_BUTTON`):**
- Tabbable by default (tabEnabled defaults to `true` for buttons)
- `tabEnabled = false` explicitly disables tab focus

**Input text fields (`CHAR_TYPE_TEXT` with `HasText` + writable):**
- Tabbable by default (tabEnabled defaults to `true` for input TFs)

**MovieClips (`CHAR_TYPE_SPRITE`):**
- NOT tabbable by default (tabEnabled defaults to `undefined`, treated as `false` unless
  `tabEnabled = true` is set explicitly on the MC instance)
- Exception: if `focusEnabled = true`, clip is focusable by mouse click but still not
  tabbable unless `tabEnabled = true`

**Nested clips:** Recurse into sprite display lists ONLY if parent's `tabChildren != false`
(default is `undefined`, treated as `true`).

### Step 2: Partition by tabIndex

- **Group A**: clips with explicit numeric `tabIndex` (not undefined, not -1) — sorted by
  tabIndex ascending. On tie (same tabIndex), sort by position (see Step 3).
- **Group B**: clips with `tabIndex = undefined` or `tabIndex = -1` — sorted by position.

Note: `tabIndex = -1` behaves like "no tabIndex" for sorting (goes into Group B). Verify
with `tab_ordering_custom_m1`.

### Step 3: Position sort (for Group B and tie-breaking in Group A)

Sort by: primary = y position (top first), secondary = x position (left first).

Position comes from the clip's transform: `ng_getTransformXY(depth, &x, &y)` gives the
display position in stage pixels. Compare y first (lower y = earlier), then x (lower x = earlier).

Same-position tie-breaking (`tab_ordering_automatic_order_same_position`): likely by depth
(lower depth = earlier) or by instance name. Verify from test output.

### Step 4: Combined list

Tab order = Group A (sorted by tabIndex) + Group B (sorted by position).

For `tab_ordering_custom_basic` expected:
```
null → text1 (tabIndex 3? or is text1 first by position?) → text3 (tabIndex 1) → text2 (tabIndex 2) → text5 → text6 → text3 → text2 ...
```
Reading output: first Tab goes to text1 with no tabIndex, second goes to text3, etc. Verify
exact mapping from the test SWF.

---

## Phase A: Tab Key Handling in swf_core.c

On `EV_KEY_DOWN` with `ev->code == 9` (Tab):

```c
case EV_KEY_DOWN:
    if (ev->code == 9) {
        // Tab: advance focus before dispatching key events
        int shift_down = app_context->keys.down[16];  // VK_SHIFT
        tab_advance_focus(app_context, shift_down ? -1 : 1);
        // Tab key is consumed for focus navigation — still call actionDispatchKeyDown
        // so Key listeners know Tab was pressed, but focused clip gets onKeyUp not onKeyDown
    } else {
        app_context->keys.down[ev->code] = 1;
        ...
        dispatch_key_to_focused(app_context, ev->code, 1);
        actionDispatchKeyDown(app_context);
        dispatch_button_key_actions(app_context, ev->code);
    }
    break;
```

`tab_advance_focus(app_context, direction)` in `tag.c`:
```c
void tab_advance_focus(SWFAppContext* app_context, int direction)
{
    // 1. Build sorted tab order list
    TabEntry* order = NULL;
    size_t order_count = 0;
    build_tab_order(app_context, &order, &order_count);

    // 2. Find current focus in list
    size_t cur_idx = find_focused_in_tab_order(order, order_count, g_focused_depth);

    // 3. Advance by direction (+1 or -1), wrapping
    size_t next_idx = (cur_idx + direction + order_count) % order_count;
    if (order_count == 0) return;

    // 4. Set new focus (fires onKillFocus/onSetFocus)
    set_focus(app_context, order[next_idx].depth);

    free(order);
}
```

### Escape key reverses to previous focus

From `tab_ordering_custom_basic` output: pressing Escape after Tab navigates backwards.
Flash's actual behavior: Escape does NOT reverse Tab — it clears focus (sets to null) OR
it acts as Shift+Tab in some contexts. Verify carefully from test output.

Looking at `tab_ordering_custom_basic` output:
```
Focus changed old: _level0.text6, new: _level0.text5   ← Escape pressed
```
This suggests Escape = previous focus (Shift+Tab-like). Store `g_previous_focused_depth`
and on Escape, set focus back to it.

---

## Phase B: `tabEnabled` / `tabIndex` / `tabChildren` Properties

These are AS2 properties read from the MovieClip's dynamic property bag.

### Reading `tabEnabled`

```c
int get_tab_enabled(DisplayObject* obj)
{
    // Read from AS object for this entry
    ActionVar* prop = get_mc_property(obj, "tabEnabled");
    if (!prop || prop->type == ACTION_STACK_VALUE_UNDEFINED) {
        // Default: true for buttons/input text, false for movieclips
        return (obj->char_type == CHAR_TYPE_BUTTON) ? 1 :
               (obj->char_type == CHAR_TYPE_TEXT && is_input_text(obj)) ? 1 : 0;
    }
    return is_truthy(prop);
}
```

### Reading `tabIndex`

```c
int get_tab_index(DisplayObject* obj)
{
    ActionVar* prop = get_mc_property(obj, "tabIndex");
    if (!prop || prop->type == ACTION_STACK_VALUE_UNDEFINED) return -1;
    return (int)convert_to_int(prop);
}
```

### Reading `tabChildren`

For sprite clips, `tabChildren` controls whether children participate:
```c
int get_tab_children(DisplayObject* obj)
{
    ActionVar* prop = get_mc_property(obj, "tabChildren");
    if (!prop || prop->type == ACTION_STACK_VALUE_UNDEFINED) return 1;  // default true
    return is_truthy(prop);
}
```

### Large tabIndex values (`tab_ordering_custom_i32_vs_u32`)

Flash treats `tabIndex` as an integer. Large values like 2147483648 (2^31) may behave
differently if read as signed vs unsigned. Test specifically covers this edge case.

---

## Phase C: Focus Events on Tab Change

`tab_ordering_events` expected ordering (from similar tests):
```
Setting the focus to _level0.clip
_level0.clip.onSetFocus          ← fires on the CLIP directly
Focus changed: null -> _level0.clip   ← Selection.addListener fires after
```

So order: (1) old.onKillFocus → (2) new.onSetFocus → (3) Selection listener.
This is the same order as FOCUS_SYSTEM_PLAN.md Phase A's `dispatch_focus_event` chain.
Tab focus uses the same focus event machinery.

---

## Phase D: Automatic Order — Position Sort

`tab_ordering_automatic_order_grid` places clips in a grid and verifies they're visited
top-to-bottom, left-to-right. Implementation: sort by `ng_getTransformXY()` values.

Grid snap: Flash uses a coarse sort where clips on the "same row" are grouped together.
The actual threshold appears to be: y values within ~20 pixels are considered same row.
Within a row, sort left-to-right by x. Verify from grid test output.

`tab_ordering_automatic_order_same_position`: two clips at same (x,y). Flash uses depth
as tie-breaker (lower depth first).

---

## Phase E: `tab_ordering_tabbable` — Enumerate Tabbable State

Expected output:
```
Tabbable elements:
  _level0.text12: false
  _level0.button11: false
  _level0.button10: true
  ...
```

This test calls a function that iterates all display entries and reports their tabbable
state. The SWF's AS code reads `Selection._tabbable` or equivalent. In Flash, this is
accessible via `Selection._focusrect` and related properties, OR via inspecting each
clip's `tabEnabled`.

The SWF likely iterates all named clips and checks tab-eligibility. This will work
automatically once `tabEnabled` reading is correct.

---

## Phase F: focusrect Tests

### `focusrect_swf5` and `focusrect_swf6`

Input: 6 Tab keypresses. Output: "Setting test stage to 1/2/3/4/5/6".
The SWF traces "Setting test stage to N" in a `Selection.addListener.onSetFocus` callback
or a `onSetFocus` callback on each clip. As Tab advances focus, the stage counter increments.

These tests should PASS automatically once Phase A (Tab key focus navigation) and Phase C
(focus events) are working. The "test stage" counter is just a trace in the onSetFocus handler.

`focusrect` itself is a visual rectangle drawn around focused clips in the player — this is
a rendering feature that doesn't affect trace output. The property `_focusrect` on clips
controls whether the focus rectangle is shown. Not needed for trace tests to pass.

---

## Implementation Order

```
FOCUS_SYSTEM_PLAN Phase A+C (focus state + getFocus) — prerequisite
    ↓
Phase A: Tab key advances focus (tab_advance_focus in tag.c, key handling in swf_core.c)
    ↓
Phase B: tabEnabled/tabIndex/tabChildren property reading
    ↓
Phase C: Focus events already work via FOCUS_SYSTEM_PLAN machinery
    ↓
Phase D: Automatic order (position sort)
    ↓
Phase E: Tabbable enumeration (automatic after B)
Phase F: focusrect tests (automatic after A+C)
```

---

## Estimated Test Fixes Per Phase

| Phase | Tests Fixed |
|-------|------------|
| A+C | `tab_ordering_automatic_basic`, `focusrect_swf5`, `focusrect_swf6` |
| B | `tab_ordering_custom_basic`, `tab_ordering_movieclip_enabled_default`, `edittext_tab_focus` |
| D | `tab_ordering_automatic_order_grid`, `tab_ordering_automatic_order_same_position`, `tab_ordering_children` |
| Various | `tab_ordering_custom_duplicate_index`, `tab_ordering_custom_i32_vs_u32`, `tab_ordering_custom_m1` |
| Full | `tab_ordering_events`, `tab_ordering_events_mouse`, `tab_ordering_reverse`, `tab_ordering_tabbable` |

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag.c` | `build_tab_order()`, `tab_advance_focus()`, `get_tab_enabled/index/children()` |
| `SWFModernRuntime/src/libswf/swf_core.c` | Tab key special-casing in EV_KEY_DOWN; Escape key handling |
| `SWFModernRuntime/include/libswf/tag.h` | Declare new functions |

---

## Relationship to Other Plans

- **FOCUS_SYSTEM_PLAN.md**: Direct prerequisite — focus state, onSetFocus/onKillFocus,
  Selection.getFocus() must all be implemented first.
- **SELECTION_PLAN.md**: Full Selection API (setFocus, addListener, setSelection) is a
  separate plan. Some overlap — `tab_ordering_events` uses `Selection.addListener`.
- **TEXTFIELD_PLAN.md Phase 4**: EditText input (TextInput events) depends on focus from
  this plan. `edittext_tab_focus` is a joint dependency.
- **input-event-injection.md Phase 9**: This plan IS Phase 9 of that plan, now as a
  standalone document.
