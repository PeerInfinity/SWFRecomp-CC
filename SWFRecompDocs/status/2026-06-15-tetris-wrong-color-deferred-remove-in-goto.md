# Tetris wrong-colour squares — deferred RemoveObject2 never finalized in `ng_gotoFrameByMC` replay

**Date:** 2026-06-15 (cont. 34)
**Status:** ✅ **FIXED** — pieces now render a single uniform colour; the
"purple square on the orange I-piece" is gone. Verified in the browser harness:
a multi-depth detector (temporary) went from **167 hits → 0** after the fix, and
`compare_ok.png` shows every stacked piece as one solid colour.
**Bucket:** **browser-WASM / HEADLESS only** — the fix is gated
`#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` (it mirrors where
`tagRemoveObject2` uses the deferred `pending_remove` path), so it is excluded
from both CI modes → verified via the harness, no CI dispatch
(`ci-only-when-observable`).

---

## Symptom

After the stale-trail fix (cont. 33), pieces erased correctly but some squares of
the long (I) piece rendered **purple instead of orange**. All four cells of a
piece are drawn with the *same* colour (`drawBlock(thisShape+1, pos)`), so a
per-cell wrong colour couldn't be a game-logic miscalculation.

## Root cause (found via instrumentation)

The board cell is the `block` sprite (`char 10`, 8 frames). Its colour shape lives
at **depth 1** (frames 1,2,5,7) or **depth 2** (frames 3,4,6), and each colour
swap **removes the other depth** (e.g. frame 5 = `RemoveObject2(depth 2)` +
`PlaceObject2(char7, depth 1)`). A multi-depth detector added to `ng_gotoFrameByMC`
showed cells ending with **both** depths occupied — `d1=7 d2=6`, `d1=4 d2=6` —
167 times in one playthrough.

The reason: in browser-WASM, `tagRemoveObject2` (tag.c) only marks
`pending_remove = 1`; it does **not** clear `char_id`. Finalization normally
happens later in `tagShowFrame`'s pending-remove walk (or a same-tick re-place
consumes it). But `ng_gotoFrameByMC` replays frame funcs **synchronously** into
the cell's swapped display list with **no such finalize pass** — so a frame's
`RemoveObject2` left the old colour shape live. The goto then landed with two
colour shapes, and the renderer draws the **higher depth on top**: for an
I-piece coloured at depth 1 (char7 = orange), the un-removed depth-2 char6
(purple) covered it → purple square. (NO_GRAPHICS / OFFSCREEN clear inline in
`tagRemoveObject2`, so they never had this bug.)

## The fix

`SWFModernRuntime/src/libswf/tag_stubs.c` `ng_gotoFrameByMC` — after the frame
replay (forward / backward / same), walk the cell's display list and finalize any
entry still flagged `pending_remove` (free its sub-list, clear `char_id`, reset
the flag). A depth that was re-placed in the same replay already had its
`pending_remove` consumed by `tagPlaceObject2`, so only genuinely-removed depths
are cleared — leaving exactly the target frame's content. Gated to the modes that
use the deferred-remove path (browser-WASM / HEADLESS).

## Verification

- Temporary multi-depth detector: 167 → **0** after the fix.
- `tetris_compare.py` `compare_ok.png`: each stacked piece is a single solid
  colour; no mixed purple/orange squares.
- Final build is diagnostic-free (`strings | grep -c PMDIAG` = 0).

## Notes

- This bug was **pre-existing**, independent of the cont. 33 off-by-one fix — it
  was simply masked while the stale trails covered the board.
- Same family as the documented browser-WASM deferred-removal gotchas
  (`clear_display_entry` dangling pointers, etc.): any synchronous sprite-frame
  replay that runs `RemoveObject2` must finalize `pending_remove` itself.

## Still open (Tetris)

- Freeze on line clear (hard to reproduce in the no-lateral-input harness —
  needs a completed row; likely the `bang_mc` line-clear path or row-shift loop).
- Stage number slanted (known italic-digit glyph issue) and still visible after
  the game starts.
