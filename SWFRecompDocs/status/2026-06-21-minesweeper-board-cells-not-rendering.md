# Minesweeper game board "uniform pink" — board cells now render

**Date:** 2026-06-21
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Bucket:** needs-browser (input-gated: the board only appears after clicking Start →
`gotoAndPlay(9)`; the divergence harness can't reach it).

## Symptom
After clicking **Start** on the difficulty screen, the game board rendered as a
**uniform pink rectangle** instead of the 30×16 grid of grey "Unknown" cell tiles
(Ruffle ground truth: full grey grid). All other game-screen chrome (Bombs Left,
Restart/Splash, smiley, Elapsed Time) rendered correctly. This was the deferred
"game-board grid cells don't render after Start" item from the 2026-06-17
interactivity work.

## How the board is built (decompiled `frame_10`)
A master clip named **`cell`** (char 104, timeline-placed at depth 26) is hidden
(`cell._visible = false`) and then cloned 480 times:
```
i in 0..29, j in 0..15:
    duplicateMovieClip(cell, "cell"+i+"_"+j, 16384+depth)
    setProperty(..., _X, 18+i*16); setProperty(..., _Y, 18+j*16)
    tellTarget(...) { gotoAndStop("Unknown"); play(); }
```
The clones are AVM1 dynamic clips (live in `child_mc_cache`, not the root
`display_list`). In browser-WASM they render via the post-loop root-attached pass
(`tag.c` → `render_attached_child`).

## Root causes (three, all confirmed with one-shot in-browser instrumentation)

1. **Clones inherited `_visible=false` from the hidden master.** `ng_cloneSprite`,
   `ng_cloneSpriteFromMC`, `ng_duplicateMovieClip` all did
   `clone_mc->visible = src_mc->visible`. Since the game hides the master before
   the loop, every clone was born invisible and `render_attached_child` skipped
   them (`if (!mc->visible) return;`). **Ruffle's `clone_sprite` copies only the
   matrix and color transform — never `_visible`** (core/src/avm1/globals/movie_clip.rs),
   so a duplicate of a hidden clip is still shown. Fix: clones are born visible
   (`clone_mc->visible = 1`) in all three functions.

2. **`ng_cloneSpriteFromMC` never created the clone's `display_obj`.** The old-form
   `duplicateMovieClip(cell, …)` of a timeline clip routes here (not
   `ng_cloneSprite`). Unlike its two sibling clone functions, it copied properties
   and registered the clone but never built a standalone `display_obj` populated by
   frame 0 — so `render_attached_child` returned at `if (mc->display_obj == NULL)`.
   In browser-WASM the global `display_list` write is skipped, so `display_obj` is
   the only content path. Fix: added the same frame-0 / `display_obj` block that
   `ng_cloneSprite` / `ng_duplicateMovieClip` already have, gated to browser-WASM
   (`!NO_GRAPHICS && !OFFSCREEN_RENDER && !HEADLESS_GRAPHICS`) so the CI modes stay
   byte-identical.

3. **`child_mc_cache` cap (512) too small for a 480-cell board.** With ~54 chrome
   MCs alongside 480 cells (~534 simultaneous live MCs), the cap was hit at 458
   cells → the last ~22 (one column) never created → partly-blank board. Fix:
   raise `MAX_CHILD_MOVIECLIPS` 512→1024, **and** make
   `actionFindOrCreateMovieClip` reuse a freed (NULL) slot before appending so
   Restart (`deleteCells` `removeMovieClip`'s all 480 cells → NULLs their slots,
   then rebuilds) doesn't grow `child_mc_count` without bound.

## Result
Full 30×16 grey grid renders, matching Ruffle. Verified in headed Chrome via
`tools/divergence/game_drive/minesweeper_board_probe.py` (clicks Start at frac
(0.5, 0.896), dumps display list + canvas); instrumentation confirmed 481 clones
(480 + master) all `visible=1` with `display_obj`, cache 535/1024.

## Files
- `SWFModernRuntime/src/libswf/tag_stubs.c` — clones born visible (×3);
  `ng_cloneSpriteFromMC` display_obj + frame-0 block (browser-WASM-gated).
- `SWFModernRuntime/src/actionmodern/action.c` — cap 512→1024;
  `actionFindOrCreateMovieClip` reuses freed NULL slots.

## Validation / gates
- avm1 `duplicate_movie_clip`, `duplicate_movie_clip_drawing`,
  `tab_ordering_custom_duplicate_index` — PASS (NO_GRAPHICS).
- Minesweeper OFFSCREEN divergence trace unchanged (634 lines; first divergence
  still the pre-existing F4 float32-scale component diff).
- CI: shared `action.c`/`tag_stubs.c` → dispatched both modes.

## Known residual (minor, follow-up) — FIXED 2026-06-22
~~The bottom-right cell (`cell29_15`, the last clone) shows a stray blue "1"
instead of the grey "Unknown" tile.~~

**Correction / resolution:** this undercounted — *all 480* cells were frozen on
frame 1 (the digit tile), not just the bottom-right; the board only *looked*
plausible because frame 1 isn't visually far off at a glance. Root cause was NOT a
playhead-advance edge case: the board build's `tellTarget("cellX_Y")
{ gotoAndStop("Unknown") }` never navigated the cells at all, because (1)
browser-WASM `actionSetTarget` couldn't resolve a `child_mc_cache` dynamic clip
(its `resolveSlashPathToMC` graphics branch only searched the display list), and
(2) `actionGoToLabel` ignored the `tellTarget` target. Fixed in `action.c`; all
480 cells now rest on frame 12 ("Unknown"), matching Ruffle. See
`2026-06-22-minesweeper-board-cells-frozen-frame1-telltarget-gotolabel.md`.
