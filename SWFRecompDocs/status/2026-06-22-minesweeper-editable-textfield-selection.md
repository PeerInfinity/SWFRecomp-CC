# Minesweeper edit box — text selection (highlight + Shift-select + replace)

**Date:** 2026-06-22 (follow-up to horizontal scrolling)
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Bucket:** needs-browser + OFFSCREEN no-regression.

User report: mouse-drag selection worked at the data level (drag then Delete
removes the range) but the selected area wasn't drawn, and Shift+keys didn't
select. Three pieces:

## 1. Selection highlight rendering
The selection range (`g_selection_begin/end`, or `[0, len]` for a select-all) is
passed to the glyph renderer via new `sel_begin`/`sel_end` fields on
`TextFieldGlyphInfo` (set in `actionIterateTextFieldGlyphs` only when
`mc == g_focused_mc`). Before the glyph pass, `textfield_glyph_render_cb` (tag.c)
walks the text to find the pixel x of `sel_lo`/`sel_hi` (single-line) and draws a
light-blue box behind the glyphs (text draws on top). Browser-WASM gated, same as
the caret — nothing is selected in headless/OFFSCREEN, so CI render is unchanged.
The highlight reads the selection state with **no branch on how it was created**,
so mouse-drag and Shift-select share the identical render path.

## 2. Shift-select (extend instead of collapse)
The move handlers (`actionTextControlMoveLeft`/`Right`/`MoveHome`/`MoveEnd`) now
read Shift (`app_context->keys.down[16]`, set by the browser keydown). New helpers
`tf_active_caret` (caret = active selection end; select-all → end), `tf_selection_anchor`
(the fixed end), and `tf_set_caret(new_caret, len, shift)` (extend from anchor when
shift, else collapse). Non-shift over a selection still collapses to the edge.

## 3. Typing replaces an active selection
`actionTextFieldInput` now computes the replaced range `[del_lo, del_hi]` from the
selection (non-empty selection → replace it; else a zero-width range at the caret),
builds `old[0..del_lo] + ch + old[del_hi..]`, and advances the caret to
`del_lo + ch_len`. Previously it inserted at the caret without removing the
selection.

## Build note
`actionIterateTextFieldGlyphs` (early in action.c) now references `g_selection_begin`,
`g_selection_end`, and `g_tf_select_all`, which are defined later in the Selection
block. Added forward tentative declarations next to the existing `g_selection_caret`
one (the established pattern, like `g_focused_mc`).

## Verification (headed Chrome, real key/mouse events)
`minesweeper_selection_probe.py` (new): clear → type "hello" → Shift+Left×3
highlights **"llo"** (blue box, verified); type "Z" → **"heZmous"**, highlight
cleared (replace verified). Mouse-drag highlight shares the exact render+state path
as the verified Shift-select highlight and the user already confirmed drag sets a
selection (Delete works) — the Playwright synthetic mouse-drag didn't reliably
drive the runtime's per-frame drag path to screenshot it, so confirm the drag
visual in-browser. OFFSCREEN divergence image **identical**, first divergence
unchanged.

## Edit box status
Caret, arrows, Home/End, typing, Backspace, Delete, horizontal scrolling, and now
selection (highlight + Shift-select + replace) all work.

## Files
- `SWFModernRuntime/include/actionmodern/action.h` — `sel_begin`/`sel_end` fields.
- `SWFModernRuntime/src/actionmodern/action.c` — selection range to the iterator;
  forward decls; Shift-aware move handlers + helpers; typing-replaces-selection.
- `SWFModernRuntime/src/libswf/tag.c` — selection-highlight draw (browser-gated).
- `tools/divergence/game_drive/minesweeper_selection_probe.py` — new selection probe.
