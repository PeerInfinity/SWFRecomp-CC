# AVM1 tick perf — per-frame-walk MovieClip resolution cache

**Date:** 2026-06-17
**Area:** `SWFModernRuntime/src/libswf/tag.c` (+ `include/libswf/swf.h`)
**Scope:** shared per-frame hot path — affects **all** games, **both** CI modes.

## What & why

The 5 per-frame display-tree walks resolve each sprite node's `MovieClip*` by
**string name every frame**. The resolvers (`actionFindOrCreateMovieClip` /
`actionFindMovieClipByName`) do an **O(child_mc_count) linear scan with
`swf_name_match`** (which for SWF≤6 case-folds via per-char `_obj_utf8_decode`).
On a deep static tree (Minesweeper's FUIComponent radios, ~50–75 sprite nodes;
`child_mc_count` grows into the hundreds) this is O(nodes × cache_size) per walk
per frame.

This was the **current #1 systemic AVM1 cost** in a fresh native profile (the
"~67% property lookup" figure predated the hash-index store and was stale; see
[[wasm-game-performance-profiling]]). Re-profiling Minesweeper (NO_GRAPHICS,
callgrind, 100 frames) showed the 5 walks at ~59% of instructions, with
`swf_name_match` (6.9%) + `_obj_utf8_decode` (4.9%) as the leaf cost *under*
them.

## Fix

Memoize the resolved `MovieClip*` on the `DisplayObject` (`obj->resolved_mc`,
`void*`). The hot walk sites first call `tag_cached_walk_mc(obj, parent,
name_only)`, which **revalidates the same predicate the resolver keys on** and
returns the cached pointer on a hit (one `swf_name_match` + a few pointer
checks); on a miss the caller runs the real resolver and `tag_store_walk_mc`s
the result.

- `name_only=1` mirrors `actionFindMovieClipByName` (NO_GRAPHICS `advance`/
  `presync`: global first-match `depth!=INT_MIN && swf_name_match`).
- `name_only=0` mirrors `findOrCreateMovieClip` (browser/OFFSCREEN + the button
  walk: live + same parent + same name, honoring `name_displaced` /
  `g_skip_pending_removal_mc`).

**Correctness argument:** a fresh same-name placement is *appended* to
`child_mc_cache` (higher index) and never shadows an earlier *live* match, so the
cached first-match stays the resolver's exact answer while it remains live and
name-matching. Otherwise (freed → `depth==INT_MIN`; renamed/re-parented →
predicate mismatch) revalidation fails and the caller re-resolves. Each site
keeps its own resolver, so no find-vs-create or mode behavior changes. The cache
is a pure memo of the scan result — same value, no side effects skipped (sprite
nodes return early from `findOrCreateMovieClip`'s textfield re-init path anyway).

Sites wrapped: `advance_sprite_children_only`, `presync_nested_cf_recurse`, and
both `ng_update_button_states_in_dl` resolver calls.

## Result (Minesweeper, NO_GRAPHICS, callgrind, 100 frames)

| | total Ir | advance_sprite_frames | presync | swf_name_match | _obj_utf8_decode |
|---|---|---|---|---|---|
| before | 605.9M | 130.1M (21.5%) | 81.2M (13.4%) | 42.0M (6.9%) | 29.6M (4.9%) |
| after  | **373.1M** | 65.6M (17.6%) | 46.8M (12.5%) | <9.3M (<2.5%) | 9.9M (2.6%) |

**−38.4% total AVM1 instruction count.** Mode-invariant (the walks run in every
build mode); the win transfers to the browser radio-click burst, which is
tick-bound on exactly these walks ([[minesweeper-radio-click-lag-is-avm1-burst]]).

## Verification

- OFFSCREEN divergence trace (`divergence_test.py … --frames 16`): **634 lines**,
  unchanged divergence pattern (byte-identical behavior).
- Local NO_GRAPHICS trace tests pass: `attach_movie`, `duplicate_movie_clip`,
  `goto_execution_order`, `goto_both_ways1`, `clone_sprite_types`,
  `empty_movieclip_can_attach_movies`, `goto_advance1`, `button_goto`,
  `attach_movie_stop`.
- CI both modes: _(filled in after dispatch)_.

## Next levers (documented, not done)

- **Subtree pruning** for the two *pure-recursion* walks that have no resolver to
  cache — `set_enterframe_eligible_recursive` (7.6%) + `gather_clip_ef_entries`
  (7.5%) — and the recursion self-cost of `advance`/`presync`. Skip recursing
  into subtrees with no dynamic descendant. A full impl was built+shelved
  (`~/avm1_subtree_pruning_shelved.patch`) but its periodic refresh iterated the
  native-only `+16384` attachMovie buffer (CI overhead); an **event-driven**
  per-sprite `subtree_dynamic` flag avoids that. Higher impact, higher risk —
  warrants its own increment + CI. See
  `minesweeper-perf-static-subtree-pruning.md` for the correctness traps.
- **`actionGetMember` (9.9%)** — FUIComponent property reads; the documented
  string-interning step
  (`wasm-game-performance-step3-string-interning.md`) would cut the residual
  UTF8↔UTF16 + hashing.
