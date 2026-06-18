# AVM1 tick perf — event-driven enterFrame-walk pruning (re-port of shelved patch)

**Date:** 2026-06-17
**Area:** `SWFModernRuntime/src/libswf/tag.c` (+ `include/libswf/swf.h`)
**Scope:** shared per-frame hot path — all games, both CI modes.
**Follows:** `2026-06-17-avm1-walk-mc-resolution-cache.md` (the resolution cache).

## Context

The earlier `minesweeper-perf-static-subtree-pruning.md` plan + its full
implementation (`~/avm1_subtree_pruning_shelved.patch`) pruned **all 5** per-frame
walks via a per-tick **full-tree recompute** (`refresh_subtree_dynamic_summary`).
It was shelved because that recompute's bottom-up pass scans the root display
list to `max_depth`, which in NO_GRAPHICS/OFFSCREEN reaches ~16,400 entries (the
attachMovie `as_depth + 16384` registration bias) → ~10% CI overhead.

This re-port is **event-driven** (no full-tree recompute, no +16384 scan) and
**scoped to the two pure-recursion walks** the resolution cache couldn't help
(they do no name resolution to memoize):

- `set_enterframe_eligible_recursive` (was ~7.6% of Minesweeper Ir)
- `gather_clip_ef_entries` via `dispatch_enterframe_clip_actions` (~7.5%)

## Design (why it's safe)

Both walks exist purely to drive enterFrame dispatch, each with a *single*
consumer:

**Walk 1** sets `enterframe_eligible`, read **only** by
`actionDispatchEnterFrameHandlers` (`mc.onEnterFrame`). An `onEnterFrame` handler
lives on `mc->dynamic_props`, which only exists on cached MovieClips — so every
dispatchable handler is reachable from `child_mc_cache`. Each tick
`stamp_onenterframe_paths()` walks **up** the display-tree ancestry
(`mc->parent…->display_obj`) of every cached MC that has `onEnterFrame`, stamping
`subtree_ef_gen = g_tick_count`. The walk then skips any subtree whose entry
isn't stamped this tick. This is **source-complete**, cheap (O(handlers × depth),
no full-tree scan), and self-healing (recomputed per tick). `g_ef_prune_safe`
falls back to the full walk for the tick if any handler MC's `display_obj`
ancestry has a NULL link before root, so a linkage gap can never drop a handler.

**Walk 2** gathers entries used **only** to fire `CLIP_EVENT_ENTER_FRAME`. A
sticky `g_any_clip_ef_placed` flag is set whenever a clip-action list containing
`CLIP_EVENT_ENTER_FRAME` is assigned to a display entry (4 funnels in tag.c).
While it's 0, `dispatch_enterframe_clip_actions` returns immediately (the gather
would find nothing). Once any such clip exists we keep the full walk
(conservative — no per-subtree gap for anonymous clips).

Both gates live **inside the two walk functions**, so they cover every caller
(swf.c / swf_core.c / swf_headless.c / tagFlushPendingEnterFrame) uniformly — no
main-loop or per-mode edits, unlike the shelved patch.

Note: `enterframe_eligible` is also set by the (unpruned) `advance_sprite_frames`,
so pruning walk 1 only removes redundant flag-sets on no-`onEnterFrame` subtrees;
it cannot suppress a handler whose path is stamped.

## Result (Minesweeper, NO_GRAPHICS, callgrind, 100 frames)

| stage | total Ir | vs baseline |
|---|---|---|
| baseline (before resolution cache) | 605.9M | — |
| + resolution cache | 373.1M | −38.4% |
| **+ enterFrame-walk pruning** | **319.4M** | **−47.3%** |

Both walks drop out of the top-cost list entirely (Minesweeper's radio tree has
no `onEnterFrame` and no clip-`ENTER_FRAME`, so both prune fully).

## Verification

- OFFSCREEN Minesweeper divergence trace: **634 lines**, unchanged pattern.
- Local NO_GRAPHICS trace tests pass (directly exercise both walks):
  `clip_events`, `clip_event_propagation_order`, `unload_clip_event`,
  `execution_order1`–`4`.
- CI both modes **green, 0 regressions** (commit `5f2530446`):
  - graphics (run 27739365781): avm1 622/701 = baseline; 0 graphics regressions.
  - no-graphics (run 27739836100): avm1 622, from_shumway 73, from_gnash
    135/67/7/9/19 — all 0 delta, no incomplete shards. The trace suites directly
    exercise `onEnterFrame` + clip-`ENTER_FRAME` dispatch (what both pruned walks
    drive), so this is the load-bearing correctness signal.
  - (Two earlier graphics runs each lost a *different* random shard — 29, then 17
    — to the recurring HTTP 401 runner-auth flake; a code bug would fail the same
    deterministic tests, and the clean re-run restored them.)

## Next levers (still open)

- `actionGetMember` (now ~11.5%) — FUIComponent property reads → string-interning
  Step 3 (`wasm-game-performance-step3-string-interning.md`).
- `advance_sprite_frames` / `presync` recursion self-cost — could take the
  *structural* subtree prune for the non-enterFrame walks, but those carry the
  animation/hit-test correctness traps from the original plan; defer.
