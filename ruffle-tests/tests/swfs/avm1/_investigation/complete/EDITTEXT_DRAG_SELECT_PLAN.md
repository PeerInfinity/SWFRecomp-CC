# EditText Drag Selection Plan
<!-- TESTS: edittext_drag_select -->

Last updated: 2026-03-28

## Status: NOT STARTED

### Problem

The `edittext_drag_select` test (6/9 lines passing) simulates three mouse drag operations on a text field and checks that `replaceSel("<selection>")` replaces the correct text ranges. Currently, mouse clicks on text fields acquire focus but do NOT position the caret or set a selection range. All selection indices remain at 0, so `replaceSel` inserts at position 0 without replacing any text.

### Test Mechanics

The test has a text field named `text` containing lorem ipsum (~100 chars, multiline). An `onMouseUp` listener calls:
```actionscript
text.replaceSel("<selection>");
trace("Text: " + text.text);
```

Three drag operations select progressively different ranges. Each `replaceSel` replaces the selected text with the literal string `"<selection>"`, so the traced text shows where selections were made.

**Input events** (`input.json`):
1. Drag (234,166) → (511,189) — selects mid-line range
2. Drag (343,166) → (764,523) — selects from mid-line to end of text
3. Drag (207,163) → (7,13) — selects from mid-line backwards to start

### What Exists

| Component | Status |
|-----------|--------|
| `g_selection_begin/end/caret` globals | Implemented |
| `Selection.setSelection()` | Implemented |
| `replaceSel()` | Implemented (uses g_selection_begin/end) |
| Mouse click → text field focus | Implemented (`actionMouseClickFocus`) |
| Caret positioning on click | **NOT IMPLEMENTED** |
| Drag selection (mouse move while pressed) | **NOT IMPLEMENTED** |
| Pixel → character index conversion | **NOT IMPLEMENTED** |

### What's Needed

#### Gap 1: Character Index from Pixel Coordinates

The core missing function: given a mouse position in stage pixels, determine which character in the text field is at that position.

```c
int ng_getCharIndexAtPoint(int tf_idx, float local_x_px, float local_y_px);
```

This requires walking through characters, accumulating glyph advance widths, to find which character boundary the x coordinate falls between. For multiline text, also determine which line the y coordinate is on.

**Available infrastructure:**
- `ng_font_find_glyph(font_id, codepoint)` → glyph index
- `ng_font_glyph_advance_by_idx(font_id, glyph_idx)` → advance width (twips)
- `ng_getTextFieldFontId(tf_idx)`, `ng_getTextFieldFontHeight(tf_idx)` → font metrics
- `ng_getTextFieldLeftMargin()`, `ng_getTextFieldIndent()` → layout offsets
- `ng_getTextFieldLeading()` → line spacing
- Text field bounds via `ng_getTextFieldBounds()` or MC position

**Algorithm outline:**
1. Convert stage coordinates to text-field-local coordinates (subtract MC position)
2. Subtract gutter (2px = 40 twips internal Flash padding)
3. Determine line from y: `line = (local_y - gutter) / (font_height + leading)`
4. Walk to the start of that line in the text string (handle `\r`/`\n` line breaks + word wrap)
5. Walk characters on that line, accumulating advance widths, until `accumulated_x >= local_x`
6. Return character index (snap to nearest boundary)

**Complexity**: Medium. Word wrapping logic is the hardest part — need to replicate Flash's line-break algorithm.

#### Gap 2: Caret Positioning on Mouse Click

In `actionMouseClickFocus()`, after focus is acquired, set the caret position based on where the click landed:

```c
// After focus change to a text field:
int char_idx = ng_getCharIndexAtPoint(hit_mc->ng_textfield_idx, local_x, local_y);
g_selection_begin = char_idx;
g_selection_end = char_idx;
g_selection_caret = char_idx;
```

#### Gap 3: Drag Selection on Mouse Move

Track mouse-down state on focused text field. On subsequent mouse moves while button is held, extend the selection:

```c
void actionTextFieldMouseDrag(SWFAppContext* app_context) {
    if (g_focused_mc == NULL || !g_mouse_button_down) return;
    int tf_idx = g_focused_mc->ng_textfield_idx;
    if (tf_idx < 0) return;

    float local_x = mouse_x - tf_x;
    float local_y = mouse_y - tf_y;
    int drag_idx = ng_getCharIndexAtPoint(tf_idx, local_x, local_y);

    // anchor stays at mouse-down position, caret follows mouse
    g_selection_caret = drag_idx;
    g_selection_end = drag_idx;
    // (begin/end may need swapping if drag goes backwards)
}
```

This should be called from `swf_core.c`'s `EV_MOUSE_MOVE` handler when a text field is focused and the mouse button is down.

### Implementation Steps

#### Step 1: Character Index Lookup (~60 lines)

Add `ng_getCharIndexAtPoint()` to `tag_stubs.c`:
- Get text content, font ID, font height from text field metadata
- Walk text character by character, computing x position from glyph advances
- Handle line breaks (`\r`, `\n`) and multiline layout
- Return index at the x/y position

For this test, word wrapping may NOT be needed — the test uses a text field with pre-set text that may already contain explicit line breaks. Check by examining the SWF's DefineEditText tag.

#### Step 2: Caret on Click (~10 lines)

In `actionMouseClickFocus()`, after `selection_do_focus_change()`:
- Convert mouse stage coordinates to text-field-local
- Call `ng_getCharIndexAtPoint()`
- Set `g_selection_begin = g_selection_end = g_selection_caret = char_idx`

#### Step 3: Drag Selection (~25 lines)

Add mouse-down-on-textfield tracking:
- New globals: `g_tf_mouse_anchor` (char index at mouse down), `g_tf_drag_active`
- On mouse down on text field: set anchor, set `g_tf_drag_active = 1`
- On mouse move while `g_tf_drag_active`: compute char index, set selection begin=min(anchor, current), end=max(anchor, current)
- On mouse up: clear `g_tf_drag_active`

Hook into `swf_core.c`'s event dispatch (or the headless equivalent in `swf_headless.c`).

#### Step 4: Test & Verify

```bash
python3 ruffle-tests/verify_output.py --test=edittext_drag_select --diff --verbose
```

### Risks and Complications

1. **Word wrapping**: If the text field uses automatic word wrap, computing line breaks from pixel width requires knowing the text field width and the font's advance table. This is complex but may not be needed for this specific test.

2. **Font dependency**: The test uses `with_default_font = true`. The test note says "TODO Fix this test. It shouldn't depend on the default font." Character positions depend on the exact font metrics. If our device font glyph advances don't match Ruffle's default font, positions will be off.

3. **Multi-line y positioning**: Need to know the exact line height formula. Flash uses `font_height + leading` with a 2px gutter on each side.

4. **Coordinate systems**: The test mouse coordinates are in stage pixels. Need to correctly transform to text-field-local coordinates accounting for MC position and any parent transforms.

### Dependencies

- Font metrics infrastructure (exists: `ng_font_*` functions)
- Text field metadata (exists: `ng_getTextField*` functions)
- Selection system (exists: `g_selection_begin/end/caret`, `replaceSel`)
- Event dispatch (exists: `actionMouseClickFocus`, `swf_core.c` event loop)

### Estimated Complexity

Medium (~95 lines of C). The character index lookup is the bulk of the work. The rest is wiring — connecting mouse events to selection state updates.
