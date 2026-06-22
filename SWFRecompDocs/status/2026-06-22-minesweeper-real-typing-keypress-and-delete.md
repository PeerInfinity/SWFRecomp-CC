# Minesweeper edit box — real typing (keydown preventDefault) + Delete key

**Date:** 2026-06-22 (follow-up to the caret / insert-at-caret / Home-End fix)
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Bucket:** needs-browser (verified in headed Chrome with REAL key events) +
OFFSCREEN no-regression.

After the caret work, the user reported: caret + arrows + Home/End + Backspace
all worked, but **typing produced no characters**, and **Delete (forward) didn't
delete**. Two bugs.

## 1. Real typing produced no characters — keydown preventDefault killed keypress
Text input flows through the browser `keypress` event → `on_keypress`
(render_webgpu.c) → `g_text_input_ring` → `actionTextFieldInput`. But
`on_key_down` **always returned `EM_TRUE`**, which makes emscripten call
`preventDefault()` on every keydown — and `preventDefault` on keydown **cancels
the browser's `keypress` event**. So no `keypress` ever fired for a real
keystroke, and no character was inserted.

This was invisible until now because every prior probe dispatched a **synthetic**
`keypress` event (`dispatchEvent(new KeyboardEvent('keypress', …))`), which
bypasses the keydown→keypress chain. A probe using only real key events
(`page.keyboard.type`, no synthetic dispatch) reproduced the user's bug exactly:
field stayed unchanged. (`minesweeper_realtype_probe.py`, new.)

**Fix (render_webgpu.c `on_key_down`):** when a text field is focused
(`ng_is_textfield_focused()`, new accessor in action.c), only `preventDefault`
the non-character navigation/editing keys (Backspace, Tab, arrows, Home/End,
PageUp/Down, Delete) — which never emit a `keypress` anyway and whose browser
defaults (scroll, back-nav, tab-out) we don't want — and return `EM_FALSE` for
printable keys (incl. space) so the browser still fires `keypress`. With no field
focused, behavior is unchanged (`EM_TRUE` for everything) so game canvases still
don't scroll the page on arrows/space. Browser-WASM only (render_webgpu.c isn't
compiled in OFFSCREEN/NO_GRAPHICS).

## 2. Delete (forward delete) did nothing
There was no forward-delete: only `actionTextControlBackspace`. Added
`actionTextControlDelete` (deletes the char AFTER the caret, or the selection;
caret stays put) and wired keycode 46 in `swf.c` + a `Delete` `TEXT_CONTROL`
event in the three headless parsers (swf_core.c / input_events.c / swf_headless.c).

## Verification (headed Chrome, real key events only)
`minesweeper_realtype_probe.py`: clear → Home → type "XY" → field renders
**"XYmous"** (real `keypress`, no synthetic dispatch); then Home → Delete ×2 →
**"mous"** (forward delete, caret stays at start). OFFSCREEN divergence image
**identical**, first divergence unchanged (pre-existing `fLabel_mc` font-metrics
diff) — no regression.

## Known remaining limitation
Still no horizontal scroll: typing/End past the field's right edge leaves the
caret + new text off-screen (deferred, as noted previously).

## Files
- `SWFModernRuntime/src/rendering/render_webgpu.c` — `on_key_down` lets keypress
  through for printable keys when a text field is focused.
- `SWFModernRuntime/src/actionmodern/action.c` — `ng_is_textfield_focused()`;
  `actionTextControlDelete`.
- `SWFModernRuntime/include/actionmodern/action.h` — both declarations.
- `SWFModernRuntime/src/libswf/swf.c` — Delete keycode 46.
- `SWFModernRuntime/src/libswf/{swf_core.c,input_events.c,swf_headless.c}` —
  `Delete` TEXT_CONTROL parity.
- `tools/divergence/game_drive/minesweeper_realtype_probe.py` — new real-key-event
  typing + Delete probe (no synthetic keypress).
