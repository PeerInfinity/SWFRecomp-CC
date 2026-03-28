# Pixel-Level Text Layout Plan
<!-- TESTS: edittext_drag_select, asfunction, edittext_ime_focus_lost -->

Last updated: 2026-03-27

## Status: NOT STARTED — Blocked on character layout engine (shared prerequisite)

### Problem

Three tests require mapping pixel coordinates to character positions within text
fields. Text field *properties* are fully implemented (62+ tests pass), but there
is no code to compute where each character is rendered at a pixel level. This
"coordinate-to-character bridge" is the shared blocker for all three features.

### Affected Tests

| Test | Lines | Current | Feature Needed | Notes |
|------|-------|---------|----------------|-------|
| edittext_drag_select | 9 | 0/9 (0%) | Mouse drag → character selection | Mouse (x,y) → char index for selection range |
| asfunction | 11 | 0/11 (0%) | Hyperlink hit testing | Mouse (x,y) �� char index → which `<a href>` link |
| edittext_ime_focus_lost | 7 | 0/7 (0%) | IME composition | IME event injection + composition state tracking |

### Shared Prerequisite: Character Layout Engine

All three features depend on knowing the pixel bounding box of each character in
a text field. This requires a **character layout engine** that computes:

```
Input:  text content, font ID, font size, text field bounds, alignment,
        margins, indentation, leading, wordWrap, multiline
Output: array of { char_index, x, y, width, height } per character
```

#### What Exists

1. **Font metrics** (`tag_stubs.c:539-568`): `ng_record_font_metrics()` stores per-font:
   - Ascent, descent, leading, em_square
   - Per-glyph: code_table (Unicode → glyph index), advance_table (glyph width in EM units)
   - Built-in font (Noto Sans) with default glyph metrics
   - Max 500 fonts × 256 glyphs

2. **TFRun formatting** (`action.c:13926-13946`): `TFRunTable` stores per-text-field:
   - Array of `TFRun` entries, each covering a character range with font_name, font_height, bold, italic, letter_spacing, alignment, margins, indent, leading, href, etc.
   - Plain text buffer (up to 16384 chars)
   - Up to 512 format runs per field

3. **Text field properties** (`action.c`): Full property access for text, htmlText, textWidth, textHeight, autoSize, wordWrap, multiline, maxChars, restrict, scroll, maxscroll, etc.

4. **Selection tracking** (`action.c:22837-22839`): `g_selection_begin`, `g_selection_caret`, `g_selection_end` globals. `Selection.setSelection()`, `Selection.getBeginIndex()`, etc. all work.

5. **replaceSel()** (`action.c:46187-46278`): Fully implemented — uses selection indices to replace text range.

#### What's Missing

1. **Character position computation**: No code computes pixel x/y/width/height for each character from font metrics + text field layout parameters

2. **Line breaking**: No code computes where line breaks occur for wordWrap/multiline fields (the runtime handles `textHeight` approximation but doesn't track per-line character ranges)

3. **getCharIndexAtPoint(x, y)**: TextField method not implemented — would use the character layout to find which character contains a point

4. **getCharBoundaries(index)**: TextField method not implemented — would return Rectangle for a character

5. **Mouse-to-character mapping**: No integration between mouse click coordinates and character indices

---

## Feature 1: Character-Level Selection (edittext_drag_select)

### What the Test Does

Creates a text field with "Lorem ipsum dolor sit amet consectetur adipiscing etus."
and performs 3 mouse drag sequences. Each drag:
1. Mouse down at (x1, y1) — records start character index
2. Mouse move to (x2, y2) — extends selection
3. Mouse up — finalizes selection range
4. Calls `replaceSel("<selection>")` to replace selected text with literal marker

### Expected Output
```
Mouse down: 234,166
Mouse up: 511,189
Text: Lore<selection>etus.
Mouse down: 343,166
Mouse up: 764,523
Text: Lore<selection>etu<selection>
Mouse down: 207,163
Mouse up: 7,13
Text: <selection>ore<selection>etu<selection>
```

### What's Needed Beyond the Layout Engine

1. **Mouse drag → selection**: On mouseDown over a text field, compute start character index from (x,y). On mouseMove/mouseUp, compute end character index. Set `g_selection_begin`/`g_selection_end` accordingly.

2. **Integration with mouse dispatch**: Currently text fields are excluded from onPress/onRelease (`action.c:49115`). Need a parallel path that detects drag-selection on text fields.

3. **Test metadata**: `with_default_font = true` — uses system default font, not embedded. Layout engine needs a fallback font metrics path.

### Implementation Sketch

```c
// New function: map pixel to character index
int textFieldCharIndexAtPoint(MovieClip* mc, float px, float py) {
    TFRunTable* rt = getRunTableForMC(mc);
    if (!rt) return -1;
    // For each character, compute its bounding box using font metrics
    float cursor_x = left_margin + indent;
    float cursor_y = ascent;
    for (u32 i = 0; i < rt->text_len; i++) {
        float char_width = getGlyphAdvance(font_id, rt->text[i]) * font_size / em_square;
        if (px >= cursor_x && px < cursor_x + char_width &&
            py >= cursor_y - ascent && py < cursor_y + descent) {
            return (int)i;
        }
        cursor_x += char_width + letter_spacing;
        // Handle line breaks, word wrap...
    }
    return -1;
}
```

---

## Feature 2: TextField Hyperlink Hit Testing (asfunction)

### What the Test Does

Creates a text field with HTML content containing `<a href="asfunction:...">` links:
```html
<p>Click <a href='asfunction:alert1'>here</a> to call alert 1</p>
<p>Or click <a href='asfunction:callback, Second Test'>here</a> to call alert 2</p>
<p><a href='asfunction:'>this one doesn't do anything</a></p>
<p>But <a href='asfunction:text1.callback,a,b,c,d'>this one</a> has lots of args!</p>
```

Mouse clicks at specific coordinates should trigger the corresponding asfunction calls.

### Expected Output
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

### What's Needed Beyond the Layout Engine

1. **Link-to-character mapping** (already exists): `TFRun.href[256]` stores the href URL for each format run. The character range `[run.start, run.start + run.length)` covers the linked text. So once we have a character index, we can look up its TFRun and check `href`.

2. **asfunction: protocol handler**: Parse `asfunction:functionName,arg1,arg2,...`:
   ```c
   void handleAsFunction(SWFAppContext* ctx, const char* href) {
       if (strncmp(href, "asfunction:", 11) != 0) return;
       const char* rest = href + 11;
       // Split on first comma: functionName, args
       char func_name[256];
       char* comma = strchr(rest, ',');
       if (comma) {
           strncpy(func_name, rest, comma - rest);
           func_name[comma - rest] = '\0';
           const char* arg = comma + 1;
           // Call function with string arg
       } else {
           strcpy(func_name, rest);
           // Call function with undefined arg
       }
       // Resolve function name (may be dotted path like "text1.callback")
       // Call with correct this binding
   }
   ```

3. **Mouse click → link dispatch**: On mouse click over a text field:
   - Compute character index from (x,y)
   - Find TFRun containing that character
   - If `run.href` is non-empty, handle the URL
   - If `asfunction:` prefix, parse and call the function
   - Otherwise, navigate to URL (not needed for tests)

4. **this binding**: The asfunction `this` depends on the scope:
   - Global function: `this == _global`
   - Property of a MovieClip: `this == that MovieClip`
   - Nested path resolution: `container.text1.callback` → `this == container.text1`

### Complexity

Medium — once the character layout engine exists, the link hit testing is ~100 lines:
- Character index lookup (shared with Feature 1)
- TFRun href lookup (~20 lines)
- asfunction parser (~40 lines)
- Function call dispatch with correct this (~40 lines)

---

## Feature 3: IME Composition (edittext_ime_focus_lost)

### What the Test Does

Focuses a text input field, then injects IME preedit events:
1. `ImePreedit("")` — clear any composition
2. `ImePreedit("q", cursor=[1,1])` — compose "q" in IME mode
3. 5 frames of waiting
4. `ImePreedit("")` — finalize composition

Between composition events, the test traces `text.text` and `text.length` to verify the composition text appears in the field.

### Expected Output
```
Before: q
  1
  q|
Changed: q|
After: q|
  2
  |q|
```

### Current Output (0/7 match)
```
Before:
  0
  |
After: |
  1
  ||
```

The IME preedit "q" is never applied, so the field stays empty.

### What's Missing (Beyond the Layout Engine)

This feature has a different primary blocker than the other two: **IME event injection**.

1. **Event framework gap**: `verify_output.py` explicitly skips `ImePreedit` and `ImeCommit` events (line ~366: `# Skip ImePreedit, ImeCommit for now`). The events are never sent to the runtime.

2. **IME composition state**: Need an `ImeData` struct on text fields:
   ```c
   typedef struct {
       u32 ime_start;   // Start position of composition in text
       u32 ime_end;     // End position of composition
       char text[256];  // Current preedit text
       u8 active;       // 1 if composition is in progress
   } ImeData;
   ```

3. **IME event handler**: When `ImePreedit(text, cursor)` arrives:
   - If text is empty: finalize composition (`ime_start..ime_end` becomes permanent)
   - If text is non-empty: replace `ime_start..ime_end` with new text, update cursor

4. **Focus loss during composition**: When the text field loses focus while IME is active, the composition should be committed (finalized) automatically.

5. **System.IME API** (`action.c`): Currently stub-only. Would need:
   - `IME.enabled` / `IME.getEnabled()` / `IME.setEnabled()`
   - `IME.conversionMode` / `IME.getConversionMode()` / `IME.setConversionMode()`
   - `onIMEComposition` event callback

### Complexity

High — IME support requires changes across multiple layers:
- verify_output.py: Parse and inject IME events (~30 lines)
- Runtime: IME event delivery mechanism (~50 lines)
- Text field: ImeData state tracking + composition logic (~150 lines)
- Focus management: Commit on focus loss (~30 lines)
- System.IME API: Stub upgrades (~50 lines)

**Note**: Unlike the other two features, IME does NOT strictly require the character layout engine. IME composition works at the text content level (insert/replace text at cursor position), not at the pixel level. However, rendering the composition underline/highlight would need pixel-level layout.

---

## Implementation Priority

| Phase | Feature | Tests Unlocked | Depends On | Complexity |
|-------|---------|---------------|------------|------------|
| 0 | Character layout engine | (prerequisite) | Font metrics (exists) | High (~300 lines) |
| 1 | asfunction handler | asfunction (11 lines) | Phase 0 + asfunction parser | Medium (~150 lines) |
| 2 | Drag selection | edittext_drag_select (9 lines) | Phase 0 + mouse drag tracking | Medium (~150 lines) |
| 3 | IME composition | edittext_ime_focus_lost (7 lines) | Event framework changes | High (~300 lines) |

**Recommended order**: Phase 0 → Phase 1 → Phase 2 → Phase 3

- Phase 1 (asfunction) unlocks the most lines (11) and the asfunction protocol handler is useful beyond this test
- Phase 2 (drag select) reuses the same infrastructure as Phase 1
- Phase 3 (IME) is somewhat independent and can be deferred

### Total Estimated Scope

~900 lines of new C code + ~30 lines of Python (verify_output.py IME event injection).

### Dependencies

- Character layout engine depends on font metrics infrastructure (exists)
- createTextField rendering (CREATETEXTFIELD_RENDERING_PLAN.md Phase 3 — glyph rendering) would provide the same glyph position data and could share code
- None of these features block other tests

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Font metrics storage | `tag_stubs.c` | 539-568 |
| TFRun / TFRunTable | `action.c` | 13926-13946 |
| HTML `<a>` tag parsing → TFRun.href | `action.c` | 15866-15881 |
| Selection globals | `action.c` | 22837-22839 |
| Selection.setSelection() | `action.c` | 49664-49711 |
| replaceSel() | `action.c` | 46187-46278 |
| Mouse click focus | `action.c` | 50310-50346 |
| Text field exclusion from onPress | `action.c` | 49115 |
| IME event skip in test harness | `verify_output.py` | ~366 |
| Ruffle IME reference | `~/CC/ruffle/core/src/display_object/edit_text.rs` | 1840-1907 |
