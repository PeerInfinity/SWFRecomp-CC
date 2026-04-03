# Pixel-Level Text Layout Plan
<!-- TESTS: edittext_drag_select, asfunction, edittext_ime_focus_lost -->

<!-- PLAN_META
id: PIXEL_TEXT_LAYOUT
status: in_progress
phases:
  - id: 0
    name: "Character layout engine (prerequisite)"
    status: complete
  - id: 1
    name: "asfunction handler"
    status: not_started
  - id: 2
    name: "Drag selection"
    status: complete
  - id: 3
    name: "IME composition"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-04-03

## Status: IN PROGRESS — Phases 0 and 2 COMPLETE, Phases 1 and 3 UNBLOCKED

- **edittext_drag_select** — PASS (9/9). Character layout engine + mouse drag selection.
- **asfunction** — 0/11. Needs hyperlink hit testing + asfunction: protocol handler. **Unblocked.**
- **edittext_ime_focus_lost** — 0/7. Needs IME event injection + composition state. **Unblocked.**

---

## Completed: Phase 0 — Character Layout Engine

`ng_getCharIndexAtPoint()` in `tag_stubs.c:1696-1809` maps pixel (x,y) to a UTF-16
character index. Accounts for line breaks, fonts, glyph advances, margins, gutters.

## Completed: Phase 2 — Drag Selection (edittext_drag_select PASS)

Mouse down/move/up handlers in `action.c:54077-54247`:
- `actionTextFieldMouseDown()` — hit-tests text field bounds, calls `ng_getCharIndexAtPoint`,
  sets `g_selection_begin/end/caret`, starts drag tracking
- `tf_char_index_at_mouse()` — reusable helper for pixel→char mapping
- `actionTextFieldDragSelect()` — updates selection during mouse move
- `actionTextFieldDragEnd()` — finalizes selection on mouse up

---

## Phase 1: asfunction Handler (UNBLOCKED — ~260 lines)

### What the Test Does

Creates a text field with HTML `<a href="asfunction:...">` links and simulates
mouse clicks at specific pixel coordinates. Each click should trigger the
corresponding asfunction call.

**Input events** (`input.json`): 4 mouse clicks (down+up pairs) at:
- (134, 69) → `asfunction:alert1` → calls `alert1(undefined)`, `this == _global`
- (166, 95) → `asfunction:callback, Second Test` → calls `callback(" Second Test")`, `this == container`
- (143, 128) → `asfunction:` → empty function name, does nothing
- (142, 160) → `asfunction:text1.callback,a,b,c,d` → calls `text1.callback("a,b,c,d")`, `this == container.text1`

**Expected output** (11 lines):
```
alert1 called with input: undefined
// this == _global
true

container.callback with input:  Second Test
// this == container
true

text1.callback with input: a,b,c,d
// this == container.text1
true
```

### Existing Infrastructure (all from drag selection)

| Component | Status | Location |
|-----------|--------|----------|
| `ng_getCharIndexAtPoint(x, y)` | Complete | `tag_stubs.c:1696-1809` |
| Mouse click → char index on text fields | Complete | `action.c:54077-54184` |
| `TFRun.href[256]` stores `<a href>` URL | Complete | `action.c:15469-15477` |
| `TFRunTable` with per-field format runs | Complete | `action.c:15480-15489` |
| `tf_get_table()` / `tf_find_table()` | Complete | `action.c:16800-16850` |
| Path resolution (`actionGetVariable`, `resolveFlashPathToMC`) | Complete | `action.c:27898+` |
| Function calling (`actionCallFunction`) | Complete | `action.c:42257+` |

### Implementation Plan

#### Step 1: Find TFRun by Character Index (~30 lines)

```c
// Returns the TFRun whose character range covers char_idx, or NULL
static TFRun* tf_find_run_at_index(TFRunTable* table, u32 char_idx) {
    for (u32 i = 0; i < table->run_count; i++) {
        TFRun* run = &table->runs[i];
        if (char_idx >= run->start && char_idx < run->start + run->length)
            return run;
    }
    return NULL;
}
```

#### Step 2: Parse asfunction: URL (~40 lines)

```c
// Parse "asfunction:functionName,arg" into function name and argument string
// Returns 1 if asfunction: prefix found, 0 otherwise
static int parse_asfunction(const char* href, char* func_out, size_t func_sz,
                            char* arg_out, size_t arg_sz) {
    if (strncmp(href, "asfunction:", 11) != 0) return 0;
    const char* rest = href + 11;
    const char* comma = strchr(rest, ',');
    if (comma) {
        size_t name_len = (size_t)(comma - rest);
        strncpy(func_out, rest, min(name_len, func_sz - 1));
        func_out[min(name_len, func_sz - 1)] = '\0';
        strncpy(arg_out, comma + 1, arg_sz - 1);
        arg_out[arg_sz - 1] = '\0';
    } else {
        strncpy(func_out, rest, func_sz - 1);
        func_out[func_sz - 1] = '\0';
        arg_out[0] = '\0';
    }
    return 1;
}
```

#### Step 3: Resolve Function Path and Call (~110 lines)

Parse dotted paths like `"text1.callback"`:
- Split on last `.` → target path = `"text1"`, method = `"callback"`
- Simple name like `"alert1"` → target = `_global`, method = `"alert1"`
- Resolve target via `actionGetVariable` or `resolveFlashPathToMC` + `getProperty`
- Call function with: `this` = resolved target object, 1 string arg (or undefined if no comma)

#### Step 4: Hook into Mouse-Up Handler (~40 lines)

In `actionTextFieldDragEnd()` (action.c:54243-54247), add a check: if the mouse
up position equals the mouse down position (click, not drag), check for href:

```c
void actionTextFieldDragEnd(SWFAppContext* app_context) {
    // ... existing drag end logic ...

    // If no actual drag occurred (click), check for hyperlink
    if (g_selection_begin == g_selection_end) {
        u32 char_idx = g_selection_caret;
        MovieClip* focused = get_focused_textfield_mc();
        TFRunTable* table = tf_find_table(focused);
        if (table) {
            TFRun* run = tf_find_run_at_index(table, char_idx);
            if (run && run->href[0] != '\0') {
                handle_asfunction_or_url(app_context, run->href, focused);
            }
        }
    }
}
```

#### Step 5: Test

```bash
python3 ruffle-tests/verify_output.py --test=asfunction --diff --verbose
```

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Mouse-up handler (hook point) | `action.c` | 54243-54247 (`actionTextFieldDragEnd`) |
| TFRun struct (href field) | `action.c` | 15469-15477 |
| TFRunTable management | `action.c` | 16798-16850 |
| HTML `<a>` parsing → href | `action.c` | 17003+ (`tf_parse_html`) |
| Path resolution | `action.c` | 27898+ (`actionGetVariable`) |
| Function calling | `action.c` | 42257+ (`actionCallFunction`) |
| ng_getCharIndexAtPoint | `tag_stubs.c` | 1696-1809 |
| Test input events | `ruffle-tests/tests/swfs/avm1/asfunction/input.json` | |

---

## Phase 3: IME Composition (UNBLOCKED — ~290 lines)

IME does NOT need the character layout engine. It works at the text content level
(insert/replace text at cursor position).

### What the Test Does

Focuses a text input field, injects IME preedit events via `input.json`:

```json
[
  { "type": "ImePreedit", "text": "", "cursor": null },
  { "type": "ImePreedit", "text": "q", "cursor": [1, 1] },
  { "type": "Wait" }, { "type": "Wait" }, { "type": "Wait" },
  { "type": "Wait" }, { "type": "Wait" },
  { "type": "ImePreedit", "text": "", "cursor": null }
]
```

**Expected output** (7 lines):
```
Before: q
  1
  q|
Changed: q|
After: q|
  2
  |q|
```

**Current output** (0/7 match): The IME preedit "q" is never applied because
`verify_output.py` explicitly skips ImePreedit/ImeCommit events (line ~366).

### Implementation Plan

#### Step 1: verify_output.py — Parse IME Events (~30 lines)

In `convert_input_to_events()`, add handling for ImePreedit and ImeCommit:

```python
elif t == "ImePreedit":
    text = evt.get("text", "")
    cursor = evt.get("cursor")
    cursor_from = cursor[0] if cursor else -1
    cursor_to = cursor[1] if cursor else -1
    # Escape text for line-based format
    encoded = text.encode('unicode_escape').decode('ascii') if text else ""
    lines.append(f"IME_PREEDIT {encoded} {cursor_from} {cursor_to}")
elif t == "ImeCommit":
    text = evt.get("text", "")
    encoded = text.encode('unicode_escape').decode('ascii') if text else ""
    lines.append(f"IME_COMMIT {encoded}")
```

#### Step 2: swf_core.c — Event Framework (~80 lines)

Add IME event types and handling:

1. Add `EV_IME_PREEDIT` and `EV_IME_COMMIT` to `InputEventType` enum
2. Add `char ime_text[256]` and `int ime_cursor_from/to` to `InputEvent` struct
3. Add parsing in `input_events_load()` for `IME_PREEDIT` and `IME_COMMIT` lines
4. Add dispatch cases in the event switch:
   ```c
   case EV_IME_PREEDIT:
       actionTextFieldImeCompose(app_context, ev->ime_text,
                                  ev->ime_cursor_from, ev->ime_cursor_to);
       break;
   case EV_IME_COMMIT:
       actionTextFieldImeCommit(app_context, ev->ime_text);
       break;
   ```

#### Step 3: action.c — IME Composition State (~150 lines)

Add global IME state:
```c
static struct {
    u32 ime_start;    // Character position where composition started
    u32 ime_end;      // Current end of composition range
    u8 active;        // 1 if composition in progress
} g_ime_data = {0};
```

Implement `actionTextFieldImeCompose(ctx, text, cursor_from, cursor_to)`:
- If `text` is empty: finalize — clear `g_ime_data.active`, composition text becomes permanent
- If `text` is non-empty and `!g_ime_data.active`: start new composition at current caret position, set `ime_start = caret`, insert text, set `ime_end = ime_start + len`
- If `text` is non-empty and `g_ime_data.active`: replace text in `[ime_start, ime_end)` with new text, update `ime_end`
- Update `text` and `length` properties on the focused text field
- Fire `onChanged` event

Implement `actionTextFieldImeCommit(ctx, text)`:
- Clear `g_ime_data.active`
- If text provided, insert at caret (like `actionTextFieldInput`)

#### Step 4: Focus Loss Commits IME (~30 lines)

In the `EV_FOCUS_LOST` handler, check `g_ime_data.active` and commit if so.

#### Step 5: Test

```bash
python3 ruffle-tests/verify_output.py --test=edittext_ime_focus_lost --diff --verbose
```

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| IME event skip (remove this) | `verify_output.py` | ~366 |
| Event enum | `swf_core.c` | 240-252 |
| Event struct | `swf_core.c` | 254-260 |
| Event parsing | `swf_core.c` | 267-330 |
| TEXT_INPUT handler (template) | `swf_core.c` | 554-562 |
| actionTextFieldInput (template) | `action.c` | 54816+ |
| Focus loss handler | `swf_core.c` | 584-589 |
| Ruffle IME reference | `~/CC/ruffle/core/src/display_object/edit_text.rs` | 1840-1907 |

---

## Summary

| Phase | Feature | Test | Status | Lines | Priority |
|-------|---------|------|--------|-------|----------|
| 0 | Character layout engine | (prerequisite) | **COMPLETE** | — | — |
| 1 | asfunction handler | asfunction (11 lines) | **UNBLOCKED** | ~260 | High — filtered failure |
| 2 | Drag selection | edittext_drag_select (9 lines) | **COMPLETE** | — | — |
| 3 | IME composition | edittext_ime_focus_lost (7 lines) | **UNBLOCKED** | ~290 | Low — ignored test |

**Recommended order**: Phase 1 first (asfunction is a filtered failure, improves pass rate).
