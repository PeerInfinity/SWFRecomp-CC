# Minesweeper edit box — caret, insert-at-caret, Home/End (follow-up)

**Date:** 2026-06-21 (follow-up to the stale-TFRunTable render fix `b5e9f3e9c`)
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Bucket:** needs-browser (verified in headed Chrome) + OFFSCREEN no-regression.

After the run-table fix, the edit box could delete text and re-render, but the
user reported three remaining gaps: no visible caret, typed characters didn't
appear, and the End key didn't jump to the end (Right-arrow + click already
worked). These were three independent bugs.

## 1. Typed text appended to the end instead of inserting at the caret
`actionTextFieldInput` built `result = existing_text + new_char`, ignoring
`g_selection_caret`, and never advanced the caret. So click-in-the-middle +
type put the character at the end (usually off the clipped right edge → looked
like "nothing happened"). Rewrote the build to work in UTF-16 and splice the
char at the caret (`old[0..caret] + ch + old[caret..]`), honoring select-all
replace + maxChars, then advance `g_selection_*` past the insert.

## 2. No caret rendered
The graphics glyph path (`textfield_glyph_render_cb`, tag.c) drew no caret. Added
`int caret_char` to `TextFieldGlyphInfo`; `actionIterateTextFieldGlyphs` sets it
to `g_selection_caret` only when `mc == g_focused_mc` (else -1). The render
callback tracks the pen x at the caret's character index during the existing
draw walk and draws a thin (~1px) vertical bar in the text color spanning the
line's em height, inside the field clip mask.

**Gated to browser-WASM only** (`#if !NO_GRAPHICS && !OFFSCREEN_RENDER &&
!HEADLESS_GRAPHICS`): the caret is interactive, and an avm1 graphics test that
calls `Selection.setFocus` would otherwise render a caret into the CI capture
and diverge from Ruffle's baseline. OFFSCREEN divergence image stayed identical,
confirming the gate.

## 3. Home / End keys did nothing
Only Left(37)/Right(39) were wired. Added `actionTextControlMoveHome` /
`MoveEnd` (line-aware: scan to the \r/\n boundary, = whole text for single-line)
and wired keycodes End(35)/Home(36) in `swf.c` (browser main loop) plus the
`MoveHome`/`MoveEnd` string `TEXT_CONTROL` events in the three headless input
parsers (`swf_core.c`, `input_events.c`, `swf_headless.c`) for parity.

## Verification (headed Chrome)
- `minesweeper_text_clear_probe.py` (clear → type "ZZZ" at caret 0): field renders
  **"ZZZmous"** with the caret bar after "ZZZ" — insert-at-caret + caret + caret
  advance all confirmed.
- `minesweeper_caret_probe.py` (new): clear → **End** moves the caret bar to after
  "mous"; **Home** moves it back before "m". Confirms Home/End + caret render.
- OFFSCREEN divergence (`--frames 8 --skip-ruffle`): image **identical**, first
  divergence unchanged (pre-existing `fLabel_mc` font-metrics diff). Caret correctly
  absent in CI render.

## Known remaining limitation
**No horizontal scroll.** A single-line field doesn't scroll to keep the caret
visible, so typing/End past the field's right edge leaves the caret + new text
off-screen (the leading text stays put). Minesweeper's name field is short enough
that this rarely bites. Implementing hscroll = store a per-field scroll offset,
update it to keep the caret in view, apply it to `base_x` in the renderer AND to
the click hit-test mapping. Deferred.

## Files
- `SWFModernRuntime/src/actionmodern/action.c` — insert-at-caret rewrite;
  `actionTextControlMoveHome`/`MoveEnd`; `caret_char` set in the glyph iterator;
  forward decl of `g_selection_caret`.
- `SWFModernRuntime/include/actionmodern/action.h` — `caret_char` field;
  MoveHome/MoveEnd decls.
- `SWFModernRuntime/src/libswf/tag.c` — caret tracking + draw (browser-WASM gated).
- `SWFModernRuntime/src/libswf/swf.c` — End/Home keycodes.
- `SWFModernRuntime/src/libswf/{swf_core.c,input_events.c,swf_headless.c}` —
  MoveHome/MoveEnd TEXT_CONTROL parity.
- `tools/divergence/game_drive/minesweeper_caret_probe.py` — new caret/Home/End probe.
