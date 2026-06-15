# Tetris game-screen layout FIXED — no-matrix PlaceObject2 "modify" reset objects to the origin

**Date:** 2026-06-14 (cont. 31)
**Status:** ✅ **FIXED** — the board outline, the level/lines/score panel labels +
values, the quit/pause buttons, and the "tetris" logo now render in their correct
positions on the SWFRecomp browser-WASM game screen, matching Ruffle. Verified with
`tools/divergence/game_drive/tetris_compare.py` (all four stages — menu / play / up /
ok — now match; no regression on the three that were already good).
**Bucket:** **shared runtime** (`tag.c` `tagPlaceObject2` compiles into
trace / NO_GRAPHICS / OFFSCREEN as well as browser-WASM) → run CI both modes as a
no-regression check.

---

## The handoff's theory was wrong (twice over)

The cont. 30 handoff hypothesized the game frame's **static/timeline content was being
skipped by the renderer** while only attached/dynamic content drew. Instrumentation
disproved both layers:

1. **The "hang" was an instrumentation artifact.** Early diagnostic builds dumped the
   full root display list + `child_mc_cache` (~400 console lines) on *every* frame
   change. That console flood froze the page mid-tick, so the timeline appeared to
   "stop" at a wall-clock-variable frame (10/13/14/15 depending on how much I logged).
   With a **lean** heartbeat (one line per main-loop iteration, no array dumps), the
   heartbeats continue indefinitely: the timeline plays cleanly to **frame 23 and
   stops** (`play=0`). **No hang.** Lesson: a per-frame full-DL dump is heavy enough to
   self-induce a "freeze" — keep render-loop diagnostics to O(1) per frame.

2. **The content is NOT skipped by the renderer — it was placed at the wrong
   coordinates.** A one-shot dump at the stopped frame showed every element present in
   the display list (`char 55`/`69` board outline, `char 41–50` labels/values,
   `quit_btn`/`pause_btn`, `char 26` logo) — but the labels, values, buttons, and logo
   were all at **tx=0, ty=0** (piled in the top-left = the garbled cluster in the broken
   screenshot). At an earlier frame (cf=14) those same objects had **correct** coords
   (`quit_btn` was tx=247, ty=280); a later frame reset them.

## Root cause

`tagPlaceObject2`'s **modify path** (`char_id == 0`, a PlaceObject2 with the Move flag
but no new CharacterId) updated the object's `transform_id` **unconditionally**:

```c
if (!display_list[depth].transformed_by_script) {
    display_list[depth].transform_id = transform_id;   // even when transform_id == 0
}
```

The recompiler emits `transform_id = 0` when a PlaceObject2 tag has **no matrix**
(`HasMatrix == 0`, `swf.cpp:3611`: `if (has_matrix) … else transform_id = 0;`). Slot 0
of `transform_data` is the identity matrix. So a move tag that changes *only* the color
transform / ratio / clip depth (no matrix) snapped the object to the **origin** instead
of keeping its position — the opposite of Flash, where a move tag only updates the
matrix when it actually carries one.

Concrete Tetris victims:
- **"tetris" logo** (`char 26`): placed at frame 3 with a real matrix (bottom-right),
  then frames 6–10 issue **cxform-only** modifies (the fade-in animation) → reset to
  (0,0) = top-left.
- **score-panel labels + values + quit/pause buttons** (`char 41–54`): placed at frame
  14 with real matrices, then frame 15 issues **cxform** modifies → reset to (0,0).

## The fix

Guard the transform update in the modify path with `transform_id != 0` so a no-matrix
modify **keeps the existing matrix** (Flash semantics). `tag.c` only, three sites in
`tagPlaceObject2`:
- the main `char_id == 0` modify branch (all modes),
- its `ng_cache_transform` companion (NO_GRAPHICS/OFFSCREEN cached x/y),
- the browser-WASM same-tick `pending_remove` reclaim-modify branch.

**This is exactly what the sibling `tagPlaceObject2Ratio` modify path already does**
(`if (transform_id != 0) { … }`) — the plain variant was the buggy outlier; the fix
brings it into line, which strongly de-risks the change.

Known minor ambiguity (documented in-code): an *explicit* identity move-matrix also
dedups to slot 0, so a deliberate "move to origin" via PlaceObject2 is now not applied.
This is rare (you'd place at origin with the default transform, not re-move there) and
is the trade-off for correct no-matrix-modify behavior.

## Verification

`tetris_compare.py` → `compare_out/compare_ok.png`: SWFRecomp now shows the tall board
outline, the next-piece preview box, the **level / lines / score** rows (values in the
right column), the **quit / pause** buttons, and the **"tetris" logo bottom-right** —
all matching Ruffle's reference. `compare_menu.png` / `compare_up.png` unchanged
(still pixel-match). Shared code → CI both modes.

## Still open (separate issues, out of scope for this fix)

- **Per-frame game ActionScript doesn't drive the timeline in browser-WASM.** During the
  full 3→23 playthrough only ~6 `func_anonymous` (init-time) calls fire; no per-tick
  `onEnterFrame` game-loop runs, and `setInterval` callbacks never fire (the
  `processTimers` call site in `swf.c` is inside `#ifdef OFFSCREEN_RENDER`, so
  browser-WASM never pumps timers). Consequences: the falling piece doesn't animate in
  the board, and the timeline free-plays to frame 23 instead of being held at the game
  frame by the running game. This is the next real blocker for *playable* Tetris.
- The deprioritized italic-digit "1"→"/" glyph slant.
- Manual re-check of DJ/Snake/Pong for cont. 29 fix #3 (`gotoAndStop`→`ng_gotoFrameByMC`).

## Process notes (heed)

- **Don't dump the full display list / child_mc_cache every frame** in browser-WASM
  diagnostics — the console flood freezes the page and masquerades as a runtime hang.
  Use a one-line-per-tick heartbeat to measure frame progression, and gate any heavy
  per-entry dump to a single one-shot (`if (cf == TARGET && !done)`).
- Runtime `.c` changes **do** recompile without `--clean` (BUILD_DIR is wiped every
  build); the earlier "timer.c marker absent" was dead-code elimination of an
  OFFSCREEN-only function, not a stale build. `--clean` additionally regenerates
  `RecompiledScripts`/`RecompiledTags` (wiping any edits to generated files).
- Harness cleanup still self-matches the launching shell — see
  `tetris-compare-harness-pkill-selfmatch.md`; run cleanup in a separate bash call.
