# Selection Object Implementation Plan
<!-- TESTS: selection, selection_handlers, edittext_focus_selection, edittext_programmatic_focus -->

<!-- PLAN_META
id: SELECTION
status: complete
phases:
  - id: 1
    name: "Core Focus Tracking + setFocus/getFocus + Listener Pattern"
    status: complete
  - id: 2
    name: "replaceSel on TextField"
    status: complete
dependencies:
  - plan: TEXTFIELD
    type: requires
    reason: "Selection API depends on TextField infrastructure"
  - plan: FOCUS_SYSTEM
    type: requires
    reason: "Selection tracking depends on focus management"
blockers: []
-->

Last updated: 2026-02-15

## Overview

The `Selection` object is a built-in global static object (NOT a constructor — `typeof Selection === "object"`) that manages keyboard focus and text selection. It has 8 methods and uses the AsBroadcaster listener pattern for focus change notifications.

**Tests**: 2 direct tests (`selection`, `selection_handlers`), plus `edittext_focus_selection` (categorized under TextField) that depends on Selection.

**Current state (updated 2026-02-22)**: `g_selection_obj` is allocated as an empty `ASObject` and registered on `_global` as `"Selection"`. Input event injection Phases 1-4 are complete (event pump, mouse/key state). Text control actions (Copy/Cut/Paste/SelectAll, clipboard) are implemented in action.c. Focus tracking and Selection methods (setFocus, getFocus, setSelection, getBeginIndex, etc.) are not yet implemented. The remaining infrastructure blocker is **Phase 0 of input-event-injection.md** (struct unification) for hit-test-based focus acquisition.

---

## Test Inventory

### `selection` (456 expected lines, currently 0% passing)

Comprehensive test of all Selection methods. Tests:
- `setFocus(target)` with movie clips (a, b, c), buttons, text fields (input, selectable, non-selectable), `false`, `null`, `undefined`, non-existent target
- `getFocus()` returning target path strings (`"_level0.a"`, `"_level0.button"`, etc.) or `null`
- `getBeginIndex()` / `getCaretIndex()` / `getEndIndex()` returning `-1` for non-text or `0..N` for text fields with selection
- `setSelection(begin, end)` — text selection on focused text fields only
- `addListener(obj)` — listener `onSetFocus(oldFocus, newFocus)` callback
- `replaceSel(text)` on text fields — replaces selected text range
- `focusEnabled` property on movie clips

### `selection_handlers` (28 expected lines, currently 0% passing)

Tests focus change event ordering:
1. `oldFocus.onKillFocus(newFocus)` fires first
2. `newFocus.onSetFocus(oldFocus)` fires second
3. Registered Selection listener `onSetFocus(oldFocus, newFocus)` fires third
- No double-fire when setting focus to already-focused object
- `setFocus(null)` fires `onKillFocus(null)` on the losing object
- Lines 20-28 test `onRollOver`/`onRollOut` (mouse events, multi-frame — likely requires interactive input simulation, may not pass)

### `edittext_focus_selection` (2 expected lines, in ignored_tests.txt)

Uses `replaceSel("|")` to test caret position before/after focus. Deferred.

---

## API Reference

### Methods on Selection object

| Method | Signature | Return | Description |
|--------|-----------|--------|-------------|
| `setFocus` | `(target)` | `Boolean` | Set focus to target. Returns `true` on success, `false` on failure |
| `getFocus` | `()` | `String\|null` | Target path of focused object, or `null` |
| `getBeginIndex` | `()` | `Number` | Start of text selection, or `-1` |
| `getEndIndex` | `()` | `Number` | End of text selection, or `-1` |
| `getCaretIndex` | `()` | `Number` | Caret position in text, or `-1` |
| `setSelection` | `(begin, end)` | `undefined` | Set text selection range on focused text field |
| `addListener` | `(obj)` | `Boolean` | Register focus change listener |
| `removeListener` | `(obj)` | `Boolean` | Unregister focus change listener |

### setFocus behavior

- `setFocus(false)` → returns `false` (no change)
- `setFocus(null)` → clears focus, returns `true`
- `setFocus(undefined)` → clears focus, returns `true`
- `setFocus(validClip)` → sets focus to clip, returns `true`
- `setFocus(nonExistent)` → fails, returns `false`
- `setFocus(button)` → sets focus to button, returns `true`
- `setFocus(textField)` → sets focus to text field, returns `true` (input, selectable, and non-selectable all accept focus)
- `setFocus(alreadyFocused)` → returns `true`, does NOT fire events again
- `focusEnabled` on movie clips: setting it to `false` does NOT prevent setFocus from working (it still returns `true` and focus stays). `focusEnabled` only affects tab-navigation focus, not programmatic focus.

### setSelection behavior

- Only effective when the focused object is a text field (selectable or input type)
- On a non-text focused object (movie clip, button): no effect, indices stay at `-1`
- `setSelection(0)` (1 arg): begin=0, caret=textLength, end=textLength
- `setSelection(2, 2)`: begin=2, caret=2, end=2
- `setSelection()` (0 args): no change (keeps previous selection)
- `setSelection(-1, 1)`: clamps negative to 0 → begin=0, caret=1, end=1
- `setSelection(5, 2)` (reversed): normalizes → begin=min(2,5)=2, caret=min(2,5)=2, end=max(2,5)=5
- Always returns `undefined`

### Focus change event dispatch order

When focus changes from object A to object B:
1. `A.onKillFocus(B)` — per-object kill handler (B is passed as argument)
2. `B.onSetFocus(A)` — per-object set handler (A is passed as argument)
3. Each registered listener's `onSetFocus(A, B)` — broadcaster pattern (both passed)

When clearing focus (`setFocus(null)`):
1. `A.onKillFocus(null)` — per-object kill handler (null passed)
2. (no new object to call onSetFocus on)
3. Each listener's `onSetFocus(A, null)` — broadcaster

When setting focus from nothing to B:
1. (no old object to call onKillFocus on)
2. `B.onSetFocus(null)` — per-object set handler (null passed)
3. Each listener's `onSetFocus(null, B)` — broadcaster

---

## Implementation Plan

### Phase 1: Core Focus Tracking + setFocus/getFocus + Listener Pattern

**Goal**: Get the basic focus management working. This alone should pass a large portion of the `selection` test and all of `selection_handlers` (except the onRollOver/onRollOut lines at the end).

#### 1a. Global focus state

Add to `action.c` static globals:

```c
// Currently focused object — NULL means no focus
static MovieClip* g_focused_object = NULL;

// Selection listener list (AsBroadcaster pattern)
static ASObject** g_selection_listeners = NULL;
static int g_selection_listener_count = 0;
static int g_selection_listener_capacity = 0;
```

#### 1b. Target path string generation

`getFocus()` returns dot-notation path strings like `"_level0.a"`, `"_level0.button"`, `"_level0.text_input"`.

The runtime already has `mc->target` on MovieClip objects (used by `actionSetTarget`). This is in slash notation (`/a`). We need to convert to dot notation (`_level0.a`). There's already conversion code at action.c:7423 for `targetPath()` — reuse that pattern.

Helper function:
```c
static const char* getTargetPathDot(MovieClip* mc) {
    // Convert mc->target (slash notation like "/a") to "_level0.a"
    // If target is "/" → "_level0"
    // If target is "/a" → "_level0.a"
    // If target is "/a/b" → "_level0.a.b"
}
```

#### 1c. Native function implementations

Register 8 native functions on `g_selection_obj`:

**`selectionSetFocus(app_context)`**:
1. Pop 1 arg from stack
2. If arg is `false` (boolean false) → push `false`, return
3. If arg is `null` or `undefined` → clear focus (set `g_focused_object = NULL`), fire events, push `true`
4. If arg is a string → resolve path to MovieClip (like actionSetTarget). If resolved → set focus, fire events, push `true`. If not resolved → push `false`
5. If arg is an object (MovieClip) → set focus, fire events, push `true`
6. If focus actually changed (old != new), dispatch events in order:
   a. Call `onKillFocus(newFocus)` on old focused object (if it has that handler)
   b. Call `onSetFocus(oldFocus)` on new focused object (if it has that handler)
   c. For each registered listener, call `onSetFocus(oldFocus, newFocus)`
7. If same object already focused → push `true` but don't fire events

**`selectionGetFocus(app_context)`**:
1. If `g_focused_object == NULL` → push `null`
2. Else → push target path string of focused object

**`selectionGetBeginIndex(app_context)`**:
1. If `g_focused_object` is a text field (has `ng_textfield_idx >= 0`) and has a selection set → push begin index
2. Else → push `-1`

**`selectionGetCaretIndex(app_context)`**: Same pattern, push caret index or `-1`

**`selectionGetEndIndex(app_context)`**: Same pattern, push end index or `-1`

**`selectionSetSelection(app_context)`**:
1. Pop 2 args (begin, end). If 0 args → do nothing, push undefined. If 1 arg → end = text length.
2. If focused object is a text field with selectable text:
   - Clamp begin to `[0, textLength]`
   - Clamp end to `[0, textLength]`
   - If begin > end → swap (begin=min, end=max), caret = min
   - Else → caret = end
   - Store begin, caret, end on the text field
3. Push `undefined`

**`selectionAddListener(app_context)`**:
1. Pop 1 arg (listener object)
2. Add to `g_selection_listeners` array (grow if needed)
3. Push `true`

**`selectionRemoveListener(app_context)`**:
1. Pop 1 arg (listener object)
2. Find and remove from `g_selection_listeners`
3. Push `true` if found, `false` if not

#### 1d. Per-object focus handlers

When dispatching `onKillFocus`/`onSetFocus` on individual objects, look up the handler as a property on the object's `dynamic_props` (or on the object's prototype chain). If found and it's a function, call it with the appropriate argument.

This uses the same mechanism as existing event handlers (onEnterFrame, etc.) — check for a named property that's a function, then call it.

#### 1e. Text field selection state

Add per-textfield selection tracking. In the `MovieClip` struct (or alongside `ng_textfield_idx`), add:

```c
s32 selection_begin;   // -1 = no selection
s32 selection_caret;   // -1 = no selection
s32 selection_end;     // -1 = no selection
```

Initialize all to `-1`. Set by `selectionSetSelection()`.

#### 1f. Registration

During initialization (near the existing `g_selection_obj` setup):

```c
g_selection_obj = allocObject(app_context, 12);
// Register methods
static ASFunction g_sel_funcs[8];
// setFocus, getFocus, getBeginIndex, getEndIndex, getCaretIndex, setSelection, addListener, removeListener
struct { const char* name; size_t name_len; void (*func)(SWFAppContext*); } sel_methods[] = {
    {"setFocus", 8, selectionSetFocus},
    {"getFocus", 8, selectionGetFocus},
    {"getBeginIndex", 13, selectionGetBeginIndex},
    {"getEndIndex", 11, selectionGetEndIndex},
    {"getCaretIndex", 13, selectionGetCaretIndex},
    {"setSelection", 12, selectionSetSelection},
    {"addListener", 11, selectionAddListener},
    {"removeListener", 14, selectionRemoveListener},
};
for (int i = 0; i < 8; i++) {
    initNativeFunction(&g_sel_funcs[i], sel_methods[i].func, sel_methods[i].name);
    ActionVar fv = {.type = ACTION_STACK_VALUE_FUNCTION, .obj = (void*)&g_sel_funcs[i]};
    setProperty(g_selection_obj, sel_methods[i].name, sel_methods[i].name_len, &fv);
}
```

### Phase 2: replaceSel on TextField

**Goal**: Implement `TextField.replaceSel(text)` to pass the final section of the `selection` test.

#### 2a. replaceSel method

Add a `replaceSel` method on TextField instances (or on the TextField prototype if/when it exists). Since TextField prototype doesn't exist yet, implement as a special case in `actionCallMethod` for text field objects:

1. Get the text field's current text (from `dynamic_props.text` or ng_textfields)
2. Get the selection range (begin, end) — if no selection, use caret position (insert mode)
3. Replace `text[begin..end]` with the argument string
4. Update the caret position to end of inserted text
5. Clear the selection (begin = caret = insertPos + insertLen, end = same)

#### 2b. Text content tracking

Currently, text content for ng_textfields is stored as `initial_text` in the ng_textfields struct. For `replaceSel` and mutable `text` property, we need runtime-mutable text storage. Use `dynamic_props.text` (already exists as a property on the MovieClip's dynamic_props object).

---

## Dependencies and Interactions

### What this feature needs from existing code

1. **MovieClip target path** — already exists (`mc->target`, plus dot-notation conversion at action.c:7423)
2. **MovieClip lookup by name** — `findDisplayObjectByName()` exists in action.c for actionSetTarget. For path resolution (e.g., `setFocus("_level0.text_input")`), we may also need general path resolution
3. **Native function registration pattern** — already established (Math object, Key object, etc.)
4. **Event handler dispatch** — calling a function property on an object. The pattern exists in button actions and other places.
5. **Text field identification** — `mc->ng_textfield_idx >= 0` identifies text fields
6. **Text field text content** — `ng_textfields[idx].initial_text` for read, `dynamic_props.text` for write

### What other features depend on this

1. **TextField Phase 1** (TEXTFIELD_PLAN.md) — TextField prototype will add `replaceSel` and `replaceText` as proper prototype methods. Selection's `replaceSel` can be a special-case first, then moved to the prototype later.
2. **Focus/input tests** — `edittext_focus_selection`, `edittext_programmatic_focus`, and several `focus_*` tests depend on Selection.setFocus working.
3. **Tab ordering tests** (14 tests) — tab navigation focus uses the same focus system, but those tests also need synthetic keyboard input simulation.

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | All Selection method implementations, focus state globals, listener array, event dispatch, registration on g_selection_obj |
| `include/actionmodern/action.h` | No changes needed (Selection methods are internal, called via native function dispatch) |

### Recompiler (SWFRecomp/)

No changes needed. Selection methods are called via generic `actionCallMethod` → `actionGetVariable("Selection")` → method dispatch. The recompiler already handles this correctly.

### No new files needed

Everything fits in `action.c` alongside the existing Selection stub. The implementation is ~200-300 lines of C.

---

## Estimated Impact

### Direct test gains

| Test | Expected Lines | Estimated Pass Rate | Notes |
|------|---------------|-------------------|-------|
| `selection` | 456 | ~85-90% after Phase 1, ~95% after Phase 2 | selection 454/454 PASS ✅. Mouse simulation now fully implemented. |
| `selection_handlers` | 27 | **27/27 PASS** ✅ | Fixed (commit 19e968ed): setFocus re-focus roll events + eager g_tab_hovered_mc tracking |

### Indirect test improvements

Focus management is a prerequisite for many other tests:
- `edittext_focus_selection` (2 lines) — needs Selection + replaceSel
- `edittext_programmatic_focus` (12 lines) — needs Selection.setFocus
- `focus_*` tests (5+ tests) — need both Selection and synthetic keyboard/mouse events
- Future tab ordering tests (14 tests) — need focus system as foundation

### Implementation effort

- **Phase 1**: ~250 lines of C in action.c. Moderate complexity — the focus tracking is simple, event dispatch follows existing patterns, text selection state is just 3 integers per text field.
- **Phase 2**: ~50 lines of C. Simple string manipulation for replaceSel.

---

## Design Decisions

1. **Focus target type**: Store focused object as `MovieClip*` since all focusable objects in the runtime (movie clips, buttons, text fields) are represented as MovieClip structs. Buttons and text fields are movie clips with special char_type or ng_textfield_idx.

2. **Listener storage**: Simple dynamic array (`ASObject**`), not a linked list. The listener count will be small (typically 1-3). Use the same pattern as if we were implementing AsBroadcaster (which we'll need later for Mouse/Key listeners anyway).

3. **Text selection storage**: Store on the MovieClip struct directly (3 `s32` fields: `selection_begin`, `selection_caret`, `selection_end`), NOT on dynamic_props. This avoids type conversion overhead and keeps the hot path fast. Initialize to -1.

4. **No AsBroadcaster dependency**: The `selection_handlers` test uses `Selection.addListener()` which follows the AsBroadcaster pattern, but we implement it directly on Selection rather than requiring a general AsBroadcaster.initialize() implementation first. This keeps the scope focused.

5. **setFocus target resolution**: The test passes both object references (movie clips accessed by name) and string paths. We need to handle both:
   - Object reference (MovieClip/MOVIECLIP type) → use directly
   - String → resolve via path lookup (like actionSetTarget)
   - null/undefined → clear focus
   - false (boolean) → return false, no change
   - Other types → return false

6. **replaceSel before TextField prototype**: Implement replaceSel as a special-case method lookup in actionCallMethod (when the target is a text field MovieClip and the method name is "replaceSel"). This gets the test passing without requiring the full TextField prototype infrastructure from TEXTFIELD_PLAN.md Phase 1.

---

## Quick Reference: Expected Behavior Summary

```
setFocus(false)         → false (no change)
setFocus(null)          → true  (clear focus, fire events)
setFocus(undefined)     → true  (clear focus, fire events)
setFocus(validMC)       → true  (set focus, fire events if changed)
setFocus(nonExistent)   → false (no change)
setFocus(sameFocused)   → true  (no events fired)

getFocus()              → "_level0.name" or null

getBeginIndex()         → -1 (non-text) or 0..N (text with selection)
getCaretIndex()         → -1 (non-text) or 0..N (text with selection)
getEndIndex()           → -1 (non-text) or 0..N (text with selection)

setSelection()          → undefined (0 args: no change)
setSelection(n)         → undefined (1 arg: begin=n, end=textLen)
setSelection(a, b)      → undefined (2 args: clamp, normalize)

addListener(obj)        → true
removeListener(obj)     → true/false

Event order: onKillFocus(new) → onSetFocus(old) → listener.onSetFocus(old, new)
```
