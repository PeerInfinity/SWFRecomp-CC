# Minesweeper "Splash partly loads the title screen" — removeMovieClip was a no-op in browser-WASM

**Date:** 2026-06-22
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Bucket:** needs-browser (input-gated; reached only by Start → play → Splash).

## Symptom
Clicking **Splash** on the game screen returned to the title/menu screen, but it
"only partly loaded" — the menu appeared cluttered/obscured because the 480 board
cells were still on screen.

## How Splash works (decompiled DefineButton2_77 on(release))
`... deleteCells(); gotoAndStop(5);` where
```
function deleteCells(){ for x,y: eval("_root.cell"+x+"_"+y).removeMovieClip(); }
```
So Splash removes all 480 `duplicateMovieClip`'d cells, then backward-gotos to the
menu frame (5).

## Diagnosis (non-stale `getGameStateJSON` debug export — `getDisplayListJSON` is
unmaintained in browser-WASM)
A per-step probe (proper press/release timing so the button state machine fires):

| state | rootFrame | childCount | liveCells |
|---|---|---|---|
| menu | 1 | 52 | 0 |
| after Start | 11 | 536 | 481 |
| after Splash (before fix) | 5 | **585** | **480** |

`gotoAndStop(5)` worked (root → frame 5, menu re-created), but **all 480 cells
survived** `deleteCells()` and `childCount` even grew (+49 menu clips on top of the
un-removed cells) → the cells covered the menu.

## Root cause
Both `removeMovieClip` dispatch sites in `action.c` wrap their entire removal body
in `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` with **no `#else`**. In
browser-WASM `mc.removeMovieClip()` fell through to `pushUndefined; return` — a
complete no-op. So `deleteCells()` did nothing.

## Fix (`SWFModernRuntime/src/actionmodern/action.c`, browser-WASM-only effect)
Ungated the method-dispatch `removeMovieClip` removal (the path `tn.removeMovieClip()`
takes) so it runs in all modes. Safe in browser-WASM:
- It only touches dynamic clips (`depth >= 0`; timeline clips have negative depth
  and are immune), which are never in the global display_list — the display_list
  slot-clear inside is guarded by `ng_findDisplayEntryByName` (returns SIZE_MAX for
  them), so it's a no-op for the cells.
- The simple-removal path sets `avm1_removed=1`, `depth=INT_MIN`, and NULLs the
  `child_mc_cache` slot; the browser-WASM render loop (`tag.c`) already skips both
  `mc==NULL` and `depth==INT_MIN`, so the cells stop rendering.

## Result (same probe, after fix)
After Splash: rootFrame=5, childCount=536, **liveCells=0** — all cells removed, the
menu is clean. Verified the menu renders cleanly in headed Chrome.

## CI
Byte-identical for CI modes — NO_GRAPHICS/OFFSCREEN already compiled the removal
(they were the `#if` condition); only the browser-WASM no-op path changed. No CI
dispatch needed (see `ci-only-when-observable`).

## Note
The companion `removeMovieClip` apply/call site (action.c ~65198) is still gated the
same way; left as-is because `tn.removeMovieClip()` routes through the
method-dispatch site. Ungate it too if a game removes clips via `.apply`/`.call`.

## Remaining Minesweeper browser follow-ups (not this fix)
- Instruction EditText doesn't word-wrap (multi-line wrap rendering gap).
- Restart (`gotoAndPlay(10)`, no deleteCells) re-runs the board build over existing
  clips → top-left tile shifts up-left + instruction text shifts left.
