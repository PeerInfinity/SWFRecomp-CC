# Minesweeper board cells "already cleared" — `tellTarget` + `gotoAndStop(label)` on duplicated clips

**Date:** 2026-06-22
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Bucket:** needs-browser (input-gated: the board only appears after clicking Start).

## Symptom
After clicking **Start**, the board appeared "already cleared" (cells not in the
raised, clickable "Unknown" state) with a stray "1" in the bottom-right corner.
Ruffle ground truth: a full grid of raised grey clickable tiles (the "Unknown"
state), no numbers, nothing cleared.

The 2026-06-21 board-render fix
(`2026-06-21-minesweeper-board-cells-not-rendering.md`) noted a "known residual:
only the bottom-right cell shows a stray 1". That undercounted — instrumentation
this session showed **all 480 board cells were frozen on frame 1** (the digit
tile), not just one. They merely *looked* plausible at a glance.

## How the board is built (decompiled root `frame_10`)
```
duplicateMovieClip(cell, "cell"+i+"_"+j, 16384+depth)
setProperty(..., _X/_Y, ...)
tellTarget("cell"+i+"_"+j) { gotoAndStop("Unknown"); play(); }
```
`cell` = `DefineSprite_104`; every frame has `stop()`. Frame labels: 1-8 = digit
tiles, 9=Bomb, 10=NoBomb, 11=Marked, **12="Unknown"** (raised tile), 13="Empty"
(cleared), 14="HotBomb". The intended rest state is frame 12 for every cell.

## Root cause (two gaps, both for AVM1 *dynamic* clips in graphics mode)
The `gotoAndStop("Unknown")` is compiled as `SetTarget2` →
`actionGoToLabel("Unknown")` → `actionPlay`. Two things were missing:

1. **`actionSetTarget` couldn't resolve a `duplicateMovieClip`'d clip in
   browser-WASM graphics.** Its bare-name path calls `resolveSlashPathToMC`,
   whose **graphics (`#else`) branch only searches the display list** for a child
   by instance name. Dynamic clips (duplicateMovieClip / attachMovie /
   createEmptyMovieClip) live in `child_mc_cache`, never the display list, so the
   lookup returned NULL → SetTarget fell back to root and set
   `g_settarget_none=1`. (The NO_GRAPHICS branch already has dynamic_props /
   `findOrCreateMovieClip` fallbacks; graphics never got them.)

2. **`actionGoToLabel` ignored the `tellTarget` target entirely.** It only
   handled (a) being inside a sprite's own frame script (`ng_isInsideSprite`) and
   (b) the root timeline (`findFrameByLabel`). Unlike `actionGotoFrame` (numeric),
   it had no `targeted_sprite` / `g_current_context` branch — so even once the
   target resolved, `gotoAndStop("Unknown")` under `tellTarget` looked up
   "Unknown" in the **root** label table (absent) and silently no-op'd.

Net: every cell stayed on its created frame 1 (the "1"/digit tile), `is_playing=0`
(frame 1's `stop()` ran on creation). The board looked cleared.

## Fix (`SWFModernRuntime/src/actionmodern/action.c`, shared → CI both modes)
1. `resolveSlashPathToMC` graphics `#else` branch: when the display-list scans
   miss, fall back to a **find-only `child_mc_cache` scan by name+parent** (no
   creation). Now SetTarget("cellX_Y") resolves the duplicated clip and sets
   `g_current_context`.
2. `actionGoToLabel`: add a redirected-target branch (mirrors
   `actionGotoFrame`): if a graphics `targeted_sprite` is set, resolve the label
   against it (`ng_findSpriteLabelFrame`) and navigate
   (`sprite_next_frame`/`sprite_manual_next_frame`, stop); else if a SetTarget
   redirect is active (`g_settarget_context_changed`) and `g_current_context` is a
   non-root MC, resolve the label against that clip's char_id and
   `ng_gotoFrameByMC(..., 0)` (gotoAndStop ⇒ stop). Only fires under an active
   redirect, so normal in-sprite / root gotos are unchanged.

`play()` after `gotoAndStop` is left targeting root (harmless): the cell is a
stopped dynamic clip and stays on "Unknown", matching Ruffle (the cells visibly do
not advance to "Empty").

## Verification
- Ruffle ground truth screenshot (`minesweeper_ruffle_click.py` clicking Start):
  full grid of raised grey "Unknown" tiles.
- In-browser data probe (temporary `getCellFramesJSON` debug export + counters,
  both stripped before commit): **before** — 480 cells `currentframe=1`,
  `sprite_current_frame=0`; **after** — 480 cells `currentframe=12`,
  `sprite_current_frame=12`, `is_playing=0`, `visible=1`; the only frame-1 entry
  is the hidden master `cell` (`visible=0`). Resolution counters: all 480
  SetTarget redirects now reach the clip and navigate (`fire=480`).
- Pixel screenshot of the board is **blocked in WSL2** (the 480-cell board
  saturates SwiftShader's present so CDP/element screenshot never gets a stable
  frame — same documented constraint as other board work; the lighter menu screen
  screenshots fine). Verification is data + Ruffle parity.
- NO_GRAPHICS regression tests PASS: `goto_label`, `tell_target`,
  `tell_target_invalid`, `tell_target_invalid_swf6`, `set_target_2_swf5/6/7`,
  `removed_base_clip_tell_target`, `target_path`, `duplicate_movie_clip`,
  `duplicate_movie_clip_drawing`. (`target_paths` is a pre-existing harness
  `COMPILE_FAIL` on missing recompiler-generated `out.h`, unrelated to a runtime
  edit.)

## Files
- `SWFModernRuntime/src/actionmodern/action.c` — `resolveSlashPathToMC`
  child_mc_cache fallback (graphics); `actionGoToLabel` redirected-target branch.

## CI
Shared `action.c` (NO_GRAPHICS / OFFSCREEN / browser-WASM) → dispatch both modes.
