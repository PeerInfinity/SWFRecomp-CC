# Minesweeper edit box — horizontal scrolling

**Date:** 2026-06-22 (follow-up to real-typing + Delete)
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Bucket:** needs-browser (verified headed Chrome) + OFFSCREEN no-regression.

The last edit-box gap: a single-line field didn't scroll, so typing/End past the
field's right edge left the caret and new text off-screen (the leading text
stayed put). Now the view follows the caret.

## Design
A per-field horizontal scroll offset (twips) is cached on the field's dynamic
props as `_tf_scroll_x`. The glyph renderer (`textfield_glyph_render_cb`, tag.c)
adjusts it each frame to keep the caret inside the field and shifts the whole
layout left by it; the field's existing clip mask hides the scrolled-out glyphs.
Click hit-testing adds the offset back so clicks map to the right character.

- **Renderer:** before the draw pass, for a focused single-line field, compute
  the caret's pixel offset (sum of glyph advances up to the caret), then move the
  scroll minimally so `caret_off` stays in `[0, visible_width]` (scroll only when
  the caret would leave the view; never negative). Persist via
  `ng_set_textfield_scroll_x` only when it changes, then `base_x -= scroll`. The
  in-loop caret-bar tracking shifts automatically with `base_x`.
- **Storage:** `ng_get_textfield_scroll_x` / `ng_set_textfield_scroll_x` (action.c)
  read/write `_tf_scroll_x`. New `void* mc` field on `TextFieldGlyphInfo` lets the
  renderer reach the MC (NULL for orphan/static fields).
- **Hit-testing:** the three `ng_getCharIndexAtPoint` call sites (click-to-caret,
  drag-select, href link) add `scroll/20` px to `local_x`.

**Browser-WASM only / CI-safe:** the whole scroll block in the renderer is gated
`#if !NO_GRAPHICS && !OFFSCREEN_RENDER && !HEADLESS_GRAPHICS`, and it only runs
when a field is focused (`caret_char >= 0`, never in headless). `_tf_scroll_x` is
therefore never written in CI, so the getter returns 0 everywhere in CI → the
hit-test offset is 0 and the layout is unshifted → CI render byte-identical.
Multiline fields are left unscrolled (offset reset to 0).

## Verification (headed Chrome, real key events)
`minesweeper_hscroll_probe.py` (new): clear → type a long string → view shows the
**end** of the text with the caret at the right edge (scrolled, not frozen at the
start); **Home** → view jumps to the **start**, caret at the left; **End** → back
to the end. OFFSCREEN divergence image **identical**, first divergence unchanged
(pre-existing `fLabel_mc` font-metrics diff).

## Edit box status
Caret, arrows, Home/End, real typing, Backspace, Delete, and now horizontal
scrolling all work. **Remaining (next milestone, per user): text selection** —
neither Shift+keys nor mouse-drag currently highlights (selection state is
tracked but never rendered, and Shift doesn't extend it).

## Files
- `SWFModernRuntime/src/actionmodern/action.c` — `ng_get/set_textfield_scroll_x`;
  `info.mc`; scroll added to the 3 hit-test `local_x` computations.
- `SWFModernRuntime/include/actionmodern/action.h` — helper decls; `mc` field.
- `SWFModernRuntime/src/libswf/tag.c` — horizontal-scroll pre-pass (browser-gated).
- `tools/divergence/game_drive/minesweeper_hscroll_probe.py` — new long-text scroll probe.
