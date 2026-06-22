# Minesweeper title-screen edit box "does nothing" — editable text field render fix

**Date:** 2026-06-21
**Game:** flasharchive/Minesweeper, browser-WASM graphics (shared runtime code)
**Bucket:** needs-browser (verified in headed Chrome) + OFFSCREEN no-regression.

## Symptom
The "Enter your name" edit box on the Minesweeper title/difficulty screen
appeared to do nothing: clicking focused it (I-beam cursor) but typing never
changed what was drawn — the field showed the clipped default `anonymou…` no
matter what you typed.

## Root cause — stale `TFRunTable` shadows the live `text`
The data path was already correct: clicking focuses the field (`g_focused_mc`
= `instance6`, `ng_textfield_idx=8`) and `actionTextFieldInput` updates the
`text` property (`anonymous` → `anonymousBob`, confirmed with instrumentation).

The **render** path (`actionIterateTextFieldGlyphs`, action.c ~26264) prefers a
field's `TFRunTable` (`tf_find_table(mc)`) over the live `text` property when the
table has runs. The field's initial static text was loaded into a run table at
init, and the editable-mutation paths write `text` directly via `setProperty()`,
**bypassing the SetMember `"text"` handler** (action.c ~47939) that normally
invalidates the stale table. So the glyph renderer kept drawing the table's
original `anonymous` forever.

The 2026-06-17 "interactivity DONE" verdict ("text field works at the data
level") was right about the data and never caught this because the only test
appended to the END of the string, which is clipped off the right edge of the
narrow single-line field — the visible leading text is identical whether or not
the render updates. The definitive test deletes the default value first
(Backspace), then types: the field now correctly renders `mousZZZ`.

## Fix
New helper `tf_invalidate_run_table(MovieClip*)` (action.c, next to
`tf_find_table`) drops the MC's run table so the renderer falls back to the live
`text`. Called from every editable-mutation path that writes `text` via
`setProperty()`:
- `actionTextFieldInput` (keyboard typing; also covers `actionTextControlEnter`
  and IME commit, which route through it)
- `actionTextControlBackspace` (both the select-all clear and the char/range delete)
- `actionTextControlCut`
- IME compose (`actionTextFieldImeCompose`)
- `TextField.replaceSel`/`replaceText` (action.c ~67415)

The fallback render path (action.c ~26320) reads `text` and synthesizes a single
run carrying the DefineEditText alignment, so plain editable fields render
correctly. Per-run TextFormat formatting is not preserved across an edit (the
fallback paints one color/font) — acceptable: the prior behavior rendered the
WRONG TEXT entirely, and editable fields are typically uniformly formatted.

## Verification
- Headed Chrome (`tools/divergence/game_drive/minesweeper_text_clear_probe.py`,
  new): focus → Backspace×16 → type `ZZZ` → field renders `mousZZZ` matching the
  data. (`minesweeper_text_probe.py` append-only was inconclusive by design.)
- OFFSCREEN divergence (`divergence_test.py Minesweeper --frames 8 --skip-ruffle`):
  first divergence unchanged (the pre-existing `fLabel_mc _y=-4.3 vs -5`
  font-metrics diff, PROGRESS sub-bug d); image identical; rc=0. No new divergence.

## CI
Shared `action.c` (NO_GRAPHICS + OFFSCREEN + browser-WASM all compile the run
table) → dispatched both modes per CLAUDE.md. The `replaceSel` path is
script-reachable, so the run table can change `textWidth`/render output in the
test suite — CI is the regression net.

## Files
- `SWFModernRuntime/src/actionmodern/action.c` — `tf_invalidate_run_table` +
  6 call sites in the editable-mutation paths.
- `tools/divergence/game_drive/minesweeper_text_clear_probe.py` — new regression
  probe (clears the field, then types, so the visible portion changes).
