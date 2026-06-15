# Tetris stale-block trail — `ng_gotoFrameByMC` branch used the NEXT frame, not the displayed one

**Date:** 2026-06-15 (cont. 33)
**Status:** ✅ **FIXED** (pending CI) — moving Tetris pieces now erase their previous
cells instead of leaving a coloured trail. Verified in the browser harness
(`tetris_fall_probe.py` `probe_fall_00.png`: the first piece falls into the empty
board as a clean 4-cell tetromino with no streak above it).
**Bucket:** **shared runtime** — `tag_stubs.c` `ng_gotoFrameByMC` compiles into
NO_GRAPHICS / OFFSCREEN / browser-WASM, and is reached from MC-targeted
`gotoAndStop` / `prevFrame` in all modes → run CI both modes as a no-regression
check (goto / timeline tests).

---

## Symptom

After the `processTimers` fix (cont. 32) made Tetris playable, pieces fell but
their previous cells were **not erased** — the board filled with stale block
visuals. A telltale detail (from manual testing): a given colour appeared in
groups that were **not multiples of 4**, even though every tetromino is exactly 4
cells.

## Root cause

The board cells are `block` sprites (`char 10`, `sprite_10`, **8 frames**)
attached to `b_mc`. The game colours a cell with
`drawBlock(num,pos)` → `b_mc[pos].gotoAndStop(num+1)` and **erases** it with
`drawBlock(0,pos)` → `b_mc[pos].gotoAndStop(1)`. Crucially, `sprite_10`'s frame
layout is:

- **frame 0** ("empty"): places `bang_mc` (char 2) at **depth 3**, and places /
  removes **nothing at depth 1/2**.
- **frames 1-7** (colours): place / modify / remove shapes at **depth 1 or 2**.

So erasing a cell (`gotoAndStop` back to frame 0) only clears the colour if the
goto performs a **rewind** — clear the display list and replay from frame 0.
`ng_gotoFrameByMC` has exactly that backward-jump branch, but it chose the branch
by comparing the target against `obj->sprite_current_frame` — which holds the
**NEXT frame to execute** (`(shown+1) % fc`), not the currently displayed frame.

That off-by-one **wraps at `fc`**: a cell stopped on the last colour (frame 7)
had `sprite_current_frame == 0`, so `gotoAndStop(1)` (→ frame 0) read as
**"same frame"** and took the no-clear branch → the depth-1/2 colour survived =
the stale streak. Because a tetromino is a single colour, only pieces whose
colour mapped to frame 7 trailed — and those trails are sized by fall distance,
producing the "colour groups not a multiple of 4" tell. (The same off-by-one also
made forward colour jumps start one frame late, skipping the depth-1 establishing
`PlaceObject`.)

## The fix

`SWFModernRuntime/src/libswf/tag_stubs.c` `ng_gotoFrameByMC` — derive the branch's
`current` from the **displayed** frame by un-wrapping the next-frame convention:

```c
size_t current = (fc > 0) ? ((obj->sprite_current_frame + fc - 1) % fc) : 0;
```

(equivalently `mc->currentframe - 1`, which the caller's no-op guard already
trusts). Now `gotoAndStop(0)` from any colour frame — including frame 7 — is seen
as a backward jump and does the clear+replay, so the cell erases. Forward colour
jumps also start at the correct frame. The post-loop
`sprite_current_frame = (frame+1) % fc` convention is unchanged, so play-driven
advance is unaffected.

## Verification

- **Tetris (browser):** `tetris_fall_probe.py` `probe_fall_00.png` — first piece
  is a clean 4-cell tetromino on an empty board, no trail. `tetris_input_probe.py`
  (drive piece left/right) shows blocks only where input placed them, no
  horizontal smear. (Harness CDP screenshots are ~minute-latency under WSLg, so
  rapid in-motion capture isn't practical here — real-time manual play is the best
  confirmation of the multiple-of-4 criterion.)
- **Doodle Jump (browser regression):** DJ's breakable platform uses
  `block.gotoAndStop(N)` via the same `ng_gotoFrameByMC`. Rebuilt DJ wasm +
  `dj_smoke.py`: menu renders, 12 s run, no error/abort/hang.
- **CI both modes:** shared code; goto / timeline tests (e.g. `goto_frame_test`)
  exercise `ng_gotoFrameByMC` in NO_GRAPHICS / OFFSCREEN → dispatched as a
  no-regression check.

## Harness additions

- `tools/divergence/game_drive/tetris_input_probe.py` — drives the piece
  horizontally to distinguish a stale trail from legitimate vertical stacking.
- `tools/divergence/game_drive/tetris_fall_probe.py` — rapid capture of the first
  piece descending into the empty board (clean 4-cell check).
