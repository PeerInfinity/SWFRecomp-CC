# avm2_goto_catchup_scale

Gates the **AVM2 goto catch-up walk gate** (Elephant Quest EQ-4, plan gap #2b) —
both that it is FAST and that it is still CORRECT.

## What it pins

Every explicit AVM2 goto runs a full stage + orphan catch-up pass
(Ruffle `frame_lifecycle.rs::run_inner_goto_frame`, mirrored by
`avm2_display.c::avm2_display_inner_goto_frame`): construct the whole tree,
then run frame scripts over the whole tree. That is O(display tree) per
`gotoAndStop`, so a build loop that creates clips and gotos them is O(n²).

Elephant Quest's `Level.initTiles` is exactly that loop — `new Tile();
addChild(t); t.gotoAndStop(type)` a few thousand times, detaching some again —
and it never finished: by tile ~4000 a single goto walked 60k nodes in ~35 ms,
94% of them in the never-shrinking orphan list.

The fix (`avm2_display.c`, "Catch-up walk gate") skips subtrees with no pending
work: `walk_clean` per node, `dirty_kids` per container, and a dirty-orphan
candidate list, all cleared up the ancestor chain whenever a node acquires
work. `AVM2_NO_WALK_SKIP=1` turns the gate off.

## Shape

- **Loop A** (8000 iterations) creates parentless clips with children — the
  orphan-list growth that dominated EQ — and gotos the root each time.
- **Loop B** (3000 iterations) attaches / gotos / detaches, the `initTiles`
  shape, exercising the container bookkeeping: a freshly attached child must
  still be found and constructed while its siblings are certified quiescent.
- The `enterFrame` traces after the loops are the semantic half: a stale clean
  certificate would freeze the timeline, and this catches that.

## Margin

Measured locally (no-graphics):

| | run time |
|---|---|
| with the gate | **0.32 s** (PASS) |
| `AVM2_NO_WALK_SKIP=1` | **TIMEOUT** (>30 s harness limit) |

Verified to fail without the fix. Rebuild the SWF with `./build_swf.sh`
(mxmlc, `~/CC/flex-sdk`).
