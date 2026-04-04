# Pixel-Level Text Layout Plan
<!-- TESTS: edittext_drag_select, asfunction, edittext_ime_focus_lost -->

<!-- PLAN_META
id: PIXEL_TEXT_LAYOUT
status: complete
phases:
  - id: 0
    name: "Character layout engine (prerequisite)"
    status: complete
  - id: 1
    name: "asfunction handler"
    status: complete
  - id: 2
    name: "Drag selection"
    status: complete
  - id: 3
    name: "IME composition"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-04-03

## Status: COMPLETE — All 4 phases done, all 3 tests PASS

- **edittext_drag_select** — PASS (9/9). Character layout engine + mouse drag selection.
- **asfunction** — PASS (11/11). Hyperlink hit testing + asfunction: protocol handler.
- **edittext_ime_focus_lost** — PASS (7/7). IME preedit event injection + composition state.

---

## Completed: Phase 0 — Character Layout Engine

`ng_getCharIndexAtPoint()` in `tag_stubs.c:1696-1809` maps pixel (x,y) to a UTF-16
character index. Accounts for line breaks, fonts, glyph advances, margins, gutters.

## Completed: Phase 1 — asfunction Handler (asfunction PASS)

Implemented in action.c:

- `tf_find_run_at_index()` — finds TFRun by character index
- `handle_asfunction()` — parses asfunction: URL, resolves dotted function paths,
  calls with correct `this` (container MC for local methods, _global for global functions)
- `call_function_with_this()` — generic function caller supporting both MC and ASObject `this`
- `actionTextFieldDragEnd()` — extended to check for hyperlinks on mouse-up via two paths:
  1. Focused text field click (existing drag infrastructure)
  2. Non-focused text field scan (hit-tests all cached text field MCs)

**Bonus fix:** Added nested sprite text field initialization in `findOrCreateMovieClip()`
via `findDisplayEntryInParent()` and `ng_getTextFieldIdxByCharId()` — text fields inside
sprites now get proper property initialization (html, text, multiline, etc.).

## Completed: Phase 2 — Drag Selection (edittext_drag_select PASS)

Mouse down/move/up handlers in `action.c`:
- `actionTextFieldMouseDown()` — hit-tests text field bounds, calls `ng_getCharIndexAtPoint`,
  sets `g_selection_begin/end/caret`, starts drag tracking
- `tf_char_index_at_mouse()` — reusable helper for pixel→char mapping
- `actionTextFieldDragSelect()` — updates selection during mouse move
- `actionTextFieldDragEnd()` — finalizes selection on mouse up

## Completed: Phase 3 — IME Composition (edittext_ime_focus_lost PASS)

Three-layer implementation:

1. **verify_output.py**: Added ImePreedit/ImeCommit event parsing into `IME_PREEDIT`/`IME_COMMIT`
   line format for the event file.

2. **swf_core.c**: Added `EV_IME_PREEDIT`/`EV_IME_COMMIT` event types, parsing, and dispatch
   to `actionTextFieldImeCompose()`/`actionTextFieldImeCommit()`.

3. **action.c**: IME composition state (`g_ime_data`) with start/replace/finalize lifecycle.
   `actionTextFieldImeCompose()` inserts/replaces composition text in the focused text field
   and updates selection. `actionTextFieldImeCommit()` finalizes via character-by-character
   insertion.

**Bonus fix:** Added deferred `onChanged` callback from `replaceSel()` — fires after the
calling script frame returns (via `g_pending_onchanged_mc`), matching Flash's async behavior.

---

## Summary

| Phase | Feature | Test | Status |
|-------|---------|------|--------|
| 0 | Character layout engine | (prerequisite) | **COMPLETE** |
| 1 | asfunction handler | asfunction (11/11) | **COMPLETE** |
| 2 | Drag selection | edittext_drag_select (9/9) | **COMPLETE** |
| 3 | IME composition | edittext_ime_focus_lost (7/7) | **COMPLETE** |
